//===== rAthena Script ===========================================|
//= Episode 17.1 Cor Operation                                   =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

sp_cor,113,130,3	script	Rebellion#cor_02	4_M_REBELLION3,{
	if(ep_illusion < 47){
		mes "[ Rebellion ]";
		mes "Oh, you're the adventurer? It's been a too long. Did you come to see me?";
		next;
		select("Do you know me?:No...");
		mes "[ Rebellion ]";
		mes "Oh, it's cold adventurer. Too cold. I don't like the cold.";
		mes "I'm in charge here, but I don't know anyone.";
		next;
		mes "[ Rebellion ]";
		mes "But the adventurer knows me well, thank you for passing by!";
		mes "I also brought the right weapons and armor for the job, I'm wearing warm clothes~!";
		close;
	}
	switch(checkquest(16377,PLAYTIME)){
		case -1: 
			break;
		case 0: 
		case 1:
			mes "[ Rebellion ]";
			mes "Mina is feeling more relaxed.";
			mes "Mina's lovely children are resting?";
			next;
			classchange(4_EP17_ELYUMINA,"Elyumina#os_merchant",bc_self);	
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "... the security devices that summon monsters are still at lower power. Don't touch them the can overheat.";
			npctalk "Elyumina : Argh.. please, despicable title, don't call me that, don't!","Elyumina#os_merchant",bc_self;
			next;
			cutin "",255;
			mes "[ Rebellion ]";
			mes "If Mina's children needs to rest, you can come back in the morning after dawn!";
			next;
			cutin "ep171_elyumina02",0;
			mes "[ Elyumina ]";
			mes "After dawn, they will have charged up enough so that you can go back!";
			unittalk getcharid(3),strcharinfo(0) + " : She handles this surprisingly well...",bc_self;
			close3;
			
		case 2:
			break;
	}
	switch(checkquest(16376)){
		case -1:
			mes "[ Rebellion ]";
			mes "Oh, adventurer. I haven't seen you in a while! I wanted to ask you something. It's about Mina...";
			unittalk getcharid(3),strcharinfo(0)+ " : Mina?",bc_self;
			next;
			cloaknpc("Elyumina#os_merchant",false,getcharid(0));
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "Here, I'll explain. My children who attacked you the last time you followed me...";
			npctalk "Elyumina : Hey, don't call me that. It's such a terrible nickname!","Elyumina#os_merchant",bc_self;
			unittalk getcharid(3),strcharinfo(0)+ " : Oh, he meant you.",bc_self;
			next;
			cutin "",255;
			mes "[ Rebellion ]";
			mes "Yep, remember Mina's kids you catched last time? They were sleeping.";
			next;
			cutin "ep171_elyumina02",0;
			mes "[ Elyumina ]";
			mes "Mine! Machines and traps! In emergencies, they go in stealth mode and low power mode. And they stay like that for a while. I'll be back soon and see them.";
			next;
			cutin "",255;
			mes "[ Rebellion ]";
			mes "That's right, Mina...";
			unittalk getcharid(3),strcharinfo(0)+ " : ... you made them, you can just turn them off.",bc_self;
			next;
			cutin "ep171_elyumina02",0;
			mes "[ Elyumina ]";
			mes "No! I can't. They have a state of the art machine learning module.";
			mes "You guys on that day were the strongest data they had ever seen.";
			next;
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "Well...! They don't recognize me as their master now. Just as I expected...";
			mes "The best way is to slowly consume their energy, weaken them slowly and neutralize them.";
			npctalk "Rebellion : So we should go with Mina...","",bc_self;
			next;
			mes "[ Elyumina ]";
			mes "That's all I can do... for now, you are the only one who can defeat EL1-A17T. Of course, I'm coming too, but I'm just going to collect more data on my children.";
			next;
			cutin "",255;
			mes "[ Rebellion ]";
			mes "I want to follow along, but somehow Mina is stubborn. Is she worried I will be in danger?";
			next;
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "Anyway, it may be best for you to bring friends along.";
			mes "It will be a hard journey and I'm still a detainee.";
			npctalk "Elyumina : Absolutely not!!!","Elyumina#os_merchant",bc_self;
			next;
			cutin "",255;
			mes "[ Rebellion ]";
			mes "So there will be me and Mina, along with you and...";
			next;
			cutin "ep171_elyumina02",0;
			mes "[ Elyumina ]";
			mes "I will give you detailed explanation inside!!! Come on, tell me you're going!!!";
			mes "Please do it before he kills me!";
			setquest 16376;
			completequest 16376;
			next;
			cutin "",255;
			break;
			
		
		case 2:
			mes "[ Rebellion ]";
			mes "It's time for Mina's children to wake up, adventurer!";
			mes "Will they patiently wait this time around?";
			next;
			cloaknpc("Elyumina#os_merchant",false,getcharid(0));	
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "... they're no longer on low power and the security devices are operation again.";
			next;
			cutin "ep171_elyumina02",0;
			mes "[ Elyumina ]";
			mes "Will you meet with Cor again and will you collect more data?";
			mes "Let me know please, I want to get away from this guy.";
			next;
			cutin "",255;
			break;	
	}
	.@md_name$ = "Cor Mission 2";
	.@party_id = getcharid(1);
	.@party_name$ = getpartyname(.@party_id);
	if(!.@party_id){
		mes "[ Rebellion ]";
		mes "Well? Mina says it will be difficult on her own. Come back with a party, adventurer.";
		close;
	}
	mes "[ Rebellion ]";
	mes "That's too bad, adventurer. To participate in the operation, you must prepare a party.";
	next;
	mes "[ Rebellion ]";
	mes "After the memorial dungeon is created, once all the party members enter the operation, the adventurer can start sending the signal~";
	next;
	switch(select("Create Operation.:Enter Operation.:Cancel")){
		case 1:
			switch(instance_create(.@md_name$,IM_PARTY)){
				case -1:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "Unknown Error Has Occurred.";
					end;
				case -2:
					mes "[ Rebellion ]";
					mes "Well? Mina says it will be difficult on her own. Come back with a party, adventurer.";
					close;
				case -3:
					mes "[ Rebellion ]";
					mes "You already have an instance active. Please cancel it before proceeding.";
					close;
					
				case -4:
					mes "^0000ff"+.@md_name$+" ^000000 - Reservation Failed!";
					mes "^0000ff"+.@md_name$+" ^000000 is currently full.";
					end;
					
				default:
					mes "[ Rebellion ]";
					mes "Okay, when everyone is ready. Please talk to me again and choose 'Enter'";
					npctalk "Eheh, I'm not afraid of you.","",bc_self;
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
					if(!isbegin_quest(16363))
						setquest 16363;
					setquest 16377;
					end;
			}
			
		case 3:
			break;
	}
	end;			
}

sp_cor,180,169,3	script	Elena Bolkova#cor_op	4_F_ELENA,{
	switch(ep_illusion){
		case 41:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "You're a little late. Well, we're all late.";
			mes "Elyumina is missing. The battle was very quick and we got knocked out.";
			mes "Damn it!";
			next;
			mes "[ Elena Bolkova ]";
			mes "I won't stop until we catch her, although we should probably rest first.";
			next;
			mes "[ Elena Bolkova ]";
			mes "After discussing this with the Rebellion captains, we decided to search the area by bringing an entire troop of elites.";
			next;
			mes "[ Elena Bolkova ]";
			mes "The president and Kaya have also agreed with our plan.";
			next;
			mes "[ Elena Bolkova ]";
			mes "Among the USU and the Rebellion only the elite members have been chosen, and I'm in command. The rest of the Rebellion will block and surround the entrance and other nearby areas.";
			next;
			mes "[ Elena Bolkova ]";
			mes "This operation, of course, also includes your support adventurer. I strongly recommend that you prepare first. Will you join us?";
			next;
			select("Of course.");
			mes "[ Elena Bolkova ]";
			mes "Okay!";
			mes "For now, I have selected those who can act alone, including myself.";
			mes "You will need to make a ^0000FFparty of 1^000000 and come back to me.";
			ep_illusion = 42;
			completequest 16353;
			setquest 16354;
			questinfo_refresh();
			close3;
			
		case 42:
			.@party_id = getcharid(1);
			.@md_name$ = "Cor Mission";
			.@party_name$ = getpartyname(.@party_id);
			if(!.@party_id){
				cutin "162elena_01",2;
				mes "[ Elena Bolkova ]";
				mes "For now, I have selected those who can act alone, including myself.";
				mes "You will need to make a ^0000FFparty of 1^000000 and come back to me.";
				close3;
			}
			for(.@i = 0; .@i < 6; .@i++)
				cloaknpc("Rebellion#cor_ms_" + .@i,false,getcharid(0));
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "The blockage of the area is over.";
			mes "Let's start the mission!";
			mes "It's not too late. Gentlemen, get ready!";
			next;
			mes "[ Elena Bolkova ]";
			mes "Good, among the elite of the brave Rebellion, your specific goal will be to capture the researcher.";
			npctalk "Elena Bolkova : She's the one who holds all the key information, we have to capture her.","",bc_self;
			npctalk "I'm ready!","Rebellion#cor_ms_0",bc_self;
			npctalk ".....","Rebellion#cor_ms_1",bc_self;
			npctalk "I'm ready!","Rebellion#cor_ms_2",bc_self;
			npctalk "I'm ready!","Rebellion#cor_ms_3",bc_self;
			npctalk "I'm ready!","Rebellion#cor_ms_4",bc_self;
			npctalk "I'm ready!","Rebellion#cor_ms_5",bc_self;
			next;
			cutin "162elena_02",2;
			mes "[ Elena Bolkova ]";
			mes "Adventurer, choose 'Create' and wait a moment when you want to go.";
			mes "Choose 'Enter' after.";
			npctalk "Elena Bolkova : Alright, ready? These bastards will face us.","",bc_self;
			npctalk "If they don't mind...","Rebellion#cor_ms_0",bc_self;
			npctalk ".....","Rebellion#cor_ms_1",bc_self;
			npctalk "It won't be easy, will it?","Rebellion#cor_ms_2",bc_self;
			npctalk "The time has come for us to show off!","Rebellion#cor_ms_3",bc_self;
			npctalk "Time for us to go!","Rebellion#cor_ms_4",bc_self;
			npctalk "Why are you smiling?","Rebellion#cor_ms_5",bc_self;
			next;
			switch(select("Create Operation.:Enter Operation.:Cancel")){
				case 1:
					switch(instance_create(.@md_name$)){
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
							mes "[ Elena Bolkova ]";
							mes "Talk to me again when you're ready. The operation is going to start soon.";
							close3;
					}

				case 2:
					getpartymember .@party_id,3;
					if($@partymembercount != 1){
						cutin "162elena_01",2;
						mes "[ Elena Bolkova ]";
						mes "For now, I have selected those who can act alone, including myself.";
						mes "You will need to make a ^0000FFparty of 1^000000 and come back to me.";
						close3;
					}
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
							end;
					}
					
				case 3:
					mes "[ Elena Bolkova ]";
					mes "Talk to me again when you're ready. The operation is going to start soon.";
					end;
			}
			
		case 43:
			cutin "162elena_02",2;
			mes "[ Elena Bolkova ]";
			mes "So much trouble! Aha, these guys are all so trustworthy.";
			mes "Of course, the adventurer is too!";
			next;
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Elyumina was captured safely. Now that the attacks have stopped, this should be a safe place.";
			next;
			mes "[ Elena Bolkova ]";
			mes "The Secret Wings and Lucky are ready to interrogate her.";
			mes "It looks like they're organizing a meeting place where we defeated the scrap metal machine.";
			next;
			mes "[ Elena Bolkova ]";
			mes "I'm not getting involved there because I'd squeeze my target rather than listening to what they're saying..";
			mes "Gonie will also observe the interrogation.";
			next;
			mes "[ Elena Bolkova ]";
			mes "Join them on that <NAVI>[side]<INFO>sp_cor,136,210,0,000,0</INFO></NAVI>.";
			mes "Lucky will be asking the questions.";
			ep_illusion = 44;
			completequest 16357;
			setquest 16358;
			getitem 25668,1;
			getitem 25723,5;
			questinfo_refresh();
			close3;
			
		case 44: 
		case 45:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Join them on that <NAVI>[side]<INFO>sp_cor,136,210,0,000,0</INFO></NAVI>.";
			mes "Lucky will be asking the questions.";
			close3;
			
		case 46: 
		case 47:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Hey. Are you busy?";
			mes "I'll have to go through a lot of things and then the Rebellion will be going back home.";
			next;
			mes "[ Elena Bolkova ]";
			mes "It's quite hard to manage the Rebellion, especially in places like these.";
			next;
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "When things have calmed down, come to Clana Nemieri and let's have a drink.";
			mes "I'd rather fight you than this machines.";
			emotion ET_KIK;
			close3;

		default:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Well? Adventurer. Don't go too far alone. I know you're skilled, but the others are nervous.";
			next;
			mes "[ Elena Bolkova ]";
			mes "There may be other equipments or evidence left behind from the people who ran away in a hurry.";
			next;
			cutin "162elena_02",2;
			mes "[ Elena Bolkova ]";
			mes "Me? Why am I alone? Are you worried about me? Ahahaha!";
			close3;
	}
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 41";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 42";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 43";
end;
}

sp_cor,177,165,1	duplicate(dummynpc)	Rebellion#cor_ms_0	4_M_REBELLION3
sp_cor,180,165,1	duplicate(dummynpc)	Rebellion#cor_ms_1	4_M_GONY
sp_cor,183,165,1	duplicate(dummynpc)	Rebellion#cor_ms_2	4_F_REBELLION3
sp_cor,177,163,1	duplicate(dummynpc)	Rebellion#cor_ms_3	4_F_ANYA
sp_cor,180,163,1	duplicate(dummynpc)	Rebellion#cor_ms_4	4_M_ILYA
sp_cor,183,163,1	duplicate(dummynpc)	Rebellion#cor_ms_5	4_F_REBELLION2

1@cor,1,1,0	script	#171_cor_control	-1,{
	end;
	
OnInstanceInit:
	.@type$ = instance_live_info(ILI_NAME);
	if(.@type$ == "Cor Mission 2")
		.@type = 1;
	set_instance_var("map$",instance_mapname("1@cor"));
	.@map$ = get_instance_var("map$");
	setcell .@map$,159,216,159,225,CELL_WALKABLE,0;
	setcell .@map$,159,216,159,225,CELL_SHOOTABLE,0;
	setcell .@map$,98,216,98,225,CELL_WALKABLE,0;
	setcell .@map$,98,216,98,225,CELL_SHOOTABLE,0;	
	setcell .@map$,132,240,141,240,CELL_WALKABLE,0;
	setcell .@map$,132,240,141,240,CELL_SHOOTABLE,0;
	for(.@i = 0; .@i < 4; .@i++){
		instance_enable("Box#cor_d_box_" + .@i,false);
		instance_enable("Rebellion#cor_s_box_" + .@i,false);
		instance_enable("Box#cor_s_box_" + .@i,false);
		instance_enable("Elyumina#cor_d_box_" + .@i,false);
	}
	instance_enable("Rebellion#cor_s_box_4",false);
	instance_enable("Elena Bolkova#cor_s2",false);
	instance_enable("#cor_ms_warp",false);
	instance_enable("Elena Bolkova#cor_s3",false);
	instance_enable("Elyumina#cor_end",false);
	instance_enable("Rebellion#cor_end1",false);
	instance_enable("Rebellion#cor_end2",false);
	instance_enable("Elyumina#cor_d2",false);	
	switch(.@type){
		case 0:
			for(.@i = 0; .@i < 6; .@i++)
				instance_hide("Rebellion#cor_op_" + .@i,true);
			instance_enable("Elena Bolkova#cor_d",false);
			instance_enable("Elyumina#cor_d",false);
		break;
			
		case 1:
			for(.@i = 0; .@i < 6; .@i++)
				instance_enable("Rebellion#cor_op_" + .@i,false);
			instance_enable("Elena Bolkova#cor_s",false);
			instance_hide("Elyumina#cor_d",true);
		break;
	}
end;

OnEventStory01:
	set_instance_var("cor_mission",1);
	for(.@i = 0; .@i < 6; .@i++){
		instance_hide("Rebellion#cor_op_" + .@i,true);
		instance_enable("Rebellion#cor_op_" + .@i,false);
	}
	instance_hide("Elena Bolkova#cor_s",true);
	instance_enable("Elena Bolkova#cor_s",false);
	for(.@i = 0; .@i < 4; .@i++){
		instance_enable("Rebellion#cor_s_box_" + .@i,true);
		instance_enable("Box#cor_s_box_" + .@i,true);
	}
	instance_enable("Rebellion#cor_s_box_4",true);
end;

OnEventStory02:
	.@map$ = get_instance_var("map$");
	set_instance_var("cor_mission",5);
	instance_hide("Rebellion#cor_s_box_1",true);
	instance_hide("Rebellion#cor_s_box_0",true);
	instance_hide("Rebellion#cor_s_box_4",true);
	instance_hide("Box#cor_s_box_0",true);
	instance_hide("Box#cor_s_box_1",true);
	instance_enable("Rebellion#cor_s_box_1",false);
	instance_enable("Rebellion#cor_s_box_0",false);
	instance_enable("Rebellion#cor_s_box_4",false);
	instance_enable("Box#cor_s_box_0",false);
	instance_enable("Box#cor_s_box_1",false);
	mapannounce .@map$,"Elena Bolkova : Awesome, she came out! I've sent the signal, come to my location!",bc_yellow;
	instance_enable("Elena Bolkova#cor_s2",true);
	viewpoint 1,172,223,5,0xFFFFFF;
	viewpoint 2,160,119,2,0xFFFFFF;
	viewpoint 2,140,79,1,0xFFFFFF;
	instance_event(strnpcinfo(0),"OnCenterPoint",false);
end;

OnEventStory03:
	instance_event(strnpcinfo(0),"OnRemoveCenter",false);
	instance_hide("Elena Bolkova#cor_s2",true);
	instance_enable("Elena Bolkova#cor_s2",false);
	instance_event("#cor_ms_warp","OnActive",false);
	instance_event("#cor_mob_boss","OnSpawn",false);
end;

OnCenterPoint:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 1,172,223,5,0xFFFFFF;
end;

OnRemoveCenter:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,172,223,5,0xFFFFFF;
end;

OnEventDaily01:
	set_instance_var("cor_mission",1);
	instance_hide("Elyumina#cor_d",true);
	instance_hide("Elena Bolkova#cor_d",true);
	instance_enable("Elena Bolkova#cor_d",false);
	instance_enable("Elyumina#cor_d",false);
	for(.@i = 0; .@i < 4; .@i++){
		instance_enable("Elyumina#cor_d_box_" + .@i,true);
		instance_enable("Box#cor_d_box_" + .@i,true);
	}
end;

OnEventDaily02:
	.@map$ = get_instance_var("map$");
	set_instance_var("cor_mission",6);
	instance_event(strnpcinfo(0),"OnCenterPoint",false);
	mapannounce .@map$,"Elena Bolkova : Once you've covered all of them, come to the barracks and Elyumina will guide you!",bc_yellow;
	instance_enable("Elyumina#cor_d2",true);
end;

OnEventDaily03:
	instance_event(strnpcinfo(0),"OnRemoveCenter",false);
	instance_hide("Elyumina#cor_d2",true);
	instance_enable("Elyumina#cor_d2",false);
	instance_event("#cor_ms_warp","OnActive",false);
	instance_event("#cor_mob_boss","OnSummon",false);
end;
}

1@cor,178,172,3	duplicate(dummynpc2)	Elyumina#cor_d	4_EP17_ELYUMINA

1@cor,180,169,3	script	Elena Bolkova#cor_s	4_F_ELENA,4,4,{
	if(is_party_leader() == false)
		end;
	.@var = get_instance_var("cor_mission");
	if(!.@var){
		set_instance_var("party_id",getcharid(1));
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "I'll start explaining the operation. First...";
		specialeffect EF_SCREEN_QUAKE;
		for(.@i = 0; .@i < 6; .@i++)
			instance_hide("Rebellion#cor_op_" + .@i,false);		
		next;
		mes "[ Elena Bolkova ]";
		mes "I'll start explaining the operation. First...";		
		mes "... now everyone is up to date.";
		next;
		cutin "",255;
		mes "[ Rebellion ]";
		mes "Something has exploded over there.";
		mes "The flames have risen from the front!";
		next;
		mes "[ Rebellion ]";
		mes "There are 4 identified locations these explosion came from! I have ^0000FFshown them on your minimap.^000000";
		viewpoint 1,140,79,1,0xFFFFFF;
		viewpoint 1,160,119,2,0xFFFFFF;
		viewpoint 1,220,170,3,0xFFFFFF;	
		viewpoint 1,222,236,4,0xFFFFFF;
		next;
		mes "[ Elena Bolkova ]";
		mes "I'm changing the operation.";
		mes "Don't worry about those already at the front, they can manage with any situation.";
		next;
		mes "[ Elena Bolkova ]";
		mes "Divide into 4 teams, everyone at their own locations and start suppressing the leads. If any team finds Elyumina, let us know immediately.";
		next;
		mes "[ Elena Bolkova ]";
		mes "Everyone, to your position! Start the operation!";
		npctalk "Yes!",instance_npcname("Rebellion#cor_op_0");
		npctalk ".....",instance_npcname("Rebellion#cor_op_1");
		npctalk "Yes!",instance_npcname("Rebellion#cor_op_2");
		npctalk "Yes!",instance_npcname("Rebellion#cor_op_3");
		npctalk "Yes!",instance_npcname("Rebellion#cor_op_4");
		npctalk "Yes!",instance_npcname("Rebellion#cor_op_5");
		next;
		cutin "162elena_02",2;
		mes "[ Elena Bolkova ]";
		mes "I ask you to act separately adventurer. Please check ^0000FFyour minimap^000000 to organize the situationn as quickly as possible. Join the team if they need support!";
		close2;
		cutin "",255;
		instance_event("#171_cor_control","OnEventStory01",false);
	}
	end;
	
OnTouch:
	npctalk "Elena Bolkova : This way. Let's gather and brief our troops.";
end;
}

1@cor,172,223,3	script	Elena Bolkova#cor_s2	4_F_ELENA,{
	if(is_party_leader() == false)
		end;
	.@var = get_instance_var("cor_mission");
	if(.@var == 5){
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "I've been waiting for you. I've found the crazy researcher.";
		mes "The other guys are surrounding the place.";
		next;
		mes "[ Elena Bolkova ]";
		mes "In order to control such a machine in such a fine manner, Elyumina must be around.";
		next;
		mes "[ Elena Bolkova ]";
		mes "It would be possible for me to handle this machine, but then I wouldn't be able to catch Elyumina.";
		next;
		mes "[ Elena Bolkova ]";
		mes "If you take care of the machine, the other search parties will take care of finding Elyumina.";
		next;
		cutin "162elena_02",2;
		mes "[ Elena Bolkova ]";
		mes "The Rebellion squad is well coordinated, this work will be best suited for us. So leave that task to us.";
		next;
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "The place we'll enter will be at 9 o'clock. I confirmed that nobody was hiding there, and we blocked the exits.";
		next;
		mes "[ Elena Bolkova ]";
		mes "Give me a signal when you're ready to get in. I'll tell the squad to let you in.";
		next;
		if(select("Give signal.:I haven't signaled yet.") == 2){
			mes "[ Elena Bolkova ]";
			mes "Yes it's a dangerous opponent to face. I'm sorry to have to leave you alone to fight. Let me know when you're ready.";
			close3;
		}
		cutin "162elena_02",2;
		mes "[ Elena Bolkova ]";
		mes "Okay, watch out! I opened the portal so that you can go in. It's a one way entry, so be prepared!";
		close2;
		cutin "",255;
		viewpoint 2,172,223,5,0xFFFFFF;
		instance_event("#171_cor_control","OnEventStory03",false);
	}
	end;
}

1@cor,180,169,3	script	Elena Bolkova#cor_d	4_F_ELENA,4,4,{
	if(is_party_leader() == false)
		end;
	.@var = get_instance_var("cor_mission");
	if(!.@var){
		set_instance_var("party_id",getcharid(1));
		instance_hide("Elyumina#cor_d",false);
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "Here's the situation... Actually, the criminal will be giving you the briefing.";
		mes "It's easier for her to explain.";
		npctalk "Elena Bolkova : Here's the situation... Actually, the criminal will be giving you the briefing. It's easier for her to explain";
		next;
		cutin "ep171_elyumina04",0;
		mes "[ Elyumina ]";
		mes "Ahah! Are these you guys? I expected better. At least give me a description?";
		npctalk "Ahah! Are these you guys? I expected better. At least give me a description?",instance_npcname("Elyumina#cor_d");
		next;
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "So noisy. Alright, let's get started. Are you part of the PSU now?";
		npctalk "So noisy. Alright, let's get started. Are you part of the PSU now?";
		next;
		cutin "ep171_elyumina03",0;
		mes "[ Elyumina ]";		
		mes "Yes, I am... are you afraid of me?";
		mes "Hey, I'll do the explaining because those are my children behind there!";
		npctalk "Yes, I am... are you afraud of me? Hey, I'll do the explaining because those are my children behind there!",instance_npcname("Elyumina#cor_d");
		next;
		cutin "ep171_elyumina01",0;
		mes "[ Elyumina ]";
		mes "Okay, it's time...";
		mes "My children will place traps in four places.";
		npctalk "Okay, it's time... My children will place traps in four places.",instance_npcname("Elyumina#cor_d");
		next;
		mes "[ Elyumina ]";
		mes "Take the map, here. It will be passed down to the party members as well.";
		mes "You aren't alone right? You know my kids are powerful?";
		npctalk "Take the map, here. It will be passed down to the party members as well.",instance_npcname("Elyumina#cor_d");
		next;
		mes "[ Elyumina ]";
		mes "Go ahead and trigger the traps. My lovely kids will appear when they are activated.";
		mes "I've spent a lot of time on each trap, you know?";
		npctalk "Go ahead and trigger the traps. My lovely kids will appear when they are activated.",instance_npcname("Elyumina#cor_d");
		next;
		cutin "ep171_elyumina03",0;
		mes "[ Elyumina ]";
		mes "After you've cleared all the four traps, EL1-A17T will come out. You'll be fighting him at the same place last time.";
		npctalk "After you've cleared all the four traps, EL1-A17T will come out. You'll be fighting him at the same place last time.",instance_npcname("Elyumina#cor_d");
		next;
		cutin "ep171_elyumina04",0;
		mes "[ Elyumina ]";
		mes "Here's the description. Come on now, get to work! You muscle idiots! Ahahahah!";
		npctalk "Here's the description. Come on now, get to work! You muscle idiots! Ahahahah!",instance_npcname("Elyumina#cor_d");
		next;
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "...I'll have a conversation with this criminal in a bit... Anyway, I'm counting on you, adventurers!";
		npctalk "...I'll have a conversation with this criminal in a bit... Anyway, I'm counting on you, adventurers!";
		close2;
		cutin "",255;
		viewpoint 1,140,79,1,0xFFFFFF;
		viewpoint 1,160,119,2,0xFFFFFF;
		viewpoint 1,220,170,3,0xFFFFFF;	
		viewpoint 1,222,236,4,0xFFFFFF;
		instance_event("#171_cor_control","OnEventDaily01",false);
		instance_event(strnpcinfo(0),"OnActiveView",false);
	}
	end;
	
OnActiveView:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$){
		setarray .@xy,140,79,160,119,220,170,222,236;
		for(.@i = 0; .@i < getarraysize(.@xy); .@i += 2){
			if(get_instance_var("cor_d_box_" +.@i) < 2)
				viewpoint 1,.@xy[.@i],.@xy[.@i+1],.@i+1,0xFFFFFF;
		}
	}
end;
}

1@cor,172,223,3	script	Elyumina#cor_d2	4_EP17_ELYUMINA,{
	if(is_party_leader() == false)
		end;	
	.@var = get_instance_var("cor_mission");
	if(.@var == 6){
		cutin "ep171_elyumina03",0;
		mes "[ Elyumina ]";
		mes "That was fast... It was expected that my kids wouldn't win though.";
		mes "There's a lot more trouble going on up there~";
		npctalk "Elyumina : That was fast... It was expected that my kids wouldn't win though. There's a lot more trouble going on up there~";
		next;
		cutin "ep171_elyumina01",0;
		mes "[ Elyumina ]";
		mes "... are you going straight for my EL1-A17T?";
		mapannounce .@map$,"Elena Bolkova : Yeah, damn criminal! Why don't you open the portal right now?",bc_yellow;
		npctalk "Elyumina : ... are you going straight for my EL1-A17T?";
		next;
		if(select("Go in.:Don't go in yet.") == 2){
			cutin "ep171_elyumina02",0;
			mes "[ Elyumina ]";
			mes "Come on, I was about to open it.";
			close3;
		}
		cutin "ep171_elyumina04",0;
		mes "[ Elyumina ]";
		mes "Hahaha! Yes. Let's work hard. Get more battle data for me!";
		npctalk "Elyumina : Hahaha! Yes. Let's work hard. Get more battle data for me!";
		close2;
		cutin "",255;
		viewpoint 2,172,223,5,0xFFFFFF;
		instance_event("#171_cor_control","OnEventDaily03",false);
	}
	end;
	
OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,172,223,5,0xFFFFFF;
end;
}

//= Story NPC
1@cor,138,82,5	script	Rebellion#cor_s_box_0	4_F_ANYA,{
	mes "[ Rebellion ]";
	mes "Did I tell you that I'm really happy working with the Secret Wing? Thanks to them, I was chosen for this operation.";
	next;
	mes "[ Rebellion ]";
	mes "Let's show them what we're all about, and that we're good guys.";
	close;	
}

1@cor,160,117,1	script	Rebellion#cor_s_box_1	4_M_GONY,{
	mes "[ Rebellion ]";
	mes ".....";
	end;
}

1@cor,218,172,5	script	Rebellion#cor_s_box_2	4_F_REBELLION2,{
	.@var = get_instance_var(strnpcinfo(2));
	if(.@var == 2){
		mes "[ Rebellion ]";
		mes "It's an awful but interesting device. It wasn't a device meant to summon monsters.";
		next;
		mes "[ Rebellion ]";
		mes "After summoning monsters, it constantly releases chemical poison, making it even more difficult to remove the monster.";
		next;
		mes "[ Rebellion ]";
		mes "If you touch the chemical poison, it will spread like bomb. You shouldn't get any closer.";
		next;
		mes "[ Rebellion ]";
		mes "So, it looks like this is over, I'll go join another team! You should too.";
		viewpoint 2,220,170,3,0xFFFFFF;
		close2;
		set_instance_var("cor_mission",get_instance_var("cor_mission") + 1);
		instance_hide(strnpcinfo(0),true);
		instance_hide("Box#cor_s_box_2",true);
		instance_enable(strnpcinfo(0),false);
		instance_enable("Box#cor_s_box_2",false);
		instance_event(strnpcinfo(0),"OnRemove",false);
		if(get_instance_var("cor_mission") == 3)
			instance_event("#171_cor_control","OnEventStory02",true);
	}
	end;
	
OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,220,170,3,0xFFFFFF;
end;
}

1@cor,224,238,3	script	Rebellion#cor_s_box_3	4_M_REBELLION3,{
	.@var = get_instance_var(strnpcinfo(2));
	if(.@var == 2){
		mes "[ Rebellion ]";
		mes "Sorry for the late analysis. It wasn't a device to summon monsters.";
		next;
		mes "[ Rebellion ]";
		mes "After summoning the monsters, it summons a bio-battery to strengthen the monsters and explodes.";
		next;
		mes "[ Rebellion ]";
		mes "If you want to handle it, just destroy it. It's good because it's a simple solution.";
		next;
		mes "[ Rebellion ]";
		mes "Well, it looks like this is over....";
		next;
		mes "[ Rebellion ]";
		mes "It looks like you've found something interesting here. You should check out the other teams!";
		viewpoint 2,222,236,4,0xFFFFFF;
		close2;
		set_instance_var("cor_mission",get_instance_var("cor_mission") + 1);
		instance_hide(strnpcinfo(0),true);
		instance_hide("Box#cor_s_box_3",true);
		instance_enable(strnpcinfo(0),false);
		instance_enable("Box#cor_s_box_3",false);
		if(get_instance_var("cor_mission") == 3)
			instance_event("#171_cor_control","OnEventStory02",true);
	}
	end;
	
OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,222,236,4,0xFFFFFF;
end;
}

1@cor,142,82,3	script	Rebellion#cor_s_box_4	4_M_ILYA,{
	mes "[ Rebellion ]";
	mes "I haven't seen you in a while adventurer.";
	next;
	mes "[ Rebellion ]";
	mes "I already know you adventurer, but please be careful.";
	close;
}

1@cor,161,221,0	script	#cor_ms_warp	WARPNPC,2,2,{
	end;
	
OnActive:
	instance_enable(strnpcinfo(0),true);
	specialeffect EF_BASH;
	specialeffect EF_READYPORTAL;
end;

OnTouch:
	.@map$ = get_instance_var("map$");
	warp .@map$,151,220;
end;
}

1@cor,140,82,3	script	Elyumina#cor_d_box_0	4_EP17_ELYUMINA,{
	.@var = get_instance_var("cor_mission");
	if(.@var == 6){
		npctalk "Elyumina : You know where the barrack is? I showed it up on your minimap. I'll follow you soon.";
		instance_event("#171_cor_control","OnCenterPoint",false);
		end;
	}
	.@num = get_instance_var(strnpcinfo(2));
	if(.@num == 1){
		npctalk "Elyumina : You have so much free time, you're chatting during battle? Huh, it's a little annoying.";
		end;
	} else 
	if(.@num == 2){
		npctalk "Elyumina : Very good combat data... Well, you can go ahead now!";
		end;
	}
	if(.@var)
		npctalk "Elyumina : Here, here! Please be careful. Touch the box and it will activate.";
	end;
}

1@cor,162,117,3	duplicate(Elyumina#cor_d_box_0)	Elyumina#cor_d_box_1	4_EP17_ELYUMINA
1@cor,218,172,5	duplicate(Elyumina#cor_d_box_0)	Elyumina#cor_d_box_2	4_EP17_ELYUMINA
1@cor,224,238,3	duplicate(Elyumina#cor_d_box_0)	Elyumina#cor_d_box_3	4_EP17_ELYUMINA

1@cor,140,79,3	script	Box#cor_s_box_0	4_WOODBOX,{
	mes "[ Rebellion ]";
	mes "Hello adventurer.";
	specialeffect EF_M03;
	next;
	mes "[ Rebellion ]";
	mes "It was nice to be part of this squad, we've already taken care of this box.";
	next;
	mes "[ Rebellion ]";
	mes "These machines uses chemical poison, be careful.";
	next;
	mes "[ Rebellion ]";
	mes "We will now conduct our search, until the signal comes. Adventurer, be careful!";
	viewpoint 2,140,79,1,0xFFFFFF;
	close2;
	instance_hide("Rebellion#cor_s_box_0",true);
	instance_hide("Rebellion#cor_s_box_4",true);
	instance_hide(strnpcinfo(0),true);
	instance_enable("Rebellion#cor_s_box_0",false);
	instance_enable("Rebellion#cor_s_box_4",false);
	instance_enable(strnpcinfo(0),false);
	instance_event(strnpcinfo(0),"OnRemove",false);
	end;
	
OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,140,79,1,0xFFFFFF;
end;
}


1@cor,140,79,3	script	Box#cor_d_box_0	4_WOODBOX,{
	.@var = get_instance_var(strnpcinfo(2));
	if(!.@var)
		instance_event(strnpcinfo(0),"OnSpawn",false);
	end;
	
OnSpawn:
	set_instance_var(strnpcinfo(2),1);
	.@map$ = get_instance_var("map$");
	specialeffect EF_BAKU;
	setarray .@xy,141,78,20356,141,80,20343,140,73,20343,137,72,20356,138,83,20356,133,83,20342,143,78,20342,144,79,20342,145,80,20342,143,82,20342,145,76,20342;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,instance_npcname(strnpcinfo(0))+"::OnMobKill";
	sleep 1500;
	monster .@map$,140,79,"",20344,1,instance_npcname(strnpcinfo(0))+"::OnPoisonKill";
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var(strnpcinfo(2),2);
		set_instance_var("cor_mission",get_instance_var("cor_mission") + 1);
		killmonster .@map$,instance_npcname(strnpcinfo(0))+"::OnPoisonKill";
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_event(strnpcinfo(0),"OnRemove",false);
		viewpoint 2,140,79,1,0xFFFFFF;
		if(get_instance_var("cor_mission") == 5)
			instance_event("#171_cor_control","OnEventDaily02",false);
	}
end;

OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,140,79,1,0xFFFFFF;
end;

OnPoisonKill:
end;
}


1@cor,160,119,3	script	Box#cor_s_box_1	4_STEELBOX,{
	mes "[ Rebellion ]";
	mes ".....";
	specialeffect EF_M03;
	next;
	mes "[ Rebellion ]";
	mes ".....";
	next;
	mes "- Smoke is rising from a box that looks suspicious. -";
	next;
	select("Have you done this already?:Are you still silent?");
	mes "[ Rebellion ]";
	mes ".....";
	next;
	mes "[ Rebellion ]";
	mes "*Nods, nods*";
	next;
	mes "- Let's go support another team. -";
	viewpoint 2,160,119,2,0xFFFFFF;
	close2;
	instance_hide("Rebellion#cor_s_box_1",true);
	instance_hide(strnpcinfo(0),true);
	instance_enable("Rebellion#cor_s_box_1",false);
	instance_enable(strnpcinfo(0),false);
	instance_event(strnpcinfo(0),"OnRemove",false);
	end;
	
OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,160,119,2,0xFFFFFF;
end;
}

1@cor,160,119,3	script	Box#cor_d_box_1	4_STEELBOX,{
	.@var = get_instance_var(strnpcinfo(2));
	if(!.@var)
		instance_event(strnpcinfo(0),"OnSpawn",false);
	end;
	
OnSpawn:
	set_instance_var(strnpcinfo(2),1);
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	specialeffect EF_BAKU;
	setarray .@xy,159,114,20355,159,113,20343,162,113,20343,162,114,20341,167,112,20355,164,117,20341,165,117,20341,168,119,20341,156,123,20341,156,124,20341,159,127,20355;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$ ;
	sleep 1000;
	while(mobcount(.@map$,.@event$)){
		if(mobcount(.@map$,.@event$))
			monster .@map$,160,119,"",20345,1,instance_npcname(strnpcinfo(0))+"::OnBombKill";
		sleep 10000;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var(strnpcinfo(2),2);
		set_instance_var("cor_mission",get_instance_var("cor_mission") + 1);
		killmonster .@map$,instance_npcname(strnpcinfo(0))+"::OnBombKill";
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_event(strnpcinfo(0),"OnRemove",false);
		viewpoint 2,160,119,2,0xFFFFFF;
		if(get_instance_var("cor_mission") == 5)
			instance_event("#171_cor_control","OnEventDaily02",false);
	}
end;

OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,160,119,2,0xFFFFFF;
end;

OnBombKill:
end;
}


1@cor,220,170,3	script	Box#cor_s_box_2	4_WOODBOX,{
	.@var = get_instance_var(strnpcinfo(2));
	if(!.@var){
		mes "[ Rebellion ]";
		mes "The cause of the explosion is unknown, but I've found this suspicious box at the site. It seems to be some sort of mechanism.";
		next;
		mes "[ Rebellion ]";
		mes "There is a signal inside... Huh, be careful.";
		mes "Something's happenning!";
		close2;
		specialeffect EF_BAKU;
		instance_event(strnpcinfo(0),"OnSpawn",false);
	}
	end;

OnSpawn:
	set_instance_var(strnpcinfo(2),1);
	.@map$ = get_instance_var("map$");
	setarray .@xy,224,164,20342,215,175,20342,222,174,20342;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,instance_npcname(strnpcinfo(0))+"::OnMobKill";
	sleep 1500;
	monster .@map$,220,170,"",20344,1,instance_npcname(strnpcinfo(0))+"::OnPoisonKill";
end;

OnPoisonKill:
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var(strnpcinfo(2),2);
		killmonster .@map$,instance_npcname(strnpcinfo(0))+"::OnPoisonKill";
		npctalk "They suffered! Please listen to what I have to say before helping another team.",instance_npcname("Rebellion#cor_s_box_2");
		viewpoint 2,220,170,3,0xFFFFFF;
	}
end;
}

1@cor,220,170,3	script	Box#cor_d_box_2	4_WOODBOX,{
	.@var = get_instance_var(strnpcinfo(2));
	if(!.@var)
		instance_event(strnpcinfo(0),"OnSpawn",false);
	end;
	
OnSpawn:
	set_instance_var(strnpcinfo(2),1);
	.@map$ = get_instance_var("map$");
	specialeffect EF_BAKU;
	setarray .@xy,222,168,20356,223,166,20343,219,162,20356,219,158,20343,215,158,20343,220,170,20342,219,169,20342,221,171,20342,217,177,20342,215,171,20342,227,175,20342,226,176,20356;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,instance_npcname(strnpcinfo(0))+"::OnMobKill";
	sleep 1500;
	monster .@map$,220,170,"",20344,1,instance_npcname(strnpcinfo(0))+"::OnPoisonKill";
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var(strnpcinfo(2),2);
		set_instance_var("cor_mission",get_instance_var("cor_mission") + 1);
		killmonster .@map$,instance_npcname(strnpcinfo(0))+"::OnPoisonKill";
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_event(strnpcinfo(0),"OnRemove",false);
		viewpoint 2,220,170,3,0xFFFFFF;
		if(get_instance_var("cor_mission") == 5)
			instance_event("#171_cor_control","OnEventDaily02",false);
	}
end;

OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,220,170,3,0xFFFFFF;
end;

OnPoisonKill:
end;
}

1@cor,222,236,3	script	Box#cor_s_box_3	4_STEELBOX,{
	.@var = get_instance_var(strnpcinfo(2));
	if(!.@var){
		mes "[ Rebellion ]";
		mes "The cause of the explosion is unknown, but I've found this suspicious box at the site. It seems to be some sort of mechanism.";
		next;
		mes "[ Rebellion ]";
		mes "There is a signal inside... Huh, be careful.";
		mes "Something's happenning!";
		close2;
		specialeffect EF_BAKU;
		instance_event(strnpcinfo(0),"OnSpawn",false);
	}
	end;
	
OnSpawn:
	set_instance_var(strnpcinfo(2),1);
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	setarray .@xy,229,232,20341,223,239,20341,218,237,20341;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,instance_npcname(strnpcinfo(0))+"::OnMobKill";
	sleep 1000;
	while(mobcount(.@map$,.@event$)){
		if(mobcount(.@map$,.@event$))
			monster .@map$,222,236,"",20345,1,instance_npcname(strnpcinfo(0))+"::OnBombKill";
		sleep 10000;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var(strnpcinfo(2),2);
		viewpoint 2,222,236,4,0xFFFFFF;
		killmonster .@map$,instance_npcname(strnpcinfo(0))+"::OnBombKill";
	}
end;

OnBombKill:
end;
}

1@cor,222,236,3	script	Box#cor_d_box_3	4_STEELBOX,{
	.@var = get_instance_var(strnpcinfo(2));
	if(!.@var)
		instance_event(strnpcinfo(0),"OnSpawn",false);
	end;
	
OnSpawn:
	set_instance_var(strnpcinfo(2),1);
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	specialeffect EF_BAKU;
	setarray .@xy,224,236,20343,219,224,20343,212,243,20343,216,236,20355,223,228,20355,224,238,20355,222,234,20341,219,236,20341,220,238,20341,224,239,20341,226,240,20341,218,244,20341;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
	sleep 1000;
	while(mobcount(.@map$,.@event$)){
		if(mobcount(.@map$,.@event$))
			monster .@map$,222,236,"",20345,1,instance_npcname(strnpcinfo(0))+"::OnBombKill";
		sleep 10000;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var(strnpcinfo(2),2);
		set_instance_var("cor_mission",get_instance_var("cor_mission") + 1);
		killmonster .@map$,instance_npcname(strnpcinfo(0))+"::OnBombKill";
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_event(strnpcinfo(0),"OnRemove",false);
		viewpoint 2,222,236,4,0xFFFFFF;
		if(get_instance_var("cor_mission") == 5)
			instance_event("#171_cor_control","OnEventDaily02",false);
	}
end;

OnRemove:
	.@map$ = get_instance_var("map$");
	addrid(1,1);
	if(strcharinfo(3) == .@map$)
		viewpoint 2,222,236,4,0xFFFFFF;
end;

OnBombKill:
end;
}

1@cor,138,221,3	script	Elena Bolkova#cor_s3	4_F_ELENA,{
	.@var = get_instance_var("cor_mission");
	if(.@var == 4){
		cutin "162elena_02",2;
		mes "[ Elena Bolkova ]";
		mes "Good work, " +strcharinfo(0)+ ". The operation was a success!";
		mes "She was running away, but I think she was upset because you broke the scrap metal box.";
		next;
		cutin "ep171_elyumina02",0;
		mes "[ Elyumina ]";
		mes "Scrap metal! It's a masterpiece! My child!";
		mes "You! You... hurt my child! I will crush you!";
		next;
		cutin "162elena_02",2;
		mes "[ Elena Bolkova ]";
		mes "Are you calling these scrap of metals your child now?";
		mes "Well, kids are good. We pay the price for our child's mistakes.";
		next;
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "What are you going to do now " + strcharinfo(0) + "?";
		next;
		if(select("I'm going right back.:I'll stay here for a bit") == 2){
			mes "[ Elena Bolkova ]";
			mes "Alright, let me know when you're ready to go out.";
			close3;
		}
		mes "[ Elena Bolkova ]";
		mes "Good work. We'll be clearing things up here, you can take a break. I'm going to interrogate her. Take a break and then come back to me.";
		ep_illusion = 43;
		completequest 16354;
		setquest 16357;
		setquest 16377;
		close2;
		warp "sp_cor",176,169;
		instance_destroy();
	}
	if(.@var == 7){
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "Ah yes. It suffered this time. Perfect! How long did it take you to stop this scrap metal?";
		next;
		cutin "ep171_elyumina02",0;
		mes "[ Elyumina ]";
		mes "Did you just say scrap metal?! You witch!";
		next;
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "Yeah yeah, it wasn't a scrap metal at first. But now it is. Anyway, thank you the help. You go back and rest now.";
		next;
		if(select("Go back.:Stay for a moment.") == 2){
			mes "[ Elena Bolkova ]";
			mes "Alright, let me know when you're ready to go out.";
			close3;
		}
		if(checkquest(16363,HUNTING) == 2){
			getitem 25669,5;
			getitem 25723,1;
			erasequest 16363;
		}
		warp "sp_cor",111,125;
		end;
	}
	end;
}

1@cor,140,221,3	script	Elyumina#cor_end	4_EP17_ELYUMINA,{ npctalk "Elyumina : You guys... killed him?! You slayers! Executioners!"; end;}
1@cor,141,223,3	script	Rebellion#cor_end1	4_M_ILYA,{ npctalk "We've captured the researcher, Elyumina!"; end;}
1@cor,141,221,3	script	Rebellion#cor_end2	4_F_ANYA,{ npctalk "We've completed the capture, the operation is over!"; end;}

//= To do create SC
1@cor,226,233,0	script	#cor_buff_0	HIDDEN_WARP_NPC,{
	end;
}

1@cor,1,1,0	script	#cor_mob_boss	-1,{
	end;
	
OnSpawn:
	.@map$ = get_instance_var("map$");
	monster .@map$,138,221,"--ja--",20340,1,instance_npcname(strnpcinfo(0))+"::OnBossKill";
	.@boss_id = $@mobid[0];
	getunitdata .@boss_id ,.@boss;
	.@MAX_HP = .@boss[3];
	.@DAMAGE = (.@MAX_HP/10) * 9;
	.@HP = (.@MAX_HP - .@DAMAGE);
	setunitdata .@boss_id ,UMOB_HP,.@HP;
	//mapannounce .@map$,"Elyumina : It's beginning to spread. Prepare yourself!",bc_yellow;	
end;

OnSummon:
	//Todo add script skills from boss
	.@map$ = get_instance_var("map$");
	monster .@map$,138,221,"--ja--",20340,1,instance_npcname(strnpcinfo(0))+"::OnDailyKill";
	.@boss_id = $@mobid[0];
end;

OnBossKill:
	set_instance_var("cor_mission",4);
	instance_enable("Elena Bolkova#cor_s3",true);
	instance_enable("Elyumina#cor_end",true);
	instance_enable("Rebellion#cor_end1",true);
	instance_enable("Rebellion#cor_end2",true);	
end;

OnDailyKill:
	.@map$ = get_instance_var("map$");
	set_instance_var("cor_mission",7);
	instance_enable("Elena Bolkova#cor_s3",true);
	instance_enable("Elyumina#cor_end",true);
end;
}


1@cor,177,165,1	duplicate(dummynpc2)	Rebellion#cor_op_0	4_M_REBELLION3
1@cor,180,165,1	duplicate(dummynpc2)	Rebellion#cor_op_1	4_M_GONY
1@cor,183,165,1	duplicate(dummynpc2)	Rebellion#cor_op_2	4_F_REBELLION3
1@cor,177,163,1	duplicate(dummynpc2)	Rebellion#cor_op_3	4_F_ANYA
1@cor,180,163,1	duplicate(dummynpc2)	Rebellion#cor_op_4	4_M_ILYA
1@cor,183,163,1	duplicate(dummynpc2)	Rebellion#cor_op_5	4_F_REBELLION2

1@cor,159,218,0	duplicate(dummynpc2)	#cor_barricade_00	4_ROPEPILE
1@cor,159,220,0	duplicate(dummynpc2)	#cor_barricade_01	4_ROPEPILE
1@cor,159,222,0	duplicate(dummynpc2)	#cor_barricade_02	4_ROPEPILE
1@cor,159,224,0	duplicate(dummynpc2)	#cor_barricade_03	4_ROPEPILE
1@cor,98,218,0	duplicate(dummynpc2)	#cor_barricade_04	4_ROPEPILE
1@cor,98,220,0	duplicate(dummynpc2)	#cor_barricade_05	4_ROPEPILE
1@cor,98,222,0	duplicate(dummynpc2)	#cor_barricade_06	4_ROPEPILE
1@cor,98,224,0	duplicate(dummynpc2)	#cor_barricade_07	4_ROPEPILE
1@cor,134,240,0	duplicate(dummynpc2)	#cor_barricade_08	4_ROPEPILE
1@cor,136,240,0	duplicate(dummynpc2)	#cor_barricade_09	4_ROPEPILE
1@cor,138,240,0	duplicate(dummynpc2)	#cor_barricade_10	4_ROPEPILE
1@cor,140,240,0	duplicate(dummynpc2)	#cor_barricade_11	4_ROPEPILE