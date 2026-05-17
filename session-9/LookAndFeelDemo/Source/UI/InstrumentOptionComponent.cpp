/*
  ==============================================================================

    InstrumentOptionComponent.cpp
    Created: 17 May 2026 9:02:21pm
    Author:  Adam Stark

  ==============================================================================
*/

#include "InstrumentOptionComponent.h"
#include "../LookAndFeel/CustomLookAndFeel.h"

//==============================================================================
InstrumentOptionComponent::InstrumentOptionComponent (Colour c, Path& i, String t, String s)
 :  highlightColour (c),
    icon (i),
    title (t),
    subtitle (s)
{
    
}

//==============================================================================
void InstrumentOptionComponent::paint (Graphics& g)
{
    Rectangle<int> r (getLocalBounds());
    
    g.setColour (getLookAndFeel().findColour (ui::ColourIds::Panel));
    g.fillRoundedRectangle (r.toFloat(), 24.f);
    
    r.reduce (12, 12);
    
    auto circleBounds = r.removeFromLeft (r.getHeight());
    
    g.setColour (highlightColour);
    g.fillEllipse (circleBounds.toFloat());
    
    g.setColour (ui::ColourPalette::white);
    circleBounds.reduce (6, 6);
    icon.scaleToFit (circleBounds.getX(), circleBounds.getY(), circleBounds.getWidth(), circleBounds.getHeight(), true);
    g.fillPath (icon);
    
    r.removeFromLeft (12);
    
    auto topBounds = r.removeFromTop (ui::FontSize::lg);
    auto bottomBounds = r.removeFromBottom (ui::FontSize::sm);
    
    g.setColour (ui::ColourPalette::white);
    g.setFont (FontOptions (ui::FontSize::lg, Font::bold));
    g.drawText (title, topBounds, Justification::left);
    
    g.setColour (ui::ColourPalette::grey4);
    g.setFont (FontOptions (ui::FontSize::sm, Font::plain));
    g.drawText (subtitle, bottomBounds, Justification::left);
    
}

//==============================================================================
void InstrumentOptionComponent::resized()
{
    
}
