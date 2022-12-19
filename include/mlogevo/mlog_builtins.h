#ifndef _MLOGEVO_MLOG_BUILTINS_H
#define _MLOGEVO_MLOG_BUILTINS_H

#define mlogobj struct MlogObject
// TODO: implement const and volatile
// NOTE: some fields are MUTABLE!
struct MLOG_BUILTINS {
    // Processor builtin constants/variables
    // https://mindustrygame.github.io/wiki/logic/3-variables/#processor-variables-and-constants
    const mlogobj this;
    const double thisx, thisy;
    const int ipt;
#ifdef MLOGEV_EXPOSE_COUNTER
    // BE EXTREMELY CAREFUL when handling this
    volatile int counter;
#endif
    const volatile int links;
    const volatile double time;
    const volatile int tick;
    const volatile int mapw, maph;
    const volatile mlogobj unit;
    // Lookup
    const int unitCount, itemCount, liquidCount, blockCount;
    // sensor @controlled
    const int ctrlProcessor, ctrlPlayer, ctrlFormation;

    // Serpulo items
    const mlogobj copper, lead, metaglass, graphite;
    const mlogobj sand, coal, titanium, thorium;
    const mlogobj scrap, silicon, plastanium, phase_fabric;
    const mlogobj surge_alloy, spore_pod, blast_compound, pyratite;
    // Erkeir items
    const mlogobj beryllium, tungsten, oxide, carbide;
    const mlogobj fissile_matter, dormant_cyst;
    // Serpulo liquids
    const mlogobj water, slag, oil, cryofluid;
    // Erkeir liquids
    const mlogobj neoplasm, arkycite;
    // Erkeir gas
    const mlogobj ozone, hydrogen, nitrogen, cyanogen;

    // Serpulo units
    const mlogobj dagger, mace, fortress, scepter;
    const mlogobj reign, nova, pulsar, quasar;
    const mlogobj vela, corvus, crawler, atrax;
    const mlogobj spiroct, arkyid, toxopid, flare;
    const mlogobj horizon, zenith, antumbra, eclipse;
    const mlogobj mono, poly, mega, quad;
    const mlogobj oct, risso, minke, bryde;
    const mlogobj sei, omura, retusa, oxynoe;
    const mlogobj cyerce, aegires, navanax, alpha;
    const mlogobj beta, gamma;
    // Erkeir units
    const mlogobj stell, locus;
    const mlogobj precept, vanquish, conquer, merui;
    const mlogobj cleroi, anthicus, tecta, collaris;
    const mlogobj elude, avert, obviate, quell;
    const mlogobj disrupt, evoke, incite, emanate;

    // Serpulo buildings
    const mlogobj graphite_press, multi_press, silicon_smelter, silicon_crucible;
    const mlogobj kiln, plastanium_compressor, phase_weaver, cryofluid_mixer;
    const mlogobj pyratite_mixer, blast_mixer, melter, separator;
    const mlogobj disassembler, spore_press, pulverizer, coal_centrifuge;
    const mlogobj incinerator, copper_wall, copper_wall_large, titanium_wall;
    const mlogobj titanium_wall_large, plastanium_wall, plastanium_wall_large, thorium_wall;
    const mlogobj thorium_wall_large, phase_wall, phase_wall_large, surge_wall;
    const mlogobj surge_wall_large, door, door_large, scrap_wall;
    const mlogobj scrap_wall_large, scrap_wall_huge, scrap_wall_gigantic, mender;
    const mlogobj mend_projector, overdrive_projector, overdrive_dome, force_projector;
    const mlogobj shock_mine, conveyor, titanium_conveyor, plastanium_conveyor;
    const mlogobj armored_conveyor, junction, bridge_conveyor, phase_conveyor;
    const mlogobj sorter, inverted_sorter, router, distributor;
    const mlogobj overflow_gate, underflow_gate, mass_driver, duct;
    const mlogobj duct_router, duct_bridge, mechanical_pump, rotary_pump;
    const mlogobj conduit, pulse_conduit, plated_conduit, liquid_router;
    const mlogobj liquid_tank, liquid_junction, bridge_conduit, phase_conduit;
    const mlogobj power_node, power_node_large, surge_tower, diode;
    const mlogobj battery, battery_large, combustion_generator, thermal_generator;
    const mlogobj steam_generator, differential_generator, rtg_generator, solar_panel;
    const mlogobj solar_panel_large, thorium_reactor, impact_reactor, mechanical_drill;
    const mlogobj pneumatic_drill, laser_drill, blast_drill, water_extractor;
    const mlogobj cultivator, oil_extractor, core_shard, core_foundation;
    const mlogobj core_nucleus, vault, container, unloader;
    const mlogobj duo, scatter, scorch, hail;
    const mlogobj wave, lancer, arc, parallax;
    const mlogobj swarmer, salvo, segment, tsunami;
    const mlogobj fuse, ripple, cyclone, foreshadow;
    const mlogobj spectre, meltdown, command_center, ground_factory;
    const mlogobj air_factory, naval_factory, additive_reconstructor, multiplicative_reconstructor;
    const mlogobj exponential_reconstructor, tetrative_reconstructor, repair_point, repair_turret;
    const mlogobj payload_conveyor, payload_router, payload_propulsion_tower, power_source;
    const mlogobj power_void, item_source, item_void, liquid_source;
    const mlogobj liquid_void, payload_void, payload_source, illuminator;
    const mlogobj launch_pad, interplanetary_accelerator, message, Switch;
    const mlogobj micro_processor, logic_processor, hyper_processor, memory_cell;
    const mlogobj memory_bank, logic_display, large_logic_display, liquid_container;
    // Erkeir buildings, I think.
    const mlogobj deconstructor, constructor, thruster, large_constructor;
    const mlogobj payload_loader, payload_unloader, silicon_arc_furnace, cliff_crusher;
    const mlogobj plasma_bore, reinforced_liquid_junction, breach, core_bastion;
    const mlogobj turbine_condenser, beam_node, beam_tower, build_tower;
    const mlogobj impact_drill, carbide_crucible, surge_conveyor, duct_unloader;
    const mlogobj surge_router, reinforced_conduit, reinforced_liquid_router, reinforced_liquid_container;
    const mlogobj reinforced_liquid_tank, reinforced_bridge_conduit, core_citadel, core_acropolis;
    const mlogobj heat_reactor, impulse_pump, reinforced_pump, electrolyzer;
    const mlogobj oxidation_chamber, surge_smelter, surge_crucible, overflow_duct;
    const mlogobj large_plasma_bore, cyanogen_synthesizer, slag_centrifuge, electric_heater;
    const mlogobj slag_incinerator, phase_synthesizer, sublimate, reinforced_container;
    const mlogobj reinforced_vault, atmospheric_concentrator, unit_cargo_loader, unit_cargo_unload_point;
    const mlogobj chemical_combustion_chamber, pyrolysis_generator, regen_projector, titan;
    const mlogobj small_deconstructor, vent_condenser, phase_heater, heat_redirector;
    const mlogobj tungsten_wall, tungsten_wall_large, tank_assembler, beryllium_wall;
    const mlogobj beryllium_wall_large, eruption_drill, ship_assembler, mech_assembler;
    const mlogobj shield_projector, beam_link, world_processor, reinforced_payload_conveyor;
    const mlogobj reinforced_payload_router, disperse, large_shield_projector, payload_mass_driver;
    const mlogobj world_cell, carbide_wall, carbide_wall_large, tank_fabricator;
    const mlogobj mech_fabricator, ship_fabricator, reinforced_surge_wall, radar;
    const mlogobj blast_door, canvas, armored_duct, shield_breaker;
    const mlogobj unit_repair_tower, diffuse, prime_refabricator, basic_assembler_module;
    const mlogobj reinforced_surge_wall_large, tank_refabricator, mech_refabricator, ship_refabricator;
    const mlogobj slag_heater, afflict, shielded_wall, lustre;
    const mlogobj scathe, smite, underflow_duct, malign;
    const mlogobj shockwave_tower, heat_source, flux_reactor, neoplasia_reactor;
};
#undef mlogobj

struct MLOG_BUILTINS builtins;
#endif //_MLOGEVO_MLOG_BUILTINS_H
