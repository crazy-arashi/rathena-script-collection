//===== Crazyarashi Services =====================================|
//= Tomb of Remorse                                              =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

dali,123,88,0	script	#remorse_ev_0	HIDDEN_WARP_NPC,3,3,{
	end;

OnTouch:
	if(BaseLevel < 220) end;
	if(isbegin_quest(16461) == 0 || isbegin_quest(16461) == 1)
		cloaknpc("Princess of Remorse#remorse",false);
end;
}

dali,80,112,0	script	#remorse_ev_1	HIDDEN_WARP_NPC,3,3,{
	end;

OnTouch:
	if(isbegin_quest(16462) == 1)
		cloaknpc("Princess of Remorse#remorse2",false);
end;
}

dali02,77,114,0	script	#remorse_ev_2	HIDDEN_WARP_NPC,5,5,{
	end;

OnTouch:
	if(isbegin_quest(16463) > 0){
		cloaknpc("Princess of Remorse#remorse3",false);
		cloaknpc("Marquis of Remorse#remorse",false);
	}
end;
}

dali,124,88,3	script	Princess of Remorse#remorse	20893,{
	if(isbegin_quest(16461) == 0){
		mes "[ Princess of Remorse ]";
		mes "......";
		next;
		mes "[ Princess of Remorse ]";
		mes "Ah, finally you have arrived, hero.";
		mes "Unspoken traces of your feat are engraved in your every action.";
		next;
		mes "[ Princess of Remorse ]";
		mes "I would like to ask you a favor.";
		mes "Can you lay rest to the dead who are wandering in the old world?";
		next;
		if(select("Listen closely.:Refuse.") == 2){
			mes "[ Princess of Remorse ]";
			mes "......";
			close;
		}
		mes "[ Princess of Remorse ]";
		mes "Thank you.";
		mes "Then, please listen...... to my story.";
		setquest 16461;
		questinfo_refresh();
		close;
	}
	if(isbegin_quest(16461) == 1){
		mes "[ Princess of Remorse ]";
		mes "I was the princess of the old tomb.";
		next;
		mes "[ Princess of Remorse ]";
		mes "I am here to ask for help, for those who can not rest even after their death.";
		next;
		mes "[ Princess of Remorse ]";
		mes "Will you come with me. To the tomb of remorse, please......";
		completequest 16461;
		setquest 16462;
		navigateto("dali",79,112);
		close2;
		cloaknpc(strnpcinfo(0),true,getcharid(0));
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
	questinfo QTYPE_QUEST,QMARK_YELLOW,"isbegin_quest(16461) == 1";
end;
}

dali,79,112,3	script	Princess of Remorse#remorse2	20893,{
	if(isbegin_quest(16462) == 1){
		mes "[ Princess of Remorse ]";
		mes "It was a long time ago.";
		next;
		mes "[ Princess of Remorse ]";
		mes "I fell into the evil's temptation, I and all the people of the old kingdom lost their lives in vain.";
		next;
		mes "[ Princess of Remorse ]";
		mes "I wish it had ended with that, but we could not find our peace even after death.";
		next;
		mes "[ Princess of Remorse ]";
		mes "Because the tragedy was caused by someone who lost his soul and became a wandering body.";
		next;
		mes "[ Princess of Remorse ]";
		mes "We ended up with the same fate, we are wandering around the empty castle like a spirit, looking for someone to make us rest.";
		next;
		mes "[ Princess of Remorse ]";
		mes "If you think you can help us, please follow me.";
		completequest 16462;
		setquest 16463;
		navigateto("dali02",78,116);
		close2;
		cloaknpc(strnpcinfo(0),true,getcharid(0));
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

dali02,78,116,3	script	Princess of Remorse#remorse3	20893,{
	if(isbegin_quest(16463) == 1){
		mes "[ Princess of Remorse ]";
		mes "My family and all my people have been turned into undead.";
		next;
		mes "[ Princess of Remorse ]";
		mes "No matter how many times we died or killed, we rose again, staggering and walking between the fallen pillars and torn insignias.";
		next;
		mes "[ Princess of Remorse ]";
		mes "Now, I am tired of knowing why, I just want to find some peace.";
		mes "But even that is not possible......";
		next;
		mes "[ Princess of Remorse ]";
		mes "Hero, please help us.";
		npctalk "Marquis of Remorse : Well, are you the one recognized by the princess? Come here for a second.","Marquis of Remorse#remorse",bc_self;
		completequest 16463;
		close;
	}
	switch(checkquest(16464,PLAYTIME)){
		case -1:
			break;
			
		case 0:
		case 1:
			mes "[ Princess of Remorse ]";
			mes "Thank you for your help, hero.";
			mes "This occurence will keep repeating endlessly. I hope you can assist me again.";
			next;
			mes "[ Princess of Remorse ]";
			mes "For the sake of the people of the Royal Palace, I want them to have their peace.";
			close;
			
		case 2:
			erasequest 16464;
			break;
	}
	.@party_id = getcharid(1);
	if(!.@party_id) instance_warning(1);
	mes "[ Princess of Remorse ]";
	mes "Will you come with me?";
	mes "To the palace where the specters are wandering with their tired body, to the tomb of remorse......";
	next;
	instance_warning(0);
	next;
	.@md_name$ = "Tomb of Remorse";
	if(select((is_party_leader()?"Create Tomb of Remorse":""),"Enter Tomb of Remorse") == 1){
		if(instance_create(.@md_name$) == -3)
			instance_warning(2);
		mes "[ Princess of Remorse ]";
		mes "Once the memorial dungeon has been completed, please talk to me again to enter the ^0000CDTomb of Remorse^000000.";
	} else {
		if(instance_enter(.@md_name$) == IE_OK){
			.@party_name$ = getpartyname(.@party_id);
			setquest 16464;
			mapannounce "dali02", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00FF99";
		} else
			mes "^0000FFThe memorial dungeon has not been created yet or you're entering a different memorial dungeon from the one created.^000000";
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

dali02,78,112,3	script	Marquis of Remorse#remorse	20899,{
	if(isbegin_quest(16463) < 2) end;
	function cd_check;
	mes "[ Marquis of Remorse ]";
	mes "I see, you're the one who the princess believes in.";
	mes "If you really are that kind of person, then I will depend on you too.";
	next;
	switch(select("Broken threads of fate.:Shedding in tears.:Memory fragments.:Fragments of the past.:Mineas Exchange.:Cancel.")){
		case 1:
			.@qid = 16465;
			.@cid = 16466;
			cd_check(.@cid);
			if(isbegin_quest(.@qid) == 0){
				mes "[ Marquis of Remorse ]";
				mes "Do you know those people wandering in the Tomb of Remorse?";
				next;
				mes "[ Marquis of Remorse ]";
				mes "Those cursed bodies that cannot sleep forever, rotting continously...";
				mes "In the meantime, there is a man whose soul is tied to a sword, neither a living or dead is also wandering.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "You are the one called by the princess herself, but not by him.";
				mes "I'm sure at one point, the princess will also get in your way of what she asked you to do.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "The princess misses him so much...... It's been a long time since fate cut them off.";
				mes "The only mercy that we can give him now is to get him off this world.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "Will you help the princess?";
				next;
				if(select("Lend your strength.:Don't help.") == 2) goto OnDecline;
				mes "[ Marquis of Remorse ]";
				mes "Thank you for lending your strength.";
				mes "At the final point in the castle, the one who will hold the sword will be there.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "Please put the ^0000CDMagic Swordsman Sakray^000000 to rest.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "I'll be waiting there.";
				mes "I'll see you there hero.";
				setquest .@qid;
			} else {
				mes "[ Marquis of Remorse ]";
				mes "I don't think you haven't settled it with the ^0000CDMagic Swordsman Sakray^000000 yet.";
				mes "For the princess, I ask for your kind cooperation.";
			}
			close;
		
		case 2:
			.@qid = 16467;
			.@cid = 16468;
			cd_check(.@cid);
			if(isbegin_quest(.@qid) == 0){
				mes "[ Marquis of Remorse ]";
				mes "Sometimes, there has to be some work to be done, even if it breaks your heart.";
				mes "It's a better choice in the end, I have no choice but to do it, even if it's painful.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "The princess can talk to you know, but it won't last long.";
				mes "The reason is because of the curse.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "After the curse returns, like the rest of the undead in the tomb, she will only have instinct for blood in her head.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "The princess wishes to be disposed before she harms anyone.";
				mes "The princess wants you the hero to do it.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "If the Princess Tiara ever attacks you in the ^0000CDTomb of Remorse^000000, will you listen to what she ask?";
				next;
				if(select("I'll listen.:I won't listen.") == 2) goto OnDecline;
				mes "[ Marquis of Remorse ]";
				mes "I respect you for that choice.";
				mes "Princess Tiara will be wandering around the tomb.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "If a trace of her reason remains even a faint of it.";
				mes "She will prevent the undeads in the tomb from coming up.";
				setquest .@qid;
			} else {
				mes "[ Marquis of Remorse ]";
				mes "If the Princess Tiara ever attacks you in the ^0000CDTomb of Remorse^000000, will you take her down?";
				mes "Even if it's painful, I kindly ask for your cooperation.";
			}
			close;
		
		case 3:
			.@qid = 16469;
			.@cid = 16470;
			cd_check(.@cid);
			if(isbegin_quest(.@qid) == 0){
				mes "[ Marquis of Remorse ]";
				mes "Somewhere in the tomb, pieces of old memories are sleeping.";
				mes "I only know that there is, but I don't know what it's about.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "With this body, I couldn't find it no matter how hard I try.";
				mes "If you find them, you might learn more about what happened inside the castle......";
				next;
				mes "[ Marquis of Remorse ]";
				mes "Maybe I can't find it because I'm tied up to that place.";
				mes "Can you find those pieces of memory pieces?";
				next;
				mes "[ Marquis of Remorse ]";
				mes "It's the memory of the palace before it turned into a tomb, or it might be a trace to what happen.";
				mes "They say that there's three pieces that are asleep.";
				next;
				if(select("I'll find it.:I won't find it.") == 2) goto OnDecline;
				mes "[ Marquis of Remorse ]";
				mes "These pieces can't be taken outside, I'll be inside the old palace.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "If you finish everything, I'll be waiting for you inside the palace.";
				setquest .@qid;
			} else {
				mes "[ Marquis of Remorse ]";
				mes "I will need you to find atleast three sleeping pieces inside the tomb.";
				mes "I'll be waiting for you inside the palace.";
			}
			close;	
		
		case 4:
			.@qid = 16471;
			.@cid = 16472;
			cd_check(.@cid);
			if(isbegin_quest(.@qid) == 0){
				mes "[ Marquis of Remorse ]";
				mes "There are ^0000CDFragments of the past^000000 scattered all over the castle.";
				mes "I want you to collect it.";
				next;
				select("Fragment of the past?");
				mes "[ Marquis of Remorse ]";
				mes "It's the trace of what that man has been through in the past.";
				mes "There are fragment that formed after the people of the castle were scattered.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "Even after the humans forgot all the memories of the castle, the castle made it so that it doesn't forget it's own memories...";
				mes "It's hidden somewhere in there, so I'd appreciate if you could find all ten of them.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "It's his beliefs, but I want you to collect it and tell the world that the castle existed.";
				mes "Even if it's just a bunch of fragments.";
				next;
				if(select("I'll collect it.:Refuse to collect.") == 2) goto OnDecline;
				mes "[ Marquis of Remorse ]";
				mes "I wish you the best of luck.";
				mes "You can't bring these fragments outside, so I'll be waiting inside.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "If you finish everything, I'll be waiting for you inside the palace.";
				setquest .@qid;
			} else {
				mes "[ Marquis of Remorse ]";
				mes "I want you to find the ten fragments of the past.";
				mes "I'll be waiting for you inside the palace.";
			}
			close;
		
		case 5:
			mes "[ Marquis of Remorse ]";
			mes "If you have a jewel given to you, a stone where the princess' remorse are gathered.";
			mes "That thing won't be a use to you, hero. If you need anything, I'll exchange it for that.";
			next;
			switch(select("Jewel Exchange.:Weapon Exchange.:Cancel")){
				case 1:
					callshop "remorse_item",1;
					break;
					
				case 2:
					callshop "remorse_weapon",1;
					break;
					
				case 3:
					break;
			}
			end;
		
		case 6:
			mes "[ Marquis of Remorse ]";
			mes "I'll still have to see it with my own eyes.";
			mes "Even if the princess herself brought you, I'll only acknowledge you after seeing what you can do in person.";
			close;
	}
	end;
	
function	cd_check	{
	switch(checkquest(getarg(0),PLAYTIME)){
		case -1: 
			return;
		case 0:
		case 1:
			mes "[ Marquis of Remorse ]";
			mes "As much as I'm happy for your kindness, hero. I can still find the traces from my request from the last time.";
			mes "Please come back again in dawn.";
			close;
			
		case 2:
			erasequest getarg(0);
			return;
	}
}
	
OnDecline:
	mes "[ Marquis of Remorse ]";
	mes "If I owe you something, I won't be able to pay you back, so it might be a wise choice.";
	close;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

1@spa2,1,1,0	script	#remorse_control	-1,{
	end;
	
OnInstanceInit:
	set_instance_var("map$",instance_mapname("1@spa2"));
	instance_enable("#rms_warp_0",false);
	instance_enable("#rms_warp_1",false);
	instance_enable("#rms_warp_2",false);
	instance_enable("#rms_warp_3",false);
	instance_enable("Princess#rms_shard_0",false);
	instance_enable("Knight#rms_shard_0",false);
	instance_enable("Magic Swordsman#rms_shard_0",false);
	instance_enable("???#rms_shard_0",false);
	instance_enable("Sakray#rms_0",false);
	instance_enable("Marquis of Remorse#rms_0",false);
	instance_enable("Memory Piece#rms_1",false);
	instance_enable("Memory Piece#rms_2",false);
	instance_enable("Princess#rms_shard_1",false);
	instance_enable("Marquis#rms_shard_0",false);
	for(.@i = 0; .@i < 3; .@i++)
		instance_enable("#rms_stone_" + .@i,false);
end;
}

1@spa2,51,198,0	script	#rms_ev_0	HIDDEN_WARP_NPC,2,2,{
	end;
	
OnTouch:
	set_instance_var("rms",0);
	if(!is_party_leader() || get_instance_var("rms")) end;
	set_instance_var("rms",1);
	instance_disable(strnpcinfo(0));
	sleep 2000;
	.@map$ = get_instance_var("map$");
	mapannounce .@map$,"Princess of Remorse : This place has been asleep for a long time after that incident.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Princess of Remorse : But with someones power, those who were resting were forced to rise.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Princess of Remorse : It is a shame, but I am one of them.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Princess of Remorse : We are losing reason and humanity, continuing to engage in meaningless battles.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Princess of Remorse : All of us wishes for our eternal sleep.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Princess of Remorse : Hero, please help us.",bc_map,0x00FF99;
	instance_event("#rms_mob","OnSummon_F1",false);
end;
}

1@spa2,215,202,0	script	#rms_ev_1	HIDDEN_WARP_NPC,2,2,{
	end;
	
OnTouch:
	if(!is_party_leader()) end;
	if(get_instance_var("rms") > 1) end;
	set_instance_var("rms",2);
	instance_disable(strnpcinfo(0));
	instance_event("#rms_mob","OnSummon_F2",false);
	.@map$ = get_instance_var("map$");
	mapannounce .@map$,"Marquis of Remorse : The princess has disappeared, she doesn't want to show herself while she is losing her mind.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Marquis of Remorse : But soon she will be drawn to the living that's in this place.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Marquis of Remorse : Please take care of the undeads and the princess.",bc_map,0x00FF99;
end;
}

1@spa2,57,23,0	script	#rms_ev_2	HIDDEN_WARP_NPC,2,2,{
	end;
	
OnTouch:
	if(!is_party_leader()) end;
	if(get_instance_var("rms") > 2) end;
	set_instance_var("rms",3);
	instance_disable(strnpcinfo(0));
	instance_event("#rms_mob","OnSummon_F3",false);
	.@map$ = get_instance_var("map$");
	mapannounce .@map$,"Marquis of Remorse : This is the tomb of the royal family. It used to be a peaceful place where several generations of the royal family are resting.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Marquis of Remorse : The guardian of the tomb not only lost his life, but also the bodies that are resting in the tomb were thrown into chaos.",bc_map,0x00FF99;
	sleep 3000;
	mapannounce .@map$,"Marquis of Remorse : Put the undead that are in here to rest.",bc_map,0x00FF99;
end;
}

1@spa2,212,55,0	script	#rms_ev_3	HIDDEN_WARP_NPC,2,2,{
OnTouch:
	if(!is_party_leader()) end;
	if(get_instance_var("rms") > 3) end;
	set_instance_var("rms",4);
	instance_disable(strnpcinfo(0));
	sleep 1000;
	instance_enable("Sakray#rms_0",true);
	.@sak$ = instance_npcname("Sakray#rms_0");
	npctalk "Magic Swordsman Sakray : Why, why are you here?",.@sak$;
	sleep 3000;
	npctalk "Magic Swordsman Sakray : I'm here to see the princess one more time. Why are you in this place?",.@sak$;
	sleep 3000;
	npctalk "Magic Sword Tartanos : Oh! Isn't that the same person..... you have ripened brilliantly.",.@sak$;
	sleep 3000;
	npctalk "Magic Sword Tartanos : Sakray, hurry and offer me that person's blood! Let me feast on that blood!",.@sak$;
	sleep 3000;
	npctalk "Magic Swordsman Sakray : Before that..... I need to find the princess.....",.@sak$;
	sleep 3000;
	npctalk "Magic Sword Tartanos : Don't you see the reason that person is here? Everything around you is that person's fault, now keep the contract. Sakray!",.@sak$;
	sleep 3000;
	npctalk "Magic Swordsman Sakray : Is that so..... Maybe it is as Tartanos said. I can't escape from this demon sword anyway.",.@sak$;
	sleep 3000;
	npctalk "Magic Swordsman Sakray : Long words are not needed, Come at me. Become the demon sword's prey!",.@sak$;
	sleep 3000;
	instance_enable("Sakray#rms_0",false);
	monster get_instance_var("map$"),211,67,"--ja--",20892,1,instance_npcname("#rms_boss") + "::OnSakrayDead";
	set_instance_var("boss_gid",$@mobid[0]);
	instance_event("#rms_boss","OnBossSkill",false);
end;
}

1@spa2,211,67,3	duplicate(dummynpc2)	Sakray#rms_0	4_M_SAKRAY

1@spa2,28,226,3	script	Memory Piece#rms_0	CLEAR_NPC,{
	.@id = atoi(replacestr(strnpcinfo(2),"rms_",""));
	if(!is_party_leader() || get_instance_var("memory_" + .@id)){
		switch(.@id){
			case 0:
				mes "The old broken piano made a murky sounds when I pressed the a key.";
				close;
				
			case 1:
				mes "There is a huge amount of dust in this area specifically.";
				close;
				
			case 2:
				mes "The old tomb has been open.";
				close;			
		}
	}
	switch(.@id){
		case 0:
			.@princess$ = instance_npcname("Princess#rms_shard_0");
			.@knight$ = instance_npcname("Knight#rms_shard_0");
			instance_enable("Princess#rms_shard_0",true);
			instance_enable("Knight#rms_shard_0",true);
			specialeffect EF_DA_SPACE,AREA,.@princess$;
			specialeffect EF_DA_SPACE,AREA,.@knight$;
			mes "[ Knight ]";
			mes "You always play the same piece, princess.";
			npctalk "Knight : You always play the same piece, princess.",.@knight$;
			next;
			mes "[ Princess ]";
			mes "I didn't know you were listening.";
			npctalk "Knight : I didn't know you were listening.",.@knight$;
			next;
			mes "[ Knight ]";
			mes "I have always been by your side.";
			npctalk "Knight : I have always been by your side.",.@knight$;
			next;
			mes "[ Princess ]";
			mes "I see. Will it still be the same even after I become a bride of the prince of the neighboring country?";
			npctalk "Princess : I see. Will it still be the same even after I become a bride of the prince of the neighboring country?",.@princess$;
			next;
			mes "[ Knight ]";
			mes "I...... I will always serve you by your side.";
			npctalk "Knight : I...... I will always serve you by your side.",.@knight$;
			next;
			mes "[ Princess ]";
			mes "Is that so. You will always be by my side.";
			npctalk "Princess : Is that so. You will always be by my side.",.@princess$;
			next;
			mes "[ Knight ]";
			mes "......";
			npctalk "Knight : ......",.@knight$;
			next;
			mes "[ Princess ]";
			mes "Sakray, I'm going to talk a bit to myself from now on.";
			npctalk "Princess : Sakray, I'm going to talk a bit to myself from now on.",.@princess$;
			next;
			mes "[ Knight ]";
			mes "I don't hear anything.";
			npctalk "Knight : I don't hear anything.",.@knight$;
			next;
			mes "[ Princess ]";
			mes "I am a princess. It is not princess like to make a foolish choice by being swept away by emotions.";
			npctalk "Princess : I am a princess. It is not princess like to make a foolish choice by being swept away by emotions.",.@princess$;
			next;
			mes "[ Princess ]";
			mes "Marriage is a duty to a princess. There is no need for affection nor love.";
			npctalk "Princess : Marriage is a duty to a princess. There is no need for affection nor love.",.@princess$;
			next;
			mes "[ Princess ]";
			mes "But for the first time in my life, I feel resent to my duty.";
			npctalk "Princess : But for the first time in my life, I feel resent to my duty.",.@princess$;
			next;
			mes "[ Princess ]";
			mes "I envy those who are born as a normal girl, caring faithfully for the lovely boy next to her with all her heart.";
			npctalk "Princess : I envy those who are born as a normal girl, caring faithfully for the lovely boy next to her with all her heart.",.@princess$;
			next;
			mes "[ Princess ]";
			mes "How happy they could be to grow up together and become an adult to reveal the harmony and share affection as a couple.";
			npctalk "Princess : How happy they could be to grow up together and become an adult to reveal the harmony and share affection as a couple.",.@princess$;
			next;
			mes "[ Princess ]";
			mes "If I only could rely on you and love you all my life.";
			npctalk "Princess : If I only could rely on you and love you all my life.",.@princess$;
			next;
			mes "[ Knight ]";
			mes "......";
			npctalk "Knight : ......",.@knight$;
			next;
			mes "[ Princess ]";
			mes "I should not talk to myself for too long.";
			mes "Sakray.";
			npctalk "Princess : I should not talk to myself for too long. Sakray.",.@princess$;
			next;
			mes "[ Knight ]";
			mes "Yes, princess.";
			npctalk "Knight : Yes, princess.",.@knight$;
			next;
			mes "[ Princess ]";
			mes "I am tired, Escort me back to my room.";
			npctalk "Princess : I am tired, Escort me back to my room.",.@princess$;
			next;
			mes "[ Knight ]";
			mes "Then, I'll take you, princess.";
			npctalk "Knight : Then, I'll take you, princess.",.@knight$;
			next;
			instance_disable("Knight#rms_shard_0");
			mes "[ Princess ]";
			mes "Sakray......";
			npctalk "Princess : Sakray......",.@princess$;
			set_instance_var("memory_" + .@id,1);
			close2;
			instance_disable("Princess#rms_shard_0");
			break;
			
		case 1:
			.@knight$ = instance_npcname("Magic Swordsman#rms_shard_0");
			.@mage$ = instance_npcname("???#rms_shard_0");
			instance_enable("Magic Swordsman#rms_shard_0",true);
			specialeffect EF_DA_SPACE,AREA,.@knight$;
			mes "[ Magic Sword ]";
			mes "Kekeke, Sakray, why are you here again?";
			npctalk "Magic Sword : Kekeke, Sakray, why are you here again?",.@knight$;
			next;
			mes "[ Magic Swordsman ]";
			mes "I just go where I want to go. Mind your own business.";
			npctalk "Magic Swordsman : I just go where I want to go. Mind your own business.",.@knight$;
			next;
			mes "[ Magic Sword ]";
			mes "Where is the person that said that he wants to get rid of his leftover crumbs of humanity?";
			npctalk "Magic Sword : Where is the person that said that he wants to get rid of his leftover crumbs of humanity?",.@knight$;
			next;
			mes "[ Magic Sword ]";
			mes "In the end, you're still stuck in the past and still returning to the same place.";
			npctalk "Magic Sword : In the end, you're still stuck in the past and still returning to the same place.",.@knight$;
			next;
			mes "[ Magic Swordsman ]";
			mes "Noisy. Don't tell me what to do, Magic Sword.";
			npctalk "Magic Swordsman : Noisy. Don't tell me what to do, Magic Sword.",.@knight$;
			next;
			mes "[ Magic Sword ]";
			mes "Remember, we are in contract.";
			npctalk "Magic Sword : Remember, we are in contract.",.@knight$;
			next;
			mes "[ Magic Sword ]";
			mes "Your soul is mine, until you give me the blood that I want.";
			npctalk "Magic Sword : Your soul is mine, until you give me the blood that I want.",.@knight$;
			next;
			mes "[ Magic Sword ]";
			mes "I don't think you have the time to spend leisurely in a place like this, do you?";
			npctalk "I don't think you have the time to spend leisurely in a place like this, do you?",.@knight$;
			next;
			mes "[ Magic Sword ]";
			mes "I hope that person is ripe enough.";
			npctalk "Magic Sword : I hope that person is ripe enough.",.@knight$;
			next;
			mes "[ Magic Sword ]";
			mes "At the time I wasn't satisfied, I wonder if his blood can satisfy me now?";
			npctalk "Magic Sword : At the time I wasn't satisfied, I wonder if his blood can satisfy me now?",.@knight$;
			next;
			mes "[ Magic Sword ]";
			mes "Tch, I can't stand it anymore. Come on, find that person and give me his blood!";
			npctalk "Magic Sword : Tch, I can't stand it anymore. Come on, find that person and give me his blood!",.@knight$;
			next;
			mes "[ Magic Swordsman ]";
			mes "..... so noisy, I'll get back to it.";
			npctalk "Magic Swordsman : ..... so noisy, I'll get back to it.",.@knight$;
			next;
			instance_disable("Magic Swordsman#rms_shard_0");
			instance_enable("???#rms_shard_0",true);
			specialeffect EF_DA_SPACE,AREA,.@mage$;
			mes "[ ??? ]";
			mes "Hm~ I saw the contractor of the Magic Sword Tartanos and followed him here, why was he interested in this place?";
			next;
			mes "[ ??? ]";
			mes "Hohoho. I can feel the energy of the dead and the tomb.";
			next;
			mes "[ ??? ]";
			mes "To use that energy to make a new Amdarais..... not a good idea.";
			next;
			mes "[ ??? ]";
			mes "But, as the Valkyrie of the Dead, it won't be fun to just leave it there, maybe I should give the dead a present~";
			next;
			mes "[ ??? ]";
			mes "Ha! Now, raise up and fight! Rip each others bodies and plant the seed of poison!";
			next;
			mes "[ ??? ]";
			mes "Too bad, I can't observe the contractor of Tartanos when he returns!";
			set_instance_var("memory_" + .@id,1);
			close2;
			instance_disable("???#rms_shard_0");
			break;
			
		case 2:
			.@princess$ = instance_npcname("Princess#rms_shard_1");
			.@marquis$ = instance_npcname("Marquis#rms_shard_0");
			instance_enable("Princess#rms_shard_1",true);
			instance_enable("Marquis#rms_shard_0",true);
			specialeffect EF_DA_SPACE,AREA,.@princess$;
			specialeffect EF_DA_SPACE,AREA,.@marquis$;
			mes "[ Princess ]";
			mes "......This place, is this the catacombs of the royal palace? My body...... how, ugh. I don't remember......";
			npctalk "......This place, is this the catacombs of the royal palace? My body...... how, ugh. I don't remember......",.@princess$;
			next;
			mes "[ Marquis ]";
			mes "Princess? Oh. You have come back to your senses again.";
			npctalk "Marquis : Princess? Oh. You have come back to your senses again.",.@marquis$;
			next;
			mes "[ Marquis ]";
			mes "Just a little while ago, you were trying to kill me. Princess.";
			npctalk "Marquis : Just a little while ago, you were trying to kill me. Princess.",.@marquis$;
			next;
			mes "[ Princess ]";
			mes "What is happening. Ugh, something is definitely wrong.";
			npctalk "Princess : What is happening. Ugh, something is definitely wrong.",.@princess$;
			next;
			mes "[ Marquis ]";
			mes "Yes. We are all dead. It seems that we are turned into an undead by someone.";
			npctalk "Marquis : Yes. We are all dead. It seems that we are turned into an undead by someone.",.@marquis$;
			next;
			mes "[ Marquis ]";
			mes "Most of the...... No. Princess, you and me aside, everyone has lost their sense of reason and are attacking each other.";
			npctalk "Marquis : Most of the...... No. Princess, you and me aside, everyone has lost their sense of reason and are attacking each other.",.@marquis$;
			next;
			mes "[ Princess ]";
			mes "Why is this happening. We are already dead, and can't even find rest.";
			npctalk "Princess : Why is this happening. We are already dead, and can't even find rest.",.@princess$;
			next;
			mes "[ Marquis ]";
			mes "The same as me. I don't know anything. I think we need to search for answers.";
			npctalk "Marquis : The same as me. I don't know anything. I think we need to search for answers.",.@marquis$;
			next;
			mes "[ Marquis ]";
			mes "You are the only person I have been able to converse to ever since that knight, when the Magic Sword and the Knight carrying it, slaughtered everyone.";
			npctalk "Marquis : You are the only person I have been able to converse to ever since that knight, when the Magic Sword and the Knight carrying it, slaughtered everyone.",.@marquis$;
			next;
			mes "[ Princess ]";
			mes "......Sakray...... It is not his fault.";
			npctalk "Princess : ......Sakray...... It is not his fault.",.@princess$;
			next;
			mes "[ Marquis ]";
			mes "Haha, I think you are joking. ......Well, I understand where you are coming from, princess.";
			npctalk "Marquis : Haha, I think you are joking. ......Well, I understand where you are coming from, princess.",.@marquis$;
			next;
			mes "[ Princess ]";
			mes "Marquis, I am going to ask someone for help.";
			npctalk "Princess : Marquis, I am going to ask someone for help.",.@princess$;
			next;
			mes "[ Princess ]";
			mes "As the princess, we can not let the people here stay like this forever.";
			npctalk "Princess : As the princess, we can not let the people here stay like this forever.",.@princess$;
			next;
			mes "[ Princess ]";
			mes "Even if this happens endlessly....... Then, I will search for help endlessly.";
			npctalk "Princess : Even if this happens endlessly....... Then, I will search for help endlessly.",.@princess$;
			next;
			mes "[ Marquis ]";
			mes "The princess has said the same thing before. It looks like it's going to be an endless search.";
			npctalk "Marquis : The princess has said the same thing before. It looks like it's going to be an endless search.",.@marquis$;
			next;
			mes "[ Princess ]";
			mes "Listen Marquis, If I ever hurt you again, ....... do you understand?";
			npctalk "Princess : Listen Marquis, If I ever hurt you again, ....... do you understand?",.@princess$;
			next;
			mes "[ Marquis ]";
			mes "I will help you find some peace as soon as possible.";
			npctalk "Marquis : I will help you find some peace as soon as possible.",.@marquis$;
			next;
			mes "[ Princess ]";
			mes "Thank you, Marquis.";
			npctalk "Princess : Thank you, Marquis.",.@princess$;		
			set_instance_var("memory_" + .@id,1);
			close2;
			instance_disable("Princess#rms_shard_1");
			instance_disable("Marquis#rms_shard_0");
			break;
	}
	end;
}

1@spa2,224,245,3	duplicate(Memory Piece#rms_0)	Memory Piece#rms_1	CLEAR_NPC
1@spa2,84,52,3	duplicate(Memory Piece#rms_0)	Memory Piece#rms_2	CLEAR_NPC
1@spa2,27,225,1	duplicate(dummynpc2)	Princess#rms_shard_0	4_F_MAYSEL
1@spa2,25,222,7	duplicate(dummynpc2)	Knight#rms_shard_0	4_M_SAKRAYROYAL
1@spa2,221,235,1	duplicate(dummynpc2)	Magic Swordsman#rms_shard_0	4_M_SAKRAY
1@spa2,225,233,1	duplicate(dummynpc2)	???#rms_shard_0	4_F_HIMEL
1@spa2,80,57,6	duplicate(dummynpc2)	Princess#rms_shard_1	20893
1@spa2,85,57,2	duplicate(dummynpc2)	Marquis#rms_shard_0	20899

1@spa2,75,211,3	script	Past Fragment#rms_0	CLEAR_NPC,{
	.@id = atoi(replacestr(strnpcinfo(2),"rms_",""));
	.@qid = 16473 + .@id;
	mes "[ ??? ]";
	if(isbegin_quest(16471)){
		switch(.@id){
			case 0: .@order$ = "3rd"; break;
			case 1: .@order$ = "1st"; break;
			case 2: .@order$ = "6th"; break;
			case 3: .@order$ = "4th"; break;
			case 4: .@order$ = "8th"; break;
			case 5: .@order$ = "5th"; break;
			case 6: .@order$ = "2nd"; break;
			case 7: .@order$ = "7th"; break;
			case 8: .@order$ = "9th"; break;
			case 9: .@order$ = "10th"; break;
		}	
		mes "I found the " + .@order$ + " fragment of the past.";
	}
	switch(.@id){
		case 0:
			.@memory$ = "A happy moment between a princess and a knight.";
			break;
		case 1:
			.@memory$ = "Memory of the time when the knight was raising his successors.";
			break;
		case 2:
			.@memory$ = "A princess in tears who was proposed to by a prince of a neighboring country.";
			break;
		case 3:
			.@memory$ = "The anger of the knight who witnessed the prince of the neighboring country's plot.";
			break;
		case 4:
			.@memory$ = "A knight biting his lips in anger while grasping the princess in his arms.";
			break;
		case 5:
			.@memory$ = "The knight with hollow eyes, framed and locked up.";
			break;
		case 6:
			.@memory$ = "Give me strength, answered by the knight with a weakened heart from the temptation of the magic sword.";
			break;
		case 7:
			.@memory$ = "The faint smile of the late knight, and the captured princess.";
			break;
		case 8:
			.@memory$ = "The princess saying her final words, I love you.";
			break;
		case 9:
			.@memory$ = "Everything was in ruin. Everyone has arised from their slumber.";
			break;
	}
	mes "This is the memory of the royal palace. " + .@memory$;
	if(isbegin_quest(16471) && !isbegin_quest(.@qid)){
		setquest .@qid;
		completequest .@qid;
	}
	close2;
	cloaknpc(instance_npcname(strnpcinfo(0)),true,getcharid(0));
	end;
}

1@spa2,25,207,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_1	CLEAR_NPC
1@spa2,82,256,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_2	CLEAR_NPC
1@spa2,215,245,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_3	CLEAR_NPC
1@spa2,230,252,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_4	CLEAR_NPC
1@spa2,201,254,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_5	CLEAR_NPC
1@spa2,82,29,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_6	CLEAR_NPC
1@spa2,26,63,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_7	CLEAR_NPC
1@spa2,64,61,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_8	CLEAR_NPC
1@spa2,203,77,3	duplicate(Past Fragment#rms_0)	Past Fragment#rms_9	CLEAR_NPC

1@spa2,1,1,0	script	#rms_mob	-1,{
	end;

//= Floor 1 Summons	
OnSummon_F1:
	.@map$ = get_instance_var("map$");
	setarray .@mob$,
	//Bottom Left
	30,206,20895,"OnKillF1_1",
	29,206,20895,"OnKillF1_1",
	29,206,20895,"OnKillF1_1",
	26,204,20895,"OnKillF1_1",
	22,205,20896,"OnKillF1_1",
	//Bottom Mid
	48,215,20899,"OnKillF1_2",
	50,216,20900,"OnKillF1_2",
	50,217,20900,"OnKillF1_2",
	51,217,20900,"OnKillF1_2",
	50,218,20900,"OnKillF1_2",
	//Center Mid
	52,237,20900,"OnKillF1_3",
	54,238,20900,"OnKillF1_3",
	50,238,20900,"OnKillF1_3",
	54,239,20900,"OnKillF1_3",
	52,244,20899,"OnKillF1_3",
	//Center Right
	76,226,20895,"OnKillF1_4",
	77,226,20895,"OnKillF1_4",
	79,225,20895,"OnKillF1_4",
	82,236,20898,"OnKillF1_4",
	83,232,20898,"OnKillF1_4",
	//Top Left
	32,249,20895,"OnKillF1_5",
	32,249,20895,"OnKillF1_5",
	32,251,20895,"OnKillF1_5",
	23,250,20898,"OnKillF1_5",
	21,248,20898,"OnKillF1_5";
	for(.@i = 0; .@i < getarraysize(.@mob$); .@i += 4)
		monster .@map$,atoi(.@mob$[.@i]),atoi(.@mob$[.@i+1]),"--ja--",atoi(.@mob$[.@i+2]),1,instance_npcname(strnpcinfo(0)) + "::" + .@mob$[.@i+3];
end;

OnCheck_F1:
	set_instance_var("floor_1",get_instance_var("floor_1") + 1);
	if(get_instance_var("floor_1") == 5){
		mapannounce get_instance_var("map$"),"Marquis of Remorse : A flow of mana toward the princess has been appeared at 12 o'clock.",bc_map,0x00FFFF;
		instance_enable("#rms_warp_0",true);
	}
end;

OnMobKill_F1:
	.@id = getarg(0);
	.@map$ = get_instance_var("map$");
	if(mobcount(.@map$,instance_npcname(strnpcinfo(0)) + "::OnKillF1_" + .@id)) end;
	if(get_instance_var("F1_" + .@id))
		instance_event(strnpcinfo(0),"OnCheck_F1",false);
	else {
		set_instance_var("F1_" + .@id,1);
		switch(.@id){
			case 1: setarray .@mob,30,205,20895,28,204,20895,28,206,20895,19,206,20896,22,208,20896; break;
			case 2: setarray .@mob,49,218,20900,51,220,20900,49,218,20900,51,218,20899,51,216,20899; break;
			case 3: setarray .@mob,54,243,20900,54,243,20900,55,244,20900,50,239,20899,54,240,20899; break;
			case 4: setarray .@mob,82,224,20898,82,226,20898,82,222,20898,70,230,20895,72,228,20895; break;
			case 5: setarray .@mob,20,249,20898,23,249,20898,22,248,20898,31,249,20895,33,249,20895; break;
		}
		for(.@i = 0; .@i < getarraysize(.@mob); .@i += 3)
			monster .@map$,.@mob[.@i],.@mob[.@i+1],"--ja--",.@mob[.@i+2],1,instance_npcname(strnpcinfo(0)) + "::" + "OnKillF1_" + .@id;
	}
end;

OnKillF1_1: callsub OnMobKill_F1,1;
OnKillF1_2: callsub OnMobKill_F1,2;
OnKillF1_3: callsub OnMobKill_F1,3;
OnKillF1_4: callsub OnMobKill_F1,4;
OnKillF1_5: callsub OnMobKill_F1,5;

//= Floor 2 Summons	
OnSummon_F2:
	.@map$ = get_instance_var("map$");
	setarray .@mob$,
	//Mid
	214,215,20897,"OnKillF2_1",
	216,216,20897,"OnKillF2_1",
	216,218,20898,"OnKillF2_1",
	216,220,20898,"OnKillF2_1",
	218,221,20898,"OnKillF2_1",
	//Left
	205,217,20896,"OnKillF2_2",
	202,218,20896,"OnKillF2_2",
	204,221,20896,"OnKillF2_2",
	205,221,20894,"OnKillF2_2",
	206,221,20894,"OnKillF2_2",
	//Right
	231,222,20896,"OnKillF2_3",
	227,221,20896,"OnKillF2_3",
	229,222,20896,"OnKillF2_3",
	229,218,20898,"OnKillF2_3",
	231,219,20898,"OnKillF2_3";
	for(.@i = 0; .@i < getarraysize(.@mob$); .@i += 4)
		monster .@map$,atoi(.@mob$[.@i]),atoi(.@mob$[.@i+1]),"--ja--",atoi(.@mob$[.@i+2]),1,instance_npcname(strnpcinfo(0)) + "::" + .@mob$[.@i+3];
end;

OnCheck_F2:
	set_instance_var("floor_2",get_instance_var("floor_2") + 1);
	if(get_instance_var("floor_2") == 3){
		mapannounce get_instance_var("map$"),"Marquis of Remorse : Please take care of the princess.",bc_map,0x00FFFF;
		sleep 2000;
		monster get_instance_var("map$"),215,232,"--ja--",20893,1,instance_npcname("#rms_boss") + "::OnTiaraDead";
	}
end;

OnMobKill_F2:
	.@id = getarg(0);
	.@map$ = get_instance_var("map$");
	if(mobcount(.@map$,instance_npcname(strnpcinfo(0)) + "::OnKillF2_" + .@id)) end;
	if(get_instance_var("F2_" + .@id))
		instance_event(strnpcinfo(0),"OnCheck_F2",false);
	else {
		set_instance_var("F2_" + .@id,1);
		switch(.@id){
			case 1: setarray .@mob,218,221,20898,214,220,20898,216,222,20898,215,214,20897,216,214,20897; break;
			case 2: setarray .@mob,204,218,20896,202,217,20896,204,221,20896,205,221,20894,206,221,20894; break;
			case 3: setarray .@mob,228,218,20898,213,217,20898,229,220,20898,229,220,20896,231,221,20896; break;
		}
		for(.@i = 0; .@i < getarraysize(.@mob); .@i += 3)
			monster .@map$,.@mob[.@i],.@mob[.@i+1],"--ja--",.@mob[.@i+2],1,instance_npcname(strnpcinfo(0)) + "::" + "OnKillF2_" + .@id;
	}
end;

OnKillF2_1: callsub OnMobKill_F2,1;
OnKillF2_2: callsub OnMobKill_F2,2;
OnKillF2_3: callsub OnMobKill_F2,3;

//= Floor 3 Summon
OnSummon_F3:
	.@map$ = get_instance_var("map$");
	setarray .@mob$,
	//Bottom Center
	61,28,20894,"OnKillF3_1",
	61,31,20894,"OnKillF3_1",
	59,29,20894,"OnKillF3_1",
	54,29,20897,"OnKillF3_1",
	54,30,20897,"OnKillF3_1",
	//Bottom Left
	34,24,20895,"OnKillF3_3",
	34,24,20895,"OnKillF3_3",
	35,26,20895,"OnKillF3_3",
	30,20,20896,"OnKillF3_3",
	28,21,20896,"OnKillF3_3",
	29,31,20898,"OnKillF3_3",
	27,30,20898,"OnKillF3_3",
	//Bottom Right
	80,27,20895,"OnKillF3_2",
	81,28,20895,"OnKillF3_2",
	85,30,20898,"OnKillF3_2",
	87,30,20898,"OnKillF3_2",
	88,20,20896,"OnKillF3_2",
	88,21,20896,"OnKillF3_2",
	//Center
	57,50,20895,"OnKillF3_4",
	57,52,20895,"OnKillF3_4",
	57,54,20895,"OnKillF3_4",
	56,59,20896,"OnKillF3_4",
	58,60,20896,"OnKillF3_4",
	//Center Left
	33,57,20897,"OnKillF3_5",
	34,57,20897,"OnKillF3_5",
	35,50,20896,"OnKillF3_5",
	34,50,20895,"OnKillF3_5",
	32,50,20895,"OnKillF3_5",
	30,49,20895,"OnKillF3_5",
	28,51,20895,"OnKillF3_5",
	//Top Center
	53,75,20894,"OnKillF3_6",
	49,76,20894,"OnKillF3_6",
	52,77,20894,"OnKillF3_6",
	63,76,20897,"OnKillF3_6",
	65,77,20897,"OnKillF3_6";
	for(.@i = 0; .@i < getarraysize(.@mob$); .@i += 4)
		monster .@map$,atoi(.@mob$[.@i]),atoi(.@mob$[.@i+1]),"--ja--",atoi(.@mob$[.@i+2]),1,instance_npcname(strnpcinfo(0)) + "::" + .@mob$[.@i+3];
end;

OnCheck_F3:
	set_instance_var("floor_3",get_instance_var("floor_3") + 1);
	if(get_instance_var("floor_3") == 6){
		mapannounce get_instance_var("map$"),"Marquis of Remorse : A flow of mana has appeared in the center. Someone is waiting in there.",bc_map,0x00FFFF;
		instance_enable("Memory Piece#rms_2",true);
		instance_enable("#rms_warp_2",true);
	}
end;

OnMobKill_F3:
	.@id = getarg(0);
	.@map$ = get_instance_var("map$");
	if(mobcount(.@map$,instance_npcname(strnpcinfo(0)) + "::OnKillF3_" + .@id)) end;
	if(get_instance_var("F3_" + .@id))
		instance_event(strnpcinfo(0),"OnCheck_F3",false);
	else {
		set_instance_var("F3_" + .@id,1);
		switch(.@id){
			case 1: setarray .@mob,61,30,20897,62,29,20897,55,30,20894,52,30,20894,54,28,20894; break;
			case 2: setarray .@mob,87,22,20898,87,24,20898,85,29,20896,85,30,20896,81,28,20895,80,26,20895; break;
			case 3: setarray .@mob,26,30,20896,28,31,20896,28,32,20896,35,27,20895,35,25,20895,29,22,20898,29,24,20898; break;
			case 4: setarray .@mob,56,51,20895,58,51,20895,56,57,20896,57,57,20895,56,59,20895; break;
			case 5: setarray .@mob,31,51,20895,33,50,20895,35,52,20895,36,51,20897,36,52,20897,34,58,20896,35,58,20895,33,59,20895; break;
			case 6: setarray .@mob,64,78,20894,64,75,20894,53,75,20897,50,78,20897,52,78,20897; break;
		}
		for(.@i = 0; .@i < getarraysize(.@mob); .@i += 3)
			monster .@map$,.@mob[.@i],.@mob[.@i+1],"--ja--",.@mob[.@i+2],1,instance_npcname(strnpcinfo(0)) + "::" + "OnKillF3_" + .@id;
	}
end;

OnKillF3_1: callsub OnMobKill_F3,1;
OnKillF3_2: callsub OnMobKill_F3,2;
OnKillF3_3: callsub OnMobKill_F3,3;
OnKillF3_4: callsub OnMobKill_F3,4;
OnKillF3_5: callsub OnMobKill_F3,5;
OnKillF3_6: callsub OnMobKill_F3,6;
}

1@spa2,1,1,0	script	#rms_boss	-1,{
	end;
	
OnTiaraDead:
	mapannounce get_instance_var("map$"),"Marquis of Remorse : If you go to the left side of the throne, there is a secret passage towards the underground tomb.",bc_map,0x00FFFF;
	instance_enable("#rms_warp_1",true);
	instance_enable("Memory Piece#rms_1",true);
end;

OnBossSkill:
	sleep 10000;
	mapannounce get_instance_var("map$"),"Marquis of Remorse : The magic pillars has appeared in the 3 corridors absorbing the attacks being dealt on Sakray.",bc_map,0x00FFFF;
	set_instance_var("pillar",3);
	for(.@i = 0; .@i < 3; .@i++)
		instance_enable("#rms_stone_" + .@i,true);
	monster get_instance_var("map$"),195,61,"",20562,1,instance_npcname(strnpcinfo(0)) + "::OnSkillDead";
	set_instance_var("gid_0",$@mobid[0]);
	monster get_instance_var("map$"),228,61,"",20562,1,instance_npcname(strnpcinfo(0)) + "::OnSkillDead";
	set_instance_var("gid_1",$@mobid[0]);
	monster get_instance_var("map$"),212,78,"",20562,1,instance_npcname(strnpcinfo(0)) + "::OnSkillDead";
	set_instance_var("gid_2",$@mobid[0]);
	for(.@i = 0; .@i < 3; .@i++)
		setunitdata get_instance_var("gid_" + .@i),UMOB_DMGIMMUNE,true;
	instance_event("#rms_boss","OnEnableShield",false);
OnSkillDead:
end;

OnEnableShield:
	.@gid = get_instance_var("boss_gid");
	if(!unitexists(.@gid)) end;
	setunitdata .@gid,UMOB_DMGIMMUNE,true;
end;

OnDisableShield:
	.@gid = get_instance_var("boss_gid");
	if(!unitexists(.@gid)) end;
	setunitdata .@gid,UMOB_DMGIMMUNE,false;
	initnpctimer instance_npcname("#rms_boss");
end;

OnSakrayDead:
	instance_enable("Sakray#rms_0",true);
	stopnpctimer instance_npcname(strnpcinfo(0));
	.@sak$ = instance_npcname("Sakray#rms_0");
	.@map$ = get_instance_var("map$");
	killmonster .@map$,instance_npcname(strnpcinfo(0)) + "::OnSkillDead";
	npctalk "Magic Swordsman Sakray : This place..... I swore I wouldn't come back here anymore......",.@sak$;
	sleep 2000;
	npctalk "Magic Swordsman Sakray : I didn't know it became like this..... I just found out and came running here.",.@sak$;
	sleep 2000;
	npctalk "Magic Swordsman Sakray : If it's not you.... then..... who..... who did this?",.@sak$;
	sleep 2000;
	instance_enable("Sakray#rms_0",false);
	instance_enable("Marquis of Remorse#rms_0",true);
	instance_enable("#rms_warp_3",true);
end;

OnTimer50000:
	stopnpctimer;
	instance_event("#rms_boss","OnBossSkill",false);
end;
}

1@spa2,186,61,3	script	#rms_stone_0	1908,{
	.@id = atoi(replacestr(strnpcinfo(2),"rms_stone_",""));
	progressbar_npc "00FF00",10;
	.@v = get_instance_var("pillar");
	switch(.@v){
		case 3:	.@mes$ = "The first magic pillar has been destroyed."; break;
		case 2: .@mes$ = "The second magic pillar has been destroyed."; break;
		case 1: .@mes$ = "The third magic pillar has been destroyed, the pillars damage absorbtion has now been completely nullified."; break;
	}
	set_instance_var("pillar",.@v - 1);
	if(unitexists(get_instance_var("gid_" + .@id)))
		unitskilluseid get_instance_var("gid_" + .@id),"NPC_EARTHQUAKE",10;
	instance_enable(strnpcinfo(0),false);
	if(!get_instance_var("pillar"))
		instance_event("#rms_boss","OnDisableShield",false);
	end;
}

1@spa2,237,61,3	duplicate(#rms_stone_0)	#rms_stone_1	1908
1@spa2,212,88,3	duplicate(#rms_stone_0)	#rms_stone_2	1908


1@spa2,52,258,0	script	#rms_warp_0	WARPNPC,2,2,{
	end;
	
OnTouch:
	switch(atoi(replacestr(strnpcinfo(2),"rms_warp_",""))){
		case 0: .@x = 215; .@y = 201; break;
		case 1: .@x = 57; .@y = 22; break;
		case 2: .@x = 212; .@y = 54; break;
		case 3:
			if(isbegin_quest(16469) || isbegin_quest(16471)){
				mes "[ Marquis of Remorse ]";
				mes "Wait, don't you have something to settle with me?";
				mes "I'll keep the broken memories and the fragments that you collected, it can't be bring out there, so I'll take it.";
				next;
				if(select("There's nothing left, I'll go out.:I remember it.") == 2){
					mes "[ Marquis of Remorse ]";
					mes "Come and talk to me to settle the deed.";
					close;
				}
				warp "dali02",73,113;
				end;
			}
			if(select("Leave this place.:Stay a bit.") == 2)
				end;
			warp "dali02",73,113;
			end;
	}
	warp get_instance_var("map$"),.@x,.@y;
end;
}

1@spa2,211,253,0	duplicate(#rms_warp_0)	#rms_warp_1	WARPNPC,2,2
1@spa2,58,42,0	duplicate(#rms_warp_0)	#rms_warp_2	WARPNPC,2,2
1@spa2,212,87,0	duplicate(#rms_warp_0)	#rms_warp_3	WARPNPC,2,2

1@spa2,214,64,3	script	Marquis of Remorse#rms_0	20899,{
	mes "[ Marquis of Remorse ]";
	mes "I have been waiting for you as promised.";
	mes "Hero, are you truly a person that we could depend on?";
	next;
	switch(select("Broken threads of fate.:Shedding in tears.:Memory fragments.:Fragments of the past.")){
		case 1:
			.@qid = 16465;
			if(checkquest(.@qid,HUNTING) < 2){
				mes "[ Marquis of Remorse ]";
				mes "I don't think there's any light or grace to clear up about the Magic Swordsman.";
				mes "Please take good care of the princess.";
			} else {
				mes "[ Marquis of Remorse ]";
				mes "The princess may be sad.";
				mes "However, now that her relationship has been lost and erased, there will be nothing left.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "There wouldn't have been a place for him on this world in the first place.";
				mes "Thank you for keeping him out of here.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "Unless we deal with the source, the poor people here in the tomb will continue rising again and again.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "It's a small reward, but it's all that I can give you right now. It's a decision of that the princess of remorse has made.";
				erasequest .@qid;
				getitem 1000367,10;
			}
			close;
		
		case 2:
			.@qid = 16467;
			if(checkquest(.@qid,HUNTING) < 2){
				mes "[ Marquis of Remorse ]";
				mes "I don't think there's any light or grace to clear up about the Princess.";
			} else {
				mes "[ Marquis of Remorse ]";
				mes "You have succesfully gave the princess her rest.";
				mes "Ho, aren't you glad to be an adventurer? It's suppose to be the prince's job to do that.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "I'm just joking, you were truly a hero to the princess.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "Unless we deal with the source, the poor people here in the tomb will continue rising again and again.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "It's a small reward, but it's all that I can give you right now. It's a decision of that the princess of remorse has made.";
				erasequest .@qid;
				getitem 1000367,8;
			}
			close;
		
		case 3:
			.@qid = 16469;
			if(isbegin_quest(.@qid) == 0){
				mes "[ Marquis of Remorse ]";
				mes "Unless we deal with the source, the poor people here in the tomb will continue rising again and again.";
				close;
			} else {
				if(!get_instance_var("memory_0") || !get_instance_var("memory_1") || !get_instance_var("memory_2")){
					mes "[ Marquis of Remorse ]";
					mes "Hero, I appreciate the thought.";
					mes "But I think you have missed a memory piece somewhere in the place.";
					next;
					mes "[ Marquis of Remorse ]";
					mes "We might be able to get it next time we come back here.";
					next;
					mes "[ Marquis of Remorse ]";
					mes "Afterall, Unless we deal with the source, the poor people here in the tomb will continue rising again and again.";
				} else {
					mes "[ Marquis of Remorse ]";
					mes "...these memory pieces can't be taken out of this place.";
					mes "I don't know the reason why.";
					next;
					mes "[ Marquis of Remorse ]";
					mes "When I try to bring it out, it starts to melt like glass, leaving no trace left, so I'll keep it in this place for now.";
					next;
					mes "[ Marquis of Remorse ]";
					mes "It's a small reward, but it's all that I can give you right now. It's a decision of that the princess of remorse has made.";
					erasequest .@qid;
					getitem 1000367,1;
				}
			}
			close;	
		
		case 4:
			.@qid = 16471;
			if(isbegin_quest(.@qid) == 0){
				mes "[ Marquis of Remorse ]";
				mes "Unless we deal with the source, the poor people here in the tomb will continue rising again and again.";
				close;
			} else {
				for(.@i = 16473; .@i < 16483; .@i++){
					if(!isbegin_quest(.@i)){
						mes "[ Marquis of Remorse ]";
						mes "Hero, I appreciate the thought.";
						mes "But I think you have missed a memory of the past somewhere in the place.";
						next;
						mes "[ Marquis of Remorse ]";
						mes "We might be able to get it next time we come back here.";
						next;
						mes "[ Marquis of Remorse ]";
						mes "Afterall, Unless we deal with the source, the poor people here in the tomb will continue rising again and again.";
						close;
					}
				}
				mes "[ Marquis of Remorse ]";
				mes "...these memory of the past can't be taken out of this place.";
				mes "I don't know the reason why.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "It's a story about an old relationship, memories, and turning to nothing, it's very sad to witness it again.";
				mes "But I want to collect these fragments so that this place will not be forgotten.";
				next;
				mes "[ Marquis of Remorse ]";
				mes "It's a small reward, but it's all that I can give you right now. It's a decision of that the princess of remorse has made.";
				erasequest .@qid;
				for(.@i = 16473; .@i < 16483; .@i++)
					erasequest .@i;
				getitem 1000367,1;
			}
			close;
	}
	end;
}
