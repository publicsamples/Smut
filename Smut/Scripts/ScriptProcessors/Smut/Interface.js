;Content.makeFrontInterface(880, 880);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "mon");

const var Smut = Synth.getChildSynth("Smut");

include("laf.js");
include("KnobLAF1.js");
include("KnobLAF2.js");
include("KnobLAF3.js");
include("KnobLAF4.js");
include("Rect.js");

include("Scopes.js");
include("Loading.js");

include("V1.js");


inline function onHiQControl(component, value)
{

	if (value == 1){
		
	SynthesiserGroup1.setAttribute(SynthesiserGroup1.VoiceLimit, 6);

	}
	
	if (value == 2){
			
	SynthesiserGroup1.setAttribute(SynthesiserGroup1.VoiceLimit, 6);
	
		}
	
	if (value == 3){
			
	SynthesiserGroup1.setAttribute(SynthesiserGroup1.VoiceLimit, 4);

		}
	
	if (value == 4){
			
	SynthesiserGroup1.setAttribute(SynthesiserGroup1.VoiceLimit, 1);

		}	
		

};

Content.getComponent("HiQ").setControlCallback(onHiQControl);



const var Filter1 = Synth.getEffect("Osc1");

Settings.setZoomLevel(1);


//Voice Pages

const var VoiceMode1 = Content.getComponent("VoiceMode1");

const var VoicePages =[];

for (i = 0; i < 4; i++)
{
    VoicePages[i] = Content.getComponent("Voice"+(i+1));
}

const var SeqPages =[];

for (i = 0; i < 4; i++)
{
    SeqPages[i] = Content.getComponent("Seq"+(i+1));
}




//Synth.setUseUniformVoiceHandler("Smut", true);

const var rm = Engine.getGlobalRoutingManager();

const var Files = Content.getComponent("Files");


//Tabs

const var NUM_BUTTONS = 6;
const var buttons = [];
const var panels = [];

for (i = 0; i < NUM_BUTTONS; i++)
{
    buttons[i] = Content.getComponent("Button" + (i+1));
    panels[i] = Content.getComponent("lfo" + (i+1));
    buttons[i].setControlCallback(onButtonControl);
}

inline function onButtonControl(component, value)
{
	local idx = buttons.indexOf(component);
		
	for (i = 0; i < panels.length; i++)
    {
        panels[i].showControl(idx == i);
        buttons[i].setValue(i == idx && value);
    }
}

onButtonControl(buttons[0], true);



//LFO1

const var LFO1 = Synth.getEffect("LFO1");

const var LfoShpPanel1 = Content.getComponent("LfoShapeVis1");
const var LfoTable1 = Content.getComponent("LfoTable1");
const var LfoSliderPack1 = Content.getComponent("LfoSliderPack1");

inline function onLfoShape1Control(component, value)
{
	
	LFO1.setAttribute(LFO1.Shape, value);

	if (value == 1){
	
		LfoShpPanel1.showControl(1);
		LfoTable1.showControl(0);
		LfoSliderPack1.showControl(0);


	}
	if (value == 2){

		LfoShpPanel1.showControl(1);
		LfoTable1.showControl(0);
		LfoSliderPack1.showControl(0);

        }
        
      if (value == 3){
      
      	LfoShpPanel1.showControl(1);
      	LfoTable1.showControl(0);
      	LfoSliderPack1.showControl(0);

              }
    
    if (value == 4){

    	LfoShpPanel1.showControl(1);
    	LfoTable1.showControl(0);
    	LfoSliderPack1.showControl(0);

            }          
 
		if (value == 5){
		

			LfoShpPanel1.showControl(1);
			LfoTable1.showControl(0);
			LfoSliderPack1.showControl(0);

		        }
		        
	if (value == 6){
	

		LfoShpPanel1.showControl(0);
		LfoTable1.showControl(1);
		LfoSliderPack1.showControl(0);
	
	        }	        
	 
	 	if (value == 7){

	 		LfoShpPanel1.showControl(0);
	 		LfoTable1.showControl(0);
	 		LfoSliderPack1.showControl(1);

	 	        }	        
	 	     
     
};

Content.getComponent("LfoShape1").setControlCallback(onLfoShape1Control);

//LFO2

const var LFO2 = Synth.getEffect("LFO2");

const var LfoShpPanel2 = Content.getComponent("LfoShapeVis2");
const var LfoTable2 = Content.getComponent("LfoTable2");
const var LfoSliderPack2 = Content.getComponent("LfoSliderPack2");

inline function onLfoShape2Control(component, value)
{
	
	LFO2.setAttribute(LFO2.Shape, value);

	if (value == 1){
	
		LfoShpPanel2.showControl(1);
		LfoTable2.showControl(0);
		LfoSliderPack2.showControl(0);
	

	}
	if (value == 2){

		LfoShpPanel2.showControl(1);
		LfoTable2.showControl(0);
		LfoSliderPack2.showControl(0);

        }
        
      if (value == 3){
      
      	LfoShpPanel2.showControl(1);
      	LfoTable2.showControl(0);
      	LfoSliderPack2.showControl(0);

              }
    
    if (value == 4){

    	LfoShpPanel2.showControl(1);
    	LfoTable2.showControl(0);
    	LfoSliderPack2.showControl(0);
    
            }          
 
		if (value == 5){
		

			LfoShpPanel2.showControl(1);
			LfoTable2.showControl(0);
			LfoSliderPack2.showControl(0);
	
		        }
		        
	if (value == 6){
	

		LfoShpPanel2.showControl(0);
		LfoTable2.showControl(1);
		LfoSliderPack2.showControl(0);
	
	        }	        
	 
	 	if (value == 7){

	 		LfoShpPanel2.showControl(0);
	 		LfoTable2.showControl(0);
	 		LfoSliderPack2.showControl(1);

	 	        }	        
	 	     
     
};

Content.getComponent("LfoShape2").setControlCallback(onLfoShape2Control);

//LFO3

const var LFO3 = Synth.getEffect("LFO3");

const var LfoShpPanel3 = Content.getComponent("LfoShapeVis3");
const var LfoTable3 = Content.getComponent("LfoTable3");
const var LfoSliderPack3 = Content.getComponent("LfoSliderPack3");
const var MiniVis3 = Content.getComponent("MiniVis3");


inline function onLfoShape3Control(component, value)
{
	
	LFO3.setAttribute(LFO3.Shape, value);

	if (value == 1){
	
		LfoShpPanel3.showControl(1);
		LfoTable3.showControl(0);
		LfoSliderPack3.showControl(0);


	}
	if (value == 2){

		LfoShpPanel3.showControl(1);
		LfoTable3.showControl(0);
		LfoSliderPack3.showControl(0);

        }
        
      if (value == 3){
      
      	LfoShpPanel3.showControl(1);
      	LfoTable3.showControl(0);
      	LfoSliderPack3.showControl(0);
      
              }
    
    if (value == 4){

    	LfoShpPanel3.showControl(1);
    	LfoTable3.showControl(0);
    	LfoSliderPack3.showControl(0);
    
            }          
 
		if (value == 5){
		

			LfoShpPanel3.showControl(1);
			LfoTable3.showControl(0);
			LfoSliderPack3.showControl(0);

		        }
		        
	if (value == 6){
	

		LfoShpPanel3.showControl(0);
		LfoTable3.showControl(1);
		LfoSliderPack3.showControl(0);

	        }	        
	 
	 	if (value == 7){

	 		LfoShpPanel3.showControl(0);
	 		LfoTable3.showControl(0);
	 		LfoSliderPack3.showControl(1);

	 	        }	        
	 	     
     
};

Content.getComponent("LfoShape3").setControlCallback(onLfoShape3Control);

//LFO6

const var LFO4 = Synth.getEffect("LFO4");

const var LfoShpPanel4 = Content.getComponent("LfoShapeVis4");
const var LfoTable4 = Content.getComponent("LfoTable4");
const var LfoSliderPack4 = Content.getComponent("LfoSliderPack4");



inline function onLfoShape4Control(component, value)
{
	
	LFO4.setAttribute(LFO4.Shape, value);

	if (value == 1){
	
		LfoShpPanel4.showControl(1);
		LfoTable4.showControl(0);
		LfoSliderPack4.showControl(0);
	

	}
	if (value == 2){

		LfoShpPanel4.showControl(1);
		LfoTable4.showControl(0);
		LfoSliderPack4.showControl(0);
	
        }
        
      if (value == 3){
      
      	LfoShpPanel4.showControl(1);
      	LfoTable4.showControl(0);
      	LfoSliderPack4.showControl(0);
     
              }
    
    if (value == 4){

    	LfoShpPanel4.showControl(1);
    	LfoTable4.showControl(0);
    	LfoSliderPack4.showControl(0);
    
            }          
 
		if (value == 5){
		

			LfoShpPanel4.showControl(1);
			LfoTable4.showControl(0);
			LfoSliderPack4.showControl(0);
		
		        }
		        
	if (value == 6){
	

		LfoShpPanel4.showControl(0);
		LfoTable4.showControl(1);
		LfoSliderPack4.showControl(0);
	
	        }	        
	 
	 	if (value == 7){

	 		LfoShpPanel4.showControl(0);
	 		LfoTable4.showControl(0);
	 		LfoSliderPack4.showControl(1);
	 	
	 	        }	        
	 	     
     
};

Content.getComponent("LfoShape4").setControlCallback(onLfoShape4Control);




//env

const var LfoPanels4 =[];

LfoPanels4[0] = Content.getComponent("LfoShapeVis4");
LfoPanels4[1] = Content.getComponent("EnvPanel1");
LfoPanels4[2] = Content.getComponent("LfoTable4");
LfoPanels4[3] = Content.getComponent("LfoSliderPack4");
LfoPanels4[4] = Content.getComponent("AdjVis4");


const var PresetPanel = Content.getComponent("PresetPanel");


inline function onClosePresetControl(component, value)
{
   PresetPanel.showControl(0);
};

Content.getComponent("ClosePreset").setControlCallback(onClosePresetControl);


inline function onPresetsControl(component, value)
{
	PresetPanel.showControl(1);
};

Content.getComponent("Presets").setControlCallback(onPresetsControl);

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




const var MixCont = [Content.getComponent("MixLabel"),
                     Content.getComponent("ScriptSliderPack1")];

const var XfCont = [Content.getComponent("Xfader"),
                    Content.getComponent("XfLabel")];
                     

inline function onFadeModeControl(component, value)
{
	Osc1.setAttribute(Osc1.FileXrossFadeMode, value);
	
		if (value == 4){
			
			for(s in MixCont)
			    s.showControl(1); 
		
			for(s in XfCont)
				s.showControl(0); 
				}
				
		else {
		for(s in MixCont)
					    s.showControl(0); 
				
					for(s in XfCont)
						s.showControl(1); 	
		}
};

Content.getComponent("FadeMode").setControlCallback(onFadeModeControl);

const var EnvTable1 = Content.getComponent("EnvTable1");

inline function onEnvMode1Control(component, value)
{
	Osc1.setAttribute(Osc1.EnvType1, value);
	EnvTable1.showControl(value);
};

Content.getComponent("EnvMode1").setControlCallback(onEnvMode1Control);

const var EnvTable2 = Content.getComponent("EnvTable2");

inline function onEnvMode2Control(component, value)
{
	Osc1.setAttribute(Osc1.EnvType2, value);
	EnvTable2.showControl(value);
};

Content.getComponent("EnvMode2").setControlCallback(onEnvMode2Control);



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
 