Content.makeFrontInterface(795, 645);

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
 