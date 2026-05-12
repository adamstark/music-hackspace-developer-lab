/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ThreadingAudioPluginAudioProcessorEditor::ThreadingAudioPluginAudioProcessorEditor (ThreadingAudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    loader (&statusLabel)
{
    statusLabel.setText ("Not Loaded", dontSendNotification);
    addAndMakeVisible (statusLabel);
    
    loadButton.setButtonText ("Load");
    addAndMakeVisible (loadButton);
    loadButton.onClick = [this]()
    {
        loader.startThread();
    };
    
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 600);
    
    startTimerHz (24);
}

ThreadingAudioPluginAudioProcessorEditor::~ThreadingAudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void ThreadingAudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    float currentPeak = audioProcessor.peakValue.load();
    
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    Rectangle<float> r (0, 0, 30, 200);
    
    auto meterBounds = r.withCentre (Point<float> (100, 200));
    g.setColour (Colours::black);
    g.fillRect (meterBounds);
    g.setColour (Colours::lightblue);
    g.fillRect (meterBounds.withTrimmedTop ((1.f - currentPeak) * meterBounds.getHeight()));
}

void ThreadingAudioPluginAudioProcessorEditor::resized()
{
    Rectangle<int> r (getLocalBounds());
    r.reduce (20, 20);
    loadButton.setBounds (r.removeFromTop (30).withWidth (100));
    r.removeFromTop (10);
    statusLabel.setBounds (r.removeFromTop (20));
}

void ThreadingAudioPluginAudioProcessorEditor::timerCallback()
{
    repaint();
}
