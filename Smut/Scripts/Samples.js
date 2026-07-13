//Samples

const var LoadSample1 = Content.getComponent("LoadSample1");
const var LoadSample2 = Content.getComponent("LoadSample2");
const var FileName1 = Content.getComponent("FileName1");
const var FileName2 = Content.getComponent("FileName2");
const var FilePath1 = Content.getComponent("FilePath1");
const var FilePath2 = Content.getComponent("FilePath2");


reg lastPath1 = "";
reg lastPath2 = "";
reg isInternalSampleUpdate = false;



inline function finishSampleLoad(slot, file, fileNameLabel, filePathLabel)
{
	isInternalSampleUpdate = true;

	slot.loadFile(file.toString(0));
	fileNameLabel.set("text", file.toString(1));
	filePathLabel.set("text", file.toString(0));

	Content.callAfterDelay(50, function()
	{
		SMUT.setBypassed(false);
		isInternalSampleUpdate = false;
	});
}

inline function recallSampleFromPath(slot, fileNameLabel, filePathLabel)
{
	local path = filePathLabel.get("text");

	if (path == "")
		return;

	Engine.allNotesOff();
	SMUT.setBypassed(true);

	slot.loadFile(path);
	fileNameLabel.set("text", FileSystem.fromAbsolutePath(path).toString(1));

	Content.callAfterDelay(50, function()
	{
		SMUT.setBypassed(false);
	});
}

inline function loadSampleForSlot(slot, fileNameLabel, filePathLabel)
{
	Engine.allNotesOff();
	SMUT.setBypassed(true);

	FileSystem.browse(FileSystem.AudioFiles, false, "*.wav;*.aif;*.aiff",
		function [slot, fileNameLabel, filePathLabel](file)
		{
			finishSampleLoad(slot, file, fileNameLabel, filePathLabel);
		}
	);
}

inline function onLoadSample1Control(component, value)
{
	if (!value)
		return;

	loadSampleForSlot(slot1, FileName1, FilePath1);
	component.setValue(0);
}

inline function onLoadSample2Control(component, value)
{
	if (!value)
		return;

	loadSampleForSlot(slot2, FileName2, FilePath2);
	component.setValue(0);
}

LoadSample1.setControlCallback(onLoadSample1Control);
LoadSample2.setControlCallback(onLoadSample2Control);

Content.setSuspendTimerCallback(false);

function onTimer()
{
	if (!isInternalSampleUpdate)
	{
		local newPath1 = FilePath1.get("text");
		local newPath2 = FilePath2.get("text");

		if (newPath1 != lastPath1)
		{
			lastPath1 = newPath1;
			recallSampleFromPath(slot1, FileName1, FilePath1);
		}

		if (newPath2 != lastPath2)
		{
			lastPath2 = newPath2;
			recallSampleFromPath(slot2, FileName2, FilePath2);
		}
	}
}

Synth.startTimer(200);


inline function onFilePath1Control(component, value)


{
	slot1.loadFile(FilePath1.getValue());
};

Content.getComponent("FilePath1").setControlCallback(onFilePath1Control);


inline function onFilePath2Control(component, value)


{
	slot2.loadFile(FilePath2.getValue());
};

Content.getComponent("FilePath2").setControlCallback(onFilePath2Control);


