//Voice 1

//Mod Panels

const var Osc1 = Synth.getEffect("Osc1");

const var Osc1Mods =[];

for (i = 0; i < 6; i++)
{
    Osc1Mods[i] = Content.getComponent("OsModRouteA"+(i+1));

} 

inline function onOscModRoutPage1Control(component, value)
{
  for (i = 0; i < Osc1Mods.length; i++)
        Osc1Mods[i].showControl(value - 1 == i);
};

Content.getComponent("OscModRoutPage1").setControlCallback(onOscModRoutPage1Control);

const var File1Mods =[];

for (i = 0; i < 7; i++)
{
    File1Mods[i] = Content.getComponent("flModRouteA"+(i+1));

} 

 const var Ramps = Content.getComponent("Ramps");
  
  
        
inline function onfileModRoutPage1Control(component, value)
{
 for (i = 0; i < File1Mods.length; i++)
        File1Mods[i].showControl(value - 1 == i);
   
  
   	  
   	  if (value == 7){
   	     		 Ramps.showControl(1);
   	     		}
   	     	  else {
   	      Ramps.showControl(0);
   	     	  }   
        
};

Content.getComponent("fileModRoutPage1").setControlCallback(onfileModRoutPage1Control);

const var Filter1Mods =[];

for (i = 0; i < 5; i++)
{
    Filter1Mods[i] = Content.getComponent("fModRouteA"+(i+1));

} 

inline function onFlModRoutPage1Control(component, value)
{
	 for (i = 0; i < Filter1Mods.length; i++)
        Filter1Mods[i].showControl(value - 1 == i);
};

Content.getComponent("FlModRoutPage1").setControlCallback(onFlModRoutPage1Control);



const var ShapePanel1 = Content.getComponent("ShapePanel1");
 
 inline function onShowUserTable1Control(component, value)
 {
 	ShapePanel1.showControl(value);
 };
 
 Content.getComponent("ShowUserTable1").setControlCallback(onShowUserTable1Control);
 
 
 //Pitch Mode Menu
 
 const var Semitones1 = [Content.getComponent("Pitch1"),
 						Content.getComponent("Pitch2"),
                         Content.getComponent("Step1")];
 
const var Tempo1 = [Content.getComponent("Tempo1"),
					Content.getComponent("Tempo2"),
                    Content.getComponent("Div1")];

const var StepLabel = Content.getComponent("StepLabel");
const var PitchLabel1 = Content.getComponent("PitchLabel1");
const var PitchLabel2 = Content.getComponent("PitchLabel2");

 inline function onPitchMode1Control(component, value)
 {
	
Osc1.setAttribute(Osc1.pitchmode, value);           

 if (value == 1){
	 
 for(s in Semitones1)
       s.showControl(1);
 
 for(s in Tempo1)
       s.showControl(0);    
       
   StepLabel.setValue("Step");
   PitchLabel1.setValue("Pitch");
   PitchLabel2.setValue("Pitch");
        
       }

   if (value == 2){
      	 
  for(s in Semitones1)
            s.showControl(0);  
   for(s in Tempo1)
         s.showControl(1); 
    StepLabel.setValue("Divide");  
    PitchLabel1.setValue("Tempo");
    PitchLabel2.setValue("Tempo");             
              
       }
   if (value == 3){
      	 
     for(s in Semitones1)
            s.showControl(0); 
   for(s in Tempo1)
         s.showControl(1);   
     StepLabel.setValue("Divide");     
     PitchLabel1.setValue("Tempo");
         PitchLabel2.setValue("Tempo");    
             
       }        
 };
 
 Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);
 
 const var FilePanel = Content.getComponent("Files");
 
 
 
 

const var WinUnsync1 = [Content.getComponent("FileWin1"),
                       Content.getComponent("FileXf1")];

const var WinSync1 = [Content.getComponent("FileXfTempo1"),
                     Content.getComponent("FileWinTempo1")];
                  
const var Files1 = Synth.getEffect("Osc1");                  


const var CutLabel1 = Content.getComponent("CutLabel1");
const var CutLabel2 = Content.getComponent("CutLabel2");
const var CutLabel9 = Content.getComponent("CutLabel9");


 