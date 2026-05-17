/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "FileLoader.h"

//==============================================================================
/**
*/
class ThreadingAudioPluginAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                                    public Timer
{
public:
    ThreadingAudioPluginAudioProcessorEditor (ThreadingAudioPluginAudioProcessor&);
    ~ThreadingAudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    // Timer
    void timerCallback() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ThreadingAudioPluginAudioProcessor& audioProcessor;
    TextButton loadButton;
    Label statusLabel;
    FileLoader loader;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ThreadingAudioPluginAudioProcessorEditor)
};
