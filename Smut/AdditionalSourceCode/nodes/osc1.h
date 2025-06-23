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

DECLARE_PARAMETER_RANGE_SKEW(sliderbank3_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using sliderbank3_c0 = parameter::from0To1<core::gain<NV>, 
                                           0, 
                                           sliderbank3_c0Range>;

template <int NV> using sliderbank3_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c7 = sliderbank3_c0<NV>;

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
using global_cable3_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
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
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>, 
                                   core::gain<NV>>;

template <int NV> using chain43_t = chain44_t<NV>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<1, math::add<NV>>, 
                                     math::add<NV>, 
                                     math::add<NV>, 
                                     math::add<NV>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch15_t<NV>>, 
                                   core::gain<NV>>;

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
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain39_t<NV>>, 
                                  chain41_t<NV>, 
                                  chain40_t<NV>, 
                                  chain42_t<NV>, 
                                  chain44_t<NV>, 
                                  chain43_t<NV>, 
                                  chain45_t<NV>, 
                                  chain46_t<NV>>;

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

using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank3_t<NV>>, 
                                      split3_t<NV>, 
                                      peak3_t<NV>, 
                                      math::clear<NV>, 
                                      chain20_t<NV>, 
                                      split7_t>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV> using sliderbank5_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank5_multimod = parameter::list<sliderbank5_c0<NV>, 
                                             sliderbank5_c1<NV>, 
                                             sliderbank5_c2<NV>, 
                                             sliderbank5_c3<NV>, 
                                             sliderbank5_c4<NV>, 
                                             sliderbank5_c5<NV>, 
                                             sliderbank5_c6<NV>, 
                                             sliderbank5_c7<NV>>;

template <int NV>
using sliderbank5_t = wrap::data<control::sliderbank<sliderbank5_multimod<NV>>, 
                                 data::external::sliderpack<1>>;
using global_cable5_t_index = global_cable3_t_index;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain136_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable5_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable15_t_index = global_cable11_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain137_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable15_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable18_t_index = global_cable10_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain138_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable18_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable19_t_index = global_cable14_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain139_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable19_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain140_t = chain44_t<NV>;

template <int NV> using chain141_t = chain44_t<NV>;
template <int NV> using branch16_t = branch15_t<NV>;

template <int NV>
using chain142_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch16_t<NV>>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc18_t = midi_cc10_t<NV>;

template <int NV>
using chain144_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc18_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc19_t = midi_cc10_t<NV>;

template <int NV>
using chain145_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc19_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc20_t = midi_cc10_t<NV>;

template <int NV>
using chain146_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc20_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc21_t = midi_cc10_t<NV>;

template <int NV>
using chain147_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc21_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi12_t = midi6_t<NV>;

template <int NV>
using chain148_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi12_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi13_t = midi7_t<NV>;

template <int NV>
using chain149_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi13_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi14_t = midi8_t<NV>;

template <int NV>
using chain150_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi14_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain144_t<NV>>, 
                                     chain145_t<NV>, 
                                     chain146_t<NV>, 
                                     chain147_t<NV>, 
                                     chain148_t<NV>, 
                                     chain149_t<NV>, 
                                     chain150_t<NV>>;

template <int NV>
using chain143_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch11_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain136_t<NV>>, 
                                  chain137_t<NV>, 
                                  chain138_t<NV>, 
                                  chain139_t<NV>, 
                                  chain140_t<NV>, 
                                  chain141_t<NV>, 
                                  chain142_t<NV>, 
                                  chain143_t<NV>>;

template <int NV> using pma3_t = pma1_t<NV>;

template <int NV> using pma14_t = pma1_t<NV>;

template <int NV> using pma15_t = pma1_t<NV>;

template <int NV>
using peak5_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma3_t<NV>, 0>, 
                                   parameter::plain<pma14_t<NV>, 0>, 
                                   parameter::plain<pma15_t<NV>, 0>>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain152_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma3_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain154_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma14_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain155_t = container::chain<parameter::empty, 
                                    wrap::fix<1, pma15_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain152_t<NV>>, 
                                     chain154_t<NV>, 
                                     chain155_t<NV>>;

template <int NV> using converter6_mod = converter5_mod<NV>;

template <int NV>
using converter6_t = control::converter<converter6_mod<NV>, 
                                        conversion_logic::ms2freq>;
template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<converter6_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV> using converter1_t = converter_t<NV>;
template <int NV>
using minmax3_t = control::minmax<NV, 
                                  parameter::plain<converter1_t<NV>, 0>>;
template <int NV>
using peak1_mod_0 = parameter::from0To1<tempo_sync1_t<NV>, 
                                        0, 
                                        peak_mod_1Range>;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   peak1_mod_0<NV>, 
                                   parameter::plain<minmax3_t<NV>, 0>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain151_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch12_t<NV>>, 
                                    core::smoother<NV>, 
                                    peak1_t<NV>>;

template <int NV>
using modchain5_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank5_t<NV>>, 
                                      split8_t<NV>, 
                                      peak5_t<NV>, 
                                      math::clear<NV>, 
                                      chain151_t<NV>>;

template <int NV>
using modchain5_t = wrap::control_rate<modchain5_t_<NV>>;

template <int NV> using sliderbank4_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank4_multimod = parameter::list<sliderbank4_c0<NV>, 
                                             sliderbank4_c1<NV>, 
                                             sliderbank4_c2<NV>, 
                                             sliderbank4_c3<NV>, 
                                             sliderbank4_c4<NV>, 
                                             sliderbank4_c5<NV>, 
                                             sliderbank4_c6<NV>, 
                                             sliderbank4_c7<NV>>;

template <int NV>
using sliderbank4_t = wrap::data<control::sliderbank<sliderbank4_multimod<NV>>, 
                                 data::external::sliderpack<2>>;
using global_cable4_t_index = global_cable3_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable12_t_index = global_cable11_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable13_t_index = global_cable10_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable25_t_index = global_cable14_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using chain51_t = chain44_t<NV>;

template <int NV> using chain52_t = chain44_t<NV>;
template <int NV> using branch19_t = branch15_t<NV>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch19_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc3_t = midi_cc10_t<NV>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, midi_cc3_t<NV>>, 
                                 math::add<NV>>;

template <int NV> using midi_cc5_t = midi_cc10_t<NV>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc5_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi_cc7_t = midi_cc10_t<NV>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc7_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi_cc8_t = midi_cc10_t<NV>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc8_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi1_t = midi6_t<NV>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi1_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi3_t = midi7_t<NV>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi3_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi5_t = midi8_t<NV>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi5_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain_t<NV>>, 
                                    chain4_t<NV>, 
                                    chain5_t<NV>, 
                                    chain6_t<NV>, 
                                    chain7_t<NV>, 
                                    chain9_t<NV>, 
                                    chain11_t<NV>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain47_t<NV>>, 
                                  chain48_t<NV>, 
                                  chain49_t<NV>, 
                                  chain50_t<NV>, 
                                  chain51_t<NV>, 
                                  chain52_t<NV>, 
                                  chain53_t<NV>, 
                                  chain54_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma2_modRange, 
                             -100., 
                             0., 
                             0.1);

template <int NV>
using pma2_mod = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     pma2_modRange>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank4_t<NV>>, 
                                      split4_t<NV>, 
                                      peak4_t<NV>, 
                                      pma2_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV> using sliderbank6_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c7 = sliderbank3_c0<NV>;

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
                                 data::external::sliderpack<3>>;
using global_cable6_t_index = global_cable3_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable16_t_index = global_cable11_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable17_t_index = global_cable10_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable26_t_index = global_cable14_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using chain67_t = chain44_t<NV>;

template <int NV> using chain68_t = chain44_t<NV>;
template <int NV> using branch20_t = branch15_t<NV>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch20_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

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
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain63_t<NV>>, 
                                  chain64_t<NV>, 
                                  chain65_t<NV>, 
                                  chain66_t<NV>, 
                                  chain67_t<NV>, 
                                  chain68_t<NV>, 
                                  chain69_t<NV>, 
                                  chain70_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma4_modRange, 
                             -100., 
                             24., 
                             5.42227);

template <int NV>
using pma4_mod = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     pma4_modRange>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma4_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank6_t<NV>>, 
                                      split6_t<NV>, 
                                      peak6_t<NV>, 
                                      pma4_t<NV>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

template <int NV> using sliderbank7_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank7_multimod = parameter::list<sliderbank7_c0<NV>, 
                                             sliderbank7_c1<NV>, 
                                             sliderbank7_c2<NV>, 
                                             sliderbank7_c3<NV>, 
                                             sliderbank7_c4<NV>, 
                                             sliderbank7_c5<NV>, 
                                             sliderbank7_c6<NV>, 
                                             sliderbank7_c7<NV>>;

template <int NV>
using sliderbank7_t = wrap::data<control::sliderbank<sliderbank7_multimod<NV>>, 
                                 data::external::sliderpack<4>>;
using global_cable7_t_index = global_cable3_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable24_t_index = global_cable11_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable27_t_index = global_cable10_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain153_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable27_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable30_t_index = global_cable14_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain156_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable30_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain157_t = chain44_t<NV>;

template <int NV> using chain158_t = chain44_t<NV>;
template <int NV> using branch24_t = branch15_t<NV>;

template <int NV>
using chain159_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch24_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc4_t = midi_cc10_t<NV>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc4_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc6_t = midi_cc10_t<NV>;

template <int NV>
using chain166_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc6_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc9_t = midi_cc10_t<NV>;

template <int NV>
using chain167_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc9_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc30_t = midi_cc10_t<NV>;

template <int NV>
using chain169_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc30_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi2_t = midi6_t<NV>;

template <int NV>
using chain171_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi2_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi21_t = midi7_t<NV>;

template <int NV>
using chain172_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi21_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi22_t = midi8_t<NV>;

template <int NV>
using chain173_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi22_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch25_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain38_t<NV>>, 
                                     chain166_t<NV>, 
                                     chain167_t<NV>, 
                                     chain169_t<NV>, 
                                     chain171_t<NV>, 
                                     chain172_t<NV>, 
                                     chain173_t<NV>>;

template <int NV>
using chain160_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch25_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain89_t<NV>>, 
                                   chain90_t<NV>, 
                                   chain153_t<NV>, 
                                   chain156_t<NV>, 
                                   chain157_t<NV>, 
                                   chain158_t<NV>, 
                                   chain159_t<NV>, 
                                   chain160_t<NV>>;

template <int NV> using pma5_mod = pma2_mod<NV>;

template <int NV>
using pma5_t = control::pma<NV, pma5_mod<NV>>;
template <int NV>
using peak11_t = wrap::mod<parameter::plain<pma5_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain9_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank7_t<NV>>, 
                                      split15_t<NV>, 
                                      peak11_t<NV>, 
                                      pma5_t<NV>>;

template <int NV>
using modchain9_t = wrap::control_rate<modchain9_t_<NV>>;

template <int NV> using sliderbank12_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c7 = sliderbank3_c0<NV>;

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
                                  data::external::sliderpack<5>>;
using global_cable39_t_index = global_cable3_t_index;

template <int NV>
using global_cable39_t = routing::global_cable<global_cable39_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain215_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable39_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable40_t_index = global_cable11_t_index;

template <int NV>
using global_cable40_t = routing::global_cable<global_cable40_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain216_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable40_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable41_t_index = global_cable10_t_index;

template <int NV>
using global_cable41_t = routing::global_cable<global_cable41_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain217_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable41_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable42_t_index = global_cable14_t_index;

template <int NV>
using global_cable42_t = routing::global_cable<global_cable42_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain218_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable42_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain219_t = chain44_t<NV>;

template <int NV> using chain220_t = chain44_t<NV>;
template <int NV> using branch49_t = branch15_t<NV>;

template <int NV>
using chain221_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch49_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

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
using split26_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain215_t<NV>>, 
                                   chain216_t<NV>, 
                                   chain217_t<NV>, 
                                   chain218_t<NV>, 
                                   chain219_t<NV>, 
                                   chain220_t<NV>, 
                                   chain221_t<NV>, 
                                   chain222_t<NV>>;

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

template <int NV> using xfader3_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader3_c1 = sliderbank3_c0<NV>;

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

template <int NV> using pma6_mod_2 = pma6_mod_1<NV>;

template <int NV> using pma6_mod_3 = pma6_mod_1<NV>;

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
                             -6., 
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

template <int NV> using sliderbank11_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank11_multimod = parameter::list<sliderbank11_c0<NV>, 
                                              sliderbank11_c1<NV>, 
                                              sliderbank11_c2<NV>, 
                                              sliderbank11_c3<NV>, 
                                              sliderbank11_c4<NV>, 
                                              sliderbank11_c5<NV>, 
                                              sliderbank11_c6<NV>, 
                                              sliderbank11_c7<NV>>;

template <int NV>
using sliderbank11_t = wrap::data<control::sliderbank<sliderbank11_multimod<NV>>, 
                                  data::external::sliderpack<6>>;
using global_cable35_t_index = global_cable3_t_index;

template <int NV>
using global_cable35_t = routing::global_cable<global_cable35_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain200_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable35_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable36_t_index = global_cable11_t_index;

template <int NV>
using global_cable36_t = routing::global_cable<global_cable36_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain201_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable36_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable37_t_index = global_cable10_t_index;

template <int NV>
using global_cable37_t = routing::global_cable<global_cable37_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain202_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable37_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable38_t_index = global_cable14_t_index;

template <int NV>
using global_cable38_t = routing::global_cable<global_cable38_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain203_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable38_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain204_t = chain44_t<NV>;

template <int NV> using chain205_t = chain44_t<NV>;
template <int NV> using branch47_t = branch15_t<NV>;

template <int NV>
using chain206_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch47_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc35_t = midi_cc10_t<NV>;

template <int NV>
using chain208_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc35_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc36_t = midi_cc10_t<NV>;

template <int NV>
using chain209_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc36_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc37_t = midi_cc10_t<NV>;

template <int NV>
using chain210_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc37_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc38_t = midi_cc10_t<NV>;

template <int NV>
using chain211_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc38_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi26_t = midi6_t<NV>;

template <int NV>
using chain212_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi26_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi27_t = midi7_t<NV>;

template <int NV>
using chain213_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi27_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi28_t = midi8_t<NV>;

template <int NV>
using chain214_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi28_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch48_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain208_t<NV>>, 
                                     chain209_t<NV>, 
                                     chain210_t<NV>, 
                                     chain211_t<NV>, 
                                     chain212_t<NV>, 
                                     chain213_t<NV>, 
                                     chain214_t<NV>>;

template <int NV>
using chain207_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch48_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split24_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain200_t<NV>>, 
                                   chain201_t<NV>, 
                                   chain202_t<NV>, 
                                   chain203_t<NV>, 
                                   chain204_t<NV>, 
                                   chain205_t<NV>, 
                                   chain206_t<NV>, 
                                   chain207_t<NV>>;

namespace custom
{

struct expr11
{
	static float op(float input, float value)
	{
		return (1.0 - value) * input + value * Math.tan(Math.PI * 4.0 * value * input);
		;
	}
};
}

template <int NV> using xfader4_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader4_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader4_multimod = parameter::list<xfader4_c0<NV>, xfader4_c1<NV>>;

template <int NV>
using xfader4_t = control::xfader<xfader4_multimod<NV>, faders::linear>;
template <int NV> using pma7_mod_0 = pma6_mod_0<NV>;

template <int NV> using pma7_mod_1 = pma6_mod_1<NV>;

template <int NV> using pma7_mod_2 = pma6_mod_1<NV>;

template <int NV> using pma7_mod_3 = pma6_mod_1<NV>;

template <int NV>
using pma7_mod_4 = parameter::from0To1<math::expr<NV, custom::expr11>, 
                                       0, 
                                       pma6_mod_4Range>;

template <int NV> using pma7_mod_5 = pma6_mod_5<NV>;

template <int NV> using pma7_mod_7 = pma6_mod_1<NV>;

template <int NV> using pma7_mod_8 = pma6_mod_8<NV>;

template <int NV>
using pma7_mod = parameter::chain<ranges::Identity, 
                                  pma7_mod_0<NV>, 
                                  pma7_mod_1<NV>, 
                                  pma7_mod_2<NV>, 
                                  pma7_mod_3<NV>, 
                                  pma7_mod_4<NV>, 
                                  pma7_mod_5<NV>, 
                                  parameter::plain<xfader4_t<NV>, 0>, 
                                  pma7_mod_7<NV>, 
                                  pma7_mod_8<NV>>;

template <int NV>
using pma7_t = control::pma<NV, pma7_mod<NV>>;
template <int NV>
using pma9_t = control::pma<NV, 
                            parameter::plain<pma7_t<NV>, 2>>;
template <int NV>
using peak13_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain11_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank11_t<NV>>, 
                                       split24_t<NV>, 
                                       peak13_t<NV>, 
                                       pma9_t<NV>>;

template <int NV>
using modchain11_t = wrap::control_rate<modchain11_t_<NV>>;

template <int NV> using sliderbank14_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank14_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank14_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank14_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank14_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank14_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank14_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank14_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank14_multimod = parameter::list<sliderbank14_c0<NV>, 
                                              sliderbank14_c1<NV>, 
                                              sliderbank14_c2<NV>, 
                                              sliderbank14_c3<NV>, 
                                              sliderbank14_c4<NV>, 
                                              sliderbank14_c5<NV>, 
                                              sliderbank14_c6<NV>, 
                                              sliderbank14_c7<NV>>;

template <int NV>
using sliderbank14_t = wrap::data<control::sliderbank<sliderbank14_multimod<NV>>, 
                                  data::external::sliderpack<8>>;
using global_cable47_t_index = global_cable3_t_index;

template <int NV>
using global_cable47_t = routing::global_cable<global_cable47_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain245_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable47_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable48_t_index = global_cable11_t_index;

template <int NV>
using global_cable48_t = routing::global_cable<global_cable48_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain246_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable48_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable49_t_index = global_cable10_t_index;

template <int NV>
using global_cable49_t = routing::global_cable<global_cable49_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain259_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable49_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable50_t_index = global_cable14_t_index;

template <int NV>
using global_cable50_t = routing::global_cable<global_cable50_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain260_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable50_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain264_t = chain44_t<NV>;

template <int NV> using chain265_t = chain44_t<NV>;
template <int NV> using branch53_t = branch15_t<NV>;

template <int NV>
using chain266_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch53_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc47_t = midi_cc10_t<NV>;

template <int NV>
using chain268_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc47_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc48_t = midi_cc10_t<NV>;

template <int NV>
using chain269_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc48_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc49_t = midi_cc10_t<NV>;

template <int NV>
using chain270_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc49_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc50_t = midi_cc10_t<NV>;

template <int NV>
using chain271_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc50_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi35_t = midi6_t<NV>;

template <int NV>
using chain272_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi35_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi36_t = midi7_t<NV>;

template <int NV>
using chain273_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi36_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi37_t = midi8_t<NV>;

template <int NV>
using chain274_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi37_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch54_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain268_t<NV>>, 
                                     chain269_t<NV>, 
                                     chain270_t<NV>, 
                                     chain271_t<NV>, 
                                     chain272_t<NV>, 
                                     chain273_t<NV>, 
                                     chain274_t<NV>>;

template <int NV>
using chain267_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch54_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split28_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain245_t<NV>>, 
                                   chain246_t<NV>, 
                                   chain259_t<NV>, 
                                   chain260_t<NV>, 
                                   chain264_t<NV>, 
                                   chain265_t<NV>, 
                                   chain266_t<NV>, 
                                   chain267_t<NV>>;

template <int NV> using pma18_mod = pma2_mod<NV>;

template <int NV>
using pma18_t = control::pma<NV, pma18_mod<NV>>;
template <int NV>
using peak34_t = wrap::mod<parameter::plain<pma18_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain14_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank14_t<NV>>, 
                                       split28_t<NV>, 
                                       peak34_t<NV>, 
                                       pma18_t<NV>>;

template <int NV>
using modchain14_t = wrap::control_rate<modchain14_t_<NV>>;

template <int NV> using sliderbank15_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank15_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank15_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank15_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank15_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank15_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank15_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank15_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank15_multimod = parameter::list<sliderbank15_c0<NV>, 
                                              sliderbank15_c1<NV>, 
                                              sliderbank15_c2<NV>, 
                                              sliderbank15_c3<NV>, 
                                              sliderbank15_c4<NV>, 
                                              sliderbank15_c5<NV>, 
                                              sliderbank15_c6<NV>, 
                                              sliderbank15_c7<NV>>;

template <int NV>
using sliderbank15_t = wrap::data<control::sliderbank<sliderbank15_multimod<NV>>, 
                                  data::external::sliderpack<9>>;
using global_cable51_t_index = global_cable3_t_index;

template <int NV>
using global_cable51_t = routing::global_cable<global_cable51_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain275_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable51_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable52_t_index = global_cable11_t_index;

template <int NV>
using global_cable52_t = routing::global_cable<global_cable52_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain276_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable52_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable53_t_index = global_cable10_t_index;

template <int NV>
using global_cable53_t = routing::global_cable<global_cable53_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain277_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable53_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable54_t_index = global_cable14_t_index;

template <int NV>
using global_cable54_t = routing::global_cable<global_cable54_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain278_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable54_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain279_t = chain44_t<NV>;

template <int NV> using chain280_t = chain44_t<NV>;
template <int NV> using branch55_t = branch15_t<NV>;

template <int NV>
using chain281_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch55_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc51_t = midi_cc10_t<NV>;

template <int NV>
using chain283_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc51_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc52_t = midi_cc10_t<NV>;

template <int NV>
using chain284_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc52_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc53_t = midi_cc10_t<NV>;

template <int NV>
using chain285_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc53_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc54_t = midi_cc10_t<NV>;

template <int NV>
using chain286_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc54_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi38_t = midi6_t<NV>;

template <int NV>
using chain287_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi38_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi39_t = midi7_t<NV>;

template <int NV>
using chain288_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi39_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi40_t = midi8_t<NV>;

template <int NV>
using chain289_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi40_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch56_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain283_t<NV>>, 
                                     chain284_t<NV>, 
                                     chain285_t<NV>, 
                                     chain286_t<NV>, 
                                     chain287_t<NV>, 
                                     chain288_t<NV>, 
                                     chain289_t<NV>>;

template <int NV>
using chain282_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch56_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split29_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain275_t<NV>>, 
                                   chain276_t<NV>, 
                                   chain277_t<NV>, 
                                   chain278_t<NV>, 
                                   chain279_t<NV>, 
                                   chain280_t<NV>, 
                                   chain281_t<NV>, 
                                   chain282_t<NV>>;

template <int NV> using xfader1_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader1_c1 = sliderbank3_c0<NV>;

template <int NV> using xfader1_c2 = sliderbank3_c0<NV>;

template <int NV> using xfader1_c3 = sliderbank3_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, 
                                         xfader1_c1<NV>, 
                                         xfader1_c2<NV>, 
                                         xfader1_c3<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV> using xfader5_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader5_c1 = sliderbank3_c0<NV>;

template <int NV> using xfader5_c2 = sliderbank3_c0<NV>;

template <int NV> using xfader5_c3 = sliderbank3_c0<NV>;

template <int NV>
using xfader5_multimod = parameter::list<xfader5_c0<NV>, 
                                         xfader5_c1<NV>, 
                                         xfader5_c2<NV>, 
                                         xfader5_c3<NV>>;

template <int NV>
using xfader5_t = control::xfader<xfader5_multimod<NV>, faders::rms>;

template <int NV> using xfader6_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader6_c1 = sliderbank3_c0<NV>;

template <int NV> using xfader6_c2 = sliderbank3_c0<NV>;

template <int NV> using xfader6_c3 = sliderbank3_c0<NV>;

template <int NV>
using xfader6_multimod = parameter::list<xfader6_c0<NV>, 
                                         xfader6_c1<NV>, 
                                         xfader6_c2<NV>, 
                                         xfader6_c3<NV>>;

template <int NV>
using xfader6_t = control::xfader<xfader6_multimod<NV>, faders::switcher>;

template <int NV>
using pma19_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<xfader1_t<NV>, 0>, 
                                   parameter::plain<xfader5_t<NV>, 0>, 
                                   parameter::plain<xfader6_t<NV>, 0>>;

template <int NV>
using pma19_t = control::pma<NV, pma19_mod<NV>>;
template <int NV>
using peak35_t = wrap::mod<parameter::plain<pma19_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain15_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank15_t<NV>>, 
                                       split29_t<NV>, 
                                       peak35_t<NV>, 
                                       pma19_t<NV>>;

template <int NV>
using modchain15_t = wrap::control_rate<modchain15_t_<NV>>;

template <int NV> using sliderbank16_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank16_multimod = parameter::list<sliderbank16_c0<NV>, 
                                              sliderbank16_c1<NV>, 
                                              sliderbank16_c2<NV>, 
                                              sliderbank16_c3<NV>, 
                                              sliderbank16_c4<NV>, 
                                              sliderbank16_c5<NV>, 
                                              sliderbank16_c6<NV>, 
                                              sliderbank16_c7<NV>>;

template <int NV>
using sliderbank16_t = wrap::data<control::sliderbank<sliderbank16_multimod<NV>>, 
                                  data::external::sliderpack<10>>;
using global_cable55_t_index = global_cable3_t_index;

template <int NV>
using global_cable55_t = routing::global_cable<global_cable55_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain290_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable55_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable56_t_index = global_cable11_t_index;

template <int NV>
using global_cable56_t = routing::global_cable<global_cable56_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain291_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable56_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable57_t_index = global_cable10_t_index;

template <int NV>
using global_cable57_t = routing::global_cable<global_cable57_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain292_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable57_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable58_t_index = global_cable14_t_index;

template <int NV>
using global_cable58_t = routing::global_cable<global_cable58_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain293_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable58_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain294_t = chain44_t<NV>;

template <int NV> using chain295_t = chain44_t<NV>;
template <int NV> using branch57_t = branch15_t<NV>;

template <int NV>
using chain296_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch57_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc55_t = midi_cc10_t<NV>;

template <int NV>
using chain298_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc55_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc56_t = midi_cc10_t<NV>;

template <int NV>
using chain299_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc56_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc57_t = midi_cc10_t<NV>;

template <int NV>
using chain426_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc57_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc58_t = midi_cc10_t<NV>;

template <int NV>
using chain451_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc58_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi41_t = midi6_t<NV>;

template <int NV>
using chain452_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi41_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi43_t = midi7_t<NV>;

template <int NV>
using chain453_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi43_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi44_t = midi8_t<NV>;

template <int NV>
using chain454_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi44_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch58_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain298_t<NV>>, 
                                     chain299_t<NV>, 
                                     chain426_t<NV>, 
                                     chain451_t<NV>, 
                                     chain452_t<NV>, 
                                     chain453_t<NV>, 
                                     chain454_t<NV>>;

template <int NV>
using chain297_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch58_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split33_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain290_t<NV>>, 
                                   chain291_t<NV>, 
                                   chain292_t<NV>, 
                                   chain293_t<NV>, 
                                   chain294_t<NV>, 
                                   chain295_t<NV>, 
                                   chain296_t<NV>, 
                                   chain297_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma20_mod_0Range, 
                             -24., 
                             24., 
                             0.1);

template <int NV>
using pma20_mod_0 = parameter::from0To1<project::shfiter<NV>, 
                                        0, 
                                        pma20_mod_0Range>;

template <int NV> using pma20_mod_1 = pma20_mod_0<NV>;

template <int NV>
using pma20_mod = parameter::chain<ranges::Identity, 
                                   pma20_mod_0<NV>, 
                                   pma20_mod_1<NV>>;

template <int NV>
using pma20_t = control::pma<NV, pma20_mod<NV>>;
template <int NV>
using peak36_t = wrap::mod<parameter::plain<pma20_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain17_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank16_t<NV>>, 
                                       split33_t<NV>, 
                                       peak36_t<NV>, 
                                       pma20_t<NV>>;

template <int NV>
using modchain17_t = wrap::control_rate<modchain17_t_<NV>>;

template <int NV> using sliderbank17_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank17_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank17_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank17_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank17_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank17_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank17_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank17_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank17_multimod = parameter::list<sliderbank17_c0<NV>, 
                                              sliderbank17_c1<NV>, 
                                              sliderbank17_c2<NV>, 
                                              sliderbank17_c3<NV>, 
                                              sliderbank17_c4<NV>, 
                                              sliderbank17_c5<NV>, 
                                              sliderbank17_c6<NV>, 
                                              sliderbank17_c7<NV>>;

template <int NV>
using sliderbank17_t = wrap::data<control::sliderbank<sliderbank17_multimod<NV>>, 
                                  data::external::sliderpack<11>>;
using global_cable59_t_index = global_cable3_t_index;

template <int NV>
using global_cable59_t = routing::global_cable<global_cable59_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain300_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable59_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable60_t_index = global_cable11_t_index;

template <int NV>
using global_cable60_t = routing::global_cable<global_cable60_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain301_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable60_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable61_t_index = global_cable10_t_index;

template <int NV>
using global_cable61_t = routing::global_cable<global_cable61_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain302_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable61_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable62_t_index = global_cable14_t_index;

template <int NV>
using global_cable62_t = routing::global_cable<global_cable62_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain303_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable62_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain304_t = chain44_t<NV>;

template <int NV> using chain305_t = chain44_t<NV>;
template <int NV> using branch59_t = branch15_t<NV>;

template <int NV>
using chain306_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch59_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc59_t = midi_cc10_t<NV>;

template <int NV>
using chain308_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc59_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc60_t = midi_cc10_t<NV>;

template <int NV>
using chain309_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc60_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc61_t = midi_cc10_t<NV>;

template <int NV>
using chain427_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc61_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc62_t = midi_cc10_t<NV>;

template <int NV>
using chain455_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc62_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi45_t = midi6_t<NV>;

template <int NV>
using chain456_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi45_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi46_t = midi7_t<NV>;

template <int NV>
using chain457_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi46_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi47_t = midi8_t<NV>;

template <int NV>
using chain458_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi47_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch60_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain308_t<NV>>, 
                                     chain309_t<NV>, 
                                     chain427_t<NV>, 
                                     chain455_t<NV>, 
                                     chain456_t<NV>, 
                                     chain457_t<NV>, 
                                     chain458_t<NV>>;

template <int NV>
using chain307_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch60_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split34_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain300_t<NV>>, 
                                   chain301_t<NV>, 
                                   chain302_t<NV>, 
                                   chain303_t<NV>, 
                                   chain304_t<NV>, 
                                   chain305_t<NV>, 
                                   chain306_t<NV>, 
                                   chain307_t<NV>>;

template <int NV>
using pma_unscaled_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<project::ps2<NV>, 2>, 
                                          parameter::plain<project::ps2<NV>, 1>, 
                                          parameter::plain<project::shfiter<NV>, 1>, 
                                          parameter::plain<project::shfiter<NV>, 2>, 
                                          parameter::plain<project::shfiter<NV>, 1>, 
                                          parameter::plain<project::shfiter<NV>, 2>>;

template <int NV>
using pma_unscaled_t = control::pma_unscaled<NV, pma_unscaled_mod<NV>>;
template <int NV>
using peak_unscaled_t = wrap::mod<parameter::plain<pma_unscaled_t<NV>, 0>, 
                                  wrap::no_data<core::peak_unscaled>>;
using peak37_t = wrap::no_data<wrap::no_process<core::peak>>;

template <int NV>
using modchain18_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank17_t<NV>>, 
                                       split34_t<NV>, 
                                       peak_unscaled_t<NV>, 
                                       peak37_t, 
                                       pma_unscaled_t<NV>>;

template <int NV>
using modchain18_t = wrap::control_rate<modchain18_t_<NV>>;

template <int NV> using sliderbank18_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank18_multimod = parameter::list<sliderbank18_c0<NV>, 
                                              sliderbank18_c1<NV>, 
                                              sliderbank18_c2<NV>, 
                                              sliderbank18_c3<NV>, 
                                              sliderbank18_c4<NV>, 
                                              sliderbank18_c5<NV>, 
                                              sliderbank18_c6<NV>, 
                                              sliderbank18_c7<NV>>;

template <int NV>
using sliderbank18_t = wrap::data<control::sliderbank<sliderbank18_multimod<NV>>, 
                                  data::external::sliderpack<12>>;
using global_cable63_t_index = global_cable3_t_index;

template <int NV>
using global_cable63_t = routing::global_cable<global_cable63_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain310_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable63_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable64_t_index = global_cable11_t_index;

template <int NV>
using global_cable64_t = routing::global_cable<global_cable64_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain311_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable64_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable65_t_index = global_cable10_t_index;

template <int NV>
using global_cable65_t = routing::global_cable<global_cable65_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain312_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable65_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable66_t_index = global_cable14_t_index;

template <int NV>
using global_cable66_t = routing::global_cable<global_cable66_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain313_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable66_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain314_t = chain44_t<NV>;

template <int NV> using chain315_t = chain44_t<NV>;
template <int NV> using branch61_t = branch15_t<NV>;

template <int NV>
using chain316_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch61_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc63_t = midi_cc10_t<NV>;

template <int NV>
using chain318_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc63_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc64_t = midi_cc10_t<NV>;

template <int NV>
using chain319_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc64_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc65_t = midi_cc10_t<NV>;

template <int NV>
using chain428_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc65_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc66_t = midi_cc10_t<NV>;

template <int NV>
using chain459_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc66_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi48_t = midi6_t<NV>;

template <int NV>
using chain460_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi48_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi49_t = midi7_t<NV>;

template <int NV>
using chain461_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi49_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi50_t = midi8_t<NV>;

template <int NV>
using chain462_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi50_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch62_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain318_t<NV>>, 
                                     chain319_t<NV>, 
                                     chain428_t<NV>, 
                                     chain459_t<NV>, 
                                     chain460_t<NV>, 
                                     chain461_t<NV>, 
                                     chain462_t<NV>>;

template <int NV>
using chain317_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch62_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split35_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain310_t<NV>>, 
                                   chain311_t<NV>, 
                                   chain312_t<NV>, 
                                   chain313_t<NV>, 
                                   chain314_t<NV>, 
                                   chain315_t<NV>, 
                                   chain316_t<NV>, 
                                   chain317_t<NV>>;

template <int NV> using xfader_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
template <int NV>
using pma22_t = control::pma<NV, 
                             parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak38_t = wrap::mod<parameter::plain<pma22_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain19_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank18_t<NV>>, 
                                       split35_t<NV>, 
                                       peak38_t<NV>, 
                                       pma22_t<NV>>;

template <int NV>
using modchain19_t = wrap::control_rate<modchain19_t_<NV>>;

template <int NV> using sliderbank19_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank19_multimod = parameter::list<sliderbank19_c0<NV>, 
                                              sliderbank19_c1<NV>, 
                                              sliderbank19_c2<NV>, 
                                              sliderbank19_c3<NV>, 
                                              sliderbank19_c4<NV>, 
                                              sliderbank19_c5<NV>, 
                                              sliderbank19_c6<NV>, 
                                              sliderbank19_c7<NV>>;

template <int NV>
using sliderbank19_t = wrap::data<control::sliderbank<sliderbank19_multimod<NV>>, 
                                  data::external::sliderpack<13>>;
using global_cable67_t_index = global_cable3_t_index;

template <int NV>
using global_cable67_t = routing::global_cable<global_cable67_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain320_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable67_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable68_t_index = global_cable11_t_index;

template <int NV>
using global_cable68_t = routing::global_cable<global_cable68_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain321_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable68_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable69_t_index = global_cable10_t_index;

template <int NV>
using global_cable69_t = routing::global_cable<global_cable69_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain322_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable69_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable70_t_index = global_cable14_t_index;

template <int NV>
using global_cable70_t = routing::global_cable<global_cable70_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain323_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable70_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain324_t = chain44_t<NV>;

template <int NV> using chain325_t = chain44_t<NV>;
template <int NV> using branch63_t = branch15_t<NV>;

template <int NV>
using chain326_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch63_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc67_t = midi_cc10_t<NV>;

template <int NV>
using chain328_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc67_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc68_t = midi_cc10_t<NV>;

template <int NV>
using chain329_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc68_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc69_t = midi_cc10_t<NV>;

template <int NV>
using chain429_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc69_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc70_t = midi_cc10_t<NV>;

template <int NV>
using chain463_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc70_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi51_t = midi6_t<NV>;

template <int NV>
using chain464_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi51_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi52_t = midi7_t<NV>;

template <int NV>
using chain465_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi52_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi53_t = midi8_t<NV>;

template <int NV>
using chain466_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi53_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch64_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain328_t<NV>>, 
                                     chain329_t<NV>, 
                                     chain429_t<NV>, 
                                     chain463_t<NV>, 
                                     chain464_t<NV>, 
                                     chain465_t<NV>, 
                                     chain466_t<NV>>;

template <int NV>
using chain327_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch64_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split36_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain320_t<NV>>, 
                                   chain321_t<NV>, 
                                   chain322_t<NV>, 
                                   chain323_t<NV>, 
                                   chain324_t<NV>, 
                                   chain325_t<NV>, 
                                   chain326_t<NV>, 
                                   chain327_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table3_modRange, 
                             0., 
                             100., 
                             0.01);

template <int NV>
using cable_table3_mod = parameter::from0To1<project::Comb<NV>, 
                                             1, 
                                             cable_table3_modRange>;

struct cable_table3_t_data
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
using cable_table3_t = wrap::data<control::cable_table<cable_table3_mod<NV>>, 
                                  data::embedded::table<cable_table3_t_data>>;

template <int NV> using cable_table_mod = cable_table3_mod<NV>;

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
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;

template <int NV>
using pma23_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<cable_table3_t<NV>, 0>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<cable_table_t<NV>, 0>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::khp<NV>, 1>>;

template <int NV>
using pma23_t = control::pma<NV, pma23_mod<NV>>;
template <int NV>
using peak39_t = wrap::mod<parameter::plain<pma23_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain20_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank19_t<NV>>, 
                                       split36_t<NV>, 
                                       peak39_t<NV>, 
                                       pma23_t<NV>>;

template <int NV>
using modchain20_t = wrap::control_rate<modchain20_t_<NV>>;

template <int NV> using sliderbank20_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank20_multimod = parameter::list<sliderbank20_c0<NV>, 
                                              sliderbank20_c1<NV>, 
                                              sliderbank20_c2<NV>, 
                                              sliderbank20_c3<NV>, 
                                              sliderbank20_c4<NV>, 
                                              sliderbank20_c5<NV>, 
                                              sliderbank20_c6<NV>, 
                                              sliderbank20_c7<NV>>;

template <int NV>
using sliderbank20_t = wrap::data<control::sliderbank<sliderbank20_multimod<NV>>, 
                                  data::external::sliderpack<14>>;
using global_cable71_t_index = global_cable3_t_index;

template <int NV>
using global_cable71_t = routing::global_cable<global_cable71_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain330_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable71_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable72_t_index = global_cable11_t_index;

template <int NV>
using global_cable72_t = routing::global_cable<global_cable72_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain331_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable72_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable73_t_index = global_cable10_t_index;

template <int NV>
using global_cable73_t = routing::global_cable<global_cable73_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain332_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable73_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable74_t_index = global_cable14_t_index;

template <int NV>
using global_cable74_t = routing::global_cable<global_cable74_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain333_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable74_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain334_t = chain44_t<NV>;

template <int NV> using chain335_t = chain44_t<NV>;
template <int NV> using branch65_t = branch15_t<NV>;

template <int NV>
using chain336_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch65_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc71_t = midi_cc10_t<NV>;

template <int NV>
using chain338_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc71_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc72_t = midi_cc10_t<NV>;

template <int NV>
using chain339_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc72_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc73_t = midi_cc10_t<NV>;

template <int NV>
using chain430_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc73_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc74_t = midi_cc10_t<NV>;

template <int NV>
using chain467_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc74_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi54_t = midi6_t<NV>;

template <int NV>
using chain468_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi54_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi55_t = midi7_t<NV>;

template <int NV>
using chain469_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi55_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi56_t = midi8_t<NV>;

template <int NV>
using chain470_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi56_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch66_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain338_t<NV>>, 
                                     chain339_t<NV>, 
                                     chain430_t<NV>, 
                                     chain467_t<NV>, 
                                     chain468_t<NV>, 
                                     chain469_t<NV>, 
                                     chain470_t<NV>>;

template <int NV>
using chain337_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch66_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split37_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain330_t<NV>>, 
                                   chain331_t<NV>, 
                                   chain332_t<NV>, 
                                   chain333_t<NV>, 
                                   chain334_t<NV>, 
                                   chain335_t<NV>, 
                                   chain336_t<NV>, 
                                   chain337_t<NV>>;

template <int NV> using cable_table4_mod = cable_table3_mod<NV>;

struct cable_table4_t_data
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
using cable_table4_t = wrap::data<control::cable_table<cable_table4_mod<NV>>, 
                                  data::embedded::table<cable_table4_t_data>>;

template <int NV> using cable_table2_mod = cable_table3_mod<NV>;

struct cable_table2_t_data
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
using cable_table2_t = wrap::data<control::cable_table<cable_table2_mod<NV>>, 
                                  data::embedded::table<cable_table2_t_data>>;

template <int NV>
using pma24_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table4_t<NV>, 0>, 
                                   parameter::plain<project::khp<NV>, 1>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<cable_table2_t<NV>, 0>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::khp2<NV>, 1>, 
                                   parameter::plain<project::khp2<NV>, 1>>;

template <int NV>
using pma24_t = control::pma<NV, pma24_mod<NV>>;
template <int NV>
using peak40_t = wrap::mod<parameter::plain<pma24_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain21_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank20_t<NV>>, 
                                       split37_t<NV>, 
                                       peak40_t<NV>, 
                                       pma24_t<NV>>;

template <int NV>
using modchain21_t = wrap::control_rate<modchain21_t_<NV>>;

template <int NV> using sliderbank21_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank21_multimod = parameter::list<sliderbank21_c0<NV>, 
                                              sliderbank21_c1<NV>, 
                                              sliderbank21_c2<NV>, 
                                              sliderbank21_c3<NV>, 
                                              sliderbank21_c4<NV>, 
                                              sliderbank21_c5<NV>, 
                                              sliderbank21_c6<NV>, 
                                              sliderbank21_c7<NV>>;

template <int NV>
using sliderbank21_t = wrap::data<control::sliderbank<sliderbank21_multimod<NV>>, 
                                  data::external::sliderpack<15>>;
using global_cable75_t_index = global_cable3_t_index;

template <int NV>
using global_cable75_t = routing::global_cable<global_cable75_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain340_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable75_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable76_t_index = global_cable11_t_index;

template <int NV>
using global_cable76_t = routing::global_cable<global_cable76_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain341_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable76_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable77_t_index = global_cable10_t_index;

template <int NV>
using global_cable77_t = routing::global_cable<global_cable77_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain342_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable77_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable78_t_index = global_cable14_t_index;

template <int NV>
using global_cable78_t = routing::global_cable<global_cable78_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain343_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable78_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain344_t = chain44_t<NV>;

template <int NV> using chain345_t = chain44_t<NV>;
template <int NV> using branch67_t = branch15_t<NV>;

template <int NV>
using chain346_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch67_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc75_t = midi_cc10_t<NV>;

template <int NV>
using chain348_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc75_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc76_t = midi_cc10_t<NV>;

template <int NV>
using chain349_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc76_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc77_t = midi_cc10_t<NV>;

template <int NV>
using chain431_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc77_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc78_t = midi_cc10_t<NV>;

template <int NV>
using chain471_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc78_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi57_t = midi6_t<NV>;

template <int NV>
using chain472_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi57_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi58_t = midi7_t<NV>;

template <int NV>
using chain473_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi58_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi59_t = midi8_t<NV>;

template <int NV>
using chain474_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi59_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch68_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain348_t<NV>>, 
                                     chain349_t<NV>, 
                                     chain431_t<NV>, 
                                     chain471_t<NV>, 
                                     chain472_t<NV>, 
                                     chain473_t<NV>, 
                                     chain474_t<NV>>;

template <int NV>
using chain347_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch68_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split38_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain340_t<NV>>, 
                                   chain341_t<NV>, 
                                   chain342_t<NV>, 
                                   chain343_t<NV>, 
                                   chain344_t<NV>, 
                                   chain345_t<NV>, 
                                   chain346_t<NV>, 
                                   chain347_t<NV>>;

template <int NV> using pma25_mod = pma4_mod<NV>;

template <int NV>
using pma25_t = control::pma<NV, pma25_mod<NV>>;
template <int NV>
using peak41_t = wrap::mod<parameter::plain<pma25_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain22_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank21_t<NV>>, 
                                       split38_t<NV>, 
                                       peak41_t<NV>, 
                                       pma25_t<NV>>;

template <int NV>
using modchain22_t = wrap::control_rate<modchain22_t_<NV>>;

template <int NV> using sliderbank22_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank22_multimod = parameter::list<sliderbank22_c0<NV>, 
                                              sliderbank22_c1<NV>, 
                                              sliderbank22_c2<NV>, 
                                              sliderbank22_c3<NV>, 
                                              sliderbank22_c4<NV>, 
                                              sliderbank22_c5<NV>, 
                                              sliderbank22_c6<NV>, 
                                              sliderbank22_c7<NV>>;

template <int NV>
using sliderbank22_t = wrap::data<control::sliderbank<sliderbank22_multimod<NV>>, 
                                  data::external::sliderpack<16>>;
using global_cable79_t_index = global_cable3_t_index;

template <int NV>
using global_cable79_t = routing::global_cable<global_cable79_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain350_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable79_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable80_t_index = global_cable11_t_index;

template <int NV>
using global_cable80_t = routing::global_cable<global_cable80_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain351_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable80_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable81_t_index = global_cable10_t_index;

template <int NV>
using global_cable81_t = routing::global_cable<global_cable81_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain352_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable81_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable82_t_index = global_cable14_t_index;

template <int NV>
using global_cable82_t = routing::global_cable<global_cable82_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain353_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable82_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain354_t = chain44_t<NV>;

template <int NV> using chain355_t = chain44_t<NV>;
template <int NV> using branch69_t = branch15_t<NV>;

template <int NV>
using chain356_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch69_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc79_t = midi_cc10_t<NV>;

template <int NV>
using chain358_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc79_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc80_t = midi_cc10_t<NV>;

template <int NV>
using chain359_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc80_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc81_t = midi_cc10_t<NV>;

template <int NV>
using chain432_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc81_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc82_t = midi_cc10_t<NV>;

template <int NV>
using chain475_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc82_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi60_t = midi6_t<NV>;

template <int NV>
using chain476_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi60_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi61_t = midi7_t<NV>;

template <int NV>
using chain477_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi61_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi62_t = midi8_t<NV>;

template <int NV>
using chain478_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi62_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch70_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain358_t<NV>>, 
                                     chain359_t<NV>, 
                                     chain432_t<NV>, 
                                     chain475_t<NV>, 
                                     chain476_t<NV>, 
                                     chain477_t<NV>, 
                                     chain478_t<NV>>;

template <int NV>
using chain357_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch70_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split39_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain350_t<NV>>, 
                                   chain351_t<NV>, 
                                   chain352_t<NV>, 
                                   chain353_t<NV>, 
                                   chain354_t<NV>, 
                                   chain355_t<NV>, 
                                   chain356_t<NV>, 
                                   chain357_t<NV>>;

DECLARE_PARAMETER_RANGE(pma26_modRange, 
                        -1., 
                        1.);

template <int NV>
using pma26_mod = parameter::from0To1<jdsp::jpanner<NV>, 
                                      0, 
                                      pma26_modRange>;

template <int NV>
using pma26_t = control::pma<NV, pma26_mod<NV>>;
template <int NV>
using peak42_t = wrap::mod<parameter::plain<pma26_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain23_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank22_t<NV>>, 
                                       split39_t<NV>, 
                                       peak42_t<NV>, 
                                       pma26_t<NV>>;

template <int NV>
using modchain23_t = wrap::control_rate<modchain23_t_<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  modchain5_t<NV>, 
                                  modchain2_t<NV>, 
                                  modchain4_t<NV>, 
                                  modchain9_t<NV>, 
                                  modchain12_t<NV>, 
                                  modchain11_t<NV>, 
                                  modchain14_t<NV>, 
                                  modchain15_t<NV>, 
                                  modchain17_t<NV>, 
                                  modchain18_t<NV>, 
                                  modchain19_t<NV>, 
                                  modchain20_t<NV>, 
                                  modchain21_t<NV>, 
                                  modchain22_t<NV>, 
                                  modchain23_t<NV>>;
using stereo_cable = cable::block<2>;
using branch38_t = container::branch<parameter::empty, 
                                     wrap::fix<2, routing::receive<stereo_cable>>, 
                                     routing::receive<stereo_cable>, 
                                     routing::receive<stereo_cable>>;
using peak8_t = peak37_t;

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

template <int NV> using no_midi_t_ = chain1_t<NV>;

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
		return (1.0f - value) * input + value * Math.sin(Math.PI * 2.0 * value * input);;
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
                                   wrap::fix<2, math::clear<NV>>, 
                                   branch38_t, 
                                   peak8_t, 
                                   core::gain<NV>, 
                                   modchain_t<NV>, 
                                   branch1_t<NV>, 
                                   core::mono2stereo, 
                                   pma6_t<NV>, 
                                   branch2_t<NV>>;

using chain197_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::send<stereo_cable>>>;

template <int NV>
using peak17_mod = parameter::chain<ranges::Identity, 
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
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak17_t = wrap::mod<peak17_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain196_t = container::chain<parameter::empty, 
                                    wrap::fix<2, peak17_t<NV>>>;

template <int NV>
using split32_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain197_t>, 
                                   chain196_t<NV>>;

template <int NV>
using chain168_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split32_t<NV>>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain77_t<NV>>, 
                                   core::gain<NV>, 
                                   filters::one_pole<NV>, 
                                   core::gain<NV>, 
                                   chain168_t<NV>, 
                                   math::clear<NV>>;
using branch27_t = branch38_t;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax3_t<NV>>, 
                                   converter1_t<NV>>;

template <int NV>
using chain92_t = container::chain<parameter::empty, 
                                   wrap::fix<1, tempo_sync1_t<NV>>, 
                                   converter6_t<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain83_t<NV>>, 
                                  chain92_t<NV>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split5_t<NV>>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV> using chain93_t = chain1_t<NV>;

template <int NV> using chain95_t = chain1_t<NV>;

template <int NV> using no_midi1_t_ = chain1_t<NV>;

template <int NV>
using no_midi1_t = wrap::no_midi<no_midi1_t_<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain93_t<NV>>, 
                                    chain95_t<NV>, 
                                    no_midi1_t<NV>>;

template <int NV> using chain98_t = chain74_t<NV>;

template <int NV>
using chain97_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain98_t<NV>>, 
                                   core::gain<NV>>;
namespace custom
{

struct expr4
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 2.0 * value * input);;
	}
};
}

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr4>>, 
                                   core::gain<NV>>;

template <int NV>
using split18_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain97_t<NV>>, 
                                   chain99_t<NV>>;

template <int NV>
using chain96_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader4_t<NV>>, 
                                   split18_t<NV>>;

template <int NV> using chain100_t = chain76_t<NV>;
using oscilloscope2_t = wrap::no_data<analyse::oscilloscope>;

template <int NV>
using chain131_t = container::chain<parameter::empty, 
                                    wrap::fix<2, core::gain<NV>>, 
                                    math::fmod<NV>, 
                                    wrap::no_process<math::mul<NV>>, 
                                    math::pi<NV>, 
                                    oscilloscope2_t>;

template <int NV>
using chain132_t = container::chain<parameter::empty, 
                                    wrap::fix<2, core::gain<NV>>, 
                                    math::expr<NV, custom::expr11>, 
                                    math::sin<NV>>;
namespace custom
{

struct expr12
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

template <int NV>
using chain133_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::pi<NV>>, 
                                    wrap::no_process<math::sin<NV>>, 
                                    core::gain<NV>, 
                                    math::sin<NV>, 
                                    math::expr<NV, custom::expr12>>;
namespace custom
{

struct expr13
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

template <int NV>
using chain134_t = container::chain<parameter::empty, 
                                    wrap::fix<2, wrap::no_process<math::pi<NV>>>, 
                                    wrap::no_process<fx::phase_delay<NV>>, 
                                    core::gain<NV>, 
                                    math::expr<NV, custom::expr13>, 
                                    math::sin<NV>>;
using table6_t = table5_t;

template <int NV>
using chain135_t = container::chain<parameter::empty, 
                                    wrap::fix<2, core::gain<NV>>, 
                                    math::pi<NV>, 
                                    table6_t>;
template <int NV>
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain96_t<NV>>, 
                                     chain100_t<NV>, 
                                     chain131_t<NV>, 
                                     chain132_t<NV>, 
                                     chain133_t<NV>, 
                                     chain134_t<NV>, 
                                     chain135_t<NV>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   branch27_t, 
                                   core::gain<NV>, 
                                   modchain3_t<NV>, 
                                   branch7_t<NV>, 
                                   core::mono2stereo, 
                                   pma7_t<NV>, 
                                   branch10_t<NV>>;

template <int NV> using peak20_mod = peak17_mod<NV>;

template <int NV>
using peak20_t = wrap::mod<peak20_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain170_t = container::chain<parameter::empty, 
                                    wrap::fix<2, peak20_t<NV>>>;

template <int NV>
using chain86_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain82_t<NV>>, 
                                   filters::one_pole<NV>, 
                                   routing::send<stereo_cable>, 
                                   chain170_t<NV>, 
                                   core::gain<NV>, 
                                   core::gain<NV>, 
                                   math::clear<NV>>;

template <int NV>
using chain191_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<stereo_cable>>, 
                                    core::gain<NV>>;

template <int NV> using chain192_t = chain191_t<NV>;

template <int NV>
using split30_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain191_t<NV>>, 
                                   chain192_t<NV>>;

template <int NV>
using chain87_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split30_t<NV>>>;

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, tempo_sync2_t<NV>>, 
                                   ramp_t<NV>>;
template <int NV>
using clock_ramp_t = wrap::no_data<core::clock_ramp<NV, false>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<1, clock_ramp_t<NV>>>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain10_t<NV>>, 
                                     chain84_t<NV>>;

template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;
template <int NV>
using input_toggle_t = control::input_toggle<NV, 
                                             parameter::plain<ahdsr_t<NV>, 8>>;

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<5>>;

template <int NV>
using peak2_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<input_toggle_t<NV>, 2>, 
                                   parameter::plain<cable_table1_t<NV>, 0>>;

template <int NV>
using peak2_t = wrap::mod<peak2_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain91_t = container::chain<parameter::empty, 
                                   wrap::fix<1, input_toggle_t<NV>>, 
                                   ahdsr_t<NV>, 
                                   math::clear<NV>, 
                                   math::add<NV>>;

template <int NV>
using split22_t = container::split<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  cable_table1_t<NV>, 
                                  math::clear<NV>, 
                                  split22_t<NV>>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain91_t<NV>>, 
                                     chain3_t<NV>>;

template <int NV>
using peak7_mod = parameter::chain<ranges::Identity, 
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
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak7_t = wrap::mod<peak7_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch13_t<NV>>, 
                                   peak2_t<NV>, 
                                   math::clear<NV>, 
                                   branch14_t<NV>, 
                                   peak7_t<NV>>;

template <int NV> using ramp4_t = ramp_t<NV>;
template <int NV>
using tempo_sync5_t = wrap::mod<parameter::plain<ramp4_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain162_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync5_t<NV>>, 
                                    ramp4_t<NV>>;
template <int NV> using clock_ramp3_t = clock_ramp_t<NV>;

template <int NV>
using chain163_t = container::chain<parameter::empty, 
                                    wrap::fix<1, clock_ramp3_t<NV>>>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain162_t<NV>>, 
                                     chain163_t<NV>>;

template <int NV> using ahdsr6_multimod = ahdsr_multimod<NV>;

template <int NV>
using ahdsr6_t = wrap::no_data<envelope::ahdsr<NV, ahdsr6_multimod<NV>>>;
template <int NV>
using input_toggle2_t = control::input_toggle<NV, 
                                              parameter::plain<ahdsr6_t<NV>, 8>>;

template <int NV>
using cable_table8_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                  data::external::table<6>>;

template <int NV>
using peak14_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<input_toggle2_t<NV>, 2>, 
                                    parameter::plain<cable_table8_t<NV>, 0>>;

template <int NV>
using peak14_t = wrap::mod<peak14_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain164_t = container::chain<parameter::empty, 
                                    wrap::fix<1, input_toggle2_t<NV>>, 
                                    ahdsr6_t<NV>, 
                                    math::clear<NV>, 
                                    math::add<NV>>;

template <int NV> using split25_t = split22_t<NV>;

template <int NV>
using chain165_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    cable_table8_t<NV>, 
                                    math::clear<NV>, 
                                    split25_t<NV>>;
template <int NV>
using branch18_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain164_t<NV>>, 
                                     chain165_t<NV>>;

template <int NV> using peak16_mod = peak7_mod<NV>;

template <int NV>
using peak16_t = wrap::mod<peak16_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain161_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch17_t<NV>>, 
                                    peak14_t<NV>, 
                                    math::clear<NV>, 
                                    branch18_t<NV>, 
                                    peak16_t<NV>>;

template <int NV> using ramp5_t = ramp_t<NV>;
template <int NV>
using tempo_sync6_t = wrap::mod<parameter::plain<ramp5_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain179_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync6_t<NV>>, 
                                    ramp5_t<NV>>;

using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, core::empty>>;
template <int NV>
using branch36_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain102_t>, 
                                     math::mod_inv<NV>>;

template <int NV>
using minmax30_t = control::minmax<NV, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV> using minmax31_t = minmax30_t<NV>;

template <int NV> using minmax32_t = minmax30_t<NV>;

template <int NV> using minmax33_t = minmax30_t<NV>;

template <int NV> using minmax34_t = minmax30_t<NV>;

template <int NV> using minmax35_t = minmax30_t<NV>;

template <int NV> using minmax36_t = minmax30_t<NV>;

template <int NV> using minmax37_t = minmax30_t<NV>;

template <int NV>
using pma33_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<minmax30_t<NV>, 0>, 
                                   parameter::plain<minmax31_t<NV>, 0>, 
                                   parameter::plain<minmax32_t<NV>, 0>, 
                                   parameter::plain<minmax33_t<NV>, 0>, 
                                   parameter::plain<minmax34_t<NV>, 0>, 
                                   parameter::plain<minmax35_t<NV>, 0>, 
                                   parameter::plain<minmax36_t<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<minmax37_t<NV>, 0>>;

template <int NV>
using pma33_t = control::pma<NV, pma33_mod<NV>>;
template <int NV>
using peak15_t = wrap::mod<parameter::plain<pma33_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain178_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain179_t<NV>>, 
                                    branch36_t<NV>, 
                                    peak15_t<NV>, 
                                    math::clear<NV>>;

template <int NV> using ramp8_t = ramp_t<NV>;
template <int NV>
using tempo_sync9_t = wrap::mod<parameter::plain<ramp8_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain188_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync9_t<NV>>, 
                                    ramp8_t<NV>>;

using chain105_t = chain102_t;
template <int NV>
using branch89_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain105_t>, 
                                     math::mod_inv<NV>>;

template <int NV> using minmax10_t = minmax30_t<NV>;

template <int NV> using minmax13_t = minmax30_t<NV>;

template <int NV> using minmax24_t = minmax30_t<NV>;

template <int NV> using minmax25_t = minmax30_t<NV>;

template <int NV> using minmax26_t = minmax30_t<NV>;

template <int NV> using minmax27_t = minmax30_t<NV>;

template <int NV> using minmax28_t = minmax30_t<NV>;

template <int NV> using minmax29_t = minmax30_t<NV>;

template <int NV>
using pma32_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<minmax10_t<NV>, 0>, 
                                   parameter::plain<minmax13_t<NV>, 0>, 
                                   parameter::plain<minmax24_t<NV>, 0>, 
                                   parameter::plain<minmax25_t<NV>, 0>, 
                                   parameter::plain<minmax26_t<NV>, 0>, 
                                   parameter::plain<minmax27_t<NV>, 0>, 
                                   parameter::plain<minmax28_t<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<minmax29_t<NV>, 0>>;

template <int NV>
using pma32_t = control::pma<NV, pma32_mod<NV>>;
template <int NV>
using peak49_t = wrap::mod<parameter::plain<pma32_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain187_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain188_t<NV>>, 
                                    branch89_t<NV>, 
                                    peak49_t<NV>, 
                                    math::clear<NV>>;

template <int NV> using ramp7_t = ramp_t<NV>;
template <int NV>
using tempo_sync8_t = wrap::mod<parameter::plain<ramp7_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain186_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync8_t<NV>>, 
                                    ramp7_t<NV>>;

using chain104_t = chain102_t;
template <int NV>
using branch46_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain104_t>, 
                                     math::mod_inv<NV>>;

template <int NV> using minmax8_t = minmax30_t<NV>;

template <int NV> using minmax9_t = minmax30_t<NV>;

template <int NV> using minmax19_t = minmax30_t<NV>;

template <int NV> using minmax12_t = minmax30_t<NV>;

template <int NV> using minmax20_t = minmax30_t<NV>;

template <int NV> using minmax21_t = minmax30_t<NV>;

template <int NV> using minmax22_t = minmax30_t<NV>;

template <int NV> using minmax23_t = minmax30_t<NV>;

template <int NV>
using pma31_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<minmax8_t<NV>, 0>, 
                                   parameter::plain<minmax9_t<NV>, 0>, 
                                   parameter::plain<minmax19_t<NV>, 0>, 
                                   parameter::plain<minmax12_t<NV>, 0>, 
                                   parameter::plain<minmax20_t<NV>, 0>, 
                                   parameter::plain<minmax21_t<NV>, 0>, 
                                   parameter::plain<minmax22_t<NV>, 0>, 
                                   parameter::plain<minmax23_t<NV>, 1>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using pma31_t = control::pma<NV, pma31_mod<NV>>;
template <int NV>
using peak48_t = wrap::mod<parameter::plain<pma31_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain185_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain186_t<NV>>, 
                                    branch46_t<NV>, 
                                    peak48_t<NV>, 
                                    math::clear<NV>>;

template <int NV> using ramp6_t = ramp_t<NV>;
template <int NV>
using tempo_sync7_t = wrap::mod<parameter::plain<ramp6_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain184_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync7_t<NV>>, 
                                    ramp6_t<NV>>;

using chain103_t = chain102_t;
template <int NV>
using branch37_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain103_t>, 
                                     math::mod_inv<NV>>;

template <int NV> using minmax38_t = minmax30_t<NV>;

template <int NV> using minmax39_t = minmax30_t<NV>;

template <int NV> using minmax40_t = minmax30_t<NV>;

template <int NV> using minmax41_t = minmax30_t<NV>;

template <int NV> using minmax42_t = minmax30_t<NV>;

template <int NV> using minmax43_t = minmax30_t<NV>;

template <int NV> using minmax44_t = minmax30_t<NV>;

template <int NV> using minmax45_t = minmax30_t<NV>;

template <int NV>
using pma34_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<minmax38_t<NV>, 0>, 
                                   parameter::plain<minmax39_t<NV>, 0>, 
                                   parameter::plain<minmax40_t<NV>, 0>, 
                                   parameter::plain<minmax41_t<NV>, 0>, 
                                   parameter::plain<minmax42_t<NV>, 0>, 
                                   parameter::plain<minmax43_t<NV>, 0>, 
                                   parameter::plain<minmax44_t<NV>, 0>, 
                                   parameter::plain<minmax45_t<NV>, 1>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using pma34_t = control::pma<NV, pma34_mod<NV>>;
template <int NV>
using peak47_t = wrap::mod<parameter::plain<pma34_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain183_t = container::chain<parameter::empty, 
                                    wrap::fix<1, chain184_t<NV>>, 
                                    branch37_t<NV>, 
                                    peak47_t<NV>, 
                                    math::clear<NV>>;

template <int NV>
using split23_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain94_t<NV>>, 
                                   chain161_t<NV>, 
                                   chain178_t<NV>, 
                                   chain187_t<NV>, 
                                   chain185_t<NV>, 
                                   chain183_t<NV>>;

template <int NV>
using modchain8_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split23_t<NV>>>;

template <int NV>
using modchain8_t = wrap::control_rate<modchain8_t_<NV>>;

template <int NV> using sliderbank_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank_c3 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank_multimod = parameter::list<sliderbank_c0<NV>, 
                                            sliderbank_c1<NV>, 
                                            sliderbank_c2<NV>, 
                                            sliderbank_c3<NV>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<19>>;
template <int NV>
using branch39_t = container::branch<parameter::empty, 
                                     wrap::fix<2, xfader1_t<NV>>, 
                                     xfader5_t<NV>, 
                                     xfader6_t<NV>, 
                                     sliderbank_t<NV>>;

template <int NV> using sliderbank13_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank13_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank13_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank13_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank13_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank13_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank13_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank13_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank13_multimod = parameter::list<sliderbank13_c0<NV>, 
                                              sliderbank13_c1<NV>, 
                                              sliderbank13_c2<NV>, 
                                              sliderbank13_c3<NV>, 
                                              sliderbank13_c4<NV>, 
                                              sliderbank13_c5<NV>, 
                                              sliderbank13_c6<NV>, 
                                              sliderbank13_c7<NV>>;

template <int NV>
using sliderbank13_t = wrap::data<control::sliderbank<sliderbank13_multimod<NV>>, 
                                  data::external::sliderpack<7>>;
using global_cable43_t_index = global_cable3_t_index;

template <int NV>
using global_cable43_t = routing::global_cable<global_cable43_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain230_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable43_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable44_t_index = global_cable11_t_index;

template <int NV>
using global_cable44_t = routing::global_cable<global_cable44_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain231_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable44_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable45_t_index = global_cable10_t_index;

template <int NV>
using global_cable45_t = routing::global_cable<global_cable45_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain232_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable45_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable46_t_index = global_cable14_t_index;

template <int NV>
using global_cable46_t = routing::global_cable<global_cable46_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain233_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable46_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain234_t = chain44_t<NV>;

template <int NV> using chain235_t = chain44_t<NV>;
template <int NV> using branch51_t = branch15_t<NV>;

template <int NV>
using chain236_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch51_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc43_t = midi_cc10_t<NV>;

template <int NV>
using chain238_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc43_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc44_t = midi_cc10_t<NV>;

template <int NV>
using chain239_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc44_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc45_t = midi_cc10_t<NV>;

template <int NV>
using chain240_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc45_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc46_t = midi_cc10_t<NV>;

template <int NV>
using chain241_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc46_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi32_t = midi6_t<NV>;

template <int NV>
using chain242_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi32_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi33_t = midi7_t<NV>;

template <int NV>
using chain243_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi33_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi34_t = midi8_t<NV>;

template <int NV>
using chain244_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi34_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch52_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain238_t<NV>>, 
                                     chain239_t<NV>, 
                                     chain240_t<NV>, 
                                     chain241_t<NV>, 
                                     chain242_t<NV>, 
                                     chain243_t<NV>, 
                                     chain244_t<NV>>;

template <int NV>
using chain237_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch52_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split27_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain230_t<NV>>, 
                                   chain231_t<NV>, 
                                   chain232_t<NV>, 
                                   chain233_t<NV>, 
                                   chain234_t<NV>, 
                                   chain235_t<NV>, 
                                   chain236_t<NV>, 
                                   chain237_t<NV>>;

template <int NV> using minmax6_t = minmax30_t<NV>;

template <int NV> using minmax7_t = minmax30_t<NV>;

template <int NV> using minmax14_t = minmax30_t<NV>;

template <int NV> using minmax11_t = minmax30_t<NV>;

template <int NV> using minmax15_t = minmax30_t<NV>;

template <int NV> using minmax16_t = minmax30_t<NV>;

template <int NV> using minmax17_t = minmax30_t<NV>;

template <int NV> using minmax18_t = minmax30_t<NV>;

template <int NV>
using pma17_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<minmax6_t<NV>, 0>, 
                                   parameter::plain<minmax7_t<NV>, 0>, 
                                   parameter::plain<minmax14_t<NV>, 0>, 
                                   parameter::plain<minmax11_t<NV>, 0>, 
                                   parameter::plain<minmax15_t<NV>, 0>, 
                                   parameter::plain<minmax16_t<NV>, 0>, 
                                   parameter::plain<minmax17_t<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<minmax18_t<NV>, 0>>;

template <int NV>
using pma17_t = control::pma<NV, pma17_mod<NV>>;
template <int NV>
using peak21_t = wrap::mod<parameter::plain<pma17_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain250_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::add<NV>>>;

template <int NV>
using chain251_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax6_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain252_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax7_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain253_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax14_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain254_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax11_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain255_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax15_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain256_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax16_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain257_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax17_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain258_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax18_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch21_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain250_t<NV>>, 
                                     chain251_t<NV>, 
                                     chain252_t<NV>, 
                                     chain253_t<NV>, 
                                     chain254_t<NV>, 
                                     chain255_t<NV>, 
                                     chain256_t<NV>, 
                                     chain257_t<NV>, 
                                     chain258_t<NV>>;

using cable_table5_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<12>>;

template <int NV>
using peak18_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<cable_table5_t, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak18_t = wrap::mod<peak18_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain248_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch21_t<NV>>, 
                                    peak18_t<NV>, 
                                    cable_table5_t>;

template <int NV>
using modchain13_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank13_t<NV>>, 
                                       split27_t<NV>, 
                                       peak21_t<NV>, 
                                       math::clear<NV>, 
                                       pma17_t<NV>, 
                                       chain248_t<NV>>;

template <int NV>
using modchain13_t = wrap::control_rate<modchain13_t_<NV>>;

template <int NV> using chain536_t = chain250_t<NV>;

template <int NV>
using chain537_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax30_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain538_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax31_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain539_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax32_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain540_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax33_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain541_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax34_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain542_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax35_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain543_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax36_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain544_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax37_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch32_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain536_t<NV>>, 
                                     chain537_t<NV>, 
                                     chain538_t<NV>, 
                                     chain539_t<NV>, 
                                     chain540_t<NV>, 
                                     chain541_t<NV>, 
                                     chain542_t<NV>, 
                                     chain543_t<NV>, 
                                     chain544_t<NV>>;

using cable_table9_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<7>>;

template <int NV>
using peak43_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<cable_table9_t, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak43_t = wrap::mod<peak43_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain535_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch32_t<NV>>, 
                                    peak43_t<NV>, 
                                    math::clear<NV>, 
                                    math::clear<NV>, 
                                    cable_table9_t>;

template <int NV>
using modchain31_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, pma33_t<NV>>, 
                                       chain535_t<NV>>;

template <int NV>
using modchain31_t = wrap::control_rate<modchain31_t_<NV>>;

template <int NV> using chain511_t = chain250_t<NV>;

template <int NV>
using chain512_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax10_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain513_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax13_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain514_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax24_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain515_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax25_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain516_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax26_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain517_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax27_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain518_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax28_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain519_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax29_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch31_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain511_t<NV>>, 
                                     chain512_t<NV>, 
                                     chain513_t<NV>, 
                                     chain514_t<NV>, 
                                     chain515_t<NV>, 
                                     chain516_t<NV>, 
                                     chain517_t<NV>, 
                                     chain518_t<NV>, 
                                     chain519_t<NV>>;

using cable_table7_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<8>>;

template <int NV>
using peak31_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<cable_table7_t, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak31_t = wrap::mod<peak31_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain510_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch31_t<NV>>, 
                                    peak31_t<NV>, 
                                    cable_table7_t>;

template <int NV>
using modchain30_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, pma32_t<NV>>, 
                                       chain510_t<NV>>;

template <int NV>
using modchain30_t = wrap::control_rate<modchain30_t_<NV>>;

template <int NV> using chain486_t = chain250_t<NV>;

template <int NV>
using chain487_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax8_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain488_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax9_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain489_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax19_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain490_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax12_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain491_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax20_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain492_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax21_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain493_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax22_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain494_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax23_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch30_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain486_t<NV>>, 
                                     chain487_t<NV>, 
                                     chain488_t<NV>, 
                                     chain489_t<NV>, 
                                     chain490_t<NV>, 
                                     chain491_t<NV>, 
                                     chain492_t<NV>, 
                                     chain493_t<NV>, 
                                     chain494_t<NV>>;

using cable_table6_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<9>>;

template <int NV>
using peak29_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<cable_table6_t, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak29_t = wrap::mod<peak29_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain485_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch30_t<NV>>, 
                                    peak29_t<NV>, 
                                    cable_table6_t>;

template <int NV>
using modchain29_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, pma31_t<NV>>, 
                                       chain485_t<NV>>;

template <int NV>
using modchain29_t = wrap::control_rate<modchain29_t_<NV>>;

template <int NV> using chain561_t = chain250_t<NV>;

template <int NV>
using chain562_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax38_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain563_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax39_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain564_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax40_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain565_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax41_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain566_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax42_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain567_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax43_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain568_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax44_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain569_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax45_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch33_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain561_t<NV>>, 
                                     chain562_t<NV>, 
                                     chain563_t<NV>, 
                                     chain564_t<NV>, 
                                     chain565_t<NV>, 
                                     chain566_t<NV>, 
                                     chain567_t<NV>, 
                                     chain568_t<NV>, 
                                     chain569_t<NV>>;

using cable_table10_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<10>>;

template <int NV>
using peak45_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<cable_table10_t, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak45_t = wrap::mod<peak45_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain560_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch33_t<NV>>, 
                                    peak45_t<NV>, 
                                    cable_table10_t>;

template <int NV>
using modchain32_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, pma34_t<NV>>, 
                                       chain560_t<NV>>;

template <int NV>
using modchain32_t = wrap::control_rate<modchain32_t_<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<2, modchain13_t<NV>>, 
                                   modchain31_t<NV>, 
                                   modchain30_t<NV>, 
                                   modchain29_t<NV>, 
                                   modchain32_t<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<2, math::add<NV>>, 
                                   math::add<NV>>;
template <int NV>
using file_player6_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<0>>;
template <int NV>
using file_player7_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<4>>;
template <int NV>
using branch22_t = container::branch<parameter::empty, 
                                     wrap::fix<2, file_player6_t<NV>>, 
                                     file_player7_t<NV>>;
template <int NV>
using branch26_t = container::branch<parameter::empty, 
                                     wrap::fix<2, core::gain<NV>>, 
                                     core::gain<NV>, 
                                     core::gain<NV>, 
                                     core::gain<NV>>;

template <int NV>
using chain174_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split11_t<NV>>, 
                                    branch22_t<NV>, 
                                    branch26_t<NV>>;

template <int NV> using split40_t = split11_t<NV>;
template <int NV>
using file_player8_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using file_player9_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<5>>;
template <int NV>
using branch40_t = container::branch<parameter::empty, 
                                     wrap::fix<2, file_player8_t<NV>>, 
                                     file_player9_t<NV>>;
template <int NV> using branch41_t = branch26_t<NV>;

template <int NV>
using chain175_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split40_t<NV>>, 
                                    branch40_t<NV>, 
                                    branch41_t<NV>>;

template <int NV> using split21_t = split11_t<NV>;
template <int NV>
using file_player10_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<2>>;
template <int NV>
using file_player11_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<6>>;
template <int NV>
using branch42_t = container::branch<parameter::empty, 
                                     wrap::fix<2, file_player10_t<NV>>, 
                                     file_player11_t<NV>>;
template <int NV> using branch43_t = branch26_t<NV>;

template <int NV>
using chain176_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split21_t<NV>>, 
                                    branch42_t<NV>, 
                                    branch43_t<NV>>;

template <int NV> using split19_t = split11_t<NV>;
template <int NV>
using file_player12_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<3>>;
template <int NV>
using file_player13_t = wrap::data<core::file_player<NV>, 
                                   data::external::audiofile<7>>;
template <int NV>
using branch44_t = container::branch<parameter::empty, 
                                     wrap::fix<2, file_player12_t<NV>>, 
                                     file_player13_t<NV>>;
template <int NV> using branch45_t = branch26_t<NV>;

template <int NV>
using chain177_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split19_t<NV>>, 
                                    branch44_t<NV>, 
                                    branch45_t<NV>>;

template <int NV>
using split17_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain174_t<NV>>, 
                                   chain175_t<NV>, 
                                   chain176_t<NV>, 
                                   chain177_t<NV>>;

template <int NV>
using chain247_t = container::chain<parameter::empty, 
                                    wrap::fix<2, filters::one_pole<NV>>, 
                                    branch39_t<NV>, 
                                    split10_t<NV>, 
                                    split17_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, modchain8_t<NV>>, 
                                       chain247_t<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain261_t = container::chain<parameter::empty, 
                                    wrap::fix<2, wrap::no_process<math::tanh<NV>>>>;

template <int NV>
using chain262_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<stereo_cable>>, 
                                    project::shfiter<NV>, 
                                    routing::send<stereo_cable>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table15_modRange, 
                             -64., 
                             64., 
                             1.);

template <int NV>
using cable_table15_mod = parameter::from0To1<project::ps2<NV>, 
                                              0, 
                                              cable_table15_modRange>;

struct cable_table15_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00211084f, 0.00422174f, 0.00633258f, 0.00844347f, 0.0105543f,
		0.0126652f, 0.0147761f, 0.0168869f, 0.0189978f, 0.0211086f, 0.0232195f,
		0.0253304f, 0.0274413f, 0.0295521f, 0.0316629f, 0.0337738f, 0.0358847f,
		0.0379956f, 0.0401064f, 0.0422173f, 0.0443282f, 0.046439f, 0.0485499f,
		0.0506607f, 0.0527716f, 0.0548825f, 0.0569934f, 0.0591042f, 0.061215f,
		0.0633259f, 0.0654368f, 0.0675477f, 0.0696585f, 0.0717694f, 0.0738803f,
		0.0759911f, 0.078102f, 0.0802128f, 0.0823237f, 0.0844346f, 0.0865455f,
		0.0886563f, 0.0907671f, 0.092878f, 0.0949889f, 0.0970998f, 0.0992106f,
		0.101321f, 0.103432f, 0.105543f, 0.107654f, 0.109765f, 0.111876f,
		0.113987f, 0.116098f, 0.118208f, 0.120319f, 0.12243f, 0.124541f,
		0.126652f, 0.128763f, 0.130874f, 0.132984f, 0.135095f, 0.137206f,
		0.139317f, 0.141428f, 0.143539f, 0.14565f, 0.147761f, 0.149871f,
		0.151982f, 0.154093f, 0.156204f, 0.158315f, 0.160426f, 0.162537f,
		0.164647f, 0.166758f, 0.168869f, 0.17098f, 0.173091f, 0.175202f,
		0.177313f, 0.179423f, 0.181534f, 0.183645f, 0.185756f, 0.187867f,
		0.189978f, 0.192089f, 0.1942f, 0.19631f, 0.198421f, 0.200532f,
		0.202643f, 0.204754f, 0.206865f, 0.208976f, 0.211086f, 0.213197f,
		0.215308f, 0.217419f, 0.21953f, 0.221641f, 0.223752f, 0.225863f,
		0.227973f, 0.230084f, 0.232195f, 0.234306f, 0.236417f, 0.238528f,
		0.240638f, 0.242749f, 0.24486f, 0.246971f, 0.249082f, 0.251193f,
		0.253304f, 0.255415f, 0.257525f, 0.259636f, 0.261747f, 0.263858f,
		0.265969f, 0.26808f, 0.270191f, 0.272301f, 0.274412f, 0.276523f,
		0.278634f, 0.280745f, 0.282856f, 0.284967f, 0.287078f, 0.289188f,
		0.291299f, 0.29341f, 0.295521f, 0.297632f, 0.299743f, 0.301854f,
		0.303992f, 0.306199f, 0.308407f, 0.310614f, 0.312821f, 0.315029f,
		0.317236f, 0.319444f, 0.321651f, 0.323859f, 0.326066f, 0.328273f,
		0.330481f, 0.332688f, 0.334896f, 0.337103f, 0.339311f, 0.341518f,
		0.343726f, 0.345933f, 0.34814f, 0.350348f, 0.352555f, 0.354763f,
		0.35697f, 0.359178f, 0.361385f, 0.363593f, 0.3658f, 0.368007f,
		0.370215f, 0.372422f, 0.37463f, 0.376837f, 0.379045f, 0.381252f,
		0.383459f, 0.385667f, 0.387874f, 0.390082f, 0.392289f, 0.394497f,
		0.396704f, 0.398912f, 0.401119f, 0.403326f, 0.405534f, 0.407741f,
		0.409949f, 0.412156f, 0.414364f, 0.416445f, 0.418321f, 0.420198f,
		0.422074f, 0.42395f, 0.425827f, 0.427703f, 0.429579f, 0.431456f,
		0.433332f, 0.435208f, 0.437085f, 0.438961f, 0.440837f, 0.442713f,
		0.44459f, 0.446466f, 0.448342f, 0.450219f, 0.452095f, 0.453971f,
		0.455848f, 0.457724f, 0.4596f, 0.461477f, 0.463353f, 0.465229f,
		0.467106f, 0.468982f, 0.470858f, 0.472735f, 0.474611f, 0.476487f,
		0.478364f, 0.48024f, 0.482116f, 0.483993f, 0.485869f, 0.487745f,
		0.489622f, 0.491498f, 0.493374f, 0.495251f, 0.497127f, 0.499003f,
		0.50088f, 0.502756f, 0.504632f, 0.506508f, 0.508385f, 0.510261f,
		0.512137f, 0.514014f, 0.51589f, 0.517766f, 0.519643f, 0.521519f,
		0.523395f, 0.525272f, 0.527148f, 0.529024f, 0.530901f, 0.532777f,
		0.534653f, 0.53653f, 0.538406f, 0.540282f, 0.542159f, 0.544035f,
		0.545911f, 0.547788f, 0.549664f, 0.55154f, 0.553417f, 0.555293f,
		0.557169f, 0.559046f, 0.560922f, 0.562798f, 0.564674f, 0.566551f,
		0.568427f, 0.570303f, 0.57218f, 0.574056f, 0.575932f, 0.577809f,
		0.579685f, 0.581561f, 0.583438f, 0.585314f, 0.58719f, 0.589067f,
		0.590943f, 0.592819f, 0.594696f, 0.596595f, 0.598511f, 0.600427f,
		0.602343f, 0.60426f, 0.606176f, 0.608092f, 0.610008f, 0.611925f,
		0.613841f, 0.615757f, 0.617673f, 0.61959f, 0.621506f, 0.623422f,
		0.625338f, 0.627255f, 0.629171f, 0.631087f, 0.633003f, 0.63492f,
		0.636836f, 0.638752f, 0.640668f, 0.642585f, 0.644501f, 0.646417f,
		0.648333f, 0.65025f, 0.652166f, 0.654082f, 0.655998f, 0.657915f,
		0.659831f, 0.661747f, 0.663663f, 0.66558f, 0.667496f, 0.669412f,
		0.671328f, 0.673244f, 0.675161f, 0.677077f, 0.678993f, 0.68091f,
		0.682826f, 0.684742f, 0.686705f, 0.688691f, 0.690678f, 0.692665f,
		0.694652f, 0.696638f, 0.698625f, 0.700612f, 0.702598f, 0.704585f,
		0.706572f, 0.708558f, 0.710545f, 0.712532f, 0.714518f, 0.716505f,
		0.718492f, 0.720479f, 0.722465f, 0.724452f, 0.726439f, 0.728425f,
		0.730412f, 0.732399f, 0.734385f, 0.736372f, 0.738359f, 0.740346f,
		0.742332f, 0.744319f, 0.746306f, 0.748292f, 0.750279f, 0.752266f,
		0.754252f, 0.756239f, 0.758226f, 0.760213f, 0.762199f, 0.764186f,
		0.766173f, 0.768159f, 0.770146f, 0.772133f, 0.774119f, 0.776106f,
		0.778093f, 0.780079f, 0.782066f, 0.784053f, 0.78604f, 0.787992f,
		0.789934f, 0.791875f, 0.793817f, 0.795759f, 0.7977f, 0.799642f,
		0.801584f, 0.803526f, 0.805467f, 0.807409f, 0.809351f, 0.811292f,
		0.813234f, 0.81516f, 0.817041f, 0.818923f, 0.820804f, 0.822686f,
		0.824567f, 0.826448f, 0.82833f, 0.830211f, 0.832093f, 0.833974f,
		0.835855f, 0.837737f, 0.839618f, 0.8415f, 0.843351f, 0.845174f,
		0.846997f, 0.84882f, 0.850643f, 0.852466f, 0.854289f, 0.856112f,
		0.857935f, 0.859758f, 0.861582f, 0.863405f, 0.865228f, 0.867051f,
		0.868874f, 0.870667f, 0.872433f, 0.8742f, 0.875967f, 0.877733f,
		0.8795f, 0.881266f, 0.883033f, 0.8848f, 0.886566f, 0.888333f,
		0.890099f, 0.891866f, 0.893633f, 0.895399f, 0.897149f, 0.898861f,
		0.900573f, 0.902285f, 0.903996f, 0.905708f, 0.90742f, 0.909132f,
		0.910844f, 0.912556f, 0.914268f, 0.91598f, 0.917692f, 0.919403f,
		0.921115f, 0.922827f, 0.924494f, 0.926153f, 0.927812f, 0.929471f,
		0.93113f, 0.932789f, 0.934447f, 0.936106f, 0.937765f, 0.939424f,
		0.941083f, 0.942742f, 0.944401f, 0.946059f, 0.947718f, 0.94937f,
		0.950977f, 0.952585f, 0.954192f, 0.9558f, 0.957407f, 0.959015f,
		0.960622f, 0.962229f, 0.963837f, 0.965444f, 0.967052f, 0.968659f,
		0.970267f, 0.971874f, 0.973481f, 0.975079f, 0.976637f, 0.978194f,
		0.979752f, 0.98131f, 0.982867f, 0.984425f, 0.985982f, 0.98754f,
		0.989097f, 0.990655f, 0.992212f, 0.99377f, 0.995327f, 0.996885f,
		0.998442f, 1.f
	};
};

template <int NV>
using cable_table15_t = wrap::data<control::cable_table<cable_table15_mod<NV>>, 
                                   data::embedded::table<cable_table15_t_data>>;
template <int NV>
using midi42_t = wrap::mod<parameter::plain<cable_table15_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain263_t = container::chain<parameter::empty, 
                                    wrap::fix<2, midi42_t<NV>>, 
                                    cable_table15_t<NV>, 
                                    routing::receive<stereo_cable>, 
                                    project::ps2<NV>, 
                                    project::shfiter<NV>, 
                                    routing::send<stereo_cable>>;

using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<2, core::empty>>;
template <int NV>
using branch23_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain261_t<NV>>, 
                                     chain262_t<NV>, 
                                     chain263_t<NV>, 
                                     chain101_t>;

template <int NV> using peak22_mod = peak17_mod<NV>;

template <int NV>
using peak22_t = wrap::mod<peak22_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   chain87_t<NV>, 
                                   fix8_block_t<NV>, 
                                   branch23_t<NV>, 
                                   routing::send<stereo_cable>, 
                                   peak22_t<NV>, 
                                   math::clear<NV>>;

template <int NV> using chain193_t = chain191_t<NV>;

template <int NV> using chain195_t = chain191_t<NV>;

template <int NV> using chain194_t = chain191_t<NV>;

template <int NV>
using split31_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain193_t<NV>>, 
                                   chain195_t<NV>, 
                                   chain194_t<NV>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::klp<NV>>, 
                                   project::khp2<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, project::klp<NV>>, 
                                  project::khp2<NV>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split1_t<NV>>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table_t<NV>>, 
                                   project::Comb<NV>, 
                                   project::klp<NV>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table2_t<NV>>, 
                                   project::klp<NV>, 
                                   project::Comb<NV>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::klp<NV>>, 
                                   jdsp::jpanner<NV>>;

template <int NV> using chain56_t = chain55_t<NV>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain55_t<NV>>, 
                                  chain56_t<NV>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::khp<NV>>, 
                                   jdsp::jpanner<NV>>;

template <int NV> using chain61_t = chain60_t<NV>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain60_t<NV>>, 
                                   chain61_t<NV>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table3_t<NV>>, 
                                   project::Comb<NV>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table4_t<NV>>, 
                                   project::Comb<NV>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain71_t<NV>>, 
                                   chain72_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain16_t<NV>>, 
                                   chain35_t<NV>, 
                                   chain36_t<NV>, 
                                   chain37_t<NV>, 
                                   split9_t<NV>, 
                                   split13_t<NV>, 
                                   split14_t<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch_t<NV>>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain15_t<NV>>, 
                                   routing::send<stereo_cable>, 
                                   core::gain<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain14_t<NV>>, 
                                   chain57_t<NV>>;

template <int NV> using peak33_mod = peak7_mod<NV>;

template <int NV>
using peak33_t = wrap::mod<peak33_mod<NV>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::clear<NV>>, 
                                   split31_t<NV>, 
                                   xfader_t<NV>, 
                                   split12_t<NV>, 
                                   peak33_t<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain19_t<NV>>, 
                                   chain86_t<NV>, 
                                   chain73_t<NV>, 
                                   chain58_t<NV>>;

template <int NV>
using xfade_2x_lin_t = container::chain<parameter::empty, 
                                        wrap::fix<2, split20_t<NV>>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfade_2x_lin_t<NV>>>;
using oscilloscope_t = wrap::data<analyse::oscilloscope, 
                                  data::external::displaybuffer<2>>;

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

template <int NV>
using div = parameter::chain<ranges::Identity, 
                             parameter::plain<osc1_impl::tempo_sync_t<NV>, 1>, 
                             parameter::plain<osc1_impl::tempo_sync1_t<NV>, 1>>;

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
using pitchmode_2 = parameter::from0To1<osc1_impl::branch7_t<NV>, 
                                        0, 
                                        pitchmode_0Range>;

template <int NV>
using pitchmode_3 = parameter::from0To1<osc1_impl::branch12_t<NV>, 
                                        0, 
                                        pitchmode_0Range>;

template <int NV>
using pitchmode = parameter::chain<pitchmode_InputRange, 
                                   pitchmode_0<NV>, 
                                   pitchmode_1<NV>, 
                                   pitchmode_2<NV>, 
                                   pitchmode_3<NV>>;

template <int NV>
using step = parameter::chain<ranges::Identity, 
                              parameter::plain<osc1_impl::minmax2_t<NV>, 4>, 
                              parameter::plain<osc1_impl::minmax3_t<NV>, 4>>;

template <int NV>
using PitchMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<osc1_impl::pma1_t<NV>, 1>, 
                                  parameter::plain<osc1_impl::pma8_t<NV>, 1>, 
                                  parameter::plain<osc1_impl::pma11_t<NV>, 1>>;

template <int NV>
using Tempo2 = parameter::chain<ranges::Identity, 
                                parameter::plain<osc1_impl::pma14_t<NV>, 2>, 
                                parameter::plain<osc1_impl::pma15_t<NV>, 2>>;

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

DECLARE_PARAMETER_RANGE(Shape2_InputRange, 
                        1., 
                        7.);
template <int NV>
using Shape2_0 = parameter::from0To1<osc1_impl::branch10_t<NV>, 
                                     0, 
                                     MidiSlotPitch_0Range>;

template <int NV>
using Shape2 = parameter::chain<Shape2_InputRange, Shape2_0<NV>>;

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

DECLARE_PARAMETER_RANGE(MidiWidth2_InputRange, 
                        1., 
                        7.);
template <int NV>
using MidiWidth2_0 = parameter::from0To1<osc1_impl::branch48_t<NV>, 
                                         0, 
                                         MidiSlotPitch_0Range>;

template <int NV>
using MidiWidth2 = parameter::chain<MidiWidth2_InputRange, MidiWidth2_0<NV>>;

DECLARE_PARAMETER_RANGE(MidiWidth_InputRange, 
                        1., 
                        7.);
template <int NV>
using MidiWidth_0 = parameter::from0To1<osc1_impl::branch50_t<NV>, 
                                        0, 
                                        MidiSlotPitch_0Range>;

template <int NV>
using MidiWidth = parameter::chain<MidiWidth_InputRange, MidiWidth_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(QuantisePositiion_InputRange, 
                             1., 
                             9., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(QuantisePositiion_0Range, 
                             0., 
                             8., 
                             1.);

template <int NV>
using QuantisePositiion_0 = parameter::from0To1<osc1_impl::branch21_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion_1 = parameter::from0To1<osc1_impl::branch32_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion_2 = parameter::from0To1<osc1_impl::branch31_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion_3 = parameter::from0To1<osc1_impl::branch30_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion_4 = parameter::from0To1<osc1_impl::branch33_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion = parameter::chain<QuantisePositiion_InputRange, 
                                           QuantisePositiion_0<NV>, 
                                           QuantisePositiion_1<NV>, 
                                           QuantisePositiion_2<NV>, 
                                           QuantisePositiion_3<NV>, 
                                           QuantisePositiion_4<NV>>;

DECLARE_PARAMETER_RANGE(FilePitch_InputRange, 
                        -24., 
                        24.);

template <int NV>
using FilePitch = parameter::chain<FilePitch_InputRange, 
                                   parameter::plain<osc1_impl::pma20_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(PtichShiftOn_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PtichShiftOn_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using PtichShiftOn_0 = parameter::from0To1<osc1_impl::branch23_t<NV>, 
                                           0, 
                                           PtichShiftOn_0Range>;

template <int NV>
using PtichShiftOn = parameter::chain<PtichShiftOn_InputRange, 
                                      PtichShiftOn_0<NV>>;

template <int NV>
using FileUser = parameter::chain<ranges::Identity, 
                                  parameter::plain<osc1_impl::branch40_t<NV>, 0>, 
                                  parameter::plain<osc1_impl::branch22_t<NV>, 0>, 
                                  parameter::plain<osc1_impl::branch42_t<NV>, 0>, 
                                  parameter::plain<osc1_impl::branch44_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidiPitch_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using FileMidiPitch_0 = parameter::from0To1<osc1_impl::branch58_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using FileMidiPitch = parameter::chain<FileMidiPitch_InputRange, 
                                       FileMidiPitch_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidipos2_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidipos2_0 = parameter::from0To1<osc1_impl::branch52_t<NV>, 
                                           0, 
                                           MidiSlotPitch_0Range>;

template <int NV>
using FileMidipos2 = parameter::chain<FileMidipos2_InputRange, 
                                      FileMidipos2_0<NV>>;

DECLARE_PARAMETER_RANGE(FileWinPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileWinPk_0 = parameter::from0To1<osc1_impl::branch59_t<NV>, 
                                        0, 
                                        PtichShiftOn_0Range>;

template <int NV>
using FileWinPk = parameter::chain<FileWinPk_InputRange, FileWinPk_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidiwindow_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidiwindow_0 = parameter::from0To1<osc1_impl::branch60_t<NV>, 
                                             0, 
                                             MidiSlotPitch_0Range>;

template <int NV>
using FileMidiwindow = parameter::chain<FileMidiwindow_InputRange, 
                                        FileMidiwindow_0<NV>>;

DECLARE_PARAMETER_RANGE(FileMidiInput_InputRange, 
                        1., 
                        7.);
template <int NV>
using FileMidiInput_0 = parameter::from0To1<osc1_impl::branch54_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using FileMidiInput = parameter::chain<FileMidiInput_InputRange, 
                                       FileMidiInput_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Q_0Range, 
                             0.5, 
                             10., 
                             0.01);

template <int NV>
using Q_0 = parameter::from0To1<project::khp<NV>, 
                                0, 
                                Q_0Range>;

template <int NV>
using Q_1 = parameter::from0To1<project::klp<NV>, 
                                0, 
                                Q_0Range>;

template <int NV> using Q_3 = Q_1<NV>;

template <int NV> using Q_5 = Q_1<NV>;

template <int NV> using Q_6 = Q_1<NV>;

template <int NV>
using Q = parameter::chain<ranges::Identity, 
                           Q_0<NV>, 
                           Q_1<NV>, 
                           parameter::plain<project::Comb<NV>, 0>, 
                           Q_3<NV>, 
                           parameter::plain<project::Comb<NV>, 0>, 
                           Q_5<NV>, 
                           Q_6<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(Cut1_InputRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using Cut1 = parameter::chain<Cut1_InputRange, 
                              parameter::plain<osc1_impl::pma23_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_SKEW(Cut2_InputRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using Cut2 = parameter::chain<Cut2_InputRange, 
                              parameter::plain<osc1_impl::pma24_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(FilterMidiMix_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiMix_0 = parameter::from0To1<osc1_impl::branch62_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using FilterMidiMix = parameter::chain<FilterMidiMix_InputRange, 
                                       FilterMidiMix_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterMidiCut1_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiCut1_0 = parameter::from0To1<osc1_impl::branch64_t<NV>, 
                                             0, 
                                             MidiSlotPitch_0Range>;

template <int NV>
using FilterMidiCut1 = parameter::chain<FilterMidiCut1_InputRange, 
                                        FilterMidiCut1_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterMidiCut2_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiCut2_0 = parameter::from0To1<osc1_impl::branch66_t<NV>, 
                                             0, 
                                             MidiSlotPitch_0Range>;

template <int NV>
using FilterMidiCut2 = parameter::chain<FilterMidiCut2_InputRange, 
                                        FilterMidiCut2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMode_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FilterMode_0 = parameter::from0To1<osc1_impl::branch_t<NV>, 
                                         0, 
                                         MidiSlotPitch_0Range>;

template <int NV>
using FilterMode = parameter::chain<FilterMode_InputRange, FilterMode_0<NV>>;

template <int NV> using q2_1 = Q_0<NV>;

template <int NV> using q2_2 = Q_1<NV>;

template <int NV> using q2_4 = Q_1<NV>;

template <int NV>
using q2_5 = parameter::from0To1<project::khp2<NV>, 
                                 0, 
                                 Q_0Range>;

DECLARE_PARAMETER_RANGE_STEP(q2_6Range, 
                             0.5, 
                             1, 
                             0.01);

template <int NV>
using q2_6 = parameter::from0To1<project::khp2<NV>, 
                                 0, 
                                 q2_6Range>;

template <int NV>
using q2 = parameter::chain<ranges::Identity, 
                            parameter::plain<project::Comb<NV>, 0>, 
                            q2_1<NV>, 
                            q2_2<NV>, 
                            parameter::plain<project::Comb<NV>, 0>, 
                            q2_4<NV>, 
                            q2_5<NV>, 
                            q2_6<NV>>;

template <int NV>
using EnvTempo1 = parameter::chain<ranges::Identity, 
                                   parameter::plain<osc1_impl::tempo_sync2_t<NV>, 0>, 
                                   parameter::plain<osc1_impl::clock_ramp_t<NV>, 0>>;

template <int NV>
using EnvTempo2 = parameter::chain<ranges::Identity, 
                                   parameter::plain<osc1_impl::tempo_sync5_t<NV>, 0>, 
                                   parameter::plain<osc1_impl::clock_ramp3_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(EnvDiv_InputRange, 
                             1., 
                             32., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(EnvDiv_0Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using EnvDiv_0 = parameter::from0To1<osc1_impl::tempo_sync2_t<NV>, 
                                     1, 
                                     EnvDiv_0Range>;

template <int NV>
using EnvDiv_1 = parameter::from0To1<osc1_impl::clock_ramp_t<NV>, 
                                     1, 
                                     EnvDiv_0Range>;

template <int NV>
using EnvDiv = parameter::chain<EnvDiv_InputRange, 
                                EnvDiv_0<NV>, 
                                EnvDiv_1<NV>>;

DECLARE_PARAMETER_RANGE(PitchPkModSrc1_InputRange, 
                        1., 
                        4.);
template <int NV>
using PitchPkModSrc1_0 = parameter::from0To1<osc1_impl::branch15_t<NV>, 
                                             0, 
                                             PtichShiftOn_0Range>;

template <int NV>
using PitchPkModSrc1 = parameter::chain<PitchPkModSrc1_InputRange, 
                                        PitchPkModSrc1_0<NV>>;

DECLARE_PARAMETER_RANGE(Pitch2Midi_InputRange, 
                        1., 
                        7.);
template <int NV>
using Pitch2Midi_0 = parameter::from0To1<osc1_impl::branch11_t<NV>, 
                                         0, 
                                         MidiSlotPitch_0Range>;

template <int NV>
using Pitch2Midi = parameter::chain<Pitch2Midi_InputRange, Pitch2Midi_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Pitch2PkModSrc_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using Pitch2PkModSrc_0 = parameter::from0To1<osc1_impl::branch16_t<NV>, 
                                             0, 
                                             PtichShiftOn_0Range>;

template <int NV>
using Pitch2PkModSrc = parameter::chain<Pitch2PkModSrc_InputRange, 
                                        Pitch2PkModSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(InSrcOsc1_InputRange, 
                             1., 
                             3., 
                             1.);
using InSrcOsc1_0 = parameter::from0To1<osc1_impl::branch38_t, 
                                        0, 
                                        pitchmode_0Range>;

using InSrcOsc1 = parameter::chain<InSrcOsc1_InputRange, InSrcOsc1_0>;

DECLARE_PARAMETER_RANGE_STEP(InSrcOsc2_InputRange, 
                             1., 
                             3., 
                             1.);
using InSrcOsc2_0 = parameter::from0To1<osc1_impl::branch27_t, 
                                        0, 
                                        pitchmode_0Range>;

using InSrcOsc2 = parameter::chain<InSrcOsc2_InputRange, InSrcOsc2_0>;

template <int NV>
using FilerInOsc1 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        osc1_impl::pma2_modRange>;

template <int NV> using FilterInOSc2 = FilerInOsc1<NV>;

template <int NV> using FilterInFile = FilerInOsc1<NV>;

DECLARE_PARAMETER_RANGE(OscMixPkIn_InputRange, 
                        1., 
                        4.);
template <int NV>
using OscMixPkIn_0 = parameter::from0To1<osc1_impl::branch19_t<NV>, 
                                         0, 
                                         PtichShiftOn_0Range>;

template <int NV>
using OscMixPkIn = parameter::chain<OscMixPkIn_InputRange, OscMixPkIn_0<NV>>;

DECLARE_PARAMETER_RANGE(OscInPeak_InputRange, 
                        1., 
                        4.);
template <int NV>
using OscInPeak_0 = parameter::from0To1<osc1_impl::branch20_t<NV>, 
                                        0, 
                                        PtichShiftOn_0Range>;

template <int NV>
using OscInPeak = parameter::chain<OscInPeak_InputRange, OscInPeak_0<NV>>;

DECLARE_PARAMETER_RANGE(OscInPEak2_InputRange, 
                        1., 
                        4.);
template <int NV>
using OscInPEak2_0 = parameter::from0To1<osc1_impl::branch24_t<NV>, 
                                         0, 
                                         PtichShiftOn_0Range>;

template <int NV>
using OscInPEak2 = parameter::chain<OscInPEak2_InputRange, OscInPEak2_0<NV>>;

DECLARE_PARAMETER_RANGE(Osc2Mid_InputRange, 
                        1., 
                        7.);
template <int NV>
using Osc2Mid_0 = parameter::from0To1<osc1_impl::branch25_t<NV>, 
                                      0, 
                                      MidiSlotPitch_0Range>;

template <int NV>
using Osc2Mid = parameter::chain<Osc2Mid_InputRange, Osc2Mid_0<NV>>;

DECLARE_PARAMETER_RANGE(OscWidthPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using OscWidthPk_0 = parameter::from0To1<osc1_impl::branch49_t<NV>, 
                                         0, 
                                         PtichShiftOn_0Range>;

template <int NV>
using OscWidthPk = parameter::chain<OscWidthPk_InputRange, OscWidthPk_0<NV>>;

DECLARE_PARAMETER_RANGE(OscWidthPk2_InputRange, 
                        1., 
                        4.);
template <int NV>
using OscWidthPk2_0 = parameter::from0To1<osc1_impl::branch47_t<NV>, 
                                          0, 
                                          PtichShiftOn_0Range>;

template <int NV>
using OscWidthPk2 = parameter::chain<OscWidthPk2_InputRange, OscWidthPk2_0<NV>>;

DECLARE_PARAMETER_RANGE(FileMidPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileMidPk_0 = parameter::from0To1<osc1_impl::branch51_t<NV>, 
                                        0, 
                                        PtichShiftOn_0Range>;

template <int NV>
using FileMidPk = parameter::chain<FileMidPk_InputRange, FileMidPk_0<NV>>;

DECLARE_PARAMETER_RANGE(FileInPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileInPk_0 = parameter::from0To1<osc1_impl::branch53_t<NV>, 
                                       0, 
                                       PtichShiftOn_0Range>;

template <int NV>
using FileInPk = parameter::chain<FileInPk_InputRange, FileInPk_0<NV>>;

DECLARE_PARAMETER_RANGE(FileXrossFadePk_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileXrossFadePk_0 = parameter::from0To1<osc1_impl::branch55_t<NV>, 
                                              0, 
                                              PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadePk = parameter::chain<FileXrossFadePk_InputRange, 
                                         FileXrossFadePk_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileXrossFadeMode_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using FileXrossFadeMode_0 = parameter::from0To1<osc1_impl::branch45_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode_1 = parameter::from0To1<osc1_impl::branch43_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode_2 = parameter::from0To1<osc1_impl::branch41_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode_3 = parameter::from0To1<osc1_impl::branch26_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode_4 = parameter::from0To1<osc1_impl::branch39_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode = parameter::chain<FileXrossFadeMode_InputRange, 
                                           FileXrossFadeMode_0<NV>, 
                                           FileXrossFadeMode_1<NV>, 
                                           FileXrossFadeMode_2<NV>, 
                                           FileXrossFadeMode_3<NV>, 
                                           FileXrossFadeMode_4<NV>>;

DECLARE_PARAMETER_RANGE(FileXrossFadeMidi_InputRange, 
                        1., 
                        7.);
template <int NV>
using FileXrossFadeMidi_0 = parameter::from0To1<osc1_impl::branch56_t<NV>, 
                                                0, 
                                                MidiSlotPitch_0Range>;

template <int NV>
using FileXrossFadeMidi = parameter::chain<FileXrossFadeMidi_InputRange, 
                                           FileXrossFadeMidi_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilePitchPk_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using FilePitchPk_0 = parameter::from0To1<osc1_impl::branch57_t<NV>, 
                                          0, 
                                          PtichShiftOn_0Range>;

template <int NV>
using FilePitchPk = parameter::chain<FilePitchPk_InputRange, FilePitchPk_0<NV>>;

DECLARE_PARAMETER_RANGE(PAn_InputRange, 
                        -1., 
                        1.);

template <int NV>
using PAn = parameter::chain<PAn_InputRange, 
                             parameter::plain<osc1_impl::pma26_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP_INV(CutPK_InputRange, 
                                 3., 
                                 14., 
                                 1.);
template <int NV>
using CutPK_0 = parameter::from0To1<osc1_impl::branch63_t<NV>, 
                                    0, 
                                    PtichShiftOn_0Range>;

template <int NV>
using CutPK = parameter::chain<CutPK_InputRange, CutPK_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Cut2Pk_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using Cut2Pk_0 = parameter::from0To1<osc1_impl::branch65_t<NV>, 
                                     0, 
                                     PtichShiftOn_0Range>;

template <int NV>
using Cut2Pk = parameter::chain<Cut2Pk_InputRange, Cut2Pk_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(GainMidi_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using GainMidi_0 = parameter::from0To1<osc1_impl::branch68_t<NV>, 
                                       0, 
                                       MidiSlotPitch_0Range>;

template <int NV>
using GainMidi = parameter::chain<GainMidi_InputRange, GainMidi_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(GainPk_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using GainPk_0 = parameter::from0To1<osc1_impl::branch67_t<NV>, 
                                     0, 
                                     PtichShiftOn_0Range>;

template <int NV>
using GainPk = parameter::chain<GainPk_InputRange, GainPk_0<NV>>;

DECLARE_PARAMETER_RANGE(PanMidi_InputRange, 
                        1., 
                        7.);
template <int NV>
using PanMidi_0 = parameter::from0To1<osc1_impl::branch70_t<NV>, 
                                      0, 
                                      MidiSlotPitch_0Range>;

template <int NV>
using PanMidi = parameter::chain<PanMidi_InputRange, PanMidi_0<NV>>;

DECLARE_PARAMETER_RANGE(PanPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using PanPk_0 = parameter::from0To1<osc1_impl::branch69_t<NV>, 
                                    0, 
                                    PtichShiftOn_0Range>;

template <int NV>
using PanPk = parameter::chain<PanPk_InputRange, PanPk_0<NV>>;

template <int NV>
using FilterMixPk = parameter::from0To1<osc1_impl::branch61_t<NV>, 
                                        0, 
                                        PtichShiftOn_0Range>;

DECLARE_PARAMETER_RANGE(feed_0Range, 
                        0., 
                        0.9);

using feed_0 = parameter::from0To1<routing::receive<stereo_cable>, 
                                   0, 
                                   feed_0Range>;

using feed_1 = feed_0;

using feed = parameter::chain<ranges::Identity, 
                              feed_0, 
                              feed_1>;

DECLARE_PARAMETER_RANGE_SKEW(FileIn_InputRange, 
                             0., 
                             0.5, 
                             0.620929);
DECLARE_PARAMETER_RANGE_SKEW(FileIn_0Range, 
                             0., 
                             0.5, 
                             0.380025);

using FileIn_0 = parameter::from0To1<routing::receive<stereo_cable>, 
                                     0, 
                                     FileIn_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(FileIn_1Range, 
                             0., 
                             0.5, 
                             0.253636);

using FileIn_1 = parameter::from0To1<routing::receive<stereo_cable>, 
                                     0, 
                                     FileIn_1Range>;

using FileIn = parameter::chain<FileIn_InputRange, 
                                FileIn_0, 
                                FileIn_1>;

DECLARE_PARAMETER_RANGE_SKEW(OscsOut_InputRange, 
                             -100., 
                             0., 
                             5.42227);
template <int NV> using OscsOut_0 = FilerInOsc1<NV>;

template <int NV>
using OscsOut_1 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      osc1_impl::sliderbank3_c0Range>;

template <int NV>
using OscsOut = parameter::chain<OscsOut_InputRange, 
                                 OscsOut_0<NV>, 
                                 OscsOut_1<NV>>;

DECLARE_PARAMETER_RANGE(Pitch2_InputRange, 
                        -24., 
                        24.);

template <int NV>
using Pitch2 = parameter::chain<Pitch2_InputRange, 
                                parameter::plain<osc1_impl::pma3_t<NV>, 2>>;

template <int NV>
using Pitch2Mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<osc1_impl::pma3_t<NV>, 1>, 
                                   parameter::plain<osc1_impl::pma14_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(Input1Midi_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using Input1Midi_0 = parameter::from0To1<osc1_impl::branch4_t<NV>, 
                                         0, 
                                         MidiSlotPitch_0Range>;

template <int NV>
using Input1Midi = parameter::chain<Input1Midi_InputRange, Input1Midi_0<NV>>;

template <int NV>
using EnvDiv2_0 = parameter::from0To1<osc1_impl::tempo_sync5_t<NV>, 
                                      1, 
                                      EnvDiv_0Range>;

template <int NV>
using EnvDiv2_1 = parameter::from0To1<osc1_impl::clock_ramp3_t<NV>, 
                                      1, 
                                      EnvDiv_0Range>;

template <int NV>
using EnvDiv2 = parameter::chain<ranges::Identity, 
                                 EnvDiv2_0<NV>, 
                                 EnvDiv2_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(RampDiv1_InputRange, 
                             1., 
                             32., 
                             1.);
template <int NV>
using RampDiv1_0 = parameter::from0To1<osc1_impl::tempo_sync6_t<NV>, 
                                       1, 
                                       EnvDiv_0Range>;

template <int NV>
using RampDiv1 = parameter::chain<RampDiv1_InputRange, RampDiv1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(RampDiv2_InputRange, 
                             1., 
                             32., 
                             1.);
template <int NV>
using RampDiv2_0 = parameter::from0To1<osc1_impl::tempo_sync9_t<NV>, 
                                       1, 
                                       EnvDiv_0Range>;

template <int NV>
using RampDiv2 = parameter::chain<RampDiv2_InputRange, RampDiv2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(RampDiv3_InputRange, 
                             1., 
                             32., 
                             1.);
template <int NV>
using RampDiv3_0 = parameter::from0To1<osc1_impl::tempo_sync8_t<NV>, 
                                       1, 
                                       EnvDiv_0Range>;

template <int NV>
using RampDiv3 = parameter::chain<RampDiv3_InputRange, RampDiv3_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(RampDiv4_InputRange, 
                             1., 
                             32., 
                             1.);
template <int NV>
using RampDiv4_0 = parameter::from0To1<osc1_impl::tempo_sync7_t<NV>, 
                                       1, 
                                       EnvDiv_0Range>;

template <int NV>
using RampDiv4 = parameter::chain<RampDiv4_InputRange, RampDiv4_0<NV>>;

template <int NV>
using OsMix = parameter::plain<osc1_impl::pma2_t<NV>, 2>;
template <int NV>
using OscMixMod = parameter::plain<osc1_impl::pma2_t<NV>, 1>;
template <int NV>
using Input1 = parameter::plain<osc1_impl::pma4_t<NV>, 2>;
template <int NV>
using InMod1 = parameter::plain<osc1_impl::pma4_t<NV>, 1>;
template <int NV>
using Width2 = parameter::plain<osc1_impl::pma9_t<NV>, 2>;
template <int NV>
using Width2Mod = parameter::plain<osc1_impl::pma9_t<NV>, 1>;
template <int NV>
using Bend2 = parameter::plain<core::smoother<NV>, 0>;
template <int NV> using Bend = Bend2<NV>;
template <int NV>
using WidhMod = parameter::plain<osc1_impl::pma16_t<NV>, 1>;
template <int NV>
using Width = parameter::plain<osc1_impl::pma16_t<NV>, 2>;
template <int NV>
using PositionMod = parameter::plain<osc1_impl::pma17_t<NV>, 1>;
template <int NV>
using Position = parameter::plain<osc1_impl::pma17_t<NV>, 2>;
template <int NV>
using PosSmooth = parameter::plain<filters::one_pole<NV>, 0>;
template <int NV>
using FilePitchMod = parameter::plain<osc1_impl::pma20_t<NV>, 1>;
template <int NV>
using PitchWin = parameter::plain<osc1_impl::pma_unscaled_t<NV>, 
                                  2>;
template <int NV>
using WinMod = parameter::plain<osc1_impl::pma_unscaled_t<NV>, 
                                1>;
template <int NV>
using FileInput = parameter::plain<osc1_impl::pma18_t<NV>, 2>;
template <int NV>
using FileInputMod = parameter::plain<osc1_impl::pma18_t<NV>, 1>;
template <int NV>
using FilterMix = parameter::plain<osc1_impl::pma22_t<NV>, 2>;
template <int NV>
using FilterMod = parameter::plain<osc1_impl::pma22_t<NV>, 1>;
template <int NV>
using Cut1Mod = parameter::plain<osc1_impl::pma23_t<NV>, 1>;
template <int NV>
using Cut2Mod = parameter::plain<osc1_impl::pma24_t<NV>, 1>;
using FilterOsc = parameter::empty;
using Osc2Filter2 = FilterOsc;
using osc2Gain = FilterOsc;
using PreFilterGain = FilterOsc;
template <int NV>
using a1 = parameter::plain<osc1_impl::ahdsr_t<NV>, 0>;
template <int NV>
using h1 = parameter::plain<osc1_impl::ahdsr_t<NV>, 2>;
template <int NV>
using d1 = parameter::plain<osc1_impl::ahdsr_t<NV>, 3>;
template <int NV>
using s1 = parameter::plain<osc1_impl::ahdsr_t<NV>, 4>;
template <int NV>
using r1 = parameter::plain<osc1_impl::ahdsr_t<NV>, 5>;
template <int NV>
using a2 = parameter::plain<osc1_impl::ahdsr6_t<NV>, 
                            0>;
template <int NV>
using h2 = parameter::plain<osc1_impl::ahdsr6_t<NV>, 
                            2>;
template <int NV>
using d2 = parameter::plain<osc1_impl::ahdsr6_t<NV>, 
                            3>;
template <int NV>
using s2 = parameter::plain<osc1_impl::ahdsr6_t<NV>, 
                            4>;
template <int NV>
using r2 = parameter::plain<osc1_impl::ahdsr6_t<NV>, 
                            5>;
template <int NV>
using EnvClock1 = parameter::plain<osc1_impl::branch13_t<NV>, 
                                   0>;
template <int NV>
using EnvClock12 = parameter::plain<osc1_impl::branch17_t<NV>, 
                                    0>;
template <int NV>
using EnvTrigIn1 = parameter::plain<osc1_impl::input_toggle_t<NV>, 
                                    0>;
template <int NV>
using EnvTrigIn2 = parameter::plain<osc1_impl::input_toggle2_t<NV>, 
                                    0>;
template <int NV>
using EnvType1 = parameter::plain<osc1_impl::branch14_t<NV>, 
                                  0>;
template <int NV>
using EnvType2 = parameter::plain<osc1_impl::branch18_t<NV>, 
                                  0>;
using FileInOsc1 = FilterOsc;
using FileInOsc2 = FilterOsc;
template <int NV>
using OscInput2 = parameter::plain<osc1_impl::pma5_t<NV>, 2>;
template <int NV>
using Osc2InMod = parameter::plain<osc1_impl::pma5_t<NV>, 1>;
template <int NV>
using FileXrossFade = parameter::plain<osc1_impl::pma19_t<NV>, 2>;
template <int NV>
using FileXrossFadeMod = parameter::plain<osc1_impl::pma19_t<NV>, 1>;
template <int NV>
using Gain = parameter::plain<osc1_impl::pma25_t<NV>, 2>;
template <int NV>
using GainMod = parameter::plain<osc1_impl::pma25_t<NV>, 1>;
template <int NV>
using PanMod = parameter::plain<osc1_impl::pma26_t<NV>, 1>;
using GainA = FilterOsc;
using GainH = FilterOsc;
using GainD = FilterOsc;
using GainS = FilterOsc;
using GainR = FilterOsc;
template <int NV>
using _1pMod = parameter::plain<filters::one_pole<NV>, 4>;
template <int NV>
using PosAMod = parameter::plain<osc1_impl::pma33_t<NV>, 1>;
template <int NV>
using PosA = parameter::plain<osc1_impl::pma33_t<NV>, 2>;
template <int NV>
using PosB = parameter::plain<osc1_impl::pma32_t<NV>, 2>;
template <int NV>
using PosBmod = parameter::plain<osc1_impl::pma32_t<NV>, 1>;
template <int NV>
using PosC = parameter::plain<osc1_impl::pma31_t<NV>, 2>;
template <int NV>
using PosCMod = parameter::plain<osc1_impl::pma31_t<NV>, 1>;
template <int NV>
using PosD = parameter::plain<osc1_impl::pma34_t<NV>, 2>;
template <int NV>
using PosDMod = parameter::plain<osc1_impl::pma34_t<NV>, 1>;
template <int NV>
using EnvOS1 = parameter::plain<osc1_impl::ramp_t<NV>, 1>;
template <int NV>
using EnvOS2 = parameter::plain<osc1_impl::ramp4_t<NV>, 1>;
template <int NV>
using RampTempo1 = parameter::plain<osc1_impl::tempo_sync6_t<NV>, 
                                    0>;
template <int NV>
using RampTempo2 = parameter::plain<osc1_impl::tempo_sync9_t<NV>, 
                                    0>;
template <int NV>
using RampInv1 = parameter::plain<osc1_impl::branch36_t<NV>, 
                                  0>;
template <int NV>
using RampInv2 = parameter::plain<osc1_impl::branch89_t<NV>, 
                                  0>;
template <int NV>
using RampTemo3 = parameter::plain<osc1_impl::tempo_sync8_t<NV>, 
                                   0>;
template <int NV>
using RampTempo4 = parameter::plain<osc1_impl::tempo_sync7_t<NV>, 
                                    0>;
template <int NV>
using RampInv3 = parameter::plain<osc1_impl::branch46_t<NV>, 
                                  0>;
template <int NV>
using RampInv4 = parameter::plain<osc1_impl::branch37_t<NV>, 
                                  0>;
template <int NV>
using RampOS1 = parameter::plain<osc1_impl::ramp5_t<NV>, 1>;
template <int NV>
using RampOS2 = parameter::plain<osc1_impl::ramp8_t<NV>, 1>;
template <int NV>
using RampOS3 = parameter::plain<osc1_impl::ramp7_t<NV>, 1>;
template <int NV>
using RampOS4 = parameter::plain<osc1_impl::ramp6_t<NV>, 1>;
template <int NV>
using osc1_t_plist = parameter::list<Pitch<NV>, 
                                     tempo<NV>, 
                                     div<NV>, 
                                     pitchmode<NV>, 
                                     step<NV>, 
                                     OsMix<NV>, 
                                     PitchMod<NV>, 
                                     OscMixMod<NV>, 
                                     Input1<NV>, 
                                     InMod1<NV>, 
                                     Tempo2<NV>, 
                                     MidiSlotPitch<NV>, 
                                     Width2<NV>, 
                                     Width2Mod<NV>, 
                                     Bend2<NV>, 
                                     Bend<NV>, 
                                     Shape2<NV>, 
                                     Shape<NV>, 
                                     WidhMod<NV>, 
                                     Width<NV>, 
                                     MidiWidth2<NV>, 
                                     MidiWidth<NV>, 
                                     PositionMod<NV>, 
                                     Position<NV>, 
                                     QuantisePositiion<NV>, 
                                     PosSmooth<NV>, 
                                     FilePitch<NV>, 
                                     PtichShiftOn<NV>, 
                                     FilePitchMod<NV>, 
                                     PitchWin<NV>, 
                                     WinMod<NV>, 
                                     FileInput<NV>, 
                                     FileInputMod<NV>, 
                                     FileUser<NV>, 
                                     FileMidiPitch<NV>, 
                                     FileMidipos2<NV>, 
                                     FileWinPk<NV>, 
                                     FileMidiwindow<NV>, 
                                     FileMidiInput<NV>, 
                                     Q<NV>, 
                                     FilterMix<NV>, 
                                     FilterMod<NV>, 
                                     Cut1<NV>, 
                                     Cut1Mod<NV>, 
                                     Cut2<NV>, 
                                     Cut2Mod<NV>, 
                                     FilterMidiMix<NV>, 
                                     FilterMidiCut1<NV>, 
                                     FilterMidiCut2<NV>, 
                                     FilterOsc, 
                                     Osc2Filter2, 
                                     osc2Gain, 
                                     PreFilterGain, 
                                     FilterMode<NV>, 
                                     q2<NV>, 
                                     a1<NV>, 
                                     h1<NV>, 
                                     d1<NV>, 
                                     s1<NV>, 
                                     r1<NV>, 
                                     a2<NV>, 
                                     h2<NV>, 
                                     d2<NV>, 
                                     s2<NV>, 
                                     r2<NV>, 
                                     EnvClock1<NV>, 
                                     EnvClock12<NV>, 
                                     EnvTempo1<NV>, 
                                     EnvTempo2<NV>, 
                                     EnvDiv<NV>, 
                                     EnvTrigIn1<NV>, 
                                     EnvTrigIn2<NV>, 
                                     EnvType1<NV>, 
                                     EnvType2<NV>, 
                                     PitchPkModSrc1<NV>, 
                                     Pitch2Midi<NV>, 
                                     Pitch2PkModSrc<NV>, 
                                     InSrcOsc1, 
                                     InSrcOsc2, 
                                     FileInOsc1, 
                                     FileInOsc2, 
                                     FilerInOsc1<NV>, 
                                     FilterInOSc2<NV>, 
                                     FilterInFile<NV>, 
                                     OscMixPkIn<NV>, 
                                     OscInput2<NV>, 
                                     Osc2InMod<NV>, 
                                     OscInPeak<NV>, 
                                     OscInPEak2<NV>, 
                                     Osc2Mid<NV>, 
                                     OscWidthPk<NV>, 
                                     OscWidthPk2<NV>, 
                                     FileMidPk<NV>, 
                                     FileInPk<NV>, 
                                     FileXrossFade<NV>, 
                                     FileXrossFadeMod<NV>, 
                                     FileXrossFadePk<NV>, 
                                     FileXrossFadeMode<NV>, 
                                     FileXrossFadeMidi<NV>, 
                                     FilePitchPk<NV>, 
                                     Gain<NV>, 
                                     GainMod<NV>, 
                                     PAn<NV>, 
                                     PanMod<NV>, 
                                     CutPK<NV>, 
                                     Cut2Pk<NV>, 
                                     GainMidi<NV>, 
                                     GainPk<NV>, 
                                     PanMidi<NV>, 
                                     PanPk<NV>, 
                                     FilterMixPk<NV>, 
                                     GainA, 
                                     GainH, 
                                     GainD, 
                                     GainS, 
                                     GainR, 
                                     feed, 
                                     FileIn, 
                                     OscsOut<NV>, 
                                     Pitch2<NV>, 
                                     Pitch2Mod<NV>, 
                                     Input1Midi<NV>, 
                                     _1pMod<NV>, 
                                     EnvDiv2<NV>, 
                                     PosAMod<NV>, 
                                     PosA<NV>, 
                                     PosB<NV>, 
                                     PosBmod<NV>, 
                                     PosC<NV>, 
                                     PosCMod<NV>, 
                                     PosD<NV>, 
                                     PosDMod<NV>, 
                                     EnvOS1<NV>, 
                                     EnvOS2<NV>, 
                                     RampTempo1<NV>, 
                                     RampTempo2<NV>, 
                                     RampDiv1<NV>, 
                                     RampDiv2<NV>, 
                                     RampInv1<NV>, 
                                     RampInv2<NV>, 
                                     RampTemo3<NV>, 
                                     RampTempo4<NV>, 
                                     RampDiv3<NV>, 
                                     RampDiv4<NV>, 
                                     RampInv3<NV>, 
                                     RampInv4<NV>, 
                                     RampOS1<NV>, 
                                     RampOS2<NV>, 
                                     RampOS3<NV>, 
                                     RampOS4<NV>>;
}

template <int NV>
using osc1_t_ = container::chain<osc1_t_parameters::osc1_t_plist<NV>, 
                                 wrap::fix<2, split2_t<NV>>, 
                                 chain59_t<NV>, 
                                 core::gain<NV>, 
                                 oscilloscope_t, 
                                 jdsp::jpanner<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public osc1_impl::osc1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 13;
		static const int NumSliderPacks = 20;
		static const int NumAudioFiles = 8;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 3;
		
		SNEX_METADATA_ID(osc1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(2546)
		{
			0x005B, 0x0000, 0x5000, 0x7469, 0x6863, 0x0000, 0xC000, 0x00C1, 
            0xC000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6574, 0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 
            0x4190, 0x0000, 0x4190, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x6400, 0x7669, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 0x0000, 
            0x6970, 0x6374, 0x6D68, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x4040, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 
            0x0000, 0x7300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 
            0x4F00, 0x4D73, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x3D3F, 
            0x570A, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 
            0x6950, 0x6374, 0x4D68, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0xEC3F, 0x7851, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 
            0x0000, 0x734F, 0x4D63, 0x7869, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x085B, 0x0000, 0x4900, 0x706E, 0x7475, 0x0031, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x095B, 0x0000, 0x4900, 0x4D6E, 0x646F, 0x0031, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0A5B, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x0032, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x8000, 0x3E23, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0B5B, 0x0000, 0x4D00, 0x6469, 0x5369, 0x6F6C, 0x5074, 0x7469, 
            0x6863, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000C, 0x0000, 0x6957, 0x7464, 
            0x3268, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000D, 0x0000, 0x6957, 0x7464, 
            0x3268, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0E5B, 0x0000, 0x4200, 
            0x6E65, 0x3264, 0x0000, 0x0000, 0x0000, 0x9C40, 0x3346, 0x4033, 
            0x6943, 0x6CEE, 0xCD3E, 0xCCCC, 0x5B3D, 0x000F, 0x0000, 0x6542, 
            0x646E, 0x0000, 0x0000, 0x0000, 0x9C40, 0x0046, 0xA000, 0x6941, 
            0x6CEE, 0xCD3E, 0xCCCC, 0x5B3D, 0x0010, 0x0000, 0x6853, 0x7061, 
            0x3265, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0011, 0x0000, 0x6853, 0x7061, 
            0x0065, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x4000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x125B, 0x0000, 0x5700, 0x6469, 0x4D68, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0013, 0x0000, 0x6957, 0x7464, 
            0x0068, 0x0000, 0x0000, 0x0000, 0x3F80, 0x851F, 0x3F2B, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x145B, 0x0000, 0x4D00, 0x6469, 0x5769, 
            0x6469, 0x6874, 0x0032, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x155B, 0x0000, 0x4D00, 
            0x6469, 0x5769, 0x6469, 0x6874, 0x0000, 0x8000, 0x003F, 0xE000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0016, 
            0x0000, 0x6F50, 0x6973, 0x6974, 0x6E6F, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x175B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x006E, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0xF5C3, 0x3EA8, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x185B, 0x0000, 0x5100, 0x6175, 0x746E, 0x7369, 
            0x5065, 0x736F, 0x7469, 0x6969, 0x6E6F, 0x0000, 0x8000, 0x003F, 
            0x1000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0019, 0x0000, 0x6F50, 0x5373, 0x6F6D, 0x746F, 0x0068, 0x0000, 
            0x41A0, 0x4000, 0x469C, 0x8000, 0x4493, 0x6C1A, 0x3E6B, 0x0000, 
            0x0000, 0x1A5B, 0x0000, 0x4600, 0x6C69, 0x5065, 0x7469, 0x6863, 
            0x0000, 0xC000, 0x00C1, 0xC000, 0x3341, 0x0333, 0x00C1, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x001B, 0x0000, 0x7450, 0x6369, 0x5368, 
            0x6968, 0x7466, 0x6E4F, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001C, 0x0000, 
            0x6946, 0x656C, 0x6950, 0x6374, 0x4D68, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x001D, 0x0000, 0x6950, 0x6374, 0x5768, 0x6E69, 0x0000, 
            0x4800, 0x0042, 0x1C40, 0x0A46, 0xCD9F, 0x0044, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x001E, 0x0000, 0x6957, 0x4D6E, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x001F, 0x0000, 0x6946, 0x656C, 0x6E49, 0x7570, 
            0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x205B, 0x0000, 0x4600, 0x6C69, 0x4965, 
            0x706E, 0x7475, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x215B, 0x0000, 
            0x4600, 0x6C69, 0x5565, 0x6573, 0x0072, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x225B, 
            0x0000, 0x4600, 0x6C69, 0x4D65, 0x6469, 0x5069, 0x7469, 0x6863, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0023, 0x0000, 0x6946, 0x656C, 0x694D, 
            0x6964, 0x6F70, 0x3273, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0024, 0x0000, 
            0x6946, 0x656C, 0x6957, 0x506E, 0x006B, 0x0000, 0x3F80, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x255B, 
            0x0000, 0x4600, 0x6C69, 0x4D65, 0x6469, 0x7769, 0x6E69, 0x6F64, 
            0x0077, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x265B, 0x0000, 0x4600, 0x6C69, 0x4D65, 
            0x6469, 0x4969, 0x706E, 0x7475, 0x0000, 0x8000, 0x003F, 0xE000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0027, 
            0x0000, 0x0051, 0x0000, 0x0000, 0x0000, 0x3F80, 0xEB85, 0x3F51, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x285B, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x4D72, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0029, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2A5B, 
            0x0000, 0x4300, 0x7475, 0x0031, 0x0000, 0x41A0, 0x4000, 0x469C, 
            0x4800, 0x4622, 0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x2B5B, 0x0000, 
            0x4300, 0x7475, 0x4D31, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x002C, 
            0x0000, 0x7543, 0x3274, 0x0000, 0xA000, 0x0041, 0x9C40, 0x0046, 
            0xA000, 0x1A41, 0x6B6C, 0x003E, 0x0000, 0x5B00, 0x002D, 0x0000, 
            0x7543, 0x3274, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2E5B, 0x0000, 
            0x4600, 0x6C69, 0x6574, 0x4D72, 0x6469, 0x4D69, 0x7869, 0x0000, 
            0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x002F, 0x0000, 0x6946, 0x746C, 0x7265, 0x694D, 
            0x6964, 0x7543, 0x3174, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0030, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x694D, 0x6964, 0x7543, 0x3274, 0x0000, 
            0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0031, 0x0000, 0x6946, 0x746C, 0x7265, 0x734F, 
            0x0063, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x325B, 0x0000, 0x4F00, 0x6373, 0x4632, 
            0x6C69, 0x6574, 0x3272, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0033, 0x0000, 
            0x736F, 0x3263, 0x6147, 0x6E69, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0xCD3F, 0x4CCC, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0034, 
            0x0000, 0x7250, 0x4665, 0x6C69, 0x6574, 0x4772, 0x6961, 0x006E, 
            0x0000, 0xC2C8, 0x0000, 0x41C0, 0x0000, 0x35C8, 0x833E, 0x40AD, 
            0xCCCD, 0x3DCC, 0x355B, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 
            0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x365B, 0x0000, 0x7100, 0x0032, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x999A, 0x3F59, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x375B, 0x0000, 0x6100, 0x0031, 0x0000, 0x0000, 
            0x4000, 0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 
            0x385B, 0x0000, 0x6800, 0x0031, 0x0000, 0x0000, 0x4000, 0x461C, 
            0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x395B, 0x0000, 
            0x6400, 0x0031, 0x0000, 0x0000, 0x4000, 0x461C, 0x4000, 0x461C, 
            0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x3A5B, 0x0000, 0x7300, 0x0031, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x3B5B, 0x0000, 0x7200, 0x0031, 0x0000, 0x0000, 
            0x4000, 0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 
            0x3C5B, 0x0000, 0x6100, 0x0032, 0x0000, 0x0000, 0x4000, 0x461C, 
            0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x3D5B, 0x0000, 
            0x6800, 0x0032, 0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 0x0000, 
            0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x3E5B, 0x0000, 0x6400, 0x0032, 
            0x0000, 0x0000, 0x4000, 0x461C, 0x0000, 0x4188, 0x6A72, 0x3E4A, 
            0xCCCD, 0x3DCC, 0x3F5B, 0x0000, 0x7300, 0x0032, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x405B, 0x0000, 0x7200, 0x0032, 0x0000, 0x0000, 0x4000, 0x461C, 
            0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x415B, 0x0000, 
            0x4500, 0x766E, 0x6C43, 0x636F, 0x316B, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0042, 0x0000, 0x6E45, 0x4376, 0x6F6C, 0x6B63, 0x3231, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0043, 0x0000, 0x6E45, 0x5476, 0x6D65, 0x6F70, 
            0x0031, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x445B, 0x0000, 0x4500, 0x766E, 0x6554, 
            0x706D, 0x326F, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0045, 0x0000, 0x6E45, 
            0x4476, 0x7669, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x3000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0046, 0x0000, 0x6E45, 
            0x5476, 0x6972, 0x4967, 0x316E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0047, 
            0x0000, 0x6E45, 0x5476, 0x6972, 0x4967, 0x326E, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0048, 0x0000, 0x6E45, 0x5476, 0x7079, 0x3165, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0049, 0x0000, 0x6E45, 0x5476, 0x7079, 0x3265, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x004A, 0x0000, 0x6950, 0x6374, 0x5068, 
            0x4D6B, 0x646F, 0x7253, 0x3163, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 0x004B, 
            0x0000, 0x6950, 0x6374, 0x3268, 0x694D, 0x6964, 0x0000, 0x8000, 
            0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x004C, 0x0000, 0x6950, 0x6374, 0x3268, 0x6B50, 0x6F4D, 
            0x5364, 0x6372, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x004D, 0x0000, 0x6E49, 
            0x7253, 0x4F63, 0x6373, 0x0031, 0x0000, 0x3F80, 0x0000, 0x4040, 
            0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x4E5B, 0x0000, 
            0x4900, 0x536E, 0x6372, 0x734F, 0x3263, 0x0000, 0x8000, 0x003F, 
            0x4000, 0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x004F, 0x0000, 0x6946, 0x656C, 0x6E49, 0x734F, 0x3163, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0050, 0x0000, 0x6946, 0x656C, 0x6E49, 0x734F, 
            0x3263, 0x0000, 0x0000, 0x0000, 0x8000, 0x103F, 0x5E58, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0051, 0x0000, 0x6946, 0x656C, 
            0x4972, 0x4F6E, 0x6373, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x525B, 0x0000, 
            0x4600, 0x6C69, 0x6574, 0x4972, 0x4F6E, 0x6353, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x535B, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4972, 0x466E, 
            0x6C69, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x545B, 0x0000, 0x4F00, 0x6373, 
            0x694D, 0x5078, 0x496B, 0x006E, 0x0000, 0x3F80, 0x0000, 0x4080, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x555B, 0x0000, 
            0x4F00, 0x6373, 0x6E49, 0x7570, 0x3274, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0056, 0x0000, 0x734F, 0x3263, 0x6E49, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x575B, 0x0000, 0x4F00, 0x6373, 0x6E49, 0x6550, 0x6B61, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0058, 0x0000, 0x734F, 0x4963, 0x506E, 
            0x6145, 0x326B, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0059, 0x0000, 0x734F, 
            0x3263, 0x694D, 0x0064, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x5A5B, 0x0000, 0x4F00, 
            0x6373, 0x6957, 0x7464, 0x5068, 0x006B, 0x0000, 0x3F80, 0x0000, 
            0x4080, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x5B5B, 
            0x0000, 0x4F00, 0x6373, 0x6957, 0x7464, 0x5068, 0x326B, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x005C, 0x0000, 0x6946, 0x656C, 0x694D, 0x5064, 
            0x006B, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x4000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x5D5B, 0x0000, 0x4600, 0x6C69, 0x4965, 
            0x506E, 0x006B, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x5E5B, 0x0000, 0x4600, 0x6C69, 
            0x5865, 0x6F72, 0x7373, 0x6146, 0x6564, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x005F, 0x0000, 0x6946, 0x656C, 0x7258, 0x736F, 0x4673, 0x6461, 
            0x4D65, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0060, 0x0000, 0x6946, 
            0x656C, 0x7258, 0x736F, 0x4673, 0x6461, 0x5065, 0x006B, 0x0000, 
            0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x615B, 0x0000, 0x4600, 0x6C69, 0x5865, 0x6F72, 0x7373, 
            0x6146, 0x6564, 0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0062, 
            0x0000, 0x6946, 0x656C, 0x7258, 0x736F, 0x4673, 0x6461, 0x4D65, 
            0x6469, 0x0069, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x635B, 0x0000, 0x4600, 0x6C69, 
            0x5065, 0x7469, 0x6863, 0x6B50, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0064, 
            0x0000, 0x6147, 0x6E69, 0x0000, 0x0000, 0x0000, 0x8000, 0x3D3F, 
            0xD70A, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0065, 0x0000, 
            0x6147, 0x6E69, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x665B, 0x0000, 
            0x5000, 0x6E41, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0067, 0x0000, 0x6150, 
            0x4D6E, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0068, 0x0000, 0x7543, 
            0x5074, 0x004B, 0x0000, 0x4040, 0x0000, 0x4160, 0x0000, 0x4040, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x695B, 0x0000, 0x4300, 0x7475, 
            0x5032, 0x006B, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x6A5B, 0x0000, 0x4700, 0x6961, 
            0x4D6E, 0x6469, 0x0069, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x6B5B, 0x0000, 0x4700, 
            0x6961, 0x506E, 0x006B, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x6C5B, 0x0000, 0x5000, 
            0x6E61, 0x694D, 0x6964, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x006D, 0x0000, 
            0x6150, 0x506E, 0x006B, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x6E5B, 0x0000, 0x4600, 
            0x6C69, 0x6574, 0x4D72, 0x7869, 0x6B50, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x006F, 0x0000, 0x6147, 0x6E69, 0x0041, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x705B, 
            0x0000, 0x4700, 0x6961, 0x486E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0071, 
            0x0000, 0x6147, 0x6E69, 0x0044, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x725B, 0x0000, 
            0x4700, 0x6961, 0x536E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0073, 0x0000, 
            0x6147, 0x6E69, 0x0052, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x745B, 0x0000, 0x6600, 
            0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0xC28F, 0x3EF5, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x755B, 0x0000, 0x4600, 0x6C69, 
            0x4965, 0x006E, 0x0000, 0x0000, 0x0000, 0x3F00, 0x0000, 0x3F00, 
            0xF532, 0x3F1E, 0x0000, 0x0000, 0x765B, 0x0000, 0x4F00, 0x6373, 
            0x4F73, 0x7475, 0x0000, 0xC800, 0x00C2, 0x0000, 0x0000, 0x0000, 
            0x3E00, 0xAD83, 0xCD40, 0xCCCC, 0x5B3D, 0x0077, 0x0000, 0x6950, 
            0x6374, 0x3268, 0x0000, 0xC000, 0x00C1, 0xC000, 0x0041, 0xC000, 
            0x00C1, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0078, 0x0000, 0x6950, 
            0x6374, 0x3268, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x795B, 0x0000, 
            0x4900, 0x706E, 0x7475, 0x4D31, 0x6469, 0x0069, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x7A5B, 0x0000, 0x5F00, 0x7031, 0x6F4D, 0x0064, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x7B5B, 0x0000, 0x4500, 0x766E, 0x6944, 0x3276, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x007C, 0x0000, 0x6F50, 0x4173, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x7D5B, 0x0000, 0x5000, 0x736F, 0x0041, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x7E5B, 0x0000, 0x5000, 0x736F, 0x0042, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x7F5B, 
            0x0000, 0x5000, 0x736F, 0x6D42, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0080, 0x0000, 0x6F50, 0x4373, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0081, 
            0x0000, 0x6F50, 0x4373, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x825B, 
            0x0000, 0x5000, 0x736F, 0x0044, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x835B, 0x0000, 
            0x5000, 0x736F, 0x4D44, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0084, 
            0x0000, 0x6E45, 0x4F76, 0x3153, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0085, 
            0x0000, 0x6E45, 0x4F76, 0x3253, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x7900, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0086, 
            0x0000, 0x6152, 0x706D, 0x6554, 0x706D, 0x316F, 0x0000, 0x0000, 
            0x0000, 0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0087, 0x0000, 0x6152, 0x706D, 0x6554, 0x706D, 0x326F, 
            0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0088, 0x0000, 0x6152, 0x706D, 0x6944, 
            0x3176, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x8000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0089, 0x0000, 0x6152, 0x706D, 
            0x6944, 0x3276, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 0x8000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x008A, 0x0000, 0x6152, 
            0x706D, 0x6E49, 0x3176, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x008B, 0x0000, 
            0x6152, 0x706D, 0x6E49, 0x3276, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x008C, 
            0x0000, 0x6152, 0x706D, 0x6554, 0x6F6D, 0x0033, 0x0000, 0x0000, 
            0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x8D5B, 0x0000, 0x5200, 0x6D61, 0x5470, 0x6D65, 0x6F70, 0x0034, 
            0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x8E5B, 0x0000, 0x5200, 0x6D61, 0x4470, 0x7669, 
            0x0033, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 0x4180, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x8F5B, 0x0000, 0x5200, 0x6D61, 0x4470, 
            0x7669, 0x0034, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 0x4140, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x905B, 0x0000, 0x5200, 0x6D61, 
            0x4970, 0x766E, 0x0033, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x915B, 0x0000, 0x5200, 
            0x6D61, 0x4970, 0x766E, 0x0034, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x925B, 0x0000, 
            0x5200, 0x6D61, 0x4F70, 0x3153, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0093, 
            0x0000, 0x6152, 0x706D, 0x534F, 0x0032, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x945B, 
            0x0000, 0x5200, 0x6D61, 0x4F70, 0x3353, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0095, 0x0000, 0x6152, 0x706D, 0x534F, 0x0034, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split2 = this->getT(0);                                                        // osc1_impl::split2_t<NV>
		auto& modchain1 = this->getT(0).getT(0);                                             // osc1_impl::modchain1_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0);                                   // osc1_impl::sliderbank3_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1);                                        // osc1_impl::split3_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(0);                               // osc1_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                          // math::add<NV>
		auto& gain13 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(1);                               // osc1_impl::chain41_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                // osc1_impl::global_cable11_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain15 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(2);                               // osc1_impl::chain40_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(2).getT(0);                // osc1_impl::global_cable10_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                          // math::add<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(3);                               // osc1_impl::chain42_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                // osc1_impl::global_cable14_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(4);                               // osc1_impl::chain44_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                         // math::add<NV>
		auto& gain32 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                        // core::gain<NV>
		auto& chain43 = this->getT(0).getT(0).getT(1).getT(5);                               // osc1_impl::chain43_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(0);                         // math::add<NV>
		auto& gain26 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                        // core::gain<NV>
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(6);                               // osc1_impl::chain45_t<NV>
		auto& branch15 = this->getT(0).getT(0).getT(1).getT(6).getT(0);                      // osc1_impl::branch15_t<NV>
		auto& add3 = this->getT(0).getT(0).getT(1).getT(6).getT(0).getT(0);                  // math::add<NV>
		auto& add23 = this->getT(0).getT(0).getT(1).getT(6).getT(0).getT(1);                 // math::add<NV>
		auto& add21 = this->getT(0).getT(0).getT(1).getT(6).getT(0).getT(2);                 // math::add<NV>
		auto& add9 = this->getT(0).getT(0).getT(1).getT(6).getT(0).getT(3);                  // math::add<NV>
		auto& gain33 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                        // core::gain<NV>
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(7);                               // osc1_impl::chain46_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                       // osc1_impl::branch5_t<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0);               // osc1_impl::chain13_t<NV>
		auto& midi_cc10 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc10_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1);               // osc1_impl::chain18_t<NV>
		auto& midi_cc11 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc11_t<NV>
		auto& add51 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2);               // osc1_impl::chain22_t<NV>
		auto& midi_cc12 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc12_t<NV>
		auto& add52 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3);               // osc1_impl::chain24_t<NV>
		auto& midi_cc13 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc13_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4);               // osc1_impl::chain25_t<NV>
		auto& midi6 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4).getT(0);         // osc1_impl::midi6_t<NV>
		auto& add54 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5);               // osc1_impl::chain26_t<NV>
		auto& midi7 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5).getT(0);         // osc1_impl::midi7_t<NV>
		auto& add55 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6);               // osc1_impl::chain27_t<NV>
		auto& midi8 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6).getT(0);         // osc1_impl::midi8_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain34 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2);                                         // osc1_impl::peak3_t<NV>
		auto& clear = this->getT(0).getT(0).getT(3);                                         // math::clear<NV>
		auto& chain20 = this->getT(0).getT(0).getT(4);                                       // osc1_impl::chain20_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(4).getT(0);                               // osc1_impl::branch3_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(4).getT(0).getT(0);                       // osc1_impl::chain17_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0);                  // osc1_impl::pma1_t<NV>
		auto& add = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1);                   // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                       // osc1_impl::chain21_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0);                  // osc1_impl::pma8_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1);                 // math::add<NV>
		auto& chain23 = this->getT(0).getT(0).getT(4).getT(0).getT(2);                       // osc1_impl::chain23_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(0);                 // osc1_impl::pma11_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(1);                 // math::add<NV>
		auto& smoother = this->getT(0).getT(0).getT(4).getT(1);                              // core::smoother<NV>
		auto& peak = this->getT(0).getT(0).getT(4).getT(2);                                  // osc1_impl::peak_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(5);                                        // osc1_impl::split7_t
		auto& modchain5 = this->getT(0).getT(1);                                             // osc1_impl::modchain5_t<NV>
		auto& sliderbank5 = this->getT(0).getT(1).getT(0);                                   // osc1_impl::sliderbank5_t<NV>
		auto& split8 = this->getT(0).getT(1).getT(1);                                        // osc1_impl::split8_t<NV>
		auto& chain136 = this->getT(0).getT(1).getT(1).getT(0);                              // osc1_impl::chain136_t<NV>
		auto& global_cable5 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable5_t<NV>
		auto& add8 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                          // math::add<NV>
		auto& gain21 = this->getT(0).getT(1).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain137 = this->getT(0).getT(1).getT(1).getT(1);                              // osc1_impl::chain137_t<NV>
		auto& global_cable15 = this->getT(0).getT(1).getT(1).getT(1).getT(0);                // osc1_impl::global_cable15_t<NV>
		auto& add37 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain22 = this->getT(0).getT(1).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain138 = this->getT(0).getT(1).getT(1).getT(2);                              // osc1_impl::chain138_t<NV>
		auto& global_cable18 = this->getT(0).getT(1).getT(1).getT(2).getT(0);                // osc1_impl::global_cable18_t<NV>
		auto& add12 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                         // math::add<NV>
		auto& gain23 = this->getT(0).getT(1).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain139 = this->getT(0).getT(1).getT(1).getT(3);                              // osc1_impl::chain139_t<NV>
		auto& global_cable19 = this->getT(0).getT(1).getT(1).getT(3).getT(0);                // osc1_impl::global_cable19_t<NV>
		auto& add49 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain24 = this->getT(0).getT(1).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain140 = this->getT(0).getT(1).getT(1).getT(4);                              // osc1_impl::chain140_t<NV>
		auto& add64 = this->getT(0).getT(1).getT(1).getT(4).getT(0);                         // math::add<NV>
		auto& gain38 = this->getT(0).getT(1).getT(1).getT(4).getT(1);                        // core::gain<NV>
		auto& chain141 = this->getT(0).getT(1).getT(1).getT(5);                              // osc1_impl::chain141_t<NV>
		auto& add65 = this->getT(0).getT(1).getT(1).getT(5).getT(0);                         // math::add<NV>
		auto& gain28 = this->getT(0).getT(1).getT(1).getT(5).getT(1);                        // core::gain<NV>
		auto& chain142 = this->getT(0).getT(1).getT(1).getT(6);                              // osc1_impl::chain142_t<NV>
		auto& branch16 = this->getT(0).getT(1).getT(1).getT(6).getT(0);                      // osc1_impl::branch16_t<NV>
		auto& add25 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(0);                 // math::add<NV>
		auto& add30 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(1);                 // math::add<NV>
		auto& add74 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(2);                 // math::add<NV>
		auto& add99 = this->getT(0).getT(1).getT(1).getT(6).getT(0).getT(3);                 // math::add<NV>
		auto& gain39 = this->getT(0).getT(1).getT(1).getT(6).getT(1);                        // core::gain<NV>
		auto& chain143 = this->getT(0).getT(1).getT(1).getT(7);                              // osc1_impl::chain143_t<NV>
		auto& branch11 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                      // osc1_impl::branch11_t<NV>
		auto& chain144 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain144_t<NV>
		auto& midi_cc18 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc18_t<NV>
		auto& add67 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain145 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain145_t<NV>
		auto& midi_cc19 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc19_t<NV>
		auto& add68 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain146 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain146_t<NV>
		auto& midi_cc20 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc20_t<NV>
		auto& add69 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain147 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain147_t<NV>
		auto& midi_cc21 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc21_t<NV>
		auto& add70 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain148 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain148_t<NV>
		auto& midi12 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi12_t<NV>
		auto& add71 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain149 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain149_t<NV>
		auto& midi13 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi13_t<NV>
		auto& add72 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain150 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain150_t<NV>
		auto& midi14 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi14_t<NV>
		auto& add73 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain40 = this->getT(0).getT(1).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak5 = this->getT(0).getT(1).getT(2);                                         // osc1_impl::peak5_t<NV>
		auto& clear3 = this->getT(0).getT(1).getT(3);                                        // math::clear<NV>
		auto& chain151 = this->getT(0).getT(1).getT(4);                                      // osc1_impl::chain151_t<NV>
		auto& branch12 = this->getT(0).getT(1).getT(4).getT(0);                              // osc1_impl::branch12_t<NV>
		auto& chain152 = this->getT(0).getT(1).getT(4).getT(0).getT(0);                      // osc1_impl::chain152_t<NV>
		auto& pma3 = this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(0);                  // osc1_impl::pma3_t<NV>
		auto& add1 = this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(1);                  // math::add<NV>
		auto& chain154 = this->getT(0).getT(1).getT(4).getT(0).getT(1);                      // osc1_impl::chain154_t<NV>
		auto& pma14 = this->getT(0).getT(1).getT(4).getT(0).getT(1).getT(0);                 // osc1_impl::pma14_t<NV>
		auto& add18 = this->getT(0).getT(1).getT(4).getT(0).getT(1).getT(1);                 // math::add<NV>
		auto& chain155 = this->getT(0).getT(1).getT(4).getT(0).getT(2);                      // osc1_impl::chain155_t<NV>
		auto& pma15 = this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(0);                 // osc1_impl::pma15_t<NV>
		auto& add13 = this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(1);                 // math::add<NV>
		auto& smoother1 = this->getT(0).getT(1).getT(4).getT(1);                             // core::smoother<NV>
		auto& peak1 = this->getT(0).getT(1).getT(4).getT(2);                                 // osc1_impl::peak1_t<NV>
		auto& modchain2 = this->getT(0).getT(2);                                             // osc1_impl::modchain2_t<NV>
		auto& sliderbank4 = this->getT(0).getT(2).getT(0);                                   // osc1_impl::sliderbank4_t<NV>
		auto& split4 = this->getT(0).getT(2).getT(1);                                        // osc1_impl::split4_t<NV>
		auto& chain47 = this->getT(0).getT(2).getT(1).getT(0);                               // osc1_impl::chain47_t<NV>
		auto& global_cable4 = this->getT(0).getT(2).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable4_t<NV>
		auto& add6 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                          // math::add<NV>
		auto& gain17 = this->getT(0).getT(2).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain48 = this->getT(0).getT(2).getT(1).getT(1);                               // osc1_impl::chain48_t<NV>
		auto& global_cable12 = this->getT(0).getT(2).getT(1).getT(1).getT(0);                // osc1_impl::global_cable12_t<NV>
		auto& add32 = this->getT(0).getT(2).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain18 = this->getT(0).getT(2).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain49 = this->getT(0).getT(2).getT(1).getT(2);                               // osc1_impl::chain49_t<NV>
		auto& global_cable13 = this->getT(0).getT(2).getT(1).getT(2).getT(0);                // osc1_impl::global_cable13_t<NV>
		auto& add7 = this->getT(0).getT(2).getT(1).getT(2).getT(1);                          // math::add<NV>
		auto& gain19 = this->getT(0).getT(2).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain50 = this->getT(0).getT(2).getT(1).getT(3);                               // osc1_impl::chain50_t<NV>
		auto& global_cable25 = this->getT(0).getT(2).getT(1).getT(3).getT(0);                // osc1_impl::global_cable25_t<NV>
		auto& add33 = this->getT(0).getT(2).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain20 = this->getT(0).getT(2).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain51 = this->getT(0).getT(2).getT(1).getT(4);                               // osc1_impl::chain51_t<NV>
		auto& add34 = this->getT(0).getT(2).getT(1).getT(4).getT(0);                         // math::add<NV>
		auto& gain35 = this->getT(0).getT(2).getT(1).getT(4).getT(1);                        // core::gain<NV>
		auto& chain52 = this->getT(0).getT(2).getT(1).getT(5);                               // osc1_impl::chain52_t<NV>
		auto& add35 = this->getT(0).getT(2).getT(1).getT(5).getT(0);                         // math::add<NV>
		auto& gain27 = this->getT(0).getT(2).getT(1).getT(5).getT(1);                        // core::gain<NV>
		auto& chain53 = this->getT(0).getT(2).getT(1).getT(6);                               // osc1_impl::chain53_t<NV>
		auto& branch19 = this->getT(0).getT(2).getT(1).getT(6).getT(0);                      // osc1_impl::branch19_t<NV>
		auto& add103 = this->getT(0).getT(2).getT(1).getT(6).getT(0).getT(0);                // math::add<NV>
		auto& add104 = this->getT(0).getT(2).getT(1).getT(6).getT(0).getT(1);                // math::add<NV>
		auto& add105 = this->getT(0).getT(2).getT(1).getT(6).getT(0).getT(2);                // math::add<NV>
		auto& add106 = this->getT(0).getT(2).getT(1).getT(6).getT(0).getT(3);                // math::add<NV>
		auto& add36 = this->getT(0).getT(2).getT(1).getT(6).getT(1);                         // math::add<NV>
		auto& gain36 = this->getT(0).getT(2).getT(1).getT(6).getT(2);                        // core::gain<NV>
		auto& chain54 = this->getT(0).getT(2).getT(1).getT(7);                               // osc1_impl::chain54_t<NV>
		auto& branch4 = this->getT(0).getT(2).getT(1).getT(7).getT(0);                       // osc1_impl::branch4_t<NV>
		auto& chain = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0);                 // osc1_impl::chain_t<NV>
		auto& midi_cc3 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0).getT(0);      // osc1_impl::midi_cc3_t<NV>
		auto& add31 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain4 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1);                // osc1_impl::chain4_t<NV>
		auto& midi_cc5 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1).getT(0);      // osc1_impl::midi_cc5_t<NV>
		auto& add38 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain5 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2);                // osc1_impl::chain5_t<NV>
		auto& midi_cc7 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2).getT(0);      // osc1_impl::midi_cc7_t<NV>
		auto& add39 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain6 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3);                // osc1_impl::chain6_t<NV>
		auto& midi_cc8 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3).getT(0);      // osc1_impl::midi_cc8_t<NV>
		auto& add40 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain7 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4);                // osc1_impl::chain7_t<NV>
		auto& midi1 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4).getT(0);         // osc1_impl::midi1_t<NV>
		auto& add41 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain9 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5);                // osc1_impl::chain9_t<NV>
		auto& midi3 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5).getT(0);         // osc1_impl::midi3_t<NV>
		auto& add42 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain11 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6);               // osc1_impl::chain11_t<NV>
		auto& midi5 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6).getT(0);         // osc1_impl::midi5_t<NV>
		auto& add43 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain37 = this->getT(0).getT(2).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak4 = this->getT(0).getT(2).getT(2);                                         // osc1_impl::peak4_t<NV>
		auto& pma2 = this->getT(0).getT(2).getT(3);                                          // osc1_impl::pma2_t<NV>
		auto& modchain4 = this->getT(0).getT(3);                                             // osc1_impl::modchain4_t<NV>
		auto& sliderbank6 = this->getT(0).getT(3).getT(0);                                   // osc1_impl::sliderbank6_t<NV>
		auto& split6 = this->getT(0).getT(3).getT(1);                                        // osc1_impl::split6_t<NV>
		auto& chain63 = this->getT(0).getT(3).getT(1).getT(0);                               // osc1_impl::chain63_t<NV>
		auto& global_cable6 = this->getT(0).getT(3).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable6_t<NV>
		auto& add10 = this->getT(0).getT(3).getT(1).getT(0).getT(1);                         // math::add<NV>
		auto& gain25 = this->getT(0).getT(3).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain64 = this->getT(0).getT(3).getT(1).getT(1);                               // osc1_impl::chain64_t<NV>
		auto& global_cable16 = this->getT(0).getT(3).getT(1).getT(1).getT(0);                // osc1_impl::global_cable16_t<NV>
		auto& add44 = this->getT(0).getT(3).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain29 = this->getT(0).getT(3).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain65 = this->getT(0).getT(3).getT(1).getT(2);                               // osc1_impl::chain65_t<NV>
		auto& global_cable17 = this->getT(0).getT(3).getT(1).getT(2).getT(0);                // osc1_impl::global_cable17_t<NV>
		auto& add11 = this->getT(0).getT(3).getT(1).getT(2).getT(1);                         // math::add<NV>
		auto& gain30 = this->getT(0).getT(3).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain66 = this->getT(0).getT(3).getT(1).getT(3);                               // osc1_impl::chain66_t<NV>
		auto& global_cable26 = this->getT(0).getT(3).getT(1).getT(3).getT(0);                // osc1_impl::global_cable26_t<NV>
		auto& add45 = this->getT(0).getT(3).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain31 = this->getT(0).getT(3).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain67 = this->getT(0).getT(3).getT(1).getT(4);                               // osc1_impl::chain67_t<NV>
		auto& add46 = this->getT(0).getT(3).getT(1).getT(4).getT(0);                         // math::add<NV>
		auto& gain41 = this->getT(0).getT(3).getT(1).getT(4).getT(1);                        // core::gain<NV>
		auto& chain68 = this->getT(0).getT(3).getT(1).getT(5);                               // osc1_impl::chain68_t<NV>
		auto& add47 = this->getT(0).getT(3).getT(1).getT(5).getT(0);                         // math::add<NV>
		auto& gain42 = this->getT(0).getT(3).getT(1).getT(5).getT(1);                        // core::gain<NV>
		auto& chain69 = this->getT(0).getT(3).getT(1).getT(6);                               // osc1_impl::chain69_t<NV>
		auto& branch20 = this->getT(0).getT(3).getT(1).getT(6).getT(0);                      // osc1_impl::branch20_t<NV>
		auto& add107 = this->getT(0).getT(3).getT(1).getT(6).getT(0).getT(0);                // math::add<NV>
		auto& add108 = this->getT(0).getT(3).getT(1).getT(6).getT(0).getT(1);                // math::add<NV>
		auto& add109 = this->getT(0).getT(3).getT(1).getT(6).getT(0).getT(2);                // math::add<NV>
		auto& add110 = this->getT(0).getT(3).getT(1).getT(6).getT(0).getT(3);                // math::add<NV>
		auto& add48 = this->getT(0).getT(3).getT(1).getT(6).getT(1);                         // math::add<NV>
		auto& gain43 = this->getT(0).getT(3).getT(1).getT(6).getT(2);                        // core::gain<NV>
		auto& chain70 = this->getT(0).getT(3).getT(1).getT(7);                               // osc1_impl::chain70_t<NV>
		auto& branch6 = this->getT(0).getT(3).getT(1).getT(7).getT(0);                       // osc1_impl::branch6_t<NV>
		auto& chain28 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(0);               // osc1_impl::chain28_t<NV>
		auto& midi_cc14 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc14_t<NV>
		auto& add57 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain29 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(1);               // osc1_impl::chain29_t<NV>
		auto& midi_cc15 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc15_t<NV>
		auto& add58 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain30 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(2);               // osc1_impl::chain30_t<NV>
		auto& midi_cc16 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc16_t<NV>
		auto& add59 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain31 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(3);               // osc1_impl::chain31_t<NV>
		auto& midi_cc17 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc17_t<NV>
		auto& add60 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain32 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(4);               // osc1_impl::chain32_t<NV>
		auto& midi9 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(4).getT(0);         // osc1_impl::midi9_t<NV>
		auto& add61 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain33 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(5);               // osc1_impl::chain33_t<NV>
		auto& midi10 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi10_t<NV>
		auto& add62 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain34 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(6);               // osc1_impl::chain34_t<NV>
		auto& midi11 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi11_t<NV>
		auto& add63 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain44 = this->getT(0).getT(3).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak6 = this->getT(0).getT(3).getT(2);                                         // osc1_impl::peak6_t<NV>
		auto& pma4 = this->getT(0).getT(3).getT(3);                                          // osc1_impl::pma4_t<NV>
		auto& modchain9 = this->getT(0).getT(4);                                             // osc1_impl::modchain9_t<NV>
		auto& sliderbank7 = this->getT(0).getT(4).getT(0);                                   // osc1_impl::sliderbank7_t<NV>
		auto& split15 = this->getT(0).getT(4).getT(1);                                       // osc1_impl::split15_t<NV>
		auto& chain89 = this->getT(0).getT(4).getT(1).getT(0);                               // osc1_impl::chain89_t<NV>
		auto& global_cable7 = this->getT(0).getT(4).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable7_t<NV>
		auto& add111 = this->getT(0).getT(4).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain48 = this->getT(0).getT(4).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain90 = this->getT(0).getT(4).getT(1).getT(1);                               // osc1_impl::chain90_t<NV>
		auto& global_cable24 = this->getT(0).getT(4).getT(1).getT(1).getT(0);                // osc1_impl::global_cable24_t<NV>
		auto& add112 = this->getT(0).getT(4).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain61 = this->getT(0).getT(4).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain153 = this->getT(0).getT(4).getT(1).getT(2);                              // osc1_impl::chain153_t<NV>
		auto& global_cable27 = this->getT(0).getT(4).getT(1).getT(2).getT(0);                // osc1_impl::global_cable27_t<NV>
		auto& add113 = this->getT(0).getT(4).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain66 = this->getT(0).getT(4).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain156 = this->getT(0).getT(4).getT(1).getT(3);                              // osc1_impl::chain156_t<NV>
		auto& global_cable30 = this->getT(0).getT(4).getT(1).getT(3).getT(0);                // osc1_impl::global_cable30_t<NV>
		auto& add114 = this->getT(0).getT(4).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain67 = this->getT(0).getT(4).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain157 = this->getT(0).getT(4).getT(1).getT(4);                              // osc1_impl::chain157_t<NV>
		auto& add115 = this->getT(0).getT(4).getT(1).getT(4).getT(0);                        // math::add<NV>
		auto& gain68 = this->getT(0).getT(4).getT(1).getT(4).getT(1);                        // core::gain<NV>
		auto& chain158 = this->getT(0).getT(4).getT(1).getT(5);                              // osc1_impl::chain158_t<NV>
		auto& add116 = this->getT(0).getT(4).getT(1).getT(5).getT(0);                        // math::add<NV>
		auto& gain69 = this->getT(0).getT(4).getT(1).getT(5).getT(1);                        // core::gain<NV>
		auto& chain159 = this->getT(0).getT(4).getT(1).getT(6);                              // osc1_impl::chain159_t<NV>
		auto& branch24 = this->getT(0).getT(4).getT(1).getT(6).getT(0);                      // osc1_impl::branch24_t<NV>
		auto& add117 = this->getT(0).getT(4).getT(1).getT(6).getT(0).getT(0);                // math::add<NV>
		auto& add118 = this->getT(0).getT(4).getT(1).getT(6).getT(0).getT(1);                // math::add<NV>
		auto& add119 = this->getT(0).getT(4).getT(1).getT(6).getT(0).getT(2);                // math::add<NV>
		auto& add120 = this->getT(0).getT(4).getT(1).getT(6).getT(0).getT(3);                // math::add<NV>
		auto& add121 = this->getT(0).getT(4).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain70 = this->getT(0).getT(4).getT(1).getT(6).getT(2);                        // core::gain<NV>
		auto& chain160 = this->getT(0).getT(4).getT(1).getT(7);                              // osc1_impl::chain160_t<NV>
		auto& branch25 = this->getT(0).getT(4).getT(1).getT(7).getT(0);                      // osc1_impl::branch25_t<NV>
		auto& chain38 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(0);               // osc1_impl::chain38_t<NV>
		auto& midi_cc4 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(0).getT(0);      // osc1_impl::midi_cc4_t<NV>
		auto& add122 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain166 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain166_t<NV>
		auto& midi_cc6 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(1).getT(0);      // osc1_impl::midi_cc6_t<NV>
		auto& add123 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain167 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain167_t<NV>
		auto& midi_cc9 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(2).getT(0);      // osc1_impl::midi_cc9_t<NV>
		auto& add124 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain169 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain169_t<NV>
		auto& midi_cc30 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc30_t<NV>
		auto& add125 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain171 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain171_t<NV>
		auto& midi2 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(4).getT(0);         // osc1_impl::midi2_t<NV>
		auto& add126 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain172 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain172_t<NV>
		auto& midi21 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi21_t<NV>
		auto& add127 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain173 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain173_t<NV>
		auto& midi22 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi22_t<NV>
		auto& add128 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain71 = this->getT(0).getT(4).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak11 = this->getT(0).getT(4).getT(2);                                        // osc1_impl::peak11_t<NV>
		auto& pma5 = this->getT(0).getT(4).getT(3);                                          // osc1_impl::pma5_t<NV>
		auto& modchain12 = this->getT(0).getT(5);                                            // osc1_impl::modchain12_t<NV>
		auto& sliderbank12 = this->getT(0).getT(5).getT(0);                                  // osc1_impl::sliderbank12_t<NV>
		auto& split26 = this->getT(0).getT(5).getT(1);                                       // osc1_impl::split26_t<NV>
		auto& chain215 = this->getT(0).getT(5).getT(1).getT(0);                              // osc1_impl::chain215_t<NV>
		auto& global_cable39 = this->getT(0).getT(5).getT(1).getT(0).getT(0);                // osc1_impl::global_cable39_t<NV>
		auto& add161 = this->getT(0).getT(5).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain116 = this->getT(0).getT(5).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain216 = this->getT(0).getT(5).getT(1).getT(1);                              // osc1_impl::chain216_t<NV>
		auto& global_cable40 = this->getT(0).getT(5).getT(1).getT(1).getT(0);                // osc1_impl::global_cable40_t<NV>
		auto& add162 = this->getT(0).getT(5).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain117 = this->getT(0).getT(5).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain217 = this->getT(0).getT(5).getT(1).getT(2);                              // osc1_impl::chain217_t<NV>
		auto& global_cable41 = this->getT(0).getT(5).getT(1).getT(2).getT(0);                // osc1_impl::global_cable41_t<NV>
		auto& add163 = this->getT(0).getT(5).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain118 = this->getT(0).getT(5).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain218 = this->getT(0).getT(5).getT(1).getT(3);                              // osc1_impl::chain218_t<NV>
		auto& global_cable42 = this->getT(0).getT(5).getT(1).getT(3).getT(0);                // osc1_impl::global_cable42_t<NV>
		auto& add164 = this->getT(0).getT(5).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain119 = this->getT(0).getT(5).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain219 = this->getT(0).getT(5).getT(1).getT(4);                              // osc1_impl::chain219_t<NV>
		auto& add165 = this->getT(0).getT(5).getT(1).getT(4).getT(0);                        // math::add<NV>
		auto& gain120 = this->getT(0).getT(5).getT(1).getT(4).getT(1);                       // core::gain<NV>
		auto& chain220 = this->getT(0).getT(5).getT(1).getT(5);                              // osc1_impl::chain220_t<NV>
		auto& add166 = this->getT(0).getT(5).getT(1).getT(5).getT(0);                        // math::add<NV>
		auto& gain121 = this->getT(0).getT(5).getT(1).getT(5).getT(1);                       // core::gain<NV>
		auto& chain221 = this->getT(0).getT(5).getT(1).getT(6);                              // osc1_impl::chain221_t<NV>
		auto& branch49 = this->getT(0).getT(5).getT(1).getT(6).getT(0);                      // osc1_impl::branch49_t<NV>
		auto& add167 = this->getT(0).getT(5).getT(1).getT(6).getT(0).getT(0);                // math::add<NV>
		auto& add168 = this->getT(0).getT(5).getT(1).getT(6).getT(0).getT(1);                // math::add<NV>
		auto& add169 = this->getT(0).getT(5).getT(1).getT(6).getT(0).getT(2);                // math::add<NV>
		auto& add170 = this->getT(0).getT(5).getT(1).getT(6).getT(0).getT(3);                // math::add<NV>
		auto& add171 = this->getT(0).getT(5).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain122 = this->getT(0).getT(5).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain222 = this->getT(0).getT(5).getT(1).getT(7);                              // osc1_impl::chain222_t<NV>
		auto& branch50 = this->getT(0).getT(5).getT(1).getT(7).getT(0);                      // osc1_impl::branch50_t<NV>
		auto& chain223 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain223_t<NV>
		auto& midi_cc39 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc39_t<NV>
		auto& add172 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain224 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain224_t<NV>
		auto& midi_cc40 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc40_t<NV>
		auto& add173 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain225 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain225_t<NV>
		auto& midi_cc41 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc41_t<NV>
		auto& add174 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain226 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain226_t<NV>
		auto& midi_cc42 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc42_t<NV>
		auto& add175 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain227 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain227_t<NV>
		auto& midi29 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi29_t<NV>
		auto& add176 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain228 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain228_t<NV>
		auto& midi30 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi30_t<NV>
		auto& add177 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain229 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain229_t<NV>
		auto& midi31 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi31_t<NV>
		auto& add178 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain123 = this->getT(0).getT(5).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak19 = this->getT(0).getT(5).getT(2);                                        // osc1_impl::peak19_t<NV>
		auto& pma16 = this->getT(0).getT(5).getT(3);                                         // osc1_impl::pma16_t<NV>
		auto& modchain11 = this->getT(0).getT(6);                                            // osc1_impl::modchain11_t<NV>
		auto& sliderbank11 = this->getT(0).getT(6).getT(0);                                  // osc1_impl::sliderbank11_t<NV>
		auto& split24 = this->getT(0).getT(6).getT(1);                                       // osc1_impl::split24_t<NV>
		auto& chain200 = this->getT(0).getT(6).getT(1).getT(0);                              // osc1_impl::chain200_t<NV>
		auto& global_cable35 = this->getT(0).getT(6).getT(1).getT(0).getT(0);                // osc1_impl::global_cable35_t<NV>
		auto& add143 = this->getT(0).getT(6).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain108 = this->getT(0).getT(6).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain201 = this->getT(0).getT(6).getT(1).getT(1);                              // osc1_impl::chain201_t<NV>
		auto& global_cable36 = this->getT(0).getT(6).getT(1).getT(1).getT(0);                // osc1_impl::global_cable36_t<NV>
		auto& add144 = this->getT(0).getT(6).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain109 = this->getT(0).getT(6).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain202 = this->getT(0).getT(6).getT(1).getT(2);                              // osc1_impl::chain202_t<NV>
		auto& global_cable37 = this->getT(0).getT(6).getT(1).getT(2).getT(0);                // osc1_impl::global_cable37_t<NV>
		auto& add145 = this->getT(0).getT(6).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain110 = this->getT(0).getT(6).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain203 = this->getT(0).getT(6).getT(1).getT(3);                              // osc1_impl::chain203_t<NV>
		auto& global_cable38 = this->getT(0).getT(6).getT(1).getT(3).getT(0);                // osc1_impl::global_cable38_t<NV>
		auto& add146 = this->getT(0).getT(6).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain111 = this->getT(0).getT(6).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain204 = this->getT(0).getT(6).getT(1).getT(4);                              // osc1_impl::chain204_t<NV>
		auto& add147 = this->getT(0).getT(6).getT(1).getT(4).getT(0);                        // math::add<NV>
		auto& gain112 = this->getT(0).getT(6).getT(1).getT(4).getT(1);                       // core::gain<NV>
		auto& chain205 = this->getT(0).getT(6).getT(1).getT(5);                              // osc1_impl::chain205_t<NV>
		auto& add148 = this->getT(0).getT(6).getT(1).getT(5).getT(0);                        // math::add<NV>
		auto& gain113 = this->getT(0).getT(6).getT(1).getT(5).getT(1);                       // core::gain<NV>
		auto& chain206 = this->getT(0).getT(6).getT(1).getT(6);                              // osc1_impl::chain206_t<NV>
		auto& branch47 = this->getT(0).getT(6).getT(1).getT(6).getT(0);                      // osc1_impl::branch47_t<NV>
		auto& add149 = this->getT(0).getT(6).getT(1).getT(6).getT(0).getT(0);                // math::add<NV>
		auto& add150 = this->getT(0).getT(6).getT(1).getT(6).getT(0).getT(1);                // math::add<NV>
		auto& add151 = this->getT(0).getT(6).getT(1).getT(6).getT(0).getT(2);                // math::add<NV>
		auto& add152 = this->getT(0).getT(6).getT(1).getT(6).getT(0).getT(3);                // math::add<NV>
		auto& add153 = this->getT(0).getT(6).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain114 = this->getT(0).getT(6).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain207 = this->getT(0).getT(6).getT(1).getT(7);                              // osc1_impl::chain207_t<NV>
		auto& branch48 = this->getT(0).getT(6).getT(1).getT(7).getT(0);                      // osc1_impl::branch48_t<NV>
		auto& chain208 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain208_t<NV>
		auto& midi_cc35 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc35_t<NV>
		auto& add154 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain209 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain209_t<NV>
		auto& midi_cc36 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc36_t<NV>
		auto& add155 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain210 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain210_t<NV>
		auto& midi_cc37 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc37_t<NV>
		auto& add156 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain211 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain211_t<NV>
		auto& midi_cc38 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc38_t<NV>
		auto& add157 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain212 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain212_t<NV>
		auto& midi26 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi26_t<NV>
		auto& add158 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain213 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain213_t<NV>
		auto& midi27 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi27_t<NV>
		auto& add159 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain214 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain214_t<NV>
		auto& midi28 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi28_t<NV>
		auto& add160 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain115 = this->getT(0).getT(6).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak13 = this->getT(0).getT(6).getT(2);                                        // osc1_impl::peak13_t<NV>
		auto& pma9 = this->getT(0).getT(6).getT(3);                                          // osc1_impl::pma9_t<NV>
		auto& modchain14 = this->getT(0).getT(7);                                            // osc1_impl::modchain14_t<NV>
		auto& sliderbank14 = this->getT(0).getT(7).getT(0);                                  // osc1_impl::sliderbank14_t<NV>
		auto& split28 = this->getT(0).getT(7).getT(1);                                       // osc1_impl::split28_t<NV>
		auto& chain245 = this->getT(0).getT(7).getT(1).getT(0);                              // osc1_impl::chain245_t<NV>
		auto& global_cable47 = this->getT(0).getT(7).getT(1).getT(0).getT(0);                // osc1_impl::global_cable47_t<NV>
		auto& add197 = this->getT(0).getT(7).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain132 = this->getT(0).getT(7).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain246 = this->getT(0).getT(7).getT(1).getT(1);                              // osc1_impl::chain246_t<NV>
		auto& global_cable48 = this->getT(0).getT(7).getT(1).getT(1).getT(0);                // osc1_impl::global_cable48_t<NV>
		auto& add198 = this->getT(0).getT(7).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain133 = this->getT(0).getT(7).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain259 = this->getT(0).getT(7).getT(1).getT(2);                              // osc1_impl::chain259_t<NV>
		auto& global_cable49 = this->getT(0).getT(7).getT(1).getT(2).getT(0);                // osc1_impl::global_cable49_t<NV>
		auto& add199 = this->getT(0).getT(7).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain134 = this->getT(0).getT(7).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain260 = this->getT(0).getT(7).getT(1).getT(3);                              // osc1_impl::chain260_t<NV>
		auto& global_cable50 = this->getT(0).getT(7).getT(1).getT(3).getT(0);                // osc1_impl::global_cable50_t<NV>
		auto& add200 = this->getT(0).getT(7).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain135 = this->getT(0).getT(7).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain264 = this->getT(0).getT(7).getT(1).getT(4);                              // osc1_impl::chain264_t<NV>
		auto& add201 = this->getT(0).getT(7).getT(1).getT(4).getT(0);                        // math::add<NV>
		auto& gain136 = this->getT(0).getT(7).getT(1).getT(4).getT(1);                       // core::gain<NV>
		auto& chain265 = this->getT(0).getT(7).getT(1).getT(5);                              // osc1_impl::chain265_t<NV>
		auto& add202 = this->getT(0).getT(7).getT(1).getT(5).getT(0);                        // math::add<NV>
		auto& gain137 = this->getT(0).getT(7).getT(1).getT(5).getT(1);                       // core::gain<NV>
		auto& chain266 = this->getT(0).getT(7).getT(1).getT(6);                              // osc1_impl::chain266_t<NV>
		auto& branch53 = this->getT(0).getT(7).getT(1).getT(6).getT(0);                      // osc1_impl::branch53_t<NV>
		auto& add203 = this->getT(0).getT(7).getT(1).getT(6).getT(0).getT(0);                // math::add<NV>
		auto& add204 = this->getT(0).getT(7).getT(1).getT(6).getT(0).getT(1);                // math::add<NV>
		auto& add205 = this->getT(0).getT(7).getT(1).getT(6).getT(0).getT(2);                // math::add<NV>
		auto& add206 = this->getT(0).getT(7).getT(1).getT(6).getT(0).getT(3);                // math::add<NV>
		auto& add207 = this->getT(0).getT(7).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain138 = this->getT(0).getT(7).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain267 = this->getT(0).getT(7).getT(1).getT(7);                              // osc1_impl::chain267_t<NV>
		auto& branch54 = this->getT(0).getT(7).getT(1).getT(7).getT(0);                      // osc1_impl::branch54_t<NV>
		auto& chain268 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain268_t<NV>
		auto& midi_cc47 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc47_t<NV>
		auto& add208 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain269 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain269_t<NV>
		auto& midi_cc48 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc48_t<NV>
		auto& add209 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain270 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain270_t<NV>
		auto& midi_cc49 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc49_t<NV>
		auto& add210 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain271 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain271_t<NV>
		auto& midi_cc50 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc50_t<NV>
		auto& add211 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain272 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain272_t<NV>
		auto& midi35 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi35_t<NV>
		auto& add212 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain273 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain273_t<NV>
		auto& midi36 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi36_t<NV>
		auto& add223 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain274 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain274_t<NV>
		auto& midi37 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi37_t<NV>
		auto& add224 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain139 = this->getT(0).getT(7).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak34 = this->getT(0).getT(7).getT(2);                                        // osc1_impl::peak34_t<NV>
		auto& pma18 = this->getT(0).getT(7).getT(3);                                         // osc1_impl::pma18_t<NV>
		auto& modchain15 = this->getT(0).getT(8);                                            // osc1_impl::modchain15_t<NV>
		auto& sliderbank15 = this->getT(0).getT(8).getT(0);                                  // osc1_impl::sliderbank15_t<NV>
		auto& split29 = this->getT(0).getT(8).getT(1);                                       // osc1_impl::split29_t<NV>
		auto& chain275 = this->getT(0).getT(8).getT(1).getT(0);                              // osc1_impl::chain275_t<NV>
		auto& global_cable51 = this->getT(0).getT(8).getT(1).getT(0).getT(0);                // osc1_impl::global_cable51_t<NV>
		auto& add225 = this->getT(0).getT(8).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain140 = this->getT(0).getT(8).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain276 = this->getT(0).getT(8).getT(1).getT(1);                              // osc1_impl::chain276_t<NV>
		auto& global_cable52 = this->getT(0).getT(8).getT(1).getT(1).getT(0);                // osc1_impl::global_cable52_t<NV>
		auto& add226 = this->getT(0).getT(8).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain141 = this->getT(0).getT(8).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain277 = this->getT(0).getT(8).getT(1).getT(2);                              // osc1_impl::chain277_t<NV>
		auto& global_cable53 = this->getT(0).getT(8).getT(1).getT(2).getT(0);                // osc1_impl::global_cable53_t<NV>
		auto& add227 = this->getT(0).getT(8).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain142 = this->getT(0).getT(8).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain278 = this->getT(0).getT(8).getT(1).getT(3);                              // osc1_impl::chain278_t<NV>
		auto& global_cable54 = this->getT(0).getT(8).getT(1).getT(3).getT(0);                // osc1_impl::global_cable54_t<NV>
		auto& add228 = this->getT(0).getT(8).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain143 = this->getT(0).getT(8).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain279 = this->getT(0).getT(8).getT(1).getT(4);                              // osc1_impl::chain279_t<NV>
		auto& add229 = this->getT(0).getT(8).getT(1).getT(4).getT(0);                        // math::add<NV>
		auto& gain144 = this->getT(0).getT(8).getT(1).getT(4).getT(1);                       // core::gain<NV>
		auto& chain280 = this->getT(0).getT(8).getT(1).getT(5);                              // osc1_impl::chain280_t<NV>
		auto& add230 = this->getT(0).getT(8).getT(1).getT(5).getT(0);                        // math::add<NV>
		auto& gain145 = this->getT(0).getT(8).getT(1).getT(5).getT(1);                       // core::gain<NV>
		auto& chain281 = this->getT(0).getT(8).getT(1).getT(6);                              // osc1_impl::chain281_t<NV>
		auto& branch55 = this->getT(0).getT(8).getT(1).getT(6).getT(0);                      // osc1_impl::branch55_t<NV>
		auto& add231 = this->getT(0).getT(8).getT(1).getT(6).getT(0).getT(0);                // math::add<NV>
		auto& add232 = this->getT(0).getT(8).getT(1).getT(6).getT(0).getT(1);                // math::add<NV>
		auto& add233 = this->getT(0).getT(8).getT(1).getT(6).getT(0).getT(2);                // math::add<NV>
		auto& add234 = this->getT(0).getT(8).getT(1).getT(6).getT(0).getT(3);                // math::add<NV>
		auto& add235 = this->getT(0).getT(8).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain146 = this->getT(0).getT(8).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain282 = this->getT(0).getT(8).getT(1).getT(7);                              // osc1_impl::chain282_t<NV>
		auto& branch56 = this->getT(0).getT(8).getT(1).getT(7).getT(0);                      // osc1_impl::branch56_t<NV>
		auto& chain283 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain283_t<NV>
		auto& midi_cc51 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc51_t<NV>
		auto& add236 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain284 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain284_t<NV>
		auto& midi_cc52 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc52_t<NV>
		auto& add237 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain285 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain285_t<NV>
		auto& midi_cc53 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc53_t<NV>
		auto& add238 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain286 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain286_t<NV>
		auto& midi_cc54 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc54_t<NV>
		auto& add239 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain287 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain287_t<NV>
		auto& midi38 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi38_t<NV>
		auto& add240 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain288 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain288_t<NV>
		auto& midi39 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi39_t<NV>
		auto& add241 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain289 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain289_t<NV>
		auto& midi40 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi40_t<NV>
		auto& add242 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain147 = this->getT(0).getT(8).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak35 = this->getT(0).getT(8).getT(2);                                        // osc1_impl::peak35_t<NV>
		auto& pma19 = this->getT(0).getT(8).getT(3);                                         // osc1_impl::pma19_t<NV>
		auto& modchain17 = this->getT(0).getT(9);                                            // osc1_impl::modchain17_t<NV>
		auto& sliderbank16 = this->getT(0).getT(9).getT(0);                                  // osc1_impl::sliderbank16_t<NV>
		auto& split33 = this->getT(0).getT(9).getT(1);                                       // osc1_impl::split33_t<NV>
		auto& chain290 = this->getT(0).getT(9).getT(1).getT(0);                              // osc1_impl::chain290_t<NV>
		auto& global_cable55 = this->getT(0).getT(9).getT(1).getT(0).getT(0);                // osc1_impl::global_cable55_t<NV>
		auto& add243 = this->getT(0).getT(9).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain228 = this->getT(0).getT(9).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain291 = this->getT(0).getT(9).getT(1).getT(1);                              // osc1_impl::chain291_t<NV>
		auto& global_cable56 = this->getT(0).getT(9).getT(1).getT(1).getT(0);                // osc1_impl::global_cable56_t<NV>
		auto& add244 = this->getT(0).getT(9).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain229 = this->getT(0).getT(9).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain292 = this->getT(0).getT(9).getT(1).getT(2);                              // osc1_impl::chain292_t<NV>
		auto& global_cable57 = this->getT(0).getT(9).getT(1).getT(2).getT(0);                // osc1_impl::global_cable57_t<NV>
		auto& add245 = this->getT(0).getT(9).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain230 = this->getT(0).getT(9).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain293 = this->getT(0).getT(9).getT(1).getT(3);                              // osc1_impl::chain293_t<NV>
		auto& global_cable58 = this->getT(0).getT(9).getT(1).getT(3).getT(0);                // osc1_impl::global_cable58_t<NV>
		auto& add246 = this->getT(0).getT(9).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain231 = this->getT(0).getT(9).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain294 = this->getT(0).getT(9).getT(1).getT(4);                              // osc1_impl::chain294_t<NV>
		auto& add247 = this->getT(0).getT(9).getT(1).getT(4).getT(0);                        // math::add<NV>
		auto& gain232 = this->getT(0).getT(9).getT(1).getT(4).getT(1);                       // core::gain<NV>
		auto& chain295 = this->getT(0).getT(9).getT(1).getT(5);                              // osc1_impl::chain295_t<NV>
		auto& add248 = this->getT(0).getT(9).getT(1).getT(5).getT(0);                        // math::add<NV>
		auto& gain233 = this->getT(0).getT(9).getT(1).getT(5).getT(1);                       // core::gain<NV>
		auto& chain296 = this->getT(0).getT(9).getT(1).getT(6);                              // osc1_impl::chain296_t<NV>
		auto& branch57 = this->getT(0).getT(9).getT(1).getT(6).getT(0);                      // osc1_impl::branch57_t<NV>
		auto& add249 = this->getT(0).getT(9).getT(1).getT(6).getT(0).getT(0);                // math::add<NV>
		auto& add250 = this->getT(0).getT(9).getT(1).getT(6).getT(0).getT(1);                // math::add<NV>
		auto& add251 = this->getT(0).getT(9).getT(1).getT(6).getT(0).getT(2);                // math::add<NV>
		auto& add252 = this->getT(0).getT(9).getT(1).getT(6).getT(0).getT(3);                // math::add<NV>
		auto& add253 = this->getT(0).getT(9).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain234 = this->getT(0).getT(9).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain297 = this->getT(0).getT(9).getT(1).getT(7);                              // osc1_impl::chain297_t<NV>
		auto& branch58 = this->getT(0).getT(9).getT(1).getT(7).getT(0);                      // osc1_impl::branch58_t<NV>
		auto& chain298 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain298_t<NV>
		auto& midi_cc55 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc55_t<NV>
		auto& add394 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain299 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain299_t<NV>
		auto& midi_cc56 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc56_t<NV>
		auto& add395 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain426 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain426_t<NV>
		auto& midi_cc57 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc57_t<NV>
		auto& add396 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain451 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain451_t<NV>
		auto& midi_cc58 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc58_t<NV>
		auto& add397 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain452 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain452_t<NV>
		auto& midi41 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi41_t<NV>
		auto& add398 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain453 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain453_t<NV>
		auto& midi43 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi43_t<NV>
		auto& add399 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain454 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain454_t<NV>
		auto& midi44 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi44_t<NV>
		auto& add400 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain235 = this->getT(0).getT(9).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak36 = this->getT(0).getT(9).getT(2);                                        // osc1_impl::peak36_t<NV>
		auto& pma20 = this->getT(0).getT(9).getT(3);                                         // osc1_impl::pma20_t<NV>
		auto& modchain18 = this->getT(0).getT(10);                                           // osc1_impl::modchain18_t<NV>
		auto& sliderbank17 = this->getT(0).getT(10).getT(0);                                 // osc1_impl::sliderbank17_t<NV>
		auto& split34 = this->getT(0).getT(10).getT(1);                                      // osc1_impl::split34_t<NV>
		auto& chain300 = this->getT(0).getT(10).getT(1).getT(0);                             // osc1_impl::chain300_t<NV>
		auto& global_cable59 = this->getT(0).getT(10).getT(1).getT(0).getT(0);               // osc1_impl::global_cable59_t<NV>
		auto& add254 = this->getT(0).getT(10).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain236 = this->getT(0).getT(10).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain301 = this->getT(0).getT(10).getT(1).getT(1);                             // osc1_impl::chain301_t<NV>
		auto& global_cable60 = this->getT(0).getT(10).getT(1).getT(1).getT(0);               // osc1_impl::global_cable60_t<NV>
		auto& add255 = this->getT(0).getT(10).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain237 = this->getT(0).getT(10).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain302 = this->getT(0).getT(10).getT(1).getT(2);                             // osc1_impl::chain302_t<NV>
		auto& global_cable61 = this->getT(0).getT(10).getT(1).getT(2).getT(0);               // osc1_impl::global_cable61_t<NV>
		auto& add256 = this->getT(0).getT(10).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain238 = this->getT(0).getT(10).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain303 = this->getT(0).getT(10).getT(1).getT(3);                             // osc1_impl::chain303_t<NV>
		auto& global_cable62 = this->getT(0).getT(10).getT(1).getT(3).getT(0);               // osc1_impl::global_cable62_t<NV>
		auto& add257 = this->getT(0).getT(10).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain239 = this->getT(0).getT(10).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain304 = this->getT(0).getT(10).getT(1).getT(4);                             // osc1_impl::chain304_t<NV>
		auto& add258 = this->getT(0).getT(10).getT(1).getT(4).getT(0);                       // math::add<NV>
		auto& gain240 = this->getT(0).getT(10).getT(1).getT(4).getT(1);                      // core::gain<NV>
		auto& chain305 = this->getT(0).getT(10).getT(1).getT(5);                             // osc1_impl::chain305_t<NV>
		auto& add259 = this->getT(0).getT(10).getT(1).getT(5).getT(0);                       // math::add<NV>
		auto& gain241 = this->getT(0).getT(10).getT(1).getT(5).getT(1);                      // core::gain<NV>
		auto& chain306 = this->getT(0).getT(10).getT(1).getT(6);                             // osc1_impl::chain306_t<NV>
		auto& branch59 = this->getT(0).getT(10).getT(1).getT(6).getT(0);                     // osc1_impl::branch59_t<NV>
		auto& add260 = this->getT(0).getT(10).getT(1).getT(6).getT(0).getT(0);               // math::add<NV>
		auto& add261 = this->getT(0).getT(10).getT(1).getT(6).getT(0).getT(1);               // math::add<NV>
		auto& add262 = this->getT(0).getT(10).getT(1).getT(6).getT(0).getT(2);               // math::add<NV>
		auto& add263 = this->getT(0).getT(10).getT(1).getT(6).getT(0).getT(3);               // math::add<NV>
		auto& add264 = this->getT(0).getT(10).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain242 = this->getT(0).getT(10).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain307 = this->getT(0).getT(10).getT(1).getT(7);                             // osc1_impl::chain307_t<NV>
		auto& branch60 = this->getT(0).getT(10).getT(1).getT(7).getT(0);                     // osc1_impl::branch60_t<NV>
		auto& chain308 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain308_t<NV>
		auto& midi_cc59 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc59_t<NV>
		auto& add401 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain309 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain309_t<NV>
		auto& midi_cc60 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc60_t<NV>
		auto& add402 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain427 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain427_t<NV>
		auto& midi_cc61 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc61_t<NV>
		auto& add403 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain455 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain455_t<NV>
		auto& midi_cc62 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc62_t<NV>
		auto& add404 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain456 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain456_t<NV>
		auto& midi45 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi45_t<NV>
		auto& add405 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain457 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain457_t<NV>
		auto& midi46 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi46_t<NV>
		auto& add406 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain458 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain458_t<NV>
		auto& midi47 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi47_t<NV>
		auto& add407 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain243 = this->getT(0).getT(10).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak_unscaled = this->getT(0).getT(10).getT(2);                                // osc1_impl::peak_unscaled_t<NV>
		auto& peak37 = this->getT(0).getT(10).getT(3);                                       // osc1_impl::peak37_t
		auto& pma_unscaled = this->getT(0).getT(10).getT(4);                                 // osc1_impl::pma_unscaled_t<NV>
		auto& modchain19 = this->getT(0).getT(11);                                           // osc1_impl::modchain19_t<NV>
		auto& sliderbank18 = this->getT(0).getT(11).getT(0);                                 // osc1_impl::sliderbank18_t<NV>
		auto& split35 = this->getT(0).getT(11).getT(1);                                      // osc1_impl::split35_t<NV>
		auto& chain310 = this->getT(0).getT(11).getT(1).getT(0);                             // osc1_impl::chain310_t<NV>
		auto& global_cable63 = this->getT(0).getT(11).getT(1).getT(0).getT(0);               // osc1_impl::global_cable63_t<NV>
		auto& add265 = this->getT(0).getT(11).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain244 = this->getT(0).getT(11).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain311 = this->getT(0).getT(11).getT(1).getT(1);                             // osc1_impl::chain311_t<NV>
		auto& global_cable64 = this->getT(0).getT(11).getT(1).getT(1).getT(0);               // osc1_impl::global_cable64_t<NV>
		auto& add266 = this->getT(0).getT(11).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain245 = this->getT(0).getT(11).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain312 = this->getT(0).getT(11).getT(1).getT(2);                             // osc1_impl::chain312_t<NV>
		auto& global_cable65 = this->getT(0).getT(11).getT(1).getT(2).getT(0);               // osc1_impl::global_cable65_t<NV>
		auto& add267 = this->getT(0).getT(11).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain246 = this->getT(0).getT(11).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain313 = this->getT(0).getT(11).getT(1).getT(3);                             // osc1_impl::chain313_t<NV>
		auto& global_cable66 = this->getT(0).getT(11).getT(1).getT(3).getT(0);               // osc1_impl::global_cable66_t<NV>
		auto& add268 = this->getT(0).getT(11).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain247 = this->getT(0).getT(11).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain314 = this->getT(0).getT(11).getT(1).getT(4);                             // osc1_impl::chain314_t<NV>
		auto& add269 = this->getT(0).getT(11).getT(1).getT(4).getT(0);                       // math::add<NV>
		auto& gain248 = this->getT(0).getT(11).getT(1).getT(4).getT(1);                      // core::gain<NV>
		auto& chain315 = this->getT(0).getT(11).getT(1).getT(5);                             // osc1_impl::chain315_t<NV>
		auto& add270 = this->getT(0).getT(11).getT(1).getT(5).getT(0);                       // math::add<NV>
		auto& gain249 = this->getT(0).getT(11).getT(1).getT(5).getT(1);                      // core::gain<NV>
		auto& chain316 = this->getT(0).getT(11).getT(1).getT(6);                             // osc1_impl::chain316_t<NV>
		auto& branch61 = this->getT(0).getT(11).getT(1).getT(6).getT(0);                     // osc1_impl::branch61_t<NV>
		auto& add271 = this->getT(0).getT(11).getT(1).getT(6).getT(0).getT(0);               // math::add<NV>
		auto& add272 = this->getT(0).getT(11).getT(1).getT(6).getT(0).getT(1);               // math::add<NV>
		auto& add273 = this->getT(0).getT(11).getT(1).getT(6).getT(0).getT(2);               // math::add<NV>
		auto& add274 = this->getT(0).getT(11).getT(1).getT(6).getT(0).getT(3);               // math::add<NV>
		auto& add275 = this->getT(0).getT(11).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain250 = this->getT(0).getT(11).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain317 = this->getT(0).getT(11).getT(1).getT(7);                             // osc1_impl::chain317_t<NV>
		auto& branch62 = this->getT(0).getT(11).getT(1).getT(7).getT(0);                     // osc1_impl::branch62_t<NV>
		auto& chain318 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain318_t<NV>
		auto& midi_cc63 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc63_t<NV>
		auto& add408 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain319 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain319_t<NV>
		auto& midi_cc64 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc64_t<NV>
		auto& add409 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain428 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain428_t<NV>
		auto& midi_cc65 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc65_t<NV>
		auto& add410 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain459 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain459_t<NV>
		auto& midi_cc66 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc66_t<NV>
		auto& add411 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain460 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain460_t<NV>
		auto& midi48 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi48_t<NV>
		auto& add412 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain461 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain461_t<NV>
		auto& midi49 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi49_t<NV>
		auto& add413 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain462 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain462_t<NV>
		auto& midi50 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi50_t<NV>
		auto& add414 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain251 = this->getT(0).getT(11).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak38 = this->getT(0).getT(11).getT(2);                                       // osc1_impl::peak38_t<NV>
		auto& pma22 = this->getT(0).getT(11).getT(3);                                        // osc1_impl::pma22_t<NV>
		auto& modchain20 = this->getT(0).getT(12);                                           // osc1_impl::modchain20_t<NV>
		auto& sliderbank19 = this->getT(0).getT(12).getT(0);                                 // osc1_impl::sliderbank19_t<NV>
		auto& split36 = this->getT(0).getT(12).getT(1);                                      // osc1_impl::split36_t<NV>
		auto& chain320 = this->getT(0).getT(12).getT(1).getT(0);                             // osc1_impl::chain320_t<NV>
		auto& global_cable67 = this->getT(0).getT(12).getT(1).getT(0).getT(0);               // osc1_impl::global_cable67_t<NV>
		auto& add276 = this->getT(0).getT(12).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain252 = this->getT(0).getT(12).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain321 = this->getT(0).getT(12).getT(1).getT(1);                             // osc1_impl::chain321_t<NV>
		auto& global_cable68 = this->getT(0).getT(12).getT(1).getT(1).getT(0);               // osc1_impl::global_cable68_t<NV>
		auto& add277 = this->getT(0).getT(12).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain253 = this->getT(0).getT(12).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain322 = this->getT(0).getT(12).getT(1).getT(2);                             // osc1_impl::chain322_t<NV>
		auto& global_cable69 = this->getT(0).getT(12).getT(1).getT(2).getT(0);               // osc1_impl::global_cable69_t<NV>
		auto& add278 = this->getT(0).getT(12).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain254 = this->getT(0).getT(12).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain323 = this->getT(0).getT(12).getT(1).getT(3);                             // osc1_impl::chain323_t<NV>
		auto& global_cable70 = this->getT(0).getT(12).getT(1).getT(3).getT(0);               // osc1_impl::global_cable70_t<NV>
		auto& add279 = this->getT(0).getT(12).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain255 = this->getT(0).getT(12).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain324 = this->getT(0).getT(12).getT(1).getT(4);                             // osc1_impl::chain324_t<NV>
		auto& add280 = this->getT(0).getT(12).getT(1).getT(4).getT(0);                       // math::add<NV>
		auto& gain256 = this->getT(0).getT(12).getT(1).getT(4).getT(1);                      // core::gain<NV>
		auto& chain325 = this->getT(0).getT(12).getT(1).getT(5);                             // osc1_impl::chain325_t<NV>
		auto& add281 = this->getT(0).getT(12).getT(1).getT(5).getT(0);                       // math::add<NV>
		auto& gain257 = this->getT(0).getT(12).getT(1).getT(5).getT(1);                      // core::gain<NV>
		auto& chain326 = this->getT(0).getT(12).getT(1).getT(6);                             // osc1_impl::chain326_t<NV>
		auto& branch63 = this->getT(0).getT(12).getT(1).getT(6).getT(0);                     // osc1_impl::branch63_t<NV>
		auto& add282 = this->getT(0).getT(12).getT(1).getT(6).getT(0).getT(0);               // math::add<NV>
		auto& add283 = this->getT(0).getT(12).getT(1).getT(6).getT(0).getT(1);               // math::add<NV>
		auto& add284 = this->getT(0).getT(12).getT(1).getT(6).getT(0).getT(2);               // math::add<NV>
		auto& add285 = this->getT(0).getT(12).getT(1).getT(6).getT(0).getT(3);               // math::add<NV>
		auto& add286 = this->getT(0).getT(12).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain258 = this->getT(0).getT(12).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain327 = this->getT(0).getT(12).getT(1).getT(7);                             // osc1_impl::chain327_t<NV>
		auto& branch64 = this->getT(0).getT(12).getT(1).getT(7).getT(0);                     // osc1_impl::branch64_t<NV>
		auto& chain328 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain328_t<NV>
		auto& midi_cc67 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc67_t<NV>
		auto& add415 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain329 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain329_t<NV>
		auto& midi_cc68 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc68_t<NV>
		auto& add416 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain429 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain429_t<NV>
		auto& midi_cc69 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc69_t<NV>
		auto& add417 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain463 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain463_t<NV>
		auto& midi_cc70 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc70_t<NV>
		auto& add418 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain464 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain464_t<NV>
		auto& midi51 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi51_t<NV>
		auto& add419 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain465 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain465_t<NV>
		auto& midi52 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi52_t<NV>
		auto& add420 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain466 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain466_t<NV>
		auto& midi53 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi53_t<NV>
		auto& add421 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain259 = this->getT(0).getT(12).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak39 = this->getT(0).getT(12).getT(2);                                       // osc1_impl::peak39_t<NV>
		auto& pma23 = this->getT(0).getT(12).getT(3);                                        // osc1_impl::pma23_t<NV>
		auto& modchain21 = this->getT(0).getT(13);                                           // osc1_impl::modchain21_t<NV>
		auto& sliderbank20 = this->getT(0).getT(13).getT(0);                                 // osc1_impl::sliderbank20_t<NV>
		auto& split37 = this->getT(0).getT(13).getT(1);                                      // osc1_impl::split37_t<NV>
		auto& chain330 = this->getT(0).getT(13).getT(1).getT(0);                             // osc1_impl::chain330_t<NV>
		auto& global_cable71 = this->getT(0).getT(13).getT(1).getT(0).getT(0);               // osc1_impl::global_cable71_t<NV>
		auto& add287 = this->getT(0).getT(13).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain260 = this->getT(0).getT(13).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain331 = this->getT(0).getT(13).getT(1).getT(1);                             // osc1_impl::chain331_t<NV>
		auto& global_cable72 = this->getT(0).getT(13).getT(1).getT(1).getT(0);               // osc1_impl::global_cable72_t<NV>
		auto& add288 = this->getT(0).getT(13).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain261 = this->getT(0).getT(13).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain332 = this->getT(0).getT(13).getT(1).getT(2);                             // osc1_impl::chain332_t<NV>
		auto& global_cable73 = this->getT(0).getT(13).getT(1).getT(2).getT(0);               // osc1_impl::global_cable73_t<NV>
		auto& add289 = this->getT(0).getT(13).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain262 = this->getT(0).getT(13).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain333 = this->getT(0).getT(13).getT(1).getT(3);                             // osc1_impl::chain333_t<NV>
		auto& global_cable74 = this->getT(0).getT(13).getT(1).getT(3).getT(0);               // osc1_impl::global_cable74_t<NV>
		auto& add290 = this->getT(0).getT(13).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain263 = this->getT(0).getT(13).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain334 = this->getT(0).getT(13).getT(1).getT(4);                             // osc1_impl::chain334_t<NV>
		auto& add291 = this->getT(0).getT(13).getT(1).getT(4).getT(0);                       // math::add<NV>
		auto& gain264 = this->getT(0).getT(13).getT(1).getT(4).getT(1);                      // core::gain<NV>
		auto& chain335 = this->getT(0).getT(13).getT(1).getT(5);                             // osc1_impl::chain335_t<NV>
		auto& add292 = this->getT(0).getT(13).getT(1).getT(5).getT(0);                       // math::add<NV>
		auto& gain265 = this->getT(0).getT(13).getT(1).getT(5).getT(1);                      // core::gain<NV>
		auto& chain336 = this->getT(0).getT(13).getT(1).getT(6);                             // osc1_impl::chain336_t<NV>
		auto& branch65 = this->getT(0).getT(13).getT(1).getT(6).getT(0);                     // osc1_impl::branch65_t<NV>
		auto& add293 = this->getT(0).getT(13).getT(1).getT(6).getT(0).getT(0);               // math::add<NV>
		auto& add294 = this->getT(0).getT(13).getT(1).getT(6).getT(0).getT(1);               // math::add<NV>
		auto& add295 = this->getT(0).getT(13).getT(1).getT(6).getT(0).getT(2);               // math::add<NV>
		auto& add296 = this->getT(0).getT(13).getT(1).getT(6).getT(0).getT(3);               // math::add<NV>
		auto& add297 = this->getT(0).getT(13).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain266 = this->getT(0).getT(13).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain337 = this->getT(0).getT(13).getT(1).getT(7);                             // osc1_impl::chain337_t<NV>
		auto& branch66 = this->getT(0).getT(13).getT(1).getT(7).getT(0);                     // osc1_impl::branch66_t<NV>
		auto& chain338 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain338_t<NV>
		auto& midi_cc71 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc71_t<NV>
		auto& add422 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain339 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain339_t<NV>
		auto& midi_cc72 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc72_t<NV>
		auto& add423 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain430 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain430_t<NV>
		auto& midi_cc73 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc73_t<NV>
		auto& add424 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain467 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain467_t<NV>
		auto& midi_cc74 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc74_t<NV>
		auto& add425 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain468 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain468_t<NV>
		auto& midi54 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi54_t<NV>
		auto& add426 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain469 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain469_t<NV>
		auto& midi55 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi55_t<NV>
		auto& add427 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain470 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain470_t<NV>
		auto& midi56 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi56_t<NV>
		auto& add428 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain267 = this->getT(0).getT(13).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak40 = this->getT(0).getT(13).getT(2);                                       // osc1_impl::peak40_t<NV>
		auto& pma24 = this->getT(0).getT(13).getT(3);                                        // osc1_impl::pma24_t<NV>
		auto& modchain22 = this->getT(0).getT(14);                                           // osc1_impl::modchain22_t<NV>
		auto& sliderbank21 = this->getT(0).getT(14).getT(0);                                 // osc1_impl::sliderbank21_t<NV>
		auto& split38 = this->getT(0).getT(14).getT(1);                                      // osc1_impl::split38_t<NV>
		auto& chain340 = this->getT(0).getT(14).getT(1).getT(0);                             // osc1_impl::chain340_t<NV>
		auto& global_cable75 = this->getT(0).getT(14).getT(1).getT(0).getT(0);               // osc1_impl::global_cable75_t<NV>
		auto& add298 = this->getT(0).getT(14).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain268 = this->getT(0).getT(14).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain341 = this->getT(0).getT(14).getT(1).getT(1);                             // osc1_impl::chain341_t<NV>
		auto& global_cable76 = this->getT(0).getT(14).getT(1).getT(1).getT(0);               // osc1_impl::global_cable76_t<NV>
		auto& add299 = this->getT(0).getT(14).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain269 = this->getT(0).getT(14).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain342 = this->getT(0).getT(14).getT(1).getT(2);                             // osc1_impl::chain342_t<NV>
		auto& global_cable77 = this->getT(0).getT(14).getT(1).getT(2).getT(0);               // osc1_impl::global_cable77_t<NV>
		auto& add300 = this->getT(0).getT(14).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain270 = this->getT(0).getT(14).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain343 = this->getT(0).getT(14).getT(1).getT(3);                             // osc1_impl::chain343_t<NV>
		auto& global_cable78 = this->getT(0).getT(14).getT(1).getT(3).getT(0);               // osc1_impl::global_cable78_t<NV>
		auto& add301 = this->getT(0).getT(14).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain271 = this->getT(0).getT(14).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain344 = this->getT(0).getT(14).getT(1).getT(4);                             // osc1_impl::chain344_t<NV>
		auto& add302 = this->getT(0).getT(14).getT(1).getT(4).getT(0);                       // math::add<NV>
		auto& gain272 = this->getT(0).getT(14).getT(1).getT(4).getT(1);                      // core::gain<NV>
		auto& chain345 = this->getT(0).getT(14).getT(1).getT(5);                             // osc1_impl::chain345_t<NV>
		auto& add303 = this->getT(0).getT(14).getT(1).getT(5).getT(0);                       // math::add<NV>
		auto& gain273 = this->getT(0).getT(14).getT(1).getT(5).getT(1);                      // core::gain<NV>
		auto& chain346 = this->getT(0).getT(14).getT(1).getT(6);                             // osc1_impl::chain346_t<NV>
		auto& branch67 = this->getT(0).getT(14).getT(1).getT(6).getT(0);                     // osc1_impl::branch67_t<NV>
		auto& add304 = this->getT(0).getT(14).getT(1).getT(6).getT(0).getT(0);               // math::add<NV>
		auto& add305 = this->getT(0).getT(14).getT(1).getT(6).getT(0).getT(1);               // math::add<NV>
		auto& add306 = this->getT(0).getT(14).getT(1).getT(6).getT(0).getT(2);               // math::add<NV>
		auto& add307 = this->getT(0).getT(14).getT(1).getT(6).getT(0).getT(3);               // math::add<NV>
		auto& add308 = this->getT(0).getT(14).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain274 = this->getT(0).getT(14).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain347 = this->getT(0).getT(14).getT(1).getT(7);                             // osc1_impl::chain347_t<NV>
		auto& branch68 = this->getT(0).getT(14).getT(1).getT(7).getT(0);                     // osc1_impl::branch68_t<NV>
		auto& chain348 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain348_t<NV>
		auto& midi_cc75 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc75_t<NV>
		auto& add429 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain349 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain349_t<NV>
		auto& midi_cc76 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc76_t<NV>
		auto& add430 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain431 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain431_t<NV>
		auto& midi_cc77 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc77_t<NV>
		auto& add431 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain471 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain471_t<NV>
		auto& midi_cc78 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc78_t<NV>
		auto& add432 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain472 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain472_t<NV>
		auto& midi57 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi57_t<NV>
		auto& add433 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain473 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain473_t<NV>
		auto& midi58 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi58_t<NV>
		auto& add434 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain474 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain474_t<NV>
		auto& midi59 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi59_t<NV>
		auto& add435 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain275 = this->getT(0).getT(14).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak41 = this->getT(0).getT(14).getT(2);                                       // osc1_impl::peak41_t<NV>
		auto& pma25 = this->getT(0).getT(14).getT(3);                                        // osc1_impl::pma25_t<NV>
		auto& modchain23 = this->getT(0).getT(15);                                           // osc1_impl::modchain23_t<NV>
		auto& sliderbank22 = this->getT(0).getT(15).getT(0);                                 // osc1_impl::sliderbank22_t<NV>
		auto& split39 = this->getT(0).getT(15).getT(1);                                      // osc1_impl::split39_t<NV>
		auto& chain350 = this->getT(0).getT(15).getT(1).getT(0);                             // osc1_impl::chain350_t<NV>
		auto& global_cable79 = this->getT(0).getT(15).getT(1).getT(0).getT(0);               // osc1_impl::global_cable79_t<NV>
		auto& add309 = this->getT(0).getT(15).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain276 = this->getT(0).getT(15).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain351 = this->getT(0).getT(15).getT(1).getT(1);                             // osc1_impl::chain351_t<NV>
		auto& global_cable80 = this->getT(0).getT(15).getT(1).getT(1).getT(0);               // osc1_impl::global_cable80_t<NV>
		auto& add310 = this->getT(0).getT(15).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain277 = this->getT(0).getT(15).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain352 = this->getT(0).getT(15).getT(1).getT(2);                             // osc1_impl::chain352_t<NV>
		auto& global_cable81 = this->getT(0).getT(15).getT(1).getT(2).getT(0);               // osc1_impl::global_cable81_t<NV>
		auto& add311 = this->getT(0).getT(15).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain278 = this->getT(0).getT(15).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain353 = this->getT(0).getT(15).getT(1).getT(3);                             // osc1_impl::chain353_t<NV>
		auto& global_cable82 = this->getT(0).getT(15).getT(1).getT(3).getT(0);               // osc1_impl::global_cable82_t<NV>
		auto& add312 = this->getT(0).getT(15).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain279 = this->getT(0).getT(15).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain354 = this->getT(0).getT(15).getT(1).getT(4);                             // osc1_impl::chain354_t<NV>
		auto& add313 = this->getT(0).getT(15).getT(1).getT(4).getT(0);                       // math::add<NV>
		auto& gain280 = this->getT(0).getT(15).getT(1).getT(4).getT(1);                      // core::gain<NV>
		auto& chain355 = this->getT(0).getT(15).getT(1).getT(5);                             // osc1_impl::chain355_t<NV>
		auto& add314 = this->getT(0).getT(15).getT(1).getT(5).getT(0);                       // math::add<NV>
		auto& gain281 = this->getT(0).getT(15).getT(1).getT(5).getT(1);                      // core::gain<NV>
		auto& chain356 = this->getT(0).getT(15).getT(1).getT(6);                             // osc1_impl::chain356_t<NV>
		auto& branch69 = this->getT(0).getT(15).getT(1).getT(6).getT(0);                     // osc1_impl::branch69_t<NV>
		auto& add315 = this->getT(0).getT(15).getT(1).getT(6).getT(0).getT(0);               // math::add<NV>
		auto& add316 = this->getT(0).getT(15).getT(1).getT(6).getT(0).getT(1);               // math::add<NV>
		auto& add317 = this->getT(0).getT(15).getT(1).getT(6).getT(0).getT(2);               // math::add<NV>
		auto& add318 = this->getT(0).getT(15).getT(1).getT(6).getT(0).getT(3);               // math::add<NV>
		auto& add319 = this->getT(0).getT(15).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain282 = this->getT(0).getT(15).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain357 = this->getT(0).getT(15).getT(1).getT(7);                             // osc1_impl::chain357_t<NV>
		auto& branch70 = this->getT(0).getT(15).getT(1).getT(7).getT(0);                     // osc1_impl::branch70_t<NV>
		auto& chain358 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain358_t<NV>
		auto& midi_cc79 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc79_t<NV>
		auto& add436 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain359 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain359_t<NV>
		auto& midi_cc80 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc80_t<NV>
		auto& add437 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain432 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain432_t<NV>
		auto& midi_cc81 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc81_t<NV>
		auto& add438 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain475 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain475_t<NV>
		auto& midi_cc82 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc82_t<NV>
		auto& add439 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain476 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain476_t<NV>
		auto& midi60 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi60_t<NV>
		auto& add440 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain477 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain477_t<NV>
		auto& midi61 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi61_t<NV>
		auto& add441 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain478 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain478_t<NV>
		auto& midi62 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi62_t<NV>
		auto& add442 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain283 = this->getT(0).getT(15).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak42 = this->getT(0).getT(15).getT(2);                                       // osc1_impl::peak42_t<NV>
		auto& pma26 = this->getT(0).getT(15).getT(3);                                        // osc1_impl::pma26_t<NV>
		auto& chain59 = this->getT(1);                                                       // osc1_impl::chain59_t<NV>
		auto& xfade_2x_lin = this->getT(1).getT(0);                                          // osc1_impl::xfade_2x_lin_t<NV>
		auto& split20 = this->getT(1).getT(0).getT(0);                                       // osc1_impl::split20_t<NV>
		auto& chain19 = this->getT(1).getT(0).getT(0).getT(0);                               // osc1_impl::chain19_t<NV>
		auto& chain77 = this->getT(1).getT(0).getT(0).getT(0).getT(0);                       // osc1_impl::chain77_t<NV>
		auto& clear23 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);               // math::clear<NV>
		auto& branch38 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(1);              // osc1_impl::branch38_t
		auto& receive7 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);      // routing::receive<stereo_cable>
		auto& receive8 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);      // routing::receive<stereo_cable>
		auto& receive9 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);      // routing::receive<stereo_cable>
		auto& peak8 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(2);                 // osc1_impl::peak8_t
		auto& gain = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(3);                  // core::gain<NV>
		auto& modchain = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(4);              // osc1_impl::modchain_t<NV>
		auto& split = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(4).getT(0);         // osc1_impl::split_t<NV>
		auto& chain8 = this->getT(1).getT(0).getT(0).getT(0).                                // osc1_impl::chain8_t<NV>
                       getT(0).getT(4).getT(0).getT(0);
		auto& minmax2 = this->getT(1).getT(0).getT(0).getT(0).                               // osc1_impl::minmax2_t<NV>
                        getT(0).getT(4).getT(0).getT(0).
                        getT(0);
		auto& converter = this->getT(1).getT(0).getT(0).getT(0).                             // osc1_impl::converter_t<NV>
                          getT(0).getT(4).getT(0).getT(0).
                          getT(1);
		auto& chain12 = this->getT(1).getT(0).getT(0).getT(0).                               // osc1_impl::chain12_t<NV>
                        getT(0).getT(4).getT(0).getT(1);
		auto& tempo_sync = this->getT(1).getT(0).getT(0).getT(0).                            // osc1_impl::tempo_sync_t<NV>
                           getT(0).getT(4).getT(0).getT(1).
                           getT(0);
		auto& converter5 = this->getT(1).getT(0).getT(0).getT(0).                            // osc1_impl::converter5_t<NV>
                           getT(0).getT(4).getT(0).getT(1).
                           getT(1);
		auto& branch1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(5);               // osc1_impl::branch1_t<NV>
		auto& chain1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(5).getT(0);        // osc1_impl::chain1_t<NV>
		auto& phasor_fm = this->getT(1).getT(0).getT(0).getT(0).                             // core::phasor_fm<NV>
                          getT(0).getT(5).getT(0).getT(0);
		auto& chain2 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(5).getT(1);        // osc1_impl::chain2_t<NV>
		auto& phasor_fm3 = this->getT(1).getT(0).getT(0).getT(0).                            // core::phasor_fm<NV>
                           getT(0).getT(5).getT(1).getT(0);
		auto& no_midi = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(5).getT(2);       // osc1_impl::no_midi_t<NV>
		auto& phasor_fm1 = this->getT(1).getT(0).getT(0).getT(0).                            // core::phasor_fm<NV>
                           getT(0).getT(5).getT(2).getT(0);
		auto& mono2stereo = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(6);           // core::mono2stereo
		auto& pma6 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(7);                  // osc1_impl::pma6_t<NV>
		auto& branch2 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(8);               // osc1_impl::branch2_t<NV>
		auto& chain88 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(8).getT(0);       // osc1_impl::chain88_t<NV>
		auto& xfader3 = this->getT(1).getT(0).getT(0).getT(0).                               // osc1_impl::xfader3_t<NV>
                        getT(0).getT(8).getT(0).getT(0);
		auto& split16 = this->getT(1).getT(0).getT(0).getT(0).                               // osc1_impl::split16_t<NV>
                        getT(0).getT(8).getT(0).getT(1);
		auto& chain62 = this->getT(1).getT(0).getT(0).getT(0).                               // osc1_impl::chain62_t<NV>
                        getT(0).getT(8).getT(0).getT(1).
                        getT(0);
		auto& chain74 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                       // osc1_impl::chain74_t<NV>
                        getT(8).getT(0).getT(1).getT(0).getT(0);
		auto& sub1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                          // math::sub<NV>
                     getT(8).getT(0).getT(1).getT(0).getT(0).
                     getT(0);
		auto& abs1 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                          // math::abs<NV>
                     getT(8).getT(0).getT(1).getT(0).getT(0).
                     getT(1);
		auto& mul2 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                          // math::mul<NV>
                     getT(8).getT(0).getT(1).getT(0).getT(0).
                     getT(2);
		auto& gain49 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                        // core::gain<NV>
                       getT(8).getT(0).getT(1).getT(0).getT(1);
		auto& chain75 = this->getT(1).getT(0).getT(0).getT(0).                               // osc1_impl::chain75_t<NV>
                        getT(0).getT(8).getT(0).getT(1).
                        getT(1);
		auto& expr3 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                         // math::expr<NV, custom::expr3>
                      getT(8).getT(0).getT(1).getT(1).getT(0);
		auto& gain50 = this->getT(1).getT(0).getT(0).getT(0).getT(0).                        // core::gain<NV>
                       getT(8).getT(0).getT(1).getT(1).getT(1);
		auto& chain76 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(8).getT(1);       // osc1_impl::chain76_t<NV>
		auto& gain51 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(8).getT(1).getT(0);
		auto& rect2 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::rect<NV>
                      getT(0).getT(8).getT(1).getT(1);
		auto& chain78 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(8).getT(2);       // osc1_impl::chain78_t<NV>
		auto& gain53 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(8).getT(2).getT(0);
		auto& fmod2 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::fmod<NV>
                      getT(0).getT(8).getT(2).getT(1);
		auto& mul3 = this->getT(1).getT(0).getT(0).getT(0).                                  // wrap::no_process<math::mul<NV>>
                     getT(0).getT(8).getT(2).getT(2);
		auto& pi8 = this->getT(1).getT(0).getT(0).getT(0).                                   // math::pi<NV>
                    getT(0).getT(8).getT(2).getT(3);
		auto& chain79 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(8).getT(3);       // osc1_impl::chain79_t<NV>
		auto& gain56 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(8).getT(3).getT(0);
		auto& expr6 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::expr<NV, custom::expr6>
                      getT(0).getT(8).getT(3).getT(1);
		auto& sin7 = this->getT(1).getT(0).getT(0).getT(0).                                  // math::sin<NV>
                     getT(0).getT(8).getT(3).getT(2);
		auto& chain80 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(8).getT(4);       // osc1_impl::chain80_t<NV>
		auto& pi9 = this->getT(1).getT(0).getT(0).getT(0).                                   // math::pi<NV>
                    getT(0).getT(8).getT(4).getT(0);
		auto& sin1 = this->getT(1).getT(0).getT(0).getT(0).                                  // wrap::no_process<math::sin<NV>>
                     getT(0).getT(8).getT(4).getT(1);
		auto& gain58 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(8).getT(4).getT(2);
		auto& sin9 = this->getT(1).getT(0).getT(0).getT(0).                                  // math::sin<NV>
                     getT(0).getT(8).getT(4).getT(3);
		auto& expr7 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::expr<NV, custom::expr7>
                      getT(0).getT(8).getT(4).getT(4);
		auto& chain81 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(8).getT(5);       // osc1_impl::chain81_t<NV>
		auto& pi3 = this->getT(1).getT(0).getT(0).getT(0).                                   // wrap::no_process<math::pi<NV>>
                    getT(0).getT(8).getT(5).getT(0);
		auto& phase_delay1 = this->getT(1).getT(0).getT(0).getT(0).                          // wrap::no_process<fx::phase_delay<NV>>
                             getT(0).getT(8).getT(5).getT(1);
		auto& gain59 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(8).getT(5).getT(2);
		auto& expr8 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::expr<NV, custom::expr8>
                      getT(0).getT(8).getT(5).getT(3);
		auto& sin10 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::sin<NV>
                      getT(0).getT(8).getT(5).getT(4);
		auto& chain85 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(8).getT(6);       // osc1_impl::chain85_t<NV>
		auto& gain63 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(8).getT(6).getT(0);
		auto& pi12 = this->getT(1).getT(0).getT(0).getT(0).                                  // math::pi<NV>
                     getT(0).getT(8).getT(6).getT(1);
		auto& table5 = this->getT(1).getT(0).getT(0).getT(0).                                // osc1_impl::table5_t
                       getT(0).getT(8).getT(6).getT(2);
		auto& gain12 = this->getT(1).getT(0).getT(0).getT(0).getT(1);                        // core::gain<NV>
		auto& one_pole1 = this->getT(1).getT(0).getT(0).getT(0).getT(2);                     // filters::one_pole<NV>
		auto& gain3 = this->getT(1).getT(0).getT(0).getT(0).getT(3);                         // core::gain<NV>
		auto& chain168 = this->getT(1).getT(0).getT(0).getT(0).getT(4);                      // osc1_impl::chain168_t<NV>
		auto& split32 = this->getT(1).getT(0).getT(0).getT(0).getT(4).getT(0);               // osc1_impl::split32_t<NV>
		auto& chain197 = this->getT(1).getT(0).getT(0).getT(0).getT(4).getT(0).getT(0);      // osc1_impl::chain197_t
		auto& send = this->getT(1).getT(0).getT(0).getT(0).                                  // routing::send<stereo_cable>
                     getT(4).getT(0).getT(0).getT(0);
		auto& chain196 = this->getT(1).getT(0).getT(0).getT(0).getT(4).getT(0).getT(1);      // osc1_impl::chain196_t<NV>
		auto& peak17 = this->getT(1).getT(0).getT(0).getT(0).                                // osc1_impl::peak17_t<NV>
                       getT(4).getT(0).getT(1).getT(0);
		auto& clear19 = this->getT(1).getT(0).getT(0).getT(0).getT(5);                       // math::clear<NV>
		auto& chain86 = this->getT(1).getT(0).getT(0).getT(1);                               // osc1_impl::chain86_t<NV>
		auto& chain82 = this->getT(1).getT(0).getT(0).getT(1).getT(0);                       // osc1_impl::chain82_t<NV>
		auto& clear22 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0);               // math::clear<NV>
		auto& branch27 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(1);              // osc1_impl::branch27_t
		auto& receive6 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);      // routing::receive<stereo_cable>
		auto& receive5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);      // routing::receive<stereo_cable>
		auto& receive4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(1).getT(2);      // routing::receive<stereo_cable>
		auto& gain11 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(2);                // core::gain<NV>
		auto& modchain3 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(3);             // osc1_impl::modchain3_t<NV>
		auto& split5 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(3).getT(0);        // osc1_impl::split5_t<NV>
		auto& chain83 = this->getT(1).getT(0).getT(0).getT(1).                               // osc1_impl::chain83_t<NV>
                        getT(0).getT(3).getT(0).getT(0);
		auto& minmax3 = this->getT(1).getT(0).getT(0).getT(1).                               // osc1_impl::minmax3_t<NV>
                        getT(0).getT(3).getT(0).getT(0).
                        getT(0);
		auto& converter1 = this->getT(1).getT(0).getT(0).getT(1).                            // osc1_impl::converter1_t<NV>
                           getT(0).getT(3).getT(0).getT(0).
                           getT(1);
		auto& chain92 = this->getT(1).getT(0).getT(0).getT(1).                               // osc1_impl::chain92_t<NV>
                        getT(0).getT(3).getT(0).getT(1);
		auto& tempo_sync1 = this->getT(1).getT(0).getT(0).getT(1).                           // osc1_impl::tempo_sync1_t<NV>
                            getT(0).getT(3).getT(0).getT(1).
                            getT(0);
		auto& converter6 = this->getT(1).getT(0).getT(0).getT(1).                            // osc1_impl::converter6_t<NV>
                           getT(0).getT(3).getT(0).getT(1).
                           getT(1);
		auto& branch7 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(4);               // osc1_impl::branch7_t<NV>
		auto& chain93 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(4).getT(0);       // osc1_impl::chain93_t<NV>
		auto& phasor_fm2 = this->getT(1).getT(0).getT(0).getT(1).                            // core::phasor_fm<NV>
                           getT(0).getT(4).getT(0).getT(0);
		auto& chain95 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(4).getT(1);       // osc1_impl::chain95_t<NV>
		auto& phasor_fm4 = this->getT(1).getT(0).getT(0).getT(1).                            // core::phasor_fm<NV>
                           getT(0).getT(4).getT(1).getT(0);
		auto& no_midi1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(4).getT(2);      // osc1_impl::no_midi1_t<NV>
		auto& phasor_fm7 = this->getT(1).getT(0).getT(0).getT(1).                            // core::phasor_fm<NV>
                           getT(0).getT(4).getT(2).getT(0);
		auto& mono2stereo1 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(5);          // core::mono2stereo
		auto& pma7 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(6);                  // osc1_impl::pma7_t<NV>
		auto& branch10 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(7);              // osc1_impl::branch10_t<NV>
		auto& chain96 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(7).getT(0);       // osc1_impl::chain96_t<NV>
		auto& xfader4 = this->getT(1).getT(0).getT(0).getT(1).                               // osc1_impl::xfader4_t<NV>
                        getT(0).getT(7).getT(0).getT(0);
		auto& split18 = this->getT(1).getT(0).getT(0).getT(1).                               // osc1_impl::split18_t<NV>
                        getT(0).getT(7).getT(0).getT(1);
		auto& chain97 = this->getT(1).getT(0).getT(0).getT(1).                               // osc1_impl::chain97_t<NV>
                        getT(0).getT(7).getT(0).getT(1).
                        getT(0);
		auto& chain98 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                       // osc1_impl::chain98_t<NV>
                        getT(7).getT(0).getT(1).getT(0).getT(0);
		auto& sub2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // math::sub<NV>
                     getT(7).getT(0).getT(1).getT(0).getT(0).
                     getT(0);
		auto& abs2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // math::abs<NV>
                     getT(7).getT(0).getT(1).getT(0).getT(0).
                     getT(1);
		auto& mul4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                          // math::mul<NV>
                     getT(7).getT(0).getT(1).getT(0).getT(0).
                     getT(2);
		auto& gain52 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                        // core::gain<NV>
                       getT(7).getT(0).getT(1).getT(0).getT(1);
		auto& chain99 = this->getT(1).getT(0).getT(0).getT(1).                               // osc1_impl::chain99_t<NV>
                        getT(0).getT(7).getT(0).getT(1).
                        getT(1);
		auto& expr4 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                         // math::expr<NV, custom::expr4>
                      getT(7).getT(0).getT(1).getT(1).getT(0);
		auto& gain54 = this->getT(1).getT(0).getT(0).getT(1).getT(0).                        // core::gain<NV>
                       getT(7).getT(0).getT(1).getT(1).getT(1);
		auto& chain100 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(7).getT(1);      // osc1_impl::chain100_t<NV>
		auto& gain55 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(7).getT(1).getT(0);
		auto& rect4 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::rect<NV>
                      getT(0).getT(7).getT(1).getT(1);
		auto& chain131 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(7).getT(2);      // osc1_impl::chain131_t<NV>
		auto& gain57 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(7).getT(2).getT(0);
		auto& fmod3 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::fmod<NV>
                      getT(0).getT(7).getT(2).getT(1);
		auto& mul5 = this->getT(1).getT(0).getT(0).getT(1).                                  // wrap::no_process<math::mul<NV>>
                     getT(0).getT(7).getT(2).getT(2);
		auto& pi10 = this->getT(1).getT(0).getT(0).getT(1).                                  // math::pi<NV>
                     getT(0).getT(7).getT(2).getT(3);
		auto& oscilloscope2 = this->getT(1).getT(0).getT(0).getT(1).                         // osc1_impl::oscilloscope2_t
                              getT(0).getT(7).getT(2).getT(4);
		auto& chain132 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(7).getT(3);      // osc1_impl::chain132_t<NV>
		auto& gain60 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(7).getT(3).getT(0);
		auto& expr11 = this->getT(1).getT(0).getT(0).getT(1).                                // math::expr<NV, custom::expr11>
                       getT(0).getT(7).getT(3).getT(1);
		auto& sin8 = this->getT(1).getT(0).getT(0).getT(1).                                  // math::sin<NV>
                     getT(0).getT(7).getT(3).getT(2);
		auto& chain133 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(7).getT(4);      // osc1_impl::chain133_t<NV>
		auto& pi13 = this->getT(1).getT(0).getT(0).getT(1).                                  // math::pi<NV>
                     getT(0).getT(7).getT(4).getT(0);
		auto& sin2 = this->getT(1).getT(0).getT(0).getT(1).                                  // wrap::no_process<math::sin<NV>>
                     getT(0).getT(7).getT(4).getT(1);
		auto& gain62 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(7).getT(4).getT(2);
		auto& sin11 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::sin<NV>
                      getT(0).getT(7).getT(4).getT(3);
		auto& expr12 = this->getT(1).getT(0).getT(0).getT(1).                                // math::expr<NV, custom::expr12>
                       getT(0).getT(7).getT(4).getT(4);
		auto& chain134 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(7).getT(5);      // osc1_impl::chain134_t<NV>
		auto& pi4 = this->getT(1).getT(0).getT(0).getT(1).                                   // wrap::no_process<math::pi<NV>>
                    getT(0).getT(7).getT(5).getT(0);
		auto& phase_delay2 = this->getT(1).getT(0).getT(0).getT(1).                          // wrap::no_process<fx::phase_delay<NV>>
                             getT(0).getT(7).getT(5).getT(1);
		auto& gain64 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(7).getT(5).getT(2);
		auto& expr13 = this->getT(1).getT(0).getT(0).getT(1).                                // math::expr<NV, custom::expr13>
                       getT(0).getT(7).getT(5).getT(3);
		auto& sin12 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::sin<NV>
                      getT(0).getT(7).getT(5).getT(4);
		auto& chain135 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(7).getT(6);      // osc1_impl::chain135_t<NV>
		auto& gain65 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(7).getT(6).getT(0);
		auto& pi14 = this->getT(1).getT(0).getT(0).getT(1).                                  // math::pi<NV>
                     getT(0).getT(7).getT(6).getT(1);
		auto& table6 = this->getT(1).getT(0).getT(0).getT(1).                                // osc1_impl::table6_t
                       getT(0).getT(7).getT(6).getT(2);
		auto& one_pole2 = this->getT(1).getT(0).getT(0).getT(1).getT(1);                     // filters::one_pole<NV>
		auto& send6 = this->getT(1).getT(0).getT(0).getT(1).getT(2);                         // routing::send<stereo_cable>
		auto& chain170 = this->getT(1).getT(0).getT(0).getT(1).getT(3);                      // osc1_impl::chain170_t<NV>
		auto& peak20 = this->getT(1).getT(0).getT(0).getT(1).getT(3).getT(0);                // osc1_impl::peak20_t<NV>
		auto& gain73 = this->getT(1).getT(0).getT(0).getT(1).getT(4);                        // core::gain<NV>
		auto& gain5 = this->getT(1).getT(0).getT(0).getT(1).getT(5);                         // core::gain<NV>
		auto& clear21 = this->getT(1).getT(0).getT(0).getT(1).getT(6);                       // math::clear<NV>
		auto& chain73 = this->getT(1).getT(0).getT(0).getT(2);                               // osc1_impl::chain73_t<NV>
		auto& clear25 = this->getT(1).getT(0).getT(0).getT(2).getT(0);                       // math::clear<NV>
		auto& chain87 = this->getT(1).getT(0).getT(0).getT(2).getT(1);                       // osc1_impl::chain87_t<NV>
		auto& split30 = this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(0);               // osc1_impl::split30_t<NV>
		auto& chain191 = this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);      // osc1_impl::chain191_t<NV>
		auto& receive10 = this->getT(1).getT(0).getT(0).getT(2).                             // routing::receive<stereo_cable>
                          getT(1).getT(0).getT(0).getT(0);
		auto& gain8 = this->getT(1).getT(0).getT(0).getT(2).                                 // core::gain<NV>
                      getT(1).getT(0).getT(0).getT(1);
		auto& chain192 = this->getT(1).getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);      // osc1_impl::chain192_t<NV>
		auto& receive11 = this->getT(1).getT(0).getT(0).getT(2).                             // routing::receive<stereo_cable>
                          getT(1).getT(0).getT(1).getT(0);
		auto& gain6 = this->getT(1).getT(0).getT(0).getT(2).                                 // core::gain<NV>
                      getT(1).getT(0).getT(1).getT(1);
		auto& fix8_block = this->getT(1).getT(0).getT(0).getT(2).getT(2);                    // osc1_impl::fix8_block_t<NV>
		auto& modchain8 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(0);             // osc1_impl::modchain8_t<NV>
		auto& split23 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(0).getT(0);       // osc1_impl::split23_t<NV>
		auto& chain94 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::chain94_t<NV>
                        getT(2).getT(0).getT(0).getT(0);
		auto& branch13 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch13_t<NV>
                         getT(2).getT(0).getT(0).getT(0).
                         getT(0);
		auto& chain10 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // osc1_impl::chain10_t<NV>
                        getT(0).getT(0).getT(0).getT(0).getT(0);
		auto& tempo_sync2 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                   // osc1_impl::tempo_sync2_t<NV>
                            getT(0).getT(0).getT(0).getT(0).getT(0).
                            getT(0);
		auto& ramp = this->getT(1).getT(0).getT(0).getT(2).getT(2).                          // osc1_impl::ramp_t<NV>
                     getT(0).getT(0).getT(0).getT(0).getT(0).
                     getT(1);
		auto& chain84 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // osc1_impl::chain84_t<NV>
                        getT(0).getT(0).getT(0).getT(0).getT(1);
		auto& clock_ramp = this->getT(1).getT(0).getT(0).getT(2).getT(2).                    // osc1_impl::clock_ramp_t<NV>
                           getT(0).getT(0).getT(0).getT(0).getT(1).
                           getT(0);
		auto& peak2 = this->getT(1).getT(0).getT(0).getT(2).                                 // osc1_impl::peak2_t<NV>
                      getT(2).getT(0).getT(0).getT(0).
                      getT(1);
		auto& clear10 = this->getT(1).getT(0).getT(0).getT(2).                               // math::clear<NV>
                        getT(2).getT(0).getT(0).getT(0).
                        getT(2);
		auto& branch14 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch14_t<NV>
                         getT(2).getT(0).getT(0).getT(0).
                         getT(3);
		auto& chain91 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // osc1_impl::chain91_t<NV>
                        getT(0).getT(0).getT(0).getT(3).getT(0);
		auto& input_toggle = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::input_toggle_t<NV>
                             getT(0).getT(0).getT(0).getT(3).getT(0).
                             getT(0);
		auto& ahdsr = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // osc1_impl::ahdsr_t<NV>
                      getT(0).getT(0).getT(0).getT(3).getT(0).
                      getT(1);
		auto& clear9 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::clear<NV>
                       getT(0).getT(0).getT(0).getT(3).getT(0).
                       getT(2);
		auto& add2 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                          // math::add<NV>
                     getT(0).getT(0).getT(0).getT(3).getT(0).
                     getT(3);
		auto& chain3 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // osc1_impl::chain3_t<NV>
                       getT(0).getT(0).getT(0).getT(3).getT(1);
		auto& clear8 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::clear<NV>
                       getT(0).getT(0).getT(0).getT(3).getT(1).
                       getT(0);
		auto& cable_table1 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::cable_table1_t<NV>
                             getT(0).getT(0).getT(0).getT(3).getT(1).
                             getT(1);
		auto& clear1 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::clear<NV>
                       getT(0).getT(0).getT(0).getT(3).getT(1).
                       getT(2);
		auto& split22 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // osc1_impl::split22_t<NV>
                        getT(0).getT(0).getT(0).getT(3).getT(1).
                        getT(3);
		auto& add22 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(0).                 // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1).getT(3).getT(0);
		auto& peak7 = this->getT(1).getT(0).getT(0).getT(2).                                 // osc1_impl::peak7_t<NV>
                      getT(2).getT(0).getT(0).getT(0).
                      getT(4);
		auto& chain161 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain161_t<NV>
                         getT(2).getT(0).getT(0).getT(1);
		auto& branch17 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch17_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(0);
		auto& chain162 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain162_t<NV>
                         getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& tempo_sync5 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                   // osc1_impl::tempo_sync5_t<NV>
                            getT(0).getT(0).getT(1).getT(0).getT(0).
                            getT(0);
		auto& ramp4 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // osc1_impl::ramp4_t<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(0).
                      getT(1);
		auto& chain163 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain163_t<NV>
                         getT(0).getT(0).getT(1).getT(0).getT(1);
		auto& clock_ramp3 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                   // osc1_impl::clock_ramp3_t<NV>
                            getT(0).getT(0).getT(1).getT(0).getT(1).
                            getT(0);
		auto& peak14 = this->getT(1).getT(0).getT(0).getT(2).                                // osc1_impl::peak14_t<NV>
                       getT(2).getT(0).getT(0).getT(1).
                       getT(1);
		auto& clear15 = this->getT(1).getT(0).getT(0).getT(2).                               // math::clear<NV>
                        getT(2).getT(0).getT(0).getT(1).
                        getT(2);
		auto& branch18 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch18_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(3);
		auto& chain164 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain164_t<NV>
                         getT(0).getT(0).getT(1).getT(3).getT(0);
		auto& input_toggle2 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                 // osc1_impl::input_toggle2_t<NV>
                              getT(0).getT(0).getT(1).getT(3).getT(0).
                              getT(0);
		auto& ahdsr6 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // osc1_impl::ahdsr6_t<NV>
                       getT(0).getT(0).getT(1).getT(3).getT(0).
                       getT(1);
		auto& clear16 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // math::clear<NV>
                        getT(0).getT(0).getT(1).getT(3).getT(0).
                        getT(2);
		auto& add100 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(0).getT(0).getT(1).getT(3).getT(0).
                       getT(3);
		auto& chain165 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain165_t<NV>
                         getT(0).getT(0).getT(1).getT(3).getT(1);
		auto& clear17 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // math::clear<NV>
                        getT(0).getT(0).getT(1).getT(3).getT(1).
                        getT(0);
		auto& cable_table8 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::cable_table8_t<NV>
                             getT(0).getT(0).getT(1).getT(3).getT(1).
                             getT(1);
		auto& clear18 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // math::clear<NV>
                        getT(0).getT(0).getT(1).getT(3).getT(1).
                        getT(2);
		auto& split25 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // osc1_impl::split25_t<NV>
                        getT(0).getT(0).getT(1).getT(3).getT(1).
                        getT(3);
		auto& add102 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(0).                // math::add<NV>
                       getT(0).getT(1).getT(3).getT(1).getT(3).getT(0);
		auto& peak16 = this->getT(1).getT(0).getT(0).getT(2).                                // osc1_impl::peak16_t<NV>
                       getT(2).getT(0).getT(0).getT(1).
                       getT(4);
		auto& chain178 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain178_t<NV>
                         getT(2).getT(0).getT(0).getT(2);
		auto& chain179 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain179_t<NV>
                         getT(2).getT(0).getT(0).getT(2).
                         getT(0);
		auto& tempo_sync6 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                   // osc1_impl::tempo_sync6_t<NV>
                            getT(0).getT(0).getT(2).getT(0).getT(0);
		auto& ramp5 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // osc1_impl::ramp5_t<NV>
                      getT(0).getT(0).getT(2).getT(0).getT(1);
		auto& branch36 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch36_t<NV>
                         getT(2).getT(0).getT(0).getT(2).
                         getT(1);
		auto& chain102 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain102_t
                         getT(0).getT(0).getT(2).getT(1).getT(0);
		auto& mod_inv = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // math::mod_inv<NV>
                        getT(0).getT(0).getT(2).getT(1).getT(1);
		auto& peak15 = this->getT(1).getT(0).getT(0).getT(2).                                // osc1_impl::peak15_t<NV>
                       getT(2).getT(0).getT(0).getT(2).
                       getT(2);
		auto& clear26 = this->getT(1).getT(0).getT(0).getT(2).                               // math::clear<NV>
                        getT(2).getT(0).getT(0).getT(2).
                        getT(3);
		auto& chain187 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain187_t<NV>
                         getT(2).getT(0).getT(0).getT(3);
		auto& chain188 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain188_t<NV>
                         getT(2).getT(0).getT(0).getT(3).
                         getT(0);
		auto& tempo_sync9 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                   // osc1_impl::tempo_sync9_t<NV>
                            getT(0).getT(0).getT(3).getT(0).getT(0);
		auto& ramp8 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // osc1_impl::ramp8_t<NV>
                      getT(0).getT(0).getT(3).getT(0).getT(1);
		auto& branch89 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch89_t<NV>
                         getT(2).getT(0).getT(0).getT(3).
                         getT(1);
		auto& chain105 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain105_t
                         getT(0).getT(0).getT(3).getT(1).getT(0);
		auto& mod_inv3 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // math::mod_inv<NV>
                         getT(0).getT(0).getT(3).getT(1).getT(1);
		auto& peak49 = this->getT(1).getT(0).getT(0).getT(2).                                // osc1_impl::peak49_t<NV>
                       getT(2).getT(0).getT(0).getT(3).
                       getT(2);
		auto& clear32 = this->getT(1).getT(0).getT(0).getT(2).                               // math::clear<NV>
                        getT(2).getT(0).getT(0).getT(3).
                        getT(3);
		auto& chain185 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain185_t<NV>
                         getT(2).getT(0).getT(0).getT(4);
		auto& chain186 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain186_t<NV>
                         getT(2).getT(0).getT(0).getT(4).
                         getT(0);
		auto& tempo_sync8 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                   // osc1_impl::tempo_sync8_t<NV>
                            getT(0).getT(0).getT(4).getT(0).getT(0);
		auto& ramp7 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // osc1_impl::ramp7_t<NV>
                      getT(0).getT(0).getT(4).getT(0).getT(1);
		auto& branch46 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch46_t<NV>
                         getT(2).getT(0).getT(0).getT(4).
                         getT(1);
		auto& chain104 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain104_t
                         getT(0).getT(0).getT(4).getT(1).getT(0);
		auto& mod_inv2 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // math::mod_inv<NV>
                         getT(0).getT(0).getT(4).getT(1).getT(1);
		auto& peak48 = this->getT(1).getT(0).getT(0).getT(2).                                // osc1_impl::peak48_t<NV>
                       getT(2).getT(0).getT(0).getT(4).
                       getT(2);
		auto& clear31 = this->getT(1).getT(0).getT(0).getT(2).                               // math::clear<NV>
                        getT(2).getT(0).getT(0).getT(4).
                        getT(3);
		auto& chain183 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain183_t<NV>
                         getT(2).getT(0).getT(0).getT(5);
		auto& chain184 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain184_t<NV>
                         getT(2).getT(0).getT(0).getT(5).
                         getT(0);
		auto& tempo_sync7 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                   // osc1_impl::tempo_sync7_t<NV>
                            getT(0).getT(0).getT(5).getT(0).getT(0);
		auto& ramp6 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // osc1_impl::ramp6_t<NV>
                      getT(0).getT(0).getT(5).getT(0).getT(1);
		auto& branch37 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch37_t<NV>
                         getT(2).getT(0).getT(0).getT(5).
                         getT(1);
		auto& chain103 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain103_t
                         getT(0).getT(0).getT(5).getT(1).getT(0);
		auto& mod_inv1 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // math::mod_inv<NV>
                         getT(0).getT(0).getT(5).getT(1).getT(1);
		auto& peak47 = this->getT(1).getT(0).getT(0).getT(2).                                // osc1_impl::peak47_t<NV>
                       getT(2).getT(0).getT(0).getT(5).
                       getT(2);
		auto& clear30 = this->getT(1).getT(0).getT(0).getT(2).                               // math::clear<NV>
                        getT(2).getT(0).getT(0).getT(5).
                        getT(3);
		auto& chain247 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1);              // osc1_impl::chain247_t<NV>
		auto& one_pole = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).getT(0);      // filters::one_pole<NV>
		auto& branch39 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).getT(1);      // osc1_impl::branch39_t<NV>
		auto& xfader1 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::xfader1_t<NV>
                        getT(2).getT(1).getT(1).getT(0);
		auto& xfader5 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::xfader5_t<NV>
                        getT(2).getT(1).getT(1).getT(1);
		auto& xfader6 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::xfader6_t<NV>
                        getT(2).getT(1).getT(1).getT(2);
		auto& sliderbank = this->getT(1).getT(0).getT(0).getT(2).                            // osc1_impl::sliderbank_t<NV>
                           getT(2).getT(1).getT(1).getT(3);
		auto& split10 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).getT(2);       // osc1_impl::split10_t<NV>
		auto& modchain13 = this->getT(1).getT(0).getT(0).getT(2).                            // osc1_impl::modchain13_t<NV>
                           getT(2).getT(1).getT(2).getT(0);
		auto& sliderbank13 = this->getT(1).getT(0).getT(0).getT(2).                          // osc1_impl::sliderbank13_t<NV>
                             getT(2).getT(1).getT(2).getT(0).
                             getT(0);
		auto& split27 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::split27_t<NV>
                        getT(2).getT(1).getT(2).getT(0).
                        getT(1);
		auto& chain230 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain230_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(0);
		auto& global_cable43 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                // osc1_impl::global_cable43_t<NV>
                               getT(1).getT(2).getT(0).getT(1).getT(0).
                               getT(0);
		auto& add179 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(2).getT(0).getT(1).getT(0).
                       getT(1);
		auto& gain124 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // core::gain<NV>
                        getT(1).getT(2).getT(0).getT(1).getT(0).
                        getT(2);
		auto& chain231 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain231_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(1);
		auto& global_cable44 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                // osc1_impl::global_cable44_t<NV>
                               getT(1).getT(2).getT(0).getT(1).getT(1).
                               getT(0);
		auto& add180 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(2).getT(0).getT(1).getT(1).
                       getT(1);
		auto& gain125 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // core::gain<NV>
                        getT(1).getT(2).getT(0).getT(1).getT(1).
                        getT(2);
		auto& chain232 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain232_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(2);
		auto& global_cable45 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                // osc1_impl::global_cable45_t<NV>
                               getT(1).getT(2).getT(0).getT(1).getT(2).
                               getT(0);
		auto& add181 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(2).getT(0).getT(1).getT(2).
                       getT(1);
		auto& gain126 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // core::gain<NV>
                        getT(1).getT(2).getT(0).getT(1).getT(2).
                        getT(2);
		auto& chain233 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain233_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(3);
		auto& global_cable46 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                // osc1_impl::global_cable46_t<NV>
                               getT(1).getT(2).getT(0).getT(1).getT(3).
                               getT(0);
		auto& add182 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(2).getT(0).getT(1).getT(3).
                       getT(1);
		auto& gain127 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // core::gain<NV>
                        getT(1).getT(2).getT(0).getT(1).getT(3).
                        getT(2);
		auto& chain234 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain234_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(4);
		auto& add183 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(2).getT(0).getT(1).getT(4).
                       getT(0);
		auto& gain128 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // core::gain<NV>
                        getT(1).getT(2).getT(0).getT(1).getT(4).
                        getT(1);
		auto& chain235 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain235_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(5);
		auto& add184 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(2).getT(0).getT(1).getT(5).
                       getT(0);
		auto& gain129 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // core::gain<NV>
                        getT(1).getT(2).getT(0).getT(1).getT(5).
                        getT(1);
		auto& chain236 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain236_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(6);
		auto& branch51 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::branch51_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(6).
                         getT(0);
		auto& add185 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(6).getT(0).getT(0);
		auto& add186 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(6).getT(0).getT(1);
		auto& add187 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(6).getT(0).getT(2);
		auto& add188 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(6).getT(0).getT(3);
		auto& add189 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(2).getT(0).getT(1).getT(6).
                       getT(1);
		auto& gain130 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // core::gain<NV>
                        getT(1).getT(2).getT(0).getT(1).getT(6).
                        getT(2);
		auto& chain237 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain237_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(7);
		auto& branch52 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::branch52_t<NV>
                         getT(1).getT(2).getT(0).getT(1).getT(7).
                         getT(0);
		auto& chain238 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::chain238_t<NV>
                         getT(2).getT(0).getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc43 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).             // osc1_impl::midi_cc43_t<NV>
                          getT(2).getT(0).getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add190 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(0).
                       getT(1);
		auto& chain239 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::chain239_t<NV>
                         getT(2).getT(0).getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc44 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).             // osc1_impl::midi_cc44_t<NV>
                          getT(2).getT(0).getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add191 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(1).
                       getT(1);
		auto& chain240 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::chain240_t<NV>
                         getT(2).getT(0).getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc45 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).             // osc1_impl::midi_cc45_t<NV>
                          getT(2).getT(0).getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add192 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(2).
                       getT(1);
		auto& chain241 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::chain241_t<NV>
                         getT(2).getT(0).getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc46 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).             // osc1_impl::midi_cc46_t<NV>
                          getT(2).getT(0).getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add193 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(3).
                       getT(1);
		auto& chain242 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::chain242_t<NV>
                         getT(2).getT(0).getT(1).getT(7).getT(0).getT(4);
		auto& midi32 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // osc1_impl::midi32_t<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(4).
                       getT(0);
		auto& add194 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(4).
                       getT(1);
		auto& chain243 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::chain243_t<NV>
                         getT(2).getT(0).getT(1).getT(7).getT(0).getT(5);
		auto& midi33 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // osc1_impl::midi33_t<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(5).
                       getT(0);
		auto& add195 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(5).
                       getT(1);
		auto& chain244 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::chain244_t<NV>
                         getT(2).getT(0).getT(1).getT(7).getT(0).getT(6);
		auto& midi34 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // osc1_impl::midi34_t<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(6).
                       getT(0);
		auto& add196 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(1).getT(7).getT(0).getT(6).
                       getT(1);
		auto& gain131 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                       // core::gain<NV>
                        getT(1).getT(2).getT(0).getT(1).getT(7).
                        getT(1);
		auto& peak21 = this->getT(1).getT(0).getT(0).getT(2).                                // osc1_impl::peak21_t<NV>
                       getT(2).getT(1).getT(2).getT(0).
                       getT(2);
		auto& clear2 = this->getT(1).getT(0).getT(0).getT(2).                                // math::clear<NV>
                       getT(2).getT(1).getT(2).getT(0).
                       getT(3);
		auto& pma17 = this->getT(1).getT(0).getT(0).getT(2).                                 // osc1_impl::pma17_t<NV>
                      getT(2).getT(1).getT(2).getT(0).
                      getT(4);
		auto& chain248 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain248_t<NV>
                         getT(2).getT(1).getT(2).getT(0).
                         getT(5);
		auto& branch21 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::branch21_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0);
		auto& chain250 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain250_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(0);
		auto& add213 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(0).getT(0);
		auto& chain251 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain251_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(1);
		auto& minmax6 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).               // osc1_impl::minmax6_t<NV>
                        getT(2).getT(0).getT(5).getT(0).getT(1).getT(0);
		auto& add214 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(1).getT(1);
		auto& chain252 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain252_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(2);
		auto& minmax7 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).               // osc1_impl::minmax7_t<NV>
                        getT(2).getT(0).getT(5).getT(0).getT(2).getT(0);
		auto& add215 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(2).getT(1);
		auto& chain253 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain253_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(3);
		auto& minmax14 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax14_t<NV>
                         getT(2).getT(0).getT(5).getT(0).getT(3).getT(0);
		auto& add216 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(3).getT(1);
		auto& chain254 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain254_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(4);
		auto& minmax11 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax11_t<NV>
                         getT(2).getT(0).getT(5).getT(0).getT(4).getT(0);
		auto& add217 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(4).getT(1);
		auto& chain255 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain255_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(5);
		auto& minmax15 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax15_t<NV>
                         getT(2).getT(0).getT(5).getT(0).getT(5).getT(0);
		auto& add218 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(5).getT(1);
		auto& chain256 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain256_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(6);
		auto& minmax16 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax16_t<NV>
                         getT(2).getT(0).getT(5).getT(0).getT(6).getT(0);
		auto& add219 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(6).getT(1);
		auto& chain257 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain257_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(7);
		auto& minmax17 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax17_t<NV>
                         getT(2).getT(0).getT(5).getT(0).getT(7).getT(0);
		auto& add220 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(7).getT(1);
		auto& chain258 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain258_t<NV>
                         getT(1).getT(2).getT(0).getT(5).getT(0).
                         getT(8);
		auto& minmax18 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax18_t<NV>
                         getT(2).getT(0).getT(5).getT(0).getT(8).getT(0);
		auto& add221 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(0).getT(5).getT(0).getT(8).getT(1);
		auto& peak18 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // osc1_impl::peak18_t<NV>
                       getT(1).getT(2).getT(0).getT(5).getT(1);
		auto& cable_table5 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::cable_table5_t
                             getT(1).getT(2).getT(0).getT(5).getT(2);
		auto& modchain31 = this->getT(1).getT(0).getT(0).getT(2).                            // osc1_impl::modchain31_t<NV>
                           getT(2).getT(1).getT(2).getT(1);
		auto& pma33 = this->getT(1).getT(0).getT(0).getT(2).                                 // osc1_impl::pma33_t<NV>
                      getT(2).getT(1).getT(2).getT(1).
                      getT(0);
		auto& chain535 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain535_t<NV>
                         getT(2).getT(1).getT(2).getT(1).
                         getT(1);
		auto& branch32 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::branch32_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0);
		auto& chain536 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain536_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(0);
		auto& add551 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(0).getT(0);
		auto& chain537 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain537_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(1);
		auto& minmax30 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax30_t<NV>
                         getT(2).getT(1).getT(1).getT(0).getT(1).getT(0);
		auto& add552 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(1).getT(1);
		auto& chain538 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain538_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(2);
		auto& minmax31 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax31_t<NV>
                         getT(2).getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& add553 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& chain539 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain539_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(3);
		auto& minmax32 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax32_t<NV>
                         getT(2).getT(1).getT(1).getT(0).getT(3).getT(0);
		auto& add554 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(3).getT(1);
		auto& chain540 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain540_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(4);
		auto& minmax33 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax33_t<NV>
                         getT(2).getT(1).getT(1).getT(0).getT(4).getT(0);
		auto& add555 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(4).getT(1);
		auto& chain541 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain541_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(5);
		auto& minmax34 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax34_t<NV>
                         getT(2).getT(1).getT(1).getT(0).getT(5).getT(0);
		auto& add556 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(5).getT(1);
		auto& chain542 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain542_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(6);
		auto& minmax35 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax35_t<NV>
                         getT(2).getT(1).getT(1).getT(0).getT(6).getT(0);
		auto& add557 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(6).getT(1);
		auto& chain543 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain543_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(7);
		auto& minmax36 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax36_t<NV>
                         getT(2).getT(1).getT(1).getT(0).getT(7).getT(0);
		auto& add558 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(7).getT(1);
		auto& chain544 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain544_t<NV>
                         getT(1).getT(2).getT(1).getT(1).getT(0).
                         getT(8);
		auto& minmax37 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax37_t<NV>
                         getT(2).getT(1).getT(1).getT(0).getT(8).getT(0);
		auto& add559 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(1).getT(1).getT(0).getT(8).getT(1);
		auto& peak43 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // osc1_impl::peak43_t<NV>
                       getT(1).getT(2).getT(1).getT(1).getT(1);
		auto& clear4 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::clear<NV>
                       getT(1).getT(2).getT(1).getT(1).getT(2);
		auto& clear5 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::clear<NV>
                       getT(1).getT(2).getT(1).getT(1).getT(3);
		auto& cable_table9 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::cable_table9_t
                             getT(1).getT(2).getT(1).getT(1).getT(4);
		auto& modchain30 = this->getT(1).getT(0).getT(0).getT(2).                            // osc1_impl::modchain30_t<NV>
                           getT(2).getT(1).getT(2).getT(2);
		auto& pma32 = this->getT(1).getT(0).getT(0).getT(2).                                 // osc1_impl::pma32_t<NV>
                      getT(2).getT(1).getT(2).getT(2).
                      getT(0);
		auto& chain510 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain510_t<NV>
                         getT(2).getT(1).getT(2).getT(2).
                         getT(1);
		auto& branch31 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::branch31_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0);
		auto& chain511 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain511_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(0);
		auto& add524 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& chain512 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain512_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(1);
		auto& minmax10 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax10_t<NV>
                         getT(2).getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& add525 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(1).getT(1);
		auto& chain513 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain513_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(2);
		auto& minmax13 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax13_t<NV>
                         getT(2).getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& add526 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(2).getT(1);
		auto& chain514 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain514_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(3);
		auto& minmax24 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax24_t<NV>
                         getT(2).getT(2).getT(1).getT(0).getT(3).getT(0);
		auto& add527 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(3).getT(1);
		auto& chain515 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain515_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(4);
		auto& minmax25 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax25_t<NV>
                         getT(2).getT(2).getT(1).getT(0).getT(4).getT(0);
		auto& add528 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(4).getT(1);
		auto& chain516 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain516_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(5);
		auto& minmax26 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax26_t<NV>
                         getT(2).getT(2).getT(1).getT(0).getT(5).getT(0);
		auto& add529 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(5).getT(1);
		auto& chain517 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain517_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(6);
		auto& minmax27 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax27_t<NV>
                         getT(2).getT(2).getT(1).getT(0).getT(6).getT(0);
		auto& add530 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(6).getT(1);
		auto& chain518 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain518_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(7);
		auto& minmax28 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax28_t<NV>
                         getT(2).getT(2).getT(1).getT(0).getT(7).getT(0);
		auto& add531 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(7).getT(1);
		auto& chain519 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain519_t<NV>
                         getT(1).getT(2).getT(2).getT(1).getT(0).
                         getT(8);
		auto& minmax29 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax29_t<NV>
                         getT(2).getT(2).getT(1).getT(0).getT(8).getT(0);
		auto& add532 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(2).getT(1).getT(0).getT(8).getT(1);
		auto& peak31 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // osc1_impl::peak31_t<NV>
                       getT(1).getT(2).getT(2).getT(1).getT(1);
		auto& cable_table7 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::cable_table7_t
                             getT(1).getT(2).getT(2).getT(1).getT(2);
		auto& modchain29 = this->getT(1).getT(0).getT(0).getT(2).                            // osc1_impl::modchain29_t<NV>
                           getT(2).getT(1).getT(2).getT(3);
		auto& pma31 = this->getT(1).getT(0).getT(0).getT(2).                                 // osc1_impl::pma31_t<NV>
                      getT(2).getT(1).getT(2).getT(3).
                      getT(0);
		auto& chain485 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain485_t<NV>
                         getT(2).getT(1).getT(2).getT(3).
                         getT(1);
		auto& branch30 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::branch30_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0);
		auto& chain486 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain486_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(0);
		auto& add497 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(0).getT(0);
		auto& chain487 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain487_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(1);
		auto& minmax8 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).               // osc1_impl::minmax8_t<NV>
                        getT(2).getT(3).getT(1).getT(0).getT(1).getT(0);
		auto& add498 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(1).getT(1);
		auto& chain488 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain488_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(2);
		auto& minmax9 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).               // osc1_impl::minmax9_t<NV>
                        getT(2).getT(3).getT(1).getT(0).getT(2).getT(0);
		auto& add499 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(2).getT(1);
		auto& chain489 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain489_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(3);
		auto& minmax19 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax19_t<NV>
                         getT(2).getT(3).getT(1).getT(0).getT(3).getT(0);
		auto& add500 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(3).getT(1);
		auto& chain490 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain490_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(4);
		auto& minmax12 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax12_t<NV>
                         getT(2).getT(3).getT(1).getT(0).getT(4).getT(0);
		auto& add501 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(4).getT(1);
		auto& chain491 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain491_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(5);
		auto& minmax20 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax20_t<NV>
                         getT(2).getT(3).getT(1).getT(0).getT(5).getT(0);
		auto& add502 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(5).getT(1);
		auto& chain492 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain492_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(6);
		auto& minmax21 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax21_t<NV>
                         getT(2).getT(3).getT(1).getT(0).getT(6).getT(0);
		auto& add503 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(6).getT(1);
		auto& chain493 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain493_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(7);
		auto& minmax22 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax22_t<NV>
                         getT(2).getT(3).getT(1).getT(0).getT(7).getT(0);
		auto& add504 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(7).getT(1);
		auto& chain494 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain494_t<NV>
                         getT(1).getT(2).getT(3).getT(1).getT(0).
                         getT(8);
		auto& minmax23 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax23_t<NV>
                         getT(2).getT(3).getT(1).getT(0).getT(8).getT(0);
		auto& add505 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(3).getT(1).getT(0).getT(8).getT(1);
		auto& peak29 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // osc1_impl::peak29_t<NV>
                       getT(1).getT(2).getT(3).getT(1).getT(1);
		auto& cable_table6 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::cable_table6_t
                             getT(1).getT(2).getT(3).getT(1).getT(2);
		auto& modchain32 = this->getT(1).getT(0).getT(0).getT(2).                            // osc1_impl::modchain32_t<NV>
                           getT(2).getT(1).getT(2).getT(4);
		auto& pma34 = this->getT(1).getT(0).getT(0).getT(2).                                 // osc1_impl::pma34_t<NV>
                      getT(2).getT(1).getT(2).getT(4).
                      getT(0);
		auto& chain560 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain560_t<NV>
                         getT(2).getT(1).getT(2).getT(4).
                         getT(1);
		auto& branch33 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::branch33_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0);
		auto& chain561 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain561_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(0);
		auto& add578 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(0).getT(0);
		auto& chain562 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain562_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(1);
		auto& minmax38 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax38_t<NV>
                         getT(2).getT(4).getT(1).getT(0).getT(1).getT(0);
		auto& add579 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(1).getT(1);
		auto& chain563 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain563_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(2);
		auto& minmax39 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax39_t<NV>
                         getT(2).getT(4).getT(1).getT(0).getT(2).getT(0);
		auto& add580 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(2).getT(1);
		auto& chain564 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain564_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(3);
		auto& minmax40 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax40_t<NV>
                         getT(2).getT(4).getT(1).getT(0).getT(3).getT(0);
		auto& add581 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(3).getT(1);
		auto& chain565 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain565_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(4);
		auto& minmax41 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax41_t<NV>
                         getT(2).getT(4).getT(1).getT(0).getT(4).getT(0);
		auto& add582 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(4).getT(1);
		auto& chain566 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain566_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(5);
		auto& minmax42 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax42_t<NV>
                         getT(2).getT(4).getT(1).getT(0).getT(5).getT(0);
		auto& add583 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(5).getT(1);
		auto& chain567 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain567_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(6);
		auto& minmax43 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax43_t<NV>
                         getT(2).getT(4).getT(1).getT(0).getT(6).getT(0);
		auto& add584 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(6).getT(1);
		auto& chain568 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain568_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(7);
		auto& minmax44 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax44_t<NV>
                         getT(2).getT(4).getT(1).getT(0).getT(7).getT(0);
		auto& add585 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(7).getT(1);
		auto& chain569 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                      // osc1_impl::chain569_t<NV>
                         getT(1).getT(2).getT(4).getT(1).getT(0).
                         getT(8);
		auto& minmax45 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).              // osc1_impl::minmax45_t<NV>
                         getT(2).getT(4).getT(1).getT(0).getT(8).getT(0);
		auto& add586 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).                // math::add<NV>
                       getT(2).getT(4).getT(1).getT(0).getT(8).getT(1);
		auto& peak45 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // osc1_impl::peak45_t<NV>
                       getT(1).getT(2).getT(4).getT(1).getT(1);
		auto& cable_table10 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                 // osc1_impl::cable_table10_t
                              getT(1).getT(2).getT(4).getT(1).getT(2);
		auto& split17 = this->getT(1).getT(0).getT(0).getT(2).getT(2).getT(1).getT(3);       // osc1_impl::split17_t<NV>
		auto& chain174 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain174_t<NV>
                         getT(2).getT(1).getT(3).getT(0);
		auto& split11 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::split11_t<NV>
                        getT(2).getT(1).getT(3).getT(0).
                        getT(0);
		auto& add222 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(3).getT(0).getT(0).getT(0);
		auto& add463 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(3).getT(0).getT(0).getT(1);
		auto& branch22 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch22_t<NV>
                         getT(2).getT(1).getT(3).getT(0).
                         getT(1);
		auto& file_player6 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::file_player6_t<NV>
                             getT(1).getT(3).getT(0).getT(1).getT(0);
		auto& file_player7 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::file_player7_t<NV>
                             getT(1).getT(3).getT(0).getT(1).getT(1);
		auto& branch26 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch26_t<NV>
                         getT(2).getT(1).getT(3).getT(0).
                         getT(2);
		auto& gain4 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // core::gain<NV>
                      getT(1).getT(3).getT(0).getT(2).getT(0);
		auto& gain10 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(0).getT(2).getT(1);
		auto& gain9 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // core::gain<NV>
                      getT(1).getT(3).getT(0).getT(2).getT(2);
		auto& gain7 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                         // core::gain<NV>
                      getT(1).getT(3).getT(0).getT(2).getT(3);
		auto& chain175 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain175_t<NV>
                         getT(2).getT(1).getT(3).getT(1);
		auto& split40 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::split40_t<NV>
                        getT(2).getT(1).getT(3).getT(1).
                        getT(0);
		auto& add474 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(3).getT(1).getT(0).getT(0);
		auto& add475 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(3).getT(1).getT(0).getT(1);
		auto& branch40 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch40_t<NV>
                         getT(2).getT(1).getT(3).getT(1).
                         getT(1);
		auto& file_player8 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::file_player8_t<NV>
                             getT(1).getT(3).getT(1).getT(1).getT(0);
		auto& file_player9 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                  // osc1_impl::file_player9_t<NV>
                             getT(1).getT(3).getT(1).getT(1).getT(1);
		auto& branch41 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch41_t<NV>
                         getT(2).getT(1).getT(3).getT(1).
                         getT(2);
		auto& gain72 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(1).getT(2).getT(0);
		auto& gain89 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(1).getT(2).getT(1);
		auto& gain90 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(1).getT(2).getT(2);
		auto& gain91 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(1).getT(2).getT(3);
		auto& chain176 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain176_t<NV>
                         getT(2).getT(1).getT(3).getT(2);
		auto& split21 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::split21_t<NV>
                        getT(2).getT(1).getT(3).getT(2).
                        getT(0);
		auto& add469 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(3).getT(2).getT(0).getT(0);
		auto& add470 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(3).getT(2).getT(0).getT(1);
		auto& branch42 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch42_t<NV>
                         getT(2).getT(1).getT(3).getT(2).
                         getT(1);
		auto& file_player10 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                 // osc1_impl::file_player10_t<NV>
                              getT(1).getT(3).getT(2).getT(1).getT(0);
		auto& file_player11 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                 // osc1_impl::file_player11_t<NV>
                              getT(1).getT(3).getT(2).getT(1).getT(1);
		auto& branch43 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch43_t<NV>
                         getT(2).getT(1).getT(3).getT(2).
                         getT(2);
		auto& gain92 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(2).getT(2).getT(0);
		auto& gain93 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(2).getT(2).getT(1);
		auto& gain94 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(2).getT(2).getT(2);
		auto& gain95 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(2).getT(2).getT(3);
		auto& chain177 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::chain177_t<NV>
                         getT(2).getT(1).getT(3).getT(3);
		auto& split19 = this->getT(1).getT(0).getT(0).getT(2).                               // osc1_impl::split19_t<NV>
                        getT(2).getT(1).getT(3).getT(3).
                        getT(0);
		auto& add464 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(3).getT(3).getT(0).getT(0);
		auto& add465 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // math::add<NV>
                       getT(1).getT(3).getT(3).getT(0).getT(1);
		auto& branch44 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch44_t<NV>
                         getT(2).getT(1).getT(3).getT(3).
                         getT(1);
		auto& file_player12 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                 // osc1_impl::file_player12_t<NV>
                              getT(1).getT(3).getT(3).getT(1).getT(0);
		auto& file_player13 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                 // osc1_impl::file_player13_t<NV>
                              getT(1).getT(3).getT(3).getT(1).getT(1);
		auto& branch45 = this->getT(1).getT(0).getT(0).getT(2).                              // osc1_impl::branch45_t<NV>
                         getT(2).getT(1).getT(3).getT(3).
                         getT(2);
		auto& gain96 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(3).getT(2).getT(0);
		auto& gain97 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(3).getT(2).getT(1);
		auto& gain98 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(3).getT(2).getT(2);
		auto& gain99 = this->getT(1).getT(0).getT(0).getT(2).getT(2).                        // core::gain<NV>
                       getT(1).getT(3).getT(3).getT(2).getT(3);
		auto& branch23 = this->getT(1).getT(0).getT(0).getT(2).getT(3);                      // osc1_impl::branch23_t<NV>
		auto& chain261 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(0);              // osc1_impl::chain261_t<NV>
		auto& tanh2 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(0).getT(0);         // wrap::no_process<math::tanh<NV>>
		auto& chain262 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(1);              // osc1_impl::chain262_t<NV>
		auto& receive2 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(1).getT(0);      // routing::receive<stereo_cable>
		auto& faust3 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(1).getT(1);        // project::shfiter<NV>
		auto& send2 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(1).getT(2);         // routing::send<stereo_cable>
		auto& chain263 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2);              // osc1_impl::chain263_t<NV>
		auto& midi42 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2).getT(0);        // osc1_impl::midi42_t<NV>
		auto& cable_table15 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2).getT(1); // osc1_impl::cable_table15_t<NV>
		auto& receive3 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2).getT(2);      // routing::receive<stereo_cable>
		auto& faust4 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2).getT(3);        // project::ps2<NV>
		auto& faust5 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2).getT(4);        // project::shfiter<NV>
		auto& send3 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2).getT(5);         // routing::send<stereo_cable>
		auto& chain101 = this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(3);              // osc1_impl::chain101_t
		auto& send1 = this->getT(1).getT(0).getT(0).getT(2).getT(4);                         // routing::send<stereo_cable>
		auto& peak22 = this->getT(1).getT(0).getT(0).getT(2).getT(5);                        // osc1_impl::peak22_t<NV>
		auto& clear20 = this->getT(1).getT(0).getT(0).getT(2).getT(6);                       // math::clear<NV>
		auto& chain58 = this->getT(1).getT(0).getT(0).getT(3);                               // osc1_impl::chain58_t<NV>
		auto& clear24 = this->getT(1).getT(0).getT(0).getT(3).getT(0);                       // math::clear<NV>
		auto& split31 = this->getT(1).getT(0).getT(0).getT(3).getT(1);                       // osc1_impl::split31_t<NV>
		auto& chain193 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(0);              // osc1_impl::chain193_t<NV>
		auto& receive13 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(0).getT(0);     // routing::receive<stereo_cable>
		auto& gain45 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(0).getT(1);        // core::gain<NV>
		auto& chain195 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(1);              // osc1_impl::chain195_t<NV>
		auto& receive14 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(1).getT(0);     // routing::receive<stereo_cable>
		auto& gain47 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(1).getT(1);        // core::gain<NV>
		auto& chain194 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(2);              // osc1_impl::chain194_t<NV>
		auto& receive15 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(2).getT(0);     // routing::receive<stereo_cable>
		auto& gain46 = this->getT(1).getT(0).getT(0).getT(3).getT(1).getT(2).getT(1);        // core::gain<NV>
		auto& xfader = this->getT(1).getT(0).getT(0).getT(3).getT(2);                        // osc1_impl::xfader_t<NV>
		auto& split12 = this->getT(1).getT(0).getT(0).getT(3).getT(3);                       // osc1_impl::split12_t<NV>
		auto& chain14 = this->getT(1).getT(0).getT(0).getT(3).getT(3).getT(0);               // osc1_impl::chain14_t<NV>
		auto& gain1 = this->getT(1).getT(0).getT(0).getT(3).getT(3).getT(0).getT(0);         // core::gain<NV>
		auto& chain57 = this->getT(1).getT(0).getT(0).getT(3).getT(3).getT(1);               // osc1_impl::chain57_t<NV>
		auto& chain15 = this->getT(1).getT(0).getT(0).getT(3).getT(3).getT(1).getT(0);       // osc1_impl::chain15_t<NV>
		auto& branch = this->getT(1).getT(0).getT(0).getT(3).                                // osc1_impl::branch_t<NV>
                       getT(3).getT(1).getT(0).getT(0);
		auto& chain16 = this->getT(1).getT(0).getT(0).getT(3).                       // osc1_impl::chain16_t<NV>
                        getT(3).getT(1).getT(0).getT(0).
                        getT(0);
		auto& faust = this->getT(1).getT(0).getT(0).getT(3).getT(3).                 // project::klp<NV>
                      getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& faust1 = this->getT(1).getT(0).getT(0).getT(3).getT(3).                // project::khp2<NV>
                       getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain35 = this->getT(1).getT(0).getT(0).getT(3).                       // osc1_impl::chain35_t<NV>
                        getT(3).getT(1).getT(0).getT(0).
                        getT(1);
		auto& split1 = this->getT(1).getT(0).getT(0).getT(3).getT(3).                // osc1_impl::split1_t<NV>
                       getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& faust2 = this->getT(1).getT(0).getT(0).getT(3).getT(3).                // project::klp<NV>
                       getT(1).getT(0).getT(0).getT(1).getT(0).
                       getT(0);
		auto& faust6 = this->getT(1).getT(0).getT(0).getT(3).getT(3).                // project::khp2<NV>
                       getT(1).getT(0).getT(0).getT(1).getT(0).
                       getT(1);
		auto& chain36 = this->getT(1).getT(0).getT(0).getT(3).                       // osc1_impl::chain36_t<NV>
                        getT(3).getT(1).getT(0).getT(0).
                        getT(2);
		auto& cable_table = this->getT(1).getT(0).getT(0).getT(3).getT(3).           // osc1_impl::cable_table_t<NV>
                            getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& faust8 = this->getT(1).getT(0).getT(0).getT(3).getT(3).                // project::Comb<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& faust7 = this->getT(1).getT(0).getT(0).getT(3).getT(3).                // project::klp<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(2);
		auto& chain37 = this->getT(1).getT(0).getT(0).getT(3).                       // osc1_impl::chain37_t<NV>
                        getT(3).getT(1).getT(0).getT(0).
                        getT(3);
		auto& cable_table2 = this->getT(1).getT(0).getT(0).getT(3).getT(3).          // osc1_impl::cable_table2_t<NV>
                             getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& faust10 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // project::klp<NV>
                        getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& faust9 = this->getT(1).getT(0).getT(0).getT(3).getT(3).                // project::Comb<NV>
                       getT(1).getT(0).getT(0).getT(3).getT(2);
		auto& split9 = this->getT(1).getT(0).getT(0).getT(3).                        // osc1_impl::split9_t<NV>
                       getT(3).getT(1).getT(0).getT(0).
                       getT(4);
		auto& chain55 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // osc1_impl::chain55_t<NV>
                        getT(1).getT(0).getT(0).getT(4).getT(0);
		auto& faust11 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // project::klp<NV>
                        getT(1).getT(0).getT(0).getT(4).getT(0).
                        getT(0);
		auto& jpanner = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // jdsp::jpanner<NV>
                        getT(1).getT(0).getT(0).getT(4).getT(0).
                        getT(1);
		auto& chain56 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // osc1_impl::chain56_t<NV>
                        getT(1).getT(0).getT(0).getT(4).getT(1);
		auto& faust12 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // project::klp<NV>
                        getT(1).getT(0).getT(0).getT(4).getT(1).
                        getT(0);
		auto& jpanner2 = this->getT(1).getT(0).getT(0).getT(3).getT(3).              // jdsp::jpanner<NV>
                         getT(1).getT(0).getT(0).getT(4).getT(1).
                         getT(1);
		auto& split13 = this->getT(1).getT(0).getT(0).getT(3).                       // osc1_impl::split13_t<NV>
                        getT(3).getT(1).getT(0).getT(0).
                        getT(5);
		auto& chain60 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // osc1_impl::chain60_t<NV>
                        getT(1).getT(0).getT(0).getT(5).getT(0);
		auto& faust13 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // project::khp<NV>
                        getT(1).getT(0).getT(0).getT(5).getT(0).
                        getT(0);
		auto& jpanner4 = this->getT(1).getT(0).getT(0).getT(3).getT(3).              // jdsp::jpanner<NV>
                         getT(1).getT(0).getT(0).getT(5).getT(0).
                         getT(1);
		auto& chain61 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // osc1_impl::chain61_t<NV>
                        getT(1).getT(0).getT(0).getT(5).getT(1);
		auto& faust14 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // project::khp<NV>
                        getT(1).getT(0).getT(0).getT(5).getT(1).
                        getT(0);
		auto& jpanner5 = this->getT(1).getT(0).getT(0).getT(3).getT(3).              // jdsp::jpanner<NV>
                         getT(1).getT(0).getT(0).getT(5).getT(1).
                         getT(1);
		auto& split14 = this->getT(1).getT(0).getT(0).getT(3).                       // osc1_impl::split14_t<NV>
                        getT(3).getT(1).getT(0).getT(0).
                        getT(6);
		auto& chain71 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // osc1_impl::chain71_t<NV>
                        getT(1).getT(0).getT(0).getT(6).getT(0);
		auto& cable_table3 = this->getT(1).getT(0).getT(0).getT(3).getT(3).          // osc1_impl::cable_table3_t<NV>
                             getT(1).getT(0).getT(0).getT(6).getT(0).
                             getT(0);
		auto& faust15 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // project::Comb<NV>
                        getT(1).getT(0).getT(0).getT(6).getT(0).
                        getT(1);
		auto& jpanner6 = this->getT(1).getT(0).getT(0).getT(3).getT(3).              // jdsp::jpanner<NV>
                         getT(1).getT(0).getT(0).getT(6).getT(0).
                         getT(2);
		auto& chain72 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // osc1_impl::chain72_t<NV>
                        getT(1).getT(0).getT(0).getT(6).getT(1);
		auto& cable_table4 = this->getT(1).getT(0).getT(0).getT(3).getT(3).          // osc1_impl::cable_table4_t<NV>
                             getT(1).getT(0).getT(0).getT(6).getT(1).
                             getT(0);
		auto& faust16 = this->getT(1).getT(0).getT(0).getT(3).getT(3).               // project::Comb<NV>
                        getT(1).getT(0).getT(0).getT(6).getT(1).
                        getT(1);
		auto& jpanner7 = this->getT(1).getT(0).getT(0).getT(3).getT(3).              // jdsp::jpanner<NV>
                         getT(1).getT(0).getT(0).getT(6).getT(1).
                         getT(2);
		auto& send7 = this->getT(1).getT(0).getT(0).getT(3).getT(3).getT(1).getT(1); // routing::send<stereo_cable>
		auto& gain2 = this->getT(1).getT(0).getT(0).getT(3).getT(3).getT(1).getT(2); // core::gain<NV>
		auto& peak33 = this->getT(1).getT(0).getT(0).getT(3).getT(4);                // osc1_impl::peak33_t<NV>
		auto& gain77 = this->getT(2);                                                // core::gain<NV>
		auto& oscilloscope = this->getT(3);                                          // osc1_impl::oscilloscope_t
		auto& jpanner3 = this->getT(4);                                              // jdsp::jpanner<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Pitch -> pma1::Add
		
		auto& tempo_p = this->getParameterT(1);
		tempo_p.connectT(0, pma8);  // tempo -> pma8::Add
		tempo_p.connectT(1, pma11); // tempo -> pma11::Add
		
		auto& div_p = this->getParameterT(2);
		div_p.connectT(0, tempo_sync);  // div -> tempo_sync::Multiplier
		div_p.connectT(1, tempo_sync1); // div -> tempo_sync1::Multiplier
		
		auto& pitchmode_p = this->getParameterT(3);
		pitchmode_p.connectT(0, branch1);  // pitchmode -> branch1::Index
		pitchmode_p.connectT(1, branch3);  // pitchmode -> branch3::Index
		pitchmode_p.connectT(2, branch7);  // pitchmode -> branch7::Index
		pitchmode_p.connectT(3, branch12); // pitchmode -> branch12::Index
		
		auto& step_p = this->getParameterT(4);
		step_p.connectT(0, minmax2); // step -> minmax2::Step
		step_p.connectT(1, minmax3); // step -> minmax3::Step
		
		this->getParameterT(5).connectT(0, pma2); // OsMix -> pma2::Add
		
		auto& PitchMod_p = this->getParameterT(6);
		PitchMod_p.connectT(0, pma1);  // PitchMod -> pma1::Multiply
		PitchMod_p.connectT(1, pma8);  // PitchMod -> pma8::Multiply
		PitchMod_p.connectT(2, pma11); // PitchMod -> pma11::Multiply
		
		this->getParameterT(7).connectT(0, pma2); // OscMixMod -> pma2::Multiply
		
		this->getParameterT(8).connectT(0, pma4); // Input1 -> pma4::Add
		
		this->getParameterT(9).connectT(0, pma4); // InMod1 -> pma4::Multiply
		
		auto& Tempo2_p = this->getParameterT(10);
		Tempo2_p.connectT(0, pma14); // Tempo2 -> pma14::Add
		Tempo2_p.connectT(1, pma15); // Tempo2 -> pma15::Add
		
		this->getParameterT(11).connectT(0, branch5); // MidiSlotPitch -> branch5::Index
		
		this->getParameterT(12).connectT(0, pma9); // Width2 -> pma9::Add
		
		this->getParameterT(13).connectT(0, pma9); // Width2Mod -> pma9::Multiply
		
		this->getParameterT(14).connectT(0, smoother1); // Bend2 -> smoother1::SmoothingTime
		
		this->getParameterT(15).connectT(0, smoother); // Bend -> smoother::SmoothingTime
		
		this->getParameterT(16).connectT(0, branch10); // Shape2 -> branch10::Index
		
		this->getParameterT(17).connectT(0, branch2); // Shape -> branch2::Index
		
		this->getParameterT(18).connectT(0, pma16); // WidhMod -> pma16::Multiply
		
		this->getParameterT(19).connectT(0, pma16); // Width -> pma16::Add
		
		this->getParameterT(20).connectT(0, branch48); // MidiWidth2 -> branch48::Index
		
		this->getParameterT(21).connectT(0, branch50); // MidiWidth -> branch50::Index
		
		this->getParameterT(22).connectT(0, pma17); // PositionMod -> pma17::Multiply
		
		this->getParameterT(23).connectT(0, pma17); // Position -> pma17::Add
		
		auto& QuantisePositiion_p = this->getParameterT(24);
		QuantisePositiion_p.connectT(0, branch21); // QuantisePositiion -> branch21::Index
		QuantisePositiion_p.connectT(1, branch32); // QuantisePositiion -> branch32::Index
		QuantisePositiion_p.connectT(2, branch31); // QuantisePositiion -> branch31::Index
		QuantisePositiion_p.connectT(3, branch30); // QuantisePositiion -> branch30::Index
		QuantisePositiion_p.connectT(4, branch33); // QuantisePositiion -> branch33::Index
		
		this->getParameterT(25).connectT(0, one_pole); // PosSmooth -> one_pole::Frequency
		
		this->getParameterT(26).connectT(0, pma20); // FilePitch -> pma20::Add
		
		this->getParameterT(27).connectT(0, branch23); // PtichShiftOn -> branch23::Index
		
		this->getParameterT(28).connectT(0, pma20); // FilePitchMod -> pma20::Multiply
		
		this->getParameterT(29).connectT(0, pma_unscaled); // PitchWin -> pma_unscaled::Add
		
		this->getParameterT(30).connectT(0, pma_unscaled); // WinMod -> pma_unscaled::Multiply
		
		this->getParameterT(31).connectT(0, pma18); // FileInput -> pma18::Add
		
		this->getParameterT(32).connectT(0, pma18); // FileInputMod -> pma18::Multiply
		
		auto& FileUser_p = this->getParameterT(33);
		FileUser_p.connectT(0, branch40); // FileUser -> branch40::Index
		FileUser_p.connectT(1, branch22); // FileUser -> branch22::Index
		FileUser_p.connectT(2, branch42); // FileUser -> branch42::Index
		FileUser_p.connectT(3, branch44); // FileUser -> branch44::Index
		
		this->getParameterT(34).connectT(0, branch58); // FileMidiPitch -> branch58::Index
		
		this->getParameterT(35).connectT(0, branch52); // FileMidipos2 -> branch52::Index
		
		this->getParameterT(36).connectT(0, branch59); // FileWinPk -> branch59::Index
		
		this->getParameterT(37).connectT(0, branch60); // FileMidiwindow -> branch60::Index
		
		this->getParameterT(38).connectT(0, branch54); // FileMidiInput -> branch54::Index
		
		auto& Q_p = this->getParameterT(39);
		Q_p.connectT(0, faust13); // Q -> faust13::Q
		Q_p.connectT(1, faust11); // Q -> faust11::Q
		Q_p.connectT(2, faust15); // Q -> faust15::aN
		Q_p.connectT(3, faust10); // Q -> faust10::Q
		Q_p.connectT(4, faust8);  // Q -> faust8::aN
		Q_p.connectT(5, faust);   // Q -> faust::Q
		Q_p.connectT(6, faust2);  // Q -> faust2::Q
		
		this->getParameterT(40).connectT(0, pma22); // FilterMix -> pma22::Add
		
		this->getParameterT(41).connectT(0, pma22); // FilterMod -> pma22::Multiply
		
		this->getParameterT(42).connectT(0, pma23); // Cut1 -> pma23::Add
		
		this->getParameterT(43).connectT(0, pma23); // Cut1Mod -> pma23::Multiply
		
		this->getParameterT(44).connectT(0, pma24); // Cut2 -> pma24::Add
		
		this->getParameterT(45).connectT(0, pma24); // Cut2Mod -> pma24::Multiply
		
		this->getParameterT(46).connectT(0, branch62); // FilterMidiMix -> branch62::Index
		
		this->getParameterT(47).connectT(0, branch64); // FilterMidiCut1 -> branch64::Index
		
		this->getParameterT(48).connectT(0, branch66); // FilterMidiCut2 -> branch66::Index
		
		this->getParameterT(53).connectT(0, branch); // FilterMode -> branch::Index
		
		auto& q2_p = this->getParameterT(54);
		q2_p.connectT(0, faust16); // q2 -> faust16::aN
		q2_p.connectT(1, faust14); // q2 -> faust14::Q
		q2_p.connectT(2, faust12); // q2 -> faust12::Q
		q2_p.connectT(3, faust9);  // q2 -> faust9::aN
		q2_p.connectT(4, faust7);  // q2 -> faust7::Q
		q2_p.connectT(5, faust6);  // q2 -> faust6::Q
		q2_p.connectT(6, faust1);  // q2 -> faust1::Q
		
		this->getParameterT(55).connectT(0, ahdsr); // a1 -> ahdsr::Attack
		
		this->getParameterT(56).connectT(0, ahdsr); // h1 -> ahdsr::Hold
		
		this->getParameterT(57).connectT(0, ahdsr); // d1 -> ahdsr::Decay
		
		this->getParameterT(58).connectT(0, ahdsr); // s1 -> ahdsr::Sustain
		
		this->getParameterT(59).connectT(0, ahdsr); // r1 -> ahdsr::Release
		
		this->getParameterT(60).connectT(0, ahdsr6); // a2 -> ahdsr6::Attack
		
		this->getParameterT(61).connectT(0, ahdsr6); // h2 -> ahdsr6::Hold
		
		this->getParameterT(62).connectT(0, ahdsr6); // d2 -> ahdsr6::Decay
		
		this->getParameterT(63).connectT(0, ahdsr6); // s2 -> ahdsr6::Sustain
		
		this->getParameterT(64).connectT(0, ahdsr6); // r2 -> ahdsr6::Release
		
		this->getParameterT(65).connectT(0, branch13); // EnvClock1 -> branch13::Index
		
		this->getParameterT(66).connectT(0, branch17); // EnvClock12 -> branch17::Index
		
		auto& EnvTempo1_p = this->getParameterT(67);
		EnvTempo1_p.connectT(0, tempo_sync2); // EnvTempo1 -> tempo_sync2::Tempo
		EnvTempo1_p.connectT(1, clock_ramp);  // EnvTempo1 -> clock_ramp::Tempo
		
		auto& EnvTempo2_p = this->getParameterT(68);
		EnvTempo2_p.connectT(0, tempo_sync5); // EnvTempo2 -> tempo_sync5::Tempo
		EnvTempo2_p.connectT(1, clock_ramp3); // EnvTempo2 -> clock_ramp3::Tempo
		
		auto& EnvDiv_p = this->getParameterT(69);
		EnvDiv_p.connectT(0, tempo_sync2); // EnvDiv -> tempo_sync2::Multiplier
		EnvDiv_p.connectT(1, clock_ramp);  // EnvDiv -> clock_ramp::Multiplier
		
		this->getParameterT(70).connectT(0, input_toggle); // EnvTrigIn1 -> input_toggle::Input
		
		this->getParameterT(71).connectT(0, input_toggle2); // EnvTrigIn2 -> input_toggle2::Input
		
		this->getParameterT(72).connectT(0, branch14); // EnvType1 -> branch14::Index
		
		this->getParameterT(73).connectT(0, branch18); // EnvType2 -> branch18::Index
		
		this->getParameterT(74).connectT(0, branch15); // PitchPkModSrc1 -> branch15::Index
		
		this->getParameterT(75).connectT(0, branch11); // Pitch2Midi -> branch11::Index
		
		this->getParameterT(76).connectT(0, branch16); // Pitch2PkModSrc -> branch16::Index
		
		this->getParameterT(77).connectT(0, branch38); // InSrcOsc1 -> branch38::Index
		
		this->getParameterT(78).connectT(0, branch27); // InSrcOsc2 -> branch27::Index
		
		this->getParameterT(81).connectT(0, gain45); // FilerInOsc1 -> gain45::Gain
		
		this->getParameterT(82).connectT(0, gain47); // FilterInOSc2 -> gain47::Gain
		
		this->getParameterT(83).connectT(0, gain46); // FilterInFile -> gain46::Gain
		
		this->getParameterT(84).connectT(0, branch19); // OscMixPkIn -> branch19::Index
		
		this->getParameterT(85).connectT(0, pma5); // OscInput2 -> pma5::Add
		
		this->getParameterT(86).connectT(0, pma5); // Osc2InMod -> pma5::Multiply
		
		this->getParameterT(87).connectT(0, branch20); // OscInPeak -> branch20::Index
		
		this->getParameterT(88).connectT(0, branch24); // OscInPEak2 -> branch24::Index
		
		this->getParameterT(89).connectT(0, branch25); // Osc2Mid -> branch25::Index
		
		this->getParameterT(90).connectT(0, branch49); // OscWidthPk -> branch49::Index
		
		this->getParameterT(91).connectT(0, branch47); // OscWidthPk2 -> branch47::Index
		
		this->getParameterT(92).connectT(0, branch51); // FileMidPk -> branch51::Index
		
		this->getParameterT(93).connectT(0, branch53); // FileInPk -> branch53::Index
		
		this->getParameterT(94).connectT(0, pma19); // FileXrossFade -> pma19::Add
		
		this->getParameterT(95).connectT(0, pma19); // FileXrossFadeMod -> pma19::Multiply
		
		this->getParameterT(96).connectT(0, branch55); // FileXrossFadePk -> branch55::Index
		
		auto& FileXrossFadeMode_p = this->getParameterT(97);
		FileXrossFadeMode_p.connectT(0, branch45); // FileXrossFadeMode -> branch45::Index
		FileXrossFadeMode_p.connectT(1, branch43); // FileXrossFadeMode -> branch43::Index
		FileXrossFadeMode_p.connectT(2, branch41); // FileXrossFadeMode -> branch41::Index
		FileXrossFadeMode_p.connectT(3, branch26); // FileXrossFadeMode -> branch26::Index
		FileXrossFadeMode_p.connectT(4, branch39); // FileXrossFadeMode -> branch39::Index
		
		this->getParameterT(98).connectT(0, branch56); // FileXrossFadeMidi -> branch56::Index
		
		this->getParameterT(99).connectT(0, branch57); // FilePitchPk -> branch57::Index
		
		this->getParameterT(100).connectT(0, pma25); // Gain -> pma25::Add
		
		this->getParameterT(101).connectT(0, pma25); // GainMod -> pma25::Multiply
		
		this->getParameterT(102).connectT(0, pma26); // PAn -> pma26::Add
		
		this->getParameterT(103).connectT(0, pma26); // PanMod -> pma26::Multiply
		
		this->getParameterT(104).connectT(0, branch63); // CutPK -> branch63::Index
		
		this->getParameterT(105).connectT(0, branch65); // Cut2Pk -> branch65::Index
		
		this->getParameterT(106).connectT(0, branch68); // GainMidi -> branch68::Index
		
		this->getParameterT(107).connectT(0, branch67); // GainPk -> branch67::Index
		
		this->getParameterT(108).connectT(0, branch70); // PanMidi -> branch70::Index
		
		this->getParameterT(109).connectT(0, branch69); // PanPk -> branch69::Index
		
		this->getParameterT(110).connectT(0, branch61); // FilterMixPk -> branch61::Index
		
		auto& feed_p = this->getParameterT(116);
		feed_p.connectT(0, receive2); // feed -> receive2::Feedback
		feed_p.connectT(1, receive3); // feed -> receive3::Feedback
		
		auto& FileIn_p = this->getParameterT(117);
		FileIn_p.connectT(0, receive10); // FileIn -> receive10::Feedback
		FileIn_p.connectT(1, receive11); // FileIn -> receive11::Feedback
		
		auto& OscsOut_p = this->getParameterT(118);
		OscsOut_p.connectT(0, gain3); // OscsOut -> gain3::Gain
		OscsOut_p.connectT(1, gain5); // OscsOut -> gain5::Gain
		
		this->getParameterT(119).connectT(0, pma3); // Pitch2 -> pma3::Add
		
		auto& Pitch2Mod_p = this->getParameterT(120);
		Pitch2Mod_p.connectT(0, pma3);  // Pitch2Mod -> pma3::Multiply
		Pitch2Mod_p.connectT(1, pma14); // Pitch2Mod -> pma14::Multiply
		
		this->getParameterT(121).connectT(0, branch4); // Input1Midi -> branch4::Index
		
		this->getParameterT(122).connectT(0, one_pole); // _1pMod -> one_pole::Mode
		
		auto& EnvDiv2_p = this->getParameterT(123);
		EnvDiv2_p.connectT(0, tempo_sync5); // EnvDiv2 -> tempo_sync5::Multiplier
		EnvDiv2_p.connectT(1, clock_ramp3); // EnvDiv2 -> clock_ramp3::Multiplier
		
		this->getParameterT(124).connectT(0, pma33); // PosAMod -> pma33::Multiply
		
		this->getParameterT(125).connectT(0, pma33); // PosA -> pma33::Add
		
		this->getParameterT(126).connectT(0, pma32); // PosB -> pma32::Add
		
		this->getParameterT(127).connectT(0, pma32); // PosBmod -> pma32::Multiply
		
		this->getParameterT(128).connectT(0, pma31); // PosC -> pma31::Add
		
		this->getParameterT(129).connectT(0, pma31); // PosCMod -> pma31::Multiply
		
		this->getParameterT(130).connectT(0, pma34); // PosD -> pma34::Add
		
		this->getParameterT(131).connectT(0, pma34); // PosDMod -> pma34::Multiply
		
		this->getParameterT(132).connectT(0, ramp); // EnvOS1 -> ramp::LoopStart
		
		this->getParameterT(133).connectT(0, ramp4); // EnvOS2 -> ramp4::LoopStart
		
		this->getParameterT(134).connectT(0, tempo_sync6); // RampTempo1 -> tempo_sync6::Tempo
		
		this->getParameterT(135).connectT(0, tempo_sync9); // RampTempo2 -> tempo_sync9::Tempo
		
		this->getParameterT(136).connectT(0, tempo_sync6); // RampDiv1 -> tempo_sync6::Multiplier
		
		this->getParameterT(137).connectT(0, tempo_sync9); // RampDiv2 -> tempo_sync9::Multiplier
		
		this->getParameterT(138).connectT(0, branch36); // RampInv1 -> branch36::Index
		
		this->getParameterT(139).connectT(0, branch89); // RampInv2 -> branch89::Index
		
		this->getParameterT(140).connectT(0, tempo_sync8); // RampTemo3 -> tempo_sync8::Tempo
		
		this->getParameterT(141).connectT(0, tempo_sync7); // RampTempo4 -> tempo_sync7::Tempo
		
		this->getParameterT(142).connectT(0, tempo_sync8); // RampDiv3 -> tempo_sync8::Multiplier
		
		this->getParameterT(143).connectT(0, tempo_sync7); // RampDiv4 -> tempo_sync7::Multiplier
		
		this->getParameterT(144).connectT(0, branch46); // RampInv3 -> branch46::Index
		
		this->getParameterT(145).connectT(0, branch37); // RampInv4 -> branch37::Index
		
		this->getParameterT(146).connectT(0, ramp5); // RampOS1 -> ramp5::LoopStart
		
		this->getParameterT(147).connectT(0, ramp8); // RampOS2 -> ramp8::LoopStart
		
		this->getParameterT(148).connectT(0, ramp7); // RampOS3 -> ramp7::LoopStart
		
		this->getParameterT(149).connectT(0, ramp6); // RampOS4 -> ramp6::LoopStart
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank3_p = sliderbank3.getWrappedObject().getParameter();
		sliderbank3_p.getParameterT(0).connectT(0, gain13);                   // sliderbank3 -> gain13::Gain
		sliderbank3_p.getParameterT(1).connectT(0, gain15);                   // sliderbank3 -> gain15::Gain
		sliderbank3_p.getParameterT(2).connectT(0, gain14);                   // sliderbank3 -> gain14::Gain
		sliderbank3_p.getParameterT(3).connectT(0, gain16);                   // sliderbank3 -> gain16::Gain
		sliderbank3_p.getParameterT(4).connectT(0, gain32);                   // sliderbank3 -> gain32::Gain
		sliderbank3_p.getParameterT(5).connectT(0, gain26);                   // sliderbank3 -> gain26::Gain
		sliderbank3_p.getParameterT(6).connectT(0, gain33);                   // sliderbank3 -> gain33::Gain
		sliderbank3_p.getParameterT(7).connectT(0, gain34);                   // sliderbank3 -> gain34::Gain
		global_cable3.getWrappedObject().getParameter().connectT(0, add4);    // global_cable3 -> add4::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add26);  // global_cable11 -> add26::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add5);   // global_cable10 -> add5::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add27);  // global_cable14 -> add27::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, add50);       // midi_cc10 -> add50::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, add51);       // midi_cc11 -> add51::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, add52);       // midi_cc12 -> add52::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, add53);       // midi_cc13 -> add53::Value
		midi6.getParameter().connectT(0, add54);                              // midi6 -> add54::Value
		midi7.getParameter().connectT(0, add55);                              // midi7 -> add55::Value
		midi8.getParameter().connectT(0, add56);                              // midi8 -> add56::Value
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
		auto& sliderbank5_p = sliderbank5.getWrappedObject().getParameter();
		sliderbank5_p.getParameterT(0).connectT(0, gain21);                   // sliderbank5 -> gain21::Gain
		sliderbank5_p.getParameterT(1).connectT(0, gain22);                   // sliderbank5 -> gain22::Gain
		sliderbank5_p.getParameterT(2).connectT(0, gain23);                   // sliderbank5 -> gain23::Gain
		sliderbank5_p.getParameterT(3).connectT(0, gain24);                   // sliderbank5 -> gain24::Gain
		sliderbank5_p.getParameterT(4).connectT(0, gain38);                   // sliderbank5 -> gain38::Gain
		sliderbank5_p.getParameterT(5).connectT(0, gain28);                   // sliderbank5 -> gain28::Gain
		sliderbank5_p.getParameterT(6).connectT(0, gain39);                   // sliderbank5 -> gain39::Gain
		sliderbank5_p.getParameterT(7).connectT(0, gain40);                   // sliderbank5 -> gain40::Gain
		global_cable5.getWrappedObject().getParameter().connectT(0, add8);    // global_cable5 -> add8::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add37);  // global_cable15 -> add37::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add12);  // global_cable18 -> add12::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add49);  // global_cable19 -> add49::Value
		midi_cc18.getWrappedObject().getParameter().connectT(0, add67);       // midi_cc18 -> add67::Value
		midi_cc19.getWrappedObject().getParameter().connectT(0, add68);       // midi_cc19 -> add68::Value
		midi_cc20.getWrappedObject().getParameter().connectT(0, add69);       // midi_cc20 -> add69::Value
		midi_cc21.getWrappedObject().getParameter().connectT(0, add70);       // midi_cc21 -> add70::Value
		midi12.getParameter().connectT(0, add71);                             // midi12 -> add71::Value
		midi13.getParameter().connectT(0, add72);                             // midi13 -> add72::Value
		midi14.getParameter().connectT(0, add73);                             // midi14 -> add73::Value
		pma3.getWrappedObject().getParameter().connectT(0, add1);             // pma3 -> add1::Value
		pma14.getWrappedObject().getParameter().connectT(0, add18);           // pma14 -> add18::Value
		pma15.getWrappedObject().getParameter().connectT(0, add13);           // pma15 -> add13::Value
		peak5.getParameter().connectT(0, pma3);                               // peak5 -> pma3::Value
		peak5.getParameter().connectT(1, pma14);                              // peak5 -> pma14::Value
		peak5.getParameter().connectT(2, pma15);                              // peak5 -> pma15::Value
		converter6.getWrappedObject().getParameter().connectT(0, phasor_fm4); // converter6 -> phasor_fm4::FreqRatio
		converter6.getWrappedObject().getParameter().connectT(1, phasor_fm7); // converter6 -> phasor_fm7::Frequency
		tempo_sync1.getParameter().connectT(0, converter6);                   // tempo_sync1 -> converter6::Value
		converter1.getWrappedObject().getParameter().connectT(0, phasor_fm2); // converter1 -> phasor_fm2::FreqRatio
		minmax3.getWrappedObject().getParameter().connectT(0, converter1);    // minmax3 -> converter1::Value
		peak1.getParameter().connectT(0, tempo_sync1);                        // peak1 -> tempo_sync1::Tempo
		peak1.getParameter().connectT(1, minmax3);                            // peak1 -> minmax3::Value
		auto& sliderbank4_p = sliderbank4.getWrappedObject().getParameter();
		sliderbank4_p.getParameterT(0).connectT(0, gain17);                  // sliderbank4 -> gain17::Gain
		sliderbank4_p.getParameterT(1).connectT(0, gain18);                  // sliderbank4 -> gain18::Gain
		sliderbank4_p.getParameterT(2).connectT(0, gain19);                  // sliderbank4 -> gain19::Gain
		sliderbank4_p.getParameterT(3).connectT(0, gain20);                  // sliderbank4 -> gain20::Gain
		sliderbank4_p.getParameterT(4).connectT(0, gain35);                  // sliderbank4 -> gain35::Gain
		sliderbank4_p.getParameterT(5).connectT(0, gain27);                  // sliderbank4 -> gain27::Gain
		sliderbank4_p.getParameterT(6).connectT(0, gain36);                  // sliderbank4 -> gain36::Gain
		sliderbank4_p.getParameterT(7).connectT(0, gain37);                  // sliderbank4 -> gain37::Gain
		global_cable4.getWrappedObject().getParameter().connectT(0, add6);   // global_cable4 -> add6::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add32); // global_cable12 -> add32::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add7);  // global_cable13 -> add7::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add33); // global_cable25 -> add33::Value
		midi_cc3.getWrappedObject().getParameter().connectT(0, add31);       // midi_cc3 -> add31::Value
		midi_cc5.getWrappedObject().getParameter().connectT(0, add38);       // midi_cc5 -> add38::Value
		midi_cc7.getWrappedObject().getParameter().connectT(0, add39);       // midi_cc7 -> add39::Value
		midi_cc8.getWrappedObject().getParameter().connectT(0, add40);       // midi_cc8 -> add40::Value
		midi1.getParameter().connectT(0, add41);                             // midi1 -> add41::Value
		midi3.getParameter().connectT(0, add42);                             // midi3 -> add42::Value
		midi5.getParameter().connectT(0, add43);                             // midi5 -> add43::Value
		pma2.getWrappedObject().getParameter().connectT(0, gain8);           // pma2 -> gain8::Gain
		peak4.getParameter().connectT(0, pma2);                              // peak4 -> pma2::Value
		auto& sliderbank6_p = sliderbank6.getWrappedObject().getParameter();
		sliderbank6_p.getParameterT(0).connectT(0, gain25);                  // sliderbank6 -> gain25::Gain
		sliderbank6_p.getParameterT(1).connectT(0, gain29);                  // sliderbank6 -> gain29::Gain
		sliderbank6_p.getParameterT(2).connectT(0, gain30);                  // sliderbank6 -> gain30::Gain
		sliderbank6_p.getParameterT(3).connectT(0, gain31);                  // sliderbank6 -> gain31::Gain
		sliderbank6_p.getParameterT(4).connectT(0, gain41);                  // sliderbank6 -> gain41::Gain
		sliderbank6_p.getParameterT(5).connectT(0, gain42);                  // sliderbank6 -> gain42::Gain
		sliderbank6_p.getParameterT(6).connectT(0, gain43);                  // sliderbank6 -> gain43::Gain
		sliderbank6_p.getParameterT(7).connectT(0, gain44);                  // sliderbank6 -> gain44::Gain
		global_cable6.getWrappedObject().getParameter().connectT(0, add10);  // global_cable6 -> add10::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add44); // global_cable16 -> add44::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add11); // global_cable17 -> add11::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add45); // global_cable26 -> add45::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, add57);      // midi_cc14 -> add57::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, add58);      // midi_cc15 -> add58::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, add59);      // midi_cc16 -> add59::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, add60);      // midi_cc17 -> add60::Value
		midi9.getParameter().connectT(0, add61);                             // midi9 -> add61::Value
		midi10.getParameter().connectT(0, add62);                            // midi10 -> add62::Value
		midi11.getParameter().connectT(0, add63);                            // midi11 -> add63::Value
		pma4.getWrappedObject().getParameter().connectT(0, gain);            // pma4 -> gain::Gain
		peak6.getParameter().connectT(0, pma4);                              // peak6 -> pma4::Value
		auto& sliderbank7_p = sliderbank7.getWrappedObject().getParameter();
		sliderbank7_p.getParameterT(0).connectT(0, gain48);                   // sliderbank7 -> gain48::Gain
		sliderbank7_p.getParameterT(1).connectT(0, gain61);                   // sliderbank7 -> gain61::Gain
		sliderbank7_p.getParameterT(2).connectT(0, gain66);                   // sliderbank7 -> gain66::Gain
		sliderbank7_p.getParameterT(3).connectT(0, gain67);                   // sliderbank7 -> gain67::Gain
		sliderbank7_p.getParameterT(4).connectT(0, gain68);                   // sliderbank7 -> gain68::Gain
		sliderbank7_p.getParameterT(5).connectT(0, gain69);                   // sliderbank7 -> gain69::Gain
		sliderbank7_p.getParameterT(6).connectT(0, gain70);                   // sliderbank7 -> gain70::Gain
		sliderbank7_p.getParameterT(7).connectT(0, gain71);                   // sliderbank7 -> gain71::Gain
		global_cable7.getWrappedObject().getParameter().connectT(0, add111);  // global_cable7 -> add111::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add112); // global_cable24 -> add112::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add113); // global_cable27 -> add113::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add114); // global_cable30 -> add114::Value
		midi_cc4.getWrappedObject().getParameter().connectT(0, add122);       // midi_cc4 -> add122::Value
		midi_cc6.getWrappedObject().getParameter().connectT(0, add123);       // midi_cc6 -> add123::Value
		midi_cc9.getWrappedObject().getParameter().connectT(0, add124);       // midi_cc9 -> add124::Value
		midi_cc30.getWrappedObject().getParameter().connectT(0, add125);      // midi_cc30 -> add125::Value
		midi2.getParameter().connectT(0, add126);                             // midi2 -> add126::Value
		midi21.getParameter().connectT(0, add127);                            // midi21 -> add127::Value
		midi22.getParameter().connectT(0, add128);                            // midi22 -> add128::Value
		pma5.getWrappedObject().getParameter().connectT(0, gain11);           // pma5 -> gain11::Gain
		peak11.getParameter().connectT(0, pma5);                              // peak11 -> pma5::Value
		auto& sliderbank12_p = sliderbank12.getWrappedObject().getParameter();
		sliderbank12_p.getParameterT(0).connectT(0, gain116);                 // sliderbank12 -> gain116::Gain
		sliderbank12_p.getParameterT(1).connectT(0, gain117);                 // sliderbank12 -> gain117::Gain
		sliderbank12_p.getParameterT(2).connectT(0, gain118);                 // sliderbank12 -> gain118::Gain
		sliderbank12_p.getParameterT(3).connectT(0, gain119);                 // sliderbank12 -> gain119::Gain
		sliderbank12_p.getParameterT(4).connectT(0, gain120);                 // sliderbank12 -> gain120::Gain
		sliderbank12_p.getParameterT(5).connectT(0, gain121);                 // sliderbank12 -> gain121::Gain
		sliderbank12_p.getParameterT(6).connectT(0, gain122);                 // sliderbank12 -> gain122::Gain
		sliderbank12_p.getParameterT(7).connectT(0, gain123);                 // sliderbank12 -> gain123::Gain
		global_cable39.getWrappedObject().getParameter().connectT(0, add161); // global_cable39 -> add161::Value
		global_cable40.getWrappedObject().getParameter().connectT(0, add162); // global_cable40 -> add162::Value
		global_cable41.getWrappedObject().getParameter().connectT(0, add163); // global_cable41 -> add163::Value
		global_cable42.getWrappedObject().getParameter().connectT(0, add164); // global_cable42 -> add164::Value
		midi_cc39.getWrappedObject().getParameter().connectT(0, add172);      // midi_cc39 -> add172::Value
		midi_cc40.getWrappedObject().getParameter().connectT(0, add173);      // midi_cc40 -> add173::Value
		midi_cc41.getWrappedObject().getParameter().connectT(0, add174);      // midi_cc41 -> add174::Value
		midi_cc42.getWrappedObject().getParameter().connectT(0, add175);      // midi_cc42 -> add175::Value
		midi29.getParameter().connectT(0, add176);                            // midi29 -> add176::Value
		midi30.getParameter().connectT(0, add177);                            // midi30 -> add177::Value
		midi31.getParameter().connectT(0, add178);                            // midi31 -> add178::Value
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
		auto& sliderbank11_p = sliderbank11.getWrappedObject().getParameter();
		sliderbank11_p.getParameterT(0).connectT(0, gain108);                 // sliderbank11 -> gain108::Gain
		sliderbank11_p.getParameterT(1).connectT(0, gain109);                 // sliderbank11 -> gain109::Gain
		sliderbank11_p.getParameterT(2).connectT(0, gain110);                 // sliderbank11 -> gain110::Gain
		sliderbank11_p.getParameterT(3).connectT(0, gain111);                 // sliderbank11 -> gain111::Gain
		sliderbank11_p.getParameterT(4).connectT(0, gain112);                 // sliderbank11 -> gain112::Gain
		sliderbank11_p.getParameterT(5).connectT(0, gain113);                 // sliderbank11 -> gain113::Gain
		sliderbank11_p.getParameterT(6).connectT(0, gain114);                 // sliderbank11 -> gain114::Gain
		sliderbank11_p.getParameterT(7).connectT(0, gain115);                 // sliderbank11 -> gain115::Gain
		global_cable35.getWrappedObject().getParameter().connectT(0, add143); // global_cable35 -> add143::Value
		global_cable36.getWrappedObject().getParameter().connectT(0, add144); // global_cable36 -> add144::Value
		global_cable37.getWrappedObject().getParameter().connectT(0, add145); // global_cable37 -> add145::Value
		global_cable38.getWrappedObject().getParameter().connectT(0, add146); // global_cable38 -> add146::Value
		midi_cc35.getWrappedObject().getParameter().connectT(0, add154);      // midi_cc35 -> add154::Value
		midi_cc36.getWrappedObject().getParameter().connectT(0, add155);      // midi_cc36 -> add155::Value
		midi_cc37.getWrappedObject().getParameter().connectT(0, add156);      // midi_cc37 -> add156::Value
		midi_cc38.getWrappedObject().getParameter().connectT(0, add157);      // midi_cc38 -> add157::Value
		midi26.getParameter().connectT(0, add158);                            // midi26 -> add158::Value
		midi27.getParameter().connectT(0, add159);                            // midi27 -> add159::Value
		midi28.getParameter().connectT(0, add160);                            // midi28 -> add160::Value
		auto& xfader4_p = xfader4.getWrappedObject().getParameter();
		xfader4_p.getParameterT(0).connectT(0, gain52);                   // xfader4 -> gain52::Gain
		xfader4_p.getParameterT(1).connectT(0, gain54);                   // xfader4 -> gain54::Gain
		pma7.getWrappedObject().getParameter().connectT(0, gain65);       // pma7 -> gain65::Gain
		pma7.getWrappedObject().getParameter().connectT(1, gain64);       // pma7 -> gain64::Gain
		pma7.getWrappedObject().getParameter().connectT(2, gain57);       // pma7 -> gain57::Gain
		pma7.getWrappedObject().getParameter().connectT(3, gain60);       // pma7 -> gain60::Gain
		pma7.getWrappedObject().getParameter().connectT(4, expr11);       // pma7 -> expr11::Value
		pma7.getWrappedObject().getParameter().connectT(5, phase_delay2); // pma7 -> phase_delay2::Frequency
		pma7.getWrappedObject().getParameter().connectT(6, xfader4);      // pma7 -> xfader4::Value
		pma7.getWrappedObject().getParameter().connectT(7, gain62);       // pma7 -> gain62::Gain
		pma7.getWrappedObject().getParameter().connectT(8, gain55);       // pma7 -> gain55::Gain
		pma9.getWrappedObject().getParameter().connectT(0, pma7);         // pma9 -> pma7::Add
		peak13.getParameter().connectT(0, pma9);                          // peak13 -> pma9::Value
		auto& sliderbank14_p = sliderbank14.getWrappedObject().getParameter();
		sliderbank14_p.getParameterT(0).connectT(0, gain132);                 // sliderbank14 -> gain132::Gain
		sliderbank14_p.getParameterT(1).connectT(0, gain133);                 // sliderbank14 -> gain133::Gain
		sliderbank14_p.getParameterT(2).connectT(0, gain134);                 // sliderbank14 -> gain134::Gain
		sliderbank14_p.getParameterT(3).connectT(0, gain135);                 // sliderbank14 -> gain135::Gain
		sliderbank14_p.getParameterT(4).connectT(0, gain136);                 // sliderbank14 -> gain136::Gain
		sliderbank14_p.getParameterT(5).connectT(0, gain137);                 // sliderbank14 -> gain137::Gain
		sliderbank14_p.getParameterT(6).connectT(0, gain138);                 // sliderbank14 -> gain138::Gain
		sliderbank14_p.getParameterT(7).connectT(0, gain139);                 // sliderbank14 -> gain139::Gain
		global_cable47.getWrappedObject().getParameter().connectT(0, add197); // global_cable47 -> add197::Value
		global_cable48.getWrappedObject().getParameter().connectT(0, add198); // global_cable48 -> add198::Value
		global_cable49.getWrappedObject().getParameter().connectT(0, add199); // global_cable49 -> add199::Value
		global_cable50.getWrappedObject().getParameter().connectT(0, add200); // global_cable50 -> add200::Value
		midi_cc47.getWrappedObject().getParameter().connectT(0, add208);      // midi_cc47 -> add208::Value
		midi_cc48.getWrappedObject().getParameter().connectT(0, add209);      // midi_cc48 -> add209::Value
		midi_cc49.getWrappedObject().getParameter().connectT(0, add210);      // midi_cc49 -> add210::Value
		midi_cc50.getWrappedObject().getParameter().connectT(0, add211);      // midi_cc50 -> add211::Value
		midi35.getParameter().connectT(0, add212);                            // midi35 -> add212::Value
		midi36.getParameter().connectT(0, add223);                            // midi36 -> add223::Value
		midi37.getParameter().connectT(0, add224);                            // midi37 -> add224::Value
		pma18.getWrappedObject().getParameter().connectT(0, gain6);           // pma18 -> gain6::Gain
		peak34.getParameter().connectT(0, pma18);                             // peak34 -> pma18::Value
		auto& sliderbank15_p = sliderbank15.getWrappedObject().getParameter();
		sliderbank15_p.getParameterT(0).connectT(0, gain140);                 // sliderbank15 -> gain140::Gain
		sliderbank15_p.getParameterT(1).connectT(0, gain141);                 // sliderbank15 -> gain141::Gain
		sliderbank15_p.getParameterT(2).connectT(0, gain142);                 // sliderbank15 -> gain142::Gain
		sliderbank15_p.getParameterT(3).connectT(0, gain143);                 // sliderbank15 -> gain143::Gain
		sliderbank15_p.getParameterT(4).connectT(0, gain144);                 // sliderbank15 -> gain144::Gain
		sliderbank15_p.getParameterT(5).connectT(0, gain145);                 // sliderbank15 -> gain145::Gain
		sliderbank15_p.getParameterT(6).connectT(0, gain146);                 // sliderbank15 -> gain146::Gain
		sliderbank15_p.getParameterT(7).connectT(0, gain147);                 // sliderbank15 -> gain147::Gain
		global_cable51.getWrappedObject().getParameter().connectT(0, add225); // global_cable51 -> add225::Value
		global_cable52.getWrappedObject().getParameter().connectT(0, add226); // global_cable52 -> add226::Value
		global_cable53.getWrappedObject().getParameter().connectT(0, add227); // global_cable53 -> add227::Value
		global_cable54.getWrappedObject().getParameter().connectT(0, add228); // global_cable54 -> add228::Value
		midi_cc51.getWrappedObject().getParameter().connectT(0, add236);      // midi_cc51 -> add236::Value
		midi_cc52.getWrappedObject().getParameter().connectT(0, add237);      // midi_cc52 -> add237::Value
		midi_cc53.getWrappedObject().getParameter().connectT(0, add238);      // midi_cc53 -> add238::Value
		midi_cc54.getWrappedObject().getParameter().connectT(0, add239);      // midi_cc54 -> add239::Value
		midi38.getParameter().connectT(0, add240);                            // midi38 -> add240::Value
		midi39.getParameter().connectT(0, add241);                            // midi39 -> add241::Value
		midi40.getParameter().connectT(0, add242);                            // midi40 -> add242::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain4);  // xfader1 -> gain4::Gain
		xfader1_p.getParameterT(1).connectT(0, gain72); // xfader1 -> gain72::Gain
		xfader1_p.getParameterT(2).connectT(0, gain92); // xfader1 -> gain92::Gain
		xfader1_p.getParameterT(3).connectT(0, gain96); // xfader1 -> gain96::Gain
		auto& xfader5_p = xfader5.getWrappedObject().getParameter();
		xfader5_p.getParameterT(0).connectT(0, gain10); // xfader5 -> gain10::Gain
		xfader5_p.getParameterT(1).connectT(0, gain89); // xfader5 -> gain89::Gain
		xfader5_p.getParameterT(2).connectT(0, gain93); // xfader5 -> gain93::Gain
		xfader5_p.getParameterT(3).connectT(0, gain97); // xfader5 -> gain97::Gain
		auto& xfader6_p = xfader6.getWrappedObject().getParameter();
		xfader6_p.getParameterT(0).connectT(0, gain9);                // xfader6 -> gain9::Gain
		xfader6_p.getParameterT(1).connectT(0, gain90);               // xfader6 -> gain90::Gain
		xfader6_p.getParameterT(2).connectT(0, gain94);               // xfader6 -> gain94::Gain
		xfader6_p.getParameterT(3).connectT(0, gain98);               // xfader6 -> gain98::Gain
		pma19.getWrappedObject().getParameter().connectT(0, xfader1); // pma19 -> xfader1::Value
		pma19.getWrappedObject().getParameter().connectT(1, xfader5); // pma19 -> xfader5::Value
		pma19.getWrappedObject().getParameter().connectT(2, xfader6); // pma19 -> xfader6::Value
		peak35.getParameter().connectT(0, pma19);                     // peak35 -> pma19::Value
		auto& sliderbank16_p = sliderbank16.getWrappedObject().getParameter();
		sliderbank16_p.getParameterT(0).connectT(0, gain228);                 // sliderbank16 -> gain228::Gain
		sliderbank16_p.getParameterT(1).connectT(0, gain229);                 // sliderbank16 -> gain229::Gain
		sliderbank16_p.getParameterT(2).connectT(0, gain230);                 // sliderbank16 -> gain230::Gain
		sliderbank16_p.getParameterT(3).connectT(0, gain231);                 // sliderbank16 -> gain231::Gain
		sliderbank16_p.getParameterT(4).connectT(0, gain232);                 // sliderbank16 -> gain232::Gain
		sliderbank16_p.getParameterT(5).connectT(0, gain233);                 // sliderbank16 -> gain233::Gain
		sliderbank16_p.getParameterT(6).connectT(0, gain234);                 // sliderbank16 -> gain234::Gain
		sliderbank16_p.getParameterT(7).connectT(0, gain235);                 // sliderbank16 -> gain235::Gain
		global_cable55.getWrappedObject().getParameter().connectT(0, add243); // global_cable55 -> add243::Value
		global_cable56.getWrappedObject().getParameter().connectT(0, add244); // global_cable56 -> add244::Value
		global_cable57.getWrappedObject().getParameter().connectT(0, add245); // global_cable57 -> add245::Value
		global_cable58.getWrappedObject().getParameter().connectT(0, add246); // global_cable58 -> add246::Value
		midi_cc55.getWrappedObject().getParameter().connectT(0, add394);      // midi_cc55 -> add394::Value
		midi_cc56.getWrappedObject().getParameter().connectT(0, add395);      // midi_cc56 -> add395::Value
		midi_cc57.getWrappedObject().getParameter().connectT(0, add396);      // midi_cc57 -> add396::Value
		midi_cc58.getWrappedObject().getParameter().connectT(0, add397);      // midi_cc58 -> add397::Value
		midi41.getParameter().connectT(0, add398);                            // midi41 -> add398::Value
		midi43.getParameter().connectT(0, add399);                            // midi43 -> add399::Value
		midi44.getParameter().connectT(0, add400);                            // midi44 -> add400::Value
		pma20.getWrappedObject().getParameter().connectT(0, faust3);          // pma20 -> faust3::shiftnote
		pma20.getWrappedObject().getParameter().connectT(1, faust5);          // pma20 -> faust5::shiftnote
		peak36.getParameter().connectT(0, pma20);                             // peak36 -> pma20::Value
		auto& sliderbank17_p = sliderbank17.getWrappedObject().getParameter();
		sliderbank17_p.getParameterT(0).connectT(0, gain236);                 // sliderbank17 -> gain236::Gain
		sliderbank17_p.getParameterT(1).connectT(0, gain237);                 // sliderbank17 -> gain237::Gain
		sliderbank17_p.getParameterT(2).connectT(0, gain238);                 // sliderbank17 -> gain238::Gain
		sliderbank17_p.getParameterT(3).connectT(0, gain239);                 // sliderbank17 -> gain239::Gain
		sliderbank17_p.getParameterT(4).connectT(0, gain240);                 // sliderbank17 -> gain240::Gain
		sliderbank17_p.getParameterT(5).connectT(0, gain241);                 // sliderbank17 -> gain241::Gain
		sliderbank17_p.getParameterT(6).connectT(0, gain242);                 // sliderbank17 -> gain242::Gain
		sliderbank17_p.getParameterT(7).connectT(0, gain243);                 // sliderbank17 -> gain243::Gain
		global_cable59.getWrappedObject().getParameter().connectT(0, add254); // global_cable59 -> add254::Value
		global_cable60.getWrappedObject().getParameter().connectT(0, add255); // global_cable60 -> add255::Value
		global_cable61.getWrappedObject().getParameter().connectT(0, add256); // global_cable61 -> add256::Value
		global_cable62.getWrappedObject().getParameter().connectT(0, add257); // global_cable62 -> add257::Value
		midi_cc59.getWrappedObject().getParameter().connectT(0, add401);      // midi_cc59 -> add401::Value
		midi_cc60.getWrappedObject().getParameter().connectT(0, add402);      // midi_cc60 -> add402::Value
		midi_cc61.getWrappedObject().getParameter().connectT(0, add403);      // midi_cc61 -> add403::Value
		midi_cc62.getWrappedObject().getParameter().connectT(0, add404);      // midi_cc62 -> add404::Value
		midi45.getParameter().connectT(0, add405);                            // midi45 -> add405::Value
		midi46.getParameter().connectT(0, add406);                            // midi46 -> add406::Value
		midi47.getParameter().connectT(0, add407);                            // midi47 -> add407::Value
		pma_unscaled.getWrappedObject().getParameter().connectT(0, faust4);   // pma_unscaled -> faust4::xfadesamples
		pma_unscaled.getWrappedObject().getParameter().connectT(1, faust4);   // pma_unscaled -> faust4::windowsamples
		pma_unscaled.getWrappedObject().getParameter().connectT(2, faust3);   // pma_unscaled -> faust3::windowsamples
		pma_unscaled.getWrappedObject().getParameter().connectT(3, faust3);   // pma_unscaled -> faust3::xfadesamples
		pma_unscaled.getWrappedObject().getParameter().connectT(4, faust5);   // pma_unscaled -> faust5::windowsamples
		pma_unscaled.getWrappedObject().getParameter().connectT(5, faust5);   // pma_unscaled -> faust5::xfadesamples
		peak_unscaled.getParameter().connectT(0, pma_unscaled);               // peak_unscaled -> pma_unscaled::Value
		auto& sliderbank18_p = sliderbank18.getWrappedObject().getParameter();
		sliderbank18_p.getParameterT(0).connectT(0, gain244);                 // sliderbank18 -> gain244::Gain
		sliderbank18_p.getParameterT(1).connectT(0, gain245);                 // sliderbank18 -> gain245::Gain
		sliderbank18_p.getParameterT(2).connectT(0, gain246);                 // sliderbank18 -> gain246::Gain
		sliderbank18_p.getParameterT(3).connectT(0, gain247);                 // sliderbank18 -> gain247::Gain
		sliderbank18_p.getParameterT(4).connectT(0, gain248);                 // sliderbank18 -> gain248::Gain
		sliderbank18_p.getParameterT(5).connectT(0, gain249);                 // sliderbank18 -> gain249::Gain
		sliderbank18_p.getParameterT(6).connectT(0, gain250);                 // sliderbank18 -> gain250::Gain
		sliderbank18_p.getParameterT(7).connectT(0, gain251);                 // sliderbank18 -> gain251::Gain
		global_cable63.getWrappedObject().getParameter().connectT(0, add265); // global_cable63 -> add265::Value
		global_cable64.getWrappedObject().getParameter().connectT(0, add266); // global_cable64 -> add266::Value
		global_cable65.getWrappedObject().getParameter().connectT(0, add267); // global_cable65 -> add267::Value
		global_cable66.getWrappedObject().getParameter().connectT(0, add268); // global_cable66 -> add268::Value
		midi_cc63.getWrappedObject().getParameter().connectT(0, add408);      // midi_cc63 -> add408::Value
		midi_cc64.getWrappedObject().getParameter().connectT(0, add409);      // midi_cc64 -> add409::Value
		midi_cc65.getWrappedObject().getParameter().connectT(0, add410);      // midi_cc65 -> add410::Value
		midi_cc66.getWrappedObject().getParameter().connectT(0, add411);      // midi_cc66 -> add411::Value
		midi48.getParameter().connectT(0, add412);                            // midi48 -> add412::Value
		midi49.getParameter().connectT(0, add413);                            // midi49 -> add413::Value
		midi50.getParameter().connectT(0, add414);                            // midi50 -> add414::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                // xfader -> gain2::Gain
		pma22.getWrappedObject().getParameter().connectT(0, xfader); // pma22 -> xfader::Value
		peak38.getParameter().connectT(0, pma22);                    // peak38 -> pma22::Value
		auto& sliderbank19_p = sliderbank19.getWrappedObject().getParameter();
		sliderbank19_p.getParameterT(0).connectT(0, gain252);                 // sliderbank19 -> gain252::Gain
		sliderbank19_p.getParameterT(1).connectT(0, gain253);                 // sliderbank19 -> gain253::Gain
		sliderbank19_p.getParameterT(2).connectT(0, gain254);                 // sliderbank19 -> gain254::Gain
		sliderbank19_p.getParameterT(3).connectT(0, gain255);                 // sliderbank19 -> gain255::Gain
		sliderbank19_p.getParameterT(4).connectT(0, gain256);                 // sliderbank19 -> gain256::Gain
		sliderbank19_p.getParameterT(5).connectT(0, gain257);                 // sliderbank19 -> gain257::Gain
		sliderbank19_p.getParameterT(6).connectT(0, gain258);                 // sliderbank19 -> gain258::Gain
		sliderbank19_p.getParameterT(7).connectT(0, gain259);                 // sliderbank19 -> gain259::Gain
		global_cable67.getWrappedObject().getParameter().connectT(0, add276); // global_cable67 -> add276::Value
		global_cable68.getWrappedObject().getParameter().connectT(0, add277); // global_cable68 -> add277::Value
		global_cable69.getWrappedObject().getParameter().connectT(0, add278); // global_cable69 -> add278::Value
		global_cable70.getWrappedObject().getParameter().connectT(0, add279); // global_cable70 -> add279::Value
		midi_cc67.getWrappedObject().getParameter().connectT(0, add415);      // midi_cc67 -> add415::Value
		midi_cc68.getWrappedObject().getParameter().connectT(0, add416);      // midi_cc68 -> add416::Value
		midi_cc69.getWrappedObject().getParameter().connectT(0, add417);      // midi_cc69 -> add417::Value
		midi_cc70.getWrappedObject().getParameter().connectT(0, add418);      // midi_cc70 -> add418::Value
		midi51.getParameter().connectT(0, add419);                            // midi51 -> add419::Value
		midi52.getParameter().connectT(0, add420);                            // midi52 -> add420::Value
		midi53.getParameter().connectT(0, add421);                            // midi53 -> add421::Value
		cable_table3.getWrappedObject().getParameter().connectT(0, faust15);  // cable_table3 -> faust15::del
		cable_table.getWrappedObject().getParameter().connectT(0, faust8);    // cable_table -> faust8::del
		pma23.getWrappedObject().getParameter().connectT(0, faust);           // pma23 -> faust::freq
		pma23.getWrappedObject().getParameter().connectT(1, cable_table3);    // pma23 -> cable_table3::Value
		pma23.getWrappedObject().getParameter().connectT(2, faust11);         // pma23 -> faust11::freq
		pma23.getWrappedObject().getParameter().connectT(3, faust10);         // pma23 -> faust10::freq
		pma23.getWrappedObject().getParameter().connectT(4, cable_table);     // pma23 -> cable_table::Value
		pma23.getWrappedObject().getParameter().connectT(5, faust2);          // pma23 -> faust2::freq
		pma23.getWrappedObject().getParameter().connectT(6, faust13);         // pma23 -> faust13::freq
		peak39.getParameter().connectT(0, pma23);                             // peak39 -> pma23::Value
		auto& sliderbank20_p = sliderbank20.getWrappedObject().getParameter();
		sliderbank20_p.getParameterT(0).connectT(0, gain260);                 // sliderbank20 -> gain260::Gain
		sliderbank20_p.getParameterT(1).connectT(0, gain261);                 // sliderbank20 -> gain261::Gain
		sliderbank20_p.getParameterT(2).connectT(0, gain262);                 // sliderbank20 -> gain262::Gain
		sliderbank20_p.getParameterT(3).connectT(0, gain263);                 // sliderbank20 -> gain263::Gain
		sliderbank20_p.getParameterT(4).connectT(0, gain264);                 // sliderbank20 -> gain264::Gain
		sliderbank20_p.getParameterT(5).connectT(0, gain265);                 // sliderbank20 -> gain265::Gain
		sliderbank20_p.getParameterT(6).connectT(0, gain266);                 // sliderbank20 -> gain266::Gain
		sliderbank20_p.getParameterT(7).connectT(0, gain267);                 // sliderbank20 -> gain267::Gain
		global_cable71.getWrappedObject().getParameter().connectT(0, add287); // global_cable71 -> add287::Value
		global_cable72.getWrappedObject().getParameter().connectT(0, add288); // global_cable72 -> add288::Value
		global_cable73.getWrappedObject().getParameter().connectT(0, add289); // global_cable73 -> add289::Value
		global_cable74.getWrappedObject().getParameter().connectT(0, add290); // global_cable74 -> add290::Value
		midi_cc71.getWrappedObject().getParameter().connectT(0, add422);      // midi_cc71 -> add422::Value
		midi_cc72.getWrappedObject().getParameter().connectT(0, add423);      // midi_cc72 -> add423::Value
		midi_cc73.getWrappedObject().getParameter().connectT(0, add424);      // midi_cc73 -> add424::Value
		midi_cc74.getWrappedObject().getParameter().connectT(0, add425);      // midi_cc74 -> add425::Value
		midi54.getParameter().connectT(0, add426);                            // midi54 -> add426::Value
		midi55.getParameter().connectT(0, add427);                            // midi55 -> add427::Value
		midi56.getParameter().connectT(0, add428);                            // midi56 -> add428::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, faust16);  // cable_table4 -> faust16::del
		cable_table2.getWrappedObject().getParameter().connectT(0, faust9);   // cable_table2 -> faust9::del
		pma24.getWrappedObject().getParameter().connectT(0, cable_table4);    // pma24 -> cable_table4::Value
		pma24.getWrappedObject().getParameter().connectT(1, faust14);         // pma24 -> faust14::freq
		pma24.getWrappedObject().getParameter().connectT(2, faust12);         // pma24 -> faust12::freq
		pma24.getWrappedObject().getParameter().connectT(3, cable_table2);    // pma24 -> cable_table2::Value
		pma24.getWrappedObject().getParameter().connectT(4, faust7);          // pma24 -> faust7::freq
		pma24.getWrappedObject().getParameter().connectT(5, faust6);          // pma24 -> faust6::freq
		pma24.getWrappedObject().getParameter().connectT(6, faust1);          // pma24 -> faust1::freq
		peak40.getParameter().connectT(0, pma24);                             // peak40 -> pma24::Value
		auto& sliderbank21_p = sliderbank21.getWrappedObject().getParameter();
		sliderbank21_p.getParameterT(0).connectT(0, gain268);                 // sliderbank21 -> gain268::Gain
		sliderbank21_p.getParameterT(1).connectT(0, gain269);                 // sliderbank21 -> gain269::Gain
		sliderbank21_p.getParameterT(2).connectT(0, gain270);                 // sliderbank21 -> gain270::Gain
		sliderbank21_p.getParameterT(3).connectT(0, gain271);                 // sliderbank21 -> gain271::Gain
		sliderbank21_p.getParameterT(4).connectT(0, gain272);                 // sliderbank21 -> gain272::Gain
		sliderbank21_p.getParameterT(5).connectT(0, gain273);                 // sliderbank21 -> gain273::Gain
		sliderbank21_p.getParameterT(6).connectT(0, gain274);                 // sliderbank21 -> gain274::Gain
		sliderbank21_p.getParameterT(7).connectT(0, gain275);                 // sliderbank21 -> gain275::Gain
		global_cable75.getWrappedObject().getParameter().connectT(0, add298); // global_cable75 -> add298::Value
		global_cable76.getWrappedObject().getParameter().connectT(0, add299); // global_cable76 -> add299::Value
		global_cable77.getWrappedObject().getParameter().connectT(0, add300); // global_cable77 -> add300::Value
		global_cable78.getWrappedObject().getParameter().connectT(0, add301); // global_cable78 -> add301::Value
		midi_cc75.getWrappedObject().getParameter().connectT(0, add429);      // midi_cc75 -> add429::Value
		midi_cc76.getWrappedObject().getParameter().connectT(0, add430);      // midi_cc76 -> add430::Value
		midi_cc77.getWrappedObject().getParameter().connectT(0, add431);      // midi_cc77 -> add431::Value
		midi_cc78.getWrappedObject().getParameter().connectT(0, add432);      // midi_cc78 -> add432::Value
		midi57.getParameter().connectT(0, add433);                            // midi57 -> add433::Value
		midi58.getParameter().connectT(0, add434);                            // midi58 -> add434::Value
		midi59.getParameter().connectT(0, add435);                            // midi59 -> add435::Value
		pma25.getWrappedObject().getParameter().connectT(0, gain77);          // pma25 -> gain77::Gain
		peak41.getParameter().connectT(0, pma25);                             // peak41 -> pma25::Value
		auto& sliderbank22_p = sliderbank22.getWrappedObject().getParameter();
		sliderbank22_p.getParameterT(0).connectT(0, gain276);                 // sliderbank22 -> gain276::Gain
		sliderbank22_p.getParameterT(1).connectT(0, gain277);                 // sliderbank22 -> gain277::Gain
		sliderbank22_p.getParameterT(2).connectT(0, gain278);                 // sliderbank22 -> gain278::Gain
		sliderbank22_p.getParameterT(3).connectT(0, gain279);                 // sliderbank22 -> gain279::Gain
		sliderbank22_p.getParameterT(4).connectT(0, gain280);                 // sliderbank22 -> gain280::Gain
		sliderbank22_p.getParameterT(5).connectT(0, gain281);                 // sliderbank22 -> gain281::Gain
		sliderbank22_p.getParameterT(6).connectT(0, gain282);                 // sliderbank22 -> gain282::Gain
		sliderbank22_p.getParameterT(7).connectT(0, gain283);                 // sliderbank22 -> gain283::Gain
		global_cable79.getWrappedObject().getParameter().connectT(0, add309); // global_cable79 -> add309::Value
		global_cable80.getWrappedObject().getParameter().connectT(0, add310); // global_cable80 -> add310::Value
		global_cable81.getWrappedObject().getParameter().connectT(0, add311); // global_cable81 -> add311::Value
		global_cable82.getWrappedObject().getParameter().connectT(0, add312); // global_cable82 -> add312::Value
		midi_cc79.getWrappedObject().getParameter().connectT(0, add436);      // midi_cc79 -> add436::Value
		midi_cc80.getWrappedObject().getParameter().connectT(0, add437);      // midi_cc80 -> add437::Value
		midi_cc81.getWrappedObject().getParameter().connectT(0, add438);      // midi_cc81 -> add438::Value
		midi_cc82.getWrappedObject().getParameter().connectT(0, add439);      // midi_cc82 -> add439::Value
		midi60.getParameter().connectT(0, add440);                            // midi60 -> add440::Value
		midi61.getParameter().connectT(0, add441);                            // midi61 -> add441::Value
		midi62.getParameter().connectT(0, add442);                            // midi62 -> add442::Value
		pma26.getWrappedObject().getParameter().connectT(0, jpanner3);        // pma26 -> jpanner3::Pan
		peak42.getParameter().connectT(0, pma26);                             // peak42 -> pma26::Value
		peak17.getParameter().connectT(0, add3);                              // peak17 -> add3::Value
		peak17.getParameter().connectT(1, add25);                             // peak17 -> add25::Value
		peak17.getParameter().connectT(2, add103);                            // peak17 -> add103::Value
		peak17.getParameter().connectT(3, add107);                            // peak17 -> add107::Value
		peak17.getParameter().connectT(4, add117);                            // peak17 -> add117::Value
		peak17.getParameter().connectT(5, add167);                            // peak17 -> add167::Value
		peak17.getParameter().connectT(6, add149);                            // peak17 -> add149::Value
		peak17.getParameter().connectT(7, add185);                            // peak17 -> add185::Value
		peak17.getParameter().connectT(8, add203);                            // peak17 -> add203::Value
		peak17.getParameter().connectT(9, add249);                            // peak17 -> add249::Value
		peak17.getParameter().connectT(10, add231);                           // peak17 -> add231::Value
		peak17.getParameter().connectT(11, add260);                           // peak17 -> add260::Value
		peak17.getParameter().connectT(12, add282);                           // peak17 -> add282::Value
		peak17.getParameter().connectT(13, add293);                           // peak17 -> add293::Value
		peak17.getParameter().connectT(14, add304);                           // peak17 -> add304::Value
		peak17.getParameter().connectT(15, add315);                           // peak17 -> add315::Value
		peak17.getParameter().connectT(16, add271);                           // peak17 -> add271::Value
		peak20.getParameter().connectT(0, add23);                             // peak20 -> add23::Value
		peak20.getParameter().connectT(1, add30);                             // peak20 -> add30::Value
		peak20.getParameter().connectT(2, add104);                            // peak20 -> add104::Value
		peak20.getParameter().connectT(3, add108);                            // peak20 -> add108::Value
		peak20.getParameter().connectT(4, add118);                            // peak20 -> add118::Value
		peak20.getParameter().connectT(5, add168);                            // peak20 -> add168::Value
		peak20.getParameter().connectT(6, add150);                            // peak20 -> add150::Value
		peak20.getParameter().connectT(7, add186);                            // peak20 -> add186::Value
		peak20.getParameter().connectT(8, add204);                            // peak20 -> add204::Value
		peak20.getParameter().connectT(9, add250);                            // peak20 -> add250::Value
		peak20.getParameter().connectT(10, add232);                           // peak20 -> add232::Value
		peak20.getParameter().connectT(11, add261);                           // peak20 -> add261::Value
		peak20.getParameter().connectT(12, add283);                           // peak20 -> add283::Value
		peak20.getParameter().connectT(13, add294);                           // peak20 -> add294::Value
		peak20.getParameter().connectT(14, add305);                           // peak20 -> add305::Value
		peak20.getParameter().connectT(15, add316);                           // peak20 -> add316::Value
		peak20.getParameter().connectT(16, add272);                           // peak20 -> add272::Value
		tempo_sync2.getParameter().connectT(0, ramp);                         // tempo_sync2 -> ramp::PeriodTime
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add2);                        // ahdsr -> add2::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, ahdsr); // input_toggle -> ahdsr::Gate
		cable_table1.getWrappedObject().getParameter().connectT(0, add22); // cable_table1 -> add22::Value
		peak2.getParameter().connectT(0, input_toggle);                    // peak2 -> input_toggle::Value2
		peak2.getParameter().connectT(1, cable_table1);                    // peak2 -> cable_table1::Value
		peak7.getParameter().connectT(0, add29);                           // peak7 -> add29::Value
		peak7.getParameter().connectT(1, add64);                           // peak7 -> add64::Value
		peak7.getParameter().connectT(2, add34);                           // peak7 -> add34::Value
		peak7.getParameter().connectT(3, add46);                           // peak7 -> add46::Value
		peak7.getParameter().connectT(4, add115);                          // peak7 -> add115::Value
		peak7.getParameter().connectT(5, add165);                          // peak7 -> add165::Value
		peak7.getParameter().connectT(6, add247);                          // peak7 -> add247::Value
		peak7.getParameter().connectT(7, add229);                          // peak7 -> add229::Value
		peak7.getParameter().connectT(8, add258);                          // peak7 -> add258::Value
		peak7.getParameter().connectT(9, add201);                          // peak7 -> add201::Value
		peak7.getParameter().connectT(10, add183);                         // peak7 -> add183::Value
		peak7.getParameter().connectT(11, add147);                         // peak7 -> add147::Value
		peak7.getParameter().connectT(12, add280);                         // peak7 -> add280::Value
		peak7.getParameter().connectT(13, add291);                         // peak7 -> add291::Value
		peak7.getParameter().connectT(14, add302);                         // peak7 -> add302::Value
		peak7.getParameter().connectT(15, add269);                         // peak7 -> add269::Value
		tempo_sync5.getParameter().connectT(0, ramp4);                     // tempo_sync5 -> ramp4::PeriodTime
		auto& ahdsr6_p = ahdsr6.getWrappedObject().getParameter();
		ahdsr6_p.getParameterT(0).connectT(0, add100);                       // ahdsr6 -> add100::Value
		input_toggle2.getWrappedObject().getParameter().connectT(0, ahdsr6); // input_toggle2 -> ahdsr6::Gate
		cable_table8.getWrappedObject().getParameter().connectT(0, add102);  // cable_table8 -> add102::Value
		peak14.getParameter().connectT(0, input_toggle2);                    // peak14 -> input_toggle2::Value2
		peak14.getParameter().connectT(1, cable_table8);                     // peak14 -> cable_table8::Value
		peak16.getParameter().connectT(0, add28);                            // peak16 -> add28::Value
		peak16.getParameter().connectT(1, add65);                            // peak16 -> add65::Value
		peak16.getParameter().connectT(2, add35);                            // peak16 -> add35::Value
		peak16.getParameter().connectT(3, add47);                            // peak16 -> add47::Value
		peak16.getParameter().connectT(4, add116);                           // peak16 -> add116::Value
		peak16.getParameter().connectT(5, add166);                           // peak16 -> add166::Value
		peak16.getParameter().connectT(6, add248);                           // peak16 -> add248::Value
		peak16.getParameter().connectT(7, add230);                           // peak16 -> add230::Value
		peak16.getParameter().connectT(8, add259);                           // peak16 -> add259::Value
		peak16.getParameter().connectT(9, add202);                           // peak16 -> add202::Value
		peak16.getParameter().connectT(10, add184);                          // peak16 -> add184::Value
		peak16.getParameter().connectT(11, add148);                          // peak16 -> add148::Value
		peak16.getParameter().connectT(12, add281);                          // peak16 -> add281::Value
		peak16.getParameter().connectT(13, add292);                          // peak16 -> add292::Value
		peak16.getParameter().connectT(14, add303);                          // peak16 -> add303::Value
		peak16.getParameter().connectT(15, add270);                          // peak16 -> add270::Value
		tempo_sync6.getParameter().connectT(0, ramp5);                       // tempo_sync6 -> ramp5::PeriodTime
		minmax30.getWrappedObject().getParameter().connectT(0, add552);      // minmax30 -> add552::Value
		minmax31.getWrappedObject().getParameter().connectT(0, add553);      // minmax31 -> add553::Value
		minmax32.getWrappedObject().getParameter().connectT(0, add554);      // minmax32 -> add554::Value
		minmax33.getWrappedObject().getParameter().connectT(0, add555);      // minmax33 -> add555::Value
		minmax34.getWrappedObject().getParameter().connectT(0, add556);      // minmax34 -> add556::Value
		minmax35.getWrappedObject().getParameter().connectT(0, add557);      // minmax35 -> add557::Value
		minmax36.getWrappedObject().getParameter().connectT(0, add558);      // minmax36 -> add558::Value
		minmax37.getWrappedObject().getParameter().connectT(0, add559);      // minmax37 -> add559::Value
		pma33.getWrappedObject().getParameter().connectT(0, minmax30);       // pma33 -> minmax30::Value
		pma33.getWrappedObject().getParameter().connectT(1, minmax31);       // pma33 -> minmax31::Value
		pma33.getWrappedObject().getParameter().connectT(2, minmax32);       // pma33 -> minmax32::Value
		pma33.getWrappedObject().getParameter().connectT(3, minmax33);       // pma33 -> minmax33::Value
		pma33.getWrappedObject().getParameter().connectT(4, minmax34);       // pma33 -> minmax34::Value
		pma33.getWrappedObject().getParameter().connectT(5, minmax35);       // pma33 -> minmax35::Value
		pma33.getWrappedObject().getParameter().connectT(6, minmax36);       // pma33 -> minmax36::Value
		pma33.getWrappedObject().getParameter().connectT(7, add551);         // pma33 -> add551::Value
		pma33.getWrappedObject().getParameter().connectT(8, minmax37);       // pma33 -> minmax37::Value
		peak15.getParameter().connectT(0, pma33);                            // peak15 -> pma33::Value
		tempo_sync9.getParameter().connectT(0, ramp8);                       // tempo_sync9 -> ramp8::PeriodTime
		minmax10.getWrappedObject().getParameter().connectT(0, add525);      // minmax10 -> add525::Value
		minmax13.getWrappedObject().getParameter().connectT(0, add526);      // minmax13 -> add526::Value
		minmax24.getWrappedObject().getParameter().connectT(0, add527);      // minmax24 -> add527::Value
		minmax25.getWrappedObject().getParameter().connectT(0, add528);      // minmax25 -> add528::Value
		minmax26.getWrappedObject().getParameter().connectT(0, add529);      // minmax26 -> add529::Value
		minmax27.getWrappedObject().getParameter().connectT(0, add530);      // minmax27 -> add530::Value
		minmax28.getWrappedObject().getParameter().connectT(0, add531);      // minmax28 -> add531::Value
		minmax29.getWrappedObject().getParameter().connectT(0, add532);      // minmax29 -> add532::Value
		pma32.getWrappedObject().getParameter().connectT(0, minmax10);       // pma32 -> minmax10::Value
		pma32.getWrappedObject().getParameter().connectT(1, minmax13);       // pma32 -> minmax13::Value
		pma32.getWrappedObject().getParameter().connectT(2, minmax24);       // pma32 -> minmax24::Value
		pma32.getWrappedObject().getParameter().connectT(3, minmax25);       // pma32 -> minmax25::Value
		pma32.getWrappedObject().getParameter().connectT(4, minmax26);       // pma32 -> minmax26::Value
		pma32.getWrappedObject().getParameter().connectT(5, minmax27);       // pma32 -> minmax27::Value
		pma32.getWrappedObject().getParameter().connectT(6, minmax28);       // pma32 -> minmax28::Value
		pma32.getWrappedObject().getParameter().connectT(7, add524);         // pma32 -> add524::Value
		pma32.getWrappedObject().getParameter().connectT(8, minmax29);       // pma32 -> minmax29::Value
		peak49.getParameter().connectT(0, pma32);                            // peak49 -> pma32::Value
		tempo_sync8.getParameter().connectT(0, ramp7);                       // tempo_sync8 -> ramp7::PeriodTime
		minmax8.getWrappedObject().getParameter().connectT(0, add498);       // minmax8 -> add498::Value
		minmax9.getWrappedObject().getParameter().connectT(0, add499);       // minmax9 -> add499::Value
		minmax19.getWrappedObject().getParameter().connectT(0, add500);      // minmax19 -> add500::Value
		minmax12.getWrappedObject().getParameter().connectT(0, add501);      // minmax12 -> add501::Value
		minmax20.getWrappedObject().getParameter().connectT(0, add502);      // minmax20 -> add502::Value
		minmax21.getWrappedObject().getParameter().connectT(0, add503);      // minmax21 -> add503::Value
		minmax22.getWrappedObject().getParameter().connectT(0, add504);      // minmax22 -> add504::Value
		minmax23.getWrappedObject().getParameter().connectT(0, add505);      // minmax23 -> add505::Value
		pma31.getWrappedObject().getParameter().connectT(0, minmax8);        // pma31 -> minmax8::Value
		pma31.getWrappedObject().getParameter().connectT(1, minmax9);        // pma31 -> minmax9::Value
		pma31.getWrappedObject().getParameter().connectT(2, minmax19);       // pma31 -> minmax19::Value
		pma31.getWrappedObject().getParameter().connectT(3, minmax12);       // pma31 -> minmax12::Value
		pma31.getWrappedObject().getParameter().connectT(4, minmax20);       // pma31 -> minmax20::Value
		pma31.getWrappedObject().getParameter().connectT(5, minmax21);       // pma31 -> minmax21::Value
		pma31.getWrappedObject().getParameter().connectT(6, minmax22);       // pma31 -> minmax22::Value
		pma31.getWrappedObject().getParameter().connectT(7, minmax23);       // pma31 -> minmax23::Minimum
		pma31.getWrappedObject().getParameter().connectT(8, add497);         // pma31 -> add497::Value
		peak48.getParameter().connectT(0, pma31);                            // peak48 -> pma31::Value
		tempo_sync7.getParameter().connectT(0, ramp6);                       // tempo_sync7 -> ramp6::PeriodTime
		minmax38.getWrappedObject().getParameter().connectT(0, add579);      // minmax38 -> add579::Value
		minmax39.getWrappedObject().getParameter().connectT(0, add580);      // minmax39 -> add580::Value
		minmax40.getWrappedObject().getParameter().connectT(0, add581);      // minmax40 -> add581::Value
		minmax41.getWrappedObject().getParameter().connectT(0, add582);      // minmax41 -> add582::Value
		minmax42.getWrappedObject().getParameter().connectT(0, add583);      // minmax42 -> add583::Value
		minmax43.getWrappedObject().getParameter().connectT(0, add584);      // minmax43 -> add584::Value
		minmax44.getWrappedObject().getParameter().connectT(0, add585);      // minmax44 -> add585::Value
		minmax45.getWrappedObject().getParameter().connectT(0, add586);      // minmax45 -> add586::Value
		pma34.getWrappedObject().getParameter().connectT(0, minmax38);       // pma34 -> minmax38::Value
		pma34.getWrappedObject().getParameter().connectT(1, minmax39);       // pma34 -> minmax39::Value
		pma34.getWrappedObject().getParameter().connectT(2, minmax40);       // pma34 -> minmax40::Value
		pma34.getWrappedObject().getParameter().connectT(3, minmax41);       // pma34 -> minmax41::Value
		pma34.getWrappedObject().getParameter().connectT(4, minmax42);       // pma34 -> minmax42::Value
		pma34.getWrappedObject().getParameter().connectT(5, minmax43);       // pma34 -> minmax43::Value
		pma34.getWrappedObject().getParameter().connectT(6, minmax44);       // pma34 -> minmax44::Value
		pma34.getWrappedObject().getParameter().connectT(7, minmax45);       // pma34 -> minmax45::Minimum
		pma34.getWrappedObject().getParameter().connectT(8, add578);         // pma34 -> add578::Value
		peak47.getParameter().connectT(0, pma34);                            // peak47 -> pma34::Value
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, gain7);  // sliderbank -> gain7::Gain
		sliderbank_p.getParameterT(1).connectT(0, gain91); // sliderbank -> gain91::Gain
		sliderbank_p.getParameterT(2).connectT(0, gain95); // sliderbank -> gain95::Gain
		sliderbank_p.getParameterT(3).connectT(0, gain99); // sliderbank -> gain99::Gain
		auto& sliderbank13_p = sliderbank13.getWrappedObject().getParameter();
		sliderbank13_p.getParameterT(0).connectT(0, gain124);                 // sliderbank13 -> gain124::Gain
		sliderbank13_p.getParameterT(1).connectT(0, gain125);                 // sliderbank13 -> gain125::Gain
		sliderbank13_p.getParameterT(2).connectT(0, gain126);                 // sliderbank13 -> gain126::Gain
		sliderbank13_p.getParameterT(3).connectT(0, gain127);                 // sliderbank13 -> gain127::Gain
		sliderbank13_p.getParameterT(4).connectT(0, gain128);                 // sliderbank13 -> gain128::Gain
		sliderbank13_p.getParameterT(5).connectT(0, gain129);                 // sliderbank13 -> gain129::Gain
		sliderbank13_p.getParameterT(6).connectT(0, gain130);                 // sliderbank13 -> gain130::Gain
		sliderbank13_p.getParameterT(7).connectT(0, gain131);                 // sliderbank13 -> gain131::Gain
		global_cable43.getWrappedObject().getParameter().connectT(0, add179); // global_cable43 -> add179::Value
		global_cable44.getWrappedObject().getParameter().connectT(0, add180); // global_cable44 -> add180::Value
		global_cable45.getWrappedObject().getParameter().connectT(0, add181); // global_cable45 -> add181::Value
		global_cable46.getWrappedObject().getParameter().connectT(0, add182); // global_cable46 -> add182::Value
		midi_cc43.getWrappedObject().getParameter().connectT(0, add190);      // midi_cc43 -> add190::Value
		midi_cc44.getWrappedObject().getParameter().connectT(0, add191);      // midi_cc44 -> add191::Value
		midi_cc45.getWrappedObject().getParameter().connectT(0, add192);      // midi_cc45 -> add192::Value
		midi_cc46.getWrappedObject().getParameter().connectT(0, add193);      // midi_cc46 -> add193::Value
		midi32.getParameter().connectT(0, add194);                            // midi32 -> add194::Value
		midi33.getParameter().connectT(0, add195);                            // midi33 -> add195::Value
		midi34.getParameter().connectT(0, add196);                            // midi34 -> add196::Value
		minmax6.getWrappedObject().getParameter().connectT(0, add214);        // minmax6 -> add214::Value
		minmax7.getWrappedObject().getParameter().connectT(0, add215);        // minmax7 -> add215::Value
		minmax14.getWrappedObject().getParameter().connectT(0, add216);       // minmax14 -> add216::Value
		minmax11.getWrappedObject().getParameter().connectT(0, add217);       // minmax11 -> add217::Value
		minmax15.getWrappedObject().getParameter().connectT(0, add218);       // minmax15 -> add218::Value
		minmax16.getWrappedObject().getParameter().connectT(0, add219);       // minmax16 -> add219::Value
		minmax17.getWrappedObject().getParameter().connectT(0, add220);       // minmax17 -> add220::Value
		minmax18.getWrappedObject().getParameter().connectT(0, add221);       // minmax18 -> add221::Value
		pma17.getWrappedObject().getParameter().connectT(0, minmax6);         // pma17 -> minmax6::Value
		pma17.getWrappedObject().getParameter().connectT(1, minmax7);         // pma17 -> minmax7::Value
		pma17.getWrappedObject().getParameter().connectT(2, minmax14);        // pma17 -> minmax14::Value
		pma17.getWrappedObject().getParameter().connectT(3, minmax11);        // pma17 -> minmax11::Value
		pma17.getWrappedObject().getParameter().connectT(4, minmax15);        // pma17 -> minmax15::Value
		pma17.getWrappedObject().getParameter().connectT(5, minmax16);        // pma17 -> minmax16::Value
		pma17.getWrappedObject().getParameter().connectT(6, minmax17);        // pma17 -> minmax17::Value
		pma17.getWrappedObject().getParameter().connectT(7, add213);          // pma17 -> add213::Value
		pma17.getWrappedObject().getParameter().connectT(8, minmax18);        // pma17 -> minmax18::Value
		peak21.getParameter().connectT(0, pma17);                             // peak21 -> pma17::Value
		peak18.getParameter().connectT(0, add222);                            // peak18 -> add222::Value
		peak18.getParameter().connectT(1, cable_table5);                      // peak18 -> cable_table5::Value
		peak18.getParameter().connectT(2, add474);                            // peak18 -> add474::Value
		peak18.getParameter().connectT(3, add469);                            // peak18 -> add469::Value
		peak18.getParameter().connectT(4, add464);                            // peak18 -> add464::Value
		peak43.getParameter().connectT(0, cable_table9);                      // peak43 -> cable_table9::Value
		peak43.getParameter().connectT(1, add463);                            // peak43 -> add463::Value
		peak31.getParameter().connectT(0, cable_table7);                      // peak31 -> cable_table7::Value
		peak31.getParameter().connectT(1, add475);                            // peak31 -> add475::Value
		peak29.getParameter().connectT(0, cable_table6);                      // peak29 -> cable_table6::Value
		peak29.getParameter().connectT(1, add470);                            // peak29 -> add470::Value
		peak45.getParameter().connectT(0, cable_table10);                     // peak45 -> cable_table10::Value
		peak45.getParameter().connectT(1, add465);                            // peak45 -> add465::Value
		cable_table15.getWrappedObject().getParameter().connectT(0, faust4);  // cable_table15 -> faust4::shiftfreq
		midi42.getParameter().connectT(0, cable_table15);                     // midi42 -> cable_table15::Value
		peak22.getParameter().connectT(0, add21);                             // peak22 -> add21::Value
		peak22.getParameter().connectT(1, add74);                             // peak22 -> add74::Value
		peak22.getParameter().connectT(2, add105);                            // peak22 -> add105::Value
		peak22.getParameter().connectT(3, add109);                            // peak22 -> add109::Value
		peak22.getParameter().connectT(4, add119);                            // peak22 -> add119::Value
		peak22.getParameter().connectT(5, add169);                            // peak22 -> add169::Value
		peak22.getParameter().connectT(6, add151);                            // peak22 -> add151::Value
		peak22.getParameter().connectT(7, add187);                            // peak22 -> add187::Value
		peak22.getParameter().connectT(8, add205);                            // peak22 -> add205::Value
		peak22.getParameter().connectT(9, add251);                            // peak22 -> add251::Value
		peak22.getParameter().connectT(10, add233);                           // peak22 -> add233::Value
		peak22.getParameter().connectT(11, add262);                           // peak22 -> add262::Value
		peak22.getParameter().connectT(12, add284);                           // peak22 -> add284::Value
		peak22.getParameter().connectT(13, add295);                           // peak22 -> add295::Value
		peak22.getParameter().connectT(14, add306);                           // peak22 -> add306::Value
		peak22.getParameter().connectT(15, add317);                           // peak22 -> add317::Value
		peak22.getParameter().connectT(16, add273);                           // peak22 -> add273::Value
		peak33.getParameter().connectT(0, add9);                              // peak33 -> add9::Value
		peak33.getParameter().connectT(1, add99);                             // peak33 -> add99::Value
		peak33.getParameter().connectT(2, add106);                            // peak33 -> add106::Value
		peak33.getParameter().connectT(3, add110);                            // peak33 -> add110::Value
		peak33.getParameter().connectT(4, add120);                            // peak33 -> add120::Value
		peak33.getParameter().connectT(5, add170);                            // peak33 -> add170::Value
		peak33.getParameter().connectT(6, add152);                            // peak33 -> add152::Value
		peak33.getParameter().connectT(7, add188);                            // peak33 -> add188::Value
		peak33.getParameter().connectT(8, add206);                            // peak33 -> add206::Value
		peak33.getParameter().connectT(9, add234);                            // peak33 -> add234::Value
		peak33.getParameter().connectT(10, add263);                           // peak33 -> add263::Value
		peak33.getParameter().connectT(11, add285);                           // peak33 -> add285::Value
		peak33.getParameter().connectT(12, add296);                           // peak33 -> add296::Value
		peak33.getParameter().connectT(13, add307);                           // peak33 -> add307::Value
		peak33.getParameter().connectT(14, add318);                           // peak33 -> add318::Value
		peak33.getParameter().connectT(15, add274);                           // peak33 -> add274::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive10);
		send.connect(receive13);
		send.connect(receive6);
		send6.connect(receive11);
		send6.connect(receive14);
		send6.connect(receive7);
		send2.connect(receive2);
		send3.connect(receive3);
		send1.connect(receive15);
		send1.connect(receive5);
		send1.connect(receive8);
		send7.connect(receive4);
		send7.connect(receive9);
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank3.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		;                             // gain13::Gain is automated
		gain13.setParameterT(1, 20.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		;                             // gain15::Gain is automated
		gain15.setParameterT(1, 20.); // core::gain::Smoothing
		gain15.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		;                             // gain14::Gain is automated
		gain14.setParameterT(1, 20.); // core::gain::Smoothing
		gain14.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		;                             // gain16::Gain is automated
		gain16.setParameterT(1, 20.); // core::gain::Smoothing
		gain16.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add29::Value is automated
		
		;                             // gain32::Gain is automated
		gain32.setParameterT(1, 20.); // core::gain::Smoothing
		gain32.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add28::Value is automated
		
		;                             // gain26::Gain is automated
		gain26.setParameterT(1, 20.); // core::gain::Smoothing
		gain26.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch15::Index is automated
		
		; // add3::Value is automated
		
		; // add23::Value is automated
		
		; // add21::Value is automated
		
		; // add9::Value is automated
		
		;                             // gain33::Gain is automated
		gain33.setParameterT(1, 20.); // core::gain::Smoothing
		gain33.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		sliderbank5.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		;                             // gain21::Gain is automated
		gain21.setParameterT(1, 20.); // core::gain::Smoothing
		gain21.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		;                             // gain22::Gain is automated
		gain22.setParameterT(1, 20.); // core::gain::Smoothing
		gain22.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		;                             // gain23::Gain is automated
		gain23.setParameterT(1, 20.); // core::gain::Smoothing
		gain23.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add49::Value is automated
		
		;                             // gain24::Gain is automated
		gain24.setParameterT(1, 20.); // core::gain::Smoothing
		gain24.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add64::Value is automated
		
		;                             // gain38::Gain is automated
		gain38.setParameterT(1, 20.); // core::gain::Smoothing
		gain38.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add65::Value is automated
		
		;                             // gain28::Gain is automated
		gain28.setParameterT(1, 20.); // core::gain::Smoothing
		gain28.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch16::Index is automated
		
		; // add25::Value is automated
		
		; // add30::Value is automated
		
		; // add74::Value is automated
		
		; // add99::Value is automated
		
		;                             // gain39::Gain is automated
		gain39.setParameterT(1, 20.); // core::gain::Smoothing
		gain39.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch11::Index is automated
		
		midi_cc18.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc18.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc18.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add67::Value is automated
		
		midi_cc19.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc19.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc19.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add68::Value is automated
		
		midi_cc20.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc20.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc20.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add69::Value is automated
		
		midi_cc21.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc21.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc21.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add70::Value is automated
		
		; // add71::Value is automated
		
		; // add72::Value is automated
		
		; // add73::Value is automated
		
		;                             // gain40::Gain is automated
		gain40.setParameterT(1, 20.); // core::gain::Smoothing
		gain40.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // branch12::Index is automated
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // add1::Value is automated
		
		; // pma14::Value is automated
		; // pma14::Multiply is automated
		; // pma14::Add is automated
		
		; // add18::Value is automated
		
		;                           // pma15::Value is automated
		pma15.setParameterT(1, 0.); // control::pma::Multiply
		;                           // pma15::Add is automated
		
		; // add13::Value is automated
		
		;                               // smoother1::SmoothingTime is automated
		smoother1.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		sliderbank4.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		;                             // gain18::Gain is automated
		gain18.setParameterT(1, 20.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		;                             // gain19::Gain is automated
		gain19.setParameterT(1, 20.); // core::gain::Smoothing
		gain19.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		;                             // gain20::Gain is automated
		gain20.setParameterT(1, 20.); // core::gain::Smoothing
		gain20.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add34::Value is automated
		
		;                             // gain35::Gain is automated
		gain35.setParameterT(1, 20.); // core::gain::Smoothing
		gain35.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add35::Value is automated
		
		;                             // gain27::Gain is automated
		gain27.setParameterT(1, 20.); // core::gain::Smoothing
		gain27.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch19::Index is automated
		
		; // add103::Value is automated
		
		; // add104::Value is automated
		
		; // add105::Value is automated
		
		; // add106::Value is automated
		
		add36.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain36::Gain is automated
		gain36.setParameterT(1, 20.); // core::gain::Smoothing
		gain36.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch4::Index is automated
		
		midi_cc3.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc3.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc3.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add31::Value is automated
		
		midi_cc5.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc5.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc5.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add38::Value is automated
		
		midi_cc7.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc7.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc7.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add39::Value is automated
		
		midi_cc8.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc8.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc8.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add40::Value is automated
		
		; // add41::Value is automated
		
		; // add42::Value is automated
		
		; // add43::Value is automated
		
		;                             // gain37::Gain is automated
		gain37.setParameterT(1, 20.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		sliderbank6.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add44::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                             // gain30::Gain is automated
		gain30.setParameterT(1, 20.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add45::Value is automated
		
		;                             // gain31::Gain is automated
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add46::Value is automated
		
		;                             // gain41::Gain is automated
		gain41.setParameterT(1, 20.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add47::Value is automated
		
		;                             // gain42::Gain is automated
		gain42.setParameterT(1, 20.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch20::Index is automated
		
		; // add107::Value is automated
		
		; // add108::Value is automated
		
		; // add109::Value is automated
		
		; // add110::Value is automated
		
		add48.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain43::Gain is automated
		gain43.setParameterT(1, 20.); // core::gain::Smoothing
		gain43.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		sliderbank7.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add111::Value is automated
		
		;                             // gain48::Gain is automated
		gain48.setParameterT(1, 20.); // core::gain::Smoothing
		gain48.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add112::Value is automated
		
		;                             // gain61::Gain is automated
		gain61.setParameterT(1, 20.); // core::gain::Smoothing
		gain61.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add113::Value is automated
		
		;                             // gain66::Gain is automated
		gain66.setParameterT(1, 20.); // core::gain::Smoothing
		gain66.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add114::Value is automated
		
		;                             // gain67::Gain is automated
		gain67.setParameterT(1, 20.); // core::gain::Smoothing
		gain67.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add115::Value is automated
		
		;                             // gain68::Gain is automated
		gain68.setParameterT(1, 20.); // core::gain::Smoothing
		gain68.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add116::Value is automated
		
		;                             // gain69::Gain is automated
		gain69.setParameterT(1, 20.); // core::gain::Smoothing
		gain69.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch24::Index is automated
		
		; // add117::Value is automated
		
		; // add118::Value is automated
		
		; // add119::Value is automated
		
		; // add120::Value is automated
		
		add121.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain70::Gain is automated
		gain70.setParameterT(1, 20.); // core::gain::Smoothing
		gain70.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch25::Index is automated
		
		midi_cc4.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc4.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc4.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add122::Value is automated
		
		midi_cc6.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc6.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc6.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add123::Value is automated
		
		midi_cc9.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc9.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc9.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add124::Value is automated
		
		midi_cc30.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc30.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc30.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add125::Value is automated
		
		; // add126::Value is automated
		
		; // add127::Value is automated
		
		; // add128::Value is automated
		
		;                             // gain71::Gain is automated
		gain71.setParameterT(1, 20.); // core::gain::Smoothing
		gain71.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma5::Value is automated
		; // pma5::Multiply is automated
		; // pma5::Add is automated
		
		sliderbank12.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable39.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add161::Value is automated
		
		;                              // gain116::Gain is automated
		gain116.setParameterT(1, 20.); // core::gain::Smoothing
		gain116.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable40.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add162::Value is automated
		
		;                              // gain117::Gain is automated
		gain117.setParameterT(1, 20.); // core::gain::Smoothing
		gain117.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable41.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add163::Value is automated
		
		;                              // gain118::Gain is automated
		gain118.setParameterT(1, 20.); // core::gain::Smoothing
		gain118.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable42.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add164::Value is automated
		
		;                              // gain119::Gain is automated
		gain119.setParameterT(1, 20.); // core::gain::Smoothing
		gain119.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add165::Value is automated
		
		;                              // gain120::Gain is automated
		gain120.setParameterT(1, 20.); // core::gain::Smoothing
		gain120.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add166::Value is automated
		
		;                              // gain121::Gain is automated
		gain121.setParameterT(1, 20.); // core::gain::Smoothing
		gain121.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch49::Index is automated
		
		; // add167::Value is automated
		
		; // add168::Value is automated
		
		; // add169::Value is automated
		
		; // add170::Value is automated
		
		add171.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain122::Gain is automated
		gain122.setParameterT(1, 20.); // core::gain::Smoothing
		gain122.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		sliderbank11.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable35.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add143::Value is automated
		
		;                              // gain108::Gain is automated
		gain108.setParameterT(1, 20.); // core::gain::Smoothing
		gain108.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable36.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add144::Value is automated
		
		;                              // gain109::Gain is automated
		gain109.setParameterT(1, 20.); // core::gain::Smoothing
		gain109.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable37.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add145::Value is automated
		
		;                              // gain110::Gain is automated
		gain110.setParameterT(1, 20.); // core::gain::Smoothing
		gain110.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable38.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add146::Value is automated
		
		;                              // gain111::Gain is automated
		gain111.setParameterT(1, 20.); // core::gain::Smoothing
		gain111.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add147::Value is automated
		
		;                              // gain112::Gain is automated
		gain112.setParameterT(1, 20.); // core::gain::Smoothing
		gain112.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add148::Value is automated
		
		;                              // gain113::Gain is automated
		gain113.setParameterT(1, 20.); // core::gain::Smoothing
		gain113.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch47::Index is automated
		
		; // add149::Value is automated
		
		; // add150::Value is automated
		
		; // add151::Value is automated
		
		; // add152::Value is automated
		
		add153.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain114::Gain is automated
		gain114.setParameterT(1, 20.); // core::gain::Smoothing
		gain114.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch48::Index is automated
		
		midi_cc35.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc35.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc35.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add154::Value is automated
		
		midi_cc36.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc36.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc36.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add155::Value is automated
		
		midi_cc37.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc37.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc37.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add156::Value is automated
		
		midi_cc38.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc38.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc38.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add157::Value is automated
		
		; // add158::Value is automated
		
		; // add159::Value is automated
		
		; // add160::Value is automated
		
		;                              // gain115::Gain is automated
		gain115.setParameterT(1, 20.); // core::gain::Smoothing
		gain115.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma9::Value is automated
		; // pma9::Multiply is automated
		; // pma9::Add is automated
		
		sliderbank14.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable47.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add197::Value is automated
		
		;                              // gain132::Gain is automated
		gain132.setParameterT(1, 20.); // core::gain::Smoothing
		gain132.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable48.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add198::Value is automated
		
		;                              // gain133::Gain is automated
		gain133.setParameterT(1, 20.); // core::gain::Smoothing
		gain133.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable49.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add199::Value is automated
		
		;                              // gain134::Gain is automated
		gain134.setParameterT(1, 20.); // core::gain::Smoothing
		gain134.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable50.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add200::Value is automated
		
		;                              // gain135::Gain is automated
		gain135.setParameterT(1, 20.); // core::gain::Smoothing
		gain135.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add201::Value is automated
		
		;                              // gain136::Gain is automated
		gain136.setParameterT(1, 20.); // core::gain::Smoothing
		gain136.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add202::Value is automated
		
		;                              // gain137::Gain is automated
		gain137.setParameterT(1, 20.); // core::gain::Smoothing
		gain137.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch53::Index is automated
		
		; // add203::Value is automated
		
		; // add204::Value is automated
		
		; // add205::Value is automated
		
		; // add206::Value is automated
		
		add207.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain138::Gain is automated
		gain138.setParameterT(1, 20.); // core::gain::Smoothing
		gain138.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch54::Index is automated
		
		midi_cc47.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc47.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc47.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add208::Value is automated
		
		midi_cc48.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc48.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc48.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add209::Value is automated
		
		midi_cc49.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc49.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc49.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add210::Value is automated
		
		midi_cc50.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc50.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc50.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add211::Value is automated
		
		; // add212::Value is automated
		
		; // add223::Value is automated
		
		; // add224::Value is automated
		
		;                              // gain139::Gain is automated
		gain139.setParameterT(1, 20.); // core::gain::Smoothing
		gain139.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma18::Value is automated
		; // pma18::Multiply is automated
		; // pma18::Add is automated
		
		sliderbank15.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable51.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add225::Value is automated
		
		;                              // gain140::Gain is automated
		gain140.setParameterT(1, 20.); // core::gain::Smoothing
		gain140.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable52.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add226::Value is automated
		
		;                              // gain141::Gain is automated
		gain141.setParameterT(1, 20.); // core::gain::Smoothing
		gain141.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable53.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add227::Value is automated
		
		;                              // gain142::Gain is automated
		gain142.setParameterT(1, 20.); // core::gain::Smoothing
		gain142.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable54.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add228::Value is automated
		
		;                              // gain143::Gain is automated
		gain143.setParameterT(1, 20.); // core::gain::Smoothing
		gain143.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add229::Value is automated
		
		;                              // gain144::Gain is automated
		gain144.setParameterT(1, 20.); // core::gain::Smoothing
		gain144.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add230::Value is automated
		
		;                              // gain145::Gain is automated
		gain145.setParameterT(1, 20.); // core::gain::Smoothing
		gain145.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch55::Index is automated
		
		; // add231::Value is automated
		
		; // add232::Value is automated
		
		; // add233::Value is automated
		
		; // add234::Value is automated
		
		add235.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain146::Gain is automated
		gain146.setParameterT(1, 20.); // core::gain::Smoothing
		gain146.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch56::Index is automated
		
		midi_cc51.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc51.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc51.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add236::Value is automated
		
		midi_cc52.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc52.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc52.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add237::Value is automated
		
		midi_cc53.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc53.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc53.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add238::Value is automated
		
		midi_cc54.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc54.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc54.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add239::Value is automated
		
		; // add240::Value is automated
		
		; // add241::Value is automated
		
		; // add242::Value is automated
		
		;                              // gain147::Gain is automated
		gain147.setParameterT(1, 20.); // core::gain::Smoothing
		gain147.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma19::Value is automated
		; // pma19::Multiply is automated
		; // pma19::Add is automated
		
		sliderbank16.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable55.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add243::Value is automated
		
		;                              // gain228::Gain is automated
		gain228.setParameterT(1, 20.); // core::gain::Smoothing
		gain228.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable56.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add244::Value is automated
		
		;                              // gain229::Gain is automated
		gain229.setParameterT(1, 20.); // core::gain::Smoothing
		gain229.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable57.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add245::Value is automated
		
		;                              // gain230::Gain is automated
		gain230.setParameterT(1, 20.); // core::gain::Smoothing
		gain230.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable58.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add246::Value is automated
		
		;                              // gain231::Gain is automated
		gain231.setParameterT(1, 20.); // core::gain::Smoothing
		gain231.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add247::Value is automated
		
		;                              // gain232::Gain is automated
		gain232.setParameterT(1, 20.); // core::gain::Smoothing
		gain232.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add248::Value is automated
		
		;                              // gain233::Gain is automated
		gain233.setParameterT(1, 20.); // core::gain::Smoothing
		gain233.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch57::Index is automated
		
		; // add249::Value is automated
		
		; // add250::Value is automated
		
		; // add251::Value is automated
		
		add252.setParameterT(0, 0.); // math::add::Value
		
		add253.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain234::Gain is automated
		gain234.setParameterT(1, 20.); // core::gain::Smoothing
		gain234.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch58::Index is automated
		
		midi_cc55.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc55.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc55.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add394::Value is automated
		
		midi_cc56.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc56.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc56.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add395::Value is automated
		
		midi_cc57.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc57.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc57.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add396::Value is automated
		
		midi_cc58.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc58.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc58.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add397::Value is automated
		
		; // add398::Value is automated
		
		; // add399::Value is automated
		
		; // add400::Value is automated
		
		;                              // gain235::Gain is automated
		gain235.setParameterT(1, 20.); // core::gain::Smoothing
		gain235.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma20::Value is automated
		; // pma20::Multiply is automated
		; // pma20::Add is automated
		
		sliderbank17.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable59.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add254::Value is automated
		
		;                              // gain236::Gain is automated
		gain236.setParameterT(1, 20.); // core::gain::Smoothing
		gain236.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable60.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add255::Value is automated
		
		;                              // gain237::Gain is automated
		gain237.setParameterT(1, 20.); // core::gain::Smoothing
		gain237.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable61.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add256::Value is automated
		
		;                              // gain238::Gain is automated
		gain238.setParameterT(1, 20.); // core::gain::Smoothing
		gain238.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable62.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add257::Value is automated
		
		;                              // gain239::Gain is automated
		gain239.setParameterT(1, 20.); // core::gain::Smoothing
		gain239.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add258::Value is automated
		
		;                              // gain240::Gain is automated
		gain240.setParameterT(1, 20.); // core::gain::Smoothing
		gain240.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add259::Value is automated
		
		;                              // gain241::Gain is automated
		gain241.setParameterT(1, 20.); // core::gain::Smoothing
		gain241.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch59::Index is automated
		
		; // add260::Value is automated
		
		; // add261::Value is automated
		
		; // add262::Value is automated
		
		; // add263::Value is automated
		
		add264.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain242::Gain is automated
		gain242.setParameterT(1, 20.); // core::gain::Smoothing
		gain242.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch60::Index is automated
		
		midi_cc59.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc59.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc59.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add401::Value is automated
		
		midi_cc60.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc60.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc60.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add402::Value is automated
		
		midi_cc61.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc61.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc61.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add403::Value is automated
		
		midi_cc62.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc62.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc62.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add404::Value is automated
		
		; // add405::Value is automated
		
		; // add406::Value is automated
		
		; // add407::Value is automated
		
		;                              // gain243::Gain is automated
		gain243.setParameterT(1, 20.); // core::gain::Smoothing
		gain243.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma_unscaled::Value is automated
		; // pma_unscaled::Multiply is automated
		; // pma_unscaled::Add is automated
		
		sliderbank18.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable63.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add265::Value is automated
		
		;                              // gain244::Gain is automated
		gain244.setParameterT(1, 20.); // core::gain::Smoothing
		gain244.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable64.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add266::Value is automated
		
		;                              // gain245::Gain is automated
		gain245.setParameterT(1, 20.); // core::gain::Smoothing
		gain245.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable65.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add267::Value is automated
		
		;                              // gain246::Gain is automated
		gain246.setParameterT(1, 20.); // core::gain::Smoothing
		gain246.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable66.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add268::Value is automated
		
		;                              // gain247::Gain is automated
		gain247.setParameterT(1, 20.); // core::gain::Smoothing
		gain247.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add269::Value is automated
		
		;                              // gain248::Gain is automated
		gain248.setParameterT(1, 20.); // core::gain::Smoothing
		gain248.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add270::Value is automated
		
		;                              // gain249::Gain is automated
		gain249.setParameterT(1, 20.); // core::gain::Smoothing
		gain249.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch61::Index is automated
		
		; // add271::Value is automated
		
		; // add272::Value is automated
		
		; // add273::Value is automated
		
		; // add274::Value is automated
		
		add275.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain250::Gain is automated
		gain250.setParameterT(1, 20.); // core::gain::Smoothing
		gain250.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch62::Index is automated
		
		midi_cc63.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc63.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc63.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add408::Value is automated
		
		midi_cc64.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc64.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc64.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add409::Value is automated
		
		midi_cc65.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc65.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc65.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add410::Value is automated
		
		midi_cc66.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc66.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc66.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add411::Value is automated
		
		; // add412::Value is automated
		
		; // add413::Value is automated
		
		; // add414::Value is automated
		
		;                              // gain251::Gain is automated
		gain251.setParameterT(1, 20.); // core::gain::Smoothing
		gain251.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma22::Value is automated
		; // pma22::Multiply is automated
		; // pma22::Add is automated
		
		sliderbank19.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable67.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add276::Value is automated
		
		;                              // gain252::Gain is automated
		gain252.setParameterT(1, 20.); // core::gain::Smoothing
		gain252.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable68.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add277::Value is automated
		
		;                              // gain253::Gain is automated
		gain253.setParameterT(1, 20.); // core::gain::Smoothing
		gain253.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable69.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add278::Value is automated
		
		;                              // gain254::Gain is automated
		gain254.setParameterT(1, 20.); // core::gain::Smoothing
		gain254.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable70.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add279::Value is automated
		
		;                              // gain255::Gain is automated
		gain255.setParameterT(1, 20.); // core::gain::Smoothing
		gain255.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add280::Value is automated
		
		;                              // gain256::Gain is automated
		gain256.setParameterT(1, 20.); // core::gain::Smoothing
		gain256.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add281::Value is automated
		
		;                              // gain257::Gain is automated
		gain257.setParameterT(1, 20.); // core::gain::Smoothing
		gain257.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch63::Index is automated
		
		; // add282::Value is automated
		
		; // add283::Value is automated
		
		; // add284::Value is automated
		
		; // add285::Value is automated
		
		add286.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain258::Gain is automated
		gain258.setParameterT(1, 20.); // core::gain::Smoothing
		gain258.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch64::Index is automated
		
		midi_cc67.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc67.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc67.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add415::Value is automated
		
		midi_cc68.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc68.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc68.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add416::Value is automated
		
		midi_cc69.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc69.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc69.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add417::Value is automated
		
		midi_cc70.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc70.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc70.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add418::Value is automated
		
		; // add419::Value is automated
		
		; // add420::Value is automated
		
		; // add421::Value is automated
		
		;                              // gain259::Gain is automated
		gain259.setParameterT(1, 20.); // core::gain::Smoothing
		gain259.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma23::Value is automated
		; // pma23::Multiply is automated
		; // pma23::Add is automated
		
		sliderbank20.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable71.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add287::Value is automated
		
		;                              // gain260::Gain is automated
		gain260.setParameterT(1, 20.); // core::gain::Smoothing
		gain260.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable72.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add288::Value is automated
		
		;                              // gain261::Gain is automated
		gain261.setParameterT(1, 20.); // core::gain::Smoothing
		gain261.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable73.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add289::Value is automated
		
		;                              // gain262::Gain is automated
		gain262.setParameterT(1, 20.); // core::gain::Smoothing
		gain262.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable74.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add290::Value is automated
		
		;                              // gain263::Gain is automated
		gain263.setParameterT(1, 20.); // core::gain::Smoothing
		gain263.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add291::Value is automated
		
		;                              // gain264::Gain is automated
		gain264.setParameterT(1, 20.); // core::gain::Smoothing
		gain264.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add292::Value is automated
		
		;                              // gain265::Gain is automated
		gain265.setParameterT(1, 20.); // core::gain::Smoothing
		gain265.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch65::Index is automated
		
		; // add293::Value is automated
		
		; // add294::Value is automated
		
		; // add295::Value is automated
		
		; // add296::Value is automated
		
		add297.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain266::Gain is automated
		gain266.setParameterT(1, 20.); // core::gain::Smoothing
		gain266.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch66::Index is automated
		
		midi_cc71.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc71.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc71.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add422::Value is automated
		
		midi_cc72.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc72.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc72.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add423::Value is automated
		
		midi_cc73.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc73.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc73.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add424::Value is automated
		
		midi_cc74.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc74.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc74.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add425::Value is automated
		
		; // add426::Value is automated
		
		; // add427::Value is automated
		
		; // add428::Value is automated
		
		;                              // gain267::Gain is automated
		gain267.setParameterT(1, 20.); // core::gain::Smoothing
		gain267.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma24::Value is automated
		; // pma24::Multiply is automated
		; // pma24::Add is automated
		
		sliderbank21.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable75.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add298::Value is automated
		
		;                              // gain268::Gain is automated
		gain268.setParameterT(1, 20.); // core::gain::Smoothing
		gain268.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable76.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add299::Value is automated
		
		;                              // gain269::Gain is automated
		gain269.setParameterT(1, 20.); // core::gain::Smoothing
		gain269.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable77.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add300::Value is automated
		
		;                              // gain270::Gain is automated
		gain270.setParameterT(1, 20.); // core::gain::Smoothing
		gain270.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable78.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add301::Value is automated
		
		;                              // gain271::Gain is automated
		gain271.setParameterT(1, 20.); // core::gain::Smoothing
		gain271.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add302::Value is automated
		
		;                              // gain272::Gain is automated
		gain272.setParameterT(1, 20.); // core::gain::Smoothing
		gain272.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add303::Value is automated
		
		;                              // gain273::Gain is automated
		gain273.setParameterT(1, 20.); // core::gain::Smoothing
		gain273.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch67::Index is automated
		
		; // add304::Value is automated
		
		; // add305::Value is automated
		
		; // add306::Value is automated
		
		; // add307::Value is automated
		
		add308.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain274::Gain is automated
		gain274.setParameterT(1, 20.); // core::gain::Smoothing
		gain274.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch68::Index is automated
		
		midi_cc75.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc75.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc75.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add429::Value is automated
		
		midi_cc76.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc76.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc76.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add430::Value is automated
		
		midi_cc77.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc77.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc77.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add431::Value is automated
		
		midi_cc78.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc78.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc78.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add432::Value is automated
		
		; // add433::Value is automated
		
		; // add434::Value is automated
		
		; // add435::Value is automated
		
		;                              // gain275::Gain is automated
		gain275.setParameterT(1, 20.); // core::gain::Smoothing
		gain275.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma25::Value is automated
		; // pma25::Multiply is automated
		; // pma25::Add is automated
		
		sliderbank22.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable79.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add309::Value is automated
		
		;                              // gain276::Gain is automated
		gain276.setParameterT(1, 20.); // core::gain::Smoothing
		gain276.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable80.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add310::Value is automated
		
		;                              // gain277::Gain is automated
		gain277.setParameterT(1, 20.); // core::gain::Smoothing
		gain277.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable81.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add311::Value is automated
		
		;                              // gain278::Gain is automated
		gain278.setParameterT(1, 20.); // core::gain::Smoothing
		gain278.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable82.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add312::Value is automated
		
		;                              // gain279::Gain is automated
		gain279.setParameterT(1, 20.); // core::gain::Smoothing
		gain279.setParameterT(2, 0.);  // core::gain::ResetValue
		
		add313.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain280::Gain is automated
		gain280.setParameterT(1, 20.); // core::gain::Smoothing
		gain280.setParameterT(2, 0.);  // core::gain::ResetValue
		
		add314.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain281::Gain is automated
		gain281.setParameterT(1, 20.); // core::gain::Smoothing
		gain281.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch69::Index is automated
		
		; // add315::Value is automated
		
		; // add316::Value is automated
		
		; // add317::Value is automated
		
		; // add318::Value is automated
		
		add319.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain282::Gain is automated
		gain282.setParameterT(1, 20.); // core::gain::Smoothing
		gain282.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch70::Index is automated
		
		midi_cc79.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc79.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc79.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add436::Value is automated
		
		midi_cc80.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc80.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc80.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add437::Value is automated
		
		midi_cc81.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc81.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc81.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add438::Value is automated
		
		midi_cc82.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc82.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc82.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add439::Value is automated
		
		; // add440::Value is automated
		
		; // add441::Value is automated
		
		; // add442::Value is automated
		
		;                              // gain283::Gain is automated
		gain283.setParameterT(1, 20.); // core::gain::Smoothing
		gain283.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma26::Value is automated
		; // pma26::Multiply is automated
		; // pma26::Add is automated
		
		clear23.setParameterT(0, 0.); // math::clear::Value
		
		; // branch38::Index is automated
		
		receive7.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive8.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive9.setParameterT(0, 1.); // routing::receive::Feedback
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 0.);    // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                               // minmax2::Value is automated
		minmax2.setParameterT(1, -24.); // control::minmax::Minimum
		minmax2.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax2.setParameterT(3, 1.);   // control::minmax::Skew
		;                               // minmax2::Step is automated
		minmax2.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // converter::Value is automated
		
		;                                // tempo_sync::Tempo is automated
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 0.); // control::tempo_sync::Enabled
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
		
		phasor_fm1.setParameterT(0, 1.); // core::phasor_fm::Gate
		;                                // phasor_fm1::Frequency is automated
		phasor_fm1.setParameterT(2, 0.); // core::phasor_fm::FreqRatio
		phasor_fm1.setParameterT(3, 0.); // core::phasor_fm::Phase
		
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
		
		gain12.setParameterT(0, -6);  // core::gain::Gain
		gain12.setParameterT(1, 20.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.);  // core::gain::ResetValue
		
		one_pole1.setParameterT(0, 50.1457); // filters::one_pole::Frequency
		one_pole1.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear19.setParameterT(0, 0.); // math::clear::Value
		
		clear22.setParameterT(0, 0.); // math::clear::Value
		
		; // branch27::Index is automated
		
		receive6.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive5.setParameterT(0, 1.); // routing::receive::Feedback
		
		receive4.setParameterT(0, 1.); // routing::receive::Feedback
		
		;                             // gain11::Gain is automated
		gain11.setParameterT(1, 20.); // core::gain::Smoothing
		gain11.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                               // minmax3::Value is automated
		minmax3.setParameterT(1, -24.); // control::minmax::Minimum
		minmax3.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax3.setParameterT(3, 1.);   // control::minmax::Skew
		;                               // minmax3::Step is automated
		minmax3.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // converter1::Value is automated
		
		;                                 // tempo_sync1::Tempo is automated
		;                                 // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.); // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 0.); // control::tempo_sync::UnsyncedTime
		
		; // converter6::Value is automated
		
		; // branch7::Index is automated
		
		phasor_fm2.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm2.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                  // phasor_fm2::FreqRatio is automated
		phasor_fm2.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		phasor_fm4.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm4.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                  // phasor_fm4::FreqRatio is automated
		phasor_fm4.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		phasor_fm7.setParameterT(0, 1.); // core::phasor_fm::Gate
		;                                // phasor_fm7::Frequency is automated
		phasor_fm7.setParameterT(2, 1.); // core::phasor_fm::FreqRatio
		phasor_fm7.setParameterT(3, 0.); // core::phasor_fm::Phase
		
		pma7.setParameterT(0, 0.); // control::pma::Value
		pma7.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma7::Add is automated
		
		; // branch10::Index is automated
		
		; // xfader4::Value is automated
		
		sub2.setParameterT(0, 0.5); // math::sub::Value
		
		abs2.setParameterT(0, 1.); // math::abs::Value
		
		mul4.setParameterT(0, 2.); // math::mul::Value
		
		;                               // gain52::Gain is automated
		gain52.setParameterT(1, 19.1);  // core::gain::Smoothing
		gain52.setParameterT(2, -100.); // core::gain::ResetValue
		
		expr4.setParameterT(0, 1.); // math::expr::Value
		
		;                              // gain54::Gain is automated
		gain54.setParameterT(1, 19.8); // core::gain::Smoothing
		gain54.setParameterT(2, -22.); // core::gain::ResetValue
		
		;                              // gain55::Gain is automated
		gain55.setParameterT(1, 20.6); // core::gain::Smoothing
		gain55.setParameterT(2, -12.); // core::gain::ResetValue
		
		rect4.setParameterT(0, 1.); // math::rect::Value
		
		;                             // gain57::Gain is automated
		gain57.setParameterT(1, 20.); // core::gain::Smoothing
		gain57.setParameterT(2, 0.);  // core::gain::ResetValue
		
		fmod3.setParameterT(0, 1.); // math::fmod::Value
		
		mul5.setParameterT(0, 1.); // math::mul::Value
		
		pi10.setParameterT(0, 1.); // math::pi::Value
		
		;                              // gain60::Gain is automated
		gain60.setParameterT(1, 7);    // core::gain::Smoothing
		gain60.setParameterT(2, -12.); // core::gain::ResetValue
		
		; // expr11::Value is automated
		
		sin8.setParameterT(0, 1.); // math::sin::Value
		
		pi13.setParameterT(0, 0.5); // math::pi::Value
		
		sin2.setParameterT(0, 1.); // math::sin::Value
		
		;                              // gain62::Gain is automated
		gain62.setParameterT(1, 20.);  // core::gain::Smoothing
		gain62.setParameterT(2, -12.); // core::gain::ResetValue
		
		sin11.setParameterT(0, 1.); // math::sin::Value
		
		expr12.setParameterT(0, 1.); // math::expr::Value
		
		pi4.setParameterT(0, 0.465825); // math::pi::Value
		
		; // phase_delay2::Frequency is automated
		
		;                              // gain64::Gain is automated
		gain64.setParameterT(1, 20.);  // core::gain::Smoothing
		gain64.setParameterT(2, -12.); // core::gain::ResetValue
		
		expr13.setParameterT(0, 0.479197); // math::expr::Value
		
		sin12.setParameterT(0, 1.); // math::sin::Value
		
		;                              // gain65::Gain is automated
		gain65.setParameterT(1, 10.8); // core::gain::Smoothing
		gain65.setParameterT(2, -11.); // core::gain::ResetValue
		
		pi14.setParameterT(0, 1.); // math::pi::Value
		
		one_pole2.setParameterT(0, 50.1457); // filters::one_pole::Frequency
		one_pole2.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole2.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole2.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole2.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole2.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		gain73.setParameterT(0, -6);  // core::gain::Gain
		gain73.setParameterT(1, 20.); // core::gain::Smoothing
		gain73.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                            // gain5::Gain is automated
		gain5.setParameterT(1, 20.); // core::gain::Smoothing
		gain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear21.setParameterT(0, 0.); // math::clear::Value
		
		clear25.setParameterT(0, 0.); // math::clear::Value
		
		; // receive10::Feedback is automated
		
		;                              // gain8::Gain is automated
		gain8.setParameterT(1, 0.);    // core::gain::Smoothing
		gain8.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // receive11::Feedback is automated
		
		;                              // gain6::Gain is automated
		gain6.setParameterT(1, 0.);    // core::gain::Smoothing
		gain6.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch13::Index is automated
		
		;                                   // tempo_sync2::Tempo is automated
		;                                   // tempo_sync2::Multiplier is automated
		tempo_sync2.setParameterT(2, 10.);  // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		;                                // clock_ramp::Tempo is automated
		;                                // clock_ramp::Multiplier is automated
		clock_ramp.setParameterT(2, 1.); // core::clock_ramp::AddToSignal
		clock_ramp.setParameterT(3, 1.); // core::clock_ramp::UpdateMode
		clock_ramp.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		clear10.setParameterT(0, 0.); // math::clear::Value
		
		; // branch14::Index is automated
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                  // input_toggle::Value2 is automated
		
		;                            // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		;                            // ahdsr::Hold is automated
		;                            // ahdsr::Decay is automated
		;                            // ahdsr::Sustain is automated
		;                            // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		;                            // ahdsr::Gate is automated
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		; // add2::Value is automated
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table1::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // add22::Value is automated
		
		; // branch17::Index is automated
		
		;                                   // tempo_sync5::Tempo is automated
		;                                   // tempo_sync5::Multiplier is automated
		tempo_sync5.setParameterT(2, 10.);  // control::tempo_sync::Enabled
		tempo_sync5.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp4::PeriodTime is automated
		;                           // ramp4::LoopStart is automated
		ramp4.setParameterT(2, 1.); // core::ramp::Gate
		
		;                                 // clock_ramp3::Tempo is automated
		;                                 // clock_ramp3::Multiplier is automated
		clock_ramp3.setParameterT(2, 1.); // core::clock_ramp::AddToSignal
		clock_ramp3.setParameterT(3, 1.); // core::clock_ramp::UpdateMode
		clock_ramp3.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // branch18::Index is automated
		
		;                                   // input_toggle2::Input is automated
		input_toggle2.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle2::Value2 is automated
		
		;                             // ahdsr6::Attack is automated
		ahdsr6.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		;                             // ahdsr6::Hold is automated
		;                             // ahdsr6::Decay is automated
		;                             // ahdsr6::Sustain is automated
		;                             // ahdsr6::Release is automated
		ahdsr6.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr6.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		;                             // ahdsr6::Gate is automated
		
		clear16.setParameterT(0, 0.); // math::clear::Value
		
		; // add100::Value is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table8::Value is automated
		
		clear18.setParameterT(0, 0.); // math::clear::Value
		
		; // add102::Value is automated
		
		;                                   // tempo_sync6::Tempo is automated
		;                                   // tempo_sync6::Multiplier is automated
		tempo_sync6.setParameterT(2, 10.);  // control::tempo_sync::Enabled
		tempo_sync6.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp5::PeriodTime is automated
		;                           // ramp5::LoopStart is automated
		ramp5.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch36::Index is automated
		
		mod_inv.setParameterT(0, 0.); // math::mod_inv::Value
		
		clear26.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // tempo_sync9::Tempo is automated
		;                                   // tempo_sync9::Multiplier is automated
		tempo_sync9.setParameterT(2, 10.);  // control::tempo_sync::Enabled
		tempo_sync9.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp8::PeriodTime is automated
		;                           // ramp8::LoopStart is automated
		ramp8.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch89::Index is automated
		
		mod_inv3.setParameterT(0, 0.); // math::mod_inv::Value
		
		clear32.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // tempo_sync8::Tempo is automated
		;                                   // tempo_sync8::Multiplier is automated
		tempo_sync8.setParameterT(2, 10.);  // control::tempo_sync::Enabled
		tempo_sync8.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp7::PeriodTime is automated
		;                           // ramp7::LoopStart is automated
		ramp7.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch46::Index is automated
		
		mod_inv2.setParameterT(0, 0.); // math::mod_inv::Value
		
		clear31.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // tempo_sync7::Tempo is automated
		;                                   // tempo_sync7::Multiplier is automated
		tempo_sync7.setParameterT(2, 10.);  // control::tempo_sync::Enabled
		tempo_sync7.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp6::PeriodTime is automated
		;                           // ramp6::LoopStart is automated
		ramp6.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch37::Index is automated
		
		mod_inv1.setParameterT(0, 0.); // math::mod_inv::Value
		
		clear30.setParameterT(0, 0.); // math::clear::Value
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		;                                // one_pole::Mode is automated
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch39::Index is automated
		
		; // xfader1::Value is automated
		
		; // xfader5::Value is automated
		
		; // xfader6::Value is automated
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
		sliderbank13.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable43.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add179::Value is automated
		
		;                              // gain124::Gain is automated
		gain124.setParameterT(1, 20.); // core::gain::Smoothing
		gain124.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable44.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add180::Value is automated
		
		;                              // gain125::Gain is automated
		gain125.setParameterT(1, 20.); // core::gain::Smoothing
		gain125.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable45.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add181::Value is automated
		
		;                              // gain126::Gain is automated
		gain126.setParameterT(1, 20.); // core::gain::Smoothing
		gain126.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable46.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add182::Value is automated
		
		;                              // gain127::Gain is automated
		gain127.setParameterT(1, 20.); // core::gain::Smoothing
		gain127.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add183::Value is automated
		
		;                              // gain128::Gain is automated
		gain128.setParameterT(1, 20.); // core::gain::Smoothing
		gain128.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add184::Value is automated
		
		;                              // gain129::Gain is automated
		gain129.setParameterT(1, 20.); // core::gain::Smoothing
		gain129.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch51::Index is automated
		
		; // add185::Value is automated
		
		; // add186::Value is automated
		
		; // add187::Value is automated
		
		; // add188::Value is automated
		
		add189.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain130::Gain is automated
		gain130.setParameterT(1, 20.); // core::gain::Smoothing
		gain130.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch52::Index is automated
		
		midi_cc43.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc43.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc43.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add190::Value is automated
		
		midi_cc44.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc44.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc44.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add191::Value is automated
		
		midi_cc45.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc45.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc45.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add192::Value is automated
		
		midi_cc46.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc46.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc46.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add193::Value is automated
		
		; // add194::Value is automated
		
		; // add195::Value is automated
		
		; // add196::Value is automated
		
		;                              // gain131::Gain is automated
		gain131.setParameterT(1, 20.); // core::gain::Smoothing
		gain131.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // pma17::Value is automated
		; // pma17::Multiply is automated
		; // pma17::Add is automated
		
		; // branch21::Index is automated
		
		; // add213::Value is automated
		
		;                             // minmax6::Value is automated
		minmax6.setParameterT(1, 0.); // control::minmax::Minimum
		minmax6.setParameterT(2, 1.); // control::minmax::Maximum
		minmax6.setParameterT(3, 1.); // control::minmax::Skew
		minmax6.setParameterT(4, 0.); // control::minmax::Step
		minmax6.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add214::Value is automated
		
		;                             // minmax7::Value is automated
		minmax7.setParameterT(1, 0.); // control::minmax::Minimum
		minmax7.setParameterT(2, 1.); // control::minmax::Maximum
		minmax7.setParameterT(3, 1.); // control::minmax::Skew
		minmax7.setParameterT(4, 0.); // control::minmax::Step
		minmax7.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add215::Value is automated
		
		;                                       // minmax14::Value is automated
		minmax14.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax14.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax14.setParameterT(3, 1.);          // control::minmax::Skew
		minmax14.setParameterT(4, 0.000976562); // control::minmax::Step
		minmax14.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add216::Value is automated
		
		;                                      // minmax11::Value is automated
		minmax11.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax11.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax11.setParameterT(3, 1.);         // control::minmax::Skew
		minmax11.setParameterT(4, 0.00195312); // control::minmax::Step
		minmax11.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add217::Value is automated
		
		;                                     // minmax15::Value is automated
		minmax15.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax15.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax15.setParameterT(3, 1.);        // control::minmax::Skew
		minmax15.setParameterT(4, 0.0117188); // control::minmax::Step
		minmax15.setParameterT(5, 0.);        // control::minmax::Polarity
		
		; // add218::Value is automated
		
		;                              // minmax16::Value is automated
		minmax16.setParameterT(1, 0.); // control::minmax::Minimum
		minmax16.setParameterT(2, 1.); // control::minmax::Maximum
		minmax16.setParameterT(3, 1.); // control::minmax::Skew
		minmax16.setParameterT(4, 0.); // control::minmax::Step
		minmax16.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add219::Value is automated
		
		;                                   // minmax17::Value is automated
		minmax17.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax17.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax17.setParameterT(3, 1.);      // control::minmax::Skew
		minmax17.setParameterT(4, 0.01562); // control::minmax::Step
		minmax17.setParameterT(5, 0.);      // control::minmax::Polarity
		
		; // add220::Value is automated
		
		;                                // minmax18::Value is automated
		minmax18.setParameterT(1, 0.);   // control::minmax::Minimum
		minmax18.setParameterT(2, 1.);   // control::minmax::Maximum
		minmax18.setParameterT(3, 1.);   // control::minmax::Skew
		minmax18.setParameterT(4, 0.03); // control::minmax::Step
		minmax18.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add221::Value is automated
		
		; // cable_table5::Value is automated
		
		; // pma33::Value is automated
		; // pma33::Multiply is automated
		; // pma33::Add is automated
		
		; // branch32::Index is automated
		
		; // add551::Value is automated
		
		;                              // minmax30::Value is automated
		minmax30.setParameterT(1, 0.); // control::minmax::Minimum
		minmax30.setParameterT(2, 1.); // control::minmax::Maximum
		minmax30.setParameterT(3, 1.); // control::minmax::Skew
		minmax30.setParameterT(4, 0.); // control::minmax::Step
		minmax30.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add552::Value is automated
		
		;                              // minmax31::Value is automated
		minmax31.setParameterT(1, 0.); // control::minmax::Minimum
		minmax31.setParameterT(2, 1.); // control::minmax::Maximum
		minmax31.setParameterT(3, 1.); // control::minmax::Skew
		minmax31.setParameterT(4, 0.); // control::minmax::Step
		minmax31.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add553::Value is automated
		
		;                                       // minmax32::Value is automated
		minmax32.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax32.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax32.setParameterT(3, 1.);          // control::minmax::Skew
		minmax32.setParameterT(4, 0.000976562); // control::minmax::Step
		minmax32.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add554::Value is automated
		
		;                                      // minmax33::Value is automated
		minmax33.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax33.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax33.setParameterT(3, 1.);         // control::minmax::Skew
		minmax33.setParameterT(4, 0.00195312); // control::minmax::Step
		minmax33.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add555::Value is automated
		
		;                                     // minmax34::Value is automated
		minmax34.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax34.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax34.setParameterT(3, 1.);        // control::minmax::Skew
		minmax34.setParameterT(4, 0.0117188); // control::minmax::Step
		minmax34.setParameterT(5, 0.);        // control::minmax::Polarity
		
		; // add556::Value is automated
		
		;                              // minmax35::Value is automated
		minmax35.setParameterT(1, 0.); // control::minmax::Minimum
		minmax35.setParameterT(2, 1.); // control::minmax::Maximum
		minmax35.setParameterT(3, 1.); // control::minmax::Skew
		minmax35.setParameterT(4, 0.); // control::minmax::Step
		minmax35.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add557::Value is automated
		
		;                                   // minmax36::Value is automated
		minmax36.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax36.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax36.setParameterT(3, 1.);      // control::minmax::Skew
		minmax36.setParameterT(4, 0.01562); // control::minmax::Step
		minmax36.setParameterT(5, 0.);      // control::minmax::Polarity
		
		; // add558::Value is automated
		
		;                                // minmax37::Value is automated
		minmax37.setParameterT(1, 0.);   // control::minmax::Minimum
		minmax37.setParameterT(2, 1.);   // control::minmax::Maximum
		minmax37.setParameterT(3, 1.);   // control::minmax::Skew
		minmax37.setParameterT(4, 0.03); // control::minmax::Step
		minmax37.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add559::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table9::Value is automated
		
		; // pma32::Value is automated
		; // pma32::Multiply is automated
		; // pma32::Add is automated
		
		; // branch31::Index is automated
		
		; // add524::Value is automated
		
		;                              // minmax10::Value is automated
		minmax10.setParameterT(1, 0.); // control::minmax::Minimum
		minmax10.setParameterT(2, 1.); // control::minmax::Maximum
		minmax10.setParameterT(3, 1.); // control::minmax::Skew
		minmax10.setParameterT(4, 0.); // control::minmax::Step
		minmax10.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add525::Value is automated
		
		;                              // minmax13::Value is automated
		minmax13.setParameterT(1, 0.); // control::minmax::Minimum
		minmax13.setParameterT(2, 1.); // control::minmax::Maximum
		minmax13.setParameterT(3, 1.); // control::minmax::Skew
		minmax13.setParameterT(4, 0.); // control::minmax::Step
		minmax13.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add526::Value is automated
		
		;                                       // minmax24::Value is automated
		minmax24.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax24.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax24.setParameterT(3, 1.);          // control::minmax::Skew
		minmax24.setParameterT(4, 0.000976562); // control::minmax::Step
		minmax24.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add527::Value is automated
		
		;                                      // minmax25::Value is automated
		minmax25.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax25.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax25.setParameterT(3, 1.);         // control::minmax::Skew
		minmax25.setParameterT(4, 0.00195312); // control::minmax::Step
		minmax25.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add528::Value is automated
		
		;                                     // minmax26::Value is automated
		minmax26.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax26.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax26.setParameterT(3, 1.);        // control::minmax::Skew
		minmax26.setParameterT(4, 0.0117188); // control::minmax::Step
		minmax26.setParameterT(5, 0.);        // control::minmax::Polarity
		
		; // add529::Value is automated
		
		;                              // minmax27::Value is automated
		minmax27.setParameterT(1, 0.); // control::minmax::Minimum
		minmax27.setParameterT(2, 1.); // control::minmax::Maximum
		minmax27.setParameterT(3, 1.); // control::minmax::Skew
		minmax27.setParameterT(4, 0.); // control::minmax::Step
		minmax27.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add530::Value is automated
		
		;                                   // minmax28::Value is automated
		minmax28.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax28.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax28.setParameterT(3, 1.);      // control::minmax::Skew
		minmax28.setParameterT(4, 0.01562); // control::minmax::Step
		minmax28.setParameterT(5, 0.);      // control::minmax::Polarity
		
		; // add531::Value is automated
		
		;                                // minmax29::Value is automated
		minmax29.setParameterT(1, 0.);   // control::minmax::Minimum
		minmax29.setParameterT(2, 1.);   // control::minmax::Maximum
		minmax29.setParameterT(3, 1.);   // control::minmax::Skew
		minmax29.setParameterT(4, 0.03); // control::minmax::Step
		minmax29.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add532::Value is automated
		
		; // cable_table7::Value is automated
		
		; // pma31::Value is automated
		; // pma31::Multiply is automated
		; // pma31::Add is automated
		
		; // branch30::Index is automated
		
		; // add497::Value is automated
		
		;                             // minmax8::Value is automated
		minmax8.setParameterT(1, 0.); // control::minmax::Minimum
		minmax8.setParameterT(2, 1.); // control::minmax::Maximum
		minmax8.setParameterT(3, 1.); // control::minmax::Skew
		minmax8.setParameterT(4, 0.); // control::minmax::Step
		minmax8.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add498::Value is automated
		
		;                             // minmax9::Value is automated
		minmax9.setParameterT(1, 0.); // control::minmax::Minimum
		minmax9.setParameterT(2, 1.); // control::minmax::Maximum
		minmax9.setParameterT(3, 1.); // control::minmax::Skew
		minmax9.setParameterT(4, 0.); // control::minmax::Step
		minmax9.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add499::Value is automated
		
		;                                       // minmax19::Value is automated
		minmax19.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax19.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax19.setParameterT(3, 1.);          // control::minmax::Skew
		minmax19.setParameterT(4, 0.000976562); // control::minmax::Step
		minmax19.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add500::Value is automated
		
		;                                      // minmax12::Value is automated
		minmax12.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax12.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax12.setParameterT(3, 1.);         // control::minmax::Skew
		minmax12.setParameterT(4, 0.00195312); // control::minmax::Step
		minmax12.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add501::Value is automated
		
		;                                     // minmax20::Value is automated
		minmax20.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax20.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax20.setParameterT(3, 1.);        // control::minmax::Skew
		minmax20.setParameterT(4, 0.0117188); // control::minmax::Step
		minmax20.setParameterT(5, 0.);        // control::minmax::Polarity
		
		; // add502::Value is automated
		
		;                              // minmax21::Value is automated
		minmax21.setParameterT(1, 0.); // control::minmax::Minimum
		minmax21.setParameterT(2, 1.); // control::minmax::Maximum
		minmax21.setParameterT(3, 1.); // control::minmax::Skew
		minmax21.setParameterT(4, 0.); // control::minmax::Step
		minmax21.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add503::Value is automated
		
		;                                   // minmax22::Value is automated
		minmax22.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax22.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax22.setParameterT(3, 1.);      // control::minmax::Skew
		minmax22.setParameterT(4, 0.01562); // control::minmax::Step
		minmax22.setParameterT(5, 0.);      // control::minmax::Polarity
		
		; // add504::Value is automated
		
		minmax23.setParameterT(0, 0.);   // control::minmax::Value
		;                                // minmax23::Minimum is automated
		minmax23.setParameterT(2, 1.);   // control::minmax::Maximum
		minmax23.setParameterT(3, 1.);   // control::minmax::Skew
		minmax23.setParameterT(4, 0.03); // control::minmax::Step
		minmax23.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add505::Value is automated
		
		; // cable_table6::Value is automated
		
		; // pma34::Value is automated
		; // pma34::Multiply is automated
		; // pma34::Add is automated
		
		; // branch33::Index is automated
		
		; // add578::Value is automated
		
		;                              // minmax38::Value is automated
		minmax38.setParameterT(1, 0.); // control::minmax::Minimum
		minmax38.setParameterT(2, 1.); // control::minmax::Maximum
		minmax38.setParameterT(3, 1.); // control::minmax::Skew
		minmax38.setParameterT(4, 0.); // control::minmax::Step
		minmax38.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add579::Value is automated
		
		;                              // minmax39::Value is automated
		minmax39.setParameterT(1, 0.); // control::minmax::Minimum
		minmax39.setParameterT(2, 1.); // control::minmax::Maximum
		minmax39.setParameterT(3, 1.); // control::minmax::Skew
		minmax39.setParameterT(4, 0.); // control::minmax::Step
		minmax39.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add580::Value is automated
		
		;                                       // minmax40::Value is automated
		minmax40.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax40.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax40.setParameterT(3, 1.);          // control::minmax::Skew
		minmax40.setParameterT(4, 0.000976562); // control::minmax::Step
		minmax40.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add581::Value is automated
		
		;                                      // minmax41::Value is automated
		minmax41.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax41.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax41.setParameterT(3, 1.);         // control::minmax::Skew
		minmax41.setParameterT(4, 0.00195312); // control::minmax::Step
		minmax41.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add582::Value is automated
		
		;                                     // minmax42::Value is automated
		minmax42.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax42.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax42.setParameterT(3, 1.);        // control::minmax::Skew
		minmax42.setParameterT(4, 0.0117188); // control::minmax::Step
		minmax42.setParameterT(5, 0.);        // control::minmax::Polarity
		
		; // add583::Value is automated
		
		;                              // minmax43::Value is automated
		minmax43.setParameterT(1, 0.); // control::minmax::Minimum
		minmax43.setParameterT(2, 1.); // control::minmax::Maximum
		minmax43.setParameterT(3, 1.); // control::minmax::Skew
		minmax43.setParameterT(4, 0.); // control::minmax::Step
		minmax43.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add584::Value is automated
		
		;                                   // minmax44::Value is automated
		minmax44.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax44.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax44.setParameterT(3, 1.);      // control::minmax::Skew
		minmax44.setParameterT(4, 0.01562); // control::minmax::Step
		minmax44.setParameterT(5, 0.);      // control::minmax::Polarity
		
		; // add585::Value is automated
		
		minmax45.setParameterT(0, 0.);   // control::minmax::Value
		;                                // minmax45::Minimum is automated
		minmax45.setParameterT(2, 1.);   // control::minmax::Maximum
		minmax45.setParameterT(3, 1.);   // control::minmax::Skew
		minmax45.setParameterT(4, 0.03); // control::minmax::Step
		minmax45.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add586::Value is automated
		
		; // cable_table10::Value is automated
		
		; // add222::Value is automated
		
		; // add463::Value is automated
		
		; // branch22::Index is automated
		
		file_player6.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 1.);      // core::file_player::Gate
		file_player6.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player6.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		file_player7.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player7.setParameterT(1, 1.);      // core::file_player::Gate
		file_player7.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player7.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		; // branch26::Index is automated
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 20.);   // core::gain::Smoothing
		gain4.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                               // gain10::Gain is automated
		gain10.setParameterT(1, 20.);   // core::gain::Smoothing
		gain10.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain9::Gain is automated
		gain9.setParameterT(1, 20.);   // core::gain::Smoothing
		gain9.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain7::Gain is automated
		gain7.setParameterT(1, 20.);   // core::gain::Smoothing
		gain7.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // add474::Value is automated
		
		; // add475::Value is automated
		
		; // branch40::Index is automated
		
		file_player8.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player8.setParameterT(1, 1.);      // core::file_player::Gate
		file_player8.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player8.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		file_player9.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player9.setParameterT(1, 1.);      // core::file_player::Gate
		file_player9.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player9.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		; // branch41::Index is automated
		
		;                              // gain72::Gain is automated
		gain72.setParameterT(1, 20.);  // core::gain::Smoothing
		gain72.setParameterT(2, -38.); // core::gain::ResetValue
		
		;                               // gain89::Gain is automated
		gain89.setParameterT(1, 20.);   // core::gain::Smoothing
		gain89.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                               // gain90::Gain is automated
		gain90.setParameterT(1, 20.);   // core::gain::Smoothing
		gain90.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                               // gain91::Gain is automated
		gain91.setParameterT(1, 20.);   // core::gain::Smoothing
		gain91.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // add469::Value is automated
		
		; // add470::Value is automated
		
		; // branch42::Index is automated
		
		file_player10.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player10.setParameterT(1, 1.);      // core::file_player::Gate
		file_player10.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player10.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		file_player11.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player11.setParameterT(1, 1.);      // core::file_player::Gate
		file_player11.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player11.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		; // branch43::Index is automated
		
		;                             // gain92::Gain is automated
		gain92.setParameterT(1, 20.); // core::gain::Smoothing
		gain92.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                               // gain93::Gain is automated
		gain93.setParameterT(1, 20.);   // core::gain::Smoothing
		gain93.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                               // gain94::Gain is automated
		gain94.setParameterT(1, 20.);   // core::gain::Smoothing
		gain94.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                               // gain95::Gain is automated
		gain95.setParameterT(1, 20.);   // core::gain::Smoothing
		gain95.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // add464::Value is automated
		
		; // add465::Value is automated
		
		; // branch44::Index is automated
		
		file_player12.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player12.setParameterT(1, 1.);      // core::file_player::Gate
		file_player12.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player12.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		file_player13.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player13.setParameterT(1, 1.);      // core::file_player::Gate
		file_player13.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player13.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		; // branch45::Index is automated
		
		;                               // gain96::Gain is automated
		gain96.setParameterT(1, 20.);   // core::gain::Smoothing
		gain96.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                               // gain97::Gain is automated
		gain97.setParameterT(1, 20.);   // core::gain::Smoothing
		gain97.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // gain98::Gain is automated
		gain98.setParameterT(1, 20.); // core::gain::Smoothing
		gain98.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                               // gain99::Gain is automated
		gain99.setParameterT(1, 20.);   // core::gain::Smoothing
		gain99.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch23::Index is automated
		
		tanh2.setParameterT(0, 0.733733); // math::tanh::Value
		
		; // receive2::Feedback is automated
		
		; // faust3::shiftnote is automated
		; // faust3::windowsamples is automated
		; // faust3::xfadesamples is automated
		
		; // cable_table15::Value is automated
		
		; // receive3::Feedback is automated
		
		; // faust4::shiftfreq is automated
		; // faust4::windowsamples is automated
		; // faust4::xfadesamples is automated
		
		; // faust5::shiftnote is automated
		; // faust5::windowsamples is automated
		; // faust5::xfadesamples is automated
		
		clear20.setParameterT(0, 0.); // math::clear::Value
		
		clear24.setParameterT(0, 0.); // math::clear::Value
		
		receive13.setParameterT(0, 1.); // routing::receive::Feedback
		
		;                               // gain45::Gain is automated
		gain45.setParameterT(1, 20.);   // core::gain::Smoothing
		gain45.setParameterT(2, -100.); // core::gain::ResetValue
		
		receive14.setParameterT(0, 1.); // routing::receive::Feedback
		
		;                               // gain47::Gain is automated
		gain47.setParameterT(1, 20.);   // core::gain::Smoothing
		gain47.setParameterT(2, -100.); // core::gain::ResetValue
		
		receive15.setParameterT(0, 1.); // routing::receive::Feedback
		
		;                               // gain46::Gain is automated
		gain46.setParameterT(1, 20.);   // core::gain::Smoothing
		gain46.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // xfader::Value is automated
		
		;                             // gain1::Gain is automated
		gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		gain1.setParameterT(2, -12.); // core::gain::ResetValue
		
		; // branch::Index is automated
		
		; // faust::Q is automated
		; // faust::freq is automated
		
		; // faust1::Q is automated
		; // faust1::freq is automated
		
		; // faust2::Q is automated
		; // faust2::freq is automated
		
		; // faust6::Q is automated
		; // faust6::freq is automated
		
		; // cable_table::Value is automated
		
		; // faust8::aN is automated
		; // faust8::del is automated
		
		; // faust7::Q is automated
		; // faust7::freq is automated
		
		; // cable_table2::Value is automated
		
		; // faust10::Q is automated
		; // faust10::freq is automated
		
		; // faust9::aN is automated
		; // faust9::del is automated
		
		; // faust11::Q is automated
		; // faust11::freq is automated
		
		jpanner.setParameterT(0, -1.); // jdsp::jpanner::Pan
		jpanner.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // faust12::Q is automated
		; // faust12::freq is automated
		
		jpanner2.setParameterT(0, 1.); // jdsp::jpanner::Pan
		jpanner2.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		; // faust13::Q is automated
		; // faust13::freq is automated
		
		jpanner4.setParameterT(0, -1.); // jdsp::jpanner::Pan
		jpanner4.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // faust14::Q is automated
		; // faust14::freq is automated
		
		jpanner5.setParameterT(0, 10.); // jdsp::jpanner::Pan
		jpanner5.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // cable_table3::Value is automated
		
		; // faust15::aN is automated
		; // faust15::del is automated
		
		jpanner6.setParameterT(0, -1.); // jdsp::jpanner::Pan
		jpanner6.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // cable_table4::Value is automated
		
		; // faust16::aN is automated
		; // faust16::del is automated
		
		jpanner7.setParameterT(0, 10.); // jdsp::jpanner::Pan
		jpanner7.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		;                             // gain2::Gain is automated
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, -16.); // core::gain::ResetValue
		
		;                              // gain77::Gain is automated
		gain77.setParameterT(1, 5.6);  // core::gain::Smoothing
		gain77.setParameterT(2, -12.); // core::gain::ResetValue
		
		;                              // jpanner3::Pan is automated
		jpanner3.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 18.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 3.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.84);
		this->setParameterT(6, 0.97);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 0.159668);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 0.);
		this->setParameterT(13, -1.);
		this->setParameterT(14, 192.2);
		this->setParameterT(15, 20.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 2.);
		this->setParameterT(18, 0.);
		this->setParameterT(19, 0.67);
		this->setParameterT(20, 1.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 0.33);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 1180.);
		this->setParameterT(26, -8.2);
		this->setParameterT(27, 1.);
		this->setParameterT(28, 0.);
		this->setParameterT(29, 1644.97);
		this->setParameterT(30, 0.);
		this->setParameterT(31, 0.);
		this->setParameterT(32, 0.);
		this->setParameterT(33, 0.);
		this->setParameterT(34, 1.);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 1.);
		this->setParameterT(37, 1.);
		this->setParameterT(38, 1.);
		this->setParameterT(39, 0.82);
		this->setParameterT(40, 0.);
		this->setParameterT(41, 0.);
		this->setParameterT(42, 10386.);
		this->setParameterT(43, 0.);
		this->setParameterT(44, 20.);
		this->setParameterT(45, 0.);
		this->setParameterT(46, 1.);
		this->setParameterT(47, 1.);
		this->setParameterT(48, 1.);
		this->setParameterT(49, 1.);
		this->setParameterT(50, 1.);
		this->setParameterT(51, 0.8);
		this->setParameterT(52, 1.49012e-06);
		this->setParameterT(53, 1.);
		this->setParameterT(54, 0.85);
		this->setParameterT(55, 0.);
		this->setParameterT(56, 0.);
		this->setParameterT(57, 10000.);
		this->setParameterT(58, 1.);
		this->setParameterT(59, 0.);
		this->setParameterT(60, 0.);
		this->setParameterT(61, 0.);
		this->setParameterT(62, 17.);
		this->setParameterT(63, 0.);
		this->setParameterT(64, 0.);
		this->setParameterT(65, 0.);
		this->setParameterT(66, 0.);
		this->setParameterT(67, 0.);
		this->setParameterT(68, 0.);
		this->setParameterT(69, 11.);
		this->setParameterT(70, 0.);
		this->setParameterT(71, 1.);
		this->setParameterT(72, 1.);
		this->setParameterT(73, 1.);
		this->setParameterT(74, 2.);
		this->setParameterT(75, 1.);
		this->setParameterT(76, 4.);
		this->setParameterT(77, 2.);
		this->setParameterT(78, 2.);
		this->setParameterT(79, 1.);
		this->setParameterT(80, 0.868531);
		this->setParameterT(81, 0.);
		this->setParameterT(82, 0.);
		this->setParameterT(83, 1.);
		this->setParameterT(84, 1.);
		this->setParameterT(85, 1.);
		this->setParameterT(86, 0.);
		this->setParameterT(87, 1.);
		this->setParameterT(88, 1.);
		this->setParameterT(89, 1.);
		this->setParameterT(90, 2.);
		this->setParameterT(91, 1.);
		this->setParameterT(92, 2.);
		this->setParameterT(93, 1.);
		this->setParameterT(94, 0.);
		this->setParameterT(95, 0.);
		this->setParameterT(96, 1.);
		this->setParameterT(97, 1.);
		this->setParameterT(98, 1.);
		this->setParameterT(99, 1.);
		this->setParameterT(100, 0.42);
		this->setParameterT(101, 0.);
		this->setParameterT(102, 0.);
		this->setParameterT(103, 0.);
		this->setParameterT(104, 3.);
		this->setParameterT(105, 1.);
		this->setParameterT(106, 1.);
		this->setParameterT(107, 1.);
		this->setParameterT(108, 1.);
		this->setParameterT(109, 1.);
		this->setParameterT(110, 1.);
		this->setParameterT(111, 0.);
		this->setParameterT(112, 0.);
		this->setParameterT(113, 1.);
		this->setParameterT(114, 1.);
		this->setParameterT(115, 1.);
		this->setParameterT(116, 0.48);
		this->setParameterT(117, 0.5);
		this->setParameterT(118, 0.);
		this->setParameterT(119, -24.);
		this->setParameterT(120, 1.);
		this->setParameterT(121, 1.);
		this->setParameterT(122, 0.);
		this->setParameterT(123, 0.);
		this->setParameterT(124, 0.);
		this->setParameterT(125, 0.);
		this->setParameterT(126, 0.);
		this->setParameterT(127, 0.);
		this->setParameterT(128, 0.);
		this->setParameterT(129, 0.);
		this->setParameterT(130, 0.);
		this->setParameterT(131, 0.);
		this->setParameterT(132, 0.);
		this->setParameterT(133, 0.243164);
		this->setParameterT(134, 0.);
		this->setParameterT(135, 0.);
		this->setParameterT(136, 4.);
		this->setParameterT(137, 16.);
		this->setParameterT(138, 0.);
		this->setParameterT(139, 0.);
		this->setParameterT(140, 0.);
		this->setParameterT(141, 0.);
		this->setParameterT(142, 16.);
		this->setParameterT(143, 12.);
		this->setParameterT(144, 0.);
		this->setParameterT(145, 0.);
		this->setParameterT(146, 0.);
		this->setParameterT(147, 0.);
		this->setParameterT(148, 0.);
		this->setParameterT(149, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable14_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable5_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable15_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable18_t<NV>
		this->getT(0).getT(1).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable19_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable4_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable12_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable13_t<NV>
		this->getT(0).getT(2).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable25_t<NV>
		this->getT(0).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable6_t<NV>
		this->getT(0).getT(3).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable16_t<NV>
		this->getT(0).getT(3).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable17_t<NV>
		this->getT(0).getT(3).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable26_t<NV>
		this->getT(0).getT(4).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable7_t<NV>
		this->getT(0).getT(4).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable24_t<NV>
		this->getT(0).getT(4).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable27_t<NV>
		this->getT(0).getT(4).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable30_t<NV>
		this->getT(0).getT(5).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable39_t<NV>
		this->getT(0).getT(5).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable40_t<NV>
		this->getT(0).getT(5).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable41_t<NV>
		this->getT(0).getT(5).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable42_t<NV>
		this->getT(0).getT(6).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable35_t<NV>
		this->getT(0).getT(6).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable36_t<NV>
		this->getT(0).getT(6).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable37_t<NV>
		this->getT(0).getT(6).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable38_t<NV>
		this->getT(0).getT(7).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable47_t<NV>
		this->getT(0).getT(7).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable48_t<NV>
		this->getT(0).getT(7).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable49_t<NV>
		this->getT(0).getT(7).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable50_t<NV>
		this->getT(0).getT(8).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable51_t<NV>
		this->getT(0).getT(8).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable52_t<NV>
		this->getT(0).getT(8).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable53_t<NV>
		this->getT(0).getT(8).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable54_t<NV>
		this->getT(0).getT(9).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable55_t<NV>
		this->getT(0).getT(9).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable56_t<NV>
		this->getT(0).getT(9).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable57_t<NV>
		this->getT(0).getT(9).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable58_t<NV>
		this->getT(0).getT(10).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable59_t<NV>
		this->getT(0).getT(10).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable60_t<NV>
		this->getT(0).getT(10).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable61_t<NV>
		this->getT(0).getT(10).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable62_t<NV>
		this->getT(0).getT(11).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable63_t<NV>
		this->getT(0).getT(11).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable64_t<NV>
		this->getT(0).getT(11).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable65_t<NV>
		this->getT(0).getT(11).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable66_t<NV>
		this->getT(0).getT(12).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable67_t<NV>
		this->getT(0).getT(12).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable68_t<NV>
		this->getT(0).getT(12).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable69_t<NV>
		this->getT(0).getT(12).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable70_t<NV>
		this->getT(0).getT(13).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable71_t<NV>
		this->getT(0).getT(13).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable72_t<NV>
		this->getT(0).getT(13).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable73_t<NV>
		this->getT(0).getT(13).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable74_t<NV>
		this->getT(0).getT(14).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable75_t<NV>
		this->getT(0).getT(14).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable76_t<NV>
		this->getT(0).getT(14).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable77_t<NV>
		this->getT(0).getT(14).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable78_t<NV>
		this->getT(0).getT(15).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable79_t<NV>
		this->getT(0).getT(15).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable80_t<NV>
		this->getT(0).getT(15).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable81_t<NV>
		this->getT(0).getT(15).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable82_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::global_cable43_t<NV>
        getT(1).getT(2).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).  // osc1_impl::global_cable44_t<NV>
        getT(1).getT(2).getT(0).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).  // osc1_impl::global_cable45_t<NV>
        getT(1).getT(2).getT(0).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).  // osc1_impl::global_cable46_t<NV>
        getT(1).getT(2).getT(0).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index);                                 // osc1_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(4).getT(2).setExternalData(b, index);                         // osc1_impl::peak_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank5_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);                                 // osc1_impl::peak5_t<NV>
		this->getT(0).getT(1).getT(4).getT(2).setExternalData(b, index);                         // osc1_impl::peak1_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank4_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index);                                 // osc1_impl::peak4_t<NV>
		this->getT(0).getT(3).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank6_t<NV>
		this->getT(0).getT(3).getT(2).setExternalData(b, index);                                 // osc1_impl::peak6_t<NV>
		this->getT(0).getT(4).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank7_t<NV>
		this->getT(0).getT(4).getT(2).setExternalData(b, index);                                 // osc1_impl::peak11_t<NV>
		this->getT(0).getT(5).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank12_t<NV>
		this->getT(0).getT(5).getT(2).setExternalData(b, index);                                 // osc1_impl::peak19_t<NV>
		this->getT(0).getT(6).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank11_t<NV>
		this->getT(0).getT(6).getT(2).setExternalData(b, index);                                 // osc1_impl::peak13_t<NV>
		this->getT(0).getT(7).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank14_t<NV>
		this->getT(0).getT(7).getT(2).setExternalData(b, index);                                 // osc1_impl::peak34_t<NV>
		this->getT(0).getT(8).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank15_t<NV>
		this->getT(0).getT(8).getT(2).setExternalData(b, index);                                 // osc1_impl::peak35_t<NV>
		this->getT(0).getT(9).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank16_t<NV>
		this->getT(0).getT(9).getT(2).setExternalData(b, index);                                 // osc1_impl::peak36_t<NV>
		this->getT(0).getT(10).getT(0).setExternalData(b, index);                                // osc1_impl::sliderbank17_t<NV>
		this->getT(0).getT(10).getT(2).setExternalData(b, index);                                // osc1_impl::peak_unscaled_t<NV>
		this->getT(0).getT(10).getT(3).setExternalData(b, index);                                // osc1_impl::peak37_t
		this->getT(0).getT(11).getT(0).setExternalData(b, index);                                // osc1_impl::sliderbank18_t<NV>
		this->getT(0).getT(11).getT(2).setExternalData(b, index);                                // osc1_impl::peak38_t<NV>
		this->getT(0).getT(12).getT(0).setExternalData(b, index);                                // osc1_impl::sliderbank19_t<NV>
		this->getT(0).getT(12).getT(2).setExternalData(b, index);                                // osc1_impl::peak39_t<NV>
		this->getT(0).getT(13).getT(0).setExternalData(b, index);                                // osc1_impl::sliderbank20_t<NV>
		this->getT(0).getT(13).getT(2).setExternalData(b, index);                                // osc1_impl::peak40_t<NV>
		this->getT(0).getT(14).getT(0).setExternalData(b, index);                                // osc1_impl::sliderbank21_t<NV>
		this->getT(0).getT(14).getT(2).setExternalData(b, index);                                // osc1_impl::peak41_t<NV>
		this->getT(0).getT(15).getT(0).setExternalData(b, index);                                // osc1_impl::sliderbank22_t<NV>
		this->getT(0).getT(15).getT(2).setExternalData(b, index);                                // osc1_impl::peak42_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);         // osc1_impl::peak8_t
		this->getT(1).getT(0).getT(0).getT(0).                                                   // osc1_impl::table5_t
        getT(0).getT(8).getT(6).getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(0).                                                   // osc1_impl::peak17_t<NV>
        getT(4).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).                                                   // osc1_impl::oscilloscope2_t
        getT(0).getT(7).getT(2).getT(4).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).                                                   // osc1_impl::table6_t
        getT(0).getT(7).getT(6).getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(1).getT(3).getT(0).setExternalData(b, index);         // osc1_impl::peak20_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::ramp_t<NV>
        getT(0).getT(0).getT(0).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::clock_ramp_t<NV>
        getT(0).getT(0).getT(0).getT(0).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak2_t<NV>
        getT(2).getT(0).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::ahdsr_t<NV>
        getT(0).getT(0).getT(0).getT(3).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::cable_table1_t<NV>
        getT(0).getT(0).getT(0).getT(3).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak7_t<NV>
        getT(2).getT(0).getT(0).getT(0).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::ramp4_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::clock_ramp3_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak14_t<NV>
        getT(2).getT(0).getT(0).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::ahdsr6_t<NV>
        getT(0).getT(0).getT(1).getT(3).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::cable_table8_t<NV>
        getT(0).getT(0).getT(1).getT(3).getT(1).
        getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak16_t<NV>
        getT(2).getT(0).getT(0).getT(1).
        getT(4).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::ramp5_t<NV>
        getT(0).getT(0).getT(2).getT(0).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak15_t<NV>
        getT(2).getT(0).getT(0).getT(2).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::ramp8_t<NV>
        getT(0).getT(0).getT(3).getT(0).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak49_t<NV>
        getT(2).getT(0).getT(0).getT(3).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::ramp7_t<NV>
        getT(0).getT(0).getT(4).getT(0).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak48_t<NV>
        getT(2).getT(0).getT(0).getT(4).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::ramp6_t<NV>
        getT(0).getT(0).getT(5).getT(0).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak47_t<NV>
        getT(2).getT(0).getT(0).getT(5).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::sliderbank_t<NV>
        getT(2).getT(1).getT(1).getT(3).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::sliderbank13_t<NV>
        getT(2).getT(1).getT(2).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).                                                   // osc1_impl::peak21_t<NV>
        getT(2).getT(1).getT(2).getT(0).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::peak18_t<NV>
        getT(1).getT(2).getT(0).getT(5).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::cable_table5_t
        getT(1).getT(2).getT(0).getT(5).getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::peak43_t<NV>
        getT(1).getT(2).getT(1).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::cable_table9_t
        getT(1).getT(2).getT(1).getT(1).getT(4).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::peak31_t<NV>
        getT(1).getT(2).getT(2).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::cable_table7_t
        getT(1).getT(2).getT(2).getT(1).getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::peak29_t<NV>
        getT(1).getT(2).getT(3).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::cable_table6_t
        getT(1).getT(2).getT(3).getT(1).getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::peak45_t<NV>
        getT(1).getT(2).getT(4).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::cable_table10_t
        getT(1).getT(2).getT(4).getT(1).getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::file_player6_t<NV>
        getT(1).getT(3).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::file_player7_t<NV>
        getT(1).getT(3).getT(0).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::file_player8_t<NV>
        getT(1).getT(3).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::file_player9_t<NV>
        getT(1).getT(3).getT(1).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::file_player10_t<NV>
        getT(1).getT(3).getT(2).getT(1).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::file_player11_t<NV>
        getT(1).getT(3).getT(2).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::file_player12_t<NV>
        getT(1).getT(3).getT(3).getT(1).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(2).                                           // osc1_impl::file_player13_t<NV>
        getT(1).getT(3).getT(3).getT(1).getT(1).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(2).getT(3).getT(2).getT(1).setExternalData(b, index); // osc1_impl::cable_table15_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(5).setExternalData(b, index);                 // osc1_impl::peak22_t<NV>
		this->getT(1).getT(0).getT(0).getT(3).getT(3).                                           // osc1_impl::cable_table_t<NV>
        getT(1).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(3).getT(3).                           // osc1_impl::cable_table2_t<NV>
        getT(1).getT(0).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(3).getT(3).                           // osc1_impl::cable_table3_t<NV>
        getT(1).getT(0).getT(0).getT(6).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(3).getT(3).                           // osc1_impl::cable_table4_t<NV>
        getT(1).getT(0).getT(0).getT(6).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(1).getT(0).getT(0).getT(3).getT(4).setExternalData(b, index); // osc1_impl::peak33_t<NV>
		this->getT(3).setExternalData(b, index);                                 // osc1_impl::oscilloscope_t
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


