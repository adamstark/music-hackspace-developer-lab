/*
  ==============================================================================

    FileLoader.h
    Created: 12 May 2026 10:17:50pm
    Author:  Adam Stark

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class FileLoader    :   public Thread
{
public:
    FileLoader (Label* textLabel);
    
    // Thread
    void run() override;
    
private:
    
    Component::SafePointer<Label> textLabel;
};
