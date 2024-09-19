#ifndef DEF_GHOSTSPEED_H
#define DEF_GHOSTSPEED_H

class GhostSpeed
{
public:
    static GhostSpeed* instance();

    int32 speed;
    int32 speedSwim;
};

#define sGhostSpeed GhostSpeed::instance()

#endif
