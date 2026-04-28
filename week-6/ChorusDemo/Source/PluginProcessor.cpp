/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

const String ChorusDemoAudioProcessor::Ids::rate ("rate");
const String ChorusDemoAudioProcessor::Ids::depth ("depth");

//==============================================================================
ChorusDemoAudioProcessor::ChorusDemoAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
    state (*this, nullptr, "CHORUS", createParameterLayout())
#endif
{
    state.addParameterListener (Ids::rate, this);
    state.addParameterListener (Ids::depth, this);
}

ChorusDemoAudioProcessor::~ChorusDemoAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout ChorusDemoAudioProcessor::createParameterLayout()
{
    AudioProcessorValueTreeState::ParameterLayout layout;
    
    layout.add (std::make_unique<AudioParameterFloat> (ParameterID (Ids::rate, 1), "Rate (Hz)", 0.1f, 10.f, 1.0f));
    layout.add (std::make_unique<AudioParameterFloat> (ParameterID (Ids::depth, 1), "Depth", 0.f, 1.f, 0.5f));
    
    return layout;
}

void ChorusDemoAudioProcessor::parameterChanged (const String& parameterID, float newValue)
{
    if (parameterID == Ids::rate)
    {
        chorus.setRate (newValue);
    }
    else if (parameterID == Ids::depth)
    {
        chorus.setDepth (newValue);
    }
}

//==============================================================================
const juce::String ChorusDemoAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ChorusDemoAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ChorusDemoAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ChorusDemoAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ChorusDemoAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ChorusDemoAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ChorusDemoAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ChorusDemoAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String ChorusDemoAudioProcessor::getProgramName (int index)
{
    return {};
}

void ChorusDemoAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void ChorusDemoAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();
    chorus.prepare (spec);
    
    chorus.setRate (state.getRawParameterValue (Ids::rate)->load());
    chorus.setDepth (state.getRawParameterValue (Ids::depth)->load());
    chorus.setCentreDelay (7.0f);
    chorus.setFeedback (0.1f);
    chorus.setMix (0.5f);
}

void ChorusDemoAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ChorusDemoAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void ChorusDemoAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    dsp::AudioBlock<float> block (buffer);
    dsp::ProcessContextReplacing<float> context (block);
    chorus.process (context);
}

//==============================================================================
bool ChorusDemoAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* ChorusDemoAudioProcessor::createEditor()
{
    return new ChorusDemoAudioProcessorEditor (*this);
}

//==============================================================================
void ChorusDemoAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    copyXmlToBinary (*state.state.createXml(), destData);
}

void ChorusDemoAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto xml = getXmlFromBinary (data, sizeInBytes);
    state.state = ValueTree::fromXml (*xml);
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ChorusDemoAudioProcessor();
}
