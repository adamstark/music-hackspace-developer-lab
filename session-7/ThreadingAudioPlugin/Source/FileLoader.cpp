/*
  ==============================================================================

    FileLoader.cpp
    Created: 12 May 2026 10:17:50pm
    Author:  Adam Stark

  ==============================================================================
*/

#include "FileLoader.h"

FileLoader::FileLoader (Label* label)
 :  Thread ("FileLoader"),
    textLabel (label)
{
    
}

void FileLoader::run()
{
    MessageManager::callAsync ([this]()
    {
        if (textLabel != nullptr)
            textLabel.getComponent()->setText ("Loading...", dontSendNotification);
    });
    
    Thread::sleep (5000);
    
    MessageManager::callAsync ([this]()
    {
        if (textLabel != nullptr)
            textLabel.getComponent()->setText ("Loaded", dontSendNotification);
    });
}
