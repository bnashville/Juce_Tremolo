/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Tremolo_beta_0_1AudioProcessor::Tremolo_beta_0_1AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                  .withInput  ("Input",  AudioChannelSet::stereo(), true)
#endif
                  .withOutput ("Output", AudioChannelSet::stereo(), true)
#endif
                  )
#endif
{
    
    state = new AudioProcessorValueTreeState(*this, nullptr);

    state->createAndAddParameter("rate", "Rate", "Rate", NormalisableRange<float>(1.f, 350, .5), 80, nullptr, nullptr);
    state->createAndAddParameter("accent", "Accent", "Accent", NormalisableRange<float>(0, 100, 1), 0, nullptr, nullptr);
    state->createAndAddParameter("depth", "Depth", "Depth", NormalisableRange<float>(0.f, 100.f, 1), 50, nullptr, nullptr);
    state->createAndAddParameter("phase", "Phase", "Phase", NormalisableRange<float>(0, 2*pi, 0), .01, nullptr, nullptr);
    state->createAndAddParameter("symmetry", "Symmetry", "Symmetry", NormalisableRange<float>(0.3, 1.7, .01), 1.0, nullptr, nullptr);
    state->createAndAddParameter("crossover", "Crossover", "Crossover", NormalisableRange<float>(30, 20000, 1), 2000.0, nullptr, nullptr);
    state->createAndAddParameter("pingPong", "PingPong", "PingPong", NormalisableRange<float>(0.f, pi, .001), 0.0, nullptr, nullptr);
    
    state->state = ValueTree("tremolo");
    
}

Tremolo_beta_0_1AudioProcessor::~Tremolo_beta_0_1AudioProcessor()
{
}

//==============================================================================
const String Tremolo_beta_0_1AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Tremolo_beta_0_1AudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool Tremolo_beta_0_1AudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool Tremolo_beta_0_1AudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double Tremolo_beta_0_1AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Tremolo_beta_0_1AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int Tremolo_beta_0_1AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Tremolo_beta_0_1AudioProcessor::setCurrentProgram (int index)
{
}

const String Tremolo_beta_0_1AudioProcessor::getProgramName (int index)
{
    return {};
}

void Tremolo_beta_0_1AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Tremolo_beta_0_1AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
  
}

void Tremolo_beta_0_1AudioProcessor::releaseResources()
{
    
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Tremolo_beta_0_1AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
#else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;
    
    // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif
    
    return true;
#endif
}
#endif
//--------------------------------------------------------------------------------------------
//this is where the money happens
//whatever we do to the 'buffer' is what comes out
void Tremolo_beta_0_1AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    
    
    Fs = getSampleRate();
    
    playHead = this->getPlayHead();
    playHead->getCurrentPosition (currentPositionInfo);
    
    //get tempo & position info from Host
    BPM = currentPositionInfo.bpm;
    currentPositionQuarters = currentPositionInfo.ppqPosition;
    timeSigNumerator = currentPositionInfo.timeSigNumerator;
    currentPositionSeconds = currentPositionInfo.timeInSeconds;
    currentPositionSamples = currentPositionInfo.timeInSamples;
    
    if (currentPositionSamples == 0) {
        currentAngle[0] = 0;
        currentAngle[1] = 0;
        lfoCurrentValue[1] = 1;
        lfoCurrentValue[0] = 1;
    }
    
    //load in values from the GUI knobs
    float phaseOffsetKnob = *state->getRawParameterValue("phase");
    float crossover = *state->getRawParameterValue("crossover");
    float symmetry = *state->getRawParameterValue("symmetry");
    float depth = *state->getRawParameterValue("depth");
    float rate = *state->getRawParameterValue("rate");
    float pingPong = *state->getRawParameterValue("pingPong");
    float accent = *state->getRawParameterValue("accent");
    
    // ----------------------CURRENT POSITION INFORMATION------------------------------
    //get BPM (rate) from host if rateSource GUI switch is set to 0, otherwise, use GUI rate slider for BPM value
    if (rateSourceAlgorithm == 0 ) rate = BPM;
    
    //A bit of math for our accent value. Need to figure out where our accent should be relative to where we are now
    notesPerBeat = multiplierAlgorithm / 4;
    notesPerSecond =  ((notesPerBeat * rate) / 60 );
    oneBeatInSeconds = 1 / notesPerSecond;
    currentPositionInMultiplierNotes = currentPositionSeconds / oneBeatInSeconds;
    currentBeatInMultiplierNotes = fmod(currentPositionInMultiplierNotes,multiplierAlgorithm); //which beat we are on in the measure, divided by multiplierAlgorithm
    
    if (currentBeatInMultiplierNotes <= 1) currentBeatInMultiplierNotes = 1; //avoid currentBeatInMultiplierNotes = 0
    
    //loop through each channel, I.E. Left & Right, or 5.1, etc. -------------------------------------------------------------------
    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        
        //scale the amplitude of lfo based on "depth" GUI slider, and /200 to keep the range <= 1.
        amp = depth/200;
        
        //offset the scaled lfo to keep all values positive
        offset = 1-amp;
        
        //the period of each positive & negative portion of cycle
        lfoPeriod = oneBeatInSeconds;
        periodTop = lfoPeriod * symmetry;
        periodBottom = (2-symmetry) * lfoPeriod;
        
        //based on the symmetry value, we calculate our 2 frequencies; one for the first half of a cycle, one for the second half.
        // this will give us an lfo cycle with a swing to it, based on the symmetry value.
        freqTop = 1/periodTop;
        freqBottom = 1/periodBottom;
        
        //calculate number of samples in one half cycle of the 2 frequencies for all waves != sine, square & rand
        samplesStart = (Fs / freqTop) / 2; //SO samplesStart, for triangle, should be where triangle == 1;
        samplesEnd = (Fs / freqBottom) / 2;
        
        //Here we figure out the current playback position relative to pi, so we can make sure the phase is the same everytime the track plays.
        //We use the modulo operator to return a value less than Fs so that (( currentPositionSamples % Fs)  / Fs )will always be < 1
        currentPositionRadians = ((( currentPositionSamples % Fs)  / Fs) * 2 * pi);
        calculatedPhaseOffset = currentPositionRadians + phaseOffsetKnob;
        
        thetaTop = (2*pi*freqTop) / Fs; //radians per sample
        thetaBottom = (2*pi*freqBottom) / Fs; //radians per sample
        
        thetaTopSaw = (pi*freqTop) / Fs; //radians per sample
        thetaBottomSaw = (pi*freqBottom) / Fs; //radians per sample
        
        //this 'if' takes in the 'pingPong' value and adds or removes phase shift of each channel appropriately
        if (channel == 0) {} //first channel, do nothing
        else if ( channel % 2 == 0) calculatedPhaseOffset = calculatedPhaseOffset - pingPong;  //even channel, remove the phase shift from last channel
        else calculatedPhaseOffset = calculatedPhaseOffset + pingPong; //odd channel, add a phase offset
        
        //if calculatedPhaseOffset breaches 2*pi, take off 2*pi
        if (calculatedPhaseOffset >2*pi) calculatedPhaseOffset = calculatedPhaseOffset - (2*pi);

        //set up duration for the random wave type
         if (waveAlgorithm == 7) duration = round ( ( Fs / rateHz ) * .5 ) ;
        
        
        //----------------------SAMPLE BUFFER ----------------------------------------------------------------------
        
        //loop throught all samples in the buffer
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
            
            //create our next LFO value based on which wave type is selected
            switch(waveAlgorithm) {
                    
                case 0 :  lfoCurrentValue[channel] = sin(currentAngle[channel] + calculatedPhaseOffset); //sine wave
                    break;
                case 1:   lfoCurrentValue[channel] = sin(currentAngle[channel] + calculatedPhaseOffset); //square wave
                    if (lfoCurrentValue[channel] >0) {
                        lfoCurrentValue[channel] = 1;
                    }
                    else if (lfoCurrentValue[channel] <0) {
                        lfoCurrentValue[channel] = -1;
                    }
                    break;
                case 2: lfoCurrentValue[channel] = .6366 * asin(sin(currentAngle[channel]*2 + calculatedPhaseOffset)); //triangle wave
                    break;
                case 3: lfoCurrentValue[channel] = -.6366 * atan((cos(currentAngle[channel]+calculatedPhaseOffset)/sin(currentAngle[channel])+calculatedPhaseOffset)/(2*lfoPeriod)); //ramp up
                    //.6366 = 1/ (pi/2)
                    break;
                case 4: lfoCurrentValue[channel] = .6366 * atan((cos(currentAngle[channel]+calculatedPhaseOffset)/sin(currentAngle[channel])+calculatedPhaseOffset)/(2*lfoPeriod)); //ramp down
                    break;
                case 5: lfoCurrentValue[channel] = sin(currentAngle[channel]/2 + calculatedPhaseOffset); //sweep
                    if (lfoCurrentValue[channel] > 0) {
                        lfoCurrentValue[channel] = -lfoCurrentValue[channel];
                    }
                    break;
                case 6:  lfoCurrentValue[channel] = sin(currentAngle[channel]/2 + calculatedPhaseOffset); //lumps
                    if (lfoCurrentValue[channel] < 0) {
                        lfoCurrentValue[channel] = -lfoCurrentValue[channel];
                    }
                    break;
                case 7:   if (currentPositionSamples == 0 || randomFlag == 0) {
                    //generate a new random value between 0 and 1
                    
                    randNum = randNum = rand()%(1-0 + 1) + 0;
                    lfoCurrentValue[channel] = randNum;
                    randomFlag = 1;
                }
                    
                    //repeat this value until it has been repeated duration # of times
                    if (duration > randomFlag) {
                        lfoCurrentValue[channel] = lfoLastValue[channel];
                        randomFlag = randomFlag + 1;
                    }
                    //generate a new random value and reset the counter
                    else if (duration  <= randomFlag){
                        randomFlag = 1;
                        randNum = rand()%(1-0 + 1) + 0;
                        lfoCurrentValue[channel] = randNum;
                    }
                    break;
            } //end of switch

            //---------------------FINISH OFF THE LFO, ADD ACCENT-----------------
            
            if ((currentBeatInMultiplierNotes == 1) && (lfoCurrentValue[channel] > 0))  mod = amp * lfoCurrentValue[channel] + offset;
            else mod = amp * (1-(accent/100)) * lfoCurrentValue[channel] + (1 - ((accent+depth)/200));
            
            
            //---------------TREMOLO TYPE & OTHER EQ CALCULATIONS-------------------------
            //calculate values and write output buffer based on tremTypeAlgorithm
            if(tremTypeAlgorithm == 0) {
                //normal tremolo, do nothing special
                
                recombineSignal =  mod * buffer.getReadPointer(channel)[sample];
                
            }
            else {
                //for all other cases, need to split signal into 'bass' and 'treble' parts to modify seperately.
                
                f0 = crossover;
                w0 = 2*pi*f0/Fs;
                Q = 0.707;
                alpha = sin(w0)/(2*Q);
                
                //BASS
                //LPF: H(s) = 1 / (s^2 + s/Q + 1)
                b0LPF =  (1 - cos(w0))/2;
                b1LPF =   1 - cos(w0);
                b2LPF =  (1 - cos(w0))/2;
                a0LPF =   1 + alpha;
                a1LPF =  -2*cos(w0);
                a2LPF =   1 - alpha;
                
                //Slide the samples over one position; a circular buffer of sorts?
                PrevSample[2][channel]  = PrevSample[1][channel] ;
                PrevSample[1][channel]  = PrevSample[0][channel] ;
                PrevSample[0][channel]  = buffer.getReadPointer(channel)[sample];
          
                //y[n] = (b0LPF/a0LPF)*x[n] + (b1LPF/a0LPF)*x[n-1] + (b2LPF/a0LPF)*x[n-2] - (a1LPF/a0LPF)*y[n-1] - (a2LPF/a0LPF)*y[n-2];
                bassOutput[0][channel]  = (b0LPF/a0LPF)*PrevSample[0][channel] +
                (b1LPF/a0LPF)*PrevSample[1][channel]  +
                (b2LPF/a0LPF)*PrevSample[2][channel]  -
                (a1LPF/a0LPF)*bassOutput[1][channel]  -
                (a2LPF/a0LPF)*bassOutput[2][channel] ;
                
                //TREBLE
                //HPF: H(s) = s^2 / (s^2 + s/Q + 1)
                b0HPF =  (1 + cos(w0))/2;
                b1HPF = -(1 + cos(w0));
                b2HPF =  (1 + cos(w0))/2;
                a0HPF =   1 + alpha;
                a1HPF =  -2*cos(w0);
                a2HPF =   1 - alpha;
                
                trebleOutput[0][channel]  = (b0HPF/a0HPF)*PrevSample[0][channel]  +
                (b1HPF/a0HPF)*PrevSample[1][channel]  +
                (b2HPF/a0HPF)*PrevSample[2][channel]  -
                (a1HPF/a0HPF)*trebleOutput[1][channel]  -
                (a2HPF/a0HPF)*trebleOutput[2][channel] ;
                
                //---------BUFFERS FOR ALL EQ FUNCTIONS-------------------------
                
                //here is the buffer to keep track of previous values
                
                bassOutput[2][channel]  = bassOutput[1][channel] ;
                bassOutput[1][channel]  = bassOutput[0][channel] ;
                
                trebleOutput[2][channel]  = trebleOutput[1][channel] ;
                trebleOutput[1][channel]  = trebleOutput[0][channel] ;
                
                
                if (tremTypeAlgorithm == 1) {
                    //treble only
                    modulatedTreble = mod * trebleOutput[0][channel] ;
                    modulatedBass = bassOutput[0][channel] ;
                }
                else if (tremTypeAlgorithm == 2) {
                    //bass only
                    modulatedBass = mod * bassOutput[0][channel] ;
                    modulatedTreble = trebleOutput[0][channel] ;
                    
                    
                }
                else if (tremTypeAlgorithm == 3 ) {
                    //bass and treble out of phase
                    modulatedTreble = mod * -trebleOutput[0][channel] ;
                    modulatedBass = mod * bassOutput[0][channel] ;
                    
                }
                
                //processing done, combine bass & treble back into one signal
                recombineSignal = modulatedTreble + modulatedBass;
                
            }
            
            //write the output buffer.
            
            buffer.getWritePointer(channel)[sample] = recombineSignal;
            
            //-----------------------SET PARAMATERS FOR NEXT ITERATION OF LOOP-----------
            
            if (currentAngle[channel] <= pi) //lfo is positive
            {
                if ( (waveAlgorithm == 2) || (waveAlgorithm == 3) || (waveAlgorithm == 4) )
                    currentAngle[channel] = currentAngle[channel] + thetaTopSaw;
                else
                    currentAngle[channel] = currentAngle[channel] + thetaTop;
            }
            else if  (currentAngle[channel] > pi ) //if lfo is negative
            {
                if ( (waveAlgorithm == 2) || (waveAlgorithm == 3) || (waveAlgorithm == 4) )
                    currentAngle[channel] = currentAngle[channel] + thetaBottomSaw;
                else
                    currentAngle[channel] = currentAngle[channel] + thetaBottom;
            }
            
            //full cycle completed of wave
            if (currentAngle[channel] > 2*pi) currentAngle[channel] = currentAngle[channel] - 2*pi;
        
            lfoLastValue[channel] = lfoCurrentValue[channel]; //n-1
            
        } // sample loop
        
    } //channel loop?
} // processor block?


AudioProcessorValueTreeState& Tremolo_beta_0_1AudioProcessor::getState(){
    
    return *state;
    
}

//==============================================================================
bool Tremolo_beta_0_1AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Tremolo_beta_0_1AudioProcessor::createEditor()
{
    return new Tremolo_beta_0_1AudioProcessorEditor (*this);
}

//==============================================================================
void Tremolo_beta_0_1AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    MemoryOutputStream stream(destData, false);
    state->state.writeToStream(stream);
}

void Tremolo_beta_0_1AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    ValueTree tree = ValueTree::readFromData(data, sizeInBytes);
    
    if(tree.isValid()){
        
        state->state = tree;
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Tremolo_beta_0_1AudioProcessor();
}
