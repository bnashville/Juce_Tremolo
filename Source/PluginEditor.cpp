/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Tremolo_beta_0_1AudioProcessorEditor::Tremolo_beta_0_1AudioProcessorEditor (Tremolo_beta_0_1AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{


    //Settings for the rate
    rateKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    rateKnob.addListener(this);
    rateKnob.setSize(100,100);
    rateKnob.setPipCount(14);
    rateKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    //rateKnob.setRange(30,380);
    //rateKnob.setDefaultValue(true, 80);
    addAndMakeVisible(rateKnob);
    
    rateLabel.setText("Rate", dontSendNotification);
    rateLabel.setFont(HackAudio::Fonts::NowRegular);
    rateLabel.setColour(juce::Label::textColourId, HackAudio::Colours::White);
    rateLabel.setJustificationType(Justification::centred);
    rateLabel.attachToComponent(&rateKnob, false); // 'false' is to put it on top
    addAndMakeVisible(rateLabel);
    
    //Settings for the symmetryKnob
    symmetryKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    symmetryKnob.addListener(this);
    symmetryKnob.setSize(75,75);
    symmetryKnob.setPipCount(9);
    symmetryKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    //symmetryKnob.setRange(0.3,1.7);
    //symmetryKnob.setDefaultValue(true, 1);
    addAndMakeVisible(symmetryKnob);
    
    symmetryLabel.setText("Symmetry", dontSendNotification);
    symmetryLabel.setFont(HackAudio::Fonts::NowRegular);
    symmetryLabel.setColour(juce::Label::textColourId, HackAudio::Colours::White);
    symmetryLabel.setJustificationType(Justification::centred);
    symmetryLabel.attachToComponent(&symmetryKnob, false); // 'false' is to put it on top
    addAndMakeVisible(symmetryLabel);
    
    //Settings for the phase knob
    phaseKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    phaseKnob.addListener(this);
    phaseKnob.setSize(75,75);
    phaseKnob.setPipCount(9);
    phaseKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    //phaseKnob.setRange(0.0,2*6.28318530718);
    //phaseKnob.setDefaultValue(true, 0);
    addAndMakeVisible(phaseKnob);
    

    phaseLabel.setText("Phase Offset", dontSendNotification);
    phaseLabel.setFont(HackAudio::Fonts::NowRegular);
    phaseLabel.setColour(juce::Label::textColourId, HackAudio::Colours::White);
    //gainLabel.setFont(Font & "Raleway");
    phaseLabel.setJustificationType(Justification::centred);
    phaseLabel.attachToComponent(&phaseKnob, false); // 'false' is to put it on top
    addAndMakeVisible(phaseLabel);
    
    //Settings for the crossoverKnob
    accentKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    accentKnob.addListener(this);
    accentKnob.setSize(75,75);
    accentKnob.setPipCount(9);
    accentKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    //accentKnob.setRange(30,20000);
    addAndMakeVisible(accentKnob);
    
    //Settings for accent knob
    accentLabel.setText("Accent", dontSendNotification);
    accentLabel.setFont(HackAudio::Fonts::NowRegular);
    accentLabel.setColour(juce::Label::textColourId, HackAudio::Colours::White);
    accentLabel.setJustificationType(Justification::centred);
    accentLabel.attachToComponent(&accentKnob, false); // 'false' is to put it on top
    addAndMakeVisible(accentLabel);
    
    //Settings for the crossoverKnob
    crossoverKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    crossoverKnob.addListener(this);
    crossoverKnob.setSize(75,75);
    crossoverKnob.setPipCount(9);
    crossoverKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    //crossoverKnob.setRange(30,20000);
    addAndMakeVisible(crossoverKnob);


    crossoverLabel.setText("Crossover", dontSendNotification);
    crossoverLabel.setFont(HackAudio::Fonts::NowRegular);
    crossoverLabel.setColour(juce::Label::textColourId, HackAudio::Colours::White);
    crossoverLabel.setJustificationType(Justification::centred);
    crossoverLabel.attachToComponent(&crossoverKnob, false); // 'false' is to put it on top
    addAndMakeVisible(crossoverLabel);


    //Settings for the pingPong switch
    pingPongKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    pingPongKnob.addListener(this);
    pingPongKnob.setSize(75,75);
    pingPongKnob.setPipCount(9);
    pingPongKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    //pingPongKnob.setRange(0,3.14);
   // pingPongKnob.setDefaultValue(true, 1);
    addAndMakeVisible(pingPongKnob);
    
    pingPongLabel.setText("Ping Pong", dontSendNotification);
    pingPongLabel.setFont(HackAudio::Fonts::NowRegular);
    pingPongLabel.setColour(juce::Label::textColourId, HackAudio::Colours::White);
    pingPongLabel.setJustificationType(Justification::centred);
    pingPongLabel.attachToComponent(&pingPongKnob, false); // 'false' is to put it on top
    addAndMakeVisible(pingPongLabel);
    
    
    //Settings for the depthKnob
    depthKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    depthKnob.addListener(this);
    depthKnob.setSize(100,100);
    depthKnob.setPipCount(14);
    depthKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    //depthKnob.setRange(0,100);
    //depthKnob.setDefaultValue(true, 50);
    addAndMakeVisible(depthKnob);
    
    depthLabel.setText("Depth", dontSendNotification);
    depthLabel.setFont(HackAudio::Fonts::NowRegular);
    depthLabel.setColour(juce::Label::textColourId, HackAudio::Colours::White);
    depthLabel.setJustificationType(Justification::centred);
    depthLabel.attachToComponent(&depthKnob, false); // 'false' is to put it on top
    addAndMakeVisible(depthLabel);
    
    
    //------------------TOGGLE BUTTONS, ROW 0, RATE SOURCE-------------
    //rate source button
    pluginSourceButton.addListener(this);
    pluginSourceButton.setButtonText("Plugin");
    pluginSourceButton.setConnectedEdges(Button::ConnectedOnRight);
    pluginSourceButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    pluginSourceButton.setSize(70,30);
    pluginSourceButton.setRadioGroupId(4);
    pluginSourceButton.setToggleState(true, dontSendNotification);
    addAndMakeVisible(pluginSourceButton);
    
    hostSourceButton.addListener(this);
    hostSourceButton.setButtonText("Host");
    hostSourceButton.setConnectedEdges(Button::ConnectedOnLeft);
    hostSourceButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    hostSourceButton.setSize(70,30);
    hostSourceButton.setRadioGroupId(4);
    addAndMakeVisible(hostSourceButton);
    
    // ------------------------TOGGLE BUTTONS, ROW 1, WAVE TYPE -----------------
    
    
    // Various settings for the sine wave button
    sineButton.addListener(this);
    //sineButton.setColour(3, juce::Colours::gold);
    sineButton.setButtonText("Sine");
    sineButton.setConnectedEdges(Button::ConnectedOnRight);
    sineButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    sineButton.setSize(90,40);
    sineButton.setRadioGroupId(1);
    sineButton.setToggleState(true, dontSendNotification);
    addAndMakeVisible(sineButton);
    
    // Various settings for the square wave button
    squareButton.addListener(this);
    squareButton.setButtonText("Square");
    squareButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    squareButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    squareButton.setSize(90,40);
    squareButton.setRadioGroupId(1);
    addAndMakeVisible(squareButton);
    
    // Various settings for the triangle wave button
    triangleButton.addListener(this);
    triangleButton.setButtonText("Triangle");
    triangleButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    triangleButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    triangleButton.setSize(90,40);
    triangleButton.setRadioGroupId(1);
    addAndMakeVisible(triangleButton);
    
    // Various settings for the rampUp wave button
    rampUpButton.addListener(this);
    rampUpButton.setButtonText("Saw Up");
    rampUpButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    rampUpButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    rampUpButton.setSize(90,40);
    rampUpButton.setRadioGroupId(1);
    addAndMakeVisible(rampUpButton);
    
    // Various settings for the rampDown wave button
    rampDownButton.addListener(this);
    rampDownButton.setButtonText("Saw Down");
    rampDownButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    rampDownButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    rampDownButton.setSize(90,40);
    rampDownButton.setRadioGroupId(1);
    addAndMakeVisible(rampDownButton);
    
    // Various settings for the sweep wave button
    sweepButton.addListener(this);
    sweepButton.setButtonText("Sweep");
    sweepButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    sweepButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    sweepButton.setSize(90,40);
    sweepButton.setRadioGroupId(1);
    addAndMakeVisible(sweepButton);
    
    // Various settings for the lumps wave button
    lumpsButton.addListener(this);
    lumpsButton.setButtonText("Lumps");
    lumpsButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    lumpsButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    lumpsButton.setSize(90,40);
    lumpsButton.setRadioGroupId(1);
    addAndMakeVisible(lumpsButton);
    
    // Various settings for the random wave button
    randomButton.addListener(this);
    randomButton.setButtonText("Random");
    randomButton.setConnectedEdges(Button::ConnectedOnLeft);
    randomButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    randomButton.setSize(90,40);
    randomButton.setRadioGroupId(1);
    addAndMakeVisible(randomButton);
 
    // ------------------------TOGGLE BUTTONS, ROW 2, NOTE VALUE  -----------------
    
    
    // Various settings for the sixteenth note button
    sixteenthButton.addListener(this);
    sixteenthButton.setButtonText("Sixteenth");
    sixteenthButton.setConnectedEdges(Button::ConnectedOnRight);
    sixteenthButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    sixteenthButton.setSize(90,40);
    sixteenthButton.setRadioGroupId(2);
    addAndMakeVisible(sixteenthButton);
    
    // Various settings for the eighth note button
    eighthButton.addListener(this);
    eighthButton.setButtonText("Eighth");
    eighthButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    eighthButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    eighthButton.setSize(90,40);
    eighthButton.setRadioGroupId(2);
    eighthButton.setToggleState(true, dontSendNotification);
    addAndMakeVisible(eighthButton);
    
    // Various settings for the eighth triplet note button
    eighthTripButton.addListener(this);
    eighthTripButton.setButtonText("E. Triplet");
    eighthTripButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    eighthTripButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    eighthTripButton.setSize(90,40);
    eighthTripButton.setRadioGroupId(2);
    addAndMakeVisible(eighthTripButton);
    
    // Various settings for the dotted eighth note button
    eighthDotButton.addListener(this);
    eighthDotButton.setButtonText("Dot Eighth");
    eighthDotButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    eighthDotButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    eighthDotButton.setSize(90,40);
    eighthDotButton.setRadioGroupId(2);
    addAndMakeVisible(eighthDotButton);

    
    // Various settings for the quarter note button
    quarterButton.addListener(this);
    quarterButton.setButtonText("Quarter");
    quarterButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    quarterButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    quarterButton.setSize(90,40);
    quarterButton.setRadioGroupId(2);
    addAndMakeVisible(quarterButton);
    
    // Various settings for the quarter triplet note button
    quarterTripButton.addListener(this);
    quarterTripButton.setButtonText("Q. Triplet");
    quarterTripButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    quarterTripButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    quarterTripButton.setSize(90,40);
    quarterTripButton.setRadioGroupId(2);
    addAndMakeVisible(quarterTripButton);
    
    // Various settings for the half note button
    halfButton.addListener(this);
    halfButton.setButtonText("Half");
    halfButton.setConnectedEdges(Button::ConnectedOnLeft);
    halfButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    halfButton.setSize(90,40);
    halfButton.setRadioGroupId(2);
    addAndMakeVisible(halfButton);

    // ------------------------TOGGLE BUTTONS, ROW 3, TREMOLO TYPE   -----------------
    
    
    // Various settings for the normal tremolo button
    normalTremButton.addListener(this);
    normalTremButton.setButtonText("Normal");
    normalTremButton.setConnectedEdges(Button::ConnectedOnRight);
    normalTremButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    normalTremButton.setSize(90,40);
    normalTremButton.setRadioGroupId(3);
    normalTremButton.setToggleState(true, dontSendNotification);
    addAndMakeVisible(normalTremButton);
    
    // Various settings for the normal tremolo treble only button
    trebleTremButton.addListener(this);
    trebleTremButton.setButtonText("Treble Only");
    trebleTremButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    trebleTremButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    trebleTremButton.setSize(90,40);
    trebleTremButton.setRadioGroupId(3);
    addAndMakeVisible(trebleTremButton);
    
    // Various settings for the normal tremolo bass only button
    bassTremButton.addListener(this);
    bassTremButton.setButtonText("Bass Only");
    bassTremButton.setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    bassTremButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    bassTremButton.setSize(90,40);
    bassTremButton.setRadioGroupId(3);
    addAndMakeVisible(bassTremButton);
    
    // Various settings for the out of phase tremolo button
    phaseTremButton.addListener(this);
    phaseTremButton.setButtonText("Out of Phase");
    phaseTremButton.setConnectedEdges(Button::ConnectedOnLeft);
    phaseTremButton.setButtonStyle(HackAudio::Button::ButtonStyle::BarToggle);
    phaseTremButton.setSize(100,40);
    phaseTremButton.setRadioGroupId(3);
    addAndMakeVisible(phaseTremButton);
    
    
    
    //-------------------FLEX BOX ITEMS ----------------
    
    //Flex box for rate source button
    flexButtons.addComponent(pluginSourceButton);
    flexButtons.addComponent(hostSourceButton);
    
    flexButtons.setJustifyContent(juce::FlexBox::JustifyContent::center);
    flexButtons.applyBounds(juce::Rectangle<int>(0,15,850,140));
    
    //Flex box for knobs
    flexKnobs.addComponent(rateKnob);
    flexKnobs.addComponent(symmetryKnob);
    flexKnobs.addComponent(phaseKnob);
    flexKnobs.addComponent(accentKnob);
    //flexKnobs.addComponent(toneKnob);
    flexKnobs.addComponent(crossoverKnob);
    flexKnobs.addComponent(pingPongKnob);
    flexKnobs.addComponent(depthKnob);

    flexKnobs.applyBounds(juce::Rectangle<int>(550/5,0,650,345));
    
    // Flex Box for wave Buttons
    flexWaves.addComponent(sineButton);
    flexWaves.addComponent(squareButton);
    flexWaves.addComponent(triangleButton);
    flexWaves.addComponent(rampUpButton);
    flexWaves.addComponent(rampDownButton);
    flexWaves.addComponent(sweepButton);
    flexWaves.addComponent(lumpsButton);
    flexWaves.addComponent(randomButton);
    
    flexWaves.setJustifyContent(juce::FlexBox::JustifyContent::center);
    flexWaves.applyBounds(juce::Rectangle<int>(0,0,850,515));
    
    // Flex Box for note Buttons
    flexNote.addComponent(sixteenthButton);
    flexNote.addComponent(eighthTripButton);
    flexNote.addComponent(eighthButton);
    flexNote.addComponent(eighthDotButton);
    flexNote.addComponent(quarterTripButton);
    flexNote.addComponent(quarterButton);
    flexNote.addComponent(halfButton);
    
    flexNote.setJustifyContent(juce::FlexBox::JustifyContent::center);
    flexNote.applyBounds(juce::Rectangle<int>(0,0,850,615));

    // Flex Box for tremolo type Buttons
    flexTremType.addComponent(normalTremButton);
    flexTremType.addComponent(trebleTremButton);
    flexTremType.addComponent(bassTremButton);
    flexTremType.addComponent(phaseTremButton);
    
    flexTremType.setJustifyContent(juce::FlexBox::JustifyContent::center);
    flexTremType.applyBounds(juce::Rectangle<int>(0,0,850,715));

    
    
    phaseAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"phase", phaseKnob);
    crossoverAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"crossover", crossoverKnob);
    symmetryAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"symmetry", symmetryKnob);
    depthAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"depth", depthKnob);
    rateAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"rate", rateKnob);
    toneAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"tone", toneKnob);
    //rateSourceAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"rateSource", rateSourceKnob);
   pingPongAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"pingPong", pingPongKnob);
    accentAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"accent", accentKnob);
    
   
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
     setSize (850, 400);
    
}

Tremolo_beta_0_1AudioProcessorEditor::~Tremolo_beta_0_1AudioProcessorEditor()
{
}

//==============================================================================
void Tremolo_beta_0_1AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::blueviolet);
    g.setFont (15.0f);
    
    Font titleFont = HackAudio::Fonts::NowBold;
    titleFont.setHeight(30);
    
    g.setFont(titleFont);
    //g.setColour (juce::Colours::blue);
    g.drawFittedText ("iconic",0, 20, 740, 25, Justification::centred, 1.0);
    g.setColour (juce::Colours::gold);//g.setColour (Colours::cyan);
    g.drawFittedText ("tremolo",0, 20, 970, 25, Justification::centred, 1.0);

    
}

void Tremolo_beta_0_1AudioProcessorEditor::resized()
{

  
    
}


void Tremolo_beta_0_1AudioProcessorEditor::buttonClicked(Button* button)
{

    
    //------RATE SOURCE VALUES --------
    if (button == &pluginSourceButton) {
        processor.rateSourceAlgorithm = 1;
        rateKnob.setEnabled(true);
    }
    if (button == &hostSourceButton) {
        processor.rateSourceAlgorithm = 0;
        rateKnob.setEnabled(false);
    }
    
    //---------WAVETYPE VALUES-------------------
if (button == &sineButton) {
    processor.waveAlgorithm = 0;
    pingPongKnob.setEnabled(true);
    phaseKnob.setEnabled(true);

}
if (button == &squareButton) {
    processor.waveAlgorithm = 1;
    pingPongKnob.setEnabled(true);
    phaseKnob.setEnabled(true);
    

}
if (button == &triangleButton) {
    processor.waveAlgorithm = 2;
    pingPongKnob.setEnabled(true);
    phaseKnob.setEnabled(true);

}
if (button == &rampUpButton) {
    processor.waveAlgorithm = 3;
    pingPongKnob.setEnabled(true);
    phaseKnob.setEnabled(true);

}
if (button == &rampDownButton) {
    processor.waveAlgorithm = 4;
    pingPongKnob.setEnabled(true);
    phaseKnob.setEnabled(true);

}
if (button == &sweepButton) {
    processor.waveAlgorithm = 5;
    pingPongKnob.setEnabled(true);
    phaseKnob.setEnabled(true);

}
if (button == &lumpsButton) {
    processor.waveAlgorithm = 6;
    pingPongKnob.setEnabled(true);
    phaseKnob.setEnabled(true);
}
if (button == &randomButton) {
    processor.waveAlgorithm = 7;
    pingPongKnob.setEnabled(false);
    phaseKnob.setEnabled(false);
    
}

 //--------------NOTE MULTIPLIER VALUES-------------
if (button == &sixteenthButton) {
    processor.multiplierAlgorithm = 16;  }
    if (button == &eighthTripButton) {
        processor.multiplierAlgorithm = 12;  } //might want to change this value based on the time signature. e.g. triplet vs. dotted eight
    if (button == &eighthButton) {
        processor.multiplierAlgorithm = 8;  }
    if (button == &eighthDotButton) {
        processor.multiplierAlgorithm = 5.333;  }
    if (button == &quarterTripButton) {
        processor.multiplierAlgorithm = 6;  } //might want to change this value based on the time signature. e.g. triplet vs. dotted eight
    if (button == &quarterButton) {
        processor.multiplierAlgorithm = 4;  }
    if (button == &halfButton) {
        processor.multiplierAlgorithm = 2;  }
//.5, 1, 1.5, 2, 3, 4
 //------------TREMTYPE VALUES----------------------
  
    if (button == &normalTremButton) {
        processor.tremTypeAlgorithm = 0;
            crossoverKnob.setEnabled(false);
    }
    if (button == &trebleTremButton) {
        processor.tremTypeAlgorithm = 1;
            crossoverKnob.setEnabled(true);
    }
    if (button == &bassTremButton) {
        processor.tremTypeAlgorithm = 2;
            crossoverKnob.setEnabled(true);
    }
    if (button == &phaseTremButton) {
        processor.tremTypeAlgorithm = 3;
            crossoverKnob.setEnabled(true);
    }

    
}

void Tremolo_beta_0_1AudioProcessorEditor::sliderValueChanged(Slider* slider){
//-----LABEL CHANGES, UPDATES THE KNOB LABELS WHEN USER CHANGES A PARAMETER---------
    if (!isShowing()) return;
    
    if (slider == &rateKnob) {
      rateLabel.setText(String(rateKnob.getValue(),1),dontSendNotification);
    }
        if (slider == &accentKnob) {
            accentLabel.setText(String(accentKnob.getValue(),1),dontSendNotification);
    }
    if (slider == &symmetryKnob) {
        symmetryLabel.setText(String(symmetryKnob.getValue(),1),dontSendNotification);
    }
    if (slider == &phaseKnob) {
        phaseLabel.setText(String(phaseKnob.getValue(),1),dontSendNotification);
    }
    if (slider == &crossoverKnob) {
        crossoverLabel.setText(String(crossoverKnob.getValue(),1),dontSendNotification);
    }
    if (slider == &pingPongKnob) {
        pingPongLabel.setText(String(pingPongKnob.getValue(),1),dontSendNotification);
    }
    if (slider == &depthKnob) {
        depthLabel.setText(String(depthKnob.getValue(),1),dontSendNotification);
       
    }
    //Starts a timer, after it expires, resets the labels to default values
     startTimer(1200);
}

void Tremolo_beta_0_1AudioProcessorEditor::timerCallback()
{
        stopTimer();
    rateLabel.setText("Rate", dontSendNotification);
    phaseLabel.setText("Phase Offset", dontSendNotification);
    accentLabel.setText("Accent", dontSendNotification);
    symmetryLabel.setText("Symmetry", dontSendNotification);
    depthLabel.setText("Depth", dontSendNotification);
    pingPongLabel.setText("Ping Pong", dontSendNotification);
    crossoverLabel.setText("Crossover", dontSendNotification);

}

