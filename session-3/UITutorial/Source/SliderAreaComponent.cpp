/*
  ==============================================================================

    SliderArea.cpp
    Created: 28 Mar 2026 7:22:13pm
    Author:  Adam Stark

  ==============================================================================
*/

#include "SliderAreaComponent.h"

SliderAreaComponent::SliderAreaComponent()
{
    mySlider1.setRange (0., 100.);
    mySlider1.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxRight, true, 60, 20);
    addAndMakeVisible (mySlider1);
    mySlider1.onValueChange = [this]()
    {
        double value = mySlider1.getValue();
        DBG ("Slider 1 value is " << value);
    };
    
    mySlider2.setRange (0., 12.);
    mySlider2.setTextBoxStyle (Slider::TextEntryBoxPosition::NoTextBox, true, 60, 20);
    mySlider2.setSliderStyle (Slider::SliderStyle::Rotary);
    addAndMakeVisible (mySlider2);
    mySlider2.onValueChange = [this]()
    {
        double value = mySlider2.getValue();
        DBG ("Slider 2 value is " << value);
    };
}

void SliderAreaComponent::paint (Graphics& g)
{
    g.fillAll (Colours::blue);
}

void SliderAreaComponent::resized()
{
    Rectangle<int> r (getLocalBounds());
    
    mySlider1.setBounds (r.removeFromTop (30));
    r.removeFromTop (20);
    mySlider2.setBounds (r.removeFromTop (60).withWidth (60));
}
