/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 17 May 2026 7:11:27pm
    Author:  Adam Stark

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace ui
{
    //==============================================================================
    namespace ColourPalette
    {
        const Colour grey1 = Colour (0xFF16171B);
        const Colour grey2 = Colour (0xFF202125);
        const Colour grey3 = Colour (0xFF2D2E31);
        const Colour grey4 = Colour (0xFF939393);
        const Colour red = Colour (0xFFFF5555);
        const Colour lightBlue = Colour (0xFF55B8FF);
        const Colour darkBlue = Colour (0xFF5566FF);
        const Colour yellow = Colour (0xFFF1B732);
        const Colour purple = Colour (0xFFA055FF);
        const Colour green = Colour (0xFF4BBB78);
        const Colour white = Colour (0xFFFFFFFF);
    }
    
    //==============================================================================
    enum ColourIds
    {
        Background = 0x2000000,
        Panel
    };
    
    //==============================================================================
    enum FontSize
    {
        xs = 10,
        sm = 12,
        base = 14,
        lg = 16,
        xl = 20,
        xl2 = 24,
        xl3 = 30,
        xl4 = 42
    };
    
    //==============================================================================
    enum Metrics
    {
        Margin = 20,
        CornerRadius1 = 16,
        CornerRadius2 = 8,
        ButtonWidth = 128,
        ButtonHeight = 36
    };
    
    //==============================================================================
    enum ButtonStyle
    {
        Red,
        Yellow,
        Purple,
        Green,
        Outlined
    };
    
    //==============================================================================
    struct Icons
    {
        static Path mic;
        static Path piano;
    };
        
    //==============================================================================
    namespace ComponentStyle
    {
        const String buttonStyle = "ButtonStyle";
    }
        
    //==============================================================================
    class CustomLookAndFeel :   public LookAndFeel_V4
    {
    public:
        CustomLookAndFeel();
        
        Typeface::Ptr getTypefaceForFont (const Font&) override;
        
        Font getTextButtonFont (TextButton&, int buttonHeight) override;
        void drawButtonBackground (Graphics&, Button&, const Colour& backgroundColour,
                                   bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
        
        void drawRotarySlider (Graphics&, int x, int y, int width, int height,
                               float sliderPosProportional, float rotaryStartAngle,
                               float rotaryEndAngle, Slider&) override;
    };
}
