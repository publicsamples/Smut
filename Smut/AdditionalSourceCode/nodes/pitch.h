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

namespace pitch_impl
{
// ==============================| Node & Parameter type declarations |==============================

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<fx::pitch_shift<NV>, 0>>;
template <int NV>
using clone_cable1_t = control::clone_cable<parameter::cloned<parameter::plain<minmax_t<NV>, 0>>, 
                                            duplilogic::spread>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, minmax_t<NV>>, 
                                       fx::pitch_shift<NV>, 
                                       core::gain<NV>>;
template <int NV>
using clone_t = wrap::fix_clonecopy<clone_child_t<NV>, 8>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, clone_cable1_t<NV>>, 
                                  clone_t<NV>>;

template <int NV> using minmax23_t = minmax_t<NV>;
template <int NV>
using clone_cable2_t = control::clone_cable<parameter::cloned<parameter::plain<minmax23_t<NV>, 0>>, 
                                            duplilogic::scale>;

template <int NV>
using clone_child15_t = container::chain<parameter::empty, 
                                         wrap::fix<2, minmax23_t<NV>>, 
                                         fx::pitch_shift<NV>, 
                                         core::gain<NV>>;
template <int NV>
using clone1_t = wrap::fix_clonecopy<clone_child15_t<NV>, 4>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, clone_cable2_t<NV>>, 
                                  clone1_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(cable_table_modRange, 
                             0.25, 
                             4., 
                             0.430677);

template <int NV>
using cable_table_mod = parameter::from0To1<fx::pitch_shift<NV>, 
                                            0, 
                                            cable_table_modRange>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.000143409f, 0.00112236f, 0.0021013f,
		0.00308025f, 0.0040592f, 0.00503814f, 0.00601709f, 0.00699604f, 0.00797504f,
		0.00895399f, 0.00993294f, 0.0109119f, 0.0118908f, 0.0128698f, 0.0138487f,
		0.0148277f, 0.0158066f, 0.0167856f, 0.0177645f, 0.0187435f, 0.0197224f,
		0.0207014f, 0.0216804f, 0.0226593f, 0.0236382f, 0.0246172f, 0.0255961f,
		0.0265751f, 0.027554f, 0.028533f, 0.0295119f, 0.0304909f, 0.0314698f,
		0.0324488f, 0.0334278f, 0.0344067f, 0.0353857f, 0.0363646f, 0.0373436f,
		0.0383225f, 0.0393015f, 0.0402804f, 0.0412593f, 0.0422383f, 0.0432172f,
		0.0441962f, 0.0451752f, 0.0461541f, 0.0471331f, 0.048112f, 0.049091f,
		0.0500699f, 0.0510489f, 0.0520278f, 0.0530068f, 0.0539857f, 0.0549647f,
		0.0559436f, 0.0569226f, 0.0579016f, 0.0588805f, 0.0598595f, 0.0608384f,
		0.0618173f, 0.0627963f, 0.0637752f, 0.0647542f, 0.0657331f, 0.0667121f,
		0.0688481f, 0.0739409f, 0.0790339f, 0.0841267f, 0.0892196f, 0.0943124f,
		0.0994054f, 0.104498f, 0.109591f, 0.114684f, 0.119777f, 0.12487f,
		0.129963f, 0.135055f, 0.140148f, 0.145241f, 0.150334f, 0.155427f,
		0.16052f, 0.165613f, 0.170706f, 0.175799f, 0.180891f, 0.185984f,
		0.191077f, 0.19617f, 0.201263f, 0.206356f, 0.211449f, 0.216542f,
		0.221635f, 0.226727f, 0.23182f, 0.236913f, 0.242006f, 0.247099f,
		0.252192f, 0.257285f, 0.262378f, 0.26747f, 0.272563f, 0.277656f,
		0.282287f, 0.286106f, 0.289926f, 0.293745f, 0.297565f, 0.301385f,
		0.305204f, 0.309024f, 0.312844f, 0.316663f, 0.320483f, 0.324303f,
		0.328122f, 0.331942f, 0.335762f, 0.339581f, 0.343401f, 0.347221f,
		0.35104f, 0.35486f, 0.35868f, 0.362499f, 0.366319f, 0.370139f,
		0.373958f, 0.377778f, 0.381598f, 0.385417f, 0.389237f, 0.393057f,
		0.396876f, 0.400696f, 0.404516f, 0.408335f, 0.412155f, 0.415975f,
		0.419794f, 0.423614f, 0.427433f, 0.431253f, 0.435073f, 0.438893f,
		0.442712f, 0.446532f, 0.450352f, 0.454171f, 0.457991f, 0.46181f,
		0.46563f, 0.46945f, 0.473269f, 0.477089f, 0.480909f, 0.484728f,
		0.488548f, 0.492368f, 0.496533f, 0.501084f, 0.505635f, 0.510186f,
		0.514737f, 0.519289f, 0.52384f, 0.528391f, 0.532942f, 0.537493f,
		0.542044f, 0.546595f, 0.551146f, 0.555697f, 0.560248f, 0.564799f,
		0.56935f, 0.573901f, 0.578453f, 0.583004f, 0.587555f, 0.592106f,
		0.596657f, 0.601208f, 0.605759f, 0.61031f, 0.614861f, 0.619412f,
		0.623963f, 0.628515f, 0.633066f, 0.637617f, 0.642168f, 0.646719f,
		0.65127f, 0.655821f, 0.660372f, 0.664923f, 0.669474f, 0.674025f,
		0.678576f, 0.683128f, 0.687679f, 0.69223f, 0.696781f, 0.701332f,
		0.705883f, 0.711105f, 0.716844f, 0.722583f, 0.728323f, 0.734062f,
		0.739802f, 0.745541f, 0.75128f, 0.75702f, 0.762759f, 0.768498f,
		0.774238f, 0.779977f, 0.785716f, 0.791456f, 0.797195f, 0.802934f,
		0.808674f, 0.814413f, 0.820152f, 0.825892f, 0.831631f, 0.83737f,
		0.84311f, 0.848849f, 0.854588f, 0.860328f, 0.866067f, 0.871806f,
		0.877546f, 0.883285f, 0.889024f, 0.894764f, 0.900503f, 0.906242f,
		0.911982f, 0.917721f, 0.92346f, 0.9292f, 0.934939f, 0.940678f,
		0.946418f, 0.952157f, 0.957897f, 0.963636f, 0.969375f, 0.975115f,
		0.980854f, 0.986593f, 0.992333f, 0.998072f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;
template <int NV>
using midi_t = wrap::mod<parameter::plain<cable_table_t<NV>, 0>, 
                         control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, midi_t<NV>>, 
                                 cable_table_t<NV>, 
                                 fx::pitch_shift<NV>>;

template <int NV> using minmax44_t = minmax_t<NV>;
template <int NV>
using clone_cable3_t = control::clone_cable<parameter::cloned<parameter::plain<minmax44_t<NV>, 0>>, 
                                            duplilogic::scale>;

template <int NV> using cable_table1_mod = cable_table_mod<NV>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.000143409f, 0.00112236f, 0.0021013f,
		0.00308025f, 0.0040592f, 0.00503814f, 0.00601709f, 0.00699604f, 0.00797504f,
		0.00895399f, 0.00993294f, 0.0109119f, 0.0118908f, 0.0128698f, 0.0138487f,
		0.0148277f, 0.0158066f, 0.0167856f, 0.0177645f, 0.0187435f, 0.0197224f,
		0.0207014f, 0.0216804f, 0.0226593f, 0.0236382f, 0.0246172f, 0.0255961f,
		0.0265751f, 0.027554f, 0.028533f, 0.0295119f, 0.0304909f, 0.0314698f,
		0.0324488f, 0.0334278f, 0.0344067f, 0.0353857f, 0.0363646f, 0.0373436f,
		0.0383225f, 0.0393015f, 0.0402804f, 0.0412593f, 0.0422383f, 0.0432172f,
		0.0441962f, 0.0451752f, 0.0461541f, 0.0471331f, 0.048112f, 0.049091f,
		0.0500699f, 0.0510489f, 0.0520278f, 0.0530068f, 0.0539857f, 0.0549647f,
		0.0559436f, 0.0569226f, 0.0579016f, 0.0588805f, 0.0598595f, 0.0608384f,
		0.0618173f, 0.0627963f, 0.0637752f, 0.0647542f, 0.0657331f, 0.0667121f,
		0.0688481f, 0.0739409f, 0.0790339f, 0.0841267f, 0.0892196f, 0.0943124f,
		0.0994054f, 0.104498f, 0.109591f, 0.114684f, 0.119777f, 0.12487f,
		0.129963f, 0.135055f, 0.140148f, 0.145241f, 0.150334f, 0.155427f,
		0.16052f, 0.165613f, 0.170706f, 0.175799f, 0.180891f, 0.185984f,
		0.191077f, 0.19617f, 0.201263f, 0.206356f, 0.211449f, 0.216542f,
		0.221635f, 0.226727f, 0.23182f, 0.236913f, 0.242006f, 0.247099f,
		0.252192f, 0.257285f, 0.262378f, 0.26747f, 0.272563f, 0.277656f,
		0.282287f, 0.286106f, 0.289926f, 0.293745f, 0.297565f, 0.301385f,
		0.305204f, 0.309024f, 0.312844f, 0.316663f, 0.320483f, 0.324303f,
		0.328122f, 0.331942f, 0.335762f, 0.339581f, 0.343401f, 0.347221f,
		0.35104f, 0.35486f, 0.35868f, 0.362499f, 0.366319f, 0.370139f,
		0.373958f, 0.377778f, 0.381598f, 0.385417f, 0.389237f, 0.393057f,
		0.396876f, 0.400696f, 0.404516f, 0.408335f, 0.412155f, 0.415975f,
		0.419794f, 0.423614f, 0.427433f, 0.431253f, 0.435073f, 0.438893f,
		0.442712f, 0.446532f, 0.450352f, 0.454171f, 0.457991f, 0.46181f,
		0.46563f, 0.46945f, 0.473269f, 0.477089f, 0.480909f, 0.484728f,
		0.488548f, 0.492368f, 0.496533f, 0.501084f, 0.505635f, 0.510186f,
		0.514737f, 0.519289f, 0.52384f, 0.528391f, 0.532942f, 0.537493f,
		0.542044f, 0.546595f, 0.551146f, 0.555697f, 0.560248f, 0.564799f,
		0.56935f, 0.573901f, 0.578453f, 0.583004f, 0.587555f, 0.592106f,
		0.596657f, 0.601208f, 0.605759f, 0.61031f, 0.614861f, 0.619412f,
		0.623963f, 0.628515f, 0.633066f, 0.637617f, 0.642168f, 0.646719f,
		0.65127f, 0.655821f, 0.660372f, 0.664923f, 0.669474f, 0.674025f,
		0.678576f, 0.683128f, 0.687679f, 0.69223f, 0.696781f, 0.701332f,
		0.705883f, 0.711105f, 0.716844f, 0.722583f, 0.728323f, 0.734062f,
		0.739802f, 0.745541f, 0.75128f, 0.75702f, 0.762759f, 0.768498f,
		0.774238f, 0.779977f, 0.785716f, 0.791456f, 0.797195f, 0.802934f,
		0.808674f, 0.814413f, 0.820152f, 0.825892f, 0.831631f, 0.83737f,
		0.84311f, 0.848849f, 0.854588f, 0.860328f, 0.866067f, 0.871806f,
		0.877546f, 0.883285f, 0.889024f, 0.894764f, 0.900503f, 0.906242f,
		0.911982f, 0.917721f, 0.92346f, 0.9292f, 0.934939f, 0.940678f,
		0.946418f, 0.952157f, 0.957897f, 0.963636f, 0.969375f, 0.975115f,
		0.980854f, 0.986593f, 0.992333f, 0.998072f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;
template <int NV>
using midi1_t = wrap::mod<parameter::plain<cable_table1_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using clone_child19_t = container::chain<parameter::empty, 
                                         wrap::fix<2, minmax44_t<NV>>, 
                                         midi1_t<NV>, 
                                         cable_table1_t<NV>, 
                                         fx::pitch_shift<NV>, 
                                         fx::pitch_shift<NV>, 
                                         core::gain<NV>>;
template <int NV>
using clone2_t = wrap::fix_clonecopy<clone_child19_t<NV>, 4>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, clone_cable3_t<NV>>, 
                                  clone2_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain1_t>, 
                                   chain2_t<NV>, 
                                   chain3_t<NV>, 
                                   chain_t<NV>, 
                                   chain4_t<NV>>;

template <int NV>
using pitch_t_ = container::chain<parameter::empty, 
                                  wrap::fix<2, branch_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public pitch_impl::pitch_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(pitch);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(2)
		{
			0x0000, 0x0000
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
		// Node References -------------------------------------------------------------------------
		
		auto& branch = this->getT(0);                               // pitch_impl::branch_t<NV>
		auto& chain1 = this->getT(0).getT(0);                       // pitch_impl::chain1_t
		auto& chain2 = this->getT(0).getT(1);                       // pitch_impl::chain2_t<NV>
		auto& clone_cable1 = this->getT(0).getT(1).getT(0);         // pitch_impl::clone_cable1_t<NV>
		auto& clone = this->getT(0).getT(1).getT(1);                // pitch_impl::clone_t<NV>                // pitch_impl::clone_child_t<NV>
		auto minmax = this->getT(0).getT(1).getT(1).getT(0);        // pitch_impl::minmax_t<NV>
		auto pitch_shift1 = this->getT(0).getT(1).getT(1).getT(1);  // fx::pitch_shift<NV>
		auto gain = this->getT(0).getT(1).getT(1).getT(2);          // core::gain<NV>
		auto& chain3 = this->getT(0).getT(2);                       // pitch_impl::chain3_t<NV>
		auto& clone_cable2 = this->getT(0).getT(2).getT(0);         // pitch_impl::clone_cable2_t<NV>
		auto& clone1 = this->getT(0).getT(2).getT(1);               // pitch_impl::clone1_t<NV>               // pitch_impl::clone_child15_t<NV>
		auto minmax23 = this->getT(0).getT(2).getT(1).getT(0);      // pitch_impl::minmax23_t<NV>
		auto pitch_shift39 = this->getT(0).getT(2).getT(1).getT(1); // fx::pitch_shift<NV>
		auto gain29 = this->getT(0).getT(2).getT(1).getT(2);        // core::gain<NV>
		auto& chain = this->getT(0).getT(3);                        // pitch_impl::chain_t<NV>
		auto& midi = this->getT(0).getT(3).getT(0);                 // pitch_impl::midi_t<NV>
		auto& cable_table = this->getT(0).getT(3).getT(1);          // pitch_impl::cable_table_t<NV>
		auto& pitch_shift = this->getT(0).getT(3).getT(2);          // fx::pitch_shift<NV>
		auto& chain4 = this->getT(0).getT(4);                       // pitch_impl::chain4_t<NV>
		auto& clone_cable3 = this->getT(0).getT(4).getT(0);         // pitch_impl::clone_cable3_t<NV>
		auto& clone2 = this->getT(0).getT(4).getT(1);               // pitch_impl::clone2_t<NV>               // pitch_impl::clone_child19_t<NV>
		auto minmax44 = this->getT(0).getT(4).getT(1).getT(0);      // pitch_impl::minmax44_t<NV>
		auto midi1 = this->getT(0).getT(4).getT(1).getT(1);         // pitch_impl::midi1_t<NV>
		auto cable_table1 = this->getT(0).getT(4).getT(1).getT(2);  // pitch_impl::cable_table1_t<NV>
		auto pitch_shift60 = this->getT(0).getT(4).getT(1).getT(3); // fx::pitch_shift<NV>
		auto pitch_shift67 = this->getT(0).getT(4).getT(1).getT(4); // fx::pitch_shift<NV>
		auto gain50 = this->getT(0).getT(4).getT(1).getT(5);        // core::gain<NV>
		
		// Modulation Connections ------------------------------------------------------------------
		
		minmax.getWrappedObject().getParameter().connectT(0, pitch_shift1);        // minmax -> pitch_shift1::FreqRatio
		clone_cable1.getWrappedObject().getParameter().connectT(0, minmax);        // clone_cable1 -> minmax::Value
		minmax23.getWrappedObject().getParameter().connectT(0, pitch_shift39);     // minmax23 -> pitch_shift39::FreqRatio
		clone_cable2.getWrappedObject().getParameter().connectT(0, minmax23);      // clone_cable2 -> minmax23::Value
		cable_table.getWrappedObject().getParameter().connectT(0, pitch_shift);    // cable_table -> pitch_shift::FreqRatio
		midi.getParameter().connectT(0, cable_table);                              // midi -> cable_table::Value
		minmax44.getWrappedObject().getParameter().connectT(0, pitch_shift67);     // minmax44 -> pitch_shift67::FreqRatio
		clone_cable3.getWrappedObject().getParameter().connectT(0, minmax44);      // clone_cable3 -> minmax44::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, pitch_shift60); // cable_table1 -> pitch_shift60::FreqRatio
		midi1.getParameter().connectT(0, cable_table1);                            // midi1 -> cable_table1::Value
		
		// Default Values --------------------------------------------------------------------------
		
		branch.setParameterT(0, 3.); // container::branch::Index
		
		;                                  // clone_cable1::NumClones is deactivated
		clone_cable1.setParameterT(1, 1.); // control::clone_cable::Value
		clone_cable1.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone.setParameterT(0, 8.); // container::clone::NumClones
		clone.setParameterT(1, 2.); // container::clone::SplitSignal
		
		;                                  // minmax::Value is automated
		minmax.setParameterT(1, 0.947207); // control::minmax::Minimum
		minmax.setParameterT(2, 1.05184);  // control::minmax::Maximum
		minmax.setParameterT(3, 0.89679);  // control::minmax::Skew
		minmax.setParameterT(4, 0.);       // control::minmax::Step
		minmax.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // pitch_shift1::FreqRatio is automated
		
		gain.setParameterT(0, -7.1); // core::gain::Gain
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                                        // clone_cable2::NumClones is deactivated
		clone_cable2.setParameterT(1, 0.557163); // control::clone_cable::Value
		clone_cable2.setParameterT(2, 0.);       // control::clone_cable::Gamma
		
		clone1.setParameterT(0, 4.); // container::clone::NumClones
		clone1.setParameterT(1, 2.); // container::clone::SplitSignal
		
		;                               // minmax23::Value is automated
		minmax23.setParameterT(1, 1.);  // control::minmax::Minimum
		minmax23.setParameterT(2, 16.); // control::minmax::Maximum
		minmax23.setParameterT(3, 1.);  // control::minmax::Skew
		minmax23.setParameterT(4, 1.);  // control::minmax::Step
		minmax23.setParameterT(5, 0.);  // control::minmax::Polarity
		
		; // pitch_shift39::FreqRatio is automated
		
		gain29.setParameterT(0, -7.1); // core::gain::Gain
		gain29.setParameterT(1, 20.);  // core::gain::Smoothing
		gain29.setParameterT(2, 0.);   // core::gain::ResetValue
		
		; // cable_table::Value is automated
		
		; // pitch_shift::FreqRatio is automated
		
		;                                        // clone_cable3::NumClones is deactivated
		clone_cable3.setParameterT(1, 0.110053); // control::clone_cable::Value
		clone_cable3.setParameterT(2, 0.);       // control::clone_cable::Gamma
		
		clone2.setParameterT(0, 4.); // container::clone::NumClones
		clone2.setParameterT(1, 2.); // container::clone::SplitSignal
		
		;                               // minmax44::Value is automated
		minmax44.setParameterT(1, 1.);  // control::minmax::Minimum
		minmax44.setParameterT(2, 16.); // control::minmax::Maximum
		minmax44.setParameterT(3, 1.);  // control::minmax::Skew
		minmax44.setParameterT(4, 1.);  // control::minmax::Step
		minmax44.setParameterT(5, 0.);  // control::minmax::Polarity
		
		; // cable_table1::Value is automated
		
		; // pitch_shift60::FreqRatio is automated
		
		; // pitch_shift67::FreqRatio is automated
		
		gain50.setParameterT(0, -7.1); // core::gain::Gain
		gain50.setParameterT(1, 20.);  // core::gain::Smoothing
		gain50.setParameterT(2, 0.);   // core::gain::ResetValue
		
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(3).getT(1).setExternalData(b, index);         // pitch_impl::cable_table_t<NV>
		this->getT(0).getT(4).getT(1).getT(2).setExternalData(b, index); // pitch_impl::cable_table1_t<NV>
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using pitch = wrap::node<pitch_impl::instance<NV>>;
}


