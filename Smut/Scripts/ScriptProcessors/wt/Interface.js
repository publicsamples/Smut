Content.makeFrontInterface(600, 600);

const var WavetableSynthesiser1 = Synth.getWavetableController("Wavetable Synthesiser1");

const var WaveList = Engine.getWavetableList();
const var WaveOptions = WavetableSynthesiser1.getResynthesisOptions();

//SAVE

function save(file)
{
    WavetableSynthesiser1.saveAsHwt(file);
}


inline function onSaveFileControl(component, value)
{
	if (value == 1)
	FileSystem.browse(FileSystem.AudioFiles, true, "*.wav", save);
};

Content.getComponent("SaveFile").setControlCallback(onSaveFileControl);

//LOAD

function load(file)
{
    WavetableSynthesiser1.loadData(file, 44100, 1);
}


inline function onLoadFileControl(component, value)
{
	if (value == 1)
	
	FileSystem.browse(FileSystem.Downloads, false, "*.wav, *.aif", load);
};

Content.getComponent("LoadFile").setControlCallback(onLoadFileControl);
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
 