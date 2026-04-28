#include "MainComponent.h"

const Identifier MainComponent::Ids::rectangleX ("rectangleX");
const Identifier MainComponent::Ids::rectangleY ("rectangleY");
const Identifier MainComponent::Ids::rectangleWidth ("rectangleWidth");
const Identifier MainComponent::Ids::rectangleHeight ("rectangleHeight");
const Identifier MainComponent::Ids::textLabel ("textLabel");

//==============================================================================
MainComponent::MainComponent()
 :  tree ("STATE")
{
    tree.setProperty (Ids::rectangleX, 200, nullptr);
    tree.setProperty (Ids::rectangleY, 200, nullptr);
    tree.setProperty (Ids::rectangleWidth, 150, nullptr);
    tree.setProperty (Ids::rectangleHeight, 250, nullptr);
    tree.setProperty (Ids::textLabel, "I love ValueTrees", nullptr);
    
    loadState();
    
    rectangleXSlider.setRange (0, 600);
    rectangleXSlider.setValue (tree.getProperty (Ids::rectangleX));
    addAndMakeVisible (rectangleXSlider);
    rectangleXSlider.getValueObject().referTo (tree.getPropertyAsValue (Ids::rectangleX, nullptr));
    
    rectangleWidthSlider.setRange (0, 600);
    rectangleWidthSlider.setValue (tree.getProperty (Ids::rectangleWidth));
    addAndMakeVisible (rectangleWidthSlider);
    rectangleWidthSlider.getValueObject().referTo (tree.getPropertyAsValue (Ids::rectangleWidth, nullptr));
        
    tree.addListener (this);
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
    saveState();
    tree.removeListener (this);
}

//==============================================================================
void MainComponent::saveState()
{
    File stateFile ("~/Desktop/state.xml");
    auto xml = tree.createXml();
    xml->writeTo (stateFile);
}

//==============================================================================
void MainComponent::loadState()
{
    File stateFile ("~/Desktop/state.xml");
    
    if (! stateFile.existsAsFile())
        return;
    
    auto xml = XmlDocument::parse (stateFile);
    tree = ValueTree::fromXml (*xml);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    int rectangleX = tree.getProperty (Ids::rectangleX);
    int rectangleY = tree.getProperty (Ids::rectangleY);
    int rectangleWidth = tree[Ids::rectangleWidth];
    int rectangleHeight = tree[Ids::rectangleHeight];
    String text = tree[Ids::textLabel];
    
    Rectangle<int> rectangleBounds (0, 0, rectangleWidth, rectangleHeight);
    g.setColour (Colours::red);
    g.fillRect (rectangleBounds.withCentre (Point<int> {rectangleX, rectangleY}));
    
    g.setColour (Colours::white);
    g.drawText (text, Rectangle<int> (300, 250, 140, 20), Justification::left);
}

void MainComponent::resized()
{
    Rectangle<int> r (getLocalBounds());
    r.reduce (20, 20);
    rectangleXSlider.setBounds (r.removeFromTop (30));
    r.removeFromTop (10);
    rectangleWidthSlider.setBounds (r.removeFromTop (30));
}

void MainComponent::valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged, const Identifier& property)
{
    if (treeWhosePropertyHasChanged == tree)
    {
        if (property == Ids::rectangleX)
        {
            repaint();
        }
        else if (property == Ids::rectangleWidth)
        {
            repaint(); // duplicate, we could just repaint for all properties
        }
    }
}
