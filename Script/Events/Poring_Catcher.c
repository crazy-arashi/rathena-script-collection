//===== rAthena Script ===========================================|
//= Poring Catcher ( crazyarashi version )			 =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|
//= Poring Catcher                                               =|
//================================================================|
-	script	Poring_Catcher	-1,{	
OnInit:
	$poring_active = 0;
	$poring_enter = 0;
	$poring_kill = 0;
	.poring_map$ = "novice";
	.poring_multiplier = 2; //= Multiply Poring Per 2 Player. 4 Player = 2 Correct Poring.
	.reward_id = 501;
	.reward_amount = 1;
	end;

OnHour00:
OnStart:
	function count_player;
	function poring_start;
	function get_count;
	killmonster "novice","All";
	announce "[ Poring Catcher ] : Poring Catcher Event will start in 1 minute.",0;
	$poring_enter = 1;
	sleep 4000;
	announce "[ Poring Catcher ] : Use the @joinevent command to participate in the event.",0;
	sleep 4000;
	announce "[ Poring Catcher ] : The registration will close in 1 minute.",0;
	sleep 26000;
	announce "[ Poring Catcher ] : Use the @joinevent command to participate in the event.",0;
	sleep 4000;
	announce "[ Poring Catcher ] : The registration will close in 30 seconds..",0;
	sleep 30000;
	$poring_enter = 0;
	announce "[ Poring Catcher ] : The registration has closed.",0;
	count_player(.poring_map$);
	$poring_active = 1;
	.@poring_count = get_count(.poring_map$);
	$poring_kill = .@poring_count;
	poring_start(.@poring_count);
	end;

OnSummonPoring:
	function anti_error;
	monster .poring_map$,0,0,"Pouring",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"Porong",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"Poringu",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"Pourinq",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"Porinq",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"Por1ng",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"P0ring",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"P@ring",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"POring",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"Puring",1002,10,strnpcinfo(0)+"::OnWrongPoring";
	monster .poring_map$,0,0,"Poring",1002,$poring_kill,strnpcinfo(0)+"::OnRightPoring";
	do {
		sleep 3000;
		anti_error(1);
	}while($poring_active != 0);
	end;
	  
OnWrongPoring:
	mapannounce .poring_map$,"[ Poring Catcher ] : Woooops. "+strcharinfo(0)+" has killed a wrong Poring.",0;
	warp "SavePoint",0,0;	
	sleep 2000;
	anti_error(2);
	end;
	
OnRightPoring:
	warp "SavePoint",0,0;
	getitem .reward_id,.reward_amount;
	announce "[ Poring Catcher ] : "+strcharinfo(0)+" has won "+.reward_amount+" "+getitemname(.reward_id)+" for killing the right Poring.",0;
	$poring_kill -= 1;
	if($poring_kill == 0){
		announce "[ Poring Catcher ] : The Poring Catcher Event has now ended. Thank you for participating.",0;
		$poring_active = 0;
		$poring_kill = 0;
		$poring_enter = 0;
		mapwarp "novice","prontera",156,191;
		killmonster "novice","All";
		end;
	}
	anti_error(3);
	mapannounce .poring_map$,"[ Poring Catcher ] : Correct Poring left : "+$poring_kill+".",0;
	end;
	
function	anti_error	{
.@i = getarg(0);
switch(.@i){
	case 1:
		if($poring_active == 0) end;
		if(getmapusers(.poring_map$) == 0){
			announce "[ Poring Catcher ] : All participants have been eliminated. There is no winner in this event.",0;
			$poring_active = 0;
			$poring_kill = 0;
			$poring_enter = 0;
			mapwarp "novice","prontera",156,191;
			killmonster "novice","All";
			end;
		}
		return;
	case 2:
		if($poring_active == 0) end;
		if(getmapusers(.poring_map$) == 0){
			announce "[ Poring Catcher ] : All participants have been eliminated. There is no winner in this event.",0;
			$poring_active = 0;
			$poring_kill = 0;
			$poring_enter = 0;
			mapwarp "novice","prontera",156,191;
			killmonster "novice","All";
			end;
		}
		return;
		
	case 3:
		if(getmapusers(.poring_map$) == 0){
			announce "[ Poring Catcher ] : The Poring Catcher Event has now ended. Thank you for participating.",0;
			$poring_active = 0;
			$poring_kill = 0;
			$poring_enter = 0;
			mapwarp "novice","prontera",156,191;
			killmonster "novice","All";
			end;
		}
		return;
	}
}

function	count_player	{
	if(getmapusers(getarg(0)) == 0){
		announce "[ Poring Catcher ] : The event has been cancelled due to lack of registration.",0;
		end;
	}
	return;
}

function	get_count	{
	.@count = getmapusers(getarg(0));
	if(.@count <= 4){
		return 1;
	}
	.@count_poring = (.@count/.poring_multiplier);
	return .@count_poring;
}

function	poring_start	{
	sleep 3500;
	mapannounce .poring_map$,"[ Poring Catcher ] : The event rules are simple.",0;
	sleep 3500;
	mapannounce .poring_map$,"[ Poring Catcher ] : There will be 100 wrong Poring and "+getarg(0)+" correct Poring.",0;
	sleep 3500;
	mapannounce .poring_map$,"[ Poring Catcher ] : Kill the correct Poring to win "+.reward_amount+" "+getitemname(.reward_id)+".",0;
	sleep 3500;
	mapannounce .poring_map$,"[ Poring Catcher ] : If the Poring is not killed in 3 minutes the event will finish without a winner.",0;
	sleep 3500;
	mapannounce .poring_map$,"[ Poring Catcher ] : The event will start in a few seconds.",0;
	sleep 2000;
	mapannounce .poring_map$,"[ Poring Catcher ] : 3.",0;
	sleep 2000;
	mapannounce .poring_map$,"[ Poring Catcher ] : 2.",0;
	sleep 2000;
	mapannounce .poring_map$,"[ Poring Catcher ] : 1.",0;
	donpcevent strnpcinfo(0)+"::OnSummonPoring";
	end;
	}
}

novice	mapflag	nowarp
novice	mapflag	nowarpto
novice	mapflag	noteleport
novice	mapflag	nosave
novice	mapflag	nomemo
novice	mapflag	nobranch
novice	mapflag	noloot
novice	mapflag	noskill
novice	mapflag	nopenalty
novice	mapflag	nodrop
