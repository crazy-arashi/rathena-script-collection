glast_01,184,283,4	script	Dark Magic Master#hard_enchant	1_F_01,{
	disable_items;
	if ((MaxWeight - Weight) < 1000) {
		mes "Your bag is too heavy. Reduce some weight and come back.";
		close;
	}
	if (checkweight(1201,1) == 0) {
		mes "You seem to be carrying too many items. Put some items in storage and come back again.";
		close;
	}
	mes "[ Dark Magic Master ]";
	mes "I only deal with the Temporal Boots with socket. Only if you have enough materials for it.";
	next;
	switch(select("How does the enchanting work?:Enchant my Temporal Boots:Initialize Temporal Boots Enchant")){
		case 1:
			mes "[ Dark Magic Master ]";
			mes "You should ask Hugin's magic master all the basic things. I want deeper conversation about enchating work.";
			next;
			mes "[ Dark Magic Master ]";
			mes "I need 4 items. ^0000ff" + callfunc("F_InsertComma",.@cost_zeny) + ", " + getitemname(.@polluted_id) + ", " + getitemname(.@coagulated_id) + ", Temporal Boots(Socket) Series^000000. If you don't have any of these, I cannot help you.";
			next;
			mes "[ Dark Magic Master ]";
			mes "It's my small hobby.. To enchant Socketed Temporal Boots using polluted and coagulated spell.";
			next;
			mes "[ Dark Magic Master ]";
			mes "Of course, you must cope with bigger risk of destruction whenever you'd like to enchant again and again.";
			next;
			mes "[ Dark Magic Master ]";
			mes "The enchant order is same as Hugin's magic master's enchantment. Please refer to his explanation.";
			close;
			
		case 2:
			function enchant;
			enchant();
			
		case 3:
			function reset;
			reset();	
	}
	end;
	
OnInit:
	disablenpc "Dark magic master#pa082";
end;
	
function	enchant	{
	.@equip_id = getequipid(EQI_SHOES);
	.@coagulated_id = 6608;
	.@polluted_id = 6755;
	.@cost_zeny = 100000;
	switch(.@equip_id) {
		case 22006:	// Temporal_Str_Boots_
		case 22007:	// Temporal_Vit_Boots_
		case 22008:	// Temporal_Dex_Boots_
		case 22009:	// Temporal_Int_Boots_
		case 22010:	// Temporal_Agi_Boots_
		case 22011:	// Temporal_Luk_Boots_
		case 22113:	// Modified_Str_Boots_
		case 22114:	// Modified_Int_Boots_
		case 22115:	// Modified_Agi_Boots_
		case 22116:	// Modified_Vit_Boots_
		case 22117:	// Modified_Dex_Boots_
		case 22118:	// Modified_Luk_Boots_
			break;
		
		case -1:
			mes "[ Dark Magic Master ]";
			mes "Are you wearing the item?";
			close;
			
		default:
			mes "[ Dark Magic Master ]";
			mes "This is not the right item for this enchant. Remember, only those 6 types of Temporal Boots with socket are available for hidden enchanting..";
			close;
	}
	.@equip_name$ = getequipname(EQI_SHOES);
	.@equip_refine = getequiprefinerycnt(EQI_SHOES);
	for(.@i = 0; .@i < 4; .@i++){
		.@card[.@i] = getequipcardid(EQI_SHOES,.@i);
		.@check[.@i] = .@card[.@i];
	}
	
	// enchants ID
	setarray .@enchant_1[0],4808,4832,4814,4741,4869,4752;// Fighting_Spirit4	Expert_Archer1	Spell2	Vitality2	DelayafterAttack1Lv	Luck3
	setarray .@enchant_2[0],4820,4833,4813,4742,4872,4753;// Fighting_Spirit5	Expert_Archer2	Spell3	Vitality3	DelayafterAttack2Lv	Luck4
	setarray .@enchant_3[0],4821,4834,4812,4861,4873,4754;// Fighting_Spirit6	Expert_Archer3	Spell4	MHP1		DelayafterAttack3Lv	Luck5
	setarray .@enchant_4[0],4822,4835,4826,4862,4881,4755;// Fighting_Spirit7	Expert_Archer4	Spell5	MHP2		DelayafterAttack4Lv	Luck6

	// requirements amount
	setarray .@en_amount_coag[0],3,10,20,40,50;
	setarray .@en_amount_polluted[0],1,2,4,7,10;
	
	if (.@card[2] > 0) {
		mes "[ Dark Magic Master ]";
		mes "These boots have already passed the enchanting limit. We can't enchant them any more.";
		close;
	}
	if (.@card[3] == 0) {// 4th slot 1st try enchanting
		.@amount_coag = .@en_amount_coag[0];
		.@amount_poll = .@en_amount_polluted[0];

		mes "[ Dark Magic Master ]";
		mes "Want to enchant ^0000ff" + .@equip_name$ + " (Socket)^000000? For the 1st enchanting, you need ^0000ff" + .@amount_poll + " " + getitemname(.@polluted_id) + ", " + .@amount_coag + " " + getitemname(.@coagulated_id) + ", and " + callfunc("F_InsertComma",.@cost_zeny) + " zeny^000000.";
		next;
		.@s = select( "Quit", "Fighting Spirit", "Archery", "Spell", "Vitality", "Attack Speed", "Lucky" ) - 2;
		if (.@s == -1) {
			mes "[ Dark Magic Master ]";
			mes "Ok, come back when you are ready.";
			close;
		}
		.@card[3] = .@enchant_1[.@s];
		.@string$ = "enchant number ^6300001^000000.";
		.@num = 0;
	}
	else {
		for ( .@num = 1; .@num < 5; .@num++ ) {
			for ( .@type = 0; .@type < 6 && .@card[3] != getd( ".@enchant_" + .@num + "[" + .@type + "]" ); .@type++ )
				continue;
			if (.@type < 6)
				break;
		}
		if (.@num == 5) {
			mes "[ Dark Magic Master ]";
			mes "Something wrong happened.";
			close;
		}
		.@amount_coag = .@en_amount_coag[.@num];
		.@amount_poll = .@en_amount_polluted[.@num];

		mes "[ Dark Magic Master ]";
		if (.@num == 4) {
			.@card[2] = callfunc("F_Rand",4875,4876,4877,4878,4879,4880);// Bear's_Power, Runaway_Magic, Speed_Of_Light, Muscle_Fool, Hawkeye, Lucky_Day
			.@string$ = "^990000 Bonus effect ^000000 upgrade.";
			mes "Would you like a random bonus effect for the 3rd slot? You need ^0000ff" + .@amount_poll + " " + getitemname(.@polluted_id) + ", " + .@amount_coag + " " + getitemname(.@coagulated_id) + ", and " + callfunc("F_InsertComma",.@cost_zeny) + " zeny^000000. But it has high risk of failing..";
		}
		else {
			.@level = .@num + 1;
			.@card[3] = getd( ".@enchant_" + (.@num+1) + "[" + .@type + "]" );
			.@string$ = "enchant number ^990000" + .@level + "^000000.";
			mes "Enchanting ^0000ff" + .@equip_name$ + " (Socket)^000000's 4th slot as ^0000ff" + .@level + "^000000 level effect. Requires ^0000ff" + .@amount_poll + " " + getitemname(.@polluted_id) + ", " + .@amount_coag + " " + getitemname(.@coagulated_id) + ", and " + callfunc("F_InsertComma",.@cost_zeny) + " z^000000. It has some risk of failing..";
		}
		next;
		if (select( "Quit", "Effect Upgrade!" ) == 1) {
			mes "[ Dark Magic Master ]";
			mes "Okay, come back when you are ready.";
			close;
		}
	}
	if (countitem(.@coagulated_id) < .@amount_coag) {
		mes "[ Dark Magic Master ]";
		mes "Hmm, you are missing " + (.@amount_coag - countitem(.@coagulated_id)) + " " + getitemname(.@coagulated_id) + " items. Go get more, and then we can talk about more enchants.";
		close;
	}
	if (countitem(.@polluted_id) < .@amount_poll) {
		mes "[ Dark Magic Master ]";
		mes "Hmm, you are missing " + (.@amount_poll - countitem(.@polluted_id)) + " " + getitemname(.@polluted_id) + " items. Go get more, and then we can talk about more enchants.";
		close;
	}
	if (Zeny < .@cost_zeny) {
		mes "[ Dark Magic Master ]";
		mes "You must bring ^0000ff" + callfunc("F_InsertComma",.@cost_zeny) + " zeny^000000. Nothing is free you know...";
		close;
	}
	delitem .@coagulated_id, .@amount_coag;
	delitem .@polluted_id, .@amount_poll;
	Zeny -= .@cost_zeny;
	// anti-hack
	if (callfunc("F_IsEquipIDHack", EQI_SHOES, .@equip_id) || callfunc("F_IsEquipCardHack", EQI_SHOES, .@check[0], .@check[1], .@check[2], .@check[3]) || callfunc("F_IsEquipRefineHack", EQI_SHOES, .@equip_refine))
		close;
	delequip EQI_SHOES;
	specialeffect2 EF_REPAIRWEAPON;
	mes "[ Dark Magic Master ]";
	mes "Trying for " + .@string$;
	getitem2 .@equip_id,1,1,.@equip_refine,0,.@card[0],.@card[1],.@card[2],.@card[3];
	end;
}

function	reset	{	
	.@equip_id = getequipid(EQI_SHOES);
	.@polluted_id = 6755;
	.@temporal_fragment = 25867; //OGH CHALLENGE MODE DROP
	.@dimension_essence = 7925; //Cash Reset from KRO
	switch(.@equip_id) {
		case 22006:	// Temporal_Str_Boots_
		case 22007:	// Temporal_Vit_Boots_
		case 22008:	// Temporal_Dex_Boots_
		case 22009:	// Temporal_Int_Boots_
		case 22010:	// Temporal_Agi_Boots_
		case 22011:	// Temporal_Luk_Boots_
		case 22113:	// Modified_Str_Boots_
		case 22114:	// Modified_Int_Boots_
		case 22115:	// Modified_Agi_Boots_
		case 22116:	// Modified_Vit_Boots_
		case 22117:	// Modified_Dex_Boots_
		case 22118:	// Modified_Luk_Boots_
			break;
		
		case -1:
			mes "[ Dark Magic Master ]";
			mes "Are you wearing the item?";
			close;
			
		default:
			mes "[ Dark Magic Master ]";
			mes "This is not the right item for this enchant. Remember, only those 6 types of Temporal Boots with socket are available for hidden enchanting..";
			close;
	}
	.@equip_name$ = getequipname(EQI_SHOES);
	.@equip_refine = getequiprefinerycnt(EQI_SHOES);
	for(.@i = 0; .@i < 4; .@i++){
		.@card[.@i] = getequipcardid(EQI_SHOES,.@i);
		.@check[.@i] = .@card[.@i];
	}
	if(!.@card[3]){
		mes "[ Dark Magic Master ]";
		mes "This equipment doesn't have any enchant in it.";
		end;
	}
	.@enchant = (.@card[2] > 0 ? 2 : (.@card[3] > 0 ? 1 : 0));
	mes "[ Dark Magic Master ]";
	if(.@enchant == 1)
		mes "One enchant has been detected.";
	else
		mes "More then one enchant has been detected.";
	mes "Do you want to proceed with the initialization?";
	next;
	switch(select("Cancel","Enchant with spell and fragment","Enchant with " + getitemname(.@dimension_essence))){
		case 1:
			mes "[ Dark Magic Master ]";
			mes "Okay, come back when you are ready.";
			close;
				
		case 2:
			setarray .@requirement,
			.@polluted_id,3,
			.@temporal_fragment,10;
			.@success_chance = 70;
			break;
			
		case 3:
			setarray .@requirement,
			.@dimension_essence,1;
			.@success_chance = 100;
			break;
	}
	mes "[ Dark Magic Master ]";
	for(.@i = 0; .@i < getarraysize(.@requirement); .@i += 2)
		mes .@requirement[.@i+1] + " [<ITEM>" + getitemname(.@requirement[.@i]) + "<INFO>" + .@requirement[.@i] + "</INFO></ITEM>]";
	mes "The success chance of the initialization is " + .@success_chance + "%";
	mes "The equipment will be destroyed if the initialization failed. Please take that in mind.";
	next;
	if(select("Cancel:Initialize Enchant") == 1){
		mes "[ Dark Magic Master ]";
		mes "Okay, come back when you are ready.";
		close;
	}
	for(.@i = 0; .@i < getarraysize(.@requirement); .@i += 2){
		if(countitem(.@requirement[.@i]) < .@requirement[.@i+1]){
			mes "[ Dark Magic Master ]";
			mes "You don't have enough materials to proceed with the initialization.";
			end;
		}
	}
	for(.@i = 0; .@i < getarraysize(.@requirement); .@i += 2)
		delitem .@requirement[.@i],.@requirement[.@i+1];
	if(callfunc("F_IsEquipIDHack", EQI_SHOES, .@equip_id) || callfunc("F_IsEquipCardHack", EQI_SHOES, .@check[0], .@check[1], .@check[2], .@check[3]) || callfunc("F_IsEquipRefineHack", EQI_SHOES, .@equip_refine))
		close;
	if(rand(1,100) <= .@success_chance){
		delequip EQI_SHOES;
		specialeffect2 EF_REPAIRWEAPON;
		mes "[ Dark Magic Master ]";
		mes "Your Temporal Boots has been successfully initialized.";
		getitem2 .@equip_id,1,1,.@equip_refine,0,.@card[0],.@card[1],0,0;
	} else {
		delequip EQI_SHOES;
		specialeffect2 EF_LORD;
		mes "[ Dark Magic Master ]";
		mes "Ugh, I failed. Your equipment was destroyed in the process. Better luck next time.";
	}
	end;
}

}