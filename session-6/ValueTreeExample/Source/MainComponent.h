#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  :  public juce::Component,
                        private ValueTree::Listener
{
public:
    
    struct Ids
    {
        static const Identifier rectangleX;
        static const Identifier rectangleY;
        static const Identifier rectangleWidth;
        static const Identifier rectangleHeight;
        static const Identifier textLabel;
    };
    
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    void valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged, const Identifier& property) override;
    
    void saveState();
    void loadState();
    
    ValueTree tree;
    Slider rectangleXSlider;
    Slider rectangleWidthSlider;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
