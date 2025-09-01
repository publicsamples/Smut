Content.makeFrontInterface(795, 655);

include("laf.js");
include("KnobLAF1.js");
include("Rect.js");
include("Scopes.js");

const var ShowPResetManager = Content.getComponent("ShowPResetManager");
ShowPResetManager.setValue(1);
ShowPResetManager.changed();
const var SMUT = Synth.getChildSynth("SMUT");

inline function onVoicesControl(component, value)
{
	if (value == 1) {
	SMUT.setAttribute(SMUT.VoiceLimit, 1);
	}
	if (value == 2) {
	SMUT.setAttribute(SMUT.VoiceLimit, 3);
	}
	if (value == 3) {
	SMUT.setAttribute(SMUT.VoiceLimit, 5);
	}
	if (value == 4) {
	SMUT.setAttribute(SMUT.VoiceLimit, 8);
	}

};

Content.getComponent("Voices").setControlCallback(onVoicesControl);



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


///Presets

const var cmbPresets = Content.getComponent("cmbPresets");
cmbPresets.setControlCallback(oncmbPresetsControl);

inline function oncmbPresetsControl(component, value)
{
	if (!value)
		return;

	local itemText = Engine.getUserPresetList()[value - 1];

	Engine.loadUserPreset(itemText + ".preset");
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


//link

const var Link = Content.getComponent("Link");

Link.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/lgzxw");
  } 
  else 
  {
  //  link_hover = event.hover;
    this.repaint();
  }
});


//Samples New


const var foldersV1 = [];        // Top-level Genre foldersV1
const var instrumentsV1 = {};    // Maps Genre to Instruments
const var samplesV1 = {};        // Maps Instrument to .wav files
const var foldersV2 = [];        // Top-level Genre foldersV1
const var instrumentsV2 = {};    // Maps Genre to Instruments
const var samplesV2 = {}; 

const var File1 = Synth.getAudioSampleProcessor("SMUT");

const slot1 = File1.getAudioFile(0);
const slot2 = File1.getAudioFile(1);

const var AudioList = Engine.loadAudioFilesIntoPool();

const var SampleA = Content.getComponent("SampleA");

inline function createDelayBroadcaster(Sample1)
{
	return Engine.createBroadcaster({
		"id": Sample1.get("id") + " Delayer",
		"args": [ "unused" ]
	});
}

const var KSampleABroadcaster = createDelayBroadcaster(SampleA);


SampleA.setControlCallback(onSampleAControl);

function functOne()
{
	Console.print("ONE");
	Engine.allNotesOff();
	SMUT.setBypassed(true);
	// You need to call it with a new argument (random number) or
	// it won't fire...
	KSampleABroadcaster.callWithDelay(30, [Math.random()], functTwo);
}

function functTwo()
{
	;
	KSampleABroadcaster.callWithDelay(50, [Math.random()], functThree);
}

function functThree()
{
	SMUT.setBypassed(false);
	Console.print("THREE");
}


inline function onSampleAControl(component, value)
{
	functOne();

	local itemText = AudioList[value - 1];
	slot1.loadFile(itemText);
		Console.print("{PROJECT_FOLDER}" + itemText);
	if (!value)
		return;
}
KSampleABroadcaster.callWithDelay(300, [Math.random()], populateAudioMenu);

inline function populateAudioMenu()
{
	SampleA.set("items", "");

	for (x in AudioList)
	{
		local fullPath = x.split("}")[1];
		local arr = fullPath.split("/");
		local item = "";

		for (i = 0; i < arr.length; i++)
		{
			item += arr[i];
			
			if (i < arr.length - 1)
				item += "::";
		}

		SampleA.addItem(item);
	
	}
}

const var SampleB = Content.getComponent("SampleB");

inline function createDelayBroadcaster2(Sample2)
{
	return Engine.createBroadcaster({
		"id": Sample2.get("id") + " Delayer",
		"args": [ "unused" ]
	});
}

const var KSampleABroadcaster2 = createDelayBroadcaster(SampleB);


SampleB.setControlCallback(onSampleBControl);

function functOne1()
{
	Console.print("ONE");
	Engine.allNotesOff();
	SMUT.setBypassed(true);
	// You need to call it with a new argument (random number) or
	// it won't fire...
	KSampleABroadcaster2.callWithDelay(30, [Math.random()], functTwo);
}



inline function onSampleBControl(component, value)
{
	functOne1();

	local itemText = AudioList[value - 1];
	slot2.loadFile(itemText);
		Console.print("{PROJECT_FOLDER}" + itemText);
	if (!value)
		return;
}
KSampleABroadcaster2.callWithDelay(300, [Math.random()], populateAudioMenu2);

inline function populateAudioMenu2()
{
	SampleB.set("items", "");

	for (x in AudioList)
	{
		local fullPath = x.split("}")[1];
		local arr = fullPath.split("/");
		local item = "";

		for (i = 0; i < arr.length; i++)
		{
			item += arr[i];
			
			if (i < arr.length - 1)
				item += "::";
		}

		SampleB.addItem(item);
	
	}
}function onNoteOn()
{
	Message.ignoreEvent(Message.getNoteNumber() == 23);
	Message.ignoreEvent(Message.getNoteNumber() == 22);
	Message.ignoreEvent(Message.getNoteNumber() == 21);
	Message.ignoreEvent(Message.getNoteNumber() == 20);
	Message.ignoreEvent(Message.getNoteNumber() == 19);
	Message.ignoreEvent(Message.getNoteNumber() == 18);
	Message.ignoreEvent(Message.getNoteNumber() == 17);
	Message.ignoreEvent(Message.getNoteNumber() == 16);
	Message.ignoreEvent(Message.getNoteNumber() == 15);
	Message.ignoreEvent(Message.getNoteNumber() == 14);
	Message.ignoreEvent(Message.getNoteNumber() == 13);
	Message.ignoreEvent(Message.getNoteNumber() == 12);
	Message.ignoreEvent(Message.getNoteNumber() == 11);
	Message.ignoreEvent(Message.getNoteNumber() == 10);
	Message.ignoreEvent(Message.getNoteNumber() == 9);
	Message.ignoreEvent(Message.getNoteNumber() == 8);
	Message.ignoreEvent(Message.getNoteNumber() == 7);
	Message.ignoreEvent(Message.getNoteNumber() == 6);
	Message.ignoreEvent(Message.getNoteNumber() == 5);
	Message.ignoreEvent(Message.getNoteNumber() == 4);
	Message.ignoreEvent(Message.getNoteNumber() == 3);
	Message.ignoreEvent(Message.getNoteNumber() == 2);
	Message.ignoreEvent(Message.getNoteNumber() == 1);
	Message.ignoreEvent(Message.getNoteNumber() == 0);
	
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
 