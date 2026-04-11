/*
  ==============================================================================

    Oscillator.cpp
    Created: 11 Apr 2026 8:23:21pm
    Author:  Adam Stark

  ==============================================================================
*/

#include "Oscillator.h"

Oscillator::Oscillator (WaveType type, float freq)
 :  waveType (type),
    frequency (freq)
{
    calculatePhaseIncrement();
}

void Oscillator::prepareToPlay (float sr)
{
    sampleRate = sr;
    calculatePhaseIncrement();
}

float Oscillator::getNextSample()
{
    advancePhase();
    
    if (waveType == WaveType::Sine)
        return renderSineWave();
    else if (waveType == WaveType::Sawtooth)
        return renderSawtooth();
    else if (waveType == WaveType::Square)
        return renderSquareWave();
    
    // You didn't implement one of the waveforms
    jassertfalse;
    return 0.f;
}

float Oscillator::renderSineWave()
{
    return std::sin (phase * MathConstants<float>::twoPi);
}

float Oscillator::renderSawtooth()
{
    return (phase * 2.f) - 1.f;
}

float Oscillator::renderSquareWave()
{
    float sineWave = renderSineWave();
    
    if (sineWave >= 0.f)
        return 1.f;
    else
        return -1.f;
}

void Oscillator::calculatePhaseIncrement()
{
    phaseIncrement = frequency / sampleRate;
}

void Oscillator::advancePhase()
{
    phase = phase + phaseIncrement;
    
    if (phase >= 1.f)
        phase = phase - 1.f;
}
