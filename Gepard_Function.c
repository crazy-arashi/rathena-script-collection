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
	return (.@total == 0 ? UID_NO_CONCURRENT : .@total);
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
				array_push(getd(.@var$), .@uid);
				array_push(getd(.@var$), .@aid);
				array_push(getd(.@var$), .@cid);
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