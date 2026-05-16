
#pragma once

#include <iostream>

class MusicHelpers
{
public:
    static int frequencyToMidiNote (double frequency);
    static double midiNoteToFrequency (int midiNote);
    static double gainToDecibels (double gain);
    static double decibelsToGain (double decibels);
    static double samplesToSeconds (int samples, double sampleRate);
    static int secondsToSamples (double seconds, double sampleRate);
};