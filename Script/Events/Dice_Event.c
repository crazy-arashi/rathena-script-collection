//===== rAthena Script ===========================================|
//= Dice Event ( crazyarashi version )			     		 	 =|
//===== By: ======================================================|
//= crazyarashi													 =|
//===== Current Version: =========================================|
//= 1.0 Initial Version											 =|
//================================================================|
//= Dice Event							 					 	 =|
//================================================================|
-	script	Dice_Event	-1,{
OnInit:
	$dice_active = 0;
	$dice_enter = 0;
	.dice_map$ = "quiz_01";
	.reward_id = 501;
	.reward_amount = 10;
	end;
	
OnHour00:
OnStart:
	function count_player;
	function dice_start;
	function roll_dice;
	function select_winner;
	function reward_winner;
	function check_player;
	announce "[ Dice Event ] : The Dice Event will start in 1 minute.",0;
	$dice_enter = 1;
	sleep 4000;
	announce "[ Dice Event ] : Use the @joinevent command to participate in the event.",0;
	sleep 4000;
	announce "[ Dice Event ] : The registration will close in 1 minute.",0;
	sleep 26000;
	announce "[ Dice Event ] : Use the @joinevent command to participate in the event.",0;
	sleep 4000;
	announce "[ Dice Event ] : The registration will close in 30 seconds.",0;
	sleep 30000;
	$dice_enter = 0;
	announce "[ Dice Event ] : The registration has closed.",0;
	count_player(.dice_map$);
	$dice_active = 1;
	dice_start();
	end;
	
function	dice_start	{
	sleep 3500;
	mapannounce .dice_map$,"[ Dice ] : The dice event rules are simple.",0;
	sleep 4000;
	mapannounce .dice_map$,"[ Dice ] : Pick a number from 1 to 4 and enter the box of the number you choose.",0;
	sleep 4000;
	mapannounce .dice_map$,"[ Dice ] : The players standing in the correct box will win "+.reward_amount+" "+getitemname(.reward_id)+".",0;
	sleep 4000;
	mapannounce .dice_map$,"[ Dice ] : Do not stand outside of the box, you will be automatically disqualified.",0;
	sleep 4000;
	mapannounce .dice_map$,"[ Dice ] : The dice roll will start in 10 seconds.",0;
	sleep 10000;
	mapannounce .dice_map$,"[ Dice ] : Rolling the dice.",0;
	.@dice = roll_dice();
	mapannounce .dice_map$,"[ Dice ] : I'll announce the winning number in 10 seconds, this is your last chance to select your winning number.",0;
	sleep 10000;
	mapannounce .dice_map$,"[ Dice ] : And the winning number is.",0;
	sleep 4000;
	mapannounce .dice_map$,"[ Dice ] : Winning Number : "+.@dice+".",0;
	sleep 1000;
	select_winner(.@dice);
	check_player(.dice_map$);
	sleep 4000;
	reward_winner(.@dice);
	sleep 5000;
	$dice_active = 0;
	$dice_enter = 0;
	mapwarp .dice_map$,"prontera",156,191; 
	end;
}

function	roll_dice	{
	count_player(.dice_map$);
	.@count = rand(1,4);
	return .@count;
}

function	check_player	{
	if(getmapusers(getarg(0)) == 0){
		announce "[ Dice Event ] : The Dice Event has ended with no winner. Better luck next time!",0;
		$dice_active = 0;
		$dice_enter = 0;
		end;
	}
return;
}

function	count_player	{
	if(getmapusers(getarg(0)) == 0){
		announce "[ Dice Event ] : The event has been cancelled due to lack of registration.",0;
		$dice_active = 0;
		$dice_enter = 0;
		end;
	}
	return;
}

function	reward_winner	{
.@box = getarg(0);
	switch(.@box){
		case 1:
			getareaunits(BL_PC,.dice_map$,183,81,191,60,.@player_id$[0]);
			break;
			
		case 2:
			getareaunits(BL_PC,.dice_map$,195,81,203,60,.@player_id$[0]);
			break;
			
		case 3:
			getareaunits(BL_PC,.dice_map$,207,81,215,60,.@player_id$[0]);
			break;
			
		case 4:
			getareaunits(BL_PC,.dice_map$,219,81,227,60,.@player_id$[0]);
			break;
	}
	.@size = getarraysize(.@player_id$);
	if(.@size == 1){
		.@word$ = "winner";
	} else {
		.@word$ = "winners";
	}
	announce "[ Dice Event ] : The Dice Event has ended with "+.@size+" "+.@word$+". Thank you for participating.",0;
	for(.@i = 0; .@i < .@size; .@i++){
		.@char_id = getcharid(0,.@player_id$[.@i]);
		.@account_id = getcharid(3,.@player_id$[.@i]);
		if(isloggedin(.@account_id,.@char_id)){
			getitem .reward_id,.reward_amount,.@account_id;
			warp "SavePoint",0,0,.@char_id;
		} else {
			continue;
		}
	}
return;
}

function	select_winner	{
.@winner = getarg(0);
	switch(.@winner){
		case 1:
			areawarp .dice_map$,195,81,203,60,"prontera",156,191;
			areawarp .dice_map$,207,81,215,60,"prontera",156,191;
			areawarp .dice_map$,219,81,227,60,"prontera",156,191;
			break;                            
			                                  
		case 2:                               
			areawarp .dice_map$,183,81,191,60,"prontera",156,191;
			areawarp .dice_map$,207,81,215,60,"prontera",156,191;
			areawarp .dice_map$,219,81,227,60,"prontera",156,191;
			break;                           
			                                  
		case 3:                               
			areawarp .dice_map$,183,81,191,60,"prontera",156,191;
			areawarp .dice_map$,195,81,203,60,"prontera",156,191;
			areawarp .dice_map$,219,81,227,60,"prontera",156,191;
			break;                            
			                                  
		case 4:                               
			areawarp .dice_map$,183,81,191,60,"prontera",156,191;
			areawarp .dice_map$,195,81,203,60,"prontera",156,191;
			areawarp .dice_map$,207,81,215,60,"prontera",156,191;
			break;
		}
	}
}

quiz_01	mapflag	nowarp
quiz_01	mapflag	nowarpto
quiz_01	mapflag	noteleport
quiz_01	mapflag	nosave
quiz_01	mapflag	nomemo
quiz_01	mapflag	nobranch
quiz_01	mapflag	noloot
quiz_01	mapflag	noskill
quiz_01	mapflag	nopenalty
quiz_01	mapflag	nodrop