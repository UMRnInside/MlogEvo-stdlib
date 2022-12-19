/* 
 * List of senseable attributes
 * Assume MlogObject is senseable (buildings, units, etc.)
 */
#ifndef _MLOGEVO_MLOG_OBJECT_H
#define _MLOGEVO_MLOG_OBJECT_H

#define _MOBJ struct MlogObject*

struct MlogObject {
    // Serpulo items
    int copper, lead, metaglass, graphite;
    int sand, coal, titanium, thorium;
    int scrap, silicon, plastanium, phase_fabric;
    int surge_alloy, spore_pod, blast_compound, pyratite;
    // Erkeir items
    int beryllium, tungsten, oxide, carbide;
    int fissile_matter, dormant_cyst;
    // Serpulo liquids
    double water, slag, oil, cryofluid;
    // Erkeir liquids
    double neoplasm, arkycite;
    // Erkeir gas
    double ozone, hydrogen, nitrogen, cyanogen;

    // item-related
    int totalItems;
    int itemCapacity;
    _MOBJ firstItem;
    // liquid-related
    double totalLiquids, liquidCapacity;
    // power-related
    double powerCapacity, powerNetStored, powerNetCapacity;
    double powerNetIn, powerNetOut;

    // ammo-related
    // Liquid-powered turrets (e.g. Wave, Tsunami) do not use ammo & ammoCapacity
    int ammo, ammoCapacity;

    // factory-related (maybe?)
    double efficiency, progress, timescale;
    // building-only
    int rotation;
    int enabled;

    double health, maxHealth;
    double heat;
    double x, y;
    double shootX, shootY;
    double range;
    int size;
    int team;
    _MOBJ type;
    _MOBJ controller;
    _MOBJ name;
    _MOBJ config;

    // A payload may be contained by units or buildings
    _MOBJ payloadType;

    // Unit-related
    int dead;
    int shooting, boosting;
    int mineX, mineY, mining;
    double speed;
    double flag;

    double color;
};

// Mindustry logic builtin constant: null
extern struct MlogObject null;

#undef _MOBJ
#endif //_MLOGEVO_MLOG_OBJECT_H
