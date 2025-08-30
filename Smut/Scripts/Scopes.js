//osc1

const var OsdDp1 = Synth.getDisplayBufferSource("SMUT");

const var rb2 = OsdDp1.getDisplayBuffer(1);


const var BUFFER_LENGTH1 = 512;
const var BUFFER_LENGTH2 = 512;
const var P2 = Content.getComponent("VisPanel2");


// These are the properties that you can give the peak meter
// NumChannels must be 1, but you can set another buffer length for the display
const var properties = {
  "BufferLength": BUFFER_LENGTH1,
  "NumChannels": 1
};
const var properties2 = {
  "BufferLength": BUFFER_LENGTH2,
  "NumChannels": 1
};
// This will override the default properties of the node. You can use the same
// procedure to customize the FFT properties too (like Window type, etc).
rb2.setRingBufferProperties(properties2);

// We need to periodically query the ring buffer to create a signal path
// so we use the panel's timers for this.
P2.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = rb2.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

P2.startTimer(30);

P2.setPaintRoutine(function(g)
{
	g.fillAll(0xFFF5EDD8);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


//OSC2

P2.setPaintRoutine(function(g)
{
	g.fillAll(0xFFF5EDD8);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


const var rb1 = OsdDp1.getDisplayBuffer(2);



const var P1 = Content.getComponent("VisPanel1");


// These are the properties that you can give the peak meter
// NumChannels must be 1, but you can set another buffer length for the display


// This will override the default properties of the node. You can use the same
// procedure to customize the FFT properties too (like Window type, etc).
rb1.setRingBufferProperties(properties);

// We need to periodically query the ring buffer to create a signal path
// so we use the panel's timers for this.
P1.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = rb1.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH1, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

P1.startTimer(30);

//OSC2

P1.setPaintRoutine(function(g)
{
	g.fillAll(0xFFF5EDD8);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});




