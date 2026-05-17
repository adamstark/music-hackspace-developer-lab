/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LookAndFeelDemoAudioProcessorEditor::LookAndFeelDemoAudioProcessorEditor (LookAndFeelDemoAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    vocals (ui::ColourPalette::red, ui::Icons::mic, "Vocals / Audio", "Record your voice"),
    piano (ui::ColourPalette::yellow, ui::Icons::piano, "Virtual Instrument", "Use your own plugins")
{
    button1.getProperties().set (ui::ComponentStyle::buttonStyle, ui::ButtonStyle::Red);
    button1.setButtonText ("Hello");
    addAndMakeVisible (button1);
    
    button2.getProperties().set (ui::ComponentStyle::buttonStyle, ui::ButtonStyle::Green);
    button2.setButtonText ("Hello");
    addAndMakeVisible (button2);
    
    button3.getProperties().set (ui::ComponentStyle::buttonStyle, ui::ButtonStyle::Purple);
    button3.setButtonText ("Hello");
    addAndMakeVisible (button3);
    
    button4.getProperties().set (ui::ComponentStyle::buttonStyle, ui::ButtonStyle::Yellow);
    button4.setButtonText ("Hello");
    addAndMakeVisible (button4);
    
    button5.getProperties().set (ui::ComponentStyle::buttonStyle, ui::ButtonStyle::Outlined);
    button5.setButtonText ("Hello");
    addAndMakeVisible (button5);
    
    addAndMakeVisible (vocals);
    addAndMakeVisible (piano);
        
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);
}

LookAndFeelDemoAudioProcessorEditor::~LookAndFeelDemoAudioProcessorEditor()
{
}

//==============================================================================
void LookAndFeelDemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ui::ColourIds::Background));
}

void LookAndFeelDemoAudioProcessorEditor::resized()
{
    Rectangle<int> r (getLocalBounds());
    r.reduce (ui::Metrics::Margin, ui::Metrics::Margin);
    r.reduce (ui::Metrics::Margin, ui::Metrics::Margin);
    
    auto buttonColoumn = r.removeFromLeft (ui::ButtonWidth);
    button1.setBounds (buttonColoumn.removeFromTop (ui::ButtonHeight));
    buttonColoumn.removeFromTop (10);
    button2.setBounds (buttonColoumn.removeFromTop (ui::ButtonHeight));
    buttonColoumn.removeFromTop (10);
    button3.setBounds (buttonColoumn.removeFromTop (ui::ButtonHeight));
    buttonColoumn.removeFromTop (10);
    button4.setBounds (buttonColoumn.removeFromTop (ui::ButtonHeight));
    buttonColoumn.removeFromTop (10);
    button5.setBounds (buttonColoumn.removeFromTop (ui::ButtonHeight));
  
    r.removeFromLeft (20);
    
    auto instrumentBounds = r.removeFromLeft (335);
    
    vocals.setBounds (instrumentBounds.removeFromTop (54));
    instrumentBounds.removeFromTop (10);
    piano.setBounds (instrumentBounds.removeFromTop (54));
}
