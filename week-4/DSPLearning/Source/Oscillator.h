/*
  ==============================================================================

    Oscillator.h
    Created: 11 Apr 2026 8:23:21pm
    Author:  Adam Stark

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class Oscillator
{
public:
    Oscillator();
    
    void prepareToPlay (float sampleRate);
    
    float getNextSample();
    
private:
    
    void advancePhase();
    void calculatePhaseIncrement();
    
    float sampleRate {44100.f};
    float frequency {440.f};
    float phase = 0.f;
    float phaseIncrement = 0.f;
    
};
