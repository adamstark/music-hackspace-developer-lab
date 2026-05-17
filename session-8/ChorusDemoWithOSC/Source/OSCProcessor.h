/*
  ==============================================================================

    OSCProcessor.h
    Created: 16 May 2026 8:28:28pm
    Author:  Adam Stark

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class OSCProcessor  :   public OSCReceiver::Listener<OSCReceiver::RealtimeCallback>
{
public:
    OSCProcessor (AudioProcessorValueTreeState& state);
    ~OSCProcessor();
    
    void oscMessageReceived (const OSCMessage& message) override;
    
    void updateRate (float rate);
    void updateDepth (float depth);
    
private:
    
    OSCReceiver oscReceiver;
    OSCSender oscSender;
    RangedAudioParameter* rateParameter;
    RangedAudioParameter* depthParameter;
};
