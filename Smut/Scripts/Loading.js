
//File Manager 
 
 const var v1 = Synth.getChildSynth("v1");

inline function onFolderSelect1Control(component, value)
{
	FilePanel.showControl(value-1);
};

Content.getComponent("FolderSelect1").setControlCallback(onFolderSelect1Control);



const var allList = [];
const var allIds = [];

const var AudioList = Engine.loadAudioFilesIntoPool();

const Folder = [];

const var File1 = Synth.getAudioSampleProcessor("File");

const var Files = Synth.getEffect("File");

const slot1 = File1.getAudioFile(0);
const slot2 = File1.getAudioFile(1);
const slot3 = File1.getAudioFile(2);
const slot4 = File1.getAudioFile(3);

//const slotU1 = File1.getAudioFile(4);


const var foldersV1 = [];        // Top-level Genre foldersV1
const var instrumentsV1 = {};    // Maps Genre to Instruments
const var samplesV1 = {};        // Maps Instrument to .wav files
const var foldersV2 = [];        // Top-level Genre foldersV1
const var instrumentsV2 = {};    // Maps Genre to Instruments
const var samplesV2 = {}; 
const var foldersV3 = [];        // Top-level Genre foldersV1
const var instrumentsV3 = {};    // Maps Genre to Instruments
const var samplesV3 = {}; 
const var foldersV4 = [];        // Top-level Genre foldersV1
const var instrumentsV4 = {};    // Maps Genre to Instruments
const var samplesV4 = {}; 


const var FirstSp = Content.getComponent("FirstSp");
const var SecondSp = Content.getComponent("SecondSp");
const var ThirdSp = Content.getComponent("ThirdSp");
const var FirstSp1 = Content.getComponent("FirstSp1");
const var SecondSp1 = Content.getComponent("SecondSp1");
const var ThirdSp1 = Content.getComponent("ThirdSp1");
const var FirstSp2 = Content.getComponent("FirstSp2");
const var SecondSp2 = Content.getComponent("SecondSp2");
const var ThirdSp2 = Content.getComponent("ThirdSp2");
const var FirstSp3 = Content.getComponent("FirstSp3");
const var SecondSp3 = Content.getComponent("SecondSp3");
const var ThirdSp3 = Content.getComponent("ThirdSp3");

const var FirstCB = Content.getComponent("FirstCB");
const var SecondCB = Content.getComponent("SecondCB");
const var ThirdCB = Content.getComponent("ThirdCB");
const var FirstCB1 = Content.getComponent("FirstCB1");
const var SecondCB1 = Content.getComponent("SecondCB1");
const var ThirdCB1 = Content.getComponent("ThirdCB1");
const var FirstCB2 = Content.getComponent("FirstCB2");
const var SecondCB2 = Content.getComponent("SecondCB2");
const var ThirdCB2 = Content.getComponent("ThirdCB2");
const var FirstCB3 = Content.getComponent("FirstCB3");
const var SecondCB3 = Content.getComponent("SecondCB3");
const var ThirdCB3 = Content.getComponent("ThirdCB3");

// Populate the hierarchy
inline function sortAudioFilesListV1() {
	
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV1.indexOf(genreFolder) == -1) {
            foldersV1.push(genreFolder);
            instrumentsV1[genreFolder] = []; 
        }

       
        if (instrumentsV1[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV1[genreFolder].push(instrumentFolder);
            samplesV1[instrumentFolder] = []; 
        }


        samplesV1[instrumentFolder].push(sampleFile);
  
  
    }


   FirstCB.set("items", foldersV1.join("\n"));
}



// Run the sorting function
sortAudioFilesListV1();
inline function onFirstCBControl(component, value) {
    if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV1[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV1 in the selected Genre
        if (instrumentsV1[selectedGenre]) {
            SecondSp.set("items", instrumentsV1[selectedGenre].join("\n"));
            SecondCB.set("items", instrumentsV1[selectedGenre].join("\n"));
     
        } else {
            SecondSp.set("items", "no file");
            SecondCB.set("items", "no file");


        }

        // Clear SampleV1 as no Instrument is selected yet
        ThirdSp.set("items", "no file");
        
     //   FirstCB.setValue(value);
		SecondCB.setValue(value);
         
    }
}

Content.getComponent("FirstCB").setControlCallback(onFirstCBControl);

const var SynthesiserGroup1 = Synth.getChildSynth("Synthesiser Group1");

inline function onSecondCBControl(component, value) {
    if (value >= 0) {
	    
    
        // Get the selected Instrument
        local selectedInstrument = SecondCB.getItemText();
    //    Console.print("Selected Instrument: " + selectedInstrument);
 		
        // Update SampleV1 dropdown with .wav files in the selected Instrument
        if (samplesV1[selectedInstrument]) {

            ThirdSp.set("items", samplesV1[selectedInstrument].join("\n"));
            ThirdCB.set("items", samplesV1[selectedInstrument].join("\n"))-1;
        } else {
            ThirdSp.set("items", "no file");
 			ThirdCB.set("items", "no file");
        }
      
        
    }
    
    SecondCB.setValue(value);
}

Content.getComponent("SecondCB").setControlCallback(onSecondCBControl);


inline function onThirdCBControl(component, value) 
{
	
	if (value >= 0) {

		local selectedSample = ThirdCB.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = FirstCB.getItemText();
       local selectedInstrument = SecondCB.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SynthesiserGroup1.setBypassed(false);
	reg voc1 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup1.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SynthesiserGroup1.setBypassed(false);

   
        // Load the sample using the full path
        slot1.loadFile("{PROJECT_FOLDER}" + FirstCB.getItemText() + "/" + SecondCB.getItemText()  + "/" + ThirdCB.getItemText());
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	}, ScriptnodeSynthesiser1);
}
}

Content.getComponent("ThirdCB").setControlCallback(onThirdCBControl);


inline function onFirstSpControl(component, value)
{
	FirstCB.setValue(value+1);
	FirstCB.changed();
};

Content.getComponent("FirstSp").setControlCallback(onFirstSpControl);


inline function onSecondSpControl(component, value)
{
	SecondCB.setValue(value+1);
	SecondCB.changed();
};

Content.getComponent("SecondSp").setControlCallback(onSecondSpControl);


inline function onThirdSpControl(component, value)
{
	ThirdCB.setValue(value+1);
	ThirdCB.changed();
};

Content.getComponent("ThirdSp").setControlCallback(onThirdSpControl);

///voice2

// Populate the hierarchy
inline function sortAudioFilesListV2() {
	
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV2.indexOf(genreFolder) == -1) {
            foldersV2.push(genreFolder);
            instrumentsV2[genreFolder] = []; 
        }

       
        if (instrumentsV2[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV2[genreFolder].push(instrumentFolder);
            samplesV2[instrumentFolder] = []; 
        }


        samplesV2[instrumentFolder].push(sampleFile);
  
  
    }

   FirstSp1.set("items", foldersV2.join("\n"));
   FirstCB1.set("items", foldersV2.join("\n"));
}



// Run the sorting function
sortAudioFilesListV2();

// Callback for GenreV1 selection
inline function onFirstCB1Control(component, value) {
    if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV2[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV2 in the selected Genre
        if (instrumentsV2[selectedGenre]) {
            SecondSp1.set("items", instrumentsV2[selectedGenre].join("\n"));
            SecondCB1.set("items", instrumentsV2[selectedGenre].join("\n"));
     
        } else {
            SecondSp1.set("items", "no file");
            SecondCB1.set("items", "no file");


        }

        // Clear SampleV1 as no Instrument is selected yet
        ThirdSp1.set("items", "no file");
        
     //   FirstCB1.setValue(value);
		SecondCB1.setValue(value);
		SecondCB1.changed();
         
    }
}

Content.getComponent("FirstCB1").setControlCallback(onFirstCB1Control);

inline function onSecondCB1Control(component, value) {
    if (value >= 0) {
	    
    
        // Get the selected Instrument
        local selectedInstrument = SecondCB1.getItemText();
    //    Console.print("Selected Instrument: " + selectedInstrument);
 		
        // Update SampleV1 dropdown with .wav files in the selected Instrument
        if (samplesV2[selectedInstrument]) {

            ThirdSp1.set("items", samplesV2[selectedInstrument].join("\n"));
            ThirdCB1.set("items", samplesV2[selectedInstrument].join("\n"))-1;
        } else {
            ThirdSp1.set("items", "no file");
 			ThirdCB1.set("items", "no file");
        }
      
        
    }
    
    SecondCB1.setValue(value);
    SecondCB1.changed();
}

Content.getComponent("SecondCB1").setControlCallback(onSecondCB1Control);



inline function onThirdCB1Control(component, value) 
{
	
	if (value >= 0) {

		local selectedSample = ThirdCB1.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = FirstCB1.getItemText();
       local selectedInstrument = SecondCB1.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SynthesiserGroup1.setBypassed(false);
	reg voc2 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup1.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SynthesiserGroup1.setBypassed(false);

   
        // Load the sample using the full path
        slot2.loadFile("{PROJECT_FOLDER}" + FirstCB1.getItemText() + "/" + SecondCB1.getItemText()  + "/" + ThirdCB1.getItemText());
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	}, ScriptnodeSynthesiser1);
}
}

Content.getComponent("ThirdCB1").setControlCallback(onThirdCB1Control);



inline function onFirstSp1Control(component, value)
{
	FirstCB1.setValue(value+1);
	FirstCB1.changed();
};

Content.getComponent("FirstSp1").setControlCallback(onFirstSp1Control);


inline function onSecondSp1Control(component, value)
{
	SecondCB1.setValue(value+1);
	SecondCB1.changed();
};

Content.getComponent("SecondSp1").setControlCallback(onSecondSp1Control);


inline function onThirdSp1Control(component, value)
{
	ThirdCB1.setValue(value+1);
	ThirdCB1.changed();
};

Content.getComponent("ThirdSp1").setControlCallback(onThirdSp1Control);


//voice3

// Populate the hierarchy
inline function sortAudioFilesListV3() {
	
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV3.indexOf(genreFolder) == -1) {
            foldersV3.push(genreFolder);
            instrumentsV3[genreFolder] = []; 
        }

       
        if (instrumentsV3[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV3[genreFolder].push(instrumentFolder);
            samplesV3[instrumentFolder] = []; 
        }


        samplesV3[instrumentFolder].push(sampleFile);
  
  
    }

   FirstSp2.set("items", foldersV3.join("\n"));
   FirstCB2.set("items", foldersV3.join("\n"));
}



// Run the sorting function
sortAudioFilesListV3();

// Callback for GenreV1 selection
inline function onFirstCB2Control(component, value) {
    if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV3[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV3 in the selected Genre
        if (instrumentsV3[selectedGenre]) {
            SecondSp2.set("items", instrumentsV3[selectedGenre].join("\n"));
            SecondCB2.set("items", instrumentsV3[selectedGenre].join("\n"));
     
        } else {
            SecondSp2.set("items", "no file");
            SecondCB2.set("items", "no file");


        }

        // Clear SampleV1 as no Instrument is selected yet
        ThirdSp2.set("items", "no file");
        
     //   FirstCB2.setValue(value);
		SecondCB2.setValue(value);
		SecondCB2.changed();
         
    }
}

Content.getComponent("FirstCB2").setControlCallback(onFirstCB2Control);

inline function onSecondCB2Control(component, value) {
    if (value >= 0) {
	    
    
        // Get the selected Instrument
        local selectedInstrument = SecondCB2.getItemText();
    //    Console.print("Selected Instrument: " + selectedInstrument);
 		
        // Update SampleV1 dropdown with .wav files in the selected Instrument
        if (samplesV3[selectedInstrument]) {

            ThirdSp2.set("items", samplesV3[selectedInstrument].join("\n"));
            ThirdCB2.set("items", samplesV3[selectedInstrument].join("\n"))-1;
        } else {
            ThirdSp2.set("items", "no file");
 			ThirdCB2.set("items", "no file");
        }
      
        
    }
    
    SecondCB2.setValue(value);
    SecondCB2.changed();
}

Content.getComponent("SecondCB2").setControlCallback(onSecondCB2Control);



inline function onThirdCB2Control(component, value) 
{
	
	if (value >= 0) {

		local selectedSample = ThirdCB2.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = FirstCB2.getItemText();
       local selectedInstrument = SecondCB2.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SynthesiserGroup1.setBypassed(false);
	reg voc3 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup1.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SynthesiserGroup1.setBypassed(false);

   
        // Load the sample using the full path
        slot3.loadFile("{PROJECT_FOLDER}" + FirstCB2.getItemText() + "/" + SecondCB2.getItemText()  + "/" + ThirdCB2.getItemText());
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	}, ScriptnodeSynthesiser1);
}
}

Content.getComponent("ThirdCB2").setControlCallback(onThirdCB2Control);



inline function onFirstSp2Control(component, value)
{
	FirstCB2.setValue(value+1);
	FirstCB2.changed();
};

Content.getComponent("FirstSp2").setControlCallback(onFirstSp2Control);


inline function onSecondSp2Control(component, value)
{
	SecondCB2.setValue(value+1);
	SecondCB2.changed();
};

Content.getComponent("SecondSp2").setControlCallback(onSecondSp2Control);


inline function onThirdSp2Control(component, value)
{
	ThirdCB2.setValue(value+1);
	ThirdCB2.changed();
};

Content.getComponent("ThirdSp2").setControlCallback(onThirdSp2Control);


//voice4

// Populate the hierarchy
inline function sortAudioFilesListV4() {
	
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV4.indexOf(genreFolder) == -1) {
            foldersV4.push(genreFolder);
            instrumentsV4[genreFolder] = []; 
        }

       
        if (instrumentsV4[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV4[genreFolder].push(instrumentFolder);
            samplesV4[instrumentFolder] = []; 
        }


        samplesV4[instrumentFolder].push(sampleFile);
  
  
    }

   FirstSp3.set("items", foldersV4.join("\n"));
   FirstCB3.set("items", foldersV4.join("\n"));
}



// Run the sorting function
sortAudioFilesListV4();

// Callback for GenreV1 selection
inline function onFirstCB3Control(component, value) {
    if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV4[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV4 in the selected Genre
        if (instrumentsV4[selectedGenre]) {
            SecondSp3.set("items", instrumentsV4[selectedGenre].join("\n"));
            SecondCB3.set("items", instrumentsV4[selectedGenre].join("\n"));
     
        } else {
            SecondSp3.set("items", "no file");
            SecondCB3.set("items", "no file");


        }

        // Clear SampleV1 as no Instrument is selected yet
        ThirdSp3.set("items", "no file");
        
     //   FirstCB3.setValue(value);
		SecondCB3.setValue(value);
		SecondCB3.changed();
         
    }
}

Content.getComponent("FirstCB3").setControlCallback(onFirstCB3Control);

inline function onSecondCB3Control(component, value) {
    if (value >= 0) {
	    
    
        // Get the selected Instrument
        local selectedInstrument = SecondCB3.getItemText();
    //    Console.print("Selected Instrument: " + selectedInstrument);
 		
        // Update SampleV1 dropdown with .wav files in the selected Instrument
        if (samplesV4[selectedInstrument]) {

            ThirdSp3.set("items", samplesV4[selectedInstrument].join("\n"));
            ThirdCB3.set("items", samplesV4[selectedInstrument].join("\n"))-1;
        } else {
            ThirdSp3.set("items", "no file");
 			ThirdCB3.set("items", "no file");
        }
      
        
    }
    
    SecondCB3.setValue(value);
    SecondCB3.changed();
}

Content.getComponent("SecondCB3").setControlCallback(onSecondCB3Control);



inline function onThirdCB3Control(component, value) 
{
	
	if (value >= 0) {

		local selectedSample = ThirdCB3.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = FirstCB3.getItemText();
       local selectedInstrument = SecondCB3.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SynthesiserGroup1.setBypassed(false);
	reg voc4 = value-1;
	
	Content.callAfterDelay(400, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup1.setBypassed(true);
		
		Content.callAfterDelay(400, function()
		{
	
	
		SynthesiserGroup1.setBypassed(false);

   
        // Load the sample using the full path
        slot4.loadFile("{PROJECT_FOLDER}" + FirstCB3.getItemText() + "/" + SecondCB3.getItemText()  + "/" + ThirdCB3.getItemText());
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	}, ScriptnodeSynthesiser1);
}
}

Content.getComponent("ThirdCB3").setControlCallback(onThirdCB3Control);



inline function onFirstSp3Control(component, value)
{
	FirstCB3.setValue(value+1);
	FirstCB3.changed();
};

Content.getComponent("FirstSp3").setControlCallback(onFirstSp3Control);


inline function onSecondSp3Control(component, value)
{
	SecondCB3.setValue(value+1);
	SecondCB3.changed();
};

Content.getComponent("SecondSp3").setControlCallback(onSecondSp3Control);


inline function onThirdSp3Control(component, value)
{
	ThirdCB3.setValue(value+1);
	ThirdCB3.changed();
};

Content.getComponent("ThirdSp3").setControlCallback(onThirdSp3Control);


//USER



 
 const var FactoryFile1 = [Content.getComponent("FacLoad"),
                           Content.getComponent("FolderSelect1"),
                           Content.getComponent("Wav1"),
                           Content.getComponent("Wav2"),
                           Content.getComponent("Wav3"),
                           Content.getComponent("Wav4")];
 
 const var Userfile1 = [Content.getComponent("UserLoad"),
                        Content.getComponent("UsrWav1"),
                        Content.getComponent("UsrWav2"),
                        Content.getComponent("UsrWav3"),
                        Content.getComponent("UsrWav4"),
                        Content.getComponent("FolderSel1")];
 
 const var UsrCb1 = Content.getComponent("UsrCb1");
 const var UsrCbVis1 = Content.getComponent("UsrCbVis1");
 const var UsrCb2 = Content.getComponent("UsrCb2");
 const var UsrCbVis2 = Content.getComponent("UsrCbVis2");
 const var UsrCb3 = Content.getComponent("UsrCb3");
 const var UsrCbVis3 = Content.getComponent("UsrCbVis3");
 const var UsrCb4 = Content.getComponent("UsrCb4");
 const var UsrCbVis4 = Content.getComponent("UsrCbVis4");
 
 const FolderPath = [];
 
 inline function onUserModeControl(component, value)
 {
 File.setAttribute(File.FileUser, value-1);
 
 	for(s in FactoryFile1)
 		s.showControl(value);  
 		
 	for(s in Userfile1)
 	 		s.showControl(value-1);  	
 };
 
 Content.getComponent("UserMode").setControlCallback(onUserModeControl);
 
 
 inline function onFolderSel1Control(component, value) {
 
 //Select a folder
 
 if (value == 1)
 
     FileSystem.browseForDirectory(FileSystem.AudioFiles, function(folder) {
         if (isDefined(folder) && folder.isDirectory()) {
          
          //find files in selected folder
          
             var folderArray = FileSystem.findFiles(folder, "*.wav, *.aif", false);
 
             for (file in folderArray) {
                 file = file.toString(0);
                 
                 var folderArray2 = FileSystem.findFiles(folder, "*.wav, *.aif", false);
                             
                             for (file1 in folderArray2) {
                                         file1 = file1.toString(1);        
                 
          //Populate the Folder Label
               
               	
               
                 FolderPath.push(folder);
               
             };
             
             
             
             //send items to hidden ComboBox
             
 
        UsrCb1.set("items", folderArray.join("\n"));
 		UsrCbVis1.set("items", folderArray2.join("\n"));
		UsrCb2.set("items", folderArray.join("\n"));
		UsrCbVis2.set("items", folderArray2.join("\n"));
		UsrCb3.set("items", folderArray.join("\n"));
		UsrCbVis3.set("items", folderArray2.join("\n"));
		UsrCb4.set("items", folderArray.join("\n"));
		UsrCbVis4.set("items", folderArray2.join("\n"));
 			
 	//	LpLoad2.set("items", folderArray2.join("\n"));
     
 }
 
         }
     });
 };
 
 Content.getComponent("FolderSel1").setControlCallback(onFolderSel1Control);
 
const var SGroup1 = Synth.getChildSynth("v1");

const slotU1 = File1.getAudioFile(4);
const slotU2 = File1.getAudioFile(5);
const slotU3 = File1.getAudioFile(6);
const slotU4 = File1.getAudioFile(7);


inline function onUsrCb1Control(component, value)
{
	v1.setBypassed(false);
	
	reg v = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slotU1.loadFile(UsrCb1.get("items").split("\n")[v]);
		}, this);

	}, SGroup1);
};

Content.getComponent("UsrCb1").setControlCallback(onUsrCb1Control);


inline function onUsrCbVis1Control(component, value)
{
	UsrCb1.setValue(value);
	UsrCb1.changed();
};

Content.getComponent("UsrCbVis1").setControlCallback(onUsrCbVis1Control);


inline function onUsrCb2Control(component, value)
{
	v1.setBypassed(false);
	
	reg v2 = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slotU2.loadFile(UsrCb2.get("items").split("\n")[v2]);
		}, this);

	}, SGroup1);
};

Content.getComponent("UsrCb2").setControlCallback(onUsrCb2Control);


inline function onUsrCbVis2Control(component, value)
{
	UsrCb2.setValue(value);
	UsrCb2.changed();
};

Content.getComponent("UsrCbVis2").setControlCallback(onUsrCbVis2Control);


inline function onUsrCb3Control(component, value)
{
	v1.setBypassed(false);
	
	reg v3 = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slotU3.loadFile(UsrCb3.get("items").split("\n")[v3]);
		}, this);

	}, SGroup1);
};

Content.getComponent("UsrCb3").setControlCallback(onUsrCb3Control);


inline function onUsrCbVis3Control(component, value)
{
	UsrCb3.setValue(value);
	UsrCb3.changed();
};

Content.getComponent("UsrCbVis3").setControlCallback(onUsrCbVis3Control);


inline function onUsrCb4Control(component, value)
{
	v1.setBypassed(false);
	
	reg v4 = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slotU4.loadFile(UsrCb4.get("items").split("\n")[v4]);
		}, this);

	}, SGroup1);
};

Content.getComponent("UsrCb4").setControlCallback(onUsrCb4Control);


inline function onUsrCbVis4Control(component, value)
{
	UsrCb4.setValue(value);
	UsrCb4.changed();
};

Content.getComponent("UsrCbVis4").setControlCallback(onUsrCbVis4Control);



const var Wf1 = Content.getComponent("Wf1");
const var Wf2 = Content.getComponent("Wf2");
const var Wf3 = Content.getComponent("Wf3");
const var Wf4 = Content.getComponent("Wf4");

const var FileLd1 = Content.getComponent("File1");
const var FileLd2 = Content.getComponent("File2");
const var FileLd3 = Content.getComponent("File3");
const var FileLd4 = Content.getComponent("File4");

const var FilePos1 = Content.getComponent("FilePos1");
const var FilePos2 = Content.getComponent("FilePos2");
const var FilePos3 = Content.getComponent("FilePos3");
const var FilePos4 = Content.getComponent("FilePos4");

const var PosLbl1 = Content.getComponent("PosLbl1");
const var PosLbl2 = Content.getComponent("PosLbl2");
const var PosLbl3 = Content.getComponent("PosLbl3");
const var PosLbl4 = Content.getComponent("PosLbl4");


inline function onfile1Control(component, value)
{
	Wf1.showControl(value);
	ThirdCB.showControl(value);
	FileLd1.showControl(value);
	FilePos1.showControl(value);
	PosLbl1.showControl(value);
	UsrCbVis1.showControl(value);
};

Content.getComponent("file1").setControlCallback(onfile1Control);


inline function onfile2Control(component, value)
{
	Wf2.showControl(value);
	ThirdCB1.showControl(value);
	FileLd2.showControl(value);
	FilePos2.showControl(value);
	PosLbl2.showControl(value);
	UsrCbVis2.showControl(value);

};

Content.getComponent("file2").setControlCallback(onfile2Control);


inline function onfile3Control(component, value)
{
	Wf3.showControl(value);
	ThirdCB2.showControl(value);
	FileLd3.showControl(value);
	FilePos3.showControl(value);
	PosLbl3.showControl(value);
	UsrCbVis3.showControl(value);

};

Content.getComponent("file3").setControlCallback(onfile3Control);


inline function onfile4Control(component, value)
{
	Wf4.showControl(value);
	ThirdCB3.showControl(value);
	FileLd4.showControl(value);
	FilePos4.showControl(value);
	PosLbl4.showControl(value);
	UsrCbVis4.showControl(value);

};

Content.getComponent("file4").setControlCallback(onfile4Control);



        


