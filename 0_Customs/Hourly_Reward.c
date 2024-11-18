-	script	hourly_reward	-1,{
OnInit:
	function Setting;
	function Init;
	function Point_Reward;
	function Item_Reward;
	Setting();
	Init();
	
	bindatcmd "hourly",strnpcinfo(0)+"::OnHourly";
end;

function	Setting	{
	freeloop(true);
	
	//================== HOURLY SETUP ==================//
	.mail = true; //= Send item rewards via mail
	.gepard = true; //= Enable gepard uid checks.
	.max_uid = 1; //= Max gepard UID to begin timer.
	.idle_time = 60; //= Time in seconds before timer stops.
	.persistent = true; //= Timer persist on logout.
	.fixed_reward = true; //= Player will only receive the set rewards once per day. Rewards will reset to 0 if set to false.
	.bound_type = BOUND_CHAR; //= Which timer is character bounded to, BOUND_CHAR or BOUND_ACCOUNT.
	.interval = 5; //= Interval in seconds in which the timer is checked. Value must be divisible by 60 or will be defaulted to 5
	
	//================== REWARD SETTING ================//
	//= Item_Reward(<HOUR>, <ITEM ID>, <ITEM AMOUNT>{, <ITEM ID>, <ITEM AMOUNT>});
	//= Point_Reward(<HOUR>, <POINT VARIABLE>, <AMOUNT>);
	//==================================================//
	
	//= Hour 1
	Item_Reward(1, 501, 20);
	Item_Reward(1, 502, 5);
	Point_Reward(1, "Zeny", 1000000);
	Point_Reward(1, "#KAFRAPOINT", 10);
	
	//= Hour 3
	Item_Reward(3, 504, 20, 507, 3);
	Point_Reward(3, "Zeny", 3000000);
	Point_Reward(3, "#KAFRAPOINT", 20);
	
	//= Hour 7
	Item_Reward(7, 504, 20, 507, 3, 510, 20);
	Point_Reward(7, "#CASHPOINT", 10);
	
	freeloop(false);
}

OnPCLoginEvent:
	function update_timer;
	if ( !.gepard ) {
		update_timer(true);
		addtimer .check_interval, .tick$;
	} else {
		if ( concurrent_uid_registration(UID_REGISTER, .max_uid, .bound_type) == UID_EXIST ) {
			@error = true;
			dispbottom "[Hourly Rewards] : Online account exceeded. Please logout your other account or use disable the hourly on that account and start it on this account using @hourly.",0xFF6347;
		}
	}
end;

OnPCLogoutEvent:
	if ( !.persistent )
		setd(.var$, "");
end;

OnHourly:
	mes "[Hourly Rewards]";
	if ( @error ) {
		mes "Status : ^FF6347Disabled^000000";
		mes "Reason : ^0000CDOnline Account Exceeded^000000";
		next;
		if ( select("Enable Hourly.","Quit.") == 2 )
			end;
		if ( concurrent_uid_registration(UID_REGISTER, .bound_type) == UID_EXIST ) {
			mes "[Hourly Rewards]";
			mes "Failed to enable hourly as online account still exceeds the limit.";
			next;
			goto OnHourly;
		}
	}
	
end;

function	Init	{
	if ( 60 % .interval != 0 ) {
		debugmes "Hourly Rewards : interval value is not divisible by 60, defaulting to 5 seconds interval.";
		.interval = 5;
	}
	.check_interval = .interval * 1000;
	.tick$ = strnpcinfo(3) + "::OnTick";
	if ( .bound_type == BOUND_CHAR )
		.var$ = "hourly$";
	else if ( .bound_type == BOUND_ACCOUNT )
		.var$ = "#hourly$";
	else {
		debugmes "Hourly Rewards : bound_type value not supported defaulting to character bound.";
		.var$ = "hourly$";
	}
	return;
}

OnTick:
	function idle_check;
	if ( idle_check() && @idle == true ) {
		@idle == false
		dispbottom "[Hourly Rewards] : Your hourly timer has continued.",0xFF6347;
	}
	if ( (@hs += .interval) >= 60 ) {
		@hs = 0;
		if ( (.@hm += 1) > 60 ) {
			@hm = 0; @hh++;
			dispbottom "[Hourly Rewards] : You have been online for " + .@hh +  (@hh > 1 ? "hours" : "hour") + ".",0xFF6347;
			.@reward = true;
		}
		update_timer(false);
	}
	addtimer .check_interval, .tick$;
	if( .@reward == true ) {
		if( inarray(.hour, @hh) != -1 ) {
			function Hourly_Reward;
			Hourly_Reward(@hh);
		}
		.@reward = false;
	}
end;

function	idle_check	{
	function special_check;
	if( checkvending() || checkchatting() || checkidle() >= .idle_time || special_check() >= .idle_time ) {
		if ( @idle == false ) {
			@idle = true;
			dispbottom "[Hourly Rewards] : Idle detected. Your hourly timer has been paused.",0xFF6347;
			addtimer .check_interval, .tick$;
			end;
		}
	}
	return true;
}

function	special_check	{
	if ( (@ctarget = get_player_target()) == 0 ) 
		return 0;
	else {
		if ( @target == @ctarget )
			@target_tick += .interval;
		else {
			@target = @ctarget;
			@target_tick = 0;
		}
	}
	return @target_tick;
}

function	update_timer	{
	explode(@T$,getd(.var$),":");
	if ( .fixed_reward == true && ((.@cm = gettime(DT_MONTH)) != (.@tm = atoi(@T$[3])) || (.@cd = gettime(DT_DAYOFMONTH)) = (.@td = atoi(@T$[2]))) ) {
		if ( .@cm != .@tm ) @T$[3] = .@cm;
		if ( .@cd != .@td ) @T$[2] = .@cd;
		@T$[0] = 0;
		setd(getd(.var$), implode(@T$,":"));
	}
	if ( getarg(0) == false ) {
		@T$[0] = @hh;
		@T$[1] = @hm;
	} else {
		@hh = atoi(@T$[0]);
		@hm = atoi(@T$[1]);
	}
	setd(getd(.var$), implode(@T$,":"));
	return;
}

function	Hourly_Reward	{
	.@hour = getarg(0);
	if( (.@size = getarraysize(getd(".hour_" + .@hour + "_reward"))) ) {
		for ( .@i = 0, .@var$ = ".hour_" + .@hour + "_reward"; .@i < .@size; .@i += 2 ) {
			array_pop(.@item_id, getd(.@var$ + "[" + .@i + "]"));
			array_pop(.@item_amount, getd(.@var$ + "[" + (.@i + 1) + "]"));
		}
		if( !.mail ){
			if( checkweight2(.@item_id,.@item_amount) ){
				for( .@i = 0; .@i < .@size; ++.@i )
					getitem .@item_id[.@i],.@item_amount[.@i];
				dispbottom "[Hourly Rewards] : Hour " + getarg(0) + " rewards has been given.",0xFF6347;
			} else {
				dispbottom "[Hourly Rewards] : You don't have enough inventory space for your hourly rewards, it has been sent on your mail.",0xFF6347;
				@mail = true;
			}
		}
	}
	.@size = getarraysize(getd(".hour_" + .@hour + "_point"));
	if( .@size ) {
		for( .@i = 0, .@var$ = ".hour_" + .@hour + "_point"; .@i < .@size; .@i += 2 ) {
			.@point$ = getd(.@var$ + "[" + .@i + "]");
			.@amount = getd(.@var$ + "[" + .@i + "]");
			if(  == "Zeny" && .mail || @mail == true )
				.@zeny += getd(.@var$ + "[" + (.@i + 1) + "]");
			else {
				
				setd(getd(".hour_" + .@hour + "_point[" + .@i + "]"), getd(".hour_" + .@hour + "_point[" + .@i + "]") + getd(".hour_" + .@hour + "_point[" + (.@i + 1) + "]"));
				dispbottom "[Hourly Rewards] : You have been awarded " + getd(".hour_" + .@hour + "_point[" + (.@i + 1) + "]") +  " " + getd(".hour_" + .@hour + "_point[" + .@i + "]") + " for being online for " + .@hour + " " + (.@hour > 1 ? "hours.":"hour."),0xFF6347;
			}
		}
	}
	if( .mail || .@mail ){
		.@size = getarraysize(.@item_id);
		if( .@size > 5 ){
			.@times = .@size/5;
			for( .@x = 0; .@x < .@times; ++.@x ) {
				deletearray .@mail_id;
				deletearray .@mail_amount;
				for( .@i = .@x * 5; .@i < 5 * .@times; ++.@i ) {
					if( !.@item_id[.@i] )
						break;
					array_pop(.@mail_id, .@item_id[.@i]);
					array_pop(.@mail_amount, .@item_amount[.@i]);
				}
				mail getcharid(0),"Hourly Rewards","Hour " + getarg(0) + " Reward.","Here is your reward for being online for " + getarg(0) + " " + (getarg(0) > 1 ? "hours.":"hour."),.@zeny,.@mail_id,.@mail_amount;
				.@zeny = 0;
			}
		} else
			mail getcharid(0),"Hourly Rewards","Hour " + getarg(0) + " Reward.","Here is your reward for being online for " + getarg(0) + " " + (getarg(0) > 1 ? "hours.":"hour."),.@zeny,.@item_id,.@item_amount;
		.@zeny = 0;
	}
	return;
}

function	Item_Reward	{
	if( getargcount() < 3 ){
		errormes "Item_Reward : the reward for hour " + getarg(0) + " needs to have atleast 3 arguments, skipping rewards.";
		return;
	}
	if ( getarg(0) == 0 || getarg(0) > 23 ) {
		errormes "Item_Reward :  The hour provided is either 0 or greater than 23. Skipping rewards.";
		return;
	}
	if( inarray(.hour, getarg(0)) == ARR_NULL )
		.hour[getarraysize(.hour)] = getarg(0);
	for( .@i = 1; .@i < getargcount(); .@i++ )
		setd(".hour_" + getarg(0) + "_reward[" + getarraysize(getd(".hour_" + getarg(0) + "_reward")) + "]", getarg(.@i));
	return;
}

function	Point_Reward	{
	if( getargcount() < 3 || getargcount() > 3 ){
		errormes "Point_Reward : the point reward for hour " + getarg(0) + " has less than 3 or greater than 3 arguments.";
		return;
	}
	if ( getarg(0) == 0 || getarg(0) > 23 ) {
		errormes "Point_Reward :  The hour provided is either 0 or greater than 23. Skipping rewards.";
		return;
	}
	if( inarray(.hour, getarg(0)) == ARR_NULL )
		.hour[getarraysize(.hour)] = getarg(0);
	.@index = inarray(getd(".hour_" + getarg(0) + "_point$"), getarg(1));
	if( .@index != ARR_NULL )
		setd(".hour_" + getarg(0) + "_point[" + (.@index + 1) + "]", getd(".hour_" + getarg(0) + "_point[" + (.@index + 1) + "]") + getarg(2));
	else {
		setd(".hour_" + getarg(0) + "_point$[" + getarraysize(getd(".hour_" + getarg(0) + "_point$")) + "]", getarg(1));
		setd(".hour_" + getarg(0) + "_point[" + getarraysize(getd(".hour_" + getarg(0) + "_point")) + "]", getarg(2));
	}
	return;
}

}