/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */
#include "Config.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "SpellScriptLoader.h"
#include "mod_ghost_speed.h"

GhostSpeed* GhostSpeed::instance()
{
    static GhostSpeed instance;
    return &instance;
}

class world_ghost_speed : public WorldScript
{
public:
    world_ghost_speed() : WorldScript("world_ghost_speed") { }

    void OnAfterConfigLoad(bool /*reload*/) override
    {
        sGhostSpeed->speed = sConfigMgr->GetOption<int32>("GhostSpeed.Speed", 200);
        sGhostSpeed->speedSwim = sConfigMgr->GetOption<int32>("GhostSpeed.SpeedSwim", 200);
        sGhostSpeed->speedNightElf = sConfigMgr->GetOption<int32>("GhostSpeed.SpeedNightElf", 300);
        sGhostSpeed->speedSwimNightElf = sConfigMgr->GetOption<int32>("GhostSpeed.SpeedSwimNightElf", 300);
    }
};

// 8326 Ghost
class spell_ghost_speed_aura : public AuraScript
{
    PrepareAuraScript(spell_ghost_speed_aura);

    void CalculateAmountSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = sGhostSpeed->speed;
    }

    void CalculateAmountSwimSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = sGhostSpeed->speedSwim;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_ghost_speed_aura::CalculateAmountSpeed, EFFECT_1, SPELL_AURA_MOD_INCREASE_SPEED);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_ghost_speed_aura::CalculateAmountSwimSpeed, EFFECT_2, SPELL_AURA_MOD_INCREASE_SWIM_SPEED);
    }
};

// 20584 Ghost - Night Elf
class spell_ghost_speed_night_elf_aura : public AuraScript
{
    PrepareAuraScript(spell_ghost_speed_night_elf_aura);

    void CalculateAmountSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = sGhostSpeed->speedNightElf;
    }

    void CalculateAmountSwimSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = sGhostSpeed->speedSwimNightElf;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_ghost_speed_night_elf_aura::CalculateAmountSpeed, EFFECT_1, SPELL_AURA_MOD_INCREASE_SPEED);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_ghost_speed_night_elf_aura::CalculateAmountSwimSpeed, EFFECT_2, SPELL_AURA_MOD_INCREASE_SWIM_SPEED);
    }
};

void AddSC_ghost_speed_spell_script()
{
    new world_ghost_speed();
    RegisterSpellScript(spell_ghost_speed_aura);
    RegisterSpellScript(spell_ghost_speed_night_elf_aura);
}
