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
    myButton.setColour (TextButton::ColourIds::buttonColourId, Colours::red);
    myButton.setColour (TextButton::ColourIds::buttonOnColourId, Colours::green);
    myButton.setClickingTogglesState (true);
    myButton.setButtonText ("Click Me");
    addAndMakeVisible (myButton);
    myButton.onClick = [this]()
    {
        bool state = myButton.getToggleState();
        
        if (state)
            DBG ("Button is On");
        else
            DBG ("Button is Off");
    };
    
    myComboBox.addItem ("Sine", 1);
    myComboBox.addItem ("Sawtooth", 2);
    myComboBox.addItem ("Square", 3);
    myComboBox.addItem ("Noise", 4);
    addAndMakeVisible (myComboBox);
    myComboBox.onChange = [this]()
    {
        int selectedIndex = myComboBox.getSelectedItemIndex();
        DBG ("We selected " << myComboBox.getItemText (selectedIndex));
    };
    
    addAndMakeVisible (sliderArea);
    
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
    Rectangle<int> r (getLocalBounds());
    r.reduce (20, 20);
    
    sliderArea.setBounds (r.removeFromTop (160));
    r.removeFromTop (20);
    myButton.setBounds (r.removeFromTop (30).withWidth (100));
    r.removeFromTop (20);
    myComboBox.setBounds (r.removeFromTop (20).withWidth (100));
}
