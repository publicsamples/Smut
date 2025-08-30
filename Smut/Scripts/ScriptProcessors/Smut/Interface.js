Content.makeFrontInterface(795, 655);

include("laf.js");
include("KnobLAF1.js");
include("KnobLAF2.js");
include("KnobLAF3.js");
include("KnobLAF4.js");
include("Rect.js");
include("Scopes.js");


const var SMUT = Synth.getChildSynth("SMUT");

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "mon");


//osc1 tempo sync
const var Osc1Tune = [Content.getComponent("OscSemiTone1"),
                      Content.getComponent("ScriptLabel17"),
                      Content.getComponent("OscCent1"),
                      Content.getComponent("ScriptLabel18")];

const var Osc1Tempo = [Content.getComponent("ScriptLabel52"),
                       Content.getComponent("Divide"),
                       Content.getComponent("ScriptLabel51"),
                       Content.getComponent("TempoSync")];


inline function onSyncControl(component, value)
{
	 for(s in Osc1Tune)
      s.showControl(value-1);
      for(s in Osc1Tempo)
            s.showControl(value);
      
      SMUT.setAttribute(SMUT.OscTempoSync1, value);     
            
};

Content.getComponent("Sync").setControlCallback(onSyncControl);

//osc2 sync

const var Osc2Tune = [Content.getComponent("OscSemiTone2"),
                      Content.getComponent("ScriptLabel22"),
                      Content.getComponent("OscCent2"),
                      Content.getComponent("ScriptLabel23")];

const var Osc2Tempo = [Content.getComponent("Divide1"),
                       Content.getComponent("ScriptLabel59"),
                       Content.getComponent("ScriptLabel60"),
                       Content.getComponent("TempoSync1")];


inline function onSync1Control(component, value)
{
	for(s in Osc2Tune)
      s.showControl(value-1);
      for(s in Osc2Tempo)
            s.showControl(value);
      
      SMUT.setAttribute(SMUT.SYNC2, value);     
};

Content.getComponent("Sync1").setControlCallback(onSync1Control);

//Osc1 Shape Menu

const var VisPanel1 = Content.getComponent("VisPanel1");
const var OscUser1 = Content.getComponent("OscUser1");


inline function onOscShapeMode1Control(component, value)
{
	SMUT.setAttribute(SMUT.oscShapeMode1, value); 
	
	if (value >= 11) {
		OscUser1.showControl(1);
		VisPanel1.showControl(0);
	}
	else {
		
		OscUser1.showControl(0);
		VisPanel1.showControl(1);
	
		
		}
	
};

Content.getComponent("OscShapeMode1").setControlCallback(onOscShapeMode1Control);

//Osc2 Shape Menu

const var VisPanel2 = Content.getComponent("VisPanel2");
const var OscUser2 = Content.getComponent("OscUser2");


inline function onOscShapeMode2Control(component, value)
{
	SMUT.setAttribute(SMUT.oscShapeMode2, value); 
	
	if (value >= 11) {
		OscUser2.showControl(1);
		VisPanel2.showControl(0);
	}
	else {
		
		OscUser2.showControl(0);
		VisPanel2.showControl(1);
	
		
		}
	
};

Content.getComponent("OscShapeMode2").setControlCallback(onOscShapeMode2Control);

//File User1 

const var UserWave = [Content.getComponent("UserWaveform1"),
                      Content.getComponent("UserInstructions")];

const var AudioWaveform1 = Content.getComponent("AudioWaveform1");


inline function onUserModeControl(component, value)
{
		for(s in UserWave)
      s.showControl(value-1);
     	 AudioWaveform1.showControl(value);
      
      SMUT.setAttribute(SMUT.User1, 1-value);   
};

Content.getComponent("UserMode").setControlCallback(onUserModeControl);

//File User2

const var UserWave1 = [Content.getComponent("UserWaveform2"),
                      Content.getComponent("UserInstructions1")];

const var AudioWaveform2 = Content.getComponent("AudioWaveform2");


inline function onUserMode1Control(component, value)
{
		for(s in UserWave1)
      s.showControl(value-1);
     	 AudioWaveform2.showControl(value);
      
      SMUT.setAttribute(SMUT.User2, 1-value);   
};

Content.getComponent("UserMode1").setControlCallback(onUserMode1Control);

//File1 Mod Mode

const var FileMods1 = [];

FileMods1[0] = Content.getComponent("FileEnv1");
FileMods1[1] = Content.getComponent("FileModTable1");
FileMods1[2] = Content.getComponent("FileModPack1");


inline function onPosModModeControl(component, value)
{
	  for (i = 0; i < FileMods1.length; i++)
        FileMods1[i].showControl(value - 1 == i);
        
        SMUT.setAttribute(SMUT.PostModMode, value-1);   
};

Content.getComponent("PosModMode").setControlCallback(onPosModModeControl);

//File2 Mod Mode

const var FileMods2 = [];

FileMods2[0] = Content.getComponent("FileEnv2");
FileMods2[1] = Content.getComponent("FileModTable2");
FileMods2[2] = Content.getComponent("FileModPack2");


inline function onPosModMode1Control(component, value)
{
	  for (i = 0; i < FileMods2.length; i++)
        FileMods2[i].showControl(value - 1 == i);
        
        SMUT.setAttribute(SMUT.File2Mode, value);   
};

Content.getComponent("PosModMode1").setControlCallback(onPosModMode1Control);

//Envelopes

const var Envs = [Content.getComponent("Envelope1"),
                  Content.getComponent("Envelope2"),
                  Content.getComponent("Envelope3")];


inline function onEnvSelControl(component, value)
{
	for (i = 0; i < Envs.length; i++)
        Envs[i].showControl(value - 1 == i);
};

Content.getComponent("EnvSel").setControlCallback(onEnvSelControl);

//env1 mode

const var ENV1 = Synth.getModulator("ENV1");

const var EnvMods1 = [];

EnvMods1[0] = Content.getComponent("EnvControls1");
EnvMods1[1] = Content.getComponent("EnvTable1");
EnvMods1[2] = Content.getComponent("EnvSp1");

inline function onEnvMode1Control(component, value)
{
		for (i = 0; i < EnvMods1.length; i++)
        EnvMods1[i].showControl(value - 1 == i);
        
        ENV1.setAttribute(ENV1.Mode, value);   
};

Content.getComponent("EnvMode1").setControlCallback(onEnvMode1Control);

//env2 mode

const var ENV2 = Synth.getModulator("ENV3");

const var EnvMods2 = [];

EnvMods2[0] = Content.getComponent("EnvControls2");
EnvMods2[1] = Content.getComponent("EnvTable2");
EnvMods2[2] = Content.getComponent("EnvSp2");

inline function onEnvMode2Control(component, value)
{
		for (i = 0; i < EnvMods2.length; i++)
        EnvMods2[i].showControl(value - 1 == i);
        
        ENV2.setAttribute(ENV2.Mode, value);   
};

Content.getComponent("EnvMode2").setControlCallback(onEnvMode2Control);

//env3 mode

const var ENV3 = Synth.getModulator("ENV3");

const var EnvMods3 = [];

EnvMods3[0] = Content.getComponent("EnvControls3");
EnvMods3[1] = Content.getComponent("EnvTable3");
EnvMods3[2] = Content.getComponent("EnvSp3");

inline function onEnvMode3Control(component, value)
{
		for (i = 0; i < EnvMods3.length; i++)
        EnvMods3[i].showControl(value - 1 == i);
        
        ENV3.setAttribute(ENV3.Mode, value);   
};

Content.getComponent("EnvMode3").setControlCallback(onEnvMode3Control);

//LFOs

const var Lfos = [Content.getComponent("LFO1"),
                  Content.getComponent("LFO2"),
                  Content.getComponent("LFO3")];

inline function onLfoSelControl(component, value)
{
		for (i = 0; i < Lfos.length; i++)
        Lfos[i].showControl(value - 1 == i);
};

Content.getComponent("LfoSel").setControlCallback(onLfoSelControl);

//LFO1 Shape

const var LfoVis1 = Content.getComponent("LfoVis1");
const var ScriptTable1 = Content.getComponent("ScriptTable1");

const var LFO1 = Synth.getModulator("LFO1");

inline function onLfoShape1Control(component, value)
{
	LFO1.setAttribute(LFO1.Shape, value);  
	
	if (value >= 6) {
		ScriptTable1.showControl(1);
		LfoVis1.setPosition(10,32,70,70);
		}
		
    else {
	    ScriptTable1.showControl(0);
	    LfoVis1.setPosition(10,32,200,70);
	    }
};

Content.getComponent("LfoShape1").setControlCallback(onLfoShape1Control);

//LFO2 Shape

const var LfoVis2 = Content.getComponent("LfoVis2");
const var ScriptTable2 = Content.getComponent("ScriptTable2");

const var LFO2 = Synth.getModulator("LFO2");

inline function onLfoShape2Control(component, value)
{
	LFO2.setAttribute(LFO2.Shape, value);  
	
	if (value >= 6) {
		ScriptTable2.showControl(1);
		LfoVis2.setPosition(10,32,70,70);
		}
		
    else {
	    ScriptTable2.showControl(0);
	    LfoVis2.setPosition(10,32,200,70);
	    }
};

Content.getComponent("LfoShape2").setControlCallback(onLfoShape2Control);

//LFO3 Shape

const var LfoVis3 = Content.getComponent("LfoVis3");
const var ScriptTable3 = Content.getComponent("ScriptTable3");

const var LFO3 = Synth.getModulator("LFO3");

inline function onLfoShape3Control(component, value)
{
	LFO3.setAttribute(LFO3.Shape, value);  
	
	if (value >= 6) {
		ScriptTable3.showControl(1);
		LfoVis2.setPosition(10,32,70,70);
		}
		
    else {
	    ScriptTable3.showControl(0);
	    LfoVis3.setPosition(10,32,200,70);
	    }	
};

Content.getComponent("LfoShape3").setControlCallback(onLfoShape3Control);


//Samples

const var foldersV1 = [];        // Top-level Genre foldersV1
const var instrumentsV1 = {};    // Maps Genre to Instruments
const var samplesV1 = {};        // Maps Instrument to .wav files
const var foldersV2 = [];        // Top-level Genre foldersV1
const var instrumentsV2 = {};    // Maps Genre to Instruments
const var samplesV2 = {}; 

const var Cat1 = Content.getComponent("Cat1");
const var Bank1 = Content.getComponent("Bank1");
const var Sample1 = Content.getComponent("Sample1");

const var Cat2 = Content.getComponent("Cat2");
const var Bank2 = Content.getComponent("Bank2");
const var Sample2 = Content.getComponent("Sample2");

const var File1 = Synth.getAudioSampleProcessor("SMUT");


const slot1 = File1.getAudioFile(0);
const slot2 = File1.getAudioFile(1);


const var AudioList = Engine.loadAudioFilesIntoPool();

inline function sortAudioFilesListV1() {
	
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV1.indexOf(genreFolder) == -1) {
            foldersV1.push(genreFolder);
            instrumentsV1[genreFolder] = []; 
            instrumentsV2[genreFolder] = []; 
        }

       
        if (instrumentsV1[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV1[genreFolder].push(instrumentFolder);
            samplesV1[instrumentFolder] = []; 
            samplesV2[instrumentFolder] = []; 
        }

		

        samplesV1[instrumentFolder].push(sampleFile);
        samplesV2[instrumentFolder].push(sampleFile);
  
  
    }


   Cat1.set("items", foldersV1.join("\n"));
   Cat2.set("items", foldersV1.join("\n"));


}

sortAudioFilesListV1();


inline function onCat1Control(component, value)
 {
  if (value >= 0) {

        local selectedGenre = foldersV1[value-1];

        if (instrumentsV1[selectedGenre]) {
            Bank1.set("items", instrumentsV1[selectedGenre].join("\n"));
     
        } else {
            Bank1.set("items", "no file");


        }

		Bank1.setValue(value);
		Bank1.changed();
		Sample1.setValue(value);
		Sample1.changed();
         
    }
}
Content.getComponent("Cat1").setControlCallback(onCat1Control);


inline function onBank1Control(component, value)
{
	   if (value >= 0) {
	    
        local selectedInstrument = Bank1.getItemText();

        if (samplesV1[selectedInstrument]) {

            Sample1.set("items", samplesV1[selectedInstrument].join("\n"))-1;
        } else {
 			Sample1.set("items", "no file");
        }
      
        
    }
    
    Bank1.setValue(value);
}


Content.getComponent("Bank1").setControlCallback(onBank1Control);


inline function onSample1Control(component, value)
{
	
	if (value >= 0) {

		local selectedSample = Sample1.get("items").split("\n")[value - 1];

       local selectedGenre = Cat1.getItemText();
       local selectedInstrument = Bank1.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SMUT.setBypassed(false);
	reg voc1 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SMUT.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SMUT.setBypassed(false);

        slot1.loadFile("{PROJECT_FOLDER}" + Cat1.getItemText() + "/" + Bank1.getItemText()  + "/" + Sample1.getItemText());
    
    }, this);

	}, SMUT);
}
}

Content.getComponent("Sample1").setControlCallback(onSample1Control);


inline function onCat2Control(component, value)
{
 if (value >= 0) {
        local selectedGenre = foldersV1[value-1];

        if (instrumentsV1[selectedGenre]) {
            Bank2.set("items", instrumentsV1[selectedGenre].join("\n"));
     
        } else {
            Bank2.set("items", "no file");


        }

		Bank2.setValue(value);
		Bank2.changed();
		Sample2.setValue(value);
		Sample2.changed();
         
    }
};

Content.getComponent("Cat2").setControlCallback(onCat2Control);


inline function onBank2Control(component, value)
{ if (value >= 0) {
	    
        local selectedInstrument = Bank2.getItemText();

        if (samplesV2[selectedInstrument]) {

            Sample2.set("items", samplesV1[selectedInstrument].join("\n"))-1;
        } else {
 			Sample2.set("items", "no file");
        }
      }
   
};

Content.getComponent("Bank2").setControlCallback(onBank2Control);


inline function onSample2Control(component, value)
{
if (value >= 0) {

		local selectedSample = Sample2.get("items").split("\n")[value - 1];

       local selectedGenre = Cat2.getItemText();
       local selectedInstrument = Bank2.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SMUT.setBypassed(false);
	reg voc2 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SMUT.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SMUT.setBypassed(false);

        slot2.loadFile("{PROJECT_FOLDER}" + Cat2.getItemText() + "/" + Bank2.getItemText()  + "/" + Sample2.getItemText());
    
    }, this);

	}, SMUT);
}
}

Content.getComponent("Sample2").setControlCallback(onSample2Control);


///Presets

const var cmbPresets = Content.getComponent("cmbPresets");
cmbPresets.setControlCallback(oncmbPresetsControl);

inline function oncmbPresetsControl(component, value)
{
	if (!value)
		return;

	local itemText = Engine.getUserPresetList()[value - 1];

	Console.print(itemText);
}

populatePresetsMenu();

inline function populatePresetsMenu()
{
	cmbPresets.set("items", "");

	for (x in Engine.getUserPresetList())
	{
		local arr = x.split("/");			
		local item = "";
		
		for (i = 0; i < arr.length; i++)
		{
			item += arr[i];
			
			if (i < arr.length - 1)
				item += "::";
		}

		cmbPresets.addItem(item);
	}
}

const var PresetMaanger = Content.getComponent("PresetMaanger");


inline function onShowPResetManagerControl(component, value)
{
	PresetMaanger.showControl(value-1);
};

Content.getComponent("ShowPResetManager").setControlCallback(onShowPResetManagerControl);



function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 