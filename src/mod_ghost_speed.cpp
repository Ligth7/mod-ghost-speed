/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "SpellScriptLoader.h"

// 8326 Ghost
class spell_ghost_speed_aura : public AuraScript
{
    PrepareAuraScript(spell_ghost_speed_aura);

    void CalculateAmountSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = 500; // default: 50
    }

    void CalculateAmountSwimSpeed(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = 500; // default: 50
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_ghost_speed_aura::CalculateAmountSpeed, EFFECT_1, SPELL_AURA_MOD_INCREASE_SPEED);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_ghost_speed_aura::CalculateAmountSwimSpeed, EFFECT_2, SPELL_AURA_MOD_INCREASE_SWIM_SPEED);
    }
};

void AddSC_ghost_speed_spell_script()
{
    RegisterSpellScript(spell_ghost_speed_aura);
}
