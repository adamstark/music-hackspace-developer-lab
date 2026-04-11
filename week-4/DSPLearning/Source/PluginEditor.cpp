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
}
