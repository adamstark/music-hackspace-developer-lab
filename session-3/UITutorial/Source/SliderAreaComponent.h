/*
  ==============================================================================

    SliderArea.h
    Created: 28 Mar 2026 7:22:13pm
    Author:  Adam Stark

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h> // know about JUCE

class SliderAreaComponent : public Component
{
public:
    
    SliderAreaComponent();
    
    // Component
    void paint (Graphics& g) override;
    void resized() override;
    
private:
    
    Slider mySlider1;
    Slider mySlider2;
};
