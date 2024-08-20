//===== Crazyarashi Services =====================================|
//= Friday Memorial Dungeon                                      =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

gef_tower,57,167,3	script	Novice Collector#friday_md	1_F_01,{
	disable_items;
	function call_mes;
	mes "[ Novice Collector ]";
	mes "You can use the Crafted Stones to empower your accessories with wonderful effects!";
	next;
	switch(select("What can I do with these stones?:Enchant Accessory:Initialize Accessory:Quit")){
		case 1:
			mes "[ Novice Collector ]";
			mes "I'm a merchant who collects and crafts using these expensive stones from several dungeons. I'm still an amateur, but I'm thankful that you came to me.";
			next;
			if(select("I've heard enough already.:Continue.") == 1){
				mes "[ Novice Collector ]";
				mes "Oh, did we talk already?";
				end;
			}
			mes "[ Novice Collector ]";
			mes "Of course the process is not free. I'll be adding the enchant to the last slot of your accessory.";
			next;
			mes "[ Novice Collector ]";
			mes "I need 10 Crafted Stones and a 100,000 Zeny fee. There is no failure in the enchanting process.";
			next;
			mes "[ Novice Collector ]";
			mes "You don't have to worry about the special option enchants on your equipment. I'll keep those safe.";
			next;
			select("What about the cards?");
			mes "[ Novice Collector ]";
			mes "You don't have to worry about it either. It won't be destroyed in the process.";
			next;
			mes "[ Novice Collector ]";
			mes "It's possible to initialize the enchants, however the success rate is about 20%. An amateur like me is only capable of that.";
			next;
			mes "[ Novice Collector ]";
			mes "In case of failure, the accessory ^0000CDwill be destroyed.^000000";
			next;
			mes "[ Novice Collector ]";
			mes "I know it's a big risk, but the difference with other merchant is that I can work almost any type of accessory.";
			next;
			mes "[ Novice Collector ]";
			mes "Oh, even with my skills, I can't work on equipments that outside of your level range. That's common sense though.";
			end;
			
		case 2:
			function enchant;
			enchant();
			
		case 3:
			function initialize;
			initialize();
	}
	
OnInit:
	setarray .accessories,
	2800,2703,2745,2766,2648,2825,2680,2809,2649,2615,2802,2656,2808,2650,2728,2609,2770,2651,2803,2652,2801,2769,2620,2720,2721,2722,2723,2724,2725,2733,2744,2804,
	2619,2671,2604,2624,2614,2787,2654,2640,2843,2772,2702,2617,2748,2773,2729,2774,2608,2626,2610,2718,2627,2719,2637,2612,2731,2767,2616,2749,2700,2743,2607,2807,
	2807,2789,2854,2853,2746,2601,2621,2790,2784,2603,2623,2788,2701,2785,2810,2628,2768,2605,2625,2881,2783,2618,2747,2611,2795,2613,2727,2716,2602,2622,2655,2771;
	
	setarray .enchant,
	4701,4702,4703,4711,4712,4713,4721,4722,4723,4731,4732,4733,4741,4742,4743,4751,4752,4753,
	4809,4808,4820,4817,4816,4843,4882,4883,4929,4887,4888,4889,4805,4850,4760,4832,4863,4864,
	4800,4801,4796,4798,4861,4862,4786,4787,4792,4794;
	
	.stone_fee = 10;
	.zeny_fee = 100000;
	.initialize_chance = 20;
end;

function	enchant	{
	.@part = EQI_ACC_R;
	.@equip_id = getequipid(.@part);
	if(.@equip_id == -1) call_mes(1);
	.@equip_name$ = getitemname(.@equip_id);
	if(inarray(.accessories,.@equip_id) == -1) call_mes(2);
	if(.@card[3] > 0) call_mes(3);
	.@refine = getequiprefinerycnt(.@part);
	for(.@i = 0; .@i < 4; .@i++){
		.@card[.@i] = getequipcardid(.@part,.@i);
		.@check[.@i] = .@card[.@i];
	}
	for(.@i = 0; .@i < 5; .@i++){
		if(getequiprandomoption(.@part,.@i,ROA_ID)){
			.@option[.@i] = getequiprandomoption(.@part,.@i,ROA_ID);
			.@val[.@i] = getequiprandomoption(.@part,.@i,ROA_VALUE);
			.@param[.@i] = getequiprandomoption(.@part,.@i,ROA_PARAM);
		}
	}
	mes "[ Novice Collector ]";
	mes "Are you sure you want to enchant your item?";
	mes "<ITEM>" + .@equip_name$ + "<INFO>" + .@equip_id + "</INFO></ITEM>";
	next;
	if(select("Cancel:Enchant") == 1) call_mes(7);
	if(countitem(25235) < .stone_fee || Zeny < .zeny_fee) call_mes(4);
	.@enchant = .enchant[rand(getarraysize(.enchant))];
	if(callfunc("F_IsEquipIDHack", .@part, .@equip_id) || callfunc("F_IsEquipRefineHack", .@part, .@refine) || callfunc("F_IsEquipCardHack", .@part, .@check[0], .@check[1], .@check[2], .@check[3]))
		end;
	mes "[ Novice Collector ]";
	mes "It's finished. Check it out!";
	specialeffect2 EF_REPAIRWEAPON;
	delitem 25235,.stone_fee;
	Zeny -= .zeny_fee;
	delequip .@part;
	getitem3 .@equip_id,1,1,.@refine,0,.@card[0],.@card[1],.@card[2],.@enchant,.@option,.@val,.@param;
	end;
}

function	initialize	{
	.@part = EQI_ACC_R;
	.@equip_id = getequipid(.@part);
	if(.@equip_id == -1) call_mes(1);
	.@equip_name$ = getitemname(.@equip_id);
	if(inarray(.accessories,.@equip_id) == -1) call_mes(2);
	if(.@card[3] == 0) call_mes(5);
	.@refine = getequiprefinerycnt(.@part);
	for(.@i = 0; .@i < 4; .@i++){
		.@card[.@i] = getequipcardid(.@part,.@i);
		.@check[.@i] = .@card[.@i];
	}
	for(.@i = 0; .@i < 5; .@i++){
		if(getequiprandomoption(.@part,.@i,ROA_ID)){
			.@option[.@i] = getequiprandomoption(.@part,.@i,ROA_ID);
			.@val[.@i] = getequiprandomoption(.@part,.@i,ROA_VALUE);
			.@param[.@i] = getequiprandomoption(.@part,.@i,ROA_PARAM);
		}
	}
	.@stone = .stone_fee;
	.@zeny = .zeny_fee;
	.@chance = .initialize_chance;
	mes "[ Novice Collector ]";
	mes "Are you sure you want to initialize your accessory?";
	mes "<ITEM>" + .@equip_name$ + "<INFO>" + .@equip_id + "</INFO></ITEM>";
	mes .@chance + "% Success Rate.";
	mes "Fee : " + .@stone + " Crafted Stones and " + F_InsertComma(.@zeny) + " Zeny.";
	next;
	if(select("I'll come back later:Initialize") == 1) call_mes(99);
	if(countitem(25235) < .@stone || Zeny < .@zeny) call_mes(4);
	if(callfunc("F_IsEquipIDHack", .@part, .@equip_id) || callfunc("F_IsEquipRefineHack", .@part, .@refine) || callfunc("F_IsEquipCardHack", .@part, .@check[0], .@check[1], .@check[2], .@check[3]))
		end;
	delitem 25235,.@stone;
	Zeny -= .@zeny;
	delequip .@part;
	if(rand(1,100) > .@chance){
		specialeffect2 EF_MAXPOWER;
		mes "[ Novice Collector ]";
		mes "Ugh, as expected it's outside my skill range... I can't recover it.";
	} else {
		specialeffect2 EF_REPAIRWEAPON;
		mes "[ Novice Collector ]";
		mes "Oh, I have successfully initialized the enchant of your accessory! I always thought I can't do it.";
		getitem3 .@equip_id,1,1,.@refine,0,.@card[0],.@card[1],.@card[2],0,.@option,.@val,.@param;
	}
	end;
}

function	call_mes	{
	switch(getarg(0)){
		case 1:
			mes "[ Novice Collector ]";
			mes "You don't have anything on your accessory slot.";
			end;
			
		case 2:
			mes "[ Novice Collector ]";
			mes "This accessory is not something I can work on. I'd probably break it if I touched it. You wouldn't want that, would you?";
			end;
			
		case 3:
			mes "[ Novice Collector ]";
			mes "This accessory is already enchanted, I can't enchant it further.";
			end;
			
		case 4:
			mes "[ Novice Collector ]";
			mes "You don't have enough materials for the enchanting process.";
			end;
			
		case 5:
			mes "[ Novice Collector ]";
			mes "I cannot initialize this accessory, it hasn't been enchanted yet.";
			end;
		
		default:
			mes "[ Novice Collector ]";
			mes "Okay, have a good one.";
			end;		
	}
}

}

gef_tower,36,177,5	script	Suspicious Man#friday_md	-1,{
	disable_items;
	.@part = EQI_ACC_R;
	if(getequipid(.@part) != .ring){
		mes "[ Suspicious Man ]";
		mes "Do you have anything interesting for me to see?";
		mes "Why don't you return when you found something interesting?";
		end;
	}
	function call_mes;
	mes "[ Suspicious Man ]";
	mes "Bring me Crafted Stones and I'll give your Royal Guard Ring a great boost!";
	next;
	switch(select("What can you do with these stones?:Enchant Accessory:Initialize Accessory:Quit")){
		case 1:
			mes "[ Suspicious Man ]";
			mes "Well, just between with you and me, I'm not allowed to use this stuff for crafting. So forget what I'm about to discuss with you.";
			next;
			if(select("I've heard enough already.:Continue.") == 1){
				mes "[ Suspicious Man ]";
				mes "I can't believe a person like you was selected by the ring.";
				end;
			}
			mes "[ Suspicious Man ]";
			mes "A long time ago, That king had three guardians for protection. But it's not in any records anymore.";
			next;
			mes "[ Suspicious Man ]";
			mes "It is said that the Royal Guard Ring chooses their owner. You're already one of the selected. However, until the ring is unsealed, you won't be able to use its true power.";
			next;
			mes "[ Suspicious Man ]";
			mes "If you want, I can unlock the true powers of the ring. Bring me 10 Crafted Stones and 100,000 Zeny.";
			next;
			mes "[ Suspicious Man ]";
			mes "If you don't like the ring's power after removing the seal, you can always reset its power. The cost will be the same as releasing the seals.";
			next;
			mes "[ Suspicious Man ]";
			mes "Well, it's nice and all that it can choose its owner...";
			end;

		case 2:
			function enchant;
			enchant();
			
		case 3:
			function initialize;
			initialize();	
	}
	
OnInit:
	.ring = 28483;
	.stone_fee = 10;
	.zeny_fee = 100000;
	.initialize_chance = 80;
	setarray .enchant$,
	"4702,4703,4704,4705,4706,4732,4733,4734,4735,4736,4742,4743,4744,4745,4746:4809,4808,4820,4821,4822,4818,4817,4816,4843,4844,4819,4766,4767,4807,4842", //Physical
	"4712,4713,4714,4715,4716,4722,4723,4724,4725,4726,4742,4743,4744,4745,4746:4813,4812,4826,4827,4828,4929,4805,4850,4851,4852,4883,4896,4897,4760,4761", //Magical
	"4732,4733,4734,4735,4736,4722,4723,4724,4725,4726,4752,4753,4754,4755,4756:4863,4864,4865,4866,4818,4817,4816,4843,4844,4832,4833,4834,4807,4842"; //Ranged
end;

function	enchant	{
	.@part = EQI_ACC_R;
	.@equip_id = getequipid(.@part);
	if(.@equip_id == -1) call_mes(1);
	.@equip_name$ = getitemname(.@equip_id);
	if(.@equip_id != .ring) call_mes(2);
	if(.@card[2] > 0) call_mes(3);
	.@refine = getequiprefinerycnt(.@part);
	for(.@i = 0; .@i < 4; .@i++){
		.@card[.@i] = getequipcardid(.@part,.@i);
		.@check[.@i] = .@card[.@i];
	}
	.@slot = (.@card[3] > 0 ? 2 : 3);
	mes "[ Suspicious Man ]";
	mes "What power are you looking to release?";
	next;
	switch(select("Let me think about it:Physical:Magical:Long Range")){
		case 1: call_mes(99);
		
		case 2:
			.@index = 0;
			break;
			
		case 3:
			.@index = 1;
			break;
			
		case 4:
			.@index = 2;
			break;
	}
	.@id = (.@slot == 3 ? 0 : 1);
	mes "[ Suspicious Man ]";
	mes "I will remove one of the seals your Royal Guard Ring.";
	next;
	if(select("I'll come back later:Release") == 1) call_mes(7);
	if(countitem(25235) < .stone_fee || Zeny < .zeny_fee) call_mes(4);
	explode(.@T$,.enchant$[.@index],":");
	explode(.@TT$,.@T$[.@id],",");
	.@card[.@slot] = atoi(.@TT$[rand(getarraysize(.@TT$))]);
	if(callfunc("F_IsEquipIDHack", .@part, .@equip_id) || callfunc("F_IsEquipRefineHack", .@part, .@refine) || callfunc("F_IsEquipCardHack", .@part, .@check[0], .@check[1], .@check[2], .@check[3]))
		end;
	mes "[ Suspicious Man ]";
	mes "One of the seals has been released. Please check the ring.";
	specialeffect2 EF_REPAIRWEAPON;
	delitem 25235,.stone_fee;
	Zeny -= .zeny_fee;
	delequip .@part;
	getitem2 .@equip_id,1,1,.@refine,0,.@card[0],.@card[1],.@card[2],.@card[3];
	end;
}

function	initialize	{
	.@part = EQI_ACC_R;
	.@equip_id = getequipid(.@part);
	if(.@equip_id == -1) call_mes(1);
	.@equip_name$ = getitemname(.@equip_id);
	if(.@equip_id != .ring) call_mes(2);
	if(.@card[2] == 0) call_mes(5);
	.@refine = getequiprefinerycnt(.@part);
	for(.@i = 0; .@i < 4; .@i++){
		.@card[.@i] = getequipcardid(.@part,.@i);
		.@check[.@i] = .@card[.@i];
	}
	.@stone = .stone_fee;
	.@zeny = .zeny_fee;
	.@chance = .initialize_chance;
	mes "[ Suspicious Man ]";
	mes "Are you sure you want to initialize your Royal Guard Ring?";
	mes "There is a " + .@chance + "% chance that your ring will break.";
	next;
	if(select("I'll come back later:Initialize") == 1) call_mes(99);
	if(countitem(25235) < .@stone || Zeny < .@zeny) call_mes(4);
	if(callfunc("F_IsEquipIDHack", .@part, .@equip_id) || callfunc("F_IsEquipRefineHack", .@part, .@refine) || callfunc("F_IsEquipCardHack", .@part, .@check[0], .@check[1], .@check[2], .@check[3]))
		end;
	delitem 25235,.@stone;
	Zeny -= .@zeny;
	delequip .@part;
	if(rand(1,100) > .@chance){
		specialeffect2 EF_MAXPOWER;
		mes "[ Suspicious Man ]";
		mes "Well, you can't blame an unofficial artisan, right?";
	} else {
		specialeffect2 EF_REPAIRWEAPON;
		mes "[ Suspicious Man ]";
		mes "The seals of your Royal Guard Ring has been initialized.";
		getitem2 .@equip_id,1,1,.@refine,0,.@card[0],.@card[1],0,0;
	}
	end;
}

function	call_mes	{
	switch(getarg(0)){
		case 1:
			mes "[ Suspicious Man ]";
			mes "You don't have anything on your accessory slot.";
			end;
			
		case 2:
			mes "[ Suspicious Man ]";
			mes "You're not a chosen person by the ring.";
			end;
			
		case 3:
			mes "[ Suspicious Man ]";
			mes "This rings sealed has been completely released.";
			end;
			
		case 4:
			mes "[ Suspicious Man ]";
			mes "You don't have enough materials or zeny to release the seal of this ring.";
			end;
			
		case 5:
			mes "[ Suspicious Man ]";
			mes "There's still a sealed left intact in the ring. I can't initialize it yet. Bring it back when it's fully released.";
			end;
		
		default:
			mes "[ Novice Collector ]";
			mes "Okay, have a good one.";
			end;		
	}
}

}

gef_tower,57,164,3	script	Mariage#friday_md	4_F_JOB_BLACKSMITH,{
	if(BaseLevel < 99){
		mes "[ Mariage ]";
		mes "It seems that you're too weak to use this dungeon. I don't want to be held responsible for any deaths of weak adventurers.";
		mes "Why don't you come back when you're atleast level 100.";
		end;
	}
	if(gettime(DT_DAYOFWEEK) != FRIDAY){
		mes "[ Mariage ]";
		mes "Who are you?";
		mes "Please listen to the opening hours.";
		close;
	}
	.@party_id = getcharid(1);
	if(!.@party_id){
		mes "[ Mariage ]";
		mes "Who are you? You're not in a party.";
		mes "You need to be in one to enter the dungeon.";
		close;
	}
	.@party_name$ = getpartyname(.@party_id);
	switch(checkquest(12379,PLAYTIME)){
		case -1:
			break;
			
		case 0:
		case 1:
			mes "[ Mariage ]";
			mes "You still have traces of the memorial, please come back again next week.";
			end;
			
		case 2:
			erasequest 12379;
			break;
	}
	.@md_name$ = "Friday Memorial";
	mes "[ Mariage ]";
	mes "Welcome! I'm about to open the memorial dungeon, would you like to enter?";
	next;
	switch(select((is_party_leader() ? "Create 'Friday Memorial'":""),"Enter 'Friday Memorial'","Cancel")){
		case 1:
			switch(instance_create(.@md_name$)){
				case -1:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "Unknown Error Has Occurred.";
					end;
				case -2:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "Party Is Non-Existent.";
					end;
				case -3:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "Player already have instance.";
					end;
					
				case -4:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "^0000ff"+.@md_name$+" ^000000 is currently full.";
					end;
					
				default:
					mes "[ Mariage ]";
					mes "I'll create the passage to the memorial dungeon for you. Talk to me again, when you're ready to enter.";
					end;
			}

		
		case 2:
			switch(instance_enter(.@md_name$)){
				case 3:
					mes "An unknown error has occurred.";
					end;
					
				case 2:
				case 1:
					mes "[ Mariage ]";
					mes "Huh, you didn't reserve a passage to enter.";
					end;
					
				case 0:
					mapannounce "gef_tower", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00FF99";
					end;
			}		
		
		case 3:
			mes "[ Mariage ]";
			mes "Huh? I'm quite confused. I thought you'll enter, could you talk to me again?";
			end;
	}
}



1@md_gef,1,1,0	script	#friday_md_control	-1,{
	end;
	
OnInstanceInit:
	set_instance_var("map$",instance_mapname("1@md_gef"));
	instance_enable("Mariage#fmd_0",true);
	instance_enable("Mariage#fmd_1",true);
	instance_hide("Mariage#fmd_1",true);
	instance_enable("fmd_boss",false);
end;
}

1@md_gef,110,129,5	script	Mariage#fmd_0	4_F_JOB_BLACKSMITH,{
	.@var = get_instance_var("setup");
	if(.@var == 0){
		if(!is_party_leader()){
			mes "[ Mariage ]";
			mes "I'm still speaking to your party leader for the enviroment setup.";
			end;
		}
		mes "[ Mariage ]";
		mes "I will prepare the memorial enviroment here but before that, I'll ask you to select the appropriate level range for you. You can choose base on your liking and on your abilities.";
		next;
		switch(select("Cancel:Level 99 to 110:Level 160 and above.")){
			case 1:
				mes "[ Mariage ]";
				mes "Speak to me again, if you decided on what to choose.";
				end;
				
			case 2:
				.@type = 0;
				break;
				
			case 3:
				.@type = 1;
				break;
		}
		set_instance_var("setup",1);
		set_instance_var("type",.@type);
		close2;
		instance_event("Mariage#fmd_1","OnStart",false);
		end;
	}
	end;
}

1@md_gef,110,129,5	script	Mariage#fmd_1	4_F_JOB_BLACKSMITH,{
	end;
	
OnStart:
	.@type = get_instance_var("type");
	instance_enable("Mariage#fmd_0",false);
	instance_hide(strnpcinfo(0),false);
	sleep 2000;
	npctalk "This place will be soon be a hunting grounds. I'll close the gates and let the monsters roam in this place.";
	sleep 2000;
	npctalk "Goodluck, adventurers~";
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	sleep 1000;
	instance_event("fmd_mobs","OnSummon",false);
	if(.@type)
		instance_event("fmd_boss","OnTimer",false);
end;
}

1@md_gef,199,70,0	script	Strange Sculpture::fmd_boss	-1,{
	.@var = get_instance_var("mvp_active");
	if(!.@var){
		mes "This strange sculpture is filled with dust.";
		end;
	}
	if(.@var == 1){
		mes "The dust that piled up scattered when you touched the sculpture and there seems to be an empty holes on it.";
		next;
		mes "It appears to be ten holes of the same size as those Crafted Stones.";
		next;
		if(select("Try to look somewhere else.:Insert 10 Crafted Stones.") == 1)
			end;
		if(countitem(25235) < 10){
			mes "It appears that I don't have enough Crafted Stone to insert.";
			end;
		}
		mes "By inserting 10 crafted stones to the strange sculpture, a bright light appeared.";
		next;
		mes "The atmosphere in the dungeon seems to have changed.";
		set_instance_var("mvp_active",1);
		instance_event(strnpcinfo(0),"OnSummon",false);
		end;
	}
	end;
	
OnTimer:
	.@timer = (1000 * 60) * 30;
	sleep .@timer;
	set_instance_var("mvp_active",1);
end;

OnSummon:
	.@type = get_instance_var("type");
	if(!.@type)
		.@lich = 3660;
	else
		.@lich = 3661;
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnBossKill";
	mapannounce .@map$,"Lich Lord : Who dare wake me from my slumber? I will face you myself!",bc_map,0xFF0000;
	monster .@map$,0,0,"--ja--",.@lich,1,.@event$;
	set_instance_var("mvp_summoned",1);
end;

OnBossKill:	
end;
}

1@md_gef,1,1,0	script	fmd_mobs	-1,{
	end;
	
OnSummon:
	.@type = get_instance_var("type");
	if(!.@type){
		.@nightmare = 3660;
		.@jakk = 3662;
		.@ghoul = 3664;
		.@drain = 3666;
	} else {
		.@nightmare = 3661;
		.@jakk = 3663;
		.@ghoul = 3665;
		.@drain = 3667;
	}
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnMobKill";
	monster .@map$,0,0,"--ja--",.@nightmare,30,.@event$;
	monster .@map$,0,0,"--ja--",.@jakk,30,.@event$;
	monster .@map$,0,0,"--ja--",.@ghoul,40,.@event$;
	monster .@map$,0,0,"--ja--",.@drain,30,.@event$;
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnMobKill";
	.@id = killedrid;
	monster .@map$,0,0,"--ja--",.@id,1,.@event$;
end;
}

1@md_gef	mapflag	noteleport
1@md_gef	mapflag	nomemo
1@md_gef	mapflag	nogo
1@md_gef	mapflag	nobranch