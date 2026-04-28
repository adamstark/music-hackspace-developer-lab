/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ChorusDemoAudioProcessorEditor::ChorusDemoAudioProcessorEditor (ChorusDemoAudioProcessor& p)
 :  AudioProcessorEditor (&p), audioProcessor (p),
    rateAttachment (p.getState(), ChorusDemoAudioProcessor::Ids::rate, rateSlider),
    depthAttachment (p.getState(), ChorusDemoAudioProcessor::Ids::depth, depthSlider)
{
    rateSlider.setSliderStyle (Slider::SliderStyle::Rotary);
    rateSlider.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, false, 60, 20);
    addAndMakeVisible (rateSlider);
    
    rateLabel.setJustificationType (Justification::centred);
    rateLabel.setText (p.getState().getParameter (ChorusDemoAudioProcessor::Ids::rate)->name, dontSendNotification);
    addAndMakeVisible (rateLabel);
    
    depthSlider.setSliderStyle (Slider::SliderStyle::Rotary);
    depthSlider.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, false, 60, 20);
    addAndMakeVisible (depthSlider);
    
    depthLabel.setJustificationType (Justification::centred);
    depthLabel.setText (p.getState().getParameter (ChorusDemoAudioProcessor::Ids::depth)->name, dontSendNotification);
    addAndMakeVisible (depthLabel);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

ChorusDemoAudioProcessorEditor::~ChorusDemoAudioProcessorEditor()
{
}

//==============================================================================
void ChorusDemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void ChorusDemoAudioProcessorEditor::resized()
{
    Rectangle<int> r (getLocalBounds());
    r.reduce (20, 20);
    
    auto column1 = r.removeFromLeft (120);
    r.removeFromLeft (20);
    auto column2 = r.removeFromLeft (120);
    
    rateSlider.setBounds (column1.removeFromTop (120));
    rateLabel.setBounds (column1.removeFromTop (20));
    
    depthSlider.setBounds (column2.removeFromTop (120));
    depthLabel.setBounds (column2.removeFromTop (20));
}
