/* ------------------------------------------------------------
name: "shfiter"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _shfiter -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___shfiter_H__
#define  ___shfiter_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _shfiter
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


struct _shfiter final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec0[2];
	int IOTA0;
	float fVec0[131072];
	float fVec1[131072];
	int fSampleRate;
	
	_shfiter() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _shfiter -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("filename", "shfiter.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "shfiter");
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
	
	_shfiter* clone() {
		return new _shfiter();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Pitch Shifter");
		ui_interface->addHorizontalSlider("shift (note)", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-24.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.1f));
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
		float fSlow2 = std::pow(2.0f, 0.083333336f * std::max<float>(-24.0f, std::min<float>(24.0f, float(fHslider2))));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[0] = std::fmod(fSlow1 + (fRec0[1] + 1.0f - fSlow2), fSlow1);
			float fTemp0 = std::min<float>(fSlow0 * fRec0[0], 1.0f);
			float fTemp1 = std::floor(fRec0[0]);
			float fTemp2 = fRec0[0] - fTemp1;
			float fTemp3 = float(input0[i0]);
			fVec0[IOTA0 & 131071] = fTemp3;
			int iTemp4 = int(fRec0[0]);
			int iTemp5 = std::min<int>(65537, std::max<int>(0, iTemp4 + 1));
			int iTemp6 = std::min<int>(65537, std::max<int>(0, iTemp4));
			float fTemp7 = 1.0f - fRec0[0];
			float fTemp8 = fTemp1 + fTemp7;
			float fTemp9 = 1.0f - fTemp0;
			float fTemp10 = fSlow1 + fRec0[0];
			int iTemp11 = int(fTemp10);
			int iTemp12 = std::min<int>(65537, std::max<int>(0, iTemp11 + 1));
			float fTemp13 = std::floor(fTemp10);
			float fTemp14 = fSlow1 + (fRec0[0] - fTemp13);
			int iTemp15 = std::min<int>(65537, std::max<int>(0, iTemp11));
			float fTemp16 = fTemp13 + fTemp7 - fSlow1;
			output0[i0] = FAUSTFLOAT(fTemp0 * (fTemp2 * fVec0[(IOTA0 - iTemp5) & 131071] + fVec0[(IOTA0 - iTemp6) & 131071] * fTemp8) + fTemp9 * (fVec0[(IOTA0 - iTemp12) & 131071] * fTemp14 + fVec0[(IOTA0 - iTemp15) & 131071] * fTemp16));
			float fTemp17 = float(input1[i0]);
			fVec1[IOTA0 & 131071] = fTemp17;
			output1[i0] = FAUSTFLOAT(fTemp0 * (fTemp2 * fVec1[(IOTA0 - iTemp5) & 131071] + fVec1[(IOTA0 - iTemp6) & 131071] * fTemp8) + fTemp9 * (fVec1[(IOTA0 - iTemp12) & 131071] * fTemp14 + fVec1[(IOTA0 - iTemp15) & 131071] * fTemp16));
			fRec0[1] = fRec0[0];
			IOTA0 = IOTA0 + 1;
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "shfiter.dsp"
	#define FAUST_CLASS_NAME "_shfiter"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _shfiter -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 3
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Pitch Shifter/shift (note)", fHslider2, 0.0f, -24.0f, 24.0f, 0.1f);
	FAUST_ADDHORIZONTALSLIDER("Pitch Shifter/window (samples)", fHslider1, 1e+03f, 5e+01f, 1e+04f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("Pitch Shifter/xfade (samples)", fHslider0, 1e+01f, 1.0f, 1e+04f, 1.0f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, shift_(note), "Pitch Shifter/shift (note)", fHslider2, 0.0f, -24.0f, 24.0f, 0.1f) \
		p(HORIZONTALSLIDER, window_(samples), "Pitch Shifter/window (samples)", fHslider1, 1e+03f, 5e+01f, 1e+04f, 1.0f) \
		p(HORIZONTALSLIDER, xfade_(samples), "Pitch Shifter/xfade (samples)", fHslider0, 1e+01f, 1.0f, 1e+04f, 1.0f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
