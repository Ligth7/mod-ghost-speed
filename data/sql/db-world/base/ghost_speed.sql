-- modify ghost speed
DELETE FROM `spell_script_names` WHERE `spell_id` = 8326;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (8326, 'spell_ghost_speed_aura');
