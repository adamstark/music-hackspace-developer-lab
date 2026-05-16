#include "doctest/doctest.h"
#include "MusicHelpers.h"

TEST_CASE("frequencyToMidiNote()") 
{
    CHECK (MusicHelpers::frequencyToMidiNote (440.0) == 69);
    CHECK (MusicHelpers::frequencyToMidiNote (392.0) == 67);
    CHECK (MusicHelpers::frequencyToMidiNote (1864.66) == 94);

    // dealing with stupid input...
    CHECK (MusicHelpers::frequencyToMidiNote (-100.0) == 0);
}

TEST_CASE("midiNoteToFrequency()") 
{
    CHECK (doctest::Approx (MusicHelpers::midiNoteToFrequency (69)) == 440.0);
    CHECK (doctest::Approx (MusicHelpers::midiNoteToFrequency (67)) == 392.0);
    CHECK (doctest::Approx (MusicHelpers::midiNoteToFrequency (94)) == 1864.66);
}

TEST_CASE("gainToDecibels()") 
{
    CHECK (doctest::Approx (MusicHelpers::gainToDecibels (1.0)) == 0.0);
    CHECK (doctest::Approx (MusicHelpers::gainToDecibels (0.5)) == -6.02059);
    CHECK (doctest::Approx (MusicHelpers::gainToDecibels (0.25)) == -12.0412);
}

TEST_CASE("decibelsToGain()") 
{
    CHECK (doctest::Approx (MusicHelpers::decibelsToGain (0.0)) == 1.0);
    CHECK (doctest::Approx (MusicHelpers::decibelsToGain (-6.02059)) == 0.5);
    CHECK (doctest::Approx (MusicHelpers::decibelsToGain (-12.0412)) == 0.25);
}

TEST_CASE("samplesToSeconds()")
{
    CHECK (doctest::Approx (MusicHelpers::samplesToSeconds (44100, 44100.0)) == 1.0);
    CHECK (doctest::Approx (MusicHelpers::samplesToSeconds (22050, 44100.0)) == 0.5);
    CHECK (doctest::Approx (MusicHelpers::samplesToSeconds (96000, 96000.0)) == 1.0);

    // Edge cases
    CHECK (doctest::Approx (MusicHelpers::samplesToSeconds (22050, -500.0)) == 0.0);
}

TEST_CASE("secondsToSamples()")
{
    CHECK (MusicHelpers::secondsToSamples (1.0, 44100.0) == 44100);
    CHECK (MusicHelpers::secondsToSamples (0.5, 44100.0) == 22050);
    CHECK (MusicHelpers::secondsToSamples (1.0, 96000.0) == 96000);

    // Edge cases
    CHECK (MusicHelpers::secondsToSamples (-1.0, 44100.0) == 0);
    CHECK (MusicHelpers::secondsToSamples (1.0, -500.0) == 0);  
}