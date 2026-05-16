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
class ChorusDemoAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ChorusDemoAudioProcessorEditor (ChorusDemoAudioProcessor&);
    ~ChorusDemoAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ChorusDemoAudioProcessor& audioProcessor;
    
    Slider rateSlider;
    AudioProcessorValueTreeState::SliderAttachment rateAttachment;
    Label rateLabel;
    
    Slider depthSlider;
    AudioProcessorValueTreeState::SliderAttachment depthAttachment;
    Label depthLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChorusDemoAudioProcessorEditor)
};
