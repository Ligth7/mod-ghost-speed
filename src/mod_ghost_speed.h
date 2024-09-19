#ifndef DEF_GHOSTSPEED_H
#define DEF_GHOSTSPEED_H

class GhostSpeed
{
public:
    static GhostSpeed* instance();

    int32 speed;
    int32 speedSwim;
    int32 speedNightElf;
    int32 speedSwimNightElf;
};

#define sGhostSpeed GhostSpeed::instance()

#endif
