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
    
    enum WaveType
    {
        Sine,
        Sawtooth,
        Square
    };
    
    Oscillator (WaveType waveType, float frequency);
    
    void prepareToPlay (float sampleRate);
    
    float getNextSample();
    
    void setFrequency (float frequency);
    
private:
    
    float renderSineWave();
    float renderNaiveSawtooth();
    float renderSawtooth();
    float renderNaiveSquareWave();
    float renderSquareWave();
    
    void advancePhase();
    void calculatePhaseIncrement();
    
    WaveType waveType {WaveType::Sine};
    float sampleRate {44100.f};
    float frequency {440.f};
    float phase {0.f};
    float phaseIncrement {0.f};
    
};
