/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class Tremolo_beta_0_1AudioProcessorEditor  : public AudioProcessorEditor,
                                                public Button::Listener,
                                                public Slider::Listener
{
public:
    Tremolo_beta_0_1AudioProcessorEditor (Tremolo_beta_0_1AudioProcessor&);
    ~Tremolo_beta_0_1AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    
    void buttonClicked (Button* button) override;
    void sliderValueChanged(Slider* slider) override;

private:

    //ScopedPointer<HackAudio::Slider> lfoShapeKnob;
    
    HackAudio::Slider phaseKnob;
    HackAudio::Slider crossoverKnob;
    HackAudio::Slider symmetryKnob;
    HackAudio::Slider depthKnob;
    HackAudio::Slider rateKnob;
    HackAudio::Slider pingPongKnob;
    HackAudio::Slider toneKnob;
    
    juce::Label phaseLabel;
    juce::Label crossoverLabel;
    juce::Label symmetryLabel;
    juce::Label depthLabel;
    juce::Label rateLabel;
    juce::Label toneLabel;
    juce::Label pingPongLabel;

//    HackAudio::Label phaseLabel;
//    HackAudio::Label crossoverLabel;
//    HackAudio::Label symmetryLabel;
//    HackAudio::Label depthLabel;
 //   HackAudio::Label rateLabel;
//    HackAudio::Label toneLabel;
//    HackAudio::Label pingPongLabel;
    
    HackAudio::Button pluginSourceButton;
    HackAudio::Button hostSourceButton;
    
    HackAudio::Button sineButton;
    HackAudio::Button squareButton;
    HackAudio::Button triangleButton;
    HackAudio::Button rampUpButton;
    HackAudio::Button rampDownButton;
    HackAudio::Button sweepButton;
    HackAudio::Button lumpsButton;
    HackAudio::Button randomButton;
    
    HackAudio::Button sixteenthButton;
    HackAudio::Button eighthButton;
    HackAudio::Button eighthTripButton;
    HackAudio::Button quarterButton;
    HackAudio::Button quarterTripButton;
    HackAudio::Button halfButton;
    
    HackAudio::Button normalTremButton;
    HackAudio::Button trebleTremButton;
    HackAudio::Button bassTremButton;
    HackAudio::Button phaseTremButton;
    
    HackAudio::FlexBox flexButtons;
    HackAudio::FlexBox flexKnobs;
    HackAudio::FlexBox flexWaves;
    HackAudio::FlexBox flexNote;
    HackAudio::FlexBox flexTremType;

 
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> phaseAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> crossoverAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> symmetryAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> depthAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rateAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> toneAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rateSourceAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> pingPongAttachment;
    
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> buttonAttachment;
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> multiplierAttachment;
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> tremoloTypeAttachment;
    
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sineAttachment;

    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Tremolo_beta_0_1AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Tremolo_beta_0_1AudioProcessorEditor)
};
