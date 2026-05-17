/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/InstrumentOptionComponent.h"

//==============================================================================
/**
*/
class LookAndFeelDemoAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    LookAndFeelDemoAudioProcessorEditor (LookAndFeelDemoAudioProcessor&);
    ~LookAndFeelDemoAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    LookAndFeelDemoAudioProcessor& audioProcessor;
    
    TextButton button1;
    TextButton button2;
    TextButton button3;
    TextButton button4;
    TextButton button5;
    
    InstrumentOptionComponent vocals;
    InstrumentOptionComponent piano;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LookAndFeelDemoAudioProcessorEditor)
};
