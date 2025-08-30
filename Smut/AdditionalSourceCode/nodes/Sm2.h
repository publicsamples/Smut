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

namespace Sm2_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;

template <int NV> using chain57_t = chain58_t<NV>;

template <int NV> using chain67_t = chain58_t<NV>;

template <int NV> using chain38_t = chain58_t<NV>;

template <int NV> using chain69_t = chain58_t<NV>;

template <int NV> using chain72_t = chain58_t<NV>;
template <int NV>
using branch9_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain58_t<NV>>, 
                                    chain57_t<NV>, 
                                    chain67_t<NV>, 
                                    chain38_t<NV>, 
                                    chain69_t<NV>, 
                                    chain72_t<NV>>;

template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<math::add<NV>, 0>>;
DECLARE_PARAMETER_RANGE(peak5_modRange, 
                        -12., 
                        12.);

template <int NV>
using peak5_mod = parameter::from0To1<pma_t<NV>, 
                                      0, 
                                      peak5_modRange>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain182_t = chain58_t<NV>;

template <int NV>
using chain258_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_t<NV>>, 
                                    math::add<NV>>;
using global_mod1_t_index = runtime_target::indexers::fix_hash<1>;
using global_mod1_t_config = modulation::config::dynamic;

template <int NV> using minmax3_t = minmax_t<NV>;
template <int NV>
using global_mod1_t = wrap::mod<parameter::plain<minmax3_t<NV>, 0>, 
                                wrap::no_data<core::global_mod<NV, global_mod1_t_index, global_mod1_t_config>>>;

template <int NV>
using chain119_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod1_t<NV>>, 
                                    minmax3_t<NV>, 
                                    math::add<NV>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, chain119_t<NV>>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain59_t<NV>>, 
                                  chain182_t<NV>, 
                                  chain258_t<NV>, 
                                  chain60_t<NV>>;
using peak16_t = wrap::no_data<wrap::no_process<core::peak>>;

template <int NV>
using converter2_t = control::converter<parameter::plain<core::phasor_fm<NV>, 2>, 
                                        conversion_logic::st2pitch>;
template <int NV>
using peak_unscaled_t = wrap::mod<parameter::plain<converter2_t<NV>, 0>, 
                                  wrap::no_data<core::peak_unscaled>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split6_t<NV>>, 
                                   math::sub<NV>, 
                                   peak16_t, 
                                   math::mod2sig<NV>, 
                                   peak_unscaled_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain62_t<NV>>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch9_t<NV>>, 
                                   peak5_t<NV>, 
                                   math::clear<NV>, 
                                   split7_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain37_t<NV>>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV> using chain79_t = chain58_t<NV>;

template <int NV> using chain80_t = chain58_t<NV>;

template <int NV> using chain81_t = chain58_t<NV>;

template <int NV> using chain78_t = chain58_t<NV>;

template <int NV> using chain86_t = chain58_t<NV>;

template <int NV> using chain87_t = chain58_t<NV>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain79_t<NV>>, 
                                     chain80_t<NV>, 
                                     chain81_t<NV>, 
                                     chain78_t<NV>, 
                                     chain86_t<NV>, 
                                     chain87_t<NV>>;

template <int NV> using pma1_t = pma_t<NV>;
template <int NV>
using peak13_mod = parameter::from0To1<pma1_t<NV>, 
                                       0, 
                                       peak5_modRange>;

template <int NV>
using peak13_t = wrap::mod<peak13_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV> using minmax2_t = minmax_t<NV>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax2_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain181_t = chain58_t<NV>;

template <int NV>
using chain260_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma1_t<NV>>, 
                                    math::add<NV>>;
using global_mod_t_index = global_mod1_t_index;
using global_mod_t_config = global_mod1_t_config;
template <int NV>
using global_mod_t = wrap::no_data<core::global_mod<NV, global_mod_t_index, global_mod_t_config>>;

template <int NV> using minmax1_t = minmax_t<NV>;

template <int NV>
using chain120_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod_t<NV>>, 
                                    minmax1_t<NV>, 
                                    math::add<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain83_t<NV>>, 
                                   chain181_t<NV>, 
                                   chain260_t<NV>, 
                                   chain120_t<NV>>;

template <int NV> using converter3_t = converter2_t<NV>;
template <int NV>
using peak_unscaled2_t = wrap::mod<parameter::plain<converter3_t<NV>, 0>, 
                                   wrap::no_data<core::peak_unscaled>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split11_t<NV>>, 
                                   math::sub<NV>, 
                                   math::mod2sig<NV>, 
                                   peak_unscaled2_t<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain82_t<NV>>>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch12_t<NV>>, 
                                   peak13_t<NV>, 
                                   math::clear<NV>, 
                                   split10_t<NV>>;

template <int NV>
using modchain5_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain77_t<NV>>>;

template <int NV>
using modchain5_t = wrap::control_rate<modchain5_t_<NV>>;

template <int NV> using chain65_t = chain58_t<NV>;

template <int NV> using chain66_t = chain58_t<NV>;

template <int NV> using chain68_t = chain58_t<NV>;

template <int NV> using chain64_t = chain58_t<NV>;

template <int NV> using chain71_t = chain58_t<NV>;

template <int NV> using chain73_t = chain58_t<NV>;
template <int NV>
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain65_t<NV>>, 
                                     chain66_t<NV>, 
                                     chain68_t<NV>, 
                                     chain64_t<NV>, 
                                     chain71_t<NV>, 
                                     chain73_t<NV>>;

template <int NV>
using pma_unscaled3_t = control::pma_unscaled<NV, 
                                              parameter::plain<math::add<NV>, 0>>;
template <int NV>
using peak7_t = wrap::mod<parameter::plain<pma_unscaled3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain97_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma_unscaled3_t<NV>>, 
                                   math::add<NV>>;
using global_mod3_t_index = global_mod1_t_index;
using global_mod3_t_config = global_mod1_t_config;

template <int NV>
using global_mod3_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::global_mod<NV, global_mod3_t_index, global_mod3_t_config>>>;

template <int NV>
using chain121_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod3_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain97_t<NV>>, 
                                   chain121_t<NV>>;

template <int NV>
using converter_t = control::converter<parameter::plain<core::phasor_fm<NV>, 2>, 
                                       conversion_logic::ms2freq>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(peak35_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using peak35_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                       0, 
                                       peak35_modRange>;

template <int NV>
using peak35_t = wrap::mod<peak35_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split12_t<NV>>, 
                                   peak35_t<NV>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch10_t<NV>>, 
                                   peak7_t<NV>, 
                                   math::clear<NV>, 
                                   chain70_t<NV>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain63_t<NV>>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV> using chain76_t = chain58_t<NV>;

template <int NV> using chain85_t = chain58_t<NV>;

template <int NV> using chain88_t = chain58_t<NV>;

template <int NV> using chain75_t = chain58_t<NV>;

template <int NV> using chain93_t = chain58_t<NV>;

template <int NV> using chain96_t = chain58_t<NV>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain76_t<NV>>, 
                                     chain85_t<NV>, 
                                     chain88_t<NV>, 
                                     chain75_t<NV>, 
                                     chain93_t<NV>, 
                                     chain96_t<NV>>;

template <int NV> using pma_unscaled15_t = pma_unscaled3_t<NV>;
template <int NV>
using peak9_t = wrap::mod<parameter::plain<pma_unscaled15_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma_unscaled15_t<NV>>, 
                                   math::add<NV>>;
using global_mod13_t_index = global_mod1_t_index;
using global_mod13_t_config = global_mod1_t_config;

template <int NV>
using global_mod13_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                 wrap::no_data<core::global_mod<NV, global_mod13_t_index, global_mod13_t_config>>>;

template <int NV>
using chain247_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod13_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain99_t<NV>>, 
                                   chain247_t<NV>>;

template <int NV>
using chain98_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split16_t<NV>>>;

template <int NV> using converter1_t = converter_t<NV>;
template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<converter1_t<NV>, 0>, 
                                control::tempo_sync<NV>>;
template <int NV>
using peak36_mod = parameter::from0To1<tempo_sync2_t<NV>, 
                                       0, 
                                       peak35_modRange>;

template <int NV>
using peak36_t = wrap::mod<peak36_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch11_t<NV>>, 
                                   peak9_t<NV>, 
                                   math::clear<NV>, 
                                   chain98_t<NV>, 
                                   peak36_t<NV>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain74_t<NV>>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV> using chain104_t = chain58_t<NV>;

template <int NV> using chain105_t = chain58_t<NV>;

template <int NV> using chain110_t = chain58_t<NV>;

template <int NV> using chain103_t = chain58_t<NV>;

template <int NV> using chain194_t = chain58_t<NV>;

template <int NV> using chain197_t = chain58_t<NV>;
template <int NV>
using branch16_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain104_t<NV>>, 
                                     chain105_t<NV>, 
                                     chain110_t<NV>, 
                                     chain103_t<NV>, 
                                     chain194_t<NV>, 
                                     chain197_t<NV>>;

template <int NV> using pma_unscaled6_t = pma_unscaled3_t<NV>;
template <int NV>
using peak17_t = wrap::mod<parameter::plain<pma_unscaled6_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain183_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled6_t<NV>>, 
                                    math::add<NV>>;
using global_mod4_t_index = global_mod1_t_index;
using global_mod4_t_config = global_mod1_t_config;

template <int NV>
using global_mod4_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::global_mod<NV, global_mod4_t_index, global_mod4_t_config>>>;

template <int NV>
using chain122_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod4_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain122_t<NV>>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain183_t<NV>>, 
                                  chain106_t<NV>>;

namespace custom
{

struct expr4
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 256.0 * value * input) * (1 - Math.PI);
		;
	}
};
}

DECLARE_PARAMETER_RANGE(smoothed_parameter1_modRange, 
                        0.00085, 
                        0.04809);

template <int NV>
using smoothed_parameter1_mod = parameter::from0To1<math::expr<NV, custom::expr4>, 
                                                    0, 
                                                    smoothed_parameter1_modRange>;

template <int NV>
using smoothed_parameter1_t = wrap::mod<smoothed_parameter1_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 8.0 * value * input) * (2 - Math.PI);
		;
	}
};
}

template <int NV>
using smoothed_parameter4_t = wrap::mod<parameter::plain<math::expr<NV, custom::expr3>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
DECLARE_PARAMETER_RANGE_STEP(peak6_mod_0Range, 
                             0., 
                             24., 
                             0.1);

template <int NV>
using peak6_mod_0 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        peak6_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(peak6_mod_3Range, 
                             0., 
                             36., 
                             0.1);

template <int NV>
using peak6_mod_3 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        peak6_mod_3Range>;

template <int NV> using peak6_mod_4 = peak6_mod_3<NV>;

DECLARE_PARAMETER_RANGE_STEP(peak6_mod_5Range, 
                             0., 
                             46., 
                             0.1);

template <int NV>
using peak6_mod_5 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        peak6_mod_5Range>;

template <int NV> using peak6_mod_6 = peak6_mod_0<NV>;

DECLARE_PARAMETER_RANGE_STEP(peak6_mod_7Range, 
                             0., 
                             64., 
                             0.1);

template <int NV>
using peak6_mod_7 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        peak6_mod_7Range>;

template <int NV> using peak6_mod_8 = peak6_mod_0<NV>;

template <int NV> using peak6_mod_9 = peak6_mod_7<NV>;

template <int NV> using peak6_mod_10 = peak6_mod_0<NV>;

template <int NV> using peak6_mod_11 = peak6_mod_0<NV>;

template <int NV>
using peak6_mod = parameter::chain<ranges::Identity, 
                                   peak6_mod_0<NV>, 
                                   parameter::plain<smoothed_parameter1_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter4_t<NV>, 0>, 
                                   peak6_mod_3<NV>, 
                                   peak6_mod_4<NV>, 
                                   peak6_mod_5<NV>, 
                                   peak6_mod_6<NV>, 
                                   peak6_mod_7<NV>, 
                                   peak6_mod_8<NV>, 
                                   peak6_mod_9<NV>, 
                                   peak6_mod_10<NV>, 
                                   peak6_mod_11<NV>>;

template <int NV>
using peak6_t = wrap::mod<peak6_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch16_t<NV>>, 
                                    peak17_t<NV>, 
                                    math::clear<NV>, 
                                    split4_t<NV>, 
                                    peak6_t<NV>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain102_t<NV>>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

template <int NV> using chain133_t = chain58_t<NV>;

template <int NV> using chain139_t = chain58_t<NV>;

template <int NV> using chain140_t = chain58_t<NV>;

template <int NV> using chain108_t = chain58_t<NV>;

template <int NV> using chain223_t = chain58_t<NV>;

template <int NV> using chain224_t = chain58_t<NV>;
template <int NV>
using branch18_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain133_t<NV>>, 
                                     chain139_t<NV>, 
                                     chain140_t<NV>, 
                                     chain108_t<NV>, 
                                     chain223_t<NV>, 
                                     chain224_t<NV>>;

template <int NV> using pma_unscaled13_t = pma_unscaled3_t<NV>;
template <int NV>
using peak30_t = wrap::mod<parameter::plain<pma_unscaled13_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain225_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled13_t<NV>>, 
                                    math::add<NV>>;
using global_mod7_t_index = global_mod1_t_index;
using global_mod7_t_config = global_mod1_t_config;

template <int NV>
using global_mod7_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::global_mod<NV, global_mod7_t_index, global_mod7_t_config>>>;

template <int NV>
using chain146_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod7_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain145_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain146_t<NV>>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain225_t<NV>>, 
                                   chain145_t<NV>>;

namespace custom
{

struct expr7
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 8.0 * value * input) * (2 - Math.PI);
		;
	}
};
}

template <int NV>
using smoothed_parameter5_t = wrap::mod<parameter::plain<math::expr<NV, custom::expr7>, 0>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

namespace custom
{

struct expr10
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 256.0 * value * input) * (1 - Math.PI);
		;
	}
};
}

template <int NV>
using smoothed_parameter2_mod = parameter::from0To1<math::expr<NV, custom::expr10>, 
                                                    0, 
                                                    smoothed_parameter1_modRange>;

template <int NV>
using smoothed_parameter2_t = wrap::mod<smoothed_parameter2_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV> using peak8_mod_0 = peak6_mod_0<NV>;

template <int NV> using peak8_mod_1 = peak6_mod_0<NV>;

template <int NV> using peak8_mod_4 = peak6_mod_3<NV>;

template <int NV> using peak8_mod_5 = peak6_mod_3<NV>;

template <int NV> using peak8_mod_6 = peak6_mod_5<NV>;

template <int NV> using peak8_mod_7 = peak6_mod_0<NV>;

template <int NV> using peak8_mod_8 = peak6_mod_7<NV>;

template <int NV> using peak8_mod_9 = peak6_mod_0<NV>;

template <int NV> using peak8_mod_10 = peak6_mod_7<NV>;

template <int NV> using peak8_mod_11 = peak6_mod_0<NV>;

template <int NV>
using peak8_mod = parameter::chain<ranges::Identity, 
                                   peak8_mod_0<NV>, 
                                   peak8_mod_1<NV>, 
                                   parameter::plain<smoothed_parameter5_t<NV>, 0>, 
                                   parameter::plain<smoothed_parameter2_t<NV>, 0>, 
                                   peak8_mod_4<NV>, 
                                   peak8_mod_5<NV>, 
                                   peak8_mod_6<NV>, 
                                   peak8_mod_7<NV>, 
                                   peak8_mod_8<NV>, 
                                   peak8_mod_9<NV>, 
                                   peak8_mod_10<NV>, 
                                   peak8_mod_11<NV>>;

template <int NV>
using peak8_t = wrap::mod<peak8_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain107_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch18_t<NV>>, 
                                    peak30_t<NV>, 
                                    math::clear<NV>, 
                                    split14_t<NV>, 
                                    peak8_t<NV>>;

template <int NV>
using modchain12_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, chain107_t<NV>>>;

template <int NV>
using modchain12_t = wrap::control_rate<modchain12_t_<NV>>;

template <int NV> using chain239_t = chain58_t<NV>;

template <int NV> using chain240_t = chain58_t<NV>;

template <int NV> using chain241_t = chain58_t<NV>;

template <int NV> using chain227_t = chain58_t<NV>;

template <int NV> using chain242_t = chain58_t<NV>;

template <int NV> using chain243_t = chain58_t<NV>;
template <int NV>
using branch29_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain239_t<NV>>, 
                                     chain240_t<NV>, 
                                     chain241_t<NV>, 
                                     chain227_t<NV>, 
                                     chain242_t<NV>, 
                                     chain243_t<NV>>;
using peak21_t = wrap::no_data<core::peak>;

template <int NV> using pma_unscaled14_t = pma_unscaled3_t<NV>;

template <int NV>
using chain244_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled14_t<NV>>, 
                                    math::add<NV>>;
using global_mod8_t_index = global_mod1_t_index;
using global_mod8_t_config = global_mod1_t_config;

template <int NV>
using global_mod8_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::global_mod<NV, global_mod8_t_index, global_mod8_t_config>>>;

template <int NV>
using chain246_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod8_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain245_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain246_t<NV>>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain244_t<NV>>, 
                                   chain245_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(peak3_modRange, 
                             -100., 
                             24., 
                             5.42227);

template <int NV>
using peak3_mod = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      peak3_modRange>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain147_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch29_t<NV>>, 
                                    peak21_t, 
                                    math::clear<NV>, 
                                    split15_t<NV>, 
                                    peak3_t<NV>>;

template <int NV>
using modchain13_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, chain147_t<NV>>>;

template <int NV>
using modchain13_t = wrap::control_rate<modchain13_t_<NV>>;

template <int NV> using chain114_t = chain58_t<NV>;

template <int NV> using chain115_t = chain58_t<NV>;

template <int NV> using chain116_t = chain58_t<NV>;

template <int NV> using chain113_t = chain58_t<NV>;

template <int NV> using chain195_t = chain58_t<NV>;

template <int NV> using chain198_t = chain58_t<NV>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain114_t<NV>>, 
                                     chain115_t<NV>, 
                                     chain116_t<NV>, 
                                     chain113_t<NV>, 
                                     chain195_t<NV>, 
                                     chain198_t<NV>>;
using peak18_t = peak21_t;

template <int NV> using pma_unscaled7_t = pma_unscaled3_t<NV>;

template <int NV>
using chain184_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled7_t<NV>>, 
                                    math::add<NV>>;
using global_mod5_t_index = global_mod1_t_index;
using global_mod5_t_config = global_mod1_t_config;

template <int NV>
using global_mod5_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::global_mod<NV, global_mod5_t_index, global_mod5_t_config>>>;

template <int NV>
using chain124_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod5_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain184_t<NV>>, 
                                  chain124_t<NV>>;

template <int NV> using peak14_mod = peak3_mod<NV>;

template <int NV>
using peak14_t = wrap::mod<peak14_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain117_t = container::chain<parameter::empty, 
                                    wrap::fix<1, peak14_t<NV>>>;

template <int NV>
using chain112_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch17_t<NV>>, 
                                    peak18_t, 
                                    math::clear<NV>, 
                                    split5_t<NV>, 
                                    chain117_t<NV>>;

template <int NV>
using modchain9_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain112_t<NV>>>;

template <int NV>
using modchain9_t = wrap::control_rate<modchain9_t_<NV>>;

template <int NV> using chain129_t = chain58_t<NV>;

template <int NV> using chain130_t = chain58_t<NV>;

template <int NV> using chain148_t = chain58_t<NV>;

template <int NV> using chain128_t = chain58_t<NV>;

template <int NV> using chain196_t = chain58_t<NV>;

template <int NV> using chain199_t = chain58_t<NV>;
template <int NV>
using branch20_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain129_t<NV>>, 
                                     chain130_t<NV>, 
                                     chain148_t<NV>, 
                                     chain128_t<NV>, 
                                     chain196_t<NV>, 
                                     chain199_t<NV>>;
using peak20_t = peak21_t;

template <int NV> using pma_unscaled8_t = pma_unscaled3_t<NV>;

template <int NV>
using chain185_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled8_t<NV>>, 
                                    math::add<NV>>;
using global_mod6_t_index = global_mod1_t_index;
using global_mod6_t_config = global_mod1_t_config;

template <int NV>
using global_mod6_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::global_mod<NV, global_mod6_t_index, global_mod6_t_config>>>;

template <int NV>
using chain151_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod6_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain131_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain151_t<NV>>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain185_t<NV>>, 
                                  chain131_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(peak_modRange, 
                             -24., 
                             0., 
                             0.1);

template <int NV>
using peak_mod = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     peak_modRange>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain127_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch20_t<NV>>, 
                                    peak20_t, 
                                    math::clear<NV>, 
                                    split9_t<NV>, 
                                    peak_t<NV>>;

template <int NV>
using modchain6_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain127_t<NV>>>;

template <int NV>
using modchain6_t = wrap::control_rate<modchain6_t_<NV>>;

template <int NV> using chain272_t = chain58_t<NV>;

template <int NV> using chain273_t = chain58_t<NV>;

template <int NV> using chain274_t = chain58_t<NV>;

template <int NV> using chain275_t = chain58_t<NV>;

template <int NV> using chain276_t = chain58_t<NV>;

template <int NV> using chain277_t = chain58_t<NV>;
template <int NV>
using branch32_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain272_t<NV>>, 
                                     chain273_t<NV>, 
                                     chain274_t<NV>, 
                                     chain275_t<NV>, 
                                     chain276_t<NV>, 
                                     chain277_t<NV>>;
using peak38_t = peak21_t;

template <int NV> using pma_unscaled17_t = pma_unscaled3_t<NV>;

template <int NV>
using chain278_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled17_t<NV>>, 
                                    math::add<NV>>;
using global_mod15_t_index = global_mod1_t_index;
using global_mod15_t_config = global_mod1_t_config;

template <int NV>
using global_mod15_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                 wrap::no_data<core::global_mod<NV, global_mod15_t_index, global_mod15_t_config>>>;

template <int NV>
using chain280_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod15_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain279_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain280_t<NV>>>;

template <int NV>
using split38_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain278_t<NV>>, 
                                   chain279_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(peak39_modRange, 
                             -100., 
                             24., 
                             0.1);

template <int NV>
using peak39_mod = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       peak39_modRange>;

template <int NV>
using peak39_t = wrap::mod<peak39_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain271_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch32_t<NV>>, 
                                    peak38_t, 
                                    math::clear<NV>, 
                                    split38_t<NV>, 
                                    peak39_t<NV>>;

template <int NV>
using modchain16_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, chain271_t<NV>>>;

template <int NV>
using modchain16_t = wrap::control_rate<modchain16_t_<NV>>;

template <int NV> using chain136_t = chain58_t<NV>;

template <int NV> using chain137_t = chain58_t<NV>;

template <int NV> using chain149_t = chain58_t<NV>;

template <int NV> using chain135_t = chain58_t<NV>;

template <int NV> using chain193_t = chain58_t<NV>;

template <int NV> using chain200_t = chain58_t<NV>;
template <int NV>
using branch21_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain136_t<NV>>, 
                                     chain137_t<NV>, 
                                     chain149_t<NV>, 
                                     chain135_t<NV>, 
                                     chain193_t<NV>, 
                                     chain200_t<NV>>;

template <int NV> using pma_unscaled9_t = pma_unscaled3_t<NV>;
template <int NV>
using peak22_t = wrap::mod<parameter::plain<pma_unscaled9_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain186_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled9_t<NV>>, 
                                    math::add<NV>>;
using global_mod9_t_index = global_mod1_t_index;
using global_mod9_t_config = global_mod1_t_config;

template <int NV>
using global_mod9_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::global_mod<NV, global_mod9_t_index, global_mod9_t_config>>>;

template <int NV>
using chain188_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod9_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain187_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain188_t<NV>>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain186_t<NV>>, 
                                   chain187_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(peak23_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using peak23_mod_0 = parameter::from0To1<filters::one_pole<NV>, 
                                         0, 
                                         peak23_mod_0Range>;

template <int NV> using peak23_mod_1 = peak23_mod_0<NV>;

template <int NV>
using peak23_mod_2 = parameter::from0To1<filters::svf<NV>, 
                                         0, 
                                         peak23_mod_0Range>;

template <int NV> using peak23_mod_3 = peak23_mod_2<NV>;

template <int NV> using peak23_mod_4 = peak23_mod_2<NV>;

template <int NV> using peak23_mod_5 = peak23_mod_2<NV>;

template <int NV>
using peak23_mod_6 = parameter::from0To1<filters::allpass<NV>, 
                                         0, 
                                         peak23_mod_0Range>;

template <int NV> using peak23_mod_7 = peak23_mod_0<NV>;

template <int NV> using peak23_mod_8 = peak23_mod_0<NV>;

template <int NV>
using peak23_mod = parameter::chain<ranges::Identity, 
                                    peak23_mod_0<NV>, 
                                    peak23_mod_1<NV>, 
                                    peak23_mod_2<NV>, 
                                    peak23_mod_3<NV>, 
                                    peak23_mod_4<NV>, 
                                    peak23_mod_5<NV>, 
                                    peak23_mod_6<NV>, 
                                    peak23_mod_7<NV>, 
                                    peak23_mod_8<NV>>;

template <int NV>
using peak23_t = wrap::mod<peak23_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain138_t = container::chain<parameter::empty, 
                                    wrap::fix<1, split13_t<NV>>, 
                                    peak23_t<NV>>;

template <int NV>
using chain134_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch21_t<NV>>, 
                                    peak22_t<NV>, 
                                    math::clear<NV>, 
                                    chain138_t<NV>>;

template <int NV>
using modchain7_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain134_t<NV>>>;

template <int NV>
using modchain7_t = wrap::control_rate<modchain7_t_<NV>>;

template <int NV> using chain204_t = chain58_t<NV>;

template <int NV> using chain205_t = chain58_t<NV>;

template <int NV> using chain206_t = chain58_t<NV>;

template <int NV> using chain203_t = chain58_t<NV>;

template <int NV> using chain207_t = chain58_t<NV>;

template <int NV> using chain208_t = chain58_t<NV>;
template <int NV>
using branch23_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain204_t<NV>>, 
                                     chain205_t<NV>, 
                                     chain206_t<NV>, 
                                     chain203_t<NV>, 
                                     chain207_t<NV>, 
                                     chain208_t<NV>>;

template <int NV> using pma_unscaled11_t = pma_unscaled3_t<NV>;
template <int NV>
using peak26_t = wrap::mod<parameter::plain<pma_unscaled11_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain210_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled11_t<NV>>, 
                                    math::add<NV>>;
using global_mod11_t_index = global_mod1_t_index;
using global_mod11_t_config = global_mod1_t_config;

template <int NV>
using global_mod11_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                 wrap::no_data<core::global_mod<NV, global_mod11_t_index, global_mod11_t_config>>>;

template <int NV>
using chain212_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod11_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain211_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain212_t<NV>>>;

template <int NV>
using split33_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain210_t<NV>>, 
                                   chain211_t<NV>>;

template <int NV> using peak27_mod_0 = peak23_mod_6<NV>;

template <int NV> using peak27_mod_1 = peak23_mod_2<NV>;

template <int NV> using peak27_mod_2 = peak23_mod_2<NV>;

template <int NV> using peak27_mod_3 = peak23_mod_2<NV>;

template <int NV> using peak27_mod_4 = peak23_mod_2<NV>;

template <int NV> using peak27_mod_5 = peak23_mod_0<NV>;

template <int NV> using peak27_mod_6 = peak23_mod_0<NV>;

template <int NV> using peak27_mod_8 = peak23_mod_0<NV>;

template <int NV> using peak27_mod_9 = peak23_mod_0<NV>;

template <int NV>
using peak27_mod = parameter::chain<ranges::Identity, 
                                    peak27_mod_0<NV>, 
                                    peak27_mod_1<NV>, 
                                    peak27_mod_2<NV>, 
                                    peak27_mod_3<NV>, 
                                    peak27_mod_4<NV>, 
                                    peak27_mod_5<NV>, 
                                    peak27_mod_6<NV>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    peak27_mod_8<NV>, 
                                    peak27_mod_9<NV>>;

template <int NV>
using peak27_t = wrap::mod<peak27_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain209_t = container::chain<parameter::empty, 
                                    wrap::fix<1, split33_t<NV>>, 
                                    peak27_t<NV>, 
                                    math::add<NV>>;

template <int NV>
using chain202_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch23_t<NV>>, 
                                    peak26_t<NV>, 
                                    math::clear<NV>, 
                                    chain209_t<NV>>;

template <int NV>
using modchain10_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, chain202_t<NV>>>;

template <int NV>
using modchain10_t = wrap::control_rate<modchain10_t_<NV>>;

template <int NV> using chain143_t = chain58_t<NV>;

template <int NV> using chain144_t = chain58_t<NV>;

template <int NV> using chain150_t = chain58_t<NV>;

template <int NV> using chain142_t = chain58_t<NV>;

template <int NV> using chain192_t = chain58_t<NV>;

template <int NV> using chain201_t = chain58_t<NV>;
template <int NV>
using branch22_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain143_t<NV>>, 
                                     chain144_t<NV>, 
                                     chain150_t<NV>, 
                                     chain142_t<NV>, 
                                     chain192_t<NV>, 
                                     chain201_t<NV>>;

template <int NV> using pma_unscaled10_t = pma_unscaled3_t<NV>;
template <int NV>
using peak24_t = wrap::mod<parameter::plain<pma_unscaled10_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain189_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled10_t<NV>>, 
                                    math::add<NV>>;
using global_mod10_t_index = global_mod1_t_index;
using global_mod10_t_config = global_mod1_t_config;

template <int NV>
using global_mod10_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                 wrap::no_data<core::global_mod<NV, global_mod10_t_index, global_mod10_t_config>>>;

template <int NV>
using chain191_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod10_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain190_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain191_t<NV>>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain189_t<NV>>, 
                                   chain190_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(peak25_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using peak25_mod = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       peak25_modRange>;

template <int NV>
using peak25_t = wrap::mod<peak25_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain141_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch22_t<NV>>, 
                                    peak24_t<NV>, 
                                    math::clear<NV>, 
                                    split19_t<NV>, 
                                    peak25_t<NV>>;

template <int NV>
using modchain8_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, chain141_t<NV>>>;

template <int NV>
using modchain8_t = wrap::control_rate<modchain8_t_<NV>>;

template <int NV> using chain215_t = chain58_t<NV>;

template <int NV> using chain216_t = chain58_t<NV>;

template <int NV> using chain217_t = chain58_t<NV>;

template <int NV> using chain214_t = chain58_t<NV>;

template <int NV> using chain218_t = chain58_t<NV>;

template <int NV> using chain219_t = chain58_t<NV>;
template <int NV>
using branch25_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain215_t<NV>>, 
                                     chain216_t<NV>, 
                                     chain217_t<NV>, 
                                     chain214_t<NV>, 
                                     chain218_t<NV>, 
                                     chain219_t<NV>>;

template <int NV> using pma_unscaled12_t = pma_unscaled3_t<NV>;
template <int NV>
using peak28_t = wrap::mod<parameter::plain<pma_unscaled12_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain220_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma_unscaled12_t<NV>>, 
                                    math::add<NV>>;
using global_mod12_t_index = global_mod1_t_index;
using global_mod12_t_config = global_mod1_t_config;

template <int NV>
using global_mod12_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                 wrap::no_data<core::global_mod<NV, global_mod12_t_index, global_mod12_t_config>>>;

template <int NV>
using chain222_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_mod12_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain221_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain222_t<NV>>>;

template <int NV>
using split34_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain220_t<NV>>, 
                                   chain221_t<NV>>;

template <int NV> using peak29_mod = peak25_mod<NV>;

template <int NV>
using peak29_t = wrap::mod<peak29_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain213_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch25_t<NV>>, 
                                    peak28_t<NV>, 
                                    math::clear<NV>, 
                                    split34_t<NV>, 
                                    peak29_t<NV>>;

template <int NV>
using modchain11_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, chain213_t<NV>>>;

template <int NV>
using modchain11_t = wrap::control_rate<modchain11_t_<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  modchain5_t<NV>, 
                                  modchain2_t<NV>, 
                                  modchain3_t<NV>, 
                                  modchain4_t<NV>, 
                                  modchain12_t<NV>, 
                                  modchain13_t<NV>, 
                                  modchain9_t<NV>, 
                                  modchain6_t<NV>, 
                                  modchain16_t<NV>, 
                                  modchain7_t<NV>, 
                                  modchain10_t<NV>, 
                                  modchain8_t<NV>, 
                                  modchain11_t<NV>>;
template <int NV>
using stereo_cable = cable::block<NV, 2>;

template <int NV>
using chain235_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>>;

template <int NV> using chain236_t = chain235_t<NV>;

template <int NV> using chain267_t = chain235_t<NV>;

template <int NV> using chain237_t = chain235_t<NV>;

template <int NV> using chain238_t = chain235_t<NV>;
template <int NV>
using branch28_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain235_t<NV>>, 
                                     chain236_t<NV>, 
                                     chain267_t<NV>, 
                                     chain237_t<NV>, 
                                     chain238_t<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, converter2_t<NV>>, 
                                   core::phasor_fm<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync_t<NV>>, 
                                   converter_t<NV>, 
                                   core::phasor_fm<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain15_t<NV>>, 
                                    chain16_t<NV>>;
namespace custom
{

struct expr
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  math::pi<NV>, 
                                  math::expr<NV, custom::expr>>;
namespace custom
{

struct expr13
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

template <int NV>
using chain111_t = container::chain<parameter::empty, 
                                    wrap::fix<2, core::gain<NV>>, 
                                    math::fmod<NV>, 
                                    math::expr<NV, custom::expr13>>;
namespace custom
{

struct expr2
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter4_t<NV>>, 
                                   math::expr<NV, custom::expr3>, 
                                   math::expr<NV, custom::expr2>>;
namespace custom
{

struct expr6
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

namespace custom
{

struct expr5
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter1_t<NV>>, 
                                   math::expr<NV, custom::expr6>, 
                                   math::expr<NV, custom::expr4>, 
                                   math::expr<NV, custom::expr5>>;

struct table_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998386f, 0.996772f, 0.995157f, 0.993543f, 0.991929f,
		0.990315f, 0.9887f, 0.987086f, 0.985472f, 0.983858f, 0.982243f,
		0.980629f, 0.979015f, 0.977401f, 0.975786f, 0.974172f, 0.972558f,
		0.970944f, 0.969329f, 0.967715f, 0.966101f, 0.964487f, 0.962873f,
		0.961258f, 0.959644f, 0.95803f, 0.956416f, 0.954801f, 0.953187f,
		0.951573f, 0.949959f, 0.948344f, 0.94673f, 0.945116f, 0.943502f,
		0.941845f, 0.940189f, 0.938533f, 0.936876f, 0.93522f, 0.933563f,
		0.931907f, 0.93025f, 0.928594f, 0.926938f, 0.925281f, 0.923625f,
		0.921968f, 0.920312f, 0.918655f, 0.916999f, 0.915343f, 0.913686f,
		0.91203f, 0.910373f, 0.908717f, 0.90706f, 0.905404f, 0.903748f,
		0.902091f, 0.900435f, 0.898778f, 0.897122f, 0.895465f, 0.893809f,
		0.892153f, 0.890496f, 0.88884f, 0.887183f, 0.885509f, 0.88381f,
		0.88211f, 0.880411f, 0.878711f, 0.877011f, 0.875312f, 0.873612f,
		0.871913f, 0.870213f, 0.868513f, 0.866814f, 0.865114f, 0.863414f,
		0.861715f, 0.860015f, 0.858316f, 0.856616f, 0.854916f, 0.853217f,
		0.851517f, 0.849818f, 0.848118f, 0.846418f, 0.844719f, 0.843019f,
		0.841319f, 0.83962f, 0.83792f, 0.836221f, 0.834521f, 0.832821f,
		0.831122f, 0.829422f, 0.827713f, 0.825969f, 0.824225f, 0.822481f,
		0.820737f, 0.818994f, 0.81725f, 0.815506f, 0.813762f, 0.812018f,
		0.810274f, 0.80853f, 0.806787f, 0.805043f, 0.803299f, 0.801555f,
		0.799811f, 0.798067f, 0.796323f, 0.79458f, 0.792836f, 0.791092f,
		0.789348f, 0.787604f, 0.78586f, 0.784116f, 0.782372f, 0.780629f,
		0.778885f, 0.777141f, 0.775397f, 0.773653f, 0.771909f, 0.770166f,
		0.768402f, 0.766612f, 0.764823f, 0.763034f, 0.761245f, 0.759456f,
		0.757667f, 0.755877f, 0.754088f, 0.752299f, 0.75051f, 0.748721f,
		0.746931f, 0.745142f, 0.743353f, 0.741564f, 0.739775f, 0.737985f,
		0.736196f, 0.734407f, 0.732618f, 0.730829f, 0.72904f, 0.72725f,
		0.725461f, 0.723672f, 0.721883f, 0.720094f, 0.718305f, 0.716515f,
		0.714726f, 0.712937f, 0.711148f, 0.709355f, 0.70752f, 0.705684f,
		0.703848f, 0.702013f, 0.700177f, 0.698341f, 0.696506f, 0.69467f,
		0.692834f, 0.690999f, 0.689163f, 0.687328f, 0.685492f, 0.683656f,
		0.681821f, 0.679985f, 0.678149f, 0.676314f, 0.674478f, 0.672643f,
		0.670807f, 0.668971f, 0.667136f, 0.6653f, 0.663464f, 0.661629f,
		0.659793f, 0.657957f, 0.656122f, 0.654286f, 0.652451f, 0.650615f,
		0.648774f, 0.646891f, 0.645007f, 0.643124f, 0.641241f, 0.639358f,
		0.637474f, 0.635591f, 0.633708f, 0.631825f, 0.629941f, 0.628058f,
		0.626175f, 0.624292f, 0.622409f, 0.620525f, 0.618642f, 0.616759f,
		0.614875f, 0.612992f, 0.611109f, 0.609226f, 0.607343f, 0.605459f,
		0.603576f, 0.601693f, 0.59981f, 0.597926f, 0.596043f, 0.59416f,
		0.592277f, 0.590393f, 0.58851f, 0.586599f, 0.584667f, 0.582735f,
		0.580803f, 0.578871f, 0.576939f, 0.575007f, 0.573075f, 0.571143f,
		0.569211f, 0.567279f, 0.565347f, 0.563415f, 0.561482f, 0.55955f,
		0.557618f, 0.555686f, 0.553754f, 0.551822f, 0.54989f, 0.547958f,
		0.546026f, 0.544094f, 0.542162f, 0.54023f, 0.538298f, 0.536366f,
		0.534433f, 0.532501f, 0.530569f, 0.528637f, 0.526705f, 0.524752f,
		0.52277f, 0.520788f, 0.518806f, 0.516823f, 0.514841f, 0.512859f,
		0.510877f, 0.508895f, 0.506913f, 0.50493f, 0.502948f, 0.500966f,
		0.498984f, 0.497002f, 0.49502f, 0.493038f, 0.491055f, 0.489073f,
		0.487091f, 0.485109f, 0.483127f, 0.481145f, 0.479163f, 0.47718f,
		0.475198f, 0.473216f, 0.471234f, 0.469252f, 0.46727f, 0.465288f,
		0.463305f, 0.461288f, 0.459254f, 0.457221f, 0.455187f, 0.453154f,
		0.45112f, 0.449087f, 0.447053f, 0.445019f, 0.442986f, 0.440952f,
		0.438919f, 0.436885f, 0.434852f, 0.432818f, 0.430785f, 0.428751f,
		0.426718f, 0.424684f, 0.422651f, 0.420617f, 0.418584f, 0.41655f,
		0.414516f, 0.412483f, 0.410449f, 0.408416f, 0.406382f, 0.404349f,
		0.402315f, 0.400282f, 0.398229f, 0.396143f, 0.394056f, 0.39197f,
		0.389884f, 0.387798f, 0.385711f, 0.383625f, 0.381539f, 0.379452f,
		0.377366f, 0.37528f, 0.373194f, 0.371107f, 0.369021f, 0.366935f,
		0.364848f, 0.362762f, 0.360676f, 0.35859f, 0.356503f, 0.354417f,
		0.352331f, 0.350245f, 0.348158f, 0.346072f, 0.343986f, 0.341899f,
		0.339813f, 0.337727f, 0.335641f, 0.33353f, 0.331389f, 0.329249f,
		0.327109f, 0.324968f, 0.322828f, 0.320687f, 0.318547f, 0.316406f,
		0.314266f, 0.312125f, 0.309985f, 0.307845f, 0.305704f, 0.303564f,
		0.301423f, 0.299283f, 0.297142f, 0.295002f, 0.292861f, 0.290721f,
		0.28858f, 0.28644f, 0.2843f, 0.282159f, 0.280019f, 0.277878f,
		0.275738f, 0.273597f, 0.271457f, 0.269316f, 0.267124f, 0.264928f,
		0.262731f, 0.260535f, 0.258339f, 0.256143f, 0.253947f, 0.251751f,
		0.249555f, 0.247359f, 0.245163f, 0.242967f, 0.240771f, 0.238575f,
		0.236379f, 0.234182f, 0.231986f, 0.22979f, 0.227594f, 0.225398f,
		0.223202f, 0.221006f, 0.21881f, 0.216614f, 0.214418f, 0.212222f,
		0.210026f, 0.20783f, 0.205634f, 0.203437f, 0.201193f, 0.19894f,
		0.196687f, 0.194433f, 0.19218f, 0.189927f, 0.187674f, 0.18542f,
		0.183167f, 0.180914f, 0.178661f, 0.176408f, 0.174154f, 0.171901f,
		0.169648f, 0.167395f, 0.165141f, 0.162888f, 0.160635f, 0.158382f,
		0.156128f, 0.153875f, 0.151622f, 0.149369f, 0.147115f, 0.144862f,
		0.142609f, 0.140356f, 0.138102f, 0.13584f, 0.133528f, 0.131216f,
		0.128904f, 0.126592f, 0.12428f, 0.121968f, 0.119656f, 0.117344f,
		0.115032f, 0.11272f, 0.110408f, 0.108096f, 0.105784f, 0.103472f,
		0.10116f, 0.0988482f, 0.0965363f, 0.0942243f, 0.0919123f, 0.0896003f,
		0.0872883f, 0.0849763f, 0.0826643f, 0.0803523f, 0.0780403f, 0.0757284f,
		0.0734164f, 0.0711044f, 0.0687924f, 0.0664277f, 0.0640552f, 0.0616828f,
		0.0593104f, 0.056938f, 0.0545656f, 0.0521932f, 0.0498208f, 0.0474483f,
		0.0450759f, 0.0427034f, 0.0403311f, 0.0379587f, 0.0355862f, 0.0332139f,
		0.0308415f, 0.028469f, 0.0260966f, 0.0237241f, 0.0213518f, 0.0189793f,
		0.0166069f, 0.0142345f, 0.0118621f, 0.00948972f, 0.00711721f, 0.00474483f,
		0.00237238f, 0.f
	};
};

using table_t = wrap::data<math::table, 
                           data::embedded::table<table_t_data>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, wrap::no_process<math::fmod<NV>>>, 
                                  math::pi<NV>, 
                                  core::gain<NV>, 
                                  table_t>;

struct table10_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998386f, 0.996772f, 0.995157f, 0.993543f, 0.991929f,
		0.990315f, 0.9887f, 0.987086f, 0.985472f, 0.983858f, 0.982243f,
		0.980629f, 0.979015f, 0.977401f, 0.975786f, 0.974172f, 0.972558f,
		0.970944f, 0.969329f, 0.967715f, 0.966101f, 0.964487f, 0.962873f,
		0.961258f, 0.959644f, 0.95803f, 0.956416f, 0.954801f, 0.953187f,
		0.951573f, 0.949959f, 0.948344f, 0.94673f, 0.945116f, 0.943502f,
		0.941845f, 0.940189f, 0.938533f, 0.936876f, 0.93522f, 0.933563f,
		0.931907f, 0.93025f, 0.928594f, 0.926938f, 0.925281f, 0.923625f,
		0.921968f, 0.920312f, 0.918655f, 0.916999f, 0.915343f, 0.913686f,
		0.91203f, 0.910373f, 0.908717f, 0.90706f, 0.905404f, 0.903748f,
		0.902091f, 0.900435f, 0.898778f, 0.897122f, 0.895465f, 0.893809f,
		0.892153f, 0.890496f, 0.88884f, 0.887183f, 0.885509f, 0.88381f,
		0.88211f, 0.880411f, 0.878711f, 0.877011f, 0.875312f, 0.873612f,
		0.871913f, 0.870213f, 0.868513f, 0.866814f, 0.865114f, 0.863414f,
		0.861715f, 0.860015f, 0.858316f, 0.856616f, 0.854916f, 0.853217f,
		0.851517f, 0.849818f, 0.848118f, 0.846418f, 0.844719f, 0.843019f,
		0.841319f, 0.83962f, 0.83792f, 0.836221f, 0.834521f, 0.832821f,
		0.831122f, 0.829422f, 0.827713f, 0.825969f, 0.824225f, 0.822481f,
		0.820737f, 0.818994f, 0.81725f, 0.815506f, 0.813762f, 0.812018f,
		0.810274f, 0.80853f, 0.806787f, 0.805043f, 0.803299f, 0.801555f,
		0.799811f, 0.798067f, 0.796323f, 0.79458f, 0.792836f, 0.791092f,
		0.789348f, 0.787604f, 0.78586f, 0.784116f, 0.782372f, 0.780629f,
		0.778885f, 0.777141f, 0.775397f, 0.773653f, 0.771909f, 0.770166f,
		0.768402f, 0.766612f, 0.764823f, 0.763034f, 0.761245f, 0.759456f,
		0.757667f, 0.755877f, 0.754088f, 0.752299f, 0.75051f, 0.748721f,
		0.746931f, 0.745142f, 0.743353f, 0.741564f, 0.739775f, 0.737985f,
		0.736196f, 0.734407f, 0.732618f, 0.730829f, 0.72904f, 0.72725f,
		0.725461f, 0.723672f, 0.721883f, 0.720094f, 0.718305f, 0.716515f,
		0.714726f, 0.712937f, 0.711148f, 0.709355f, 0.70752f, 0.705684f,
		0.703848f, 0.702013f, 0.700177f, 0.698341f, 0.696506f, 0.69467f,
		0.692834f, 0.690999f, 0.689163f, 0.687328f, 0.685492f, 0.683656f,
		0.681821f, 0.679985f, 0.678149f, 0.676314f, 0.674478f, 0.672643f,
		0.670807f, 0.668971f, 0.667136f, 0.6653f, 0.663464f, 0.661629f,
		0.659793f, 0.657957f, 0.656122f, 0.654286f, 0.652451f, 0.650615f,
		0.648774f, 0.646891f, 0.645007f, 0.643124f, 0.641241f, 0.639358f,
		0.637474f, 0.635591f, 0.633708f, 0.631825f, 0.629941f, 0.628058f,
		0.626175f, 0.624292f, 0.622409f, 0.620525f, 0.618642f, 0.616759f,
		0.614875f, 0.612992f, 0.611109f, 0.609226f, 0.607343f, 0.605459f,
		0.603576f, 0.601693f, 0.59981f, 0.597926f, 0.596043f, 0.59416f,
		0.592277f, 0.590393f, 0.58851f, 0.586599f, 0.584667f, 0.582735f,
		0.580803f, 0.578871f, 0.576939f, 0.575007f, 0.573075f, 0.571143f,
		0.569211f, 0.567279f, 0.565347f, 0.563415f, 0.561482f, 0.55955f,
		0.557618f, 0.555686f, 0.553754f, 0.551822f, 0.54989f, 0.547958f,
		0.546026f, 0.544094f, 0.542162f, 0.54023f, 0.538298f, 0.536366f,
		0.534433f, 0.532501f, 0.530569f, 0.528637f, 0.526705f, 0.524752f,
		0.52277f, 0.520788f, 0.518806f, 0.516823f, 0.514841f, 0.512859f,
		0.510877f, 0.508895f, 0.506913f, 0.50493f, 0.502948f, 0.500966f,
		0.498984f, 0.497002f, 0.49502f, 0.493038f, 0.491055f, 0.489073f,
		0.487091f, 0.485109f, 0.483127f, 0.481145f, 0.479163f, 0.47718f,
		0.475198f, 0.473216f, 0.471234f, 0.469252f, 0.46727f, 0.465288f,
		0.463305f, 0.461288f, 0.459254f, 0.457221f, 0.455187f, 0.453154f,
		0.45112f, 0.449087f, 0.447053f, 0.445019f, 0.442986f, 0.440952f,
		0.438919f, 0.436885f, 0.434852f, 0.432818f, 0.430785f, 0.428751f,
		0.426718f, 0.424684f, 0.422651f, 0.420617f, 0.418584f, 0.41655f,
		0.414516f, 0.412483f, 0.410449f, 0.408416f, 0.406382f, 0.404349f,
		0.402315f, 0.400282f, 0.398229f, 0.396143f, 0.394056f, 0.39197f,
		0.389884f, 0.387798f, 0.385711f, 0.383625f, 0.381539f, 0.379452f,
		0.377366f, 0.37528f, 0.373194f, 0.371107f, 0.369021f, 0.366935f,
		0.364848f, 0.362762f, 0.360676f, 0.35859f, 0.356503f, 0.354417f,
		0.352331f, 0.350245f, 0.348158f, 0.346072f, 0.343986f, 0.341899f,
		0.339813f, 0.337727f, 0.335641f, 0.33353f, 0.331389f, 0.329249f,
		0.327109f, 0.324968f, 0.322828f, 0.320687f, 0.318547f, 0.316406f,
		0.314266f, 0.312125f, 0.309985f, 0.307845f, 0.305704f, 0.303564f,
		0.301423f, 0.299283f, 0.297142f, 0.295002f, 0.292861f, 0.290721f,
		0.28858f, 0.28644f, 0.2843f, 0.282159f, 0.280019f, 0.277878f,
		0.275738f, 0.273597f, 0.271457f, 0.269316f, 0.267124f, 0.264928f,
		0.262731f, 0.260535f, 0.258339f, 0.256143f, 0.253947f, 0.251751f,
		0.249555f, 0.247359f, 0.245163f, 0.242967f, 0.240771f, 0.238575f,
		0.236379f, 0.234182f, 0.231986f, 0.22979f, 0.227594f, 0.225398f,
		0.223202f, 0.221006f, 0.21881f, 0.216614f, 0.214418f, 0.212222f,
		0.210026f, 0.20783f, 0.205634f, 0.203437f, 0.201193f, 0.19894f,
		0.196687f, 0.194433f, 0.19218f, 0.189927f, 0.187674f, 0.18542f,
		0.183167f, 0.180914f, 0.178661f, 0.176408f, 0.174154f, 0.171901f,
		0.169648f, 0.167395f, 0.165141f, 0.162888f, 0.160635f, 0.158382f,
		0.156128f, 0.153875f, 0.151622f, 0.149369f, 0.147115f, 0.144862f,
		0.142609f, 0.140356f, 0.138102f, 0.13584f, 0.133528f, 0.131216f,
		0.128904f, 0.126592f, 0.12428f, 0.121968f, 0.119656f, 0.117344f,
		0.115032f, 0.11272f, 0.110408f, 0.108096f, 0.105784f, 0.103472f,
		0.10116f, 0.0988482f, 0.0965363f, 0.0942243f, 0.0919123f, 0.0896003f,
		0.0872883f, 0.0849763f, 0.0826643f, 0.0803523f, 0.0780403f, 0.0757284f,
		0.0734164f, 0.0711044f, 0.0687924f, 0.0664277f, 0.0640552f, 0.0616828f,
		0.0593104f, 0.056938f, 0.0545656f, 0.0521932f, 0.0498208f, 0.0474483f,
		0.0450759f, 0.0427034f, 0.0403311f, 0.0379587f, 0.0355862f, 0.0332139f,
		0.0308415f, 0.028469f, 0.0260966f, 0.0237241f, 0.0213518f, 0.0189793f,
		0.0166069f, 0.0142345f, 0.0118621f, 0.00948972f, 0.00711721f, 0.00474483f,
		0.00237238f, 0.f
	};
};

using table10_t = wrap::data<math::table, 
                             data::embedded::table<table10_t_data>>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<2, wrap::no_process<math::pi<NV>>>, 
                                    core::gain<NV>, 
                                    math::fmod<NV>, 
                                    table10_t>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  math::rect<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  math::fmod<NV>, 
                                  wrap::no_process<math::pi<NV>>, 
                                  math::rect<NV>>;

struct table2_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00346178f, 0.00692362f, 0.0103854f, 0.0138472f, 0.017309f,
		0.0207708f, 0.0242326f, 0.0276944f, 0.0311562f, 0.034618f, 0.0380798f,
		0.0415416f, 0.0450034f, 0.0484653f, 0.051927f, 0.0553888f, 0.0588561f,
		0.0623772f, 0.0658983f, 0.0694194f, 0.0729405f, 0.0764617f, 0.0799828f,
		0.0835039f, 0.087025f, 0.0905461f, 0.0940672f, 0.0975884f, 0.101109f,
		0.104631f, 0.108152f, 0.111673f, 0.115194f, 0.118734f, 0.122316f,
		0.125897f, 0.129478f, 0.13306f, 0.136641f, 0.140223f, 0.143804f,
		0.147385f, 0.150967f, 0.154548f, 0.15813f, 0.161711f, 0.165292f,
		0.168874f, 0.172455f, 0.176036f, 0.179659f, 0.183302f, 0.186945f,
		0.190587f, 0.19423f, 0.197873f, 0.201515f, 0.205158f, 0.208801f,
		0.212443f, 0.216086f, 0.219729f, 0.223371f, 0.227014f, 0.230657f,
		0.234299f, 0.237953f, 0.241658f, 0.245363f, 0.249067f, 0.252772f,
		0.256477f, 0.260182f, 0.263887f, 0.267592f, 0.271297f, 0.275002f,
		0.278707f, 0.282412f, 0.286117f, 0.289822f, 0.293526f, 0.297231f,
		0.300987f, 0.304755f, 0.308524f, 0.312292f, 0.31606f, 0.319828f,
		0.323596f, 0.327365f, 0.331133f, 0.334901f, 0.338669f, 0.342438f,
		0.346206f, 0.349974f, 0.353742f, 0.35751f, 0.361315f, 0.365148f,
		0.36898f, 0.372813f, 0.376646f, 0.380478f, 0.384311f, 0.388143f,
		0.391976f, 0.395808f, 0.399641f, 0.403473f, 0.407306f, 0.411139f,
		0.414971f, 0.418804f, 0.422667f, 0.426565f, 0.430463f, 0.434361f,
		0.438259f, 0.442157f, 0.446055f, 0.449953f, 0.453851f, 0.457749f,
		0.461647f, 0.465545f, 0.469443f, 0.473341f, 0.477239f, 0.481137f,
		0.485069f, 0.489033f, 0.492998f, 0.496962f, 0.500927f, 0.504891f,
		0.508856f, 0.51282f, 0.516785f, 0.52075f, 0.524714f, 0.528679f,
		0.532643f, 0.536608f, 0.540572f, 0.544537f, 0.548547f, 0.552579f,
		0.556611f, 0.560644f, 0.564676f, 0.568708f, 0.57274f, 0.576773f,
		0.580805f, 0.584837f, 0.588869f, 0.592902f, 0.596934f, 0.600966f,
		0.604998f, 0.609031f, 0.61313f, 0.617231f, 0.621332f, 0.625433f,
		0.629534f, 0.633636f, 0.637737f, 0.641838f, 0.645939f, 0.65004f,
		0.654141f, 0.658242f, 0.662343f, 0.666444f, 0.670546f, 0.674676f,
		0.678847f, 0.683018f, 0.687189f, 0.69136f, 0.695531f, 0.699703f,
		0.703874f, 0.708045f, 0.712216f, 0.716387f, 0.720559f, 0.72473f,
		0.728901f, 0.733072f, 0.737243f, 0.741485f, 0.745727f, 0.74997f,
		0.754212f, 0.758455f, 0.762697f, 0.766939f, 0.771182f, 0.775424f,
		0.779667f, 0.783909f, 0.788152f, 0.792394f, 0.796637f, 0.800879f,
		0.805172f, 0.809487f, 0.813802f, 0.818117f, 0.822432f, 0.826747f,
		0.831062f, 0.835377f, 0.839692f, 0.844007f, 0.848322f, 0.852637f,
		0.856952f, 0.861268f, 0.865583f, 0.869937f, 0.874326f, 0.878715f,
		0.883104f, 0.887493f, 0.891882f, 0.89627f, 0.900659f, 0.905048f,
		0.909437f, 0.913826f, 0.918215f, 0.922604f, 0.926993f, 0.931382f,
		0.935809f, 0.940273f, 0.944737f, 0.949201f, 0.953665f, 0.958129f,
		0.962594f, 0.967058f, 0.971522f, 0.975986f, 0.98045f, 0.984914f,
		0.989378f, 0.993842f, 0.998306f, 0.997366f, 0.993121f, 0.988877f,
		0.984632f, 0.980388f, 0.976143f, 0.971898f, 0.967654f, 0.963409f,
		0.959165f, 0.95492f, 0.950675f, 0.946431f, 0.942186f, 0.937942f,
		0.933697f, 0.929453f, 0.925208f, 0.920963f, 0.916719f, 0.912474f,
		0.90823f, 0.903985f, 0.899741f, 0.895496f, 0.891251f, 0.887007f,
		0.882762f, 0.878518f, 0.874273f, 0.870028f, 0.865878f, 0.861735f,
		0.857593f, 0.853451f, 0.849309f, 0.845167f, 0.841025f, 0.836883f,
		0.832741f, 0.828599f, 0.824457f, 0.820315f, 0.816173f, 0.812031f,
		0.807888f, 0.803746f, 0.799604f, 0.795462f, 0.79132f, 0.787178f,
		0.783036f, 0.778894f, 0.774752f, 0.77061f, 0.766468f, 0.762325f,
		0.758183f, 0.754041f, 0.749899f, 0.745757f, 0.741615f, 0.737554f,
		0.733512f, 0.72947f, 0.725428f, 0.721386f, 0.717344f, 0.713302f,
		0.709259f, 0.705217f, 0.701175f, 0.697133f, 0.693091f, 0.689049f,
		0.685007f, 0.680964f, 0.676922f, 0.67288f, 0.668838f, 0.664796f,
		0.660754f, 0.656712f, 0.652669f, 0.648627f, 0.644585f, 0.640543f,
		0.636501f, 0.632459f, 0.628417f, 0.624374f, 0.620332f, 0.61629f,
		0.612279f, 0.608335f, 0.60439f, 0.600446f, 0.596501f, 0.592556f,
		0.588612f, 0.584667f, 0.580722f, 0.576778f, 0.572833f, 0.568888f,
		0.564944f, 0.560999f, 0.557054f, 0.55311f, 0.549165f, 0.54522f,
		0.541276f, 0.537331f, 0.533386f, 0.529442f, 0.525497f, 0.521553f,
		0.517608f, 0.513663f, 0.509718f, 0.505774f, 0.501829f, 0.497885f,
		0.49394f, 0.489995f, 0.486093f, 0.482243f, 0.478394f, 0.474544f,
		0.470695f, 0.466845f, 0.462995f, 0.459146f, 0.455296f, 0.451447f,
		0.447597f, 0.443748f, 0.439898f, 0.436049f, 0.432199f, 0.42835f,
		0.4245f, 0.420651f, 0.416801f, 0.412952f, 0.409102f, 0.405252f,
		0.401403f, 0.397553f, 0.393704f, 0.389854f, 0.386005f, 0.382155f,
		0.378306f, 0.374456f, 0.370607f, 0.366757f, 0.362923f, 0.359167f,
		0.35541f, 0.351653f, 0.347897f, 0.34414f, 0.340383f, 0.336627f,
		0.33287f, 0.329113f, 0.325356f, 0.3216f, 0.317843f, 0.314086f,
		0.31033f, 0.306573f, 0.302816f, 0.29906f, 0.295303f, 0.291546f,
		0.28779f, 0.284033f, 0.280276f, 0.27652f, 0.272763f, 0.269006f,
		0.265249f, 0.261493f, 0.257736f, 0.253979f, 0.250223f, 0.246466f,
		0.242709f, 0.238998f, 0.235332f, 0.231666f, 0.228f, 0.224334f,
		0.220668f, 0.217002f, 0.213336f, 0.20967f, 0.206004f, 0.202338f,
		0.198672f, 0.195006f, 0.19134f, 0.187674f, 0.184008f, 0.180342f,
		0.176675f, 0.17301f, 0.169343f, 0.165677f, 0.162011f, 0.158345f,
		0.154679f, 0.151013f, 0.147347f, 0.143681f, 0.140015f, 0.136349f,
		0.132683f, 0.129017f, 0.125351f, 0.121685f, 0.118058f, 0.114481f,
		0.110903f, 0.107326f, 0.103748f, 0.100171f, 0.0965932f, 0.0930157f,
		0.0894382f, 0.0858607f, 0.0822831f, 0.0787056f, 0.0751281f, 0.0715506f,
		0.067973f, 0.0643955f, 0.060818f, 0.0572404f, 0.0536629f, 0.0500854f,
		0.0465079f, 0.0429304f, 0.0393528f, 0.0357752f, 0.0321977f, 0.0286202f,
		0.0250427f, 0.0214652f, 0.0178877f, 0.0143102f, 0.0107325f, 0.007155f,
		0.00357753f, 0.f
	};
};

using table2_t = wrap::data<math::table, 
                            data::embedded::table<table2_t_data>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   table2_t>;

struct table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00396609f, 0.00793219f, 0.0118982f, 0.0158643f, 0.0198304f,
		0.0237965f, 0.0277625f, 0.0317286f, 0.0356947f, 0.0396608f, 0.0436269f,
		0.0475929f, 0.051559f, 0.0555251f, 0.0594912f, 0.0634573f, 0.0674233f,
		0.0713894f, 0.0753555f, 0.0793216f, 0.0832877f, 0.0872537f, 0.0912198f,
		0.0951859f, 0.099152f, 0.103118f, 0.107084f, 0.11105f, 0.115016f,
		0.118982f, 0.122948f, 0.126915f, 0.130881f, 0.134847f, 0.138813f,
		0.142779f, 0.146745f, 0.150711f, 0.154677f, 0.158643f, 0.162609f,
		0.166575f, 0.170541f, 0.174507f, 0.178474f, 0.18244f, 0.186406f,
		0.190372f, 0.194338f, 0.198304f, 0.20227f, 0.206236f, 0.210202f,
		0.214168f, 0.218134f, 0.2221f, 0.226067f, 0.230033f, 0.233999f,
		0.237965f, 0.241931f, 0.245897f, 0.249863f, 0.253829f, 0.257795f,
		0.261761f, 0.265727f, 0.269693f, 0.27366f, 0.277626f, 0.281592f,
		0.285558f, 0.289524f, 0.29349f, 0.297456f, 0.301422f, 0.305388f,
		0.309354f, 0.31332f, 0.317286f, 0.321252f, 0.325219f, 0.329185f,
		0.333151f, 0.337117f, 0.341083f, 0.345049f, 0.349015f, 0.352981f,
		0.356947f, 0.360913f, 0.364879f, 0.368845f, 0.372811f, 0.376778f,
		0.380744f, 0.38471f, 0.388676f, 0.392642f, 0.396608f, 0.400574f,
		0.40454f, 0.408506f, 0.412472f, 0.416438f, 0.420404f, 0.424371f,
		0.428337f, 0.432303f, 0.436269f, 0.440235f, 0.444201f, 0.448167f,
		0.452133f, 0.456099f, 0.460065f, 0.464031f, 0.467997f, 0.471964f,
		0.475929f, 0.479896f, 0.483862f, 0.487828f, 0.491794f, 0.49576f,
		0.499726f, 0.503692f, 0.507658f, 0.511624f, 0.51559f, 0.519556f,
		0.523523f, 0.527489f, 0.531455f, 0.535421f, 0.539387f, 0.543353f,
		0.547319f, 0.551285f, 0.555251f, 0.559217f, 0.563183f, 0.567149f,
		0.571115f, 0.575082f, 0.579048f, 0.583014f, 0.58698f, 0.590946f,
		0.594912f, 0.598878f, 0.602844f, 0.60681f, 0.610776f, 0.614742f,
		0.618708f, 0.622675f, 0.626641f, 0.630607f, 0.634573f, 0.638539f,
		0.642505f, 0.646471f, 0.650437f, 0.654403f, 0.658369f, 0.662335f,
		0.666301f, 0.670267f, 0.674234f, 0.6782f, 0.682166f, 0.686132f,
		0.690098f, 0.694064f, 0.69803f, 0.701996f, 0.705962f, 0.709928f,
		0.713894f, 0.71786f, 0.721826f, 0.725793f, 0.729759f, 0.733725f,
		0.737691f, 0.741657f, 0.745623f, 0.749589f, 0.753555f, 0.757521f,
		0.761487f, 0.765453f, 0.769419f, 0.773386f, 0.777352f, 0.781318f,
		0.785284f, 0.78925f, 0.793216f, 0.797182f, 0.801148f, 0.805114f,
		0.80908f, 0.813046f, 0.817012f, 0.820979f, 0.824945f, 0.828911f,
		0.832877f, 0.836843f, 0.840809f, 0.844775f, 0.848741f, 0.852707f,
		0.856673f, 0.860639f, 0.864605f, 0.868571f, 0.872537f, 0.876504f,
		0.88047f, 0.884436f, 0.888402f, 0.892368f, 0.896334f, 0.9003f,
		0.904266f, 0.908232f, 0.912198f, 0.916164f, 0.92013f, 0.924097f,
		0.928063f, 0.932029f, 0.935995f, 0.939961f, 0.943927f, 0.947893f,
		0.951859f, 0.955825f, 0.959791f, 0.963757f, 0.967723f, 0.97169f,
		0.975656f, 0.979622f, 0.983588f, 0.987554f, 0.99152f, 0.995486f,
		0.999452f, 0.996671f, 0.992808f, 0.988945f, 0.985081f, 0.981218f,
		0.977355f, 0.973492f, 0.969629f, 0.965766f, 0.961903f, 0.95804f,
		0.954177f, 0.950314f, 0.946451f, 0.942588f, 0.938725f, 0.934862f,
		0.930999f, 0.927135f, 0.923272f, 0.919409f, 0.915546f, 0.911683f,
		0.90782f, 0.903957f, 0.900094f, 0.896231f, 0.892368f, 0.888505f,
		0.884642f, 0.880779f, 0.876916f, 0.873053f, 0.86919f, 0.865326f,
		0.861463f, 0.8576f, 0.853737f, 0.849874f, 0.846011f, 0.842148f,
		0.838285f, 0.834422f, 0.830559f, 0.826696f, 0.822833f, 0.81897f,
		0.815107f, 0.811243f, 0.80738f, 0.803517f, 0.799654f, 0.795791f,
		0.791928f, 0.788065f, 0.784202f, 0.780339f, 0.776476f, 0.772613f,
		0.76875f, 0.764887f, 0.761024f, 0.757161f, 0.753298f, 0.749434f,
		0.745571f, 0.741708f, 0.737845f, 0.733982f, 0.730119f, 0.726256f,
		0.722393f, 0.71853f, 0.714667f, 0.710804f, 0.706941f, 0.703078f,
		0.699215f, 0.695352f, 0.691489f, 0.687625f, 0.683762f, 0.679899f,
		0.676036f, 0.672173f, 0.66831f, 0.664447f, 0.660584f, 0.656721f,
		0.652858f, 0.648995f, 0.645132f, 0.641269f, 0.637406f, 0.633543f,
		0.629679f, 0.625816f, 0.621953f, 0.61809f, 0.614227f, 0.610364f,
		0.606501f, 0.602638f, 0.598775f, 0.594912f, 0.591049f, 0.587186f,
		0.583323f, 0.57946f, 0.575597f, 0.571734f, 0.56787f, 0.564007f,
		0.560144f, 0.556281f, 0.552418f, 0.548555f, 0.544692f, 0.540829f,
		0.536966f, 0.533103f, 0.52924f, 0.525377f, 0.521514f, 0.517651f,
		0.513788f, 0.509925f, 0.506061f, 0.502198f, 0.498335f, 0.494472f,
		0.490609f, 0.486746f, 0.482883f, 0.47902f, 0.475157f, 0.471294f,
		0.467431f, 0.463568f, 0.459705f, 0.455842f, 0.451979f, 0.448116f,
		0.444252f, 0.440389f, 0.436526f, 0.432663f, 0.4288f, 0.424937f,
		0.421074f, 0.417211f, 0.413348f, 0.409485f, 0.405622f, 0.401759f,
		0.397896f, 0.394033f, 0.39017f, 0.386306f, 0.382443f, 0.37858f,
		0.374717f, 0.370854f, 0.366991f, 0.363128f, 0.359265f, 0.355402f,
		0.351539f, 0.347676f, 0.343813f, 0.33995f, 0.336087f, 0.332224f,
		0.32836f, 0.324497f, 0.320634f, 0.316771f, 0.312908f, 0.309045f,
		0.305182f, 0.301319f, 0.297456f, 0.293593f, 0.28973f, 0.285867f,
		0.282004f, 0.278141f, 0.274278f, 0.270414f, 0.266551f, 0.262688f,
		0.258825f, 0.254962f, 0.251099f, 0.247236f, 0.243373f, 0.23951f,
		0.235647f, 0.231784f, 0.227921f, 0.224058f, 0.220195f, 0.216332f,
		0.212469f, 0.208605f, 0.204742f, 0.200879f, 0.197016f, 0.193153f,
		0.18929f, 0.185427f, 0.181564f, 0.177701f, 0.173838f, 0.169975f,
		0.166112f, 0.162249f, 0.158386f, 0.154522f, 0.15066f, 0.146796f,
		0.142933f, 0.13907f, 0.135207f, 0.131344f, 0.127481f, 0.123618f,
		0.119755f, 0.115892f, 0.112029f, 0.108166f, 0.104303f, 0.10044f,
		0.0965766f, 0.0927134f, 0.0888504f, 0.0849874f, 0.0811243f, 0.0772613f,
		0.0733981f, 0.0695351f, 0.065672f, 0.0618089f, 0.057946f, 0.0540828f,
		0.0502198f, 0.0463567f, 0.0424936f, 0.0386305f, 0.0347675f, 0.0309045f,
		0.0270414f, 0.0231783f, 0.0193152f, 0.0154523f, 0.0115891f, 0.00772613f,
		0.00386304f, 0.f
	};
};

using table1_t = wrap::data<math::table, 
                            data::embedded::table<table1_t_data>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  math::fmod<NV>, 
                                  table1_t>;
using table3_t = wrap::data<math::table, 
                            data::external::table<0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   table3_t>;
using table4_t = table3_t;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::fmod<NV>, 
                                   table4_t>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain1_t<NV>>, 
                                   chain111_t<NV>, 
                                   chain10_t<NV>, 
                                   chain11_t<NV>, 
                                   chain5_t<NV>, 
                                   chain109_t<NV>, 
                                   chain3_t<NV>, 
                                   chain4_t<NV>, 
                                   chain12_t<NV>, 
                                   chain6_t<NV>, 
                                   chain13_t<NV>, 
                                   chain14_t<NV>>;

using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;
using oscilloscope_t = wrap::data<analyse::oscilloscope, 
                                  data::external::displaybuffer<2>>;

template <int NV>
using peak15_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak15_t = wrap::mod<peak15_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sig2mod<NV>>, 
                                   oscilloscope_t, 
                                   peak15_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split21_t = container::split<parameter::empty, 
                                   wrap::fix<2, routing::send<NV, stereo_cable<NV>>>, 
                                   chain36_t<NV>>;

template <int NV>
using chain91_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split21_t<NV>>, 
                                   math::clear<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain90_t>, 
                                   chain91_t<NV>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split20_t<NV>>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch28_t<NV>>, 
                                   core::gain<NV>, 
                                   branch2_t<NV>, 
                                   core::mono2stereo, 
                                   branch_t<NV>, 
                                   chain89_t<NV>>;

template <int NV> using chain228_t = chain235_t<NV>;

template <int NV> using chain230_t = chain235_t<NV>;

template <int NV> using chain268_t = chain235_t<NV>;

template <int NV> using chain229_t = chain235_t<NV>;

template <int NV> using chain231_t = chain235_t<NV>;
template <int NV>
using branch27_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain228_t<NV>>, 
                                     chain230_t<NV>, 
                                     chain268_t<NV>, 
                                     chain229_t<NV>, 
                                     chain231_t<NV>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<2, converter3_t<NV>>, 
                                   core::phasor_fm<NV>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync2_t<NV>>, 
                                   converter1_t<NV>, 
                                   core::phasor_fm<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain31_t<NV>>, 
                                    chain32_t<NV>>;
namespace custom
{

struct expr1
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::pi<NV>, 
                                   math::expr<NV, custom::expr1>>;
namespace custom
{

struct expr14
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<2, core::gain<NV>>, 
                                    math::fmod<NV>, 
                                    math::expr<NV, custom::expr14>>;
namespace custom
{

struct expr8
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter5_t<NV>>, 
                                   math::expr<NV, custom::expr7>, 
                                   math::expr<NV, custom::expr8>>;
namespace custom
{

struct expr9
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

namespace custom
{

struct expr11
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);
		;
	}
};
}

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter2_t<NV>>, 
                                   math::expr<NV, custom::expr9>, 
                                   math::expr<NV, custom::expr10>, 
                                   math::expr<NV, custom::expr11>>;

struct table5_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998386f, 0.996772f, 0.995157f, 0.993543f, 0.991929f,
		0.990315f, 0.9887f, 0.987086f, 0.985472f, 0.983858f, 0.982243f,
		0.980629f, 0.979015f, 0.977401f, 0.975786f, 0.974172f, 0.972558f,
		0.970944f, 0.969329f, 0.967715f, 0.966101f, 0.964487f, 0.962873f,
		0.961258f, 0.959644f, 0.95803f, 0.956416f, 0.954801f, 0.953187f,
		0.951573f, 0.949959f, 0.948344f, 0.94673f, 0.945116f, 0.943502f,
		0.941845f, 0.940189f, 0.938533f, 0.936876f, 0.93522f, 0.933563f,
		0.931907f, 0.93025f, 0.928594f, 0.926938f, 0.925281f, 0.923625f,
		0.921968f, 0.920312f, 0.918655f, 0.916999f, 0.915343f, 0.913686f,
		0.91203f, 0.910373f, 0.908717f, 0.90706f, 0.905404f, 0.903748f,
		0.902091f, 0.900435f, 0.898778f, 0.897122f, 0.895465f, 0.893809f,
		0.892153f, 0.890496f, 0.88884f, 0.887183f, 0.885509f, 0.88381f,
		0.88211f, 0.880411f, 0.878711f, 0.877011f, 0.875312f, 0.873612f,
		0.871913f, 0.870213f, 0.868513f, 0.866814f, 0.865114f, 0.863414f,
		0.861715f, 0.860015f, 0.858316f, 0.856616f, 0.854916f, 0.853217f,
		0.851517f, 0.849818f, 0.848118f, 0.846418f, 0.844719f, 0.843019f,
		0.841319f, 0.83962f, 0.83792f, 0.836221f, 0.834521f, 0.832821f,
		0.831122f, 0.829422f, 0.827713f, 0.825969f, 0.824225f, 0.822481f,
		0.820737f, 0.818994f, 0.81725f, 0.815506f, 0.813762f, 0.812018f,
		0.810274f, 0.80853f, 0.806787f, 0.805043f, 0.803299f, 0.801555f,
		0.799811f, 0.798067f, 0.796323f, 0.79458f, 0.792836f, 0.791092f,
		0.789348f, 0.787604f, 0.78586f, 0.784116f, 0.782372f, 0.780629f,
		0.778885f, 0.777141f, 0.775397f, 0.773653f, 0.771909f, 0.770166f,
		0.768402f, 0.766612f, 0.764823f, 0.763034f, 0.761245f, 0.759456f,
		0.757667f, 0.755877f, 0.754088f, 0.752299f, 0.75051f, 0.748721f,
		0.746931f, 0.745142f, 0.743353f, 0.741564f, 0.739775f, 0.737985f,
		0.736196f, 0.734407f, 0.732618f, 0.730829f, 0.72904f, 0.72725f,
		0.725461f, 0.723672f, 0.721883f, 0.720094f, 0.718305f, 0.716515f,
		0.714726f, 0.712937f, 0.711148f, 0.709355f, 0.70752f, 0.705684f,
		0.703848f, 0.702013f, 0.700177f, 0.698341f, 0.696506f, 0.69467f,
		0.692834f, 0.690999f, 0.689163f, 0.687328f, 0.685492f, 0.683656f,
		0.681821f, 0.679985f, 0.678149f, 0.676314f, 0.674478f, 0.672643f,
		0.670807f, 0.668971f, 0.667136f, 0.6653f, 0.663464f, 0.661629f,
		0.659793f, 0.657957f, 0.656122f, 0.654286f, 0.652451f, 0.650615f,
		0.648774f, 0.646891f, 0.645007f, 0.643124f, 0.641241f, 0.639358f,
		0.637474f, 0.635591f, 0.633708f, 0.631825f, 0.629941f, 0.628058f,
		0.626175f, 0.624292f, 0.622409f, 0.620525f, 0.618642f, 0.616759f,
		0.614875f, 0.612992f, 0.611109f, 0.609226f, 0.607343f, 0.605459f,
		0.603576f, 0.601693f, 0.59981f, 0.597926f, 0.596043f, 0.59416f,
		0.592277f, 0.590393f, 0.58851f, 0.586599f, 0.584667f, 0.582735f,
		0.580803f, 0.578871f, 0.576939f, 0.575007f, 0.573075f, 0.571143f,
		0.569211f, 0.567279f, 0.565347f, 0.563415f, 0.561482f, 0.55955f,
		0.557618f, 0.555686f, 0.553754f, 0.551822f, 0.54989f, 0.547958f,
		0.546026f, 0.544094f, 0.542162f, 0.54023f, 0.538298f, 0.536366f,
		0.534433f, 0.532501f, 0.530569f, 0.528637f, 0.526705f, 0.524752f,
		0.52277f, 0.520788f, 0.518806f, 0.516823f, 0.514841f, 0.512859f,
		0.510877f, 0.508895f, 0.506913f, 0.50493f, 0.502948f, 0.500966f,
		0.498984f, 0.497002f, 0.49502f, 0.493038f, 0.491055f, 0.489073f,
		0.487091f, 0.485109f, 0.483127f, 0.481145f, 0.479163f, 0.47718f,
		0.475198f, 0.473216f, 0.471234f, 0.469252f, 0.46727f, 0.465288f,
		0.463305f, 0.461288f, 0.459254f, 0.457221f, 0.455187f, 0.453154f,
		0.45112f, 0.449087f, 0.447053f, 0.445019f, 0.442986f, 0.440952f,
		0.438919f, 0.436885f, 0.434852f, 0.432818f, 0.430785f, 0.428751f,
		0.426718f, 0.424684f, 0.422651f, 0.420617f, 0.418584f, 0.41655f,
		0.414516f, 0.412483f, 0.410449f, 0.408416f, 0.406382f, 0.404349f,
		0.402315f, 0.400282f, 0.398229f, 0.396143f, 0.394056f, 0.39197f,
		0.389884f, 0.387798f, 0.385711f, 0.383625f, 0.381539f, 0.379452f,
		0.377366f, 0.37528f, 0.373194f, 0.371107f, 0.369021f, 0.366935f,
		0.364848f, 0.362762f, 0.360676f, 0.35859f, 0.356503f, 0.354417f,
		0.352331f, 0.350245f, 0.348158f, 0.346072f, 0.343986f, 0.341899f,
		0.339813f, 0.337727f, 0.335641f, 0.33353f, 0.331389f, 0.329249f,
		0.327109f, 0.324968f, 0.322828f, 0.320687f, 0.318547f, 0.316406f,
		0.314266f, 0.312125f, 0.309985f, 0.307845f, 0.305704f, 0.303564f,
		0.301423f, 0.299283f, 0.297142f, 0.295002f, 0.292861f, 0.290721f,
		0.28858f, 0.28644f, 0.2843f, 0.282159f, 0.280019f, 0.277878f,
		0.275738f, 0.273597f, 0.271457f, 0.269316f, 0.267124f, 0.264928f,
		0.262731f, 0.260535f, 0.258339f, 0.256143f, 0.253947f, 0.251751f,
		0.249555f, 0.247359f, 0.245163f, 0.242967f, 0.240771f, 0.238575f,
		0.236379f, 0.234182f, 0.231986f, 0.22979f, 0.227594f, 0.225398f,
		0.223202f, 0.221006f, 0.21881f, 0.216614f, 0.214418f, 0.212222f,
		0.210026f, 0.20783f, 0.205634f, 0.203437f, 0.201193f, 0.19894f,
		0.196687f, 0.194433f, 0.19218f, 0.189927f, 0.187674f, 0.18542f,
		0.183167f, 0.180914f, 0.178661f, 0.176408f, 0.174154f, 0.171901f,
		0.169648f, 0.167395f, 0.165141f, 0.162888f, 0.160635f, 0.158382f,
		0.156128f, 0.153875f, 0.151622f, 0.149369f, 0.147115f, 0.144862f,
		0.142609f, 0.140356f, 0.138102f, 0.13584f, 0.133528f, 0.131216f,
		0.128904f, 0.126592f, 0.12428f, 0.121968f, 0.119656f, 0.117344f,
		0.115032f, 0.11272f, 0.110408f, 0.108096f, 0.105784f, 0.103472f,
		0.10116f, 0.0988482f, 0.0965363f, 0.0942243f, 0.0919123f, 0.0896003f,
		0.0872883f, 0.0849763f, 0.0826643f, 0.0803523f, 0.0780403f, 0.0757284f,
		0.0734164f, 0.0711044f, 0.0687924f, 0.0664277f, 0.0640552f, 0.0616828f,
		0.0593104f, 0.056938f, 0.0545656f, 0.0521932f, 0.0498208f, 0.0474483f,
		0.0450759f, 0.0427034f, 0.0403311f, 0.0379587f, 0.0355862f, 0.0332139f,
		0.0308415f, 0.028469f, 0.0260966f, 0.0237241f, 0.0213518f, 0.0189793f,
		0.0166069f, 0.0142345f, 0.0118621f, 0.00948972f, 0.00711721f, 0.00474483f,
		0.00237238f, 0.f
	};
};

using table5_t = wrap::data<math::table, 
                            data::embedded::table<table5_t_data>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::fmod<NV>>>, 
                                   math::pi<NV>, 
                                   core::gain<NV>, 
                                   table5_t>;

struct table11_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998386f, 0.996772f, 0.995157f, 0.993543f, 0.991929f,
		0.990315f, 0.9887f, 0.987086f, 0.985472f, 0.983858f, 0.982243f,
		0.980629f, 0.979015f, 0.977401f, 0.975786f, 0.974172f, 0.972558f,
		0.970944f, 0.969329f, 0.967715f, 0.966101f, 0.964487f, 0.962873f,
		0.961258f, 0.959644f, 0.95803f, 0.956416f, 0.954801f, 0.953187f,
		0.951573f, 0.949959f, 0.948344f, 0.94673f, 0.945116f, 0.943502f,
		0.941845f, 0.940189f, 0.938533f, 0.936876f, 0.93522f, 0.933563f,
		0.931907f, 0.93025f, 0.928594f, 0.926938f, 0.925281f, 0.923625f,
		0.921968f, 0.920312f, 0.918655f, 0.916999f, 0.915343f, 0.913686f,
		0.91203f, 0.910373f, 0.908717f, 0.90706f, 0.905404f, 0.903748f,
		0.902091f, 0.900435f, 0.898778f, 0.897122f, 0.895465f, 0.893809f,
		0.892153f, 0.890496f, 0.88884f, 0.887183f, 0.885509f, 0.88381f,
		0.88211f, 0.880411f, 0.878711f, 0.877011f, 0.875312f, 0.873612f,
		0.871913f, 0.870213f, 0.868513f, 0.866814f, 0.865114f, 0.863414f,
		0.861715f, 0.860015f, 0.858316f, 0.856616f, 0.854916f, 0.853217f,
		0.851517f, 0.849818f, 0.848118f, 0.846418f, 0.844719f, 0.843019f,
		0.841319f, 0.83962f, 0.83792f, 0.836221f, 0.834521f, 0.832821f,
		0.831122f, 0.829422f, 0.827713f, 0.825969f, 0.824225f, 0.822481f,
		0.820737f, 0.818994f, 0.81725f, 0.815506f, 0.813762f, 0.812018f,
		0.810274f, 0.80853f, 0.806787f, 0.805043f, 0.803299f, 0.801555f,
		0.799811f, 0.798067f, 0.796323f, 0.79458f, 0.792836f, 0.791092f,
		0.789348f, 0.787604f, 0.78586f, 0.784116f, 0.782372f, 0.780629f,
		0.778885f, 0.777141f, 0.775397f, 0.773653f, 0.771909f, 0.770166f,
		0.768402f, 0.766612f, 0.764823f, 0.763034f, 0.761245f, 0.759456f,
		0.757667f, 0.755877f, 0.754088f, 0.752299f, 0.75051f, 0.748721f,
		0.746931f, 0.745142f, 0.743353f, 0.741564f, 0.739775f, 0.737985f,
		0.736196f, 0.734407f, 0.732618f, 0.730829f, 0.72904f, 0.72725f,
		0.725461f, 0.723672f, 0.721883f, 0.720094f, 0.718305f, 0.716515f,
		0.714726f, 0.712937f, 0.711148f, 0.709355f, 0.70752f, 0.705684f,
		0.703848f, 0.702013f, 0.700177f, 0.698341f, 0.696506f, 0.69467f,
		0.692834f, 0.690999f, 0.689163f, 0.687328f, 0.685492f, 0.683656f,
		0.681821f, 0.679985f, 0.678149f, 0.676314f, 0.674478f, 0.672643f,
		0.670807f, 0.668971f, 0.667136f, 0.6653f, 0.663464f, 0.661629f,
		0.659793f, 0.657957f, 0.656122f, 0.654286f, 0.652451f, 0.650615f,
		0.648774f, 0.646891f, 0.645007f, 0.643124f, 0.641241f, 0.639358f,
		0.637474f, 0.635591f, 0.633708f, 0.631825f, 0.629941f, 0.628058f,
		0.626175f, 0.624292f, 0.622409f, 0.620525f, 0.618642f, 0.616759f,
		0.614875f, 0.612992f, 0.611109f, 0.609226f, 0.607343f, 0.605459f,
		0.603576f, 0.601693f, 0.59981f, 0.597926f, 0.596043f, 0.59416f,
		0.592277f, 0.590393f, 0.58851f, 0.586599f, 0.584667f, 0.582735f,
		0.580803f, 0.578871f, 0.576939f, 0.575007f, 0.573075f, 0.571143f,
		0.569211f, 0.567279f, 0.565347f, 0.563415f, 0.561482f, 0.55955f,
		0.557618f, 0.555686f, 0.553754f, 0.551822f, 0.54989f, 0.547958f,
		0.546026f, 0.544094f, 0.542162f, 0.54023f, 0.538298f, 0.536366f,
		0.534433f, 0.532501f, 0.530569f, 0.528637f, 0.526705f, 0.524752f,
		0.52277f, 0.520788f, 0.518806f, 0.516823f, 0.514841f, 0.512859f,
		0.510877f, 0.508895f, 0.506913f, 0.50493f, 0.502948f, 0.500966f,
		0.498984f, 0.497002f, 0.49502f, 0.493038f, 0.491055f, 0.489073f,
		0.487091f, 0.485109f, 0.483127f, 0.481145f, 0.479163f, 0.47718f,
		0.475198f, 0.473216f, 0.471234f, 0.469252f, 0.46727f, 0.465288f,
		0.463305f, 0.461288f, 0.459254f, 0.457221f, 0.455187f, 0.453154f,
		0.45112f, 0.449087f, 0.447053f, 0.445019f, 0.442986f, 0.440952f,
		0.438919f, 0.436885f, 0.434852f, 0.432818f, 0.430785f, 0.428751f,
		0.426718f, 0.424684f, 0.422651f, 0.420617f, 0.418584f, 0.41655f,
		0.414516f, 0.412483f, 0.410449f, 0.408416f, 0.406382f, 0.404349f,
		0.402315f, 0.400282f, 0.398229f, 0.396143f, 0.394056f, 0.39197f,
		0.389884f, 0.387798f, 0.385711f, 0.383625f, 0.381539f, 0.379452f,
		0.377366f, 0.37528f, 0.373194f, 0.371107f, 0.369021f, 0.366935f,
		0.364848f, 0.362762f, 0.360676f, 0.35859f, 0.356503f, 0.354417f,
		0.352331f, 0.350245f, 0.348158f, 0.346072f, 0.343986f, 0.341899f,
		0.339813f, 0.337727f, 0.335641f, 0.33353f, 0.331389f, 0.329249f,
		0.327109f, 0.324968f, 0.322828f, 0.320687f, 0.318547f, 0.316406f,
		0.314266f, 0.312125f, 0.309985f, 0.307845f, 0.305704f, 0.303564f,
		0.301423f, 0.299283f, 0.297142f, 0.295002f, 0.292861f, 0.290721f,
		0.28858f, 0.28644f, 0.2843f, 0.282159f, 0.280019f, 0.277878f,
		0.275738f, 0.273597f, 0.271457f, 0.269316f, 0.267124f, 0.264928f,
		0.262731f, 0.260535f, 0.258339f, 0.256143f, 0.253947f, 0.251751f,
		0.249555f, 0.247359f, 0.245163f, 0.242967f, 0.240771f, 0.238575f,
		0.236379f, 0.234182f, 0.231986f, 0.22979f, 0.227594f, 0.225398f,
		0.223202f, 0.221006f, 0.21881f, 0.216614f, 0.214418f, 0.212222f,
		0.210026f, 0.20783f, 0.205634f, 0.203437f, 0.201193f, 0.19894f,
		0.196687f, 0.194433f, 0.19218f, 0.189927f, 0.187674f, 0.18542f,
		0.183167f, 0.180914f, 0.178661f, 0.176408f, 0.174154f, 0.171901f,
		0.169648f, 0.167395f, 0.165141f, 0.162888f, 0.160635f, 0.158382f,
		0.156128f, 0.153875f, 0.151622f, 0.149369f, 0.147115f, 0.144862f,
		0.142609f, 0.140356f, 0.138102f, 0.13584f, 0.133528f, 0.131216f,
		0.128904f, 0.126592f, 0.12428f, 0.121968f, 0.119656f, 0.117344f,
		0.115032f, 0.11272f, 0.110408f, 0.108096f, 0.105784f, 0.103472f,
		0.10116f, 0.0988482f, 0.0965363f, 0.0942243f, 0.0919123f, 0.0896003f,
		0.0872883f, 0.0849763f, 0.0826643f, 0.0803523f, 0.0780403f, 0.0757284f,
		0.0734164f, 0.0711044f, 0.0687924f, 0.0664277f, 0.0640552f, 0.0616828f,
		0.0593104f, 0.056938f, 0.0545656f, 0.0521932f, 0.0498208f, 0.0474483f,
		0.0450759f, 0.0427034f, 0.0403311f, 0.0379587f, 0.0355862f, 0.0332139f,
		0.0308415f, 0.028469f, 0.0260966f, 0.0237241f, 0.0213518f, 0.0189793f,
		0.0166069f, 0.0142345f, 0.0118621f, 0.00948972f, 0.00711721f, 0.00474483f,
		0.00237238f, 0.f
	};
};

using table11_t = wrap::data<math::table, 
                             data::embedded::table<table11_t_data>>;

template <int NV>
using chain132_t = container::chain<parameter::empty, 
                                    wrap::fix<2, wrap::no_process<math::pi<NV>>>, 
                                    core::gain<NV>, 
                                    math::fmod<NV>, 
                                    table11_t>;

template <int NV> using chain25_t = chain3_t<NV>;

template <int NV> using chain26_t = chain4_t<NV>;

struct table6_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00346178f, 0.00692362f, 0.0103854f, 0.0138472f, 0.017309f,
		0.0207708f, 0.0242326f, 0.0276944f, 0.0311562f, 0.034618f, 0.0380798f,
		0.0415416f, 0.0450034f, 0.0484653f, 0.051927f, 0.0553888f, 0.0588561f,
		0.0623772f, 0.0658983f, 0.0694194f, 0.0729405f, 0.0764617f, 0.0799828f,
		0.0835039f, 0.087025f, 0.0905461f, 0.0940672f, 0.0975884f, 0.101109f,
		0.104631f, 0.108152f, 0.111673f, 0.115194f, 0.118734f, 0.122316f,
		0.125897f, 0.129478f, 0.13306f, 0.136641f, 0.140223f, 0.143804f,
		0.147385f, 0.150967f, 0.154548f, 0.15813f, 0.161711f, 0.165292f,
		0.168874f, 0.172455f, 0.176036f, 0.179659f, 0.183302f, 0.186945f,
		0.190587f, 0.19423f, 0.197873f, 0.201515f, 0.205158f, 0.208801f,
		0.212443f, 0.216086f, 0.219729f, 0.223371f, 0.227014f, 0.230657f,
		0.234299f, 0.237953f, 0.241658f, 0.245363f, 0.249067f, 0.252772f,
		0.256477f, 0.260182f, 0.263887f, 0.267592f, 0.271297f, 0.275002f,
		0.278707f, 0.282412f, 0.286117f, 0.289822f, 0.293526f, 0.297231f,
		0.300987f, 0.304755f, 0.308524f, 0.312292f, 0.31606f, 0.319828f,
		0.323596f, 0.327365f, 0.331133f, 0.334901f, 0.338669f, 0.342438f,
		0.346206f, 0.349974f, 0.353742f, 0.35751f, 0.361315f, 0.365148f,
		0.36898f, 0.372813f, 0.376646f, 0.380478f, 0.384311f, 0.388143f,
		0.391976f, 0.395808f, 0.399641f, 0.403473f, 0.407306f, 0.411139f,
		0.414971f, 0.418804f, 0.422667f, 0.426565f, 0.430463f, 0.434361f,
		0.438259f, 0.442157f, 0.446055f, 0.449953f, 0.453851f, 0.457749f,
		0.461647f, 0.465545f, 0.469443f, 0.473341f, 0.477239f, 0.481137f,
		0.485069f, 0.489033f, 0.492998f, 0.496962f, 0.500927f, 0.504891f,
		0.508856f, 0.51282f, 0.516785f, 0.52075f, 0.524714f, 0.528679f,
		0.532643f, 0.536608f, 0.540572f, 0.544537f, 0.548547f, 0.552579f,
		0.556611f, 0.560644f, 0.564676f, 0.568708f, 0.57274f, 0.576773f,
		0.580805f, 0.584837f, 0.588869f, 0.592902f, 0.596934f, 0.600966f,
		0.604998f, 0.609031f, 0.61313f, 0.617231f, 0.621332f, 0.625433f,
		0.629534f, 0.633636f, 0.637737f, 0.641838f, 0.645939f, 0.65004f,
		0.654141f, 0.658242f, 0.662343f, 0.666444f, 0.670546f, 0.674676f,
		0.678847f, 0.683018f, 0.687189f, 0.69136f, 0.695531f, 0.699703f,
		0.703874f, 0.708045f, 0.712216f, 0.716387f, 0.720559f, 0.72473f,
		0.728901f, 0.733072f, 0.737243f, 0.741485f, 0.745727f, 0.74997f,
		0.754212f, 0.758455f, 0.762697f, 0.766939f, 0.771182f, 0.775424f,
		0.779667f, 0.783909f, 0.788152f, 0.792394f, 0.796637f, 0.800879f,
		0.805172f, 0.809487f, 0.813802f, 0.818117f, 0.822432f, 0.826747f,
		0.831062f, 0.835377f, 0.839692f, 0.844007f, 0.848322f, 0.852637f,
		0.856952f, 0.861268f, 0.865583f, 0.869937f, 0.874326f, 0.878715f,
		0.883104f, 0.887493f, 0.891882f, 0.89627f, 0.900659f, 0.905048f,
		0.909437f, 0.913826f, 0.918215f, 0.922604f, 0.926993f, 0.931382f,
		0.935809f, 0.940273f, 0.944737f, 0.949201f, 0.953665f, 0.958129f,
		0.962594f, 0.967058f, 0.971522f, 0.975986f, 0.98045f, 0.984914f,
		0.989378f, 0.993842f, 0.998306f, 0.997366f, 0.993121f, 0.988877f,
		0.984632f, 0.980388f, 0.976143f, 0.971898f, 0.967654f, 0.963409f,
		0.959165f, 0.95492f, 0.950675f, 0.946431f, 0.942186f, 0.937942f,
		0.933697f, 0.929453f, 0.925208f, 0.920963f, 0.916719f, 0.912474f,
		0.90823f, 0.903985f, 0.899741f, 0.895496f, 0.891251f, 0.887007f,
		0.882762f, 0.878518f, 0.874273f, 0.870028f, 0.865878f, 0.861735f,
		0.857593f, 0.853451f, 0.849309f, 0.845167f, 0.841025f, 0.836883f,
		0.832741f, 0.828599f, 0.824457f, 0.820315f, 0.816173f, 0.812031f,
		0.807888f, 0.803746f, 0.799604f, 0.795462f, 0.79132f, 0.787178f,
		0.783036f, 0.778894f, 0.774752f, 0.77061f, 0.766468f, 0.762325f,
		0.758183f, 0.754041f, 0.749899f, 0.745757f, 0.741615f, 0.737554f,
		0.733512f, 0.72947f, 0.725428f, 0.721386f, 0.717344f, 0.713302f,
		0.709259f, 0.705217f, 0.701175f, 0.697133f, 0.693091f, 0.689049f,
		0.685007f, 0.680964f, 0.676922f, 0.67288f, 0.668838f, 0.664796f,
		0.660754f, 0.656712f, 0.652669f, 0.648627f, 0.644585f, 0.640543f,
		0.636501f, 0.632459f, 0.628417f, 0.624374f, 0.620332f, 0.61629f,
		0.612279f, 0.608335f, 0.60439f, 0.600446f, 0.596501f, 0.592556f,
		0.588612f, 0.584667f, 0.580722f, 0.576778f, 0.572833f, 0.568888f,
		0.564944f, 0.560999f, 0.557054f, 0.55311f, 0.549165f, 0.54522f,
		0.541276f, 0.537331f, 0.533386f, 0.529442f, 0.525497f, 0.521553f,
		0.517608f, 0.513663f, 0.509718f, 0.505774f, 0.501829f, 0.497885f,
		0.49394f, 0.489995f, 0.486093f, 0.482243f, 0.478394f, 0.474544f,
		0.470695f, 0.466845f, 0.462995f, 0.459146f, 0.455296f, 0.451447f,
		0.447597f, 0.443748f, 0.439898f, 0.436049f, 0.432199f, 0.42835f,
		0.4245f, 0.420651f, 0.416801f, 0.412952f, 0.409102f, 0.405252f,
		0.401403f, 0.397553f, 0.393704f, 0.389854f, 0.386005f, 0.382155f,
		0.378306f, 0.374456f, 0.370607f, 0.366757f, 0.362923f, 0.359167f,
		0.35541f, 0.351653f, 0.347897f, 0.34414f, 0.340383f, 0.336627f,
		0.33287f, 0.329113f, 0.325356f, 0.3216f, 0.317843f, 0.314086f,
		0.31033f, 0.306573f, 0.302816f, 0.29906f, 0.295303f, 0.291546f,
		0.28779f, 0.284033f, 0.280276f, 0.27652f, 0.272763f, 0.269006f,
		0.265249f, 0.261493f, 0.257736f, 0.253979f, 0.250223f, 0.246466f,
		0.242709f, 0.238998f, 0.235332f, 0.231666f, 0.228f, 0.224334f,
		0.220668f, 0.217002f, 0.213336f, 0.20967f, 0.206004f, 0.202338f,
		0.198672f, 0.195006f, 0.19134f, 0.187674f, 0.184008f, 0.180342f,
		0.176675f, 0.17301f, 0.169343f, 0.165677f, 0.162011f, 0.158345f,
		0.154679f, 0.151013f, 0.147347f, 0.143681f, 0.140015f, 0.136349f,
		0.132683f, 0.129017f, 0.125351f, 0.121685f, 0.118058f, 0.114481f,
		0.110903f, 0.107326f, 0.103748f, 0.100171f, 0.0965932f, 0.0930157f,
		0.0894382f, 0.0858607f, 0.0822831f, 0.0787056f, 0.0751281f, 0.0715506f,
		0.067973f, 0.0643955f, 0.060818f, 0.0572404f, 0.0536629f, 0.0500854f,
		0.0465079f, 0.0429304f, 0.0393528f, 0.0357752f, 0.0321977f, 0.0286202f,
		0.0250427f, 0.0214652f, 0.0178877f, 0.0143102f, 0.0107325f, 0.007155f,
		0.00357753f, 0.f
	};
};

using table6_t = wrap::data<math::table, 
                            data::embedded::table<table6_t_data>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   table6_t>;

struct table7_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00396609f, 0.00793219f, 0.0118982f, 0.0158643f, 0.0198304f,
		0.0237965f, 0.0277625f, 0.0317286f, 0.0356947f, 0.0396608f, 0.0436269f,
		0.0475929f, 0.051559f, 0.0555251f, 0.0594912f, 0.0634573f, 0.0674233f,
		0.0713894f, 0.0753555f, 0.0793216f, 0.0832877f, 0.0872537f, 0.0912198f,
		0.0951859f, 0.099152f, 0.103118f, 0.107084f, 0.11105f, 0.115016f,
		0.118982f, 0.122948f, 0.126915f, 0.130881f, 0.134847f, 0.138813f,
		0.142779f, 0.146745f, 0.150711f, 0.154677f, 0.158643f, 0.162609f,
		0.166575f, 0.170541f, 0.174507f, 0.178474f, 0.18244f, 0.186406f,
		0.190372f, 0.194338f, 0.198304f, 0.20227f, 0.206236f, 0.210202f,
		0.214168f, 0.218134f, 0.2221f, 0.226067f, 0.230033f, 0.233999f,
		0.237965f, 0.241931f, 0.245897f, 0.249863f, 0.253829f, 0.257795f,
		0.261761f, 0.265727f, 0.269693f, 0.27366f, 0.277626f, 0.281592f,
		0.285558f, 0.289524f, 0.29349f, 0.297456f, 0.301422f, 0.305388f,
		0.309354f, 0.31332f, 0.317286f, 0.321252f, 0.325219f, 0.329185f,
		0.333151f, 0.337117f, 0.341083f, 0.345049f, 0.349015f, 0.352981f,
		0.356947f, 0.360913f, 0.364879f, 0.368845f, 0.372811f, 0.376778f,
		0.380744f, 0.38471f, 0.388676f, 0.392642f, 0.396608f, 0.400574f,
		0.40454f, 0.408506f, 0.412472f, 0.416438f, 0.420404f, 0.424371f,
		0.428337f, 0.432303f, 0.436269f, 0.440235f, 0.444201f, 0.448167f,
		0.452133f, 0.456099f, 0.460065f, 0.464031f, 0.467997f, 0.471964f,
		0.475929f, 0.479896f, 0.483862f, 0.487828f, 0.491794f, 0.49576f,
		0.499726f, 0.503692f, 0.507658f, 0.511624f, 0.51559f, 0.519556f,
		0.523523f, 0.527489f, 0.531455f, 0.535421f, 0.539387f, 0.543353f,
		0.547319f, 0.551285f, 0.555251f, 0.559217f, 0.563183f, 0.567149f,
		0.571115f, 0.575082f, 0.579048f, 0.583014f, 0.58698f, 0.590946f,
		0.594912f, 0.598878f, 0.602844f, 0.60681f, 0.610776f, 0.614742f,
		0.618708f, 0.622675f, 0.626641f, 0.630607f, 0.634573f, 0.638539f,
		0.642505f, 0.646471f, 0.650437f, 0.654403f, 0.658369f, 0.662335f,
		0.666301f, 0.670267f, 0.674234f, 0.6782f, 0.682166f, 0.686132f,
		0.690098f, 0.694064f, 0.69803f, 0.701996f, 0.705962f, 0.709928f,
		0.713894f, 0.71786f, 0.721826f, 0.725793f, 0.729759f, 0.733725f,
		0.737691f, 0.741657f, 0.745623f, 0.749589f, 0.753555f, 0.757521f,
		0.761487f, 0.765453f, 0.769419f, 0.773386f, 0.777352f, 0.781318f,
		0.785284f, 0.78925f, 0.793216f, 0.797182f, 0.801148f, 0.805114f,
		0.80908f, 0.813046f, 0.817012f, 0.820979f, 0.824945f, 0.828911f,
		0.832877f, 0.836843f, 0.840809f, 0.844775f, 0.848741f, 0.852707f,
		0.856673f, 0.860639f, 0.864605f, 0.868571f, 0.872537f, 0.876504f,
		0.88047f, 0.884436f, 0.888402f, 0.892368f, 0.896334f, 0.9003f,
		0.904266f, 0.908232f, 0.912198f, 0.916164f, 0.92013f, 0.924097f,
		0.928063f, 0.932029f, 0.935995f, 0.939961f, 0.943927f, 0.947893f,
		0.951859f, 0.955825f, 0.959791f, 0.963757f, 0.967723f, 0.97169f,
		0.975656f, 0.979622f, 0.983588f, 0.987554f, 0.99152f, 0.995486f,
		0.999452f, 0.996671f, 0.992808f, 0.988945f, 0.985081f, 0.981218f,
		0.977355f, 0.973492f, 0.969629f, 0.965766f, 0.961903f, 0.95804f,
		0.954177f, 0.950314f, 0.946451f, 0.942588f, 0.938725f, 0.934862f,
		0.930999f, 0.927135f, 0.923272f, 0.919409f, 0.915546f, 0.911683f,
		0.90782f, 0.903957f, 0.900094f, 0.896231f, 0.892368f, 0.888505f,
		0.884642f, 0.880779f, 0.876916f, 0.873053f, 0.86919f, 0.865326f,
		0.861463f, 0.8576f, 0.853737f, 0.849874f, 0.846011f, 0.842148f,
		0.838285f, 0.834422f, 0.830559f, 0.826696f, 0.822833f, 0.81897f,
		0.815107f, 0.811243f, 0.80738f, 0.803517f, 0.799654f, 0.795791f,
		0.791928f, 0.788065f, 0.784202f, 0.780339f, 0.776476f, 0.772613f,
		0.76875f, 0.764887f, 0.761024f, 0.757161f, 0.753298f, 0.749434f,
		0.745571f, 0.741708f, 0.737845f, 0.733982f, 0.730119f, 0.726256f,
		0.722393f, 0.71853f, 0.714667f, 0.710804f, 0.706941f, 0.703078f,
		0.699215f, 0.695352f, 0.691489f, 0.687625f, 0.683762f, 0.679899f,
		0.676036f, 0.672173f, 0.66831f, 0.664447f, 0.660584f, 0.656721f,
		0.652858f, 0.648995f, 0.645132f, 0.641269f, 0.637406f, 0.633543f,
		0.629679f, 0.625816f, 0.621953f, 0.61809f, 0.614227f, 0.610364f,
		0.606501f, 0.602638f, 0.598775f, 0.594912f, 0.591049f, 0.587186f,
		0.583323f, 0.57946f, 0.575597f, 0.571734f, 0.56787f, 0.564007f,
		0.560144f, 0.556281f, 0.552418f, 0.548555f, 0.544692f, 0.540829f,
		0.536966f, 0.533103f, 0.52924f, 0.525377f, 0.521514f, 0.517651f,
		0.513788f, 0.509925f, 0.506061f, 0.502198f, 0.498335f, 0.494472f,
		0.490609f, 0.486746f, 0.482883f, 0.47902f, 0.475157f, 0.471294f,
		0.467431f, 0.463568f, 0.459705f, 0.455842f, 0.451979f, 0.448116f,
		0.444252f, 0.440389f, 0.436526f, 0.432663f, 0.4288f, 0.424937f,
		0.421074f, 0.417211f, 0.413348f, 0.409485f, 0.405622f, 0.401759f,
		0.397896f, 0.394033f, 0.39017f, 0.386306f, 0.382443f, 0.37858f,
		0.374717f, 0.370854f, 0.366991f, 0.363128f, 0.359265f, 0.355402f,
		0.351539f, 0.347676f, 0.343813f, 0.33995f, 0.336087f, 0.332224f,
		0.32836f, 0.324497f, 0.320634f, 0.316771f, 0.312908f, 0.309045f,
		0.305182f, 0.301319f, 0.297456f, 0.293593f, 0.28973f, 0.285867f,
		0.282004f, 0.278141f, 0.274278f, 0.270414f, 0.266551f, 0.262688f,
		0.258825f, 0.254962f, 0.251099f, 0.247236f, 0.243373f, 0.23951f,
		0.235647f, 0.231784f, 0.227921f, 0.224058f, 0.220195f, 0.216332f,
		0.212469f, 0.208605f, 0.204742f, 0.200879f, 0.197016f, 0.193153f,
		0.18929f, 0.185427f, 0.181564f, 0.177701f, 0.173838f, 0.169975f,
		0.166112f, 0.162249f, 0.158386f, 0.154522f, 0.15066f, 0.146796f,
		0.142933f, 0.13907f, 0.135207f, 0.131344f, 0.127481f, 0.123618f,
		0.119755f, 0.115892f, 0.112029f, 0.108166f, 0.104303f, 0.10044f,
		0.0965766f, 0.0927134f, 0.0888504f, 0.0849874f, 0.0811243f, 0.0772613f,
		0.0733981f, 0.0695351f, 0.065672f, 0.0618089f, 0.057946f, 0.0540828f,
		0.0502198f, 0.0463567f, 0.0424936f, 0.0386305f, 0.0347675f, 0.0309045f,
		0.0270414f, 0.0231783f, 0.0193152f, 0.0154523f, 0.0115891f, 0.00772613f,
		0.00386304f, 0.f
	};
};

using table7_t = wrap::data<math::table, 
                            data::embedded::table<table7_t_data>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::fmod<NV>, 
                                   table7_t>;
using table8_t = wrap::data<math::table, 
                            data::external::table<1>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   table8_t>;
using table9_t = table8_t;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::fmod<NV>, 
                                   table9_t>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain21_t<NV>>, 
                                    chain118_t<NV>, 
                                    chain22_t<NV>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>, 
                                    chain132_t<NV>, 
                                    chain25_t<NV>, 
                                    chain26_t<NV>, 
                                    chain27_t<NV>, 
                                    chain28_t<NV>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>>;

using chain178_t = chain90_t;
using oscilloscope1_t = wrap::data<analyse::oscilloscope, 
                                   data::external::displaybuffer<1>>;

template <int NV> using peak34_mod = peak15_mod<NV>;

template <int NV>
using peak34_t = wrap::mod<peak34_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<2, oscilloscope1_t>, 
                                   peak34_t<NV>, 
                                   math::clear<NV>>;

template <int NV>
using split32_t = container::split<parameter::empty, 
                                   wrap::fix<2, routing::send<NV, stereo_cable<NV>>>, 
                                   chain46_t<NV>>;

template <int NV>
using chain179_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::sig2mod<NV>>, 
                                    split32_t<NV>, 
                                    math::clear<NV>>;

template <int NV>
using split31_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain178_t>, 
                                   chain179_t<NV>>;

template <int NV>
using chain177_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split31_t<NV>>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch27_t<NV>>, 
                                   core::gain<NV>, 
                                   branch5_t<NV>, 
                                   core::mono2stereo, 
                                   branch4_t<NV>, 
                                   chain177_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain17_t<NV>>, 
                                  chain18_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split2_t<NV>>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain2_t<NV>>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, chain8_t<NV>>, 
                                 filters::one_pole<NV>>;

template <int NV> using chain152_t = chain235_t<NV>;

template <int NV> using chain153_t = chain235_t<NV>;

template <int NV> using chain269_t = chain235_t<NV>;

template <int NV> using chain176_t = chain235_t<NV>;

template <int NV> using chain226_t = chain235_t<NV>;
template <int NV>
using branch26_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain152_t<NV>>, 
                                     chain153_t<NV>, 
                                     chain269_t<NV>, 
                                     chain176_t<NV>, 
                                     chain226_t<NV>>;

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<2>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table1_t<NV>, 0>, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<cable_pack_t<NV>, 0>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync4_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                                control::tempo_sync<NV>>;
using peak4_t = peak21_t;

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
                                   input_toggle_t<NV>, 
                                   math::clear<NV>, 
                                   ahdsr_t<NV>, 
                                   math::add<NV>>;
using cable_table4_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<4>>;
using cable_table3_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<5>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_table1_t<NV>, 
                                   cable_table4_t, 
                                   cable_table3_t, 
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

DECLARE_PARAMETER_RANGE(smoothed_parameter_mod_0Range, 
                        0., 
                        0.999997);

template <int NV>
using smoothed_parameter_mod_0 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_1Range, 
                             0., 
                             0.999997, 
                             0.00195312);

template <int NV>
using smoothed_parameter_mod_1 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_2Range, 
                             0., 
                             0.999997, 
                             0.00390625);

template <int NV>
using smoothed_parameter_mod_2 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_2Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_3Range, 
                             0., 
                             0.999997, 
                             0.0078125);

template <int NV>
using smoothed_parameter_mod_3 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_3Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_4Range, 
                             0., 
                             0.999997, 
                             0.015625);

template <int NV>
using smoothed_parameter_mod_4 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_4Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_5Range, 
                             0., 
                             0.999997, 
                             0.0625);

template <int NV>
using smoothed_parameter_mod_5 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_5Range>;

DECLARE_PARAMETER_RANGE(smoothed_parameter_mod_6Range, 
                        0., 
                        0.999997);

template <int NV>
using smoothed_parameter_mod_6 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_6Range>;

DECLARE_PARAMETER_RANGE(smoothed_parameter_mod_8Range, 
                        0., 
                        0.999997);

template <int NV>
using smoothed_parameter_mod_8 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_8Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter_mod_9Range, 
                             0., 
                             0.999997, 
                             0.03125);

template <int NV>
using smoothed_parameter_mod_9 = parameter::from0To1<math::add<NV>, 
                                                     0, 
                                                     smoothed_parameter_mod_9Range>;

template <int NV>
using smoothed_parameter_mod = parameter::chain<ranges::Identity, 
                                                smoothed_parameter_mod_0<NV>, 
                                                smoothed_parameter_mod_1<NV>, 
                                                smoothed_parameter_mod_2<NV>, 
                                                smoothed_parameter_mod_3<NV>, 
                                                smoothed_parameter_mod_4<NV>, 
                                                smoothed_parameter_mod_5<NV>, 
                                                smoothed_parameter_mod_6<NV>, 
                                                parameter::plain<math::add<NV>, 0>, 
                                                smoothed_parameter_mod_8<NV>, 
                                                smoothed_parameter_mod_9<NV>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod<NV>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<smoothed_parameter_t<NV>, 0>, 
                                  parameter::plain<cable_table3_t, 0>>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   ramp_t<NV>, 
                                   branch3_t<NV>, 
                                   peak2_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain47_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, math::add<NV>>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>, 
                                    math::add<NV>>;
template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;
template <int NV>
using file_player2_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<2>>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<2, file_player_t<NV>>, 
                                     file_player2_t<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<filters::one_pole<NV>>>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, peak4_t>, 
                                  split3_t<NV>, 
                                  pma3_t<NV>, 
                                  smoothed_parameter_t<NV>, 
                                  branch1_t<NV>, 
                                  branch14_t<NV>, 
                                  chain19_t<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain9_t<NV>>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, split1_t<NV>>>;

template <int NV>
using frame2_block1_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, chain7_t<NV>>>;

template <int NV>
using frame2_block1_t = wrap::frame<2, frame2_block1_t_<NV>>;

using chain255_t = chain90_t;

template <int NV> using peak31_mod = peak15_mod<NV>;

template <int NV>
using peak31_t = wrap::mod<peak31_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sig2mod<NV>>, 
                                   peak31_t<NV>>;

template <int NV>
using split36_t = container::split<parameter::empty, 
                                   wrap::fix<2, routing::send<NV, stereo_cable<NV>>>, 
                                   chain20_t<NV>>;

template <int NV>
using chain256_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split36_t<NV>>>;

template <int NV>
using split35_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain255_t>, 
                                   chain256_t<NV>>;

template <int NV>
using chain254_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split35_t<NV>>>;

template <int NV>
using chain180_t = container::chain<parameter::empty, 
                                    wrap::fix<2, branch26_t<NV>>, 
                                    wrap::no_process<filters::one_pole<NV>>, 
                                    core::gain<NV>, 
                                    core::gain<NV>, 
                                    tempo_sync4_t<NV>, 
                                    frame2_block1_t<NV>, 
                                    chain254_t<NV>>;

template <int NV> using chain250_t = chain235_t<NV>;

template <int NV> using chain251_t = chain235_t<NV>;

template <int NV> using chain252_t = chain235_t<NV>;

template <int NV> using chain253_t = chain235_t<NV>;

template <int NV> using chain270_t = chain235_t<NV>;
template <int NV>
using branch30_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain250_t<NV>>, 
                                     chain251_t<NV>, 
                                     chain252_t<NV>, 
                                     chain253_t<NV>, 
                                     chain270_t<NV>>;
using peak10_t = peak21_t;

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<3>>;

template <int NV>
using cable_pack1_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::sliderpack<1>>;

template <int NV>
using ramp1_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<cable_table2_t<NV>, 0>, 
                                   parameter::plain<cable_pack1_t<NV>, 0>>;

template <int NV>
using ramp1_t = wrap::mod<ramp1_mod<NV>, 
                          wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync3_t = wrap::mod<parameter::plain<ramp1_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV> using ahdsr2_multimod = ahdsr_multimod<NV>;

template <int NV>
using ahdsr2_t = wrap::no_data<envelope::ahdsr<NV, ahdsr2_multimod<NV>>>;
template <int NV>
using input_toggle1_t = control::input_toggle<NV, 
                                              parameter::plain<ahdsr2_t<NV>, 8>>;
template <int NV>
using peak11_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 2>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>, 
                                   math::rect<NV>, 
                                   peak11_t<NV>, 
                                   math::clear<NV>, 
                                   input_toggle1_t<NV>, 
                                   ahdsr2_t<NV>, 
                                   math::add<NV>>;
using cable_table5_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<6>>;
using cable_table6_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<7>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_table2_t<NV>, 
                                   cable_table5_t, 
                                   cable_table6_t, 
                                   math::add<NV>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   cable_pack1_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain50_t<NV>>, 
                                    chain54_t<NV>, 
                                    chain55_t<NV>>;

template <int NV>
using smoothed_parameter3_mod_0 = smoothed_parameter_mod_0<NV>;

template <int NV>
using smoothed_parameter3_mod_1 = smoothed_parameter_mod_1<NV>;

template <int NV>
using smoothed_parameter3_mod_2 = smoothed_parameter_mod_2<NV>;

template <int NV>
using smoothed_parameter3_mod_3 = smoothed_parameter_mod_3<NV>;

template <int NV>
using smoothed_parameter3_mod_4 = smoothed_parameter_mod_4<NV>;

template <int NV>
using smoothed_parameter3_mod_5 = smoothed_parameter_mod_5<NV>;

template <int NV>
using smoothed_parameter3_mod_6 = smoothed_parameter_mod_6<NV>;

template <int NV>
using smoothed_parameter3_mod_8 = smoothed_parameter_mod_8<NV>;

template <int NV>
using smoothed_parameter3_mod_9 = smoothed_parameter_mod_9<NV>;

template <int NV>
using smoothed_parameter3_mod = parameter::chain<ranges::Identity, 
                                                 smoothed_parameter3_mod_0<NV>, 
                                                 smoothed_parameter3_mod_1<NV>, 
                                                 smoothed_parameter3_mod_2<NV>, 
                                                 smoothed_parameter3_mod_3<NV>, 
                                                 smoothed_parameter3_mod_4<NV>, 
                                                 smoothed_parameter3_mod_5<NV>, 
                                                 smoothed_parameter3_mod_6<NV>, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 smoothed_parameter3_mod_8<NV>, 
                                                 smoothed_parameter3_mod_9<NV>>;

template <int NV>
using smoothed_parameter3_t = wrap::mod<smoothed_parameter3_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<smoothed_parameter3_t<NV>, 0>, 
                                  parameter::plain<cable_table6_t, 0>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak12_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, tempo_sync3_t<NV>>, 
                                   ramp1_t<NV>, 
                                   branch7_t<NV>, 
                                   peak12_t<NV>>;

template <int NV>
using modchain14_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, chain49_t<NV>>>;

template <int NV>
using modchain14_t = wrap::control_rate<modchain14_t_<NV>>;

template <int NV>
using split18_t = container::split<parameter::empty, 
                                   wrap::fix<2, modchain14_t<NV>>>;
template <int NV> using branch8_t = branch1_t<NV>;
template <int NV>
using file_player1_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using file_player3_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<3>>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<2, file_player1_t<NV>>, 
                                     file_player3_t<NV>>;

template <int NV> using chain35_t = chain19_t<NV>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<2, peak10_t>, 
                                   split18_t<NV>, 
                                   pma2_t<NV>, 
                                   smoothed_parameter3_t<NV>, 
                                   branch8_t<NV>, 
                                   branch15_t<NV>, 
                                   chain35_t<NV>>;

template <int NV>
using split17_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain34_t<NV>>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split17_t<NV>>>;

template <int NV>
using frame2_block2_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, chain33_t<NV>>>;

template <int NV>
using frame2_block2_t = wrap::frame<2, frame2_block2_t_<NV>>;

using chain100_t = chain90_t;

template <int NV> using peak19_mod = peak15_mod<NV>;

template <int NV>
using peak19_t = wrap::mod<peak19_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sig2mod<NV>>, 
                                   peak19_t<NV>>;

template <int NV>
using split25_t = container::split<parameter::empty, 
                                   wrap::fix<2, routing::send<NV, stereo_cable<NV>>>, 
                                   chain84_t<NV>>;

template <int NV>
using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split25_t<NV>>>;

template <int NV>
using split24_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain100_t>, 
                                   chain101_t<NV>>;

template <int NV>
using chain95_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split24_t<NV>>>;

template <int NV>
using chain248_t = container::chain<parameter::empty, 
                                    wrap::fix<2, branch30_t<NV>>, 
                                    filters::one_pole<NV>, 
                                    core::gain<NV>, 
                                    core::gain<NV>, 
                                    frame2_block2_t<NV>, 
                                    chain95_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain180_t<NV>, 
                                 chain248_t<NV>>;

template <int NV>
using sliderbank_multimod = parameter::list<parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                            parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                            parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                            parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<2>>;

template <int NV>
using split39_t = container::split<parameter::empty, 
                                   wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                   routing::receive<NV, stereo_cable<NV>>, 
                                   routing::receive<NV, stereo_cable<NV>>, 
                                   routing::receive<NV, stereo_cable<NV>>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::svf<NV>>>;

template <int NV> using chain43_t = chain41_t<NV>;

template <int NV> using chain42_t = chain41_t<NV>;

template <int NV> using chain44_t = chain41_t<NV>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::one_pole<NV>>, 
                                   filters::allpass<NV>>;
template <int NV>
using stereo_frame_cable = cable::frame<NV, 2>;

template <int NV>
using converter6_t = control::converter<parameter::plain<jdsp::jdelay<NV>, 1>, 
                                        conversion_logic::freq2ms>;
template <int NV>
using converter7_t = control::converter<parameter::plain<converter6_t<NV>, 0>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using midi_t = wrap::mod<parameter::plain<converter7_t<NV>, 0>, 
                         control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<2, midi_t<NV>>, 
                                   converter7_t<NV>, 
                                   converter6_t<NV>, 
                                   jdsp::jdelay<NV>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<NV, stereo_frame_cable<NV>>>, 
                                   chain51_t<NV>, 
                                   filters::one_pole<NV>, 
                                   routing::send<NV, stereo_frame_cable<NV>>>;

template <int NV>
using frame2_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain39_t<NV>>>;

template <int NV>
using frame2_block_t = wrap::frame<2, frame2_block_t_<NV>>;

template <int NV> using converter9_t = converter6_t<NV>;
template <int NV>
using converter8_t = control::converter<parameter::plain<converter9_t<NV>, 0>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using midi1_t = wrap::mod<parameter::plain<converter8_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<2, midi1_t<NV>>, 
                                   converter8_t<NV>, 
                                   converter9_t<NV>, 
                                   jdsp::jdelay<NV>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                   chain56_t<NV>, 
                                   filters::one_pole<NV>, 
                                   routing::send<NV, stereo_cable<NV>>>;

template <int NV> using converter17_t = converter6_t<NV>;
template <int NV>
using converter16_t = control::converter<parameter::plain<converter17_t<NV>, 0>, 
                                         conversion_logic::midi2freq>;

template <int NV>
using chain125_t = container::chain<parameter::empty, 
                                    wrap::fix<2, converter16_t<NV>>, 
                                    converter17_t<NV>, 
                                    jdsp::jdelay<NV>>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                    chain125_t<NV>, 
                                    filters::one_pole<NV>, 
                                    routing::send<NV, stereo_cable<NV>>>;

template <int NV> using converter19_t = converter6_t<NV>;
template <int NV>
using converter18_t = control::converter<parameter::plain<converter19_t<NV>, 0>, 
                                         conversion_logic::midi2freq>;

template <int NV>
using chain155_t = container::chain<parameter::empty, 
                                    wrap::fix<2, converter18_t<NV>>, 
                                    converter19_t<NV>, 
                                    jdsp::jdelay<NV>>;

template <int NV>
using chain126_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                    chain155_t<NV>, 
                                    filters::one_pole<NV>, 
                                    routing::send<NV, stereo_cable<NV>>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain41_t<NV>>, 
                                    chain43_t<NV>, 
                                    chain42_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>, 
                                    frame2_block_t<NV>, 
                                    chain40_t<NV>, 
                                    chain123_t<NV>, 
                                    chain126_t<NV>>;

using chain158_t = chain90_t;

template <int NV> using peak32_mod = peak15_mod<NV>;

template <int NV>
using peak32_t = wrap::mod<peak32_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain249_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::sig2mod<NV>>, 
                                    peak32_t<NV>>;

template <int NV>
using split28_t = container::split<parameter::empty, 
                                   wrap::fix<2, routing::send<NV, stereo_cable<NV>>>, 
                                   chain249_t<NV>>;

template <int NV>
using chain159_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split28_t<NV>>, 
                                    math::clear<NV>>;

template <int NV>
using split27_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain158_t>, 
                                   chain159_t<NV>>;

template <int NV>
using chain157_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split27_t<NV>>>;

template <int NV>
using chain154_t = container::chain<parameter::empty, 
                                    wrap::fix<2, sliderbank_t<NV>>, 
                                    split39_t<NV>, 
                                    branch6_t<NV>, 
                                    chain157_t<NV>, 
                                    core::gain<NV>, 
                                    jdsp::jpanner<NV>>;

template <int NV>
using sliderbank1_multimod = parameter::list<parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                             parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                             parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                             parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>, 
                                             parameter::plain<routing::receive<NV, stereo_cable<NV>>, 0>>;

template <int NV>
using sliderbank1_t = wrap::data<control::sliderbank<sliderbank1_multimod<NV>>, 
                                 data::external::sliderpack<3>>;

template <int NV>
using split40_t = container::split<parameter::empty, 
                                   wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                   routing::receive<NV, stereo_cable<NV>>, 
                                   routing::receive<NV, stereo_cable<NV>>, 
                                   routing::receive<NV, stereo_cable<NV>>, 
                                   routing::receive<NV, stereo_cable<NV>>>;

template <int NV> using chain168_t = chain41_t<NV>;

template <int NV> using chain169_t = chain41_t<NV>;

template <int NV> using chain170_t = chain41_t<NV>;

template <int NV> using chain171_t = chain41_t<NV>;

template <int NV>
using chain172_t = container::chain<parameter::empty, 
                                    wrap::fix<2, filters::allpass<NV>>>;

template <int NV> using converter11_t = converter6_t<NV>;
template <int NV>
using converter10_t = control::converter<parameter::plain<converter11_t<NV>, 0>, 
                                         conversion_logic::midi2freq>;
template <int NV>
using midi2_t = wrap::mod<parameter::plain<converter10_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<2, midi2_t<NV>>, 
                                   converter10_t<NV>, 
                                   converter11_t<NV>, 
                                   jdsp::jdelay<NV>>;

template <int NV> using converter13_t = converter6_t<NV>;
template <int NV>
using converter12_t = control::converter<parameter::plain<converter13_t<NV>, 0>, 
                                         conversion_logic::midi2freq>;
template <int NV>
using midi3_t = wrap::mod<parameter::plain<converter12_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain92_t = container::chain<parameter::empty, 
                                   wrap::fix<2, midi3_t<NV>>, 
                                   converter12_t<NV>, 
                                   converter13_t<NV>, 
                                   jdsp::jdelay<NV>>;

template <int NV>
using chain166_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                    chain61_t<NV>, 
                                    chain92_t<NV>, 
                                    filters::one_pole<NV>, 
                                    routing::send<NV, stereo_cable<NV>>>;

template <int NV> using converter15_t = converter6_t<NV>;
template <int NV>
using converter14_t = control::converter<parameter::plain<converter15_t<NV>, 0>, 
                                         conversion_logic::midi2freq>;
template <int NV>
using midi4_t = wrap::mod<parameter::plain<converter14_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<2, midi4_t<NV>>, 
                                   converter14_t<NV>, 
                                   converter15_t<NV>, 
                                   jdsp::jdelay<NV>>;

template <int NV>
using chain167_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                    chain94_t<NV>, 
                                    filters::one_pole<NV>, 
                                    routing::send<NV, stereo_cable<NV>>>;

template <int NV> using converter21_t = converter6_t<NV>;
template <int NV>
using converter20_t = control::converter<parameter::plain<converter21_t<NV>, 0>, 
                                         conversion_logic::midi2freq>;

template <int NV>
using chain156_t = container::chain<parameter::empty, 
                                    wrap::fix<2, converter20_t<NV>>, 
                                    converter21_t<NV>, 
                                    jdsp::jdelay<NV>>;

template <int NV>
using chain232_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                    chain156_t<NV>, 
                                    filters::one_pole<NV>, 
                                    routing::send<NV, stereo_cable<NV>>>;

template <int NV> using converter23_t = converter6_t<NV>;
template <int NV>
using converter22_t = control::converter<parameter::plain<converter23_t<NV>, 0>, 
                                         conversion_logic::midi2freq>;

template <int NV>
using chain234_t = container::chain<parameter::empty, 
                                    wrap::fix<2, converter22_t<NV>>, 
                                    converter23_t<NV>, 
                                    jdsp::jdelay<NV>>;

template <int NV>
using chain233_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<NV, stereo_cable<NV>>>, 
                                    chain234_t<NV>, 
                                    filters::one_pole<NV>, 
                                    routing::send<NV, stereo_cable<NV>>>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain168_t<NV>>, 
                                     chain169_t<NV>, 
                                     chain170_t<NV>, 
                                     chain171_t<NV>, 
                                     chain172_t<NV>, 
                                     chain166_t<NV>, 
                                     chain167_t<NV>, 
                                     chain232_t<NV>, 
                                     chain233_t<NV>>;

using chain174_t = chain90_t;

template <int NV> using peak33_mod = peak15_mod<NV>;

template <int NV>
using peak33_t = wrap::mod<peak33_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain257_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::sig2mod<NV>>, 
                                    peak33_t<NV>>;

template <int NV>
using split30_t = container::split<parameter::empty, 
                                   wrap::fix<2, routing::send<NV, stereo_cable<NV>>>, 
                                   chain257_t<NV>>;

template <int NV>
using chain175_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split30_t<NV>>, 
                                    math::clear<NV>>;

template <int NV>
using split29_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain174_t>, 
                                   chain175_t<NV>>;

template <int NV>
using chain173_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split29_t<NV>>>;

template <int NV>
using chain160_t = container::chain<parameter::empty, 
                                    wrap::fix<2, sliderbank1_t<NV>>, 
                                    split40_t<NV>, 
                                    branch13_t<NV>, 
                                    chain173_t<NV>, 
                                    core::gain<NV>, 
                                    jdsp::jpanner<NV>>;

template <int NV>
using split26_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain154_t<NV>>, 
                                   chain160_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, split8_t<NV>>, 
                                       split_t<NV>, 
                                       math::clear<NV>, 
                                       split26_t<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

using ahdsr1_multimod = parameter::list<parameter::empty, 
                                        parameter::plain<envelope::voice_manager, 0>>;

template <int NV>
using ahdsr1_t = wrap::no_data<envelope::ahdsr<NV, ahdsr1_multimod>>;

namespace Sm2_t_parameters
{
// Parameter list for Sm2_impl::Sm2_t --------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(OscSt1_InputRange, 
                             -24., 
                             24., 
                             1.);

template <int NV>
using OscSt1 = parameter::chain<OscSt1_InputRange, 
                                parameter::plain<Sm2_impl::minmax_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(OscCent1_InputRange, 
                        -1., 
                        1.);

template <int NV>
using OscCent1 = parameter::chain<OscCent1_InputRange, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV>
using Oscfm1 = parameter::chain<ranges::Identity, 
                                parameter::plain<Sm2_impl::pma_unscaled3_t<NV>, 1>, 
                                parameter::plain<Sm2_impl::pma_t<NV>, 1>>;

template <int NV>
using OscMod1 = parameter::chain<ranges::Identity, 
                                 parameter::plain<Sm2_impl::global_mod1_t<NV>, 4>, 
                                 parameter::plain<Sm2_impl::global_mod3_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE_STEP(OscTempo1_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using OscTempo1 = parameter::chain<OscTempo1_InputRange, 
                                   parameter::plain<Sm2_impl::global_mod3_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(OscFmSrc1_InputRange, 
                             1., 
                             6., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(OscFmSrc1_0Range, 
                             0., 
                             5., 
                             1.);

template <int NV>
using OscFmSrc1_0 = parameter::from0To1<Sm2_impl::branch9_t<NV>, 
                                        0, 
                                        OscFmSrc1_0Range>;

template <int NV>
using OscFmSrc1_1 = parameter::from0To1<Sm2_impl::branch10_t<NV>, 
                                        0, 
                                        OscFmSrc1_0Range>;

template <int NV>
using OscFmSrc1 = parameter::chain<OscFmSrc1_InputRange, 
                                   OscFmSrc1_0<NV>, 
                                   OscFmSrc1_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(OscPitchSrc1_InputRange, 
                             1., 
                             17., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(OscPitchSrc1_0Range, 
                             0., 
                             16., 
                             1.);

template <int NV>
using OscPitchSrc1_0 = parameter::from0To1<Sm2_impl::global_mod1_t<NV>, 
                                           0, 
                                           OscPitchSrc1_0Range>;

template <int NV>
using OscPitchSrc1_1 = parameter::from0To1<Sm2_impl::global_mod3_t<NV>, 
                                           0, 
                                           OscPitchSrc1_0Range>;

template <int NV>
using OscPitchSrc1 = parameter::chain<OscPitchSrc1_InputRange, 
                                      OscPitchSrc1_0<NV>, 
                                      OscPitchSrc1_1<NV>>;

template <int NV>
using filePos1 = parameter::chain<ranges::Identity, 
                                  parameter::plain<Sm2_impl::cable_table4_t, 0>, 
                                  parameter::plain<Sm2_impl::pma3_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(FilePosQuant1_InputRange, 
                             1., 
                             10., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FilePosQuant1_0Range, 
                             0., 
                             9., 
                             1.);

template <int NV>
using FilePosQuant1_0 = parameter::from0To1<Sm2_impl::branch1_t<NV>, 
                                            0, 
                                            FilePosQuant1_0Range>;

template <int NV>
using FilePosQuant1 = parameter::chain<FilePosQuant1_InputRange, 
                                       FilePosQuant1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileInputGainSrc1_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using FileInputGainSrc1_0 = parameter::from0To1<Sm2_impl::global_mod6_t<NV>, 
                                                0, 
                                                OscPitchSrc1_0Range>;

template <int NV>
using FileInputGainSrc1 = parameter::chain<FileInputGainSrc1_InputRange, 
                                           FileInputGainSrc1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMode1_InputRange, 
                             1., 
                             9., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FilterMode1_0Range, 
                             0., 
                             8., 
                             1.);

template <int NV>
using FilterMode1_0 = parameter::from0To1<Sm2_impl::branch6_t<NV>, 
                                          0, 
                                          FilterMode1_0Range>;

template <int NV>
using FilterMode1 = parameter::chain<FilterMode1_InputRange, FilterMode1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterCutSrc1_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using FilterCutSrc1_0 = parameter::from0To1<Sm2_impl::global_mod9_t<NV>, 
                                            0, 
                                            OscPitchSrc1_0Range>;

template <int NV>
using FilterCutSrc1 = parameter::chain<FilterCutSrc1_InputRange, 
                                       FilterCutSrc1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterModMode1_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using FilterModMode1_0 = parameter::from0To1<Sm2_impl::branch21_t<NV>, 
                                             0, 
                                             OscFmSrc1_0Range>;

template <int NV>
using FilterModMode1 = parameter::chain<FilterModMode1_InputRange, 
                                        FilterModMode1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(VcaGainSrc1_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using VcaGainSrc1_0 = parameter::from0To1<Sm2_impl::global_mod10_t<NV>, 
                                          0, 
                                          OscPitchSrc1_0Range>;

template <int NV>
using VcaGainSrc1 = parameter::chain<VcaGainSrc1_InputRange, VcaGainSrc1_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(Res1_InputRange, 
                             0., 
                             1., 
                             0.264718);
DECLARE_PARAMETER_RANGE_SKEW(Res1_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using Res1_0 = parameter::from0To1<filters::one_pole<NV>, 
                                   1, 
                                   Res1_0Range>;

template <int NV> using Res1_1 = Res1_0<NV>;

template <int NV>
using Res1_2 = parameter::from0To1<filters::svf<NV>, 
                                   1, 
                                   Res1_0Range>;

template <int NV> using Res1_3 = Res1_2<NV>;

template <int NV> using Res1_4 = Res1_2<NV>;

template <int NV> using Res1_5 = Res1_2<NV>;

template <int NV>
using Res1_6 = parameter::from0To1<filters::allpass<NV>, 
                                   1, 
                                   Res1_0Range>;

DECLARE_PARAMETER_RANGE(Res1_7Range, 
                        0., 
                        0.8);

template <int NV>
using Res1_7 = parameter::from0To1<routing::receive<NV, stereo_frame_cable<NV>>, 
                                   0, 
                                   Res1_7Range>;

template <int NV>
using Res1_8 = parameter::from0To1<routing::receive<NV, stereo_cable<NV>>, 
                                   0, 
                                   Res1_7Range>;

template <int NV> using Res1_9 = Res1_8<NV>;

template <int NV> using Res1_10 = Res1_8<NV>;

template <int NV>
using Res1 = parameter::chain<Res1_InputRange, 
                              Res1_0<NV>, 
                              Res1_1<NV>, 
                              Res1_2<NV>, 
                              Res1_3<NV>, 
                              Res1_4<NV>, 
                              Res1_5<NV>, 
                              Res1_6<NV>, 
                              Res1_7<NV>, 
                              Res1_8<NV>, 
                              Res1_9<NV>, 
                              Res1_10<NV>>;

DECLARE_PARAMETER_RANGE_STEP(VcaFmSrc1_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using VcaFmSrc1_0 = parameter::from0To1<Sm2_impl::branch22_t<NV>, 
                                        0, 
                                        OscFmSrc1_0Range>;

template <int NV>
using VcaFmSrc1 = parameter::chain<VcaFmSrc1_InputRange, VcaFmSrc1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(OscSt2_InputRange, 
                             -24., 
                             24., 
                             1.);

template <int NV>
using OscSt2 = parameter::chain<OscSt2_InputRange, 
                                parameter::plain<Sm2_impl::minmax2_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(OscCent2_InputRange, 
                        -1., 
                        1.);

template <int NV>
using OscCent2 = parameter::chain<OscCent2_InputRange, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV>
using Oscfm2 = parameter::chain<ranges::Identity, 
                                parameter::plain<Sm2_impl::pma_unscaled15_t<NV>, 1>, 
                                parameter::plain<Sm2_impl::pma1_t<NV>, 1>>;

template <int NV>
using OscMod2 = parameter::chain<ranges::Identity, 
                                 parameter::plain<Sm2_impl::global_mod_t<NV>, 4>, 
                                 parameter::plain<Sm2_impl::global_mod13_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE_STEP(OscFmSrc2_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using OscFmSrc2_0 = parameter::from0To1<Sm2_impl::branch12_t<NV>, 
                                        0, 
                                        OscFmSrc1_0Range>;

template <int NV>
using OscFmSrc2_1 = parameter::from0To1<Sm2_impl::branch11_t<NV>, 
                                        0, 
                                        OscFmSrc1_0Range>;

template <int NV>
using OscFmSrc2 = parameter::chain<OscFmSrc2_InputRange, 
                                   OscFmSrc2_0<NV>, 
                                   OscFmSrc2_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMode2_InputRange, 
                             1., 
                             9., 
                             1.);
template <int NV>
using FilterMode2_0 = parameter::from0To1<Sm2_impl::branch13_t<NV>, 
                                          0, 
                                          FilterMode1_0Range>;

template <int NV>
using FilterMode2 = parameter::chain<FilterMode2_InputRange, FilterMode2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterCutSrc2_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using FilterCutSrc2_0 = parameter::from0To1<Sm2_impl::global_mod11_t<NV>, 
                                            0, 
                                            OscPitchSrc1_0Range>;

template <int NV>
using FilterCutSrc2 = parameter::chain<FilterCutSrc2_InputRange, 
                                       FilterCutSrc2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterFmdSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using FilterFmdSrc_0 = parameter::from0To1<Sm2_impl::branch23_t<NV>, 
                                           0, 
                                           OscFmSrc1_0Range>;

template <int NV>
using FilterFmdSrc = parameter::chain<FilterFmdSrc_InputRange, 
                                      FilterFmdSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(VcaGainSrc2_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using VcaGainSrc2_0 = parameter::from0To1<Sm2_impl::global_mod12_t<NV>, 
                                          0, 
                                          OscPitchSrc1_0Range>;

template <int NV>
using VcaGainSrc2 = parameter::chain<VcaGainSrc2_InputRange, VcaGainSrc2_0<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(Res2_InputRange, 
                             0., 
                             1., 
                             0.264718);
template <int NV> using Res2_0 = Res1_0<NV>;

template <int NV> using Res2_1 = Res1_8<NV>;

template <int NV> using Res2_2 = Res1_8<NV>;

template <int NV> using Res2_3 = Res1_2<NV>;

template <int NV> using Res2_4 = Res1_2<NV>;

template <int NV> using Res2_5 = Res1_2<NV>;

template <int NV> using Res2_6 = Res1_2<NV>;

template <int NV> using Res2_7 = Res1_6<NV>;

template <int NV> using Res2_8 = Res1_0<NV>;

template <int NV> using Res2_9 = Res1_8<NV>;

template <int NV> using Res2_10 = Res1_8<NV>;

template <int NV>
using Res2 = parameter::chain<Res2_InputRange, 
                              Res2_0<NV>, 
                              Res2_1<NV>, 
                              Res2_2<NV>, 
                              Res2_3<NV>, 
                              Res2_4<NV>, 
                              Res2_5<NV>, 
                              Res2_6<NV>, 
                              Res2_7<NV>, 
                              Res2_8<NV>, 
                              Res2_9<NV>, 
                              Res2_10<NV>>;

DECLARE_PARAMETER_RANGE_STEP(VcaFmSrc2_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using VcaFmSrc2_0 = parameter::from0To1<Sm2_impl::branch25_t<NV>, 
                                        0, 
                                        OscFmSrc1_0Range>;

template <int NV>
using VcaFmSrc2 = parameter::chain<VcaFmSrc2_InputRange, VcaFmSrc2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(OscShapeModSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using OscShapeModSrc_0 = parameter::from0To1<Sm2_impl::global_mod4_t<NV>, 
                                             0, 
                                             OscPitchSrc1_0Range>;

template <int NV>
using OscShapeModSrc = parameter::chain<OscShapeModSrc_InputRange, 
                                        OscShapeModSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(OscShapeFmSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using OscShapeFmSrc_0 = parameter::from0To1<Sm2_impl::branch16_t<NV>, 
                                            0, 
                                            OscFmSrc1_0Range>;

template <int NV>
using OscShapeFmSrc = parameter::chain<OscShapeFmSrc_InputRange, 
                                       OscShapeFmSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Osc2InputGainFmSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using Osc2InputGainFmSrc_0 = parameter::from0To1<Sm2_impl::branch17_t<NV>, 
                                                 0, 
                                                 OscFmSrc1_0Range>;

template <int NV>
using Osc2InputGainFmSrc = parameter::chain<Osc2InputGainFmSrc_InputRange, 
                                            Osc2InputGainFmSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileInFmSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using FileInFmSrc_0 = parameter::from0To1<Sm2_impl::branch20_t<NV>, 
                                          0, 
                                          OscFmSrc1_0Range>;

template <int NV>
using FileInFmSrc = parameter::chain<FileInFmSrc_InputRange, FileInFmSrc_0<NV>>;

template <int NV>
using FileInOffset = parameter::from0To1<core::gain<NV>, 
                                         0, 
                                         Sm2_impl::peak39_modRange>;

DECLARE_PARAMETER_RANGE_STEP(oscShapeMode1_InputRange, 
                             1., 
                             12., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(oscShapeMode1_0Range, 
                             0., 
                             11., 
                             1.);

template <int NV>
using oscShapeMode1_0 = parameter::from0To1<Sm2_impl::branch_t<NV>, 
                                            0, 
                                            oscShapeMode1_0Range>;

template <int NV>
using oscShapeMode1 = parameter::chain<oscShapeMode1_InputRange, 
                                       oscShapeMode1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(oscShapeMode2_InputRange, 
                             1., 
                             12., 
                             1.);
template <int NV>
using oscShapeMode2_0 = parameter::from0To1<Sm2_impl::branch4_t<NV>, 
                                            0, 
                                            oscShapeMode1_0Range>;

template <int NV>
using oscShapeMode2 = parameter::chain<oscShapeMode2_InputRange, 
                                       oscShapeMode2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ShapeSrc2_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using ShapeSrc2_0 = parameter::from0To1<Sm2_impl::global_mod7_t<NV>, 
                                        0, 
                                        OscPitchSrc1_0Range>;

template <int NV>
using ShapeSrc2 = parameter::chain<ShapeSrc2_InputRange, ShapeSrc2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(ShapeFmSrc2_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using ShapeFmSrc2_0 = parameter::from0To1<Sm2_impl::branch18_t<NV>, 
                                          0, 
                                          OscFmSrc1_0Range>;

template <int NV>
using ShapeFmSrc2 = parameter::chain<ShapeFmSrc2_InputRange, ShapeFmSrc2_0<NV>>;

template <int NV>
using Osc2Src_0 = parameter::from0To1<Sm2_impl::global_mod_t<NV>, 
                                      0, 
                                      OscPitchSrc1_0Range>;

template <int NV>
using Osc2Src_1 = parameter::from0To1<Sm2_impl::global_mod13_t<NV>, 
                                      0, 
                                      OscPitchSrc1_0Range>;

template <int NV>
using Osc2Src = parameter::chain<ranges::Identity, 
                                 Osc2Src_0<NV>, 
                                 Osc2Src_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Osc2InSel_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Osc2InSel_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using Osc2InSel_0 = parameter::from0To1<Sm2_impl::branch27_t<NV>, 
                                        0, 
                                        Osc2InSel_0Range>;

template <int NV>
using Osc2InSel = parameter::chain<Osc2InSel_InputRange, Osc2InSel_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileInSel_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using FileInSel_0 = parameter::from0To1<Sm2_impl::branch26_t<NV>, 
                                        0, 
                                        Osc2InSel_0Range>;

template <int NV>
using FileInSel = parameter::chain<FileInSel_InputRange, FileInSel_0<NV>>;

template <int NV>
using Vol = parameter::from0To1<core::gain<NV>, 
                                0, 
                                Sm2_impl::peak25_modRange>;

DECLARE_PARAMETER_RANGE_STEP(OscFmSrc_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using OscFmSrc_0 = parameter::from0To1<Sm2_impl::branch29_t<NV>, 
                                       0, 
                                       OscFmSrc1_0Range>;

template <int NV>
using OscFmSrc = parameter::chain<OscFmSrc_InputRange, OscFmSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Osc1InputSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using Osc1InputSrc_0 = parameter::from0To1<Sm2_impl::global_mod8_t<NV>, 
                                           0, 
                                           OscPitchSrc1_0Range>;

template <int NV>
using Osc1InputSrc = parameter::chain<Osc1InputSrc_InputRange, 
                                      Osc1InputSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Osc1InSel_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using Osc1InSel_0 = parameter::from0To1<Sm2_impl::branch28_t<NV>, 
                                        0, 
                                        Osc2InSel_0Range>;

template <int NV>
using Osc1InSel = parameter::chain<Osc1InSel_InputRange, Osc1InSel_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(TEMPO2_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using TEMPO2 = parameter::chain<TEMPO2_InputRange, 
                                parameter::plain<Sm2_impl::global_mod13_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(File2InSel_InputRange, 
                             1., 
                             5., 
                             1.);
template <int NV>
using File2InSel_0 = parameter::from0To1<Sm2_impl::branch30_t<NV>, 
                                         0, 
                                         Osc2InSel_0Range>;

template <int NV>
using File2InSel = parameter::chain<File2InSel_InputRange, File2InSel_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(File2GainOffset_InputRange, 
                             -100., 
                             0., 
                             0.1);
template <int NV>
using File2GainOffset_0 = parameter::from0To1<core::gain<NV>, 
                                              0, 
                                              Sm2_impl::peak_modRange>;

template <int NV>
using File2GainOffset = parameter::chain<File2GainOffset_InputRange, 
                                         File2GainOffset_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(File2ModSrc_InputRange, 
                             1., 
                             17., 
                             1.);
template <int NV>
using File2ModSrc_0 = parameter::from0To1<Sm2_impl::global_mod15_t<NV>, 
                                          0, 
                                          OscPitchSrc1_0Range>;

template <int NV>
using File2ModSrc = parameter::chain<File2ModSrc_InputRange, File2ModSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(File2FmSrc_InputRange, 
                             1., 
                             6., 
                             1.);
template <int NV>
using File2FmSrc_0 = parameter::from0To1<Sm2_impl::branch32_t<NV>, 
                                         0, 
                                         OscFmSrc1_0Range>;

template <int NV>
using File2FmSrc = parameter::chain<File2FmSrc_InputRange, File2FmSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(File2Mode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(File2Mode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using File2Mode_0 = parameter::from0To1<Sm2_impl::branch7_t<NV>, 
                                        0, 
                                        File2Mode_0Range>;

template <int NV>
using File2Mode = parameter::chain<File2Mode_InputRange, File2Mode_0<NV>>;

template <int NV>
using File2Pos = parameter::chain<ranges::Identity, 
                                  parameter::plain<Sm2_impl::pma2_t<NV>, 2>, 
                                  parameter::plain<Sm2_impl::cable_table5_t, 0>>;

DECLARE_PARAMETER_RANGE_STEP(File2Quant_InputRange, 
                             1., 
                             10., 
                             1.);
template <int NV>
using File2Quant_0 = parameter::from0To1<Sm2_impl::branch8_t<NV>, 
                                         0, 
                                         FilePosQuant1_0Range>;

template <int NV>
using File2Quant = parameter::chain<File2Quant_InputRange, File2Quant_0<NV>>;

DECLARE_PARAMETER_RANGE(tune_0Range, 
                        0., 
                        32.);

template <int NV>
using tune_0 = parameter::from0To1<math::sub<NV>, 
                                   0, 
                                   tune_0Range>;

template <int NV> using tune_1 = tune_0<NV>;

template <int NV>
using tune = parameter::chain<ranges::Identity, 
                              tune_0<NV>, 
                              tune_1<NV>>;

template <int NV>
using OscTempoSync1 = parameter::plain<Sm2_impl::branch2_t<NV>, 
                                       0>;
template <int NV>
using OscDiv1 = parameter::plain<Sm2_impl::tempo_sync_t<NV>, 
                                 1>;
using Osc12Mix = parameter::empty;
template <int NV>
using FilePosMod1 = parameter::plain<Sm2_impl::pma3_t<NV>, 1>;
template <int NV>
using FileInputGain1 = parameter::plain<Sm2_impl::global_mod6_t<NV>, 
                                        1>;
template <int NV>
using FileInputGainMod = parameter::plain<Sm2_impl::global_mod6_t<NV>, 
                                          4>;
template <int NV>
using FileInputGainFm1 = parameter::plain<Sm2_impl::pma_unscaled8_t<NV>, 
                                          1>;
template <int NV>
using FilterCut1 = parameter::plain<Sm2_impl::global_mod9_t<NV>, 
                                    1>;
template <int NV>
using FilterCutMod1 = parameter::plain<Sm2_impl::global_mod9_t<NV>, 
                                       4>;
template <int NV>
using FilterCutFm1 = parameter::plain<Sm2_impl::pma_unscaled9_t<NV>, 
                                      1>;
template <int NV>
using VcaGain1 = parameter::plain<Sm2_impl::global_mod10_t<NV>, 
                                  1>;
template <int NV>
using VcaGainMod1 = parameter::plain<Sm2_impl::global_mod10_t<NV>, 
                                     4>;
template <int NV>
using VcaGainFm1 = parameter::plain<Sm2_impl::pma_unscaled10_t<NV>, 
                                    1>;
template <int NV>
using Pan1 = parameter::plain<jdsp::jpanner<NV>, 0>;
template <int NV>
using FilterCut2 = parameter::plain<Sm2_impl::global_mod11_t<NV>, 
                                    1>;
template <int NV>
using FilterCutMod2 = parameter::plain<Sm2_impl::global_mod11_t<NV>, 
                                       4>;
template <int NV>
using FilterCutFm2 = parameter::plain<Sm2_impl::pma_unscaled11_t<NV>, 
                                      1>;
template <int NV>
using VcaGain2 = parameter::plain<Sm2_impl::global_mod12_t<NV>, 
                                  1>;
template <int NV>
using VcaGainMod2 = parameter::plain<Sm2_impl::global_mod12_t<NV>, 
                                     4>;
template <int NV>
using VcaGainFm2 = parameter::plain<Sm2_impl::pma_unscaled12_t<NV>, 
                                    1>;
using VcaGainModMode2 = Osc12Mix;
template <int NV> using Pan2 = Pan1<NV>;
template <int NV>
using OscShape = parameter::plain<Sm2_impl::global_mod4_t<NV>, 
                                  1>;
template <int NV>
using OscShapeMod = parameter::plain<Sm2_impl::global_mod4_t<NV>, 
                                     4>;
template <int NV>
using OscShapeFm = parameter::plain<Sm2_impl::pma_unscaled6_t<NV>, 
                                    1>;
template <int NV>
using Osc2InputGain = parameter::plain<Sm2_impl::global_mod5_t<NV>, 
                                       1>;
template <int NV>
using Osc2InputGainMod = parameter::plain<Sm2_impl::global_mod5_t<NV>, 
                                          4>;
template <int NV>
using Osc2InputGainFm = parameter::plain<Sm2_impl::pma_unscaled7_t<NV>, 
                                         1>;
template <int NV>
using Osc2InputGainModSrc = parameter::plain<Sm2_impl::global_mod5_t<NV>, 
                                             0>;
using FilterInput1 = Osc12Mix;
using FilterInput2 = Osc12Mix;
template <int NV>
using PostModMode = parameter::plain<Sm2_impl::branch3_t<NV>, 
                                     0>;
template <int NV>
using PosEnvTrig = parameter::plain<Sm2_impl::input_toggle_t<NV>, 
                                    0>;
template <int NV>
using PosEnvA = parameter::plain<Sm2_impl::ahdsr_t<NV>, 0>;
template <int NV>
using PosEnvH = parameter::plain<Sm2_impl::ahdsr_t<NV>, 2>;
template <int NV>
using PosEnvD = parameter::plain<Sm2_impl::ahdsr_t<NV>, 3>;
template <int NV>
using PosEnvS = parameter::plain<Sm2_impl::ahdsr_t<NV>, 4>;
template <int NV>
using PosEnvR = parameter::plain<Sm2_impl::ahdsr_t<NV>, 5>;
using PosVel = Osc12Mix;
using OscsSubGain = Osc12Mix;
template <int NV>
using PosTempo = parameter::plain<Sm2_impl::tempo_sync4_t<NV>, 
                                  0>;
template <int NV>
using PosDib = parameter::plain<Sm2_impl::tempo_sync4_t<NV>, 
                                1>;
template <int NV>
using shape2 = parameter::plain<Sm2_impl::global_mod7_t<NV>, 
                                1>;
template <int NV>
using ShapeMod1 = parameter::plain<Sm2_impl::global_mod7_t<NV>, 
                                   4>;
template <int NV>
using ShapeFm2 = parameter::plain<Sm2_impl::pma_unscaled13_t<NV>, 
                                  1>;
using PosSmooth = Osc12Mix;
template <int NV>
using Osc1Input = parameter::plain<Sm2_impl::global_mod8_t<NV>, 
                                   1>;
template <int NV>
using Osc1InputMod = parameter::plain<Sm2_impl::global_mod8_t<NV>, 
                                      4>;
template <int NV>
using Osc1FM = parameter::plain<Sm2_impl::pma_unscaled14_t<NV>, 
                                1>;
template <int NV>
using s = parameter::plain<Sm2_impl::ahdsr1_t<NV>, 4>;
template <int NV>
using a = parameter::plain<Sm2_impl::ahdsr1_t<NV>, 0>;
template <int NV>
using h = parameter::plain<Sm2_impl::ahdsr1_t<NV>, 2>;
template <int NV>
using d = parameter::plain<Sm2_impl::ahdsr1_t<NV>, 3>;
template <int NV>
using r = parameter::plain<Sm2_impl::ahdsr1_t<NV>, 5>;
template <int NV>
using DIV2 = parameter::plain<Sm2_impl::tempo_sync2_t<NV>, 
                              1>;
template <int NV>
using SYNC2 = parameter::plain<Sm2_impl::branch5_t<NV>, 
                               0>;
template <int NV>
using File2Gain = parameter::plain<Sm2_impl::global_mod15_t<NV>, 
                                   1>;
template <int NV>
using File2Mod = parameter::plain<Sm2_impl::global_mod15_t<NV>, 
                                  4>;
template <int NV>
using File2Fm = parameter::plain<Sm2_impl::pma_unscaled17_t<NV>, 
                                 1>;
template <int NV>
using File2Tempo = parameter::plain<Sm2_impl::tempo_sync3_t<NV>, 
                                    0>;
template <int NV>
using FileDiv = parameter::plain<Sm2_impl::tempo_sync3_t<NV>, 
                                 1>;
template <int NV>
using File2EnvTrig = parameter::plain<Sm2_impl::input_toggle1_t<NV>, 
                                      0>;
template <int NV>
using File2A = parameter::plain<Sm2_impl::ahdsr2_t<NV>, 0>;
template <int NV>
using File2H = parameter::plain<Sm2_impl::ahdsr2_t<NV>, 2>;
template <int NV>
using File2D = parameter::plain<Sm2_impl::ahdsr2_t<NV>, 3>;
template <int NV>
using File2S = parameter::plain<Sm2_impl::ahdsr2_t<NV>, 4>;
template <int NV>
using File2R = parameter::plain<Sm2_impl::ahdsr2_t<NV>, 5>;
template <int NV>
using File2PosMod = parameter::plain<Sm2_impl::pma2_t<NV>, 1>;
template <int NV>
using User1 = parameter::plain<Sm2_impl::branch14_t<NV>, 
                               0>;
template <int NV>
using User2 = parameter::plain<Sm2_impl::branch15_t<NV>, 
                               0>;
using Track1 = Osc12Mix;
using Track2 = Osc12Mix;
template <int NV>
using Sm2_t_plist = parameter::list<OscSt1<NV>, 
                                    OscCent1<NV>, 
                                    Oscfm1<NV>, 
                                    OscMod1<NV>, 
                                    OscTempoSync1<NV>, 
                                    OscTempo1<NV>, 
                                    OscDiv1<NV>, 
                                    OscFmSrc1<NV>, 
                                    OscPitchSrc1<NV>, 
                                    Osc12Mix, 
                                    filePos1<NV>, 
                                    FilePosMod1<NV>, 
                                    FilePosQuant1<NV>, 
                                    FileInputGain1<NV>, 
                                    FileInputGainMod<NV>, 
                                    FileInputGainSrc1<NV>, 
                                    FileInputGainFm1<NV>, 
                                    FilterMode1<NV>, 
                                    FilterCut1<NV>, 
                                    FilterCutMod1<NV>, 
                                    FilterCutFm1<NV>, 
                                    FilterCutSrc1<NV>, 
                                    FilterModMode1<NV>, 
                                    VcaGain1<NV>, 
                                    VcaGainMod1<NV>, 
                                    VcaGainFm1<NV>, 
                                    VcaGainSrc1<NV>, 
                                    Res1<NV>, 
                                    Pan1<NV>, 
                                    VcaFmSrc1<NV>, 
                                    OscSt2<NV>, 
                                    OscCent2<NV>, 
                                    Oscfm2<NV>, 
                                    OscMod2<NV>, 
                                    OscFmSrc2<NV>, 
                                    FilterMode2<NV>, 
                                    FilterCut2<NV>, 
                                    FilterCutMod2<NV>, 
                                    FilterCutFm2<NV>, 
                                    FilterCutSrc2<NV>, 
                                    FilterFmdSrc<NV>, 
                                    VcaGain2<NV>, 
                                    VcaGainMod2<NV>, 
                                    VcaGainFm2<NV>, 
                                    VcaGainSrc2<NV>, 
                                    VcaGainModMode2, 
                                    Res2<NV>, 
                                    Pan2<NV>, 
                                    VcaFmSrc2<NV>, 
                                    OscShape<NV>, 
                                    OscShapeMod<NV>, 
                                    OscShapeFm<NV>, 
                                    OscShapeModSrc<NV>, 
                                    OscShapeFmSrc<NV>, 
                                    Osc2InputGain<NV>, 
                                    Osc2InputGainMod<NV>, 
                                    Osc2InputGainFm<NV>, 
                                    Osc2InputGainModSrc<NV>, 
                                    Osc2InputGainFmSrc<NV>, 
                                    FileInFmSrc<NV>, 
                                    FilterInput1, 
                                    FilterInput2, 
                                    PostModMode<NV>, 
                                    PosEnvTrig<NV>, 
                                    PosEnvA<NV>, 
                                    PosEnvH<NV>, 
                                    PosEnvD<NV>, 
                                    PosEnvS<NV>, 
                                    PosEnvR<NV>, 
                                    PosVel, 
                                    OscsSubGain, 
                                    PosTempo<NV>, 
                                    PosDib<NV>, 
                                    FileInOffset<NV>, 
                                    oscShapeMode1<NV>, 
                                    oscShapeMode2<NV>, 
                                    shape2<NV>, 
                                    ShapeMod1<NV>, 
                                    ShapeSrc2<NV>, 
                                    ShapeFm2<NV>, 
                                    ShapeFmSrc2<NV>, 
                                    PosSmooth, 
                                    Osc2Src<NV>, 
                                    Osc2InSel<NV>, 
                                    FileInSel<NV>, 
                                    Vol<NV>, 
                                    Osc1Input<NV>, 
                                    Osc1InputMod<NV>, 
                                    Osc1FM<NV>, 
                                    OscFmSrc<NV>, 
                                    Osc1InputSrc<NV>, 
                                    Osc1InSel<NV>, 
                                    s<NV>, 
                                    a<NV>, 
                                    h<NV>, 
                                    d<NV>, 
                                    r<NV>, 
                                    TEMPO2<NV>, 
                                    DIV2<NV>, 
                                    SYNC2<NV>, 
                                    File2InSel<NV>, 
                                    File2GainOffset<NV>, 
                                    File2Gain<NV>, 
                                    File2Mod<NV>, 
                                    File2Fm<NV>, 
                                    File2ModSrc<NV>, 
                                    File2FmSrc<NV>, 
                                    File2Tempo<NV>, 
                                    FileDiv<NV>, 
                                    File2Mode<NV>, 
                                    File2EnvTrig<NV>, 
                                    File2A<NV>, 
                                    File2H<NV>, 
                                    File2D<NV>, 
                                    File2S<NV>, 
                                    File2R<NV>, 
                                    File2Pos<NV>, 
                                    File2PosMod<NV>, 
                                    File2Quant<NV>, 
                                    User1<NV>, 
                                    User2<NV>, 
                                    tune<NV>, 
                                    Track1, 
                                    Track2>;
}

template <int NV>
using Sm2_t_ = container::chain<Sm2_t_parameters::Sm2_t_plist<NV>, 
                                wrap::fix<2, fix8_block_t<NV>>, 
                                ahdsr1_t<NV>, 
                                envelope::voice_manager, 
                                core::gain<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Sm2_impl::Sm2_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 8;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 4;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 3;
		
		SNEX_METADATA_ID(Sm2);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(2242)
		{
			0x005C, 0x0000, 0x0000, 0x734F, 0x5363, 0x3174, 0x0000, 0xC000, 
            0x00C1, 0xC000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x0100, 0x0000, 0x4F00, 0x6373, 0x6543, 0x746E, 0x0031, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0002, 0x0000, 0x734F, 0x6663, 0x316D, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x0300, 0x0000, 0x4F00, 0x6373, 0x6F4D, 
            0x3164, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x0400, 0x0000, 0x4F00, 0x6373, 
            0x6554, 0x706D, 0x536F, 0x6E79, 0x3163, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x0500, 0x0000, 0x4F00, 0x6373, 0x6554, 0x706D, 0x316F, 0x0000, 
            0x0000, 0x0000, 0x9000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x0600, 0x0000, 0x4F00, 0x6373, 0x6944, 0x3176, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x0000, 0x0042, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x0700, 0x0000, 0x4F00, 0x6373, 0x6D46, 
            0x7253, 0x3163, 0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 0x0000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x0800, 0x0000, 0x4F00, 
            0x6373, 0x6950, 0x6374, 0x5368, 0x6372, 0x0031, 0x0000, 0x3F80, 
            0x0000, 0x4188, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x0009, 0x0000, 0x734F, 0x3163, 0x4D32, 0x7869, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x5C3F, 0x028F, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x0A00, 0x0000, 0x6600, 0x6C69, 0x5065, 0x736F, 
            0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0x1EB8, 0x3F45, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x000B, 0x0000, 0x6946, 0x656C, 
            0x6F50, 0x4D73, 0x646F, 0x0031, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0xCCCD, 0x3D4C, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000C, 
            0x0000, 0x6946, 0x656C, 0x6F50, 0x5173, 0x6175, 0x746E, 0x0031, 
            0x0000, 0x3F80, 0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x000D, 0x0000, 0x6946, 0x656C, 0x6E49, 
            0x7570, 0x4774, 0x6961, 0x316E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x0E00, 
            0x0000, 0x4600, 0x6C69, 0x4965, 0x706E, 0x7475, 0x6147, 0x6E69, 
            0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x000F, 0x0000, 0x6946, 
            0x656C, 0x6E49, 0x7570, 0x4774, 0x6961, 0x536E, 0x6372, 0x0031, 
            0x0000, 0x3F80, 0x0000, 0x4188, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x0010, 0x0000, 0x6946, 0x656C, 0x6E49, 
            0x7570, 0x4774, 0x6961, 0x466E, 0x316D, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x1100, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x646F, 0x3165, 
            0x0000, 0x8000, 0x003F, 0x1000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x1200, 0x0000, 0x4600, 0x6C69, 0x6574, 
            0x4372, 0x7475, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0013, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x7543, 0x4D74, 0x646F, 0x0031, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0014, 0x0000, 0x6946, 0x746C, 0x7265, 0x7543, 
            0x4674, 0x316D, 0x0000, 0x8000, 0x00BF, 0x8000, 0x0A3F, 0x23D7, 
            0x00BD, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1500, 0x0000, 0x4600, 
            0x6C69, 0x6574, 0x4372, 0x7475, 0x7253, 0x3163, 0x0000, 0x8000, 
            0x003F, 0x8800, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x1600, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x646F, 
            0x6F4D, 0x6564, 0x0031, 0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 
            0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0017, 0x0000, 
            0x6356, 0x4761, 0x6961, 0x316E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xD73F, 0x30A3, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x1800, 
            0x0000, 0x5600, 0x6163, 0x6147, 0x6E69, 0x6F4D, 0x3164, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x1900, 0x0000, 0x5600, 0x6163, 0x6147, 0x6E69, 
            0x6D46, 0x0031, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x001A, 0x0000, 0x6356, 
            0x4761, 0x6961, 0x536E, 0x6372, 0x0031, 0x0000, 0x3F80, 0x0000, 
            0x4188, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x001B, 0x0000, 0x6552, 0x3173, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x8F3F, 0x75C2, 0x183F, 0x8789, 0x003E, 0x0000, 0x5C00, 0x1C00, 
            0x0000, 0x5000, 0x6E61, 0x0031, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0xD70A, 0xBD23, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x001D, 
            0x0000, 0x6356, 0x4661, 0x536D, 0x6372, 0x0031, 0x0000, 0x3F80, 
            0x0000, 0x40C0, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x005C, 0x001E, 0x0000, 0x734F, 0x5363, 0x3274, 0x0000, 0xC000, 
            0x00C1, 0xC000, 0x0041, 0xB800, 0x00C1, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x1F00, 0x0000, 0x4F00, 0x6373, 0x6543, 0x746E, 0x0032, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0xFBE8, 0xBE79, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0020, 0x0000, 0x734F, 0x6663, 0x326D, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x2100, 0x0000, 0x4F00, 0x6373, 0x6F4D, 
            0x3264, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x2200, 0x0000, 0x4F00, 0x6373, 
            0x6D46, 0x7253, 0x3263, 0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x2300, 0x0000, 
            0x4600, 0x6C69, 0x6574, 0x4D72, 0x646F, 0x3265, 0x0000, 0x8000, 
            0x003F, 0x1000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x2400, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4372, 0x7475, 
            0x0032, 0x0000, 0x0000, 0x0000, 0x3F80, 0x70A4, 0x3F7D, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0025, 0x0000, 0x6946, 0x746C, 
            0x7265, 0x7543, 0x4D74, 0x646F, 0x0032, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0026, 0x0000, 0x6946, 0x746C, 0x7265, 0x7543, 0x4674, 0x326D, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x2700, 0x0000, 0x4600, 0x6C69, 0x6574, 
            0x4372, 0x7475, 0x7253, 0x3263, 0x0000, 0x8000, 0x003F, 0x8800, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x2800, 
            0x0000, 0x4600, 0x6C69, 0x6574, 0x4672, 0x646D, 0x7253, 0x0063, 
            0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x0029, 0x0000, 0x6356, 0x4761, 0x6961, 
            0x326E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x2A00, 0x0000, 0x5600, 0x6163, 
            0x6147, 0x6E69, 0x6F4D, 0x3264, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x2B00, 
            0x0000, 0x5600, 0x6163, 0x6147, 0x6E69, 0x6D46, 0x0032, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x002C, 0x0000, 0x6356, 0x4761, 0x6961, 0x536E, 
            0x6372, 0x0032, 0x0000, 0x3F80, 0x0000, 0x4188, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x002D, 0x0000, 0x6356, 
            0x4761, 0x6961, 0x4D6E, 0x646F, 0x6F4D, 0x6564, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x999A, 0x3E99, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x002E, 0x0000, 0x6552, 0x3273, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x1800, 0x8789, 0x003E, 0x0000, 
            0x5C00, 0x2F00, 0x0000, 0x5000, 0x6E61, 0x0032, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0030, 0x0000, 0x6356, 0x4661, 0x536D, 0x6372, 0x0032, 
            0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x0031, 0x0000, 0x734F, 0x5363, 0x6168, 
            0x6570, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x3200, 0x0000, 0x4F00, 0x6373, 
            0x6853, 0x7061, 0x4D65, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x3300, 
            0x0000, 0x4F00, 0x6373, 0x6853, 0x7061, 0x4665, 0x006D, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0xAE14, 0x3F47, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0034, 0x0000, 0x734F, 0x5363, 0x6168, 0x6570, 
            0x6F4D, 0x5364, 0x6372, 0x0000, 0x8000, 0x003F, 0x8800, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x3500, 0x0000, 
            0x4F00, 0x6373, 0x6853, 0x7061, 0x4665, 0x536D, 0x6372, 0x0000, 
            0x8000, 0x003F, 0xC000, 0x0040, 0x4000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x3600, 0x0000, 0x4F00, 0x6373, 0x4932, 0x706E, 
            0x7475, 0x6147, 0x6E69, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x3700, 0x0000, 
            0x4F00, 0x6373, 0x4932, 0x706E, 0x7475, 0x6147, 0x6E69, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x0038, 0x0000, 0x734F, 0x3263, 
            0x6E49, 0x7570, 0x4774, 0x6961, 0x466E, 0x006D, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0039, 0x0000, 0x734F, 0x3263, 0x6E49, 0x7570, 0x4774, 
            0x6961, 0x4D6E, 0x646F, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x4180, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x003A, 0x0000, 0x734F, 0x3263, 0x6E49, 0x7570, 0x4774, 0x6961, 
            0x466E, 0x536D, 0x6372, 0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x3B00, 0x0000, 
            0x4600, 0x6C69, 0x4965, 0x466E, 0x536D, 0x6372, 0x0000, 0x8000, 
            0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5C3F, 0x3C00, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4972, 0x706E, 
            0x7475, 0x0031, 0x0000, 0x3F80, 0x0000, 0x40A0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x003D, 0x0000, 0x6946, 
            0x746C, 0x7265, 0x6E49, 0x7570, 0x3274, 0x0000, 0x8000, 0x003F, 
            0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x3E00, 0x0000, 0x5000, 0x736F, 0x4D74, 0x646F, 0x6F4D, 0x6564, 
            0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5C3F, 0x3F00, 0x0000, 0x5000, 0x736F, 0x6E45, 
            0x5476, 0x6972, 0x0067, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0040, 0x0000, 
            0x6F50, 0x4573, 0x766E, 0x0041, 0x0000, 0x0000, 0x4000, 0x461C, 
            0x3000, 0x4568, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 0x0041, 
            0x0000, 0x6F50, 0x4573, 0x766E, 0x0048, 0x0000, 0x0000, 0x4000, 
            0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 
            0x0042, 0x0000, 0x6F50, 0x4573, 0x766E, 0x0044, 0x0000, 0x0000, 
            0x4000, 0x461C, 0x4000, 0x461C, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 
            0x005C, 0x0043, 0x0000, 0x6F50, 0x4573, 0x766E, 0x0053, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0044, 0x0000, 0x6F50, 0x4573, 0x766E, 0x0052, 
            0x0000, 0x0000, 0x4000, 0x461C, 0x8000, 0x44EE, 0x6A72, 0x3E4A, 
            0xCCCD, 0x3DCC, 0x005C, 0x0045, 0x0000, 0x6F50, 0x5673, 0x6C65, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5C00, 0x4600, 0x0000, 0x4F00, 0x6373, 0x5373, 
            0x6275, 0x6147, 0x6E69, 0x0000, 0x0000, 0x0000, 0x3800, 0x3342, 
            0xC333, 0x0040, 0x8000, 0xCD3F, 0xCCCC, 0x5C3D, 0x4700, 0x0000, 
            0x5000, 0x736F, 0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 
            0x4190, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x0048, 0x0000, 0x6F50, 0x4473, 0x6269, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0042, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x4900, 0x0000, 0x4600, 0x6C69, 0x4965, 0x4F6E, 0x6666, 0x6573, 
            0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x005C, 0x004A, 0x0000, 0x736F, 0x5363, 
            0x6168, 0x6570, 0x6F4D, 0x6564, 0x0031, 0x0000, 0x3F80, 0x0000, 
            0x4140, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x004B, 0x0000, 0x736F, 0x5363, 0x6168, 0x6570, 0x6F4D, 0x6564, 
            0x0032, 0x0000, 0x3F80, 0x0000, 0x4140, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x004C, 0x0000, 0x6873, 0x7061, 
            0x3265, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x4D00, 0x0000, 0x5300, 0x6168, 
            0x6570, 0x6F4D, 0x3164, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x4E00, 0x0000, 
            0x5300, 0x6168, 0x6570, 0x7253, 0x3263, 0x0000, 0x8000, 0x003F, 
            0x8800, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x4F00, 0x0000, 0x5300, 0x6168, 0x6570, 0x6D46, 0x0032, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0050, 0x0000, 0x6853, 0x7061, 0x4665, 0x536D, 
            0x6372, 0x0032, 0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0051, 0x0000, 0x6F50, 
            0x5373, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0052, 
            0x0000, 0x734F, 0x3263, 0x7253, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 
            0x0053, 0x0000, 0x734F, 0x3263, 0x6E49, 0x6553, 0x006C, 0x0000, 
            0x3F80, 0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0054, 0x0000, 0x6946, 0x656C, 0x6E49, 0x6553, 
            0x006C, 0x0000, 0x3F80, 0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x005C, 0x0055, 0x0000, 0x6F56, 0x006C, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x005C, 0x0056, 0x0000, 0x734F, 0x3163, 0x6E49, 
            0x7570, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x0057, 0x0000, 0x734F, 
            0x3163, 0x6E49, 0x7570, 0x4D74, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 
            0x5800, 0x0000, 0x4F00, 0x6373, 0x4631, 0x004D, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0059, 0x0000, 0x734F, 0x4663, 0x536D, 0x6372, 0x0000, 
            0x8000, 0x003F, 0xA000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5C3F, 0x5A00, 0x0000, 0x4F00, 0x6373, 0x4931, 0x706E, 
            0x7475, 0x7253, 0x0063, 0x0000, 0x3F80, 0x0000, 0x4188, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x005B, 0x0000, 
            0x734F, 0x3163, 0x6E49, 0x6553, 0x006C, 0x0000, 0x3F80, 0x0000, 
            0x40A0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 
            0x005C, 0x0000, 0x0073, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x005C, 0x005D, 0x0000, 
            0x0061, 0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 0x0000, 0x6A72, 
            0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 0x005E, 0x0000, 0x0068, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 
            0x3DCC, 0x005C, 0x005F, 0x0000, 0x0064, 0x0000, 0x0000, 0x4000, 
            0x461C, 0x4000, 0x461C, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 
            0x0060, 0x0000, 0x0072, 0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 
            0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x005C, 0x0061, 0x0000, 
            0x4554, 0x504D, 0x324F, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x6200, 0x0000, 
            0x4400, 0x5649, 0x0032, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 
            0x4160, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0063, 0x0000, 
            0x5953, 0x434E, 0x0032, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x0064, 0x0000, 
            0x6946, 0x656C, 0x4932, 0x536E, 0x6C65, 0x0000, 0x8000, 0x003F, 
            0xA000, 0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x6500, 0x0000, 0x4600, 0x6C69, 0x3265, 0x6147, 0x6E69, 0x664F, 
            0x7366, 0x7465, 0x0000, 0xC800, 0x00C2, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x8000, 0xCD3F, 0xCCCC, 0x5C3D, 0x6600, 0x0000, 0x4600, 
            0x6C69, 0x3265, 0x6147, 0x6E69, 0x0000, 0x0000, 0x0000, 0x8000, 
            0xF63F, 0x1C28, 0x003F, 0x8000, 0x003F, 0x0000, 0x5C00, 0x6700, 
            0x0000, 0x4600, 0x6C69, 0x3265, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x005C, 0x0068, 0x0000, 0x6946, 0x656C, 0x4632, 0x006D, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x005C, 0x0069, 0x0000, 0x6946, 0x656C, 0x4D32, 0x646F, 
            0x7253, 0x0063, 0x0000, 0x3F80, 0x0000, 0x4188, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x006A, 0x0000, 0x6946, 
            0x656C, 0x4632, 0x536D, 0x6372, 0x0000, 0x8000, 0x003F, 0xC000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 0x6B00, 
            0x0000, 0x4600, 0x6C69, 0x3265, 0x6554, 0x706D, 0x006F, 0x0000, 
            0x0000, 0x0000, 0x4190, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x006C, 0x0000, 0x6946, 0x656C, 0x6944, 0x0076, 
            0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x005C, 0x006D, 0x0000, 0x6946, 0x656C, 0x4D32, 
            0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 0x4040, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x005C, 0x006E, 0x0000, 0x6946, 
            0x656C, 0x4532, 0x766E, 0x7254, 0x6769, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5C3F, 
            0x6F00, 0x0000, 0x4600, 0x6C69, 0x3265, 0x0041, 0x0000, 0x0000, 
            0x4000, 0x461C, 0x0000, 0x435E, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 
            0x005C, 0x0070, 0x0000, 0x6946, 0x656C, 0x4832, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0x0000, 0x7200, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5C3D, 0x7100, 0x0000, 0x4600, 0x6C69, 0x3265, 0x0044, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x0000, 0x4000, 0x6A72, 0x3E4A, 0xCCCD, 
            0x3DCC, 0x005C, 0x0072, 0x0000, 0x6946, 0x656C, 0x5332, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5C00, 0x7300, 0x0000, 0x4600, 0x6C69, 0x3265, 0x0052, 
            0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 0x4040, 0x6A72, 0x3E4A, 
            0xCCCD, 0x3DCC, 0x005C, 0x0074, 0x0000, 0x6946, 0x656C, 0x5032, 
            0x736F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5C00, 0x7500, 0x0000, 0x4600, 0x6C69, 
            0x3265, 0x6F50, 0x4D73, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5C00, 0x7600, 
            0x0000, 0x4600, 0x6C69, 0x3265, 0x7551, 0x6E61, 0x0074, 0x0000, 
            0x3F80, 0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0077, 0x0000, 0x7355, 0x7265, 0x0031, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0078, 0x0000, 0x7355, 0x7265, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x0079, 0x0000, 0x7574, 0x656E, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5C00, 0x7A00, 0x0000, 0x5400, 0x6172, 0x6B63, 0x0031, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x005C, 0x007B, 0x0000, 0x7254, 0x6361, 0x326B, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F
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
		
		auto& fix8_block = this->getT(0);                                                      // Sm2_impl::fix8_block_t<NV>
		auto& split8 = this->getT(0).getT(0);                                                  // Sm2_impl::split8_t<NV>
		auto& modchain1 = this->getT(0).getT(0).getT(0);                                       // Sm2_impl::modchain1_t<NV>
		auto& chain37 = this->getT(0).getT(0).getT(0).getT(0);                                 // Sm2_impl::chain37_t<NV>
		auto& branch9 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                         // Sm2_impl::branch9_t<NV>
		auto& chain58 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);                 // Sm2_impl::chain58_t<NV>
		auto& add24 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain57 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);                 // Sm2_impl::chain57_t<NV>
		auto& add23 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain67 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);                 // Sm2_impl::chain67_t<NV>
		auto& add25 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);           // math::add<NV>
		auto& chain38 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3);                 // Sm2_impl::chain38_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);            // math::add<NV>
		auto& chain69 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4);                 // Sm2_impl::chain69_t<NV>
		auto& add33 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(4).getT(0);           // math::add<NV>
		auto& chain72 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5);                 // Sm2_impl::chain72_t<NV>
		auto& add51 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(5).getT(0);           // math::add<NV>
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                           // Sm2_impl::peak5_t<NV>
		auto& clear15 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                         // math::clear<NV>
		auto& split7 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                          // Sm2_impl::split7_t<NV>
		auto& chain62 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);                 // Sm2_impl::chain62_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).getT(0);          // Sm2_impl::split6_t<NV>
		auto& chain59 = this->getT(0).getT(0).getT(0).getT(0).                                 // Sm2_impl::chain59_t<NV>
                        getT(3).getT(0).getT(0).getT(0);
		auto& minmax = this->getT(0).getT(0).getT(0).getT(0).                                  // Sm2_impl::minmax_t<NV>
                       getT(3).getT(0).getT(0).getT(0).
                       getT(0);
		auto& add26 = this->getT(0).getT(0).getT(0).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(0).getT(0).
                      getT(1);
		auto& chain182 = this->getT(0).getT(0).getT(0).getT(0).                                // Sm2_impl::chain182_t<NV>
                         getT(3).getT(0).getT(0).getT(1);
		auto& add36 = this->getT(0).getT(0).getT(0).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(0).getT(1).
                      getT(0);
		auto& chain258 = this->getT(0).getT(0).getT(0).getT(0).                                // Sm2_impl::chain258_t<NV>
                         getT(3).getT(0).getT(0).getT(2);
		auto& pma = this->getT(0).getT(0).getT(0).getT(0).                                     // Sm2_impl::pma_t<NV>
                    getT(3).getT(0).getT(0).getT(2).
                    getT(0);
		auto& add27 = this->getT(0).getT(0).getT(0).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain60 = this->getT(0).getT(0).getT(0).getT(0).                                 // Sm2_impl::chain60_t<NV>
                        getT(3).getT(0).getT(0).getT(3);
		auto& chain119 = this->getT(0).getT(0).getT(0).getT(0).                                // Sm2_impl::chain119_t<NV>
                         getT(3).getT(0).getT(0).getT(3).
                         getT(0);
		auto& global_mod1 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                     // Sm2_impl::global_mod1_t<NV>
                            getT(0).getT(0).getT(3).getT(0).getT(0);
		auto& minmax3 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                         // Sm2_impl::minmax3_t<NV>
                        getT(0).getT(0).getT(3).getT(0).getT(1);
		auto& add89 = this->getT(0).getT(0).getT(0).getT(0).getT(3).                           // math::add<NV>
                      getT(0).getT(0).getT(3).getT(0).getT(2);
		auto& sub21 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).getT(1);           // math::sub<NV>
		auto& peak16 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).getT(2);          // Sm2_impl::peak16_t
		auto& mod2sig1 = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).getT(3);        // math::mod2sig<NV>
		auto& peak_unscaled = this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).getT(4);   // Sm2_impl::peak_unscaled_t<NV>
		auto& modchain5 = this->getT(0).getT(0).getT(1);                                       // Sm2_impl::modchain5_t<NV>
		auto& chain77 = this->getT(0).getT(0).getT(1).getT(0);                                 // Sm2_impl::chain77_t<NV>
		auto& branch12 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                        // Sm2_impl::branch12_t<NV>
		auto& chain79 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);                 // Sm2_impl::chain79_t<NV>
		auto& add39 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain80 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);                 // Sm2_impl::chain80_t<NV>
		auto& add40 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain81 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(2);                 // Sm2_impl::chain81_t<NV>
		auto& add41 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);           // math::add<NV>
		auto& chain78 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(3);                 // Sm2_impl::chain78_t<NV>
		auto& add38 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(3).getT(0);           // math::add<NV>
		auto& chain86 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(4);                 // Sm2_impl::chain86_t<NV>
		auto& add49 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(4).getT(0);           // math::add<NV>
		auto& chain87 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(5);                 // Sm2_impl::chain87_t<NV>
		auto& add52 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(5).getT(0);           // math::add<NV>
		auto& peak13 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                          // Sm2_impl::peak13_t<NV>
		auto& clear18 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                         // math::clear<NV>
		auto& split10 = this->getT(0).getT(0).getT(1).getT(0).getT(3);                         // Sm2_impl::split10_t<NV>
		auto& chain82 = this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(0);                 // Sm2_impl::chain82_t<NV>
		auto& split11 = this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).getT(0);         // Sm2_impl::split11_t<NV>
		auto& chain83 = this->getT(0).getT(0).getT(1).getT(0).                                 // Sm2_impl::chain83_t<NV>
                        getT(3).getT(0).getT(0).getT(0);
		auto& minmax2 = this->getT(0).getT(0).getT(1).getT(0).                                 // Sm2_impl::minmax2_t<NV>
                        getT(3).getT(0).getT(0).getT(0).
                        getT(0);
		auto& add42 = this->getT(0).getT(0).getT(1).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(0).getT(0).
                      getT(1);
		auto& chain181 = this->getT(0).getT(0).getT(1).getT(0).                                // Sm2_impl::chain181_t<NV>
                         getT(3).getT(0).getT(0).getT(1);
		auto& add35 = this->getT(0).getT(0).getT(1).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(0).getT(1).
                      getT(0);
		auto& chain260 = this->getT(0).getT(0).getT(1).getT(0).                                // Sm2_impl::chain260_t<NV>
                         getT(3).getT(0).getT(0).getT(2);
		auto& pma1 = this->getT(0).getT(0).getT(1).getT(0).                                    // Sm2_impl::pma1_t<NV>
                     getT(3).getT(0).getT(0).getT(2).
                     getT(0);
		auto& add43 = this->getT(0).getT(0).getT(1).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain120 = this->getT(0).getT(0).getT(1).getT(0).                                // Sm2_impl::chain120_t<NV>
                         getT(3).getT(0).getT(0).getT(3);
		auto& global_mod = this->getT(0).getT(0).getT(1).getT(0).                              // Sm2_impl::global_mod_t<NV>
                           getT(3).getT(0).getT(0).getT(3).
                           getT(0);
		auto& minmax1 = this->getT(0).getT(0).getT(1).getT(0).                                 // Sm2_impl::minmax1_t<NV>
                        getT(3).getT(0).getT(0).getT(3).
                        getT(1);
		auto& add90 = this->getT(0).getT(0).getT(1).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(0).getT(3).
                      getT(2);
		auto& sub3 = this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).getT(1);            // math::sub<NV>
		auto& mod2sig = this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).getT(2);         // math::mod2sig<NV>
		auto& peak_unscaled2 = this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).getT(3);  // Sm2_impl::peak_unscaled2_t<NV>
		auto& modchain2 = this->getT(0).getT(0).getT(2);                                       // Sm2_impl::modchain2_t<NV>
		auto& chain63 = this->getT(0).getT(0).getT(2).getT(0);                                 // Sm2_impl::chain63_t<NV>
		auto& branch10 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                        // Sm2_impl::branch10_t<NV>
		auto& chain65 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);                 // Sm2_impl::chain65_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain66 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);                 // Sm2_impl::chain66_t<NV>
		auto& add31 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain68 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(2);                 // Sm2_impl::chain68_t<NV>
		auto& add32 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(2).getT(0);           // math::add<NV>
		auto& chain64 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(3);                 // Sm2_impl::chain64_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(3).getT(0);           // math::add<NV>
		auto& chain71 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(4);                 // Sm2_impl::chain71_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(4).getT(0);           // math::add<NV>
		auto& chain73 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(5);                 // Sm2_impl::chain73_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(5).getT(0);           // math::add<NV>
		auto& peak7 = this->getT(0).getT(0).getT(2).getT(0).getT(1);                           // Sm2_impl::peak7_t<NV>
		auto& clear17 = this->getT(0).getT(0).getT(2).getT(0).getT(2);                         // math::clear<NV>
		auto& chain70 = this->getT(0).getT(0).getT(2).getT(0).getT(3);                         // Sm2_impl::chain70_t<NV>
		auto& split12 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0);                 // Sm2_impl::split12_t<NV>
		auto& chain97 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0).getT(0);         // Sm2_impl::chain97_t<NV>
		auto& pma_unscaled3 = this->getT(0).getT(0).getT(2).getT(0).                           // Sm2_impl::pma_unscaled3_t<NV>
                              getT(3).getT(0).getT(0).getT(0);
		auto& add34 = this->getT(0).getT(0).getT(2).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(0).getT(1);
		auto& chain121 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(0).getT(1);        // Sm2_impl::chain121_t<NV>
		auto& global_mod3 = this->getT(0).getT(0).getT(2).getT(0).                             // Sm2_impl::global_mod3_t<NV>
                            getT(3).getT(0).getT(1).getT(0);
		auto& add91 = this->getT(0).getT(0).getT(2).getT(0).                                   // math::add<NV>
                      getT(3).getT(0).getT(1).getT(1);
		auto& peak35 = this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(1);                  // Sm2_impl::peak35_t<NV>
		auto& modchain3 = this->getT(0).getT(0).getT(3);                                       // Sm2_impl::modchain3_t<NV>
		auto& chain74 = this->getT(0).getT(0).getT(3).getT(0);                                 // Sm2_impl::chain74_t<NV>
		auto& branch11 = this->getT(0).getT(0).getT(3).getT(0).getT(0);                        // Sm2_impl::branch11_t<NV>
		auto& chain76 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0);                 // Sm2_impl::chain76_t<NV>
		auto& add57 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain85 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1);                 // Sm2_impl::chain85_t<NV>
		auto& add68 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain88 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(2);                 // Sm2_impl::chain88_t<NV>
		auto& add78 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(2).getT(0);           // math::add<NV>
		auto& chain75 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(3);                 // Sm2_impl::chain75_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(3).getT(0);           // math::add<NV>
		auto& chain93 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(4);                 // Sm2_impl::chain93_t<NV>
		auto& add82 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(4).getT(0);           // math::add<NV>
		auto& chain96 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(5);                 // Sm2_impl::chain96_t<NV>
		auto& add83 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(5).getT(0);           // math::add<NV>
		auto& peak9 = this->getT(0).getT(0).getT(3).getT(0).getT(1);                           // Sm2_impl::peak9_t<NV>
		auto& clear28 = this->getT(0).getT(0).getT(3).getT(0).getT(2);                         // math::clear<NV>
		auto& chain98 = this->getT(0).getT(0).getT(3).getT(0).getT(3);                         // Sm2_impl::chain98_t<NV>
		auto& split16 = this->getT(0).getT(0).getT(3).getT(0).getT(3).getT(0);                 // Sm2_impl::split16_t<NV>
		auto& chain99 = this->getT(0).getT(0).getT(3).getT(0).getT(3).getT(0).getT(0);         // Sm2_impl::chain99_t<NV>
		auto& pma_unscaled15 = this->getT(0).getT(0).getT(3).getT(0).                          // Sm2_impl::pma_unscaled15_t<NV>
                               getT(3).getT(0).getT(0).getT(0);
		auto& add129 = this->getT(0).getT(0).getT(3).getT(0).                                  // math::add<NV>
                       getT(3).getT(0).getT(0).getT(1);
		auto& chain247 = this->getT(0).getT(0).getT(3).getT(0).getT(3).getT(0).getT(1);        // Sm2_impl::chain247_t<NV>
		auto& global_mod13 = this->getT(0).getT(0).getT(3).getT(0).                            // Sm2_impl::global_mod13_t<NV>
                             getT(3).getT(0).getT(1).getT(0);
		auto& add130 = this->getT(0).getT(0).getT(3).getT(0).                                  // math::add<NV>
                       getT(3).getT(0).getT(1).getT(1);
		auto& peak36 = this->getT(0).getT(0).getT(3).getT(0).getT(4);                          // Sm2_impl::peak36_t<NV>
		auto& modchain4 = this->getT(0).getT(0).getT(4);                                       // Sm2_impl::modchain4_t<NV>
		auto& chain102 = this->getT(0).getT(0).getT(4).getT(0);                                // Sm2_impl::chain102_t<NV>
		auto& branch16 = this->getT(0).getT(0).getT(4).getT(0).getT(0);                        // Sm2_impl::branch16_t<NV>
		auto& chain104 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0);                // Sm2_impl::chain104_t<NV>
		auto& add60 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain105 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1);                // Sm2_impl::chain105_t<NV>
		auto& add61 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain110 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(2);                // Sm2_impl::chain110_t<NV>
		auto& add84 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(2).getT(0);           // math::add<NV>
		auto& chain103 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(3);                // Sm2_impl::chain103_t<NV>
		auto& add59 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(3).getT(0);           // math::add<NV>
		auto& chain194 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(4);                // Sm2_impl::chain194_t<NV>
		auto& add101 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(4).getT(0);          // math::add<NV>
		auto& chain197 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(5);                // Sm2_impl::chain197_t<NV>
		auto& add104 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(5).getT(0);          // math::add<NV>
		auto& peak17 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                          // Sm2_impl::peak17_t<NV>
		auto& clear16 = this->getT(0).getT(0).getT(4).getT(0).getT(2);                         // math::clear<NV>
		auto& split4 = this->getT(0).getT(0).getT(4).getT(0).getT(3);                          // Sm2_impl::split4_t<NV>
		auto& chain183 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(0);                // Sm2_impl::chain183_t<NV>
		auto& pma_unscaled6 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(0).getT(0);   // Sm2_impl::pma_unscaled6_t<NV>
		auto& add37 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(0).getT(1);           // math::add<NV>
		auto& chain106 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(1);                // Sm2_impl::chain106_t<NV>
		auto& chain122 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(1).getT(0);        // Sm2_impl::chain122_t<NV>
		auto& global_mod4 = this->getT(0).getT(0).getT(4).getT(0).                             // Sm2_impl::global_mod4_t<NV>
                            getT(3).getT(1).getT(0).getT(0);
		auto& add92 = this->getT(0).getT(0).getT(4).getT(0).                                   // math::add<NV>
                      getT(3).getT(1).getT(0).getT(1);
		auto& peak6 = this->getT(0).getT(0).getT(4).getT(0).getT(4);                           // Sm2_impl::peak6_t<NV>
		auto& modchain12 = this->getT(0).getT(0).getT(5);                                      // Sm2_impl::modchain12_t<NV>
		auto& chain107 = this->getT(0).getT(0).getT(5).getT(0);                                // Sm2_impl::chain107_t<NV>
		auto& branch18 = this->getT(0).getT(0).getT(5).getT(0).getT(0);                        // Sm2_impl::branch18_t<NV>
		auto& chain133 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(0);                // Sm2_impl::chain133_t<NV>
		auto& add63 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain139 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(1);                // Sm2_impl::chain139_t<NV>
		auto& add67 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain140 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(2);                // Sm2_impl::chain140_t<NV>
		auto& add95 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(2).getT(0);           // math::add<NV>
		auto& chain108 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(3);                // Sm2_impl::chain108_t<NV>
		auto& add62 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(3).getT(0);           // math::add<NV>
		auto& chain223 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(4);                // Sm2_impl::chain223_t<NV>
		auto& add123 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(4).getT(0);          // math::add<NV>
		auto& chain224 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(5);                // Sm2_impl::chain224_t<NV>
		auto& add124 = this->getT(0).getT(0).getT(5).getT(0).getT(0).getT(5).getT(0);          // math::add<NV>
		auto& peak30 = this->getT(0).getT(0).getT(5).getT(0).getT(1);                          // Sm2_impl::peak30_t<NV>
		auto& clear26 = this->getT(0).getT(0).getT(5).getT(0).getT(2);                         // math::clear<NV>
		auto& split14 = this->getT(0).getT(0).getT(5).getT(0).getT(3);                         // Sm2_impl::split14_t<NV>
		auto& chain225 = this->getT(0).getT(0).getT(5).getT(0).getT(3).getT(0);                // Sm2_impl::chain225_t<NV>
		auto& pma_unscaled13 = this->getT(0).getT(0).getT(5).getT(0).getT(3).getT(0).getT(0);  // Sm2_impl::pma_unscaled13_t<NV>
		auto& add44 = this->getT(0).getT(0).getT(5).getT(0).getT(3).getT(0).getT(1);           // math::add<NV>
		auto& chain145 = this->getT(0).getT(0).getT(5).getT(0).getT(3).getT(1);                // Sm2_impl::chain145_t<NV>
		auto& chain146 = this->getT(0).getT(0).getT(5).getT(0).getT(3).getT(1).getT(0);        // Sm2_impl::chain146_t<NV>
		auto& global_mod7 = this->getT(0).getT(0).getT(5).getT(0).                             // Sm2_impl::global_mod7_t<NV>
                            getT(3).getT(1).getT(0).getT(0);
		auto& add96 = this->getT(0).getT(0).getT(5).getT(0).                                   // math::add<NV>
                      getT(3).getT(1).getT(0).getT(1);
		auto& peak8 = this->getT(0).getT(0).getT(5).getT(0).getT(4);                           // Sm2_impl::peak8_t<NV>
		auto& modchain13 = this->getT(0).getT(0).getT(6);                                      // Sm2_impl::modchain13_t<NV>
		auto& chain147 = this->getT(0).getT(0).getT(6).getT(0);                                // Sm2_impl::chain147_t<NV>
		auto& branch29 = this->getT(0).getT(0).getT(6).getT(0).getT(0);                        // Sm2_impl::branch29_t<NV>
		auto& chain239 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(0);                // Sm2_impl::chain239_t<NV>
		auto& add73 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain240 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(1);                // Sm2_impl::chain240_t<NV>
		auto& add77 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain241 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(2);                // Sm2_impl::chain241_t<NV>
		auto& add125 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(2).getT(0);          // math::add<NV>
		auto& chain227 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(3);                // Sm2_impl::chain227_t<NV>
		auto& add72 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(3).getT(0);           // math::add<NV>
		auto& chain242 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(4);                // Sm2_impl::chain242_t<NV>
		auto& add126 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(4).getT(0);          // math::add<NV>
		auto& chain243 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(5);                // Sm2_impl::chain243_t<NV>
		auto& add127 = this->getT(0).getT(0).getT(6).getT(0).getT(0).getT(5).getT(0);          // math::add<NV>
		auto& peak21 = this->getT(0).getT(0).getT(6).getT(0).getT(1);                          // Sm2_impl::peak21_t
		auto& clear27 = this->getT(0).getT(0).getT(6).getT(0).getT(2);                         // math::clear<NV>
		auto& split15 = this->getT(0).getT(0).getT(6).getT(0).getT(3);                         // Sm2_impl::split15_t<NV>
		auto& chain244 = this->getT(0).getT(0).getT(6).getT(0).getT(3).getT(0);                // Sm2_impl::chain244_t<NV>
		auto& pma_unscaled14 = this->getT(0).getT(0).getT(6).getT(0).getT(3).getT(0).getT(0);  // Sm2_impl::pma_unscaled14_t<NV>
		auto& add55 = this->getT(0).getT(0).getT(6).getT(0).getT(3).getT(0).getT(1);           // math::add<NV>
		auto& chain245 = this->getT(0).getT(0).getT(6).getT(0).getT(3).getT(1);                // Sm2_impl::chain245_t<NV>
		auto& chain246 = this->getT(0).getT(0).getT(6).getT(0).getT(3).getT(1).getT(0);        // Sm2_impl::chain246_t<NV>
		auto& global_mod8 = this->getT(0).getT(0).getT(6).getT(0).                             // Sm2_impl::global_mod8_t<NV>
                            getT(3).getT(1).getT(0).getT(0);
		auto& add128 = this->getT(0).getT(0).getT(6).getT(0).                                  // math::add<NV>
                       getT(3).getT(1).getT(0).getT(1);
		auto& peak3 = this->getT(0).getT(0).getT(6).getT(0).getT(4);                           // Sm2_impl::peak3_t<NV>
		auto& modchain9 = this->getT(0).getT(0).getT(7);                                       // Sm2_impl::modchain9_t<NV>
		auto& chain112 = this->getT(0).getT(0).getT(7).getT(0);                                // Sm2_impl::chain112_t<NV>
		auto& branch17 = this->getT(0).getT(0).getT(7).getT(0).getT(0);                        // Sm2_impl::branch17_t<NV>
		auto& chain114 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(0);                // Sm2_impl::chain114_t<NV>
		auto& add65 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain115 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(1);                // Sm2_impl::chain115_t<NV>
		auto& add66 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain116 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(2);                // Sm2_impl::chain116_t<NV>
		auto& add88 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(2).getT(0);           // math::add<NV>
		auto& chain113 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(3);                // Sm2_impl::chain113_t<NV>
		auto& add64 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(3).getT(0);           // math::add<NV>
		auto& chain195 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(4);                // Sm2_impl::chain195_t<NV>
		auto& add102 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(4).getT(0);          // math::add<NV>
		auto& chain198 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(5);                // Sm2_impl::chain198_t<NV>
		auto& add105 = this->getT(0).getT(0).getT(7).getT(0).getT(0).getT(5).getT(0);          // math::add<NV>
		auto& peak18 = this->getT(0).getT(0).getT(7).getT(0).getT(1);                          // Sm2_impl::peak18_t
		auto& clear23 = this->getT(0).getT(0).getT(7).getT(0).getT(2);                         // math::clear<NV>
		auto& split5 = this->getT(0).getT(0).getT(7).getT(0).getT(3);                          // Sm2_impl::split5_t<NV>
		auto& chain184 = this->getT(0).getT(0).getT(7).getT(0).getT(3).getT(0);                // Sm2_impl::chain184_t<NV>
		auto& pma_unscaled7 = this->getT(0).getT(0).getT(7).getT(0).getT(3).getT(0).getT(0);   // Sm2_impl::pma_unscaled7_t<NV>
		auto& add45 = this->getT(0).getT(0).getT(7).getT(0).getT(3).getT(0).getT(1);           // math::add<NV>
		auto& chain124 = this->getT(0).getT(0).getT(7).getT(0).getT(3).getT(1);                // Sm2_impl::chain124_t<NV>
		auto& global_mod5 = this->getT(0).getT(0).getT(7).getT(0).getT(3).getT(1).getT(0);     // Sm2_impl::global_mod5_t<NV>
		auto& add93 = this->getT(0).getT(0).getT(7).getT(0).getT(3).getT(1).getT(1);           // math::add<NV>
		auto& chain117 = this->getT(0).getT(0).getT(7).getT(0).getT(4);                        // Sm2_impl::chain117_t<NV>
		auto& peak14 = this->getT(0).getT(0).getT(7).getT(0).getT(4).getT(0);                  // Sm2_impl::peak14_t<NV>
		auto& modchain6 = this->getT(0).getT(0).getT(8);                                       // Sm2_impl::modchain6_t<NV>
		auto& chain127 = this->getT(0).getT(0).getT(8).getT(0);                                // Sm2_impl::chain127_t<NV>
		auto& branch20 = this->getT(0).getT(0).getT(8).getT(0).getT(0);                        // Sm2_impl::branch20_t<NV>
		auto& chain129 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(0);                // Sm2_impl::chain129_t<NV>
		auto& add70 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain130 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(1);                // Sm2_impl::chain130_t<NV>
		auto& add71 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(1).getT(0);           // math::add<NV>
		auto& chain148 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(2);                // Sm2_impl::chain148_t<NV>
		auto& add85 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(2).getT(0);           // math::add<NV>
		auto& chain128 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(3);                // Sm2_impl::chain128_t<NV>
		auto& add69 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(3).getT(0);           // math::add<NV>
		auto& chain196 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(4);                // Sm2_impl::chain196_t<NV>
		auto& add103 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(4).getT(0);          // math::add<NV>
		auto& chain199 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(5);                // Sm2_impl::chain199_t<NV>
		auto& add106 = this->getT(0).getT(0).getT(8).getT(0).getT(0).getT(5).getT(0);          // math::add<NV>
		auto& peak20 = this->getT(0).getT(0).getT(8).getT(0).getT(1);                          // Sm2_impl::peak20_t
		auto& clear20 = this->getT(0).getT(0).getT(8).getT(0).getT(2);                         // math::clear<NV>
		auto& split9 = this->getT(0).getT(0).getT(8).getT(0).getT(3);                          // Sm2_impl::split9_t<NV>
		auto& chain185 = this->getT(0).getT(0).getT(8).getT(0).getT(3).getT(0);                // Sm2_impl::chain185_t<NV>
		auto& pma_unscaled8 = this->getT(0).getT(0).getT(8).getT(0).getT(3).getT(0).getT(0);   // Sm2_impl::pma_unscaled8_t<NV>
		auto& add46 = this->getT(0).getT(0).getT(8).getT(0).getT(3).getT(0).getT(1);           // math::add<NV>
		auto& chain131 = this->getT(0).getT(0).getT(8).getT(0).getT(3).getT(1);                // Sm2_impl::chain131_t<NV>
		auto& chain151 = this->getT(0).getT(0).getT(8).getT(0).getT(3).getT(1).getT(0);        // Sm2_impl::chain151_t<NV>
		auto& global_mod6 = this->getT(0).getT(0).getT(8).getT(0).                             // Sm2_impl::global_mod6_t<NV>
                            getT(3).getT(1).getT(0).getT(0);
		auto& add94 = this->getT(0).getT(0).getT(8).getT(0).                                   // math::add<NV>
                      getT(3).getT(1).getT(0).getT(1);
		auto& peak = this->getT(0).getT(0).getT(8).getT(0).getT(4);                            // Sm2_impl::peak_t<NV>
		auto& modchain16 = this->getT(0).getT(0).getT(9);                                      // Sm2_impl::modchain16_t<NV>
		auto& chain271 = this->getT(0).getT(0).getT(9).getT(0);                                // Sm2_impl::chain271_t<NV>
		auto& branch32 = this->getT(0).getT(0).getT(9).getT(0).getT(0);                        // Sm2_impl::branch32_t<NV>
		auto& chain272 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(0);                // Sm2_impl::chain272_t<NV>
		auto& add147 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(0).getT(0);          // math::add<NV>
		auto& chain273 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(1);                // Sm2_impl::chain273_t<NV>
		auto& add148 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(1).getT(0);          // math::add<NV>
		auto& chain274 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(2);                // Sm2_impl::chain274_t<NV>
		auto& add149 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(2).getT(0);          // math::add<NV>
		auto& chain275 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(3);                // Sm2_impl::chain275_t<NV>
		auto& add150 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(3).getT(0);          // math::add<NV>
		auto& chain276 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(4);                // Sm2_impl::chain276_t<NV>
		auto& add151 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(4).getT(0);          // math::add<NV>
		auto& chain277 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(5);                // Sm2_impl::chain277_t<NV>
		auto& add152 = this->getT(0).getT(0).getT(9).getT(0).getT(0).getT(5).getT(0);          // math::add<NV>
		auto& peak38 = this->getT(0).getT(0).getT(9).getT(0).getT(1);                          // Sm2_impl::peak38_t
		auto& clear30 = this->getT(0).getT(0).getT(9).getT(0).getT(2);                         // math::clear<NV>
		auto& split38 = this->getT(0).getT(0).getT(9).getT(0).getT(3);                         // Sm2_impl::split38_t<NV>
		auto& chain278 = this->getT(0).getT(0).getT(9).getT(0).getT(3).getT(0);                // Sm2_impl::chain278_t<NV>
		auto& pma_unscaled17 = this->getT(0).getT(0).getT(9).getT(0).getT(3).getT(0).getT(0);  // Sm2_impl::pma_unscaled17_t<NV>
		auto& add153 = this->getT(0).getT(0).getT(9).getT(0).getT(3).getT(0).getT(1);          // math::add<NV>
		auto& chain279 = this->getT(0).getT(0).getT(9).getT(0).getT(3).getT(1);                // Sm2_impl::chain279_t<NV>
		auto& chain280 = this->getT(0).getT(0).getT(9).getT(0).getT(3).getT(1).getT(0);        // Sm2_impl::chain280_t<NV>
		auto& global_mod15 = this->getT(0).getT(0).getT(9).getT(0).                            // Sm2_impl::global_mod15_t<NV>
                             getT(3).getT(1).getT(0).getT(0);
		auto& add154 = this->getT(0).getT(0).getT(9).getT(0).                                  // math::add<NV>
                       getT(3).getT(1).getT(0).getT(1);
		auto& peak39 = this->getT(0).getT(0).getT(9).getT(0).getT(4);                          // Sm2_impl::peak39_t<NV>
		auto& modchain7 = this->getT(0).getT(0).getT(10);                                      // Sm2_impl::modchain7_t<NV>
		auto& chain134 = this->getT(0).getT(0).getT(10).getT(0);                               // Sm2_impl::chain134_t<NV>
		auto& branch21 = this->getT(0).getT(0).getT(10).getT(0).getT(0);                       // Sm2_impl::branch21_t<NV>
		auto& chain136 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(0);               // Sm2_impl::chain136_t<NV>
		auto& add75 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(0).getT(0);          // math::add<NV>
		auto& chain137 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(1);               // Sm2_impl::chain137_t<NV>
		auto& add76 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(1).getT(0);          // math::add<NV>
		auto& chain149 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(2);               // Sm2_impl::chain149_t<NV>
		auto& add86 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(2).getT(0);          // math::add<NV>
		auto& chain135 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(3);               // Sm2_impl::chain135_t<NV>
		auto& add74 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(3).getT(0);          // math::add<NV>
		auto& chain193 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(4);               // Sm2_impl::chain193_t<NV>
		auto& add100 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(4).getT(0);         // math::add<NV>
		auto& chain200 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(5);               // Sm2_impl::chain200_t<NV>
		auto& add107 = this->getT(0).getT(0).getT(10).getT(0).getT(0).getT(5).getT(0);         // math::add<NV>
		auto& peak22 = this->getT(0).getT(0).getT(10).getT(0).getT(1);                         // Sm2_impl::peak22_t<NV>
		auto& clear21 = this->getT(0).getT(0).getT(10).getT(0).getT(2);                        // math::clear<NV>
		auto& chain138 = this->getT(0).getT(0).getT(10).getT(0).getT(3);                       // Sm2_impl::chain138_t<NV>
		auto& split13 = this->getT(0).getT(0).getT(10).getT(0).getT(3).getT(0);                // Sm2_impl::split13_t<NV>
		auto& chain186 = this->getT(0).getT(0).getT(10).getT(0).getT(3).getT(0).getT(0);       // Sm2_impl::chain186_t<NV>
		auto& pma_unscaled9 = this->getT(0).getT(0).getT(10).getT(0).                          // Sm2_impl::pma_unscaled9_t<NV>
                              getT(3).getT(0).getT(0).getT(0);
		auto& add47 = this->getT(0).getT(0).getT(10).getT(0).                                  // math::add<NV>
                      getT(3).getT(0).getT(0).getT(1);
		auto& chain187 = this->getT(0).getT(0).getT(10).getT(0).getT(3).getT(0).getT(1);       // Sm2_impl::chain187_t<NV>
		auto& chain188 = this->getT(0).getT(0).getT(10).getT(0).                               // Sm2_impl::chain188_t<NV>
                         getT(3).getT(0).getT(1).getT(0);
		auto& global_mod9 = this->getT(0).getT(0).getT(10).getT(0).                            // Sm2_impl::global_mod9_t<NV>
                            getT(3).getT(0).getT(1).getT(0).
                            getT(0);
		auto& add97 = this->getT(0).getT(0).getT(10).getT(0).                                  // math::add<NV>
                      getT(3).getT(0).getT(1).getT(0).
                      getT(1);
		auto& peak23 = this->getT(0).getT(0).getT(10).getT(0).getT(3).getT(1);                 // Sm2_impl::peak23_t<NV>
		auto& modchain10 = this->getT(0).getT(0).getT(11);                                     // Sm2_impl::modchain10_t<NV>
		auto& chain202 = this->getT(0).getT(0).getT(11).getT(0);                               // Sm2_impl::chain202_t<NV>
		auto& branch23 = this->getT(0).getT(0).getT(11).getT(0).getT(0);                       // Sm2_impl::branch23_t<NV>
		auto& chain204 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(0);               // Sm2_impl::chain204_t<NV>
		auto& add110 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(0).getT(0);         // math::add<NV>
		auto& chain205 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(1);               // Sm2_impl::chain205_t<NV>
		auto& add111 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(1).getT(0);         // math::add<NV>
		auto& chain206 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(2);               // Sm2_impl::chain206_t<NV>
		auto& add112 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(2).getT(0);         // math::add<NV>
		auto& chain203 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(3);               // Sm2_impl::chain203_t<NV>
		auto& add109 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(3).getT(0);         // math::add<NV>
		auto& chain207 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(4);               // Sm2_impl::chain207_t<NV>
		auto& add113 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(4).getT(0);         // math::add<NV>
		auto& chain208 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(5);               // Sm2_impl::chain208_t<NV>
		auto& add114 = this->getT(0).getT(0).getT(11).getT(0).getT(0).getT(5).getT(0);         // math::add<NV>
		auto& peak26 = this->getT(0).getT(0).getT(11).getT(0).getT(1);                         // Sm2_impl::peak26_t<NV>
		auto& clear24 = this->getT(0).getT(0).getT(11).getT(0).getT(2);                        // math::clear<NV>
		auto& chain209 = this->getT(0).getT(0).getT(11).getT(0).getT(3);                       // Sm2_impl::chain209_t<NV>
		auto& split33 = this->getT(0).getT(0).getT(11).getT(0).getT(3).getT(0);                // Sm2_impl::split33_t<NV>
		auto& chain210 = this->getT(0).getT(0).getT(11).getT(0).getT(3).getT(0).getT(0);       // Sm2_impl::chain210_t<NV>
		auto& pma_unscaled11 = this->getT(0).getT(0).getT(11).getT(0).                         // Sm2_impl::pma_unscaled11_t<NV>
                               getT(3).getT(0).getT(0).getT(0);
		auto& add54 = this->getT(0).getT(0).getT(11).getT(0).                                  // math::add<NV>
                      getT(3).getT(0).getT(0).getT(1);
		auto& chain211 = this->getT(0).getT(0).getT(11).getT(0).getT(3).getT(0).getT(1);       // Sm2_impl::chain211_t<NV>
		auto& chain212 = this->getT(0).getT(0).getT(11).getT(0).                               // Sm2_impl::chain212_t<NV>
                         getT(3).getT(0).getT(1).getT(0);
		auto& global_mod11 = this->getT(0).getT(0).getT(11).getT(0).                           // Sm2_impl::global_mod11_t<NV>
                             getT(3).getT(0).getT(1).getT(0).
                             getT(0);
		auto& add115 = this->getT(0).getT(0).getT(11).getT(0).                                 // math::add<NV>
                       getT(3).getT(0).getT(1).getT(0).
                       getT(1);
		auto& peak27 = this->getT(0).getT(0).getT(11).getT(0).getT(3).getT(1);                 // Sm2_impl::peak27_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(11).getT(0).getT(3).getT(2);                  // math::add<NV>
		auto& modchain8 = this->getT(0).getT(0).getT(12);                                      // Sm2_impl::modchain8_t<NV>
		auto& chain141 = this->getT(0).getT(0).getT(12).getT(0);                               // Sm2_impl::chain141_t<NV>
		auto& branch22 = this->getT(0).getT(0).getT(12).getT(0).getT(0);                       // Sm2_impl::branch22_t<NV>
		auto& chain143 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(0);               // Sm2_impl::chain143_t<NV>
		auto& add80 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(0).getT(0);          // math::add<NV>
		auto& chain144 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(1);               // Sm2_impl::chain144_t<NV>
		auto& add81 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(1).getT(0);          // math::add<NV>
		auto& chain150 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(2);               // Sm2_impl::chain150_t<NV>
		auto& add87 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(2).getT(0);          // math::add<NV>
		auto& chain142 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(3);               // Sm2_impl::chain142_t<NV>
		auto& add79 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(3).getT(0);          // math::add<NV>
		auto& chain192 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(4);               // Sm2_impl::chain192_t<NV>
		auto& add99 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(4).getT(0);          // math::add<NV>
		auto& chain201 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(5);               // Sm2_impl::chain201_t<NV>
		auto& add108 = this->getT(0).getT(0).getT(12).getT(0).getT(0).getT(5).getT(0);         // math::add<NV>
		auto& peak24 = this->getT(0).getT(0).getT(12).getT(0).getT(1);                         // Sm2_impl::peak24_t<NV>
		auto& clear22 = this->getT(0).getT(0).getT(12).getT(0).getT(2);                        // math::clear<NV>
		auto& split19 = this->getT(0).getT(0).getT(12).getT(0).getT(3);                        // Sm2_impl::split19_t<NV>
		auto& chain189 = this->getT(0).getT(0).getT(12).getT(0).getT(3).getT(0);               // Sm2_impl::chain189_t<NV>
		auto& pma_unscaled10 = this->getT(0).getT(0).getT(12).getT(0).getT(3).getT(0).getT(0); // Sm2_impl::pma_unscaled10_t<NV>
		auto& add48 = this->getT(0).getT(0).getT(12).getT(0).getT(3).getT(0).getT(1);          // math::add<NV>
		auto& chain190 = this->getT(0).getT(0).getT(12).getT(0).getT(3).getT(1);               // Sm2_impl::chain190_t<NV>
		auto& chain191 = this->getT(0).getT(0).getT(12).getT(0).getT(3).getT(1).getT(0);       // Sm2_impl::chain191_t<NV>
		auto& global_mod10 = this->getT(0).getT(0).getT(12).getT(0).                           // Sm2_impl::global_mod10_t<NV>
                             getT(3).getT(1).getT(0).getT(0);
		auto& add98 = this->getT(0).getT(0).getT(12).getT(0).                                  // math::add<NV>
                      getT(3).getT(1).getT(0).getT(1);
		auto& peak25 = this->getT(0).getT(0).getT(12).getT(0).getT(4);                         // Sm2_impl::peak25_t<NV>
		auto& modchain11 = this->getT(0).getT(0).getT(13);                                     // Sm2_impl::modchain11_t<NV>
		auto& chain213 = this->getT(0).getT(0).getT(13).getT(0);                               // Sm2_impl::chain213_t<NV>
		auto& branch25 = this->getT(0).getT(0).getT(13).getT(0).getT(0);                       // Sm2_impl::branch25_t<NV>
		auto& chain215 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(0);               // Sm2_impl::chain215_t<NV>
		auto& add117 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(0).getT(0);         // math::add<NV>
		auto& chain216 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(1);               // Sm2_impl::chain216_t<NV>
		auto& add118 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(1).getT(0);         // math::add<NV>
		auto& chain217 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(2);               // Sm2_impl::chain217_t<NV>
		auto& add119 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(2).getT(0);         // math::add<NV>
		auto& chain214 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(3);               // Sm2_impl::chain214_t<NV>
		auto& add116 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(3).getT(0);         // math::add<NV>
		auto& chain218 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(4);               // Sm2_impl::chain218_t<NV>
		auto& add120 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(4).getT(0);         // math::add<NV>
		auto& chain219 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(5);               // Sm2_impl::chain219_t<NV>
		auto& add121 = this->getT(0).getT(0).getT(13).getT(0).getT(0).getT(5).getT(0);         // math::add<NV>
		auto& peak28 = this->getT(0).getT(0).getT(13).getT(0).getT(1);                         // Sm2_impl::peak28_t<NV>
		auto& clear25 = this->getT(0).getT(0).getT(13).getT(0).getT(2);                        // math::clear<NV>
		auto& split34 = this->getT(0).getT(0).getT(13).getT(0).getT(3);                        // Sm2_impl::split34_t<NV>
		auto& chain220 = this->getT(0).getT(0).getT(13).getT(0).getT(3).getT(0);               // Sm2_impl::chain220_t<NV>
		auto& pma_unscaled12 = this->getT(0).getT(0).getT(13).getT(0).getT(3).getT(0).getT(0); // Sm2_impl::pma_unscaled12_t<NV>
		auto& add58 = this->getT(0).getT(0).getT(13).getT(0).getT(3).getT(0).getT(1);          // math::add<NV>
		auto& chain221 = this->getT(0).getT(0).getT(13).getT(0).getT(3).getT(1);               // Sm2_impl::chain221_t<NV>
		auto& chain222 = this->getT(0).getT(0).getT(13).getT(0).getT(3).getT(1).getT(0);       // Sm2_impl::chain222_t<NV>
		auto& global_mod12 = this->getT(0).getT(0).getT(13).getT(0).                           // Sm2_impl::global_mod12_t<NV>
                             getT(3).getT(1).getT(0).getT(0);
		auto& add122 = this->getT(0).getT(0).getT(13).getT(0).                             // math::add<NV>
                       getT(3).getT(1).getT(0).getT(1);
		auto& peak29 = this->getT(0).getT(0).getT(13).getT(0).getT(4);                     // Sm2_impl::peak29_t<NV>
		auto& split = this->getT(0).getT(1);                                               // Sm2_impl::split_t<NV>
		auto& chain = this->getT(0).getT(1).getT(0);                                       // Sm2_impl::chain_t<NV>
		auto& chain8 = this->getT(0).getT(1).getT(0).getT(0);                              // Sm2_impl::chain8_t<NV>
		auto& chain2 = this->getT(0).getT(1).getT(0).getT(0).getT(0);                      // Sm2_impl::chain2_t<NV>
		auto& split2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);              // Sm2_impl::split2_t<NV>
		auto& chain17 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);     // Sm2_impl::chain17_t<NV>
		auto& branch28 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::branch28_t<NV>
                         getT(0).getT(0).getT(0).getT(0);
		auto& chain235 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain235_t<NV>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(0);
		auto& receive22 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(0).getT(0).getT(0).getT(0);
		auto& chain236 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain236_t<NV>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(1);
		auto& receive30 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(0).getT(0).getT(1).getT(0);
		auto& chain267 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain267_t<NV>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(2);
		auto& receive37 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(0).getT(0).getT(2).getT(0);
		auto& chain237 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain237_t<NV>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(3);
		auto& receive31 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(0).getT(0).getT(3).getT(0);
		auto& chain238 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain238_t<NV>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(4);
		auto& receive32 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(0).getT(0).getT(4).getT(0);
		auto& gain1 = this->getT(0).getT(1).getT(0).getT(0).                               // core::gain<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& branch2 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::branch2_t<NV>
                        getT(0).getT(0).getT(0).getT(2);
		auto& chain15 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain15_t<NV>
                        getT(0).getT(0).getT(0).getT(2).
                        getT(0);
		auto& converter2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                  // Sm2_impl::converter2_t<NV>
                           getT(0).getT(0).getT(2).getT(0).getT(0);
		auto& phasor_fm1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                  // core::phasor_fm<NV>
                           getT(0).getT(0).getT(2).getT(0).getT(1);
		auto& chain16 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain16_t<NV>
                        getT(0).getT(0).getT(0).getT(2).
                        getT(1);
		auto& tempo_sync = this->getT(0).getT(1).getT(0).getT(0).getT(0).                  // Sm2_impl::tempo_sync_t<NV>
                           getT(0).getT(0).getT(2).getT(1).getT(0);
		auto& converter = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::converter_t<NV>
                          getT(0).getT(0).getT(2).getT(1).getT(1);
		auto& phasor_fm2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                  // core::phasor_fm<NV>
                           getT(0).getT(0).getT(2).getT(1).getT(2);
		auto& mono2stereo3 = this->getT(0).getT(1).getT(0).getT(0).                        // core::mono2stereo
                             getT(0).getT(0).getT(0).getT(3);
		auto& branch = this->getT(0).getT(1).getT(0).getT(0).                              // Sm2_impl::branch_t<NV>
                       getT(0).getT(0).getT(0).getT(4);
		auto& chain1 = this->getT(0).getT(1).getT(0).getT(0).                              // Sm2_impl::chain1_t<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(0);
		auto& gain9 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // core::gain<NV>
                      getT(0).getT(0).getT(4).getT(0).getT(0);
		auto& pi1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                         // math::pi<NV>
                    getT(0).getT(0).getT(4).getT(0).getT(1);
		auto& expr = this->getT(0).getT(1).getT(0).getT(0).getT(0).                        // math::expr<NV, custom::expr>
                     getT(0).getT(0).getT(4).getT(0).getT(2);
		auto& chain111 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain111_t<NV>
                         getT(0).getT(0).getT(0).getT(4).
                         getT(1);
		auto& gain37 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(0).getT(4).getT(1).getT(0);
		auto& fmod12 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::fmod<NV>
                       getT(0).getT(0).getT(4).getT(1).getT(1);
		auto& expr13 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr13>
                       getT(0).getT(0).getT(4).getT(1).getT(2);
		auto& chain10 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain10_t<NV>
                        getT(0).getT(0).getT(0).getT(4).
                        getT(2);
		auto& smoothed_parameter4 = this->getT(0).getT(1).getT(0).getT(0).getT(0).         // Sm2_impl::smoothed_parameter4_t<NV>
                                    getT(0).getT(0).getT(4).getT(2).getT(0);
		auto& expr3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr3>
                      getT(0).getT(0).getT(4).getT(2).getT(1);
		auto& expr2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr2>
                      getT(0).getT(0).getT(4).getT(2).getT(2);
		auto& chain11 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain11_t<NV>
                        getT(0).getT(0).getT(0).getT(4).
                        getT(3);
		auto& smoothed_parameter1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).         // Sm2_impl::smoothed_parameter1_t<NV>
                                    getT(0).getT(0).getT(4).getT(3).getT(0);
		auto& expr6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr6>
                      getT(0).getT(0).getT(4).getT(3).getT(1);
		auto& expr4 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr4>
                      getT(0).getT(0).getT(4).getT(3).getT(2);
		auto& expr5 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr5>
                      getT(0).getT(0).getT(4).getT(3).getT(3);
		auto& chain5 = this->getT(0).getT(1).getT(0).getT(0).                              // Sm2_impl::chain5_t<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(4);
		auto& fmod = this->getT(0).getT(1).getT(0).getT(0).getT(0).                        // wrap::no_process<math::fmod<NV>>
                     getT(0).getT(0).getT(4).getT(4).getT(0);
		auto& pi = this->getT(0).getT(1).getT(0).getT(0).getT(0).                          // math::pi<NV>
                   getT(0).getT(0).getT(4).getT(4).getT(1);
		auto& gain3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // core::gain<NV>
                      getT(0).getT(0).getT(4).getT(4).getT(2);
		auto& table = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // Sm2_impl::table_t
                      getT(0).getT(0).getT(4).getT(4).getT(3);
		auto& chain109 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain109_t<NV>
                         getT(0).getT(0).getT(0).getT(4).
                         getT(5);
		auto& pi6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                         // wrap::no_process<math::pi<NV>>
                    getT(0).getT(0).getT(4).getT(5).getT(0);
		auto& gain35 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(0).getT(4).getT(5).getT(1);
		auto& fmod10 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::fmod<NV>
                       getT(0).getT(0).getT(4).getT(5).getT(2);
		auto& table10 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                     // Sm2_impl::table10_t
                        getT(0).getT(0).getT(4).getT(5).getT(3);
		auto& chain3 = this->getT(0).getT(1).getT(0).getT(0).                              // Sm2_impl::chain3_t<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(6);
		auto& gain6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // core::gain<NV>
                      getT(0).getT(0).getT(4).getT(6).getT(0);
		auto& rect = this->getT(0).getT(1).getT(0).getT(0).getT(0).                        // math::rect<NV>
                     getT(0).getT(0).getT(4).getT(6).getT(1);
		auto& chain4 = this->getT(0).getT(1).getT(0).getT(0).                              // Sm2_impl::chain4_t<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(7);
		auto& gain4 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // core::gain<NV>
                      getT(0).getT(0).getT(4).getT(7).getT(0);
		auto& fmod2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::fmod<NV>
                      getT(0).getT(0).getT(4).getT(7).getT(1);
		auto& pi2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                         // wrap::no_process<math::pi<NV>>
                    getT(0).getT(0).getT(4).getT(7).getT(2);
		auto& rect1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::rect<NV>
                      getT(0).getT(0).getT(4).getT(7).getT(3);
		auto& chain12 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain12_t<NV>
                        getT(0).getT(0).getT(0).getT(4).
                        getT(8);
		auto& gain13 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(0).getT(4).getT(8).getT(0);
		auto& table2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table2_t
                       getT(0).getT(0).getT(4).getT(8).getT(1);
		auto& chain6 = this->getT(0).getT(1).getT(0).getT(0).                              // Sm2_impl::chain6_t<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(9);
		auto& gain7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // core::gain<NV>
                      getT(0).getT(0).getT(4).getT(9).getT(0);
		auto& fmod4 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::fmod<NV>
                      getT(0).getT(0).getT(4).getT(9).getT(1);
		auto& table1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table1_t
                       getT(0).getT(0).getT(4).getT(9).getT(2);
		auto& chain13 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain13_t<NV>
                        getT(0).getT(0).getT(0).getT(4).
                        getT(10);
		auto& gain14 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(0).getT(4).getT(10).getT(0);
		auto& table3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table3_t
                       getT(0).getT(0).getT(4).getT(10).getT(1);
		auto& chain14 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain14_t<NV>
                        getT(0).getT(0).getT(0).getT(4).
                        getT(11);
		auto& gain15 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(0).getT(4).getT(11).getT(0);
		auto& fmod6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::fmod<NV>
                      getT(0).getT(0).getT(4).getT(11).getT(1);
		auto& table4 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table4_t
                       getT(0).getT(0).getT(4).getT(11).getT(2);
		auto& chain89 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain89_t<NV>
                        getT(0).getT(0).getT(0).getT(5);
		auto& split20 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::split20_t<NV>
                        getT(0).getT(0).getT(0).getT(5).
                        getT(0);
		auto& chain90 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                     // Sm2_impl::chain90_t
                        getT(0).getT(0).getT(5).getT(0).getT(0);
		auto& chain91 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                     // Sm2_impl::chain91_t<NV>
                        getT(0).getT(0).getT(5).getT(0).getT(1);
		auto& split21 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                     // Sm2_impl::split21_t<NV>
                        getT(0).getT(0).getT(5).getT(0).getT(1).
                        getT(0);
		auto& send9 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).               // routing::send<NV, stereo_cable<NV>>
                      getT(0).getT(5).getT(0).getT(1).getT(0).getT(0);
		auto& chain36 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).             // Sm2_impl::chain36_t<NV>
                        getT(0).getT(5).getT(0).getT(1).getT(0).getT(1);
		auto& sig2mod = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).             // math::sig2mod<NV>
                        getT(0).getT(5).getT(0).getT(1).getT(0).getT(1).
                        getT(0);
		auto& oscilloscope = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).        // Sm2_impl::oscilloscope_t
                             getT(0).getT(5).getT(0).getT(1).getT(0).getT(1).
                             getT(1);
		auto& peak15 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).              // Sm2_impl::peak15_t<NV>
                       getT(0).getT(5).getT(0).getT(1).getT(0).getT(1).
                       getT(2);
		auto& clear9 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).              // math::clear<NV>
                       getT(0).getT(5).getT(0).getT(1).getT(0).getT(1).
                       getT(3);
		auto& clear7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::clear<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(1).
                       getT(1);
		auto& chain18 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);     // Sm2_impl::chain18_t<NV>
		auto& branch27 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::branch27_t<NV>
                         getT(0).getT(0).getT(1).getT(0);
		auto& chain228 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain228_t<NV>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(0);
		auto& receive11 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& chain230 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain230_t<NV>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(1);
		auto& receive25 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& chain268 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain268_t<NV>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(2);
		auto& receive38 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(1).getT(0).getT(2).getT(0);
		auto& chain229 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain229_t<NV>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(3);
		auto& receive24 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(1).getT(0).getT(3).getT(0);
		auto& chain231 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain231_t<NV>
                         getT(0).getT(0).getT(1).getT(0).
                         getT(4);
		auto& receive26 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // routing::receive<NV, stereo_cable<NV>>
                          getT(0).getT(1).getT(0).getT(4).getT(0);
		auto& gain32 = this->getT(0).getT(1).getT(0).getT(0).                              // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1);
		auto& branch5 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::branch5_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& chain31 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain31_t<NV>
                        getT(0).getT(0).getT(1).getT(2).
                        getT(0);
		auto& converter3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                  // Sm2_impl::converter3_t<NV>
                           getT(0).getT(1).getT(2).getT(0).getT(0);
		auto& phasor_fm = this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // core::phasor_fm<NV>
                          getT(0).getT(1).getT(2).getT(0).getT(1);
		auto& chain32 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain32_t<NV>
                        getT(0).getT(0).getT(1).getT(2).
                        getT(1);
		auto& tempo_sync2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                 // Sm2_impl::tempo_sync2_t<NV>
                            getT(0).getT(1).getT(2).getT(1).getT(0);
		auto& converter1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                  // Sm2_impl::converter1_t<NV>
                           getT(0).getT(1).getT(2).getT(1).getT(1);
		auto& phasor_fm3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                  // core::phasor_fm<NV>
                           getT(0).getT(1).getT(2).getT(1).getT(2);
		auto& mono2stereo = this->getT(0).getT(1).getT(0).getT(0).                         // core::mono2stereo
                            getT(0).getT(0).getT(1).getT(3);
		auto& branch4 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::branch4_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& chain21 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain21_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(0);
		auto& gain10 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(0).getT(0);
		auto& pi3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                         // math::pi<NV>
                    getT(0).getT(1).getT(4).getT(0).getT(1);
		auto& expr1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr1>
                      getT(0).getT(1).getT(4).getT(0).getT(2);
		auto& chain118 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain118_t<NV>
                         getT(0).getT(0).getT(1).getT(4).
                         getT(1);
		auto& gain39 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(1).getT(0);
		auto& fmod13 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::fmod<NV>
                       getT(0).getT(1).getT(4).getT(1).getT(1);
		auto& expr14 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr14>
                       getT(0).getT(1).getT(4).getT(1).getT(2);
		auto& chain22 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain22_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(2);
		auto& smoothed_parameter5 = this->getT(0).getT(1).getT(0).getT(0).getT(0).         // Sm2_impl::smoothed_parameter5_t<NV>
                                    getT(0).getT(1).getT(4).getT(2).getT(0);
		auto& expr7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr7>
                      getT(0).getT(1).getT(4).getT(2).getT(1);
		auto& expr8 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr8>
                      getT(0).getT(1).getT(4).getT(2).getT(2);
		auto& chain23 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain23_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(3);
		auto& smoothed_parameter2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).         // Sm2_impl::smoothed_parameter2_t<NV>
                                    getT(0).getT(1).getT(4).getT(3).getT(0);
		auto& expr9 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::expr<NV, custom::expr9>
                      getT(0).getT(1).getT(4).getT(3).getT(1);
		auto& expr10 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr10>
                       getT(0).getT(1).getT(4).getT(3).getT(2);
		auto& expr11 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::expr<NV, custom::expr11>
                       getT(0).getT(1).getT(4).getT(3).getT(3);
		auto& chain24 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain24_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(4);
		auto& fmod1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // wrap::no_process<math::fmod<NV>>
                      getT(0).getT(1).getT(4).getT(4).getT(0);
		auto& pi4 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                         // math::pi<NV>
                    getT(0).getT(1).getT(4).getT(4).getT(1);
		auto& gain5 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // core::gain<NV>
                      getT(0).getT(1).getT(4).getT(4).getT(2);
		auto& table5 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table5_t
                       getT(0).getT(1).getT(4).getT(4).getT(3);
		auto& chain132 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain132_t<NV>
                         getT(0).getT(0).getT(1).getT(4).
                         getT(5);
		auto& pi7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                         // wrap::no_process<math::pi<NV>>
                    getT(0).getT(1).getT(4).getT(5).getT(0);
		auto& gain36 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(5).getT(1);
		auto& fmod11 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // math::fmod<NV>
                       getT(0).getT(1).getT(4).getT(5).getT(2);
		auto& table11 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                     // Sm2_impl::table11_t
                        getT(0).getT(1).getT(4).getT(5).getT(3);
		auto& chain25 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain25_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(6);
		auto& gain11 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(6).getT(0);
		auto& rect2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::rect<NV>
                      getT(0).getT(1).getT(4).getT(6).getT(1);
		auto& chain26 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain26_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(7);
		auto& gain12 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(7).getT(0);
		auto& fmod3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::fmod<NV>
                      getT(0).getT(1).getT(4).getT(7).getT(1);
		auto& pi5 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                         // wrap::no_process<math::pi<NV>>
                    getT(0).getT(1).getT(4).getT(7).getT(2);
		auto& rect3 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::rect<NV>
                      getT(0).getT(1).getT(4).getT(7).getT(3);
		auto& chain27 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain27_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(8);
		auto& gain16 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(8).getT(0);
		auto& table6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table6_t
                       getT(0).getT(1).getT(4).getT(8).getT(1);
		auto& chain28 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain28_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(9);
		auto& gain17 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(9).getT(0);
		auto& fmod5 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::fmod<NV>
                      getT(0).getT(1).getT(4).getT(9).getT(1);
		auto& table7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table7_t
                       getT(0).getT(1).getT(4).getT(9).getT(2);
		auto& chain29 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain29_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(10);
		auto& gain18 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(10).getT(0);
		auto& table8 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table8_t
                       getT(0).getT(1).getT(4).getT(10).getT(1);
		auto& chain30 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::chain30_t<NV>
                        getT(0).getT(0).getT(1).getT(4).
                        getT(11);
		auto& gain19 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(11).getT(0);
		auto& fmod7 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                       // math::fmod<NV>
                      getT(0).getT(1).getT(4).getT(11).getT(1);
		auto& table9 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                      // Sm2_impl::table9_t
                       getT(0).getT(1).getT(4).getT(11).getT(2);
		auto& chain177 = this->getT(0).getT(1).getT(0).getT(0).                            // Sm2_impl::chain177_t<NV>
                         getT(0).getT(0).getT(1).getT(5);
		auto& split31 = this->getT(0).getT(1).getT(0).getT(0).                             // Sm2_impl::split31_t<NV>
                        getT(0).getT(0).getT(1).getT(5).
                        getT(0);
		auto& chain178 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                    // Sm2_impl::chain178_t
                         getT(0).getT(1).getT(5).getT(0).getT(0);
		auto& chain179 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                    // Sm2_impl::chain179_t<NV>
                         getT(0).getT(1).getT(5).getT(0).getT(1);
		auto& sig2mod2 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                    // math::sig2mod<NV>
                         getT(0).getT(1).getT(5).getT(0).getT(1).
                         getT(0);
		auto& split32 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                     // Sm2_impl::split32_t<NV>
                        getT(0).getT(1).getT(5).getT(0).getT(1).
                        getT(1);
		auto& send16 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).              // routing::send<NV, stereo_cable<NV>>
                       getT(1).getT(5).getT(0).getT(1).getT(1).getT(0);
		auto& chain46 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).             // Sm2_impl::chain46_t<NV>
                        getT(1).getT(5).getT(0).getT(1).getT(1).getT(1);
		auto& oscilloscope1 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).       // Sm2_impl::oscilloscope1_t
                              getT(1).getT(5).getT(0).getT(1).getT(1).getT(1).
                              getT(0);
		auto& peak34 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).              // Sm2_impl::peak34_t<NV>
                       getT(1).getT(5).getT(0).getT(1).getT(1).getT(1).
                       getT(1);
		auto& clear8 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).              // math::clear<NV>
                       getT(1).getT(5).getT(0).getT(1).getT(1).getT(1).
                       getT(2);
		auto& clear12 = this->getT(0).getT(1).getT(0).getT(0).getT(0).                     // math::clear<NV>
                        getT(0).getT(1).getT(5).getT(0).getT(1).
                        getT(2);
		auto& one_pole9 = this->getT(0).getT(1).getT(0).getT(1);                           // filters::one_pole<NV>
		auto& chain180 = this->getT(0).getT(1).getT(1);                                    // Sm2_impl::chain180_t<NV>
		auto& branch26 = this->getT(0).getT(1).getT(1).getT(0);                            // Sm2_impl::branch26_t<NV>
		auto& chain152 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                    // Sm2_impl::chain152_t<NV>
		auto& receive8 = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(0);            // routing::receive<NV, stereo_cable<NV>>
		auto& chain153 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                    // Sm2_impl::chain153_t<NV>
		auto& receive9 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0);            // routing::receive<NV, stereo_cable<NV>>
		auto& chain269 = this->getT(0).getT(1).getT(1).getT(0).getT(2);                    // Sm2_impl::chain269_t<NV>
		auto& receive39 = this->getT(0).getT(1).getT(1).getT(0).getT(2).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain176 = this->getT(0).getT(1).getT(1).getT(0).getT(3);                    // Sm2_impl::chain176_t<NV>
		auto& receive21 = this->getT(0).getT(1).getT(1).getT(0).getT(3).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain226 = this->getT(0).getT(1).getT(1).getT(0).getT(4);                    // Sm2_impl::chain226_t<NV>
		auto& receive23 = this->getT(0).getT(1).getT(1).getT(0).getT(4).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& one_pole7 = this->getT(0).getT(1).getT(1).getT(1);                           // wrap::no_process<filters::one_pole<NV>>
		auto& gain21 = this->getT(0).getT(1).getT(1).getT(2);                              // core::gain<NV>
		auto& gain20 = this->getT(0).getT(1).getT(1).getT(3);                              // core::gain<NV>
		auto& tempo_sync4 = this->getT(0).getT(1).getT(1).getT(4);                         // Sm2_impl::tempo_sync4_t<NV>
		auto& frame2_block1 = this->getT(0).getT(1).getT(1).getT(5);                       // Sm2_impl::frame2_block1_t<NV>
		auto& chain7 = this->getT(0).getT(1).getT(1).getT(5).getT(0);                      // Sm2_impl::chain7_t<NV>
		auto& split1 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0);              // Sm2_impl::split1_t<NV>
		auto& chain9 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).getT(0);      // Sm2_impl::chain9_t<NV>
		auto& peak4 = this->getT(0).getT(1).getT(1).getT(5).                               // Sm2_impl::peak4_t
                      getT(0).getT(0).getT(0).getT(0);
		auto& split3 = this->getT(0).getT(1).getT(1).getT(5).                              // Sm2_impl::split3_t<NV>
                       getT(0).getT(0).getT(0).getT(1);
		auto& modchain = this->getT(0).getT(1).getT(1).getT(5).                            // Sm2_impl::modchain_t<NV>
                         getT(0).getT(0).getT(0).getT(1).
                         getT(0);
		auto& chain47 = this->getT(0).getT(1).getT(1).getT(5).getT(0).                     // Sm2_impl::chain47_t<NV>
                        getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& clear13 = this->getT(0).getT(1).getT(1).getT(5).getT(0).                     // math::clear<NV>
                        getT(0).getT(0).getT(1).getT(0).getT(0).
                        getT(0);
		auto& ramp = this->getT(0).getT(1).getT(1).getT(5).getT(0).                        // Sm2_impl::ramp_t<NV>
                     getT(0).getT(0).getT(1).getT(0).getT(0).
                     getT(1);
		auto& branch3 = this->getT(0).getT(1).getT(1).getT(5).getT(0).                     // Sm2_impl::branch3_t<NV>
                        getT(0).getT(0).getT(1).getT(0).getT(0).
                        getT(2);
		auto& chain48 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).             // Sm2_impl::chain48_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add7 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).                // math::add<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                     getT(0);
		auto& rect6 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).               // math::rect<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                      getT(1);
		auto& peak1 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).               // Sm2_impl::peak1_t<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                      getT(2);
		auto& input_toggle = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).        // Sm2_impl::input_toggle_t<NV>
                             getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                             getT(3);
		auto& clear = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).               // math::clear<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                      getT(4);
		auto& ahdsr = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).               // Sm2_impl::ahdsr_t<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                      getT(5);
		auto& add8 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).                // math::add<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                     getT(6);
		auto& chain52 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).             // Sm2_impl::chain52_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& clear2 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).              // math::clear<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                       getT(0);
		auto& cable_table1 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).        // Sm2_impl::cable_table1_t<NV>
                             getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                             getT(1);
		auto& cable_table4 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).        // Sm2_impl::cable_table4_t
                             getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                             getT(2);
		auto& cable_table3 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).        // Sm2_impl::cable_table3_t
                             getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                             getT(3);
		auto& add9 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).                // math::add<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                     getT(4);
		auto& chain53 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).             // Sm2_impl::chain53_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& clear1 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).              // math::clear<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                       getT(0);
		auto& cable_pack = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).          // Sm2_impl::cable_pack_t<NV>
                           getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                           getT(1);
		auto& add10 = this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).               // math::add<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                      getT(2);
		auto& peak2 = this->getT(0).getT(1).getT(1).getT(5).getT(0).                       // Sm2_impl::peak2_t<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(0).
                      getT(3);
		auto& pma3 = this->getT(0).getT(1).getT(1).getT(5).                                // Sm2_impl::pma3_t<NV>
                     getT(0).getT(0).getT(0).getT(2);
		auto& smoothed_parameter = this->getT(0).getT(1).getT(1).getT(5).                  // Sm2_impl::smoothed_parameter_t<NV>
                                   getT(0).getT(0).getT(0).getT(3);
		auto& branch1 = this->getT(0).getT(1).getT(1).getT(5).                             // Sm2_impl::branch1_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& add13 = this->getT(0).getT(1).getT(1).getT(5).                               // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add = this->getT(0).getT(1).getT(1).getT(5).                                 // math::add<NV>
                    getT(0).getT(0).getT(0).getT(4).
                    getT(1);
		auto& add12 = this->getT(0).getT(1).getT(1).getT(5).                               // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(2);
		auto& add11 = this->getT(0).getT(1).getT(1).getT(5).                               // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(3);
		auto& add2 = this->getT(0).getT(1).getT(1).getT(5).                                // math::add<NV>
                     getT(0).getT(0).getT(0).getT(4).
                     getT(4);
		auto& add3 = this->getT(0).getT(1).getT(1).getT(5).                                // math::add<NV>
                     getT(0).getT(0).getT(0).getT(4).
                     getT(5);
		auto& add4 = this->getT(0).getT(1).getT(1).getT(5).                                // math::add<NV>
                     getT(0).getT(0).getT(0).getT(4).
                     getT(6);
		auto& add5 = this->getT(0).getT(1).getT(1).getT(5).                                // math::add<NV>
                     getT(0).getT(0).getT(0).getT(4).
                     getT(7);
		auto& add14 = this->getT(0).getT(1).getT(1).getT(5).                               // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(8);
		auto& add6 = this->getT(0).getT(1).getT(1).getT(5).                                // math::add<NV>
                     getT(0).getT(0).getT(0).getT(4).
                     getT(9);
		auto& branch14 = this->getT(0).getT(1).getT(1).getT(5).                            // Sm2_impl::branch14_t<NV>
                         getT(0).getT(0).getT(0).getT(5);
		auto& file_player = this->getT(0).getT(1).getT(1).getT(5).                         // Sm2_impl::file_player_t<NV>
                            getT(0).getT(0).getT(0).getT(5).
                            getT(0);
		auto& file_player2 = this->getT(0).getT(1).getT(1).getT(5).                        // Sm2_impl::file_player2_t<NV>
                             getT(0).getT(0).getT(0).getT(5).
                             getT(1);
		auto& chain19 = this->getT(0).getT(1).getT(1).getT(5).                             // Sm2_impl::chain19_t<NV>
                        getT(0).getT(0).getT(0).getT(6);
		auto& one_pole = this->getT(0).getT(1).getT(1).getT(5).                            // wrap::no_process<filters::one_pole<NV>>
                         getT(0).getT(0).getT(0).getT(6).
                         getT(0);
		auto& chain254 = this->getT(0).getT(1).getT(1).getT(6);                            // Sm2_impl::chain254_t<NV>
		auto& split35 = this->getT(0).getT(1).getT(1).getT(6).getT(0);                     // Sm2_impl::split35_t<NV>
		auto& chain255 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(0);            // Sm2_impl::chain255_t
		auto& chain256 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(1);            // Sm2_impl::chain256_t<NV>
		auto& split36 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(1).getT(0);     // Sm2_impl::split36_t<NV>
		auto& send17 = this->getT(0).getT(1).getT(1).getT(6).                              // routing::send<NV, stereo_cable<NV>>
                       getT(0).getT(1).getT(0).getT(0);
		auto& chain20 = this->getT(0).getT(1).getT(1).getT(6).                             // Sm2_impl::chain20_t<NV>
                        getT(0).getT(1).getT(0).getT(1);
		auto& sig2mod4 = this->getT(0).getT(1).getT(1).getT(6).                            // math::sig2mod<NV>
                         getT(0).getT(1).getT(0).getT(1).
                         getT(0);
		auto& peak31 = this->getT(0).getT(1).getT(1).getT(6).                              // Sm2_impl::peak31_t<NV>
                       getT(0).getT(1).getT(0).getT(1).
                       getT(1);
		auto& chain248 = this->getT(0).getT(1).getT(2);                                    // Sm2_impl::chain248_t<NV>
		auto& branch30 = this->getT(0).getT(1).getT(2).getT(0);                            // Sm2_impl::branch30_t<NV>
		auto& chain250 = this->getT(0).getT(1).getT(2).getT(0).getT(0);                    // Sm2_impl::chain250_t<NV>
		auto& receive10 = this->getT(0).getT(1).getT(2).getT(0).getT(0).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain251 = this->getT(0).getT(1).getT(2).getT(0).getT(1);                    // Sm2_impl::chain251_t<NV>
		auto& receive34 = this->getT(0).getT(1).getT(2).getT(0).getT(1).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain252 = this->getT(0).getT(1).getT(2).getT(0).getT(2);                    // Sm2_impl::chain252_t<NV>
		auto& receive35 = this->getT(0).getT(1).getT(2).getT(0).getT(2).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain253 = this->getT(0).getT(1).getT(2).getT(0).getT(3);                    // Sm2_impl::chain253_t<NV>
		auto& receive36 = this->getT(0).getT(1).getT(2).getT(0).getT(3).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain270 = this->getT(0).getT(1).getT(2).getT(0).getT(4);                    // Sm2_impl::chain270_t<NV>
		auto& receive40 = this->getT(0).getT(1).getT(2).getT(0).getT(4).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& one_pole8 = this->getT(0).getT(1).getT(2).getT(1);                           // filters::one_pole<NV>
		auto& gain22 = this->getT(0).getT(1).getT(2).getT(2);                              // core::gain<NV>
		auto& gain23 = this->getT(0).getT(1).getT(2).getT(3);                              // core::gain<NV>
		auto& frame2_block2 = this->getT(0).getT(1).getT(2).getT(4);                       // Sm2_impl::frame2_block2_t<NV>
		auto& chain33 = this->getT(0).getT(1).getT(2).getT(4).getT(0);                     // Sm2_impl::chain33_t<NV>
		auto& split17 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0);             // Sm2_impl::split17_t<NV>
		auto& chain34 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).getT(0);     // Sm2_impl::chain34_t<NV>
		auto& peak10 = this->getT(0).getT(1).getT(2).getT(4).                              // Sm2_impl::peak10_t
                       getT(0).getT(0).getT(0).getT(0);
		auto& split18 = this->getT(0).getT(1).getT(2).getT(4).                             // Sm2_impl::split18_t<NV>
                        getT(0).getT(0).getT(0).getT(1);
		auto& modchain14 = this->getT(0).getT(1).getT(2).getT(4).                          // Sm2_impl::modchain14_t<NV>
                           getT(0).getT(0).getT(0).getT(1).
                           getT(0);
		auto& chain49 = this->getT(0).getT(1).getT(2).getT(4).getT(0).                     // Sm2_impl::chain49_t<NV>
                        getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& tempo_sync3 = this->getT(0).getT(1).getT(2).getT(4).getT(0).                 // Sm2_impl::tempo_sync3_t<NV>
                            getT(0).getT(0).getT(1).getT(0).getT(0).
                            getT(0);
		auto& ramp1 = this->getT(0).getT(1).getT(2).getT(4).getT(0).                       // Sm2_impl::ramp1_t<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(0).
                      getT(1);
		auto& branch7 = this->getT(0).getT(1).getT(2).getT(4).getT(0).                     // Sm2_impl::branch7_t<NV>
                        getT(0).getT(0).getT(1).getT(0).getT(0).
                        getT(2);
		auto& chain50 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).             // Sm2_impl::chain50_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add16 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).               // math::add<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                      getT(0);
		auto& rect7 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).               // math::rect<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                      getT(1);
		auto& peak11 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).              // Sm2_impl::peak11_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                       getT(2);
		auto& clear3 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).              // math::clear<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                       getT(3);
		auto& input_toggle1 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).       // Sm2_impl::input_toggle1_t<NV>
                              getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                              getT(4);
		auto& ahdsr2 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).              // Sm2_impl::ahdsr2_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                       getT(5);
		auto& add17 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).               // math::add<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
                      getT(6);
		auto& chain54 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).             // Sm2_impl::chain54_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& clear4 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).              // math::clear<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                       getT(0);
		auto& cable_table2 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).        // Sm2_impl::cable_table2_t<NV>
                             getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                             getT(1);
		auto& cable_table5 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).        // Sm2_impl::cable_table5_t
                             getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                             getT(2);
		auto& cable_table6 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).        // Sm2_impl::cable_table6_t
                             getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                             getT(3);
		auto& add18 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).               // math::add<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
                      getT(4);
		auto& chain55 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).             // Sm2_impl::chain55_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& clear5 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).              // math::clear<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                       getT(0);
		auto& cable_pack1 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).         // Sm2_impl::cable_pack1_t<NV>
                            getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                            getT(1);
		auto& add19 = this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).               // math::add<NV>
                      getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
                      getT(2);
		auto& peak12 = this->getT(0).getT(1).getT(2).getT(4).getT(0).                      // Sm2_impl::peak12_t<NV>
                       getT(0).getT(0).getT(1).getT(0).getT(0).
                       getT(3);
		auto& pma2 = this->getT(0).getT(1).getT(2).getT(4).                                // Sm2_impl::pma2_t<NV>
                     getT(0).getT(0).getT(0).getT(2);
		auto& smoothed_parameter3 = this->getT(0).getT(1).getT(2).getT(4).                 // Sm2_impl::smoothed_parameter3_t<NV>
                                    getT(0).getT(0).getT(0).getT(3);
		auto& branch8 = this->getT(0).getT(1).getT(2).getT(4).                             // Sm2_impl::branch8_t<NV>
                        getT(0).getT(0).getT(0).getT(4);
		auto& add20 = this->getT(0).getT(1).getT(2).getT(4).                               // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add21 = this->getT(0).getT(1).getT(2).getT(4).                               // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(1);
		auto& add22 = this->getT(0).getT(1).getT(2).getT(4).                               // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(2);
		auto& add28 = this->getT(0).getT(1).getT(2).getT(4).                               // math::add<NV>
                      getT(0).getT(0).getT(0).getT(4).
                      getT(3);
		auto& add131 = this->getT(0).getT(1).getT(2).getT(4).                              // math::add<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(4);
		auto& add132 = this->getT(0).getT(1).getT(2).getT(4).                              // math::add<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(5);
		auto& add133 = this->getT(0).getT(1).getT(2).getT(4).                              // math::add<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(6);
		auto& add134 = this->getT(0).getT(1).getT(2).getT(4).                              // math::add<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(7);
		auto& add135 = this->getT(0).getT(1).getT(2).getT(4).                              // math::add<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(8);
		auto& add136 = this->getT(0).getT(1).getT(2).getT(4).                              // math::add<NV>
                       getT(0).getT(0).getT(0).getT(4).
                       getT(9);
		auto& branch15 = this->getT(0).getT(1).getT(2).getT(4).                            // Sm2_impl::branch15_t<NV>
                         getT(0).getT(0).getT(0).getT(5);
		auto& file_player1 = this->getT(0).getT(1).getT(2).getT(4).                        // Sm2_impl::file_player1_t<NV>
                             getT(0).getT(0).getT(0).getT(5).
                             getT(0);
		auto& file_player3 = this->getT(0).getT(1).getT(2).getT(4).                        // Sm2_impl::file_player3_t<NV>
                             getT(0).getT(0).getT(0).getT(5).
                             getT(1);
		auto& chain35 = this->getT(0).getT(1).getT(2).getT(4).                             // Sm2_impl::chain35_t<NV>
                        getT(0).getT(0).getT(0).getT(6);
		auto& one_pole1 = this->getT(0).getT(1).getT(2).getT(4).                           // wrap::no_process<filters::one_pole<NV>>
                          getT(0).getT(0).getT(0).getT(6).
                          getT(0);
		auto& chain95 = this->getT(0).getT(1).getT(2).getT(5);                             // Sm2_impl::chain95_t<NV>
		auto& split24 = this->getT(0).getT(1).getT(2).getT(5).getT(0);                     // Sm2_impl::split24_t<NV>
		auto& chain100 = this->getT(0).getT(1).getT(2).getT(5).getT(0).getT(0);            // Sm2_impl::chain100_t
		auto& chain101 = this->getT(0).getT(1).getT(2).getT(5).getT(0).getT(1);            // Sm2_impl::chain101_t<NV>
		auto& split25 = this->getT(0).getT(1).getT(2).getT(5).getT(0).getT(1).getT(0);     // Sm2_impl::split25_t<NV>
		auto& send11 = this->getT(0).getT(1).getT(2).getT(5).                              // routing::send<NV, stereo_cable<NV>>
                       getT(0).getT(1).getT(0).getT(0);
		auto& chain84 = this->getT(0).getT(1).getT(2).getT(5).                             // Sm2_impl::chain84_t<NV>
                        getT(0).getT(1).getT(0).getT(1);
		auto& sig2mod3 = this->getT(0).getT(1).getT(2).getT(5).                            // math::sig2mod<NV>
                         getT(0).getT(1).getT(0).getT(1).
                         getT(0);
		auto& peak19 = this->getT(0).getT(1).getT(2).getT(5).                              // Sm2_impl::peak19_t<NV>
                       getT(0).getT(1).getT(0).getT(1).
                       getT(1);
		auto& clear6 = this->getT(0).getT(2);                                              // math::clear<NV>
		auto& split26 = this->getT(0).getT(3);                                             // Sm2_impl::split26_t<NV>
		auto& chain154 = this->getT(0).getT(3).getT(0);                                    // Sm2_impl::chain154_t<NV>
		auto& sliderbank = this->getT(0).getT(3).getT(0).getT(0);                          // Sm2_impl::sliderbank_t<NV>
		auto& split39 = this->getT(0).getT(3).getT(0).getT(1);                             // Sm2_impl::split39_t<NV>
		auto& receive7 = this->getT(0).getT(3).getT(0).getT(1).getT(0);                    // routing::receive<NV, stereo_cable<NV>>
		auto& receive6 = this->getT(0).getT(3).getT(0).getT(1).getT(1);                    // routing::receive<NV, stereo_cable<NV>>
		auto& receive13 = this->getT(0).getT(3).getT(0).getT(1).getT(2);                   // routing::receive<NV, stereo_cable<NV>>
		auto& receive4 = this->getT(0).getT(3).getT(0).getT(1).getT(3);                    // routing::receive<NV, stereo_cable<NV>>
		auto& branch6 = this->getT(0).getT(3).getT(0).getT(2);                             // Sm2_impl::branch6_t<NV>
		auto& chain41 = this->getT(0).getT(3).getT(0).getT(2).getT(0);                     // Sm2_impl::chain41_t<NV>
		auto& svf = this->getT(0).getT(3).getT(0).getT(2).getT(0).getT(0);                 // filters::svf<NV>
		auto& chain43 = this->getT(0).getT(3).getT(0).getT(2).getT(1);                     // Sm2_impl::chain43_t<NV>
		auto& svf2 = this->getT(0).getT(3).getT(0).getT(2).getT(1).getT(0);                // filters::svf<NV>
		auto& chain42 = this->getT(0).getT(3).getT(0).getT(2).getT(2);                     // Sm2_impl::chain42_t<NV>
		auto& svf1 = this->getT(0).getT(3).getT(0).getT(2).getT(2).getT(0);                // filters::svf<NV>
		auto& chain44 = this->getT(0).getT(3).getT(0).getT(2).getT(3);                     // Sm2_impl::chain44_t<NV>
		auto& svf3 = this->getT(0).getT(3).getT(0).getT(2).getT(3).getT(0);                // filters::svf<NV>
		auto& chain45 = this->getT(0).getT(3).getT(0).getT(2).getT(4);                     // Sm2_impl::chain45_t<NV>
		auto& one_pole6 = this->getT(0).getT(3).getT(0).getT(2).getT(4).getT(0);           // filters::one_pole<NV>
		auto& allpass = this->getT(0).getT(3).getT(0).getT(2).getT(4).getT(1);             // filters::allpass<NV>
		auto& frame2_block = this->getT(0).getT(3).getT(0).getT(2).getT(5);                // Sm2_impl::frame2_block_t<NV>
		auto& chain39 = this->getT(0).getT(3).getT(0).getT(2).getT(5).getT(0);             // Sm2_impl::chain39_t<NV>
		auto& receive = this->getT(0).getT(3).getT(0).getT(2).getT(5).getT(0).getT(0);     // routing::receive<NV, stereo_frame_cable<NV>>
		auto& chain51 = this->getT(0).getT(3).getT(0).getT(2).getT(5).getT(0).getT(1);     // Sm2_impl::chain51_t<NV>
		auto& midi = this->getT(0).getT(3).getT(0).getT(2).                                // Sm2_impl::midi_t<NV>
                     getT(5).getT(0).getT(1).getT(0);
		auto& converter7 = this->getT(0).getT(3).getT(0).getT(2).                          // Sm2_impl::converter7_t<NV>
                           getT(5).getT(0).getT(1).getT(1);
		auto& converter6 = this->getT(0).getT(3).getT(0).getT(2).                          // Sm2_impl::converter6_t<NV>
                           getT(5).getT(0).getT(1).getT(2);
		auto& jdelay = this->getT(0).getT(3).getT(0).getT(2).                              // jdsp::jdelay<NV>
                       getT(5).getT(0).getT(1).getT(3);
		auto& one_pole2 = this->getT(0).getT(3).getT(0).getT(2).getT(5).getT(0).getT(2);   // filters::one_pole<NV>
		auto& send = this->getT(0).getT(3).getT(0).getT(2).getT(5).getT(0).getT(3);        // routing::send<NV, stereo_frame_cable<NV>>
		auto& chain40 = this->getT(0).getT(3).getT(0).getT(2).getT(6);                     // Sm2_impl::chain40_t<NV>
		auto& receive1 = this->getT(0).getT(3).getT(0).getT(2).getT(6).getT(0);            // routing::receive<NV, stereo_cable<NV>>
		auto& chain56 = this->getT(0).getT(3).getT(0).getT(2).getT(6).getT(1);             // Sm2_impl::chain56_t<NV>
		auto& midi1 = this->getT(0).getT(3).getT(0).getT(2).getT(6).getT(1).getT(0);       // Sm2_impl::midi1_t<NV>
		auto& converter8 = this->getT(0).getT(3).getT(0).getT(2).getT(6).getT(1).getT(1);  // Sm2_impl::converter8_t<NV>
		auto& converter9 = this->getT(0).getT(3).getT(0).getT(2).getT(6).getT(1).getT(2);  // Sm2_impl::converter9_t<NV>
		auto& jdelay1 = this->getT(0).getT(3).getT(0).getT(2).getT(6).getT(1).getT(3);     // jdsp::jdelay<NV>
		auto& one_pole3 = this->getT(0).getT(3).getT(0).getT(2).getT(6).getT(2);           // filters::one_pole<NV>
		auto& send1 = this->getT(0).getT(3).getT(0).getT(2).getT(6).getT(3);               // routing::send<NV, stereo_cable<NV>>
		auto& chain123 = this->getT(0).getT(3).getT(0).getT(2).getT(7);                    // Sm2_impl::chain123_t<NV>
		auto& receive2 = this->getT(0).getT(3).getT(0).getT(2).getT(7).getT(0);            // routing::receive<NV, stereo_cable<NV>>
		auto& chain125 = this->getT(0).getT(3).getT(0).getT(2).getT(7).getT(1);            // Sm2_impl::chain125_t<NV>
		auto& converter16 = this->getT(0).getT(3).getT(0).getT(2).getT(7).getT(1).getT(0); // Sm2_impl::converter16_t<NV>
		auto& converter17 = this->getT(0).getT(3).getT(0).getT(2).getT(7).getT(1).getT(1); // Sm2_impl::converter17_t<NV>
		auto& jdelay5 = this->getT(0).getT(3).getT(0).getT(2).getT(7).getT(1).getT(2);     // jdsp::jdelay<NV>
		auto& one_pole4 = this->getT(0).getT(3).getT(0).getT(2).getT(7).getT(2);           // filters::one_pole<NV>
		auto& send2 = this->getT(0).getT(3).getT(0).getT(2).getT(7).getT(3);               // routing::send<NV, stereo_cable<NV>>
		auto& chain126 = this->getT(0).getT(3).getT(0).getT(2).getT(8);                    // Sm2_impl::chain126_t<NV>
		auto& receive3 = this->getT(0).getT(3).getT(0).getT(2).getT(8).getT(0);            // routing::receive<NV, stereo_cable<NV>>
		auto& chain155 = this->getT(0).getT(3).getT(0).getT(2).getT(8).getT(1);            // Sm2_impl::chain155_t<NV>
		auto& converter18 = this->getT(0).getT(3).getT(0).getT(2).getT(8).getT(1).getT(0); // Sm2_impl::converter18_t<NV>
		auto& converter19 = this->getT(0).getT(3).getT(0).getT(2).getT(8).getT(1).getT(1); // Sm2_impl::converter19_t<NV>
		auto& jdelay6 = this->getT(0).getT(3).getT(0).getT(2).getT(8).getT(1).getT(2);     // jdsp::jdelay<NV>
		auto& one_pole5 = this->getT(0).getT(3).getT(0).getT(2).getT(8).getT(2);           // filters::one_pole<NV>
		auto& send3 = this->getT(0).getT(3).getT(0).getT(2).getT(8).getT(3);               // routing::send<NV, stereo_cable<NV>>
		auto& chain157 = this->getT(0).getT(3).getT(0).getT(3);                            // Sm2_impl::chain157_t<NV>
		auto& split27 = this->getT(0).getT(3).getT(0).getT(3).getT(0);                     // Sm2_impl::split27_t<NV>
		auto& chain158 = this->getT(0).getT(3).getT(0).getT(3).getT(0).getT(0);            // Sm2_impl::chain158_t
		auto& chain159 = this->getT(0).getT(3).getT(0).getT(3).getT(0).getT(1);            // Sm2_impl::chain159_t<NV>
		auto& split28 = this->getT(0).getT(3).getT(0).getT(3).getT(0).getT(1).getT(0);     // Sm2_impl::split28_t<NV>
		auto& send12 = this->getT(0).getT(3).getT(0).getT(3).                              // routing::send<NV, stereo_cable<NV>>
                       getT(0).getT(1).getT(0).getT(0);
		auto& chain249 = this->getT(0).getT(3).getT(0).getT(3).                            // Sm2_impl::chain249_t<NV>
                         getT(0).getT(1).getT(0).getT(1);
		auto& sig2mod5 = this->getT(0).getT(3).getT(0).getT(3).                            // math::sig2mod<NV>
                         getT(0).getT(1).getT(0).getT(1).
                         getT(0);
		auto& peak32 = this->getT(0).getT(3).getT(0).getT(3).                              // Sm2_impl::peak32_t<NV>
                       getT(0).getT(1).getT(0).getT(1).
                       getT(1);
		auto& clear10 = this->getT(0).getT(3).getT(0).getT(3).getT(0).getT(1).getT(1);     // math::clear<NV>
		auto& gain38 = this->getT(0).getT(3).getT(0).getT(4);                              // core::gain<NV>
		auto& jpanner = this->getT(0).getT(3).getT(0).getT(5);                             // jdsp::jpanner<NV>
		auto& chain160 = this->getT(0).getT(3).getT(1);                                    // Sm2_impl::chain160_t<NV>
		auto& sliderbank1 = this->getT(0).getT(3).getT(1).getT(0);                         // Sm2_impl::sliderbank1_t<NV>
		auto& split40 = this->getT(0).getT(3).getT(1).getT(1);                             // Sm2_impl::split40_t<NV>
		auto& receive15 = this->getT(0).getT(3).getT(1).getT(1).getT(0);                   // routing::receive<NV, stereo_cable<NV>>
		auto& receive16 = this->getT(0).getT(3).getT(1).getT(1).getT(1);                   // routing::receive<NV, stereo_cable<NV>>
		auto& receive17 = this->getT(0).getT(3).getT(1).getT(1).getT(2);                   // routing::receive<NV, stereo_cable<NV>>
		auto& receive14 = this->getT(0).getT(3).getT(1).getT(1).getT(3);                   // routing::receive<NV, stereo_cable<NV>>
		auto& receive18 = this->getT(0).getT(3).getT(1).getT(1).getT(4);                   // routing::receive<NV, stereo_cable<NV>>
		auto& branch13 = this->getT(0).getT(3).getT(1).getT(2);                            // Sm2_impl::branch13_t<NV>
		auto& chain168 = this->getT(0).getT(3).getT(1).getT(2).getT(0);                    // Sm2_impl::chain168_t<NV>
		auto& svf8 = this->getT(0).getT(3).getT(1).getT(2).getT(0).getT(0);                // filters::svf<NV>
		auto& chain169 = this->getT(0).getT(3).getT(1).getT(2).getT(1);                    // Sm2_impl::chain169_t<NV>
		auto& svf9 = this->getT(0).getT(3).getT(1).getT(2).getT(1).getT(0);                // filters::svf<NV>
		auto& chain170 = this->getT(0).getT(3).getT(1).getT(2).getT(2);                    // Sm2_impl::chain170_t<NV>
		auto& svf10 = this->getT(0).getT(3).getT(1).getT(2).getT(2).getT(0);               // filters::svf<NV>
		auto& chain171 = this->getT(0).getT(3).getT(1).getT(2).getT(3);                    // Sm2_impl::chain171_t<NV>
		auto& svf11 = this->getT(0).getT(3).getT(1).getT(2).getT(3).getT(0);               // filters::svf<NV>
		auto& chain172 = this->getT(0).getT(3).getT(1).getT(2).getT(4);                    // Sm2_impl::chain172_t<NV>
		auto& allpass2 = this->getT(0).getT(3).getT(1).getT(2).getT(4).getT(0);            // filters::allpass<NV>
		auto& chain166 = this->getT(0).getT(3).getT(1).getT(2).getT(5);                    // Sm2_impl::chain166_t<NV>
		auto& receive19 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain61 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(1);             // Sm2_impl::chain61_t<NV>
		auto& midi2 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(1).getT(0);       // Sm2_impl::midi2_t<NV>
		auto& converter10 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(1).getT(1); // Sm2_impl::converter10_t<NV>
		auto& converter11 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(1).getT(2); // Sm2_impl::converter11_t<NV>
		auto& jdelay2 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(1).getT(3);     // jdsp::jdelay<NV>
		auto& chain92 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(2);             // Sm2_impl::chain92_t<NV>
		auto& midi3 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(2).getT(0);       // Sm2_impl::midi3_t<NV>
		auto& converter12 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(2).getT(1); // Sm2_impl::converter12_t<NV>
		auto& converter13 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(2).getT(2); // Sm2_impl::converter13_t<NV>
		auto& jdelay3 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(2).getT(3);     // jdsp::jdelay<NV>
		auto& one_pole12 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(3);          // filters::one_pole<NV>
		auto& send13 = this->getT(0).getT(3).getT(1).getT(2).getT(5).getT(4);              // routing::send<NV, stereo_cable<NV>>
		auto& chain167 = this->getT(0).getT(3).getT(1).getT(2).getT(6);                    // Sm2_impl::chain167_t<NV>
		auto& receive20 = this->getT(0).getT(3).getT(1).getT(2).getT(6).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain94 = this->getT(0).getT(3).getT(1).getT(2).getT(6).getT(1);             // Sm2_impl::chain94_t<NV>
		auto& midi4 = this->getT(0).getT(3).getT(1).getT(2).getT(6).getT(1).getT(0);       // Sm2_impl::midi4_t<NV>
		auto& converter14 = this->getT(0).getT(3).getT(1).getT(2).getT(6).getT(1).getT(1); // Sm2_impl::converter14_t<NV>
		auto& converter15 = this->getT(0).getT(3).getT(1).getT(2).getT(6).getT(1).getT(2); // Sm2_impl::converter15_t<NV>
		auto& jdelay4 = this->getT(0).getT(3).getT(1).getT(2).getT(6).getT(1).getT(3);     // jdsp::jdelay<NV>
		auto& one_pole13 = this->getT(0).getT(3).getT(1).getT(2).getT(6).getT(2);          // filters::one_pole<NV>
		auto& send14 = this->getT(0).getT(3).getT(1).getT(2).getT(6).getT(3);              // routing::send<NV, stereo_cable<NV>>
		auto& chain232 = this->getT(0).getT(3).getT(1).getT(2).getT(7);                    // Sm2_impl::chain232_t<NV>
		auto& receive27 = this->getT(0).getT(3).getT(1).getT(2).getT(7).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain156 = this->getT(0).getT(3).getT(1).getT(2).getT(7).getT(1);            // Sm2_impl::chain156_t<NV>
		auto& converter20 = this->getT(0).getT(3).getT(1).getT(2).getT(7).getT(1).getT(0); // Sm2_impl::converter20_t<NV>
		auto& converter21 = this->getT(0).getT(3).getT(1).getT(2).getT(7).getT(1).getT(1); // Sm2_impl::converter21_t<NV>
		auto& jdelay7 = this->getT(0).getT(3).getT(1).getT(2).getT(7).getT(1).getT(2);     // jdsp::jdelay<NV>
		auto& one_pole14 = this->getT(0).getT(3).getT(1).getT(2).getT(7).getT(2);          // filters::one_pole<NV>
		auto& send18 = this->getT(0).getT(3).getT(1).getT(2).getT(7).getT(3);              // routing::send<NV, stereo_cable<NV>>
		auto& chain233 = this->getT(0).getT(3).getT(1).getT(2).getT(8);                    // Sm2_impl::chain233_t<NV>
		auto& receive28 = this->getT(0).getT(3).getT(1).getT(2).getT(8).getT(0);           // routing::receive<NV, stereo_cable<NV>>
		auto& chain234 = this->getT(0).getT(3).getT(1).getT(2).getT(8).getT(1);            // Sm2_impl::chain234_t<NV>
		auto& converter22 = this->getT(0).getT(3).getT(1).getT(2).getT(8).getT(1).getT(0); // Sm2_impl::converter22_t<NV>
		auto& converter23 = this->getT(0).getT(3).getT(1).getT(2).getT(8).getT(1).getT(1); // Sm2_impl::converter23_t<NV>
		auto& jdelay8 = this->getT(0).getT(3).getT(1).getT(2).getT(8).getT(1).getT(2);     // jdsp::jdelay<NV>
		auto& one_pole15 = this->getT(0).getT(3).getT(1).getT(2).getT(8).getT(2);          // filters::one_pole<NV>
		auto& send19 = this->getT(0).getT(3).getT(1).getT(2).getT(8).getT(3);              // routing::send<NV, stereo_cable<NV>>
		auto& chain173 = this->getT(0).getT(3).getT(1).getT(3);                            // Sm2_impl::chain173_t<NV>
		auto& split29 = this->getT(0).getT(3).getT(1).getT(3).getT(0);                     // Sm2_impl::split29_t<NV>
		auto& chain174 = this->getT(0).getT(3).getT(1).getT(3).getT(0).getT(0);            // Sm2_impl::chain174_t
		auto& chain175 = this->getT(0).getT(3).getT(1).getT(3).getT(0).getT(1);            // Sm2_impl::chain175_t<NV>
		auto& split30 = this->getT(0).getT(3).getT(1).getT(3).getT(0).getT(1).getT(0);     // Sm2_impl::split30_t<NV>
		auto& send15 = this->getT(0).getT(3).getT(1).getT(3).                              // routing::send<NV, stereo_cable<NV>>
                       getT(0).getT(1).getT(0).getT(0);
		auto& chain257 = this->getT(0).getT(3).getT(1).getT(3).                        // Sm2_impl::chain257_t<NV>
                         getT(0).getT(1).getT(0).getT(1);
		auto& sig2mod6 = this->getT(0).getT(3).getT(1).getT(3).                        // math::sig2mod<NV>
                         getT(0).getT(1).getT(0).getT(1).
                         getT(0);
		auto& peak33 = this->getT(0).getT(3).getT(1).getT(3).                          // Sm2_impl::peak33_t<NV>
                       getT(0).getT(1).getT(0).getT(1).
                       getT(1);
		auto& clear11 = this->getT(0).getT(3).getT(1).getT(3).getT(0).getT(1).getT(1); // math::clear<NV>
		auto& gain41 = this->getT(0).getT(3).getT(1).getT(4);                          // core::gain<NV>
		auto& jpanner2 = this->getT(0).getT(3).getT(1).getT(5);                        // jdsp::jpanner<NV>
		auto& ahdsr1 = this->getT(1);                                                  // Sm2_impl::ahdsr1_t<NV>
		auto& voice_manager = this->getT(2);                                           // envelope::voice_manager
		auto& gain = this->getT(3);                                                    // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, minmax); // OscSt1 -> minmax::Value
		
		this->getParameterT(1).connectT(0, add36); // OscCent1 -> add36::Value
		
		auto& Oscfm1_p = this->getParameterT(2);
		Oscfm1_p.connectT(0, pma_unscaled3); // Oscfm1 -> pma_unscaled3::Multiply
		Oscfm1_p.connectT(1, pma);           // Oscfm1 -> pma::Multiply
		
		auto& OscMod1_p = this->getParameterT(3);
		OscMod1_p.connectT(0, global_mod1); // OscMod1 -> global_mod1::Intensity
		OscMod1_p.connectT(1, global_mod3); // OscMod1 -> global_mod3::Intensity
		
		this->getParameterT(4).connectT(0, branch2); // OscTempoSync1 -> branch2::Index
		
		this->getParameterT(5).connectT(0, global_mod3); // OscTempo1 -> global_mod3::Value
		
		this->getParameterT(6).connectT(0, tempo_sync); // OscDiv1 -> tempo_sync::Multiplier
		
		auto& OscFmSrc1_p = this->getParameterT(7);
		OscFmSrc1_p.connectT(0, branch9);  // OscFmSrc1 -> branch9::Index
		OscFmSrc1_p.connectT(1, branch10); // OscFmSrc1 -> branch10::Index
		
		auto& OscPitchSrc1_p = this->getParameterT(8);
		OscPitchSrc1_p.connectT(0, global_mod1); // OscPitchSrc1 -> global_mod1::Index
		OscPitchSrc1_p.connectT(1, global_mod3); // OscPitchSrc1 -> global_mod3::Index
		
		auto& filePos1_p = this->getParameterT(10);
		filePos1_p.connectT(0, cable_table4); // filePos1 -> cable_table4::Value
		filePos1_p.connectT(1, pma3);         // filePos1 -> pma3::Add
		
		this->getParameterT(11).connectT(0, pma3); // FilePosMod1 -> pma3::Multiply
		
		this->getParameterT(12).connectT(0, branch1); // FilePosQuant1 -> branch1::Index
		
		this->getParameterT(13).connectT(0, global_mod6); // FileInputGain1 -> global_mod6::Value
		
		this->getParameterT(14).connectT(0, global_mod6); // FileInputGainMod -> global_mod6::Intensity
		
		this->getParameterT(15).connectT(0, global_mod6); // FileInputGainSrc1 -> global_mod6::Index
		
		this->getParameterT(16).connectT(0, pma_unscaled8); // FileInputGainFm1 -> pma_unscaled8::Multiply
		
		this->getParameterT(17).connectT(0, branch6); // FilterMode1 -> branch6::Index
		
		this->getParameterT(18).connectT(0, global_mod9); // FilterCut1 -> global_mod9::Value
		
		this->getParameterT(19).connectT(0, global_mod9); // FilterCutMod1 -> global_mod9::Intensity
		
		this->getParameterT(20).connectT(0, pma_unscaled9); // FilterCutFm1 -> pma_unscaled9::Multiply
		
		this->getParameterT(21).connectT(0, global_mod9); // FilterCutSrc1 -> global_mod9::Index
		
		this->getParameterT(22).connectT(0, branch21); // FilterModMode1 -> branch21::Index
		
		this->getParameterT(23).connectT(0, global_mod10); // VcaGain1 -> global_mod10::Value
		
		this->getParameterT(24).connectT(0, global_mod10); // VcaGainMod1 -> global_mod10::Intensity
		
		this->getParameterT(25).connectT(0, pma_unscaled10); // VcaGainFm1 -> pma_unscaled10::Multiply
		
		this->getParameterT(26).connectT(0, global_mod10); // VcaGainSrc1 -> global_mod10::Index
		
		auto& Res1_p = this->getParameterT(27);
		Res1_p.connectT(0, one_pole2); // Res1 -> one_pole2::Q
		Res1_p.connectT(1, one_pole3); // Res1 -> one_pole3::Q
		Res1_p.connectT(2, svf);       // Res1 -> svf::Q
		Res1_p.connectT(3, svf2);      // Res1 -> svf2::Q
		Res1_p.connectT(4, svf1);      // Res1 -> svf1::Q
		Res1_p.connectT(5, svf3);      // Res1 -> svf3::Q
		Res1_p.connectT(6, allpass);   // Res1 -> allpass::Q
		Res1_p.connectT(7, receive);   // Res1 -> receive::Feedback
		Res1_p.connectT(8, receive1);  // Res1 -> receive1::Feedback
		Res1_p.connectT(9, receive2);  // Res1 -> receive2::Feedback
		Res1_p.connectT(10, receive3); // Res1 -> receive3::Feedback
		
		this->getParameterT(28).connectT(0, jpanner); // Pan1 -> jpanner::Pan
		
		this->getParameterT(29).connectT(0, branch22); // VcaFmSrc1 -> branch22::Index
		
		this->getParameterT(30).connectT(0, minmax2); // OscSt2 -> minmax2::Value
		
		this->getParameterT(31).connectT(0, add35); // OscCent2 -> add35::Value
		
		auto& Oscfm2_p = this->getParameterT(32);
		Oscfm2_p.connectT(0, pma_unscaled15); // Oscfm2 -> pma_unscaled15::Multiply
		Oscfm2_p.connectT(1, pma1);           // Oscfm2 -> pma1::Multiply
		
		auto& OscMod2_p = this->getParameterT(33);
		OscMod2_p.connectT(0, global_mod);   // OscMod2 -> global_mod::Intensity
		OscMod2_p.connectT(1, global_mod13); // OscMod2 -> global_mod13::Intensity
		
		auto& OscFmSrc2_p = this->getParameterT(34);
		OscFmSrc2_p.connectT(0, branch12); // OscFmSrc2 -> branch12::Index
		OscFmSrc2_p.connectT(1, branch11); // OscFmSrc2 -> branch11::Index
		
		this->getParameterT(35).connectT(0, branch13); // FilterMode2 -> branch13::Index
		
		this->getParameterT(36).connectT(0, global_mod11); // FilterCut2 -> global_mod11::Value
		
		this->getParameterT(37).connectT(0, global_mod11); // FilterCutMod2 -> global_mod11::Intensity
		
		this->getParameterT(38).connectT(0, pma_unscaled11); // FilterCutFm2 -> pma_unscaled11::Multiply
		
		this->getParameterT(39).connectT(0, global_mod11); // FilterCutSrc2 -> global_mod11::Index
		
		this->getParameterT(40).connectT(0, branch23); // FilterFmdSrc -> branch23::Index
		
		this->getParameterT(41).connectT(0, global_mod12); // VcaGain2 -> global_mod12::Value
		
		this->getParameterT(42).connectT(0, global_mod12); // VcaGainMod2 -> global_mod12::Intensity
		
		this->getParameterT(43).connectT(0, pma_unscaled12); // VcaGainFm2 -> pma_unscaled12::Multiply
		
		this->getParameterT(44).connectT(0, global_mod12); // VcaGainSrc2 -> global_mod12::Index
		
		auto& Res2_p = this->getParameterT(46);
		Res2_p.connectT(0, one_pole12); // Res2 -> one_pole12::Q
		Res2_p.connectT(1, receive20);  // Res2 -> receive20::Feedback
		Res2_p.connectT(2, receive19);  // Res2 -> receive19::Feedback
		Res2_p.connectT(3, svf8);       // Res2 -> svf8::Q
		Res2_p.connectT(4, svf9);       // Res2 -> svf9::Q
		Res2_p.connectT(5, svf10);      // Res2 -> svf10::Q
		Res2_p.connectT(6, svf11);      // Res2 -> svf11::Q
		Res2_p.connectT(7, allpass2);   // Res2 -> allpass2::Q
		Res2_p.connectT(8, one_pole13); // Res2 -> one_pole13::Q
		Res2_p.connectT(9, receive27);  // Res2 -> receive27::Feedback
		Res2_p.connectT(10, receive28); // Res2 -> receive28::Feedback
		
		this->getParameterT(47).connectT(0, jpanner2); // Pan2 -> jpanner2::Pan
		
		this->getParameterT(48).connectT(0, branch25); // VcaFmSrc2 -> branch25::Index
		
		this->getParameterT(49).connectT(0, global_mod4); // OscShape -> global_mod4::Value
		
		this->getParameterT(50).connectT(0, global_mod4); // OscShapeMod -> global_mod4::Intensity
		
		this->getParameterT(51).connectT(0, pma_unscaled6); // OscShapeFm -> pma_unscaled6::Multiply
		
		this->getParameterT(52).connectT(0, global_mod4); // OscShapeModSrc -> global_mod4::Index
		
		this->getParameterT(53).connectT(0, branch16); // OscShapeFmSrc -> branch16::Index
		
		this->getParameterT(54).connectT(0, global_mod5); // Osc2InputGain -> global_mod5::Value
		
		this->getParameterT(55).connectT(0, global_mod5); // Osc2InputGainMod -> global_mod5::Intensity
		
		this->getParameterT(56).connectT(0, pma_unscaled7); // Osc2InputGainFm -> pma_unscaled7::Multiply
		
		this->getParameterT(57).connectT(0, global_mod5); // Osc2InputGainModSrc -> global_mod5::Index
		
		this->getParameterT(58).connectT(0, branch17); // Osc2InputGainFmSrc -> branch17::Index
		
		this->getParameterT(59).connectT(0, branch20); // FileInFmSrc -> branch20::Index
		
		this->getParameterT(62).connectT(0, branch3); // PostModMode -> branch3::Index
		
		this->getParameterT(63).connectT(0, input_toggle); // PosEnvTrig -> input_toggle::Input
		
		this->getParameterT(64).connectT(0, ahdsr); // PosEnvA -> ahdsr::Attack
		
		this->getParameterT(65).connectT(0, ahdsr); // PosEnvH -> ahdsr::Hold
		
		this->getParameterT(66).connectT(0, ahdsr); // PosEnvD -> ahdsr::Decay
		
		this->getParameterT(67).connectT(0, ahdsr); // PosEnvS -> ahdsr::Sustain
		
		this->getParameterT(68).connectT(0, ahdsr); // PosEnvR -> ahdsr::Release
		
		this->getParameterT(71).connectT(0, tempo_sync4); // PosTempo -> tempo_sync4::Tempo
		
		this->getParameterT(72).connectT(0, tempo_sync4); // PosDib -> tempo_sync4::Multiplier
		
		this->getParameterT(73).connectT(0, gain21); // FileInOffset -> gain21::Gain
		
		this->getParameterT(74).connectT(0, branch); // oscShapeMode1 -> branch::Index
		
		this->getParameterT(75).connectT(0, branch4); // oscShapeMode2 -> branch4::Index
		
		this->getParameterT(76).connectT(0, global_mod7); // shape2 -> global_mod7::Value
		
		this->getParameterT(77).connectT(0, global_mod7); // ShapeMod1 -> global_mod7::Intensity
		
		this->getParameterT(78).connectT(0, global_mod7); // ShapeSrc2 -> global_mod7::Index
		
		this->getParameterT(79).connectT(0, pma_unscaled13); // ShapeFm2 -> pma_unscaled13::Multiply
		
		this->getParameterT(80).connectT(0, branch18); // ShapeFmSrc2 -> branch18::Index
		
		auto& Osc2Src_p = this->getParameterT(82);
		Osc2Src_p.connectT(0, global_mod);   // Osc2Src -> global_mod::Index
		Osc2Src_p.connectT(1, global_mod13); // Osc2Src -> global_mod13::Index
		
		this->getParameterT(83).connectT(0, branch27); // Osc2InSel -> branch27::Index
		
		this->getParameterT(84).connectT(0, branch26); // FileInSel -> branch26::Index
		
		this->getParameterT(85).connectT(0, gain); // Vol -> gain::Gain
		
		this->getParameterT(86).connectT(0, global_mod8); // Osc1Input -> global_mod8::Value
		
		this->getParameterT(87).connectT(0, global_mod8); // Osc1InputMod -> global_mod8::Intensity
		
		this->getParameterT(88).connectT(0, pma_unscaled14); // Osc1FM -> pma_unscaled14::Multiply
		
		this->getParameterT(89).connectT(0, branch29); // OscFmSrc -> branch29::Index
		
		this->getParameterT(90).connectT(0, global_mod8); // Osc1InputSrc -> global_mod8::Index
		
		this->getParameterT(91).connectT(0, branch28); // Osc1InSel -> branch28::Index
		
		this->getParameterT(92).connectT(0, ahdsr1); // s -> ahdsr1::Sustain
		
		this->getParameterT(93).connectT(0, ahdsr1); // a -> ahdsr1::Attack
		
		this->getParameterT(94).connectT(0, ahdsr1); // h -> ahdsr1::Hold
		
		this->getParameterT(95).connectT(0, ahdsr1); // d -> ahdsr1::Decay
		
		this->getParameterT(96).connectT(0, ahdsr1); // r -> ahdsr1::Release
		
		this->getParameterT(97).connectT(0, global_mod13); // TEMPO2 -> global_mod13::Value
		
		this->getParameterT(98).connectT(0, tempo_sync2); // DIV2 -> tempo_sync2::Multiplier
		
		this->getParameterT(99).connectT(0, branch5); // SYNC2 -> branch5::Index
		
		this->getParameterT(100).connectT(0, branch30); // File2InSel -> branch30::Index
		
		this->getParameterT(101).connectT(0, gain23); // File2GainOffset -> gain23::Gain
		
		this->getParameterT(102).connectT(0, global_mod15); // File2Gain -> global_mod15::Value
		
		this->getParameterT(103).connectT(0, global_mod15); // File2Mod -> global_mod15::Intensity
		
		this->getParameterT(104).connectT(0, pma_unscaled17); // File2Fm -> pma_unscaled17::Multiply
		
		this->getParameterT(105).connectT(0, global_mod15); // File2ModSrc -> global_mod15::Index
		
		this->getParameterT(106).connectT(0, branch32); // File2FmSrc -> branch32::Index
		
		this->getParameterT(107).connectT(0, tempo_sync3); // File2Tempo -> tempo_sync3::Tempo
		
		this->getParameterT(108).connectT(0, tempo_sync3); // FileDiv -> tempo_sync3::Multiplier
		
		this->getParameterT(109).connectT(0, branch7); // File2Mode -> branch7::Index
		
		this->getParameterT(110).connectT(0, input_toggle1); // File2EnvTrig -> input_toggle1::Input
		
		this->getParameterT(111).connectT(0, ahdsr2); // File2A -> ahdsr2::Attack
		
		this->getParameterT(112).connectT(0, ahdsr2); // File2H -> ahdsr2::Hold
		
		this->getParameterT(113).connectT(0, ahdsr2); // File2D -> ahdsr2::Decay
		
		this->getParameterT(114).connectT(0, ahdsr2); // File2S -> ahdsr2::Sustain
		
		this->getParameterT(115).connectT(0, ahdsr2); // File2R -> ahdsr2::Release
		
		auto& File2Pos_p = this->getParameterT(116);
		File2Pos_p.connectT(0, pma2);         // File2Pos -> pma2::Add
		File2Pos_p.connectT(1, cable_table5); // File2Pos -> cable_table5::Value
		
		this->getParameterT(117).connectT(0, pma2); // File2PosMod -> pma2::Multiply
		
		this->getParameterT(118).connectT(0, branch8); // File2Quant -> branch8::Index
		
		this->getParameterT(119).connectT(0, branch14); // User1 -> branch14::Index
		
		this->getParameterT(120).connectT(0, branch15); // User2 -> branch15::Index
		
		auto& tune_p = this->getParameterT(121);
		tune_p.connectT(0, sub21); // tune -> sub21::Value
		tune_p.connectT(1, sub3);  // tune -> sub3::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		pma.getWrappedObject().getParameter().connectT(0, add27);             // pma -> add27::Value
		peak5.getParameter().connectT(0, pma);                                // peak5 -> pma::Value
		minmax.getWrappedObject().getParameter().connectT(0, add26);          // minmax -> add26::Value
		minmax3.getWrappedObject().getParameter().connectT(0, add89);         // minmax3 -> add89::Value
		global_mod1.getParameter().connectT(0, minmax3);                      // global_mod1 -> minmax3::Value
		converter2.getWrappedObject().getParameter().connectT(0, phasor_fm1); // converter2 -> phasor_fm1::FreqRatio
		peak_unscaled.getParameter().connectT(0, converter2);                 // peak_unscaled -> converter2::Value
		pma1.getWrappedObject().getParameter().connectT(0, add43);            // pma1 -> add43::Value
		peak13.getParameter().connectT(0, pma1);                              // peak13 -> pma1::Value
		minmax2.getWrappedObject().getParameter().connectT(0, add42);         // minmax2 -> add42::Value
		minmax1.getWrappedObject().getParameter().connectT(0, add90);         // minmax1 -> add90::Value
		converter3.getWrappedObject().getParameter().connectT(0, phasor_fm);  // converter3 -> phasor_fm::FreqRatio
		peak_unscaled2.getParameter().connectT(0, converter3);                // peak_unscaled2 -> converter3::Value
		pma_unscaled3.getWrappedObject().getParameter().connectT(0, add34);   // pma_unscaled3 -> add34::Value
		peak7.getParameter().connectT(0, pma_unscaled3);                      // peak7 -> pma_unscaled3::Value
		global_mod3.getParameter().connectT(0, add91);                        // global_mod3 -> add91::Value
		converter.getWrappedObject().getParameter().connectT(0, phasor_fm2);  // converter -> phasor_fm2::FreqRatio
		tempo_sync.getParameter().connectT(0, converter);                     // tempo_sync -> converter::Value
		peak35.getParameter().connectT(0, tempo_sync);                        // peak35 -> tempo_sync::Tempo
		pma_unscaled15.getWrappedObject().getParameter().connectT(0, add129); // pma_unscaled15 -> add129::Value
		peak9.getParameter().connectT(0, pma_unscaled15);                     // peak9 -> pma_unscaled15::Value
		global_mod13.getParameter().connectT(0, add130);                      // global_mod13 -> add130::Value
		converter1.getWrappedObject().getParameter().connectT(0, phasor_fm3); // converter1 -> phasor_fm3::FreqRatio
		tempo_sync2.getParameter().connectT(0, converter1);                   // tempo_sync2 -> converter1::Value
		peak36.getParameter().connectT(0, tempo_sync2);                       // peak36 -> tempo_sync2::Tempo
		pma_unscaled6.getWrappedObject().getParameter().connectT(0, add37);   // pma_unscaled6 -> add37::Value
		peak17.getParameter().connectT(0, pma_unscaled6);                     // peak17 -> pma_unscaled6::Value
		global_mod4.getParameter().connectT(0, add92);                        // global_mod4 -> add92::Value
		smoothed_parameter1.getParameter().connectT(0, expr4);                // smoothed_parameter1 -> expr4::Value
		smoothed_parameter4.getParameter().connectT(0, expr3);                // smoothed_parameter4 -> expr3::Value
		peak6.getParameter().connectT(0, gain9);                              // peak6 -> gain9::Gain
		peak6.getParameter().connectT(1, smoothed_parameter1);                // peak6 -> smoothed_parameter1::Value
		peak6.getParameter().connectT(2, smoothed_parameter4);                // peak6 -> smoothed_parameter4::Value
		peak6.getParameter().connectT(3, gain3);                              // peak6 -> gain3::Gain
		peak6.getParameter().connectT(4, gain35);                             // peak6 -> gain35::Gain
		peak6.getParameter().connectT(5, gain6);                              // peak6 -> gain6::Gain
		peak6.getParameter().connectT(6, gain4);                              // peak6 -> gain4::Gain
		peak6.getParameter().connectT(7, gain13);                             // peak6 -> gain13::Gain
		peak6.getParameter().connectT(8, gain7);                              // peak6 -> gain7::Gain
		peak6.getParameter().connectT(9, gain14);                             // peak6 -> gain14::Gain
		peak6.getParameter().connectT(10, gain15);                            // peak6 -> gain15::Gain
		peak6.getParameter().connectT(11, gain37);                            // peak6 -> gain37::Gain
		pma_unscaled13.getWrappedObject().getParameter().connectT(0, add44);  // pma_unscaled13 -> add44::Value
		peak30.getParameter().connectT(0, pma_unscaled13);                    // peak30 -> pma_unscaled13::Value
		global_mod7.getParameter().connectT(0, add96);                        // global_mod7 -> add96::Value
		smoothed_parameter5.getParameter().connectT(0, expr7);                // smoothed_parameter5 -> expr7::Value
		smoothed_parameter2.getParameter().connectT(0, expr10);               // smoothed_parameter2 -> expr10::Value
		peak8.getParameter().connectT(0, gain10);                             // peak8 -> gain10::Gain
		peak8.getParameter().connectT(1, gain39);                             // peak8 -> gain39::Gain
		peak8.getParameter().connectT(2, smoothed_parameter5);                // peak8 -> smoothed_parameter5::Value
		peak8.getParameter().connectT(3, smoothed_parameter2);                // peak8 -> smoothed_parameter2::Value
		peak8.getParameter().connectT(4, gain5);                              // peak8 -> gain5::Gain
		peak8.getParameter().connectT(5, gain36);                             // peak8 -> gain36::Gain
		peak8.getParameter().connectT(6, gain11);                             // peak8 -> gain11::Gain
		peak8.getParameter().connectT(7, gain12);                             // peak8 -> gain12::Gain
		peak8.getParameter().connectT(8, gain16);                             // peak8 -> gain16::Gain
		peak8.getParameter().connectT(9, gain17);                             // peak8 -> gain17::Gain
		peak8.getParameter().connectT(10, gain18);                            // peak8 -> gain18::Gain
		peak8.getParameter().connectT(11, gain19);                            // peak8 -> gain19::Gain
		pma_unscaled14.getWrappedObject().getParameter().connectT(0, add55);  // pma_unscaled14 -> add55::Value
		global_mod8.getParameter().connectT(0, add128);                       // global_mod8 -> add128::Value
		peak3.getParameter().connectT(0, gain1);                              // peak3 -> gain1::Gain
		pma_unscaled7.getWrappedObject().getParameter().connectT(0, add45);   // pma_unscaled7 -> add45::Value
		global_mod5.getParameter().connectT(0, add93);                        // global_mod5 -> add93::Value
		peak14.getParameter().connectT(0, gain32);                            // peak14 -> gain32::Gain
		pma_unscaled8.getWrappedObject().getParameter().connectT(0, add46);   // pma_unscaled8 -> add46::Value
		global_mod6.getParameter().connectT(0, add94);                        // global_mod6 -> add94::Value
		peak.getParameter().connectT(0, gain20);                              // peak -> gain20::Gain
		pma_unscaled17.getWrappedObject().getParameter().connectT(0, add153); // pma_unscaled17 -> add153::Value
		global_mod15.getParameter().connectT(0, add154);                      // global_mod15 -> add154::Value
		peak39.getParameter().connectT(0, gain22);                            // peak39 -> gain22::Gain
		pma_unscaled9.getWrappedObject().getParameter().connectT(0, add47);   // pma_unscaled9 -> add47::Value
		peak22.getParameter().connectT(0, pma_unscaled9);                     // peak22 -> pma_unscaled9::Value
		global_mod9.getParameter().connectT(0, add97);                        // global_mod9 -> add97::Value
		peak23.getParameter().connectT(0, one_pole2);                         // peak23 -> one_pole2::Frequency
		peak23.getParameter().connectT(1, one_pole3);                         // peak23 -> one_pole3::Frequency
		peak23.getParameter().connectT(2, svf);                               // peak23 -> svf::Frequency
		peak23.getParameter().connectT(3, svf2);                              // peak23 -> svf2::Frequency
		peak23.getParameter().connectT(4, svf1);                              // peak23 -> svf1::Frequency
		peak23.getParameter().connectT(5, svf3);                              // peak23 -> svf3::Frequency
		peak23.getParameter().connectT(6, allpass);                           // peak23 -> allpass::Frequency
		peak23.getParameter().connectT(7, one_pole4);                         // peak23 -> one_pole4::Frequency
		peak23.getParameter().connectT(8, one_pole5);                         // peak23 -> one_pole5::Frequency
		pma_unscaled11.getWrappedObject().getParameter().connectT(0, add54);  // pma_unscaled11 -> add54::Value
		peak26.getParameter().connectT(0, pma_unscaled11);                    // peak26 -> pma_unscaled11::Value
		global_mod11.getParameter().connectT(0, add115);                      // global_mod11 -> add115::Value
		peak27.getParameter().connectT(0, allpass2);                          // peak27 -> allpass2::Frequency
		peak27.getParameter().connectT(1, svf11);                             // peak27 -> svf11::Frequency
		peak27.getParameter().connectT(2, svf10);                             // peak27 -> svf10::Frequency
		peak27.getParameter().connectT(3, svf9);                              // peak27 -> svf9::Frequency
		peak27.getParameter().connectT(4, svf8);                              // peak27 -> svf8::Frequency
		peak27.getParameter().connectT(5, one_pole13);                        // peak27 -> one_pole13::Frequency
		peak27.getParameter().connectT(6, one_pole12);                        // peak27 -> one_pole12::Frequency
		peak27.getParameter().connectT(7, add15);                             // peak27 -> add15::Value
		peak27.getParameter().connectT(8, one_pole14);                        // peak27 -> one_pole14::Frequency
		peak27.getParameter().connectT(9, one_pole15);                        // peak27 -> one_pole15::Frequency
		pma_unscaled10.getWrappedObject().getParameter().connectT(0, add48);  // pma_unscaled10 -> add48::Value
		peak24.getParameter().connectT(0, pma_unscaled10);                    // peak24 -> pma_unscaled10::Value
		global_mod10.getParameter().connectT(0, add98);                       // global_mod10 -> add98::Value
		peak25.getParameter().connectT(0, gain38);                            // peak25 -> gain38::Gain
		pma_unscaled12.getWrappedObject().getParameter().connectT(0, add58);  // pma_unscaled12 -> add58::Value
		peak28.getParameter().connectT(0, pma_unscaled12);                    // peak28 -> pma_unscaled12::Value
		global_mod12.getParameter().connectT(0, add122);                      // global_mod12 -> add122::Value
		peak29.getParameter().connectT(0, gain41);                            // peak29 -> gain41::Gain
		peak15.getParameter().connectT(0, add24);                             // peak15 -> add24::Value
		peak15.getParameter().connectT(1, add39);                             // peak15 -> add39::Value
		peak15.getParameter().connectT(2, add30);                             // peak15 -> add30::Value
		peak15.getParameter().connectT(3, add60);                             // peak15 -> add60::Value
		peak15.getParameter().connectT(4, add65);                             // peak15 -> add65::Value
		peak15.getParameter().connectT(5, add70);                             // peak15 -> add70::Value
		peak15.getParameter().connectT(6, add75);                             // peak15 -> add75::Value
		peak15.getParameter().connectT(7, add80);                             // peak15 -> add80::Value
		peak15.getParameter().connectT(8, add117);                            // peak15 -> add117::Value
		peak15.getParameter().connectT(9, add110);                            // peak15 -> add110::Value
		peak15.getParameter().connectT(10, add63);                            // peak15 -> add63::Value
		peak15.getParameter().connectT(11, add73);                            // peak15 -> add73::Value
		peak15.getParameter().connectT(12, add57);                            // peak15 -> add57::Value
		peak15.getParameter().connectT(13, add147);                           // peak15 -> add147::Value
		peak34.getParameter().connectT(0, add23);                             // peak34 -> add23::Value
		peak34.getParameter().connectT(1, add40);                             // peak34 -> add40::Value
		peak34.getParameter().connectT(2, add31);                             // peak34 -> add31::Value
		peak34.getParameter().connectT(3, add61);                             // peak34 -> add61::Value
		peak34.getParameter().connectT(4, add66);                             // peak34 -> add66::Value
		peak34.getParameter().connectT(5, add71);                             // peak34 -> add71::Value
		peak34.getParameter().connectT(6, add76);                             // peak34 -> add76::Value
		peak34.getParameter().connectT(7, add81);                             // peak34 -> add81::Value
		peak34.getParameter().connectT(8, add111);                            // peak34 -> add111::Value
		peak34.getParameter().connectT(9, add118);                            // peak34 -> add118::Value
		peak34.getParameter().connectT(10, add67);                            // peak34 -> add67::Value
		peak34.getParameter().connectT(11, add77);                            // peak34 -> add77::Value
		peak34.getParameter().connectT(12, add68);                            // peak34 -> add68::Value
		peak34.getParameter().connectT(13, add148);                           // peak34 -> add148::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, add9);     // cable_table1 -> add9::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add10);      // cable_pack -> add10::Value
		ramp.getParameter().connectT(0, cable_table1);                        // ramp -> cable_table1::Value
		ramp.getParameter().connectT(1, add7);                                // ramp -> add7::Value
		ramp.getParameter().connectT(2, cable_pack);                          // ramp -> cable_pack::Value
		tempo_sync4.getParameter().connectT(0, ramp);                         // tempo_sync4 -> ramp::PeriodTime
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add8);                             // ahdsr -> add8::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ahdsr);      // input_toggle -> ahdsr::Gate
		peak1.getParameter().connectT(0, input_toggle);                         // peak1 -> input_toggle::Value2
		smoothed_parameter.getParameter().connectT(0, add);                     // smoothed_parameter -> add::Value
		smoothed_parameter.getParameter().connectT(1, add2);                    // smoothed_parameter -> add2::Value
		smoothed_parameter.getParameter().connectT(2, add3);                    // smoothed_parameter -> add3::Value
		smoothed_parameter.getParameter().connectT(3, add4);                    // smoothed_parameter -> add4::Value
		smoothed_parameter.getParameter().connectT(4, add5);                    // smoothed_parameter -> add5::Value
		smoothed_parameter.getParameter().connectT(5, add6);                    // smoothed_parameter -> add6::Value
		smoothed_parameter.getParameter().connectT(6, add11);                   // smoothed_parameter -> add11::Value
		smoothed_parameter.getParameter().connectT(7, add13);                   // smoothed_parameter -> add13::Value
		smoothed_parameter.getParameter().connectT(8, add12);                   // smoothed_parameter -> add12::Value
		smoothed_parameter.getParameter().connectT(9, add14);                   // smoothed_parameter -> add14::Value
		pma3.getWrappedObject().getParameter().connectT(0, smoothed_parameter); // pma3 -> smoothed_parameter::Value
		pma3.getWrappedObject().getParameter().connectT(1, cable_table3);       // pma3 -> cable_table3::Value
		peak2.getParameter().connectT(0, pma3);                                 // peak2 -> pma3::Value
		peak31.getParameter().connectT(0, add78);                               // peak31 -> add78::Value
		peak31.getParameter().connectT(1, add149);                              // peak31 -> add149::Value
		peak31.getParameter().connectT(2, add25);                               // peak31 -> add25::Value
		peak31.getParameter().connectT(3, add41);                               // peak31 -> add41::Value
		peak31.getParameter().connectT(4, add32);                               // peak31 -> add32::Value
		peak31.getParameter().connectT(5, add84);                               // peak31 -> add84::Value
		peak31.getParameter().connectT(6, add95);                               // peak31 -> add95::Value
		peak31.getParameter().connectT(7, add125);                              // peak31 -> add125::Value
		peak31.getParameter().connectT(8, add88);                               // peak31 -> add88::Value
		peak31.getParameter().connectT(9, add85);                               // peak31 -> add85::Value
		peak31.getParameter().connectT(10, add119);                             // peak31 -> add119::Value
		peak31.getParameter().connectT(11, add87);                              // peak31 -> add87::Value
		peak31.getParameter().connectT(12, add112);                             // peak31 -> add112::Value
		peak31.getParameter().connectT(13, add86);                              // peak31 -> add86::Value
		cable_table2.getWrappedObject().getParameter().connectT(0, add18);      // cable_table2 -> add18::Value
		cable_pack1.getWrappedObject().getParameter().connectT(0, add19);       // cable_pack1 -> add19::Value
		ramp1.getParameter().connectT(0, add16);                                // ramp1 -> add16::Value
		ramp1.getParameter().connectT(1, cable_table2);                         // ramp1 -> cable_table2::Value
		ramp1.getParameter().connectT(2, cable_pack1);                          // ramp1 -> cable_pack1::Value
		tempo_sync3.getParameter().connectT(0, ramp1);                          // tempo_sync3 -> ramp1::PeriodTime
		auto& ahdsr2_p = ahdsr2.getWrappedObject().getParameter();
		ahdsr2_p.getParameterT(0).connectT(0, add17);                            // ahdsr2 -> add17::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, ahdsr2);     // input_toggle1 -> ahdsr2::Gate
		peak11.getParameter().connectT(0, input_toggle1);                        // peak11 -> input_toggle1::Value2
		smoothed_parameter3.getParameter().connectT(0, add21);                   // smoothed_parameter3 -> add21::Value
		smoothed_parameter3.getParameter().connectT(1, add131);                  // smoothed_parameter3 -> add131::Value
		smoothed_parameter3.getParameter().connectT(2, add132);                  // smoothed_parameter3 -> add132::Value
		smoothed_parameter3.getParameter().connectT(3, add133);                  // smoothed_parameter3 -> add133::Value
		smoothed_parameter3.getParameter().connectT(4, add134);                  // smoothed_parameter3 -> add134::Value
		smoothed_parameter3.getParameter().connectT(5, add136);                  // smoothed_parameter3 -> add136::Value
		smoothed_parameter3.getParameter().connectT(6, add28);                   // smoothed_parameter3 -> add28::Value
		smoothed_parameter3.getParameter().connectT(7, add20);                   // smoothed_parameter3 -> add20::Value
		smoothed_parameter3.getParameter().connectT(8, add22);                   // smoothed_parameter3 -> add22::Value
		smoothed_parameter3.getParameter().connectT(9, add135);                  // smoothed_parameter3 -> add135::Value
		pma2.getWrappedObject().getParameter().connectT(0, smoothed_parameter3); // pma2 -> smoothed_parameter3::Value
		pma2.getWrappedObject().getParameter().connectT(1, cable_table6);        // pma2 -> cable_table6::Value
		peak12.getParameter().connectT(0, pma2);                                 // peak12 -> pma2::Value
		peak19.getParameter().connectT(0, add38);                                // peak19 -> add38::Value
		peak19.getParameter().connectT(1, add64);                                // peak19 -> add64::Value
		peak19.getParameter().connectT(2, add62);                                // peak19 -> add62::Value
		peak19.getParameter().connectT(3, add72);                                // peak19 -> add72::Value
		peak19.getParameter().connectT(4, add69);                                // peak19 -> add69::Value
		peak19.getParameter().connectT(5, add150);                               // peak19 -> add150::Value
		peak19.getParameter().connectT(6, add56);                                // peak19 -> add56::Value
		peak19.getParameter().connectT(7, add59);                                // peak19 -> add59::Value
		peak19.getParameter().connectT(8, add74);                                // peak19 -> add74::Value
		peak19.getParameter().connectT(9, add109);                               // peak19 -> add109::Value
		peak19.getParameter().connectT(10, add79);                               // peak19 -> add79::Value
		peak19.getParameter().connectT(11, add116);                              // peak19 -> add116::Value
		peak19.getParameter().connectT(12, add29);                               // peak19 -> add29::Value
		peak19.getParameter().connectT(13, add1);                                // peak19 -> add1::Value
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, receive7);                    // sliderbank -> receive7::Feedback
		sliderbank_p.getParameterT(1).connectT(0, receive6);                    // sliderbank -> receive6::Feedback
		sliderbank_p.getParameterT(2).connectT(0, receive13);                   // sliderbank -> receive13::Feedback
		sliderbank_p.getParameterT(3).connectT(0, receive4);                    // sliderbank -> receive4::Feedback
		converter6.getWrappedObject().getParameter().connectT(0, jdelay);       // converter6 -> jdelay::DelayTime
		converter7.getWrappedObject().getParameter().connectT(0, converter6);   // converter7 -> converter6::Value
		midi.getParameter().connectT(0, converter7);                            // midi -> converter7::Value
		converter9.getWrappedObject().getParameter().connectT(0, jdelay1);      // converter9 -> jdelay1::DelayTime
		converter8.getWrappedObject().getParameter().connectT(0, converter9);   // converter8 -> converter9::Value
		midi1.getParameter().connectT(0, converter8);                           // midi1 -> converter8::Value
		converter17.getWrappedObject().getParameter().connectT(0, jdelay5);     // converter17 -> jdelay5::DelayTime
		converter16.getWrappedObject().getParameter().connectT(0, converter17); // converter16 -> converter17::Value
		converter19.getWrappedObject().getParameter().connectT(0, jdelay6);     // converter19 -> jdelay6::DelayTime
		converter18.getWrappedObject().getParameter().connectT(0, converter19); // converter18 -> converter19::Value
		peak32.getParameter().connectT(0, add33);                               // peak32 -> add33::Value
		peak32.getParameter().connectT(1, add49);                               // peak32 -> add49::Value
		peak32.getParameter().connectT(2, add50);                               // peak32 -> add50::Value
		peak32.getParameter().connectT(3, add101);                              // peak32 -> add101::Value
		peak32.getParameter().connectT(4, add102);                              // peak32 -> add102::Value
		peak32.getParameter().connectT(5, add103);                              // peak32 -> add103::Value
		peak32.getParameter().connectT(6, add100);                              // peak32 -> add100::Value
		peak32.getParameter().connectT(7, add99);                               // peak32 -> add99::Value
		peak32.getParameter().connectT(8, add113);                              // peak32 -> add113::Value
		peak32.getParameter().connectT(9, add120);                              // peak32 -> add120::Value
		peak32.getParameter().connectT(10, add123);                             // peak32 -> add123::Value
		peak32.getParameter().connectT(11, add126);                             // peak32 -> add126::Value
		peak32.getParameter().connectT(12, add82);                              // peak32 -> add82::Value
		peak32.getParameter().connectT(13, add151);                             // peak32 -> add151::Value
		auto& sliderbank1_p = sliderbank1.getWrappedObject().getParameter();
		sliderbank1_p.getParameterT(0).connectT(0, receive15);                  // sliderbank1 -> receive15::Feedback
		sliderbank1_p.getParameterT(1).connectT(0, receive16);                  // sliderbank1 -> receive16::Feedback
		sliderbank1_p.getParameterT(2).connectT(0, receive17);                  // sliderbank1 -> receive17::Feedback
		sliderbank1_p.getParameterT(3).connectT(0, receive14);                  // sliderbank1 -> receive14::Feedback
		sliderbank1_p.getParameterT(4).connectT(0, receive18);                  // sliderbank1 -> receive18::Feedback
		converter11.getWrappedObject().getParameter().connectT(0, jdelay2);     // converter11 -> jdelay2::DelayTime
		converter10.getWrappedObject().getParameter().connectT(0, converter11); // converter10 -> converter11::Value
		midi2.getParameter().connectT(0, converter10);                          // midi2 -> converter10::Value
		converter13.getWrappedObject().getParameter().connectT(0, jdelay3);     // converter13 -> jdelay3::DelayTime
		converter12.getWrappedObject().getParameter().connectT(0, converter13); // converter12 -> converter13::Value
		midi3.getParameter().connectT(0, converter12);                          // midi3 -> converter12::Value
		converter15.getWrappedObject().getParameter().connectT(0, jdelay4);     // converter15 -> jdelay4::DelayTime
		converter14.getWrappedObject().getParameter().connectT(0, converter15); // converter14 -> converter15::Value
		midi4.getParameter().connectT(0, converter14);                          // midi4 -> converter14::Value
		converter21.getWrappedObject().getParameter().connectT(0, jdelay7);     // converter21 -> jdelay7::DelayTime
		converter20.getWrappedObject().getParameter().connectT(0, converter21); // converter20 -> converter21::Value
		converter23.getWrappedObject().getParameter().connectT(0, jdelay8);     // converter23 -> jdelay8::DelayTime
		converter22.getWrappedObject().getParameter().connectT(0, converter23); // converter22 -> converter23::Value
		peak33.getParameter().connectT(0, add108);                              // peak33 -> add108::Value
		peak33.getParameter().connectT(1, add107);                              // peak33 -> add107::Value
		peak33.getParameter().connectT(2, add106);                              // peak33 -> add106::Value
		peak33.getParameter().connectT(3, add105);                              // peak33 -> add105::Value
		peak33.getParameter().connectT(4, add104);                              // peak33 -> add104::Value
		peak33.getParameter().connectT(5, add53);                               // peak33 -> add53::Value
		peak33.getParameter().connectT(6, add52);                               // peak33 -> add52::Value
		peak33.getParameter().connectT(7, add51);                               // peak33 -> add51::Value
		peak33.getParameter().connectT(8, add114);                              // peak33 -> add114::Value
		peak33.getParameter().connectT(9, add121);                              // peak33 -> add121::Value
		peak33.getParameter().connectT(10, add124);                             // peak33 -> add124::Value
		peak33.getParameter().connectT(11, add127);                             // peak33 -> add127::Value
		peak33.getParameter().connectT(12, add83);                              // peak33 -> add83::Value
		peak33.getParameter().connectT(13, add152);                             // peak33 -> add152::Value
		auto& ahdsr1_p = ahdsr1.getWrappedObject().getParameter();
		ahdsr1_p.getParameterT(1).connectT(0, voice_manager); // ahdsr1 -> voice_manager::KillVoice
		
		// Send Connections ------------------------------------------------------------------------
		
		send9.connect(receive10);
		send9.connect(receive11);
		send9.connect(receive15);
		send9.connect(receive7);
		send9.connect(receive8);
		send16.connect(receive16);
		send16.connect(receive22);
		send16.connect(receive34);
		send16.connect(receive6);
		send16.connect(receive9);
		send17.connect(receive13);
		send17.connect(receive17);
		send17.connect(receive25);
		send17.connect(receive30);
		send17.connect(receive35);
		send11.connect(receive14);
		send11.connect(receive37);
		send11.connect(receive38);
		send11.connect(receive39);
		send11.connect(receive4);
		send.connect(receive);
		send1.connect(receive1);
		send2.connect(receive2);
		send3.connect(receive3);
		send12.connect(receive18);
		send12.connect(receive21);
		send12.connect(receive24);
		send12.connect(receive31);
		send12.connect(receive36);
		send13.connect(receive19);
		send14.connect(receive20);
		send18.connect(receive27);
		send19.connect(receive28);
		send15.connect(receive23);
		send15.connect(receive26);
		send15.connect(receive32);
		send15.connect(receive40);
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch9::Index is automated
		
		; // add24::Value is automated
		
		; // add23::Value is automated
		
		; // add25::Value is automated
		
		; // add1::Value is automated
		
		; // add33::Value is automated
		
		; // add51::Value is automated
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		;                              // minmax::Value is automated
		minmax.setParameterT(1, -24.); // control::minmax::Minimum
		minmax.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax.setParameterT(3, 1.);   // control::minmax::Skew
		minmax.setParameterT(4, 0.);   // control::minmax::Step
		minmax.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add26::Value is automated
		
		; // add36::Value is automated
		
		;                                 // pma::Value is automated
		;                                 // pma::Multiply is automated
		pma.setParameterT(2, -0.0297686); // control::pma::Add
		
		; // add27::Value is automated
		
		;                                 // global_mod1::Index is automated
		global_mod1.setParameterT(1, 0.); // core::global_mod::Value
		global_mod1.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod1.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod1::Intensity is automated
		
		;                               // minmax3::Value is automated
		minmax3.setParameterT(1, -12.); // control::minmax::Minimum
		minmax3.setParameterT(2, 12.);  // control::minmax::Maximum
		minmax3.setParameterT(3, 1.);   // control::minmax::Skew
		minmax3.setParameterT(4, 0.);   // control::minmax::Step
		minmax3.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add89::Value is automated
		
		; // sub21::Value is automated
		
		mod2sig1.setParameterT(0, 0.); // math::mod2sig::Value
		
		; // branch12::Index is automated
		
		; // add39::Value is automated
		
		; // add40::Value is automated
		
		; // add41::Value is automated
		
		; // add38::Value is automated
		
		; // add49::Value is automated
		
		; // add52::Value is automated
		
		clear18.setParameterT(0, 0.); // math::clear::Value
		
		;                               // minmax2::Value is automated
		minmax2.setParameterT(1, -24.); // control::minmax::Minimum
		minmax2.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax2.setParameterT(3, 1.);   // control::minmax::Skew
		minmax2.setParameterT(4, 0.);   // control::minmax::Step
		minmax2.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add42::Value is automated
		
		; // add35::Value is automated
		
		;                                  // pma1::Value is automated
		;                                  // pma1::Multiply is automated
		pma1.setParameterT(2, -0.0297686); // control::pma::Add
		
		; // add43::Value is automated
		
		;                                // global_mod::Index is automated
		global_mod.setParameterT(1, 0.); // core::global_mod::Value
		global_mod.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod.setParameterT(3, 1.); // core::global_mod::Mode
		;                                // global_mod::Intensity is automated
		
		minmax1.setParameterT(0, 0.);   // control::minmax::Value
		minmax1.setParameterT(1, -12.); // control::minmax::Minimum
		minmax1.setParameterT(2, 12.);  // control::minmax::Maximum
		minmax1.setParameterT(3, 1.);   // control::minmax::Skew
		minmax1.setParameterT(4, 0.);   // control::minmax::Step
		minmax1.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add90::Value is automated
		
		; // sub3::Value is automated
		
		mod2sig.setParameterT(0, 0.); // math::mod2sig::Value
		
		; // branch10::Index is automated
		
		; // add30::Value is automated
		
		; // add31::Value is automated
		
		; // add32::Value is automated
		
		; // add29::Value is automated
		
		; // add50::Value is automated
		
		; // add53::Value is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // pma_unscaled3::Value is automated
		;                                   // pma_unscaled3::Multiply is automated
		pma_unscaled3.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add34::Value is automated
		
		;                                 // global_mod3::Index is automated
		;                                 // global_mod3::Value is automated
		global_mod3.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod3.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod3::Intensity is automated
		
		; // add91::Value is automated
		
		; // branch11::Index is automated
		
		; // add57::Value is automated
		
		; // add68::Value is automated
		
		; // add78::Value is automated
		
		; // add56::Value is automated
		
		; // add82::Value is automated
		
		; // add83::Value is automated
		
		clear28.setParameterT(0, 0.); // math::clear::Value
		
		;                                    // pma_unscaled15::Value is automated
		;                                    // pma_unscaled15::Multiply is automated
		pma_unscaled15.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add129::Value is automated
		
		;                                  // global_mod13::Index is automated
		;                                  // global_mod13::Value is automated
		global_mod13.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod13.setParameterT(3, 1.); // core::global_mod::Mode
		;                                  // global_mod13::Intensity is automated
		
		; // add130::Value is automated
		
		; // branch16::Index is automated
		
		; // add60::Value is automated
		
		; // add61::Value is automated
		
		; // add84::Value is automated
		
		; // add59::Value is automated
		
		; // add101::Value is automated
		
		; // add104::Value is automated
		
		clear16.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // pma_unscaled6::Value is automated
		;                                   // pma_unscaled6::Multiply is automated
		pma_unscaled6.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add37::Value is automated
		
		;                                 // global_mod4::Index is automated
		;                                 // global_mod4::Value is automated
		global_mod4.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod4.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod4::Intensity is automated
		
		; // add92::Value is automated
		
		; // branch18::Index is automated
		
		; // add63::Value is automated
		
		; // add67::Value is automated
		
		; // add95::Value is automated
		
		; // add62::Value is automated
		
		; // add123::Value is automated
		
		; // add124::Value is automated
		
		clear26.setParameterT(0, 0.); // math::clear::Value
		
		;                                    // pma_unscaled13::Value is automated
		;                                    // pma_unscaled13::Multiply is automated
		pma_unscaled13.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add44::Value is automated
		
		;                                 // global_mod7::Index is automated
		;                                 // global_mod7::Value is automated
		global_mod7.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod7.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod7::Intensity is automated
		
		; // add96::Value is automated
		
		; // branch29::Index is automated
		
		; // add73::Value is automated
		
		; // add77::Value is automated
		
		; // add125::Value is automated
		
		; // add72::Value is automated
		
		; // add126::Value is automated
		
		; // add127::Value is automated
		
		clear27.setParameterT(0, 0.); // math::clear::Value
		
		pma_unscaled14.setParameterT(0, 0.); // control::pma_unscaled::Value
		;                                    // pma_unscaled14::Multiply is automated
		pma_unscaled14.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add55::Value is automated
		
		;                                 // global_mod8::Index is automated
		;                                 // global_mod8::Value is automated
		global_mod8.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod8.setParameterT(3, 0.); // core::global_mod::Mode
		;                                 // global_mod8::Intensity is automated
		
		; // add128::Value is automated
		
		; // branch17::Index is automated
		
		; // add65::Value is automated
		
		; // add66::Value is automated
		
		; // add88::Value is automated
		
		; // add64::Value is automated
		
		; // add102::Value is automated
		
		; // add105::Value is automated
		
		clear23.setParameterT(0, 0.); // math::clear::Value
		
		pma_unscaled7.setParameterT(0, 0.); // control::pma_unscaled::Value
		;                                   // pma_unscaled7::Multiply is automated
		pma_unscaled7.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add45::Value is automated
		
		;                                 // global_mod5::Index is automated
		;                                 // global_mod5::Value is automated
		global_mod5.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod5.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod5::Intensity is automated
		
		; // add93::Value is automated
		
		; // branch20::Index is automated
		
		; // add70::Value is automated
		
		; // add71::Value is automated
		
		; // add85::Value is automated
		
		; // add69::Value is automated
		
		; // add103::Value is automated
		
		; // add106::Value is automated
		
		clear20.setParameterT(0, 0.); // math::clear::Value
		
		pma_unscaled8.setParameterT(0, 0.); // control::pma_unscaled::Value
		;                                   // pma_unscaled8::Multiply is automated
		pma_unscaled8.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add46::Value is automated
		
		;                                 // global_mod6::Index is automated
		;                                 // global_mod6::Value is automated
		global_mod6.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod6.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod6::Intensity is automated
		
		; // add94::Value is automated
		
		; // branch32::Index is automated
		
		; // add147::Value is automated
		
		; // add148::Value is automated
		
		; // add149::Value is automated
		
		; // add150::Value is automated
		
		; // add151::Value is automated
		
		; // add152::Value is automated
		
		clear30.setParameterT(0, 0.); // math::clear::Value
		
		pma_unscaled17.setParameterT(0, 0.); // control::pma_unscaled::Value
		;                                    // pma_unscaled17::Multiply is automated
		pma_unscaled17.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add153::Value is automated
		
		;                                  // global_mod15::Index is automated
		;                                  // global_mod15::Value is automated
		global_mod15.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod15.setParameterT(3, 1.); // core::global_mod::Mode
		;                                  // global_mod15::Intensity is automated
		
		; // add154::Value is automated
		
		; // branch21::Index is automated
		
		; // add75::Value is automated
		
		; // add76::Value is automated
		
		; // add86::Value is automated
		
		; // add74::Value is automated
		
		; // add100::Value is automated
		
		; // add107::Value is automated
		
		clear21.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // pma_unscaled9::Value is automated
		;                                   // pma_unscaled9::Multiply is automated
		pma_unscaled9.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add47::Value is automated
		
		;                                 // global_mod9::Index is automated
		;                                 // global_mod9::Value is automated
		global_mod9.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod9.setParameterT(3, 1.); // core::global_mod::Mode
		;                                 // global_mod9::Intensity is automated
		
		; // add97::Value is automated
		
		; // branch23::Index is automated
		
		; // add110::Value is automated
		
		; // add111::Value is automated
		
		; // add112::Value is automated
		
		; // add109::Value is automated
		
		; // add113::Value is automated
		
		; // add114::Value is automated
		
		clear24.setParameterT(0, 0.); // math::clear::Value
		
		;                                    // pma_unscaled11::Value is automated
		;                                    // pma_unscaled11::Multiply is automated
		pma_unscaled11.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add54::Value is automated
		
		;                                  // global_mod11::Index is automated
		;                                  // global_mod11::Value is automated
		global_mod11.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod11.setParameterT(3, 1.); // core::global_mod::Mode
		;                                  // global_mod11::Intensity is automated
		
		; // add115::Value is automated
		
		; // add15::Value is automated
		
		; // branch22::Index is automated
		
		; // add80::Value is automated
		
		; // add81::Value is automated
		
		; // add87::Value is automated
		
		; // add79::Value is automated
		
		; // add99::Value is automated
		
		; // add108::Value is automated
		
		clear22.setParameterT(0, 0.); // math::clear::Value
		
		;                                    // pma_unscaled10::Value is automated
		;                                    // pma_unscaled10::Multiply is automated
		pma_unscaled10.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add48::Value is automated
		
		;                                  // global_mod10::Index is automated
		;                                  // global_mod10::Value is automated
		global_mod10.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod10.setParameterT(3, 1.); // core::global_mod::Mode
		;                                  // global_mod10::Intensity is automated
		
		; // add98::Value is automated
		
		; // branch25::Index is automated
		
		; // add117::Value is automated
		
		; // add118::Value is automated
		
		; // add119::Value is automated
		
		; // add116::Value is automated
		
		; // add120::Value is automated
		
		; // add121::Value is automated
		
		clear25.setParameterT(0, 0.); // math::clear::Value
		
		;                                    // pma_unscaled12::Value is automated
		;                                    // pma_unscaled12::Multiply is automated
		pma_unscaled12.setParameterT(2, 0.); // control::pma_unscaled::Add
		
		; // add58::Value is automated
		
		;                                  // global_mod12::Index is automated
		;                                  // global_mod12::Value is automated
		global_mod12.setParameterT(2, 0.); // core::global_mod::ProcessSignal
		global_mod12.setParameterT(3, 1.); // core::global_mod::Mode
		;                                  // global_mod12::Intensity is automated
		
		; // add122::Value is automated
		
		; // branch28::Index is automated
		
		receive22.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive30.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive37.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive31.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive32.setParameterT(0, 1.); // routing::receive::Feedback
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch2::Index is automated
		
		; // converter2::Value is automated
		
		phasor_fm1.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm1.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                  // phasor_fm1::FreqRatio is automated
		phasor_fm1.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		;                                   // tempo_sync::Tempo is automated
		;                                   // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 406.2); // control::tempo_sync::UnsyncedTime
		
		; // converter::Value is automated
		
		phasor_fm2.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm2.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                  // phasor_fm2::FreqRatio is automated
		phasor_fm2.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		; // branch::Index is automated
		
		;                              // gain9::Gain is automated
		gain9.setParameterT(1, 0.);    // core::gain::Smoothing
		gain9.setParameterT(2, -100.); // core::gain::ResetValue
		
		pi1.setParameterT(0, 0.650239); // math::pi::Value
		
		expr.setParameterT(0, 1.); // math::expr::Value
		
		;                               // gain37::Gain is automated
		gain37.setParameterT(1, 0.);    // core::gain::Smoothing
		gain37.setParameterT(2, -100.); // core::gain::ResetValue
		
		fmod12.setParameterT(0, 1.); // math::fmod::Value
		
		expr13.setParameterT(0, 1.); // math::expr::Value
		
		;                                           // smoothed_parameter4::Value is automated
		smoothed_parameter4.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter4.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		; // expr3::Value is automated
		
		expr2.setParameterT(0, 1.); // math::expr::Value
		
		;                                           // smoothed_parameter1::Value is automated
		smoothed_parameter1.setParameterT(1, 70.9); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter1.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		expr6.setParameterT(0, 1.); // math::expr::Value
		
		; // expr4::Value is automated
		
		expr5.setParameterT(0, 1.); // math::expr::Value
		
		fmod.setParameterT(0, 1.); // math::fmod::Value
		
		pi.setParameterT(0, 0.648856); // math::pi::Value
		
		;                           // gain3::Gain is automated
		gain3.setParameterT(1, 0.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.); // core::gain::ResetValue
		
		pi6.setParameterT(0, 0.648856); // math::pi::Value
		
		;                            // gain35::Gain is automated
		gain35.setParameterT(1, 0.); // core::gain::Smoothing
		gain35.setParameterT(2, 0.); // core::gain::ResetValue
		
		fmod10.setParameterT(0, 1.); // math::fmod::Value
		
		;                           // gain6::Gain is automated
		gain6.setParameterT(1, 0.); // core::gain::Smoothing
		gain6.setParameterT(2, 0.); // core::gain::ResetValue
		
		rect.setParameterT(0, 1.); // math::rect::Value
		
		;                           // gain4::Gain is automated
		gain4.setParameterT(1, 0.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.); // core::gain::ResetValue
		
		fmod2.setParameterT(0, 1.); // math::fmod::Value
		
		pi2.setParameterT(0, 0.32); // math::pi::Value
		
		rect1.setParameterT(0, 1.); // math::rect::Value
		
		;                            // gain13::Gain is automated
		gain13.setParameterT(1, 0.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.); // core::gain::ResetValue
		
		;                           // gain7::Gain is automated
		gain7.setParameterT(1, 0.); // core::gain::Smoothing
		gain7.setParameterT(2, 0.); // core::gain::ResetValue
		
		fmod4.setParameterT(0, 1.); // math::fmod::Value
		
		;                            // gain14::Gain is automated
		gain14.setParameterT(1, 0.); // core::gain::Smoothing
		gain14.setParameterT(2, 0.); // core::gain::ResetValue
		
		;                            // gain15::Gain is automated
		gain15.setParameterT(1, 0.); // core::gain::Smoothing
		gain15.setParameterT(2, 0.); // core::gain::ResetValue
		
		fmod6.setParameterT(0, 1.); // math::fmod::Value
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		; // branch27::Index is automated
		
		receive11.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive25.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive38.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive24.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive26.setParameterT(0, 1.); // routing::receive::Feedback
		
		;                               // gain32::Gain is automated
		gain32.setParameterT(1, 0.);    // core::gain::Smoothing
		gain32.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch5::Index is automated
		
		; // converter3::Value is automated
		
		phasor_fm.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                 // phasor_fm::FreqRatio is automated
		phasor_fm.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		;                                    // tempo_sync2::Tempo is automated
		;                                    // tempo_sync2::Multiplier is automated
		tempo_sync2.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		; // converter1::Value is automated
		
		phasor_fm3.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm3.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                  // phasor_fm3::FreqRatio is automated
		phasor_fm3.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		; // branch4::Index is automated
		
		;                               // gain10::Gain is automated
		gain10.setParameterT(1, 0.);    // core::gain::Smoothing
		gain10.setParameterT(2, -100.); // core::gain::ResetValue
		
		pi3.setParameterT(0, 0.650239); // math::pi::Value
		
		expr1.setParameterT(0, 1.); // math::expr::Value
		
		;                               // gain39::Gain is automated
		gain39.setParameterT(1, 0.);    // core::gain::Smoothing
		gain39.setParameterT(2, -100.); // core::gain::ResetValue
		
		fmod13.setParameterT(0, 1.); // math::fmod::Value
		
		expr14.setParameterT(0, 1.); // math::expr::Value
		
		;                                           // smoothed_parameter5::Value is automated
		smoothed_parameter5.setParameterT(1, 100.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter5.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		; // expr7::Value is automated
		
		expr8.setParameterT(0, 1.); // math::expr::Value
		
		;                                           // smoothed_parameter2::Value is automated
		smoothed_parameter2.setParameterT(1, 70.9); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter2.setParameterT(2, 1.);   // control::smoothed_parameter::Enabled
		
		expr9.setParameterT(0, 1.); // math::expr::Value
		
		; // expr10::Value is automated
		
		expr11.setParameterT(0, 1.); // math::expr::Value
		
		fmod1.setParameterT(0, 1.); // math::fmod::Value
		
		pi4.setParameterT(0, 0.648856); // math::pi::Value
		
		;                           // gain5::Gain is automated
		gain5.setParameterT(1, 0.); // core::gain::Smoothing
		gain5.setParameterT(2, 0.); // core::gain::ResetValue
		
		pi7.setParameterT(0, 0.648856); // math::pi::Value
		
		;                            // gain36::Gain is automated
		gain36.setParameterT(1, 0.); // core::gain::Smoothing
		gain36.setParameterT(2, 0.); // core::gain::ResetValue
		
		fmod11.setParameterT(0, 1.); // math::fmod::Value
		
		;                            // gain11::Gain is automated
		gain11.setParameterT(1, 0.); // core::gain::Smoothing
		gain11.setParameterT(2, 0.); // core::gain::ResetValue
		
		rect2.setParameterT(0, 1.); // math::rect::Value
		
		;                            // gain12::Gain is automated
		gain12.setParameterT(1, 0.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.); // core::gain::ResetValue
		
		fmod3.setParameterT(0, 1.); // math::fmod::Value
		
		pi5.setParameterT(0, 0.32); // math::pi::Value
		
		rect3.setParameterT(0, 1.); // math::rect::Value
		
		;                            // gain16::Gain is automated
		gain16.setParameterT(1, 0.); // core::gain::Smoothing
		gain16.setParameterT(2, 0.); // core::gain::ResetValue
		
		;                            // gain17::Gain is automated
		gain17.setParameterT(1, 0.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.); // core::gain::ResetValue
		
		fmod5.setParameterT(0, 1.); // math::fmod::Value
		
		;                            // gain18::Gain is automated
		gain18.setParameterT(1, 0.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.); // core::gain::ResetValue
		
		;                            // gain19::Gain is automated
		gain19.setParameterT(1, 0.); // core::gain::Smoothing
		gain19.setParameterT(2, 0.); // core::gain::ResetValue
		
		fmod7.setParameterT(0, 1.); // math::fmod::Value
		
		sig2mod2.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		clear12.setParameterT(0, 0.); // math::clear::Value
		
		one_pole9.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole9.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole9.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole9.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole9.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole9.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch26::Index is automated
		
		receive8.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive9.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive39.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive21.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive23.setParameterT(0, 1.); // routing::receive::Feedback
		
		one_pole7.setParameterT(0, 50.1942); // filters::one_pole::Frequency
		one_pole7.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole7.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole7.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole7.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole7.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		;                               // gain21::Gain is automated
		gain21.setParameterT(1, 20.);   // core::gain::Smoothing
		gain21.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain20::Gain is automated
		gain20.setParameterT(1, 20.);  // core::gain::Smoothing
		gain20.setParameterT(2, -24.); // core::gain::ResetValue
		
		;                                   // tempo_sync4::Tempo is automated
		;                                   // tempo_sync4::Multiplier is automated
		tempo_sync4.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync4.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch3::Index is automated
		
		; // add7::Value is automated
		
		rect6.setParameterT(0, 0.); // math::rect::Value
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 0.); // control::input_toggle::Value1
		;                                  // input_toggle::Value2 is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
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
		
		; // cable_table4::Value is automated
		
		; // cable_table3::Value is automated
		
		; // add9::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack::Value is automated
		
		; // add10::Value is automated
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		;                                        // smoothed_parameter::Value is automated
		smoothed_parameter.setParameterT(1, 0.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // branch1::Index is automated
		
		; // add13::Value is automated
		
		; // add::Value is automated
		
		; // add12::Value is automated
		
		; // add11::Value is automated
		
		; // add2::Value is automated
		
		; // add3::Value is automated
		
		; // add4::Value is automated
		
		; // add5::Value is automated
		
		; // add14::Value is automated
		
		; // add6::Value is automated
		
		; // branch14::Index is automated
		
		file_player.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);      // core::file_player::Gate
		file_player.setParameterT(2, 850.645); // core::file_player::RootFrequency
		file_player.setParameterT(3, 0.96);    // core::file_player::FreqRatio
		
		file_player2.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player2.setParameterT(1, 1.);      // core::file_player::Gate
		file_player2.setParameterT(2, 850.645); // core::file_player::RootFrequency
		file_player2.setParameterT(3, 0.96);    // core::file_player::FreqRatio
		
		one_pole.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		sig2mod4.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // branch30::Index is automated
		
		receive10.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive34.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive35.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive36.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive40.setParameterT(0, 1.); // routing::receive::Feedback
		
		one_pole8.setParameterT(0, 50.1942); // filters::one_pole::Frequency
		one_pole8.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole8.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole8.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole8.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole8.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		;                            // gain22::Gain is automated
		gain22.setParameterT(1, 0.); // core::gain::Smoothing
		gain22.setParameterT(2, 0.); // core::gain::ResetValue
		
		;                             // gain23::Gain is automated
		gain23.setParameterT(1, 0.8); // core::gain::Smoothing
		gain23.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                   // tempo_sync3::Tempo is automated
		;                                   // tempo_sync3::Multiplier is automated
		tempo_sync3.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync3.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp1::PeriodTime is automated
		ramp1.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp1.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch7::Index is automated
		
		; // add16::Value is automated
		
		rect7.setParameterT(0, 0.); // math::rect::Value
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // input_toggle1::Input is automated
		input_toggle1.setParameterT(1, 0.); // control::input_toggle::Value1
		;                                   // input_toggle1::Value2 is automated
		
		;                                  // ahdsr2::Attack is automated
		ahdsr2.setParameterT(1, 1.);       // envelope::ahdsr::AttackLevel
		;                                  // ahdsr2::Hold is automated
		;                                  // ahdsr2::Decay is automated
		;                                  // ahdsr2::Sustain is automated
		;                                  // ahdsr2::Release is automated
		ahdsr2.setParameterT(6, 0.450656); // envelope::ahdsr::AttackCurve
		ahdsr2.setParameterT(7, 0.);       // envelope::ahdsr::Retrigger
		;                                  // ahdsr2::Gate is automated
		
		; // add17::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table2::Value is automated
		
		; // cable_table5::Value is automated
		
		; // cable_table6::Value is automated
		
		; // add18::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack1::Value is automated
		
		; // add19::Value is automated
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		;                                         // smoothed_parameter3::Value is automated
		smoothed_parameter3.setParameterT(1, 0.); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter3.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // branch8::Index is automated
		
		; // add20::Value is automated
		
		; // add21::Value is automated
		
		; // add22::Value is automated
		
		; // add28::Value is automated
		
		; // add131::Value is automated
		
		; // add132::Value is automated
		
		; // add133::Value is automated
		
		; // add134::Value is automated
		
		; // add135::Value is automated
		
		; // add136::Value is automated
		
		; // branch15::Index is automated
		
		file_player1.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player1.setParameterT(1, 1.);      // core::file_player::Gate
		file_player1.setParameterT(2, 850.645); // core::file_player::RootFrequency
		file_player1.setParameterT(3, 0.96);    // core::file_player::FreqRatio
		
		file_player3.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player3.setParameterT(1, 1.);      // core::file_player::Gate
		file_player3.setParameterT(2, 850.645); // core::file_player::RootFrequency
		file_player3.setParameterT(3, 0.96);    // core::file_player::FreqRatio
		
		one_pole1.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole1.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		sig2mod3.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // receive7::Feedback is automated
		
		; // receive6::Feedback is automated
		
		; // receive13::Feedback is automated
		
		; // receive4::Feedback is automated
		
		; // branch6::Index is automated
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 1.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 2.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf3::Frequency is automated
		;                            // svf3::Q is automated
		svf3.setParameterT(2, 0.);   // filters::svf::Gain
		svf3.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf3.setParameterT(4, 3.);   // filters::svf::Mode
		svf3.setParameterT(5, 1.);   // filters::svf::Enabled
		
		one_pole6.setParameterT(0, 50.);  // filters::one_pole::Frequency
		one_pole6.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole6.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole6.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole6.setParameterT(4, 10.);  // filters::one_pole::Mode
		one_pole6.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                    // allpass::Frequency is automated
		;                                    // allpass::Q is automated
		allpass.setParameterT(2, 0.);        // filters::allpass::Gain
		allpass.setParameterT(3, 0.0321673); // filters::allpass::Smoothing
		allpass.setParameterT(4, 0.);        // filters::allpass::Mode
		allpass.setParameterT(5, 1.);        // filters::allpass::Enabled
		
		; // receive::Feedback is automated
		
		; // converter7::Value is automated
		
		; // converter6::Value is automated
		
		jdelay.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                             // jdelay::DelayTime is automated
		
		;                                        // one_pole2::Frequency is automated
		;                                        // one_pole2::Q is automated
		one_pole2.setParameterT(2, 0.);          // filters::one_pole::Gain
		one_pole2.setParameterT(3, 0.000309024); // filters::one_pole::Smoothing
		one_pole2.setParameterT(4, 0.);          // filters::one_pole::Mode
		one_pole2.setParameterT(5, 1.);          // filters::one_pole::Enabled
		
		; // receive1::Feedback is automated
		
		; // converter8::Value is automated
		
		; // converter9::Value is automated
		
		jdelay1.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                              // jdelay1::DelayTime is automated
		
		;                                       // one_pole3::Frequency is automated
		;                                       // one_pole3::Q is automated
		one_pole3.setParameterT(2, 2.34452);    // filters::one_pole::Gain
		one_pole3.setParameterT(3, 0.00394027); // filters::one_pole::Smoothing
		one_pole3.setParameterT(4, 1.);         // filters::one_pole::Mode
		one_pole3.setParameterT(5, 1.);         // filters::one_pole::Enabled
		
		; // receive2::Feedback is automated
		
		converter16.setParameterT(0, 0.); // control::converter::Value
		
		; // converter17::Value is automated
		
		jdelay5.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                              // jdelay5::DelayTime is automated
		
		;                                       // one_pole4::Frequency is automated
		one_pole4.setParameterT(1, 0.);         // filters::one_pole::Q
		one_pole4.setParameterT(2, 2.34452);    // filters::one_pole::Gain
		one_pole4.setParameterT(3, 0.00394027); // filters::one_pole::Smoothing
		one_pole4.setParameterT(4, 0.);         // filters::one_pole::Mode
		one_pole4.setParameterT(5, 1.);         // filters::one_pole::Enabled
		
		; // receive3::Feedback is automated
		
		converter18.setParameterT(0, 0.); // control::converter::Value
		
		; // converter19::Value is automated
		
		jdelay6.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                              // jdelay6::DelayTime is automated
		
		;                                       // one_pole5::Frequency is automated
		one_pole5.setParameterT(1, 0.);         // filters::one_pole::Q
		one_pole5.setParameterT(2, 2.34452);    // filters::one_pole::Gain
		one_pole5.setParameterT(3, 0.00394027); // filters::one_pole::Smoothing
		one_pole5.setParameterT(4, 1.);         // filters::one_pole::Mode
		one_pole5.setParameterT(5, 1.);         // filters::one_pole::Enabled
		
		sig2mod5.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear10.setParameterT(0, 0.); // math::clear::Value
		
		;                              // gain38::Gain is automated
		gain38.setParameterT(1, 0.4);  // core::gain::Smoothing
		gain38.setParameterT(2, -14.); // core::gain::ResetValue
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		sliderbank1.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // receive15::Feedback is automated
		
		; // receive16::Feedback is automated
		
		; // receive17::Feedback is automated
		
		; // receive14::Feedback is automated
		
		; // receive18::Feedback is automated
		
		; // branch13::Index is automated
		
		;                          // svf8::Frequency is automated
		;                          // svf8::Q is automated
		svf8.setParameterT(2, 0.); // filters::svf::Gain
		svf8.setParameterT(3, 0.); // filters::svf::Smoothing
		svf8.setParameterT(4, 0.); // filters::svf::Mode
		svf8.setParameterT(5, 1.); // filters::svf::Enabled
		
		;                            // svf9::Frequency is automated
		;                            // svf9::Q is automated
		svf9.setParameterT(2, 0.);   // filters::svf::Gain
		svf9.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf9.setParameterT(4, 1.);   // filters::svf::Mode
		svf9.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // svf10::Frequency is automated
		;                             // svf10::Q is automated
		svf10.setParameterT(2, 0.);   // filters::svf::Gain
		svf10.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf10.setParameterT(4, 2.);   // filters::svf::Mode
		svf10.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // svf11::Frequency is automated
		;                             // svf11::Q is automated
		svf11.setParameterT(2, 0.);   // filters::svf::Gain
		svf11.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf11.setParameterT(4, 3.);   // filters::svf::Mode
		svf11.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                                // allpass2::Frequency is automated
		;                                // allpass2::Q is automated
		allpass2.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass2.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass2.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass2.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		; // receive19::Feedback is automated
		
		; // converter10::Value is automated
		
		; // converter11::Value is automated
		
		jdelay2.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                              // jdelay2::DelayTime is automated
		
		; // converter12::Value is automated
		
		; // converter13::Value is automated
		
		jdelay3.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                              // jdelay3::DelayTime is automated
		
		;                                // one_pole12::Frequency is automated
		;                                // one_pole12::Q is automated
		one_pole12.setParameterT(2, 0.); // filters::one_pole::Gain
		one_pole12.setParameterT(3, 0.); // filters::one_pole::Smoothing
		one_pole12.setParameterT(4, 0.); // filters::one_pole::Mode
		one_pole12.setParameterT(5, 1.); // filters::one_pole::Enabled
		
		; // receive20::Feedback is automated
		
		; // converter14::Value is automated
		
		; // converter15::Value is automated
		
		jdelay4.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                              // jdelay4::DelayTime is automated
		
		;                                     // one_pole13::Frequency is automated
		;                                     // one_pole13::Q is automated
		one_pole13.setParameterT(2, 2.34452); // filters::one_pole::Gain
		one_pole13.setParameterT(3, 0.);      // filters::one_pole::Smoothing
		one_pole13.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole13.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		; // receive27::Feedback is automated
		
		converter20.setParameterT(0, 0.); // control::converter::Value
		
		; // converter21::Value is automated
		
		jdelay7.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                              // jdelay7::DelayTime is automated
		
		;                                     // one_pole14::Frequency is automated
		one_pole14.setParameterT(1, 0.);      // filters::one_pole::Q
		one_pole14.setParameterT(2, 2.34452); // filters::one_pole::Gain
		one_pole14.setParameterT(3, 0.);      // filters::one_pole::Smoothing
		one_pole14.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole14.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		; // receive28::Feedback is automated
		
		converter22.setParameterT(0, 0.); // control::converter::Value
		
		; // converter23::Value is automated
		
		jdelay8.setParameterT(0, 30.); // jdsp::jdelay::Limit
		;                              // jdelay8::DelayTime is automated
		
		;                                     // one_pole15::Frequency is automated
		one_pole15.setParameterT(1, 0.);      // filters::one_pole::Q
		one_pole15.setParameterT(2, 2.34452); // filters::one_pole::Gain
		one_pole15.setParameterT(3, 0.);      // filters::one_pole::Smoothing
		one_pole15.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole15.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		sig2mod6.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear11.setParameterT(0, 0.); // math::clear::Value
		
		;                              // gain41::Gain is automated
		gain41.setParameterT(1, 0.);   // core::gain::Smoothing
		gain41.setParameterT(2, -10.); // core::gain::ResetValue
		
		;                              // jpanner2::Pan is automated
		jpanner2.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		;                             // ahdsr1::Attack is automated
		ahdsr1.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		;                             // ahdsr1::Hold is automated
		;                             // ahdsr1::Decay is automated
		;                             // ahdsr1::Sustain is automated
		;                             // ahdsr1::Release is automated
		ahdsr1.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr1.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		ahdsr1.setParameterT(8, 0.);  // envelope::ahdsr::Gate
		
		; // voice_manager::KillVoice is automated
		
		;                            // gain::Gain is automated
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, -18.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 32.);
		this->setParameterT(7, 2.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.51);
		this->setParameterT(10, 0.77);
		this->setParameterT(11, 0.05);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 0.);
		this->setParameterT(20, -0.04);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 2.);
		this->setParameterT(23, 0.69);
		this->setParameterT(24, 0.);
		this->setParameterT(25, 0.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 0.96);
		this->setParameterT(28, -0.04);
		this->setParameterT(29, 2.);
		this->setParameterT(30, -23.);
		this->setParameterT(31, -0.244125);
		this->setParameterT(32, 0.);
		this->setParameterT(33, 0.);
		this->setParameterT(34, 1.);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 0.99);
		this->setParameterT(37, 0.);
		this->setParameterT(38, 0.);
		this->setParameterT(39, 1.);
		this->setParameterT(40, 1.);
		this->setParameterT(41, 1.);
		this->setParameterT(42, 0.);
		this->setParameterT(43, 0.);
		this->setParameterT(44, 1.);
		this->setParameterT(45, 0.3);
		this->setParameterT(46, 0.);
		this->setParameterT(47, 0.);
		this->setParameterT(48, 1.);
		this->setParameterT(49, 0.);
		this->setParameterT(50, 0.);
		this->setParameterT(51, 0.78);
		this->setParameterT(52, 1.);
		this->setParameterT(53, 3.);
		this->setParameterT(54, 0.);
		this->setParameterT(55, 0.);
		this->setParameterT(56, 0.);
		this->setParameterT(57, 1.);
		this->setParameterT(58, 1.);
		this->setParameterT(59, 1.);
		this->setParameterT(60, 1.);
		this->setParameterT(61, 1.);
		this->setParameterT(62, 1.);
		this->setParameterT(63, 0.);
		this->setParameterT(64, 3715.);
		this->setParameterT(65, 0.);
		this->setParameterT(66, 10000.);
		this->setParameterT(67, 0.);
		this->setParameterT(68, 1908.);
		this->setParameterT(69, 1.);
		this->setParameterT(70, 6.1);
		this->setParameterT(71, 7.);
		this->setParameterT(72, 5.);
		this->setParameterT(73, 1.);
		this->setParameterT(74, 1.);
		this->setParameterT(75, 1.);
		this->setParameterT(76, 0.);
		this->setParameterT(77, 0.);
		this->setParameterT(78, 1.);
		this->setParameterT(79, 0.);
		this->setParameterT(80, 1.);
		this->setParameterT(81, 0.);
		this->setParameterT(82, 1.);
		this->setParameterT(83, 1.);
		this->setParameterT(84, 1.);
		this->setParameterT(85, 0.5);
		this->setParameterT(86, 0.);
		this->setParameterT(87, 0.);
		this->setParameterT(88, 0.);
		this->setParameterT(89, 1.);
		this->setParameterT(90, 1.);
		this->setParameterT(91, 1.);
		this->setParameterT(92, 1.);
		this->setParameterT(93, 0.);
		this->setParameterT(94, 0.);
		this->setParameterT(95, 10000.);
		this->setParameterT(96, 0.);
		this->setParameterT(97, 1.);
		this->setParameterT(98, 14.);
		this->setParameterT(99, 1.);
		this->setParameterT(100, 2.);
		this->setParameterT(101, 0.);
		this->setParameterT(102, 0.61);
		this->setParameterT(103, 0.);
		this->setParameterT(104, 0.);
		this->setParameterT(105, 1.);
		this->setParameterT(106, 1.);
		this->setParameterT(107, 1.);
		this->setParameterT(108, 1.);
		this->setParameterT(109, 3.);
		this->setParameterT(110, 1.);
		this->setParameterT(111, 222.);
		this->setParameterT(112, 0.);
		this->setParameterT(113, 2);
		this->setParameterT(114, 1.);
		this->setParameterT(115, 3);
		this->setParameterT(116, 0.);
		this->setParameterT(117, 0.);
		this->setParameterT(118, 1.);
		this->setParameterT(119, 0.);
		this->setParameterT(120, 0.);
		this->setParameterT(121, 0.);
		this->setParameterT(122, 0.);
		this->setParameterT(123, 0.);
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
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(3).                                                          // Sm2_impl::global_mod1_t<NV>
        getT(0).getT(0).getT(3).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(0).                                                                  // Sm2_impl::global_mod_t<NV>
        getT(3).getT(0).getT(0).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(0).                                                                  // Sm2_impl::global_mod3_t<NV>
        getT(3).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).                                                                  // Sm2_impl::global_mod13_t<NV>
        getT(3).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(4).getT(0).                                                                  // Sm2_impl::global_mod4_t<NV>
        getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(5).getT(0).                                                                  // Sm2_impl::global_mod7_t<NV>
        getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(6).getT(0).                                                                  // Sm2_impl::global_mod8_t<NV>
        getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(7).getT(0).getT(3).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // Sm2_impl::global_mod5_t<NV>
		this->getT(0).getT(0).getT(8).getT(0).                                                                  // Sm2_impl::global_mod6_t<NV>
        getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(9).getT(0).   // Sm2_impl::global_mod15_t<NV>
        getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(10).getT(0).  // Sm2_impl::global_mod9_t<NV>
        getT(3).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(11).getT(0).  // Sm2_impl::global_mod11_t<NV>
        getT(3).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(12).getT(0).  // Sm2_impl::global_mod10_t<NV>
        getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(13).getT(0).  // Sm2_impl::global_mod12_t<NV>
        getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak5_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(3).                                           // Sm2_impl::global_mod1_t<NV>
        getT(0).getT(0).getT(3).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).getT(2).setExternalData(b, index); // Sm2_impl::peak16_t
		this->getT(0).getT(0).getT(0).getT(0).getT(3).getT(0).getT(4).setExternalData(b, index); // Sm2_impl::peak_unscaled_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak13_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).                                                   // Sm2_impl::global_mod_t<NV>
        getT(3).getT(0).getT(0).getT(3).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(0).getT(3).getT(0).getT(3).setExternalData(b, index); // Sm2_impl::peak_unscaled2_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak7_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).                                                   // Sm2_impl::global_mod3_t<NV>
        getT(3).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(2).getT(0).getT(3).getT(1).setExternalData(b, index);         // Sm2_impl::peak35_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak9_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).                                                   // Sm2_impl::global_mod13_t<NV>
        getT(3).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(3).getT(0).getT(4).setExternalData(b, index);                 // Sm2_impl::peak36_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak17_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).                                                   // Sm2_impl::global_mod4_t<NV>
        getT(3).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(4).getT(0).getT(4).setExternalData(b, index);                 // Sm2_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak30_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).                                                   // Sm2_impl::global_mod7_t<NV>
        getT(3).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(5).getT(0).getT(4).setExternalData(b, index);                 // Sm2_impl::peak8_t<NV>
		this->getT(0).getT(0).getT(6).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak21_t
		this->getT(0).getT(0).getT(6).getT(0).                                                   // Sm2_impl::global_mod8_t<NV>
        getT(3).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(6).getT(0).getT(4).setExternalData(b, index);                 // Sm2_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(7).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak18_t
		this->getT(0).getT(0).getT(7).getT(0).getT(3).getT(1).getT(0).setExternalData(b, index); // Sm2_impl::global_mod5_t<NV>
		this->getT(0).getT(0).getT(7).getT(0).getT(4).getT(0).setExternalData(b, index);         // Sm2_impl::peak14_t<NV>
		this->getT(0).getT(0).getT(8).getT(0).getT(1).setExternalData(b, index);                 // Sm2_impl::peak20_t
		this->getT(0).getT(0).getT(8).getT(0).                                                   // Sm2_impl::global_mod6_t<NV>
        getT(3).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(8).getT(0).getT(4).setExternalData(b, index);          // Sm2_impl::peak_t<NV>
		this->getT(0).getT(0).getT(9).getT(0).getT(1).setExternalData(b, index);          // Sm2_impl::peak38_t
		this->getT(0).getT(0).getT(9).getT(0).                                            // Sm2_impl::global_mod15_t<NV>
        getT(3).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(9).getT(0).getT(4).setExternalData(b, index);          // Sm2_impl::peak39_t<NV>
		this->getT(0).getT(0).getT(10).getT(0).getT(1).setExternalData(b, index);         // Sm2_impl::peak22_t<NV>
		this->getT(0).getT(0).getT(10).getT(0).                                           // Sm2_impl::global_mod9_t<NV>
        getT(3).getT(0).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(10).getT(0).getT(3).getT(1).setExternalData(b, index); // Sm2_impl::peak23_t<NV>
		this->getT(0).getT(0).getT(11).getT(0).getT(1).setExternalData(b, index);         // Sm2_impl::peak26_t<NV>
		this->getT(0).getT(0).getT(11).getT(0).                                           // Sm2_impl::global_mod11_t<NV>
        getT(3).getT(0).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(11).getT(0).getT(3).getT(1).setExternalData(b, index); // Sm2_impl::peak27_t<NV>
		this->getT(0).getT(0).getT(12).getT(0).getT(1).setExternalData(b, index);         // Sm2_impl::peak24_t<NV>
		this->getT(0).getT(0).getT(12).getT(0).                                           // Sm2_impl::global_mod10_t<NV>
        getT(3).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(12).getT(0).getT(4).setExternalData(b, index); // Sm2_impl::peak25_t<NV>
		this->getT(0).getT(0).getT(13).getT(0).getT(1).setExternalData(b, index); // Sm2_impl::peak28_t<NV>
		this->getT(0).getT(0).getT(13).getT(0).                                   // Sm2_impl::global_mod12_t<NV>
        getT(3).getT(1).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(13).getT(0).getT(4).setExternalData(b, index); // Sm2_impl::peak29_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                            // Sm2_impl::table_t
        getT(0).getT(0).getT(4).getT(4).getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table10_t
        getT(0).getT(0).getT(4).getT(5).getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table2_t
        getT(0).getT(0).getT(4).getT(8).getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table1_t
        getT(0).getT(0).getT(4).getT(9).getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table3_t
        getT(0).getT(0).getT(4).getT(10).getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table4_t
        getT(0).getT(0).getT(4).getT(11).getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).           // Sm2_impl::oscilloscope_t
        getT(0).getT(5).getT(0).getT(1).getT(0).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).           // Sm2_impl::peak15_t<NV>
        getT(0).getT(5).getT(0).getT(1).getT(0).getT(1).
        getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table5_t
        getT(0).getT(1).getT(4).getT(4).getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table11_t
        getT(0).getT(1).getT(4).getT(5).getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table6_t
        getT(0).getT(1).getT(4).getT(8).getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table7_t
        getT(0).getT(1).getT(4).getT(9).getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table8_t
        getT(0).getT(1).getT(4).getT(10).getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).                   // Sm2_impl::table9_t
        getT(0).getT(1).getT(4).getT(11).getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).           // Sm2_impl::oscilloscope1_t
        getT(1).getT(5).getT(0).getT(1).getT(1).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0).           // Sm2_impl::peak34_t<NV>
        getT(1).getT(5).getT(0).getT(1).getT(1).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).                           // Sm2_impl::peak4_t
        getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).getT(0).                   // Sm2_impl::ramp_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).           // Sm2_impl::peak1_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
        getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).           // Sm2_impl::ahdsr_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).           // Sm2_impl::cable_table1_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).           // Sm2_impl::cable_table4_t
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
        getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).           // Sm2_impl::cable_table3_t
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).getT(0).getT(0).           // Sm2_impl::cable_pack_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).getT(0).                   // Sm2_impl::peak2_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).
        getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).                           // Sm2_impl::file_player_t<NV>
        getT(0).getT(0).getT(0).getT(5).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(5).                           // Sm2_impl::file_player2_t<NV>
        getT(0).getT(0).getT(0).getT(5).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(6).                           // Sm2_impl::peak31_t<NV>
        getT(0).getT(1).getT(0).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).                           // Sm2_impl::peak10_t
        getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).getT(0).                   // Sm2_impl::ramp1_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).           // Sm2_impl::peak11_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
        getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).           // Sm2_impl::ahdsr2_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).           // Sm2_impl::cable_table2_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).           // Sm2_impl::cable_table5_t
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
        getT(2).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).           // Sm2_impl::cable_table6_t
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).           // Sm2_impl::cable_pack1_t<NV>
        getT(0).getT(1).getT(0).getT(0).getT(2).getT(2).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).getT(0).                   // Sm2_impl::peak12_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).
        getT(3).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).                           // Sm2_impl::file_player1_t<NV>
        getT(0).getT(0).getT(0).getT(5).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(4).                           // Sm2_impl::file_player3_t<NV>
        getT(0).getT(0).getT(0).getT(5).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(2).getT(5).                           // Sm2_impl::peak19_t<NV>
        getT(0).getT(1).getT(0).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(3).getT(0).getT(0).setExternalData(b, index); // Sm2_impl::sliderbank_t<NV>
		this->getT(0).getT(3).getT(0).getT(3).                           // Sm2_impl::peak32_t<NV>
        getT(0).getT(1).getT(0).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(3).getT(1).getT(0).setExternalData(b, index); // Sm2_impl::sliderbank1_t<NV>
		this->getT(0).getT(3).getT(1).getT(3).                           // Sm2_impl::peak33_t<NV>
        getT(0).getT(1).getT(0).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).setExternalData(b, index); // Sm2_impl::ahdsr1_t<NV>
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
using Sm2 = wrap::node<Sm2_impl::instance<NV>>;
}


