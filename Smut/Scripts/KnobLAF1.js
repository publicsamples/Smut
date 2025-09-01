const var KnobLaf = Content.createLocalLookAndFeel();




KnobLaf.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	g.setColour(0x00000000);

	var radius = 35 - obj.clicked;

	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 2));
	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 3));
	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 4));
	
	

	var p = Content.createPath();
	
//	p.startNewSubPath(0, 0);
//	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], -2.7, 2.7);
	
	g.setColour( obj.itemColour1);
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	g.setColour(underDrag ? 0xFF303030 : 0xFF303030);
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);

	p = Content.createPath();
		
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], start, -2.66 + Math.max(0.01, obj.valueNormalized) * 2 * 2.66);
	
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 1.0 : 0.8));
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	
	p = Content.createPath();
			
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
//	var modValue = matrix.getModValue(obj.id);
	
	
///	p.addArc([0.0, 0.0, 1.0, 1.0], modStart, -2.66 + Math.max(0.01, modValue) * 2 * 2.66);
	
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 0.8 : 0.5));
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);

//	g.addDropShadowFromAlpha(0x44000000, 2);
	
	g.setGradientFill([obj.bgColour, 0.0, 0.0,
					   obj.bgColour, 0.0, obj.area[3], false]);
	g.fillEllipse(Rect.withSizeKeepingCentre(obj.area, radius, radius));
	

	
	g.setGradientFill([obj.itemColour2, 0.0, 0.0,
					   obj.itemColour2, 0.0, obj.area[3], true]);
	g.drawEllipse(Rect.withSizeKeepingCentre(obj.area, radius-3, radius-3), 3.5);
	
	if(underDrag)
	{
		g.setColour(0xFF515151);

		
		g.fillEllipse(Rect.reduced(obj.area, 6));
	}
	
	g.setColour(Colours.black);
	g.rotate(-2.66 + obj.valueNormalized * 2.66 * 2, Rect.getCentre(obj.area));
	g.fillRect(Rect.translated(Rect.withSizeKeepingCentre(obj.area, 2, 11), 0, -8));
	
	
	
	//g.drawAlignedText(obj.text, obj.area, "centred");
});


KnobLaf.registerFunction("drawTableRuler", function(g, obj)
{
    g.setColour(Colours.withAlpha(obj.textColour, 5));
    
    var x = obj.position * obj.area[2];
    
    g.drawLine(x, x, 0, obj.area[3], 0.0);
    g.setColour(obj.bgColour);
    g.drawLine(x, x, 0, obj.area[3], 1);
});

//const var UserShape1 = Content.getComponent("UserShape1").setLocalLookAndFeel(KnobLaf);     ;





//const var ShpKnbs = [Content.getComponent("FileSmooth1")];



const var OscKbs = [Content.getComponent("OscSemiTone1"),
                    Content.getComponent("OscSemiTone2"),
                    Content.getComponent("OscCent2"),
                    Content.getComponent("OscCent1"),
                    Content.getComponent("OscShape1"),
                    Content.getComponent("OscShape2"),
                    Content.getComponent("Osc1into2"),
                    Content.getComponent("Osc2into1"),
                    Content.getComponent("Divide1"),
                    Content.getComponent("Divide")];

for(s in OscKbs)
     s.setLocalLookAndFeel(KnobLaf);     

const var FileKnbs = [Content.getComponent("PosDiv"),
                      Content.getComponent("PosMod"),
                      Content.getComponent("FileInput"),
                      Content.getComponent("FilePos1"),
                      Content.getComponent("FileInput1"),
                       Content.getComponent("FilePosi1"),
                       Content.getComponent("PosMod1"),
                        Content.getComponent("PosDiv1")];

for(s in FileKnbs)
     s.setLocalLookAndFeel(KnobLaf); 
     
     
const var FilterKnbs = [Content.getComponent("Cut1"),
                        Content.getComponent("Q1"),
                        Content.getComponent("FilterGain1"),
                        Content.getComponent("Pan1"),
                        Content.getComponent("Cut2"),
                        Content.getComponent("q2"),
                        Content.getComponent("FilterGain2"),
                        Content.getComponent("Pan")];

 for(s in FilterKnbs)
      s.setLocalLookAndFeel(KnobLaf);

const var EnvKnbs = [Content.getComponent("PosDiv9"),
                     Content.getComponent("PosDiv8"),
                     Content.getComponent("PosDiv6"),
                     Content.getComponent("PosDiv7"),
                     Content.getComponent("PosDiv3"),
                     Content.getComponent("PosDiv2")];

for(s in EnvKnbs)
     s.setLocalLookAndFeel(KnobLaf);
     
     
     const var LfoKnbs = [Content.getComponent("PosDiv4"),
                          Content.getComponent("PosDiv5"),
                          Content.getComponent("PosDiv10"),
                          Content.getComponent("PosDiv11"),
                          Content.getComponent("PosDiv12"),
                          Content.getComponent("PosDiv13")];
     
for(s in LfoKnbs)
     s.setLocalLookAndFeel(KnobLaf);    
     
const var MasterKnbs = [Content.getComponent("Vol1"),
                        Content.getComponent("Vol")];
for(s in MasterKnbs)
     s.setLocalLookAndFeel(KnobLaf);                   

      
     