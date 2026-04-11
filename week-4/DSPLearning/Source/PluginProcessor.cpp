/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DSPLearningAudioProcessor::DSPLearningAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
    osc (Oscillator::WaveType::Sawtooth, 220)
#endif
{
}

DSPLearningAudioProcessor::~DSPLearningAudioProcessor()
{
}

//==============================================================================
const juce::String DSPLearningAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DSPLearningAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DSPLearningAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DSPLearningAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DSPLearningAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DSPLearningAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DSPLearningAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DSPLearningAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String DSPLearningAudioProcessor::getProgramName (int index)
{
    return {};
}

void DSPLearningAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void DSPLearningAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    osc.prepareToPlay (sampleRate);
}

void DSPLearningAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DSPLearningAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DSPLearningAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    for (int i = 0; i < buffer.getNumSamples(); i++)
    {
        float oscillatorSample = osc.getNextSample();
        oscillatorSample *= 0.1f; // DO THIS OTHERWISE IT WILL BE DANGEROUSLY LOUD
        
        for (int ch = 0; ch < buffer.getNumChannels(); ch++)
        {
            buffer.setSample (ch, i, oscillatorSample * gain);
        }
    }
}

void DSPLearningAudioProcessor::setLevelInDecibels (float dB)
{
    if (dB < -40)
        gain = 0.f;
    else
        gain = Decibels::decibelsToGain (dB);
}

//==============================================================================
bool DSPLearningAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* DSPLearningAudioProcessor::createEditor()
{
    return new DSPLearningAudioProcessorEditor (*this);
}

//==============================================================================
void DSPLearningAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DSPLearningAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DSPLearningAudioProcessor();
}
