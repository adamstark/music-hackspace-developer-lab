/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class UITutorialAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    UITutorialAudioProcessorEditor (UITutorialAudioProcessor&);
    ~UITutorialAudioProcessorEditor() override;

    //==============================================================================
    // Component
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    UITutorialAudioProcessor& audioProcessor;
    TextButton myButton;
    Slider mySlider1;
    Slider mySlider2;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UITutorialAudioProcessorEditor)
};
