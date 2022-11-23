#ifndef _ARCH_MLOG_RADAR_H
#define _ARCH_MLOG_RADAR_H

#define RADAR_FILTER_ANY "any"
#define RADAR_FILTER_ENEMY "enemy"
#define RADAR_FILTER_ALLY "ally"
#define RADAR_FILTER_PLAYER "player"
#define RADAR_FILTER_ATTACKER "attacker"
#define RADAR_FILTER_FLYING "flying"
#define RADAR_FILTER_GROUND "ground"
#define RADAR_FILTER_BOSS "boss"

#define RADAR_ORDERBY_DISTANCE "distance"
#define RADAR_ORDERBY_HEALTH "health"
#define RADAR_ORDERBY_SHIELD "shield"
#define RADAR_ORDERBY_ARMOR "armor"
#define RADAR_ORDERBY_MAXHEALTH "maxHealth"

#define BUILDING_RADAR(result, building, filter1, filter2, filter3, asc, orderby) \
    __asm__ ("radar " filter1 " " filter2 " "  filter3 " " orderby " "\
            "%1 %2 %0" \
            : "=r" (result) \
            : "r" (building), "r" (asc) )

#define UNIT_RADAR(result, building, filter1, filter2, filter3, asc, orderby) \
    __asm__ ("uradar " filter1 " " filter2 " "  filter3 " " orderby " "\
            "0 %1 %0" \
            : "=r" (result) \
            : "r" (asc) )


#endif //_ARCH_MLOG_RADAR_H
