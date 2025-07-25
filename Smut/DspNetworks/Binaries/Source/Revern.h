#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace Revern_impl
{
// ===========================| Node & Parameter type declarations |===========================

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::hole<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain14_t<NV>>, 
                                   chain57_t<NV>>;

template <int NV>
using xfade_2x_lin_t = container::chain<parameter::empty, 
                                        wrap::fix<2, xfader_t<NV>>, 
                                        split12_t<NV>>;

namespace Revern_t_parameters
{
// Parameter list for Revern_impl::Revern_t ---------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Size_InputRange, 
                             0.5, 
                             3, 
                             0.01);
DECLARE_PARAMETER_RANGE(Size_0Range, 
                        0.5, 
                        3.);

template <int NV>
using Size_0 = parameter::from0To1<project::hole<NV>, 
                                   2, 
                                   Size_0Range>;

template <int NV>
using Size = parameter::chain<Size_InputRange, Size_0<NV>>;

template <int NV>
using Mix = parameter::plain<Revern_impl::xfader_t<NV>, 
                             0>;
template <int NV>
using Time = parameter::plain<project::hole<NV>, 0>;
template <int NV>
using Damp = parameter::plain<project::hole<NV>, 1>;
template <int NV>
using Diffuse = parameter::plain<project::hole<NV>, 3>;
template <int NV>
using Feedbk = parameter::plain<project::hole<NV>, 4>;
template <int NV>
using Depth = parameter::plain<project::hole<NV>, 5>;
template <int NV>
using Freq = parameter::plain<project::hole<NV>, 6>;
template <int NV>
using Revern_t_plist = parameter::list<Mix<NV>, 
                                       Size<NV>, 
                                       Time<NV>, 
                                       Damp<NV>, 
                                       Diffuse<NV>, 
                                       Feedbk<NV>, 
                                       Depth<NV>, 
                                       Freq<NV>>;
}

template <int NV>
using Revern_t_ = container::chain<Revern_t_parameters::Revern_t_plist<NV>, 
                                   wrap::fix<2, xfade_2x_lin_t<NV>>>;

// ===============================| Root node initialiser class |===============================

template <int NV> struct instance: public Revern_impl::Revern_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Revern);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(128)
		{
			0x005C, 0x0000, 0x0000, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0001, 0x0000, 0x6953, 0x657A, 0x0000, 0x0000, 0x003F, 0x4000, 
            0x9940, 0x9999, 0x003F, 0x8000, 0x0A3F, 0x23D7, 0x5C3C, 0x0200, 
            0x0000, 0x5400, 0x6D69, 0x0065, 0x126E, 0x3A83, 0x9999, 0x3FB9, 
            0x88CE, 0x3E92, 0x0000, 0x3F80, 0xB717, 0x38D1, 0x005C, 0x0003, 
            0x0000, 0x6144, 0x706D, 0x0000, 0x0000, 0xA400, 0x7D70, 0xA43F, 
            0x7D70, 0x003F, 0x8000, 0x6F3F, 0x8312, 0x5C3A, 0x0400, 0x0000, 
            0x4400, 0x6669, 0x7566, 0x6573, 0x0000, 0x0000, 0xA400, 0x7D70, 
            0x003F, 0x0000, 0x003F, 0x8000, 0x173F, 0xD1B7, 0x5C38, 0x0500, 
            0x0000, 0x4600, 0x6565, 0x6264, 0x006B, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x6666, 0x3F66, 0x0000, 0x3F80, 0xD70A, 0x3C23, 0x005C, 
            0x0006, 0x0000, 0x6544, 0x7470, 0x0068, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xCCCD, 0x3DCC, 0x0000, 0x3F80, 0x126F, 0x3A83, 0x005C, 
            0x0007, 0x0000, 0x7246, 0x7165, 0x0000, 0x0000, 0x0000, 0x2000, 
            0x0041, 0x0000, 0x0040, 0x8000, 0x0A3F, 0x23D7, 0x003C, 0x0000
		};
		SNEX_METADATA_ENCODED_MOD_INFO(17)
		{
			0x003A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0000
		};
	};
	
	instance()
	{
		// Node References --------------------------------------------------------------------
		
		auto& xfade_2x_lin = this->getT(0);                  // Revern_impl::xfade_2x_lin_t<NV>
		auto& xfader = this->getT(0).getT(0);                // Revern_impl::xfader_t<NV>
		auto& split12 = this->getT(0).getT(1);               // Revern_impl::split12_t<NV>
		auto& chain14 = this->getT(0).getT(1).getT(0);       // Revern_impl::chain14_t<NV>
		auto& gain1 = this->getT(0).getT(1).getT(0).getT(0); // core::gain<NV>
		auto& chain57 = this->getT(0).getT(1).getT(1);       // Revern_impl::chain57_t<NV>
		auto& faust = this->getT(0).getT(1).getT(1).getT(0); // project::hole<NV>
		auto& gain2 = this->getT(0).getT(1).getT(1).getT(1); // core::gain<NV>
		
		// Parameter Connections --------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // Mix -> xfader::Value
		
		this->getParameterT(1).connectT(0, faust); // Size -> faust::size
		
		this->getParameterT(2).connectT(0, faust); // Time -> faust::delayTime
		
		this->getParameterT(3).connectT(0, faust); // Damp -> faust::damping
		
		this->getParameterT(4).connectT(0, faust); // Diffuse -> faust::diffusion
		
		this->getParameterT(5).connectT(0, faust); // Feedbk -> faust::feedback
		
		this->getParameterT(6).connectT(0, faust); // Depth -> faust::modDepth
		
		this->getParameterT(7).connectT(0, faust); // Freq -> faust::modFreq
		
		// Modulation Connections -------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1); // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain2); // xfader -> gain2::Gain
		
		// Default Values ---------------------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // faust::delayTime is automated
		; // faust::damping is automated
		; // faust::size is automated
		; // faust::diffusion is automated
		; // faust::feedback is automated
		; // faust::modDepth is automated
		; // faust::modFreq is automated
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.2);
		this->setParameterT(2, 0.2862);
		this->setParameterT(3, 0.99);
		this->setParameterT(4, 0.5);
		this->setParameterT(5, 0.9);
		this->setParameterT(6, 0.1);
		this->setParameterT(7, 2);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ====================================| Public Definition |====================================

namespace project
{
// polyphonic template declaration

template <int NV>
using Revern = wrap::node<Revern_impl::instance<NV>>;
}


