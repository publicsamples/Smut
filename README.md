
# Smut

Smut emerged from the decaying corpse of Shapey, a short lived experiment in oscillator driven file manipulation. Unlike its previous host, Smut  is a semi-modular synthesiser with deep cross modulation options and the ability to freely route between the different modules. Generally speaking, Smut has a dirty, unpredictable quality and offers many opportunities for unrestrained chaos, however in the right hands it can brought to heel and made to sound rather pleasant. 

![Smut](https://raw.githubusercontent.com/publicsamples/Smut/main/Smut.png)

Smut is a semi-modular synthesizer with deep fm and cross modulation options. Smut has three main sound generators, 8 freely routable modulation sources and a lush sounding reverb. 

# The "modules"

Note: Parameters marked with an asterisk can be modulated. 

## Dual Oscillator

Two sawtooth generators with waveshaping and fm controls.

**Pitch** - Determines the pitch of the oscillator (becomes a tempo control when in sync or LFO mode)*

**Step** - Set quantisation of both the pitch controls (becomes a divide control when in sync or LFO mode)

**Pitch Mode** - Select between semitone, tempo sync and LFO modes

**Bend** - Applies a on-note pitch glide

**FM Source** - selects an input source 

**Input** - The FM input amount *

**Shape** - Select a waveshaper 

**Width** - A meta parameter for the waveshaper, performs different functions dependent on selected shape. *
	
**Shape Modes**

 - Tri/Sin - crossfade between a triangle and sine. 
 - PWM - square with width control. 
   Sync1 - "soft" sync effect . 
   Sync2 - A dirtier sync effect
   Fold1 - My "bad at maths" attempt at a wavefolder
   Fold2 - Grottier version of above. Maybe sine squisher would be a better name. 
   User  - "Draw" your own waveform
   
## File

Four crossfading sample players derive their clock from either the oscillators, the modulators or some combination of both. Depending on how things are configured, they can act as waveshapers, lofi-samplers, or crude wavetable players. 

**File Menu** - select a sample

**File manager** - opens the file manager allowing for selection of internal samples

**User Mode** - switches the samplers into user mode allowing you to load your own samples

**Folder Select** - Selects a user folder to populate the file menu

**Position 1-4** - sets the start position for the selected sampler *

**Fade Mode** - select one of three crossfade modes, or put the sample player into mix mode

**X-Fade** - controls the position of the crossfader *

**Mix** - Independent volume control for each sampler

**Quantise** - Steps the output of the position control, useful when working with wavetables

**Global Position** - sets the start position of all samplers *

**Input** - The gain of the incoming signal *

**Source** - Selects the input source

**In Offset** - Offsets the input signal  

**Cutoff** - apples a 1 pole lp/hp filter to the signal from both oscillators

**lp/hp** - switches the filter mode

**Pitch Shifter** - applies a delay based pitch shifter to the file player 

**Pitch** - the pitch shifter value in semitones *

**Feedback** - applies feedback to the delay lines

**Window** - the window length of the delay lines *

## Filter/VCA 1 & 2

Dual combined Filter/VCA module with comprehensive signal routing. 

**Mixer** - Controls which signals pass into the Filter/VCA. Filter 1 has 3 inputs (osc 1, 2 and File) while filter 2 adds a 4th, input Filter 1. This allows the the filters to operate in a serial configuration.

**Cutoff** - Sets the frequency of the filter *

**Q** - The resonance

**Filter Mix** - Mix between a dry signal (no filter) and filtered*

**Type** - Select between low pass, high pass and comb filters (FYI, the lp & hp filters are models of those found in  Korg MS-20, more info [here](https://faustlibraries.grame.fr/libs/vaeffects/#korg-35-filters))

**Gain** -  VCA Gain *

**Pan** -  Stereo filter, innit? *

**Spread** -  Enables an 8 stage pitch/pan effect. 

## Modulation

![enter image description here](https://raw.githubusercontent.com/publicsamples/Smut/refs/heads/main/Smut/Documentation/Images/mod.png)

Unlike previous synths I've created (Oi, Grandad! or Quetzalcoatl for instance), Smuts modulation system allows parameters to be controlled concurrently by mixing the levels of the various modulators. The modulator sections for each module are identical and have the following controls.

**Destination menu** - Select the parameter to be modulated 

**Routing sliders** - Increase the modulation from the labeled modulator

**Master Mod Amount** - Sets the amount of modulation from *all* sources. Control is bi-polar. In the middle position there will no modulation, right 


