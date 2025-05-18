//===== rAthena Script ===========================================|
//= Body Changer                                                 =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

-	script	suit_changer_core	-1,{
	end;
	
OnItemExist:
	if ( !countitem(.item_id) ) {
		baselook = 0;
		changelook LOOK_BODY2,Class;
		end;
	}
	addtimer 30000,"suit_changer_core::OnItemExist";
end;

OnPCLoginEvent:
	if ( baselook > 0 && countitem(.item_id) ) {
		changelook LOOK_BODY2,baselook;
		addtimer 30000,"suit_changer_core::OnItemExist";
	}
end;
	
OnInit:
	setarray .expanded_class, JOB_GUNSLINGER, JOB_NINJA, JOB_SUPERNOVICE, JOB_SUPER_NOVICE_E, JOB_STAR_GLADIATOR, JOB_SOUL_LINKER;
	.item_id = 501;
end;
}

function	script	F_Suit_Changer	{
	.@eac = eaclass();
	
	if ( Class == JOB_NOVICE ) {
		mes "^DC143C[ Suit Changer ]^000000";
		mes "Novice character can't use this item to change appearance!";
		close;
	}
	if ( Class == JOB_SUMMONER ) {
		mes "^DC143C[ Suit Changer ]^000000";
		mes "Dorams can't use this item to change appearance!";
		close;
	}
	
	.@expanded = ( getnpc_arrindex(".expanded_class", Class, "suit_changer_core") != - 1 );
	if ( !.@expanded )
		.@menu$ += "Original Class:Third Class(kRO):Third Class(jRO):Fourth Class";
	else
		.@menu$ += "::::Original Class:Expanded Third Class:Expanded Fourth Class";
	
	switch ( select( .@menu$ ) ) {
		case 1:
		case 5:
			deltimer "suit_changer_core::OnItemExist";
			changelook LOOK_BODY2,Class;
			baselook = 0;
			end;
			
		case 2: 
			.@value = roclass(.@eac | EAJL_THIRD); 
			break;
			
		case 3: 
			.@value = roclass(.@eac | EAJL_THIRD);
			switch ( .@value ) {
				case 4054: case 4060: .@body = 1; break;
				case 4058: case 4064: .@body = 2; break;
				case 4059: case 4065: .@body = 3; break;
				case 4055: case 4061: .@body = 4; break;
				case 4057: case 4063: .@body = 5; break;
				case 4056: case 4062: .@body = 6; break;
				case 4066: case 4073: .@body = 7; break;
				case 4071: case 4078: .@body = 8; break;
				case 4072: case 4079: .@body = 9; break;
				case 4067: case 4074: .@body = 10; break;
				case 4070: case 4077: .@body = 11; break;
				case 4068: case 4075: .@body = 12; break;
				case 4069: case 4076: .@body = 13; break;
			}
			.@value = 4331 + .@body;
			break;
			
		case 4:
			.@value = roclass( .@eac|EAJL_UPPER|EAJL_THIRD|EAJL_FOURTH );
			break;

		case 6:
			if ( Class == JOB_GUNSLINGER || Class == JOB_NINJA )
				.@value = roclass(.@eac|EAJL_2_1);
			else
				.@value = roclass(.@eac|EAJL_THIRD);
			break;
			
		case 7:
			if ( Class == JOB_GUNSLINGER || Class == JOB_NINJA )
				.@value = roclass( .@eac|EAJL_2_1|EAJL_UPPER|EAJL_THIRD|EAJL_FOURTH );
			else
				.@value = roclass( .@eac|EAJL_UPPER|EAJL_THIRD|EAJL_FOURTH );
			break;	
	}
	changelook LOOK_BODY2,.@value;
	baselook = .@value;
	deltimer "suit_changer_core::OnItemExist";
	addtimer 30000,"suit_changer_core::OnItemExist";
	end;
}