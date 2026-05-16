/*
  ==============================================================================

    OSCProcessor.cpp
    Created: 16 May 2026 8:28:28pm
    Author:  Adam Stark

  ==============================================================================
*/

#include "OSCProcessor.h"
#include "PluginProcessor.h"

OSCProcessor::OSCProcessor (AudioProcessorValueTreeState& state)
 :  rateParameter (state.getParameter (ChorusDemoAudioProcessor::Ids::rate)),
    depthParameter (state.getParameter (ChorusDemoAudioProcessor::Ids::depth))
{
    oscSender.connect ("127.0.0.1", 8050);
    
    oscReceiver.addListener (this);
    oscReceiver.connect (9050);
}

OSCProcessor::~OSCProcessor()
{
    oscReceiver.removeListener (this);
    oscReceiver.disconnect();
    oscSender.disconnect();
}

void OSCProcessor::updateRate (float rate)
{
    OSCMessage message ("/chorus/rate");
    message.addFloat32 (rate);
    oscSender.send (message);
}

void OSCProcessor::updateDepth (float depth)
{
    OSCMessage message ("/chorus/depth");
    message.addFloat32 (depth);
    oscSender.send (message);
}

void OSCProcessor::oscMessageReceived (const OSCMessage& message)
{
    if (message.getAddressPattern().matches ("/rate"))
    {
        if (message.size() != 1)
            return;
            
        float value = message[0].getFloat32();
        rateParameter->setValueNotifyingHost (rateParameter->convertTo0to1 (value));
        DBG ("RATE: " << value);
    }
    else if (message.getAddressPattern().matches ("/depth"))
    {
        if (message.size() != 1)
            return;
        
        float value = message[0].getFloat32();
        depthParameter->setValueNotifyingHost (depthParameter->convertTo0to1 (value));
        DBG ("DEPTH: " << value);
    }
}
