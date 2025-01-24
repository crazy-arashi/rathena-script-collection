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

function	script	array_push	{
	set getelementofarray(getarg(0),(.@size = getarraysize(getarg(0)))), getarg(1);
	return .@size;
}

/* Functions for storing/fetching multiple array of data without using unreadable getd
** SprintVar("<Base Array Variable>",<Value>{,<"NPC Name">};
** SprintIndex"<Base Array Variable>",<Value>,<Index>{,<"NPC Name">};

-- Use Cases
set SprintVar(".var", 1), 20;
Equivalent : .var_1 = 20;
.@value = SprintVar(".var", 1); //Returns 20

set SprintVar(".name$, 1), "Hello";
Equivalent : .name_1$ = "Hello";
.@value$ = SprintVar(".name$, 1); //Returns Hello

//= Usage with array_push function
array_push(SprintVar(".var", 1), 30);
.@index_0 = SprintIndex(".var", 1, 0); //Returns 20
.@index_1 = SprintIndex(".var", 1, 1); //Returns 30

//= Usage with getarraysize
.@size = getarraysize(SprintVar(".var", 1)); // Returns 2
*/

function	script	SprintVar	{
    return getvariableofnpc(getd(sprintf((compare(getarg(0), "$") ? (delchar(getarg(0), getstrlen(getarg(0)) - 1) + "_%d$") : (getarg(0) + "_%d")), getarg(1))), getarg(2,strnpcinfo(3)));
}

function	script	SprintIndex	{
    return getvariableofnpc(getd(sprintf((compare(getarg(0), "$") ? (delchar(getarg(0), getstrlen(getarg(0)) - 1) + "_%d$[%d]") : (getarg(0) + "_%d[%d]")), getarg(1), getarg(2))), getarg(3,strnpcinfo(3)));
}

/* Instance commands shorcuts
instance_warning(<TYPE>);
instance_hide(<NPC Name>,<Bool>);
instance_enable(<NPC Name>,<Bool>);
instance_event(<NPC Name>,<Event Name>,<Attach Player Bool>);
*/

function	script	instance_warning	{
	.@type = (getargcount() < 1 ? 0 : getarg(0));
	.@md_name$ = (getargcount() == 2 ? getarg(1,"") : "");
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

function	script	get_instance_var	{
	return getd("'" + getarg(0));
}

function	script	set_instance_var	{
	setd("'" + getarg(0),getarg(1));
	return;
}

function	script	inc_instance_var	{
	setd("'" + getarg(0), getd("'" + getarg(0)) + 1);
	return;
}

//= Shortcut Functions
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
	if(getargcount() < 2)
		setpcblock PCBLOCK_NPC,getarg(0);
	else
		setpcblock PCBLOCK_NPC,getarg(0),getarg(1);
	return;
}

/* Search the index of a value in from another NPC Variable
** npc_resize(<SIZE>);
Sizes :
Size_Small
Size_Medium
Size_Large

-- Use Cases
OnInit:
OnInstanceInit:
	npc_resize(Size_Large);
*/

function	script	npc_resize	{
	.@npc$ = .@name$ = strnpcinfo(0);
	if(instance_live_info(ILI_NAME) != "")
		.@npc$ = instance_npcname(.@npc$);
	getunitdata getnpcid(0,.@npc$),.@npc;
	setnpcdisplay(.@npc$,.@name$,.@npc[UNPC_CLASS],getarg(0));
	return;
}

function	script	mapexists	{
	return getmapusers(getarg(0));
}

function	script	create_menu	{
	return implode(getarg(0),":");
}

function	script	getday	{
	switch(getarg(0)) {
		case SUNDAY: .@d$ = "Sunday"; break;
		case MONDAY: .@d$ = "Monday"; break;
		case TUESDAY: .@d$ = "Tuesday"; break;
		case WEDNESDAY: .@d$ = "Wednesday"; break;
		case THURSDAY: .@d$ = "Thursday"; break;
		case FRIDAY: .@d$ = "Friday"; break;
		case SATURDAY: .@d$ = "Saturday"; break;
	}
	return .@d$;
}

/*
GEPARD FUNCTION
** get_concurrent_uid({<ACCOUNT ID>});
** get_concurrent_uid_map({<ACCOUNT ID>,<MAP NAME>})

const values:
UID_NULL = -1
UID_NO_CONCURRENT = 0
*/

function	script	concurrent_uid	{
	if((.@c = getargcount()))
		query_sql("SELECT `last_unique_id` FROM `login` WHERE `account_id` = '" + getarg(0) + "'", .@uid);
	else {
		if(!playerattached()){
			errormes "get_concurrent_uid : There's no RID attached to the function. Source NPC: " + strnpcinfo(3);
			end;
		}
		.@uid = get_unique_id();
	}
	if(!.@uid){
		errormes "get_concurrent_uid : There's no UID input from the AID : '" + (.@c ? getarg(0) : getcharid(3)) + "'. Source NPC: " + strnpcinfo(3);
		return UID_NULL;
	}
	if ((.@size = query_sql("SELECT `account_id` FROM `login` WHERE `last_unique_id` = '" + .@uid + "'", .@aid)) == 1)
		return UID_NO_CONCURRENT;
	for(.@i = 0; .@i < .@size; ++.@i)
		.@total += query_sql("SELECT `char_id` FROM `char` WHERE `account_id` = '" + .@aid[.@i] + "' AND `online` = 1");
	return (.@total == 1 ? UID_NO_CONCURRENT : .@total);
}

function	script	concurrent_uid_map	{
	if(getargcount()){
		.@aid = getarg(0);
		if(getargcount() > 1)
			.@map$ = getarg(1);
		else {
			if(!(.@cid = convertpcinfo(.@aid,CPC_CHAR))){
				errormes "concurrent_uid_map : The provded AID doesn't exist or not online.";
				end;
			}
			.@map$ = strcharinfo(3,.@cid);
			query_sql("SELECT `last_unique_id` FROM `login` WHERE `account_id` = '" + .@aid + "'", .@uid);
		}
	} else {
		if(!playerattached()){
			errormes "get_concurrent_uid : There's no RID attached to the function. Source NPC: " + strnpcinfo(3);
			end;
		}
		.@aid = getcharid(3);
		.@map$ = strcharinfo(3);
		.@uid = get_unique_id();
	}
	if(!.@uid){
		errormes "get_concurrent_uid : There's no UID input from the AID : '" + .@aid + "'. Source NPC: " + strnpcinfo(3);
		return UID_NULL;
	}
	if(mapexists(.@map$) == MAP_NULL){
		errormes "get_concurrent_uid : The map '" + .@map$ + " doesn't exist. Source NPC: " + strnpcinfo(3);
		end;
	}
	if ((.@size = query_sql("SELECT `account_id` FROM `login` WHERE `last_unique_id` = '" + .@uid + "'", .@aid)) == 1)
		return UID_NO_CONCURRENT;
	for(.@i = 0; .@i < .@size; ++.@i){
		query_sql("SELECT `char_id` FROM `char` WHERE `account_id` = '" + .@aid[.@i] + "' AND `online` = 1",.@cid);
		if(!.@cid) continue;
		getmapxy(.@m$,.@x,.@y,BL_PC,strcharinfo(0,.@cid));
		if(.@map$ == .@m$)
			.@total++;
	}
	return (.@total == 1 ? UID_NO_CONCURRENT : .@total);
}

function	script	concurrent_uid_registration	{
	if ( (.@npc$ = strnpcinfo(3)) == "" ) {
		errormes "concurrent_uid_registration: This function is only for NPC. Source NPC: " + strnpcinfo(3);
		end;
	}
	if ( (.@c = getargcount()) < 2 ) {
		errormes "concurrent_uid_registration : Missing necessary arguments for UID registration.";
		return UID_NULL;
	}
	if ( getargcount() > 3 ) {
		.@aid = getarg(3);
		query_sql("SELECT `last_unique_id` FROM `login` WHERE `account_id` = '" + .@aid + "'", .@uid);
		query_sql("SELECT `char_id` FROM `char` WHERE `account_id` = '" + .@aid + "' AND `online` = 1",.@cid);
	} else {
		if( !playerattached() ) {
			errormes "concurrent_uid_registration : There's no RID attached to the function. Source NPC: " + strnpcinfo(3);
			end;
		}
		.@aid = getcharid(3);
		.@uid = get_unique_id();
		.@cid = getcharid(0);
	}
	if ( !.@uid ) {
		errormes "concurrent_uid_registration : There's no UID input from the AID : '" + (.@c > 3 ? getarg(3) : getcharid(3)) + "'. Source NPC: " + strnpcinfo(3);
		return UID_NULL;
	}
	
	.@uid_count = countinarray(getd((.@var$ = "$" + .@npc$ + "_reg")), .@uid);
	.@vidx = inarray(getd(.@var$), .@aid);

	if ( getarg(0) == UID_REGISTER ) {
		if ( .@uid_count >= getarg(1) )
			return UID_EXCEED;
		if ( .@vidx != ARR_NULL ) {
			if ( getd(.@var$ + "[" + (.@vidx - 1) + "]") != .@uid )
				setd(getd(.@var$ + "[" + (.@vidx - 1) + "]"), .@uid);
			if ( getarg(2) == BOUND_CHAR ) {
				if( getd(.@var$ + "[" + (.@vidx + 1) + "]") != .@cid )
					setd(getd(.@var$ + "[" + (.@vidx + 1) + "]"), .@cid);
			}
		} else {
			if ( (.@eidx = inarray(getd(.@var$), 1)) != ARR_NULL ) {
				setd(getd(.@var$ + "[" + (.@eidx) + "]"), .@uid);
				setd(getd(.@var$ + "[" + (.@eidx + 1) + "]"), .@aid);
				setd(getd(.@var$ + "[" + (.@eidx + 2) + "]"), .@cid);
			} else {
				.@size = getarraysize(getd(.@var$));
				array_pop(getd(.@var$), .@uid);
				array_pop(getd(.@var$), .@aid);
				array_pop(getd(.@var$), .@cid);
			}
		}
	} else if ( getarg(0) == UID_DELETE ) {
		if( .@vidx == ARR_NULL ) return UID_SUCCESS;
		setd(getd(.@var$ + "[" + (.@vidx - 1) + "]"), 1);
		setd(getd(.@var$ + "[" + (.@vidx) + "]"), 1);
		setd(getd(.@var$ + "[" + (.@vidx + 1) + "]"), 1);
	} else {
		errormes "concurrent_uid_registration : Unknown type. Source NPC: " + strnpcinfo(3);
		end;
	}
	return UID_SUCCESS;
}


//= DUMMY NPC's
-	script	dummynpc	-1,{
	end;
	
OnInit:
	cloakonnpc;
end;
}

-	script	dummynpc2	-1,{ 
	end; 
}

-	script	instancedummynpc	-1,{ 
	end;
	
OnInstanceInit: 
	instance_enable(strnpcinfo(0),false); 
end; 
}