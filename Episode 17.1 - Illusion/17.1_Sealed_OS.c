//===== rAthena Script ===========================================|
//= Episode 17.1 Sealed Barrier OS                               =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

ein_fild03,278,269,4	script	Rebellion Crew#old_mem_1	CLEAR_NPC,{
	switch(ep_illusion){
		case 29:
			mes "[ Rebellion Crew ]";
			mes "Eheh...";
			mes "This area is disguised as an abandoned mine.";
			mes "Such a sloppy trick~ ehe~";
			next;
			select("Please speak.");
			mes "[ Rebellion Crew ]";
			mes "Shh!";
			mes "Not so loud!!";
			mes "If they find us, we're done for!!";
			next;
			mes "[ Rebellion Crew ]";
			mes "Oh... I thought you were a rebellion member too.";
			next;
			mes "[ Rebellion Crew ]";
			mes "Do you see the ^FF0000mine entrance^000000 blocked by wire mesh?";
			mes "I think it's the entrance to their main base.";
			next;
			mes "[ Rebellion Crew ]";
			mes "I tried to get in a while ago, but it was blocked by wire mesh. I could see suspicious movements from the outside.";
			next;
			mes "[ Rebellion Crew ]";
			mes "If you go in by force, you will get chased down by dogs. You should ^FF0000scout nearby^000000 and wait for more support.";
			next;
			mes "[ Rebellion Crew ]";
			mes "I've never seen anyone go onside...";
			mes "I don't really know what's going to happen, so why don't you go have a look around?";
			ep_illusion = 30;
			completequest 7865;
			setquest 11596;
			questinfo_refresh();
			close2;
			navigateto("ein_fild03",347,219);
			end;
			
		case 30:
			if(!isbegin_quest(11599)){
				mes "[ Rebellion Crew ]";
				mes "I've never seen anyone go onside...";
				mes "I don't really know what's going to happen, so why don't you go have a look around?";
				close;
			}
			mes "[ Rebellion Crew ]";
			mes "Hmmm.";
			mes "There are no signs of people around...";
			next;
			select("I'm going inside.");
			mes "[ Rebellion Crew ]";
			mes "I'm not kidding, it's dangerous.";
			mes "You're just going in to look right?";
			mes "Tell me again when you're ^FF0000ready to go inside.^000000";
			ep_illusion = 31;
			completequest 11599;
			setquest 11600;
			getexp 100000,100000;
			end;
			
		case 31:
			break;
			
		case 32:
			mes "[ Rebellion Crew ]";
			mes "What?!";
			mes "Have you forgotten the road to Clana Nemieri?";
			next;
			mes "[ Rebellion Crew ]";
			mes "What happened to you?";
			close;

		case 33:
			mes "[ Rebellion Crew ]";
			mes "What?!";
			mes "Dien's room?";
			mes "It's on the second floor of Clana Nemieri.";
			close;
			
		default:
			mes "[ Rebellion Crew ]";
			mes "Huh...";
			mes "It used to be great...";
			mes "It was great...";
			close;
			
	}
	mes "[ Rebellion Crew ]";
	mes "Are you ready?";
	next;
	.@md_name$ = "Sealed OS";
	.@party_id = getcharid(1);
	.@party_name$ = getpartyname(.@party_id);
	if(!.@party_id){
		mes "[ Rebellion Crew ]";
		mes "I'll need you to create a party to proceed.";
		close;
	}
	getpartymember .@party_id,3;
	if($@partymembercount != 1){
		mes "[ Rebellion Crew ]";
		mes "You can't bring other than yourself in the dangerous area. Make sure you're alone.";
		close;
	}
	switch(select("Create Memorial.:Enter Memorial.:Cancel.")){
		case 1:
			switch(instance_create(.@md_name$)){
				case -1:
					mes "[ Rebellion Crew ]";
					mes "Unknown Error Has Occurred.";
					end;
				case -2:
					mes "[ Rebellion Crew ]";
					mes "I'll need you to create a party to proceed.";
					end;
				case -3:
					mes "[ Rebellion Crew ]";
					mes "You already have an instance active. Cancel it and try again later.";
					mes "Player already have instance.";
					end;
					
				case -4:
					mes "[ Rebellion Crew ]";
					mes "Reservation is currently full. Try again later.";
					end;
					
				default:
					mes "[ Rebellion Crew ]";
					mes "Please wait a minute. I'll prepare the portal, talk to me again to enter.";
					end;
			}
			
		case 2:
			switch(instance_enter(.@md_name$)){
				case IE_OTHER:
					mes "An unknown error has occurred.";
					end;
					
				case IE_NOINSTANCE:
					mes "^ff0000Character doesn't have an instance reserved.^000000";
					end;
					
				case IE_OK:
					mapannounce "ein_fild03", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00FF99";
					end;
			}
			
		case 3:
			mes "[ Rebellion Crew ]";
			mes "Tell me whenever you're ready.";
			close;
	}
	
	
OnInit:
	setunitdata getnpcid(0),UNPC_CLASS,4215;
	setunitdata getnpcid(0),UNPC_SEX,SEX_MALE;
	setunitdata getnpcid(0),UNPC_HAIRSTYLE,17;
	setunitdata getnpcid(0),UNPC_HEADBOTTOM,0;
	setunitdata getnpcid(0),UNPC_HEADMIDDLE,1561;
	setunitdata getnpcid(0),UNPC_HEADTOP,1406;
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 29");
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 30 && checkquest(11599) == 1");
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 31");
end;
}

1@os_b,1,1,0	script	#171_sealedos_control	-1,{
OnInstanceInit:
	set_instance_var("map$",instance_mapname("1@os_b"));
	instance_hide("Dien#s_os",true);
	instance_hide("Cotnes#s_os",true);
	instance_hide("Dien#s_os2",true);
	instance_hide("Ridsh#s_os2",true);
	instance_hide("Cotnes#s_os2",true);
	instance_enable("Suspicious Device#s_os_trigger",false);
	instance_enable("Thick Wire#os_lock_0",false);
	instance_enable("Thick Wire#os_lock_1",false);
	instance_enable("Thick Wire#os_lock_2",false);
	instance_enable("Dien#s_os3",false);
	instance_enable("Cotnes#s_os3",false);
	instance_enable("Dien#s_os4",false);
	instance_enable("Erst#s_os",false);
	instance_enable("Cotnes#s_os4",false);
	instance_enable("Dien#s_os5",false);
	instance_enable("Ridsh#s_os3",false);
	instance_enable("#s_os_dum01",false);
	instance_enable("#s_os_dum02",false);
	instance_enable("Ridsh#s_os4",false);
	instance_enable("Erst#s_os2",false);
	instance_enable("Cotnes#s_os5",false);
	instance_enable("Dien#s_os6",false);
end;

OnEvent01:
	instance_hide("Ridsh#s_os",true);
	instance_hide("Dien#s_os",true);
	instance_hide("Cotnes#s_os",true);
	instance_enable("Ridsh#s_os",false);
	instance_enable("Dien#s_os",false);
	instance_enable("Cotnes#s_os",false);
	instance_hide("#os_lock_01",true);
	instance_enable("#os_lock_01",false);
	instance_hide("#os_lock_02",true);
	instance_enable("#os_lock_02",false);
	instance_hide("Dien#s_os2",false);
	instance_hide("Ridsh#s_os2",false);
	instance_hide("Cotnes#s_os2",false);
	instance_event("#sealedos_mob_1","OnSpawn",false);
end;

OnEvent02:
	for(.@i = 0; .@i < 6; .@i++){
		instance_hide("#s_os_dummy0"+.@i,true);
		instance_enable("#s_os_dummy0"+.@i,false);
	}
	instance_hide("Suspicious Device#s_os_trigger",true);
	instance_hide("Dien#s_os2",true);
	instance_hide("Ridsh#s_os2",true);
	instance_hide("Cotnes#s_os2",true);
	instance_enable("Suspicious Device#s_os_trigger",false);
	instance_enable("Dien#s_os2",false);
	instance_enable("Ridsh#s_os2",false);
	instance_enable("Cotnes#s_os2",false);
	instance_enable("#os_lock_00",false);
	instance_enable("Thick Wire#os_lock_0",true);
	instance_enable("Thick Wire#os_lock_1",true);
	instance_enable("Thick Wire#os_lock_2",true);
	instance_enable("Dien#s_os3",true);
end;

OnEvent03:
	instance_enable("Dien#s_os3",false);
	instance_enable("Cotnes#s_os3",true);
	instance_enable("Dien#s_os4",true);
	instance_enable("Ridsh#s_os3",true);
end;

OnEvent04:
	set_instance_var("s_os",8);
	instance_hide("#os_lock_03",true);
	instance_enable("#os_lock_03",false);
	instance_enable("Ridsh#s_os3",true);
	instance_enable("#s_os_dum01",true);
	instance_enable("#s_os_dum02",true);
end;

OnEvent05:
	set_instance_var("s_os",9);
	instance_hide("Ridsh#s_os3",true);
	instance_hide("Erst#s_os",true);
	instance_hide("Cotnes#s_os4",true);
	instance_hide("Dien#s_os5",true);
	instance_hide("#os_lock_05",true);
	instance_enable("Ridsh#s_os3",false);
	instance_enable("Erst#s_os",false);
	instance_enable("Cotnes#s_os4",false);
	instance_enable("Dien#s_os5",false);
	instance_enable("#os_lock_05",false);
	instance_enable("Ridsh#s_os4",true);
	instance_enable("Erst#s_os2",true);
	instance_enable("Cotnes#s_os5",true);
	instance_enable("Dien#s_os6",true);
end;
}

1@os_b,188,45,5	script	Ridsh#s_os	4_F_LEEDSH,{
	.@var = get_instance_var("s_os");
	.@dien$ =  instance_npcname("Dien#s_os");
	.@cot$ = instance_npcname("Cotnes#s_os");
	if(!.@var){
		cutin "ep162_rds01",2;
		mes "[ Ridsh ]";
		mes "Oh?";
		mes "What are you doing here?";
		npctalk "Ridsh : Oh? What are you doing here.";
		next;
		instance_hide("Dien#s_os",false);
		instance_hide("Cotnes#s_os",false);
		cutin "ep162_rds05",2;
		mes "[ Ridsh ]";
		mes "We're in trouble~~";
		mes "We can't have anyone know we're here~~";
		npctalk "Ridsh : We're in trouble~~ We can't have anyone know we're here~~";
		next;
		cutin "ep162_dn03",2;
		mes "[ Dien ]";
		mes "The adventurer is here too!";
		mes "Why are you scared!";
		npctalk "Dien : The adventurer is here too!  Why are you scared!",.@dien$;
		next;
		mes "[ Dien ]";
		mes "Hello " + strcharinfo(0) + ".";
		npctalk "Dien : Hello " + strcharinfo(0) +".",.@dien$;
		sleep2 1200;
		mes "We've came here to do something.. It was too troublesome to tell the kids.";
		npctalk "Dien : We've came here to do something.. It was too troublesome to tell the kids.",.@dien$;
		next;
		mes "[ Dien ]";
		mes "If you keep it a secret that you saw us...";
		npctalk "Dien : If you keep it a secret that you saw us...",.@dien$;
		next;
		specialeffect EF_BLASTMINEBOMB,AREA,instance_npcname("#os_lock_01");
		sleep2 350;
		specialeffect EF_BLASTMINEBOMB,AREA,instance_npcname("#os_lock_02");
		sleep2 350;
		specialeffect EF_BLASTMINEBOMB,AREA,instance_npcname("#os_lock_01");
		sleep2 350;
		specialeffect EF_BLASTMINEBOMB,AREA,instance_npcname("#os_lock_02");
		next;
		cutin "ep162_rds04",2;
		mes "[ Ridsh ]";
		mes "Sister~~";
		mes "What are you talking about, I don't see the adventurer!";
		npctalk "Ridsh : Sister~~ What are you talking about, I don't see the adventurer!";
		next;
		cutin "ep162_ctn01",2;
		mes "[ Cotnes ]";
		mes "Oh~";
		mes "Yeah?";
		mes "I don't see the adventurer either~";
		npctalk "Cotnes : Oh~ Yeah? I don't see the adventurer either~",.@cot$;
		next;
		mes "[ Cotnes ]";
		mes "So what now?";
		mes "We're already inside.";
		npctalk "Cotnes : So what now? We're already inside.",.@cot$;
		next;
		cutin "ep162_rds05",2;
		mes "[ Ridsh ]";
		mes "It can't be helped~~";
		mes "We have to go with the adventurer.";
		npctalk "Ridsh : It can't be helped~~ We have to go with the adventurer.";
		next;
		cutin "ep162_dn01",2;
		mes "[ Dien ]";	
		mes "It's dangerous, so please come with us.";
		npctalk "Dien :  It's dangerous so please come with us.",.@dien$;
		close2;
		cutin "",255;
		set_instance_var("s_os",1);
		instance_event("#171_sealedos_control","OnEvent01",false);
	}
	end;
}

1@os_b,212,41,0	script	Suspicious Device#s_os_trigger	4_ENERGY_BLUE,{
	.@var = get_instance_var("s_os");
	.@map$ = get_instance_var("map$");
	mes "- There is a pipe going through the floor. -";
	if(.@var == 2){
		next;
		if(select("Crush it.:Put it down.") == 2){
			mes "- Nothing happened. -";
			end;
		}
		mes "- Breaking the piple made a strange noise. The machine has stopped. -";
		specialeffect EF_BLASTMINEBOMB;
		close2;
		set_instance_var("s_os",3);
		mapannounce .@map$,"Ridsh : Alright! Let's move up along the railroad tracks!",bc_map,0xFF0000;
		instance_event("#171_sealedos_control","OnEvent02",false);
	}
	end;
}

1@os_b,190,44,3	duplicate(dummynpc2)	Dien#s_os	4_F_DIENE
1@os_b,190,49,5	duplicate(dummynpc2)	Cotnes#s_os	4_F_COATNEIS
1@os_b,199,51,7	duplicate(dummynpc2)	Dien#s_os2	4_F_DIENE
1@os_b,201,49,5	duplicate(dummynpc2)	Cotnes#s_os2	4_F_COATNEIS
1@os_b,203,51,7	duplicate(dummynpc2)	Ridsh#s_os2	4_F_LEEDSH

1@os_b,112,108,5	script	Dien#s_os3	4_F_DIENE,{
	cutin "ep162_dn01",2;
	mes "[ Dien ]";
	mes "Oh! What's in front over there?";
	close3;
}

1@os_b,115,112,0	script	Dangerous Device#s_os_0	4_PURPLE_WARP,3,5,{
	end;
	
OnTouch:
	.@map$ = get_instance_var("map$");
	mes "[ Dien ]";
	mes "Oh! I think it's a very precise device.";
	npctalk "Dien : Oh! I think it's a very precise device.",instance_npcname("Dien#s_os3"),bc_map;
	next;
	mes "[ Dien ]";
	mes "If you don't break the machine on the other side, you cannot pass!";
	npctalk "Dien : If you don't break the machine on the other side, you cannot pass!",instance_npcname("Dien#s_os3"),bc_map;
	next;
	mes "[ Dien ]";
	mes "It's dangerous to go through right now, so turn around and go to the device!";
	npctalk "Dien : It's dangerous to go through right now, so turn around and go to the device!",instance_npcname("Dien#s_os3"),bc_map;
	close2;
	warp .@map$,115,104;
	end;
end;
}

1@os_b,115,126,0	duplicate(Dangerous Device#s_os_0)	Dangerous Device#s_os_1	4_PURPLE_WARP,3,2
1@os_b,115,138,0	duplicate(Dangerous Device#s_os_0)	Dangerous Device#s_os_2	4_PURPLE_WARP,3,2

1@os_b,137,107,0	script	Thick Wire#os_lock_0	4_ENERGY_BLUE,{
	.@map$ = get_instance_var("map$");
	.@var = get_instance_var("s_os");
	.@npc = atoi(replacestr(strnpcinfo(2),"os_lock_",""));
	set_instance_var("s_os",.@var + 1);
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	instance_enable("Dangerous Device#s_os_" + .@npc,false);
	if((.@var+1) < 6)
		mapannounce .@map$,"Ridsh : The machine hasn't turned off yet. Please take a look above.",bc_map,0xFF0000;
	else {
		set_instance_var("s_os",7);
		mapannounce .@map$,"Ridsh : That's it! Let's move along the railroad tracks!",bc_map,0xFF0000;
		instance_event("#171_sealedos_control","OnEvent03",false);
	}
	end;
}

1@os_b,137,123,0	duplicate(Thick Wire#os_lock_0)	Thick Wire#os_lock_1	4_ENERGY_BLUE
1@os_b,137,139,0	duplicate(Thick Wire#os_lock_0)	Thick Wire#os_lock_2	4_ENERGY_BLUE

1@os_b,122,212,5	script	Dien#s_os4	4_F_DIENE,{
OnTalk:
	.@var = get_instance_var("s_os");
	cutin "ep162_dn01",2;
	mes "[ Dien ]";
	mes "Oh!";
	mes "If you go right, I think you can go back on the railroad without having to break the door.";
	npctalk "Dien : Oh! If you go right, I think you can go back on the railroad without having to break the door";
	if(.@var == 7)
		instance_event("#171_sealedos_control","OnEvent04",false);
	close3;
}

1@os_b,114,217,0	script	Cotnes#s_os3	4_F_COATNEIS,{
	.@var = get_instance_var("s_os");
	if(.@var == 7){
		cutin "ep162_ctn01",2;
		mes "[ Cotnes ]";
		mes "Oh, is this door too hard?";
		mes "It will take some time to break it~";
		next;
	}
	instance_event("Dien#s_os4","OnTalk",true);
	end;
}

1@os_b,146,221,7	script	Ridsh#s_os3	4_F_LEEDSH,{
	.@erst$ = instance_npcname("Erst#s_os");
	.@cot$ = instance_npcname("Cotnes#s_os4");
	.@dien$ = instance_npcname("Dien#s_os5");
	cutin "ep162_rds04",2;
	mes "[ Ridsh ]";
	mes "Argh!";
	npctalk "Ridsh : Argh!";
	next;
	specialeffect EF_BLASTMINEBOMB,AREA,instance_npcname("#s_os_dum01");
	specialeffect EF_BLASTMINEBOMB,AREA,instance_npcname("#s_os_dum02");
	instance_hide("#s_os_dum01",true);	
	instance_hide("#s_os_dum02",true);
	instance_enable("#s_os_dum01",false);	
	instance_enable("#s_os_dum02",false);
	instance_enable("Erst#s_os",true);
	cutin "ep162_est01",2;
	mes "[ Erst ]";
	mes "Oh...";
	mes "I'm in a hurry, what are you doing here?";
	npctalk "Erst : I'm in a hurry, what are you doing here?",.@erst$;
	next;
	cutin "ep162_est02",2;
	mes "[ Erst ]";
	mes "Please go back and enjoy your tea gracefully.";
	npctalk "Erst : Please go back and enjoy your tea gracefully.",.@erst$;
	next;
	cutin "ep162_rds02",2;
	mes "[ Ridsh ]";
	mes "Huh!";
	mes "How did you sneak in here anyway?";
	npctalk "Ridsh : Huh! How did you sneak in here anyway?";
	next;
	cutin "ep162_est02",2;
	mes "[ Erst ]";
	mes "This is only a surveillance routine.";
	mes "If you close your eyes for a second, you may run into an accident.";
	npctalk "Erst : This is only a surveillance routine.",.@erst$;
	sleep2 2000;
	npctalk "Erst : If you close your eyes for a second, you may run into an accident.",.@erst$;
	next;
	cutin "ep162_rds02",2;
	mes "[ Ridsh ]";
	mes "What makes you think we need your help?";
	npctalk "Ridsh : What makes you think we need your help?";
	next;
	cutin "ep162_est02",2;
	mes "[ Erst ]";
	mes "Didn't you just did now?";
	mes "I don't think I heard that wrong. Did I?";
	next;
	instance_enable("Cotnes#s_os3",false);
	instance_enable("Cotnes#s_os4",true);
	cutin "ep162_ctn01",2;
	mes "[ Cotnes ]";
	mes "You two really~";
	mes "Please stop fighting.";
	npctalk "Cotnes : You two really~ Please stop fighting.",.@cot$;
	next;
	instance_enable("Dien#s_os4",false);
	instance_enable("Dien#s_os5",true);
	cutin "ep162_dn03",2;
	mes "[ Dien ]";
	mes "How do you always fight like that?";
	npctalk "Dien : How do you always fight like that?",.@dien$;
	next;
	cutin "ep162_ctn01",2;
	mes "[ Cotnes ]";
	mes "I'm so excited about this~ I'm getting old and I'm tired of fighting.";
	npctalk "Cotnes : I'm so excited about this~ I'm getting old and I'm tired of fighting.",.@cot$;
	next;
	cutin "ep162_dn03",1;
	mes "[ Dien ]";
	mes "Is that so?";
	npctalk "Dien : Is that so?",.@dien$;
	next;
	cutin "ep162_ctn01",2;
	mes "[ Cotnes ]";
	mes "Yeah~";
	mes "I'm tired of fighting, let's go back to work.";
	mes "The road is open now.";
	npctalk "Cotnes : Yeah~ I'm tired of fighting, let's go back to work. The road is open now.",.@cot$;
	close2;
	cutin "",255;
	instance_event("#171_sealedos_control","OnEvent05",false);
	end;
}

1@os_b,148,217,3	duplicate(dummynpc2)	Erst#s_os	4_F_ESTLOVELOY
1@os_b,142,225,5	duplicate(dummynpc2)	Cotnes#s_os4	4_F_COATNEIS
1@os_b,143,222,5	duplicate(dummynpc2)	Dien#s_os5	4_F_DIENE
1@os_b,144,221,5	duplicate(dummynpc2)	#s_os_dum01	20363
1@os_b,148,221,3	duplicate(dummynpc2)	#s_os_dum02	20365

1@os_b,259,360,5	script	Dien#s_os6	4_F_DIENE,{
	cutin "ep162_dn03",2;
	mes "[ Dien ]";
	mes "Finally..";
	mes "If you cross this door...";
	next;
	cutin "ep162_est01",2;
	mes "[ Erst ]";
	mes "Let's head back now before they gather more troops.";
	next;
	cutin "ep162_dn03",2;
	mes "[ Dien ]";
	mes "Excuse me.";
	next;
	cutin "ep162_est01",2;
	mes "[ Erst ]";
	mes "?";
	next;
	cutin "ep162_rds01",2;
	mes "[ Ridsh ]";
	mes "Why?";
	next;
	cutin "ep162_dn03",2;
	mes "[ Dien ]";
	mes "Oh my, oh my!";
	mes "What should we do!";
	next;
	cutin "ep162_rds04",2;
	mes "[ Ridsh ]";
	mes "Why, what's going on?";
	next;
	cutin "ep162_dn03",2;
	mes "[ Dien ]";
	mes "I think I've left it.";
	next;
	cutin "ep162_rds01",2;
	mes "[ Ridsh ]";
	mes "Left what?";
	next;
	cutin "ep162_dn03",2;
	mes "[ Dien ]";
	mes "My protection charm!";
	mes "I get nervous if I don't have it with me.";
	next;
	cutin "ep162_rds04",2;
	mes "[ Ridsh ]";
	mes "You've been fine so far without it?!";
	next;
	cutin "ep162_dn03",2;
	mes "[ Dien ]";
	mes "...";
	next;
	cutin "ep162_rds01",2;
	mes "[ Ridsh ]";
	mes "Ah... Sorry..";
	mes "Alright.";
	next;
	mes "[ Ridsh ]";
	mes "While we open the last door, would you mind going back to ^FF0000Clana Nemieri^000000?";
	next;
	mes "[ Ridsh ]";
	mes "I have to contact a few people anyway, and Dien won't go anywhere until she gets her protection charm.";
	next;
	mes "[ Ridsh ]";
	mes "Sister, tell me where it is.";
	next;
	cutin "ep162_dn02",2;
	mes "[ Dien ]";
	mes "Oh!";
	mes "Thank you so much for that";
	next;
	mes "[ Dien ]";
	mes "It's hard for me to get it back because it's far...";
	mes "Please do me a favor.";
	next;
	cutin "ep162_dn01",2;
	mes "[ Dien ]";
	mes "^FF0000Go back to my room and look for a chest on the left side of the window, near a vase.";
	next;
	mes "[ Dien ]";
	mes "It should be easy to get since we're here.";
	next;
	cutin "ep162_rds05",2;
	mes "[ Ridsh ]";
	mes "Oh!";
	mes "Shouldn't we tell them where we are?";
	ep_illusion = 32;
	completequest 11600;
	setquest 11601;
	getitem 25669,25;
	getexp 600000,600000;
	close2;
	warp "ein_fild03",258,267;
	instance_destroy();
	end;
	
OnInstanceInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"isbegin_quest(11600) == 1");
end;
}

1@os_b,260,363,5	script	Cotnes#s_os5	4_F_COATNEIS,{
	cutin "ep162_ctn01",2;
	mes "[ Cotnes ]";
	mes "It's good sometimes to take a walk like this~";
	close3;
}

1@os_b,262,362,5	script	Erst#s_os2	4_F_ESTLOVELOY,{
	cutin "ep162_est01",2;
	mes "[ Erst ]";
	mes "I want to explore the next area.";
	close3;
}

1@os_b,261,358,3	script	Ridsh#s_os4	4_F_LEEDSH,{
	cutin "ep162_rds01",2;
	mes "[ Ridsh ]";
	mes "I'm tired!";
	mes "I want to go home.";
	close3;
}


//= Mob

1@os_b,1,1,0	script	#sealedos_mob_1	HIDDEN_WARP_NPC,{
OnSpawn:
	.@map$ = get_instance_var("map$");
	npctalk "Cotnes : This way.",instance_npcname("Dien#s_os2");
	sleep 1500;
	npctalk "Dien : Oh my... what a surprise!",instance_npcname("Dien#s_os2");
	sleep 1500;
	npctalk "Dien : We will take care of these, please take care of the gnarly ones!",instance_npcname("Dien#s_os2");
	monster .@map$,205,46,"Dolor",20361,1,instance_npcname(strnpcinfo(0)) + "::OnMobKill";
	monster .@map$,200,45,"Twin Caput",20365,1,instance_npcname(strnpcinfo(0)) + "::OnMobKill";
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		instance_enable(strnpcinfo(0),false);
		set_instance_var("s_os",2);
		instance_enable("Suspicious Device#s_os_trigger",true);
		mapannounce .@map$,"Ridsh : While we are dealing with the enemies, turn of the device at the bottom.",bc_map,0xFF0000;
	}
end;
}

1@os_b,204,266,0	script	#s_os_trap_0	4_PURPLE_WARP,2,3,{
	end;
	
OnTouch:
	.@i = atoi(replacestr(strnpcinfo(2),"s_os_trap_",""));
	if(get_instance_var("trap[" + .@i + "]"))
		end;
	.@map$ = get_instance_var("map$");
	switch(.@i){
		case 0: setarray .@xy,209,264,20363,209,268,20355; break;		
		case 1: setarray .@xy,234,269,20357,236,266,20357; break;		
		case 2: setarray .@xy,250,268,20363,252,266,20355; break;
		case 3: setarray .@xy,263,285,20361,259,286,20365; break;
		case 4: setarray .@xy,262,303,20355,258,306,20355; break;
		case 5: setarray .@xy,262,318,20363,259,320,20361; break;
		case 6: setarray .@xy,258,336,20365,263,338,20355; break;
	}
	set_instance_var("trap[" + .@i + "]",1);
	for(.@j = 0; .@j < getarraysize(.@xy); .@j += 3)
		monster .@map$,.@xy[.@j],.@xy[.@j+1],"--ja--",.@xy[.@j+2],1,instance_npcname(strnpcinfo(0))+"::OnMobKill";
end;
	
OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
	}
end;
}

1@os_b,229,267,0	duplicate(#s_os_trap_0)	#s_os_trap_1	4_PURPLE_WARP,2,3
1@os_b,244,267,0	duplicate(#s_os_trap_0)	#s_os_trap_2	4_PURPLE_WARP,2,3
1@os_b,261,281,0	duplicate(#s_os_trap_0)	#s_os_trap_3	4_PURPLE_WARP,2,3
1@os_b,261,299,0	duplicate(#s_os_trap_0)	#s_os_trap_4	4_PURPLE_WARP,2,3
1@os_b,261,314,0	duplicate(#s_os_trap_0)	#s_os_trap_5	4_PURPLE_WARP,2,3
1@os_b,261,332,0	duplicate(#s_os_trap_0)	#s_os_trap_6	4_PURPLE_WARP,2,3

//= Warp/Other
1@os_b,187,52,0	script	#os_lock_00	WARPNPC,3,4,{
	end;
	
OnTouch:
	.@map$ = get_instance_var("map$");
	.@ev = atoi(replacestr(strnpcinfo(2),"os_lock_0",""));
	switch(.@ev){
		case 0:
		case 1:
		case 2:
			warp .@map$,188,41;
			break;
			
		case 3:
		case 4:
			.@var = get_instance_var("s_os");
			if(.@var < 8){
				cutin "ep162_dn01",2;
				mes "[ Dien ]";
				mes "It would be better to just go around the door.";
				npctalk "Dien : It would be better to just go around the door.",instance_npcname("Dien#s_os5"),bc_map;
				close2;
				cutin "",255;
			}
			warp .@map$,114,204;
			break;
			
		case 5:
			warp .@map$,142,220;
			break;
	}
end;
}

1@os_b,191,46,0	duplicate(#os_lock_00)	#os_lock_01	WARPNPC,3,4
1@os_b,192,49,0	duplicate(#os_lock_00)	#os_lock_02	WARPNPC,3,4
1@os_b,118,209,0	duplicate(#os_lock_00)	#os_lock_03	WARPNPC,3,4	
1@os_b,119,215,0	duplicate(#os_lock_00)	#os_lock_04	WARPNPC,3,4
1@os_b,147,224,0	duplicate(#os_lock_00)	#os_lock_05	WARPNPC,2,2

1@os_b,203,53,5	duplicate(dummynpc2)	#s_os_dummy00	20357
1@os_b,202,55,3	duplicate(dummynpc2)	#s_os_dummy01	20357
1@os_b,198,53,3	duplicate(dummynpc2)	#s_os_dummy02	20355
1@os_b,199,55,5	duplicate(dummynpc2)	#s_os_dummy03	20355
1@os_b,201,52,3	duplicate(dummynpc2)	#s_os_dummy04	20363
1@os_b,200,54,3	duplicate(dummynpc2)	#s_os_dummy05	20361
1@os_b,194,250,5	duplicate(dummynpc2)	#s_os_dummy06	20357
1@os_b,196,250,3	duplicate(dummynpc2)	#s_os_dummy07	20355
1@os_b,195,251,3	duplicate(dummynpc2)	#s_os_dummy08	20363
1@os_b,205,256,4	duplicate(dummynpc2)	#s_os_dummy09	20365
1@os_b,193,274,4	duplicate(dummynpc2)	#s_os_dummy10	20365
1@os_b,199,274,4	duplicate(dummynpc2)	#s_os_dummy11	20361
1@os_b,205,274,4	duplicate(dummynpc2)	#s_os_dummy12	20363
1@os_b,213,256,4	duplicate(dummynpc2)	#s_os_dummy13	20357
1@os_b,125,230,4	duplicate(dummynpc2)	#s_os_dummy14	20365
1@os_b,129,230,4	duplicate(dummynpc2)	#s_os_dummy15	20361
1@os_b,228,276,4	duplicate(dummynpc2)	#s_os_dummy16	20361
1@os_b,243,276,4	duplicate(dummynpc2)	#s_os_dummy17	20361
1@os_b,231,276,4	duplicate(dummynpc2)	#s_os_dummy18	20365
1@os_b,240,276,4	duplicate(dummynpc2)	#s_os_dummy19	20365
1@os_b,260,261,4	duplicate(dummynpc2)	#s_os_dummy20	20365
1@os_b,262,261,4	duplicate(dummynpc2)	#s_os_dummy21	20363
1@os_b,265,268,4	duplicate(dummynpc2)	#s_os_dummy22	20361
1@os_b,252,279,5	duplicate(dummynpc2)	#s_os_dummy23	20363
1@os_b,252,300,5	duplicate(dummynpc2)	#s_os_dummy24	20363
1@os_b,252,298,5	duplicate(dummynpc2)	#s_os_dummy25	20361
1@os_b,266,283,3	duplicate(dummynpc2)	#s_os_dummy26	20355
1@os_b,134,230,4	duplicate(dummynpc2)	#s_os_dummy27	20363