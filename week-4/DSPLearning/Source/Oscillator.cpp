/*
  ==============================================================================

    Oscillator.cpp
    Created: 11 Apr 2026 8:23:21pm
    Author:  Adam Stark

  ==============================================================================
*/

#include "Oscillator.h"

Oscillator::Oscillator()
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
    return std::sin (phase * MathConstants<float>::twoPi);
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
