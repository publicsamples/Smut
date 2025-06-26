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

namespace osc1_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable3_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass_t_ = container::chain<parameter::empty, 
                                        wrap::fix<1, chain39_t<NV>>>;

template <int NV>
using soft_bypass_t = bypass::smoothed<20, soft_bypass_t_<NV>>;
template <int NV>
using xfader2_c1 = parameter::bypass<soft_bypass_t<NV>>;

template <int NV>
using xfader2_multimod = parameter::list<parameter::empty, xfader2_c1<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::switcher>;
DECLARE_PARAMETER_RANGE_SKEW(sliderbank3_c0_0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using sliderbank3_c0_0 = parameter::from0To1<core::gain<NV>, 
                                             0, 
                                             sliderbank3_c0_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(sliderbank3_c0_1Range, 
                             0., 
                             1., 
                             13.65);

template <int NV>
using sliderbank3_c0_1 = parameter::from0To1<xfader2_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank3_c0 = parameter::chain<ranges::Identity, 
                                        sliderbank3_c0_0<NV>, 
                                        sliderbank3_c0_1<NV>>;

using global_cable11_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass7_t_ = container::chain<parameter::empty, 
                                         wrap::fix<1, chain41_t<NV>>>;

template <int NV>
using soft_bypass7_t = bypass::smoothed<20, soft_bypass7_t_<NV>>;
template <int NV>
using xfader13_c1 = parameter::bypass<soft_bypass7_t<NV>>;

template <int NV>
using xfader13_multimod = parameter::list<parameter::empty, xfader13_c1<NV>>;

template <int NV>
using xfader13_t = control::xfader<xfader13_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank3_c1_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank3_c1_1 = parameter::from0To1<xfader13_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank3_c1 = parameter::chain<ranges::Identity, 
                                        sliderbank3_c1_0<NV>, 
                                        sliderbank3_c1_1<NV>>;

using global_cable10_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass6_t_ = container::chain<parameter::empty, 
                                         wrap::fix<1, chain40_t<NV>>>;

template <int NV>
using soft_bypass6_t = bypass::smoothed<20, soft_bypass6_t_<NV>>;
template <int NV>
using xfader12_c1 = parameter::bypass<soft_bypass6_t<NV>>;

template <int NV>
using xfader12_multimod = parameter::list<parameter::empty, xfader12_c1<NV>>;

template <int NV>
using xfader12_t = control::xfader<xfader12_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank3_c2_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank3_c2_1 = parameter::from0To1<xfader12_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank3_c2 = parameter::chain<ranges::Identity, 
                                        sliderbank3_c2_0<NV>, 
                                        sliderbank3_c2_1<NV>>;

using global_cable14_t_index = runtime_target::indexers::fix_hash<2333887>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass5_t_ = container::chain<parameter::empty, 
                                         wrap::fix<1, chain42_t<NV>>>;

template <int NV>
using soft_bypass5_t = bypass::smoothed<20, soft_bypass5_t_<NV>>;
template <int NV>
using xfader11_c1 = parameter::bypass<soft_bypass5_t<NV>>;

template <int NV>
using xfader11_multimod = parameter::list<parameter::empty, xfader11_c1<NV>>;

template <int NV>
using xfader11_t = control::xfader<xfader11_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank3_c3_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank3_c3_1 = parameter::from0To1<xfader11_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank3_c3 = parameter::chain<ranges::Identity, 
                                        sliderbank3_c3_0<NV>, 
                                        sliderbank3_c3_1<NV>>;

template <int NV>
using event_data_reader4_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass4_t_ = container::chain<parameter::empty, 
                                         wrap::fix<1, chain44_t<NV>>>;

template <int NV>
using soft_bypass4_t = bypass::smoothed<20, soft_bypass4_t_<NV>>;
template <int NV>
using xfader10_c1 = parameter::bypass<soft_bypass4_t<NV>>;

template <int NV>
using xfader10_multimod = parameter::list<parameter::empty, xfader10_c1<NV>>;

template <int NV>
using xfader10_t = control::xfader<xfader10_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank3_c4_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank3_c4_1 = parameter::from0To1<xfader10_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank3_c4 = parameter::chain<ranges::Identity, 
                                        sliderbank3_c4_0<NV>, 
                                        sliderbank3_c4_1<NV>>;

template <int NV> using event_data_reader5_t = event_data_reader4_t<NV>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass3_t_ = container::chain<parameter::empty, 
                                         wrap::fix<1, chain43_t<NV>>>;

template <int NV>
using soft_bypass3_t = bypass::smoothed<20, soft_bypass3_t_<NV>>;
template <int NV>
using xfader9_c1 = parameter::bypass<soft_bypass3_t<NV>>;

template <int NV>
using xfader9_multimod = parameter::list<parameter::empty, xfader9_c1<NV>>;

template <int NV>
using xfader9_t = control::xfader<xfader9_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank3_c5_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank3_c5_1 = parameter::from0To1<xfader9_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank3_c5 = parameter::chain<ranges::Identity, 
                                        sliderbank3_c5_0<NV>, 
                                        sliderbank3_c5_1<NV>>;

template <int NV> using event_data_reader_t = event_data_reader4_t<NV>;

template <int NV>
using chain384_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader3_t = event_data_reader4_t<NV>;

template <int NV>
using chain395_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader3_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader2_t = event_data_reader4_t<NV>;

template <int NV>
using chain394_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader2_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader1_t = event_data_reader4_t<NV>;

template <int NV>
using chain393_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader1_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain384_t<NV>>, 
                                     chain395_t<NV>, 
                                     chain394_t<NV>, 
                                     chain393_t<NV>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch15_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass2_t_ = container::chain<parameter::empty, 
                                         wrap::fix<1, chain45_t<NV>>>;

template <int NV>
using soft_bypass2_t = bypass::smoothed<20, soft_bypass2_t_<NV>>;
template <int NV>
using xfader8_c1 = parameter::bypass<soft_bypass2_t<NV>>;

template <int NV>
using xfader8_multimod = parameter::list<parameter::empty, xfader8_c1<NV>>;

template <int NV>
using xfader8_t = control::xfader<xfader8_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank3_c6_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank3_c6_1 = parameter::from0To1<xfader8_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank3_c6 = parameter::chain<ranges::Identity, 
                                        sliderbank3_c6_0<NV>, 
                                        sliderbank3_c6_1<NV>>;

template <int NV>
using midi_cc10_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc11_t = midi_cc10_t<NV>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc11_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc12_t = midi_cc10_t<NV>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc12_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc13_t = midi_cc10_t<NV>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc13_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi6_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi6_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi7_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi7_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi8_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi8_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain13_t<NV>>, 
                                    chain18_t<NV>, 
                                    chain22_t<NV>, 
                                    chain24_t<NV>, 
                                    chain25_t<NV>, 
                                    chain26_t<NV>, 
                                    chain27_t<NV>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass1_t_ = container::chain<parameter::empty, 
                                         wrap::fix<1, chain46_t<NV>>>;

template <int NV>
using soft_bypass1_t = bypass::smoothed<20, soft_bypass1_t_<NV>>;
template <int NV>
using xfader7_c1 = parameter::bypass<soft_bypass1_t<NV>>;

template <int NV>
using xfader7_multimod = parameter::list<parameter::empty, xfader7_c1<NV>>;

template <int NV>
using xfader7_t = control::xfader<xfader7_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank3_c7_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank3_c7_1 = parameter::from0To1<xfader7_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank3_c7 = parameter::chain<ranges::Identity, 
                                        sliderbank3_c7_0<NV>, 
                                        sliderbank3_c7_1<NV>>;

template <int NV>
using sliderbank3_multimod = parameter::list<sliderbank3_c0<NV>, 
                                             sliderbank3_c1<NV>, 
                                             sliderbank3_c2<NV>, 
                                             sliderbank3_c3<NV>, 
                                             sliderbank3_c4<NV>, 
                                             sliderbank3_c5<NV>, 
                                             sliderbank3_c6<NV>, 
                                             sliderbank3_c7<NV>>;

template <int NV>
using sliderbank3_t = wrap::data<control::sliderbank<sliderbank3_multimod<NV>>, 
                                 data::external::sliderpack<0>>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader2_t<NV>>, 
                                    soft_bypass_t<NV>>;

template <int NV>
using chain113_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader13_t<NV>>, 
                                    soft_bypass7_t<NV>>;

template <int NV>
using chain112_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader12_t<NV>>, 
                                    soft_bypass6_t<NV>>;

template <int NV>
using chain111_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader11_t<NV>>, 
                                    soft_bypass5_t<NV>>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader10_t<NV>>, 
                                    soft_bypass4_t<NV>>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader9_t<NV>>, 
                                    soft_bypass3_t<NV>>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader8_t<NV>>, 
                                    soft_bypass2_t<NV>>;

template <int NV>
using chain107_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader7_t<NV>>, 
                                    soft_bypass1_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain106_t<NV>>, 
                                  chain113_t<NV>, 
                                  chain112_t<NV>, 
                                  chain111_t<NV>, 
                                  chain110_t<NV>, 
                                  chain109_t<NV>, 
                                  chain108_t<NV>, 
                                  chain107_t<NV>>;

template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<math::add<NV>, 0>>;

template <int NV> using pma8_t = pma1_t<NV>;

template <int NV> using pma11_t = pma1_t<NV>;

template <int NV>
using peak3_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma1_t<NV>, 0>, 
                                   parameter::plain<pma8_t<NV>, 0>, 
                                   parameter::plain<pma11_t<NV>, 0>>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma1_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma8_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma11_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain17_t<NV>>, 
                                    chain21_t<NV>, 
                                    chain23_t<NV>>;

template <int NV>
using converter_t = control::converter<parameter::plain<core::phasor_fm<NV>, 2>, 
                                       conversion_logic::st2pitch>;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<converter_t<NV>, 0>>;

template <int NV>
using converter5_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<core::phasor_fm<NV>, 2>, 
                                        parameter::plain<core::phasor_fm<NV>, 1>>;

template <int NV>
using converter5_t = control::converter<converter5_mod<NV>, 
                                        conversion_logic::ms2freq>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<converter5_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(peak_mod_1Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using peak_mod_1 = parameter::from0To1<tempo_sync_t<NV>, 
                                       0, 
                                       peak_mod_1Range>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<minmax2_t<NV>, 0>, 
                                  peak_mod_1<NV>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   core::smoother<NV>, 
                                   peak_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank3_t<NV>>, 
                                      split3_t<NV>, 
                                      peak3_t<NV>, 
                                      math::clear<NV>, 
                                      chain20_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

using global_cable6_t_index = global_cable3_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass17_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain63_t<NV>>>;

template <int NV>
using soft_bypass17_t = bypass::smoothed<20, soft_bypass17_t_<NV>>;
template <int NV>
using xfader23_c1 = parameter::bypass<soft_bypass17_t<NV>>;

template <int NV>
using xfader23_multimod = parameter::list<parameter::empty, xfader23_c1<NV>>;

template <int NV>
using xfader23_t = control::xfader<xfader23_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank6_c0_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank6_c0_1 = parameter::from0To1<xfader23_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank6_c0 = parameter::chain<ranges::Identity, 
                                        sliderbank6_c0_0<NV>, 
                                        sliderbank6_c0_1<NV>>;

using global_cable16_t_index = global_cable11_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass32_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain64_t<NV>>>;

template <int NV>
using soft_bypass32_t = bypass::smoothed<20, soft_bypass32_t_<NV>>;
template <int NV>
using xfader38_c1 = parameter::bypass<soft_bypass32_t<NV>>;

template <int NV>
using xfader38_multimod = parameter::list<parameter::empty, xfader38_c1<NV>>;

template <int NV>
using xfader38_t = control::xfader<xfader38_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank6_c1_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank6_c1_1 = parameter::from0To1<xfader38_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank6_c1 = parameter::chain<ranges::Identity, 
                                        sliderbank6_c1_0<NV>, 
                                        sliderbank6_c1_1<NV>>;

using global_cable17_t_index = global_cable10_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass31_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain65_t<NV>>>;

template <int NV>
using soft_bypass31_t = bypass::smoothed<20, soft_bypass31_t_<NV>>;
template <int NV>
using xfader37_c1 = parameter::bypass<soft_bypass31_t<NV>>;

template <int NV>
using xfader37_multimod = parameter::list<parameter::empty, xfader37_c1<NV>>;

template <int NV>
using xfader37_t = control::xfader<xfader37_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank6_c2_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank6_c2_1 = parameter::from0To1<xfader37_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank6_c2 = parameter::chain<ranges::Identity, 
                                        sliderbank6_c2_0<NV>, 
                                        sliderbank6_c2_1<NV>>;

using global_cable26_t_index = global_cable14_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass30_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain66_t<NV>>>;

template <int NV>
using soft_bypass30_t = bypass::smoothed<20, soft_bypass30_t_<NV>>;
template <int NV>
using xfader36_c1 = parameter::bypass<soft_bypass30_t<NV>>;

template <int NV>
using xfader36_multimod = parameter::list<parameter::empty, xfader36_c1<NV>>;

template <int NV>
using xfader36_t = control::xfader<xfader36_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank6_c3_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank6_c3_1 = parameter::from0To1<xfader36_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank6_c3 = parameter::chain<ranges::Identity, 
                                        sliderbank6_c3_0<NV>, 
                                        sliderbank6_c3_1<NV>>;

using soft_bypass29_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, core::empty>>;

using soft_bypass29_t = bypass::smoothed<20, soft_bypass29_t_>;
using xfader35_c1 = parameter::bypass<soft_bypass29_t>;

using xfader35_multimod = parameter::list<parameter::empty, xfader35_c1>;

using xfader35_t = control::xfader<xfader35_multimod, faders::switcher>;
template <int NV> using sliderbank6_c4_0 = sliderbank3_c0_0<NV>;

using sliderbank6_c4_1 = parameter::from0To1<xfader35_t, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank6_c4 = parameter::chain<ranges::Identity, 
                                        sliderbank6_c4_0<NV>, 
                                        sliderbank6_c4_1>;

template <int NV> using event_data_reader11_t = event_data_reader4_t<NV>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass28_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain68_t<NV>>>;

template <int NV>
using soft_bypass28_t = bypass::smoothed<20, soft_bypass28_t_<NV>>;
template <int NV>
using xfader34_c1 = parameter::bypass<soft_bypass28_t<NV>>;

template <int NV>
using xfader34_multimod = parameter::list<parameter::empty, xfader34_c1<NV>>;

template <int NV>
using xfader34_t = control::xfader<xfader34_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank6_c5_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank6_c5_1 = parameter::from0To1<xfader34_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank6_c5 = parameter::chain<ranges::Identity, 
                                        sliderbank6_c5_0<NV>, 
                                        sliderbank6_c5_1<NV>>;

template <int NV> using event_data_reader6_t = event_data_reader4_t<NV>;

template <int NV>
using chain385_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader6_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader7_t = event_data_reader4_t<NV>;

template <int NV>
using chain399_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader7_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader8_t = event_data_reader4_t<NV>;

template <int NV>
using chain400_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader8_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader9_t = event_data_reader4_t<NV>;

template <int NV>
using chain401_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader9_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch16_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain385_t<NV>>, 
                                     chain399_t<NV>, 
                                     chain400_t<NV>, 
                                     chain401_t<NV>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass27_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain69_t<NV>>>;

template <int NV>
using soft_bypass27_t = bypass::smoothed<20, soft_bypass27_t_<NV>>;
template <int NV>
using xfader33_c1 = parameter::bypass<soft_bypass27_t<NV>>;

template <int NV>
using xfader33_multimod = parameter::list<parameter::empty, xfader33_c1<NV>>;

template <int NV>
using xfader33_t = control::xfader<xfader33_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank6_c6_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank6_c6_1 = parameter::from0To1<xfader33_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank6_c6 = parameter::chain<ranges::Identity, 
                                        sliderbank6_c6_0<NV>, 
                                        sliderbank6_c6_1<NV>>;

template <int NV> using midi_cc14_t = midi_cc10_t<NV>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc14_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc15_t = midi_cc10_t<NV>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc15_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc16_t = midi_cc10_t<NV>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc16_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc17_t = midi_cc10_t<NV>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc17_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi9_t = midi6_t<NV>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi9_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi10_t = midi7_t<NV>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi11_t = midi8_t<NV>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi11_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain28_t<NV>>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using soft_bypass26_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain70_t<NV>>>;

template <int NV>
using soft_bypass26_t = bypass::smoothed<20, soft_bypass26_t_<NV>>;
template <int NV>
using xfader32_c1 = parameter::bypass<soft_bypass26_t<NV>>;

template <int NV>
using xfader32_multimod = parameter::list<parameter::empty, xfader32_c1<NV>>;

template <int NV>
using xfader32_t = control::xfader<xfader32_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank6_c7_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank6_c7_1 = parameter::from0To1<xfader32_t<NV>, 
                                             0, 
                                             sliderbank3_c0_1Range>;

template <int NV>
using sliderbank6_c7 = parameter::chain<ranges::Identity, 
                                        sliderbank6_c7_0<NV>, 
                                        sliderbank6_c7_1<NV>>;

template <int NV>
using sliderbank6_multimod = parameter::list<sliderbank6_c0<NV>, 
                                             sliderbank6_c1<NV>, 
                                             sliderbank6_c2<NV>, 
                                             sliderbank6_c3<NV>, 
                                             sliderbank6_c4<NV>, 
                                             sliderbank6_c5<NV>, 
                                             sliderbank6_c6<NV>, 
                                             sliderbank6_c7<NV>>;

template <int NV>
using sliderbank6_t = wrap::data<control::sliderbank<sliderbank6_multimod<NV>>, 
                                 data::external::sliderpack<1>>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader23_t<NV>>, 
                                    soft_bypass17_t<NV>>;

template <int NV>
using chain249_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader38_t<NV>>, 
                                    soft_bypass32_t<NV>>;

template <int NV>
using chain199_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader37_t<NV>>, 
                                    soft_bypass31_t<NV>>;

template <int NV>
using chain198_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader36_t<NV>>, 
                                    soft_bypass30_t<NV>>;

template <int NV> using event_data_reader10_t = event_data_reader4_t<NV>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain190_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader35_t>, 
                                    soft_bypass29_t, 
                                    chain67_t<NV>>;

template <int NV>
using chain189_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader34_t<NV>>, 
                                    soft_bypass28_t<NV>>;

template <int NV>
using chain182_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader33_t<NV>>, 
                                    soft_bypass27_t<NV>>;

template <int NV>
using chain181_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader32_t<NV>>, 
                                    soft_bypass26_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain123_t<NV>>, 
                                  chain249_t<NV>, 
                                  chain199_t<NV>, 
                                  chain198_t<NV>, 
                                  chain190_t<NV>, 
                                  chain189_t<NV>, 
                                  chain182_t<NV>, 
                                  chain181_t<NV>>;

template <int NV> using pma_mod = sliderbank3_c0_0<NV>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank6_t<NV>>, 
                                      split6_t<NV>, 
                                      peak6_t<NV>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

using global_cable39_t_index = global_cable3_t_index;

template <int NV>
using global_cable39_t = routing::global_cable<global_cable39_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain215_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable39_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass33_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain215_t<NV>>>;

template <int NV>
using soft_bypass33_t = bypass::smoothed<20, soft_bypass33_t_<NV>>;
template <int NV>
using xfader39_c1 = parameter::bypass<soft_bypass33_t<NV>>;

template <int NV>
using xfader39_multimod = parameter::list<parameter::empty, xfader39_c1<NV>>;

template <int NV>
using xfader39_t = control::xfader<xfader39_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank12_c0_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank12_c0_1 = parameter::from0To1<xfader39_t<NV>, 
                                              0, 
                                              sliderbank3_c0_1Range>;

template <int NV>
using sliderbank12_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank12_c0_0<NV>, 
                                         sliderbank12_c0_1<NV>>;

using global_cable40_t_index = global_cable11_t_index;

template <int NV>
using global_cable40_t = routing::global_cable<global_cable40_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain216_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable40_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass48_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain216_t<NV>>>;

template <int NV>
using soft_bypass48_t = bypass::smoothed<20, soft_bypass48_t_<NV>>;
template <int NV>
using xfader54_c1 = parameter::bypass<soft_bypass48_t<NV>>;

template <int NV>
using xfader54_multimod = parameter::list<parameter::empty, xfader54_c1<NV>>;

template <int NV>
using xfader54_t = control::xfader<xfader54_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank12_c1_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank12_c1_1 = parameter::from0To1<xfader54_t<NV>, 
                                              0, 
                                              sliderbank3_c0_1Range>;

template <int NV>
using sliderbank12_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank12_c1_0<NV>, 
                                         sliderbank12_c1_1<NV>>;

using global_cable41_t_index = global_cable10_t_index;

template <int NV>
using global_cable41_t = routing::global_cable<global_cable41_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain217_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable41_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass47_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain217_t<NV>>>;

template <int NV>
using soft_bypass47_t = bypass::smoothed<20, soft_bypass47_t_<NV>>;
template <int NV>
using xfader53_c1 = parameter::bypass<soft_bypass47_t<NV>>;

template <int NV>
using xfader53_multimod = parameter::list<parameter::empty, xfader53_c1<NV>>;

template <int NV>
using xfader53_t = control::xfader<xfader53_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank12_c2_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank12_c2_1 = parameter::from0To1<xfader53_t<NV>, 
                                              0, 
                                              sliderbank3_c0_1Range>;

template <int NV>
using sliderbank12_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank12_c2_0<NV>, 
                                         sliderbank12_c2_1<NV>>;

using global_cable42_t_index = global_cable14_t_index;

template <int NV>
using global_cable42_t = routing::global_cable<global_cable42_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain218_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable42_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass46_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain218_t<NV>>>;

template <int NV>
using soft_bypass46_t = bypass::smoothed<20, soft_bypass46_t_<NV>>;
template <int NV>
using xfader52_c1 = parameter::bypass<soft_bypass46_t<NV>>;

template <int NV>
using xfader52_multimod = parameter::list<parameter::empty, xfader52_c1<NV>>;

template <int NV>
using xfader52_t = control::xfader<xfader52_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank12_c3_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank12_c3_1 = parameter::from0To1<xfader52_t<NV>, 
                                              0, 
                                              sliderbank3_c0_1Range>;

template <int NV>
using sliderbank12_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank12_c3_0<NV>, 
                                         sliderbank12_c3_1<NV>>;

template <int NV> using event_data_reader16_t = event_data_reader4_t<NV>;

template <int NV>
using chain219_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader16_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass45_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain219_t<NV>>>;

template <int NV>
using soft_bypass45_t = bypass::smoothed<20, soft_bypass45_t_<NV>>;
template <int NV>
using xfader51_c1 = parameter::bypass<soft_bypass45_t<NV>>;

template <int NV>
using xfader51_multimod = parameter::list<parameter::empty, xfader51_c1<NV>>;

template <int NV>
using xfader51_t = control::xfader<xfader51_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank12_c4_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank12_c4_1 = parameter::from0To1<xfader51_t<NV>, 
                                              0, 
                                              sliderbank3_c0_1Range>;

template <int NV>
using sliderbank12_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank12_c4_0<NV>, 
                                         sliderbank12_c4_1<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader4_t<NV>;

template <int NV>
using chain220_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader17_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass44_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain220_t<NV>>>;

template <int NV>
using soft_bypass44_t = bypass::smoothed<20, soft_bypass44_t_<NV>>;
template <int NV>
using xfader50_c1 = parameter::bypass<soft_bypass44_t<NV>>;

template <int NV>
using xfader50_multimod = parameter::list<parameter::empty, xfader50_c1<NV>>;

template <int NV>
using xfader50_t = control::xfader<xfader50_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank12_c5_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank12_c5_1 = parameter::from0To1<xfader50_t<NV>, 
                                              0, 
                                              sliderbank3_c0_1Range>;

template <int NV>
using sliderbank12_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank12_c5_0<NV>, 
                                         sliderbank12_c5_1<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader4_t<NV>;

template <int NV>
using chain386_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader12_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader13_t = event_data_reader4_t<NV>;

template <int NV>
using chain402_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader13_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader4_t<NV>;

template <int NV>
using chain403_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader14_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader4_t<NV>;

template <int NV>
using chain404_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader15_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch19_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain386_t<NV>>, 
                                     chain402_t<NV>, 
                                     chain403_t<NV>, 
                                     chain404_t<NV>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch19_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain221_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain71_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass43_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain221_t<NV>>>;

template <int NV>
using soft_bypass43_t = bypass::smoothed<20, soft_bypass43_t_<NV>>;
template <int NV>
using xfader49_c1 = parameter::bypass<soft_bypass43_t<NV>>;

template <int NV>
using xfader49_multimod = parameter::list<parameter::empty, xfader49_c1<NV>>;

template <int NV>
using xfader49_t = control::xfader<xfader49_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank12_c6_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank12_c6_1 = parameter::from0To1<xfader49_t<NV>, 
                                              0, 
                                              sliderbank3_c0_1Range>;

template <int NV>
using sliderbank12_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank12_c6_0<NV>, 
                                         sliderbank12_c6_1<NV>>;

template <int NV> using midi_cc39_t = midi_cc10_t<NV>;

template <int NV>
using chain223_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc39_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc40_t = midi_cc10_t<NV>;

template <int NV>
using chain224_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc40_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc41_t = midi_cc10_t<NV>;

template <int NV>
using chain225_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc41_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc42_t = midi_cc10_t<NV>;

template <int NV>
using chain226_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc42_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi29_t = midi6_t<NV>;

template <int NV>
using chain227_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi29_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi30_t = midi7_t<NV>;

template <int NV>
using chain228_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi30_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi31_t = midi8_t<NV>;

template <int NV>
using chain229_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi31_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch50_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain223_t<NV>>, 
                                     chain224_t<NV>, 
                                     chain225_t<NV>, 
                                     chain226_t<NV>, 
                                     chain227_t<NV>, 
                                     chain228_t<NV>, 
                                     chain229_t<NV>>;

template <int NV>
using chain222_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch50_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass42_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain222_t<NV>>>;

template <int NV>
using soft_bypass42_t = bypass::smoothed<20, soft_bypass42_t_<NV>>;
template <int NV>
using xfader48_c1 = parameter::bypass<soft_bypass42_t<NV>>;

template <int NV>
using xfader48_multimod = parameter::list<parameter::empty, xfader48_c1<NV>>;

template <int NV>
using xfader48_t = control::xfader<xfader48_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank12_c7_0 = sliderbank3_c0_0<NV>;

template <int NV>
using sliderbank12_c7_1 = parameter::from0To1<xfader48_t<NV>, 
                                              0, 
                                              sliderbank3_c0_1Range>;

template <int NV>
using sliderbank12_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank12_c7_0<NV>, 
                                         sliderbank12_c7_1<NV>>;

template <int NV>
using sliderbank12_multimod = parameter::list<sliderbank12_c0<NV>, 
                                              sliderbank12_c1<NV>, 
                                              sliderbank12_c2<NV>, 
                                              sliderbank12_c3<NV>, 
                                              sliderbank12_c4<NV>, 
                                              sliderbank12_c5<NV>, 
                                              sliderbank12_c6<NV>, 
                                              sliderbank12_c7<NV>>;

template <int NV>
using sliderbank12_t = wrap::data<control::sliderbank<sliderbank12_multimod<NV>>, 
                                  data::external::sliderpack<2>>;

template <int NV>
using chain360_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader39_t<NV>>, 
                                    soft_bypass33_t<NV>>;

template <int NV>
using chain375_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader54_t<NV>>, 
                                    soft_bypass48_t<NV>>;

template <int NV>
using chain374_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader53_t<NV>>, 
                                    soft_bypass47_t<NV>>;

template <int NV>
using chain373_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader52_t<NV>>, 
                                    soft_bypass46_t<NV>>;

template <int NV>
using chain372_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader51_t<NV>>, 
                                    soft_bypass45_t<NV>>;

template <int NV>
using chain371_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader50_t<NV>>, 
                                    soft_bypass44_t<NV>>;

template <int NV>
using chain370_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader49_t<NV>>, 
                                    soft_bypass43_t<NV>>;

template <int NV>
using chain369_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader48_t<NV>>, 
                                    soft_bypass42_t<NV>>;

template <int NV>
using split26_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain360_t<NV>>, 
                                   chain375_t<NV>, 
                                   chain374_t<NV>, 
                                   chain373_t<NV>, 
                                   chain372_t<NV>, 
                                   chain371_t<NV>, 
                                   chain370_t<NV>, 
                                   chain369_t<NV>>;

namespace custom
{

struct expr6
{
	static float op(float input, float value)
	{
		return (1.0 - value) * input + value * Math.tan(Math.PI * 4.0 * value * input);
		;
	}
};
}

template <int NV> using xfader3_c0 = sliderbank3_c0_0<NV>;

template <int NV> using xfader3_c1 = sliderbank3_c0_0<NV>;

template <int NV>
using xfader3_multimod = parameter::list<xfader3_c0<NV>, xfader3_c1<NV>>;

template <int NV>
using xfader3_t = control::xfader<xfader3_multimod<NV>, faders::linear>;
DECLARE_PARAMETER_RANGE_STEP(pma6_mod_0Range, 
                             -20., 
                             24., 
                             0.1);

template <int NV>
using pma6_mod_0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma6_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma6_mod_1Range, 
                             -12., 
                             12., 
                             0.1);

template <int NV>
using pma6_mod_1 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma6_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(pma6_mod_2Range, 
                             0., 
                             12., 
                             0.1);

template <int NV>
using pma6_mod_2 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma6_mod_2Range>;

template <int NV> using pma6_mod_3 = pma6_mod_2<NV>;

DECLARE_PARAMETER_RANGE(pma6_mod_4Range, 
                        0.11, 
                        1.);

template <int NV>
using pma6_mod_4 = parameter::from0To1<math::expr<NV, custom::expr6>, 
                                       0, 
                                       pma6_mod_4Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma6_mod_5Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma6_mod_5 = parameter::from0To1<wrap::no_process<fx::phase_delay<NV>>, 
                                       0, 
                                       pma6_mod_5Range>;

template <int NV> using pma6_mod_7 = pma6_mod_1<NV>;

DECLARE_PARAMETER_RANGE_STEP(pma6_mod_8Range, 
                             0., 
                             24., 
                             0.1);

template <int NV>
using pma6_mod_8 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma6_mod_8Range>;

template <int NV>
using pma6_mod = parameter::chain<ranges::Identity, 
                                  pma6_mod_0<NV>, 
                                  pma6_mod_1<NV>, 
                                  pma6_mod_2<NV>, 
                                  pma6_mod_3<NV>, 
                                  pma6_mod_4<NV>, 
                                  pma6_mod_5<NV>, 
                                  parameter::plain<xfader3_t<NV>, 0>, 
                                  pma6_mod_7<NV>, 
                                  pma6_mod_8<NV>>;

template <int NV>
using pma6_t = control::pma<NV, pma6_mod<NV>>;
template <int NV>
using pma16_t = control::pma<NV, 
                             parameter::plain<pma6_t<NV>, 2>>;
template <int NV>
using peak19_t = wrap::mod<parameter::plain<pma16_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain12_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank12_t<NV>>, 
                                       split26_t<NV>, 
                                       peak19_t<NV>, 
                                       pma16_t<NV>>;

template <int NV>
using modchain12_t = wrap::control_rate<modchain12_t_<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  modchain4_t<NV>, 
                                  modchain12_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, minmax2_t<NV>>, 
                                  converter_t<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, tempo_sync_t<NV>>, 
                                   converter5_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain8_t<NV>>, 
                                 chain12_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::phasor_fm<NV>>>;

template <int NV> using chain2_t = chain1_t<NV>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<2, core::phasor_fm<NV>>, 
                                    wrap::no_process<math::sig2mod<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain1_t<NV>>, 
                                    chain2_t<NV>, 
                                    no_midi_t<NV>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sub<NV>>, 
                                   math::abs<NV>, 
                                   math::mul<NV>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain74_t<NV>>, 
                                   core::gain<NV>>;
namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 1.0 * value * input);;
	}
};
}

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr3>>, 
                                   core::gain<NV>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain62_t<NV>>, 
                                   chain75_t<NV>>;

template <int NV>
using chain88_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader3_t<NV>>, 
                                   split16_t<NV>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::rect<NV>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::fmod<NV>, 
                                   wrap::no_process<math::mul<NV>>, 
                                   math::pi<NV>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::expr<NV, custom::expr6>, 
                                   math::sin<NV>>;
namespace custom
{

struct expr7
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::pi<NV>>, 
                                   wrap::no_process<math::sin<NV>>, 
                                   core::gain<NV>, 
                                   math::sin<NV>, 
                                   math::expr<NV, custom::expr7>>;
namespace custom
{

struct expr8
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::pi<NV>>>, 
                                   wrap::no_process<fx::phase_delay<NV>>, 
                                   core::gain<NV>, 
                                   math::expr<NV, custom::expr8>, 
                                   math::sin<NV>>;
using table5_t = wrap::data<math::table, 
                            data::external::table<0>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::pi<NV>, 
                                   table5_t>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain88_t<NV>>, 
                                    chain76_t<NV>, 
                                    chain78_t<NV>, 
                                    chain79_t<NV>, 
                                    chain80_t<NV>, 
                                    chain81_t<NV>, 
                                    chain85_t<NV>>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<2, pma_t<NV>>, 
                                   core::gain<NV>, 
                                   modchain_t<NV>, 
                                   branch1_t<NV>, 
                                   core::mono2stereo, 
                                   pma6_t<NV>, 
                                   branch2_t<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain77_t<NV>>, 
                                   wrap::no_process<math::clear<NV>>, 
                                   filters::one_pole<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain19_t<NV>>>;

template <int NV>
using xfade_2x_lin_t = container::chain<parameter::empty, 
                                        wrap::fix<2, split20_t<NV>>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfade_2x_lin_t<NV>>>;

namespace osc1_t_parameters
{
// Parameter list for osc1_impl::osc1_t ------------------------------------------------------------

DECLARE_PARAMETER_RANGE(Pitch_InputRange, 
                        -24., 
                        24.);

template <int NV>
using Pitch = parameter::chain<Pitch_InputRange, 
                               parameter::plain<osc1_impl::pma1_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(tempo_InputRange, 
                        0., 
                        18.);

template <int NV>
using tempo = parameter::chain<tempo_InputRange, 
                               parameter::plain<osc1_impl::pma8_t<NV>, 2>, 
                               parameter::plain<osc1_impl::pma11_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(pitchmode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(pitchmode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using pitchmode_0 = parameter::from0To1<osc1_impl::branch1_t<NV>, 
                                        0, 
                                        pitchmode_0Range>;

template <int NV>
using pitchmode_1 = parameter::from0To1<osc1_impl::branch3_t<NV>, 
                                        0, 
                                        pitchmode_0Range>;

template <int NV>
using pitchmode = parameter::chain<pitchmode_InputRange, 
                                   pitchmode_0<NV>, 
                                   pitchmode_1<NV>>;

template <int NV>
using PitchMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<osc1_impl::pma1_t<NV>, 1>, 
                                  parameter::plain<osc1_impl::pma8_t<NV>, 1>, 
                                  parameter::plain<osc1_impl::pma11_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(MidiSlotPitch_InputRange, 
                        1., 
                        7.);
DECLARE_PARAMETER_RANGE_STEP(MidiSlotPitch_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using MidiSlotPitch_0 = parameter::from0To1<osc1_impl::branch5_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using MidiSlotPitch = parameter::chain<MidiSlotPitch_InputRange, 
                                       MidiSlotPitch_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Shape_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using Shape_0 = parameter::from0To1<osc1_impl::branch2_t<NV>, 
                                    0, 
                                    MidiSlotPitch_0Range>;

template <int NV>
using Shape = parameter::chain<Shape_InputRange, Shape_0<NV>>;

DECLARE_PARAMETER_RANGE(MidiWidth_InputRange, 
                        1., 
                        7.);
template <int NV>
using MidiWidth_0 = parameter::from0To1<osc1_impl::branch50_t<NV>, 
                                        0, 
                                        MidiSlotPitch_0Range>;

template <int NV>
using MidiWidth = parameter::chain<MidiWidth_InputRange, MidiWidth_0<NV>>;

DECLARE_PARAMETER_RANGE(PitchPkModSrc1_InputRange, 
                        1., 
                        4.);
DECLARE_PARAMETER_RANGE_STEP(PitchPkModSrc1_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using PitchPkModSrc1_0 = parameter::from0To1<osc1_impl::branch15_t<NV>, 
                                             0, 
                                             PitchPkModSrc1_0Range>;

template <int NV>
using PitchPkModSrc1 = parameter::chain<PitchPkModSrc1_InputRange, 
                                        PitchPkModSrc1_0<NV>>;

DECLARE_PARAMETER_RANGE(OscInPeak_InputRange, 
                        1., 
                        4.);
template <int NV>
using OscInPeak_0 = parameter::from0To1<osc1_impl::branch16_t<NV>, 
                                        0, 
                                        PitchPkModSrc1_0Range>;

template <int NV>
using OscInPeak = parameter::chain<OscInPeak_InputRange, OscInPeak_0<NV>>;

DECLARE_PARAMETER_RANGE(OscWidthPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using OscWidthPk_0 = parameter::from0To1<osc1_impl::branch19_t<NV>, 
                                         0, 
                                         PitchPkModSrc1_0Range>;

template <int NV>
using OscWidthPk = parameter::chain<OscWidthPk_InputRange, OscWidthPk_0<NV>>;

template <int NV>
using div = parameter::plain<osc1_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using step = parameter::plain<osc1_impl::minmax2_t<NV>, 
                              4>;
template <int NV>
using Input1 = parameter::plain<osc1_impl::pma_t<NV>, 2>;
template <int NV>
using InMod1 = parameter::plain<osc1_impl::pma_t<NV>, 1>;
template <int NV>
using Bend = parameter::plain<core::smoother<NV>, 0>;
template <int NV>
using WidhMod = parameter::plain<osc1_impl::pma16_t<NV>, 1>;
template <int NV>
using Width = parameter::plain<osc1_impl::pma16_t<NV>, 2>;
using InSrcOsc1 = parameter::empty;
using ModOutputDest = InSrcOsc1;
template <int NV>
using osc1_t_plist = parameter::list<Pitch<NV>, 
                                     tempo<NV>, 
                                     div<NV>, 
                                     pitchmode<NV>, 
                                     step<NV>, 
                                     PitchMod<NV>, 
                                     Input1<NV>, 
                                     InMod1<NV>, 
                                     MidiSlotPitch<NV>, 
                                     Bend<NV>, 
                                     Shape<NV>, 
                                     WidhMod<NV>, 
                                     Width<NV>, 
                                     MidiWidth<NV>, 
                                     PitchPkModSrc1<NV>, 
                                     InSrcOsc1, 
                                     OscInPeak<NV>, 
                                     OscWidthPk<NV>, 
                                     ModOutputDest>;
}

template <int NV>
using osc1_t_ = container::chain<osc1_t_parameters::osc1_t_plist<NV>, 
                                 wrap::fix<2, split2_t<NV>>, 
                                 chain59_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public osc1_impl::osc1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(osc1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(320)
		{
			0x005B, 0x0000, 0x5000, 0x7469, 0x6863, 0x0000, 0xC000, 0x00C1, 
            0xC000, 0xDF41, 0x82F4, 0x00BF, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6574, 0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 
            0x4190, 0xC859, 0x412B, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x6400, 0x7669, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 
            0x2000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 0x0000, 
            0x6970, 0x6374, 0x6D68, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x4040, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 
            0x0000, 0x7300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 
            0x5000, 0x7469, 0x6863, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0B21, 0x3C99, 0x0000, 0x3F80, 0x0000, 0x0000, 0x065B, 
            0x0000, 0x4900, 0x706E, 0x7475, 0x0031, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0B21, 0x3F27, 0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 
            0x0000, 0x4900, 0x4D6E, 0x646F, 0x0031, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0xA6F5, 0x3E83, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 
            0x0000, 0x4D00, 0x6469, 0x5369, 0x6F6C, 0x5074, 0x7469, 0x6863, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0009, 0x0000, 0x6542, 0x646E, 0x0000, 
            0x0000, 0x0000, 0x9C40, 0x0046, 0xA000, 0x6941, 0x6CEE, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x000A, 0x0000, 0x6853, 0x7061, 0x0065, 0x0000, 
            0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0B5B, 0x0000, 0x5700, 0x6469, 0x4D68, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000C, 0x0000, 0x6957, 0x7464, 0x0068, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0D5B, 0x0000, 0x4D00, 0x6469, 0x5769, 0x6469, 0x6874, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000E, 0x0000, 0x6950, 0x6374, 0x5068, 
            0x4D6B, 0x646F, 0x7253, 0x3163, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000F, 
            0x0000, 0x6E49, 0x7253, 0x4F63, 0x6373, 0x0031, 0x0000, 0x3F80, 
            0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x105B, 0x0000, 0x4F00, 0x6373, 0x6E49, 0x6550, 0x6B61, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0011, 0x0000, 0x734F, 0x5763, 0x6469, 0x6874, 
            0x6B50, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x4000, 0x0040, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0012, 0x0000, 0x6F4D, 0x4F64, 
            0x7475, 0x7570, 0x4474, 0x7365, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split2 = this->getT(0);                                                              // osc1_impl::split2_t<NV>
		auto& modchain1 = this->getT(0).getT(0);                                                   // osc1_impl::modchain1_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0);                                         // osc1_impl::sliderbank3_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1);                                              // osc1_impl::split3_t<NV>
		auto& chain106 = this->getT(0).getT(0).getT(1).getT(0);                                    // osc1_impl::chain106_t<NV>
		auto& xfader2 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                             // osc1_impl::xfader2_t<NV>
		auto& soft_bypass = this->getT(0).getT(0).getT(1).getT(0).getT(1);                         // osc1_impl::soft_bypass_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);                     // osc1_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);       // osc1_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);                // math::add<NV>
		auto& gain13 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain113 = this->getT(0).getT(0).getT(1).getT(1);                                    // osc1_impl::chain113_t<NV>
		auto& xfader13 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                            // osc1_impl::xfader13_t<NV>
		auto& soft_bypass7 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                        // osc1_impl::soft_bypass7_t<NV>
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);                     // osc1_impl::chain41_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(0);      // osc1_impl::global_cable11_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain15 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain112 = this->getT(0).getT(0).getT(1).getT(2);                                    // osc1_impl::chain112_t<NV>
		auto& xfader12 = this->getT(0).getT(0).getT(1).getT(2).getT(0);                            // osc1_impl::xfader12_t<NV>
		auto& soft_bypass6 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                        // osc1_impl::soft_bypass6_t<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0);                     // osc1_impl::chain40_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(0);      // osc1_impl::global_cable10_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(1);                // math::add<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain111 = this->getT(0).getT(0).getT(1).getT(3);                                    // osc1_impl::chain111_t<NV>
		auto& xfader11 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                            // osc1_impl::xfader11_t<NV>
		auto& soft_bypass5 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                        // osc1_impl::soft_bypass5_t<NV>
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0);                     // osc1_impl::chain42_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(0);      // osc1_impl::global_cable14_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain110 = this->getT(0).getT(0).getT(1).getT(4);                                    // osc1_impl::chain110_t<NV>
		auto& xfader10 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                            // osc1_impl::xfader10_t<NV>
		auto& soft_bypass4 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                        // osc1_impl::soft_bypass4_t<NV>
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0);                     // osc1_impl::chain44_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(0);  // osc1_impl::event_data_reader4_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain32 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain109 = this->getT(0).getT(0).getT(1).getT(5);                                    // osc1_impl::chain109_t<NV>
		auto& xfader9 = this->getT(0).getT(0).getT(1).getT(5).getT(0);                             // osc1_impl::xfader9_t<NV>
		auto& soft_bypass3 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                        // osc1_impl::soft_bypass3_t<NV>
		auto& chain43 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0);                     // osc1_impl::chain43_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(0);  // osc1_impl::event_data_reader5_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain26 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain108 = this->getT(0).getT(0).getT(1).getT(6);                                    // osc1_impl::chain108_t<NV>
		auto& xfader8 = this->getT(0).getT(0).getT(1).getT(6).getT(0);                             // osc1_impl::xfader8_t<NV>
		auto& soft_bypass2 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                        // osc1_impl::soft_bypass2_t<NV>
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0);                     // osc1_impl::chain45_t<NV>
		auto& branch15 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).getT(0);            // osc1_impl::branch15_t<NV>
		auto& chain384 = this->getT(0).getT(0).getT(1).getT(6).                                    // osc1_impl::chain384_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& event_data_reader = this->getT(0).getT(0).getT(1).getT(6).                           // osc1_impl::event_data_reader_t<NV>
                                  getT(1).getT(0).getT(0).getT(0).
                                  getT(0);
		auto& add3 = this->getT(0).getT(0).getT(1).getT(6).                                        // math::add<NV>
                     getT(1).getT(0).getT(0).getT(0).
                     getT(1);
		auto& chain395 = this->getT(0).getT(0).getT(1).getT(6).                                    // osc1_impl::chain395_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& event_data_reader3 = this->getT(0).getT(0).getT(1).getT(6).                          // osc1_impl::event_data_reader3_t<NV>
                                   getT(1).getT(0).getT(0).getT(1).
                                   getT(0);
		auto& add16 = this->getT(0).getT(0).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1).
                      getT(1);
		auto& chain394 = this->getT(0).getT(0).getT(1).getT(6).                                    // osc1_impl::chain394_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& event_data_reader2 = this->getT(0).getT(0).getT(1).getT(6).                          // osc1_impl::event_data_reader2_t<NV>
                                   getT(1).getT(0).getT(0).getT(2).
                                   getT(0);
		auto& add15 = this->getT(0).getT(0).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain393 = this->getT(0).getT(0).getT(1).getT(6).                                    // osc1_impl::chain393_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& event_data_reader1 = this->getT(0).getT(0).getT(1).getT(6).                          // osc1_impl::event_data_reader1_t<NV>
                                   getT(1).getT(0).getT(0).getT(3).
                                   getT(0);
		auto& add14 = this->getT(0).getT(0).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(3).
                      getT(1);
		auto& gain33 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).getT(1);              // core::gain<NV>
		auto& chain107 = this->getT(0).getT(0).getT(1).getT(7);                                    // osc1_impl::chain107_t<NV>
		auto& xfader7 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                             // osc1_impl::xfader7_t<NV>
		auto& soft_bypass1 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                        // osc1_impl::soft_bypass1_t<NV>
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0);                     // osc1_impl::chain46_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).getT(0);             // osc1_impl::branch5_t<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(7).                                     // osc1_impl::chain13_t<NV>
                        getT(1).getT(0).getT(0).getT(0);
		auto& midi_cc10 = this->getT(0).getT(0).getT(1).getT(7).                                   // osc1_impl::midi_cc10_t<NV>
                          getT(1).getT(0).getT(0).getT(0).
                          getT(0);
		auto& add50 = this->getT(0).getT(0).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(0).
                      getT(1);
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(7).                                     // osc1_impl::chain18_t<NV>
                        getT(1).getT(0).getT(0).getT(1);
		auto& midi_cc11 = this->getT(0).getT(0).getT(1).getT(7).                                   // osc1_impl::midi_cc11_t<NV>
                          getT(1).getT(0).getT(0).getT(1).
                          getT(0);
		auto& add51 = this->getT(0).getT(0).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1).
                      getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(7).                                     // osc1_impl::chain22_t<NV>
                        getT(1).getT(0).getT(0).getT(2);
		auto& midi_cc12 = this->getT(0).getT(0).getT(1).getT(7).                                   // osc1_impl::midi_cc12_t<NV>
                          getT(1).getT(0).getT(0).getT(2).
                          getT(0);
		auto& add52 = this->getT(0).getT(0).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(7).                                     // osc1_impl::chain24_t<NV>
                        getT(1).getT(0).getT(0).getT(3);
		auto& midi_cc13 = this->getT(0).getT(0).getT(1).getT(7).                                   // osc1_impl::midi_cc13_t<NV>
                          getT(1).getT(0).getT(0).getT(3).
                          getT(0);
		auto& add53 = this->getT(0).getT(0).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(7).                                     // osc1_impl::chain25_t<NV>
                        getT(1).getT(0).getT(0).getT(4);
		auto& midi6 = this->getT(0).getT(0).getT(1).getT(7).                                       // osc1_impl::midi6_t<NV>
                      getT(1).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add54 = this->getT(0).getT(0).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(4).
                      getT(1);
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(7).                                     // osc1_impl::chain26_t<NV>
                        getT(1).getT(0).getT(0).getT(5);
		auto& midi7 = this->getT(0).getT(0).getT(1).getT(7).                                       // osc1_impl::midi7_t<NV>
                      getT(1).getT(0).getT(0).getT(5).
                      getT(0);
		auto& add55 = this->getT(0).getT(0).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(5).
                      getT(1);
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(7).                                     // osc1_impl::chain27_t<NV>
                        getT(1).getT(0).getT(0).getT(6);
		auto& midi8 = this->getT(0).getT(0).getT(1).getT(7).                                       // osc1_impl::midi8_t<NV>
                      getT(1).getT(0).getT(0).getT(6).
                      getT(0);
		auto& add56 = this->getT(0).getT(0).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(6).
                      getT(1);
		auto& gain34 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).getT(1);              // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2);                                               // osc1_impl::peak3_t<NV>
		auto& clear = this->getT(0).getT(0).getT(3);                                               // math::clear<NV>
		auto& chain20 = this->getT(0).getT(0).getT(4);                                             // osc1_impl::chain20_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(4).getT(0);                                     // osc1_impl::branch3_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(4).getT(0).getT(0);                             // osc1_impl::chain17_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0);                        // osc1_impl::pma1_t<NV>
		auto& add = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1);                         // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                             // osc1_impl::chain21_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0);                        // osc1_impl::pma8_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1);                       // math::add<NV>
		auto& chain23 = this->getT(0).getT(0).getT(4).getT(0).getT(2);                             // osc1_impl::chain23_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(0);                       // osc1_impl::pma11_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(1);                       // math::add<NV>
		auto& smoother = this->getT(0).getT(0).getT(4).getT(1);                                    // core::smoother<NV>
		auto& peak = this->getT(0).getT(0).getT(4).getT(2);                                        // osc1_impl::peak_t<NV>
		auto& modchain4 = this->getT(0).getT(1);                                                   // osc1_impl::modchain4_t<NV>
		auto& sliderbank6 = this->getT(0).getT(1).getT(0);                                         // osc1_impl::sliderbank6_t<NV>
		auto& split6 = this->getT(0).getT(1).getT(1);                                              // osc1_impl::split6_t<NV>
		auto& chain123 = this->getT(0).getT(1).getT(1).getT(0);                                    // osc1_impl::chain123_t<NV>
		auto& xfader23 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                            // osc1_impl::xfader23_t<NV>
		auto& soft_bypass17 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                       // osc1_impl::soft_bypass17_t<NV>
		auto& chain63 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0);                     // osc1_impl::chain63_t<NV>
		auto& global_cable6 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(0);       // osc1_impl::global_cable6_t<NV>
		auto& add10 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain25 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain249 = this->getT(0).getT(1).getT(1).getT(1);                                    // osc1_impl::chain249_t<NV>
		auto& xfader38 = this->getT(0).getT(1).getT(1).getT(1).getT(0);                            // osc1_impl::xfader38_t<NV>
		auto& soft_bypass32 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                       // osc1_impl::soft_bypass32_t<NV>
		auto& chain64 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0);                     // osc1_impl::chain64_t<NV>
		auto& global_cable16 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).getT(0);      // osc1_impl::global_cable16_t<NV>
		auto& add44 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain29 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain199 = this->getT(0).getT(1).getT(1).getT(2);                                    // osc1_impl::chain199_t<NV>
		auto& xfader37 = this->getT(0).getT(1).getT(1).getT(2).getT(0);                            // osc1_impl::xfader37_t<NV>
		auto& soft_bypass31 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                       // osc1_impl::soft_bypass31_t<NV>
		auto& chain65 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0);                     // osc1_impl::chain65_t<NV>
		auto& global_cable17 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(0);      // osc1_impl::global_cable17_t<NV>
		auto& add11 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain30 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain198 = this->getT(0).getT(1).getT(1).getT(3);                                    // osc1_impl::chain198_t<NV>
		auto& xfader36 = this->getT(0).getT(1).getT(1).getT(3).getT(0);                            // osc1_impl::xfader36_t<NV>
		auto& soft_bypass30 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                       // osc1_impl::soft_bypass30_t<NV>
		auto& chain66 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0);                     // osc1_impl::chain66_t<NV>
		auto& global_cable26 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).getT(0);      // osc1_impl::global_cable26_t<NV>
		auto& add45 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain31 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain190 = this->getT(0).getT(1).getT(1).getT(4);                                    // osc1_impl::chain190_t<NV>
		auto& xfader35 = this->getT(0).getT(1).getT(1).getT(4).getT(0);                            // osc1_impl::xfader35_t
		auto& soft_bypass29 = this->getT(0).getT(1).getT(1).getT(4).getT(1);                       // osc1_impl::soft_bypass29_t
		auto& chain67 = this->getT(0).getT(1).getT(1).getT(4).getT(2);                             // osc1_impl::chain67_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(1).getT(1).getT(4).getT(2).getT(0);         // osc1_impl::event_data_reader10_t<NV>
		auto& add46 = this->getT(0).getT(1).getT(1).getT(4).getT(2).getT(1);                       // math::add<NV>
		auto& gain41 = this->getT(0).getT(1).getT(1).getT(4).getT(2).getT(2);                      // core::gain<NV>
		auto& chain189 = this->getT(0).getT(1).getT(1).getT(5);                                    // osc1_impl::chain189_t<NV>
		auto& xfader34 = this->getT(0).getT(1).getT(1).getT(5).getT(0);                            // osc1_impl::xfader34_t<NV>
		auto& soft_bypass28 = this->getT(0).getT(1).getT(1).getT(5).getT(1);                       // osc1_impl::soft_bypass28_t<NV>
		auto& chain68 = this->getT(0).getT(1).getT(1).getT(5).getT(1).getT(0);                     // osc1_impl::chain68_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(1).getT(1).getT(5).getT(1).getT(0).getT(0); // osc1_impl::event_data_reader11_t<NV>
		auto& add47 = this->getT(0).getT(1).getT(1).getT(5).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain42 = this->getT(0).getT(1).getT(1).getT(5).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain182 = this->getT(0).getT(1).getT(1).getT(6);                                    // osc1_impl::chain182_t<NV>
		auto& xfader33 = this->getT(0).getT(1).getT(1).getT(6).getT(0);                            // osc1_impl::xfader33_t<NV>
		auto& soft_bypass27 = this->getT(0).getT(1).getT(1).getT(6).getT(1);                       // osc1_impl::soft_bypass27_t<NV>
		auto& chain69 = this->getT(0).getT(1).getT(1).getT(6).getT(1).getT(0);                     // osc1_impl::chain69_t<NV>
		auto& branch16 = this->getT(0).getT(1).getT(1).getT(6).getT(1).getT(0).getT(0);            // osc1_impl::branch16_t<NV>
		auto& chain385 = this->getT(0).getT(1).getT(1).getT(6).                                    // osc1_impl::chain385_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& event_data_reader6 = this->getT(0).getT(1).getT(1).getT(6).                          // osc1_impl::event_data_reader6_t<NV>
                                   getT(1).getT(0).getT(0).getT(0).
                                   getT(0);
		auto& add6 = this->getT(0).getT(1).getT(1).getT(6).                                        // math::add<NV>
                     getT(1).getT(0).getT(0).getT(0).
                     getT(1);
		auto& chain399 = this->getT(0).getT(1).getT(1).getT(6).                                    // osc1_impl::chain399_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& event_data_reader7 = this->getT(0).getT(1).getT(1).getT(6).                          // osc1_impl::event_data_reader7_t<NV>
                                   getT(1).getT(0).getT(0).getT(1).
                                   getT(0);
		auto& add17 = this->getT(0).getT(1).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1).
                      getT(1);
		auto& chain400 = this->getT(0).getT(1).getT(1).getT(6).                                    // osc1_impl::chain400_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& event_data_reader8 = this->getT(0).getT(1).getT(1).getT(6).                          // osc1_impl::event_data_reader8_t<NV>
                                   getT(1).getT(0).getT(0).getT(2).
                                   getT(0);
		auto& add18 = this->getT(0).getT(1).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain401 = this->getT(0).getT(1).getT(1).getT(6).                                    // osc1_impl::chain401_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& event_data_reader9 = this->getT(0).getT(1).getT(1).getT(6).                          // osc1_impl::event_data_reader9_t<NV>
                                   getT(1).getT(0).getT(0).getT(3).
                                   getT(0);
		auto& add21 = this->getT(0).getT(1).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(3).
                      getT(1);
		auto& add48 = this->getT(0).getT(1).getT(1).getT(6).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain43 = this->getT(0).getT(1).getT(1).getT(6).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain181 = this->getT(0).getT(1).getT(1).getT(7);                                    // osc1_impl::chain181_t<NV>
		auto& xfader32 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                            // osc1_impl::xfader32_t<NV>
		auto& soft_bypass26 = this->getT(0).getT(1).getT(1).getT(7).getT(1);                       // osc1_impl::soft_bypass26_t<NV>
		auto& chain70 = this->getT(0).getT(1).getT(1).getT(7).getT(1).getT(0);                     // osc1_impl::chain70_t<NV>
		auto& branch6 = this->getT(0).getT(1).getT(1).getT(7).getT(1).getT(0).getT(0);             // osc1_impl::branch6_t<NV>
		auto& chain28 = this->getT(0).getT(1).getT(1).getT(7).                                     // osc1_impl::chain28_t<NV>
                        getT(1).getT(0).getT(0).getT(0);
		auto& midi_cc14 = this->getT(0).getT(1).getT(1).getT(7).                                   // osc1_impl::midi_cc14_t<NV>
                          getT(1).getT(0).getT(0).getT(0).
                          getT(0);
		auto& add57 = this->getT(0).getT(1).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(0).
                      getT(1);
		auto& chain29 = this->getT(0).getT(1).getT(1).getT(7).                                     // osc1_impl::chain29_t<NV>
                        getT(1).getT(0).getT(0).getT(1);
		auto& midi_cc15 = this->getT(0).getT(1).getT(1).getT(7).                                   // osc1_impl::midi_cc15_t<NV>
                          getT(1).getT(0).getT(0).getT(1).
                          getT(0);
		auto& add58 = this->getT(0).getT(1).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1).
                      getT(1);
		auto& chain30 = this->getT(0).getT(1).getT(1).getT(7).                                     // osc1_impl::chain30_t<NV>
                        getT(1).getT(0).getT(0).getT(2);
		auto& midi_cc16 = this->getT(0).getT(1).getT(1).getT(7).                                   // osc1_impl::midi_cc16_t<NV>
                          getT(1).getT(0).getT(0).getT(2).
                          getT(0);
		auto& add59 = this->getT(0).getT(1).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain31 = this->getT(0).getT(1).getT(1).getT(7).                                     // osc1_impl::chain31_t<NV>
                        getT(1).getT(0).getT(0).getT(3);
		auto& midi_cc17 = this->getT(0).getT(1).getT(1).getT(7).                                   // osc1_impl::midi_cc17_t<NV>
                          getT(1).getT(0).getT(0).getT(3).
                          getT(0);
		auto& add60 = this->getT(0).getT(1).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(3).
                      getT(1);
		auto& chain32 = this->getT(0).getT(1).getT(1).getT(7).                                     // osc1_impl::chain32_t<NV>
                        getT(1).getT(0).getT(0).getT(4);
		auto& midi9 = this->getT(0).getT(1).getT(1).getT(7).                                       // osc1_impl::midi9_t<NV>
                      getT(1).getT(0).getT(0).getT(4).
                      getT(0);
		auto& add61 = this->getT(0).getT(1).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(4).
                      getT(1);
		auto& chain33 = this->getT(0).getT(1).getT(1).getT(7).                                     // osc1_impl::chain33_t<NV>
                        getT(1).getT(0).getT(0).getT(5);
		auto& midi10 = this->getT(0).getT(1).getT(1).getT(7).                                      // osc1_impl::midi10_t<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(0);
		auto& add62 = this->getT(0).getT(1).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(5).
                      getT(1);
		auto& chain34 = this->getT(0).getT(1).getT(1).getT(7).                                     // osc1_impl::chain34_t<NV>
                        getT(1).getT(0).getT(0).getT(6);
		auto& midi11 = this->getT(0).getT(1).getT(1).getT(7).                                      // osc1_impl::midi11_t<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(0);
		auto& add63 = this->getT(0).getT(1).getT(1).getT(7).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(6).
                      getT(1);
		auto& gain44 = this->getT(0).getT(1).getT(1).getT(7).getT(1).getT(0).getT(1);              // core::gain<NV>
		auto& peak6 = this->getT(0).getT(1).getT(2);                                               // osc1_impl::peak6_t<NV>
		auto& modchain12 = this->getT(0).getT(2);                                                  // osc1_impl::modchain12_t<NV>
		auto& sliderbank12 = this->getT(0).getT(2).getT(0);                                        // osc1_impl::sliderbank12_t<NV>
		auto& split26 = this->getT(0).getT(2).getT(1);                                             // osc1_impl::split26_t<NV>
		auto& chain360 = this->getT(0).getT(2).getT(1).getT(0);                                    // osc1_impl::chain360_t<NV>
		auto& xfader39 = this->getT(0).getT(2).getT(1).getT(0).getT(0);                            // osc1_impl::xfader39_t<NV>
		auto& soft_bypass33 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                       // osc1_impl::soft_bypass33_t<NV>
		auto& chain215 = this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0);                    // osc1_impl::chain215_t<NV>
		auto& global_cable39 = this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).getT(0);      // osc1_impl::global_cable39_t<NV>
		auto& add161 = this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain116 = this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain375 = this->getT(0).getT(2).getT(1).getT(1);                                    // osc1_impl::chain375_t<NV>
		auto& xfader54 = this->getT(0).getT(2).getT(1).getT(1).getT(0);                            // osc1_impl::xfader54_t<NV>
		auto& soft_bypass48 = this->getT(0).getT(2).getT(1).getT(1).getT(1);                       // osc1_impl::soft_bypass48_t<NV>
		auto& chain216 = this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0);                    // osc1_impl::chain216_t<NV>
		auto& global_cable40 = this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0).getT(0);      // osc1_impl::global_cable40_t<NV>
		auto& add162 = this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain117 = this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain374 = this->getT(0).getT(2).getT(1).getT(2);                                    // osc1_impl::chain374_t<NV>
		auto& xfader53 = this->getT(0).getT(2).getT(1).getT(2).getT(0);                            // osc1_impl::xfader53_t<NV>
		auto& soft_bypass47 = this->getT(0).getT(2).getT(1).getT(2).getT(1);                       // osc1_impl::soft_bypass47_t<NV>
		auto& chain217 = this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0);                    // osc1_impl::chain217_t<NV>
		auto& global_cable41 = this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0).getT(0);      // osc1_impl::global_cable41_t<NV>
		auto& add163 = this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain118 = this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain373 = this->getT(0).getT(2).getT(1).getT(3);                                    // osc1_impl::chain373_t<NV>
		auto& xfader52 = this->getT(0).getT(2).getT(1).getT(3).getT(0);                            // osc1_impl::xfader52_t<NV>
		auto& soft_bypass46 = this->getT(0).getT(2).getT(1).getT(3).getT(1);                       // osc1_impl::soft_bypass46_t<NV>
		auto& chain218 = this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(0);                    // osc1_impl::chain218_t<NV>
		auto& global_cable42 = this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(0).getT(0);      // osc1_impl::global_cable42_t<NV>
		auto& add164 = this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain119 = this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain372 = this->getT(0).getT(2).getT(1).getT(4);                                    // osc1_impl::chain372_t<NV>
		auto& xfader51 = this->getT(0).getT(2).getT(1).getT(4).getT(0);                            // osc1_impl::xfader51_t<NV>
		auto& soft_bypass45 = this->getT(0).getT(2).getT(1).getT(4).getT(1);                       // osc1_impl::soft_bypass45_t<NV>
		auto& chain219 = this->getT(0).getT(2).getT(1).getT(4).getT(1).getT(0);                    // osc1_impl::chain219_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(2).getT(1).getT(4).getT(1).getT(0).getT(0); // osc1_impl::event_data_reader16_t<NV>
		auto& add165 = this->getT(0).getT(2).getT(1).getT(4).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain120 = this->getT(0).getT(2).getT(1).getT(4).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain371 = this->getT(0).getT(2).getT(1).getT(5);                                    // osc1_impl::chain371_t<NV>
		auto& xfader50 = this->getT(0).getT(2).getT(1).getT(5).getT(0);                            // osc1_impl::xfader50_t<NV>
		auto& soft_bypass44 = this->getT(0).getT(2).getT(1).getT(5).getT(1);                       // osc1_impl::soft_bypass44_t<NV>
		auto& chain220 = this->getT(0).getT(2).getT(1).getT(5).getT(1).getT(0);                    // osc1_impl::chain220_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(2).getT(1).getT(5).getT(1).getT(0).getT(0); // osc1_impl::event_data_reader17_t<NV>
		auto& add166 = this->getT(0).getT(2).getT(1).getT(5).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain121 = this->getT(0).getT(2).getT(1).getT(5).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain370 = this->getT(0).getT(2).getT(1).getT(6);                                    // osc1_impl::chain370_t<NV>
		auto& xfader49 = this->getT(0).getT(2).getT(1).getT(6).getT(0);                            // osc1_impl::xfader49_t<NV>
		auto& soft_bypass43 = this->getT(0).getT(2).getT(1).getT(6).getT(1);                       // osc1_impl::soft_bypass43_t<NV>
		auto& chain221 = this->getT(0).getT(2).getT(1).getT(6).getT(1).getT(0);                    // osc1_impl::chain221_t<NV>
		auto& chain71 = this->getT(0).getT(2).getT(1).getT(6).getT(1).getT(0).getT(0);             // osc1_impl::chain71_t<NV>
		auto& branch19 = this->getT(0).getT(2).getT(1).getT(6).                                    // osc1_impl::branch19_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& chain386 = this->getT(0).getT(2).getT(1).getT(6).                         // osc1_impl::chain386_t<NV>
                         getT(1).getT(0).getT(0).getT(0).
                         getT(0);
		auto& event_data_reader12 = this->getT(0).getT(2).getT(1).getT(6).getT(1).      // osc1_impl::event_data_reader12_t<NV>
                                    getT(0).getT(0).getT(0).getT(0).getT(0);
		auto& add7 = this->getT(0).getT(2).getT(1).getT(6).getT(1).                     // math::add<NV>
                     getT(0).getT(0).getT(0).getT(0).getT(1);
		auto& chain402 = this->getT(0).getT(2).getT(1).getT(6).                         // osc1_impl::chain402_t<NV>
                         getT(1).getT(0).getT(0).getT(0).
                         getT(1);
		auto& event_data_reader13 = this->getT(0).getT(2).getT(1).getT(6).getT(1).      // osc1_impl::event_data_reader13_t<NV>
                                    getT(0).getT(0).getT(0).getT(1).getT(0);
		auto& add23 = this->getT(0).getT(2).getT(1).getT(6).getT(1).                    // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1).getT(1);
		auto& chain403 = this->getT(0).getT(2).getT(1).getT(6).                         // osc1_impl::chain403_t<NV>
                         getT(1).getT(0).getT(0).getT(0).
                         getT(2);
		auto& event_data_reader14 = this->getT(0).getT(2).getT(1).getT(6).getT(1).      // osc1_impl::event_data_reader14_t<NV>
                                    getT(0).getT(0).getT(0).getT(2).getT(0);
		auto& add24 = this->getT(0).getT(2).getT(1).getT(6).getT(1).                    // math::add<NV>
                      getT(0).getT(0).getT(0).getT(2).getT(1);
		auto& chain404 = this->getT(0).getT(2).getT(1).getT(6).                         // osc1_impl::chain404_t<NV>
                         getT(1).getT(0).getT(0).getT(0).
                         getT(3);
		auto& event_data_reader15 = this->getT(0).getT(2).getT(1).getT(6).getT(1).      // osc1_impl::event_data_reader15_t<NV>
                                    getT(0).getT(0).getT(0).getT(3).getT(0);
		auto& add25 = this->getT(0).getT(2).getT(1).getT(6).getT(1).                    // math::add<NV>
                      getT(0).getT(0).getT(0).getT(3).getT(1);
		auto& add49 = this->getT(0).getT(2).getT(1).getT(6).                            // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1);
		auto& gain45 = this->getT(0).getT(2).getT(1).getT(6).                           // core::gain<NV>
                       getT(1).getT(0).getT(0).getT(2);
		auto& add171 = this->getT(0).getT(2).getT(1).getT(6).getT(1).getT(0).getT(1);   // math::add<NV>
		auto& gain122 = this->getT(0).getT(2).getT(1).getT(6).getT(1).getT(0).getT(2);  // core::gain<NV>
		auto& chain369 = this->getT(0).getT(2).getT(1).getT(7);                         // osc1_impl::chain369_t<NV>
		auto& xfader48 = this->getT(0).getT(2).getT(1).getT(7).getT(0);                 // osc1_impl::xfader48_t<NV>
		auto& soft_bypass42 = this->getT(0).getT(2).getT(1).getT(7).getT(1);            // osc1_impl::soft_bypass42_t<NV>
		auto& chain222 = this->getT(0).getT(2).getT(1).getT(7).getT(1).getT(0);         // osc1_impl::chain222_t<NV>
		auto& branch50 = this->getT(0).getT(2).getT(1).getT(7).getT(1).getT(0).getT(0); // osc1_impl::branch50_t<NV>
		auto& chain223 = this->getT(0).getT(2).getT(1).getT(7).                         // osc1_impl::chain223_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& midi_cc39 = this->getT(0).getT(2).getT(1).getT(7).                       // osc1_impl::midi_cc39_t<NV>
                          getT(1).getT(0).getT(0).getT(0).
                          getT(0);
		auto& add172 = this->getT(0).getT(2).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(0).
                       getT(1);
		auto& chain224 = this->getT(0).getT(2).getT(1).getT(7).                        // osc1_impl::chain224_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& midi_cc40 = this->getT(0).getT(2).getT(1).getT(7).                       // osc1_impl::midi_cc40_t<NV>
                          getT(1).getT(0).getT(0).getT(1).
                          getT(0);
		auto& add173 = this->getT(0).getT(2).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(1).
                       getT(1);
		auto& chain225 = this->getT(0).getT(2).getT(1).getT(7).                        // osc1_impl::chain225_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& midi_cc41 = this->getT(0).getT(2).getT(1).getT(7).                       // osc1_impl::midi_cc41_t<NV>
                          getT(1).getT(0).getT(0).getT(2).
                          getT(0);
		auto& add174 = this->getT(0).getT(2).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(2).
                       getT(1);
		auto& chain226 = this->getT(0).getT(2).getT(1).getT(7).                        // osc1_impl::chain226_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& midi_cc42 = this->getT(0).getT(2).getT(1).getT(7).                       // osc1_impl::midi_cc42_t<NV>
                          getT(1).getT(0).getT(0).getT(3).
                          getT(0);
		auto& add175 = this->getT(0).getT(2).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(3).
                       getT(1);
		auto& chain227 = this->getT(0).getT(2).getT(1).getT(7).                        // osc1_impl::chain227_t<NV>
                         getT(1).getT(0).getT(0).getT(4);
		auto& midi29 = this->getT(0).getT(2).getT(1).getT(7).                          // osc1_impl::midi29_t<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(0);
		auto& add176 = this->getT(0).getT(2).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(1);
		auto& chain228 = this->getT(0).getT(2).getT(1).getT(7).                        // osc1_impl::chain228_t<NV>
                         getT(1).getT(0).getT(0).getT(5);
		auto& midi30 = this->getT(0).getT(2).getT(1).getT(7).                          // osc1_impl::midi30_t<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(0);
		auto& add177 = this->getT(0).getT(2).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(1);
		auto& chain229 = this->getT(0).getT(2).getT(1).getT(7).                        // osc1_impl::chain229_t<NV>
                         getT(1).getT(0).getT(0).getT(6);
		auto& midi31 = this->getT(0).getT(2).getT(1).getT(7).                          // osc1_impl::midi31_t<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(0);
		auto& add178 = this->getT(0).getT(2).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(1);
		auto& gain123 = this->getT(0).getT(2).getT(1).getT(7).getT(1).getT(0).getT(1); // core::gain<NV>
		auto& peak19 = this->getT(0).getT(2).getT(2);                                  // osc1_impl::peak19_t<NV>
		auto& pma16 = this->getT(0).getT(2).getT(3);                                   // osc1_impl::pma16_t<NV>
		auto& chain59 = this->getT(1);                                                 // osc1_impl::chain59_t<NV>
		auto& xfade_2x_lin = this->getT(1).getT(0);                                    // osc1_impl::xfade_2x_lin_t<NV>
		auto& split20 = this->getT(1).getT(0).getT(0);                                 // osc1_impl::split20_t<NV>
		auto& chain19 = this->getT(1).getT(0).getT(0).getT(0);                         // osc1_impl::chain19_t<NV>
		auto& chain77 = this->getT(1).getT(0).getT(0).getT(0).getT(0);                 // osc1_impl::chain77_t<NV>
		auto& pma = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);             // osc1_impl::pma_t<NV>
		auto& gain1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);           // core::gain<NV>
		auto& modchain = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(2);        // osc1_impl::modchain_t<NV>
		auto& split = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);   // osc1_impl::split_t<NV>
		auto& chain8 = this->getT(1).getT(0).getT(0).getT(0).                          // osc1_impl::chain8_t<NV>
                       getT(0).getT(2).getT(0).getT(0);
		auto& minmax2 = this->getT(1).getT(0).getT(0).getT(0).                         // osc1_impl::minmax2_t<NV>
                        getT(0).getT(2).getT(0).getT(0).
                        getT(0);
		auto& converter = this->getT(1).getT(0).getT(0).getT(0).                       // osc1_impl::converter_t<NV>
                          getT(0).getT(2).getT(0).getT(0).
                          getT(1);
		auto& chain12 = this->getT(1).getT(0).getT(0).getT(0).                         // osc1_impl::chain12_t<NV>
                        getT(0).getT(2).getT(0).getT(1);
		auto& tempo_sync = this->getT(1).getT(0).getT(0).getT(0).                      // osc1_impl::tempo_sync_t<NV>
                           getT(0).getT(2).getT(0).getT(1).
                           getT(0);
		auto& converter5 = this->getT(1).getT(0).getT(0).getT(0).                      // osc1_impl::converter5_t<NV>
                           getT(0).getT(2).getT(0).getT(1).
                           getT(1);
		auto& branch1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(3);         // osc1_impl::branch1_t<NV>
		auto& chain1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(3).getT(0);  // osc1_impl::chain1_t<NV>
		auto& phasor_fm = this->getT(1).getT(0).getT(0).getT(0).                       // core::phasor_fm<NV>
                          getT(0).getT(3).getT(0).getT(0);
		auto& chain2 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(3).getT(1);  // osc1_impl::chain2_t<NV>
		auto& phasor_fm3 = this->getT(1).getT(0).getT(0).getT(0).                      // core::phasor_fm<NV>
                           getT(0).getT(3).getT(1).getT(0);
		auto& no_midi = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(3).getT(2); // osc1_impl::no_midi_t<NV>
		auto& phasor_fm1 = this->getT(1).getT(0).getT(0).getT(0).                      // core::phasor_fm<NV>
                           getT(0).getT(3).getT(2).getT(0);
		auto& sig2mod = this->getT(1).getT(0).getT(0).getT(0).                         // wrap::no_process<math::sig2mod<NV>>
                        getT(0).getT(3).getT(2).getT(1);
		auto& mono2stereo = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(4);     // core::mono2stereo
		auto& pma6 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(5);            // osc1_impl::pma6_t<NV>
		auto& branch2 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6);         // osc1_impl::branch2_t<NV>
		auto& chain88 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6).getT(0); // osc1_impl::chain88_t<NV>
		auto& xfader3 = this->getT(1).getT(0).getT(0).getT(0).                         // osc1_impl::xfader3_t<NV>
                        getT(0).getT(6).getT(0).getT(0);
		auto& split16 = this->getT(1).getT(0).getT(0).getT(0).                         // osc1_impl::split16_t<NV>
                        getT(0).getT(6).getT(0).getT(1);
		auto& chain62 = this->getT(1).getT(0).getT(0).getT(0).                         // osc1_impl::chain62_t<NV>
                        getT(0).getT(6).getT(0).getT(1).
                        getT(0);
		auto& chain74 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                 // osc1_impl::chain74_t<NV>
                        getT(6).getT(0).getT(1).getT(0).getT(0);
		auto& sub1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                    // math::sub<NV>
                     getT(6).getT(0).getT(1).getT(0).getT(0).
                     getT(0);
		auto& abs1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                    // math::abs<NV>
                     getT(6).getT(0).getT(1).getT(0).getT(0).
                     getT(1);
		auto& mul2 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                    // math::mul<NV>
                     getT(6).getT(0).getT(1).getT(0).getT(0).
                     getT(2);
		auto& gain49 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                  // core::gain<NV>
                       getT(6).getT(0).getT(1).getT(0).getT(1);
		auto& chain75 = this->getT(1).getT(0).getT(0).getT(0).                         // osc1_impl::chain75_t<NV>
                        getT(0).getT(6).getT(0).getT(1).
                        getT(1);
		auto& expr3 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                   // math::expr<NV, custom::expr3>
                      getT(6).getT(0).getT(1).getT(1).getT(0);
		auto& gain50 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                  // core::gain<NV>
                       getT(6).getT(0).getT(1).getT(1).getT(1);
		auto& chain76 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6).getT(1); // osc1_impl::chain76_t<NV>
		auto& gain51 = this->getT(1).getT(0).getT(0).getT(0).                          // core::gain<NV>
                       getT(0).getT(6).getT(1).getT(0);
		auto& rect2 = this->getT(1).getT(0).getT(0).getT(0).                           // math::rect<NV>
                      getT(0).getT(6).getT(1).getT(1);
		auto& chain78 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6).getT(2); // osc1_impl::chain78_t<NV>
		auto& gain53 = this->getT(1).getT(0).getT(0).getT(0).                          // core::gain<NV>
                       getT(0).getT(6).getT(2).getT(0);
		auto& fmod2 = this->getT(1).getT(0).getT(0).getT(0).                           // math::fmod<NV>
                      getT(0).getT(6).getT(2).getT(1);
		auto& mul3 = this->getT(1).getT(0).getT(0).getT(0).                            // wrap::no_process<math::mul<NV>>
                     getT(0).getT(6).getT(2).getT(2);
		auto& pi8 = this->getT(1).getT(0).getT(0).getT(0).                             // math::pi<NV>
                    getT(0).getT(6).getT(2).getT(3);
		auto& chain79 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6).getT(3); // osc1_impl::chain79_t<NV>
		auto& gain56 = this->getT(1).getT(0).getT(0).getT(0).                          // core::gain<NV>
                       getT(0).getT(6).getT(3).getT(0);
		auto& expr6 = this->getT(1).getT(0).getT(0).getT(0).                           // math::expr<NV, custom::expr6>
                      getT(0).getT(6).getT(3).getT(1);
		auto& sin7 = this->getT(1).getT(0).getT(0).getT(0).                            // math::sin<NV>
                     getT(0).getT(6).getT(3).getT(2);
		auto& chain80 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6).getT(4); // osc1_impl::chain80_t<NV>
		auto& pi9 = this->getT(1).getT(0).getT(0).getT(0).                             // math::pi<NV>
                    getT(0).getT(6).getT(4).getT(0);
		auto& sin1 = this->getT(1).getT(0).getT(0).getT(0).                            // wrap::no_process<math::sin<NV>>
                     getT(0).getT(6).getT(4).getT(1);
		auto& gain58 = this->getT(1).getT(0).getT(0).getT(0).                          // core::gain<NV>
                       getT(0).getT(6).getT(4).getT(2);
		auto& sin9 = this->getT(1).getT(0).getT(0).getT(0).                            // math::sin<NV>
                     getT(0).getT(6).getT(4).getT(3);
		auto& expr7 = this->getT(1).getT(0).getT(0).getT(0).                           // math::expr<NV, custom::expr7>
                      getT(0).getT(6).getT(4).getT(4);
		auto& chain81 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6).getT(5); // osc1_impl::chain81_t<NV>
		auto& pi3 = this->getT(1).getT(0).getT(0).getT(0).                             // wrap::no_process<math::pi<NV>>
                    getT(0).getT(6).getT(5).getT(0);
		auto& phase_delay1 = this->getT(1).getT(0).getT(0).getT(0).                    // wrap::no_process<fx::phase_delay<NV>>
                             getT(0).getT(6).getT(5).getT(1);
		auto& gain59 = this->getT(1).getT(0).getT(0).getT(0).                          // core::gain<NV>
                       getT(0).getT(6).getT(5).getT(2);
		auto& expr8 = this->getT(1).getT(0).getT(0).getT(0).                           // math::expr<NV, custom::expr8>
                      getT(0).getT(6).getT(5).getT(3);
		auto& sin10 = this->getT(1).getT(0).getT(0).getT(0).                           // math::sin<NV>
                      getT(0).getT(6).getT(5).getT(4);
		auto& chain85 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6).getT(6); // osc1_impl::chain85_t<NV>
		auto& gain63 = this->getT(1).getT(0).getT(0).getT(0).                          // core::gain<NV>
                       getT(0).getT(6).getT(6).getT(0);
		auto& pi12 = this->getT(1).getT(0).getT(0).getT(0).              // math::pi<NV>
                     getT(0).getT(6).getT(6).getT(1);
		auto& table5 = this->getT(1).getT(0).getT(0).getT(0).            // osc1_impl::table5_t
                       getT(0).getT(6).getT(6).getT(2);
		auto& clear19 = this->getT(1).getT(0).getT(0).getT(0).getT(1);   // wrap::no_process<math::clear<NV>>
		auto& one_pole1 = this->getT(1).getT(0).getT(0).getT(0).getT(2); // filters::one_pole<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Pitch -> pma1::Add
		
		auto& tempo_p = this->getParameterT(1);
		tempo_p.connectT(0, pma8);  // tempo -> pma8::Add
		tempo_p.connectT(1, pma11); // tempo -> pma11::Add
		
		this->getParameterT(2).connectT(0, tempo_sync); // div -> tempo_sync::Multiplier
		
		auto& pitchmode_p = this->getParameterT(3);
		pitchmode_p.connectT(0, branch1); // pitchmode -> branch1::Index
		pitchmode_p.connectT(1, branch3); // pitchmode -> branch3::Index
		
		this->getParameterT(4).connectT(0, minmax2); // step -> minmax2::Step
		
		auto& PitchMod_p = this->getParameterT(5);
		PitchMod_p.connectT(0, pma1);  // PitchMod -> pma1::Multiply
		PitchMod_p.connectT(1, pma8);  // PitchMod -> pma8::Multiply
		PitchMod_p.connectT(2, pma11); // PitchMod -> pma11::Multiply
		
		this->getParameterT(6).connectT(0, pma); // Input1 -> pma::Add
		
		this->getParameterT(7).connectT(0, pma); // InMod1 -> pma::Multiply
		
		this->getParameterT(8).connectT(0, branch5); // MidiSlotPitch -> branch5::Index
		
		this->getParameterT(9).connectT(0, smoother); // Bend -> smoother::SmoothingTime
		
		this->getParameterT(10).connectT(0, branch2); // Shape -> branch2::Index
		
		this->getParameterT(11).connectT(0, pma16); // WidhMod -> pma16::Multiply
		
		this->getParameterT(12).connectT(0, pma16); // Width -> pma16::Add
		
		this->getParameterT(13).connectT(0, branch50); // MidiWidth -> branch50::Index
		
		this->getParameterT(14).connectT(0, branch15); // PitchPkModSrc1 -> branch15::Index
		
		this->getParameterT(16).connectT(0, branch16); // OscInPeak -> branch16::Index
		
		this->getParameterT(17).connectT(0, branch19); // OscWidthPk -> branch19::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable3.getWrappedObject().getParameter().connectT(0, add4); // global_cable3 -> add4::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(1).connectT(0, soft_bypass);                 // xfader2 -> soft_bypass::Bypassed
		global_cable11.getWrappedObject().getParameter().connectT(0, add26); // global_cable11 -> add26::Value
		auto& xfader13_p = xfader13.getWrappedObject().getParameter();
		xfader13_p.getParameterT(1).connectT(0, soft_bypass7);              // xfader13 -> soft_bypass7::Bypassed
		global_cable10.getWrappedObject().getParameter().connectT(0, add5); // global_cable10 -> add5::Value
		auto& xfader12_p = xfader12.getWrappedObject().getParameter();
		xfader12_p.getParameterT(1).connectT(0, soft_bypass6);               // xfader12 -> soft_bypass6::Bypassed
		global_cable14.getWrappedObject().getParameter().connectT(0, add27); // global_cable14 -> add27::Value
		auto& xfader11_p = xfader11.getWrappedObject().getParameter();
		xfader11_p.getParameterT(1).connectT(0, soft_bypass5); // xfader11 -> soft_bypass5::Bypassed
		event_data_reader4.getParameter().connectT(0, add29);  // event_data_reader4 -> add29::Value
		auto& xfader10_p = xfader10.getWrappedObject().getParameter();
		xfader10_p.getParameterT(1).connectT(0, soft_bypass4); // xfader10 -> soft_bypass4::Bypassed
		event_data_reader5.getParameter().connectT(0, add28);  // event_data_reader5 -> add28::Value
		auto& xfader9_p = xfader9.getWrappedObject().getParameter();
		xfader9_p.getParameterT(1).connectT(0, soft_bypass3); // xfader9 -> soft_bypass3::Bypassed
		event_data_reader.getParameter().connectT(0, add3);   // event_data_reader -> add3::Value
		event_data_reader3.getParameter().connectT(0, add16); // event_data_reader3 -> add16::Value
		event_data_reader2.getParameter().connectT(0, add15); // event_data_reader2 -> add15::Value
		event_data_reader1.getParameter().connectT(0, add14); // event_data_reader1 -> add14::Value
		auto& xfader8_p = xfader8.getWrappedObject().getParameter();
		xfader8_p.getParameterT(1).connectT(0, soft_bypass2);           // xfader8 -> soft_bypass2::Bypassed
		midi_cc10.getWrappedObject().getParameter().connectT(0, add50); // midi_cc10 -> add50::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, add51); // midi_cc11 -> add51::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, add52); // midi_cc12 -> add52::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, add53); // midi_cc13 -> add53::Value
		midi6.getParameter().connectT(0, add54);                        // midi6 -> add54::Value
		midi7.getParameter().connectT(0, add55);                        // midi7 -> add55::Value
		midi8.getParameter().connectT(0, add56);                        // midi8 -> add56::Value
		auto& xfader7_p = xfader7.getWrappedObject().getParameter();
		xfader7_p.getParameterT(1).connectT(0, soft_bypass1); // xfader7 -> soft_bypass1::Bypassed
		auto& sliderbank3_p = sliderbank3.getWrappedObject().getParameter();
		sliderbank3_p.getParameterT(0).connectT(0, gain13);                   // sliderbank3 -> gain13::Gain
		sliderbank3_p.getParameterT(0).connectT(1, xfader2);                  // sliderbank3 -> xfader2::Value
		sliderbank3_p.getParameterT(1).connectT(0, gain15);                   // sliderbank3 -> gain15::Gain
		sliderbank3_p.getParameterT(1).connectT(1, xfader13);                 // sliderbank3 -> xfader13::Value
		sliderbank3_p.getParameterT(2).connectT(0, gain14);                   // sliderbank3 -> gain14::Gain
		sliderbank3_p.getParameterT(2).connectT(1, xfader12);                 // sliderbank3 -> xfader12::Value
		sliderbank3_p.getParameterT(3).connectT(0, gain16);                   // sliderbank3 -> gain16::Gain
		sliderbank3_p.getParameterT(3).connectT(1, xfader11);                 // sliderbank3 -> xfader11::Value
		sliderbank3_p.getParameterT(4).connectT(0, gain32);                   // sliderbank3 -> gain32::Gain
		sliderbank3_p.getParameterT(4).connectT(1, xfader10);                 // sliderbank3 -> xfader10::Value
		sliderbank3_p.getParameterT(5).connectT(0, gain26);                   // sliderbank3 -> gain26::Gain
		sliderbank3_p.getParameterT(5).connectT(1, xfader9);                  // sliderbank3 -> xfader9::Value
		sliderbank3_p.getParameterT(6).connectT(0, gain33);                   // sliderbank3 -> gain33::Gain
		sliderbank3_p.getParameterT(6).connectT(1, xfader8);                  // sliderbank3 -> xfader8::Value
		sliderbank3_p.getParameterT(7).connectT(0, gain34);                   // sliderbank3 -> gain34::Gain
		sliderbank3_p.getParameterT(7).connectT(1, xfader7);                  // sliderbank3 -> xfader7::Value
		pma1.getWrappedObject().getParameter().connectT(0, add);              // pma1 -> add::Value
		pma8.getWrappedObject().getParameter().connectT(0, add19);            // pma8 -> add19::Value
		pma11.getWrappedObject().getParameter().connectT(0, add20);           // pma11 -> add20::Value
		peak3.getParameter().connectT(0, pma1);                               // peak3 -> pma1::Value
		peak3.getParameter().connectT(1, pma8);                               // peak3 -> pma8::Value
		peak3.getParameter().connectT(2, pma11);                              // peak3 -> pma11::Value
		converter.getWrappedObject().getParameter().connectT(0, phasor_fm);   // converter -> phasor_fm::FreqRatio
		minmax2.getWrappedObject().getParameter().connectT(0, converter);     // minmax2 -> converter::Value
		converter5.getWrappedObject().getParameter().connectT(0, phasor_fm3); // converter5 -> phasor_fm3::FreqRatio
		converter5.getWrappedObject().getParameter().connectT(1, phasor_fm1); // converter5 -> phasor_fm1::Frequency
		tempo_sync.getParameter().connectT(0, converter5);                    // tempo_sync -> converter5::Value
		peak.getParameter().connectT(0, minmax2);                             // peak -> minmax2::Value
		peak.getParameter().connectT(1, tempo_sync);                          // peak -> tempo_sync::Tempo
		global_cable6.getWrappedObject().getParameter().connectT(0, add10);   // global_cable6 -> add10::Value
		auto& xfader23_p = xfader23.getWrappedObject().getParameter();
		xfader23_p.getParameterT(1).connectT(0, soft_bypass17);              // xfader23 -> soft_bypass17::Bypassed
		global_cable16.getWrappedObject().getParameter().connectT(0, add44); // global_cable16 -> add44::Value
		auto& xfader38_p = xfader38.getWrappedObject().getParameter();
		xfader38_p.getParameterT(1).connectT(0, soft_bypass32);              // xfader38 -> soft_bypass32::Bypassed
		global_cable17.getWrappedObject().getParameter().connectT(0, add11); // global_cable17 -> add11::Value
		auto& xfader37_p = xfader37.getWrappedObject().getParameter();
		xfader37_p.getParameterT(1).connectT(0, soft_bypass31);              // xfader37 -> soft_bypass31::Bypassed
		global_cable26.getWrappedObject().getParameter().connectT(0, add45); // global_cable26 -> add45::Value
		auto& xfader36_p = xfader36.getWrappedObject().getParameter();
		xfader36_p.getParameterT(1).connectT(0, soft_bypass30); // xfader36 -> soft_bypass30::Bypassed
		auto& xfader35_p = xfader35.getWrappedObject().getParameter();
		xfader35_p.getParameterT(1).connectT(0, soft_bypass29); // xfader35 -> soft_bypass29::Bypassed
		event_data_reader11.getParameter().connectT(0, add47);  // event_data_reader11 -> add47::Value
		auto& xfader34_p = xfader34.getWrappedObject().getParameter();
		xfader34_p.getParameterT(1).connectT(0, soft_bypass28); // xfader34 -> soft_bypass28::Bypassed
		event_data_reader6.getParameter().connectT(0, add6);    // event_data_reader6 -> add6::Value
		event_data_reader7.getParameter().connectT(0, add17);   // event_data_reader7 -> add17::Value
		event_data_reader8.getParameter().connectT(0, add18);   // event_data_reader8 -> add18::Value
		event_data_reader9.getParameter().connectT(0, add21);   // event_data_reader9 -> add21::Value
		auto& xfader33_p = xfader33.getWrappedObject().getParameter();
		xfader33_p.getParameterT(1).connectT(0, soft_bypass27);         // xfader33 -> soft_bypass27::Bypassed
		midi_cc14.getWrappedObject().getParameter().connectT(0, add57); // midi_cc14 -> add57::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, add58); // midi_cc15 -> add58::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, add59); // midi_cc16 -> add59::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, add60); // midi_cc17 -> add60::Value
		midi9.getParameter().connectT(0, add61);                        // midi9 -> add61::Value
		midi10.getParameter().connectT(0, add62);                       // midi10 -> add62::Value
		midi11.getParameter().connectT(0, add63);                       // midi11 -> add63::Value
		auto& xfader32_p = xfader32.getWrappedObject().getParameter();
		xfader32_p.getParameterT(1).connectT(0, soft_bypass26); // xfader32 -> soft_bypass26::Bypassed
		auto& sliderbank6_p = sliderbank6.getWrappedObject().getParameter();
		sliderbank6_p.getParameterT(0).connectT(0, gain25);                   // sliderbank6 -> gain25::Gain
		sliderbank6_p.getParameterT(0).connectT(1, xfader23);                 // sliderbank6 -> xfader23::Value
		sliderbank6_p.getParameterT(1).connectT(0, gain29);                   // sliderbank6 -> gain29::Gain
		sliderbank6_p.getParameterT(1).connectT(1, xfader38);                 // sliderbank6 -> xfader38::Value
		sliderbank6_p.getParameterT(2).connectT(0, gain30);                   // sliderbank6 -> gain30::Gain
		sliderbank6_p.getParameterT(2).connectT(1, xfader37);                 // sliderbank6 -> xfader37::Value
		sliderbank6_p.getParameterT(3).connectT(0, gain31);                   // sliderbank6 -> gain31::Gain
		sliderbank6_p.getParameterT(3).connectT(1, xfader36);                 // sliderbank6 -> xfader36::Value
		sliderbank6_p.getParameterT(4).connectT(0, gain41);                   // sliderbank6 -> gain41::Gain
		sliderbank6_p.getParameterT(4).connectT(1, xfader35);                 // sliderbank6 -> xfader35::Value
		sliderbank6_p.getParameterT(5).connectT(0, gain42);                   // sliderbank6 -> gain42::Gain
		sliderbank6_p.getParameterT(5).connectT(1, xfader34);                 // sliderbank6 -> xfader34::Value
		sliderbank6_p.getParameterT(6).connectT(0, gain43);                   // sliderbank6 -> gain43::Gain
		sliderbank6_p.getParameterT(6).connectT(1, xfader33);                 // sliderbank6 -> xfader33::Value
		sliderbank6_p.getParameterT(7).connectT(0, gain44);                   // sliderbank6 -> gain44::Gain
		sliderbank6_p.getParameterT(7).connectT(1, xfader32);                 // sliderbank6 -> xfader32::Value
		event_data_reader10.getParameter().connectT(0, add46);                // event_data_reader10 -> add46::Value
		pma.getWrappedObject().getParameter().connectT(0, gain1);             // pma -> gain1::Gain
		peak6.getParameter().connectT(0, pma);                                // peak6 -> pma::Value
		global_cable39.getWrappedObject().getParameter().connectT(0, add161); // global_cable39 -> add161::Value
		auto& xfader39_p = xfader39.getWrappedObject().getParameter();
		xfader39_p.getParameterT(1).connectT(0, soft_bypass33);               // xfader39 -> soft_bypass33::Bypassed
		global_cable40.getWrappedObject().getParameter().connectT(0, add162); // global_cable40 -> add162::Value
		auto& xfader54_p = xfader54.getWrappedObject().getParameter();
		xfader54_p.getParameterT(1).connectT(0, soft_bypass48);               // xfader54 -> soft_bypass48::Bypassed
		global_cable41.getWrappedObject().getParameter().connectT(0, add163); // global_cable41 -> add163::Value
		auto& xfader53_p = xfader53.getWrappedObject().getParameter();
		xfader53_p.getParameterT(1).connectT(0, soft_bypass47);               // xfader53 -> soft_bypass47::Bypassed
		global_cable42.getWrappedObject().getParameter().connectT(0, add164); // global_cable42 -> add164::Value
		auto& xfader52_p = xfader52.getWrappedObject().getParameter();
		xfader52_p.getParameterT(1).connectT(0, soft_bypass46); // xfader52 -> soft_bypass46::Bypassed
		event_data_reader16.getParameter().connectT(0, add165); // event_data_reader16 -> add165::Value
		auto& xfader51_p = xfader51.getWrappedObject().getParameter();
		xfader51_p.getParameterT(1).connectT(0, soft_bypass45); // xfader51 -> soft_bypass45::Bypassed
		event_data_reader17.getParameter().connectT(0, add166); // event_data_reader17 -> add166::Value
		auto& xfader50_p = xfader50.getWrappedObject().getParameter();
		xfader50_p.getParameterT(1).connectT(0, soft_bypass44); // xfader50 -> soft_bypass44::Bypassed
		event_data_reader12.getParameter().connectT(0, add7);   // event_data_reader12 -> add7::Value
		event_data_reader13.getParameter().connectT(0, add23);  // event_data_reader13 -> add23::Value
		event_data_reader14.getParameter().connectT(0, add24);  // event_data_reader14 -> add24::Value
		event_data_reader15.getParameter().connectT(0, add25);  // event_data_reader15 -> add25::Value
		auto& xfader49_p = xfader49.getWrappedObject().getParameter();
		xfader49_p.getParameterT(1).connectT(0, soft_bypass43);          // xfader49 -> soft_bypass43::Bypassed
		midi_cc39.getWrappedObject().getParameter().connectT(0, add172); // midi_cc39 -> add172::Value
		midi_cc40.getWrappedObject().getParameter().connectT(0, add173); // midi_cc40 -> add173::Value
		midi_cc41.getWrappedObject().getParameter().connectT(0, add174); // midi_cc41 -> add174::Value
		midi_cc42.getWrappedObject().getParameter().connectT(0, add175); // midi_cc42 -> add175::Value
		midi29.getParameter().connectT(0, add176);                       // midi29 -> add176::Value
		midi30.getParameter().connectT(0, add177);                       // midi30 -> add177::Value
		midi31.getParameter().connectT(0, add178);                       // midi31 -> add178::Value
		auto& xfader48_p = xfader48.getWrappedObject().getParameter();
		xfader48_p.getParameterT(1).connectT(0, soft_bypass42); // xfader48 -> soft_bypass42::Bypassed
		auto& sliderbank12_p = sliderbank12.getWrappedObject().getParameter();
		sliderbank12_p.getParameterT(0).connectT(0, gain116);  // sliderbank12 -> gain116::Gain
		sliderbank12_p.getParameterT(0).connectT(1, xfader39); // sliderbank12 -> xfader39::Value
		sliderbank12_p.getParameterT(1).connectT(0, gain117);  // sliderbank12 -> gain117::Gain
		sliderbank12_p.getParameterT(1).connectT(1, xfader54); // sliderbank12 -> xfader54::Value
		sliderbank12_p.getParameterT(2).connectT(0, gain118);  // sliderbank12 -> gain118::Gain
		sliderbank12_p.getParameterT(2).connectT(1, xfader53); // sliderbank12 -> xfader53::Value
		sliderbank12_p.getParameterT(3).connectT(0, gain119);  // sliderbank12 -> gain119::Gain
		sliderbank12_p.getParameterT(3).connectT(1, xfader52); // sliderbank12 -> xfader52::Value
		sliderbank12_p.getParameterT(4).connectT(0, gain120);  // sliderbank12 -> gain120::Gain
		sliderbank12_p.getParameterT(4).connectT(1, xfader51); // sliderbank12 -> xfader51::Value
		sliderbank12_p.getParameterT(5).connectT(0, gain121);  // sliderbank12 -> gain121::Gain
		sliderbank12_p.getParameterT(5).connectT(1, xfader50); // sliderbank12 -> xfader50::Value
		sliderbank12_p.getParameterT(6).connectT(0, gain122);  // sliderbank12 -> gain122::Gain
		sliderbank12_p.getParameterT(6).connectT(1, xfader49); // sliderbank12 -> xfader49::Value
		sliderbank12_p.getParameterT(7).connectT(0, gain123);  // sliderbank12 -> gain123::Gain
		sliderbank12_p.getParameterT(7).connectT(1, xfader48); // sliderbank12 -> xfader48::Value
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, gain49);                   // xfader3 -> gain49::Gain
		xfader3_p.getParameterT(1).connectT(0, gain50);                   // xfader3 -> gain50::Gain
		pma6.getWrappedObject().getParameter().connectT(0, gain63);       // pma6 -> gain63::Gain
		pma6.getWrappedObject().getParameter().connectT(1, gain59);       // pma6 -> gain59::Gain
		pma6.getWrappedObject().getParameter().connectT(2, gain53);       // pma6 -> gain53::Gain
		pma6.getWrappedObject().getParameter().connectT(3, gain56);       // pma6 -> gain56::Gain
		pma6.getWrappedObject().getParameter().connectT(4, expr6);        // pma6 -> expr6::Value
		pma6.getWrappedObject().getParameter().connectT(5, phase_delay1); // pma6 -> phase_delay1::Frequency
		pma6.getWrappedObject().getParameter().connectT(6, xfader3);      // pma6 -> xfader3::Value
		pma6.getWrappedObject().getParameter().connectT(7, gain58);       // pma6 -> gain58::Gain
		pma6.getWrappedObject().getParameter().connectT(8, gain51);       // pma6 -> gain51::Gain
		pma16.getWrappedObject().getParameter().connectT(0, pma6);        // pma16 -> pma6::Add
		peak19.getParameter().connectT(0, pma16);                         // peak19 -> pma16::Value
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank3.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // xfader2::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		;                             // gain13::Gain is automated
		gain13.setParameterT(1, 20.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader13::Value is automated
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		;                             // gain15::Gain is automated
		gain15.setParameterT(1, 20.); // core::gain::Smoothing
		gain15.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader12::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		;                             // gain14::Gain is automated
		gain14.setParameterT(1, 20.); // core::gain::Smoothing
		gain14.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader11::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		;                             // gain16::Gain is automated
		gain16.setParameterT(1, 20.); // core::gain::Smoothing
		gain16.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader10::Value is automated
		
		event_data_reader4.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add29::Value is automated
		
		;                             // gain32::Gain is automated
		gain32.setParameterT(1, 20.); // core::gain::Smoothing
		gain32.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader9::Value is automated
		
		event_data_reader5.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add28::Value is automated
		
		;                             // gain26::Gain is automated
		gain26.setParameterT(1, 20.); // core::gain::Smoothing
		gain26.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader8::Value is automated
		
		; // branch15::Index is automated
		
		event_data_reader.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add3::Value is automated
		
		event_data_reader3.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader3.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add16::Value is automated
		
		event_data_reader2.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader2.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add15::Value is automated
		
		event_data_reader1.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader1.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add14::Value is automated
		
		;                             // gain33::Gain is automated
		gain33.setParameterT(1, 20.); // core::gain::Smoothing
		gain33.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader7::Value is automated
		
		; // branch5::Index is automated
		
		midi_cc10.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc10.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc10.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add50::Value is automated
		
		midi_cc11.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc11.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc11.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add51::Value is automated
		
		midi_cc12.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc12.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc12.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add52::Value is automated
		
		midi_cc13.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc13.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc13.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add53::Value is automated
		
		; // add54::Value is automated
		
		; // add55::Value is automated
		
		; // add56::Value is automated
		
		;                             // gain34::Gain is automated
		gain34.setParameterT(1, 20.); // core::gain::Smoothing
		gain34.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch3::Index is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // add::Value is automated
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
		; // add19::Value is automated
		
		; // pma11::Value is automated
		; // pma11::Multiply is automated
		; // pma11::Add is automated
		
		; // add20::Value is automated
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		sliderbank6.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // xfader23::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader38::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add44::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader37::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                             // gain30::Gain is automated
		gain30.setParameterT(1, 20.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader36::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add45::Value is automated
		
		;                             // gain31::Gain is automated
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader35::Value is automated
		
		event_data_reader10.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add46::Value is automated
		
		;                             // gain41::Gain is automated
		gain41.setParameterT(1, 20.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader34::Value is automated
		
		event_data_reader11.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader11.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add47::Value is automated
		
		;                             // gain42::Gain is automated
		gain42.setParameterT(1, 20.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader33::Value is automated
		
		; // branch16::Index is automated
		
		event_data_reader6.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add6::Value is automated
		
		event_data_reader7.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add17::Value is automated
		
		event_data_reader8.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader8.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add18::Value is automated
		
		event_data_reader9.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader9.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add21::Value is automated
		
		add48.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain43::Gain is automated
		gain43.setParameterT(1, 20.); // core::gain::Smoothing
		gain43.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader32::Value is automated
		
		branch6.setParameterT(0, 0.); // container::branch::Index
		
		midi_cc14.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc14.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc14.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add57::Value is automated
		
		midi_cc15.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc15.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc15.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add58::Value is automated
		
		midi_cc16.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc16.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc16.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add59::Value is automated
		
		midi_cc17.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc17.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc17.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add60::Value is automated
		
		; // add61::Value is automated
		
		; // add62::Value is automated
		
		; // add63::Value is automated
		
		;                             // gain44::Gain is automated
		gain44.setParameterT(1, 20.); // core::gain::Smoothing
		gain44.setParameterT(2, 0.);  // core::gain::ResetValue
		
		sliderbank12.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // xfader39::Value is automated
		
		global_cable39.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add161::Value is automated
		
		;                              // gain116::Gain is automated
		gain116.setParameterT(1, 20.); // core::gain::Smoothing
		gain116.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader54::Value is automated
		
		global_cable40.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add162::Value is automated
		
		;                              // gain117::Gain is automated
		gain117.setParameterT(1, 20.); // core::gain::Smoothing
		gain117.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader53::Value is automated
		
		global_cable41.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add163::Value is automated
		
		;                              // gain118::Gain is automated
		gain118.setParameterT(1, 20.); // core::gain::Smoothing
		gain118.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader52::Value is automated
		
		global_cable42.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add164::Value is automated
		
		;                              // gain119::Gain is automated
		gain119.setParameterT(1, 20.); // core::gain::Smoothing
		gain119.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader51::Value is automated
		
		event_data_reader16.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add165::Value is automated
		
		;                              // gain120::Gain is automated
		gain120.setParameterT(1, 20.); // core::gain::Smoothing
		gain120.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader50::Value is automated
		
		event_data_reader17.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add166::Value is automated
		
		;                              // gain121::Gain is automated
		gain121.setParameterT(1, 20.); // core::gain::Smoothing
		gain121.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader49::Value is automated
		
		; // branch19::Index is automated
		
		event_data_reader12.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add7::Value is automated
		
		event_data_reader13.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add23::Value is automated
		
		event_data_reader14.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add24::Value is automated
		
		event_data_reader15.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add25::Value is automated
		
		add49.setParameterT(0, 0.); // math::add::Value
		
		gain45.setParameterT(0, 0.);  // core::gain::Gain
		gain45.setParameterT(1, 20.); // core::gain::Smoothing
		gain45.setParameterT(2, 0.);  // core::gain::ResetValue
		
		add171.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain122::Gain is automated
		gain122.setParameterT(1, 20.); // core::gain::Smoothing
		gain122.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader48::Value is automated
		
		; // branch50::Index is automated
		
		midi_cc39.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc39.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc39.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add172::Value is automated
		
		midi_cc40.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc40.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc40.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add173::Value is automated
		
		midi_cc41.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc41.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc41.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add174::Value is automated
		
		midi_cc42.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc42.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc42.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add175::Value is automated
		
		; // add176::Value is automated
		
		; // add177::Value is automated
		
		; // add178::Value is automated
		
		;                              // gain123::Gain is automated
		gain123.setParameterT(1, 20.); // core::gain::Smoothing
		gain123.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma16::Value is automated
		; // pma16::Multiply is automated
		; // pma16::Add is automated
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                               // minmax2::Value is automated
		minmax2.setParameterT(1, -24.); // control::minmax::Minimum
		minmax2.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax2.setParameterT(3, 1.);   // control::minmax::Skew
		;                               // minmax2::Step is automated
		minmax2.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // converter::Value is automated
		
		;                                // tempo_sync::Tempo is automated
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 0.); // control::tempo_sync::UnsyncedTime
		
		; // converter5::Value is automated
		
		; // branch1::Index is automated
		
		phasor_fm.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                 // phasor_fm::FreqRatio is automated
		phasor_fm.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		phasor_fm3.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm3.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                  // phasor_fm3::FreqRatio is automated
		phasor_fm3.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		phasor_fm1.setParameterT(0, 1.);       // core::phasor_fm::Gate
		;                                      // phasor_fm1::Frequency is automated
		phasor_fm1.setParameterT(2, 0.957148); // core::phasor_fm::FreqRatio
		phasor_fm1.setParameterT(3, 0.);       // core::phasor_fm::Phase
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		pma6.setParameterT(0, 0.); // control::pma::Value
		pma6.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma6::Add is automated
		
		; // branch2::Index is automated
		
		; // xfader3::Value is automated
		
		sub1.setParameterT(0, 0.5); // math::sub::Value
		
		abs1.setParameterT(0, 1.); // math::abs::Value
		
		mul2.setParameterT(0, 2.); // math::mul::Value
		
		;                               // gain49::Gain is automated
		gain49.setParameterT(1, 19.1);  // core::gain::Smoothing
		gain49.setParameterT(2, -100.); // core::gain::ResetValue
		
		expr3.setParameterT(0, 1.); // math::expr::Value
		
		;                              // gain50::Gain is automated
		gain50.setParameterT(1, 19.8); // core::gain::Smoothing
		gain50.setParameterT(2, -22.); // core::gain::ResetValue
		
		;                              // gain51::Gain is automated
		gain51.setParameterT(1, 20.6); // core::gain::Smoothing
		gain51.setParameterT(2, -12.); // core::gain::ResetValue
		
		rect2.setParameterT(0, 1.); // math::rect::Value
		
		;                             // gain53::Gain is automated
		gain53.setParameterT(1, 20.); // core::gain::Smoothing
		gain53.setParameterT(2, 0.);  // core::gain::ResetValue
		
		fmod2.setParameterT(0, 1.); // math::fmod::Value
		
		mul3.setParameterT(0, 1.); // math::mul::Value
		
		pi8.setParameterT(0, 1.); // math::pi::Value
		
		;                              // gain56::Gain is automated
		gain56.setParameterT(1, 7);    // core::gain::Smoothing
		gain56.setParameterT(2, -12.); // core::gain::ResetValue
		
		; // expr6::Value is automated
		
		sin7.setParameterT(0, 1.); // math::sin::Value
		
		pi9.setParameterT(0, 0.5); // math::pi::Value
		
		sin1.setParameterT(0, 1.); // math::sin::Value
		
		;                              // gain58::Gain is automated
		gain58.setParameterT(1, 20.);  // core::gain::Smoothing
		gain58.setParameterT(2, -12.); // core::gain::ResetValue
		
		sin9.setParameterT(0, 1.); // math::sin::Value
		
		expr7.setParameterT(0, 1.); // math::expr::Value
		
		pi3.setParameterT(0, 0.465825); // math::pi::Value
		
		; // phase_delay1::Frequency is automated
		
		;                              // gain59::Gain is automated
		gain59.setParameterT(1, 20.);  // core::gain::Smoothing
		gain59.setParameterT(2, -12.); // core::gain::ResetValue
		
		expr8.setParameterT(0, 0.479197); // math::expr::Value
		
		sin10.setParameterT(0, 1.); // math::sin::Value
		
		;                              // gain63::Gain is automated
		gain63.setParameterT(1, 10.8); // core::gain::Smoothing
		gain63.setParameterT(2, -11.); // core::gain::ResetValue
		
		pi12.setParameterT(0, 1.); // math::pi::Value
		
		clear19.setParameterT(0, 0.); // math::clear::Value
		
		one_pole1.setParameterT(0, 48.5475); // filters::one_pole::Frequency
		one_pole1.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		this->setParameterT(0, -1.0231);
		this->setParameterT(1, 10.7364);
		this->setParameterT(2, 10.);
		this->setParameterT(3, 3.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.0186821);
		this->setParameterT(6, 0.652514);
		this->setParameterT(7, 0.257133);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 20.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 2.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 3.);
		this->setParameterT(18, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable14_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable6_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable16_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable17_t<NV>
		this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable26_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable39_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable40_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable41_t<NV>
		this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable42_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index);         // osc1_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index);         // osc1_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(4).getT(2).setExternalData(b, index); // osc1_impl::peak_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index);         // osc1_impl::sliderbank6_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);         // osc1_impl::peak6_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index);         // osc1_impl::sliderbank12_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index);         // osc1_impl::peak19_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).                           // osc1_impl::table5_t
        getT(0).getT(6).getT(6).getT(2).setExternalData(b, index);
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
using osc1 = wrap::node<osc1_impl::instance<NV>>;
}


