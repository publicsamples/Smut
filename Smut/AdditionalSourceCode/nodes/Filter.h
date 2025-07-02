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

namespace Filter_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable63_t_index = runtime_target::indexers::fix_hash<2333884>;

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
DECLARE_PARAMETER_RANGE_SKEW(sliderbank18_c0_0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using sliderbank18_c0_0 = parameter::from0To1<core::gain<NV>, 
                                              0, 
                                              sliderbank18_c0_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(sliderbank18_c0_1Range, 
                             0., 
                             1., 
                             13.65);

template <int NV>
using sliderbank18_c0_1 = parameter::from0To1<xfader88_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank18_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c0_0<NV>, 
                                         sliderbank18_c0_1<NV>>;

using global_cable64_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable64_t = routing::global_cable<global_cable64_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain311_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable64_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass97_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain311_t<NV>>>;

template <int NV>
using soft_bypass97_t = bypass::smoothed<20, soft_bypass97_t_<NV>>;
template <int NV>
using xfader103_c1 = parameter::bypass<soft_bypass97_t<NV>>;

template <int NV>
using xfader103_multimod = parameter::list<parameter::empty, xfader103_c1<NV>>;

template <int NV>
using xfader103_t = control::xfader<xfader103_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c1_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank18_c1_1 = parameter::from0To1<xfader103_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank18_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c1_0<NV>, 
                                         sliderbank18_c1_1<NV>>;

using global_cable65_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable65_t = routing::global_cable<global_cable65_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain312_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable65_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass96_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain312_t<NV>>>;

template <int NV>
using soft_bypass96_t = bypass::smoothed<20, soft_bypass96_t_<NV>>;
template <int NV>
using xfader102_c1 = parameter::bypass<soft_bypass96_t<NV>>;

template <int NV>
using xfader102_multimod = parameter::list<parameter::empty, xfader102_c1<NV>>;

template <int NV>
using xfader102_t = control::xfader<xfader102_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c2_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank18_c2_1 = parameter::from0To1<xfader102_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank18_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c2_0<NV>, 
                                         sliderbank18_c2_1<NV>>;

template <int NV> using sliderbank18_c3 = sliderbank18_c0_0<NV>;

template <int NV>
using event_data_reader16_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                        routing::event_data_reader<NV>>;

template <int NV>
using chain314_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader16_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass94_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain314_t<NV>>>;

template <int NV>
using soft_bypass94_t = bypass::smoothed<20, soft_bypass94_t_<NV>>;
template <int NV>
using xfader100_c1 = parameter::bypass<soft_bypass94_t<NV>>;

template <int NV>
using xfader100_multimod = parameter::list<parameter::empty, xfader100_c1<NV>>;

template <int NV>
using xfader100_t = control::xfader<xfader100_multimod<NV>, faders::switcher>;

using global_cable66_t_index = runtime_target::indexers::fix_hash<2333887>;

template <int NV>
using global_cable66_t = routing::global_cable<global_cable66_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain313_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable66_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass95_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain313_t<NV>>>;

template <int NV>
using soft_bypass95_t = bypass::smoothed<20, soft_bypass95_t_<NV>>;
template <int NV>
using xfader101_c1 = parameter::bypass<soft_bypass95_t<NV>>;

template <int NV>
using xfader101_multimod = parameter::list<parameter::empty, xfader101_c1<NV>>;

template <int NV>
using xfader101_t = control::xfader<xfader101_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c4_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank18_c4_1 = parameter::from0To1<xfader100_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank18_c4_2 = parameter::from0To1<xfader101_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank18_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c4_0<NV>, 
                                         sliderbank18_c4_1<NV>, 
                                         sliderbank18_c4_2<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader16_t<NV>;

template <int NV>
using chain315_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader17_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass93_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain315_t<NV>>>;

template <int NV>
using soft_bypass93_t = bypass::smoothed<20, soft_bypass93_t_<NV>>;
template <int NV>
using xfader99_c1 = parameter::bypass<soft_bypass93_t<NV>>;

template <int NV>
using xfader99_multimod = parameter::list<parameter::empty, xfader99_c1<NV>>;

template <int NV>
using xfader99_t = control::xfader<xfader99_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c5_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank18_c5_1 = parameter::from0To1<xfader99_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank18_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c5_0<NV>, 
                                         sliderbank18_c5_1<NV>>;

template <int NV>
using chain386_t = container::chain<parameter::empty, 
                                    wrap::fix<1, routing::event_data_reader<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain402_t = chain386_t<NV>;

template <int NV> using chain403_t = chain386_t<NV>;

template <int NV> using chain404_t = chain386_t<NV>;
template <int NV>
using branch19_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain386_t<NV>>, 
                                     chain402_t<NV>, 
                                     chain403_t<NV>, 
                                     chain404_t<NV>>;

template <int NV>
using chain316_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch19_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass92_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain316_t<NV>>>;

template <int NV>
using soft_bypass92_t = bypass::smoothed<20, soft_bypass92_t_<NV>>;
template <int NV>
using xfader98_c1 = parameter::bypass<soft_bypass92_t<NV>>;

template <int NV>
using xfader98_multimod = parameter::list<parameter::empty, xfader98_c1<NV>>;

template <int NV>
using xfader98_t = control::xfader<xfader98_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c6_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank18_c6_1 = parameter::from0To1<xfader98_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank18_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank18_c6_0<NV>, 
                                         sliderbank18_c6_1<NV>>;

template <int NV>
using midi_cc63_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain318_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc63_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc64_t = midi_cc63_t<NV>;

template <int NV>
using chain319_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc64_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc65_t = midi_cc63_t<NV>;

template <int NV>
using chain428_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc65_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc66_t = midi_cc63_t<NV>;

template <int NV>
using chain459_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc66_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using midi48_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                           control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain460_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi48_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using midi49_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain461_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi49_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using midi50_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                           control::midi<midi_logic::random<NV>>>;

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
using soft_bypass91_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain317_t<NV>>>;

template <int NV>
using soft_bypass91_t = bypass::smoothed<20, soft_bypass91_t_<NV>>;
template <int NV>
using xfader97_c1 = parameter::bypass<soft_bypass91_t<NV>>;

template <int NV>
using xfader97_multimod = parameter::list<parameter::empty, xfader97_c1<NV>>;

template <int NV>
using xfader97_t = control::xfader<xfader97_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank18_c7_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank18_c7_1 = parameter::from0To1<xfader97_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

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
                                  data::external::sliderpack<0>>;

template <int NV>
using chain416_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader88_t<NV>>, 
                                    soft_bypass82_t<NV>>;

template <int NV>
using chain438_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader103_t<NV>>, 
                                    soft_bypass97_t<NV>>;

template <int NV>
using chain437_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader102_t<NV>>, 
                                    soft_bypass96_t<NV>>;

template <int NV>
using chain436_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader101_t<NV>>, 
                                    soft_bypass95_t<NV>>;

template <int NV>
using chain435_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader100_t<NV>>, 
                                    soft_bypass94_t<NV>>;

template <int NV>
using chain434_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader99_t<NV>>, 
                                    soft_bypass93_t<NV>>;

template <int NV>
using chain433_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader98_t<NV>>, 
                                    soft_bypass92_t<NV>>;

template <int NV>
using chain425_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader97_t<NV>>, 
                                    soft_bypass91_t<NV>>;

template <int NV>
using split35_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain416_t<NV>>, 
                                   chain438_t<NV>, 
                                   chain437_t<NV>, 
                                   chain436_t<NV>, 
                                   chain435_t<NV>, 
                                   chain434_t<NV>, 
                                   chain433_t<NV>, 
                                   chain425_t<NV>>;

template <int NV> using xfader_c0 = sliderbank18_c0_0<NV>;

template <int NV> using xfader_c1 = sliderbank18_c0_0<NV>;

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

using global_cable67_t_index = global_cable63_t_index;

template <int NV>
using global_cable67_t = routing::global_cable<global_cable67_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain320_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable67_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass90_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain320_t<NV>>>;

template <int NV>
using soft_bypass90_t = bypass::smoothed<20, soft_bypass90_t_<NV>>;
template <int NV>
using xfader96_c1 = parameter::bypass<soft_bypass90_t<NV>>;

template <int NV>
using xfader96_multimod = parameter::list<parameter::empty, xfader96_c1<NV>>;

template <int NV>
using xfader96_t = control::xfader<xfader96_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank19_c0_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank19_c0_1 = parameter::from0To1<xfader96_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank19_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank19_c0_0<NV>, 
                                         sliderbank19_c0_1<NV>>;

using global_cable68_t_index = global_cable64_t_index;

template <int NV>
using global_cable68_t = routing::global_cable<global_cable68_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain321_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable68_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass105_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain321_t<NV>>>;

template <int NV>
using soft_bypass105_t = bypass::smoothed<20, soft_bypass105_t_<NV>>;
template <int NV>
using xfader111_c1 = parameter::bypass<soft_bypass105_t<NV>>;

template <int NV>
using xfader111_multimod = parameter::list<parameter::empty, xfader111_c1<NV>>;

template <int NV>
using xfader111_t = control::xfader<xfader111_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank19_c1_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank19_c1_1 = parameter::from0To1<xfader111_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank19_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank19_c1_0<NV>, 
                                         sliderbank19_c1_1<NV>>;

using global_cable69_t_index = global_cable65_t_index;

template <int NV>
using global_cable69_t = routing::global_cable<global_cable69_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain322_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable69_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass104_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain322_t<NV>>>;

template <int NV>
using soft_bypass104_t = bypass::smoothed<20, soft_bypass104_t_<NV>>;
template <int NV>
using xfader110_c1 = parameter::bypass<soft_bypass104_t<NV>>;

template <int NV>
using xfader110_multimod = parameter::list<parameter::empty, xfader110_c1<NV>>;

template <int NV>
using xfader110_t = control::xfader<xfader110_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank19_c2_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank19_c2_1 = parameter::from0To1<xfader110_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank19_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank19_c2_0<NV>, 
                                         sliderbank19_c2_1<NV>>;

using global_cable70_t_index = global_cable66_t_index;

template <int NV>
using global_cable70_t = routing::global_cable<global_cable70_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain323_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable70_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass103_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain323_t<NV>>>;

template <int NV>
using soft_bypass103_t = bypass::smoothed<20, soft_bypass103_t_<NV>>;
template <int NV>
using xfader109_c1 = parameter::bypass<soft_bypass103_t<NV>>;

template <int NV>
using xfader109_multimod = parameter::list<parameter::empty, xfader109_c1<NV>>;

template <int NV>
using xfader109_t = control::xfader<xfader109_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank19_c3_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank19_c3_1 = parameter::from0To1<xfader109_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank19_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank19_c3_0<NV>, 
                                         sliderbank19_c3_1<NV>>;

template <int NV> using event_data_reader22_t = event_data_reader16_t<NV>;

template <int NV>
using chain324_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader22_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass102_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain324_t<NV>>>;

template <int NV>
using soft_bypass102_t = bypass::smoothed<20, soft_bypass102_t_<NV>>;
template <int NV>
using xfader108_c1 = parameter::bypass<soft_bypass102_t<NV>>;

template <int NV>
using xfader108_multimod = parameter::list<parameter::empty, xfader108_c1<NV>>;

template <int NV>
using xfader108_t = control::xfader<xfader108_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank19_c4_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank19_c4_1 = parameter::from0To1<xfader108_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank19_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank19_c4_0<NV>, 
                                         sliderbank19_c4_1<NV>>;

template <int NV> using event_data_reader23_t = event_data_reader16_t<NV>;

template <int NV>
using chain325_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader23_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass101_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain325_t<NV>>>;

template <int NV>
using soft_bypass101_t = bypass::smoothed<20, soft_bypass101_t_<NV>>;
template <int NV>
using xfader107_c1 = parameter::bypass<soft_bypass101_t<NV>>;

template <int NV>
using xfader107_multimod = parameter::list<parameter::empty, xfader107_c1<NV>>;

template <int NV>
using xfader107_t = control::xfader<xfader107_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank19_c5_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank19_c5_1 = parameter::from0To1<xfader107_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank19_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank19_c5_0<NV>, 
                                         sliderbank19_c5_1<NV>>;

template <int NV> using event_data_reader18_t = event_data_reader16_t<NV>;

template <int NV>
using chain387_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader18_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader19_t = event_data_reader16_t<NV>;

template <int NV>
using chain405_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader19_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader20_t = event_data_reader16_t<NV>;

template <int NV>
using chain406_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader20_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader21_t = event_data_reader16_t<NV>;

template <int NV>
using chain407_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader21_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch20_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain387_t<NV>>, 
                                     chain405_t<NV>, 
                                     chain406_t<NV>, 
                                     chain407_t<NV>>;

template <int NV>
using chain326_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch20_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass100_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain326_t<NV>>>;

template <int NV>
using soft_bypass100_t = bypass::smoothed<20, soft_bypass100_t_<NV>>;
template <int NV>
using xfader106_c1 = parameter::bypass<soft_bypass100_t<NV>>;

template <int NV>
using xfader106_multimod = parameter::list<parameter::empty, xfader106_c1<NV>>;

template <int NV>
using xfader106_t = control::xfader<xfader106_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank19_c6_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank19_c6_1 = parameter::from0To1<xfader106_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank19_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank19_c6_0<NV>, 
                                         sliderbank19_c6_1<NV>>;

template <int NV> using midi_cc67_t = midi_cc63_t<NV>;

template <int NV>
using chain328_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc67_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc68_t = midi_cc63_t<NV>;

template <int NV>
using chain329_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc68_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc69_t = midi_cc63_t<NV>;

template <int NV>
using chain429_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc69_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc70_t = midi_cc63_t<NV>;

template <int NV>
using chain463_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc70_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi51_t = midi48_t<NV>;

template <int NV>
using chain464_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi51_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi52_t = midi49_t<NV>;

template <int NV>
using chain465_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi52_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi53_t = midi50_t<NV>;

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
using soft_bypass99_t_ = container::chain<parameter::empty, 
                                          wrap::fix<1, chain327_t<NV>>>;

template <int NV>
using soft_bypass99_t = bypass::smoothed<20, soft_bypass99_t_<NV>>;
template <int NV>
using xfader105_c1 = parameter::bypass<soft_bypass99_t<NV>>;

template <int NV>
using xfader105_multimod = parameter::list<parameter::empty, xfader105_c1<NV>>;

template <int NV>
using xfader105_t = control::xfader<xfader105_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank19_c7_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank19_c7_1 = parameter::from0To1<xfader105_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank19_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank19_c7_0<NV>, 
                                         sliderbank19_c7_1<NV>>;

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
                                  data::external::sliderpack<1>>;

template <int NV>
using chain424_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader96_t<NV>>, 
                                    soft_bypass90_t<NV>>;

template <int NV>
using chain446_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader111_t<NV>>, 
                                    soft_bypass105_t<NV>>;

template <int NV>
using chain445_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader110_t<NV>>, 
                                    soft_bypass104_t<NV>>;

template <int NV>
using chain444_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader109_t<NV>>, 
                                    soft_bypass103_t<NV>>;

template <int NV>
using chain443_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader108_t<NV>>, 
                                    soft_bypass102_t<NV>>;

template <int NV>
using chain442_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader107_t<NV>>, 
                                    soft_bypass101_t<NV>>;

template <int NV>
using chain441_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader106_t<NV>>, 
                                    soft_bypass100_t<NV>>;

template <int NV>
using chain440_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader105_t<NV>>, 
                                    soft_bypass99_t<NV>>;

template <int NV>
using split36_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain424_t<NV>>, 
                                   chain446_t<NV>, 
                                   chain445_t<NV>, 
                                   chain444_t<NV>, 
                                   chain443_t<NV>, 
                                   chain442_t<NV>, 
                                   chain441_t<NV>, 
                                   chain440_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table_modRange, 
                             0., 
                             100., 
                             0.01);

template <int NV>
using cable_table_mod = parameter::from0To1<project::Comb<NV>, 
                                            1, 
                                            cable_table_modRange>;

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
DECLARE_PARAMETER_RANGE_STEP(pma23_mod_2Range, 
                             0.5, 
                             1, 
                             0.01);

template <int NV>
using pma23_mod_2 = parameter::from0To1<project::khp2<NV>, 
                                        0, 
                                        pma23_mod_2Range>;

template <int NV>
using pma23_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<cable_table_t<NV>, 0>, 
                                   pma23_mod_2<NV>>;

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

using global_cable75_t_index = global_cable63_t_index;

template <int NV>
using global_cable75_t = routing::global_cable<global_cable75_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain340_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable75_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass106_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain340_t<NV>>>;

template <int NV>
using soft_bypass106_t = bypass::smoothed<20, soft_bypass106_t_<NV>>;
template <int NV>
using xfader112_c1 = parameter::bypass<soft_bypass106_t<NV>>;

template <int NV>
using xfader112_multimod = parameter::list<parameter::empty, xfader112_c1<NV>>;

template <int NV>
using xfader112_t = control::xfader<xfader112_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank21_c0_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank21_c0_1 = parameter::from0To1<xfader112_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank21_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank21_c0_0<NV>, 
                                         sliderbank21_c0_1<NV>>;

using global_cable76_t_index = global_cable64_t_index;

template <int NV>
using global_cable76_t = routing::global_cable<global_cable76_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain341_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable76_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass121_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain341_t<NV>>>;

template <int NV>
using soft_bypass121_t = bypass::smoothed<20, soft_bypass121_t_<NV>>;
template <int NV>
using xfader127_c1 = parameter::bypass<soft_bypass121_t<NV>>;

template <int NV>
using xfader127_multimod = parameter::list<parameter::empty, xfader127_c1<NV>>;

template <int NV>
using xfader127_t = control::xfader<xfader127_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank21_c1_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank21_c1_1 = parameter::from0To1<xfader127_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank21_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank21_c1_0<NV>, 
                                         sliderbank21_c1_1<NV>>;

using global_cable77_t_index = global_cable65_t_index;

template <int NV>
using global_cable77_t = routing::global_cable<global_cable77_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain342_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable77_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass120_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain342_t<NV>>>;

template <int NV>
using soft_bypass120_t = bypass::smoothed<20, soft_bypass120_t_<NV>>;
template <int NV>
using xfader126_c1 = parameter::bypass<soft_bypass120_t<NV>>;

template <int NV>
using xfader126_multimod = parameter::list<parameter::empty, xfader126_c1<NV>>;

template <int NV>
using xfader126_t = control::xfader<xfader126_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank21_c2_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank21_c2_1 = parameter::from0To1<xfader126_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank21_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank21_c2_0<NV>, 
                                         sliderbank21_c2_1<NV>>;

using soft_bypass119_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, core::empty>>;

using soft_bypass119_t = bypass::smoothed<20, soft_bypass119_t_>;
using xfader125_c1 = parameter::bypass<soft_bypass119_t>;

using xfader125_multimod = parameter::list<parameter::empty, xfader125_c1>;

using xfader125_t = control::xfader<xfader125_multimod, faders::switcher>;
template <int NV> using sliderbank21_c3_0 = sliderbank18_c0_0<NV>;

using sliderbank21_c3_1 = parameter::from0To1<xfader125_t, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank21_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank21_c3_0<NV>, 
                                         sliderbank21_c3_1>;

template <int NV> using event_data_reader28_t = event_data_reader16_t<NV>;

template <int NV>
using chain344_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader28_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass118_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain344_t<NV>>>;

template <int NV>
using soft_bypass118_t = bypass::smoothed<20, soft_bypass118_t_<NV>>;
template <int NV>
using xfader124_c1 = parameter::bypass<soft_bypass118_t<NV>>;

template <int NV>
using xfader124_multimod = parameter::list<parameter::empty, xfader124_c1<NV>>;

template <int NV>
using xfader124_t = control::xfader<xfader124_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank21_c4_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank21_c4_1 = parameter::from0To1<xfader124_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank21_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank21_c4_0<NV>, 
                                         sliderbank21_c4_1<NV>>;

template <int NV> using event_data_reader29_t = event_data_reader16_t<NV>;

template <int NV>
using chain345_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader29_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass117_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain345_t<NV>>>;

template <int NV>
using soft_bypass117_t = bypass::smoothed<20, soft_bypass117_t_<NV>>;
template <int NV>
using xfader123_c1 = parameter::bypass<soft_bypass117_t<NV>>;

template <int NV>
using xfader123_multimod = parameter::list<parameter::empty, xfader123_c1<NV>>;

template <int NV>
using xfader123_t = control::xfader<xfader123_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank21_c5_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank21_c5_1 = parameter::from0To1<xfader123_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank21_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank21_c5_0<NV>, 
                                         sliderbank21_c5_1<NV>>;

template <int NV> using event_data_reader24_t = event_data_reader16_t<NV>;

template <int NV>
using chain388_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader24_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader25_t = event_data_reader16_t<NV>;

template <int NV>
using chain408_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader25_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader26_t = event_data_reader16_t<NV>;

template <int NV>
using chain409_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader26_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader27_t = event_data_reader16_t<NV>;

template <int NV>
using chain410_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader27_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch21_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain388_t<NV>>, 
                                     chain408_t<NV>, 
                                     chain409_t<NV>, 
                                     chain410_t<NV>>;

template <int NV>
using chain346_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch21_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass116_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain346_t<NV>>>;

template <int NV>
using soft_bypass116_t = bypass::smoothed<20, soft_bypass116_t_<NV>>;
template <int NV>
using xfader122_c1 = parameter::bypass<soft_bypass116_t<NV>>;

template <int NV>
using xfader122_multimod = parameter::list<parameter::empty, xfader122_c1<NV>>;

template <int NV>
using xfader122_t = control::xfader<xfader122_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank21_c6_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank21_c6_1 = parameter::from0To1<xfader122_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank21_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank21_c6_0<NV>, 
                                         sliderbank21_c6_1<NV>>;

template <int NV> using midi_cc75_t = midi_cc63_t<NV>;

template <int NV>
using chain348_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc75_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc76_t = midi_cc63_t<NV>;

template <int NV>
using chain349_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc76_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc77_t = midi_cc63_t<NV>;

template <int NV>
using chain431_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc77_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc78_t = midi_cc63_t<NV>;

template <int NV>
using chain471_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc78_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi57_t = midi48_t<NV>;

template <int NV>
using chain472_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi57_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi58_t = midi49_t<NV>;

template <int NV>
using chain473_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi58_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi59_t = midi50_t<NV>;

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
using soft_bypass115_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain347_t<NV>>>;

template <int NV>
using soft_bypass115_t = bypass::smoothed<20, soft_bypass115_t_<NV>>;
template <int NV>
using xfader121_c1 = parameter::bypass<soft_bypass115_t<NV>>;

template <int NV>
using xfader121_multimod = parameter::list<parameter::empty, xfader121_c1<NV>>;

template <int NV>
using xfader121_t = control::xfader<xfader121_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank21_c7_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank21_c7_1 = parameter::from0To1<xfader121_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank21_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank21_c7_0<NV>, 
                                         sliderbank21_c7_1<NV>>;

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
                                  data::external::sliderpack<2>>;

template <int NV>
using chain447_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader112_t<NV>>, 
                                    soft_bypass106_t<NV>>;

template <int NV>
using chain500_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader127_t<NV>>, 
                                    soft_bypass121_t<NV>>;

template <int NV>
using chain499_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader126_t<NV>>, 
                                    soft_bypass120_t<NV>>;
using global_cable78_t_index = global_cable66_t_index;

template <int NV>
using global_cable78_t = routing::global_cable<global_cable78_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain343_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable78_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using chain498_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader125_t>, 
                                    chain343_t<NV>, 
                                    soft_bypass119_t>;

template <int NV>
using chain497_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader124_t<NV>>, 
                                    soft_bypass118_t<NV>>;

template <int NV>
using chain496_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader123_t<NV>>, 
                                    soft_bypass117_t<NV>>;

template <int NV>
using chain495_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader122_t<NV>>, 
                                    soft_bypass116_t<NV>>;

template <int NV>
using chain484_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader121_t<NV>>, 
                                    soft_bypass115_t<NV>>;

template <int NV>
using split38_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain447_t<NV>>, 
                                   chain500_t<NV>, 
                                   chain499_t<NV>, 
                                   chain498_t<NV>, 
                                   chain497_t<NV>, 
                                   chain496_t<NV>, 
                                   chain495_t<NV>, 
                                   chain484_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma25_modRange, 
                             -100., 
                             24., 
                             5.42227);

template <int NV>
using pma25_mod = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      pma25_modRange>;

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

using global_cable79_t_index = global_cable63_t_index;

template <int NV>
using global_cable79_t = routing::global_cable<global_cable79_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain350_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable79_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass114_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain350_t<NV>>>;

template <int NV>
using soft_bypass114_t = bypass::smoothed<20, soft_bypass114_t_<NV>>;
template <int NV>
using xfader120_c1 = parameter::bypass<soft_bypass114_t<NV>>;

template <int NV>
using xfader120_multimod = parameter::list<parameter::empty, xfader120_c1<NV>>;

template <int NV>
using xfader120_t = control::xfader<xfader120_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank22_c0_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank22_c0_1 = parameter::from0To1<xfader120_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank22_c0 = parameter::chain<ranges::Identity, 
                                         sliderbank22_c0_0<NV>, 
                                         sliderbank22_c0_1<NV>>;

using global_cable80_t_index = global_cable64_t_index;

template <int NV>
using global_cable80_t = routing::global_cable<global_cable80_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain351_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable80_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass128_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain351_t<NV>>>;

template <int NV>
using soft_bypass128_t = bypass::smoothed<20, soft_bypass128_t_<NV>>;
template <int NV>
using xfader134_c1 = parameter::bypass<soft_bypass128_t<NV>>;

template <int NV>
using xfader134_multimod = parameter::list<parameter::empty, xfader134_c1<NV>>;

template <int NV>
using xfader134_t = control::xfader<xfader134_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank22_c1_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank22_c1_1 = parameter::from0To1<xfader134_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank22_c1 = parameter::chain<ranges::Identity, 
                                         sliderbank22_c1_0<NV>, 
                                         sliderbank22_c1_1<NV>>;

using global_cable81_t_index = global_cable65_t_index;

template <int NV>
using global_cable81_t = routing::global_cable<global_cable81_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain352_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable81_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass127_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain352_t<NV>>>;

template <int NV>
using soft_bypass127_t = bypass::smoothed<20, soft_bypass127_t_<NV>>;
template <int NV>
using xfader133_c1 = parameter::bypass<soft_bypass127_t<NV>>;

template <int NV>
using xfader133_multimod = parameter::list<parameter::empty, xfader133_c1<NV>>;

template <int NV>
using xfader133_t = control::xfader<xfader133_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank22_c2_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank22_c2_1 = parameter::from0To1<xfader133_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank22_c2 = parameter::chain<ranges::Identity, 
                                         sliderbank22_c2_0<NV>, 
                                         sliderbank22_c2_1<NV>>;

using global_cable82_t_index = global_cable66_t_index;

template <int NV>
using global_cable82_t = routing::global_cable<global_cable82_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain353_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable82_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass126_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain353_t<NV>>>;

template <int NV>
using soft_bypass126_t = bypass::smoothed<20, soft_bypass126_t_<NV>>;
template <int NV>
using xfader132_c1 = parameter::bypass<soft_bypass126_t<NV>>;

template <int NV>
using xfader132_multimod = parameter::list<parameter::empty, xfader132_c1<NV>>;

template <int NV>
using xfader132_t = control::xfader<xfader132_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank22_c3_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank22_c3_1 = parameter::from0To1<xfader132_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank22_c3 = parameter::chain<ranges::Identity, 
                                         sliderbank22_c3_0<NV>, 
                                         sliderbank22_c3_1<NV>>;

template <int NV> using event_data_reader34_t = event_data_reader16_t<NV>;

template <int NV>
using chain354_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader34_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass125_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain354_t<NV>>>;

template <int NV>
using soft_bypass125_t = bypass::smoothed<20, soft_bypass125_t_<NV>>;
template <int NV>
using xfader131_c1 = parameter::bypass<soft_bypass125_t<NV>>;

template <int NV>
using xfader131_multimod = parameter::list<parameter::empty, xfader131_c1<NV>>;

template <int NV>
using xfader131_t = control::xfader<xfader131_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank22_c4_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank22_c4_1 = parameter::from0To1<xfader131_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank22_c4 = parameter::chain<ranges::Identity, 
                                         sliderbank22_c4_0<NV>, 
                                         sliderbank22_c4_1<NV>>;

template <int NV> using event_data_reader35_t = event_data_reader16_t<NV>;

template <int NV>
using chain355_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader35_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass124_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain355_t<NV>>>;

template <int NV>
using soft_bypass124_t = bypass::smoothed<20, soft_bypass124_t_<NV>>;
template <int NV>
using xfader130_c1 = parameter::bypass<soft_bypass124_t<NV>>;

template <int NV>
using xfader130_multimod = parameter::list<parameter::empty, xfader130_c1<NV>>;

template <int NV>
using xfader130_t = control::xfader<xfader130_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank22_c5_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank22_c5_1 = parameter::from0To1<xfader130_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank22_c5 = parameter::chain<ranges::Identity, 
                                         sliderbank22_c5_0<NV>, 
                                         sliderbank22_c5_1<NV>>;

template <int NV> using event_data_reader30_t = event_data_reader16_t<NV>;

template <int NV>
using chain389_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader30_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader31_t = event_data_reader16_t<NV>;

template <int NV>
using chain411_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader31_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader32_t = event_data_reader16_t<NV>;

template <int NV>
using chain412_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader32_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using event_data_reader33_t = event_data_reader16_t<NV>;

template <int NV>
using chain413_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader33_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch22_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain389_t<NV>>, 
                                     chain411_t<NV>, 
                                     chain412_t<NV>, 
                                     chain413_t<NV>>;

template <int NV>
using chain356_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch22_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using soft_bypass123_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain356_t<NV>>>;

template <int NV>
using soft_bypass123_t = bypass::smoothed<20, soft_bypass123_t_<NV>>;
template <int NV>
using xfader129_c1 = parameter::bypass<soft_bypass123_t<NV>>;

template <int NV>
using xfader129_multimod = parameter::list<parameter::empty, xfader129_c1<NV>>;

template <int NV>
using xfader129_t = control::xfader<xfader129_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank22_c6_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank22_c6_1 = parameter::from0To1<xfader129_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank22_c6 = parameter::chain<ranges::Identity, 
                                         sliderbank22_c6_0<NV>, 
                                         sliderbank22_c6_1<NV>>;

template <int NV> using midi_cc79_t = midi_cc63_t<NV>;

template <int NV>
using chain358_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc79_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc80_t = midi_cc63_t<NV>;

template <int NV>
using chain359_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc80_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc81_t = midi_cc63_t<NV>;

template <int NV>
using chain432_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc81_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc82_t = midi_cc63_t<NV>;

template <int NV>
using chain475_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc82_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi60_t = midi48_t<NV>;

template <int NV>
using chain476_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi60_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi61_t = midi49_t<NV>;

template <int NV>
using chain477_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi61_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi62_t = midi50_t<NV>;

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
using soft_bypass122_t_ = container::chain<parameter::empty, 
                                           wrap::fix<1, chain357_t<NV>>>;

template <int NV>
using soft_bypass122_t = bypass::smoothed<20, soft_bypass122_t_<NV>>;
template <int NV>
using xfader128_c1 = parameter::bypass<soft_bypass122_t<NV>>;

template <int NV>
using xfader128_multimod = parameter::list<parameter::empty, xfader128_c1<NV>>;

template <int NV>
using xfader128_t = control::xfader<xfader128_multimod<NV>, faders::switcher>;
template <int NV> using sliderbank22_c7_0 = sliderbank18_c0_0<NV>;

template <int NV>
using sliderbank22_c7_1 = parameter::from0To1<xfader128_t<NV>, 
                                              0, 
                                              sliderbank18_c0_1Range>;

template <int NV>
using sliderbank22_c7 = parameter::chain<ranges::Identity, 
                                         sliderbank22_c7_0<NV>, 
                                         sliderbank22_c7_1<NV>>;

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
                                  data::external::sliderpack<3>>;

template <int NV>
using chain483_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader120_t<NV>>, 
                                    soft_bypass114_t<NV>>;

template <int NV>
using chain507_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader134_t<NV>>, 
                                    soft_bypass128_t<NV>>;

template <int NV>
using chain506_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader133_t<NV>>, 
                                    soft_bypass127_t<NV>>;

template <int NV>
using chain505_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader132_t<NV>>, 
                                    soft_bypass126_t<NV>>;

template <int NV>
using chain504_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader131_t<NV>>, 
                                    soft_bypass125_t<NV>>;

template <int NV>
using chain503_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader130_t<NV>>, 
                                    soft_bypass124_t<NV>>;

template <int NV>
using chain502_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader129_t<NV>>, 
                                    soft_bypass123_t<NV>>;

template <int NV>
using chain501_t = container::chain<parameter::empty, 
                                    wrap::fix<1, xfader128_t<NV>>, 
                                    soft_bypass122_t<NV>>;

template <int NV>
using split39_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain483_t<NV>>, 
                                   chain507_t<NV>, 
                                   chain506_t<NV>, 
                                   chain505_t<NV>, 
                                   chain504_t<NV>, 
                                   chain503_t<NV>, 
                                   chain502_t<NV>, 
                                   chain501_t<NV>>;

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
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, modchain19_t<NV>>, 
                                 modchain20_t<NV>, 
                                 modchain22_t<NV>, 
                                 modchain23_t<NV>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::klp<NV>>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::khp2<NV>>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table_t<NV>>, 
                                   project::Comb<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain16_t<NV>>, 
                                   chain35_t<NV>, 
                                   chain36_t<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch_t<NV>>>;
using stereo_cable = cable::block<2>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain15_t<NV>>, 
                                   routing::send<stereo_cable>, 
                                   core::gain<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain14_t<NV>>, 
                                   chain57_t<NV>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader_t<NV>>, 
                                   split12_t<NV>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain58_t<NV>>>;

template <int NV>
using xfade_2x_lin_t = container::chain<parameter::empty, 
                                        wrap::fix<2, split20_t<NV>>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfade_2x_lin_t<NV>>>;
using oscilloscope_t = wrap::data<analyse::oscilloscope, 
                                  data::external::displaybuffer<2>>;

namespace Filter_t_parameters
{
// Parameter list for Filter_impl::Filter_t --------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(Q_1Range, 
                             0.5, 
                             10., 
                             0.01);

template <int NV>
using Q_1 = parameter::from0To1<project::klp<NV>, 
                                0, 
                                Q_1Range>;

template <int NV>
using Q = parameter::chain<ranges::Identity, 
                           parameter::plain<project::Comb<NV>, 0>, 
                           Q_1<NV>, 
                           parameter::plain<project::khp2<NV>, 1>>;

DECLARE_PARAMETER_RANGE_SKEW(Cut1_InputRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using Cut1 = parameter::chain<Cut1_InputRange, 
                              parameter::plain<Filter_impl::pma23_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(FilterMidiMix_InputRange, 
                        1., 
                        7.);
DECLARE_PARAMETER_RANGE_STEP(FilterMidiMix_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using FilterMidiMix_0 = parameter::from0To1<Filter_impl::branch62_t<NV>, 
                                            0, 
                                            FilterMidiMix_0Range>;

template <int NV>
using FilterMidiMix = parameter::chain<FilterMidiMix_InputRange, 
                                       FilterMidiMix_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterMidiCut1_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiCut1_0 = parameter::from0To1<Filter_impl::branch64_t<NV>, 
                                             0, 
                                             FilterMidiMix_0Range>;

template <int NV>
using FilterMidiCut1 = parameter::chain<FilterMidiCut1_InputRange, 
                                        FilterMidiCut1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FilterMode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using FilterMode_0 = parameter::from0To1<Filter_impl::branch_t<NV>, 
                                         0, 
                                         FilterMode_0Range>;

template <int NV>
using FilterMode = parameter::chain<FilterMode_InputRange, FilterMode_0<NV>>;

DECLARE_PARAMETER_RANGE(PAn_InputRange, 
                        -1., 
                        1.);

template <int NV>
using PAn = parameter::chain<PAn_InputRange, 
                             parameter::plain<Filter_impl::pma26_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(CutPK_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(CutPK_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using CutPK_0 = parameter::from0To1<Filter_impl::branch20_t<NV>, 
                                    0, 
                                    CutPK_0Range>;

template <int NV>
using CutPK = parameter::chain<CutPK_InputRange, CutPK_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(GainMidi_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using GainMidi_0 = parameter::from0To1<Filter_impl::branch68_t<NV>, 
                                       0, 
                                       FilterMidiMix_0Range>;

template <int NV>
using GainMidi = parameter::chain<GainMidi_InputRange, GainMidi_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(GainPk_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using GainPk_0 = parameter::from0To1<Filter_impl::branch21_t<NV>, 
                                     0, 
                                     CutPK_0Range>;

template <int NV>
using GainPk = parameter::chain<GainPk_InputRange, GainPk_0<NV>>;

DECLARE_PARAMETER_RANGE(PanMidi_InputRange, 
                        1., 
                        7.);
template <int NV>
using PanMidi_0 = parameter::from0To1<Filter_impl::branch70_t<NV>, 
                                      0, 
                                      FilterMidiMix_0Range>;

template <int NV>
using PanMidi = parameter::chain<PanMidi_InputRange, PanMidi_0<NV>>;

DECLARE_PARAMETER_RANGE(PanPk_InputRange, 
                        1., 
                        4.);
template <int NV>
using PanPk_0 = parameter::from0To1<Filter_impl::branch22_t<NV>, 
                                    0, 
                                    CutPK_0Range>;

template <int NV>
using PanPk = parameter::chain<PanPk_InputRange, PanPk_0<NV>>;

template <int NV>
using FilterMixPk = parameter::from0To1<Filter_impl::branch19_t<NV>, 
                                        0, 
                                        CutPK_0Range>;

template <int NV>
using FilterMix = parameter::plain<Filter_impl::pma22_t<NV>, 
                                   2>;
template <int NV>
using FilterMod = parameter::plain<Filter_impl::pma22_t<NV>, 
                                   1>;
template <int NV>
using Cut1Mod = parameter::plain<Filter_impl::pma23_t<NV>, 
                                 1>;
using FilerInOsc1 = parameter::empty;
using FilterInOSc2 = FilerInOsc1;
using FilterInFile = FilerInOsc1;
template <int NV>
using Gain = parameter::plain<Filter_impl::pma25_t<NV>, 
                              2>;
template <int NV>
using GainMod = parameter::plain<Filter_impl::pma25_t<NV>, 
                                 1>;
template <int NV>
using PanMod = parameter::plain<Filter_impl::pma26_t<NV>, 
                                1>;
template <int NV>
using Filter_t_plist = parameter::list<Q<NV>, 
                                       FilterMix<NV>, 
                                       FilterMod<NV>, 
                                       Cut1<NV>, 
                                       Cut1Mod<NV>, 
                                       FilterMidiMix<NV>, 
                                       FilterMidiCut1<NV>, 
                                       FilterMode<NV>, 
                                       FilerInOsc1, 
                                       FilterInOSc2, 
                                       FilterInFile, 
                                       Gain<NV>, 
                                       GainMod<NV>, 
                                       PAn<NV>, 
                                       PanMod<NV>, 
                                       CutPK<NV>, 
                                       GainMidi<NV>, 
                                       GainPk<NV>, 
                                       PanMidi<NV>, 
                                       PanPk<NV>, 
                                       FilterMixPk<NV>>;
}

template <int NV>
using Filter_t_ = container::chain<Filter_t_parameters::Filter_t_plist<NV>, 
                                   wrap::fix<2, split_t<NV>>, 
                                   chain59_t<NV>, 
                                   core::gain<NV>, 
                                   oscilloscope_t, 
                                   jdsp::jpanner<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public Filter_impl::Filter_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 3;
		
		SNEX_METADATA_ID(Filter);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(356)
		{
			0x005B, 0x0000, 0x5100, 0x0000, 0x0000, 0x0000, 0x8000, 0xA43F, 
            0x7D70, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x590B, 0x3E8E, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0003, 0x0000, 0x7543, 0x3174, 0x0000, 0xA000, 0x0041, 
            0x9C40, 0x0046, 0xB390, 0x1A45, 0x6B6C, 0x003E, 0x0000, 0x5B00, 
            0x0004, 0x0000, 0x7543, 0x3174, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x055B, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x6469, 0x4D69, 
            0x7869, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 0x6946, 0x746C, 
            0x7265, 0x694D, 0x6964, 0x7543, 0x3174, 0x0000, 0x8000, 0x003F, 
            0xE000, 0x0040, 0xC000, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0007, 0x0000, 0x6946, 0x746C, 0x7265, 0x6F4D, 0x6564, 0x0000, 
            0x8000, 0x003F, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0008, 0x0000, 0x6946, 0x656C, 0x4972, 0x4F6E, 
            0x6373, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x4972, 0x4F6E, 0x6353, 0x0032, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 
            0x0000, 0x4600, 0x6C69, 0x6574, 0x4972, 0x466E, 0x6C69, 0x0065, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0B5B, 0x0000, 0x4700, 0x6961, 0x006E, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0xF5C3, 0x3F68, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0C5B, 0x0000, 0x4700, 0x6961, 0x4D6E, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000D, 0x0000, 0x4150, 0x006E, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0E5B, 0x0000, 0x5000, 0x6E61, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0F5B, 0x0000, 0x4300, 0x7475, 0x4B50, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0040, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0010, 0x0000, 0x6147, 0x6E69, 0x694D, 0x6964, 0x0000, 0x8000, 
            0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0011, 0x0000, 0x6147, 0x6E69, 0x6B50, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0012, 0x0000, 0x6150, 0x4D6E, 0x6469, 0x0069, 0x0000, 
            0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x135B, 0x0000, 0x5000, 0x6E61, 0x6B50, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0014, 0x0000, 0x6946, 0x746C, 0x7265, 0x694D, 0x5078, 
            0x006B, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split = this->getT(0);                                                               // Filter_impl::split_t<NV>
		auto& modchain19 = this->getT(0).getT(0);                                                  // Filter_impl::modchain19_t<NV>
		auto& sliderbank18 = this->getT(0).getT(0).getT(0);                                        // Filter_impl::sliderbank18_t<NV>
		auto& split35 = this->getT(0).getT(0).getT(1);                                             // Filter_impl::split35_t<NV>
		auto& chain416 = this->getT(0).getT(0).getT(1).getT(0);                                    // Filter_impl::chain416_t<NV>
		auto& xfader88 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                            // Filter_impl::xfader88_t<NV>
		auto& soft_bypass82 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                       // Filter_impl::soft_bypass82_t<NV>
		auto& chain310 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);                    // Filter_impl::chain310_t<NV>
		auto& global_cable63 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0);      // Filter_impl::global_cable63_t<NV>
		auto& add265 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain244 = this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain438 = this->getT(0).getT(0).getT(1).getT(1);                                    // Filter_impl::chain438_t<NV>
		auto& xfader103 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                           // Filter_impl::xfader103_t<NV>
		auto& soft_bypass97 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                       // Filter_impl::soft_bypass97_t<NV>
		auto& chain311 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);                    // Filter_impl::chain311_t<NV>
		auto& global_cable64 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(0);      // Filter_impl::global_cable64_t<NV>
		auto& add266 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain245 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain437 = this->getT(0).getT(0).getT(1).getT(2);                                    // Filter_impl::chain437_t<NV>
		auto& xfader102 = this->getT(0).getT(0).getT(1).getT(2).getT(0);                           // Filter_impl::xfader102_t<NV>
		auto& soft_bypass96 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                       // Filter_impl::soft_bypass96_t<NV>
		auto& chain312 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0);                    // Filter_impl::chain312_t<NV>
		auto& global_cable65 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(0);      // Filter_impl::global_cable65_t<NV>
		auto& add267 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain246 = this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain436 = this->getT(0).getT(0).getT(1).getT(3);                                    // Filter_impl::chain436_t<NV>
		auto& xfader101 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                           // Filter_impl::xfader101_t<NV>
		auto& soft_bypass95 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                       // Filter_impl::soft_bypass95_t<NV>
		auto& chain313 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0);                    // Filter_impl::chain313_t<NV>
		auto& global_cable66 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(0);      // Filter_impl::global_cable66_t<NV>
		auto& add268 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain247 = this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain435 = this->getT(0).getT(0).getT(1).getT(4);                                    // Filter_impl::chain435_t<NV>
		auto& xfader100 = this->getT(0).getT(0).getT(1).getT(4).getT(0);                           // Filter_impl::xfader100_t<NV>
		auto& soft_bypass94 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                       // Filter_impl::soft_bypass94_t<NV>
		auto& chain314 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0);                    // Filter_impl::chain314_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(0); // Filter_impl::event_data_reader16_t<NV>
		auto& add269 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain248 = this->getT(0).getT(0).getT(1).getT(4).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain434 = this->getT(0).getT(0).getT(1).getT(5);                                    // Filter_impl::chain434_t<NV>
		auto& xfader99 = this->getT(0).getT(0).getT(1).getT(5).getT(0);                            // Filter_impl::xfader99_t<NV>
		auto& soft_bypass93 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                       // Filter_impl::soft_bypass93_t<NV>
		auto& chain315 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0);                    // Filter_impl::chain315_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(0); // Filter_impl::event_data_reader17_t<NV>
		auto& add270 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain249 = this->getT(0).getT(0).getT(1).getT(5).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain433 = this->getT(0).getT(0).getT(1).getT(6);                                    // Filter_impl::chain433_t<NV>
		auto& xfader98 = this->getT(0).getT(0).getT(1).getT(6).getT(0);                            // Filter_impl::xfader98_t<NV>
		auto& soft_bypass92 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                       // Filter_impl::soft_bypass92_t<NV>
		auto& chain316 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0);                    // Filter_impl::chain316_t<NV>
		auto& branch19 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).getT(0);            // Filter_impl::branch19_t<NV>
		auto& chain386 = this->getT(0).getT(0).getT(1).getT(6).                                    // Filter_impl::chain386_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& event_data_reader12 = this->getT(0).getT(0).getT(1).getT(6).                         // routing::event_data_reader<NV>
                                    getT(1).getT(0).getT(0).getT(0).
                                    getT(0);
		auto& add7 = this->getT(0).getT(0).getT(1).getT(6).                                        // math::add<NV>
                     getT(1).getT(0).getT(0).getT(0).
                     getT(1);
		auto& chain402 = this->getT(0).getT(0).getT(1).getT(6).                                    // Filter_impl::chain402_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& event_data_reader13 = this->getT(0).getT(0).getT(1).getT(6).                         // routing::event_data_reader<NV>
                                    getT(1).getT(0).getT(0).getT(1).
                                    getT(0);
		auto& add23 = this->getT(0).getT(0).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1).
                      getT(1);
		auto& chain403 = this->getT(0).getT(0).getT(1).getT(6).                                    // Filter_impl::chain403_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& event_data_reader14 = this->getT(0).getT(0).getT(1).getT(6).                         // routing::event_data_reader<NV>
                                    getT(1).getT(0).getT(0).getT(2).
                                    getT(0);
		auto& add24 = this->getT(0).getT(0).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain404 = this->getT(0).getT(0).getT(1).getT(6).                                    // Filter_impl::chain404_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& event_data_reader15 = this->getT(0).getT(0).getT(1).getT(6).                         // routing::event_data_reader<NV>
                                    getT(1).getT(0).getT(0).getT(3).
                                    getT(0);
		auto& add25 = this->getT(0).getT(0).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(3).
                      getT(1);
		auto& add275 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain250 = this->getT(0).getT(0).getT(1).getT(6).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain425 = this->getT(0).getT(0).getT(1).getT(7);                                    // Filter_impl::chain425_t<NV>
		auto& xfader97 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                            // Filter_impl::xfader97_t<NV>
		auto& soft_bypass91 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                       // Filter_impl::soft_bypass91_t<NV>
		auto& chain317 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0);                    // Filter_impl::chain317_t<NV>
		auto& branch62 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).getT(0);            // Filter_impl::branch62_t<NV>
		auto& chain318 = this->getT(0).getT(0).getT(1).getT(7).                                    // Filter_impl::chain318_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& midi_cc63 = this->getT(0).getT(0).getT(1).getT(7).                                   // Filter_impl::midi_cc63_t<NV>
                          getT(1).getT(0).getT(0).getT(0).
                          getT(0);
		auto& add408 = this->getT(0).getT(0).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(0).
                       getT(1);
		auto& chain319 = this->getT(0).getT(0).getT(1).getT(7).                                    // Filter_impl::chain319_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& midi_cc64 = this->getT(0).getT(0).getT(1).getT(7).                                   // Filter_impl::midi_cc64_t<NV>
                          getT(1).getT(0).getT(0).getT(1).
                          getT(0);
		auto& add409 = this->getT(0).getT(0).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(1).
                       getT(1);
		auto& chain428 = this->getT(0).getT(0).getT(1).getT(7).                                    // Filter_impl::chain428_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& midi_cc65 = this->getT(0).getT(0).getT(1).getT(7).                                   // Filter_impl::midi_cc65_t<NV>
                          getT(1).getT(0).getT(0).getT(2).
                          getT(0);
		auto& add410 = this->getT(0).getT(0).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(2).
                       getT(1);
		auto& chain459 = this->getT(0).getT(0).getT(1).getT(7).                                    // Filter_impl::chain459_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& midi_cc66 = this->getT(0).getT(0).getT(1).getT(7).                                   // Filter_impl::midi_cc66_t<NV>
                          getT(1).getT(0).getT(0).getT(3).
                          getT(0);
		auto& add411 = this->getT(0).getT(0).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(3).
                       getT(1);
		auto& chain460 = this->getT(0).getT(0).getT(1).getT(7).                                    // Filter_impl::chain460_t<NV>
                         getT(1).getT(0).getT(0).getT(4);
		auto& midi48 = this->getT(0).getT(0).getT(1).getT(7).                                      // Filter_impl::midi48_t<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(0);
		auto& add412 = this->getT(0).getT(0).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(1);
		auto& chain461 = this->getT(0).getT(0).getT(1).getT(7).                                    // Filter_impl::chain461_t<NV>
                         getT(1).getT(0).getT(0).getT(5);
		auto& midi49 = this->getT(0).getT(0).getT(1).getT(7).                                      // Filter_impl::midi49_t<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(0);
		auto& add413 = this->getT(0).getT(0).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(1);
		auto& chain462 = this->getT(0).getT(0).getT(1).getT(7).                                    // Filter_impl::chain462_t<NV>
                         getT(1).getT(0).getT(0).getT(6);
		auto& midi50 = this->getT(0).getT(0).getT(1).getT(7).                                      // Filter_impl::midi50_t<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(0);
		auto& add414 = this->getT(0).getT(0).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(1);
		auto& gain251 = this->getT(0).getT(0).getT(1).getT(7).getT(1).getT(0).getT(1);             // core::gain<NV>
		auto& peak38 = this->getT(0).getT(0).getT(2);                                              // Filter_impl::peak38_t<NV>
		auto& pma22 = this->getT(0).getT(0).getT(3);                                               // Filter_impl::pma22_t<NV>
		auto& modchain20 = this->getT(0).getT(1);                                                  // Filter_impl::modchain20_t<NV>
		auto& sliderbank19 = this->getT(0).getT(1).getT(0);                                        // Filter_impl::sliderbank19_t<NV>
		auto& split36 = this->getT(0).getT(1).getT(1);                                             // Filter_impl::split36_t<NV>
		auto& chain424 = this->getT(0).getT(1).getT(1).getT(0);                                    // Filter_impl::chain424_t<NV>
		auto& xfader96 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                            // Filter_impl::xfader96_t<NV>
		auto& soft_bypass90 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                       // Filter_impl::soft_bypass90_t<NV>
		auto& chain320 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0);                    // Filter_impl::chain320_t<NV>
		auto& global_cable67 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(0);      // Filter_impl::global_cable67_t<NV>
		auto& add276 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain252 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain446 = this->getT(0).getT(1).getT(1).getT(1);                                    // Filter_impl::chain446_t<NV>
		auto& xfader111 = this->getT(0).getT(1).getT(1).getT(1).getT(0);                           // Filter_impl::xfader111_t<NV>
		auto& soft_bypass105 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                      // Filter_impl::soft_bypass105_t<NV>
		auto& chain321 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0);                    // Filter_impl::chain321_t<NV>
		auto& global_cable68 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).getT(0);      // Filter_impl::global_cable68_t<NV>
		auto& add277 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain253 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain445 = this->getT(0).getT(1).getT(1).getT(2);                                    // Filter_impl::chain445_t<NV>
		auto& xfader110 = this->getT(0).getT(1).getT(1).getT(2).getT(0);                           // Filter_impl::xfader110_t<NV>
		auto& soft_bypass104 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                      // Filter_impl::soft_bypass104_t<NV>
		auto& chain322 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0);                    // Filter_impl::chain322_t<NV>
		auto& global_cable69 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(0);      // Filter_impl::global_cable69_t<NV>
		auto& add278 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain254 = this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain444 = this->getT(0).getT(1).getT(1).getT(3);                                    // Filter_impl::chain444_t<NV>
		auto& xfader109 = this->getT(0).getT(1).getT(1).getT(3).getT(0);                           // Filter_impl::xfader109_t<NV>
		auto& soft_bypass103 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                      // Filter_impl::soft_bypass103_t<NV>
		auto& chain323 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0);                    // Filter_impl::chain323_t<NV>
		auto& global_cable70 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).getT(0);      // Filter_impl::global_cable70_t<NV>
		auto& add279 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain255 = this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain443 = this->getT(0).getT(1).getT(1).getT(4);                                    // Filter_impl::chain443_t<NV>
		auto& xfader108 = this->getT(0).getT(1).getT(1).getT(4).getT(0);                           // Filter_impl::xfader108_t<NV>
		auto& soft_bypass102 = this->getT(0).getT(1).getT(1).getT(4).getT(1);                      // Filter_impl::soft_bypass102_t<NV>
		auto& chain324 = this->getT(0).getT(1).getT(1).getT(4).getT(1).getT(0);                    // Filter_impl::chain324_t<NV>
		auto& event_data_reader22 = this->getT(0).getT(1).getT(1).getT(4).getT(1).getT(0).getT(0); // Filter_impl::event_data_reader22_t<NV>
		auto& add280 = this->getT(0).getT(1).getT(1).getT(4).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain256 = this->getT(0).getT(1).getT(1).getT(4).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain442 = this->getT(0).getT(1).getT(1).getT(5);                                    // Filter_impl::chain442_t<NV>
		auto& xfader107 = this->getT(0).getT(1).getT(1).getT(5).getT(0);                           // Filter_impl::xfader107_t<NV>
		auto& soft_bypass101 = this->getT(0).getT(1).getT(1).getT(5).getT(1);                      // Filter_impl::soft_bypass101_t<NV>
		auto& chain325 = this->getT(0).getT(1).getT(1).getT(5).getT(1).getT(0);                    // Filter_impl::chain325_t<NV>
		auto& event_data_reader23 = this->getT(0).getT(1).getT(1).getT(5).getT(1).getT(0).getT(0); // Filter_impl::event_data_reader23_t<NV>
		auto& add281 = this->getT(0).getT(1).getT(1).getT(5).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain257 = this->getT(0).getT(1).getT(1).getT(5).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain441 = this->getT(0).getT(1).getT(1).getT(6);                                    // Filter_impl::chain441_t<NV>
		auto& xfader106 = this->getT(0).getT(1).getT(1).getT(6).getT(0);                           // Filter_impl::xfader106_t<NV>
		auto& soft_bypass100 = this->getT(0).getT(1).getT(1).getT(6).getT(1);                      // Filter_impl::soft_bypass100_t<NV>
		auto& chain326 = this->getT(0).getT(1).getT(1).getT(6).getT(1).getT(0);                    // Filter_impl::chain326_t<NV>
		auto& branch20 = this->getT(0).getT(1).getT(1).getT(6).getT(1).getT(0).getT(0);            // Filter_impl::branch20_t<NV>
		auto& chain387 = this->getT(0).getT(1).getT(1).getT(6).                                    // Filter_impl::chain387_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& event_data_reader18 = this->getT(0).getT(1).getT(1).getT(6).                         // Filter_impl::event_data_reader18_t<NV>
                                    getT(1).getT(0).getT(0).getT(0).
                                    getT(0);
		auto& add8 = this->getT(0).getT(1).getT(1).getT(6).                                        // math::add<NV>
                     getT(1).getT(0).getT(0).getT(0).
                     getT(1);
		auto& chain405 = this->getT(0).getT(1).getT(1).getT(6).                                    // Filter_impl::chain405_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& event_data_reader19 = this->getT(0).getT(1).getT(1).getT(6).                         // Filter_impl::event_data_reader19_t<NV>
                                    getT(1).getT(0).getT(0).getT(1).
                                    getT(0);
		auto& add26 = this->getT(0).getT(1).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1).
                      getT(1);
		auto& chain406 = this->getT(0).getT(1).getT(1).getT(6).                                    // Filter_impl::chain406_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& event_data_reader20 = this->getT(0).getT(1).getT(1).getT(6).                         // Filter_impl::event_data_reader20_t<NV>
                                    getT(1).getT(0).getT(0).getT(2).
                                    getT(0);
		auto& add27 = this->getT(0).getT(1).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain407 = this->getT(0).getT(1).getT(1).getT(6).                                    // Filter_impl::chain407_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& event_data_reader21 = this->getT(0).getT(1).getT(1).getT(6).                         // Filter_impl::event_data_reader21_t<NV>
                                    getT(1).getT(0).getT(0).getT(3).
                                    getT(0);
		auto& add28 = this->getT(0).getT(1).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(3).
                      getT(1);
		auto& gain258 = this->getT(0).getT(1).getT(1).getT(6).getT(1).getT(0).getT(1);             // core::gain<NV>
		auto& chain440 = this->getT(0).getT(1).getT(1).getT(7);                                    // Filter_impl::chain440_t<NV>
		auto& xfader105 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                           // Filter_impl::xfader105_t<NV>
		auto& soft_bypass99 = this->getT(0).getT(1).getT(1).getT(7).getT(1);                       // Filter_impl::soft_bypass99_t<NV>
		auto& chain327 = this->getT(0).getT(1).getT(1).getT(7).getT(1).getT(0);                    // Filter_impl::chain327_t<NV>
		auto& branch64 = this->getT(0).getT(1).getT(1).getT(7).getT(1).getT(0).getT(0);            // Filter_impl::branch64_t<NV>
		auto& chain328 = this->getT(0).getT(1).getT(1).getT(7).                                    // Filter_impl::chain328_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& midi_cc67 = this->getT(0).getT(1).getT(1).getT(7).                                   // Filter_impl::midi_cc67_t<NV>
                          getT(1).getT(0).getT(0).getT(0).
                          getT(0);
		auto& add415 = this->getT(0).getT(1).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(0).
                       getT(1);
		auto& chain329 = this->getT(0).getT(1).getT(1).getT(7).                                    // Filter_impl::chain329_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& midi_cc68 = this->getT(0).getT(1).getT(1).getT(7).                                   // Filter_impl::midi_cc68_t<NV>
                          getT(1).getT(0).getT(0).getT(1).
                          getT(0);
		auto& add416 = this->getT(0).getT(1).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(1).
                       getT(1);
		auto& chain429 = this->getT(0).getT(1).getT(1).getT(7).                                    // Filter_impl::chain429_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& midi_cc69 = this->getT(0).getT(1).getT(1).getT(7).                                   // Filter_impl::midi_cc69_t<NV>
                          getT(1).getT(0).getT(0).getT(2).
                          getT(0);
		auto& add417 = this->getT(0).getT(1).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(2).
                       getT(1);
		auto& chain463 = this->getT(0).getT(1).getT(1).getT(7).                                    // Filter_impl::chain463_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& midi_cc70 = this->getT(0).getT(1).getT(1).getT(7).                                   // Filter_impl::midi_cc70_t<NV>
                          getT(1).getT(0).getT(0).getT(3).
                          getT(0);
		auto& add418 = this->getT(0).getT(1).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(3).
                       getT(1);
		auto& chain464 = this->getT(0).getT(1).getT(1).getT(7).                                    // Filter_impl::chain464_t<NV>
                         getT(1).getT(0).getT(0).getT(4);
		auto& midi51 = this->getT(0).getT(1).getT(1).getT(7).                                      // Filter_impl::midi51_t<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(0);
		auto& add419 = this->getT(0).getT(1).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(1);
		auto& chain465 = this->getT(0).getT(1).getT(1).getT(7).                                    // Filter_impl::chain465_t<NV>
                         getT(1).getT(0).getT(0).getT(5);
		auto& midi52 = this->getT(0).getT(1).getT(1).getT(7).                                      // Filter_impl::midi52_t<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(0);
		auto& add420 = this->getT(0).getT(1).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(1);
		auto& chain466 = this->getT(0).getT(1).getT(1).getT(7).                                    // Filter_impl::chain466_t<NV>
                         getT(1).getT(0).getT(0).getT(6);
		auto& midi53 = this->getT(0).getT(1).getT(1).getT(7).                                      // Filter_impl::midi53_t<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(0);
		auto& add421 = this->getT(0).getT(1).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(1);
		auto& gain259 = this->getT(0).getT(1).getT(1).getT(7).getT(1).getT(0).getT(1);             // core::gain<NV>
		auto& peak39 = this->getT(0).getT(1).getT(2);                                              // Filter_impl::peak39_t<NV>
		auto& pma23 = this->getT(0).getT(1).getT(3);                                               // Filter_impl::pma23_t<NV>
		auto& modchain22 = this->getT(0).getT(2);                                                  // Filter_impl::modchain22_t<NV>
		auto& sliderbank21 = this->getT(0).getT(2).getT(0);                                        // Filter_impl::sliderbank21_t<NV>
		auto& split38 = this->getT(0).getT(2).getT(1);                                             // Filter_impl::split38_t<NV>
		auto& chain447 = this->getT(0).getT(2).getT(1).getT(0);                                    // Filter_impl::chain447_t<NV>
		auto& xfader112 = this->getT(0).getT(2).getT(1).getT(0).getT(0);                           // Filter_impl::xfader112_t<NV>
		auto& soft_bypass106 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                      // Filter_impl::soft_bypass106_t<NV>
		auto& chain340 = this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0);                    // Filter_impl::chain340_t<NV>
		auto& global_cable75 = this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).getT(0);      // Filter_impl::global_cable75_t<NV>
		auto& add298 = this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain268 = this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain500 = this->getT(0).getT(2).getT(1).getT(1);                                    // Filter_impl::chain500_t<NV>
		auto& xfader127 = this->getT(0).getT(2).getT(1).getT(1).getT(0);                           // Filter_impl::xfader127_t<NV>
		auto& soft_bypass121 = this->getT(0).getT(2).getT(1).getT(1).getT(1);                      // Filter_impl::soft_bypass121_t<NV>
		auto& chain341 = this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0);                    // Filter_impl::chain341_t<NV>
		auto& global_cable76 = this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0).getT(0);      // Filter_impl::global_cable76_t<NV>
		auto& add299 = this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain269 = this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain499 = this->getT(0).getT(2).getT(1).getT(2);                                    // Filter_impl::chain499_t<NV>
		auto& xfader126 = this->getT(0).getT(2).getT(1).getT(2).getT(0);                           // Filter_impl::xfader126_t<NV>
		auto& soft_bypass120 = this->getT(0).getT(2).getT(1).getT(2).getT(1);                      // Filter_impl::soft_bypass120_t<NV>
		auto& chain342 = this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0);                    // Filter_impl::chain342_t<NV>
		auto& global_cable77 = this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0).getT(0);      // Filter_impl::global_cable77_t<NV>
		auto& add300 = this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain270 = this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain498 = this->getT(0).getT(2).getT(1).getT(3);                                    // Filter_impl::chain498_t<NV>
		auto& xfader125 = this->getT(0).getT(2).getT(1).getT(3).getT(0);                           // Filter_impl::xfader125_t
		auto& chain343 = this->getT(0).getT(2).getT(1).getT(3).getT(1);                            // Filter_impl::chain343_t<NV>
		auto& global_cable78 = this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(0);              // Filter_impl::global_cable78_t<NV>
		auto& add301 = this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(1);                      // math::add<NV>
		auto& gain271 = this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(2);                     // core::gain<NV>
		auto& soft_bypass119 = this->getT(0).getT(2).getT(1).getT(3).getT(2);                      // Filter_impl::soft_bypass119_t
		auto& chain497 = this->getT(0).getT(2).getT(1).getT(4);                                    // Filter_impl::chain497_t<NV>
		auto& xfader124 = this->getT(0).getT(2).getT(1).getT(4).getT(0);                           // Filter_impl::xfader124_t<NV>
		auto& soft_bypass118 = this->getT(0).getT(2).getT(1).getT(4).getT(1);                      // Filter_impl::soft_bypass118_t<NV>
		auto& chain344 = this->getT(0).getT(2).getT(1).getT(4).getT(1).getT(0);                    // Filter_impl::chain344_t<NV>
		auto& event_data_reader28 = this->getT(0).getT(2).getT(1).getT(4).getT(1).getT(0).getT(0); // Filter_impl::event_data_reader28_t<NV>
		auto& add302 = this->getT(0).getT(2).getT(1).getT(4).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain272 = this->getT(0).getT(2).getT(1).getT(4).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain496 = this->getT(0).getT(2).getT(1).getT(5);                                    // Filter_impl::chain496_t<NV>
		auto& xfader123 = this->getT(0).getT(2).getT(1).getT(5).getT(0);                           // Filter_impl::xfader123_t<NV>
		auto& soft_bypass117 = this->getT(0).getT(2).getT(1).getT(5).getT(1);                      // Filter_impl::soft_bypass117_t<NV>
		auto& chain345 = this->getT(0).getT(2).getT(1).getT(5).getT(1).getT(0);                    // Filter_impl::chain345_t<NV>
		auto& event_data_reader29 = this->getT(0).getT(2).getT(1).getT(5).getT(1).getT(0).getT(0); // Filter_impl::event_data_reader29_t<NV>
		auto& add303 = this->getT(0).getT(2).getT(1).getT(5).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain273 = this->getT(0).getT(2).getT(1).getT(5).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain495 = this->getT(0).getT(2).getT(1).getT(6);                                    // Filter_impl::chain495_t<NV>
		auto& xfader122 = this->getT(0).getT(2).getT(1).getT(6).getT(0);                           // Filter_impl::xfader122_t<NV>
		auto& soft_bypass116 = this->getT(0).getT(2).getT(1).getT(6).getT(1);                      // Filter_impl::soft_bypass116_t<NV>
		auto& chain346 = this->getT(0).getT(2).getT(1).getT(6).getT(1).getT(0);                    // Filter_impl::chain346_t<NV>
		auto& branch21 = this->getT(0).getT(2).getT(1).getT(6).getT(1).getT(0).getT(0);            // Filter_impl::branch21_t<NV>
		auto& chain388 = this->getT(0).getT(2).getT(1).getT(6).                                    // Filter_impl::chain388_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& event_data_reader24 = this->getT(0).getT(2).getT(1).getT(6).                         // Filter_impl::event_data_reader24_t<NV>
                                    getT(1).getT(0).getT(0).getT(0).
                                    getT(0);
		auto& add9 = this->getT(0).getT(2).getT(1).getT(6).                                        // math::add<NV>
                     getT(1).getT(0).getT(0).getT(0).
                     getT(1);
		auto& chain408 = this->getT(0).getT(2).getT(1).getT(6).                                    // Filter_impl::chain408_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& event_data_reader25 = this->getT(0).getT(2).getT(1).getT(6).                         // Filter_impl::event_data_reader25_t<NV>
                                    getT(1).getT(0).getT(0).getT(1).
                                    getT(0);
		auto& add29 = this->getT(0).getT(2).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1).
                      getT(1);
		auto& chain409 = this->getT(0).getT(2).getT(1).getT(6).                                    // Filter_impl::chain409_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& event_data_reader26 = this->getT(0).getT(2).getT(1).getT(6).                         // Filter_impl::event_data_reader26_t<NV>
                                    getT(1).getT(0).getT(0).getT(2).
                                    getT(0);
		auto& add30 = this->getT(0).getT(2).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain410 = this->getT(0).getT(2).getT(1).getT(6).                                    // Filter_impl::chain410_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& event_data_reader27 = this->getT(0).getT(2).getT(1).getT(6).                         // Filter_impl::event_data_reader27_t<NV>
                                    getT(1).getT(0).getT(0).getT(3).
                                    getT(0);
		auto& add31 = this->getT(0).getT(2).getT(1).getT(6).                                       // math::add<NV>
                      getT(1).getT(0).getT(0).getT(3).
                      getT(1);
		auto& add308 = this->getT(0).getT(2).getT(1).getT(6).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain274 = this->getT(0).getT(2).getT(1).getT(6).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain484 = this->getT(0).getT(2).getT(1).getT(7);                                    // Filter_impl::chain484_t<NV>
		auto& xfader121 = this->getT(0).getT(2).getT(1).getT(7).getT(0);                           // Filter_impl::xfader121_t<NV>
		auto& soft_bypass115 = this->getT(0).getT(2).getT(1).getT(7).getT(1);                      // Filter_impl::soft_bypass115_t<NV>
		auto& chain347 = this->getT(0).getT(2).getT(1).getT(7).getT(1).getT(0);                    // Filter_impl::chain347_t<NV>
		auto& branch68 = this->getT(0).getT(2).getT(1).getT(7).getT(1).getT(0).getT(0);            // Filter_impl::branch68_t<NV>
		auto& chain348 = this->getT(0).getT(2).getT(1).getT(7).                                    // Filter_impl::chain348_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& midi_cc75 = this->getT(0).getT(2).getT(1).getT(7).                                   // Filter_impl::midi_cc75_t<NV>
                          getT(1).getT(0).getT(0).getT(0).
                          getT(0);
		auto& add429 = this->getT(0).getT(2).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(0).
                       getT(1);
		auto& chain349 = this->getT(0).getT(2).getT(1).getT(7).                                    // Filter_impl::chain349_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& midi_cc76 = this->getT(0).getT(2).getT(1).getT(7).                                   // Filter_impl::midi_cc76_t<NV>
                          getT(1).getT(0).getT(0).getT(1).
                          getT(0);
		auto& add430 = this->getT(0).getT(2).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(1).
                       getT(1);
		auto& chain431 = this->getT(0).getT(2).getT(1).getT(7).                                    // Filter_impl::chain431_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& midi_cc77 = this->getT(0).getT(2).getT(1).getT(7).                                   // Filter_impl::midi_cc77_t<NV>
                          getT(1).getT(0).getT(0).getT(2).
                          getT(0);
		auto& add431 = this->getT(0).getT(2).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(2).
                       getT(1);
		auto& chain471 = this->getT(0).getT(2).getT(1).getT(7).                                    // Filter_impl::chain471_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& midi_cc78 = this->getT(0).getT(2).getT(1).getT(7).                                   // Filter_impl::midi_cc78_t<NV>
                          getT(1).getT(0).getT(0).getT(3).
                          getT(0);
		auto& add432 = this->getT(0).getT(2).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(3).
                       getT(1);
		auto& chain472 = this->getT(0).getT(2).getT(1).getT(7).                                    // Filter_impl::chain472_t<NV>
                         getT(1).getT(0).getT(0).getT(4);
		auto& midi57 = this->getT(0).getT(2).getT(1).getT(7).                                      // Filter_impl::midi57_t<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(0);
		auto& add433 = this->getT(0).getT(2).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(1);
		auto& chain473 = this->getT(0).getT(2).getT(1).getT(7).                                    // Filter_impl::chain473_t<NV>
                         getT(1).getT(0).getT(0).getT(5);
		auto& midi58 = this->getT(0).getT(2).getT(1).getT(7).                                      // Filter_impl::midi58_t<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(0);
		auto& add434 = this->getT(0).getT(2).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(1);
		auto& chain474 = this->getT(0).getT(2).getT(1).getT(7).                                    // Filter_impl::chain474_t<NV>
                         getT(1).getT(0).getT(0).getT(6);
		auto& midi59 = this->getT(0).getT(2).getT(1).getT(7).                                      // Filter_impl::midi59_t<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(0);
		auto& add435 = this->getT(0).getT(2).getT(1).getT(7).                                      // math::add<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(1);
		auto& gain275 = this->getT(0).getT(2).getT(1).getT(7).getT(1).getT(0).getT(1);             // core::gain<NV>
		auto& peak41 = this->getT(0).getT(2).getT(2);                                              // Filter_impl::peak41_t<NV>
		auto& pma25 = this->getT(0).getT(2).getT(3);                                               // Filter_impl::pma25_t<NV>
		auto& modchain23 = this->getT(0).getT(3);                                                  // Filter_impl::modchain23_t<NV>
		auto& sliderbank22 = this->getT(0).getT(3).getT(0);                                        // Filter_impl::sliderbank22_t<NV>
		auto& split39 = this->getT(0).getT(3).getT(1);                                             // Filter_impl::split39_t<NV>
		auto& chain483 = this->getT(0).getT(3).getT(1).getT(0);                                    // Filter_impl::chain483_t<NV>
		auto& xfader120 = this->getT(0).getT(3).getT(1).getT(0).getT(0);                           // Filter_impl::xfader120_t<NV>
		auto& soft_bypass114 = this->getT(0).getT(3).getT(1).getT(0).getT(1);                      // Filter_impl::soft_bypass114_t<NV>
		auto& chain350 = this->getT(0).getT(3).getT(1).getT(0).getT(1).getT(0);                    // Filter_impl::chain350_t<NV>
		auto& global_cable79 = this->getT(0).getT(3).getT(1).getT(0).getT(1).getT(0).getT(0);      // Filter_impl::global_cable79_t<NV>
		auto& add309 = this->getT(0).getT(3).getT(1).getT(0).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain276 = this->getT(0).getT(3).getT(1).getT(0).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain507 = this->getT(0).getT(3).getT(1).getT(1);                                    // Filter_impl::chain507_t<NV>
		auto& xfader134 = this->getT(0).getT(3).getT(1).getT(1).getT(0);                           // Filter_impl::xfader134_t<NV>
		auto& soft_bypass128 = this->getT(0).getT(3).getT(1).getT(1).getT(1);                      // Filter_impl::soft_bypass128_t<NV>
		auto& chain351 = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(0);                    // Filter_impl::chain351_t<NV>
		auto& global_cable80 = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(0).getT(0);      // Filter_impl::global_cable80_t<NV>
		auto& add310 = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain277 = this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain506 = this->getT(0).getT(3).getT(1).getT(2);                                    // Filter_impl::chain506_t<NV>
		auto& xfader133 = this->getT(0).getT(3).getT(1).getT(2).getT(0);                           // Filter_impl::xfader133_t<NV>
		auto& soft_bypass127 = this->getT(0).getT(3).getT(1).getT(2).getT(1);                      // Filter_impl::soft_bypass127_t<NV>
		auto& chain352 = this->getT(0).getT(3).getT(1).getT(2).getT(1).getT(0);                    // Filter_impl::chain352_t<NV>
		auto& global_cable81 = this->getT(0).getT(3).getT(1).getT(2).getT(1).getT(0).getT(0);      // Filter_impl::global_cable81_t<NV>
		auto& add311 = this->getT(0).getT(3).getT(1).getT(2).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain278 = this->getT(0).getT(3).getT(1).getT(2).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain505 = this->getT(0).getT(3).getT(1).getT(3);                                    // Filter_impl::chain505_t<NV>
		auto& xfader132 = this->getT(0).getT(3).getT(1).getT(3).getT(0);                           // Filter_impl::xfader132_t<NV>
		auto& soft_bypass126 = this->getT(0).getT(3).getT(1).getT(3).getT(1);                      // Filter_impl::soft_bypass126_t<NV>
		auto& chain353 = this->getT(0).getT(3).getT(1).getT(3).getT(1).getT(0);                    // Filter_impl::chain353_t<NV>
		auto& global_cable82 = this->getT(0).getT(3).getT(1).getT(3).getT(1).getT(0).getT(0);      // Filter_impl::global_cable82_t<NV>
		auto& add312 = this->getT(0).getT(3).getT(1).getT(3).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain279 = this->getT(0).getT(3).getT(1).getT(3).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain504 = this->getT(0).getT(3).getT(1).getT(4);                                    // Filter_impl::chain504_t<NV>
		auto& xfader131 = this->getT(0).getT(3).getT(1).getT(4).getT(0);                           // Filter_impl::xfader131_t<NV>
		auto& soft_bypass125 = this->getT(0).getT(3).getT(1).getT(4).getT(1);                      // Filter_impl::soft_bypass125_t<NV>
		auto& chain354 = this->getT(0).getT(3).getT(1).getT(4).getT(1).getT(0);                    // Filter_impl::chain354_t<NV>
		auto& event_data_reader34 = this->getT(0).getT(3).getT(1).getT(4).getT(1).getT(0).getT(0); // Filter_impl::event_data_reader34_t<NV>
		auto& add313 = this->getT(0).getT(3).getT(1).getT(4).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain280 = this->getT(0).getT(3).getT(1).getT(4).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain503 = this->getT(0).getT(3).getT(1).getT(5);                                    // Filter_impl::chain503_t<NV>
		auto& xfader130 = this->getT(0).getT(3).getT(1).getT(5).getT(0);                           // Filter_impl::xfader130_t<NV>
		auto& soft_bypass124 = this->getT(0).getT(3).getT(1).getT(5).getT(1);                      // Filter_impl::soft_bypass124_t<NV>
		auto& chain355 = this->getT(0).getT(3).getT(1).getT(5).getT(1).getT(0);                    // Filter_impl::chain355_t<NV>
		auto& event_data_reader35 = this->getT(0).getT(3).getT(1).getT(5).getT(1).getT(0).getT(0); // Filter_impl::event_data_reader35_t<NV>
		auto& add314 = this->getT(0).getT(3).getT(1).getT(5).getT(1).getT(0).getT(1);              // math::add<NV>
		auto& gain281 = this->getT(0).getT(3).getT(1).getT(5).getT(1).getT(0).getT(2);             // core::gain<NV>
		auto& chain502 = this->getT(0).getT(3).getT(1).getT(6);                                    // Filter_impl::chain502_t<NV>
		auto& xfader129 = this->getT(0).getT(3).getT(1).getT(6).getT(0);                           // Filter_impl::xfader129_t<NV>
		auto& soft_bypass123 = this->getT(0).getT(3).getT(1).getT(6).getT(1);                      // Filter_impl::soft_bypass123_t<NV>
		auto& chain356 = this->getT(0).getT(3).getT(1).getT(6).getT(1).getT(0);                    // Filter_impl::chain356_t<NV>
		auto& branch22 = this->getT(0).getT(3).getT(1).getT(6).getT(1).getT(0).getT(0);            // Filter_impl::branch22_t<NV>
		auto& chain389 = this->getT(0).getT(3).getT(1).getT(6).                                    // Filter_impl::chain389_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& event_data_reader30 = this->getT(0).getT(3).getT(1).getT(6).              // Filter_impl::event_data_reader30_t<NV>
                                    getT(1).getT(0).getT(0).getT(0).
                                    getT(0);
		auto& add10 = this->getT(0).getT(3).getT(1).getT(6).                            // math::add<NV>
                      getT(1).getT(0).getT(0).getT(0).
                      getT(1);
		auto& chain411 = this->getT(0).getT(3).getT(1).getT(6).                         // Filter_impl::chain411_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& event_data_reader31 = this->getT(0).getT(3).getT(1).getT(6).              // Filter_impl::event_data_reader31_t<NV>
                                    getT(1).getT(0).getT(0).getT(1).
                                    getT(0);
		auto& add32 = this->getT(0).getT(3).getT(1).getT(6).                            // math::add<NV>
                      getT(1).getT(0).getT(0).getT(1).
                      getT(1);
		auto& chain412 = this->getT(0).getT(3).getT(1).getT(6).                         // Filter_impl::chain412_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& event_data_reader32 = this->getT(0).getT(3).getT(1).getT(6).              // Filter_impl::event_data_reader32_t<NV>
                                    getT(1).getT(0).getT(0).getT(2).
                                    getT(0);
		auto& add33 = this->getT(0).getT(3).getT(1).getT(6).                            // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2).
                      getT(1);
		auto& chain413 = this->getT(0).getT(3).getT(1).getT(6).                         // Filter_impl::chain413_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& event_data_reader33 = this->getT(0).getT(3).getT(1).getT(6).              // Filter_impl::event_data_reader33_t<NV>
                                    getT(1).getT(0).getT(0).getT(3).
                                    getT(0);
		auto& add34 = this->getT(0).getT(3).getT(1).getT(6).                            // math::add<NV>
                      getT(1).getT(0).getT(0).getT(3).
                      getT(1);
		auto& gain282 = this->getT(0).getT(3).getT(1).getT(6).getT(1).getT(0).getT(1);  // core::gain<NV>
		auto& chain501 = this->getT(0).getT(3).getT(1).getT(7);                         // Filter_impl::chain501_t<NV>
		auto& xfader128 = this->getT(0).getT(3).getT(1).getT(7).getT(0);                // Filter_impl::xfader128_t<NV>
		auto& soft_bypass122 = this->getT(0).getT(3).getT(1).getT(7).getT(1);           // Filter_impl::soft_bypass122_t<NV>
		auto& chain357 = this->getT(0).getT(3).getT(1).getT(7).getT(1).getT(0);         // Filter_impl::chain357_t<NV>
		auto& branch70 = this->getT(0).getT(3).getT(1).getT(7).getT(1).getT(0).getT(0); // Filter_impl::branch70_t<NV>
		auto& chain358 = this->getT(0).getT(3).getT(1).getT(7).                         // Filter_impl::chain358_t<NV>
                         getT(1).getT(0).getT(0).getT(0);
		auto& midi_cc79 = this->getT(0).getT(3).getT(1).getT(7).                       // Filter_impl::midi_cc79_t<NV>
                          getT(1).getT(0).getT(0).getT(0).
                          getT(0);
		auto& add436 = this->getT(0).getT(3).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(0).
                       getT(1);
		auto& chain359 = this->getT(0).getT(3).getT(1).getT(7).                        // Filter_impl::chain359_t<NV>
                         getT(1).getT(0).getT(0).getT(1);
		auto& midi_cc80 = this->getT(0).getT(3).getT(1).getT(7).                       // Filter_impl::midi_cc80_t<NV>
                          getT(1).getT(0).getT(0).getT(1).
                          getT(0);
		auto& add437 = this->getT(0).getT(3).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(1).
                       getT(1);
		auto& chain432 = this->getT(0).getT(3).getT(1).getT(7).                        // Filter_impl::chain432_t<NV>
                         getT(1).getT(0).getT(0).getT(2);
		auto& midi_cc81 = this->getT(0).getT(3).getT(1).getT(7).                       // Filter_impl::midi_cc81_t<NV>
                          getT(1).getT(0).getT(0).getT(2).
                          getT(0);
		auto& add438 = this->getT(0).getT(3).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(2).
                       getT(1);
		auto& chain475 = this->getT(0).getT(3).getT(1).getT(7).                        // Filter_impl::chain475_t<NV>
                         getT(1).getT(0).getT(0).getT(3);
		auto& midi_cc82 = this->getT(0).getT(3).getT(1).getT(7).                       // Filter_impl::midi_cc82_t<NV>
                          getT(1).getT(0).getT(0).getT(3).
                          getT(0);
		auto& add439 = this->getT(0).getT(3).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(3).
                       getT(1);
		auto& chain476 = this->getT(0).getT(3).getT(1).getT(7).                        // Filter_impl::chain476_t<NV>
                         getT(1).getT(0).getT(0).getT(4);
		auto& midi60 = this->getT(0).getT(3).getT(1).getT(7).                          // Filter_impl::midi60_t<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(0);
		auto& add440 = this->getT(0).getT(3).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(4).
                       getT(1);
		auto& chain477 = this->getT(0).getT(3).getT(1).getT(7).                        // Filter_impl::chain477_t<NV>
                         getT(1).getT(0).getT(0).getT(5);
		auto& midi61 = this->getT(0).getT(3).getT(1).getT(7).                          // Filter_impl::midi61_t<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(0);
		auto& add441 = this->getT(0).getT(3).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(5).
                       getT(1);
		auto& chain478 = this->getT(0).getT(3).getT(1).getT(7).                        // Filter_impl::chain478_t<NV>
                         getT(1).getT(0).getT(0).getT(6);
		auto& midi62 = this->getT(0).getT(3).getT(1).getT(7).                          // Filter_impl::midi62_t<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(0);
		auto& add442 = this->getT(0).getT(3).getT(1).getT(7).                          // math::add<NV>
                       getT(1).getT(0).getT(0).getT(6).
                       getT(1);
		auto& gain283 = this->getT(0).getT(3).getT(1).getT(7).getT(1).getT(0).getT(1); // core::gain<NV>
		auto& peak42 = this->getT(0).getT(3).getT(2);                                  // Filter_impl::peak42_t<NV>
		auto& pma26 = this->getT(0).getT(3).getT(3);                                   // Filter_impl::pma26_t<NV>
		auto& chain59 = this->getT(1);                                                 // Filter_impl::chain59_t<NV>
		auto& xfade_2x_lin = this->getT(1).getT(0);                                    // Filter_impl::xfade_2x_lin_t<NV>
		auto& split20 = this->getT(1).getT(0).getT(0);                                 // Filter_impl::split20_t<NV>
		auto& chain58 = this->getT(1).getT(0).getT(0).getT(0);                         // Filter_impl::chain58_t<NV>
		auto& xfader = this->getT(1).getT(0).getT(0).getT(0).getT(0);                  // Filter_impl::xfader_t<NV>
		auto& split12 = this->getT(1).getT(0).getT(0).getT(0).getT(1);                 // Filter_impl::split12_t<NV>
		auto& chain14 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(0);         // Filter_impl::chain14_t<NV>
		auto& gain1 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);   // core::gain<NV>
		auto& chain57 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1);         // Filter_impl::chain57_t<NV>
		auto& chain15 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0); // Filter_impl::chain15_t<NV>
		auto& branch = this->getT(1).getT(0).getT(0).getT(0).                          // Filter_impl::branch_t<NV>
                       getT(1).getT(1).getT(0).getT(0);
		auto& chain16 = this->getT(1).getT(0).getT(0).getT(0).                       // Filter_impl::chain16_t<NV>
                        getT(1).getT(1).getT(0).getT(0).
                        getT(0);
		auto& faust = this->getT(1).getT(0).getT(0).getT(0).getT(1).                 // project::klp<NV>
                      getT(1).getT(0).getT(0).getT(0).getT(0);
		auto& chain35 = this->getT(1).getT(0).getT(0).getT(0).                       // Filter_impl::chain35_t<NV>
                        getT(1).getT(1).getT(0).getT(0).
                        getT(1);
		auto& faust1 = this->getT(1).getT(0).getT(0).getT(0).getT(1).                // project::khp2<NV>
                       getT(1).getT(0).getT(0).getT(1).getT(0);
		auto& chain36 = this->getT(1).getT(0).getT(0).getT(0).                       // Filter_impl::chain36_t<NV>
                        getT(1).getT(1).getT(0).getT(0).
                        getT(2);
		auto& cable_table = this->getT(1).getT(0).getT(0).getT(0).getT(1).           // Filter_impl::cable_table_t<NV>
                            getT(1).getT(0).getT(0).getT(2).getT(0);
		auto& faust8 = this->getT(1).getT(0).getT(0).getT(0).getT(1).                // project::Comb<NV>
                       getT(1).getT(0).getT(0).getT(2).getT(1);
		auto& send7 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1); // routing::send<stereo_cable>
		auto& gain2 = this->getT(1).getT(0).getT(0).getT(0).getT(1).getT(1).getT(2); // core::gain<NV>
		auto& gain77 = this->getT(2);                                                // core::gain<NV>
		auto& oscilloscope = this->getT(3);                                          // Filter_impl::oscilloscope_t
		auto& jpanner3 = this->getT(4);                                              // jdsp::jpanner<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		auto& Q_p = this->getParameterT(0);
		Q_p.connectT(0, faust8); // Q -> faust8::aN
		Q_p.connectT(1, faust);  // Q -> faust::Q
		Q_p.connectT(2, faust1); // Q -> faust1::freq
		
		this->getParameterT(1).connectT(0, pma22); // FilterMix -> pma22::Add
		
		this->getParameterT(2).connectT(0, pma22); // FilterMod -> pma22::Multiply
		
		this->getParameterT(3).connectT(0, pma23); // Cut1 -> pma23::Add
		
		this->getParameterT(4).connectT(0, pma23); // Cut1Mod -> pma23::Multiply
		
		this->getParameterT(5).connectT(0, branch62); // FilterMidiMix -> branch62::Index
		
		this->getParameterT(6).connectT(0, branch64); // FilterMidiCut1 -> branch64::Index
		
		this->getParameterT(7).connectT(0, branch); // FilterMode -> branch::Index
		
		this->getParameterT(11).connectT(0, pma25); // Gain -> pma25::Add
		
		this->getParameterT(12).connectT(0, pma25); // GainMod -> pma25::Multiply
		
		this->getParameterT(13).connectT(0, pma26); // PAn -> pma26::Add
		
		this->getParameterT(14).connectT(0, pma26); // PanMod -> pma26::Multiply
		
		this->getParameterT(15).connectT(0, branch20); // CutPK -> branch20::Index
		
		this->getParameterT(16).connectT(0, branch68); // GainMidi -> branch68::Index
		
		this->getParameterT(17).connectT(0, branch21); // GainPk -> branch21::Index
		
		this->getParameterT(18).connectT(0, branch70); // PanMidi -> branch70::Index
		
		this->getParameterT(19).connectT(0, branch22); // PanPk -> branch22::Index
		
		this->getParameterT(20).connectT(0, branch19); // FilterMixPk -> branch19::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable63.getWrappedObject().getParameter().connectT(0, add265); // global_cable63 -> add265::Value
		auto& xfader88_p = xfader88.getWrappedObject().getParameter();
		xfader88_p.getParameterT(1).connectT(0, soft_bypass82);               // xfader88 -> soft_bypass82::Bypassed
		global_cable64.getWrappedObject().getParameter().connectT(0, add266); // global_cable64 -> add266::Value
		auto& xfader103_p = xfader103.getWrappedObject().getParameter();
		xfader103_p.getParameterT(1).connectT(0, soft_bypass97);              // xfader103 -> soft_bypass97::Bypassed
		global_cable65.getWrappedObject().getParameter().connectT(0, add267); // global_cable65 -> add267::Value
		auto& xfader102_p = xfader102.getWrappedObject().getParameter();
		xfader102_p.getParameterT(1).connectT(0, soft_bypass96); // xfader102 -> soft_bypass96::Bypassed
		event_data_reader16.getParameter().connectT(0, add269);  // event_data_reader16 -> add269::Value
		auto& xfader100_p = xfader100.getWrappedObject().getParameter();
		xfader100_p.getParameterT(1).connectT(0, soft_bypass94);              // xfader100 -> soft_bypass94::Bypassed
		global_cable66.getWrappedObject().getParameter().connectT(0, add268); // global_cable66 -> add268::Value
		auto& xfader101_p = xfader101.getWrappedObject().getParameter();
		xfader101_p.getParameterT(1).connectT(0, soft_bypass95); // xfader101 -> soft_bypass95::Bypassed
		event_data_reader17.getParameter().connectT(0, add270);  // event_data_reader17 -> add270::Value
		auto& xfader99_p = xfader99.getWrappedObject().getParameter();
		xfader99_p.getParameterT(1).connectT(0, soft_bypass93); // xfader99 -> soft_bypass93::Bypassed
		auto& xfader98_p = xfader98.getWrappedObject().getParameter();
		xfader98_p.getParameterT(1).connectT(0, soft_bypass92);          // xfader98 -> soft_bypass92::Bypassed
		midi_cc63.getWrappedObject().getParameter().connectT(0, add408); // midi_cc63 -> add408::Value
		midi_cc64.getWrappedObject().getParameter().connectT(0, add409); // midi_cc64 -> add409::Value
		midi_cc65.getWrappedObject().getParameter().connectT(0, add410); // midi_cc65 -> add410::Value
		midi_cc66.getWrappedObject().getParameter().connectT(0, add411); // midi_cc66 -> add411::Value
		midi48.getParameter().connectT(0, add412);                       // midi48 -> add412::Value
		midi49.getParameter().connectT(0, add413);                       // midi49 -> add413::Value
		midi50.getParameter().connectT(0, add414);                       // midi50 -> add414::Value
		auto& xfader97_p = xfader97.getWrappedObject().getParameter();
		xfader97_p.getParameterT(1).connectT(0, soft_bypass91); // xfader97 -> soft_bypass91::Bypassed
		auto& sliderbank18_p = sliderbank18.getWrappedObject().getParameter();
		sliderbank18_p.getParameterT(0).connectT(0, gain244);   // sliderbank18 -> gain244::Gain
		sliderbank18_p.getParameterT(0).connectT(1, xfader88);  // sliderbank18 -> xfader88::Value
		sliderbank18_p.getParameterT(1).connectT(0, gain245);   // sliderbank18 -> gain245::Gain
		sliderbank18_p.getParameterT(1).connectT(1, xfader103); // sliderbank18 -> xfader103::Value
		sliderbank18_p.getParameterT(2).connectT(0, gain246);   // sliderbank18 -> gain246::Gain
		sliderbank18_p.getParameterT(2).connectT(1, xfader102); // sliderbank18 -> xfader102::Value
		sliderbank18_p.getParameterT(3).connectT(0, gain247);   // sliderbank18 -> gain247::Gain
		sliderbank18_p.getParameterT(4).connectT(0, gain248);   // sliderbank18 -> gain248::Gain
		sliderbank18_p.getParameterT(4).connectT(1, xfader100); // sliderbank18 -> xfader100::Value
		sliderbank18_p.getParameterT(4).connectT(2, xfader101); // sliderbank18 -> xfader101::Value
		sliderbank18_p.getParameterT(5).connectT(0, gain249);   // sliderbank18 -> gain249::Gain
		sliderbank18_p.getParameterT(5).connectT(1, xfader99);  // sliderbank18 -> xfader99::Value
		sliderbank18_p.getParameterT(6).connectT(0, gain250);   // sliderbank18 -> gain250::Gain
		sliderbank18_p.getParameterT(6).connectT(1, xfader98);  // sliderbank18 -> xfader98::Value
		sliderbank18_p.getParameterT(7).connectT(0, gain251);   // sliderbank18 -> gain251::Gain
		sliderbank18_p.getParameterT(7).connectT(1, xfader97);  // sliderbank18 -> xfader97::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                         // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                         // xfader -> gain2::Gain
		pma22.getWrappedObject().getParameter().connectT(0, xfader);          // pma22 -> xfader::Value
		peak38.getParameter().connectT(0, pma22);                             // peak38 -> pma22::Value
		global_cable67.getWrappedObject().getParameter().connectT(0, add276); // global_cable67 -> add276::Value
		auto& xfader96_p = xfader96.getWrappedObject().getParameter();
		xfader96_p.getParameterT(1).connectT(0, soft_bypass90);               // xfader96 -> soft_bypass90::Bypassed
		global_cable68.getWrappedObject().getParameter().connectT(0, add277); // global_cable68 -> add277::Value
		auto& xfader111_p = xfader111.getWrappedObject().getParameter();
		xfader111_p.getParameterT(1).connectT(0, soft_bypass105);             // xfader111 -> soft_bypass105::Bypassed
		global_cable69.getWrappedObject().getParameter().connectT(0, add278); // global_cable69 -> add278::Value
		auto& xfader110_p = xfader110.getWrappedObject().getParameter();
		xfader110_p.getParameterT(1).connectT(0, soft_bypass104);             // xfader110 -> soft_bypass104::Bypassed
		global_cable70.getWrappedObject().getParameter().connectT(0, add279); // global_cable70 -> add279::Value
		auto& xfader109_p = xfader109.getWrappedObject().getParameter();
		xfader109_p.getParameterT(1).connectT(0, soft_bypass103); // xfader109 -> soft_bypass103::Bypassed
		event_data_reader22.getParameter().connectT(0, add280);   // event_data_reader22 -> add280::Value
		auto& xfader108_p = xfader108.getWrappedObject().getParameter();
		xfader108_p.getParameterT(1).connectT(0, soft_bypass102); // xfader108 -> soft_bypass102::Bypassed
		event_data_reader23.getParameter().connectT(0, add281);   // event_data_reader23 -> add281::Value
		auto& xfader107_p = xfader107.getWrappedObject().getParameter();
		xfader107_p.getParameterT(1).connectT(0, soft_bypass101); // xfader107 -> soft_bypass101::Bypassed
		event_data_reader18.getParameter().connectT(0, add8);     // event_data_reader18 -> add8::Value
		event_data_reader19.getParameter().connectT(0, add26);    // event_data_reader19 -> add26::Value
		event_data_reader20.getParameter().connectT(0, add27);    // event_data_reader20 -> add27::Value
		event_data_reader21.getParameter().connectT(0, add28);    // event_data_reader21 -> add28::Value
		auto& xfader106_p = xfader106.getWrappedObject().getParameter();
		xfader106_p.getParameterT(1).connectT(0, soft_bypass100);        // xfader106 -> soft_bypass100::Bypassed
		midi_cc67.getWrappedObject().getParameter().connectT(0, add415); // midi_cc67 -> add415::Value
		midi_cc68.getWrappedObject().getParameter().connectT(0, add416); // midi_cc68 -> add416::Value
		midi_cc69.getWrappedObject().getParameter().connectT(0, add417); // midi_cc69 -> add417::Value
		midi_cc70.getWrappedObject().getParameter().connectT(0, add418); // midi_cc70 -> add418::Value
		midi51.getParameter().connectT(0, add419);                       // midi51 -> add419::Value
		midi52.getParameter().connectT(0, add420);                       // midi52 -> add420::Value
		midi53.getParameter().connectT(0, add421);                       // midi53 -> add421::Value
		auto& xfader105_p = xfader105.getWrappedObject().getParameter();
		xfader105_p.getParameterT(1).connectT(0, soft_bypass99); // xfader105 -> soft_bypass99::Bypassed
		auto& sliderbank19_p = sliderbank19.getWrappedObject().getParameter();
		sliderbank19_p.getParameterT(0).connectT(0, gain252);                 // sliderbank19 -> gain252::Gain
		sliderbank19_p.getParameterT(0).connectT(1, xfader96);                // sliderbank19 -> xfader96::Value
		sliderbank19_p.getParameterT(1).connectT(0, gain253);                 // sliderbank19 -> gain253::Gain
		sliderbank19_p.getParameterT(1).connectT(1, xfader111);               // sliderbank19 -> xfader111::Value
		sliderbank19_p.getParameterT(2).connectT(0, gain254);                 // sliderbank19 -> gain254::Gain
		sliderbank19_p.getParameterT(2).connectT(1, xfader110);               // sliderbank19 -> xfader110::Value
		sliderbank19_p.getParameterT(3).connectT(0, gain255);                 // sliderbank19 -> gain255::Gain
		sliderbank19_p.getParameterT(3).connectT(1, xfader109);               // sliderbank19 -> xfader109::Value
		sliderbank19_p.getParameterT(4).connectT(0, gain256);                 // sliderbank19 -> gain256::Gain
		sliderbank19_p.getParameterT(4).connectT(1, xfader108);               // sliderbank19 -> xfader108::Value
		sliderbank19_p.getParameterT(5).connectT(0, gain257);                 // sliderbank19 -> gain257::Gain
		sliderbank19_p.getParameterT(5).connectT(1, xfader107);               // sliderbank19 -> xfader107::Value
		sliderbank19_p.getParameterT(6).connectT(0, gain258);                 // sliderbank19 -> gain258::Gain
		sliderbank19_p.getParameterT(6).connectT(1, xfader106);               // sliderbank19 -> xfader106::Value
		sliderbank19_p.getParameterT(7).connectT(0, gain259);                 // sliderbank19 -> gain259::Gain
		sliderbank19_p.getParameterT(7).connectT(1, xfader105);               // sliderbank19 -> xfader105::Value
		cable_table.getWrappedObject().getParameter().connectT(0, faust8);    // cable_table -> faust8::del
		pma23.getWrappedObject().getParameter().connectT(0, faust);           // pma23 -> faust::freq
		pma23.getWrappedObject().getParameter().connectT(1, cable_table);     // pma23 -> cable_table::Value
		pma23.getWrappedObject().getParameter().connectT(2, faust1);          // pma23 -> faust1::Q
		peak39.getParameter().connectT(0, pma23);                             // peak39 -> pma23::Value
		global_cable75.getWrappedObject().getParameter().connectT(0, add298); // global_cable75 -> add298::Value
		auto& xfader112_p = xfader112.getWrappedObject().getParameter();
		xfader112_p.getParameterT(1).connectT(0, soft_bypass106);             // xfader112 -> soft_bypass106::Bypassed
		global_cable76.getWrappedObject().getParameter().connectT(0, add299); // global_cable76 -> add299::Value
		auto& xfader127_p = xfader127.getWrappedObject().getParameter();
		xfader127_p.getParameterT(1).connectT(0, soft_bypass121);             // xfader127 -> soft_bypass121::Bypassed
		global_cable77.getWrappedObject().getParameter().connectT(0, add300); // global_cable77 -> add300::Value
		auto& xfader126_p = xfader126.getWrappedObject().getParameter();
		xfader126_p.getParameterT(1).connectT(0, soft_bypass120); // xfader126 -> soft_bypass120::Bypassed
		auto& xfader125_p = xfader125.getWrappedObject().getParameter();
		xfader125_p.getParameterT(1).connectT(0, soft_bypass119); // xfader125 -> soft_bypass119::Bypassed
		event_data_reader28.getParameter().connectT(0, add302);   // event_data_reader28 -> add302::Value
		auto& xfader124_p = xfader124.getWrappedObject().getParameter();
		xfader124_p.getParameterT(1).connectT(0, soft_bypass118); // xfader124 -> soft_bypass118::Bypassed
		event_data_reader29.getParameter().connectT(0, add303);   // event_data_reader29 -> add303::Value
		auto& xfader123_p = xfader123.getWrappedObject().getParameter();
		xfader123_p.getParameterT(1).connectT(0, soft_bypass117); // xfader123 -> soft_bypass117::Bypassed
		event_data_reader24.getParameter().connectT(0, add9);     // event_data_reader24 -> add9::Value
		event_data_reader25.getParameter().connectT(0, add29);    // event_data_reader25 -> add29::Value
		event_data_reader26.getParameter().connectT(0, add30);    // event_data_reader26 -> add30::Value
		event_data_reader27.getParameter().connectT(0, add31);    // event_data_reader27 -> add31::Value
		auto& xfader122_p = xfader122.getWrappedObject().getParameter();
		xfader122_p.getParameterT(1).connectT(0, soft_bypass116);        // xfader122 -> soft_bypass116::Bypassed
		midi_cc75.getWrappedObject().getParameter().connectT(0, add429); // midi_cc75 -> add429::Value
		midi_cc76.getWrappedObject().getParameter().connectT(0, add430); // midi_cc76 -> add430::Value
		midi_cc77.getWrappedObject().getParameter().connectT(0, add431); // midi_cc77 -> add431::Value
		midi_cc78.getWrappedObject().getParameter().connectT(0, add432); // midi_cc78 -> add432::Value
		midi57.getParameter().connectT(0, add433);                       // midi57 -> add433::Value
		midi58.getParameter().connectT(0, add434);                       // midi58 -> add434::Value
		midi59.getParameter().connectT(0, add435);                       // midi59 -> add435::Value
		auto& xfader121_p = xfader121.getWrappedObject().getParameter();
		xfader121_p.getParameterT(1).connectT(0, soft_bypass115); // xfader121 -> soft_bypass115::Bypassed
		auto& sliderbank21_p = sliderbank21.getWrappedObject().getParameter();
		sliderbank21_p.getParameterT(0).connectT(0, gain268);                 // sliderbank21 -> gain268::Gain
		sliderbank21_p.getParameterT(0).connectT(1, xfader112);               // sliderbank21 -> xfader112::Value
		sliderbank21_p.getParameterT(1).connectT(0, gain269);                 // sliderbank21 -> gain269::Gain
		sliderbank21_p.getParameterT(1).connectT(1, xfader127);               // sliderbank21 -> xfader127::Value
		sliderbank21_p.getParameterT(2).connectT(0, gain270);                 // sliderbank21 -> gain270::Gain
		sliderbank21_p.getParameterT(2).connectT(1, xfader126);               // sliderbank21 -> xfader126::Value
		sliderbank21_p.getParameterT(3).connectT(0, gain271);                 // sliderbank21 -> gain271::Gain
		sliderbank21_p.getParameterT(3).connectT(1, xfader125);               // sliderbank21 -> xfader125::Value
		sliderbank21_p.getParameterT(4).connectT(0, gain272);                 // sliderbank21 -> gain272::Gain
		sliderbank21_p.getParameterT(4).connectT(1, xfader124);               // sliderbank21 -> xfader124::Value
		sliderbank21_p.getParameterT(5).connectT(0, gain273);                 // sliderbank21 -> gain273::Gain
		sliderbank21_p.getParameterT(5).connectT(1, xfader123);               // sliderbank21 -> xfader123::Value
		sliderbank21_p.getParameterT(6).connectT(0, gain274);                 // sliderbank21 -> gain274::Gain
		sliderbank21_p.getParameterT(6).connectT(1, xfader122);               // sliderbank21 -> xfader122::Value
		sliderbank21_p.getParameterT(7).connectT(0, gain275);                 // sliderbank21 -> gain275::Gain
		sliderbank21_p.getParameterT(7).connectT(1, xfader121);               // sliderbank21 -> xfader121::Value
		global_cable78.getWrappedObject().getParameter().connectT(0, add301); // global_cable78 -> add301::Value
		pma25.getWrappedObject().getParameter().connectT(0, gain77);          // pma25 -> gain77::Gain
		peak41.getParameter().connectT(0, pma25);                             // peak41 -> pma25::Value
		global_cable79.getWrappedObject().getParameter().connectT(0, add309); // global_cable79 -> add309::Value
		auto& xfader120_p = xfader120.getWrappedObject().getParameter();
		xfader120_p.getParameterT(1).connectT(0, soft_bypass114);             // xfader120 -> soft_bypass114::Bypassed
		global_cable80.getWrappedObject().getParameter().connectT(0, add310); // global_cable80 -> add310::Value
		auto& xfader134_p = xfader134.getWrappedObject().getParameter();
		xfader134_p.getParameterT(1).connectT(0, soft_bypass128);             // xfader134 -> soft_bypass128::Bypassed
		global_cable81.getWrappedObject().getParameter().connectT(0, add311); // global_cable81 -> add311::Value
		auto& xfader133_p = xfader133.getWrappedObject().getParameter();
		xfader133_p.getParameterT(1).connectT(0, soft_bypass127);             // xfader133 -> soft_bypass127::Bypassed
		global_cable82.getWrappedObject().getParameter().connectT(0, add312); // global_cable82 -> add312::Value
		auto& xfader132_p = xfader132.getWrappedObject().getParameter();
		xfader132_p.getParameterT(1).connectT(0, soft_bypass126); // xfader132 -> soft_bypass126::Bypassed
		event_data_reader34.getParameter().connectT(0, add313);   // event_data_reader34 -> add313::Value
		auto& xfader131_p = xfader131.getWrappedObject().getParameter();
		xfader131_p.getParameterT(1).connectT(0, soft_bypass125); // xfader131 -> soft_bypass125::Bypassed
		event_data_reader35.getParameter().connectT(0, add314);   // event_data_reader35 -> add314::Value
		auto& xfader130_p = xfader130.getWrappedObject().getParameter();
		xfader130_p.getParameterT(1).connectT(0, soft_bypass124); // xfader130 -> soft_bypass124::Bypassed
		event_data_reader30.getParameter().connectT(0, add10);    // event_data_reader30 -> add10::Value
		event_data_reader31.getParameter().connectT(0, add32);    // event_data_reader31 -> add32::Value
		event_data_reader32.getParameter().connectT(0, add33);    // event_data_reader32 -> add33::Value
		event_data_reader33.getParameter().connectT(0, add34);    // event_data_reader33 -> add34::Value
		auto& xfader129_p = xfader129.getWrappedObject().getParameter();
		xfader129_p.getParameterT(1).connectT(0, soft_bypass123);        // xfader129 -> soft_bypass123::Bypassed
		midi_cc79.getWrappedObject().getParameter().connectT(0, add436); // midi_cc79 -> add436::Value
		midi_cc80.getWrappedObject().getParameter().connectT(0, add437); // midi_cc80 -> add437::Value
		midi_cc81.getWrappedObject().getParameter().connectT(0, add438); // midi_cc81 -> add438::Value
		midi_cc82.getWrappedObject().getParameter().connectT(0, add439); // midi_cc82 -> add439::Value
		midi60.getParameter().connectT(0, add440);                       // midi60 -> add440::Value
		midi61.getParameter().connectT(0, add441);                       // midi61 -> add441::Value
		midi62.getParameter().connectT(0, add442);                       // midi62 -> add442::Value
		auto& xfader128_p = xfader128.getWrappedObject().getParameter();
		xfader128_p.getParameterT(1).connectT(0, soft_bypass122); // xfader128 -> soft_bypass122::Bypassed
		auto& sliderbank22_p = sliderbank22.getWrappedObject().getParameter();
		sliderbank22_p.getParameterT(0).connectT(0, gain276);          // sliderbank22 -> gain276::Gain
		sliderbank22_p.getParameterT(0).connectT(1, xfader120);        // sliderbank22 -> xfader120::Value
		sliderbank22_p.getParameterT(1).connectT(0, gain277);          // sliderbank22 -> gain277::Gain
		sliderbank22_p.getParameterT(1).connectT(1, xfader134);        // sliderbank22 -> xfader134::Value
		sliderbank22_p.getParameterT(2).connectT(0, gain278);          // sliderbank22 -> gain278::Gain
		sliderbank22_p.getParameterT(2).connectT(1, xfader133);        // sliderbank22 -> xfader133::Value
		sliderbank22_p.getParameterT(3).connectT(0, gain279);          // sliderbank22 -> gain279::Gain
		sliderbank22_p.getParameterT(3).connectT(1, xfader132);        // sliderbank22 -> xfader132::Value
		sliderbank22_p.getParameterT(4).connectT(0, gain280);          // sliderbank22 -> gain280::Gain
		sliderbank22_p.getParameterT(4).connectT(1, xfader131);        // sliderbank22 -> xfader131::Value
		sliderbank22_p.getParameterT(5).connectT(0, gain281);          // sliderbank22 -> gain281::Gain
		sliderbank22_p.getParameterT(5).connectT(1, xfader130);        // sliderbank22 -> xfader130::Value
		sliderbank22_p.getParameterT(6).connectT(0, gain282);          // sliderbank22 -> gain282::Gain
		sliderbank22_p.getParameterT(6).connectT(1, xfader129);        // sliderbank22 -> xfader129::Value
		sliderbank22_p.getParameterT(7).connectT(0, gain283);          // sliderbank22 -> gain283::Gain
		sliderbank22_p.getParameterT(7).connectT(1, xfader128);        // sliderbank22 -> xfader128::Value
		pma26.getWrappedObject().getParameter().connectT(0, jpanner3); // pma26 -> jpanner3::Pan
		peak42.getParameter().connectT(0, pma26);                      // peak42 -> pma26::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank18.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // xfader88::Value is automated
		
		global_cable63.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add265::Value is automated
		
		;                              // gain244::Gain is automated
		gain244.setParameterT(1, 20.); // core::gain::Smoothing
		gain244.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader103::Value is automated
		
		global_cable64.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add266::Value is automated
		
		;                              // gain245::Gain is automated
		gain245.setParameterT(1, 20.); // core::gain::Smoothing
		gain245.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader102::Value is automated
		
		global_cable65.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add267::Value is automated
		
		;                              // gain246::Gain is automated
		gain246.setParameterT(1, 20.); // core::gain::Smoothing
		gain246.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader101::Value is automated
		
		global_cable66.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add268::Value is automated
		
		;                              // gain247::Gain is automated
		gain247.setParameterT(1, 20.); // core::gain::Smoothing
		gain247.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader100::Value is automated
		
		event_data_reader16.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add269::Value is automated
		
		;                              // gain248::Gain is automated
		gain248.setParameterT(1, 20.); // core::gain::Smoothing
		gain248.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader99::Value is automated
		
		event_data_reader17.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add270::Value is automated
		
		;                              // gain249::Gain is automated
		gain249.setParameterT(1, 20.); // core::gain::Smoothing
		gain249.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader98::Value is automated
		
		; // branch19::Index is automated
		
		event_data_reader12.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add7.setParameterT(0, 0.); // math::add::Value
		
		event_data_reader13.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add23.setParameterT(0, 0.); // math::add::Value
		
		event_data_reader14.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add24.setParameterT(0, 0.); // math::add::Value
		
		event_data_reader15.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add25.setParameterT(0, 0.); // math::add::Value
		
		add275.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain250::Gain is automated
		gain250.setParameterT(1, 20.); // core::gain::Smoothing
		gain250.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader97::Value is automated
		
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
		
		; // xfader96::Value is automated
		
		global_cable67.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add276::Value is automated
		
		;                              // gain252::Gain is automated
		gain252.setParameterT(1, 20.); // core::gain::Smoothing
		gain252.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader111::Value is automated
		
		global_cable68.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add277::Value is automated
		
		;                              // gain253::Gain is automated
		gain253.setParameterT(1, 20.); // core::gain::Smoothing
		gain253.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader110::Value is automated
		
		global_cable69.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add278::Value is automated
		
		;                              // gain254::Gain is automated
		gain254.setParameterT(1, 20.); // core::gain::Smoothing
		gain254.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader109::Value is automated
		
		global_cable70.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add279::Value is automated
		
		;                              // gain255::Gain is automated
		gain255.setParameterT(1, 20.); // core::gain::Smoothing
		gain255.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader108::Value is automated
		
		event_data_reader22.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader22.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add280::Value is automated
		
		;                              // gain256::Gain is automated
		gain256.setParameterT(1, 20.); // core::gain::Smoothing
		gain256.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader107::Value is automated
		
		event_data_reader23.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader23.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add281::Value is automated
		
		;                              // gain257::Gain is automated
		gain257.setParameterT(1, 20.); // core::gain::Smoothing
		gain257.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader106::Value is automated
		
		; // branch20::Index is automated
		
		event_data_reader18.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader18.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add8::Value is automated
		
		event_data_reader19.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader19.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add26::Value is automated
		
		event_data_reader20.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader20.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add27::Value is automated
		
		event_data_reader21.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader21.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add28::Value is automated
		
		;                              // gain258::Gain is automated
		gain258.setParameterT(1, 20.); // core::gain::Smoothing
		gain258.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader105::Value is automated
		
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
		
		sliderbank21.setParameterT(0, 1.); // control::sliderbank::Value
		
		; // xfader112::Value is automated
		
		global_cable75.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add298::Value is automated
		
		;                              // gain268::Gain is automated
		gain268.setParameterT(1, 20.); // core::gain::Smoothing
		gain268.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader127::Value is automated
		
		global_cable76.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add299::Value is automated
		
		;                              // gain269::Gain is automated
		gain269.setParameterT(1, 20.); // core::gain::Smoothing
		gain269.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader126::Value is automated
		
		global_cable77.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add300::Value is automated
		
		;                              // gain270::Gain is automated
		gain270.setParameterT(1, 20.); // core::gain::Smoothing
		gain270.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader125::Value is automated
		
		global_cable78.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add301::Value is automated
		
		;                              // gain271::Gain is automated
		gain271.setParameterT(1, 20.); // core::gain::Smoothing
		gain271.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader124::Value is automated
		
		event_data_reader28.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader28.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add302::Value is automated
		
		;                              // gain272::Gain is automated
		gain272.setParameterT(1, 20.); // core::gain::Smoothing
		gain272.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader123::Value is automated
		
		event_data_reader29.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader29.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add303::Value is automated
		
		;                              // gain273::Gain is automated
		gain273.setParameterT(1, 20.); // core::gain::Smoothing
		gain273.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader122::Value is automated
		
		; // branch21::Index is automated
		
		event_data_reader24.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader24.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add9::Value is automated
		
		event_data_reader25.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader25.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add29::Value is automated
		
		event_data_reader26.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader26.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add30::Value is automated
		
		event_data_reader27.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader27.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add31::Value is automated
		
		add308.setParameterT(0, 0.); // math::add::Value
		
		;                              // gain274::Gain is automated
		gain274.setParameterT(1, 20.); // core::gain::Smoothing
		gain274.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader121::Value is automated
		
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
		
		; // xfader120::Value is automated
		
		global_cable79.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add309::Value is automated
		
		;                              // gain276::Gain is automated
		gain276.setParameterT(1, 20.); // core::gain::Smoothing
		gain276.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader134::Value is automated
		
		global_cable80.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add310::Value is automated
		
		;                              // gain277::Gain is automated
		gain277.setParameterT(1, 20.); // core::gain::Smoothing
		gain277.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader133::Value is automated
		
		global_cable81.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add311::Value is automated
		
		;                              // gain278::Gain is automated
		gain278.setParameterT(1, 20.); // core::gain::Smoothing
		gain278.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader132::Value is automated
		
		global_cable82.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add312::Value is automated
		
		;                              // gain279::Gain is automated
		gain279.setParameterT(1, 20.); // core::gain::Smoothing
		gain279.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader131::Value is automated
		
		event_data_reader34.setParameterT(0, 4.); // routing::event_data_reader::SlotIndex
		event_data_reader34.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add313::Value is automated
		
		;                              // gain280::Gain is automated
		gain280.setParameterT(1, 20.); // core::gain::Smoothing
		gain280.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader130::Value is automated
		
		event_data_reader35.setParameterT(0, 5.); // routing::event_data_reader::SlotIndex
		event_data_reader35.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add314::Value is automated
		
		;                              // gain281::Gain is automated
		gain281.setParameterT(1, 20.); // core::gain::Smoothing
		gain281.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader129::Value is automated
		
		; // branch22::Index is automated
		
		event_data_reader30.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader30.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add10::Value is automated
		
		event_data_reader31.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader31.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add32::Value is automated
		
		event_data_reader32.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader32.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add33::Value is automated
		
		event_data_reader33.setParameterT(0, 3.); // routing::event_data_reader::SlotIndex
		event_data_reader33.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add34::Value is automated
		
		;                              // gain282::Gain is automated
		gain282.setParameterT(1, 20.); // core::gain::Smoothing
		gain282.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader128::Value is automated
		
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
		
		; // xfader::Value is automated
		
		;                             // gain1::Gain is automated
		gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		gain1.setParameterT(2, -12.); // core::gain::ResetValue
		
		; // branch::Index is automated
		
		; // faust::Q is automated
		; // faust::freq is automated
		
		; // faust1::Q is automated
		; // faust1::freq is automated
		
		; // cable_table::Value is automated
		
		; // faust8::aN is automated
		; // faust8::del is automated
		
		;                             // gain2::Gain is automated
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, -16.); // core::gain::ResetValue
		
		;                              // gain77::Gain is automated
		gain77.setParameterT(1, 0.2);  // core::gain::Smoothing
		gain77.setParameterT(2, -10.); // core::gain::ResetValue
		
		;                              // jpanner3::Pan is automated
		jpanner3.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		this->setParameterT(0, 0.99);
		this->setParameterT(1, 0.278023);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 5746.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 6.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 0.91);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 3.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 1.);
		this->setParameterT(20, 1.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable63_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable64_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable65_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable66_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable67_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable68_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable69_t<NV>
		this->getT(0).getT(1).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable70_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable75_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable76_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable77_t<NV>
		this->getT(0).getT(2).getT(1).getT(3).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);         // Filter_impl::global_cable78_t<NV>
		this->getT(0).getT(3).getT(1).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable79_t<NV>
		this->getT(0).getT(3).getT(1).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable80_t<NV>
		this->getT(0).getT(3).getT(1).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable81_t<NV>
		this->getT(0).getT(3).getT(1).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // Filter_impl::global_cable82_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index); // Filter_impl::sliderbank18_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index); // Filter_impl::peak38_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index); // Filter_impl::sliderbank19_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index); // Filter_impl::peak39_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index); // Filter_impl::sliderbank21_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index); // Filter_impl::peak41_t<NV>
		this->getT(0).getT(3).getT(0).setExternalData(b, index); // Filter_impl::sliderbank22_t<NV>
		this->getT(0).getT(3).getT(2).setExternalData(b, index); // Filter_impl::peak42_t<NV>
		this->getT(1).getT(0).getT(0).getT(0).getT(1).           // Filter_impl::cable_table_t<NV>
        getT(1).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);
		this->getT(3).setExternalData(b, index); // Filter_impl::oscilloscope_t
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
using Filter = wrap::node<Filter_impl::instance<NV>>;
}


