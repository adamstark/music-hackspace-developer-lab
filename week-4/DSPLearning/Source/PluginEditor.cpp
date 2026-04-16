/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DSPLearningAudioProcessorEditor::DSPLearningAudioProcessorEditor (DSPLearningAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setRange (-48., 6.);
    gainSlider.setValue (0.);
    addAndMakeVisible (gainSlider);
    gainSlider.onValueChange = [this]()
    {
        float dB = gainSlider.getValue();
        audioProcessor.setLevelInDecibels (dB);
    };
    
    noteButton.setClickingTogglesState (true);
    addAndMakeVisible (noteButton);
    noteButton.onClick = [this]()
    {
        bool state = noteButton.getToggleState();
        
        if (state)
        {
            audioProcessor.getADSR().noteOn();
        }
        else
        {
            audioProcessor.getADSR().noteOff();
        }
    };
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

DSPLearningAudioProcessorEditor::~DSPLearningAudioProcessorEditor()
{
}

//==============================================================================
void DSPLearningAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void DSPLearningAudioProcessorEditor::resized()
{
    Rectangle<int> r (getLocalBounds());
    r.reduce (20, 20);
    
    gainSlider.setBounds (r.removeFromTop (30));
    r.removeFromTop (20);
    noteButton.setBounds (r.removeFromTop (20).removeFromLeft (100));
}
