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

namespace Files_impl
{
// ==============================| Node & Parameter type declarations |==============================

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
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV> using xfader1_c2 = xfader_c0<NV>;

template <int NV> using xfader1_c3 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, 
                                         xfader1_c1<NV>, 
                                         xfader1_c2<NV>, 
                                         xfader1_c3<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

template <int NV> using xfader5_c0 = xfader_c0<NV>;

template <int NV> using xfader5_c1 = xfader_c0<NV>;

template <int NV> using xfader5_c2 = xfader_c0<NV>;

template <int NV> using xfader5_c3 = xfader_c0<NV>;

template <int NV>
using xfader5_multimod = parameter::list<xfader5_c0<NV>, 
                                         xfader5_c1<NV>, 
                                         xfader5_c2<NV>, 
                                         xfader5_c3<NV>>;

template <int NV>
using xfader5_t = control::xfader<xfader5_multimod<NV>, faders::rms>;

template <int NV> using xfader6_c0 = xfader_c0<NV>;

template <int NV> using xfader6_c1 = xfader_c0<NV>;

template <int NV> using xfader6_c2 = xfader_c0<NV>;

template <int NV> using xfader6_c3 = xfader_c0<NV>;

template <int NV>
using xfader6_multimod = parameter::list<xfader6_c0<NV>, 
                                         xfader6_c1<NV>, 
                                         xfader6_c2<NV>, 
                                         xfader6_c3<NV>>;

template <int NV>
using xfader6_t = control::xfader<xfader6_multimod<NV>, faders::switcher>;

template <int NV> using sliderbank_c0 = xfader_c0<NV>;

template <int NV> using sliderbank_c1 = xfader_c0<NV>;

template <int NV> using sliderbank_c2 = xfader_c0<NV>;

template <int NV> using sliderbank_c3 = xfader_c0<NV>;

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

using global_cable51_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable51_t = routing::global_cable<global_cable51_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain275_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable51_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass65_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain275_t<NV>>>;

template <int NV>
using soft_bypass65_t = bypass::smoothed<20, soft_bypass65_t_<NV>>;
template <int NV>
using xfader71_c1 = parameter::bypass<soft_bypass65_t<NV>>;

template <int NV>
using xfader71_multimod = parameter::list<parameter::empty, xfader71_c1<NV>>;

template <int NV>
using xfader71_t = control::xfader<xfader71_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank15_c0_0 = xfader_c0<NV>;

DECLARE_PARAMETER_RANGE_SKEW(sliderbank15_c0_1Range, 
                             0., 
                             1., 
                             13.65);

template <int NV>
using sliderbank15_c0_1 = parameter::from0To1<xfader71_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank15_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank15_c0_0<NV>, 
                                         sliderbank15_c0_1<NV>>;

using global_cable52_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable52_t = routing::global_cable<global_cable52_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain276_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable52_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass73_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain276_t<NV>>>;

template <int NV>
using soft_bypass73_t = bypass::smoothed<20, soft_bypass73_t_<NV>>;
template <int NV>
using xfader79_c1 = parameter::bypass<soft_bypass73_t<NV>>;

template <int NV>
using xfader79_multimod = parameter::list<parameter::empty, xfader79_c1<NV>>;

template <int NV>
using xfader79_t = control::xfader<xfader79_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank15_c1_0 = xfader_c0<NV>;

template <int NV>
using sliderbank15_c1_1 = parameter::from0To1<xfader79_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank15_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank15_c1_0<NV>, 
                                         sliderbank15_c1_1<NV>>;

using soft_bypass72_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, core::empty>>;

using soft_bypass72_t = bypass::smoothed<20, soft_bypass72_t_>;
using xfader78_c1 = parameter::bypass<soft_bypass72_t>;

using xfader78_multimod = parameter::list<parameter::empty, xfader78_c1>;

using xfader78_t = control::xfader<xfader78_multimod, faders::switcher>;
template <int NV> using sliderbank15_c2_0 = xfader_c0<NV>;

using sliderbank15_c2_1 = parameter::from0To1<xfader78_t, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank15_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank15_c2_0<NV>, 
                                         sliderbank15_c2_1>;

using global_cable54_t_index = runtime_target::indexers::fix_hash<2333887>;

template <int NV>
using global_cable54_t = routing::global_cable<global_cable54_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain278_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable54_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass71_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain278_t<NV>>>;

template <int NV>
using soft_bypass71_t = bypass::smoothed<20, soft_bypass71_t_<NV>>;
template <int NV>
using xfader77_c1 = parameter::bypass<soft_bypass71_t<NV>>;

template <int NV>
using xfader77_multimod = parameter::list<parameter::empty, xfader77_c1<NV>>;

template <int NV>
using xfader77_t = control::xfader<xfader77_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank15_c3_0 = xfader_c0<NV>;

template <int NV>
using sliderbank15_c3_1 = parameter::from0To1<xfader77_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank15_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank15_c3_0<NV>, 
                                         sliderbank15_c3_1<NV>>;

template <int NV>
using event_data_reader16_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                        routing::event_data_reader<NV>>;

template <int NV>
using chain279_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader16_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass70_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain279_t<NV>>>;

template <int NV>
using soft_bypass70_t = bypass::smoothed<20, soft_bypass70_t_<NV>>;
template <int NV>
using xfader76_c1 = parameter::bypass<soft_bypass70_t<NV>>;

template <int NV>
using xfader76_multimod = parameter::list<parameter::empty, xfader76_c1<NV>>;

template <int NV>
using xfader76_t = control::xfader<xfader76_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank15_c4_0 = xfader_c0<NV>;

template <int NV>
using sliderbank15_c4_1 = parameter::from0To1<xfader76_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank15_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank15_c4_0<NV>, 
                                         sliderbank15_c4_1<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader16_t<NV>;

template <int NV>
using chain280_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader17_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass69_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain280_t<NV>>>;

template <int NV>
using soft_bypass69_t = bypass::smoothed<20, soft_bypass69_t_<NV>>;
template <int NV>
using xfader75_c1 = parameter::bypass<soft_bypass69_t<NV>>;

template <int NV>
using xfader75_multimod = parameter::list<parameter::empty, xfader75_c1<NV>>;

template <int NV>
using xfader75_t = control::xfader<xfader75_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank15_c5_0 = xfader_c0<NV>;

template <int NV>
using sliderbank15_c5_1 = parameter::from0To1<xfader75_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank15_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank15_c5_0<NV>, 
                                         sliderbank15_c5_1<NV>>;

template <int NV> using event_data_reader_t = event_data_reader16_t<NV>;

template <int NV>
using chain384_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader3_t = event_data_reader16_t<NV>;

template <int NV>
using chain395_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader3_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader2_t = event_data_reader16_t<NV>;

template <int NV>
using chain394_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader2_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader1_t = event_data_reader16_t<NV>;

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
using chain281_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch15_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass68_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain281_t<NV>>>;

template <int NV>
using soft_bypass68_t = bypass::smoothed<20, soft_bypass68_t_<NV>>;
template <int NV>
using xfader74_c1 = parameter::bypass<soft_bypass68_t<NV>>;

template <int NV>
using xfader74_multimod = parameter::list<parameter::empty, xfader74_c1<NV>>;

template <int NV>
using xfader74_t = control::xfader<xfader74_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank15_c6_0 = xfader_c0<NV>;

template <int NV>
using sliderbank15_c6_1 = parameter::from0To1<xfader74_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank15_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank15_c6_0<NV>, 
                                         sliderbank15_c6_1<NV>>;

template <int NV>
using midi_cc51_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain283_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc51_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc52_t = midi_cc51_t<NV>;

template <int NV>
using chain284_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc52_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc53_t = midi_cc51_t<NV>;

template <int NV>
using chain285_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc53_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc54_t = midi_cc51_t<NV>;

template <int NV>
using chain286_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc54_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using midi38_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain287_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi38_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using midi39_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain288_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi39_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using midi40_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

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
using soft_bypass67_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain282_t<NV>>>;

template <int NV>
using soft_bypass67_t = bypass::smoothed<20, soft_bypass67_t_<NV>>;
template <int NV>
using xfader73_c1 = parameter::bypass<soft_bypass67_t<NV>>;

template <int NV>
using xfader73_multimod = parameter::list<parameter::empty, xfader73_c1<NV>>;

template <int NV>
using xfader73_t = control::xfader<xfader73_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank15_c7_0 = xfader_c0<NV>;

template <int NV>
using sliderbank15_c7_1 = parameter::from0To1<xfader73_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank15_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank15_c7_0<NV>, 
                                         sliderbank15_c7_1<NV>>;

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
                                  data::external::sliderpack<0>>;

template <int NV>
using chain392_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader71_t<NV>>, 
                                    soft_bypass65_t<NV>>;

template <int NV>
using chain407_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader79_t<NV>>, 
                                    soft_bypass73_t<NV>>;
using global_cable53_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable53_t = routing::global_cable<global_cable53_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain277_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable53_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using chain406_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader78_t>, 
                                    soft_bypass72_t, 
                                    chain277_t<NV>>;

template <int NV>
using chain405_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader77_t<NV>>, 
                                    soft_bypass71_t<NV>>;

template <int NV>
using chain404_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader76_t<NV>>, 
                                    soft_bypass70_t<NV>>;

template <int NV>
using chain403_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader75_t<NV>>, 
                                    soft_bypass69_t<NV>>;

template <int NV>
using chain402_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader74_t<NV>>, 
                                    soft_bypass68_t<NV>>;

template <int NV>
using chain401_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader73_t<NV>>, 
                                    soft_bypass67_t<NV>>;

template <int NV>
using split29_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain392_t<NV>>, 
                                   chain407_t<NV>, 
                                   chain406_t<NV>, 
                                   chain405_t<NV>, 
                                   chain404_t<NV>, 
                                   chain403_t<NV>, 
                                   chain402_t<NV>, 
                                   chain401_t<NV>>;

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

using global_cable55_t_index = global_cable51_t_index;

template <int NV>
using global_cable55_t = routing::global_cable<global_cable55_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain290_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable55_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass66_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain290_t<NV>>>;

template <int NV>
using soft_bypass66_t = bypass::smoothed<20, soft_bypass66_t_<NV>>;
template <int NV>
using xfader72_c1 = parameter::bypass<soft_bypass66_t<NV>>;

template <int NV>
using xfader72_multimod = parameter::list<parameter::empty, xfader72_c1<NV>>;

template <int NV>
using xfader72_t = control::xfader<xfader72_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank16_c0_0 = xfader_c0<NV>;

template <int NV>
using sliderbank16_c0_1 = parameter::from0To1<xfader72_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank16_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank16_c0_0<NV>, 
                                         sliderbank16_c0_1<NV>>;

using global_cable56_t_index = global_cable52_t_index;

template <int NV>
using global_cable56_t = routing::global_cable<global_cable56_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain291_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable56_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass80_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain291_t<NV>>>;

template <int NV>
using soft_bypass80_t = bypass::smoothed<20, soft_bypass80_t_<NV>>;
template <int NV>
using xfader86_c1 = parameter::bypass<soft_bypass80_t<NV>>;

template <int NV>
using xfader86_multimod = parameter::list<parameter::empty, xfader86_c1<NV>>;

template <int NV>
using xfader86_t = control::xfader<xfader86_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank16_c1_0 = xfader_c0<NV>;

template <int NV>
using sliderbank16_c1_1 = parameter::from0To1<xfader86_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank16_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank16_c1_0<NV>, 
                                         sliderbank16_c1_1<NV>>;

using global_cable57_t_index = global_cable53_t_index;

template <int NV>
using global_cable57_t = routing::global_cable<global_cable57_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain292_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable57_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass79_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain292_t<NV>>>;

template <int NV>
using soft_bypass79_t = bypass::smoothed<20, soft_bypass79_t_<NV>>;
template <int NV>
using xfader85_c1 = parameter::bypass<soft_bypass79_t<NV>>;

template <int NV>
using xfader85_multimod = parameter::list<parameter::empty, xfader85_c1<NV>>;

template <int NV>
using xfader85_t = control::xfader<xfader85_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank16_c2_0 = xfader_c0<NV>;

template <int NV>
using sliderbank16_c2_1 = parameter::from0To1<xfader85_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank16_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank16_c2_0<NV>, 
                                         sliderbank16_c2_1<NV>>;

using soft_bypass78_t_ = soft_bypass72_t_;

using soft_bypass78_t = bypass::smoothed<20, soft_bypass78_t_>;
using xfader84_c1 = parameter::bypass<soft_bypass78_t>;

using xfader84_multimod = parameter::list<parameter::empty, xfader84_c1>;

using xfader84_t = control::xfader<xfader84_multimod, faders::switcher>;
template <int NV> using sliderbank16_c3_0 = xfader_c0<NV>;

using sliderbank16_c3_1 = parameter::from0To1<xfader84_t, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank16_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank16_c3_0<NV>, 
                                         sliderbank16_c3_1>;

template <int NV> using event_data_reader18_t = event_data_reader16_t<NV>;

template <int NV>
using chain294_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader18_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass77_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain294_t<NV>>>;

template <int NV>
using soft_bypass77_t = bypass::smoothed<20, soft_bypass77_t_<NV>>;
template <int NV>
using xfader83_c1 = parameter::bypass<soft_bypass77_t<NV>>;

template <int NV>
using xfader83_multimod = parameter::list<parameter::empty, xfader83_c1<NV>>;

template <int NV>
using xfader83_t = control::xfader<xfader83_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank16_c4_0 = xfader_c0<NV>;

template <int NV>
using sliderbank16_c4_1 = parameter::from0To1<xfader83_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank16_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank16_c4_0<NV>, 
                                         sliderbank16_c4_1<NV>>;

template <int NV> using event_data_reader19_t = event_data_reader16_t<NV>;

template <int NV>
using chain295_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader19_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass76_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain295_t<NV>>>;

template <int NV>
using soft_bypass76_t = bypass::smoothed<20, soft_bypass76_t_<NV>>;
template <int NV>
using xfader82_c1 = parameter::bypass<soft_bypass76_t<NV>>;

template <int NV>
using xfader82_multimod = parameter::list<parameter::empty, xfader82_c1<NV>>;

template <int NV>
using xfader82_t = control::xfader<xfader82_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank16_c5_0 = xfader_c0<NV>;

template <int NV>
using sliderbank16_c5_1 = parameter::from0To1<xfader82_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank16_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank16_c5_0<NV>, 
                                         sliderbank16_c5_1<NV>>;

template <int NV> using event_data_reader4_t = event_data_reader16_t<NV>;

template <int NV>
using chain385_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader4_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader5_t = event_data_reader16_t<NV>;

template <int NV>
using chain396_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader5_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader6_t = event_data_reader16_t<NV>;

template <int NV>
using chain397_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader6_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader7_t = event_data_reader16_t<NV>;

template <int NV>
using chain398_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader7_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch16_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain385_t<NV>>, 
                                     chain396_t<NV>, 
                                     chain397_t<NV>, 
                                     chain398_t<NV>>;

template <int NV>
using chain296_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch16_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass75_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain296_t<NV>>>;

template <int NV>
using soft_bypass75_t = bypass::smoothed<20, soft_bypass75_t_<NV>>;
template <int NV>
using xfader81_c1 = parameter::bypass<soft_bypass75_t<NV>>;

template <int NV>
using xfader81_multimod = parameter::list<parameter::empty, xfader81_c1<NV>>;

template <int NV>
using xfader81_t = control::xfader<xfader81_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank16_c6_0 = xfader_c0<NV>;

template <int NV>
using sliderbank16_c6_1 = parameter::from0To1<xfader81_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank16_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank16_c6_0<NV>, 
                                         sliderbank16_c6_1<NV>>;

template <int NV> using midi_cc55_t = midi_cc51_t<NV>;

template <int NV>
using chain298_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc55_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc56_t = midi_cc51_t<NV>;

template <int NV>
using chain299_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc56_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc57_t = midi_cc51_t<NV>;

template <int NV>
using chain426_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc57_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc58_t = midi_cc51_t<NV>;

template <int NV>
using chain451_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc58_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi41_t = midi38_t<NV>;

template <int NV>
using chain452_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi41_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi43_t = midi39_t<NV>;

template <int NV>
using chain453_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi43_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi44_t = midi40_t<NV>;

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
using soft_bypass74_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain297_t<NV>>>;

template <int NV>
using soft_bypass74_t = bypass::smoothed<20, soft_bypass74_t_<NV>>;
template <int NV>
using xfader80_c1 = parameter::bypass<soft_bypass74_t<NV>>;

template <int NV>
using xfader80_multimod = parameter::list<parameter::empty, xfader80_c1<NV>>;

template <int NV>
using xfader80_t = control::xfader<xfader80_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank16_c7_0 = xfader_c0<NV>;

template <int NV>
using sliderbank16_c7_1 = parameter::from0To1<xfader80_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank16_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank16_c7_0<NV>, 
                                         sliderbank16_c7_1<NV>>;

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
                                  data::external::sliderpack<1>>;

template <int NV>
using chain400_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader72_t<NV>>, 
                                    soft_bypass66_t<NV>>;

template <int NV>
using chain414_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader86_t<NV>>, 
                                    soft_bypass80_t<NV>>;

template <int NV>
using chain413_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader85_t<NV>>, 
                                    soft_bypass79_t<NV>>;
using global_cable58_t_index = global_cable54_t_index;

template <int NV>
using global_cable58_t = routing::global_cable<global_cable58_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain293_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable58_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using chain412_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader84_t>, 
                                    soft_bypass78_t, 
                                    chain293_t<NV>>;

template <int NV>
using chain411_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader83_t<NV>>, 
                                    soft_bypass77_t<NV>>;

template <int NV>
using chain410_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader82_t<NV>>, 
                                    soft_bypass76_t<NV>>;

template <int NV>
using chain409_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader81_t<NV>>, 
                                    soft_bypass75_t<NV>>;

template <int NV>
using chain408_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader80_t<NV>>, 
                                    soft_bypass74_t<NV>>;

template <int NV>
using split33_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain400_t<NV>>, 
                                   chain414_t<NV>, 
                                   chain413_t<NV>, 
                                   chain412_t<NV>, 
                                   chain411_t<NV>, 
                                   chain410_t<NV>, 
                                   chain409_t<NV>, 
                                   chain408_t<NV>>;

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

using global_cable59_t_index = global_cable51_t_index;

template <int NV>
using global_cable59_t = routing::global_cable<global_cable59_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain300_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable59_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass81_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain300_t<NV>>>;

template <int NV>
using soft_bypass81_t = bypass::smoothed<20, soft_bypass81_t_<NV>>;
template <int NV>
using xfader87_c1 = parameter::bypass<soft_bypass81_t<NV>>;

template <int NV>
using xfader87_multimod = parameter::list<parameter::empty, xfader87_c1<NV>>;

template <int NV>
using xfader87_t = control::xfader<xfader87_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank17_c0_0 = xfader_c0<NV>;

template <int NV>
using sliderbank17_c0_1 = parameter::from0To1<xfader87_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank17_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank17_c0_0<NV>, 
                                         sliderbank17_c0_1<NV>>;

using global_cable60_t_index = global_cable52_t_index;

template <int NV>
using global_cable60_t = routing::global_cable<global_cable60_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain301_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable60_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass89_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain301_t<NV>>>;

template <int NV>
using soft_bypass89_t = bypass::smoothed<20, soft_bypass89_t_<NV>>;
template <int NV>
using xfader95_c1 = parameter::bypass<soft_bypass89_t<NV>>;

template <int NV>
using xfader95_multimod = parameter::list<parameter::empty, xfader95_c1<NV>>;

template <int NV>
using xfader95_t = control::xfader<xfader95_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank17_c1_0 = xfader_c0<NV>;

template <int NV>
using sliderbank17_c1_1 = parameter::from0To1<xfader95_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank17_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank17_c1_0<NV>, 
                                         sliderbank17_c1_1<NV>>;

using global_cable61_t_index = global_cable53_t_index;

template <int NV>
using global_cable61_t = routing::global_cable<global_cable61_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain302_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable61_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass88_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain302_t<NV>>>;

template <int NV>
using soft_bypass88_t = bypass::smoothed<20, soft_bypass88_t_<NV>>;
template <int NV>
using xfader94_c1 = parameter::bypass<soft_bypass88_t<NV>>;

template <int NV>
using xfader94_multimod = parameter::list<parameter::empty, xfader94_c1<NV>>;

template <int NV>
using xfader94_t = control::xfader<xfader94_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank17_c2_0 = xfader_c0<NV>;

template <int NV>
using sliderbank17_c2_1 = parameter::from0To1<xfader94_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank17_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank17_c2_0<NV>, 
                                         sliderbank17_c2_1<NV>>;

using global_cable62_t_index = global_cable54_t_index;

template <int NV>
using global_cable62_t = routing::global_cable<global_cable62_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain303_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable62_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass87_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain303_t<NV>>>;

template <int NV>
using soft_bypass87_t = bypass::smoothed<20, soft_bypass87_t_<NV>>;
template <int NV>
using xfader93_c1 = parameter::bypass<soft_bypass87_t<NV>>;

template <int NV>
using xfader93_multimod = parameter::list<parameter::empty, xfader93_c1<NV>>;

template <int NV>
using xfader93_t = control::xfader<xfader93_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank17_c3_0 = xfader_c0<NV>;

template <int NV>
using sliderbank17_c3_1 = parameter::from0To1<xfader93_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank17_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank17_c3_0<NV>, 
                                         sliderbank17_c3_1<NV>>;

template <int NV> using event_data_reader20_t = event_data_reader16_t<NV>;

template <int NV>
using chain304_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader20_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass86_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain304_t<NV>>>;

template <int NV>
using soft_bypass86_t = bypass::smoothed<20, soft_bypass86_t_<NV>>;
template <int NV>
using xfader92_c1 = parameter::bypass<soft_bypass86_t<NV>>;

template <int NV>
using xfader92_multimod = parameter::list<parameter::empty, xfader92_c1<NV>>;

template <int NV>
using xfader92_t = control::xfader<xfader92_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank17_c4_0 = xfader_c0<NV>;

template <int NV>
using sliderbank17_c4_1 = parameter::from0To1<xfader92_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank17_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank17_c4_0<NV>, 
                                         sliderbank17_c4_1<NV>>;

template <int NV> using event_data_reader21_t = event_data_reader16_t<NV>;

template <int NV>
using chain305_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader21_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass85_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain305_t<NV>>>;

template <int NV>
using soft_bypass85_t = bypass::smoothed<20, soft_bypass85_t_<NV>>;
template <int NV>
using xfader91_c1 = parameter::bypass<soft_bypass85_t<NV>>;

template <int NV>
using xfader91_multimod = parameter::list<parameter::empty, xfader91_c1<NV>>;

template <int NV>
using xfader91_t = control::xfader<xfader91_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank17_c5_0 = xfader_c0<NV>;

template <int NV>
using sliderbank17_c5_1 = parameter::from0To1<xfader91_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank17_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank17_c5_0<NV>, 
                                         sliderbank17_c5_1<NV>>;

template <int NV> using event_data_reader8_t = event_data_reader16_t<NV>;

template <int NV>
using chain386_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader8_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader9_t = event_data_reader16_t<NV>;

template <int NV>
using chain399_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader9_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader10_t = event_data_reader16_t<NV>;

template <int NV>
using chain416_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader10_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader11_t = event_data_reader16_t<NV>;

template <int NV>
using chain424_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader11_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch19_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain386_t<NV>>, 
                                     chain399_t<NV>, 
                                     chain416_t<NV>, 
                                     chain424_t<NV>>;

template <int NV>
using chain306_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch19_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass84_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain306_t<NV>>>;

template <int NV>
using soft_bypass84_t = bypass::smoothed<20, soft_bypass84_t_<NV>>;
template <int NV>
using xfader90_c1 = parameter::bypass<soft_bypass84_t<NV>>;

template <int NV>
using xfader90_multimod = parameter::list<parameter::empty, xfader90_c1<NV>>;

template <int NV>
using xfader90_t = control::xfader<xfader90_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank17_c6_0 = xfader_c0<NV>;

template <int NV>
using sliderbank17_c6_1 = parameter::from0To1<xfader90_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank17_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank17_c6_0<NV>, 
                                         sliderbank17_c6_1<NV>>;

template <int NV> using midi_cc59_t = midi_cc51_t<NV>;

template <int NV>
using chain308_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc59_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc60_t = midi_cc51_t<NV>;

template <int NV>
using chain309_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc60_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc61_t = midi_cc51_t<NV>;

template <int NV>
using chain427_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc61_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc62_t = midi_cc51_t<NV>;

template <int NV>
using chain455_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc62_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi45_t = midi38_t<NV>;

template <int NV>
using chain456_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi45_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi46_t = midi39_t<NV>;

template <int NV>
using chain457_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi46_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi47_t = midi40_t<NV>;

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
using soft_bypass83_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain307_t<NV>>>;

template <int NV>
using soft_bypass83_t = bypass::smoothed<20, soft_bypass83_t_<NV>>;
template <int NV>
using xfader89_c1 = parameter::bypass<soft_bypass83_t<NV>>;

template <int NV>
using xfader89_multimod = parameter::list<parameter::empty, xfader89_c1<NV>>;

template <int NV>
using xfader89_t = control::xfader<xfader89_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank17_c7_0 = xfader_c0<NV>;

template <int NV>
using sliderbank17_c7_1 = parameter::from0To1<xfader89_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank17_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank17_c7_0<NV>, 
                                         sliderbank17_c7_1<NV>>;

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
                                  data::external::sliderpack<2>>;

template <int NV>
using chain415_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader87_t<NV>>, 
                                    soft_bypass81_t<NV>>;

template <int NV>
using chain423_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader95_t<NV>>, 
                                    soft_bypass89_t<NV>>;

template <int NV>
using chain422_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader94_t<NV>>, 
                                    soft_bypass88_t<NV>>;

template <int NV>
using chain421_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader93_t<NV>>, 
                                    soft_bypass87_t<NV>>;

template <int NV>
using chain420_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader92_t<NV>>, 
                                    soft_bypass86_t<NV>>;

template <int NV>
using chain419_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader91_t<NV>>, 
                                    soft_bypass85_t<NV>>;

template <int NV>
using chain418_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader90_t<NV>>, 
                                    soft_bypass84_t<NV>>;

template <int NV>
using chain417_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader89_t<NV>>, 
                                    soft_bypass83_t<NV>>;

template <int NV>
using split34_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain415_t<NV>>, 
                                   chain423_t<NV>, 
                                   chain422_t<NV>, 
                                   chain421_t<NV>, 
                                   chain420_t<NV>, 
                                   chain419_t<NV>, 
                                   chain418_t<NV>, 
                                   chain417_t<NV>>;

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

using global_cable63_t_index = global_cable51_t_index;

template <int NV>
using global_cable63_t = routing::global_cable<global_cable63_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain310_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable63_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass82_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain310_t<NV>>>;

template <int NV>
using soft_bypass82_t = bypass::smoothed<20, soft_bypass82_t_<NV>>;
template <int NV>
using xfader88_c1 = parameter::bypass<soft_bypass82_t<NV>>;

template <int NV>
using xfader88_multimod = parameter::list<parameter::empty, xfader88_c1<NV>>;

template <int NV>
using xfader88_t = control::xfader<xfader88_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c0_0 = xfader_c0<NV>;

template <int NV>
using sliderbank18_c0_1 = parameter::from0To1<xfader88_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank18_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c0_0<NV>, 
                                         sliderbank18_c0_1<NV>>;

using global_cable64_t_index = global_cable52_t_index;

template <int NV>
using global_cable64_t = routing::global_cable<global_cable64_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain311_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable64_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass90_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain311_t<NV>>>;

template <int NV>
using soft_bypass90_t = bypass::smoothed<20, soft_bypass90_t_<NV>>;
template <int NV>
using xfader96_c1 = parameter::bypass<soft_bypass90_t<NV>>;

template <int NV>
using xfader96_multimod = parameter::list<parameter::empty, xfader96_c1<NV>>;

template <int NV>
using xfader96_t = control::xfader<xfader96_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c1_0 = xfader_c0<NV>;

template <int NV>
using sliderbank18_c1_1 = parameter::from0To1<xfader96_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank18_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c1_0<NV>, 
                                         sliderbank18_c1_1<NV>>;

using global_cable65_t_index = global_cable53_t_index;

template <int NV>
using global_cable65_t = routing::global_cable<global_cable65_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain312_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable65_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass91_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain312_t<NV>>>;

template <int NV>
using soft_bypass91_t = bypass::smoothed<20, soft_bypass91_t_<NV>>;
template <int NV>
using xfader97_c1 = parameter::bypass<soft_bypass91_t<NV>>;

template <int NV>
using xfader97_multimod = parameter::list<parameter::empty, xfader97_c1<NV>>;

template <int NV>
using xfader97_t = control::xfader<xfader97_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c2_0 = xfader_c0<NV>;

template <int NV>
using sliderbank18_c2_1 = parameter::from0To1<xfader97_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank18_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c2_0<NV>, 
                                         sliderbank18_c2_1<NV>>;

using global_cable66_t_index = global_cable54_t_index;

template <int NV>
using global_cable66_t = routing::global_cable<global_cable66_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain313_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable66_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass92_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain313_t<NV>>>;

template <int NV>
using soft_bypass92_t = bypass::smoothed<20, soft_bypass92_t_<NV>>;
template <int NV>
using xfader98_c1 = parameter::bypass<soft_bypass92_t<NV>>;

template <int NV>
using xfader98_multimod = parameter::list<parameter::empty, xfader98_c1<NV>>;

template <int NV>
using xfader98_t = control::xfader<xfader98_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c3_0 = xfader_c0<NV>;

template <int NV>
using sliderbank18_c3_1 = parameter::from0To1<xfader98_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank18_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c3_0<NV>, 
                                         sliderbank18_c3_1<NV>>;

template <int NV> using event_data_reader22_t = event_data_reader16_t<NV>;

template <int NV>
using chain314_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader22_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass93_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain314_t<NV>>>;

template <int NV>
using soft_bypass93_t = bypass::smoothed<20, soft_bypass93_t_<NV>>;
template <int NV>
using xfader99_c1 = parameter::bypass<soft_bypass93_t<NV>>;

template <int NV>
using xfader99_multimod = parameter::list<parameter::empty, xfader99_c1<NV>>;

template <int NV>
using xfader99_t = control::xfader<xfader99_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c4_0 = xfader_c0<NV>;

template <int NV>
using sliderbank18_c4_1 = parameter::from0To1<xfader99_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank18_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c4_0<NV>, 
                                         sliderbank18_c4_1<NV>>;

template <int NV> using event_data_reader23_t = event_data_reader16_t<NV>;

template <int NV>
using chain315_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader23_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass94_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain315_t<NV>>>;

template <int NV>
using soft_bypass94_t = bypass::smoothed<20, soft_bypass94_t_<NV>>;
template <int NV>
using xfader100_c1 = parameter::bypass<soft_bypass94_t<NV>>;

template <int NV>
using xfader100_multimod = parameter::list<parameter::empty, xfader100_c1<NV>>;

template <int NV>
using xfader100_t = control::xfader<xfader100_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c5_0 = xfader_c0<NV>;

template <int NV>
using sliderbank18_c5_1 = parameter::from0To1<xfader100_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank18_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c5_0<NV>, 
                                         sliderbank18_c5_1<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader16_t<NV>;

template <int NV>
using chain387_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader12_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader13_t = event_data_reader16_t<NV>;

template <int NV>
using chain434_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader13_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader16_t<NV>;

template <int NV>
using chain435_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader14_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader16_t<NV>;

template <int NV>
using chain436_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader15_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch20_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain387_t<NV>>, 
                                     chain434_t<NV>, 
                                     chain435_t<NV>, 
                                     chain436_t<NV>>;

template <int NV>
using chain316_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch20_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass95_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain316_t<NV>>>;

template <int NV>
using soft_bypass95_t = bypass::smoothed<20, soft_bypass95_t_<NV>>;
template <int NV>
using xfader101_c1 = parameter::bypass<soft_bypass95_t<NV>>;

template <int NV>
using xfader101_multimod = parameter::list<parameter::empty, xfader101_c1<NV>>;

template <int NV>
using xfader101_t = control::xfader<xfader101_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c6_0 = xfader_c0<NV>;

template <int NV>
using sliderbank18_c6_1 = parameter::from0To1<xfader101_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank18_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c6_0<NV>, 
                                         sliderbank18_c6_1<NV>>;

template <int NV> using midi_cc63_t = midi_cc51_t<NV>;

template <int NV>
using chain318_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc63_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc64_t = midi_cc51_t<NV>;

template <int NV>
using chain319_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc64_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc65_t = midi_cc51_t<NV>;

template <int NV>
using chain438_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc65_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc66_t = midi_cc51_t<NV>;

template <int NV>
using chain459_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc66_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi48_t = midi38_t<NV>;

template <int NV>
using chain460_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi48_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi49_t = midi39_t<NV>;

template <int NV>
using chain461_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi49_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi50_t = midi40_t<NV>;

template <int NV>
using chain462_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi50_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch61_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain318_t<NV>>, 
                                     chain319_t<NV>, 
                                     chain438_t<NV>, 
                                     chain459_t<NV>, 
                                     chain460_t<NV>, 
                                     chain461_t<NV>, 
                                     chain462_t<NV>>;

template <int NV>
using chain317_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch61_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass96_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain317_t<NV>>>;

template <int NV>
using soft_bypass96_t = bypass::smoothed<20, soft_bypass96_t_<NV>>;
template <int NV>
using xfader102_c1 = parameter::bypass<soft_bypass96_t<NV>>;

template <int NV>
using xfader102_multimod = parameter::list<parameter::empty, xfader102_c1<NV>>;

template <int NV>
using xfader102_t = control::xfader<xfader102_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c7_0 = xfader_c0<NV>;

template <int NV>
using sliderbank18_c7_1 = parameter::from0To1<xfader102_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank18_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c7_0<NV>, 
                                         sliderbank18_c7_1<NV>>;

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
                                  data::external::sliderpack<3>>;

template <int NV>
using chain425_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader88_t<NV>>, 
                                    soft_bypass82_t<NV>>;

template <int NV>
using chain428_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader96_t<NV>>, 
                                    soft_bypass90_t<NV>>;

template <int NV>
using chain429_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader97_t<NV>>, 
                                    soft_bypass91_t<NV>>;

template <int NV>
using chain430_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader98_t<NV>>, 
                                    soft_bypass92_t<NV>>;

template <int NV>
using chain431_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader99_t<NV>>, 
                                    soft_bypass93_t<NV>>;

template <int NV>
using chain432_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader100_t<NV>>, 
                                    soft_bypass94_t<NV>>;

template <int NV>
using chain433_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader101_t<NV>>, 
                                    soft_bypass95_t<NV>>;

template <int NV>
using chain437_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader102_t<NV>>, 
                                    soft_bypass96_t<NV>>;

template <int NV>
using split35_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain425_t<NV>>, 
                                   chain428_t<NV>, 
                                   chain429_t<NV>, 
                                   chain430_t<NV>, 
                                   chain431_t<NV>, 
                                   chain432_t<NV>, 
                                   chain433_t<NV>, 
                                   chain437_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma_modRange, 
                             -50., 
                             0., 
                             0.1);

template <int NV>
using pma_mod = parameter::from0To1<core::gain<NV>, 
                                    0, 
                                    pma_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using peak38_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain19_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank18_t<NV>>, 
                                       split35_t<NV>, 
                                       peak38_t<NV>, 
                                       pma_t<NV>>;

template <int NV>
using modchain19_t = wrap::control_rate<modchain19_t_<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain15_t<NV>>, 
                                  modchain17_t<NV>, 
                                  modchain18_t<NV>, 
                                  modchain19_t<NV>>;

template <int NV>
using ramp5_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync6_t = wrap::mod<parameter::plain<ramp5_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

using chain102_t = soft_bypass72_t_;
template <int NV>
using branch36_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain102_t>, 
                                     math::mod_inv<NV>>;

template <int NV>
using chain179_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync6_t<NV>>, 
                                    ramp5_t<NV>, 
                                    branch36_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::phasor<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain179_t<NV>>, 
                                   chain1_t<NV>>;

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
                                    wrap::fix<1, branch_t<NV>>, 
                                    peak15_t<NV>, 
                                    math::clear<NV>>;

template <int NV> using ramp8_t = ramp5_t<NV>;
template <int NV>
using tempo_sync9_t = wrap::mod<parameter::plain<ramp8_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain188_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync9_t<NV>>, 
                                    ramp8_t<NV>>;

using chain105_t = soft_bypass72_t_;
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

template <int NV> using chain4_t = chain1_t<NV>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain187_t<NV>>, 
                                    chain4_t<NV>>;

template <int NV> using ramp7_t = ramp5_t<NV>;
template <int NV>
using tempo_sync8_t = wrap::mod<parameter::plain<ramp7_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain186_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync8_t<NV>>, 
                                    ramp7_t<NV>>;

using chain104_t = soft_bypass72_t_;
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

template <int NV> using chain3_t = chain1_t<NV>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain185_t<NV>>, 
                                    chain3_t<NV>>;

template <int NV> using ramp6_t = ramp5_t<NV>;
template <int NV>
using tempo_sync7_t = wrap::mod<parameter::plain<ramp6_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain184_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync7_t<NV>>, 
                                    ramp6_t<NV>>;

using chain103_t = soft_bypass72_t_;
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

template <int NV> using chain2_t = chain1_t<NV>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain183_t<NV>>, 
                                    chain2_t<NV>>;

template <int NV>
using split23_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain178_t<NV>>, 
                                   branch1_t<NV>, 
                                   branch3_t<NV>, 
                                   branch2_t<NV>>;

template <int NV>
using modchain8_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split23_t<NV>>>;

template <int NV>
using modchain8_t = wrap::control_rate<modchain8_t_<NV>>;

using global_cable43_t_index = global_cable51_t_index;

template <int NV>
using global_cable43_t = routing::global_cable<global_cable43_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain230_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable43_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass129_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain230_t<NV>>>;

template <int NV>
using soft_bypass129_t = bypass::smoothed<20, soft_bypass129_t_<NV>>;
template <int NV>
using xfader135_c1 = parameter::bypass<soft_bypass129_t<NV>>;

template <int NV>
using xfader135_multimod = parameter::list<parameter::empty, xfader135_c1<NV>>;

template <int NV>
using xfader135_t = control::xfader<xfader135_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank13_c0_0 = xfader_c0<NV>;

template <int NV>
using sliderbank13_c0_1 = parameter::from0To1<xfader135_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank13_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank13_c0_0<NV>, 
                                         sliderbank13_c0_1<NV>>;

using global_cable44_t_index = global_cable52_t_index;

template <int NV>
using global_cable44_t = routing::global_cable<global_cable44_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain231_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable44_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass136_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain231_t<NV>>>;

template <int NV>
using soft_bypass136_t = bypass::smoothed<20, soft_bypass136_t_<NV>>;
template <int NV>
using xfader142_c1 = parameter::bypass<soft_bypass136_t<NV>>;

template <int NV>
using xfader142_multimod = parameter::list<parameter::empty, xfader142_c1<NV>>;

template <int NV>
using xfader142_t = control::xfader<xfader142_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank13_c1_0 = xfader_c0<NV>;

template <int NV>
using sliderbank13_c1_1 = parameter::from0To1<xfader142_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank13_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank13_c1_0<NV>, 
                                         sliderbank13_c1_1<NV>>;

using global_cable45_t_index = global_cable53_t_index;

template <int NV>
using global_cable45_t = routing::global_cable<global_cable45_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain232_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable45_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass135_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain232_t<NV>>>;

template <int NV>
using soft_bypass135_t = bypass::smoothed<20, soft_bypass135_t_<NV>>;
template <int NV>
using xfader141_c1 = parameter::bypass<soft_bypass135_t<NV>>;

template <int NV>
using xfader141_multimod = parameter::list<parameter::empty, xfader141_c1<NV>>;

template <int NV>
using xfader141_t = control::xfader<xfader141_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank13_c2_0 = xfader_c0<NV>;

template <int NV>
using sliderbank13_c2_1 = parameter::from0To1<xfader141_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank13_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank13_c2_0<NV>, 
                                         sliderbank13_c2_1<NV>>;

using global_cable46_t_index = global_cable54_t_index;

template <int NV>
using global_cable46_t = routing::global_cable<global_cable46_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain233_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable46_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass134_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain233_t<NV>>>;

template <int NV>
using soft_bypass134_t = bypass::smoothed<20, soft_bypass134_t_<NV>>;
template <int NV>
using xfader140_c1 = parameter::bypass<soft_bypass134_t<NV>>;

template <int NV>
using xfader140_multimod = parameter::list<parameter::empty, xfader140_c1<NV>>;

template <int NV>
using xfader140_t = control::xfader<xfader140_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank13_c3_0 = xfader_c0<NV>;

template <int NV>
using sliderbank13_c3_1 = parameter::from0To1<xfader140_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank13_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank13_c3_0<NV>, 
                                         sliderbank13_c3_1<NV>>;

template <int NV> using event_data_reader24_t = event_data_reader16_t<NV>;

template <int NV>
using chain234_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader24_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass133_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain234_t<NV>>>;

template <int NV>
using soft_bypass133_t = bypass::smoothed<20, soft_bypass133_t_<NV>>;
template <int NV>
using xfader139_c1 = parameter::bypass<soft_bypass133_t<NV>>;

template <int NV>
using xfader139_multimod = parameter::list<parameter::empty, xfader139_c1<NV>>;

template <int NV>
using xfader139_t = control::xfader<xfader139_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank13_c4_0 = xfader_c0<NV>;

template <int NV>
using sliderbank13_c4_1 = parameter::from0To1<xfader139_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank13_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank13_c4_0<NV>, 
                                         sliderbank13_c4_1<NV>>;

template <int NV> using event_data_reader25_t = event_data_reader16_t<NV>;

template <int NV>
using chain235_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader25_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass132_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain235_t<NV>>>;

template <int NV>
using soft_bypass132_t = bypass::smoothed<20, soft_bypass132_t_<NV>>;
template <int NV>
using xfader138_c1 = parameter::bypass<soft_bypass132_t<NV>>;

template <int NV>
using xfader138_multimod = parameter::list<parameter::empty, xfader138_c1<NV>>;

template <int NV>
using xfader138_t = control::xfader<xfader138_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank13_c5_0 = xfader_c0<NV>;

template <int NV>
using sliderbank13_c5_1 = parameter::from0To1<xfader138_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank13_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank13_c5_0<NV>, 
                                         sliderbank13_c5_1<NV>>;

template <int NV>
using branch51_t = container::branch<parameter::empty, 
                                     wrap::fix<1, math::add<NV>>, 
                                     math::add<NV>, 
                                     math::add<NV>, 
                                     math::add<NV>>;

template <int NV>
using chain236_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch51_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass131_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain236_t<NV>>>;

template <int NV>
using soft_bypass131_t = bypass::smoothed<20, soft_bypass131_t_<NV>>;
template <int NV>
using xfader137_c1 = parameter::bypass<soft_bypass131_t<NV>>;

template <int NV>
using xfader137_multimod = parameter::list<parameter::empty, xfader137_c1<NV>>;

template <int NV>
using xfader137_t = control::xfader<xfader137_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank13_c6_0 = xfader_c0<NV>;

template <int NV>
using sliderbank13_c6_1 = parameter::from0To1<xfader137_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank13_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank13_c6_0<NV>, 
                                         sliderbank13_c6_1<NV>>;

template <int NV> using midi_cc43_t = midi_cc51_t<NV>;

template <int NV>
using chain238_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc43_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc44_t = midi_cc51_t<NV>;

template <int NV>
using chain239_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc44_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc45_t = midi_cc51_t<NV>;

template <int NV>
using chain240_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc45_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc46_t = midi_cc51_t<NV>;

template <int NV>
using chain241_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc46_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi32_t = midi38_t<NV>;

template <int NV>
using chain242_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi32_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi33_t = midi39_t<NV>;

template <int NV>
using chain243_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi33_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi34_t = midi40_t<NV>;

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
using soft_bypass130_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain237_t<NV>>>;

template <int NV>
using soft_bypass130_t = bypass::smoothed<20, soft_bypass130_t_<NV>>;
template <int NV>
using xfader136_c1 = parameter::bypass<soft_bypass130_t<NV>>;

template <int NV>
using xfader136_multimod = parameter::list<parameter::empty, xfader136_c1<NV>>;

template <int NV>
using xfader136_t = control::xfader<xfader136_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank13_c7_0 = xfader_c0<NV>;

template <int NV>
using sliderbank13_c7_1 = parameter::from0To1<xfader136_t<NV>, 
                                              0, 
                                              sliderbank15_c0_1Range>;

template <int NV>
using sliderbank13_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank13_c7_0<NV>, 
                                         sliderbank13_c7_1<NV>>;

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
                                  data::external::sliderpack<4>>;

template <int NV>
using chain508_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader135_t<NV>>, 
                                    soft_bypass129_t<NV>>;

template <int NV>
using chain525_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader142_t<NV>>, 
                                    soft_bypass136_t<NV>>;

template <int NV>
using chain524_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader141_t<NV>>, 
                                    soft_bypass135_t<NV>>;

template <int NV>
using chain523_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader140_t<NV>>, 
                                    soft_bypass134_t<NV>>;

template <int NV>
using chain522_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader139_t<NV>>, 
                                    soft_bypass133_t<NV>>;

template <int NV>
using chain521_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader138_t<NV>>, 
                                    soft_bypass132_t<NV>>;

template <int NV>
using chain520_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader137_t<NV>>, 
                                    soft_bypass131_t<NV>>;

template <int NV>
using chain509_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader136_t<NV>>, 
                                    soft_bypass130_t<NV>>;

template <int NV>
using split27_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain508_t<NV>>, 
                                   chain525_t<NV>, 
                                   chain524_t<NV>, 
                                   chain523_t<NV>, 
                                   chain522_t<NV>, 
                                   chain521_t<NV>, 
                                   chain520_t<NV>, 
                                   chain509_t<NV>>;

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
                                    wrap::fix<2, split10_t<NV>>, 
                                    split17_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, split2_t<NV>>, 
                                       core::gain<NV>, 
                                       filters::one_pole<NV>, 
                                       modchain8_t<NV>, 
                                       chain247_t<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain261_t = container::chain<parameter::empty, 
                                    wrap::fix<2, wrap::no_process<math::tanh<NV>>>>;
using stereo_cable = cable::block<2>;

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

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::clear<NV>>>, 
                                   branch39_t<NV>, 
                                   fix8_block_t<NV>, 
                                   branch23_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain_t<NV>>, 
                                   chain73_t<NV>>;

template <int NV>
using xfade_2x_lin_t = container::chain<parameter::empty, 
                                        wrap::fix<2, xfader_t<NV>>, 
                                        split20_t<NV>>;

template <int NV>
using peak_t = wrap::mod<parameter::plain<routing::event_data_writer<NV>, 1>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, routing::event_data_writer<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfade_2x_lin_t<NV>>, 
                                   peak_t<NV>, 
                                   modchain_t<NV>>;

namespace Files_t_parameters
{
// Parameter list for Files_impl::Files_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(QuantisePositiion_InputRange, 
                             1., 
                             9., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(QuantisePositiion_0Range, 
                             0., 
                             8., 
                             1.);

template <int NV>
using QuantisePositiion_0 = parameter::from0To1<Files_impl::branch21_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion_1 = parameter::from0To1<Files_impl::branch32_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion_2 = parameter::from0To1<Files_impl::branch31_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion_3 = parameter::from0To1<Files_impl::branch30_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion_4 = parameter::from0To1<Files_impl::branch33_t<NV>, 
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
                                   parameter::plain<Files_impl::pma20_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(PtichShiftOn_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PtichShiftOn_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using PtichShiftOn_0 = parameter::from0To1<Files_impl::branch23_t<NV>, 
                                           0, 
                                           PtichShiftOn_0Range>;

template <int NV>
using PtichShiftOn = parameter::chain<PtichShiftOn_InputRange, 
                                      PtichShiftOn_0<NV>>;

template <int NV>
using FileUser = parameter::chain<ranges::Identity, 
                                  parameter::plain<Files_impl::branch40_t<NV>, 0>, 
                                  parameter::plain<Files_impl::branch22_t<NV>, 0>, 
                                  parameter::plain<Files_impl::branch42_t<NV>, 0>, 
                                  parameter::plain<Files_impl::branch44_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidiPitch_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FileMidiPitch_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using FileMidiPitch_0 = parameter::from0To1<Files_impl::branch58_t<NV>, 
                                            0, 
                                            FileMidiPitch_0Range>;

template <int NV>
using FileMidiPitch = parameter::chain<FileMidiPitch_InputRange, 
                                       FileMidiPitch_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidipos2_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidipos2_0 = parameter::from0To1<Files_impl::branch52_t<NV>, 
                                           0, 
                                           FileMidiPitch_0Range>;

template <int NV>
using FileMidipos2 = parameter::chain<FileMidipos2_InputRange, 
                                      FileMidipos2_0<NV>>;

DECLARE_PARAMETER_RANGE(FileWinPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileWinPk_0 = parameter::from0To1<Files_impl::branch19_t<NV>, 
                                        0, 
                                        PtichShiftOn_0Range>;

template <int NV>
using FileWinPk = parameter::chain<FileWinPk_InputRange, FileWinPk_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidiwindow_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidiwindow_0 = parameter::from0To1<Files_impl::branch60_t<NV>, 
                                             0, 
                                             FileMidiPitch_0Range>;

template <int NV>
using FileMidiwindow = parameter::chain<FileMidiwindow_InputRange, 
                                        FileMidiwindow_0<NV>>;

DECLARE_PARAMETER_RANGE(FileMidPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileMidPk_0 = parameter::from0To1<Files_impl::branch51_t<NV>, 
                                        0, 
                                        PtichShiftOn_0Range>;

template <int NV>
using FileMidPk = parameter::chain<FileMidPk_InputRange, FileMidPk_0<NV>>;

DECLARE_PARAMETER_RANGE(FileInPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileInPk_0 = parameter::from0To1<Files_impl::branch20_t<NV>, 
                                       0, 
                                       PtichShiftOn_0Range>;

template <int NV>
using FileInPk = parameter::chain<FileInPk_InputRange, FileInPk_0<NV>>;

DECLARE_PARAMETER_RANGE(FileXrossFadePk_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileXrossFadePk_0 = parameter::from0To1<Files_impl::branch15_t<NV>, 
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
using FileXrossFadeMode_0 = parameter::from0To1<Files_impl::branch45_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode_1 = parameter::from0To1<Files_impl::branch43_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode_2 = parameter::from0To1<Files_impl::branch41_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode_3 = parameter::from0To1<Files_impl::branch26_t<NV>, 
                                                0, 
                                                PtichShiftOn_0Range>;

template <int NV>
using FileXrossFadeMode_4 = parameter::from0To1<Files_impl::branch39_t<NV>, 
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
using FileXrossFadeMidi_0 = parameter::from0To1<Files_impl::branch56_t<NV>, 
                                                0, 
                                                FileMidiPitch_0Range>;

template <int NV>
using FileXrossFadeMidi = parameter::chain<FileXrossFadeMidi_InputRange, 
                                           FileXrossFadeMidi_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilePitchPk_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using FilePitchPk_0 = parameter::from0To1<Files_impl::branch16_t<NV>, 
                                          0, 
                                          PtichShiftOn_0Range>;

template <int NV>
using FilePitchPk = parameter::chain<FilePitchPk_InputRange, FilePitchPk_0<NV>>;

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

DECLARE_PARAMETER_RANGE_STEP(RampDiv1_InputRange, 
                             1., 
                             32., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(RampDiv1_0Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using RampDiv1_0 = parameter::from0To1<Files_impl::tempo_sync6_t<NV>, 
                                       1, 
                                       RampDiv1_0Range>;

template <int NV>
using RampDiv1 = parameter::chain<RampDiv1_InputRange, RampDiv1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(RampDiv2_InputRange, 
                             1., 
                             32., 
                             1.);
template <int NV>
using RampDiv2_0 = parameter::from0To1<Files_impl::tempo_sync9_t<NV>, 
                                       1, 
                                       RampDiv1_0Range>;

template <int NV>
using RampDiv2 = parameter::chain<RampDiv2_InputRange, RampDiv2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(RampDiv3_InputRange, 
                             1., 
                             32., 
                             1.);
template <int NV>
using RampDiv3_0 = parameter::from0To1<Files_impl::tempo_sync8_t<NV>, 
                                       1, 
                                       RampDiv1_0Range>;

template <int NV>
using RampDiv3 = parameter::chain<RampDiv3_InputRange, RampDiv3_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(RampDiv4_InputRange, 
                             1., 
                             32., 
                             1.);
template <int NV>
using RampDiv4_0 = parameter::from0To1<Files_impl::tempo_sync7_t<NV>, 
                                       1, 
                                       RampDiv1_0Range>;

template <int NV>
using RampDiv4 = parameter::chain<RampDiv4_InputRange, RampDiv4_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(InputMidi_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using InputMidi_0 = parameter::from0To1<Files_impl::branch61_t<NV>, 
                                        0, 
                                        FileMidiPitch_0Range>;

template <int NV>
using InputMidi = parameter::chain<InputMidi_InputRange, InputMidi_0<NV>>;

template <int NV>
using PositionMod = parameter::plain<Files_impl::pma17_t<NV>, 
                                     1>;
template <int NV>
using Position = parameter::plain<Files_impl::pma17_t<NV>, 
                                  2>;
template <int NV>
using PosSmooth = parameter::plain<filters::one_pole<NV>, 0>;
template <int NV>
using FilePitchMod = parameter::plain<Files_impl::pma20_t<NV>, 
                                      1>;
template <int NV>
using PitchWin = parameter::plain<Files_impl::pma_unscaled_t<NV>, 
                                  2>;
template <int NV>
using WinMod = parameter::plain<Files_impl::pma_unscaled_t<NV>, 
                                1>;
template <int NV>
using FileXrossFade = parameter::plain<Files_impl::pma19_t<NV>, 
                                       2>;
template <int NV>
using FileXrossFadeMod = parameter::plain<Files_impl::pma19_t<NV>, 
                                          1>;
template <int NV>
using _1pMod = parameter::plain<filters::one_pole<NV>, 4>;
using EnvDiv2 = parameter::empty;
template <int NV>
using PosAMod = parameter::plain<Files_impl::pma33_t<NV>, 
                                 1>;
template <int NV>
using PosA = parameter::plain<Files_impl::pma33_t<NV>, 
                              2>;
template <int NV>
using PosB = parameter::plain<Files_impl::pma32_t<NV>, 
                              2>;
template <int NV>
using PosBmod = parameter::plain<Files_impl::pma32_t<NV>, 
                                 1>;
template <int NV>
using PosC = parameter::plain<Files_impl::pma31_t<NV>, 
                              2>;
template <int NV>
using PosCMod = parameter::plain<Files_impl::pma31_t<NV>, 
                                 1>;
template <int NV>
using PosD = parameter::plain<Files_impl::pma34_t<NV>, 
                              2>;
template <int NV>
using PosDMod = parameter::plain<Files_impl::pma34_t<NV>, 
                                 1>;
using EnvOS1 = EnvDiv2;
using EnvOS2 = EnvDiv2;
template <int NV>
using RampTempo1 = parameter::plain<Files_impl::tempo_sync6_t<NV>, 
                                    0>;
template <int NV>
using RampTempo2 = parameter::plain<Files_impl::tempo_sync9_t<NV>, 
                                    0>;
template <int NV>
using RampInv1 = parameter::plain<Files_impl::branch36_t<NV>, 
                                  0>;
template <int NV>
using RampInv2 = parameter::plain<Files_impl::branch89_t<NV>, 
                                  0>;
template <int NV>
using RampTemo3 = parameter::plain<Files_impl::tempo_sync8_t<NV>, 
                                   0>;
template <int NV>
using RampTempo4 = parameter::plain<Files_impl::tempo_sync7_t<NV>, 
                                    0>;
template <int NV>
using RampInv3 = parameter::plain<Files_impl::branch46_t<NV>, 
                                  0>;
template <int NV>
using RampInv4 = parameter::plain<Files_impl::branch37_t<NV>, 
                                  0>;
template <int NV>
using RampOS1 = parameter::plain<Files_impl::ramp5_t<NV>, 
                                 1>;
template <int NV>
using RampOS2 = parameter::plain<Files_impl::ramp8_t<NV>, 
                                 1>;
template <int NV>
using RampOS3 = parameter::plain<Files_impl::ramp7_t<NV>, 
                                 1>;
template <int NV>
using RampOS4 = parameter::plain<Files_impl::ramp6_t<NV>, 
                                 1>;
template <int NV>
using Input = parameter::plain<Files_impl::pma_t<NV>, 2>;
template <int NV>
using InputMod = parameter::plain<Files_impl::pma_t<NV>, 1>;
template <int NV>
using Mix = parameter::plain<Files_impl::xfader_t<NV>, 
                             0>;
template <int NV>
using Trk1 = parameter::plain<Files_impl::branch_t<NV>, 
                              0>;
template <int NV>
using trk2 = parameter::plain<Files_impl::branch1_t<NV>, 
                              0>;
template <int NV>
using trk3 = parameter::plain<Files_impl::branch3_t<NV>, 
                              0>;
template <int NV>
using trk4 = parameter::plain<Files_impl::branch2_t<NV>, 
                              0>;
template <int NV>
using Files_t_plist = parameter::list<PositionMod<NV>, 
                                      Position<NV>, 
                                      QuantisePositiion<NV>, 
                                      PosSmooth<NV>, 
                                      FilePitch<NV>, 
                                      PtichShiftOn<NV>, 
                                      FilePitchMod<NV>, 
                                      PitchWin<NV>, 
                                      WinMod<NV>, 
                                      FileUser<NV>, 
                                      FileMidiPitch<NV>, 
                                      FileMidipos2<NV>, 
                                      FileWinPk<NV>, 
                                      FileMidiwindow<NV>, 
                                      FileMidPk<NV>, 
                                      FileInPk<NV>, 
                                      FileXrossFade<NV>, 
                                      FileXrossFadeMod<NV>, 
                                      FileXrossFadePk<NV>, 
                                      FileXrossFadeMode<NV>, 
                                      FileXrossFadeMidi<NV>, 
                                      FilePitchPk<NV>, 
                                      feed, 
                                      _1pMod<NV>, 
                                      EnvDiv2, 
                                      PosAMod<NV>, 
                                      PosA<NV>, 
                                      PosB<NV>, 
                                      PosBmod<NV>, 
                                      PosC<NV>, 
                                      PosCMod<NV>, 
                                      PosD<NV>, 
                                      PosDMod<NV>, 
                                      EnvOS1, 
                                      EnvOS2, 
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
                                      RampOS4<NV>, 
                                      InputMidi<NV>, 
                                      Input<NV>, 
                                      InputMod<NV>, 
                                      Mix<NV>, 
                                      Trk1<NV>, 
                                      trk2<NV>, 
                                      trk3<NV>, 
                                      trk4<NV>>;
}

template <int NV>
using Files_t_ = container::chain<Files_t_parameters::Files_t_plist<NV>, 
                                  wrap::fix<2, chain59_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Files_impl::Files_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 13;
		static const int NumSliderPacks = 20;
		static const int NumAudioFiles = 8;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(Files);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1018)
		{
			0x005B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x4D6E, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0001, 0x0000, 0x6F50, 0x6973, 0x6974, 
            0x6E6F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 0x0000, 0x7551, 0x6E61, 
            0x6974, 0x6573, 0x6F50, 0x6973, 0x6974, 0x6F69, 0x006E, 0x0000, 
            0x3F80, 0x0000, 0x4110, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x035B, 0x0000, 0x5000, 0x736F, 0x6D53, 0x6F6F, 0x6874, 
            0x0000, 0xA000, 0x0041, 0x9C40, 0x0046, 0x4790, 0x1A45, 0x6B6C, 
            0x003E, 0x0000, 0x5B00, 0x0004, 0x0000, 0x6946, 0x656C, 0x6950, 
            0x6374, 0x0068, 0x0000, 0xC1C0, 0x0000, 0x41C0, 0x0000, 0xC1C0, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x5000, 0x6974, 
            0x6863, 0x6853, 0x6669, 0x4F74, 0x006E, 0x0000, 0x3F80, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x065B, 
            0x0000, 0x4600, 0x6C69, 0x5065, 0x7469, 0x6863, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x075B, 0x0000, 0x5000, 0x7469, 0x6863, 0x6957, 
            0x006E, 0x0000, 0x4248, 0x4000, 0x461C, 0x147B, 0x42BA, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 0x5700, 0x6E69, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 0x4600, 0x6C69, 0x5565, 
            0x6573, 0x0072, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0A5B, 0x0000, 0x4600, 0x6C69, 
            0x4D65, 0x6469, 0x5069, 0x7469, 0x6863, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x000B, 0x0000, 0x6946, 0x656C, 0x694D, 0x6964, 0x6F70, 0x3273, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x000C, 0x0000, 0x6946, 0x656C, 0x6957, 
            0x506E, 0x006B, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0D5B, 0x0000, 0x4600, 0x6C69, 
            0x4D65, 0x6469, 0x7769, 0x6E69, 0x6F64, 0x0077, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0E5B, 0x0000, 0x4600, 0x6C69, 0x4D65, 0x6469, 0x6B50, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0040, 0x0000, 0x0040, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000F, 0x0000, 0x6946, 0x656C, 0x6E49, 0x6B50, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0010, 0x0000, 0x6946, 0x656C, 0x7258, 
            0x736F, 0x4673, 0x6461, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x115B, 0x0000, 
            0x4600, 0x6C69, 0x5865, 0x6F72, 0x7373, 0x6146, 0x6564, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x125B, 0x0000, 0x4600, 0x6C69, 0x5865, 
            0x6F72, 0x7373, 0x6146, 0x6564, 0x6B50, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0013, 0x0000, 0x6946, 0x656C, 0x7258, 0x736F, 0x4673, 0x6461, 
            0x4D65, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x145B, 0x0000, 0x4600, 
            0x6C69, 0x5865, 0x6F72, 0x7373, 0x6146, 0x6564, 0x694D, 0x6964, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0015, 0x0000, 0x6946, 0x656C, 0x6950, 
            0x6374, 0x5068, 0x006B, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x165B, 0x0000, 0x6600, 
            0x6565, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x175B, 0x0000, 0x5F00, 0x7031, 
            0x6F4D, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x185B, 0x0000, 0x4500, 0x766E, 
            0x6944, 0x3276, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0019, 0x0000, 0x6F50, 
            0x4173, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1A5B, 0x0000, 0x5000, 
            0x736F, 0x0041, 0x0000, 0x0000, 0x0000, 0x3F80, 0x28F6, 0x3EDC, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x1B5B, 0x0000, 0x5000, 0x736F, 
            0x0042, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x1C5B, 0x0000, 0x5000, 0x736F, 0x6D42, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x001D, 0x0000, 0x6F50, 0x4373, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x001E, 0x0000, 0x6F50, 0x4373, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x1F5B, 0x0000, 0x5000, 0x736F, 0x0044, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x205B, 0x0000, 0x5000, 0x736F, 0x4D44, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0021, 0x0000, 0x6E45, 0x4F76, 0x3153, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0022, 0x0000, 0x6E45, 0x4F76, 0x3253, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x7900, 0x003E, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0023, 0x0000, 0x6152, 0x706D, 0x6554, 
            0x706D, 0x316F, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0024, 0x0000, 0x6152, 
            0x706D, 0x6554, 0x706D, 0x326F, 0x0000, 0x0000, 0x0000, 0x9000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0025, 
            0x0000, 0x6152, 0x706D, 0x6944, 0x3176, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0042, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0026, 0x0000, 0x6152, 0x706D, 0x6944, 0x3276, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0042, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0027, 0x0000, 0x6152, 0x706D, 0x6E49, 0x3176, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0028, 0x0000, 0x6152, 0x706D, 0x6E49, 0x3276, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0029, 0x0000, 0x6152, 0x706D, 0x6554, 
            0x6F6D, 0x0033, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x2A5B, 0x0000, 0x5200, 0x6D61, 
            0x5470, 0x6D65, 0x6F70, 0x0034, 0x0000, 0x0000, 0x0000, 0x4190, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x2B5B, 0x0000, 
            0x5200, 0x6D61, 0x4470, 0x7669, 0x0033, 0x0000, 0x3F80, 0x0000, 
            0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x2C5B, 
            0x0000, 0x5200, 0x6D61, 0x4470, 0x7669, 0x0034, 0x0000, 0x3F80, 
            0x0000, 0x4200, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x2D5B, 0x0000, 0x5200, 0x6D61, 0x4970, 0x766E, 0x0033, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x2E5B, 0x0000, 0x5200, 0x6D61, 0x4970, 0x766E, 0x0034, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x2F5B, 0x0000, 0x5200, 0x6D61, 0x4F70, 0x3153, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0030, 0x0000, 0x6152, 0x706D, 0x534F, 
            0x0032, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x315B, 0x0000, 0x5200, 0x6D61, 0x4F70, 
            0x3353, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0032, 0x0000, 0x6152, 0x706D, 
            0x534F, 0x0034, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x335B, 0x0000, 0x4900, 0x706E, 
            0x7475, 0x694D, 0x6964, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0034, 0x0000, 
            0x6E49, 0x7570, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x1EB8, 
            0x3F45, 0x0000, 0x3F80, 0x0000, 0x0000, 0x355B, 0x0000, 0x4900, 
            0x706E, 0x7475, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x365B, 0x0000, 
            0x4D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0037, 0x0000, 0x7254, 
            0x316B, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0038, 0x0000, 0x7274, 0x326B, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0039, 0x0000, 0x7274, 0x336B, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x003A, 0x0000, 0x7274, 0x346B, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain59 = this->getT(0);                                                              // Files_impl::chain59_t<NV>
		auto& xfade_2x_lin = this->getT(0).getT(0);                                                 // Files_impl::xfade_2x_lin_t<NV>
		auto& xfader = this->getT(0).getT(0).getT(0);                                               // Files_impl::xfader_t<NV>
		auto& split20 = this->getT(0).getT(0).getT(1);                                              // Files_impl::split20_t<NV>
		auto& chain = this->getT(0).getT(0).getT(1).getT(0);                                        // Files_impl::chain_t<NV>
		auto& gain = this->getT(0).getT(0).getT(1).getT(0).getT(0);                                 // core::gain<NV>
		auto& chain73 = this->getT(0).getT(0).getT(1).getT(1);                                      // Files_impl::chain73_t<NV>
		auto& clear25 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                              // wrap::no_process<math::clear<NV>>
		auto& branch39 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                             // Files_impl::branch39_t<NV>
		auto& xfader1 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);                      // Files_impl::xfader1_t<NV>
		auto& xfader5 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(1);                      // Files_impl::xfader5_t<NV>
		auto& xfader6 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(2);                      // Files_impl::xfader6_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(3);                   // Files_impl::sliderbank_t<NV>
		auto& fix8_block = this->getT(0).getT(0).getT(1).getT(1).getT(2);                           // Files_impl::fix8_block_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0);                       // Files_impl::split2_t<NV>
		auto& modchain15 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0);           // Files_impl::modchain15_t<NV>
		auto& sliderbank15 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::sliderbank15_t<NV>
                             getT(2).getT(0).getT(0).getT(0);
		auto& split29 = this->getT(0).getT(0).getT(1).getT(1).                                      // Files_impl::split29_t<NV>
                        getT(2).getT(0).getT(0).getT(1);
		auto& chain392 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain392_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(0);
		auto& xfader71 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader71_t<NV>
                         getT(0).getT(0).getT(1).getT(0).getT(0);
		auto& soft_bypass65 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass65_t<NV>
                              getT(0).getT(0).getT(1).getT(0).getT(1);
		auto& chain275 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain275_t<NV>
                         getT(0).getT(0).getT(1).getT(0).getT(1).
                         getT(0);
		auto& global_cable51 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable51_t<NV>
                               getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);
		auto& add225 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);
		auto& gain140 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(0).getT(1).getT(0).getT(1).getT(0).getT(2);
		auto& chain407 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain407_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(1);
		auto& xfader79 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader79_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(0);
		auto& soft_bypass73 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass73_t<NV>
                              getT(0).getT(0).getT(1).getT(1).getT(1);
		auto& chain276 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain276_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(1).
                         getT(0);
		auto& global_cable52 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable52_t<NV>
                               getT(0).getT(1).getT(1).getT(1).getT(0).getT(0);
		auto& add226 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(0).getT(1).getT(1).getT(1).getT(0).getT(1);
		auto& gain141 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(0).getT(1).getT(1).getT(1).getT(0).getT(2);
		auto& chain406 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain406_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(2);
		auto& xfader78 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader78_t
                         getT(0).getT(0).getT(1).getT(2).getT(0);
		auto& soft_bypass72 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass72_t
                              getT(0).getT(0).getT(1).getT(2).getT(1);
		auto& chain277 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain277_t<NV>
                         getT(0).getT(0).getT(1).getT(2).getT(2);
		auto& global_cable53 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                       // Files_impl::global_cable53_t<NV>
                               getT(0).getT(0).getT(1).getT(2).getT(2).
                               getT(0);
		auto& add227 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                               // math::add<NV>
                       getT(0).getT(0).getT(1).getT(2).getT(2).
                       getT(1);
		auto& gain142 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                              // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(2).getT(2).
                        getT(2);
		auto& chain405 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain405_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(3);
		auto& xfader77 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader77_t<NV>
                         getT(0).getT(0).getT(1).getT(3).getT(0);
		auto& soft_bypass71 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass71_t<NV>
                              getT(0).getT(0).getT(1).getT(3).getT(1);
		auto& chain278 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain278_t<NV>
                         getT(0).getT(0).getT(1).getT(3).getT(1).
                         getT(0);
		auto& global_cable54 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable54_t<NV>
                               getT(0).getT(1).getT(3).getT(1).getT(0).getT(0);
		auto& add228 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(0).getT(1).getT(3).getT(1).getT(0).getT(1);
		auto& gain143 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(0).getT(1).getT(3).getT(1).getT(0).getT(2);
		auto& chain404 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain404_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(4);
		auto& xfader76 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader76_t<NV>
                         getT(0).getT(0).getT(1).getT(4).getT(0);
		auto& soft_bypass70 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass70_t<NV>
                              getT(0).getT(0).getT(1).getT(4).getT(1);
		auto& chain279 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain279_t<NV>
                         getT(0).getT(0).getT(1).getT(4).getT(1).
                         getT(0);
		auto& event_data_reader16 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).          // Files_impl::event_data_reader16_t<NV>
                                    getT(0).getT(1).getT(4).getT(1).getT(0).getT(0);
		auto& add229 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(0).getT(1).getT(4).getT(1).getT(0).getT(1);
		auto& gain144 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(0).getT(1).getT(4).getT(1).getT(0).getT(2);
		auto& chain403 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain403_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(5);
		auto& xfader75 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader75_t<NV>
                         getT(0).getT(0).getT(1).getT(5).getT(0);
		auto& soft_bypass69 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass69_t<NV>
                              getT(0).getT(0).getT(1).getT(5).getT(1);
		auto& chain280 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain280_t<NV>
                         getT(0).getT(0).getT(1).getT(5).getT(1).
                         getT(0);
		auto& event_data_reader17 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).          // Files_impl::event_data_reader17_t<NV>
                                    getT(0).getT(1).getT(5).getT(1).getT(0).getT(0);
		auto& add230 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(0).getT(1).getT(5).getT(1).getT(0).getT(1);
		auto& gain145 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(0).getT(1).getT(5).getT(1).getT(0).getT(2);
		auto& chain402 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain402_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(6);
		auto& xfader74 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader74_t<NV>
                         getT(0).getT(0).getT(1).getT(6).getT(0);
		auto& soft_bypass68 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass68_t<NV>
                              getT(0).getT(0).getT(1).getT(6).getT(1);
		auto& chain281 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain281_t<NV>
                         getT(0).getT(0).getT(1).getT(6).getT(1).
                         getT(0);
		auto& branch15 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::branch15_t<NV>
                         getT(0).getT(1).getT(6).getT(1).getT(0).getT(0);
		auto& chain384 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain384_t<NV>
                         getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(0);
		auto& event_data_reader = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).    // Files_impl::event_data_reader_t<NV>
                                  getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& add3 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).                 // math::add<NV>
                     getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain395 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain395_t<NV>
                         getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(1);
		auto& event_data_reader3 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).   // Files_impl::event_data_reader3_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(1).getT(1);
		auto& chain394 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain394_t<NV>
                         getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(2);
		auto& event_data_reader2 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).   // Files_impl::event_data_reader2_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add15 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& chain393 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain393_t<NV>
                         getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(3);
		auto& event_data_reader1 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).   // Files_impl::event_data_reader1_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& add14 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& add235 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(0).getT(1).getT(6).getT(1).getT(0).getT(1);
		auto& gain146 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(0).getT(1).getT(6).getT(1).getT(0).getT(2);
		auto& chain401 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain401_t<NV>
                         getT(2).getT(0).getT(0).getT(1).
                         getT(7);
		auto& xfader73 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader73_t<NV>
                         getT(0).getT(0).getT(1).getT(7).getT(0);
		auto& soft_bypass67 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass67_t<NV>
                              getT(0).getT(0).getT(1).getT(7).getT(1);
		auto& chain282 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain282_t<NV>
                         getT(0).getT(0).getT(1).getT(7).getT(1).
                         getT(0);
		auto& branch56 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::branch56_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0);
		auto& chain283 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain283_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(0);
		auto& midi_cc51 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).            // Files_impl::midi_cc51_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& add236 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain284 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain284_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(1);
		auto& midi_cc52 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).            // Files_impl::midi_cc52_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& add237 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).getT(1);
		auto& chain285 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain285_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(2);
		auto& midi_cc53 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).            // Files_impl::midi_cc53_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add238 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& chain286 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain286_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(3);
		auto& midi_cc54 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).            // Files_impl::midi_cc54_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& add239 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& chain287 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain287_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(4);
		auto& midi38 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // Files_impl::midi38_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).getT(0);
		auto& add240 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).getT(1);
		auto& chain288 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain288_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(5);
		auto& midi39 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // Files_impl::midi39_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).getT(0);
		auto& add241 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).getT(1);
		auto& chain289 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain289_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(6);
		auto& midi40 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // Files_impl::midi40_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).getT(0);
		auto& add242 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(0).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).getT(1);
		auto& gain147 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(0).getT(1).getT(7).getT(1).getT(0).getT(1);
		auto& peak35 = this->getT(0).getT(0).getT(1).getT(1).                                       // Files_impl::peak35_t<NV>
                       getT(2).getT(0).getT(0).getT(2);
		auto& pma19 = this->getT(0).getT(0).getT(1).getT(1).                                        // Files_impl::pma19_t<NV>
                      getT(2).getT(0).getT(0).getT(3);
		auto& modchain17 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1);           // Files_impl::modchain17_t<NV>
		auto& sliderbank16 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::sliderbank16_t<NV>
                             getT(2).getT(0).getT(1).getT(0);
		auto& split33 = this->getT(0).getT(0).getT(1).getT(1).                                      // Files_impl::split33_t<NV>
                        getT(2).getT(0).getT(1).getT(1);
		auto& chain400 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain400_t<NV>
                         getT(2).getT(0).getT(1).getT(1).
                         getT(0);
		auto& xfader72 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader72_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(0);
		auto& soft_bypass66 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass66_t<NV>
                              getT(0).getT(1).getT(1).getT(0).getT(1);
		auto& chain290 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain290_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(1).
                         getT(0);
		auto& global_cable55 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable55_t<NV>
                               getT(1).getT(1).getT(0).getT(1).getT(0).getT(0);
		auto& add243 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(1).getT(1).getT(0).getT(1).getT(0).getT(1);
		auto& gain228 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(1).getT(1).getT(0).getT(1).getT(0).getT(2);
		auto& chain414 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain414_t<NV>
                         getT(2).getT(0).getT(1).getT(1).
                         getT(1);
		auto& xfader86 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader86_t<NV>
                         getT(0).getT(1).getT(1).getT(1).getT(0);
		auto& soft_bypass80 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass80_t<NV>
                              getT(0).getT(1).getT(1).getT(1).getT(1);
		auto& chain291 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain291_t<NV>
                         getT(0).getT(1).getT(1).getT(1).getT(1).
                         getT(0);
		auto& global_cable56 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable56_t<NV>
                               getT(1).getT(1).getT(1).getT(1).getT(0).getT(0);
		auto& add244 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(1).getT(1).getT(1).getT(1).getT(0).getT(1);
		auto& gain229 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(1).getT(1).getT(1).getT(1).getT(0).getT(2);
		auto& chain413 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain413_t<NV>
                         getT(2).getT(0).getT(1).getT(1).
                         getT(2);
		auto& xfader85 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader85_t<NV>
                         getT(0).getT(1).getT(1).getT(2).getT(0);
		auto& soft_bypass79 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass79_t<NV>
                              getT(0).getT(1).getT(1).getT(2).getT(1);
		auto& chain292 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain292_t<NV>
                         getT(0).getT(1).getT(1).getT(2).getT(1).
                         getT(0);
		auto& global_cable57 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable57_t<NV>
                               getT(1).getT(1).getT(2).getT(1).getT(0).getT(0);
		auto& add245 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(1).getT(1).getT(2).getT(1).getT(0).getT(1);
		auto& gain230 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(1).getT(1).getT(2).getT(1).getT(0).getT(2);
		auto& chain412 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain412_t<NV>
                         getT(2).getT(0).getT(1).getT(1).
                         getT(3);
		auto& xfader84 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader84_t
                         getT(0).getT(1).getT(1).getT(3).getT(0);
		auto& soft_bypass78 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass78_t
                              getT(0).getT(1).getT(1).getT(3).getT(1);
		auto& chain293 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain293_t<NV>
                         getT(0).getT(1).getT(1).getT(3).getT(2);
		auto& global_cable58 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                       // Files_impl::global_cable58_t<NV>
                               getT(0).getT(1).getT(1).getT(3).getT(2).
                               getT(0);
		auto& add246 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                               // math::add<NV>
                       getT(0).getT(1).getT(1).getT(3).getT(2).
                       getT(1);
		auto& gain231 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                              // core::gain<NV>
                        getT(0).getT(1).getT(1).getT(3).getT(2).
                        getT(2);
		auto& chain411 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain411_t<NV>
                         getT(2).getT(0).getT(1).getT(1).
                         getT(4);
		auto& xfader83 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader83_t<NV>
                         getT(0).getT(1).getT(1).getT(4).getT(0);
		auto& soft_bypass77 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass77_t<NV>
                              getT(0).getT(1).getT(1).getT(4).getT(1);
		auto& chain294 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain294_t<NV>
                         getT(0).getT(1).getT(1).getT(4).getT(1).
                         getT(0);
		auto& event_data_reader18 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).          // Files_impl::event_data_reader18_t<NV>
                                    getT(1).getT(1).getT(4).getT(1).getT(0).getT(0);
		auto& add247 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(1).getT(1).getT(4).getT(1).getT(0).getT(1);
		auto& gain232 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(1).getT(1).getT(4).getT(1).getT(0).getT(2);
		auto& chain410 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain410_t<NV>
                         getT(2).getT(0).getT(1).getT(1).
                         getT(5);
		auto& xfader82 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader82_t<NV>
                         getT(0).getT(1).getT(1).getT(5).getT(0);
		auto& soft_bypass76 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass76_t<NV>
                              getT(0).getT(1).getT(1).getT(5).getT(1);
		auto& chain295 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain295_t<NV>
                         getT(0).getT(1).getT(1).getT(5).getT(1).
                         getT(0);
		auto& event_data_reader19 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).          // Files_impl::event_data_reader19_t<NV>
                                    getT(1).getT(1).getT(5).getT(1).getT(0).getT(0);
		auto& add248 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(1).getT(1).getT(5).getT(1).getT(0).getT(1);
		auto& gain233 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(1).getT(1).getT(5).getT(1).getT(0).getT(2);
		auto& chain409 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain409_t<NV>
                         getT(2).getT(0).getT(1).getT(1).
                         getT(6);
		auto& xfader81 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader81_t<NV>
                         getT(0).getT(1).getT(1).getT(6).getT(0);
		auto& soft_bypass75 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass75_t<NV>
                              getT(0).getT(1).getT(1).getT(6).getT(1);
		auto& chain296 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain296_t<NV>
                         getT(0).getT(1).getT(1).getT(6).getT(1).
                         getT(0);
		auto& branch16 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::branch16_t<NV>
                         getT(1).getT(1).getT(6).getT(1).getT(0).getT(0);
		auto& chain385 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain385_t<NV>
                         getT(1).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(0);
		auto& event_data_reader4 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).   // Files_impl::event_data_reader4_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& add4 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).                 // math::add<NV>
                     getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain396 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain396_t<NV>
                         getT(1).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(1);
		auto& event_data_reader5 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).   // Files_impl::event_data_reader5_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(1).getT(1);
		auto& chain397 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain397_t<NV>
                         getT(1).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(2);
		auto& event_data_reader6 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).   // Files_impl::event_data_reader6_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& chain398 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain398_t<NV>
                         getT(1).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(3);
		auto& event_data_reader7 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).   // Files_impl::event_data_reader7_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& add253 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(1).getT(1).getT(6).getT(1).getT(0).getT(1);
		auto& gain234 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(1).getT(1).getT(6).getT(1).getT(0).getT(2);
		auto& chain408 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain408_t<NV>
                         getT(2).getT(0).getT(1).getT(1).
                         getT(7);
		auto& xfader80 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader80_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(0);
		auto& soft_bypass74 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass74_t<NV>
                              getT(0).getT(1).getT(1).getT(7).getT(1);
		auto& chain297 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain297_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(1).
                         getT(0);
		auto& branch58 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::branch58_t<NV>
                         getT(1).getT(1).getT(7).getT(1).getT(0).getT(0);
		auto& chain298 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain298_t<NV>
                         getT(1).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(0);
		auto& midi_cc55 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).            // Files_impl::midi_cc55_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& add394 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain299 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain299_t<NV>
                         getT(1).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(1);
		auto& midi_cc56 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).            // Files_impl::midi_cc56_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& add395 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).getT(1);
		auto& chain426 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain426_t<NV>
                         getT(1).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(2);
		auto& midi_cc57 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).            // Files_impl::midi_cc57_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add396 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& chain451 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain451_t<NV>
                         getT(1).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(3);
		auto& midi_cc58 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).            // Files_impl::midi_cc58_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& add397 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& chain452 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain452_t<NV>
                         getT(1).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(4);
		auto& midi41 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // Files_impl::midi41_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).getT(0);
		auto& add398 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).getT(1);
		auto& chain453 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain453_t<NV>
                         getT(1).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(5);
		auto& midi43 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // Files_impl::midi43_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).getT(0);
		auto& add399 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).getT(1);
		auto& chain454 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain454_t<NV>
                         getT(1).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(6);
		auto& midi44 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // Files_impl::midi44_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).getT(0);
		auto& add400 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(1).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).getT(1);
		auto& gain235 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(1).getT(1).getT(7).getT(1).getT(0).getT(1);
		auto& peak36 = this->getT(0).getT(0).getT(1).getT(1).                                       // Files_impl::peak36_t<NV>
                       getT(2).getT(0).getT(1).getT(2);
		auto& pma20 = this->getT(0).getT(0).getT(1).getT(1).                                        // Files_impl::pma20_t<NV>
                      getT(2).getT(0).getT(1).getT(3);
		auto& modchain18 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2);           // Files_impl::modchain18_t<NV>
		auto& sliderbank17 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::sliderbank17_t<NV>
                             getT(2).getT(0).getT(2).getT(0);
		auto& split34 = this->getT(0).getT(0).getT(1).getT(1).                                      // Files_impl::split34_t<NV>
                        getT(2).getT(0).getT(2).getT(1);
		auto& chain415 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain415_t<NV>
                         getT(2).getT(0).getT(2).getT(1).
                         getT(0);
		auto& xfader87 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader87_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(0);
		auto& soft_bypass81 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass81_t<NV>
                              getT(0).getT(2).getT(1).getT(0).getT(1);
		auto& chain300 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain300_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(1).
                         getT(0);
		auto& global_cable59 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable59_t<NV>
                               getT(2).getT(1).getT(0).getT(1).getT(0).getT(0);
		auto& add254 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(2).getT(1).getT(0).getT(1).getT(0).getT(1);
		auto& gain236 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(2).getT(1).getT(0).getT(1).getT(0).getT(2);
		auto& chain423 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain423_t<NV>
                         getT(2).getT(0).getT(2).getT(1).
                         getT(1);
		auto& xfader95 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader95_t<NV>
                         getT(0).getT(2).getT(1).getT(1).getT(0);
		auto& soft_bypass89 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass89_t<NV>
                              getT(0).getT(2).getT(1).getT(1).getT(1);
		auto& chain301 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain301_t<NV>
                         getT(0).getT(2).getT(1).getT(1).getT(1).
                         getT(0);
		auto& global_cable60 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable60_t<NV>
                               getT(2).getT(1).getT(1).getT(1).getT(0).getT(0);
		auto& add255 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(2).getT(1).getT(1).getT(1).getT(0).getT(1);
		auto& gain237 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(2).getT(1).getT(1).getT(1).getT(0).getT(2);
		auto& chain422 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain422_t<NV>
                         getT(2).getT(0).getT(2).getT(1).
                         getT(2);
		auto& xfader94 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader94_t<NV>
                         getT(0).getT(2).getT(1).getT(2).getT(0);
		auto& soft_bypass88 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass88_t<NV>
                              getT(0).getT(2).getT(1).getT(2).getT(1);
		auto& chain302 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain302_t<NV>
                         getT(0).getT(2).getT(1).getT(2).getT(1).
                         getT(0);
		auto& global_cable61 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable61_t<NV>
                               getT(2).getT(1).getT(2).getT(1).getT(0).getT(0);
		auto& add256 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(2).getT(1).getT(2).getT(1).getT(0).getT(1);
		auto& gain238 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(2).getT(1).getT(2).getT(1).getT(0).getT(2);
		auto& chain421 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain421_t<NV>
                         getT(2).getT(0).getT(2).getT(1).
                         getT(3);
		auto& xfader93 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader93_t<NV>
                         getT(0).getT(2).getT(1).getT(3).getT(0);
		auto& soft_bypass87 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass87_t<NV>
                              getT(0).getT(2).getT(1).getT(3).getT(1);
		auto& chain303 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain303_t<NV>
                         getT(0).getT(2).getT(1).getT(3).getT(1).
                         getT(0);
		auto& global_cable62 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable62_t<NV>
                               getT(2).getT(1).getT(3).getT(1).getT(0).getT(0);
		auto& add257 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(2).getT(1).getT(3).getT(1).getT(0).getT(1);
		auto& gain239 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(2).getT(1).getT(3).getT(1).getT(0).getT(2);
		auto& chain420 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain420_t<NV>
                         getT(2).getT(0).getT(2).getT(1).
                         getT(4);
		auto& xfader92 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader92_t<NV>
                         getT(0).getT(2).getT(1).getT(4).getT(0);
		auto& soft_bypass86 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass86_t<NV>
                              getT(0).getT(2).getT(1).getT(4).getT(1);
		auto& chain304 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain304_t<NV>
                         getT(0).getT(2).getT(1).getT(4).getT(1).
                         getT(0);
		auto& event_data_reader20 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).          // Files_impl::event_data_reader20_t<NV>
                                    getT(2).getT(1).getT(4).getT(1).getT(0).getT(0);
		auto& add258 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(2).getT(1).getT(4).getT(1).getT(0).getT(1);
		auto& gain240 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(2).getT(1).getT(4).getT(1).getT(0).getT(2);
		auto& chain419 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain419_t<NV>
                         getT(2).getT(0).getT(2).getT(1).
                         getT(5);
		auto& xfader91 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader91_t<NV>
                         getT(0).getT(2).getT(1).getT(5).getT(0);
		auto& soft_bypass85 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass85_t<NV>
                              getT(0).getT(2).getT(1).getT(5).getT(1);
		auto& chain305 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain305_t<NV>
                         getT(0).getT(2).getT(1).getT(5).getT(1).
                         getT(0);
		auto& event_data_reader21 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).          // Files_impl::event_data_reader21_t<NV>
                                    getT(2).getT(1).getT(5).getT(1).getT(0).getT(0);
		auto& add259 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(2).getT(1).getT(5).getT(1).getT(0).getT(1);
		auto& gain241 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(2).getT(1).getT(5).getT(1).getT(0).getT(2);
		auto& chain418 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain418_t<NV>
                         getT(2).getT(0).getT(2).getT(1).
                         getT(6);
		auto& xfader90 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader90_t<NV>
                         getT(0).getT(2).getT(1).getT(6).getT(0);
		auto& soft_bypass84 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass84_t<NV>
                              getT(0).getT(2).getT(1).getT(6).getT(1);
		auto& chain306 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain306_t<NV>
                         getT(0).getT(2).getT(1).getT(6).getT(1).
                         getT(0);
		auto& branch19 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::branch19_t<NV>
                         getT(2).getT(1).getT(6).getT(1).getT(0).getT(0);
		auto& chain386 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain386_t<NV>
                         getT(2).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(0);
		auto& event_data_reader8 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).   // Files_impl::event_data_reader8_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& add5 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).                 // math::add<NV>
                     getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain399 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain399_t<NV>
                         getT(2).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(1);
		auto& event_data_reader9 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).   // Files_impl::event_data_reader9_t<NV>
                                   getT(1).getT(6).getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(1).getT(1);
		auto& chain416 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain416_t<NV>
                         getT(2).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(2);
		auto& event_data_reader10 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).  // Files_impl::event_data_reader10_t<NV>
                                    getT(1).getT(6).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& chain424 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain424_t<NV>
                         getT(2).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(3);
		auto& event_data_reader11 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).  // Files_impl::event_data_reader11_t<NV>
                                    getT(1).getT(6).getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& add264 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(2).getT(1).getT(6).getT(1).getT(0).getT(1);
		auto& gain242 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(2).getT(1).getT(6).getT(1).getT(0).getT(2);
		auto& chain417 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain417_t<NV>
                         getT(2).getT(0).getT(2).getT(1).
                         getT(7);
		auto& xfader89 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader89_t<NV>
                         getT(0).getT(2).getT(1).getT(7).getT(0);
		auto& soft_bypass83 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass83_t<NV>
                              getT(0).getT(2).getT(1).getT(7).getT(1);
		auto& chain307 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain307_t<NV>
                         getT(0).getT(2).getT(1).getT(7).getT(1).
                         getT(0);
		auto& branch60 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::branch60_t<NV>
                         getT(2).getT(1).getT(7).getT(1).getT(0).getT(0);
		auto& chain308 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain308_t<NV>
                         getT(2).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(0);
		auto& midi_cc59 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).            // Files_impl::midi_cc59_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& add401 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain309 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain309_t<NV>
                         getT(2).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(1);
		auto& midi_cc60 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).            // Files_impl::midi_cc60_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& add402 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).getT(1);
		auto& chain427 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain427_t<NV>
                         getT(2).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(2);
		auto& midi_cc61 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).            // Files_impl::midi_cc61_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add403 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& chain455 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain455_t<NV>
                         getT(2).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(3);
		auto& midi_cc62 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).            // Files_impl::midi_cc62_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& add404 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& chain456 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain456_t<NV>
                         getT(2).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(4);
		auto& midi45 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // Files_impl::midi45_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).getT(0);
		auto& add405 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).getT(1);
		auto& chain457 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain457_t<NV>
                         getT(2).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(5);
		auto& midi46 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // Files_impl::midi46_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).getT(0);
		auto& add406 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).getT(1);
		auto& chain458 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain458_t<NV>
                         getT(2).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(6);
		auto& midi47 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // Files_impl::midi47_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).getT(0);
		auto& add407 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(2).               // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).getT(1);
		auto& gain243 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(2).getT(1).getT(7).getT(1).getT(0).getT(1);
		auto& peak_unscaled = this->getT(0).getT(0).getT(1).getT(1).                                // Files_impl::peak_unscaled_t<NV>
                              getT(2).getT(0).getT(2).getT(2);
		auto& peak37 = this->getT(0).getT(0).getT(1).getT(1).                                       // Files_impl::peak37_t
                       getT(2).getT(0).getT(2).getT(3);
		auto& pma_unscaled = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::pma_unscaled_t<NV>
                             getT(2).getT(0).getT(2).getT(4);
		auto& modchain19 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3);           // Files_impl::modchain19_t<NV>
		auto& sliderbank18 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::sliderbank18_t<NV>
                             getT(2).getT(0).getT(3).getT(0);
		auto& split35 = this->getT(0).getT(0).getT(1).getT(1).                                      // Files_impl::split35_t<NV>
                        getT(2).getT(0).getT(3).getT(1);
		auto& chain425 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain425_t<NV>
                         getT(2).getT(0).getT(3).getT(1).
                         getT(0);
		auto& xfader88 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader88_t<NV>
                         getT(0).getT(3).getT(1).getT(0).getT(0);
		auto& soft_bypass82 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass82_t<NV>
                              getT(0).getT(3).getT(1).getT(0).getT(1);
		auto& chain310 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain310_t<NV>
                         getT(0).getT(3).getT(1).getT(0).getT(1).
                         getT(0);
		auto& global_cable63 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable63_t<NV>
                               getT(3).getT(1).getT(0).getT(1).getT(0).getT(0);
		auto& add265 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(3).getT(1).getT(0).getT(1).getT(0).getT(1);
		auto& gain244 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(3).getT(1).getT(0).getT(1).getT(0).getT(2);
		auto& chain428 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain428_t<NV>
                         getT(2).getT(0).getT(3).getT(1).
                         getT(1);
		auto& xfader96 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader96_t<NV>
                         getT(0).getT(3).getT(1).getT(1).getT(0);
		auto& soft_bypass90 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass90_t<NV>
                              getT(0).getT(3).getT(1).getT(1).getT(1);
		auto& chain311 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain311_t<NV>
                         getT(0).getT(3).getT(1).getT(1).getT(1).
                         getT(0);
		auto& global_cable64 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable64_t<NV>
                               getT(3).getT(1).getT(1).getT(1).getT(0).getT(0);
		auto& add266 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(3).getT(1).getT(1).getT(1).getT(0).getT(1);
		auto& gain245 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(3).getT(1).getT(1).getT(1).getT(0).getT(2);
		auto& chain429 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain429_t<NV>
                         getT(2).getT(0).getT(3).getT(1).
                         getT(2);
		auto& xfader97 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader97_t<NV>
                         getT(0).getT(3).getT(1).getT(2).getT(0);
		auto& soft_bypass91 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass91_t<NV>
                              getT(0).getT(3).getT(1).getT(2).getT(1);
		auto& chain312 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain312_t<NV>
                         getT(0).getT(3).getT(1).getT(2).getT(1).
                         getT(0);
		auto& global_cable65 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable65_t<NV>
                               getT(3).getT(1).getT(2).getT(1).getT(0).getT(0);
		auto& add267 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(3).getT(1).getT(2).getT(1).getT(0).getT(1);
		auto& gain246 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(3).getT(1).getT(2).getT(1).getT(0).getT(2);
		auto& chain430 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain430_t<NV>
                         getT(2).getT(0).getT(3).getT(1).
                         getT(3);
		auto& xfader98 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader98_t<NV>
                         getT(0).getT(3).getT(1).getT(3).getT(0);
		auto& soft_bypass92 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass92_t<NV>
                              getT(0).getT(3).getT(1).getT(3).getT(1);
		auto& chain313 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain313_t<NV>
                         getT(0).getT(3).getT(1).getT(3).getT(1).
                         getT(0);
		auto& global_cable66 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // Files_impl::global_cable66_t<NV>
                               getT(3).getT(1).getT(3).getT(1).getT(0).getT(0);
		auto& add268 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(3).getT(1).getT(3).getT(1).getT(0).getT(1);
		auto& gain247 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(3).getT(1).getT(3).getT(1).getT(0).getT(2);
		auto& chain431 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain431_t<NV>
                         getT(2).getT(0).getT(3).getT(1).
                         getT(4);
		auto& xfader99 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::xfader99_t<NV>
                         getT(0).getT(3).getT(1).getT(4).getT(0);
		auto& soft_bypass93 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass93_t<NV>
                              getT(0).getT(3).getT(1).getT(4).getT(1);
		auto& chain314 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain314_t<NV>
                         getT(0).getT(3).getT(1).getT(4).getT(1).
                         getT(0);
		auto& event_data_reader22 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).          // Files_impl::event_data_reader22_t<NV>
                                    getT(3).getT(1).getT(4).getT(1).getT(0).getT(0);
		auto& add269 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(3).getT(1).getT(4).getT(1).getT(0).getT(1);
		auto& gain248 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(3).getT(1).getT(4).getT(1).getT(0).getT(2);
		auto& chain432 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain432_t<NV>
                         getT(2).getT(0).getT(3).getT(1).
                         getT(5);
		auto& xfader100 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                            // Files_impl::xfader100_t<NV>
                          getT(0).getT(3).getT(1).getT(5).getT(0);
		auto& soft_bypass94 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass94_t<NV>
                              getT(0).getT(3).getT(1).getT(5).getT(1);
		auto& chain315 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain315_t<NV>
                         getT(0).getT(3).getT(1).getT(5).getT(1).
                         getT(0);
		auto& event_data_reader23 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).          // Files_impl::event_data_reader23_t<NV>
                                    getT(3).getT(1).getT(5).getT(1).getT(0).getT(0);
		auto& add270 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                       // math::add<NV>
                       getT(3).getT(1).getT(5).getT(1).getT(0).getT(1);
		auto& gain249 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                      // core::gain<NV>
                        getT(3).getT(1).getT(5).getT(1).getT(0).getT(2);
		auto& chain433 = this->getT(0).getT(0).getT(1).getT(1).                                     // Files_impl::chain433_t<NV>
                         getT(2).getT(0).getT(3).getT(1).
                         getT(6);
		auto& xfader101 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                            // Files_impl::xfader101_t<NV>
                          getT(0).getT(3).getT(1).getT(6).getT(0);
		auto& soft_bypass95 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::soft_bypass95_t<NV>
                              getT(0).getT(3).getT(1).getT(6).getT(1);
		auto& chain316 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                             // Files_impl::chain316_t<NV>
                         getT(0).getT(3).getT(1).getT(6).getT(1).
                         getT(0);
		auto& branch20 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::branch20_t<NV>
                         getT(3).getT(1).getT(6).getT(1).getT(0).getT(0);
		auto& chain387 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain387_t<NV>
                         getT(3).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(0);
		auto& event_data_reader12 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).  // Files_impl::event_data_reader12_t<NV>
                                    getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& add6 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).                 // math::add<NV>
                     getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain434 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain434_t<NV>
                         getT(3).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(1);
		auto& event_data_reader13 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).  // Files_impl::event_data_reader13_t<NV>
                                    getT(1).getT(6).getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& add24 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(1).getT(1);
		auto& chain435 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain435_t<NV>
                         getT(3).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(2);
		auto& event_data_reader14 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).  // Files_impl::event_data_reader14_t<NV>
                                    getT(1).getT(6).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add25 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).                // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& chain436 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                     // Files_impl::chain436_t<NV>
                         getT(3).getT(1).getT(6).getT(1).getT(0).getT(0).
                         getT(3);
		auto& event_data_reader15 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).  // Files_impl::event_data_reader15_t<NV>
                                    getT(1).getT(6).getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).         // math::add<NV>
                      getT(1).getT(6).getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& add271 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).                // math::add<NV>
                       getT(3).getT(1).getT(6).getT(1).getT(0).getT(1);
		auto& gain250 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // core::gain<NV>
                        getT(3).getT(1).getT(6).getT(1).getT(0).getT(2);
		auto& chain437 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain437_t<NV>
                         getT(2).getT(0).getT(3).getT(1).
                         getT(7);
		auto& xfader102 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader102_t<NV>
                          getT(0).getT(3).getT(1).getT(7).getT(0);
		auto& soft_bypass96 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                 // Files_impl::soft_bypass96_t<NV>
                              getT(0).getT(3).getT(1).getT(7).getT(1);
		auto& chain317 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain317_t<NV>
                         getT(0).getT(3).getT(1).getT(7).getT(1).
                         getT(0);
		auto& branch61 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).              // Files_impl::branch61_t<NV>
                         getT(3).getT(1).getT(7).getT(1).getT(0).getT(0);
		auto& chain318 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).              // Files_impl::chain318_t<NV>
                         getT(3).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(0);
		auto& midi_cc63 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).     // Files_impl::midi_cc63_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& add408 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).getT(1);
		auto& chain319 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).              // Files_impl::chain319_t<NV>
                         getT(3).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(1);
		auto& midi_cc64 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).     // Files_impl::midi_cc64_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& add409 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).getT(1);
		auto& chain438 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).              // Files_impl::chain438_t<NV>
                         getT(3).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(2);
		auto& midi_cc65 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).     // Files_impl::midi_cc65_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& add410 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& chain459 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).              // Files_impl::chain459_t<NV>
                         getT(3).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(3);
		auto& midi_cc66 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).     // Files_impl::midi_cc66_t<NV>
                          getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).getT(0);
		auto& add411 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).getT(1);
		auto& chain460 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).              // Files_impl::chain460_t<NV>
                         getT(3).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(4);
		auto& midi48 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // Files_impl::midi48_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).getT(0);
		auto& add412 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).getT(1);
		auto& chain461 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).              // Files_impl::chain461_t<NV>
                         getT(3).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(5);
		auto& midi49 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // Files_impl::midi49_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).getT(0);
		auto& add413 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).getT(1);
		auto& chain462 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).              // Files_impl::chain462_t<NV>
                         getT(3).getT(1).getT(7).getT(1).getT(0).getT(0).
                         getT(6);
		auto& midi50 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // Files_impl::midi50_t<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).getT(0);
		auto& add414 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).getT(3).        // math::add<NV>
                       getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).getT(1);
		auto& gain251 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).               // core::gain<NV>
                        getT(3).getT(1).getT(7).getT(1).getT(0).getT(1);
		auto& peak38 = this->getT(0).getT(0).getT(1).getT(1).                                // Files_impl::peak38_t<NV>
                       getT(2).getT(0).getT(3).getT(2);
		auto& pma = this->getT(0).getT(0).getT(1).getT(1).                                   // Files_impl::pma_t<NV>
                    getT(2).getT(0).getT(3).getT(3);
		auto& gain1 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(1);                 // core::gain<NV>
		auto& one_pole = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(2);              // filters::one_pole<NV>
		auto& modchain8 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(3);             // Files_impl::modchain8_t<NV>
		auto& split23 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(3).getT(0);       // Files_impl::split23_t<NV>
		auto& chain178 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain178_t<NV>
                         getT(2).getT(3).getT(0).getT(0);
		auto& branch = this->getT(0).getT(0).getT(1).getT(1).                                // Files_impl::branch_t<NV>
                       getT(2).getT(3).getT(0).getT(0).
                       getT(0);
		auto& chain179 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain179_t<NV>
                         getT(3).getT(0).getT(0).getT(0).getT(0);
		auto& tempo_sync6 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                   // Files_impl::tempo_sync6_t<NV>
                            getT(3).getT(0).getT(0).getT(0).getT(0).
                            getT(0);
		auto& ramp5 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                         // Files_impl::ramp5_t<NV>
                      getT(3).getT(0).getT(0).getT(0).getT(0).
                      getT(1);
		auto& branch36 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch36_t<NV>
                         getT(3).getT(0).getT(0).getT(0).getT(0).
                         getT(2);
		auto& chain102 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(3).              // Files_impl::chain102_t
                         getT(0).getT(0).getT(0).getT(0).getT(2).getT(0);
		auto& mod_inv = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(3).               // math::mod_inv<NV>
                        getT(0).getT(0).getT(0).getT(0).getT(2).getT(1);
		auto& chain1 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::chain1_t<NV>
                       getT(3).getT(0).getT(0).getT(0).getT(1);
		auto& phasor = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::phasor<NV>
                       getT(3).getT(0).getT(0).getT(0).getT(1).
                       getT(0);
		auto& peak15 = this->getT(0).getT(0).getT(1).getT(1).                                // Files_impl::peak15_t<NV>
                       getT(2).getT(3).getT(0).getT(0).
                       getT(1);
		auto& clear26 = this->getT(0).getT(0).getT(1).getT(1).                               // math::clear<NV>
                        getT(2).getT(3).getT(0).getT(0).
                        getT(2);
		auto& branch1 = this->getT(0).getT(0).getT(1).getT(1).                               // Files_impl::branch1_t<NV>
                        getT(2).getT(3).getT(0).getT(1);
		auto& chain187 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain187_t<NV>
                         getT(2).getT(3).getT(0).getT(1).
                         getT(0);
		auto& chain188 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain188_t<NV>
                         getT(3).getT(0).getT(1).getT(0).getT(0);
		auto& tempo_sync9 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                   // Files_impl::tempo_sync9_t<NV>
                            getT(3).getT(0).getT(1).getT(0).getT(0).
                            getT(0);
		auto& ramp8 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                         // Files_impl::ramp8_t<NV>
                      getT(3).getT(0).getT(1).getT(0).getT(0).
                      getT(1);
		auto& branch89 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch89_t<NV>
                         getT(3).getT(0).getT(1).getT(0).getT(1);
		auto& chain105 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain105_t
                         getT(3).getT(0).getT(1).getT(0).getT(1).
                         getT(0);
		auto& mod_inv3 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // math::mod_inv<NV>
                         getT(3).getT(0).getT(1).getT(0).getT(1).
                         getT(1);
		auto& peak49 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::peak49_t<NV>
                       getT(3).getT(0).getT(1).getT(0).getT(2);
		auto& clear32 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                       // math::clear<NV>
                        getT(3).getT(0).getT(1).getT(0).getT(3);
		auto& chain4 = this->getT(0).getT(0).getT(1).getT(1).                                // Files_impl::chain4_t<NV>
                       getT(2).getT(3).getT(0).getT(1).
                       getT(1);
		auto& phasor3 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                       // core::phasor<NV>
                        getT(3).getT(0).getT(1).getT(1).getT(0);
		auto& branch3 = this->getT(0).getT(0).getT(1).getT(1).                               // Files_impl::branch3_t<NV>
                        getT(2).getT(3).getT(0).getT(2);
		auto& chain185 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain185_t<NV>
                         getT(2).getT(3).getT(0).getT(2).
                         getT(0);
		auto& chain186 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain186_t<NV>
                         getT(3).getT(0).getT(2).getT(0).getT(0);
		auto& tempo_sync8 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                   // Files_impl::tempo_sync8_t<NV>
                            getT(3).getT(0).getT(2).getT(0).getT(0).
                            getT(0);
		auto& ramp7 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                         // Files_impl::ramp7_t<NV>
                      getT(3).getT(0).getT(2).getT(0).getT(0).
                      getT(1);
		auto& branch46 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch46_t<NV>
                         getT(3).getT(0).getT(2).getT(0).getT(1);
		auto& chain104 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain104_t
                         getT(3).getT(0).getT(2).getT(0).getT(1).
                         getT(0);
		auto& mod_inv2 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // math::mod_inv<NV>
                         getT(3).getT(0).getT(2).getT(0).getT(1).
                         getT(1);
		auto& peak48 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::peak48_t<NV>
                       getT(3).getT(0).getT(2).getT(0).getT(2);
		auto& clear31 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                       // math::clear<NV>
                        getT(3).getT(0).getT(2).getT(0).getT(3);
		auto& chain3 = this->getT(0).getT(0).getT(1).getT(1).                                // Files_impl::chain3_t<NV>
                       getT(2).getT(3).getT(0).getT(2).
                       getT(1);
		auto& phasor2 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                       // core::phasor<NV>
                        getT(3).getT(0).getT(2).getT(1).getT(0);
		auto& branch2 = this->getT(0).getT(0).getT(1).getT(1).                               // Files_impl::branch2_t<NV>
                        getT(2).getT(3).getT(0).getT(3);
		auto& chain183 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain183_t<NV>
                         getT(2).getT(3).getT(0).getT(3).
                         getT(0);
		auto& chain184 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain184_t<NV>
                         getT(3).getT(0).getT(3).getT(0).getT(0);
		auto& tempo_sync7 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                   // Files_impl::tempo_sync7_t<NV>
                            getT(3).getT(0).getT(3).getT(0).getT(0).
                            getT(0);
		auto& ramp6 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                         // Files_impl::ramp6_t<NV>
                      getT(3).getT(0).getT(3).getT(0).getT(0).
                      getT(1);
		auto& branch37 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch37_t<NV>
                         getT(3).getT(0).getT(3).getT(0).getT(1);
		auto& chain103 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain103_t
                         getT(3).getT(0).getT(3).getT(0).getT(1).
                         getT(0);
		auto& mod_inv1 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // math::mod_inv<NV>
                         getT(3).getT(0).getT(3).getT(0).getT(1).
                         getT(1);
		auto& peak47 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::peak47_t<NV>
                       getT(3).getT(0).getT(3).getT(0).getT(2);
		auto& clear30 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                       // math::clear<NV>
                        getT(3).getT(0).getT(3).getT(0).getT(3);
		auto& chain2 = this->getT(0).getT(0).getT(1).getT(1).                                // Files_impl::chain2_t<NV>
                       getT(2).getT(3).getT(0).getT(3).
                       getT(1);
		auto& phasor1 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                       // core::phasor<NV>
                        getT(3).getT(0).getT(3).getT(1).getT(0);
		auto& chain247 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4);              // Files_impl::chain247_t<NV>
		auto& split10 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0);       // Files_impl::split10_t<NV>
		auto& modchain13 = this->getT(0).getT(0).getT(1).getT(1).                            // Files_impl::modchain13_t<NV>
                           getT(2).getT(4).getT(0).getT(0);
		auto& sliderbank13 = this->getT(0).getT(0).getT(1).getT(1).                          // Files_impl::sliderbank13_t<NV>
                             getT(2).getT(4).getT(0).getT(0).
                             getT(0);
		auto& split27 = this->getT(0).getT(0).getT(1).getT(1).                               // Files_impl::split27_t<NV>
                        getT(2).getT(4).getT(0).getT(0).
                        getT(1);
		auto& chain508 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain508_t<NV>
                         getT(4).getT(0).getT(0).getT(1).getT(0);
		auto& xfader135 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader135_t<NV>
                          getT(4).getT(0).getT(0).getT(1).getT(0).
                          getT(0);
		auto& soft_bypass129 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                // Files_impl::soft_bypass129_t<NV>
                               getT(4).getT(0).getT(0).getT(1).getT(0).
                               getT(1);
		auto& chain230 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::chain230_t<NV>
                         getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& global_cable43 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).        // Files_impl::global_cable43_t<NV>
                               getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).
                               getT(0);
		auto& add179 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).
                       getT(1);
		auto& gain124 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).
                        getT(2);
		auto& chain525 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain525_t<NV>
                         getT(4).getT(0).getT(0).getT(1).getT(1);
		auto& xfader142 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader142_t<NV>
                          getT(4).getT(0).getT(0).getT(1).getT(1).
                          getT(0);
		auto& soft_bypass136 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                // Files_impl::soft_bypass136_t<NV>
                               getT(4).getT(0).getT(0).getT(1).getT(1).
                               getT(1);
		auto& chain231 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::chain231_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);
		auto& global_cable44 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).        // Files_impl::global_cable44_t<NV>
                               getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).
                               getT(0);
		auto& add180 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).
                       getT(1);
		auto& gain125 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).
                        getT(2);
		auto& chain524 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain524_t<NV>
                         getT(4).getT(0).getT(0).getT(1).getT(2);
		auto& xfader141 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader141_t<NV>
                          getT(4).getT(0).getT(0).getT(1).getT(2).
                          getT(0);
		auto& soft_bypass135 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                // Files_impl::soft_bypass135_t<NV>
                               getT(4).getT(0).getT(0).getT(1).getT(2).
                               getT(1);
		auto& chain232 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::chain232_t<NV>
                         getT(0).getT(0).getT(1).getT(2).getT(1).getT(0);
		auto& global_cable45 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).        // Files_impl::global_cable45_t<NV>
                               getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).
                               getT(0);
		auto& add181 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).
                       getT(1);
		auto& gain126 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).
                        getT(2);
		auto& chain523 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain523_t<NV>
                         getT(4).getT(0).getT(0).getT(1).getT(3);
		auto& xfader140 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader140_t<NV>
                          getT(4).getT(0).getT(0).getT(1).getT(3).
                          getT(0);
		auto& soft_bypass134 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                // Files_impl::soft_bypass134_t<NV>
                               getT(4).getT(0).getT(0).getT(1).getT(3).
                               getT(1);
		auto& chain233 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::chain233_t<NV>
                         getT(0).getT(0).getT(1).getT(3).getT(1).getT(0);
		auto& global_cable46 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).        // Files_impl::global_cable46_t<NV>
                               getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).
                               getT(0);
		auto& add182 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).
                       getT(1);
		auto& gain127 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).
                        getT(2);
		auto& chain522 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain522_t<NV>
                         getT(4).getT(0).getT(0).getT(1).getT(4);
		auto& xfader139 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader139_t<NV>
                          getT(4).getT(0).getT(0).getT(1).getT(4).
                          getT(0);
		auto& soft_bypass133 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                // Files_impl::soft_bypass133_t<NV>
                               getT(4).getT(0).getT(0).getT(1).getT(4).
                               getT(1);
		auto& chain234 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::chain234_t<NV>
                         getT(0).getT(0).getT(1).getT(4).getT(1).getT(0);
		auto& event_data_reader24 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).   // Files_impl::event_data_reader24_t<NV>
                                    getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).
                                    getT(0);
		auto& add183 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).
                       getT(1);
		auto& gain128 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).
                        getT(2);
		auto& chain521 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain521_t<NV>
                         getT(4).getT(0).getT(0).getT(1).getT(5);
		auto& xfader138 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader138_t<NV>
                          getT(4).getT(0).getT(0).getT(1).getT(5).
                          getT(0);
		auto& soft_bypass132 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                // Files_impl::soft_bypass132_t<NV>
                               getT(4).getT(0).getT(0).getT(1).getT(5).
                               getT(1);
		auto& chain235 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::chain235_t<NV>
                         getT(0).getT(0).getT(1).getT(5).getT(1).getT(0);
		auto& event_data_reader25 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).   // Files_impl::event_data_reader25_t<NV>
                                    getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).
                                    getT(0);
		auto& add184 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).
                       getT(1);
		auto& gain129 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).
                        getT(2);
		auto& chain520 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain520_t<NV>
                         getT(4).getT(0).getT(0).getT(1).getT(6);
		auto& xfader137 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader137_t<NV>
                          getT(4).getT(0).getT(0).getT(1).getT(6).
                          getT(0);
		auto& soft_bypass131 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                // Files_impl::soft_bypass131_t<NV>
                               getT(4).getT(0).getT(0).getT(1).getT(6).
                               getT(1);
		auto& chain236 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::chain236_t<NV>
                         getT(0).getT(0).getT(1).getT(6).getT(1).getT(0);
		auto& branch51 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::branch51_t<NV>
                         getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).
                         getT(0);
		auto& add185 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).getT(0);
		auto& add186 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).getT(1);
		auto& add187 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).getT(2);
		auto& add188 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(6).getT(1).getT(0).getT(0).getT(3);
		auto& add189 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).
                       getT(1);
		auto& gain130 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).
                        getT(2);
		auto& chain509 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain509_t<NV>
                         getT(4).getT(0).getT(0).getT(1).getT(7);
		auto& xfader136 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                     // Files_impl::xfader136_t<NV>
                          getT(4).getT(0).getT(0).getT(1).getT(7).
                          getT(0);
		auto& soft_bypass130 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                // Files_impl::soft_bypass130_t<NV>
                               getT(4).getT(0).getT(0).getT(1).getT(7).
                               getT(1);
		auto& chain237 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::chain237_t<NV>
                         getT(0).getT(0).getT(1).getT(7).getT(1).getT(0);
		auto& branch52 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::branch52_t<NV>
                         getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).
                         getT(0);
		auto& chain238 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).      // Files_impl::chain238_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(0);
		auto& midi_cc43 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).     // Files_impl::midi_cc43_t<NV>
                          getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).
                          getT(0);
		auto& add190 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(0).
                       getT(1);
		auto& chain239 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).      // Files_impl::chain239_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(1);
		auto& midi_cc44 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).     // Files_impl::midi_cc44_t<NV>
                          getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).
                          getT(0);
		auto& add191 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(1).
                       getT(1);
		auto& chain240 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).      // Files_impl::chain240_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(2);
		auto& midi_cc45 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).     // Files_impl::midi_cc45_t<NV>
                          getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).
                          getT(0);
		auto& add192 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(2).
                       getT(1);
		auto& chain241 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).      // Files_impl::chain241_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(3);
		auto& midi_cc46 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).     // Files_impl::midi_cc46_t<NV>
                          getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).
                          getT(0);
		auto& add193 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(3).
                       getT(1);
		auto& chain242 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).      // Files_impl::chain242_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(4);
		auto& midi32 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // Files_impl::midi32_t<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).
                       getT(0);
		auto& add194 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(4).
                       getT(1);
		auto& chain243 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).      // Files_impl::chain243_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(5);
		auto& midi33 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // Files_impl::midi33_t<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).
                       getT(0);
		auto& add195 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(5).
                       getT(1);
		auto& chain244 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).      // Files_impl::chain244_t<NV>
                         getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(6);
		auto& midi34 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // Files_impl::midi34_t<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).
                       getT(0);
		auto& add196 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(0).        // math::add<NV>
                       getT(0).getT(1).getT(7).getT(1).getT(0).getT(0).getT(6).
                       getT(1);
		auto& gain131 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).
                        getT(1);
		auto& peak21 = this->getT(0).getT(0).getT(1).getT(1).                                // Files_impl::peak21_t<NV>
                       getT(2).getT(4).getT(0).getT(0).
                       getT(2);
		auto& clear2 = this->getT(0).getT(0).getT(1).getT(1).                                // math::clear<NV>
                       getT(2).getT(4).getT(0).getT(0).
                       getT(3);
		auto& pma17 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::pma17_t<NV>
                      getT(2).getT(4).getT(0).getT(0).
                      getT(4);
		auto& chain248 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain248_t<NV>
                         getT(2).getT(4).getT(0).getT(0).
                         getT(5);
		auto& branch21 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch21_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0);
		auto& chain250 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain250_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(0);
		auto& add213 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(0).getT(0);
		auto& chain251 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain251_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(1);
		auto& minmax6 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // Files_impl::minmax6_t<NV>
                        getT(0).getT(0).getT(5).getT(0).getT(1).getT(0);
		auto& add214 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(1).getT(1);
		auto& chain252 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain252_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(2);
		auto& minmax7 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // Files_impl::minmax7_t<NV>
                        getT(0).getT(0).getT(5).getT(0).getT(2).getT(0);
		auto& add215 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(2).getT(1);
		auto& chain253 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain253_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(3);
		auto& minmax14 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax14_t<NV>
                         getT(0).getT(0).getT(5).getT(0).getT(3).getT(0);
		auto& add216 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(3).getT(1);
		auto& chain254 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain254_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(4);
		auto& minmax11 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax11_t<NV>
                         getT(0).getT(0).getT(5).getT(0).getT(4).getT(0);
		auto& add217 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(4).getT(1);
		auto& chain255 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain255_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(5);
		auto& minmax15 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax15_t<NV>
                         getT(0).getT(0).getT(5).getT(0).getT(5).getT(0);
		auto& add218 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(5).getT(1);
		auto& chain256 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain256_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(6);
		auto& minmax16 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax16_t<NV>
                         getT(0).getT(0).getT(5).getT(0).getT(6).getT(0);
		auto& add219 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(6).getT(1);
		auto& chain257 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain257_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(7);
		auto& minmax17 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax17_t<NV>
                         getT(0).getT(0).getT(5).getT(0).getT(7).getT(0);
		auto& add220 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(7).getT(1);
		auto& chain258 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain258_t<NV>
                         getT(4).getT(0).getT(0).getT(5).getT(0).
                         getT(8);
		auto& minmax18 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax18_t<NV>
                         getT(0).getT(0).getT(5).getT(0).getT(8).getT(0);
		auto& add221 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(0).getT(5).getT(0).getT(8).getT(1);
		auto& peak18 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::peak18_t<NV>
                       getT(4).getT(0).getT(0).getT(5).getT(1);
		auto& cable_table5 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                  // Files_impl::cable_table5_t
                             getT(4).getT(0).getT(0).getT(5).getT(2);
		auto& modchain31 = this->getT(0).getT(0).getT(1).getT(1).                            // Files_impl::modchain31_t<NV>
                           getT(2).getT(4).getT(0).getT(1);
		auto& pma33 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::pma33_t<NV>
                      getT(2).getT(4).getT(0).getT(1).
                      getT(0);
		auto& chain535 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain535_t<NV>
                         getT(2).getT(4).getT(0).getT(1).
                         getT(1);
		auto& branch32 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch32_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0);
		auto& chain536 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain536_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(0);
		auto& add551 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(0).getT(0);
		auto& chain537 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain537_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(1);
		auto& minmax30 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax30_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(1).getT(0);
		auto& add552 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(1).getT(1);
		auto& chain538 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain538_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(2);
		auto& minmax31 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax31_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(2).getT(0);
		auto& add553 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(2).getT(1);
		auto& chain539 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain539_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(3);
		auto& minmax32 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax32_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(3).getT(0);
		auto& add554 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(3).getT(1);
		auto& chain540 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain540_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(4);
		auto& minmax33 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax33_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(4).getT(0);
		auto& add555 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(4).getT(1);
		auto& chain541 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain541_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(5);
		auto& minmax34 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax34_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(5).getT(0);
		auto& add556 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(5).getT(1);
		auto& chain542 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain542_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(6);
		auto& minmax35 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax35_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(6).getT(0);
		auto& add557 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(6).getT(1);
		auto& chain543 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain543_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(7);
		auto& minmax36 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax36_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(7).getT(0);
		auto& add558 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(7).getT(1);
		auto& chain544 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain544_t<NV>
                         getT(4).getT(0).getT(1).getT(1).getT(0).
                         getT(8);
		auto& minmax37 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax37_t<NV>
                         getT(0).getT(1).getT(1).getT(0).getT(8).getT(0);
		auto& add559 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(1).getT(1).getT(0).getT(8).getT(1);
		auto& peak43 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::peak43_t<NV>
                       getT(4).getT(0).getT(1).getT(1).getT(1);
		auto& clear4 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::clear<NV>
                       getT(4).getT(0).getT(1).getT(1).getT(2);
		auto& clear5 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::clear<NV>
                       getT(4).getT(0).getT(1).getT(1).getT(3);
		auto& cable_table9 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                  // Files_impl::cable_table9_t
                             getT(4).getT(0).getT(1).getT(1).getT(4);
		auto& modchain30 = this->getT(0).getT(0).getT(1).getT(1).                            // Files_impl::modchain30_t<NV>
                           getT(2).getT(4).getT(0).getT(2);
		auto& pma32 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::pma32_t<NV>
                      getT(2).getT(4).getT(0).getT(2).
                      getT(0);
		auto& chain510 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain510_t<NV>
                         getT(2).getT(4).getT(0).getT(2).
                         getT(1);
		auto& branch31 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch31_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0);
		auto& chain511 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain511_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(0);
		auto& add524 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& chain512 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain512_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(1);
		auto& minmax10 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax10_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(1).getT(0);
		auto& add525 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(1).getT(1);
		auto& chain513 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain513_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(2);
		auto& minmax13 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax13_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(2).getT(0);
		auto& add526 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(2).getT(1);
		auto& chain514 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain514_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(3);
		auto& minmax24 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax24_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(3).getT(0);
		auto& add527 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(3).getT(1);
		auto& chain515 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain515_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(4);
		auto& minmax25 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax25_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(4).getT(0);
		auto& add528 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(4).getT(1);
		auto& chain516 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain516_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(5);
		auto& minmax26 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax26_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(5).getT(0);
		auto& add529 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(5).getT(1);
		auto& chain517 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain517_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(6);
		auto& minmax27 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax27_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(6).getT(0);
		auto& add530 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(6).getT(1);
		auto& chain518 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain518_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(7);
		auto& minmax28 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax28_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(7).getT(0);
		auto& add531 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(7).getT(1);
		auto& chain519 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain519_t<NV>
                         getT(4).getT(0).getT(2).getT(1).getT(0).
                         getT(8);
		auto& minmax29 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax29_t<NV>
                         getT(0).getT(2).getT(1).getT(0).getT(8).getT(0);
		auto& add532 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(2).getT(1).getT(0).getT(8).getT(1);
		auto& peak31 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::peak31_t<NV>
                       getT(4).getT(0).getT(2).getT(1).getT(1);
		auto& cable_table7 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                  // Files_impl::cable_table7_t
                             getT(4).getT(0).getT(2).getT(1).getT(2);
		auto& modchain29 = this->getT(0).getT(0).getT(1).getT(1).                            // Files_impl::modchain29_t<NV>
                           getT(2).getT(4).getT(0).getT(3);
		auto& pma31 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::pma31_t<NV>
                      getT(2).getT(4).getT(0).getT(3).
                      getT(0);
		auto& chain485 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain485_t<NV>
                         getT(2).getT(4).getT(0).getT(3).
                         getT(1);
		auto& branch30 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch30_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0);
		auto& chain486 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain486_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(0);
		auto& add497 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(0).getT(0);
		auto& chain487 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain487_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(1);
		auto& minmax8 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // Files_impl::minmax8_t<NV>
                        getT(0).getT(3).getT(1).getT(0).getT(1).getT(0);
		auto& add498 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(1).getT(1);
		auto& chain488 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain488_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(2);
		auto& minmax9 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).               // Files_impl::minmax9_t<NV>
                        getT(0).getT(3).getT(1).getT(0).getT(2).getT(0);
		auto& add499 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(2).getT(1);
		auto& chain489 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain489_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(3);
		auto& minmax19 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax19_t<NV>
                         getT(0).getT(3).getT(1).getT(0).getT(3).getT(0);
		auto& add500 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(3).getT(1);
		auto& chain490 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain490_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(4);
		auto& minmax12 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax12_t<NV>
                         getT(0).getT(3).getT(1).getT(0).getT(4).getT(0);
		auto& add501 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(4).getT(1);
		auto& chain491 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain491_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(5);
		auto& minmax20 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax20_t<NV>
                         getT(0).getT(3).getT(1).getT(0).getT(5).getT(0);
		auto& add502 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(5).getT(1);
		auto& chain492 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain492_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(6);
		auto& minmax21 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax21_t<NV>
                         getT(0).getT(3).getT(1).getT(0).getT(6).getT(0);
		auto& add503 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(6).getT(1);
		auto& chain493 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain493_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(7);
		auto& minmax22 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax22_t<NV>
                         getT(0).getT(3).getT(1).getT(0).getT(7).getT(0);
		auto& add504 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(7).getT(1);
		auto& chain494 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain494_t<NV>
                         getT(4).getT(0).getT(3).getT(1).getT(0).
                         getT(8);
		auto& minmax23 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax23_t<NV>
                         getT(0).getT(3).getT(1).getT(0).getT(8).getT(0);
		auto& add505 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(3).getT(1).getT(0).getT(8).getT(1);
		auto& peak29 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::peak29_t<NV>
                       getT(4).getT(0).getT(3).getT(1).getT(1);
		auto& cable_table6 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                  // Files_impl::cable_table6_t
                             getT(4).getT(0).getT(3).getT(1).getT(2);
		auto& modchain32 = this->getT(0).getT(0).getT(1).getT(1).                            // Files_impl::modchain32_t<NV>
                           getT(2).getT(4).getT(0).getT(4);
		auto& pma34 = this->getT(0).getT(0).getT(1).getT(1).                                 // Files_impl::pma34_t<NV>
                      getT(2).getT(4).getT(0).getT(4).
                      getT(0);
		auto& chain560 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain560_t<NV>
                         getT(2).getT(4).getT(0).getT(4).
                         getT(1);
		auto& branch33 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::branch33_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0);
		auto& chain561 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain561_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(0);
		auto& add578 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(0).getT(0);
		auto& chain562 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain562_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(1);
		auto& minmax38 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax38_t<NV>
                         getT(0).getT(4).getT(1).getT(0).getT(1).getT(0);
		auto& add579 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(1).getT(1);
		auto& chain563 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain563_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(2);
		auto& minmax39 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax39_t<NV>
                         getT(0).getT(4).getT(1).getT(0).getT(2).getT(0);
		auto& add580 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(2).getT(1);
		auto& chain564 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain564_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(3);
		auto& minmax40 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax40_t<NV>
                         getT(0).getT(4).getT(1).getT(0).getT(3).getT(0);
		auto& add581 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(3).getT(1);
		auto& chain565 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain565_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(4);
		auto& minmax41 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax41_t<NV>
                         getT(0).getT(4).getT(1).getT(0).getT(4).getT(0);
		auto& add582 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(4).getT(1);
		auto& chain566 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain566_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(5);
		auto& minmax42 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax42_t<NV>
                         getT(0).getT(4).getT(1).getT(0).getT(5).getT(0);
		auto& add583 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(5).getT(1);
		auto& chain567 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain567_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(6);
		auto& minmax43 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax43_t<NV>
                         getT(0).getT(4).getT(1).getT(0).getT(6).getT(0);
		auto& add584 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(6).getT(1);
		auto& chain568 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain568_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(7);
		auto& minmax44 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax44_t<NV>
                         getT(0).getT(4).getT(1).getT(0).getT(7).getT(0);
		auto& add585 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(7).getT(1);
		auto& chain569 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                      // Files_impl::chain569_t<NV>
                         getT(4).getT(0).getT(4).getT(1).getT(0).
                         getT(8);
		auto& minmax45 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).              // Files_impl::minmax45_t<NV>
                         getT(0).getT(4).getT(1).getT(0).getT(8).getT(0);
		auto& add586 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).                // math::add<NV>
                       getT(0).getT(4).getT(1).getT(0).getT(8).getT(1);
		auto& peak45 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // Files_impl::peak45_t<NV>
                       getT(4).getT(0).getT(4).getT(1).getT(1);
		auto& cable_table10 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                 // Files_impl::cable_table10_t
                              getT(4).getT(0).getT(4).getT(1).getT(2);
		auto& split17 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).getT(1);       // Files_impl::split17_t<NV>
		auto& chain174 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain174_t<NV>
                         getT(2).getT(4).getT(1).getT(0);
		auto& split11 = this->getT(0).getT(0).getT(1).getT(1).                               // Files_impl::split11_t<NV>
                        getT(2).getT(4).getT(1).getT(0).
                        getT(0);
		auto& add222 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::add<NV>
                       getT(4).getT(1).getT(0).getT(0).getT(0);
		auto& add463 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::add<NV>
                       getT(4).getT(1).getT(0).getT(0).getT(1);
		auto& branch22 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::branch22_t<NV>
                         getT(2).getT(4).getT(1).getT(0).
                         getT(1);
		auto& file_player6 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                  // Files_impl::file_player6_t<NV>
                             getT(4).getT(1).getT(0).getT(1).getT(0);
		auto& file_player7 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                  // Files_impl::file_player7_t<NV>
                             getT(4).getT(1).getT(0).getT(1).getT(1);
		auto& branch26 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::branch26_t<NV>
                         getT(2).getT(4).getT(1).getT(0).
                         getT(2);
		auto& gain4 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                         // core::gain<NV>
                      getT(4).getT(1).getT(0).getT(2).getT(0);
		auto& gain10 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(0).getT(2).getT(1);
		auto& gain9 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                         // core::gain<NV>
                      getT(4).getT(1).getT(0).getT(2).getT(2);
		auto& gain7 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                         // core::gain<NV>
                      getT(4).getT(1).getT(0).getT(2).getT(3);
		auto& chain175 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain175_t<NV>
                         getT(2).getT(4).getT(1).getT(1);
		auto& split40 = this->getT(0).getT(0).getT(1).getT(1).                               // Files_impl::split40_t<NV>
                        getT(2).getT(4).getT(1).getT(1).
                        getT(0);
		auto& add474 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::add<NV>
                       getT(4).getT(1).getT(1).getT(0).getT(0);
		auto& add475 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::add<NV>
                       getT(4).getT(1).getT(1).getT(0).getT(1);
		auto& branch40 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::branch40_t<NV>
                         getT(2).getT(4).getT(1).getT(1).
                         getT(1);
		auto& file_player8 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                  // Files_impl::file_player8_t<NV>
                             getT(4).getT(1).getT(1).getT(1).getT(0);
		auto& file_player9 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                  // Files_impl::file_player9_t<NV>
                             getT(4).getT(1).getT(1).getT(1).getT(1);
		auto& branch41 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::branch41_t<NV>
                         getT(2).getT(4).getT(1).getT(1).
                         getT(2);
		auto& gain72 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(1).getT(2).getT(0);
		auto& gain89 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(1).getT(2).getT(1);
		auto& gain90 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(1).getT(2).getT(2);
		auto& gain91 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(1).getT(2).getT(3);
		auto& chain176 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain176_t<NV>
                         getT(2).getT(4).getT(1).getT(2);
		auto& split21 = this->getT(0).getT(0).getT(1).getT(1).                               // Files_impl::split21_t<NV>
                        getT(2).getT(4).getT(1).getT(2).
                        getT(0);
		auto& add469 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::add<NV>
                       getT(4).getT(1).getT(2).getT(0).getT(0);
		auto& add470 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::add<NV>
                       getT(4).getT(1).getT(2).getT(0).getT(1);
		auto& branch42 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::branch42_t<NV>
                         getT(2).getT(4).getT(1).getT(2).
                         getT(1);
		auto& file_player10 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                 // Files_impl::file_player10_t<NV>
                              getT(4).getT(1).getT(2).getT(1).getT(0);
		auto& file_player11 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                 // Files_impl::file_player11_t<NV>
                              getT(4).getT(1).getT(2).getT(1).getT(1);
		auto& branch43 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::branch43_t<NV>
                         getT(2).getT(4).getT(1).getT(2).
                         getT(2);
		auto& gain92 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(2).getT(2).getT(0);
		auto& gain93 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(2).getT(2).getT(1);
		auto& gain94 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(2).getT(2).getT(2);
		auto& gain95 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(2).getT(2).getT(3);
		auto& chain177 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::chain177_t<NV>
                         getT(2).getT(4).getT(1).getT(3);
		auto& split19 = this->getT(0).getT(0).getT(1).getT(1).                               // Files_impl::split19_t<NV>
                        getT(2).getT(4).getT(1).getT(3).
                        getT(0);
		auto& add464 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::add<NV>
                       getT(4).getT(1).getT(3).getT(0).getT(0);
		auto& add465 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // math::add<NV>
                       getT(4).getT(1).getT(3).getT(0).getT(1);
		auto& branch44 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::branch44_t<NV>
                         getT(2).getT(4).getT(1).getT(3).
                         getT(1);
		auto& file_player12 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                 // Files_impl::file_player12_t<NV>
                              getT(4).getT(1).getT(3).getT(1).getT(0);
		auto& file_player13 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                 // Files_impl::file_player13_t<NV>
                              getT(4).getT(1).getT(3).getT(1).getT(1);
		auto& branch45 = this->getT(0).getT(0).getT(1).getT(1).                              // Files_impl::branch45_t<NV>
                         getT(2).getT(4).getT(1).getT(3).
                         getT(2);
		auto& gain96 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(3).getT(2).getT(0);
		auto& gain97 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(3).getT(2).getT(1);
		auto& gain98 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(3).getT(2).getT(2);
		auto& gain99 = this->getT(0).getT(0).getT(1).getT(1).getT(2).                        // core::gain<NV>
                       getT(4).getT(1).getT(3).getT(2).getT(3);
		auto& branch23 = this->getT(0).getT(0).getT(1).getT(1).getT(3);                      // Files_impl::branch23_t<NV>
		auto& chain261 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(0);              // Files_impl::chain261_t<NV>
		auto& tanh2 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(0).getT(0);         // wrap::no_process<math::tanh<NV>>
		auto& chain262 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1);              // Files_impl::chain262_t<NV>
		auto& receive2 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1).getT(0);      // routing::receive<stereo_cable>
		auto& faust3 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1).getT(1);        // project::shfiter<NV>
		auto& send2 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1).getT(2);         // routing::send<stereo_cable>
		auto& chain263 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2);              // Files_impl::chain263_t<NV>
		auto& midi42 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2).getT(0);        // Files_impl::midi42_t<NV>
		auto& cable_table15 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2).getT(1); // Files_impl::cable_table15_t<NV>
		auto& receive3 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2).getT(2);      // routing::receive<stereo_cable>
		auto& faust4 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2).getT(3);        // project::ps2<NV>
		auto& faust5 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2).getT(4);        // project::shfiter<NV>
		auto& send3 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2).getT(5);         // routing::send<stereo_cable>
		auto& chain101 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(3);              // Files_impl::chain101_t
		auto& gain2 = this->getT(0).getT(0).getT(1).getT(1).getT(4);                         // core::gain<NV>
		auto& peak = this->getT(0).getT(1);                                                  // Files_impl::peak_t<NV>
		auto& modchain = this->getT(0).getT(2);                                              // Files_impl::modchain_t<NV>
		auto& event_data_writer = this->getT(0).getT(2).getT(0);                             // routing::event_data_writer<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma17); // PositionMod -> pma17::Multiply
		
		this->getParameterT(1).connectT(0, pma17); // Position -> pma17::Add
		
		auto& QuantisePositiion_p = this->getParameterT(2);
		QuantisePositiion_p.connectT(0, branch21); // QuantisePositiion -> branch21::Index
		QuantisePositiion_p.connectT(1, branch32); // QuantisePositiion -> branch32::Index
		QuantisePositiion_p.connectT(2, branch31); // QuantisePositiion -> branch31::Index
		QuantisePositiion_p.connectT(3, branch30); // QuantisePositiion -> branch30::Index
		QuantisePositiion_p.connectT(4, branch33); // QuantisePositiion -> branch33::Index
		
		this->getParameterT(3).connectT(0, one_pole); // PosSmooth -> one_pole::Frequency
		
		this->getParameterT(4).connectT(0, pma20); // FilePitch -> pma20::Add
		
		this->getParameterT(5).connectT(0, branch23); // PtichShiftOn -> branch23::Index
		
		this->getParameterT(6).connectT(0, pma20); // FilePitchMod -> pma20::Multiply
		
		this->getParameterT(7).connectT(0, pma_unscaled); // PitchWin -> pma_unscaled::Add
		
		this->getParameterT(8).connectT(0, pma_unscaled); // WinMod -> pma_unscaled::Multiply
		
		auto& FileUser_p = this->getParameterT(9);
		FileUser_p.connectT(0, branch40); // FileUser -> branch40::Index
		FileUser_p.connectT(1, branch22); // FileUser -> branch22::Index
		FileUser_p.connectT(2, branch42); // FileUser -> branch42::Index
		FileUser_p.connectT(3, branch44); // FileUser -> branch44::Index
		
		this->getParameterT(10).connectT(0, branch58); // FileMidiPitch -> branch58::Index
		
		this->getParameterT(11).connectT(0, branch52); // FileMidipos2 -> branch52::Index
		
		this->getParameterT(12).connectT(0, branch19); // FileWinPk -> branch19::Index
		
		this->getParameterT(13).connectT(0, branch60); // FileMidiwindow -> branch60::Index
		
		this->getParameterT(14).connectT(0, branch51); // FileMidPk -> branch51::Index
		
		this->getParameterT(15).connectT(0, branch20); // FileInPk -> branch20::Index
		
		this->getParameterT(16).connectT(0, pma19); // FileXrossFade -> pma19::Add
		
		this->getParameterT(17).connectT(0, pma19); // FileXrossFadeMod -> pma19::Multiply
		
		this->getParameterT(18).connectT(0, branch15); // FileXrossFadePk -> branch15::Index
		
		auto& FileXrossFadeMode_p = this->getParameterT(19);
		FileXrossFadeMode_p.connectT(0, branch45); // FileXrossFadeMode -> branch45::Index
		FileXrossFadeMode_p.connectT(1, branch43); // FileXrossFadeMode -> branch43::Index
		FileXrossFadeMode_p.connectT(2, branch41); // FileXrossFadeMode -> branch41::Index
		FileXrossFadeMode_p.connectT(3, branch26); // FileXrossFadeMode -> branch26::Index
		FileXrossFadeMode_p.connectT(4, branch39); // FileXrossFadeMode -> branch39::Index
		
		this->getParameterT(20).connectT(0, branch56); // FileXrossFadeMidi -> branch56::Index
		
		this->getParameterT(21).connectT(0, branch16); // FilePitchPk -> branch16::Index
		
		auto& feed_p = this->getParameterT(22);
		feed_p.connectT(0, receive2); // feed -> receive2::Feedback
		feed_p.connectT(1, receive3); // feed -> receive3::Feedback
		
		this->getParameterT(23).connectT(0, one_pole); // _1pMod -> one_pole::Mode
		
		this->getParameterT(25).connectT(0, pma33); // PosAMod -> pma33::Multiply
		
		this->getParameterT(26).connectT(0, pma33); // PosA -> pma33::Add
		
		this->getParameterT(27).connectT(0, pma32); // PosB -> pma32::Add
		
		this->getParameterT(28).connectT(0, pma32); // PosBmod -> pma32::Multiply
		
		this->getParameterT(29).connectT(0, pma31); // PosC -> pma31::Add
		
		this->getParameterT(30).connectT(0, pma31); // PosCMod -> pma31::Multiply
		
		this->getParameterT(31).connectT(0, pma34); // PosD -> pma34::Add
		
		this->getParameterT(32).connectT(0, pma34); // PosDMod -> pma34::Multiply
		
		this->getParameterT(35).connectT(0, tempo_sync6); // RampTempo1 -> tempo_sync6::Tempo
		
		this->getParameterT(36).connectT(0, tempo_sync9); // RampTempo2 -> tempo_sync9::Tempo
		
		this->getParameterT(37).connectT(0, tempo_sync6); // RampDiv1 -> tempo_sync6::Multiplier
		
		this->getParameterT(38).connectT(0, tempo_sync9); // RampDiv2 -> tempo_sync9::Multiplier
		
		this->getParameterT(39).connectT(0, branch36); // RampInv1 -> branch36::Index
		
		this->getParameterT(40).connectT(0, branch89); // RampInv2 -> branch89::Index
		
		this->getParameterT(41).connectT(0, tempo_sync8); // RampTemo3 -> tempo_sync8::Tempo
		
		this->getParameterT(42).connectT(0, tempo_sync7); // RampTempo4 -> tempo_sync7::Tempo
		
		this->getParameterT(43).connectT(0, tempo_sync8); // RampDiv3 -> tempo_sync8::Multiplier
		
		this->getParameterT(44).connectT(0, tempo_sync7); // RampDiv4 -> tempo_sync7::Multiplier
		
		this->getParameterT(45).connectT(0, branch46); // RampInv3 -> branch46::Index
		
		this->getParameterT(46).connectT(0, branch37); // RampInv4 -> branch37::Index
		
		this->getParameterT(47).connectT(0, ramp5); // RampOS1 -> ramp5::LoopStart
		
		this->getParameterT(48).connectT(0, ramp8); // RampOS2 -> ramp8::LoopStart
		
		this->getParameterT(49).connectT(0, ramp7); // RampOS3 -> ramp7::LoopStart
		
		this->getParameterT(50).connectT(0, ramp6); // RampOS4 -> ramp6::LoopStart
		
		this->getParameterT(51).connectT(0, branch61); // InputMidi -> branch61::Index
		
		this->getParameterT(52).connectT(0, pma); // Input -> pma::Add
		
		this->getParameterT(53).connectT(0, pma); // InputMod -> pma::Multiply
		
		this->getParameterT(54).connectT(0, xfader); // Mix -> xfader::Value
		
		this->getParameterT(55).connectT(0, branch); // Trk1 -> branch::Index
		
		this->getParameterT(56).connectT(0, branch1); // trk2 -> branch1::Index
		
		this->getParameterT(57).connectT(0, branch3); // trk3 -> branch3::Index
		
		this->getParameterT(58).connectT(0, branch2); // trk4 -> branch2::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain2); // xfader -> gain2::Gain
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
		xfader6_p.getParameterT(0).connectT(0, gain9);  // xfader6 -> gain9::Gain
		xfader6_p.getParameterT(1).connectT(0, gain90); // xfader6 -> gain90::Gain
		xfader6_p.getParameterT(2).connectT(0, gain94); // xfader6 -> gain94::Gain
		xfader6_p.getParameterT(3).connectT(0, gain98); // xfader6 -> gain98::Gain
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, gain7);                     // sliderbank -> gain7::Gain
		sliderbank_p.getParameterT(1).connectT(0, gain91);                    // sliderbank -> gain91::Gain
		sliderbank_p.getParameterT(2).connectT(0, gain95);                    // sliderbank -> gain95::Gain
		sliderbank_p.getParameterT(3).connectT(0, gain99);                    // sliderbank -> gain99::Gain
		global_cable51.getWrappedObject().getParameter().connectT(0, add225); // global_cable51 -> add225::Value
		auto& xfader71_p = xfader71.getWrappedObject().getParameter();
		xfader71_p.getParameterT(1).connectT(0, soft_bypass65);               // xfader71 -> soft_bypass65::Bypassed
		global_cable52.getWrappedObject().getParameter().connectT(0, add226); // global_cable52 -> add226::Value
		auto& xfader79_p = xfader79.getWrappedObject().getParameter();
		xfader79_p.getParameterT(1).connectT(0, soft_bypass73); // xfader79 -> soft_bypass73::Bypassed
		auto& xfader78_p = xfader78.getWrappedObject().getParameter();
		xfader78_p.getParameterT(1).connectT(0, soft_bypass72);               // xfader78 -> soft_bypass72::Bypassed
		global_cable54.getWrappedObject().getParameter().connectT(0, add228); // global_cable54 -> add228::Value
		auto& xfader77_p = xfader77.getWrappedObject().getParameter();
		xfader77_p.getParameterT(1).connectT(0, soft_bypass71); // xfader77 -> soft_bypass71::Bypassed
		event_data_reader16.getParameter().connectT(0, add229); // event_data_reader16 -> add229::Value
		auto& xfader76_p = xfader76.getWrappedObject().getParameter();
		xfader76_p.getParameterT(1).connectT(0, soft_bypass70); // xfader76 -> soft_bypass70::Bypassed
		event_data_reader17.getParameter().connectT(0, add230); // event_data_reader17 -> add230::Value
		auto& xfader75_p = xfader75.getWrappedObject().getParameter();
		xfader75_p.getParameterT(1).connectT(0, soft_bypass69); // xfader75 -> soft_bypass69::Bypassed
		event_data_reader.getParameter().connectT(0, add3);     // event_data_reader -> add3::Value
		event_data_reader3.getParameter().connectT(0, add16);   // event_data_reader3 -> add16::Value
		event_data_reader2.getParameter().connectT(0, add15);   // event_data_reader2 -> add15::Value
		event_data_reader1.getParameter().connectT(0, add14);   // event_data_reader1 -> add14::Value
		auto& xfader74_p = xfader74.getWrappedObject().getParameter();
		xfader74_p.getParameterT(1).connectT(0, soft_bypass68);          // xfader74 -> soft_bypass68::Bypassed
		midi_cc51.getWrappedObject().getParameter().connectT(0, add236); // midi_cc51 -> add236::Value
		midi_cc52.getWrappedObject().getParameter().connectT(0, add237); // midi_cc52 -> add237::Value
		midi_cc53.getWrappedObject().getParameter().connectT(0, add238); // midi_cc53 -> add238::Value
		midi_cc54.getWrappedObject().getParameter().connectT(0, add239); // midi_cc54 -> add239::Value
		midi38.getParameter().connectT(0, add240);                       // midi38 -> add240::Value
		midi39.getParameter().connectT(0, add241);                       // midi39 -> add241::Value
		midi40.getParameter().connectT(0, add242);                       // midi40 -> add242::Value
		auto& xfader73_p = xfader73.getWrappedObject().getParameter();
		xfader73_p.getParameterT(1).connectT(0, soft_bypass67); // xfader73 -> soft_bypass67::Bypassed
		auto& sliderbank15_p = sliderbank15.getWrappedObject().getParameter();
		sliderbank15_p.getParameterT(0).connectT(0, gain140);                 // sliderbank15 -> gain140::Gain
		sliderbank15_p.getParameterT(0).connectT(1, xfader71);                // sliderbank15 -> xfader71::Value
		sliderbank15_p.getParameterT(1).connectT(0, gain141);                 // sliderbank15 -> gain141::Gain
		sliderbank15_p.getParameterT(1).connectT(1, xfader79);                // sliderbank15 -> xfader79::Value
		sliderbank15_p.getParameterT(2).connectT(0, gain142);                 // sliderbank15 -> gain142::Gain
		sliderbank15_p.getParameterT(2).connectT(1, xfader78);                // sliderbank15 -> xfader78::Value
		sliderbank15_p.getParameterT(3).connectT(0, gain143);                 // sliderbank15 -> gain143::Gain
		sliderbank15_p.getParameterT(3).connectT(1, xfader77);                // sliderbank15 -> xfader77::Value
		sliderbank15_p.getParameterT(4).connectT(0, gain144);                 // sliderbank15 -> gain144::Gain
		sliderbank15_p.getParameterT(4).connectT(1, xfader76);                // sliderbank15 -> xfader76::Value
		sliderbank15_p.getParameterT(5).connectT(0, gain145);                 // sliderbank15 -> gain145::Gain
		sliderbank15_p.getParameterT(5).connectT(1, xfader75);                // sliderbank15 -> xfader75::Value
		sliderbank15_p.getParameterT(6).connectT(0, gain146);                 // sliderbank15 -> gain146::Gain
		sliderbank15_p.getParameterT(6).connectT(1, xfader74);                // sliderbank15 -> xfader74::Value
		sliderbank15_p.getParameterT(7).connectT(0, gain147);                 // sliderbank15 -> gain147::Gain
		sliderbank15_p.getParameterT(7).connectT(1, xfader73);                // sliderbank15 -> xfader73::Value
		global_cable53.getWrappedObject().getParameter().connectT(0, add227); // global_cable53 -> add227::Value
		pma19.getWrappedObject().getParameter().connectT(0, xfader1);         // pma19 -> xfader1::Value
		pma19.getWrappedObject().getParameter().connectT(1, xfader5);         // pma19 -> xfader5::Value
		pma19.getWrappedObject().getParameter().connectT(2, xfader6);         // pma19 -> xfader6::Value
		peak35.getParameter().connectT(0, pma19);                             // peak35 -> pma19::Value
		global_cable55.getWrappedObject().getParameter().connectT(0, add243); // global_cable55 -> add243::Value
		auto& xfader72_p = xfader72.getWrappedObject().getParameter();
		xfader72_p.getParameterT(1).connectT(0, soft_bypass66);               // xfader72 -> soft_bypass66::Bypassed
		global_cable56.getWrappedObject().getParameter().connectT(0, add244); // global_cable56 -> add244::Value
		auto& xfader86_p = xfader86.getWrappedObject().getParameter();
		xfader86_p.getParameterT(1).connectT(0, soft_bypass80);               // xfader86 -> soft_bypass80::Bypassed
		global_cable57.getWrappedObject().getParameter().connectT(0, add245); // global_cable57 -> add245::Value
		auto& xfader85_p = xfader85.getWrappedObject().getParameter();
		xfader85_p.getParameterT(1).connectT(0, soft_bypass79); // xfader85 -> soft_bypass79::Bypassed
		auto& xfader84_p = xfader84.getWrappedObject().getParameter();
		xfader84_p.getParameterT(1).connectT(0, soft_bypass78); // xfader84 -> soft_bypass78::Bypassed
		event_data_reader18.getParameter().connectT(0, add247); // event_data_reader18 -> add247::Value
		auto& xfader83_p = xfader83.getWrappedObject().getParameter();
		xfader83_p.getParameterT(1).connectT(0, soft_bypass77); // xfader83 -> soft_bypass77::Bypassed
		event_data_reader19.getParameter().connectT(0, add248); // event_data_reader19 -> add248::Value
		auto& xfader82_p = xfader82.getWrappedObject().getParameter();
		xfader82_p.getParameterT(1).connectT(0, soft_bypass76); // xfader82 -> soft_bypass76::Bypassed
		event_data_reader4.getParameter().connectT(0, add4);    // event_data_reader4 -> add4::Value
		event_data_reader5.getParameter().connectT(0, add17);   // event_data_reader5 -> add17::Value
		event_data_reader6.getParameter().connectT(0, add18);   // event_data_reader6 -> add18::Value
		event_data_reader7.getParameter().connectT(0, add19);   // event_data_reader7 -> add19::Value
		auto& xfader81_p = xfader81.getWrappedObject().getParameter();
		xfader81_p.getParameterT(1).connectT(0, soft_bypass75);          // xfader81 -> soft_bypass75::Bypassed
		midi_cc55.getWrappedObject().getParameter().connectT(0, add394); // midi_cc55 -> add394::Value
		midi_cc56.getWrappedObject().getParameter().connectT(0, add395); // midi_cc56 -> add395::Value
		midi_cc57.getWrappedObject().getParameter().connectT(0, add396); // midi_cc57 -> add396::Value
		midi_cc58.getWrappedObject().getParameter().connectT(0, add397); // midi_cc58 -> add397::Value
		midi41.getParameter().connectT(0, add398);                       // midi41 -> add398::Value
		midi43.getParameter().connectT(0, add399);                       // midi43 -> add399::Value
		midi44.getParameter().connectT(0, add400);                       // midi44 -> add400::Value
		auto& xfader80_p = xfader80.getWrappedObject().getParameter();
		xfader80_p.getParameterT(1).connectT(0, soft_bypass74); // xfader80 -> soft_bypass74::Bypassed
		auto& sliderbank16_p = sliderbank16.getWrappedObject().getParameter();
		sliderbank16_p.getParameterT(0).connectT(0, gain228);                 // sliderbank16 -> gain228::Gain
		sliderbank16_p.getParameterT(0).connectT(1, xfader72);                // sliderbank16 -> xfader72::Value
		sliderbank16_p.getParameterT(1).connectT(0, gain229);                 // sliderbank16 -> gain229::Gain
		sliderbank16_p.getParameterT(1).connectT(1, xfader86);                // sliderbank16 -> xfader86::Value
		sliderbank16_p.getParameterT(2).connectT(0, gain230);                 // sliderbank16 -> gain230::Gain
		sliderbank16_p.getParameterT(2).connectT(1, xfader85);                // sliderbank16 -> xfader85::Value
		sliderbank16_p.getParameterT(3).connectT(0, gain231);                 // sliderbank16 -> gain231::Gain
		sliderbank16_p.getParameterT(3).connectT(1, xfader84);                // sliderbank16 -> xfader84::Value
		sliderbank16_p.getParameterT(4).connectT(0, gain232);                 // sliderbank16 -> gain232::Gain
		sliderbank16_p.getParameterT(4).connectT(1, xfader83);                // sliderbank16 -> xfader83::Value
		sliderbank16_p.getParameterT(5).connectT(0, gain233);                 // sliderbank16 -> gain233::Gain
		sliderbank16_p.getParameterT(5).connectT(1, xfader82);                // sliderbank16 -> xfader82::Value
		sliderbank16_p.getParameterT(6).connectT(0, gain234);                 // sliderbank16 -> gain234::Gain
		sliderbank16_p.getParameterT(6).connectT(1, xfader81);                // sliderbank16 -> xfader81::Value
		sliderbank16_p.getParameterT(7).connectT(0, gain235);                 // sliderbank16 -> gain235::Gain
		sliderbank16_p.getParameterT(7).connectT(1, xfader80);                // sliderbank16 -> xfader80::Value
		global_cable58.getWrappedObject().getParameter().connectT(0, add246); // global_cable58 -> add246::Value
		pma20.getWrappedObject().getParameter().connectT(0, faust3);          // pma20 -> faust3::shiftnote
		pma20.getWrappedObject().getParameter().connectT(1, faust5);          // pma20 -> faust5::shiftnote
		peak36.getParameter().connectT(0, pma20);                             // peak36 -> pma20::Value
		global_cable59.getWrappedObject().getParameter().connectT(0, add254); // global_cable59 -> add254::Value
		auto& xfader87_p = xfader87.getWrappedObject().getParameter();
		xfader87_p.getParameterT(1).connectT(0, soft_bypass81);               // xfader87 -> soft_bypass81::Bypassed
		global_cable60.getWrappedObject().getParameter().connectT(0, add255); // global_cable60 -> add255::Value
		auto& xfader95_p = xfader95.getWrappedObject().getParameter();
		xfader95_p.getParameterT(1).connectT(0, soft_bypass89);               // xfader95 -> soft_bypass89::Bypassed
		global_cable61.getWrappedObject().getParameter().connectT(0, add256); // global_cable61 -> add256::Value
		auto& xfader94_p = xfader94.getWrappedObject().getParameter();
		xfader94_p.getParameterT(1).connectT(0, soft_bypass88);               // xfader94 -> soft_bypass88::Bypassed
		global_cable62.getWrappedObject().getParameter().connectT(0, add257); // global_cable62 -> add257::Value
		auto& xfader93_p = xfader93.getWrappedObject().getParameter();
		xfader93_p.getParameterT(1).connectT(0, soft_bypass87); // xfader93 -> soft_bypass87::Bypassed
		event_data_reader20.getParameter().connectT(0, add258); // event_data_reader20 -> add258::Value
		auto& xfader92_p = xfader92.getWrappedObject().getParameter();
		xfader92_p.getParameterT(1).connectT(0, soft_bypass86); // xfader92 -> soft_bypass86::Bypassed
		event_data_reader21.getParameter().connectT(0, add259); // event_data_reader21 -> add259::Value
		auto& xfader91_p = xfader91.getWrappedObject().getParameter();
		xfader91_p.getParameterT(1).connectT(0, soft_bypass85); // xfader91 -> soft_bypass85::Bypassed
		event_data_reader8.getParameter().connectT(0, add5);    // event_data_reader8 -> add5::Value
		event_data_reader9.getParameter().connectT(0, add20);   // event_data_reader9 -> add20::Value
		event_data_reader10.getParameter().connectT(0, add21);  // event_data_reader10 -> add21::Value
		event_data_reader11.getParameter().connectT(0, add23);  // event_data_reader11 -> add23::Value
		auto& xfader90_p = xfader90.getWrappedObject().getParameter();
		xfader90_p.getParameterT(1).connectT(0, soft_bypass84);          // xfader90 -> soft_bypass84::Bypassed
		midi_cc59.getWrappedObject().getParameter().connectT(0, add401); // midi_cc59 -> add401::Value
		midi_cc60.getWrappedObject().getParameter().connectT(0, add402); // midi_cc60 -> add402::Value
		midi_cc61.getWrappedObject().getParameter().connectT(0, add403); // midi_cc61 -> add403::Value
		midi_cc62.getWrappedObject().getParameter().connectT(0, add404); // midi_cc62 -> add404::Value
		midi45.getParameter().connectT(0, add405);                       // midi45 -> add405::Value
		midi46.getParameter().connectT(0, add406);                       // midi46 -> add406::Value
		midi47.getParameter().connectT(0, add407);                       // midi47 -> add407::Value
		auto& xfader89_p = xfader89.getWrappedObject().getParameter();
		xfader89_p.getParameterT(1).connectT(0, soft_bypass83); // xfader89 -> soft_bypass83::Bypassed
		auto& sliderbank17_p = sliderbank17.getWrappedObject().getParameter();
		sliderbank17_p.getParameterT(0).connectT(0, gain236);                 // sliderbank17 -> gain236::Gain
		sliderbank17_p.getParameterT(0).connectT(1, xfader87);                // sliderbank17 -> xfader87::Value
		sliderbank17_p.getParameterT(1).connectT(0, gain237);                 // sliderbank17 -> gain237::Gain
		sliderbank17_p.getParameterT(1).connectT(1, xfader95);                // sliderbank17 -> xfader95::Value
		sliderbank17_p.getParameterT(2).connectT(0, gain238);                 // sliderbank17 -> gain238::Gain
		sliderbank17_p.getParameterT(2).connectT(1, xfader94);                // sliderbank17 -> xfader94::Value
		sliderbank17_p.getParameterT(3).connectT(0, gain239);                 // sliderbank17 -> gain239::Gain
		sliderbank17_p.getParameterT(3).connectT(1, xfader93);                // sliderbank17 -> xfader93::Value
		sliderbank17_p.getParameterT(4).connectT(0, gain240);                 // sliderbank17 -> gain240::Gain
		sliderbank17_p.getParameterT(4).connectT(1, xfader92);                // sliderbank17 -> xfader92::Value
		sliderbank17_p.getParameterT(5).connectT(0, gain241);                 // sliderbank17 -> gain241::Gain
		sliderbank17_p.getParameterT(5).connectT(1, xfader91);                // sliderbank17 -> xfader91::Value
		sliderbank17_p.getParameterT(6).connectT(0, gain242);                 // sliderbank17 -> gain242::Gain
		sliderbank17_p.getParameterT(6).connectT(1, xfader90);                // sliderbank17 -> xfader90::Value
		sliderbank17_p.getParameterT(7).connectT(0, gain243);                 // sliderbank17 -> gain243::Gain
		sliderbank17_p.getParameterT(7).connectT(1, xfader89);                // sliderbank17 -> xfader89::Value
		pma_unscaled.getWrappedObject().getParameter().connectT(0, faust4);   // pma_unscaled -> faust4::xfadesamples
		pma_unscaled.getWrappedObject().getParameter().connectT(1, faust4);   // pma_unscaled -> faust4::windowsamples
		pma_unscaled.getWrappedObject().getParameter().connectT(2, faust3);   // pma_unscaled -> faust3::windowsamples
		pma_unscaled.getWrappedObject().getParameter().connectT(3, faust3);   // pma_unscaled -> faust3::xfadesamples
		pma_unscaled.getWrappedObject().getParameter().connectT(4, faust5);   // pma_unscaled -> faust5::windowsamples
		pma_unscaled.getWrappedObject().getParameter().connectT(5, faust5);   // pma_unscaled -> faust5::xfadesamples
		peak_unscaled.getParameter().connectT(0, pma_unscaled);               // peak_unscaled -> pma_unscaled::Value
		global_cable63.getWrappedObject().getParameter().connectT(0, add265); // global_cable63 -> add265::Value
		auto& xfader88_p = xfader88.getWrappedObject().getParameter();
		xfader88_p.getParameterT(1).connectT(0, soft_bypass82);               // xfader88 -> soft_bypass82::Bypassed
		global_cable64.getWrappedObject().getParameter().connectT(0, add266); // global_cable64 -> add266::Value
		auto& xfader96_p = xfader96.getWrappedObject().getParameter();
		xfader96_p.getParameterT(1).connectT(0, soft_bypass90);               // xfader96 -> soft_bypass90::Bypassed
		global_cable65.getWrappedObject().getParameter().connectT(0, add267); // global_cable65 -> add267::Value
		auto& xfader97_p = xfader97.getWrappedObject().getParameter();
		xfader97_p.getParameterT(1).connectT(0, soft_bypass91);               // xfader97 -> soft_bypass91::Bypassed
		global_cable66.getWrappedObject().getParameter().connectT(0, add268); // global_cable66 -> add268::Value
		auto& xfader98_p = xfader98.getWrappedObject().getParameter();
		xfader98_p.getParameterT(1).connectT(0, soft_bypass92); // xfader98 -> soft_bypass92::Bypassed
		event_data_reader22.getParameter().connectT(0, add269); // event_data_reader22 -> add269::Value
		auto& xfader99_p = xfader99.getWrappedObject().getParameter();
		xfader99_p.getParameterT(1).connectT(0, soft_bypass93); // xfader99 -> soft_bypass93::Bypassed
		event_data_reader23.getParameter().connectT(0, add270); // event_data_reader23 -> add270::Value
		auto& xfader100_p = xfader100.getWrappedObject().getParameter();
		xfader100_p.getParameterT(1).connectT(0, soft_bypass94); // xfader100 -> soft_bypass94::Bypassed
		event_data_reader12.getParameter().connectT(0, add6);    // event_data_reader12 -> add6::Value
		event_data_reader13.getParameter().connectT(0, add24);   // event_data_reader13 -> add24::Value
		event_data_reader14.getParameter().connectT(0, add25);   // event_data_reader14 -> add25::Value
		event_data_reader15.getParameter().connectT(0, add26);   // event_data_reader15 -> add26::Value
		auto& xfader101_p = xfader101.getWrappedObject().getParameter();
		xfader101_p.getParameterT(1).connectT(0, soft_bypass95);         // xfader101 -> soft_bypass95::Bypassed
		midi_cc63.getWrappedObject().getParameter().connectT(0, add408); // midi_cc63 -> add408::Value
		midi_cc64.getWrappedObject().getParameter().connectT(0, add409); // midi_cc64 -> add409::Value
		midi_cc65.getWrappedObject().getParameter().connectT(0, add410); // midi_cc65 -> add410::Value
		midi_cc66.getWrappedObject().getParameter().connectT(0, add411); // midi_cc66 -> add411::Value
		midi48.getParameter().connectT(0, add412);                       // midi48 -> add412::Value
		midi49.getParameter().connectT(0, add413);                       // midi49 -> add413::Value
		midi50.getParameter().connectT(0, add414);                       // midi50 -> add414::Value
		auto& xfader102_p = xfader102.getWrappedObject().getParameter();
		xfader102_p.getParameterT(1).connectT(0, soft_bypass96); // xfader102 -> soft_bypass96::Bypassed
		auto& sliderbank18_p = sliderbank18.getWrappedObject().getParameter();
		sliderbank18_p.getParameterT(0).connectT(0, gain244);                 // sliderbank18 -> gain244::Gain
		sliderbank18_p.getParameterT(0).connectT(1, xfader88);                // sliderbank18 -> xfader88::Value
		sliderbank18_p.getParameterT(1).connectT(0, gain245);                 // sliderbank18 -> gain245::Gain
		sliderbank18_p.getParameterT(1).connectT(1, xfader96);                // sliderbank18 -> xfader96::Value
		sliderbank18_p.getParameterT(2).connectT(0, gain246);                 // sliderbank18 -> gain246::Gain
		sliderbank18_p.getParameterT(2).connectT(1, xfader97);                // sliderbank18 -> xfader97::Value
		sliderbank18_p.getParameterT(3).connectT(0, gain247);                 // sliderbank18 -> gain247::Gain
		sliderbank18_p.getParameterT(3).connectT(1, xfader98);                // sliderbank18 -> xfader98::Value
		sliderbank18_p.getParameterT(4).connectT(0, gain248);                 // sliderbank18 -> gain248::Gain
		sliderbank18_p.getParameterT(4).connectT(1, xfader99);                // sliderbank18 -> xfader99::Value
		sliderbank18_p.getParameterT(5).connectT(0, gain249);                 // sliderbank18 -> gain249::Gain
		sliderbank18_p.getParameterT(5).connectT(1, xfader100);               // sliderbank18 -> xfader100::Value
		sliderbank18_p.getParameterT(6).connectT(0, gain250);                 // sliderbank18 -> gain250::Gain
		sliderbank18_p.getParameterT(6).connectT(1, xfader101);               // sliderbank18 -> xfader101::Value
		sliderbank18_p.getParameterT(7).connectT(0, gain251);                 // sliderbank18 -> gain251::Gain
		sliderbank18_p.getParameterT(7).connectT(1, xfader102);               // sliderbank18 -> xfader102::Value
		pma.getWrappedObject().getParameter().connectT(0, gain1);             // pma -> gain1::Gain
		peak38.getParameter().connectT(0, pma);                               // peak38 -> pma::Value
		tempo_sync6.getParameter().connectT(0, ramp5);                        // tempo_sync6 -> ramp5::PeriodTime
		minmax30.getWrappedObject().getParameter().connectT(0, add552);       // minmax30 -> add552::Value
		minmax31.getWrappedObject().getParameter().connectT(0, add553);       // minmax31 -> add553::Value
		minmax32.getWrappedObject().getParameter().connectT(0, add554);       // minmax32 -> add554::Value
		minmax33.getWrappedObject().getParameter().connectT(0, add555);       // minmax33 -> add555::Value
		minmax34.getWrappedObject().getParameter().connectT(0, add556);       // minmax34 -> add556::Value
		minmax35.getWrappedObject().getParameter().connectT(0, add557);       // minmax35 -> add557::Value
		minmax36.getWrappedObject().getParameter().connectT(0, add558);       // minmax36 -> add558::Value
		minmax37.getWrappedObject().getParameter().connectT(0, add559);       // minmax37 -> add559::Value
		pma33.getWrappedObject().getParameter().connectT(0, minmax30);        // pma33 -> minmax30::Value
		pma33.getWrappedObject().getParameter().connectT(1, minmax31);        // pma33 -> minmax31::Value
		pma33.getWrappedObject().getParameter().connectT(2, minmax32);        // pma33 -> minmax32::Value
		pma33.getWrappedObject().getParameter().connectT(3, minmax33);        // pma33 -> minmax33::Value
		pma33.getWrappedObject().getParameter().connectT(4, minmax34);        // pma33 -> minmax34::Value
		pma33.getWrappedObject().getParameter().connectT(5, minmax35);        // pma33 -> minmax35::Value
		pma33.getWrappedObject().getParameter().connectT(6, minmax36);        // pma33 -> minmax36::Value
		pma33.getWrappedObject().getParameter().connectT(7, add551);          // pma33 -> add551::Value
		pma33.getWrappedObject().getParameter().connectT(8, minmax37);        // pma33 -> minmax37::Value
		peak15.getParameter().connectT(0, pma33);                             // peak15 -> pma33::Value
		tempo_sync9.getParameter().connectT(0, ramp8);                        // tempo_sync9 -> ramp8::PeriodTime
		minmax10.getWrappedObject().getParameter().connectT(0, add525);       // minmax10 -> add525::Value
		minmax13.getWrappedObject().getParameter().connectT(0, add526);       // minmax13 -> add526::Value
		minmax24.getWrappedObject().getParameter().connectT(0, add527);       // minmax24 -> add527::Value
		minmax25.getWrappedObject().getParameter().connectT(0, add528);       // minmax25 -> add528::Value
		minmax26.getWrappedObject().getParameter().connectT(0, add529);       // minmax26 -> add529::Value
		minmax27.getWrappedObject().getParameter().connectT(0, add530);       // minmax27 -> add530::Value
		minmax28.getWrappedObject().getParameter().connectT(0, add531);       // minmax28 -> add531::Value
		minmax29.getWrappedObject().getParameter().connectT(0, add532);       // minmax29 -> add532::Value
		pma32.getWrappedObject().getParameter().connectT(0, minmax10);        // pma32 -> minmax10::Value
		pma32.getWrappedObject().getParameter().connectT(1, minmax13);        // pma32 -> minmax13::Value
		pma32.getWrappedObject().getParameter().connectT(2, minmax24);        // pma32 -> minmax24::Value
		pma32.getWrappedObject().getParameter().connectT(3, minmax25);        // pma32 -> minmax25::Value
		pma32.getWrappedObject().getParameter().connectT(4, minmax26);        // pma32 -> minmax26::Value
		pma32.getWrappedObject().getParameter().connectT(5, minmax27);        // pma32 -> minmax27::Value
		pma32.getWrappedObject().getParameter().connectT(6, minmax28);        // pma32 -> minmax28::Value
		pma32.getWrappedObject().getParameter().connectT(7, add524);          // pma32 -> add524::Value
		pma32.getWrappedObject().getParameter().connectT(8, minmax29);        // pma32 -> minmax29::Value
		peak49.getParameter().connectT(0, pma32);                             // peak49 -> pma32::Value
		tempo_sync8.getParameter().connectT(0, ramp7);                        // tempo_sync8 -> ramp7::PeriodTime
		minmax8.getWrappedObject().getParameter().connectT(0, add498);        // minmax8 -> add498::Value
		minmax9.getWrappedObject().getParameter().connectT(0, add499);        // minmax9 -> add499::Value
		minmax19.getWrappedObject().getParameter().connectT(0, add500);       // minmax19 -> add500::Value
		minmax12.getWrappedObject().getParameter().connectT(0, add501);       // minmax12 -> add501::Value
		minmax20.getWrappedObject().getParameter().connectT(0, add502);       // minmax20 -> add502::Value
		minmax21.getWrappedObject().getParameter().connectT(0, add503);       // minmax21 -> add503::Value
		minmax22.getWrappedObject().getParameter().connectT(0, add504);       // minmax22 -> add504::Value
		minmax23.getWrappedObject().getParameter().connectT(0, add505);       // minmax23 -> add505::Value
		pma31.getWrappedObject().getParameter().connectT(0, minmax8);         // pma31 -> minmax8::Value
		pma31.getWrappedObject().getParameter().connectT(1, minmax9);         // pma31 -> minmax9::Value
		pma31.getWrappedObject().getParameter().connectT(2, minmax19);        // pma31 -> minmax19::Value
		pma31.getWrappedObject().getParameter().connectT(3, minmax12);        // pma31 -> minmax12::Value
		pma31.getWrappedObject().getParameter().connectT(4, minmax20);        // pma31 -> minmax20::Value
		pma31.getWrappedObject().getParameter().connectT(5, minmax21);        // pma31 -> minmax21::Value
		pma31.getWrappedObject().getParameter().connectT(6, minmax22);        // pma31 -> minmax22::Value
		pma31.getWrappedObject().getParameter().connectT(7, minmax23);        // pma31 -> minmax23::Minimum
		pma31.getWrappedObject().getParameter().connectT(8, add497);          // pma31 -> add497::Value
		peak48.getParameter().connectT(0, pma31);                             // peak48 -> pma31::Value
		tempo_sync7.getParameter().connectT(0, ramp6);                        // tempo_sync7 -> ramp6::PeriodTime
		minmax38.getWrappedObject().getParameter().connectT(0, add579);       // minmax38 -> add579::Value
		minmax39.getWrappedObject().getParameter().connectT(0, add580);       // minmax39 -> add580::Value
		minmax40.getWrappedObject().getParameter().connectT(0, add581);       // minmax40 -> add581::Value
		minmax41.getWrappedObject().getParameter().connectT(0, add582);       // minmax41 -> add582::Value
		minmax42.getWrappedObject().getParameter().connectT(0, add583);       // minmax42 -> add583::Value
		minmax43.getWrappedObject().getParameter().connectT(0, add584);       // minmax43 -> add584::Value
		minmax44.getWrappedObject().getParameter().connectT(0, add585);       // minmax44 -> add585::Value
		minmax45.getWrappedObject().getParameter().connectT(0, add586);       // minmax45 -> add586::Value
		pma34.getWrappedObject().getParameter().connectT(0, minmax38);        // pma34 -> minmax38::Value
		pma34.getWrappedObject().getParameter().connectT(1, minmax39);        // pma34 -> minmax39::Value
		pma34.getWrappedObject().getParameter().connectT(2, minmax40);        // pma34 -> minmax40::Value
		pma34.getWrappedObject().getParameter().connectT(3, minmax41);        // pma34 -> minmax41::Value
		pma34.getWrappedObject().getParameter().connectT(4, minmax42);        // pma34 -> minmax42::Value
		pma34.getWrappedObject().getParameter().connectT(5, minmax43);        // pma34 -> minmax43::Value
		pma34.getWrappedObject().getParameter().connectT(6, minmax44);        // pma34 -> minmax44::Value
		pma34.getWrappedObject().getParameter().connectT(7, minmax45);        // pma34 -> minmax45::Minimum
		pma34.getWrappedObject().getParameter().connectT(8, add578);          // pma34 -> add578::Value
		peak47.getParameter().connectT(0, pma34);                             // peak47 -> pma34::Value
		global_cable43.getWrappedObject().getParameter().connectT(0, add179); // global_cable43 -> add179::Value
		auto& xfader135_p = xfader135.getWrappedObject().getParameter();
		xfader135_p.getParameterT(1).connectT(0, soft_bypass129);             // xfader135 -> soft_bypass129::Bypassed
		global_cable44.getWrappedObject().getParameter().connectT(0, add180); // global_cable44 -> add180::Value
		auto& xfader142_p = xfader142.getWrappedObject().getParameter();
		xfader142_p.getParameterT(1).connectT(0, soft_bypass136);             // xfader142 -> soft_bypass136::Bypassed
		global_cable45.getWrappedObject().getParameter().connectT(0, add181); // global_cable45 -> add181::Value
		auto& xfader141_p = xfader141.getWrappedObject().getParameter();
		xfader141_p.getParameterT(1).connectT(0, soft_bypass135);             // xfader141 -> soft_bypass135::Bypassed
		global_cable46.getWrappedObject().getParameter().connectT(0, add182); // global_cable46 -> add182::Value
		auto& xfader140_p = xfader140.getWrappedObject().getParameter();
		xfader140_p.getParameterT(1).connectT(0, soft_bypass134); // xfader140 -> soft_bypass134::Bypassed
		event_data_reader24.getParameter().connectT(0, add183);   // event_data_reader24 -> add183::Value
		auto& xfader139_p = xfader139.getWrappedObject().getParameter();
		xfader139_p.getParameterT(1).connectT(0, soft_bypass133); // xfader139 -> soft_bypass133::Bypassed
		event_data_reader25.getParameter().connectT(0, add184);   // event_data_reader25 -> add184::Value
		auto& xfader138_p = xfader138.getWrappedObject().getParameter();
		xfader138_p.getParameterT(1).connectT(0, soft_bypass132); // xfader138 -> soft_bypass132::Bypassed
		auto& xfader137_p = xfader137.getWrappedObject().getParameter();
		xfader137_p.getParameterT(1).connectT(0, soft_bypass131);        // xfader137 -> soft_bypass131::Bypassed
		midi_cc43.getWrappedObject().getParameter().connectT(0, add190); // midi_cc43 -> add190::Value
		midi_cc44.getWrappedObject().getParameter().connectT(0, add191); // midi_cc44 -> add191::Value
		midi_cc45.getWrappedObject().getParameter().connectT(0, add192); // midi_cc45 -> add192::Value
		midi_cc46.getWrappedObject().getParameter().connectT(0, add193); // midi_cc46 -> add193::Value
		midi32.getParameter().connectT(0, add194);                       // midi32 -> add194::Value
		midi33.getParameter().connectT(0, add195);                       // midi33 -> add195::Value
		midi34.getParameter().connectT(0, add196);                       // midi34 -> add196::Value
		auto& xfader136_p = xfader136.getWrappedObject().getParameter();
		xfader136_p.getParameterT(1).connectT(0, soft_bypass130); // xfader136 -> soft_bypass130::Bypassed
		auto& sliderbank13_p = sliderbank13.getWrappedObject().getParameter();
		sliderbank13_p.getParameterT(0).connectT(0, gain124);                // sliderbank13 -> gain124::Gain
		sliderbank13_p.getParameterT(0).connectT(1, xfader135);              // sliderbank13 -> xfader135::Value
		sliderbank13_p.getParameterT(1).connectT(0, gain125);                // sliderbank13 -> gain125::Gain
		sliderbank13_p.getParameterT(1).connectT(1, xfader142);              // sliderbank13 -> xfader142::Value
		sliderbank13_p.getParameterT(2).connectT(0, gain126);                // sliderbank13 -> gain126::Gain
		sliderbank13_p.getParameterT(2).connectT(1, xfader141);              // sliderbank13 -> xfader141::Value
		sliderbank13_p.getParameterT(3).connectT(0, gain127);                // sliderbank13 -> gain127::Gain
		sliderbank13_p.getParameterT(3).connectT(1, xfader140);              // sliderbank13 -> xfader140::Value
		sliderbank13_p.getParameterT(4).connectT(0, gain128);                // sliderbank13 -> gain128::Gain
		sliderbank13_p.getParameterT(4).connectT(1, xfader139);              // sliderbank13 -> xfader139::Value
		sliderbank13_p.getParameterT(5).connectT(0, gain129);                // sliderbank13 -> gain129::Gain
		sliderbank13_p.getParameterT(5).connectT(1, xfader138);              // sliderbank13 -> xfader138::Value
		sliderbank13_p.getParameterT(6).connectT(0, gain130);                // sliderbank13 -> gain130::Gain
		sliderbank13_p.getParameterT(6).connectT(1, xfader137);              // sliderbank13 -> xfader137::Value
		sliderbank13_p.getParameterT(7).connectT(0, gain131);                // sliderbank13 -> gain131::Gain
		sliderbank13_p.getParameterT(7).connectT(1, xfader136);              // sliderbank13 -> xfader136::Value
		minmax6.getWrappedObject().getParameter().connectT(0, add214);       // minmax6 -> add214::Value
		minmax7.getWrappedObject().getParameter().connectT(0, add215);       // minmax7 -> add215::Value
		minmax14.getWrappedObject().getParameter().connectT(0, add216);      // minmax14 -> add216::Value
		minmax11.getWrappedObject().getParameter().connectT(0, add217);      // minmax11 -> add217::Value
		minmax15.getWrappedObject().getParameter().connectT(0, add218);      // minmax15 -> add218::Value
		minmax16.getWrappedObject().getParameter().connectT(0, add219);      // minmax16 -> add219::Value
		minmax17.getWrappedObject().getParameter().connectT(0, add220);      // minmax17 -> add220::Value
		minmax18.getWrappedObject().getParameter().connectT(0, add221);      // minmax18 -> add221::Value
		pma17.getWrappedObject().getParameter().connectT(0, minmax6);        // pma17 -> minmax6::Value
		pma17.getWrappedObject().getParameter().connectT(1, minmax7);        // pma17 -> minmax7::Value
		pma17.getWrappedObject().getParameter().connectT(2, minmax14);       // pma17 -> minmax14::Value
		pma17.getWrappedObject().getParameter().connectT(3, minmax11);       // pma17 -> minmax11::Value
		pma17.getWrappedObject().getParameter().connectT(4, minmax15);       // pma17 -> minmax15::Value
		pma17.getWrappedObject().getParameter().connectT(5, minmax16);       // pma17 -> minmax16::Value
		pma17.getWrappedObject().getParameter().connectT(6, minmax17);       // pma17 -> minmax17::Value
		pma17.getWrappedObject().getParameter().connectT(7, add213);         // pma17 -> add213::Value
		pma17.getWrappedObject().getParameter().connectT(8, minmax18);       // pma17 -> minmax18::Value
		peak21.getParameter().connectT(0, pma17);                            // peak21 -> pma17::Value
		peak18.getParameter().connectT(0, add222);                           // peak18 -> add222::Value
		peak18.getParameter().connectT(1, cable_table5);                     // peak18 -> cable_table5::Value
		peak18.getParameter().connectT(2, add474);                           // peak18 -> add474::Value
		peak18.getParameter().connectT(3, add469);                           // peak18 -> add469::Value
		peak18.getParameter().connectT(4, add464);                           // peak18 -> add464::Value
		peak43.getParameter().connectT(0, cable_table9);                     // peak43 -> cable_table9::Value
		peak43.getParameter().connectT(1, add463);                           // peak43 -> add463::Value
		peak31.getParameter().connectT(0, cable_table7);                     // peak31 -> cable_table7::Value
		peak31.getParameter().connectT(1, add475);                           // peak31 -> add475::Value
		peak29.getParameter().connectT(0, cable_table6);                     // peak29 -> cable_table6::Value
		peak29.getParameter().connectT(1, add470);                           // peak29 -> add470::Value
		peak45.getParameter().connectT(0, cable_table10);                    // peak45 -> cable_table10::Value
		peak45.getParameter().connectT(1, add465);                           // peak45 -> add465::Value
		cable_table15.getWrappedObject().getParameter().connectT(0, faust4); // cable_table15 -> faust4::shiftfreq
		midi42.getParameter().connectT(0, cable_table15);                    // midi42 -> cable_table15::Value
		peak.getParameter().connectT(0, event_data_writer);                  // peak -> event_data_writer::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send2.connect(receive2);
		send3.connect(receive3);
		
		// Default Values --------------------------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear25.setParameterT(0, 0.); // math::clear::Value
		
		; // branch39::Index is automated
		
		; // xfader1::Value is automated
		
		; // xfader5::Value is automated
		
		; // xfader6::Value is automated
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
		sliderbank15.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // xfader71::Value is automated
		
		global_cable51.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add225::Value is automated
		
		;                              // gain140::Gain is automated
		gain140.setParameterT(1, 20.); // core::gain::Smoothing
		gain140.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader79::Value is automated
		
		global_cable52.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add226::Value is automated
		
		;                              // gain141::Gain is automated
		gain141.setParameterT(1, 20.); // core::gain::Smoothing
		gain141.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader78::Value is automated
		
		global_cable53.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add227::Value is automated
		
		;                              // gain142::Gain is automated
		gain142.setParameterT(1, 20.); // core::gain::Smoothing
		gain142.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader77::Value is automated
		
		global_cable54.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add228::Value is automated
		
		;                              // gain143::Gain is automated
		gain143.setParameterT(1, 20.); // core::gain::Smoothing
		gain143.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader76::Value is automated
		
		event_data_reader16.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add229::Value is automated
		
		;                              // gain144::Gain is automated
		gain144.setParameterT(1, 20.); // core::gain::Smoothing
		gain144.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader75::Value is automated
		
		event_data_reader17.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add230::Value is automated
		
		;                              // gain145::Gain is automated
		gain145.setParameterT(1, 20.); // core::gain::Smoothing
		gain145.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader74::Value is automated
		
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
		
		add235.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain146::Gain is automated
		gain146.setParameterT(1, 20.); // core::gain::Smoothing
		gain146.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader73::Value is automated
		
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
		
		; // xfader72::Value is automated
		
		global_cable55.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add243::Value is automated
		
		;                              // gain228::Gain is automated
		gain228.setParameterT(1, 20.); // core::gain::Smoothing
		gain228.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader86::Value is automated
		
		global_cable56.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add244::Value is automated
		
		;                              // gain229::Gain is automated
		gain229.setParameterT(1, 20.); // core::gain::Smoothing
		gain229.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader85::Value is automated
		
		global_cable57.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add245::Value is automated
		
		;                              // gain230::Gain is automated
		gain230.setParameterT(1, 20.); // core::gain::Smoothing
		gain230.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader84::Value is automated
		
		global_cable58.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add246::Value is automated
		
		;                              // gain231::Gain is automated
		gain231.setParameterT(1, 20.); // core::gain::Smoothing
		gain231.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader83::Value is automated
		
		event_data_reader18.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader18.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add247::Value is automated
		
		;                              // gain232::Gain is automated
		gain232.setParameterT(1, 20.); // core::gain::Smoothing
		gain232.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader82::Value is automated
		
		event_data_reader19.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader19.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add248::Value is automated
		
		;                              // gain233::Gain is automated
		gain233.setParameterT(1, 20.); // core::gain::Smoothing
		gain233.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader81::Value is automated
		
		; // branch16::Index is automated
		
		event_data_reader4.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add4::Value is automated
		
		event_data_reader5.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add17::Value is automated
		
		event_data_reader6.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add18::Value is automated
		
		event_data_reader7.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add19::Value is automated
		
		add253.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain234::Gain is automated
		gain234.setParameterT(1, 20.); // core::gain::Smoothing
		gain234.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader80::Value is automated
		
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
		
		; // xfader87::Value is automated
		
		global_cable59.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add254::Value is automated
		
		;                              // gain236::Gain is automated
		gain236.setParameterT(1, 20.); // core::gain::Smoothing
		gain236.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader95::Value is automated
		
		global_cable60.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add255::Value is automated
		
		;                              // gain237::Gain is automated
		gain237.setParameterT(1, 20.); // core::gain::Smoothing
		gain237.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader94::Value is automated
		
		global_cable61.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add256::Value is automated
		
		;                              // gain238::Gain is automated
		gain238.setParameterT(1, 20.); // core::gain::Smoothing
		gain238.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader93::Value is automated
		
		global_cable62.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add257::Value is automated
		
		;                              // gain239::Gain is automated
		gain239.setParameterT(1, 20.); // core::gain::Smoothing
		gain239.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader92::Value is automated
		
		event_data_reader20.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader20.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add258::Value is automated
		
		;                              // gain240::Gain is automated
		gain240.setParameterT(1, 20.); // core::gain::Smoothing
		gain240.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader91::Value is automated
		
		event_data_reader21.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader21.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add259::Value is automated
		
		;                              // gain241::Gain is automated
		gain241.setParameterT(1, 20.); // core::gain::Smoothing
		gain241.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader90::Value is automated
		
		; // branch19::Index is automated
		
		event_data_reader8.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader8.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add5::Value is automated
		
		event_data_reader9.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader9.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add20::Value is automated
		
		event_data_reader10.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add21::Value is automated
		
		event_data_reader11.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader11.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add23::Value is automated
		
		add264.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain242::Gain is automated
		gain242.setParameterT(1, 20.); // core::gain::Smoothing
		gain242.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader89::Value is automated
		
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
		
		; // xfader88::Value is automated
		
		global_cable63.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add265::Value is automated
		
		;                              // gain244::Gain is automated
		gain244.setParameterT(1, 20.); // core::gain::Smoothing
		gain244.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader96::Value is automated
		
		global_cable64.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add266::Value is automated
		
		;                              // gain245::Gain is automated
		gain245.setParameterT(1, 20.); // core::gain::Smoothing
		gain245.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader97::Value is automated
		
		global_cable65.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add267::Value is automated
		
		;                              // gain246::Gain is automated
		gain246.setParameterT(1, 20.); // core::gain::Smoothing
		gain246.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader98::Value is automated
		
		global_cable66.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add268::Value is automated
		
		;                              // gain247::Gain is automated
		gain247.setParameterT(1, 20.); // core::gain::Smoothing
		gain247.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader99::Value is automated
		
		event_data_reader22.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader22.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add269::Value is automated
		
		;                              // gain248::Gain is automated
		gain248.setParameterT(1, 20.); // core::gain::Smoothing
		gain248.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader100::Value is automated
		
		event_data_reader23.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader23.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add270::Value is automated
		
		;                              // gain249::Gain is automated
		gain249.setParameterT(1, 20.); // core::gain::Smoothing
		gain249.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader101::Value is automated
		
		; // branch20::Index is automated
		
		event_data_reader12.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add6::Value is automated
		
		event_data_reader13.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add24::Value is automated
		
		event_data_reader14.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add25::Value is automated
		
		event_data_reader15.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add26::Value is automated
		
		add271.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain250::Gain is automated
		gain250.setParameterT(1, 20.); // core::gain::Smoothing
		gain250.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader102::Value is automated
		
		; // branch61::Index is automated
		
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
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		;                                // one_pole::Mode is automated
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // branch::Index is automated
		
		;                                   // tempo_sync6::Tempo is automated
		;                                   // tempo_sync6::Multiplier is automated
		tempo_sync6.setParameterT(2, 10.);  // control::tempo_sync::Enabled
		tempo_sync6.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp5::PeriodTime is automated
		;                           // ramp5::LoopStart is automated
		ramp5.setParameterT(2, 1.); // core::ramp::Gate
		
		; // branch36::Index is automated
		
		mod_inv.setParameterT(0, 0.); // math::mod_inv::Value
		
		phasor.setParameterT(0, 1.);   // core::phasor::Gate
		phasor.setParameterT(1, 220.); // core::phasor::Frequency
		phasor.setParameterT(2, 0.);   // core::phasor::FreqRatio
		phasor.setParameterT(3, 0.);   // core::phasor::Phase
		
		clear26.setParameterT(0, 0.); // math::clear::Value
		
		; // branch1::Index is automated
		
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
		
		phasor3.setParameterT(0, 1.);   // core::phasor::Gate
		phasor3.setParameterT(1, 220.); // core::phasor::Frequency
		phasor3.setParameterT(2, 0.);   // core::phasor::FreqRatio
		phasor3.setParameterT(3, 0.);   // core::phasor::Phase
		
		; // branch3::Index is automated
		
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
		
		phasor2.setParameterT(0, 1.);   // core::phasor::Gate
		phasor2.setParameterT(1, 220.); // core::phasor::Frequency
		phasor2.setParameterT(2, 0.);   // core::phasor::FreqRatio
		phasor2.setParameterT(3, 0.);   // core::phasor::Phase
		
		; // branch2::Index is automated
		
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
		
		phasor1.setParameterT(0, 1.);   // core::phasor::Gate
		phasor1.setParameterT(1, 220.); // core::phasor::Frequency
		phasor1.setParameterT(2, 0.);   // core::phasor::FreqRatio
		phasor1.setParameterT(3, 0.);   // core::phasor::Phase
		
		sliderbank13.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // xfader135::Value is automated
		
		global_cable43.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add179::Value is automated
		
		;                              // gain124::Gain is automated
		gain124.setParameterT(1, 20.); // core::gain::Smoothing
		gain124.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader142::Value is automated
		
		global_cable44.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add180::Value is automated
		
		;                              // gain125::Gain is automated
		gain125.setParameterT(1, 20.); // core::gain::Smoothing
		gain125.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader141::Value is automated
		
		global_cable45.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add181::Value is automated
		
		;                              // gain126::Gain is automated
		gain126.setParameterT(1, 20.); // core::gain::Smoothing
		gain126.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader140::Value is automated
		
		global_cable46.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add182::Value is automated
		
		;                              // gain127::Gain is automated
		gain127.setParameterT(1, 20.); // core::gain::Smoothing
		gain127.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader139::Value is automated
		
		event_data_reader24.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader24.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add183::Value is automated
		
		;                              // gain128::Gain is automated
		gain128.setParameterT(1, 20.); // core::gain::Smoothing
		gain128.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader138::Value is automated
		
		event_data_reader25.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader25.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add184::Value is automated
		
		;                              // gain129::Gain is automated
		gain129.setParameterT(1, 20.); // core::gain::Smoothing
		gain129.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader137::Value is automated
		
		; // branch51::Index is automated
		
		add185.setParameterT(0, 0.); // math::add::Value
		
		add186.setParameterT(0, 0.); // math::add::Value
		
		add187.setParameterT(0, 0.); // math::add::Value
		
		add188.setParameterT(0, 0.); // math::add::Value
		
		add189.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain130::Gain is automated
		gain130.setParameterT(1, 20.); // core::gain::Smoothing
		gain130.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader136::Value is automated
		
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
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_writer.setParameterT(0, 2.); // routing::event_data_writer::SlotIndex
		;                                       // event_data_writer::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 3193.);
		this->setParameterT(4, -24.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 93.04);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 2.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 4.);
		this->setParameterT(20, 1.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 0.);
		this->setParameterT(25, 0.);
		this->setParameterT(26, 0.43);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 0.);
		this->setParameterT(29, 0.);
		this->setParameterT(30, 0.);
		this->setParameterT(31, 0.);
		this->setParameterT(32, 1.);
		this->setParameterT(33, 0.);
		this->setParameterT(34, 0.243164);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 1.);
		this->setParameterT(37, 1.);
		this->setParameterT(38, 1.);
		this->setParameterT(39, 0.);
		this->setParameterT(40, 0.);
		this->setParameterT(41, 0.);
		this->setParameterT(42, 0.);
		this->setParameterT(43, 1.);
		this->setParameterT(44, 32.);
		this->setParameterT(45, 0.);
		this->setParameterT(46, 0.);
		this->setParameterT(47, 0.);
		this->setParameterT(48, 0.);
		this->setParameterT(49, 0.);
		this->setParameterT(50, 0.);
		this->setParameterT(51, 1.);
		this->setParameterT(52, 0.77);
		this->setParameterT(53, 0.);
		this->setParameterT(54, 1.);
		this->setParameterT(55, 0.);
		this->setParameterT(56, 0.);
		this->setParameterT(57, 0.);
		this->setParameterT(58, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable51_t<NV>
        getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable52_t<NV>
        getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).          // Files_impl::global_cable53_t<NV>
        getT(0).getT(0).getT(1).getT(2).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable54_t<NV>
        getT(0).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable55_t<NV>
        getT(1).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable56_t<NV>
        getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable57_t<NV>
        getT(1).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).          // Files_impl::global_cable58_t<NV>
        getT(0).getT(1).getT(1).getT(3).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable59_t<NV>
        getT(2).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable60_t<NV>
        getT(2).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable61_t<NV>
        getT(2).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable62_t<NV>
        getT(2).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable63_t<NV>
        getT(3).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable64_t<NV>
        getT(3).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable65_t<NV>
        getT(3).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).  // Files_impl::global_cable66_t<NV>
        getT(3).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).  // Files_impl::global_cable43_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).  // Files_impl::global_cable44_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).  // Files_impl::global_cable45_t<NV>
        getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(4).  // Files_impl::global_cable46_t<NV>
        getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(3).setExternalData(b, index);         // Files_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::sliderbank15_t<NV>
        getT(2).getT(0).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::peak35_t<NV>
        getT(2).getT(0).getT(0).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::sliderbank16_t<NV>
        getT(2).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::peak36_t<NV>
        getT(2).getT(0).getT(1).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::sliderbank17_t<NV>
        getT(2).getT(0).getT(2).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::peak_unscaled_t<NV>
        getT(2).getT(0).getT(2).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::peak37_t
        getT(2).getT(0).getT(2).getT(3).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::sliderbank18_t<NV>
        getT(2).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::peak38_t<NV>
        getT(2).getT(0).getT(3).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::ramp5_t<NV>
        getT(3).getT(0).getT(0).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::peak15_t<NV>
        getT(2).getT(3).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::ramp8_t<NV>
        getT(3).getT(0).getT(1).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::peak49_t<NV>
        getT(3).getT(0).getT(1).getT(0).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::ramp7_t<NV>
        getT(3).getT(0).getT(2).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::peak48_t<NV>
        getT(3).getT(0).getT(2).getT(0).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::ramp6_t<NV>
        getT(3).getT(0).getT(3).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::peak47_t<NV>
        getT(3).getT(0).getT(3).getT(0).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::sliderbank13_t<NV>
        getT(2).getT(4).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).                                                   // Files_impl::peak21_t<NV>
        getT(2).getT(4).getT(0).getT(0).
        getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::peak18_t<NV>
        getT(4).getT(0).getT(0).getT(5).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::cable_table5_t
        getT(4).getT(0).getT(0).getT(5).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::peak43_t<NV>
        getT(4).getT(0).getT(1).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::cable_table9_t
        getT(4).getT(0).getT(1).getT(1).getT(4).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::peak31_t<NV>
        getT(4).getT(0).getT(2).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::cable_table7_t
        getT(4).getT(0).getT(2).getT(1).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::peak29_t<NV>
        getT(4).getT(0).getT(3).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::cable_table6_t
        getT(4).getT(0).getT(3).getT(1).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::peak45_t<NV>
        getT(4).getT(0).getT(4).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::cable_table10_t
        getT(4).getT(0).getT(4).getT(1).getT(2).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::file_player6_t<NV>
        getT(4).getT(1).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::file_player7_t<NV>
        getT(4).getT(1).getT(0).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::file_player8_t<NV>
        getT(4).getT(1).getT(1).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::file_player9_t<NV>
        getT(4).getT(1).getT(1).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::file_player10_t<NV>
        getT(4).getT(1).getT(2).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::file_player11_t<NV>
        getT(4).getT(1).getT(2).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::file_player12_t<NV>
        getT(4).getT(1).getT(3).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(2).                                           // Files_impl::file_player13_t<NV>
        getT(4).getT(1).getT(3).getT(1).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2).getT(1).setExternalData(b, index); // Files_impl::cable_table15_t<NV>
		this->getT(0).getT(1).setExternalData(b, index);                                         // Files_impl::peak_t<NV>
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
using Files = wrap::node<Files_impl::instance<NV>>;
}


