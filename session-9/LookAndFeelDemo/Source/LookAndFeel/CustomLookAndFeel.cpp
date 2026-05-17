/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 17 May 2026 7:11:27pm
    Author:  Adam Stark

  ==============================================================================
*/

#include "CustomLookAndFeel.h"
#include "Icons.h"

//==============================================================================
Path ui::Icons::mic = createIcon (icon_data::mic, sizeof(icon_data::mic));
Path ui::Icons::piano = createIcon (icon_data::piano, sizeof(icon_data::piano));

namespace ui
{
    //==============================================================================
    CustomLookAndFeel::CustomLookAndFeel()
    {
        setColour (ui::ColourIds::Background, ColourPalette::grey1);
        setColour (ui::ColourIds::Panel, ColourPalette::grey2);
        
        setColour (Slider::ColourIds::rotarySliderFillColourId, ColourPalette::lightBlue);
        setColour (Slider::ColourIds::rotarySliderOutlineColourId, ColourPalette::grey3);
    }
    
    //==============================================================================
    Typeface::Ptr CustomLookAndFeel::getTypefaceForFont (const Font& font)
    {
        if (font.isBold())
        {
            if (font.isItalic())
                return Typeface::createSystemTypefaceFor (BinaryData::RobotoBoldItalic_ttf, BinaryData::RobotoBoldItalic_ttfSize);
            else
                return Typeface::createSystemTypefaceFor (BinaryData::RobotoBold_ttf, BinaryData::RobotoBold_ttfSize);
        }
        else
        {
            if (font.isItalic())
                return Typeface::createSystemTypefaceFor (BinaryData::RobotoItalic_ttf, BinaryData::RobotoItalic_ttfSize);
            else
                return Typeface::createSystemTypefaceFor (BinaryData::RobotoRegular_ttf, BinaryData::RobotoRegular_ttfSize);
        }
    }
    
    //==============================================================================
    int getButtonStyle (Button& b)
    {
        return b.getProperties().getWithDefault (ui::ComponentStyle::buttonStyle, ui::ButtonStyle::Red);
    }
    
    //==============================================================================
    Font CustomLookAndFeel::getTextButtonFont (TextButton& button, int buttonHeight)
    {
        int buttonStyle = getButtonStyle (button);
        
        if (buttonStyle == ui::ButtonStyle::Outlined)
            return FontOptions (ui::FontSize::base, Font::italic);
        else
            return FontOptions (ui::FontSize::base, Font::plain);
    }
    
    //==============================================================================
    void CustomLookAndFeel::drawButtonBackground (Graphics& g,
                                               Button& button,
                                               const Colour& backgroundColour,
                                               bool shouldDrawButtonAsHighlighted,
                                               bool shouldDrawButtonAsDown)
    {
        Colour buttonBackgroundColour;
        bool outlined {false};
        int buttonStyle = getButtonStyle (button);
        
        auto bounds = button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);
        
        switch (buttonStyle) {
            case ui::ButtonStyle::Red:
                buttonBackgroundColour = ui::ColourPalette::red;
                break;
            case ui::ButtonStyle::Green:
                buttonBackgroundColour = ui::ColourPalette::green;
                break;
            case ui::ButtonStyle::Yellow:
                buttonBackgroundColour = ui::ColourPalette::yellow;
                break;
            case ui::ButtonStyle::Purple:
                buttonBackgroundColour = ui::ColourPalette::purple;
                break;
            case ui::ButtonStyle::Outlined:
                buttonBackgroundColour = Colours::transparentBlack;
                outlined = true;
                break;
                
            default:
                break;
        }
        
        if (shouldDrawButtonAsHighlighted)
        {
            if (outlined)
                buttonBackgroundColour = ColourPalette::grey3;
            else
                buttonBackgroundColour = buttonBackgroundColour.brighter();
        }
        
        if (shouldDrawButtonAsDown)
        {
            if (outlined)
                buttonBackgroundColour = ColourPalette::grey4;
            else
                buttonBackgroundColour = buttonBackgroundColour.darker();
        }
        
        g.setColour (buttonBackgroundColour);
        g.fillRoundedRectangle (bounds, ui::CornerRadius2);
        
        if (outlined)
        {
            g.setColour (ui::ColourPalette::white);
            g.drawRoundedRectangle (bounds.reduced (1.f, 1.f), ui::CornerRadius2, 2.f);
        }
    }
    
    //==============================================================================
    void CustomLookAndFeel::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
    {
        auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
        auto fill    = slider.findColour (Slider::rotarySliderFillColourId);
        
        auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);
        
        auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = 16.f; //jmin (8.0f, radius * 0.5f);
        auto arcRadius = radius - lineW * 0.5f;
        
        Path backgroundArc;
        backgroundArc.addCentredArc (bounds.getCentreX(),
                                     bounds.getCentreY(),
                                     arcRadius,
                                     arcRadius,
                                     0.0f,
                                     rotaryStartAngle,
                                     rotaryEndAngle,
                                     true);
        
        g.setColour (outline);
        g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
        
        if (slider.isEnabled())
        {
            Path valueArc;
            valueArc.addCentredArc (bounds.getCentreX(),
                                    bounds.getCentreY(),
                                    arcRadius,
                                    arcRadius,
                                    0.0f,
                                    rotaryStartAngle,
                                    toAngle,
                                    true);
            
            g.setColour (fill);
            g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
        }
        
        auto thumbWidth = lineW * 2.0f;
        Point<float> thumbPoint (bounds.getCentreX() + arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                                 bounds.getCentreY() + arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
        
        g.setColour (slider.findColour (Slider::thumbColourId));
        g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    }
}
