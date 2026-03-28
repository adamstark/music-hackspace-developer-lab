/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
UITutorialAudioProcessorEditor::UITutorialAudioProcessorEditor (UITutorialAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

UITutorialAudioProcessorEditor::~UITutorialAudioProcessorEditor()
{
}

//==============================================================================
void UITutorialAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (Colours::grey);
    
    Rectangle<int> r (getLocalBounds());
    r.reduce (10, 10);
    
    g.setColour (Colours::darkgrey);
    g.fillRect (r);
}

void UITutorialAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
