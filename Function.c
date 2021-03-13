//= getnpc_var("<VAR NAME>"{,<NPC NAME>});
function	script	getnpc_var	{
	return getvariableofnpc(getd((compare(getarg(0),".")?"":".") + getarg(0)),getarg(1,strnpcinfo(3)));
}

//= setnpc_var("<ARRAY NAME>"{,<NPC NAME>});
function	script	setnpc_var	{
	set getvariableofnpc(getd((compare(getarg(0),".")?"":".") + getarg(0)),getarg(2,strnpcinfo(3))),getarg(1);
	return;
}

//= getnpc_array("<ARRAY NAME>",<VAR NAME>{,<"NPC NAME">});
function	script	getnpc_array	{
	copyarray getd(".@temp_array" + (compare(getarg(0),"$")?"$":"") + "[0]"),getnpc_var(getarg(0),getarg(2,strnpcinfo(3))),getarraysize(getnpc_var(getarg(0),getarg(2,strnpcinfo(3))));
	for(.@i = 0; .@i < getarraysize(getd(".@temp_array" + (compare(getarg(0),"$")?"$":""))); .@i++)
		set getelementofarray(getarg(1),.@i),getd(".@temp_array" + (compare(getarg(0),"$")?"$":"") + "[" + .@i + "]");
	return;
}

//= getnpc_index("<ARRAY NAME>",<SEARCH VAR>{,<"NPC NAME">});
function	script	getnpc_arrindex	{
	return inarray(getnpc_var(getarg(0),getarg(2,strnpcinfo(3))),getarg(1));
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


//= getd_instance_var(<VAR>); (For non-instance NPC)
function	script	getd_instance_var	{
	return getvariableofinstance("'" + getarg(0), getarg(1));
}

//= setd_instance_var(<VAR>,<VALUE>); (For non-instance NPC)
function	script	setd_instance_var	{
	set getvariableofinstance("'" + getarg(0), getarg(2)), getarg(1);
	return;
}

//= instance_effect(<EFFECT ID>,<NPC>);
function	script	instance_effect	{
	specialeffect getarg(0),AREA,getarg(1);
	return;
}

//= Lazy version of cloakon/off
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

//= Duplicate for dummy cloaked npc
-	script	dummynpc	-1,{
	end;
	
OnInit:
	cloakonnpc strnpcinfo(0);
end;
}

//= Duplicate for dummy npc
-	script	dummynpc2	-1,{ 
	end; 
}

//= Duplicate for dummy npc in instances
-	script	instancedummynpc	-1,{ 
	end;
	
OnInstanceInit: 
	instance_enable(strnpcinfo(0),false); 
end; 
}