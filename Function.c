/* Function to change get a variable value from another NPC
** getnpc_var("<Variable Name>",{,<NPC NAME>});

-- Use Cases
.@value = getnpc_var("target_var","npc_name");
.@value$ = getnpc_var("target_var$","npc_name");
.@value$ = getnpc_var("target_var$[2]","npc_name");
.@size = getarraysize(getnpcvar("target_array","npc_name"));
*/

function	script	getnpc_var	{
	return getvariableofnpc(getd((compare(getarg(0),".")?"":".") + getarg(0)),getarg(1,strnpcinfo(3)));
}

/* Function to change a variable/array from another NPC
** setnpc_var("<Variable Name>",<New Value>,{,<NPC NAME>});

-- Use Cases
setnpc_var("target_var",10,"npc_name");
setnpc_var("target_var$","HELLO","npc_name");
setnpc_var("target_var$[2]","Change Array Value 2","npc_name");
*/

function	script	setnpc_var	{
	set getvariableofnpc(getd((compare(getarg(0),".")?"":".") + getarg(0)),getarg(2,strnpcinfo(3))),getarg(1);
	return;
}

/* Function to copy an array from another NPC
** getnpc_array("<Target Array Variable>",<Temporary Array Variable>{,<"NPC Name">});

-- Use Cases
.@array_size = getnpc_array(".target_array",.@temp_array,"npc_name");

- Target array data type should be the same
- returns the array size
*/

function	script	getnpc_array	{
	.@type$ = (compare(getarg(0),"$") ? "$" : "");
	copyarray getd(".@temp_array" + .@type$ + "[0]"),getnpc_var(getarg(0),getarg(2,strnpcinfo(3))),getarraysize(getnpc_var(getarg(0),getarg(2,strnpcinfo(3))));
	.@size = getarraysize(getd(".@temp_array" + .@type$));
	if(.@size < 1){
		debugmes "getnpc_array : The target array " + getarg(0) + " is empty."; 
		return 0;
	}
	for(.@i = 0; .@i < .@size; .@i++)
		set getelementofarray(getarg(1),.@i),getd(".@temp_array" + .@type$ + "[" + .@i + "]");
	return .@size;
}

/* Search the index of a value in from another NPC Variable
** getnpc_arrindex("<Target Array Variable>",<Search Value>{,<"NPC Name">});

-- Use Cases
.@index = getnpc_arrindex(".target_array",7,"npc_name");
*/

function	script	getnpc_arrindex	{
	return inarray(getnpc_var(getarg(0),getarg(2,strnpcinfo(3))),getarg(1));
}

/* Instance commands shorcuts
instance_hide(<NPC Name>,<Bool>);
instance_enable(<NPC Name>,<Bool>);
instance_event(<NPC Name>,<Event Name>,<Attach Player Bool>);
*/

function	script	instance_hide	{
	if(getarg(1))
		hideonnpc instance_npcname(getarg(0));
	else
		hideoffnpc instance_npcname(getarg(0));
	return;
}

function	script	instance_enable	{
	if(getarg(1))
		enablenpc instance_npcname(getarg(0));
	else
		disablenpc instance_npcname(getarg(0));
	return;
}

function	script	instance_event	{
	if(getarg(2))
		doevent instance_npcname(getarg(0)) + "::" + getarg(1);
	else
		donpcevent instance_npcname(getarg(0)) + "::" + getarg(1);
	return;
}

// Shorcut/Personal preference functions

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

function	script	pctalk	{
	unittalk getcharid(3),strcharinfo(0) + ":" + getarg(0),bc_self;
	return;
}

function	script	pcblock	{
	setpcblock PCBLOCK_NPC,getarg(0);
	return;
}

//= Cloaked Dummy NPC
-	script	dummynpc	-1,{
	end;
	
OnInit:
	cloakonnpcself;
end;
}

//= Normal Dummy NPC
-	script	dummynpc2	-1,{ 
	end; 
}

//= Disabled Dummy NPC in Instance
-	script	instancedummynpc	-1,{ 
	end;
	
OnInstanceInit: 
	instance_enable(strnpcinfo(0),false); 
end; 
}