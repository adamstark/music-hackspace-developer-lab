
#include "MusicHelpers.h"

int MusicHelpers::frequencyToMidiNote (double frequency)
{
  if (frequency <= 0.0)
    return 0;
    
  return static_cast<int> (round (69.0 + 12.0 * log2(frequency / 	440.0)));
}

double MusicHelpers::midiNoteToFrequency (int midiNote)
{
  return 440.0 * pow (2.0, (midiNote - 69) / 12.0);
}

double MusicHelpers::gainToDecibels (double gain)
{
  return 20.0 * log10 (gain);
}

double MusicHelpers::decibelsToGain (double decibels)
{
  return pow (10.0, decibels / 20.0);
}

double MusicHelpers::samplesToSeconds (int samples, double sampleRate)
{
  if (sampleRate <= 0.0)
    return 0.0;

  return static_cast<double> (samples) / sampleRate;
}

int MusicHelpers::secondsToSamples (double seconds, double sampleRate)
{
  if (seconds < 0.0 || sampleRate <= 0.0)
    return 0;

  return static_cast<int> (round (seconds * sampleRate));
}