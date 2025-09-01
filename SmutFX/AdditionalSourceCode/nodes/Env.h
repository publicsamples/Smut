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

namespace Env_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<0>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table1_t<NV>, 0>, 
                                  parameter::plain<cable_pack_t<NV>, 0>, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;
template <int NV>
using input_toggle_t = control::input_toggle<NV, 
                                             parameter::plain<ahdsr_t<NV>, 8>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<input_toggle_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>, 
                                   math::rect<NV>, 
                                   peak1_t<NV>, 
                                   math::clear<NV>, 
                                   input_toggle_t<NV>, 
                                   ahdsr_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_table1_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_pack_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain48_t<NV>>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>>;

template <int NV>
using peak_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                         wrap::no_data<core::peak>>;

DECLARE_PARAMETER_RANGE_SKEW(pma_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using pma_mod = parameter::from0To1<core::gain<NV>, 
                                    0, 
                                    pma_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using midi_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                         control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, midi_t<NV>>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<pma_t<NV>, 2>>, 
                                 data::embedded::table<cable_table_t_data>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, midichain_t<NV>>, 
                                 cable_table_t<NV>, 
                                 pma_t<NV>>;
using peak2_t = wrap::no_data<core::peak>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, tempo_sync1_t<NV>>, 
                                   ramp_t<NV>, 
                                   branch3_t<NV>, 
                                   peak_t<NV>, 
                                   math::clear<NV>, 
                                   math::add<NV>, 
                                   core::gain<NV>, 
                                   chain_t<NV>, 
                                   peak2_t>;

namespace Env_t_parameters
{
// Parameter list for Env_impl::Env_t --------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Mode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Mode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using Mode_0 = parameter::from0To1<Env_impl::branch3_t<NV>, 
                                   0, 
                                   Mode_0Range>;

template <int NV>
using Mode = parameter::chain<Mode_InputRange, Mode_0<NV>>;

template <int NV>
using Velocity = parameter::chain<ranges::Identity, 
                                  parameter::plain<Env_impl::cable_table_t<NV>, 0>, 
                                  parameter::plain<Env_impl::pma_t<NV>, 1>>;

template <int NV>
using Tempo = parameter::plain<Env_impl::tempo_sync1_t<NV>, 
                               0>;
template <int NV>
using Divide = parameter::plain<Env_impl::tempo_sync1_t<NV>, 
                                1>;
template <int NV>
using EnvTrig = parameter::plain<Env_impl::input_toggle_t<NV>, 
                                 0>;
template <int NV>
using a = parameter::plain<Env_impl::ahdsr_t<NV>, 0>;
template <int NV>
using h = parameter::plain<Env_impl::ahdsr_t<NV>, 2>;
template <int NV>
using d = parameter::plain<Env_impl::ahdsr_t<NV>, 3>;
template <int NV>
using s = parameter::plain<Env_impl::ahdsr_t<NV>, 4>;
template <int NV>
using r = parameter::plain<Env_impl::ahdsr_t<NV>, 5>;
template <int NV>
using Oneshot = parameter::plain<Env_impl::ramp_t<NV>, 1>;
template <int NV>
using Env_t_plist = parameter::list<Tempo<NV>, 
                                    Divide<NV>, 
                                    Mode<NV>, 
                                    EnvTrig<NV>, 
                                    a<NV>, 
                                    h<NV>, 
                                    d<NV>, 
                                    s<NV>, 
                                    r<NV>, 
                                    Oneshot<NV>, 
                                    Velocity<NV>>;
}

template <int NV>
using Env_t_ = container::chain<Env_t_parameters::Env_t_plist<NV>, 
                                wrap::fix<1, chain47_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Env_impl::Env_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 1;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Env);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(170)
		{
			0x005C, 0x0000, 0x0000, 0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x4190, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0001, 0x0000, 0x6944, 0x6976, 0x6564, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0200, 0x0000, 0x4D00, 0x646F, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x4040, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0003, 0x0000, 0x6E45, 0x5476, 0x6972, 0x0067, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0004, 0x0000, 0x0061, 0x0000, 0x0000, 0x4000, 
            0x461C, 0x7CCD, 0x449E, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 
            0x0005, 0x0000, 0x0068, 0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 
            0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 0x0006, 0x0000, 
            0x0064, 0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 0x0000, 0x6A72, 
            0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 0x0007, 0x0000, 0x0073, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x4D23, 0x3F1C, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0008, 0x0000, 0x0072, 0x0000, 0x0000, 0x4000, 
            0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 
            0x0009, 0x0000, 0x6E4F, 0x7365, 0x6F68, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x000A, 0x0000, 0x6556, 0x6F6C, 0x6963, 0x7974, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
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
		
		auto& chain47 = this->getT(0);                              // Env_impl::chain47_t<NV>
		auto& tempo_sync1 = this->getT(0).getT(0);                  // Env_impl::tempo_sync1_t<NV>
		auto& ramp = this->getT(0).getT(1);                         // Env_impl::ramp_t<NV>
		auto& branch3 = this->getT(0).getT(2);                      // Env_impl::branch3_t<NV>
		auto& chain48 = this->getT(0).getT(2).getT(0);              // Env_impl::chain48_t<NV>
		auto& add7 = this->getT(0).getT(2).getT(0).getT(0);         // math::add<NV>
		auto& rect6 = this->getT(0).getT(2).getT(0).getT(1);        // math::rect<NV>
		auto& peak1 = this->getT(0).getT(2).getT(0).getT(2);        // Env_impl::peak1_t<NV>
		auto& clear = this->getT(0).getT(2).getT(0).getT(3);        // math::clear<NV>
		auto& input_toggle = this->getT(0).getT(2).getT(0).getT(4); // Env_impl::input_toggle_t<NV>
		auto& ahdsr = this->getT(0).getT(2).getT(0).getT(5);        // Env_impl::ahdsr_t<NV>
		auto& add8 = this->getT(0).getT(2).getT(0).getT(6);         // math::add<NV>
		auto& chain52 = this->getT(0).getT(2).getT(1);              // Env_impl::chain52_t<NV>
		auto& clear2 = this->getT(0).getT(2).getT(1).getT(0);       // math::clear<NV>
		auto& cable_table1 = this->getT(0).getT(2).getT(1).getT(1); // Env_impl::cable_table1_t<NV>
		auto& add9 = this->getT(0).getT(2).getT(1).getT(2);         // math::add<NV>
		auto& chain53 = this->getT(0).getT(2).getT(2);              // Env_impl::chain53_t<NV>
		auto& clear1 = this->getT(0).getT(2).getT(2).getT(0);       // math::clear<NV>
		auto& cable_pack = this->getT(0).getT(2).getT(2).getT(1);   // Env_impl::cable_pack_t<NV>
		auto& add10 = this->getT(0).getT(2).getT(2).getT(2);        // math::add<NV>
		auto& peak = this->getT(0).getT(3);                         // Env_impl::peak_t<NV>
		auto& clear3 = this->getT(0).getT(4);                       // math::clear<NV>
		auto& add1 = this->getT(0).getT(5);                         // math::add<NV>
		auto& gain = this->getT(0).getT(6);                         // core::gain<NV>
		auto& chain = this->getT(0).getT(7);                        // Env_impl::chain_t<NV>
		auto& midichain = this->getT(0).getT(7).getT(0);            // Env_impl::midichain_t<NV>
		auto& midi = this->getT(0).getT(7).getT(0).getT(0);         // Env_impl::midi_t<NV>
		auto& cable_table = this->getT(0).getT(7).getT(1);          // Env_impl::cable_table_t<NV>
		auto& pma = this->getT(0).getT(7).getT(2);                  // Env_impl::pma_t<NV>
		auto& peak2 = this->getT(0).getT(8);                        // Env_impl::peak2_t
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync1); // Tempo -> tempo_sync1::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync1); // Divide -> tempo_sync1::Multiplier
		
		this->getParameterT(2).connectT(0, branch3); // Mode -> branch3::Index
		
		this->getParameterT(3).connectT(0, input_toggle); // EnvTrig -> input_toggle::Input
		
		this->getParameterT(4).connectT(0, ahdsr); // a -> ahdsr::Attack
		
		this->getParameterT(5).connectT(0, ahdsr); // h -> ahdsr::Hold
		
		this->getParameterT(6).connectT(0, ahdsr); // d -> ahdsr::Decay
		
		this->getParameterT(7).connectT(0, ahdsr); // s -> ahdsr::Sustain
		
		this->getParameterT(8).connectT(0, ahdsr); // r -> ahdsr::Release
		
		this->getParameterT(9).connectT(0, ramp); // Oneshot -> ramp::LoopStart
		
		auto& Velocity_p = this->getParameterT(10);
		Velocity_p.connectT(0, cable_table); // Velocity -> cable_table::Value
		Velocity_p.connectT(1, pma);         // Velocity -> pma::Multiply
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_table1.getWrappedObject().getParameter().connectT(0, add9); // cable_table1 -> add9::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add10);  // cable_pack -> add10::Value
		ramp.getParameter().connectT(0, cable_table1);                    // ramp -> cable_table1::Value
		ramp.getParameter().connectT(1, cable_pack);                      // ramp -> cable_pack::Value
		ramp.getParameter().connectT(2, add7);                            // ramp -> add7::Value
		tempo_sync1.getParameter().connectT(0, ramp);                     // tempo_sync1 -> ramp::PeriodTime
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add8);                        // ahdsr -> add8::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ahdsr); // input_toggle -> ahdsr::Gate
		peak1.getParameter().connectT(0, input_toggle);                    // peak1 -> input_toggle::Value2
		peak.getParameter().connectT(0, add1);                             // peak -> add1::Value
		pma.getWrappedObject().getParameter().connectT(0, gain);           // pma -> gain::Gain
		midi.getParameter().connectT(0, pma);                              // midi -> pma::Value
		cable_table.getWrappedObject().getParameter().connectT(0, pma);    // cable_table -> pma::Add
		
		// Default Values --------------------------------------------------------------------------
		
		;                                   // tempo_sync1::Tempo is automated
		;                                   // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch3::Index is automated
		
		; // add7::Value is automated
		
		rect6.setParameterT(0, 0.); // math::rect::Value
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 0.); // control::input_toggle::Value1
		;                                  // input_toggle::Value2 is automated
		
		;                                 // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);       // envelope::ahdsr::AttackLevel
		;                                 // ahdsr::Hold is automated
		;                                 // ahdsr::Decay is automated
		;                                 // ahdsr::Sustain is automated
		;                                 // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.450656); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);       // envelope::ahdsr::Retrigger
		;                                 // ahdsr::Gate is automated
		
		; // add8::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table1::Value is automated
		
		; // add9::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack::Value is automated
		
		; // add10::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // add1::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_table::Value is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 2.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1267.9);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.610552);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 1.);
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
		
		this->getT(0).getT(1).setExternalData(b, index);                 // Env_impl::ramp_t<NV>
		this->getT(0).getT(2).getT(0).getT(2).setExternalData(b, index); // Env_impl::peak1_t<NV>
		this->getT(0).getT(2).getT(0).getT(5).setExternalData(b, index); // Env_impl::ahdsr_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).setExternalData(b, index); // Env_impl::cable_table1_t<NV>
		this->getT(0).getT(2).getT(2).getT(1).setExternalData(b, index); // Env_impl::cable_pack_t<NV>
		this->getT(0).getT(3).setExternalData(b, index);                 // Env_impl::peak_t<NV>
		this->getT(0).getT(7).getT(1).setExternalData(b, index);         // Env_impl::cable_table_t<NV>
		this->getT(0).getT(8).setExternalData(b, index);                 // Env_impl::peak2_t
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
using Env = wrap::node<Env_impl::instance<NV>>;
}


