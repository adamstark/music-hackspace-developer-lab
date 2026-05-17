/*
  ==============================================================================

    InstrumentOptionComponent.h
    Created: 17 May 2026 9:02:21pm
    Author:  Adam Stark

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class InstrumentOptionComponent :   public Component
{
public:
    InstrumentOptionComponent (Colour highlightColour, Path& icon, String title, String subtitle);
    
    //==============================================================================
    // Component
    void paint (Graphics& g) override;
    void resized() override;

private:
    
    Colour highlightColour;
    Path& icon;
    String title;
    String subtitle;
};
