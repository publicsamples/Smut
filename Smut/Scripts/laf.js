

//Draw Combobox

const var laf = Engine.createGlobalScriptLookAndFeel();



laf.registerFunction("drawComboBox", function(g, obj)
{
    g.setColour(obj.bgColour);
    g.drawRoundedRectangle(obj.area, 3.0, 3.0);
    g.setColour(Colours.withAlpha(obj.textColour, (obj.enabled && obj.active) ? 1.0 : 0.2));
    ///g.setFont("Montserrat", 12.0);
   
  
    var a = obj.area;
    g.drawAlignedText(obj.text, [a[0] + 0, a[0], a[2]-1, a[3]], "centred");


});

laf.registerFunction("drawSliderPack", function(g, obj)
{
    g.fillRoundedRectangle(obj.area, 8.0);
        g.rotate(90, 90);
       g.setFont("Montserrat", 16.0);


});

laf.registerFunction("drawPresetBrowserListItem", function(g, obj)
{
    if(obj.selected)
    {
        g.setColour(0x6DD3ADAD);
        g.fillRoundedRectangle(obj.area, 5.0);
        
       g.setFont("Montserrat", 16.0);
    }
   
    g.setColour(obj.textColour);
    g.setFont("Montserrat", 16.0);
    g.drawAlignedText(obj.text, obj.area, "centred");
});


laf.registerFunction("drawTableRuler", function(g, obj)
{
    g.setColour(Colours.withAlpha(obj.bgColour, 2.1));
    
    var x = obj.position * obj.area[2];
    
    g.drawLine(x, x, 0, obj.area[3], 10.0);
    g.setColour(obj.bgColour);
    g.drawLine(x, x, 0, obj.area[3], 1);
});

laf.registerFunction("drawToggleButton", function(g, obj)
{
    g.setColour(obj.bgColour);   
    g.fillRoundedRectangle(obj.area, 4.0);
    
    if(obj.over)
        g.fillRoundedRectangle(obj.area, 4.0);
    
    if(obj.down)
        g.fillRoundedRectangle(obj.area, 4.0);
        
    g.setColour(Colours.withAlpha(obj.textColour, obj.value ? 1.0 : 0.3));
    g.setFont("Montserrat", 18.0);
    g.drawAlignedText(obj.text, obj.area, "centred");
});


const var CONST_LABEL_Backbground = 0;



const CONST_DisabledIndicatorColour = 0xFFC8F9F7c;

const CONST_InactiveIndicatorColour = 0xFFC8F9F7c;
const STARTX = 0;
const STARTY = 1;
const WIDTH = 2;
const HEIGHT = 2;

var LAF_Button = Content.createLocalLookAndFeel();


LAF_Button.registerFunction("drawToggleButton", function(g, obj)
{

	var WidgetArea = obj.area;
	
	// Is the button enabled?
	var ButtonActive = obj.enabled;

	 if (ButtonActive) {
		var opacity = obj.over ? 1.0 - (obj.down * 0.2) : 0.8 - (obj.down * 0.2);
		g.setGradientFill([Colours.withAlpha(obj.itemColour1, opacity), WidgetArea[STARTX], WidgetArea[STARTY], Colours.withAlpha(obj.itemColour2, opacity), WidgetArea[STARTX], WidgetArea[HEIGHT]]);
	} else {
	//	g.setColour(CONST_InactiveSurfaceColour);
	}

	// Draw the surface.
//	g.fillRoundedRectangle(WidgetArea, 4);

	// ------------- Indicator Light
	
	// Choose the colour(s).
	if (ButtonActive) {
		if (obj.value) { var fillColour = obj.bgColour; } else { var fillColour = CONST_DisabledIndicatorColour; }
		g.setColour(Colours.withAlpha(fillColour, obj.over ? 1.0 : 0.7));
	} else {
		g.setColour(CONST_InactiveIndicatorColour);
	}
	
	// Draw the indicator.
	g.fillEllipse([WidgetArea[STARTX] + 8, WidgetArea[STARTY] + WidgetArea[HEIGHT] / 2 - 4, 8, 8]);
	});

///////////////// BUTTON DEFINITION ///////////////// 

const var EnvButtons = [Content.getComponent("EnvMode1"),
                        Content.getComponent("ClkTring1"),
                        Content.getComponent("ClkTring2"),
                        Content.getComponent("EnvMode2"),
                        Content.getComponent("RampOS1"),
                        Content.getComponent("RampOS2"),
                        Content.getComponent("RampOS3"),
                        Content.getComponent("RampOS4"),
                        Content.getComponent("ClkTring3"),
                        Content.getComponent("ClkTring4")];
                        
for(s in EnvButtons)
      s.setLocalLookAndFeel(LAF_Button);  
      
const var MiscButtons = [Content.getComponent("LpHpCt"),
                         Content.getComponent("ScriptButton1")];

 
 for(s in MiscButtons)
       s.setLocalLookAndFeel(LAF_Button);                         
