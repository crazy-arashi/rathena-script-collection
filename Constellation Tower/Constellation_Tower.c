//===== rAthena script ===========================================|
//= Constellation Tower                                          =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//= 1.1 Added 300/400/600% Bonus Drops                           =|
//================================================================|

-	script	ctower_init	-1,{
	end;

OnInit:
	disablenpc "Captain Janssen";
	disablenpc "Tower Protection Stone";
	disablenpc "Huge Vortex";
end;
}

alberta,214,77,6	script	Captain Janssen#ctower	709,{
	if(checkweight(1201,1) == 0){
		mes "[ Captain Janssen ]";
		mes "^008800Wait here!!";
		mes "You're carrying too much stuff. Why don't you put some of it away, and then come back.^000000";
		close;
	}
	if(BaseLevel < 240){
		mes "[ Captain Janssen ]";
		mes "I'm sorry adventurer, but those who are below level 240 won't be allowed to enter the Misty Island anymore. It was a measure decided by the Fisherman Union because of the meteor that fell the other day.";
		next;
		if(select("I see.:What's happening.") == 1){
			mes "[ Captain Janssen ]";
			mes "You're a pretty good lad, aren't you? You'd better be careful and save your life.";
			close;
		}
		mes "[ Captain Janssen ]";
		mes "Oh. Is this your first time? The Misty Island used to have an old tower called the ^0000CDEndless Tower^000000.";
		next;
		mes "[ Captain Janssen ]";
		mes "But a new owner has of the tower has appeared, the name seems to have changed also. I didn't have the courage to go inside the island by myself.";
		next;
		mes "[ Captain Janssen ]";
		mes "With your ability now, it will be hard to come back alive if you go there. I don't want to see young adventurer die because of a useless bravado.";
		close;
	}
	mes "[ Captain Janssen ]";
	mes "Oh, you seem capable. Do you want to go to the Misty Island?";
	mes "It would be 10,000 Zeny. Are you ready to go?";
	next;
	if(select("Misty Island?:Let's go.") == 1){
		mes "[ Captain Janssen ]";
		mes "Oh. Is this your first time? The Misty Island used to have an old tower called the ^0000CDEndless Tower^000000.";
		next;
		mes "[ Captain Janssen ]";
		mes "But a new owner has of the tower has appeared, the name seems to have changed also. I didn't have the courage to go inside the island by myself.";
		next;
		mes "[ Captain Janssen ]";
		mes "With your ability now, you would be fine... I think.";
		close;
	}
	if(Zeny < 10000){
		mes "[ Captain Janssen ]";
		mes "I'm sorry, you don't have enough Zeny for the payment. I need you to atleast bring me that for the supply and the danger that I'm heading into.";
		close;
	}
	mes "[ Captain Janssen ]";
	mes "Alright! Then, we are prepared to soil. Let's go!";
	Zeny -= 10000;
	close2;
	warp "e_tower",70,114;
	end;
}

e_tower,70,114,0	script	#ctower_ev	HIDDEN_WARP_NPC,4,4,{
	end;

OnTouch:
	cloaknpc("Oscar#ctower",false);
	specialeffect 1145,AREA,"Oscar#ctower";
	if(isbegin_quest(12513) == 2){
		cloaknpc("OSC0007#ctower",false);
		cloaknpc("OSC0008#ctower",false);
	}
end;
}

e_tower,78,112,5	script	OSC0007#ctower	2_DROP_MACHINE,{
	mes "^0000CDThe barely functioning machine started up^000000";
	callshop "ctower_shop",1;
	end;

OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

e_tower,80,110,5	script	OSC0008#ctower	2_SLOT_MACHINE,{
	mes "^0000CDThis machine can strengten your star equipments.^000000";
	next;
	.@s = select("Cancel:Power:Stamina:Concentration:Creative:Spell:Wisdom") - 1;
	switch(.@s){
		case 0:
			end;

		default:
			.@id = 6 + .@s;
			break;
	}
	enchantui(.@id);
	end;

OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

e_tower,30,30,2	script	Huge Vortex#ctower	844,2,2,{
	if(select("Return to Alberta:Cancel") == 1)
		warp "alberta",223,36;
	end;
}

e_tower,68,116,6	duplicate(dummynpc)	Leticia#ctower	4_4JOB_LETICIA

e_tower,72,116,2	script	Oscar#ctower	4_ED_OSCAR,{
	emotion ET_THROB;
	if(isbegin_quest(12513) == 0){
		mes "^0000CDOscar is talking to someone.^000000";
		next;
		if(select("Step back.:Listen to him secretly.") == 1){
			mes "^0000CDWell, eavesdropping is not a good thing to do.^000000";
			close;
		}
		cutin "OSCAR03",0;
		mes "[ Oscar ]";
		mes "So this mess isn't your work, correct?";
		next;
		cloaknpc("Leticia#ctower",false,getcharid(0));
		cutin "4job_leticia_02.png",2;
		mes "[ Leticia ]";
		mes "What kind of constellation do you think I am. Those prejudices doesn't really help on improving relationships!";
		next;
		cutin "OSCAR05",0;
		mes "[ Oscar ]";
		mes "I thought you've smashed this place up for a warm up. I never thought you were that violent. But I do think you're pretty aggresive kid.";
		next;
		cutin "4job_leticia_05.png",2;
		mes "[ Leticia ]";
		mes "No matter how hot-tempered I am, I'm not brave enough to do such a thing in an area that you manage, Oscar.";
		next;
		cutin "OSCAR05",0;
		mes "[ Oscar ]";
		mes "Well, that's true, you were certainly a kid who atleast know her limits.";
		next;
		emotion ET_THROB;
		cutin "4job_leticia_04.png",2;
		mes "[ Leticia ]";
		mes "Of course! And the rest is history. I don't know who did it, but he broke that ugly tower in half, maybe I should completely break it...";
		next;
		cutin "OSCAR03",0;
		mes "[ Oscar ]";
		mes "As expected, you wanted to destroy this place, don't you? Thank you for honesty and confessing your preferences.";
		next;
		cutin "4job_leticia_02.png",2;
		mes "[ Leticia ]";
		mes "What do you mean preference? It's a misunderstanding!";
		next;
		select("(I shouldn't have witness this scene.)");
		cutin "OSCAR01",0;
		mes "[ Oscar ]";
		mes "Oh, " + strcharinfo(0) + ". You're finally here. I was sure that you would come with all this fuss.";
		next;
		select("Were you waiting for me?");
		cutin "4job_leticia_02.png",2;
		mes "[ Leticia ]";
		mes "Oscar, who's that creature? Why are you talking to Oscar like you're on the same level as him?";
		next;
		cutin "OSCAR03",0;
		mes "[ Oscar ]";
		mes "You must speak politely, Leticia. I have asked for this adventurer's help many times.";
		next;
		select("(He suddenly changed his tone?)");
		cutin "OSCAR04",0;
		mes "[ ^88AA66Oscar's Voice^000000 ]";
		mes "[^88AA66Leticia! I told you that you should be careful of what you say when you're on this place. Was my lecture not enough?^000000]";
		next;
		cutin "4job_leticia_05.png",2;
		mes "[ Leticia ]";
		mes "Ah... Ah!!! That's the adventurer that you're talking about, isn't it? I know. I'm familiar with the stories.";
		next;
		select("Nice to meet you.");
		emotion ET_THROB;
		next;
		cutin "4job_leticia_04.png",2;
		mes "[ ^88AA66Leticia^000000 ]";
		mes "[^88AA66I'm in front of Oscar, so I'll show you some courtesy. But don't expect that it'll be the same when you and I are alone.^000000]";
		next;
		cutin "OSCAR01",0;
		mes "[ Oscar ]";
		mes "I can feel something different and familiar about the place where the tower was destroyed. I have to go see it for myself. Leticia, are you available now?";
		next;
		cutin "4job_leticia_01.png",2;
		mes "[ Leticia ]";
		mes "Of course! Should I destroy the rest of the tower?";
		next;
		cutin "OSCAR04",0;
		mes "[ Oscar ]";
		mes "I'm not asking you to destroy it. Leticia, for now, let's explore the part of the tower reamins. I'll take the adventurer to the entrance and look around in it.";
		next;
		select("Can I go in too?");
		cutin "OSCAR03",0;
		mes "[ Oscar ]";
		mes "Of course. " + strcharinfo(0) + " is the only person I know who can overcome this situation. There's no other option.";
		next;
		cutin "4job_leticia_01.png",2;
		mes "[ Leticia ]";
		mes "Then, I'll head in first!";
		next;
		cloaknpc("Leticia#ctower",true,getcharid(0));
		sleep2 300;
		cutin "OSCAR03",0;
		mes "[ Oscar ]";
		mes "I'm going to release the sealed entrance. In the meantime, you should prepare to enter it.";	
		close2;
		cutin "",255;
		setquest 12513;
		end;
	}
	switch(checkquest(12514,PLAYTIME)){
		case -1: 
			break;
		
		case 0:
		case 1:
			cutin "OSCAR03",2;
			mes "[ Oscar ]";
			mes "^0000CDYou'd had enough travel time for today.^000000 You need to rest up your body to do another dimensional travel. Come back again when you rest your body enough.";
			close3;	
			
		case 2:
			erasequest 12514;
			break;
	}
	.@party_id = getcharid(1);
	if(!.@party_id){
		cutin "OSCAR01",2;
		mes "[ Oscar ]";
		mes "I can only activate it for you adventurer. Please create a party of your own and talk to me again.";
		close3;
	}
	cutin "OSCAR01",0;
	mes "[ Oscar ]";
	mes "Are you ready to enter the tower? Then, please hold my hand and concentrate.";
	next;
	.@md_name$ = "Constellation Tower";
	if(select("Enter.",(is_party_leader() ? "Create Constellation Tower." : "")) == 1){
		if(instance_enter(.@md_name$) == IE_OK){
			.@party_name$ = getpartyname(.@party_id);
			setquest 12514;
			mapannounce "e_tower", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00FF99";
		} else
			mes "^0000FFThe memorial dungeon has not been created yet or you're entering a different memorial dungeon from the one created.^000000";
	} else {
		if(instance_create(.@md_name$) == -3)
			instance_warning(2,.@md_name$);
	}
	cutin "",255;
	end;

OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

1@ch_t,1,1,0	script	#ctower_control	-1,{
    end;

OnInstanceInit:
    instance_enable("#oscar_ctower_1",true);
	instance_hide("#ctower_jump",true);
	instance_enable("#ctower_fountain",false);
    instance_event(strnpcinfo(0),"OnCreateFloor",false);
	instance_enable("#ctower_button",false);
	for(.@i = 1; .@i < 4; .@i++)
		instance_enable("#ctower_betel_" + .@i,false);
	for(.@i = 1; .@i < 13; .@i++)
		instance_enable("#ctower_treasure_" + .@i,false);
	for(.@i = 0; .@i < 10; .@i++)
		instance_enable("#ctower_trap_" + .@i,false);
	for(.@i = 0; .@i < 16; .@i++)
		instance_enable("#ctower_trap2_" + .@i,false);
	instance_enable("#ctower_exit",false);
end;

OnCreateFloor:
	freeloop(true);
    for(.@i = 1; .@i < 51; .@i++){
        .@mvp_id = 0;
        .@mob_id = 0;
        .@type = rand(2,6);
        .@amount = rand(.@type,.@type + 8);
		deletearray .@mob_list[0];
		deletearray .@floor$[0];
        for(.@x = 0; .@x < .@type; .@x++){
            .@mob_id = rand(20998,21046);
            while(inarray(.@mob_list,.@mob_id) != -1)
               .@mob_id = rand(20998,21046);
            .@mob_list[.@x] = .@mob_id; 
        }
        for(.@x = 0; .@x < .@amount; .@x++){
            if(.@x <= (.@type - 1))
                .@floor$[.@x] = .@mob_list[.@x];
            else
                .@floor$[.@x] = .@mob_list[rand(getarraysize(.@mob_list))];
        }
        if(.@i % 5 == 0){
            .@mvp_id = rand(21325,21358);
            while(inarray(.@mvp_list,.@mvp_id) != -1)
                .@mvp_id = rand(21325,21358);
            .@mvp_list[getarraysize(.@mvp_list)] = .@mvp_id;
			set_instance_var("floor_" + .@i + "_mvp",.@mvp_id);
        }
        set_instance_var("floor_" + .@i + "$",implode(.@floor$,":"));
    }
	freeloop(false);
end;
}

1@ch_t,1,1,0	script	#ctower_mob	HIDDEN_WARP_NPC,{
	end;

OnSummon:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnMobKill";
	.@event2$ = instance_npcname(strnpcinfo(0)) + "::OnBossKill";
	.@floor = get_instance_var("floor");
	killmonster .@map$,.@event$;
	killmonster .@map$,.@event2$;
	cleanmap get_instance_var("map$");
	explode(.@T$,get_instance_var("floor_" + .@floor + "$"),":");
	set_instance_var("unlocked_" + get_instance_var("area"),0);
	switch(get_instance_var("area")){
		case 1:	.@x1 = 7; .@y1 = 177; .@x2 = 18; .@y2 = 217; break;
		case 2: .@x1 = 92; .@y1 = 177; .@x2 = 100; .@y2 = 217; break;
		case 3: .@x1 = 180; .@y1 = 177; .@x2 = 188; .@y2 = 217; break;
		case 4: .@x1 = 266; .@y1 = 177; .@x2 = 275; .@y2 = 217; break;
		case 5: .@x1 = 350; .@y1 = 177; .@x2 = 360; .@y2 = 217; break;
	}
	for(.@i = 0; .@i < getarraysize(.@T$); .@i++){
		areamonster .@map$,.@x1,.@y1,.@x2,.@y2,"--ja--",atoi(.@T$[.@i]),1,.@event$;
		unitskilluseid $@mobid[0],"NPC_RELIEVE_ON",9;
	}
	if(.@floor % 5 == 0){
		areamonster .@map$,365,207,375,218,"--ja--",get_instance_var("floor_" + .@floor + "_mvp"),1,.@event2$;
		unitskilluseid $@mobid[0],"NPC_RELIEVE_ON",9;
	}
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnMobKill";
	if(!mobcount(.@map$,.@event$))
		set_instance_var("unlocked_" + get_instance_var("area"),1);
end;

OnBossKill: //Nothing happens when you kill the boss, you can unlock the floor without killing it
end;
}

1@ch_t,46,188,6	script	#oscar_ctower_1	4_ED_OSCAR,{
	cutin "OSCAR01",2;
	mes "[ Oscar ]";
    if(!is_party_leader()){	
		mes "Did your party leader came in here with you? We don't have much time to have a leisure talk.";
		close3;
    }
	mes "Are you ready? If you're ready, we will immediately start climbing the tower, yes?";
	next;
	if(select("Please wait a minute!:Start right away.") == 1){
		mes "[ Oscar ]";
		mes "We don't have much time. Please hurry.";
		close3;
	}
	close2;
	cutin "",255;
	instance_disable(strnpcinfo(0));
	set_instance_var("map$",instance_mapname("1@ch_t"));
	instance_hide("#ctower_jump",false);
	set_instance_var("area",1);
	set_instance_var("floor",1);
	.@party_id = getcharid(1);
	getpartymember .@party_id,0;
	getpartymember .@party_id,1;
	getpartymember .@party_id,2;
	set_instance_var("party_id",.@party_id);
	.@count = $@partymembercount;
	if(.@count > 0){
		.@map$ = get_instance_var("map$");
		for(.@i = 0; .@i < $@partymembercount; .@i++){
			if(!isloggedin($@partymemberaid[.@i],$@partymembercid[.@i])) continue;
			if(strcharinfo(3,$@partymembercid[.@i]) != .@map$) continue;
			.@cid[.@x] = $@partymembercid[.@i];
			.@aid[.@x] = $@partymemberaid[.@i];
			.@name$[.@x] = $@partymembername$[.@i];
			.@x++;
		}
	}
	set_instance_var("count",.@x);
	for(.@i = 0; .@i < .@x; .@i++){
		set_instance_var("cid_" + .@i,.@cid[.@i]);
		set_instance_var("aid_" + .@i,.@aid[.@i]);
		set_instance_var("name_" + .@i + "$",.@name$[.@i]);
	}
	instance_event("#ctower_mob","OnSummon",false);
	mapannounce get_instance_var("map$"),"Oscar : The majority of the monsters on the lower floors are dead. As you go up, they seem to preserve their original strength.",bc_map,0xCCFF99;
	sleep 2000;
	mapannounce get_instance_var("map$"),"Oscar : I'm afraid that someone from the top floor might attack you and kick you out from here.",bc_map,0xCCFF99;
	sleep 2000;
	mapannounce get_instance_var("map$"),"Oscar : Be careful anyway. I'm going to lif the seals that are blocking the floor.",bc_map,0xCCFF99;
	end;
}

1@ch_t,50,188,0	script	#ctower_jump	CLEAR_NPC,{
	if(!is_party_leader()) end;
	.@floor = get_instance_var("floor") + 4;
	.@used = get_instance_var("jump");
	.@required = 50 + ( .@used * 25 );
	mes "^0000CDThe braziers desires a tribute.^000000";
	next;
	if(select("Cancel.","Move to the " + .@floor + "th floor using " + .@required + " " + getitemname(1000372) + ".") == 1) end;
	if(countitem(1000372) < .@required){
		mes "^FF0000You don't have enough " + getitemname(1000372) + " that the braziers desires.";
		end;
	}
	delitem 1000372,.@required;
	set_instance_var("floor",.@floor);
	set_instance_var("area",5);
	set_instance_var("jump",.@used + 1);
	instance_event("#ctower_mob","OnSummon",false);
	instance_warpall get_instance_var("map$"),390,183,instance_id();
	end;
}

1@ch_t,13,221,1	script	#ctower_warp_1	PORTAL,{
	if(!is_party_leader()) end; //Members can't talk to it
	if(get_instance_var("floor") == 25){
		mes "There seems to be a gap between these dimension. Will you stop climbing the tower and enter the gap?";
		next;
		switch(select("Cancel.:Head into the gap.:^0000CDContinue climbing^000000")){
			case 1:
				mes "This is an important decision to make, please think wisely.";
				end;

			case 2:
				mes "Once you head into another dimension gap, you won't be able to return in this one. Do you really want to head into it?";
				next;
				if(select("Cancel:Yes!") == 1){
					mes "This is an important decision to make, please think wisely.";
					end;
				}
				instance_warpall instance_mapname("3@ch_t"),32,17,instance_id();
				set_instance_var("mode",1);
				end;

			case 3:
				break;
		}
	}
	if(get_instance_var("floor") == 50){
		instance_warpall instance_mapname("3@ch_t"),32,17,instance_id();
		end;
	}
	if(!get_instance_var("unlocked_" + get_instance_var("area"))) end;
    .@id = atoi(replacestr(strnpcinfo(2),"ctower_warp_",""));
    switch(.@id){
    	case 1:
            .@x = 132; 
			.@y = 183;
			break;

        case 2:
            .@x = 220; 
			.@y = 183; 
			break;

        case 3: 
            .@x = 306; 
			.@y = 183; 
			break;

		case 4:
            .@x = 390;
			.@y = 183; 
			break;

		case 5:
			.@x = 48; 
			.@y = 183; 
			break;
    }	
	if(get_instance_var("area") == 5)
		set_instance_var("area",1);
	else
		set_instance_var("area",get_instance_var("area") + 1);
	set_instance_var("floor",get_instance_var("floor") + 1);
	instance_warpall get_instance_var("map$"),.@x,.@y,instance_id();
	instance_event("#ctower_mob","OnSummon",false);
    end;
}

1@ch_t,97,221,1	duplicate(#ctower_warp_1)	#ctower_warp_2	PORTAL
1@ch_t,185,221,1	duplicate(#ctower_warp_1)	#ctower_warp_3	PORTAL
1@ch_t,271,221,1	duplicate(#ctower_warp_1)	#ctower_warp_4	PORTAL
1@ch_t,355,221,1	duplicate(#ctower_warp_1)	#ctower_warp_5	PORTAL

//Easy Boss
2@ch_t,91,95,7	script	#ctower_leticia2	4_4JOB_LETICIA,{
	.@var = get_instance_var("easy_boss");
	if(!.@var){
		cutin "4job_leticia_03.png",2;
		mes "[ Leticia ]";
		mes "It's strange that he alone could have messed this tower by himself. It's ridiculous for me to deal with such trifle myself, so I'll have you take care of it.";
		if(!is_party_leader()) close3;
		next;
		if(select("I can't handle it with my skills.:Let's do this!") == 1){
			cutin "4job_leticia_02.png",2;
			mes "[ Leticia ]";
			mes "Huh? After what all Oscar said, I had a little bit of expectations from you.";
			close3;
		}
		mes "[ Leticia ]";
		mes "Ho~ You got lot of guts. I like it.";
		npctalk "Ho~ You got lot of guts. I like it.";
		close2;
		set_instance_var("easy_boss",1);
		mapannounce instance_mapname("2@ch_t"),"Black... constellation... The constellation... red lizard... you... constellation. this... bad things... my land... my lost wife... how pathetic... it's you.",bc_map,0xFFCCCC;
		sleep 2000;
		npctalk "Lizard? You can't even see properly because you're holding that very huge sword.";
		sleep 2000;
		mapannounce instance_mapname("2@ch_t"),"You... I.. I will.. make you pay... for my comrades.",bc_map,0xFFCCCC;
		instance_event("#ctower_naght","OnWalk",false);
		end;
	}
	if(.@var == 2){
		if(isbegin_quest(12519) == 1){
			cutin "4job_leticia_05.png",2;
			mes "[ Leticia ]";
			mes "I've been watching, you are pretty good. I promise you that I won't get angry no matter what, even if you introduce me as an acquaintance.";
			next;
			cutin "4job_leticia_02.png",2;
			mes "[ Leticia ]";
			mes "By the way, that thing you defeated, is it the original ruler of this place?";
			next;
			select("It used to be the top floor ruler.:I'm not sure.");
			cutin "4job_leticia_04.png",2;
			mes "[ Leticia ]";
			mes "Ha! I can now picture the situation.";
			next;
			mes "[ Leticia ]";
			mes "Judging from the situation, that thing escaped like a rabbit from its nest after a wild beast appeared in it, he was pushed out by a very strong being and ran all the way here.";
			next;
			cutin "OSCAR01",0;
			mes "[ ^88AA66Oscar's Voice^000000 ]";
			mes "[[^88AA66" + strcharinfo(0) + ", did you find anything?^000000]]";
			next;
			select("Oscar? Where are you talking from?");
			cutin "OSCAR01",0;
			mes "[ ^88AA66Oscar's Voice^000000 ]";
			mes "[[^88AA66Oh, I'm at the best place in the tower, I'm on the top. Don't worry about it, I'm conveying this to you telepathically.^000000]]";
			next;
			cutin "OSCAR01",0;
			mes "[ ^88AA66Oscar's Voice^000000 ]";	
			mes "[[^88AA66I can feel a lot of power from the top floor, I think we should prepare more." + strcharinfo(0) + ", make sure to clean up before you leave.^000000]]";	
			next;
			cutin "4job_leticia_05.png",2;
			mes "[ Leticia ]";
			mes "This place is already great, What do we need to clean up?";
			completequest 12519;
			next;			
		}
		if(isbegin_quest(12518) == 1){
			cutin "4job_leticia_04.png",2;
			mes "[ Leticia ]";
			mes "Something came out of that thing's body.";
			mes "I don't need it, so I'll give it to you.";
			erasequest 12518;
			getitem 1000373,rand(1,2);
			getitem 1000396,1;
			close3;
		}
		cutin "4job_leticia_02.png",2;
		mes "[ Leticia ]";
		mes "Are you done here? Since you can't get out of here the normal way, I'll fly you outside.";
		next;
		if(select("Leave.:Wait a little bit.") == 2){
			mes "[ Leticia ]";
			mes "What is left here to do? Hurry up, will you?";
			close3;
		}
		warp "e_tower",70,114;
	}
	end;
}

2@ch_t,71,74,0	script	#ctower_ev_2	HIDDEN_WARP_NPC,2,2,{
	end;

OnTouch:
	if(isbegin_quest(12518) == 0)
		setquest 12518;
end;
}

2@ch_t,103,107,3	script	#ctower_naght	20996,{
	end;

OnWalk:
	npcspeed 200;
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),93,97,instance_npcname("#ctower_boss_easy") + "::OnSummon";
end;
}

2@ch_t,1,1,0	script	#ctower_boss_easy	HIDDEN_WARP_NPC,{
	end;

OnSummon:
	instance_enable("#ctower_ev_2",false);
	instance_hide("#ctower_naght",true);
	instance_enable("#ctower_leticia2",false);
	instance_enable("#ctower_naght",false);
	monster instance_mapname("2@ch_t"),93,97,"--ja--",20996,1,instance_npcname(strnpcinfo(0)) + "::OnBossKill";
	set_instance_var("boss_id",$@mobid[0]);
	unitskilluseid $@mobid[0],"NPC_RELIEVE_ON",10;
	while(true){
		sleep 1000;
		getunitdata get_instance_var("boss_id"),.@data;
		if(.@data[UMOB_HP] <=  (.@data[UMOB_MAXHP]/10) * 9){
			instance_event(strnpcinfo(0),"OnBossSkill",false);
			break;
		}
	}
end;

OnBossSkill:
	.@map$ = instance_mapname("2@ch_t");
	.@gid = get_instance_var("boss_id");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnSlaveDead";
	getunitdata get_instance_var("boss_id"),.@data;
	.@x = .@data[UMOB_X];
	.@y = .@data[UMOB_Y];
	if(!unitexists(.@gid)){
		stopnpctimer;
		end;
	}
	monster .@map$,.@x,.@y + 3,"--ja--",20997,1,.@event$;
	monster .@map$,.@x,.@y - 3,"--ja--",20997,1,.@event$;
	monster .@map$,.@x + 3,.@y,"--ja--",20997,1,.@event$;
	monster .@map$,.@x - 3,.@y,"--ja--",20997,1,.@event$;
	initnpctimer;
OnSlaveDead:
end;

OnTimer15000:
	stopnpctimer;
	.@map$ = instance_mapname("2@ch_t");
	killmonster .@map$,instance_npcname(strnpcinfo(0)) + "::OnSlaveDead";
	if(unitexists(get_instance_var("boss_id")))
		instance_event(strnpcinfo(0),"OnBossSkill",false);
end;

OnBossKill:
	.@map$ = instance_mapname("2@ch_t");
	killmonster .@map$,instance_npcname(strnpcinfo(0)) + "::OnSlaveDead";
	set_instance_var("easy_boss",2);
	instance_enable("#ctower_leticia2",true);
end;
}

//Top Floor
3@ch_t,32,17,0	script	#ctower_ev_0	HIDDEN_WARP_NPC,2,2,{
	end;

OnTouch:
	if(get_instance_var("mode")){
		if(isbegin_quest(12519) == 0)
			setquest 12519;
	}
end;
}

3@ch_t,32,81,0	script	#ctower_ev_1	HIDDEN_WARP_NPC,2,2,{
	end;

OnTouch:
	if(!is_party_leader()) end;
	if(!get_instance_var("fountain_active")){
		set_instance_var("fountain_active",1);
		instance_enable("#ctower_fountain",true);
		instance_enable(strnpcinfo(0),false);
		sleep 100;
		specialeffect EF_NC_ANAL,AREA,instance_npcname("#ctower_fountain");
		npctalk "This is the altar of goddess, I'll take a look if it works.",instance_npcname("#oscar_ctower_2");
	}
end;
}

3@ch_t,40,93,6	script	#oscar_ctower_2	4_ED_OSCAR,{
	if(!is_party_leader()){
		cutin "OSCAR01",2;
		mes "[ Oscar ]";
		mes "Where is your leader? Don't you think it's odd that this altar is still standing?";
		close3;
	}
	if(!get_instance_var("talk")){
		cutin "OSCAR02",2;
		mes "[ Oscar ]";
		mes "The alter of goddess was not broken.";
		next;
		select("I used that altar as a healing fountain...");
		cutin "OSCAR03",2;
		mes "[ Oscar ]";
		mes "Ah. Healing Fountain. It also had that ability too. Maybe that was the only function because the altars seals were not released.";
		next;
		select("Does it have any other abilites?");
		cutin "OSCAR01",2;
		mes "[ Oscar ]";
		mes "The altar of goddesses are hidden in various forms all over the world. This altar controls various citations and laws under the protection of the goddeses.";
		next;
		mes "[ Oscar ]";
		mes "For instance, it is possible to seal the capabilities of the person who took over this tower.";
		next;
		select("Seal the capabilities?");
		cutin "OSCAR03",2;
		mes "[ Oscar ]";
		mes "Haha, " + strcharinfo(0) + ". Do you think this tower will be safe if a person with enough power to take the tower went all out?";
		next;
		cutin "OSCAR01",2;
		mes "[ Oscar ]";
		mes "The person who took over this tower is probably a hundred times weaker than it's original power. This is because of the altar of goddess' protection";
		next;
		mes "[ Oscar ]";
		mes "But... you can offer a tribute to the goddess and unseal it to some extend. The effect will vary depending on the amount and the way it's offered.";
		next;
		select("A Goddess.... Is it Freya?");
		mes "[ Oscar ]";
		mes "I can't say the name myself, but it's not the goddess you mentioned, " + strcharinfo(0) + ".";
		next;
		mes "[ Oscar ]";
		mes "Anyway, I'm relieved that the altar is safe. I don't think even I can touch the person who took over this tower.";
		next;
		if(get_instance_var("mode")){
			cutin "OSCAR05",2;
			mes "[ Oscar ]";
			mes "However, since this is a very low floor, the power of the goddess doesn't seem to work much. It can only be used as a simple fountain to recover.";
			close2;
			instance_warpall instance_mapname("2@ch_t"),71,74,instance_id();
			end;
		} else {
			cutin "OSCAR02",2;
			mes "[ Oscar ]";
			mes "I can feel the overwhelming power of the person who's beyond this place.";
			mes "You can use the altar of goddess freely to alter his sealed abilites.";
			next;
			cutin "OSCAR01",2;
			mes "[ Oscar ]";
			mes "I release the sealed that is bounding this dimension to the place where the person who took over the tower is.";
			set_instance_var("talk",1);
			
			close3;	
		}
	}
	if(!get_instance_var("switch_active")){
		if(isbegin_quest(12513) == 2){
			cutin "OSCAR02",2;
			mes "[ Oscar ]";
			mes "I finished all the preparations, we can meet the one who destroyed this tower.";
			next;
			mes "[ Oscar ]";
			mes "Are you ready?";
			next;
			if(select("Yes.:Not yet.") == 2){
				cutin "OSCAR01",2;
				mes "[ Oscar ]";
				mes "Take all the time you need to prepare.";
				close3;
			}
		} else {
			cutin "OSCAR02",2;
			mes "[ Oscar ]";
			mes "Are you here to challenge Betelguese?";
			next;
			if(select("Not really.:Fight Betelguese.") == 1){
				cutin "OSCAR03",2;
				mes "[ Oscar ]";
				mes "Then, why are you here? You adventurers are really interesting.";
				close3;
			}
		}
		mes "[ Oscar ]";
		mes "Then, I opened up the entrance to the top floor, use it when you're ready.";
		instance_enable("#ctower_button",true);
		set_instance_var("switch_active",true);
		close3;
	}
	cutin "OSCAR02",2;
	mes "[ Oscar ]";
	mes "I already opened the entrance to the top floor, use it when you're ready.";
	close3;
}

3@ch_t,32,102,1	script	#ctower_button	CLEAR_NPC,{
	if(get_instance_var("mode") || !is_party_leader()) end;
	instance_warpall instance_mapname("3@ch_t"),156,73;
	end;
}

3@ch_t,156,73,0	script	#ctower_ev_3	HIDDEN_WARP_NPC,2,2,{
	end;

OnTouch:
	if(isbegin_quest(12515) == 0) setquest 12515;
	if(isbegin_quest(12516)) erasequest 12516;
	if(isbegin_quest(12517)) erasequest 12517;
	if(isbegin_quest(12518)) erasequest 12518;
	setquest 12518;
	if(get_instance_var("total") >= 300)
		setquest 12516;
	else if(get_instance_var("total") >= 600)
		setquest 12517;
end;
}

3@ch_t,45,89,1	script	#ctower_fountain	CLEAR_NPC,{
	if(get_instance_var("mode")){
		specialeffect EF_BUBBLE;
		percentheal 100,100;
		end;
	}
	.@HP = get_instance_var("HP");
	.@ATK = get_instance_var("ATK");
	.@RECO = get_instance_var("RECO");
	.@RES = get_instance_var("RES");
	.@TRAP = get_instance_var("TRAP");
	.@star0$ = "Sealed";
	.@star1$ = "★";
	.@star2$ = "★★";
	.@star3$ = "★★★";
	switch(.@HP){
		case 1: .@TOTAL += 15; break;
		case 2: .@TOTAL += 30; break;
		case 3: .@TOTAL += 45; break;
	}
	switch(.@ATK){
		case 1: .@TOTAL += 20; break;
		case 2: .@TOTAL += 40; break;
		case 3: .@TOTAL += 60; break;
	}
	switch(.@RECO){
		case 1: .@TOTAL += 30; break;
		case 2: .@TOTAL += 60; break;
		case 3: .@TOTAL += 90; break;
	}
	switch(.@RES){
		case 1: .@TOTAL += 50; break;
		case 2: .@TOTAL += 100; break;
		case 3: .@TOTAL += 150; break;
	}
	switch(.@TRAP){
		case 1: .@TOTAL += 85; break;
		case 2: .@TOTAL += 170; break;
		case 3: .@TOTAL += 255; break;
	}
	mes "[ Current Constellation Abilities ]";
	mes "HP - ^0000CD" + getd(".@star" + .@HP + "$") + "^000000";
	mes "ATK - ^0000CD" + getd(".@star" + .@ATK + "$") + "^000000";
	mes "RECOVERY - ^0000CD" + getd(".@star" + .@RECO + "$") + "^000000";
	mes "RESISTANCE - ^0000CD" + getd(".@star" + .@RES + "$") + "^000000";
	mes "TRAP - ^0000CD" + getd(".@star" + .@TRAP + "$") + "^000000";
	next;
	if(!.@TOTAL)
		mes "The current constellation abilties are completely sealed.";
	else {
		mes "The current constellation abilities are increased from it's sealed state.";
		mes "It's currently increased by ^FF0000" + .@total + "%^000000";
	}
	mes "----------------------";
	if(.@TOTAL < 400)
		mes "^FF0000There will be no extra costume drop chance.^000000";
	if(.@TOTAL >= 400)
		mes "<ITEM>[Additional Reward 1]<INFO>400147</INFO></ITEM>";
	if(.@TOTAL >= 500)
		mes "<ITEM>[Additional Reward 2]<INFO>400148</INFO></ITEM>";
	if(.@TOTAL == 600)
		mes "<ITEM>[Additional Reward 3]<INFO>400149</INFO></ITEM>";
	if(!is_party_leader()) end;
	next;
	switch(select("Quit:Randomize Abilities:Maximize Abilities")){
		case 1:
			break;

		case 2:
			mes "- For the randomizing the constellation's abilities, you will need to offer ^0000CD 1 " + getitemname(1000372) + "^000000.";
			mes "----------------------";
			mes "^FF0000The current constellation abilities not be retained.^000000";
			next;
			if(select("Quit.:Proceed.") == 1) end;
			if(countitem(1000372) < 1){
				mes "- You don't have the required amount of ^FF0000" + getitemname(1000372) + "^000000 for the offering.";
				end;
			}
			delitem 1000372,1;
			.@HP = rand(0,3);
			.@ATK = rand(0,3);
			.@RECO = rand(0,3);
			.@RES = rand(0,3);
			.@TRAP = rand(0,3);
			set_instance_var("HP",.@HP);
			set_instance_var("ATK",.@ATK);
			set_instance_var("RECO",.@RECO);
			set_instance_var("RES",.@RES);
			set_instance_var("TRAP",.@TRAP);
			mes "The constellation abilities has changed.";
			break;

		case 3:
			mes "- For maximizing the constellation's abilities, you will need to offer ^0000CD 20 " + getitemname(1000372) + "^000000.";
			next;
			if(select("Quit.:Proceed.") == 1) end;
			if(countitem(1000372) < 20){
				mes "- You don't have the required amount of ^FF0000" + getitemname(1000372) + "^000000 for the offering.";
				end;
			}
			delitem 1000372,20;
			.@HP = 3;
			.@ATK = 3;
			.@RECO = 3;
			.@RES = 3;
			.@TRAP = 3;
			set_instance_var("HP",.@HP);
			set_instance_var("ATK",.@ATK);
			set_instance_var("RECO",.@RECO);
			set_instance_var("RES",.@RES);
			set_instance_var("TRAP",.@TRAP);
			mes "The constellation abilities has changed.";
			break;
	}
	switch(.@HP){
		case 1: .@TOTAL += 15; break;
		case 2: .@TOTAL += 30; break;
		case 3: .@TOTAL += 45; break;
	}
	switch(.@ATK){
		case 1: .@TOTAL += 20; break;
		case 2: .@TOTAL += 40; break;
		case 3: .@TOTAL += 60; break;
	}
	switch(.@RECO){
		case 1: .@TOTAL += 30; break;
		case 2: .@TOTAL += 60; break;
		case 3: .@TOTAL += 90; break;
	}
	switch(.@RES){
		case 1: .@TOTAL += 50; break;
		case 2: .@TOTAL += 100; break;
		case 3: .@TOTAL += 150; break;
	}
	switch(.@TRAP){
		case 1: .@TOTAL += 85; break;
		case 2: .@TOTAL += 170; break;
		case 3: .@TOTAL += 255; break;
	}
	set_instance_var("TOTAL",.@TOTAL);
	next;
	mes "[ Current Constellation Abilities ]";
	mes "HP - ^0000CD" + getd(".@star" + .@HP + "$") + "^000000";
	mes "ATK - ^0000CD" + getd(".@star" + .@ATK + "$") + "^000000";
	mes "RECOVERY - ^0000CD" + getd(".@star" + .@RECO + "$") + "^000000";
	mes "RESISTANCE - ^0000CD" + getd(".@star" + .@RES + "$") + "^000000";
	mes "TRAP - ^0000CD" + getd(".@star" + .@TRAP + "$") + "^000000";
	end;
}

3@ch_t,156,86,5	script	#ctower_betel_0	20994,{
	if(!is_party_leader()){
		cutin "betelgeuse04.png",2;
		mes "[ Betelgeuse ]";
		mes "Where is your leader? It's not my taste to have a leisurely chat with beings like you.";
		close3;
	}
	if(!get_instance_var("phase")){
		if(isbegin_quest(12513) == 2){
			cutin "betelgeuse03.png",2;
			mes "As I thought, Who could have it been other than you humans coming here to challenge me. You never get tired, do you?";
			npctalk "As I thought, Who could have it been other than you humans coming here to challenge me. You never get tired, do you?";
			if(select("Run.:Fight.") == 1){
				next;
				mes "[ Betelgeuse ]";
				mes "Wise choice foolish creature.";
				close3;
			}
			close2;
			cutin "",255;
		}
		set_instance_var("phase",1);
		if(isbegin_quest(12513) == 1){
			npctalk "What's this? Ah... Another bugs snooping around, are you expecting something?";
			sleep 3000;
			specialeffect EF_MAGIC_FLOOR;
			npctalk "Most of my abilities are sealed, so it's worth trying to challenge me, isn't it? Even though you don't have the slightest idea what you're facing.";
			sleep 3000;
			npctalk "I hope you're better than the humans who've visited before.";
			sleep 3000;
		} else {
			npctalk "Most of my abilities are still sealed, but I think you're power is still not enough to stop me..";
			sleep 3000;
			specialeffect EF_MAGIC_FLOOR;
			sleep 3000;
		}
		removespecialeffect EF_MAGIC_FLOOR,AREA,instance_npcname(strnpcinfo(0));
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_event("#ctower_boss_hard","OnFirstPhase",false);
		end;
	}
	end;
}

3@ch_t,156,86,5	duplicate(dummynpc2)	#ctower_betel_1	20994
3@ch_t,156,86,5	duplicate(dummynpc2)	#ctower_betel_2	20994

3@ch_t,156,86,5	script	#ctower_betel_3	20994,{
	if(get_instance_var("phase") == 4){
		if(isbegin_quest(12513) == 1){
			cutin "4job_leticia_03.png",0;
			mes "[ Leticia ]";
			mes "I was wondering who it was, to think that it was you, you negligent boy.";
			next;
			cutin "betelgeuse01.png",2;
			mes "[ Betelguese ]";
			mes "Ah, who would have thought, Leticia, you still haven't fixed your habit of appearing whenever I'm upset.";
			next;
			cutin "4job_leticia_03.png",0;
			mes "[ Leticia ]";
			mes "Ho~ I'm curious, I wonder why the person I haven't seen for so long is upset.";
			next;
			cutin "betelgeuse06.png",2;
			mes "[ Betelguese ]";
			mes "I just hope you the red one, stop paying attention to me and quietly leave~";
			next;
			cutin "4job_leticia_03.png",0;
			mes "[ Leticia ]";
			mes "Yeah~ I guess it must be it. You fought against ^0000CDhumans^000000, and lost. You must be so upset.";
			next;
			cutin "betelgeuse04.png",2;
			mes "[ Betelgeuse ]";
			mes "I'm just a little tired from making this place my rarity, of course I let things slide a bit. That must be a joke, right?";
			next;
			cutin "4job_leticia_02.png",0;
			mes "[ Leticia ]";
			mes "Did I heard it correctly? Did you say you're going to creating a rare?";
			next;
			cutin "betelgeuse06.png",2;
			mes "[ Betelguese ]";
			mes "You heard it right. I'm glad your ears is bad as it was.";
			next;
			cutin "4job_leticia_02.png",0;
			mes "[ Leticia ]";
			mes "This topic, I don't think anyone would let it go if they heard of it.";
			mes "Don't you know who's on this continent now?";
			next;
			cutin "betelgeuse07.png",2;
			mes "[ Betelguese ]";
			mes "Is that something I need to know? You know I don't like to be bothered.";
			next;
			cutin "OSCAR04",0;
			mes "[ Oscar ]";
			mes "I see. Our Betel really hated being bothered. That's why you hadn't reach out for 400 years. And you started rampaging, such an annoying kid.";
			next;
			cutin "betelgeuse07.png",2;
			mes "[ Betelguese ]";
			mes "Who are you? A person who dares to call my name without fear... This is the first time I've faced such embarassment in a hundred years.";
			next;
			cutin "OSCAR01",0;
			mes "[ Oscar ]";
			mes "That's what I mean. It's been so long, but I still havent forgotten your name.";
			mes "I'm sure you'll remember even though we are apart for many years without any form of contact";
			next;
			cutin "betelgeuse07.png",2;
			mes "[ Betelguese ]";
			mes "^88AA66What is this? This familiar voice, My body is sensing fear instinctively, the awe, what's wrong? Haven't I forgot the feeling of fear through the countless years?^000000";
			next;
			cutin "4job_leticia_02.png",2;
			mes "[ Leticia ]";
			mes "You're speaking your mind right now.";
			next;
			cutin "OSCAR01",0;
			mes "[ Oscar ]";
			mes "Betel, We should put off the greetings, I'll have you tell me in detail why you broke this tower.";
			mes "We shouldn't touch the human realm recklessly.";
			next;
			cutin "betelgeuse05.png",2;
			mes "[ Betelguese ]";
			mes "O... Oscar? Sir Oscar, why are you here?";
			next;
			cutin "OSCAR01",0;
			mes "[ Oscar ]";
			mes "Do you think I would have ignore it after all the commosion? Why did you do that?";
			next;
			cutin "4job_leticia_02.png",2;
			mes "[ Leticia ]";
			mes "Oscar... Don't be too angry and listen here. Betelguese here wants to make a new rare here, haha... Isn't there something we can do about it?";
			next;
			cutin "OSCAR01",0;
			mes "[ Oscar ]";
			mes "What? A rare, here? Are you serious, Betelguese?";
			next;
			cutin "betelgeuse07.png",2;
			mes "[ Betelguese ]";
			mes "^88AA66I'm doomed. The look on Oscar's face is very furious, will I be punished by turning my age back by what, 3000 years? 4000 years??^000000";
			next;
			cutin "4job_leticia_02.png",2;
			mes "[ Leticia ]";
			mes "You're wrong, if he's this angry. It might be atleast 6000 years long.";
			next;
			cutin "OSCAR01",0;
			mes "[ Oscar ]";
			mes "Come to think of it, It's not all that bad. Isn't this the place where the monster were originally created?";
			next;
			select("This was a monster dungeon.:I don't know.");
			cutin "4job_leticia_01.png",2;
			mes "[ Leticia ]";
			mes "Oscar, are you just going to forgive Betelguese for what he did?";
			next;
			cutin "OSCAR02",0;
			mes "[ Oscar ]";
			mes "If you accept a few conditions, I'll close my eyes on this one, what do you say? Betelguese?";
			next;
			cutin "betelgeuse07.png",2;
			mes "[ Betelguese ]";
			mes "Are you serious? Just say your conditions. My age... as long as you don't revert my age back, I'll do anything!";
			next;
			cutin "OSCAR02",0;
			mes "[ Oscar ]";
			mes "Alright. So I'll let you make this place your rarity, but make sure that the monstes in here don't go out running in the human continent.";
			next;
			cutin "betelgeuse06.png",2;
			mes "[ Betelguese ]";
			mes "If it's only that much, then I'll do it!";
			next;
			cutin "OSCAR02",0;
			mes "[ Oscar ]";
			mes "Originally this place was a hunting grounds for the adventurers, make sure you let them come in and make them hunt like they used to, and that's the end of my conditions.";
			next;
			cutin "betelgeuse07.png",2;
			mes "[ Betelguese ]";
			mes "Tha... That. Nothing, I accept your conditions.";
			mes "Oscar, I have a request.";
			next;
			cutin "OSCAR02",0;
			mes "[ Oscar ]";
			mes "Alright, tell me anything, as long that it won't make me angry.";
			next;
			cutin "betelgeuse07.png",2;
			mes "[ Betelguese ]";
			mes "Would you allow me to fight the adventurers who occasionally visit here?";
			mes "It's a big deal for me...";
			next;
			cutin "OSCAR02",0;
			mes "[ Oscar ]";
			mes "I don't think that's for me to decide.";
			mes "Luckily, there's a representative over here, so let's ask the adventurer. What do you think?";
			next;
			select("Sounds good.:As long as you reward us for beating him.");
			cutin "betelgeuse02.png",2;
			mes "[ Betelguese ]";
			mes "Of course, I'll make a reward worthy of the fun that you'll give me, humans.";
			mes "That is, if you can win. Haha";
			next;
			cutin "OSCAR02",0;
			mes "[ Oscar ]";
			mes "Of course, when the adventurers visits you, Betelguese. I'll be there to observer and stop you from going wild.";
			next;
			cutin "betelgeuse05.png",2;
			mes "[ Betelguese ]";
			mes "Sigh, well... you don't have to come in person.";
			next;
			cutin "OSCAR02",0;
			mes "[ Oscar ]";
			mes "Well then, I think everything is settled, so I'll return to town and calm myself down. I'll see you next time adventurer.";
			next;
			cutin "4job_leticia_01.png",2;
			mes "[ Leticia ]";
			mes "I like you humans, you're pretty good.";
			mes "I'll see you next time.";
			completequest 12513;
			next;
		}
		if(isbegin_quest(12518) == 1){
			.@amount = 2 + (2*(get_instance_var("TOTAL")/50)); 
			.@amount2 = 5 + (get_instance_var("TOTAL")/100);
			if(get_instance_var("TOTAL") >= 200)
				.@amount3 = 1;
			cutin "betelgeuse03.png",2;
			mes "[ Betelguese ]";
			mes "Here's a reward of what you did my challenge, I prepared as much as worthy of the ordeal that you overcame, so take it without hesitating.";
			if(isbegin_quest(12516) == 1){
				.@amount += 4;
				.@amount2 += 3;
				.@amount3 += 1;
				erasequest 12516;
			}
			if(isbegin_quest(12517) == 2){
				.@amount += 9;
				.@amount2 += 8;
				.@amount3 += 2;
				erasequest 12517;
			}
			erasequest 12518;
			getitem 1000397,.@amount3;
			getitem 1000373,.@amount2;
			getitem 1000372,.@amount;
		} else {
			cutin "betelgeuse05.png",2;
			mes "[ Betelguese ]";
			mes "It's really not my hobby to spend my time leisurely talking with being such as yours. If you're done here, I opened up the portal to leave the tower.";
		}
		close3;
	}
	end;
}

//= Betelguese Bosss Fight/Rewards
function	script	ctower_cacl_stats	{
	.@gid = getarg(0);
	getunitdata .@gid,.@data;
	if(unitexists(.@gid)){   
		.@HP = get_instance_var("HP");
		.@ATK = get_instance_var("ATK");
		.@RES = get_instance_var("RES");
		if(.@HP){
			.@MOB_HP = .@data[UMOB_MAXHP] + (300000000 * .@HP);
			setunitdata .@gid,UMOB_MAXHP,.@MOB_HP;
			setunitdata .@gid,UMOB_HP,.@MOB_HP;
			set_instance_var("BOSS_HP",.@MOB_HP);
		}
		if(.@ATK){
			.@MOB_ATK = getmonsterinfo(20994,MOB_ATK1) + (5000 * .@ATK);
			.@MOB_ATK2 = getmonsterinfo(20994,MOB_ATK2) + (7000 * .@ATK);
			.@STR = getmonsterinfo(20994,MOB_STR) + (100 * .@ATK);
			.@INT = getmonsterinfo(20994,MOB_INT) + (100 * .@ATK);
			setunitdata .@gid,UMOB_ATKMIN,.@MOB_ATK;
			setunitdata .@gid,UMOB_ATKMAX,.@MOB_ATK2;
			setunitdata .@gid,UMOB_STR,.@STR;
			setunitdata .@gid,UMOB_INT,.@INT;
			set_instance_var("BOSS_ATK",.@MOB_ATK);
			set_instance_var("BOSS_ATK2",.@MOB_ATK2);
			set_instance_var("BOSS_STR",.@STR);
			set_instance_var("BOSS_INT",.@INT);
		}
		if(.@RES){
			.@RES = .@data[UMOB_RES] + (100 * .@RES);
			.@MRES = .@data[UMOB_MRES] + (100 * .@MRES);
			setunitdata .@gid,UMOB_RES,.@RES;
			setunitdata .@gid,UMOB_MRES,.@MRES;
			set_instance_var("BOSS_RES",.@RES);
			set_instance_var("BOSS_MRES",.@MRES);
		}
	}
	return;
}

function	script	ctower_revert_stats	{
	.@gid = getarg(0);
	if(unitexists(.@gid)){
		setunitdata .@gid,UMOB_ATKMIN,get_instance_var("BOSS_ATK");
		setunitdata .@gid,UMOB_ATKMAX,get_instance_var("BOSS_ATK2");
		setunitdata .@gid,UMOB_STR,get_instance_var("BOSS_STR");
		setunitdata .@gid,UMOB_INT,get_instance_var("BOSS_INT");
	}
	return;
}

function	script	ctower_recalc_stats	{
    .@gid = getarg(0);
    .@value = getarg(1);
    ctower_revert_stats(.@gid);
    if(unitexists(.@gid)){
        .@MOB_ATK = get_instance_var("BOSS_ATK") + (5000 * .@value);
        .@MOB_ATK2 = get_instance_var("BOSS_ATK2") + (7000 * .@value);
		.@MOB_MATK = get_instance_var("BOSS_MATK") + (2000 * .@value);;
		.@MOB_MATK2 = get_instance_var("BOSS_MATK2") + (4000 * .@value);;
        .@STR = get_instance_var("BOSS_STR") + (100 * .@value);
        .@INT = get_instance_var("BOSS_INT") + (100 * .@value);
        setunitdata .@gid,UMOB_ATKMIN,.@MOB_ATK;
        setunitdata .@gid,UMOB_ATKMAX,.@MOB_ATK2;
        setunitdata .@gid,UMOB_STR,.@STR;
        setunitdata .@gid,UMOB_INT,.@INT;
    }
    return;
}

3@ch_t,1,1,0	script	#ctower_boss_hard	HIDDEN_WARP_NPC,{
	end;

OnFirstPhase:
	instance_enable("#ctower_ev_3",false);
	set_instance_var("map$",instance_mapname("3@ch_t"));
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnBossKill";
	monster .@map$,156,85,"Betelguese",20994,1,.@event$;
	set_instance_var("gid",$@mobid[0]);
    unitskilluseid $@mobid[0],"NPC_RELIEVE_ON",10;
    ctower_cacl_stats($@mobid[0]);
	instance_event("#ctower_party_check","OnCheck",false);
	instance_event("#ctower_check_area","OnCheck",false);
	instance_event("#ctower_check_dead","OnCheck",false);
    instance_event(strnpcinfo(0),"OnFirstPhaseCheck",false);
	sleep 1000;
	instance_event("#ctower_skill_heal","OnSkill",false);
	instance_event("#ctower_skill_meteor","OnSkill",false);
end;

OnFirstPhaseCheck:
    .@gid = get_instance_var("gid");
    freeloop(true);
    while(unitexists(.@gid)){
        getunitdata .@gid,.@data;
        if(.@data[UMOB_HP] <= (.@data[UMOB_MAXHP]/10) * 9){
        	instance_event(strnpcinfo(0),"OnSecondPhase",false);
        	break;
        }
        sleep 1000;
    }
	freeloop(false);
end;

OnSecondPhase:
	.@map$ = get_instance_var("map$");
	set_instance_var("phase_check",1);
	set_instance_var("trap_active",false);
	unitkill get_instance_var("gid");
    instance_warpall .@map$,156,79,instance_id();
	set_instance_var("phase_check",0);
    instance_enable("#ctower_betel_1",true);
    sleep 2000;
    npctalk "I'm a little bored, let's add some life to this banquet, humans.",instance_npcname("#ctower_betel_1");
    unitwalk getnpcid(0,instance_npcname("#ctower_betel_1")),156,80,instance_npcname(strnpcinfo(0)) + "::OnSecondPhaseTalk";
end;

OnSecondPhaseTalk:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnBossKill";
	sleep 2000;
    npctalk "Should we start with something light? I hope you'll like it.",instance_npcname("#ctower_betel_1");
    sleep 2000;
    specialeffect EF_MAGIC_FLOOR,AREA,instance_npcname("#ctower_betel_1");
	sleep 2000;
	if(get_instance_var("TRAP") < 2){
		for(.@i = 0; .@i < 10; .@i++)
			instance_enable("#ctower_trap_" + .@i,true);
		for(.@i = 0; .@i < 10; .@i++)
			instance_event("#ctower_trap_" + .@i,"OnMove",false);
	} else if(get_instance_var("TRAP") == 2){
		for(.@i = 0; .@i < 16; .@i++)
			instance_enable("#ctower_trap2_" + .@i,true);
		for(.@i = 0; .@i < 16; .@i++)
			instance_event("#ctower_trap2_" + .@i,"OnMove",false);
	} else {
		for(.@i = 0; .@i < 16; .@i++){
			if(.@i < 10)
				instance_enable("#ctower_trap_" + .@i,true);
			instance_enable("#ctower_trap2_" + .@i,true);
		}
		for(.@i = 0; .@i < 16; .@i++){
			if(.@i < 10)
				instance_event("#ctower_trap_" + .@i,"OnMove",false);
			instance_event("#ctower_trap2_" + .@i,"OnMove",false);
		}
	}
	sleep 2000;
	set_instance_var("phase",2);
	set_instance_var("trap_active",true);
	instance_enable("#ctower_betel_1",false);
	monster .@map$,156,80,"Betelguese",20994,1,.@event$;
	set_instance_var("gid",$@mobid[0]);
    unitskilluseid $@mobid[0],"NPC_RELIEVE_ON",10;
    ctower_cacl_stats($@mobid[0]);
	ctower_recalc_stats($@mobid[0],1);
	instance_event(strnpcinfo(0),"OnSecondPhaseCheck",false);
	stopnpctimer instance_npcname("#ctower_skill_meteor");
	instance_event("#ctower_skill_meteor","OnSkill",false);
	instance_event("#ctower_skill_soul","OnSkill",false);
	sleep 1000;
	instance_event("#ctower_skill_ganbantein","OnSkill",false);
end;

OnSecondPhaseCheck:
    .@gid = get_instance_var("gid");
    freeloop(true);
    while(unitexists(.@gid)){
        getunitdata .@gid,.@data;
        if(.@data[UMOB_HP] <= (.@data[UMOB_MAXHP]/10) * 6){
        	instance_event(strnpcinfo(0),"OnThirdPhase",false);
        	break;
        }
        sleep 1000;
    }
	freeloop(false);
end;

OnThirdPhase:
	.@map$ = get_instance_var("map$");
	set_instance_var("trap_active",false);
	set_instance_var("phase_check",1);
	unitkill get_instance_var("gid");
    instance_warpall .@map$,156,79,instance_id();
	set_instance_var("phase_check",0);
    instance_enable("#ctower_betel_2",true);
	killmonster .@map$,instance_npcname("#ctower_skill_soul") + "::OnSkillDead";
    sleep 2000;
    npctalk "This banquet is getting a little boring.",instance_npcname("#ctower_betel_2");
    unitwalk getnpcid(0,instance_npcname("#ctower_betel_2")),156,80,instance_npcname(strnpcinfo(0)) + "::OnThirdPhaseTalk";
end;

OnThirdPhaseTalk:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnBossKill";
	sleep 2000;
    npctalk "Now, let's change to something heavier shall we.",instance_npcname("#ctower_betel_1");
    sleep 2000;
    specialeffect EF_MAGIC_FLOOR,AREA,instance_npcname("#ctower_betel_2");
	sleep 2000;
	if(get_instance_var("TRAP") < 2){
		for(.@i = 0; .@i < 10; .@i++)
			setnpcdisplay instance_npcname("#ctower_trap_" + .@i),20351;
	} else if(get_instance_var("TRAP") == 2){
		for(.@i = 0; .@i < 16; .@i++)
			setnpcdisplay instance_npcname("#ctower_trap2_" + .@i),20351;
	} else {
		for(.@i = 0; .@i < 16; .@i++){
			if(.@i < 10)
				setnpcdisplay instance_npcname("#ctower_trap_" + .@i),20351;
			setnpcdisplay instance_npcname("#ctower_trap2_" + .@i),20351;
		}
	}
	sleep 2000;
	set_instance_var("phase",3);
	set_instance_var("trap_active",true);
	instance_enable("#ctower_betel_2",false);
	monster .@map$,156,80,"Betelguese",20994,1,.@event$;
	set_instance_var("gid",$@mobid[0]);
    unitskilluseid $@mobid[0],"NPC_RELIEVE_ON",10;
    ctower_cacl_stats($@mobid[0]);
	ctower_recalc_stats($@mobid[0],2);
end;

OnBossKill:
    if(get_instance_var("phase_check")) end;
	.@map$ = get_instance_var("map$");
	for(.@i = 0; .@i < 10; .@i++)
		instance_enable("#ctower_trap_" + .@i,false);
	for(.@i = 0; .@i < 16; .@i++)
		instance_enable("#ctower_trap2_" + .@i,false);
	stopnpctimer instance_npcname("#ctower_skill_meteor");
	stopnpctimer instance_npcname("#ctower_skill_ganbantein");
	stopnpctimer instance_npcname("#ctower_skill_soul");
	stopnpctimer instance_npcname("#ctower_skill_heal");
	killmonster .@map$,instance_npcname("#ctower_skill_soul") + "::OnSkillDead";
	set_instance_var("boss_dead",1); //Extra Check
	set_instance_var("phase",4);
	instance_warpall .@map$,156,79,instance_id();
	instance_enable("#ctower_betel_3",true);
	instance_enable("#ctower_exit",true);
	if(get_instance_var("TOTAL") > 0){
		.@TOTAL = get_instance_var("TOTAL");
		.@AMOUNT = .@TOTAL/50;
	}
	if(.@AMOUNT){
		if(.@AMOUNT >= 5){
			for(.@i = 1; .@i < 6; .@i++)
				instance_enable("#ctower_treasure_" + .@i,true);
		} else {
			while(.@Z < .@AMOUNT){
				.@var = rand(1,5);
				while(inarray(.@T,.@var) != -1)
					.@var = rand(1,5);
				.@T[getarraysize(.@T)] = .@var;
				instance_enable("#ctower_treasure_" + .@var,true);
				.@Z++;
			}
		}
		if(.@TOTAL >= 400)
			instance_enable("#ctower_treasure_11",true);
		deletearray .@T[0];
		.@Z = 0;
		.@AMOUNT -= 6;
		if(.@AMOUNT >= 6){
			for(.@i = 6; .@i < 11; .@i++)
				instance_enable("#ctower_treasure_" + .@i,true);
		} else {
			while(.@Z < .@AMOUNT){
				.@var = rand(6,10);
				while(inarray(.@T,.@var) != -1)
					.@var = rand(6,10);
				.@T[getarraysize(.@T)] = .@var;
				instance_enable("#ctower_treasure_" + .@var,true);
				.@Z++;
			}
		}
		if(.@TOTAL >= 600)
			instance_enable("#ctower_treasure_12",true);
	}
end;
}

3@ch_t,147,76,3	script	#ctower_treasure_1	4_STAR_BOX_POW1,{
	.@id = atoi(replacestr(strnpcinfo(2),"ctower_treasure_",""));
	switch(.@id){
		case 1: .@item_id = 1000398; .@amount = rand(5,9); break;
		case 2: .@item_id = 1000399; .@amount = rand(5,9); break;
		case 3: .@item_id = 1000402; .@amount = rand(5,9); break;
		case 4: .@item_id = 1000400; .@amount = rand(5,9); break;
		case 5: .@item_id = 1000403; .@amount = rand(5,9); break;
		case 6: .@item_id = 1000442; .@amount = rand(2,5); break;
		case 7: .@item_id = 1000443; .@amount = rand(2,5); break;
		case 8: .@item_id = 1000446; .@amount = rand(2,5); break;
		case 9: .@item_id = 1000444; .@amount = rand(2,5); break;
		case 10: .@item_id = 1000447; .@amount = rand(2,5); break;
		case 11: .@item_id = 1000401; .@amount = rand(5,9); break;
		case 12: .@item_id = 1000445; .@amount = rand(2,5); break; 
	}
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	getmapxy(.@map$,.@x,.@y,BL_NPC);
	for(.@i = 0; .@i < .@amount; .@i++)
		makeitem .@item_id,1,.@map$,.@x + rand(-1,1),.@y + rand(-1,1);
	if(.@id == 11){
		.@chance = 5;
		if(get_instance_var("TOTAL") >= 400)
			if(rand(1,100) <= .@chance) makeitem 400147,1,.@map$,.@x + rand(-1,1),.@y + rand(-1,1);
		if(get_instance_var("TOTAL") >= 500)
			if(rand(1,100) <= .@chance) makeitem 400148,1,.@map$,.@x + rand(-1,1),.@y + rand(-1,1);
	}
	if(.@id == 12){
		if(get_instance_var("TOTAL") >= 600)
			if(rand(1,100) <= .@chance) makeitem 400149,1,.@map$,.@x + rand(-1,1),.@y + rand(-1,1);
	}
	end;
}

3@ch_t,151,76,3	duplicate(#ctower_treasure_1)	#ctower_treasure_2	4_STAR_BOX_STA1
3@ch_t,155,76,3	duplicate(#ctower_treasure_1)	#ctower_treasure_3	4_STAR_BOX_SPL1
3@ch_t,159,76,3	duplicate(#ctower_treasure_1)	#ctower_treasure_4	4_STAR_BOX_CON1
3@ch_t,163,76,3	duplicate(#ctower_treasure_1)	#ctower_treasure_5	4_STAR_BOX_WIS1

3@ch_t,147,72,3	duplicate(#ctower_treasure_1)	#ctower_treasure_6	4_STAR_BOX_POW2
3@ch_t,151,72,3	duplicate(#ctower_treasure_1)	#ctower_treasure_7	4_STAR_BOX_STA2
3@ch_t,155,72,3	duplicate(#ctower_treasure_1)	#ctower_treasure_8	4_STAR_BOX_SPL2
3@ch_t,159,72,3	duplicate(#ctower_treasure_1)	#ctower_treasure_9	4_STAR_BOX_CON2
3@ch_t,163,72,3	duplicate(#ctower_treasure_1)	#ctower_treasure_10	4_STAR_BOX_WIS2

3@ch_t,159,80,3	duplicate(#ctower_treasure_1)	#ctower_treasure_11	4_STAR_BOX_CRT1
3@ch_t,155,80,3	duplicate(#ctower_treasure_1)	#ctower_treasure_12	4_STAR_BOX_CRT2



3@ch_t,1,1,0	script	#ctower_skill_meteor	HIDDEN_WARP_NPC,{
	end;

OnSkill:
	initnpctimer;
end;

OnTimer5000:
	if(get_instance_var("phase") < 3) end;
	stopnpctimer;
	if(get_instance_var("boss_dead")) end;
	if(!unitexists(get_instance_var("gid"))) initnpctimer;
	function SafeSkill;
	SafeSkill;
	initnpctimer;
end;

OnTimer10000:
	stopnpctimer;
	if(get_instance_var("boss_dead")) end;
	if(!unitexists(get_instance_var("gid"))) initnpctimer;
	function SafeSkill;
	SafeSkill;
	initnpctimer;
end;

function	SafeSkill	{
	if(get_instance_var("boss_dead")) end;
	.@gid = get_instance_var("gid");
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnSkillDead";
	setarray .@x[1],
	-10,0,10,
	-10,0,10,
	-10,0,10;
	setarray .@y[1],
	10,10,10,
	0,0,0,
	-10,-10,-10;
	if(unitexists(.@gid)){
		getunitdata .@gid,.@data;
		.@x2 = .@data[UMOB_X];
		.@y2 = .@data[UMOB_Y];
		for(.@i = 1; .@i < getarraysize(.@x); .@i++){
			if(!unitexists(.@gid))
				break;
			monster .@map$,.@x2 + .@x[.@i],.@y2 + .@y[.@i],"",20562,1,.@event$;
			setunitdata $@mobid[0],UMOB_DMGIMMUNE,true;
			ctower_cacl_stats($@mobid[0]); //COPY STATS OF BETEL TO HIDDEN MOB
			getunitdata $@mobid[0],.@data;
			unitskillusepos $@mobid[0],"WZ_METEOR",10,.@x2 + .@x[.@i],.@y2 + .@y[.@i],-10000;
			sleep 1000;
		}
	}
	sleep 5000;
	killmonster .@map$,.@event$;
	return;
}

OnSkillDead:
end;
}

3@ch_t,1,1,0	script	#ctower_skill_ganbantein	HIDDEN_WARP_NPC,{
	end;

OnSkill:
	initnpctimer;
end;

OnTimer10000:
	if(get_instance_var("phase") < 3) end;
	stopnpctimer;
	if(get_instance_var("boss_dead")) end;
	if(!unitexists(get_instance_var("gid"))) initnpctimer;
	function SafeSkill;
	SafeSkill;
	initnpctimer;
end;

OnTimer15000:
	stopnpctimer;
	if(get_instance_var("boss_dead")) end;
	.@gid = get_instance_var("gid");
	if(!unitexists(get_instance_var("gid"))) initnpctimer;
	function SafeSkill;
	SafeSkill;
	initnpctimer;
end;

function	SafeSkill	{
	if(get_instance_var("boss_dead")) end;
	.@gid = get_instance_var("gid");
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnSkillDead";
	setarray .@x[1],
	-10,-5,0,5,10,
	-10,-5,0,5,10,
	-10,-5,0,5,10,
	-10,-5,0,5,10,
	-10,-5,0,5,10;
	setarray .@y[1],
	10,10,10,10,10,
	5,5,5,5,5,
	0,0,0,0,0,
	-5,-5,-5,-5,-5,
	-10,-10,-10,-10,-10;
	if(unitexists(.@gid)){
		getunitdata .@gid,.@data;
		.@x2 = .@data[UMOB_X];
		.@y2 = .@data[UMOB_Y];
		for(.@i = 1; .@i < getarraysize(.@x); .@i++){
			if(!unitexists(.@gid))
				break;
			monster .@map$,.@x2 + .@x[.@i],.@y2 + .@y[.@i],"",20562,1,.@event$;
			setunitdata $@mobid[0],UMOB_DMGIMMUNE,true;
			unitskillusepos $@mobid[0],"HW_GANBANTEIN",1,.@x2 + .@x[.@i],.@y2 + .@y[.@i],-10000;
			if(.@i % 5 == 0)
				sleep 200;
		}
		sleep 1000;
		killmonster .@map$,.@event$;
	}
	return;
}

OnSkillDead:
end;
}

3@ch_t,1,1,0	script	#ctower_skill_soul	HIDDEN_WARP_NPC,{
	end;

OnSkill:
	initnpctimer;
end;

OnTimer10000:
	if(get_instance_var("phase") < 3) end;
	stopnpctimer;
	if(get_instance_var("boss_dead")) end;
	if(!unitexists(get_instance_var("gid"))) initnpctimer;
	function SafeSkill;
	SafeSkill;
	initnpctimer;
end;

OnTimer15000:
	stopnpctimer;
	if(get_instance_var("boss_dead")) end;
	if(!unitexists(get_instance_var("gid"))) initnpctimer;
	function SafeSkill;
	SafeSkill;
	initnpctimer;
end;

function	SafeSkill	{
	if(get_instance_var("boss_dead")) end;
	.@gid = get_instance_var("gid");
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnSkillDead";
	monster .@map$,rand(148,163),rand(74,101),"Betelguese's Soul",20995,2,.@event$;
	getunitdata .@gid,.@data;
	setunitdata .@gid,UMOB_RES,.@data[UMOB_RES] + 100;
	setunitdata .@gid,UMOB_MRES,.@data[UMOB_MRES] + 100;
	mapannounce .@map$,"Betelguese reproduced his soul and spread it all over the place. Betelguese resistance rises as much as the number of souls around the area.",bc_blue;
	return;
}

OnSkillDead:
	.@gid = get_instance_var("gid");
	getunitdata .@gid,.@data;
	setunitdata .@gid,UMOB_RES,.@data[UMOB_RES] - 50;
	setunitdata .@gid,UMOB_MRES,.@data[UMOB_MRES] - 50;
end;
}

3@ch_t,1,1,0	script	#ctower_skill_heal	HIDDEN_WARP_NPC,{
	end;

OnSkill:
	initnpctimer;
end;

OnTimer5000:
	stopnpctimer;
	if(get_instance_var("boss_dead")) end;
	.@gid = get_instance_var("gid");
	if(!unitexists(.@gid)){
		initnpctimer;
		end;
	}
	getunitdata .@gid,.@data;
	//RECO * 1% (MAX_HP)
	.@HEAL = (.@data[UMOB_MAXHP]/100) * get_instance_var("RECO");
	setunitdata .@gid,UMOB_HP,.@data[UMOB_HP] + .@HEAL;
	initnpctimer;
end;
}

3@ch_t,1,1,0	script	#ctower_check_area	HIDDEN_WARP_NPC,{
	end;

OnCheck:
	initnpctimer;
end;

OnTimer1000:
	stopnpctimer;
    .@map$ = get_instance_var("map$");
	.@count = get_instance_var("count");
	.@map$ = get_instance_var("map$");
	.@gid = get_instance_var("gid");
	if(!.@gid){	
		initnpctimer;
		end;
	}
	if(unitexists(.@gid)){
		getunitdata .@gid,.@data;
        .@x = .@data[UMOB_X];
        .@y = .@data[UMOB_Y];
        if(.@x < 148 || .@x > 163 || .@y < 74 || .@y > 101){
            sleep 5000;
            if(.@x < 148 || .@x > 163 || .@y < 74 || .@y > 101){
                ctower_recalc_stats(.@gid,10);
				unitwarp .@gid,.@map$,156,81;
                instance_warpall .@map$,156,79,instance_id();
                sleep 3000;
                unitskilluseid .@gid,"NPC_HELLJUDGEMENT2",10;
				sleep 2000;
				 unitskilluseid .@gid,"NPC_EARTHQUAKE",10;
                sleep 1000;
                ctower_revert_stats(.@gid);
            } else
                initnpctimer;
        }
    }
	initnpctimer;
end;
}

3@ch_t,1,1,0	script	#ctower_check_dead	HIDDEN_WARP_NPC,{
	end;

OnCheck:
	initnpctimer;
end;

OnTimer1000:
	if(get_instance_var("boss_dead")) end;
	stopnpctimer;
	.@count = get_instance_var("count");
	.@map$ = get_instance_var("map$");
	.@gid = get_instance_var("gid");
	if(!.@gid){	
		initnpctimer;
		end;
	}
	if(unitexists(.@gid))
		getunitdata .@gid,.@data;
	else
		initnpctimer;
	.@mode = .@data[UMOB_MODE];
	for(.@i = 0; .@i < .@count; .@i++){
		if(attachrid(get_instance_var("aid_" + .@i))){
			if(Hp < 1){
				.@gid = get_instance_var("gid");
				if(!.@gid){
					initnpctimer;
					end;
				}
				if(unitexists(.@gid))
					setunitdata .@gid,UMOB_MODE,(.@mode|MD_IGNOREMELEE|MD_IGNOREMAGIC|MD_IGNORERANGED|MD_IGNOREMISC);
				else
					initnpctimer;
				while(Hp < 1)
					sleep2 1000;
				setunitdata .@gid,UMOB_MODE,.@mode;
			}
			detachrid;
		}
	}
	initnpctimer;
end;
}
	
3@ch_t,1,1,0	script	#ctower_party_check	HIDDEN_WARP_NPC,{
	end;
	
OnCheck:
	initnpctimer;
end;

OnTimer1000:
	stopnpctimer;
	.@count = get_instance_var("count");
	.@map$ = get_instance_var("map$");
	.@gid = get_instance_var("gid");
	if(getmapunits(BL_PC,.@map$) == .@count)
		initnpctimer;
	else {
		while(getmapunits(BL_PC,.@map$) != .@count){
			if(unitexists(.@gid))
					setunitdata .@gid,UMOB_DMGIMMUNE,true;
				else
					break;
			sleep 100;
		}
		if(unitexists(get_instance_var("gid")))
			setunitdata .@gid,UMOB_DMGIMMUNE,false;
		initnpctimer;
	}
	end;
end;
}

3@ch_t,142,85,3	script	#ctower_trap_0	20112,1,1,{
    end;

OnTouch:
	if(!get_instance_var("trap_active")) end;
    if(get_instance_var("phase") == 2){
		.@DAMAGE = (MaxHp / 10) * (1 + get_instance_var("TRAP"));
		specialeffect2 EF_HYOUSYOURAKU;
	} else {
		.@DAMAGE = (MaxHp / 10) * (2 + get_instance_var("TRAP"));
		specialeffect2 EF_FIREHIT;
		pushpc rand(1,7),rand(1,2);
    }
	if(.@DAMAGE > Hp && get_instance_var("phase") > 2)
		unitkill getcharid(3);
	else
		Hp -= .@DAMAGE;
end;

OnMove:
	.@id = atoi(replacestr(strnpcinfo(2),"ctower_trap_",""));
	getunitdata getnpcid(0,instance_npcname(strnpcinfo(0))),.@data;
	set_instance_var("x_" + strnpcinfo(2),.@data[UNPC_X]);
	switch(.@id){
		case 0: npcspeed 161; break;
		case 1: npcspeed 159; break;
		case 2: npcspeed 179; break;
		case 3: npcspeed 170; break;
		case 4: npcspeed 166; break;
		case 5: npcspeed 172; break;
		case 6: npcspeed 160; break;
		case 7: npcspeed 164; break;
		case 8: npcspeed 154; break;
		case 9: npcspeed 156; break;
	}
	switch(.@id){
		case 0:
			instance_event(strnpcinfo(0),"OnWalk",false);
			break;

		case 1:
			instance_event(strnpcinfo(0),"OnWalk5",false);
			break;
			
		default:
			if(.@id % 2 == 0)
				instance_event(strnpcinfo(0),"OnWalk",false);
			else
				instance_event(strnpcinfo(0),"OnWalk5",false);
			break;
	}
end;

OnWalk:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),get_instance_var("x_" + strnpcinfo(2)),110,instance_npcname(strnpcinfo(0)) + "::OnWalk2";
end;

OnWalk2:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),get_instance_var("x_" + strnpcinfo(2)),85,instance_npcname(strnpcinfo(0)) + "::OnWalk3";
end;

OnWalk3:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),get_instance_var("x_" + strnpcinfo(2)),64,instance_npcname(strnpcinfo(0)) + "::OnWalk4";
end;

OnWalk4:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),get_instance_var("x_" + strnpcinfo(2)),85,instance_npcname(strnpcinfo(0)) + "::OnWalk";
end;

OnWalk5:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),get_instance_var("x_" + strnpcinfo(2)),64,instance_npcname(strnpcinfo(0)) + "::OnWalk6";
end;

OnWalk6:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),get_instance_var("x_" + strnpcinfo(2)),85,instance_npcname(strnpcinfo(0)) + "::OnWalk7";
end;

OnWalk7:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),get_instance_var("x_" + strnpcinfo(2)),110,instance_npcname(strnpcinfo(0)) + "::OnWalk8";
end;

OnWalk8:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),get_instance_var("x_" + strnpcinfo(2)),85,instance_npcname(strnpcinfo(0)) + "::OnWalk5";
end;
}

3@ch_t,145,85,3	duplicate(#ctower_trap_0)	#ctower_trap_1	20112,1,1
3@ch_t,148,85,3	duplicate(#ctower_trap_0)	#ctower_trap_2	20112,1,1
3@ch_t,151,85,3	duplicate(#ctower_trap_0)	#ctower_trap_3	20112,1,1
3@ch_t,154,85,3	duplicate(#ctower_trap_0)	#ctower_trap_4	20112,1,1
3@ch_t,157,85,3	duplicate(#ctower_trap_0)	#ctower_trap_5	20112,1,1
3@ch_t,160,85,3	duplicate(#ctower_trap_0)	#ctower_trap_6	20112,1,1
3@ch_t,163,85,3	duplicate(#ctower_trap_0)	#ctower_trap_7	20112,1,1
3@ch_t,166,85,3	duplicate(#ctower_trap_0)	#ctower_trap_8	20112,1,1
3@ch_t,169,85,3	duplicate(#ctower_trap_0)	#ctower_trap_9	20112,1,1

3@ch_t,156,64,3	script	#ctower_trap2_0	20112,1,1,{
    end;

OnTouch:
	if(!get_instance_var("trap_active")) end;
    if(get_instance_var("phase") == 2){
		.@DAMAGE = (MaxHp / 10) * (1 + get_instance_var("TRAP"));
		specialeffect2 EF_HYOUSYOURAKU;
	} else {
		.@DAMAGE = (MaxHp / 10) * (2 + get_instance_var("TRAP"));
		specialeffect2 EF_FIREHIT;
		pushpc rand(1,7),rand(1,2);
    }
	if(.@DAMAGE > Hp && get_instance_var("phase") > 2)
		unitkill getcharid(3);
	else
		Hp -= .@DAMAGE;
end;

OnMove:
	.@id = atoi(replacestr(strnpcinfo(2),"ctower_trap2_",""));
	getunitdata getnpcid(0,instance_npcname(strnpcinfo(0))),.@data;
	set_instance_var("y_" + strnpcinfo(2),.@data[UNPC_Y]);
	switch(.@id){
		case 0: npcspeed 158; break;
		case 1: npcspeed 161; break;
		case 2: npcspeed 163; break;
		case 3: npcspeed 154; break;
		case 4: npcspeed 163; break;
		case 5: npcspeed 168; break;
		case 6: npcspeed 162; break;
		case 7: npcspeed 154; break;
		case 8: npcspeed 157; break;
		case 9: npcspeed 174; break;
		case 10: npcspeed 163; break;
		case 11: npcspeed 154; break;
		case 12: npcspeed 172; break;
		case 13: npcspeed 168; break;
		case 14: npcspeed 165; break;
		case 15: npcspeed 171; break;
	}
	switch(.@id){
		case 0:
			instance_event(strnpcinfo(0),"OnWalk",false);
			break;

		case 1:
			instance_event(strnpcinfo(0),"OnWalk5",false);
			break;
			
		default:
			if(.@id % 2 == 0)
				instance_event(strnpcinfo(0),"OnWalk",false);
			else
				instance_event(strnpcinfo(0),"OnWalk5",false);
			break;
	}
end;

OnWalk:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),142,get_instance_var("y_" + strnpcinfo(2)),instance_npcname(strnpcinfo(0)) + "::OnWalk2";
end;

OnWalk2:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),156,get_instance_var("y_" + strnpcinfo(2)),instance_npcname(strnpcinfo(0)) + "::OnWalk3";
end;

OnWalk3:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),169,get_instance_var("y_" + strnpcinfo(2)),instance_npcname(strnpcinfo(0)) + "::OnWalk4";
end;

OnWalk4:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),156,get_instance_var("y_" + strnpcinfo(2)),instance_npcname(strnpcinfo(0)) + "::OnWalk";
end;

OnWalk5:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),169,get_instance_var("y_" + strnpcinfo(2)),instance_npcname(strnpcinfo(0)) + "::OnWalk6";
end;

OnWalk6:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),156,get_instance_var("y_" + strnpcinfo(2)),instance_npcname(strnpcinfo(0)) + "::OnWalk7";
end;

OnWalk7:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),142,get_instance_var("y_" + strnpcinfo(2)),instance_npcname(strnpcinfo(0)) + "::OnWalk8";
end;

OnWalk8:
	unitwalk getnpcid(0,instance_npcname(strnpcinfo(0))),156,get_instance_var("y_" + strnpcinfo(2)),instance_npcname(strnpcinfo(0)) + "::OnWalk5";
end;
}

3@ch_t,156,67,3	duplicate(#ctower_trap2_0)	#ctower_trap2_1	20112,1,1
3@ch_t,156,70,3	duplicate(#ctower_trap2_0)	#ctower_trap2_2	20112,1,1
3@ch_t,156,73,3	duplicate(#ctower_trap2_0)	#ctower_trap2_3	20112,1,1
3@ch_t,156,76,3	duplicate(#ctower_trap2_0)	#ctower_trap2_4	20112,1,1
3@ch_t,156,79,3	duplicate(#ctower_trap2_0)	#ctower_trap2_5	20112,1,1
3@ch_t,156,82,3	duplicate(#ctower_trap2_0)	#ctower_trap2_6	20112,1,1
3@ch_t,156,85,3	duplicate(#ctower_trap2_0)	#ctower_trap2_7	20112,1,1
3@ch_t,156,88,3	duplicate(#ctower_trap2_0)	#ctower_trap2_8	20112,1,1
3@ch_t,156,91,3	duplicate(#ctower_trap2_0)	#ctower_trap2_9	20112,1,1
3@ch_t,156,94,3	duplicate(#ctower_trap2_0)	#ctower_trap2_10	20112,1,1
3@ch_t,156,97,3	duplicate(#ctower_trap2_0)	#ctower_trap2_11	20112,1,1
3@ch_t,156,100,3	duplicate(#ctower_trap2_0)	#ctower_trap2_12	20112,1,1
3@ch_t,156,103,3	duplicate(#ctower_trap2_0)	#ctower_trap2_13	20112,1,1
3@ch_t,156,106,3	duplicate(#ctower_trap2_0)	#ctower_trap2_14	20112,1,1
3@ch_t,156,109,3	duplicate(#ctower_trap2_0)	#ctower_trap2_15	20112,1,1

3@ch_t,156,96,1	script	#ctower_exit	PORTAL,{
	mes "^0000CDDo you want to leave the tower?^000000";
	next;
	if(select("Cancel.:Leave.") == 1) end;
	warp "e_tower",70,114;
	end;
}