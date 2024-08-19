//= instance_warning(<TYPE>);
function	script	instance_warning	{
	.@type = (getargcount() < 1 ? 0 : getarg(0));
	switch(.@type){
		case 0: 
			mes "^FF0000Please note that, any abnormal monster handling inside the instance such as taming is not considered normal and may hinder the instance progress.^000000"; 
			break;
			
		case 1:
			mes "^4D4DFFThis place is a memorial dungeon.";
			mes "Please form a party and try again.^000000";
			mes "To create a party with the following command ^4D4DFF'/organize PARTY NAME'.^000000";
			end;
			
		case 2:
			.@md_name$ = getarg(1);
			dispbottom "The reservation of the instance '" + .@md_name$ + "' has failed due to an active instance.";
			break;
			
		case 3:
			mes "^FF0000In beginners mode, the player transform into a monster. Please not that existing transformation effect will disappear after entering and proceeding.^000000"; 
			break;
			
		case 4:
			mes "^4D4DFFThis place is a memorial dungeon.";
			mes "You have to be a party leader to create a memorial dungeon.^000000";
			end;
	}
	return;
}

//= instance_hide(<NPC NAME>,<BOOL>);
function	script	instance_hide	{
	if(getarg(1))
		hideonnpc instance_npcname(getarg(0));
	else
		hideoffnpc instance_npcname(getarg(0));
	return;
}

//= instance_enable(<NPC NAME>,<BOOL>);
function	script	instance_enable	{
	if(getarg(1))
		enablenpc instance_npcname(getarg(0));
	else
		disablenpc instance_npcname(getarg(0));
	return;
}

//= instance_disable(<NPC NAME>);
function	script	instance_disable	{
	hideoffnpc instance_npcname(getarg(0));
	disablenpc instance_npcname(getarg(0));
	return;
}

//= instance_event(<NPC NAME>,<EVENT NAME>,<BOOL>);
function	script	instance_event	{
	if(getarg(2))
		doevent instance_npcname(getarg(0)) + "::" + getarg(1);
	else
		donpcevent instance_npcname(getarg(0)) + "::" + getarg(1);
	return;
}

//= get_instance_var(<VAR>);
function	script	get_instance_var	{
	return getd("'" + getarg(0));
}

//= set_instance_var(<VAR>,<VALUE>);
function	script	set_instance_var	{
	setd("'" + getarg(0),getarg(1));
	return;
}

//= cloaknpc("<NPC NAME>",<BOOL>{,<CHAR ID>});
function	script	cloaknpc	{
	if(getargcount() > 2){
		if(getarg(1))
			cloakonnpc getarg(0),getarg(2);
		else
			cloakoffnpc getarg(0),getarg(2);
	} else {
		if(getarg(1))
			cloakonnpc getarg(0);
		else
			cloakoffnpc getarg(0);
	}
	return;
}

//= Dummy NPC's
-	script	dummynpc	HIDDEN_WARP_NPC,{
	end;
	
OnInit:
	cloakonnpc;
end;
}

-	script	dummynpc2	HIDDEN_WARP_NPC,{ 
	end; 
}