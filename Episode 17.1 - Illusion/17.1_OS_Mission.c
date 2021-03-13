//===== rAthena Script ===========================================|
//= Episode 17.1 OS Mission                                      =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

sp_cor,163,56,0	script	#171_EV_OS_MS	HIDDEN_WARP_NPC,10,10,{
	end;
	
OnTouch:
	if(checkquest(12452) != 2){
		cloaknpc("Erst#os_mission",false,getcharid(0));
		npctalk "We have to move quickly while we have the advantage.","Erst#os_mission",bc_self;
	} else if(checkquest(12452) == 2)
		cloaknpc("Operation Officer#os_mission",false,getcharid(0));
end;
}

sp_cor,163,56,3	script	Erst#os_mission	4_F_ESTLOVELOY,{
	switch(isbegin_quest(12452)){
		case 0:
			cutin "ep162_est01",2;
			mes "[ Erst ]";
			mes "Oh you're here. I heard that the recon team has taken control over the railroad.";
			next;
			select("Ask about the next operation.");
			mes "[ Erst ]";
			mes "I took control for now, but in a few hours they will be back. It would make the current operation useless.";
			next;
			mes "[ Erst ]";
			mes "We are going to carry out the battle of surrounding area to prevent a subsequent counterattack.";
			mes "Of course civilians will not be included.";
			next;
			select("Ask what you need to prepare.");
			mes "[ Erst ]";
			mes "We'll brief you after we enter the operational area. Bring only necessary items.";
			next;
			mes "[ Erst ]";
			mes "We have to hurry before they take back the railroad.";
			setquest 12452;
			close3;
			
		case 1:
			cutin "ep162_est01",2;
			mes "[ Erst ]";
			mes "Have you prepared all you needed?";
			next;
			.@md_name$ = "OS Mission";
			.@party_id = getcharid(1);
			if(!.@party_id){
				mes "[ Erst ]";
				mes "Are you alone? It's difficult if you're alone. Once you've made a party of one, talk to me again.";
				close3;
			}
			getpartymember .@party_id,3;
			if($@partymembercount != 1){
				mes "[ Erst ]";
				mes "Are you alone? It's difficult if you're alone. Once you've made a party of one, talk to me again.";
				close3;
			}
			.@party_name$ = getpartyname(.@party_id);
			switch(select("Generate OS Mission.:Enter OS Mission.:Quit")){
				case 1:
					switch(instance_create(.@md_name$,IM_PARTY)){
						case -1:
							mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
							mes "Unknown Error Has Occurred.";
							end;
						case -2:
							mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
							mes "Party Is Non-Existent.";
							end;
						case -3:
							mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
							mes "Player already have instance.";
							end;
							
						case -4:
							mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
							mes "^0000ff"+.@md_name$+" ^000000 is currently full.";
							end;
							
						default:
							mes "[ Erst ]";
							mes "The last checks are in place, let me know when you're ready to enter.";
							close3;
					}
				case 2:
					switch(instance_enter(.@md_name$)){
						case 3:
							mes "An unknown error has occurred.";
							end;
							
						case 2:
						case 1:
							mes "[ Erst ]";
							mes "^ff0000Character doesn't have an instance reserved.^000000";
							end;
							
						case 0:
							mapannounce "sp_cor", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00FF99";
							end;
					}	
				
				case 3:
					break;
			}
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,160,55,5	script	Operation Officer#os_mission	4_M_ILYA,{
	.@md_name$ = "OS Mission 2";
	.@party_id = getcharid(1);
	.@party_name$ = getpartyname(.@party_id);
	if(isbegin_quest(12454) == 0){
		mes "[ Operation Officer ]";
		mes "Even though the first operation was done by our squad, the mutants still continue to come out.";
		next;
		mes "[ Operation Officer ]";
		mes "If the facility is destroyed at the source, it will clear them out. But it won't be approved by the upper level, so we'll have to send a second search team instead.";
		setquest 12454;
	} else {
		mes "[ Operation Officer ]";
		mes "I hope the search is done safely.";
	}
	next;
	mes "[ Operation Officer ]";
	mes "Are you prepared?";
	next;
	switch(checkquest(12455,PLAYTIME)){
		case -1:
			break;
			
		case 0: 
		case 1:
			mes "[ Operation Officer ]";
			mes "I don't have time yet, let's take a break.";
			end;
			
		case 2:
			erasequest 12455;
			break;
	}
	if(!.@party_id){
		mes "[ Operation Officer ]";
		mes "You're going alone? It may be difficult. Once you've formed a party, come and talk to me again.";
		close;
	}
	switch(select("Prepare OS Mission 2.:Enter OS Mission 2.:Cancel")){
		case 1:
			switch(instance_create(.@md_name$,IM_PARTY)){
				case -1:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "Unknown Error Has Occurred.";
					end;
				case -2:
					mes "[ Operation Officer ]";
					mes "You're going alone? It may be difficult. Once you've formed a party, come and talk to me again.";
					close;
				case -3:
					mes "[ Operation Officer ]";
					mes "You already have an instance active. Please cancel it before proceeding.";
					close;
					
				case -4:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "^0000ff"+.@md_name$+" ^000000 is currently full.";
					end;
					
				default:
					mes "[ Operation Officer ]";
					mes "Before going make sure you make a party first.";
					end;
			}

		case 2:
			switch(instance_enter(.@md_name$)){
				case 3:
					mes "An unknown error has occurred.";
					end;
					
				case 2:
				case 1:
					mes "^ff0000Character doesn't have an instance reserved.^000000";
					end;
					
				case 0:
					mapannounce "sp_cor", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00FF99";
					setquest 12455;
					end;
			}

		case 3:
			break;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

1@os_a,30,354,0	script	#os_mission_control	HIDDEN_WARP_NPC,2,2,{
	end;
	
OnTouch:
	.@var = get_instance_var("os_mission");
	if(.@var == 0){
		set_instance_var("os_mission",1);
		instance_event(strnpcinfo(0),"OnEvent01",true);
	}
end;

OnInstanceInit:
	.@type$ = instance_live_info(ILI_NAME);
	if(.@type$ == "OS Mission 2"){
		instance_enable(strnpcinfo(0),false);
		end;
	}
	set_instance_var("map$",instance_mapname("1@os_a"));
	.@map$ = get_instance_var("map$");
	setcell .@map$,48,327,48,345,CELL_WALKABLE,0;
	setcell .@map$,48,327,48,345,CELL_SHOOTABLE,0;
	setcell .@map$,46,356,46,363,CELL_WALKABLE,0;
	setcell .@map$,46,356,46,363,CELL_SHOOTABLE,0;
	for(.@i = 1; .@i < 26; .@i++)
		instance_hide("#os_rebel_" + .@i,true);
	instance_hide("Erst#os_mission_st",true);
	instance_enable("#os_com_dev_2",false);
	instance_enable("#os_mission_ev01",false);
	instance_enable("#os_mission_ev02",false);
	instance_enable("#os_mission_ev03",false);
	instance_enable("#os_mission_miguel",false);
	instance_enable("Erst#os_mission_exit",false);
end;

OnEvent01:
	instance_hide("Erst#os_mission_st",false);
	for(.@i = 1; .@i < 26; .@i++)
		instance_hide("#os_rebel_" + .@i,false);
	instance_event("Erst#os_mission_st","OnStart",true);
end;

OnEvent02:
	setarray .@id$,"1,18,19,25","13,20,24","4,14,16,23","9,10,21,22","7,8,12,17","2,3,6,15","5,11";
	for(.@i = 0; .@i < getarraysize(.@id$); .@i++){
		explode(.@T$,.@id$[.@i],",");
		for(.@j = 0; .@j < getarraysize(.@T$); .@j++)
			instance_hide("#os_rebel_" + .@T$[.@j],true);
		sleep2 500;
	}
	set_instance_var("os_mission",2);
	instance_event("#os_a_mob01","OnMobSpawn",false);
	instance_event("#os_com_dev_1","OnStart",true);
end;

OnEvent03:
	.@map$ = get_instance_var("map$");
	specialeffect EF_CLOUD4,AREA,instance_npcname("#os_com_dev_1");
	for(.@i = 0; .@i < 10; .@i++)
		instance_enable("#os_poison_" + .@i,false);
	setcell .@map$,48,327,48,345,CELL_WALKABLE,1;
	setcell .@map$,48,327,48,345,CELL_SHOOTABLE,1;
	setcell .@map$,46,356,46,363,CELL_WALKABLE,1;
	setcell .@map$,46,356,46,363,CELL_SHOOTABLE,1;
	instance_enable("#os_com_dev_2",true);
end;

OnEvent04:
	instance_hide("#os_com_dev_2",true);
	instance_enable("#os_com_dev_2",false);
	instance_event("#os_a_mob02","OnMobSpawn",false);
end;
}

1@os_a,30,360,3	script	Erst#os_mission_st	4_F_ESTLOVELOY,{
	cutin "ep162_est01",2;
	mes "[ Erst ]";
	mes "Focus on the briefing.";
	close3;
	
OnStart:
	.@map$ = get_instance_var("map$");
	npctalk "Erst : I have confirmed that there's toxic gas spreading at the front and it's being removed as we speak.";
	sleep2 2300;
	npctalk "Erst : Do not go until the clean up is finished...";
	sleep2 2300;
	npctalk "Erst : We need to properly establish a base here. I don't know how many experiment are lurking around.";
	sleep2 2300;
	npctalk "Erst : There isn't much information available, so it's our duty to figure it out. From now on, we'll split in 3 groups.";
	sleep2 2300;
	npctalk "Erst : The Alpha Team will begin a search around the southern channel.";
	sleep2 2300;
	npctalk "Erst : Bravo Team, you will come with me and we'll sweep the border to the east.";
	sleep2 2300;
	npctalk "Erst : The Echo team is guided by Lulune and they will be our backups. You will block the entrance and stop the experiments from coming back.";
	sleep2 2300;
	npctalk "Erst : We shouldn't need to ask anything from the support team, but if that happens, the Echo team will stand by.";
	sleep2 1500;
	mapannounce .@map$,"Chemical Processing Unit : The toxic gas facilities have been blocked successfully. The residual gas is expected to last for several more minutes.",bc_map,0xFFAE42;
	sleep2 1500;
	npctalk "Erst : it's time, let's move out. " + strcharinfo(0) + " team, wait here on standby, you're the support team.";	
	sleep2 1000;
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	instance_event("#os_mission_control","OnEvent02",true);
end;
}

1@os_a,29,360,3	script	#os_com_dev_1	4_SCR_AT_ROBOTS,{
	.@var = get_instance_var("os_mission");
	.@var2 = get_instance_var("os_dev");
	if(.@var < 3 || .@var2 == 0){
		mes "## ^FF0000No Communication Status^000000 ##";
		close;
	}
	.@map$ = get_instance_var("map$");
	switch(.@var){
		case 3:
			mes "## Send Message Input ##";
			next;
			switch(select("Engaging with mutants north.:Engaging with small mutants.:No~! I want to go home!")){
				case 1: .@word$ = "Engaging with mutants north."; break;
				case 2: .@word$ = "Engaging with small mutants."; break;
				case 3: .@word$ = "No~! I want to go home!"; break;
			}
			close2;
			set_instance_var("os_dev",0);
			mapannounce .@map$,strcharinfo(0) + " : " + .@word$,bc_map,0xC081C0;
			sleep2 4800;
			mapannounce .@map$,"Erst : The Echo reception is not so good. Please send again.",bc_blue|bc_map;
			sleep2 4800;
			mapannounce .@map$,"Alpha : It's an ambush! Alpha team coordinates are OS Car Sierra 9.... *inaudible*",bc_map,0xF0E68C;
			sleep2 4800;
			mapannounce .@map$,"Erst : Team Alpha, resume your coordinates. Alpha!! Respond!!.",bc_blue|bc_map;
			sleep2 4800;
			mapannounce .@map$,"Alpha : ---- Tch -----!",bc_map,0xF0E68C;
			sleep2 4800;
			mapannounce .@map$,"Erst : Damn!... Team Echo, check if you can get to team Alpha's coordinates.",bc_blue|bc_map;
			sleep2 4800;
			mapannounce .@map$,"Erst : " + strcharinfo(0) + "! Check Alpha team's coordinates!",bc_blue|bc_map;
			sleep2 1000;
			set_instance_var("os_mission",4);
			set_instance_var("os_dev",1);
			specialeffect EF_BIG_PORTAL;
			end;
			
		case 4:
			mes "## Send Message Input ##";
			next;
			switch(select("Team Echo is fighting. Requesting more support.:There was an engagement, but it ended.:Help me!")){
				case 1: .@word$ = "Team Echo is fighting. Requesting more support."; break;
				case 2: .@word$ = "There was an engagement, but it ended."; break;
				case 3: .@word$ = "Help me!"; break;		
			}
			close2;
			set_instance_var("os_dev",0);
			mapannounce .@map$,strcharinfo(0) + " : " + .@word$,bc_map,0xC081C0;
			sleep2 4800;
			mapannounce .@map$,"?????? : This is Foxtrot. Ground support bombardment is ready.",bc_map,0x00FF00;
			sleep2 4800;
			mapannounce .@map$,"Erst : Team Alpha is not responding." + strcharinfo(0) + ", please go back them up. The coordinates are OS Cat Sierra 32 356.",bc_blue|bc_map;
			sleep2 4800;
			mapannounce .@map$,"?????? : Foxtrot here, we received the coordinates.  Please be careful to only hit the mutants.",bc_map,0x00FF00;
			sleep2 4800;
			mapannounce .@map$,"?????? : A ground pulse will be sent on Echo's side in 3 seconds.",bc_map,0x00FF00;
			sleep2 3000;
			setarray .@id,1,18,19,25,13,20,24,4,14,16,23,9,10,21,22,7,8,12,17,2,3,6,15,5,11;
			for(.@i = 0; .@i < getarraysize(.@id); .@i++){
				specialeffect EF_METEORSTORM,AREA,instance_npcname("#os_rebel_" + .@id[.@i]);
				killmonster .@map$,instance_npcname("#os_a_mob01")+"::OnMobKill";
				sleep2 210;
			}
			set_instance_var("os_mission",5);
			mapannounce .@map$,"?????? : Team Echo, the mutant disabling support is complete.",bc_map;
			sleep2 3000;
			mapannounce .@map$,"Erst : The engagement has ended on our end.",bc_blue|bc_map;
			sleep2 3000;
			mapannounce .@map$,"Erst : I will transmit Alpha team's approximate coordinates of their last contact point by radio.",bc_blue|bc_map;
			instance_event("#os_mission_control","OnEvent03",false);
			set_instance_var("os_dev",1);
			set_instance_var("poison",1);
			specialeffect EF_BIG_PORTAL;
			end;
			
		default:
			mes "## Received Message ##";
			mes "## Team Alpha's last communication was at Car Sierra 52 177 ##";
			navigateto(.@map$,52,177);
			end;				
	}
	
OnStart:
	.@map$ = get_instance_var("map$");
	sleep2 2000;
	mapannounce .@map$,"Alpha : The Alpha team is approaching south. We found a lot of mutants north of the Echo team.",bc_map,0xF0E68C;
	sleep2 4800;
	mapannounce .@map$,"Erst : The reception is good. Team Echo, prepare yourselves  and then contact us when you've taken care of the attack.",bc_blue|bc_map;
	sleep2 4800;
	mapannounce .@map$,"Alpha : This is Team Alpha. We're dealing with a number of mutants near the south drain. We're about to engage.",bc_map,0xF0E68C;
	sleep2 4800;
	mapannounce .@map$,"Erst : ---Roger.",bc_blue|bc_map;
	sleep2 4800;
	mapannounce .@map$,"Erst : Team Alpha, notify us when you're done with your engagement.",bc_blue|bc_map;
	sleep2 4800;
	mapannounce .@map$,"Alpha : We've cleared the mutants around the drain. A biological researched was confirmed. Waiting on the second wave.",bc_map,0xF0E68C;
	sleep2 4800;
	mapannounce .@map$,"Erst : Team Alpha, roger. Team Echo, give us a status report.",bc_blue|bc_map;
	sleep2 4800;
	mapannounce .@map$,"Erst : " + strcharinfo(0) + "!! What is your situation!!",bc_blue|bc_map;
	sleep2 1000;
	set_instance_var("os_mission",3);
	set_instance_var("os_dev",1);
	specialeffect EF_BIG_PORTAL;
end;	
}

1@os_a,52,177,3	script	#os_com_dev_2	4_SCR_AT_ROBOTS,5,5,{
	.@map$ = get_instance_var("map$");
	.@var = get_instance_var("os_mission");
	if(.@var == 5){
		set_instance_var("os_mission",6);
		mes "## Send Message Input ##";
		next;
		select("I can't find team Alpha's traces.");
		mapannounce .@map$,strcharinfo(0) + " : No traces of the Alpha team were found at the bottom bridge.",bc_map,0xC081C0;
		sleep2 1000;
		select("There is nothing special.");
		mapannounce .@map$,strcharinfo(0) + " : There is nothing special.",bc_map,0xC081C0;
		sleep2 1000;
		mapannounce .@map$,"Erst : Team Bravo just completed the search on the east side.",bc_blue|bc_map;
		sleep2 1000;
		mapannounce .@map$,"Erst : We'll be moving south. I'll transmit the new coordinates. Prepare yourselves for an engagement when you move out.",bc_blue|bc_map;
		mes "## Received Coordinates ##";
		navigateto(.@map$,84,256);
		close2;
		instance_event("#os_mission_control","OnEvent04",true);
	}
	end;
	
OnTouch:
	.@var = get_instance_var("os_mission");
	if(.@var)
		npctalk "Erst : Can you hear me " + strcharinfo(0) + "? Answer me if possible.";
end;
}

1@os_a,84,256,0	script	#os_mission_ev01	4_ENERGY_BLUE,2,2,{
	end;
	
OnTouch:
	.@map$ = get_instance_var("map$");
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	mapannounce .@map$,"Erst : " + strcharinfo(0) + ", can you hear me?",bc_blue|bc_map;
	instance_event("#os_a_mob03","OnMobSpawn",false);
	navigateto(.@map$,163,266);
	sleep2 1000;
	mapannounce .@map$,"Erst : I transmitted the second search coordinates. Be careful not to lose them.",bc_blue|bc_map;
	sleep2 2500;
	mapannounce .@map$,"Erst : " + strcharinfo(0) + ". See if you find any traces of team Alpha nearby.",bc_blue|bc_map;
	sleep2 2500;
	mapannounce .@map$,strcharinfo(0) + " : I've detected movements nearby, there are troops of mutants..",bc_map,0xC081C0;
	sleep2 2500;
	mapannounce .@map$,"Erst : See if you can get through. Try to ... take over all of them.",bc_blue|bc_map;
end;
}

1@os_a,163,266,0	script	#os_mission_ev02	4_ENERGY_BLUE,2,2,{
	end;
	
OnTouch:
	.@map$ = get_instance_var("map$");
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	navigateto(.@map$,138,174);
	instance_event("#os_a_mob04","OnMobSpawn",false);	
	mapannounce .@map$,"Erst : " + strcharinfo(0) + ", are you still there?",bc_blue|bc_map;
	sleep2 1000;
	mapannounce .@map$,strcharinfo(0) + " : Team Echo is still moving towards to the southern point.",bc_map,0xC081C0;
	sleep2 2500;
	mapannounce .@map$,"Erst : Team Bravo is also moving to the meeting point, we're skipping the eastern location.",bc_blue|bc_map;
end;
}
	
1@os_a,138,174,0	script	#os_mission_ev03	4_ENERGY_BLUE,2,2,{
	end;
	
OnTouch:
	.@map$ = get_instance_var("map$");
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	navigateto(.@map$,161,179);
	instance_event("#os_a_mob05","OnMobSpawn",false);
	end;
end;
}

1@os_a,162,176,5	script	#os_mission_miguel	4_EP17_MIGUEL_D,{
	if(@clicked){
		mes "^0000FFI think he stopped breathing.^000000";
		close;
	}
	cutin "ep171_miguel01",0;
	mes "[ ??? ]";
	mes "You... You must have been to Regenschirm. I have something to say...";
	next;
	cutin "",255;
	mes "^0000FFThe mutant seems like he want to say something.^000000";
	@clicked++;
	close;
}

1@os_a,165,176,3	script	Erst#os_mission_exit	4_F_ESTLOVELOY,{
	.@var = get_instance_var("os_mission");
	if(.@var == 6){
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes strcharinfo(0) + ", I didn't know if you'd make it. You're pretty good.";
		next;
		mes "[ Erst ]";
		mes "Well, I think we should ask him...";
		mes "he's the first able to speak.";
		next;
		cutin "ep171_miguel03",0;
		mes "[ ??? ]";
		mes "... Erst?";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "How do you know my name? Who are you!";
		next;
		cutin "ep171_miguel03",0;
		mes "[ ??? ]";
		mes "Erst... Rebellion Ghost Squad... Do you remember uncle Miguel?";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "How do you know that name, that's not possible...";
		next;
		cutin "ep171_miguel03",0;
		mes "[ ??? ]";
		mes "Ah... ahah... so you do remember.";
		next;
		mes "^0000FFYou notice the identification tag on the mutant's neck.^000000";
		next;
		select("Untie the tag and hand it over to Erst.");
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "Mi... guel...?";
		next;
		cutin "ep171_miguel03",0;
		mes "[ Miguel ]";
		mes "... Erst, the last thing I'll see... is your face... I'm glad.";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";			
		mes "Uncle Miguel?! How did this happen!";
		next;
		cutin "ep171_miguel03",0;
		mes "[ Miguel ]";
		mes "Before I die... I always wanted to see my old colleagues... You made that wish happen.";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "Uncle! What is this! What the hell happened to you?";
		next;
		cutin "ep171_miguel01",0;
		mes "[ Miguel ]";
		mes "Come on... I don't have much time left... Listen to me, Erst.";
		next;
		mes "[ Miguel ]";
		mes "Somewhere in here... the mad research results of Regenschirm... can be found somewhere in here.";
		next;
		mes "[ Miguel ]";
		mes "Find everything... and you'll know what happened to me... you'll see things that can't be explained here.";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "Uncle! Stand up!! Please... let's go back home together!";
		next;
		cutin "ep171_miguel02",0;
		mes "[ Miguel ]";
		mes  "Erst... you still have a big heart... did you... learn that in... the battlefield...";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "Uncle! Uncle!!";
		next;
		cutin "",255;
		mes "[ Miguel ]";
		mes "...";
		set_instance_var("os_mission",7);
		if(isbegin_quest(12452) == 1)
			completequest 12452;
		getitem 25668,1;
		getitem 25723,5;
		getexp 300000,300000;
		end;
	}
	select("Ask about Miguel");
	cutin "ep162_est01",2;
	mes "[ Erst ]";
	mes strcharinfo(0) +", I'm sorry but I don't feel like talking about him right now.";
	next;
	select("Ask about the records.");
	mes "[ Erst ]";
	mes "I checked the northeast section and saw a place over the railway that seemed to be a research facility.";
	next;
	mes "[ Erst ]";
	mes "Maybe the research Miguel was talking about... is somewhere in there. I'm going to have to start another operation right away.";
	next;
	mes "[ Erst ]";
	mes "I don't think there will be anything else to do here.";
	next;
	select("I want to go back.");
	if(isbegin_quest(12452) == 1)
		completequest 12452;
	warp "sp_cor",162,56;
	instance_destroy();
	end;	
}

//= Mob Spawn

1@os_a,1,1,0	script	#os_a_mob01	HIDDEN_WARP_NPC,{
	end;
	
OnMobSpawn:
	.@map$ = get_instance_var("map$");
	setarray .@mob,20348,20349,20350;
	while(get_instance_var("os_mission") < 5){
		.@id = .@mob[rand(getarraysize(.@mob))];
		areamonster .@map$,26,349,37,357,"--ja--",.@id,1,instance_npcname(strnpcinfo(0))+"::OnMobKill";
		sleep 6000;
	}
end;

OnMobKill:	
end;
}

1@os_a,1,1,0	script	#os_a_mob02	HIDDEN_WARP_NPC,{
	end;
	
OnMobSpawn:
	.@map$ = get_instance_var("map$");
	.@x = 63;
	.@y = 210;
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	for(.@i = 1; .@i < 9; .@i++)
		monster .@map$,.@x,.@y + (4*.@i),"Mutant Survivor",20355,1,.@event$;
	while(mobcount(.@map$,.@event$)){
		sleep 6000;
		.@mob_count = mobcount(.@map$,.@event$);
		if(.@mob_count)
			mapannounce .@map$,"Remaining Mutant Survivor - " + .@mob_count,bc_map;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		mapannounce .@map$,"Secure of the intermediate base complete.",bc_map;
		instance_enable("#os_mission_ev01",true);
	}
end;
}

1@os_a,1,1,0	script	#os_a_mob03	HIDDEN_WARP_NPC,{
	end;
	
OnMobSpawn:
	.@map$ = get_instance_var("map$");
	.@x = 122;
	.@y = 266;
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	for(.@i = 1; .@i < 14; .@i++){
		if(.@i == 1 || .@i == 6)
			monster .@map$,.@x + (4*.@i),.@y,"Mutant Survivor",20361,1,.@event$;
		else
			monster .@map$,.@x + (4*.@i),.@y,"Mutant Survivor",20355,1,.@event$;
	}
	while(mobcount(.@map$,.@event$)){
		sleep 6000;
		.@mob_count = mobcount(.@map$,.@event$);
		if(.@mob_count)
			mapannounce .@map$,"Remaining Mutant Survivor - " + .@mob_count,bc_map;
	}
end;
	
OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		mapannounce .@map$,"Secure of the intermediate base complete.",bc_map;
		instance_enable("#os_mission_ev02",true);
	}
end;
}

1@os_a,1,1,0	script	#os_a_mob04	HIDDEN_WARP_NPC,{
OnMobSpawn:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	setarray .@xy,
	139,199,20355,138,199,20355,138,201,20355,135,201,20361,140,195,20355,143,195,20355,145,201,20355,133,197,20355,136,206,20361,134,206,20355,139,198,20355,143,209,20355,142,210,20355,143,215,20361;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"Mutant Survivor",.@xy[.@i+2],1,.@event$;
	while(mobcount(.@map$,.@event$)){
		sleep 6000;
		.@mob_count = mobcount(.@map$,.@event$);
		if(.@mob_count)
			mapannounce .@map$,"Remaining Mutant Survivor - " + .@mob_count,bc_map;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		mapannounce .@map$,"Secure of the intermediate base complete.",bc_map;
		instance_enable("#os_mission_ev03",true);
	}
end;
}

1@os_a,1,1,0	script	#os_a_mob05	HIDDEN_WARP_NPC,{
OnMobSpawn:
	.@map$ = get_instance_var("map$");
	monster .@map$,161,178,"????",20347,1,instance_npcname(strnpcinfo(0))+"::OnMobKill";
	.@boss_id = $@mobid[0];
	getunitdata .@boss_id,.@boss;
	.@MAX_HP = .@boss[3];
	.@DAMAGE = (.@MAX_HP/10) * 8;
	.@HP = (.@MAX_HP - .@DAMAGE);
	setunitdata .@boss_id,UMOB_HP,.@HP;
end;	
	
OnMobKill:
	instance_enable("#os_mission_miguel",true);
	instance_enable("Erst#os_mission_exit",true);
end;
}

	
1@os_a,42,360,0	script	#os_poison_0	HIDDEN_WARP_NPC,{
	end;
	
OnInstanceInit:
	.@gid = getnpcid(0);
	getmapxy(.@map$,.@x,.@y,BL_NPC);
	setarray .@data,UNPC_ATKMIN,1,UNPC_ATKMAX,1,UNPC_MATKMIN,1500,UNPC_MATKMAX,2000,UNPC_STR,100,UNPC_AGI,100,UNPC_VIT,100,UNPC_INT,2000,UNPC_DEX,500,UNPC_LUK,100;
	for(.@i = 0; .@i < 20; .@i += 2)
		setunitdata .@gid,.@data[.@i],.@data[.@i+1];
	while(get_instance_var("poison") < 1){
		unitskillusepos .@gid,"NPC_VENOMFOG",1,.@x,.@y,-10000;
		sleep 3000;
	}
end;
}

1@os_a,45,360,0	duplicate(#os_poison_0)	#os_poison_1	HIDDEN_WARP_NPC
1@os_a,42,344,0	duplicate(#os_poison_0)	#os_poison_2	HIDDEN_WARP_NPC
1@os_a,42,341,0	duplicate(#os_poison_0)	#os_poison_3	HIDDEN_WARP_NPC
1@os_a,45,341,0	duplicate(#os_poison_0)	#os_poison_4	HIDDEN_WARP_NPC
1@os_a,45,344,0	duplicate(#os_poison_0)	#os_poison_5	HIDDEN_WARP_NPC
1@os_a,42,334,0	duplicate(#os_poison_0)	#os_poison_6	HIDDEN_WARP_NPC
1@os_a,45,334,0	duplicate(#os_poison_0)	#os_poison_7	HIDDEN_WARP_NPC
1@os_a,42,330,0	duplicate(#os_poison_0)	#os_poison_8	HIDDEN_WARP_NPC
1@os_a,45,330,0	duplicate(#os_poison_0)	#os_poison_9	HIDDEN_WARP_NPC

1@os_a,142,274,0	script	#os_poison_10	HIDDEN_WARP_NPC,{
	end;
	
OnInstanceInit:
	.@gid = getnpcid(0);
	getmapxy(.@map$,.@x,.@y,BL_NPC);
	//= Damage Estimation
	setarray .@data,UNPC_ATKMIN,1,UNPC_ATKMAX,1,UNPC_MATKMIN,1500,UNPC_MATKMAX,2300,UNPC_STR,100,UNPC_AGI,100,UNPC_VIT,100,UNPC_INT,2200,UNPC_DEX,500,UNPC_LUK,100;
	for(.@i = 0; .@i < 20; .@i += 2)
		setunitdata .@gid,.@data[.@i],.@data[.@i+1];
	while(true){
		unitskillusepos .@gid,"NPC_VENOMFOG",1,.@x,.@y,-10000;
		sleep 3000;
	}
end;
}

1@os_a,145,274,0	duplicate(#os_poison_10)	#os_poison_11	HIDDEN_WARP_NPC

1@os_a,38,357,7	duplicate(dummynpc2)	#os_rebel_1	4_F_GUNSLINGER3
1@os_a,38,354,7	duplicate(dummynpc2)	#os_rebel_2	4_F_GUNSLINGER3
1@os_a,38,351,7	duplicate(dummynpc2)	#os_rebel_3	4_F_GUNSLINGER3
1@os_a,38,348,7	duplicate(dummynpc2)	#os_rebel_4	4_F_GUNSLINGER3
1@os_a,38,345,7	duplicate(dummynpc2)	#os_rebel_5	4_F_GUNSLINGER3
1@os_a,35,357,7	duplicate(dummynpc2)	#os_rebel_6	4_F_GUNSLINGER2
1@os_a,35,354,7	duplicate(dummynpc2)	#os_rebel_7	4_F_GUNSLINGER2
1@os_a,35,351,7	duplicate(dummynpc2)	#os_rebel_8	4_F_GUNSLINGER2
1@os_a,35,348,7	duplicate(dummynpc2)	#os_rebel_9	4_F_GUNSLINGER2
1@os_a,35,345,7	duplicate(dummynpc2)	#os_rebel_10	4_F_GUNSLINGER2
1@os_a,32,357,7	duplicate(dummynpc2)	#os_rebel_11	4_M_REBELLION3
1@os_a,32,354,7	duplicate(dummynpc2)	#os_rebel_12	4_M_REBELLION3
1@os_a,32,351,7	duplicate(dummynpc2)	#os_rebel_13	4_M_REBELLION3
1@os_a,32,348,7	duplicate(dummynpc2)	#os_rebel_14	4_M_REBELLION3
1@os_a,32,345,7	duplicate(dummynpc2)	#os_rebel_15	4_M_REBELLION3
1@os_a,29,357,7	duplicate(dummynpc2)	#os_rebel_16	4_M_REBELLION2
1@os_a,29,354,7	duplicate(dummynpc2)	#os_rebel_17	4_M_REBELLION2
1@os_a,29,351,7	duplicate(dummynpc2)	#os_rebel_18	4_M_REBELLION2
1@os_a,29,348,7	duplicate(dummynpc2)	#os_rebel_19	4_M_REBELLION2
1@os_a,29,345,7	duplicate(dummynpc2)	#os_rebel_20	4_M_REBELLION2
1@os_a,26,357,7	duplicate(dummynpc2)	#os_rebel_21	4_M_REBELLION2
1@os_a,26,354,7	duplicate(dummynpc2)	#os_rebel_22	4_M_REBELLION2
1@os_a,26,351,7	duplicate(dummynpc2)	#os_rebel_23	4_M_REBELLION2
1@os_a,26,348,7	duplicate(dummynpc2)	#os_rebel_24	4_M_REBELLION2
1@os_a,26,345,7	duplicate(dummynpc2)	#os_rebel_25	4_M_REBELLION2




1@os_a,335,33,0	script	#os_mission_control_d	HIDDEN_WARP_NPC,2,2,{
	end;
	
OnTouch:
	if(is_party_leader() == false)
		end;	
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	instance_event("#os_d_mob01","OnSpawn",false);
end;
	
OnInstanceInit:
	.@type$ = instance_live_info(ILI_NAME);
	if(.@type$ == "OS Mission"){
		instance_enable(strnpcinfo(0),false);
		end;
	}
	set_instance_var("map$",instance_mapname("1@os_a"));
	.@map$ = get_instance_var("map$");
	setcell .@map$,248,110,258,110,CELL_SHOOTABLE,0;
	setcell .@map$,248,110,258,110,CELL_WALKABLE,0;
	setcell .@map$,198,110,204,110,CELL_SHOOTABLE,0;
	setcell .@map$,198,110,204,110,CELL_WALKABLE,0;
	instance_enable("Operation Officer#os_mission_d",false);
end;
}

1@os_a,1,1,0	script	#os_d_mob01	HIDDEN_WARP_NPC,{
OnSpawn:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	setarray .@xy,325,85,20365,295,91,20361,277,94,20365,277,91,20365,278,91,20365,272,91,20365,265,95,20361,264,94,20361,264,82,20365,263,69,20365,261,69,20365,260,66,20361,258,67,20355,257,63,20365,256,61,20365,254,61,20365;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"CP1 " + getmonsterinfo(.@xy[.@i+2],MOB_NAME),.@xy[.@i+2],1,.@event$;
	sleep 2000;
	mapannounce .@map$,"Operation Officer : The Alpha team should be prepare to battle as soon as mutants are seen nearby.",bc_blue|bc_map;
	sleep 2800;
	mapannounce .@map$,"Operation Officer : There are no civilian this area, we can safely subdue monsters.",bc_blue|bc_map;
	sleep 2800;
	mapannounce .@map$,"Operation Officer : Charlie, the Delta team will fight into battle if they are engaged.",bc_blue|bc_map;
	while(mobcount(.@map$,.@event$)){
		sleep 6000;
		.@mob_count = mobcount(.@map$,.@event$);
		if(.@mob_count)
			mapannounce .@map$,"Remaining Mutant Survivor - " + .@mob_count,bc_map;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		instance_enable(strnpcinfo(0),false);
		mapannounce .@map$,"First base secured.",bc_map;
		instance_event("#os_d_mob02","OnSpawn",false);
	}
end;
}

1@os_a,1,1,0	script	#os_d_mob02	HIDDEN_WARP_NPC,{
OnSpawn:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	setarray .@xy,211,78,20361,211,72,20365,208,72,20365,210,71,20365,203,74,20355,204,79,20361,210,85,20355,211,87,20355,215,85,20365,208,88,20365,209,90,20365,211,93,20365,207,91,20355,205,90,20361,198,86,20361,207,100,20365;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"CP3 " + getmonsterinfo(.@xy[.@i+2],MOB_NAME),.@xy[.@i+2],1,.@event$;
	sleep 2000;
	mapannounce .@map$,"Operation Officer : We received information about this search area.",bc_blue|bc_map;
	sleep 2800;
	mapannounce .@map$,"Operation Officer : A mutant marked with A013 is unique and independent of this base.",bc_blue|bc_map;
	sleep 2800;
	mapannounce .@map$,"Operation Officer : Avoid combat unless you are willing to fight more than normal mutants.",bc_blue|bc_map;
	while(mobcount(.@map$,.@event$)){
		sleep 6000;
		.@mob_count = mobcount(.@map$,.@event$);
		if(.@mob_count)
			mapannounce .@map$,"Remaining Mutant Survivor - " + .@mob_count,bc_map;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		instance_enable(strnpcinfo(0),false);
		mapannounce .@map$,"Second base secured.",bc_map;
		setcell .@map$,248,110,258,110,CELL_SHOOTABLE,1;
		setcell .@map$,248,110,258,110,CELL_WALKABLE,1;
		setcell .@map$,198,110,204,110,CELL_SHOOTABLE,1;
		setcell .@map$,198,110,204,110,CELL_WALKABLE,1;
		for(.@i = 0; .@i < 4; .@i++)
			instance_enable("#os_poison_d" + .@i,false);
		set_instance_var("poison",1);
		instance_event("#os_d_mob03","OnSpawn",false);
	}
end;
}

1@os_a,1,1,0	script	#os_d_mob03	HIDDEN_WARP_NPC,{
OnSpawn:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	setarray .@xy,207,126,20365,209,127,20355,203,128,20361,210,132,20361,206,135,20361,206,138,20361,203,137,20355,213,131,20355,214,130,20365,215,135,20355,215,136,20361,224,131,20365,225,131,20361,224,126,20365;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"CP5 " + getmonsterinfo(.@xy[.@i+2],MOB_NAME),.@xy[.@i+2],1,.@event$;
	sleep 2000;
	mapannounce .@map$,"Operation Officer : Be careful when dealing with CP4 or higher class mutants.",bc_blue|bc_map;
	sleep 2800;
	mapannounce .@map$,"Operation Officer : They are the same type as CP1, but their destructive power increases with their grade. Be careful not to be surrounded.",bc_blue|bc_map;
	while(mobcount(.@map$,.@event$)){
		sleep 6000;
		.@mob_count = mobcount(.@map$,.@event$);
		if(.@mob_count)
			mapannounce .@map$,"Remaining Mutant Survivor - " + .@mob_count,bc_map;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		instance_enable(strnpcinfo(0),false);
		mapannounce .@map$,"Third base secured.",bc_map;
		instance_event("#os_d_mob04","OnSpawn",false);
	}
end;
}

1@os_a,1,1,0	script	#os_d_mob04	HIDDEN_WARP_NPC,{
OnSpawn:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	setarray .@xy,245,158,20361,248,155,20361,249,155,20365,249,153,20365,254,155,20361,254,161,20361,252,161,20365,251,161,20361,258,157,20355,259,154,20365,263,159,20361;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"CP5 " + getmonsterinfo(.@xy[.@i+2],MOB_NAME),.@xy[.@i+2],1,.@event$;
	sleep 2000;
	mapannounce .@map$,"Operation Officer : The fourth area is said to be contain confidential documents from the storage room.",bc_blue|bc_map;
	sleep 2800;
	mapannounce .@map$,"Operation Officer : I want you to focus on battle because the first team has already searched the place for important information.",bc_blue|bc_map;
	while(mobcount(.@map$,.@event$)){
		sleep 6000;
		.@mob_count = mobcount(.@map$,.@event$);
		if(.@mob_count)
			mapannounce .@map$,"Remaining Mutant Survivor - " + .@mob_count,bc_map;
	}
end;
	
OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		instance_enable(strnpcinfo(0),false);
		mapannounce .@map$,"Fourth base secured.",bc_map;
		instance_event("#os_d_mob05","OnSpawn",false);
	}
end;
}

1@os_a,1,1,0	script	#os_d_mob05	HIDDEN_WARP_NPC,{
OnSpawn:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	setarray .@xy,222,187,20361,225,184,20365,229,184,20355,230,183,20365,232,182,20365,233,186,20365,228,189,20361,220,190,20361,214,191,20355,211,191,20361,211,186,20355,212,187,20365,211,183,20361,210,182,20361,205,185,20355,205,183,20365,203,187,20361,199,188,20361,198,185,20361,197,182,20361;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"CP7 " + getmonsterinfo(.@xy[.@i+2],MOB_NAME),.@xy[.@i+2],1,.@event$;
	sleep 2000;
	mapannounce .@map$,"Operation Officer : Bravo Team. CP6 mutants sighted. Their attack power is very strong.",bc_blue|bc_map;
	sleep 2800;
	mapannounce .@map$,"Operation Officer : Alpha, Charlie and Delta team, be very careful. Never be surrounded by CP6 grade mutants.",bc_blue|bc_map;
	while(
	mobcount(.@map$,.@event$)){
		sleep 6000;
		.@mob_count = mobcount(.@map$,.@event$);
		if(.@mob_count)
			mapannounce .@map$,"Remaining Mutant Survivor - " + .@mob_count,bc_map;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		instance_enable(strnpcinfo(0),false);
		mapannounce .@map$,"Fifth base secured.",bc_map;
		instance_event("#os_d_mob06","OnSpawn",false);
	}
end;
}

1@os_a,1,1,0	script	#os_d_mob06	HIDDEN_WARP_NPC,{
OnSpawn:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	mapannounce .@map$,"Operation Officer : To all team. If you find an S-Class mutant, engage in the battle immediately.",bc_blue|bc_map;
	sleep 2000;
	mapannounce .@map$,"????: Argh...",bc_map,0xFF0000;
	sleep 2800;
	mapannounce .@map$,"Operation Officer : A mutant with a high CP is hard to deal with, so be careful!",bc_blue|bc_map;
	monster .@map$,205,188,"CP8 Miguel",20346,1,.@event$;
	.@boss_id = $@mobid[0];
	set_instance_var("boss_id",.@boss_id);
	freeloop(true);
	while(unitexists(.@boss_id)){
		if(unitexists(.@boss_id)){
			getunitdata .@boss_id,.@boss_data;
			.@HP = .@boss_data[2];
			.@MAX_HP = .@boss_data[3];
			.@FIRST_SUMMON = (.@MAX_HP/10)*7;
			.@SECOND_SUMMON = (.@MAX_HP/10)*3;
			if(.@HP <= .@FIRST_SUMMON && get_instance_var("first_summon") == 0)
				instance_event(strnpcinfo(0),"OnFirstSummon",false);
			if(.@HP <= .@SECOND_SUMMON && get_instance_var("second_summon") == 0)
				instance_event(strnpcinfo(0),"OnSecondSummon",false);
		}
		if(get_instance_var("second_summon"))
			break;
		sleep 100;
	}
end;

OnFirstSummon:
	set_instance_var("first_summon",1);
	.@map$ = get_instance_var("map$");
	.@boss_id = get_instance_var("boss_id");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnEnd";
	freeloop(true);
	while(unitexists(.@boss_id)){
		getunitdata .@boss_id,.@xy;
		if(.@xy[6] == get_instance_var("boss_x") && .@xy[7] == get_instance_var("boss_y")){
			sleep 100;
			continue;
		}
		for(.@i = 0; .@i < 8; .@i++){
			if(.@i == 4 && get_instance_var("second_summon") == 0)
				break;
			if(unitexists('summon[.@i]))
				unitkill 'summon[.@i];
		}
		set_instance_var("boss_x",.@xy[6]);
		set_instance_var("boss_y",.@xy[7]);
		monster .@map$,get_instance_var("boss_x")+7,get_instance_var("boss_y"),"",20351,1,.@event$;
		'summon[0] = $@mobid[0];
		monster .@map$,get_instance_var("boss_x")-7,get_instance_var("boss_y"),"",20351,1,.@event$;
		'summon[1] = $@mobid[0];
		monster .@map$,get_instance_var("boss_x"),get_instance_var("boss_y")+7,"",20351,1,.@event$;
		'summon[2] = $@mobid[0];
		monster .@map$,get_instance_var("boss_x"),get_instance_var("boss_y")-7,"",20351,1,.@event$;
		'summon[3] = $@mobid[0];
		if(get_instance_var("second_summon") == 1){
			monster .@map$,get_instance_var("boss_x")+5,get_instance_var("boss_y")+5,"",20351,1,.@event$;
			'summon[4] = $@mobid[0];
			monster .@map$,get_instance_var("boss_x")+5,get_instance_var("boss_y")-5,"",20351,1,.@event$;
			'summon[5] = $@mobid[0];
			monster .@map$,get_instance_var("boss_x")-5,get_instance_var("boss_y")+5,"",20351,1,.@event$;
			'summon[6] = $@mobid[0];
			monster .@map$,get_instance_var("boss_x")-5,get_instance_var("boss_y")-5,"",20351,1,.@event$;
			'summon[7] = $@mobid[0];
		}
		for(.@i = 0; .@i < 8; .@i++){
			if(.@i == 4 && get_instance_var("second_summon") == 0)
				break;
			setunitdata get_instance_var("summon["+.@i+"]"),UMOB_DMGIMMUNE,1;
		}
		sleep 100;
	}
	freeloop(false);
	for(.@i = 0; .@i < 8; .@i++){
		if(unitexists('summon[.@i]))
			unitkill 'summon[.@i];			
	}
end;

OnSecondSummon:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnEnd";
	set_instance_var("second_summon",1);
	monster .@map$,get_instance_var("boss_x")+5,get_instance_var("boss_y")+5,"",20351,1,.@event$;
	'summon[4] = $@mobid[0];
	monster .@map$,get_instance_var("boss_x")+5,get_instance_var("boss_y")-5,"",20351,1,.@event$;
	'summon[5] = $@mobid[0];
	monster .@map$,get_instance_var("boss_x")-5,get_instance_var("boss_y")+5,"",20351,1,.@event$;
	'summon[6] = $@mobid[0];
	monster .@map$,get_instance_var("boss_x")-5,get_instance_var("boss_y")-5,"",20351,1,.@event$;
	'summon[7] = $@mobid[0];
	for(.@i = 4; .@i < 8; .@i++)
		setunitdata get_instance_var("summon["+.@i+"]"),UMOB_DMGIMMUNE,1;
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	set_instance_var("os_mission_d",1);
	killmonsterall .@map$;
	instance_enable("Operation Officer#os_mission_d",true);
	mapannounce .@map$,"Operation Officer : I think I arrived late!.",bc_blue|bc_map;
end;

OnEnd:
end;
}

1@os_a,187,195,5	script	Operation Officer#os_mission_d	4_M_ILYA,{
	if(get_instance_var("os_mission_d") == 1 && checkquest(12454,HUNTING) == 2){
		mes "[ Operation Officer ]";
		mes "You've dealt with the CP6 Mutant all by yourself. Was it a good fight?";
		next;
		mes "[ Operation Officer ]";
		mes "These are the supplies and reward given to the troops that joined the operation. There you go.";
		erasequest 12454;
		getexp 150000,150000;
		getitem 25669,5;
		getitem 25723,1;
		next;
		mes "[ Operation Officer ]";
		mes "It's a CP24 rating, sorry I couldn't give you more reward.";
		end;
	}
	mes "[ Operation Officer ]";
	mes "Let's go out now. You'll have to go back soon.";
	next;
	if(select("Take a closer look.:I'm going now.") == 1){
		mes "[ Operation Officer ]";
		mes "Hurry up. We can't stay much longer here.";
		end;
	}
	warp "sp_cor",162,56;
end;
}

1@os_a,252,107,0	script	#os_poison_d0	HIDDEN_WARP_NPC,{
	end;
	
OnInstanceInit:
	.@gid = getnpcid(0);
	getmapxy(.@map$,.@x,.@y,BL_NPC);
	setarray .@data,UNPC_ATKMIN,1,UNPC_ATKMAX,1,UNPC_MATKMIN,1500,UNPC_MATKMAX,2300,UNPC_STR,100,UNPC_AGI,100,UNPC_VIT,100,UNPC_INT,2200,UNPC_DEX,500,UNPC_LUK,100;
	for(.@i = 0; .@i < 20; .@i += 2)
		setunitdata .@gid,.@data[.@i],.@data[.@i+1];
	while(get_instance_var("poison") < 1){
		unitskillusepos .@gid,"NPC_VENOMFOG",1,.@x,.@y,-10000;
		sleep 3000;
	}
end;
}

1@os_a,255,107,0	duplicate(#os_poison_d0)	#os_poison_d1	HIDDEN_WARP_NPC
1@os_a,198,107,0	duplicate(#os_poison_d0)	#os_poison_d2	HIDDEN_WARP_NPC
1@os_a,201,107,0	duplicate(#os_poison_d0)	#os_poison_d3	HIDDEN_WARP_NPC