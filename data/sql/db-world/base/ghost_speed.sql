-- modify ghost speed
DELETE FROM `spell_script_names` WHERE `spell_id` = 8326 AND `ScriptName` = 'spell_ghost_speed_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (8326, 'spell_ghost_speed_aura');
DELETE FROM `spell_script_names` WHERE `spell_id` = 20584 AND `ScriptName` = 'spell_ghost_speed_night_elf_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (20584, 'spell_ghost_speed_night_elf_aura');
