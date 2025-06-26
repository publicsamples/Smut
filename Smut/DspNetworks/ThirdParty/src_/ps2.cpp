/* ------------------------------------------------------------
name: "ps2"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _ps2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___ps2_H__
#define  ___ps2_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _ps2
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


struct _ps2 final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec0[2];
	int IOTA0;
	float fVec0[131072];
	float fVec1[131072];
	int fSampleRate;
	
	_ps2() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _ps2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("filename", "ps2.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "ps2");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1e+01f);
		fHslider1 = FAUSTFLOAT(1e+03f);
		fHslider2 = FAUSTFLOAT(0.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 131072; l1 = l1 + 1) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 131072; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_ps2* clone() {
		return new _ps2();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Pitch Shifter");
		ui_interface->addHorizontalSlider("shift (freq)", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-64.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("window (samples)", &fHslider1, FAUSTFLOAT(1e+03f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("xfade (samples)", &fHslider0, FAUSTFLOAT(1e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = 1.0f / std::max<float>(1.0f, std::min<float>(1e+04f, float(fHslider0)));
		float fSlow1 = std::max<float>(5e+01f, std::min<float>(1e+04f, float(fHslider1)));
		float fSlow2 = std::pow(2.0f, 0.083333336f * std::max<float>(-64.0f, std::min<float>(64.0f, float(fHslider2))));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[0] = std::fmod(fSlow1 + (fRec0[1] + 1.0f - fSlow2), fSlow1);
			float fTemp0 = std::min<float>(fSlow0 * fRec0[0], 1.0f);
			float fTemp1 = 1.0f - fTemp0;
			float fTemp2 = float(input0[i0]);
			fVec0[IOTA0 & 131071] = fTemp2;
			float fTemp3 = fSlow1 + fRec0[0];
			int iTemp4 = int(fTemp3);
			int iTemp5 = std::min<int>(65537, std::max<int>(0, iTemp4));
			float fTemp6 = std::floor(fTemp3);
			float fTemp7 = 1.0f - fRec0[0];
			float fTemp8 = fTemp6 + fTemp7 - fSlow1;
			int iTemp9 = std::min<int>(65537, std::max<int>(0, iTemp4 + 1));
			float fTemp10 = fSlow1 + (fRec0[0] - fTemp6);
			float fTemp11 = std::floor(fRec0[0]);
			float fTemp12 = fRec0[0] - fTemp11;
			int iTemp13 = int(fRec0[0]);
			int iTemp14 = std::min<int>(65537, std::max<int>(0, iTemp13 + 1));
			float fTemp15 = fTemp11 + fTemp7;
			int iTemp16 = std::min<int>(65537, std::max<int>(0, iTemp13));
			output0[i0] = FAUSTFLOAT(fTemp1 * (fVec0[(IOTA0 - iTemp5) & 131071] * fTemp8 + fVec0[(IOTA0 - iTemp9) & 131071] * fTemp10) + fTemp0 * (fTemp12 * fVec0[(IOTA0 - iTemp14) & 131071] + fTemp15 * fVec0[(IOTA0 - iTemp16) & 131071]));
			float fTemp17 = float(input1[i0]);
			fVec1[IOTA0 & 131071] = fTemp17;
			output1[i0] = FAUSTFLOAT(fTemp0 * (fTemp15 * fVec1[(IOTA0 - iTemp16) & 131071] + fTemp12 * fVec1[(IOTA0 - iTemp14) & 131071]) + fTemp1 * (fTemp8 * fVec1[(IOTA0 - iTemp5) & 131071] + fTemp10 * fVec1[(IOTA0 - iTemp9) & 131071]));
			fRec0[1] = fRec0[0];
			IOTA0 = IOTA0 + 1;
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "ps2.dsp"
	#define FAUST_CLASS_NAME "_ps2"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _ps2 -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 3
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Pitch Shifter/shift (freq)", fHslider2, 0.0f, -64.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("Pitch Shifter/window (samples)", fHslider1, 1e+03f, 5e+01f, 1e+04f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("Pitch Shifter/xfade (samples)", fHslider0, 1e+01f, 1.0f, 1e+04f, 1.0f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, shift_(freq), "Pitch Shifter/shift (freq)", fHslider2, 0.0f, -64.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, window_(samples), "Pitch Shifter/window (samples)", fHslider1, 1e+03f, 5e+01f, 1e+04f, 1.0f) \
		p(HORIZONTALSLIDER, xfade_(samples), "Pitch Shifter/xfade (samples)", fHslider0, 1e+01f, 1.0f, 1e+04f, 1.0f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
