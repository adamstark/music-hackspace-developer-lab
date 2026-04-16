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

float Oscillator::renderNaiveSawtooth()
{
    return (phase * 2.f) - 1.f;
}

float Oscillator::renderSawtooth()
{
    float sample = 0.f;
    int maxHarmonics = static_cast<int> ((sampleRate / 2.f) / frequency);
    
    for (int n = 1; n < maxHarmonics; n++)
        sample += std::sin (n * phase * MathConstants<float>::twoPi) / n;
    
    sample = sample * -2.f / MathConstants<float>::pi;
    return sample;
}

float Oscillator::renderNaiveSquareWave()
{
    float sineWave = renderSineWave();
    
    if (sineWave >= 0.f)
        return 1.f;
    else
        return -1.f;
}

float Oscillator::renderSquareWave()
{
    float sample = 0.f;
    int maxHarmonics = static_cast<int> ((sampleRate / 2.f) / frequency);
    
    for (int n = 1; n < maxHarmonics; n += 2)
        sample += std::sin (n * phase * MathConstants<float>::twoPi) / n;
    
    sample = sample * 4.f / MathConstants<float>::pi;
    return sample;
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

void Oscillator::setFrequency (float f)
{
    frequency = f;
    calculatePhaseIncrement();
}
