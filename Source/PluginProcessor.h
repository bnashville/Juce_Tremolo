/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class Tremolo_beta_0_1AudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Tremolo_beta_0_1AudioProcessor();
    ~Tremolo_beta_0_1AudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //my variables
    
    // Wave Type Variable
    // This variable can be used to change between different types of algorithms
    
    int accentFlag = 1;
    
    // 0 - Sine, 1 - Square, 2 - Triangle, 3 - RampUp, 4 - rampdown, 5 - sweep, 6 - lumps, 7 - random
    int waveAlgorithm = 0;
    int rateSourceAlgorithm = 1;
    float multiplierAlgorithm = 8;
    int tremTypeAlgorithm = 0;
    
    //EQ Processing Values
    int f0 = 2000;
    int f0Tone = 100;
    float w0 = 0;
    float w0Tone = 0;
    float alpha = 1;
    float alphaTone = 1;
    float Q = 0.707;
    float QTone = 0.707;
    
    float b0LPF =  1;
    float b1LPF =   1;
    float b2LPF =  1;
    float a0LPF =   1;
    float a1LPF =  1;
    float a2LPF = 1;
    float bassOutput[3][2] = {0};
    
    
    float b0HPF =  1;
    float b1HPF =   1;
    float b2HPF =  1;
    float a0HPF =   1;
    float a1HPF =  1;
    float a2HPF = 1;
    float trebleOutput[3][2] = {0};
    
    
    float b0Tone =  1;
    float b1Tone =   1;
    float b2Tone =  1;
    float a0Tone =   1;
    float a1Tone =  1;
    float a2Tone = 1;
    float toneOutput[3][2] = {0};
     
    float PrevSample[3][2]; 
    
    float tone = 20000;

    AudioProcessorValueTreeState& getState();
    
private:
    int Fs = 1;
    float amp = 1;
    float offset = 1;
    float rateMs = 1;
    float rateHz = 1;
    float lfoPeriod = 1;
    float freqTop = 1;
    float freqBottom = 1;
    float periodTop = 1;
    float periodBottom = 1;
    float samplesStart = 1;
    float samplesEnd = 1;
    float duration = 1;
    float slopeStart = 1;
    float slopeEnd = 1;
    float multiplierNumber =1;
    double BPM;
    
    //More EQ
    float recombineSignal = 1;
    float modulatedTreble = 1;
    float modulatedBass = 1;
    
    //LFO Params
    float currentAngle[2] = {0};
    float lfoCurrentValue[2] = {1};
    float lfoLastValue[2] = {1};
           
    float thetaTop = 1;
    float thetaBottom = 1;
    float thetaTopSaw = 1;
    float thetaBottomSaw = 1;
    
    
    int64 currentPositionSamples;
    int currentPositionQuarters;
    int currentBeatQuarters;
    int timeSigNumerator;
    float currentPositionRadians;
    float calculatedPhaseOffset;
    //bool firstRunFlag = 1;
    
    float pi = 3.141592653589793238;
    float mod = 1;
    
    //long long xx;
    //double oneQuarterInSeconds;
   // long long zz;
    double currentPositionSeconds;
    
    int randomFlag = 0;
    int slopeFlag = 1;
    
    double notesPerBeat = 1;
    double notesPerSecond =  1;
    double  oneBeatInSeconds = 1;
    double currentPositionInMultiplierNotes = 1;
   double currentBeatInMultiplierNotes = 1;
    float accentModifier = 1;
    
    AudioPlayHead* playHead;
    AudioPlayHead::CurrentPositionInfo currentPositionInfo;
    
    ScopedPointer<AudioProcessorValueTreeState> state;
    
    float randNum = rand()%(1-0 + 1) + 0;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Tremolo_beta_0_1AudioProcessor)
};
