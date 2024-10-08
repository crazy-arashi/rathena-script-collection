//===== rAthena Script =======================================
//= Old Glast Heim
//===== Description: =========================================
//= Discover the history of events that took place in the
//= Glast Heim castle and how it ended up in ruins.
//===== Changelogs: =================================
//= 1.0 First version. [Euphy, Ziu, Heris]
//=     This is a custom version, and may contain bugs.
//= 1.1 Bug fixes; removed redundant OnInstanceInit scripts.
//= 1.2 Add NPC Hugin's Follower [exneval]
//=     NPC that give access to Glast Heim Nightmare Mode.
//= 1.3 Add some NPCs placeholder. [exneval]
//= 1.4 Update to its official text. [exneval]
//=     Support merchant, enchant, socket features.
//= 1.5 idAthena merge. Removed Hugin's Follower NPCs. [Secretdataz]
//=     Changed `set` calls to direct assignments.
//=     Cleaned up the script.
//=     TODO: Confirm Hugin NPC's code flow.
//= 1.6 Cleaned up the dialogue. [Aleos]
//= 1.7 Added Hard Mode/Portal Cleanup/New Enchanter [crazyarashi services]
//============================================================

glast_01,204,273,5	script	Hugin#ogh	4_M_SAGE_C,{
	if(BaseLevel < 130){
		mes "[Hugin]";
		mes "Why don't you come back after becoming stronger?";
		mes "Maybe, level 130.";
		close;
	}
	if(isbegin_quest(12316) == 0){
		mes "[Hugin]";
		mes "A long time ago, this castle did not look like this.";
		next;
		mes "[Hugin]";
		mes "Ah, I'm sorry. I'm muttering in front of a stranger.";
		next;
		mes "[Hugin]";
		mes "My name is Hugin. I'm studying the dimensional gap between time and space.";
		next;
		select("There's something like that here?");
		mes "[Hugin]";
		mes "Have you ever wondered about the history of Glast Heim?";
		next;
		mes "[Hugin]";
		mes "There was a King named Shumiche who was known as a tyrant in the history of the Rune-Midgarts Kingdom.";
		next;
		mes "[Hugin]";
		mes "Time will reveal the true answers if we look in the right places.";
		next;
		if (select("I don't care about history","That is interesting. Did you find anything?") == 1) {
			mes "[Hugin]";
			mes "Really? Hmm, please come back later when you are interested then.";
			close;
		}
		mes "[Hugin]";
		mes "Actually, dimensional time travel is possible but I'm too afraid to go there.";
		next;
		mes "[Hugin]";
		mes "It might be possible for you!";
		next;
		mes "[Hugin]";
		mes "Do you want to time travel?";
		next;
		if (select("No, thanks.","Yes, of course I do!") == 1) {
			mes "[Hugin]";
			mes "Really? But, jumping gigawatts, this is such a great opportunity.";
			close;
		}
		mes "[Hugin]";
		mes "I knew that you would understand what I said. Well, please tell me what you want to do.";
		setquest 12316;
		completequest 12316;		
	} else {
		mes "[Hugin]";
		mes "Umm? Did you see me at another place? I don't think so. What about this time?";
		if (isbegin_quest(12322) == 1)
			erasequest 12322;
	}
	next;
	.@cooldown = 12317;
	.@root_hunt = 12318;
	.@md_name$ = "Old Glast Heim";
	switch(checkquest(.@cooldown,PLAYTIME)){
		case -1:
			break;
			
		case 0:
		case 1:
			mes "[Hugin]";
			mes "Oh, my...";
			mes "You still have after-effects of time travel. You can't travel again with this condition.";
			next;
			mes "[Hugin]";
			mes "Staying healthy is important, so please take a break and come back again later.";
			close;
			
		case 2:
			mes "^0000CDAll traces of access to Old Glast Heim have been removed. Now you can talk with Hugin again.^000000";
			if(isbegin_quest(.@root_hunt) > 0)
				erasequest .@root_hunt;
			erasequest .@cooldown	;
			close;			
	}
	.@party_id = getcharid(1);
	.@party_name$ = getpartyname(.@party_id);	
	if(!.@party_id){
		mes "[Hugin]";
		mes "Why don't you make a party with more than 1 person and talk to me again?";
		close;
	}
	mes "[Hugin]";
	mes "Have we met before? No way. It's my first time seeing you. What do you want?";
	next;
	switch(select((is_party_leader() && !instance_id(IM_PARTY)?"Create " + .@md_name$:""),(!instance_id(IM_PARTY) ? "":"Enter." + .@md_name$),"Cancel")){
		case 1:
			switch(instance_create(.@md_name$)){
				case -3:
					dispbottom "Memorial Dungeon, '" + .@md_name$ + "' is already in progress.",0xFF0000;
					end;
					
				case -4:
				case -2:
				case -1:
					mes "Party Name: " + getpartyname( getcharid(1) );
					mes "Party Leader: " + strcharinfo(0);
					mes "^0000ff" + .@md_name$ + "^000000 - time gap generation failed.";
					end;
			}
			mes "[Hugin]";
			mes "After the time gap opens, please tell me again.";
			end;
			
		case 2:
			switch(instance_enter(.@md_name$)){
				case IE_OTHER:
					mes "[Hugin]";
					mes "An unknown error has occurred.";
					close;
				case IE_NOINSTANCE:
					mes "[Hugin]";
					mes "The time gap is not yet open.";
					close;
				case IE_NOMEMBER:
					mes "[Hugin]";
					mes "Your body is not fit to enter the time gap. You won't be able to get in if you're not in a party.";
					close;
				case IE_OK:
					mapannounce "glast_01", "" + getpartyname( getcharid(1) ) + " party member " + strcharinfo(0) + " enters the " + .@md_name$ + ".", bc_map,0x00FF99;
					if(isbegin_quest(.@root_hunt) == 0)
						setquest .@root_hunt;
					setquest .@cooldown;
					end;
			}
			end;
			
		case 3:
			end;
	}
}

glast_01,179,283,5	script	Another Hugin#ogh_hard	4_M_SAGE_C,{
	instance_warning();
	next;
	if(BaseLevel < 160){
		mes "[ Another Hugin ]";
		mes "Why don't you come back after becoming stronger?";
		mes "Maybe, level 160.";
		close;
	}
	if(isbegin_quest(12321) != 2){
		mes "[ Another Hugin ]";
		mes "...";
		next;
		mes "^0000CDThis man looks exactly like Hugin. But he doesn't seem to be any interest in you.^000000";
		end;
	}
	next;
	.@cooldown = 12334;
	.@root_hunt = 12336;
	.@md_name$ = "Old Glast Heim Hard";
	switch(checkquest(.@cooldown,PLAYTIME)){
		case -1:
			break;
			
		case 0:
		case 1:
			mes "[ Another Hugin ]";
			mes "Oh, my...";
			mes "You still have after-effects of time travel. You can't travel again with this condition.";
			next;
			mes "[ Another Hugin ]";
			mes "Staying healthy is important, so please take a break and come back again later.";
			close;
			
		case 2:
			mes "^0000CDAll traces of access to Old Glast Heim have been removed. Now you can talk with Hugin again.^000000";
			if(isbegin_quest(.@root_hunt) > 0)
				erasequest .@root_hunt;
			if(isbegin_quest(12335) > 0)
				erasequest 12335;
			erasequest .@cooldown;
			close;			
	}
	.@party_id = getcharid(1);
	.@party_name$ = getpartyname(.@party_id);	
	if(!.@party_id){
		mes "[ Another Hugin ]";
		mes "Why don't you make a party with more than 1 person and talk to me again?";
		close;
	}
	mes "[ Another Hugin ]";
	mes "What you're seeing is me from another dimension. I'm going to remind you that it's going to be dangerous. Are you ready?";
	next;
	switch(select((is_party_leader() && !instance_id(IM_PARTY)?"Create " + .@md_name$:""),(!instance_id(IM_PARTY) ? "":"Enter." + .@md_name$),"Cancel")){
		case 1:
			switch(instance_create(.@md_name$)){
				case -3:
					dispbottom "Memorial Dungeon, '" + .@md_name$ + "' is already in progress.",0xFF0000;
					end;
					
				case -4:
				case -2:
				case -1:
					mes "Party Name: " + getpartyname( getcharid(1) );
					mes "Party Leader: " + strcharinfo(0);
					mes "^0000ff" + .@md_name$ + "^000000 - time gap generation failed.";
					end;
			}
			mes "[ Another Hugin ]";
			mes "After the time gap opens, take a quick breath and talk to me again.";
			end;
			
		case 2:
			switch(instance_enter(.@md_name$)){
				case IE_OTHER:
					mes "[ Another Hugin ]";
					mes "An unknown error has occurred.";
					close;
				case IE_NOINSTANCE:
					mes "[ Another Hugin ]";
					mes "The time gap is not yet open.";
					close;
				case IE_NOMEMBER:
					mes "[ Another Hugin ]";
					mes "Your body is not fit to enter the time gap. You won't be able to get in if you're not in a party.";
					close;
				case IE_OK:
					mapannounce "glast_01", "" + getpartyname( getcharid(1) ) + " party member " + strcharinfo(0) + " enters the " + .@md_name$ + ".", bc_map,0x00FF99;
					if(isbegin_quest(.@root_hunt) == 0)
						setquest .@root_hunt;
					setquest .@cooldown;
					end;
			}
			end;
			
		case 3:
			end;
	}
}

// Warps
1@gl_k,96,80,0	warp	#2Control	2,2,1@gl_k,80,80
1@gl_k,90,80,0	warp	#2Control2	2,2,1@gl_k,105,80
1@gl_k,202,79,0	warp	#3Control	2,2,1@gl_k,215,79
1@gl_k,206,79,0	warp	#3Control2	2,2,1@gl_k,195,79
1@gl_k,227,216,0	warp	#4Control	2,2,1@gl_k,215,216
1@gl_k,222,216,0	warp	#4Control2	2,2,1@gl_k,233,216
1@gl_k,150,284,0	warp	#2F Entrance	2,2,2@gl_k,150,46
2@gl_k,149,32,0	warp	#1 Control	2,2,1@gl_k,150,270
2@gl_k,145,123,0	warp	#22 Control	2,2,2@gl_k,126,123
2@gl_k,136,122,0	warp	#22 Control2	2,2,2@gl_k,150,116
2@gl_k,154,101,0	warp	#23 Control	2,2,2@gl_k,174,101
2@gl_k,165,101,0	warp	#23 Control2	2,2,2@gl_k,150,111
2@gl_k,150,163,0	warp	#24 Control	2,2,2@gl_k,150,179
2@gl_k,150,167,0	warp	#24 Control2	2,2,2@gl_k,150,149
1@gl_k,69,168,0	warp	#Secret Room Exit	2,2,1@gl_k,48,168

// Floor 1
//============================================================
1@gl_k,149,41,5	script	Varmundt#0	4_M_BARMUND,{
	if (is_party_leader() == false) {
		mes "[Varmundt]";
		mes "Where's your leader? I need his help.";
		cutin "gl_barmund2",2;
		close3;
	}
	'party_id = getcharid(1);
	.@account_id = getcharid(3);
	.@player_name$ = strcharinfo(0);
	mes "[Varmundt]";
	mes "Are you the one ^0000ffHerico^000000 sent to help me?";
	npctalk "Varmundt: Are you the one Herico sent to help me?";
	cutin "gl_barmund1",2;
	next;
	select("Oh. Well I...");
	mes "[" + .@player_name$ + "]";
	mes "Ah yes, I am. Herico told me to meet you.";
	unittalk .@account_id, .@player_name$ + " : Ah yes, I am. Herico told me to meet you.";
	next;
	mes "[Varmundt]";
	mes "We don't have much time. We must report to Sir Heinrich about Himelmez's invasion.";
	npctalk "Varmundt: We don't have much time. We must report to Sir Heinrich about Himelmez's invasion.";
	cutin "gl_barmund2",2;
	next;
	select("Himelmez...");
	mes "[" + .@player_name$ + "]";
	mes "Who is Himelmez?";
	unittalk .@account_id, .@player_name$ + " : Who is Himelmez?";
	next;
	mes "[Varmundt]";
	mes "Herico didn't tell you?";
	npctalk "Varmundt: Herico didn't tell you?";
	cutin "gl_barmund3",2;
	next;
	mes "[Varmundt]";
	mes "She is the Ruler of Death, Dead man's Valkyrie. Himelmez is looking to take the heart of Ymir from us.";
	npctalk "Varmundt: She is the Ruler of Death, Dead man's Valkyrie. Himelmez is looking to take the heart of Ymir from us.";
	cutin "gl_barmund2",2;
	next;
	mes "[Varmundt]";
	mes "She might even destroy this whole castle if she wanted to.";
	npctalk "Varmundt: She might even destroy this whole castle if she wanted to.";
	next;
	mes "[Varmundt]";
	mes "Hurry! Report to Sir. Heinrich about Himelmez. I must check the defense barrier here!";
	npctalk "Varmundt: Hurry! Report to Sir. Heinrich about Himelmez. I must check the defense barrier here!";
	close2;
	cutin "",255;
	disablenpc instance_npcname("Varmundt#0");
	enablenpc instance_npcname("Heinrich#1");
	enablenpc instance_npcname("Varmundt#1");
	end;
}

1@gl_k,145,104,6	script	Khalitzburg Knightage#1	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "My work shift will be over soon, but the next crew is not coming.";
	close;
}

1@gl_k,154,104,3	script	Khalitzburg Knightage#2	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "Something you want to tell me?";
	close;
}

1@gl_k,145,99,6	script	White Knight#3	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "Are you with Varmundt? Commander is waiting for you.";
	close;
}

1@gl_k,154,99,3	duplicate(Khalitzburg Knightage#1)	White Knight#4	4_WHITEKNIGHT

1@gl_k,145,94,6	script	Khalitzburg Knightage#5	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "I had a weird dream last night. My mom was in it... Wonder if she is ok...";
	close;
}

1@gl_k,154,94,3	duplicate(White Knight#3)	Khalitzburg Knightage#6	4_F_KHALITZBURG

1@gl_k,145,89,6	script	White Knight#7	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "Please do not make a mess here.";
	close;
}
1@gl_k,154,89,3	duplicate(White Knight#7)	White Knight#8	4_WHITEKNIGHT

1@gl_k,145,84,6	script	Khalitzburg Knightage#9	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "Orders please.";
	close;
}
1@gl_k,154,84,3	duplicate(Khalitzburg Knightage#9)	Khalitzburg Knightage#10	4_F_KHALITZBURG

1@gl_k,145,79,6	script	White Knight#11	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "How do you know Varmundt? I heard that he's not really a friendly man...";
	close;
}
1@gl_k,154,79,3	duplicate(White Knight#11)	White Knight#12	4_WHITEKNIGHT

1@gl_k,145,74,6	script	Khalitzburg Knightage#13	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "Doesn't this castle seem weird all of a sudden? Something's not quite right.";
	close;
}
1@gl_k,154,74,3	duplicate(Khalitzburg Knightage#13)	Khalitzburg Knightage#14	4_F_KHALITZBURG

1@gl_k,145,69,6	script	White Knight#15	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "I do not like to chat during work.";
	close;
}
1@gl_k,154,69,3	duplicate(White Knight#15)	White Knight#16	4_WHITEKNIGHT

1@gl_k,145,64,6	script	Khalitzburg Knightage#17	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "...";
	close;
}
1@gl_k,154,64,3	duplicate(Khalitzburg Knightage#17)	Khalitzburg Knightage#18	4_F_KHALITZBURG

1@gl_k,145,59,6	script	White Knight#19	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "What can I do for you?";
	close;
}
1@gl_k,154,59,3	duplicate(White Knight#19)	White Knight#20	4_WHITEKNIGHT

1@gl_k,145,54,6	script	Khalitzburg Knightage#21	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "Is there something you need?";
	close;
}
1@gl_k,154,54,3	duplicate(Khalitzburg Knightage#21)	Khalitzburg Knightage#22	4_F_KHALITZBURG

1@gl_k,149,100,6	script	Heinrich#1	4_M_HEINRICH,{
	if (is_party_leader() == false) {
		mes "[Heinrich]";
		mes "Where is your leader? I must talk to him.";
		cutin "gl_heinrich2",2;
		close3;
	}
	.@account_id = getcharid(3);
	.@player_name$ = strcharinfo(0);
	cutin "gl_heinrich2",2;
	select("Sir Heinrich. Varmundt...");
	mes "[" + .@player_name$ + "]";
	mes "Sir Heinrich. Do you know what is happening in the castle now?";
	unittalk .@account_id, .@player_name$ + " : Sir Heinrich. Do you know what is happening in the castle now?";
	next;
	mes "[Heinrich]";
	mes "Aren't you the adventurer that came along with Varmundt?";
	npctalk "Heinrich: Aren't you the adventurer that came along with Varmundt?";
	next;
	mes "[Heinrich]";
	mes "What is it? Something wrong with the castle?";
	npctalk "Heinrich: What is it? Something wrong with the castle?";
	next;
	select("Himelmez's invasion...");
	mes "[" + .@player_name$ + "]";
	mes "Dead man's Valkyrie, Himelmez is coming to take the Ymir's Heart piece hidden inside this castle!";
	unittalk .@account_id, .@player_name$ + " : Dead man's Valkyrie, Himelmez is coming to take the Ymir's Heart piece hidden inside this castle!";
	next;
	mes "[Heinrich]";
	mes "Haha. Funny. Do you really think that is possible?";
	npctalk "Heinrich: Haha. Funny. Do you really think that is possible?";
	cutin "gl_heinrich1",2;
	next;
	mes "[Varmundt]";
	mes "I'm not kidding, Sir Heinrich. If I'm correct, then she will be here very soon.";
	npctalk "Varmundt: I'm not kidding, Sir Heinrich. If I'm correct, then she will be here very soon.", instance_npcname("Varmundt#1");
	cutin "gl_barmund2",2;
	next;
	mes "[Varmundt]";
	mes "We must hide the heart piece in a safe place before Himelmez's attack starts!";
	npctalk "Varmundt: We must hide the heart piece in a safe place before Himelmez's attack starts!", instance_npcname("Varmundt#1");
	next;
	select("Even if you don't believe me...");
	mes "[" + .@player_name$ + "]";
	mes "I can't make you believe me, but there's no time to argue!";
	unittalk .@account_id, .@player_name$ + " : I can't make you believe me, but there's no time to argue!";
	cutin "",255;
	next;
	mes "[Heinrich]";
	mes "Thank you for the help. But we don't even have our king with us right now.";
	npctalk "Heinrich: Thank you for the help. But we don't even have our king with us right now.";
	cutin "gl_heinrich1",2;
	next;
	mes "[Heinrich]";
	mes "We cannot risk moving the heart just because some stranger says so.";
	npctalk "Heinrich: We cannot risk moving the heart just because some stranger says so.";
	close2;
	disablenpc instance_npcname("Heinrich#1");
	enablenpc instance_npcname("Heinrich#2");
	enablenpc instance_npcname("Himelmez#1");
	donpcevent instance_npcname("#talkinstance1") + "::OnEnable";
	cutin "",255;
	end;
}

1@gl_k,152,97,3	script	Varmundt#1	4_M_BARMUND,{ end; }
1@gl_k,149,97,5	duplicate(Varmundt#1)	Heinrich#2	4_M_HEINRICH
1@gl_k,149,100,5	duplicate(Varmundt#1)	Heinrich#3	4_M_HEINRICH
1@gl_k,149,89,1	duplicate(Varmundt#1)	Himelmez#1	4_F_HIMEL

// Control Timer
//============================================================
1@gl_k,1,1,0	script	#talkinstance1	HIDDEN_WARP_NPC,{
	end;
OnEnable:
	mapannounce 'map_name$[0], "????'s: Muahahahaha~!", bc_map,0xFFFF00,FW_NORMAL,18;
	initnpctimer;
	'npc_himelmez1$ = instance_npcname("Himelmez#1");
	'npc_varmundt1$ = instance_npcname("Varmundt#1");
	'npc_heinrich2$ = instance_npcname("Heinrich#2");
	'npc_heinrich3$ = instance_npcname("Heinrich#3");
	end;
OnTimer1500:
	npctalk "Heinrich: Who are you?", 'npc_heinrich2$;
	end;
OnTimer4500:
	npctalk "Himelmez: Well well~ Am I interrupting you? Weren't you expecting me?", 'npc_himelmez1$;
	end;
OnTimer10000:
	npctalk "Varmundt: Himelmez!! Already!", 'npc_varmundt1$;
	end;
OnTimer17500:
	npctalk "Himelmez: My name is Lisa Kahn Himelmez. Master of Dullahan, Dead man's Valkyrie, that's what they call me.", 'npc_himelmez1$;
	end;
OnTimer22000:
	npctalk "Heinrich: Aren't you a little too feminine to be the Ruler of death? We are not afraid of you...", 'npc_heinrich2$;
	end;
OnTimer28500:
	npctalk "Himelmez: Let's see if you can relax like that after you find out where your king is.", 'npc_himelmez1$;
	end;
OnTimer36000:
	npctalk "Heinrich: What?", 'npc_heinrich2$;
	end;
OnTimer41000:
	npctalk "Himelmez: Hmm, now I have your attention do I not?", 'npc_himelmez1$;
	end;
OnTimer47000:
	npctalk "Himelmez: You don't want the king's position, just wait for him to come back. I like your purity.", 'npc_himelmez1$;
	end;
OnTimer54000:
	npctalk "Himelmez: It's a pity to meet you in a situation like this.", 'npc_himelmez1$;
	end;
OnTimer59000:
	npctalk "Heinrich: My king is visiting the Rune-Midgarts royal family. He's not back yet.", 'npc_heinrich2$;
	end;
OnTimer66500:
	npctalk "Heinrich: And now you are trying to trick me, what has happened to him?!", 'npc_heinrich2$;
	end;
OnTimer71500:
	npctalk "Himelmez: Well~ I would love to sit down and explain for you, but I'm kind of busy today~", 'npc_himelmez1$;
	end;
OnTimer78000:
	npctalk "Himelmez: I have business to take care of. My minions will treat you well enough for me~", 'npc_himelmez1$;
	end;
OnTimer84500:
	npctalk "Heinrich: She probably already knows where the Ymir's heart piece is.", 'npc_heinrich2$;
	disablenpc 'npc_himelmez1$;
	end;
OnTimer90500:
	npctalk "Heinrich: All Khalitzburg and White Knights should follow me now...", 'npc_heinrich2$;
	end;
OnTimer92000:
	for (.@i = 1; .@i <= 20; .@i += 4) {
		hideonnpc instance_npcname("Khalitzburg Knightage#" + .@i);
		hideonnpc instance_npcname("Khalitzburg Knightage#" + (.@i+1));
		hideonnpc instance_npcname("White Knight#" + (.@i+2));
		hideonnpc instance_npcname("White Knight#" + (.@i+3));
	}
	hideonnpc instance_npcname("Khalitzburg Knightage#21");
	hideonnpc instance_npcname("Khalitzburg Knightage#22");

	.@label$ = instance_npcname("#talkinstance1") + "::OnMyMobDead";
	monster 'map_name$[0],145,59,"Abysmal Knight",2470,1,.@label$;// MG_KNIGHT_OF_ABYSS
	monster 'map_name$[0],154,59,"Abysmal Knight",2470,1,.@label$;
	monster 'map_name$[0],145,69,"Abysmal Knight",2470,1,.@label$;
	monster 'map_name$[0],154,69,"Abysmal Knight",2470,1,.@label$;
	monster 'map_name$[0],145,79,"Abysmal Knight",2470,1,.@label$;
	monster 'map_name$[0],154,79,"Abysmal Knight",2470,1,.@label$;
	monster 'map_name$[0],145,89,"Abysmal Knight",2470,1,.@label$;
	monster 'map_name$[0],154,89,"Abysmal Knight",2470,1,.@label$;
	monster 'map_name$[0],145,99,"Abysmal Knight",2470,1,.@label$;
	monster 'map_name$[0],154,99,"Abysmal Knight",2470,1,.@label$;

	monster 'map_name$[0],145,54,"Khalitzburg",2471,1,.@label$;// G_MG_KHALITZBURG
	unittalk $@mobid[0],"Water... Someone give me water...";
	monster 'map_name$[0],154,54,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"Kkkrrrruughgh...";
	monster 'map_name$[0],145,64,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"Sir Heinrich. Save me...";
	monster 'map_name$[0],154,64,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"I miss my sister...";
	monster 'map_name$[0],145,74,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"Don't leave me alone, help me.";
	monster 'map_name$[0],154,74,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"Aaarrrrrhhhh";
	monster 'map_name$[0],145,84,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"I am so thirsty.";
	monster 'map_name$[0],154,84,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"Oh...No...I can't die yet...";
	monster 'map_name$[0],145,94,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"I feel sick to my stomach urrgg";
	monster 'map_name$[0],154,94,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"Can someone...";
	monster 'map_name$[0],145,104,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"Arrgg... My body";
	monster 'map_name$[0],154,104,"Khalitzburg",2471,1,.@label$;
	unittalk $@mobid[0],"My throat is burning!";
	end;
OnTimer94000:
	npctalk "Heinrich: My men... This can't be happening!", 'npc_heinrich2$;
	end;
OnTimer96500:
	npctalk "Varmundt: Sir Heinrich, they're all monsters. You need to give them rest!", 'npc_varmundt1$;
	end;
OnTimer100000:
	npctalk "Heinrich: I'm so sorry...", 'npc_heinrich2$;
	end;
OnTimer103000:
	npctalk "Heinrich: I am sorry, my knights! Forgive me!", 'npc_heinrich2$;
	end;
OnTimer106000:
	mapannounce 'map_name$[0], "Sir Heinrich: Death to all!", bc_map,0xFFFF33,FW_NORMAL,15;
	end;
OnTimer109000:
	mapannounce 'map_name$[0], "Sir Heinrich: Go back to the darkness!", bc_map,0xFFFF33,FW_NORMAL,15;
	end;
OnTimer109500:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#1");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#2");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#1");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#2");
	end;
OnTimer110000:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#3");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#4");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#5");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#6");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#3");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#4");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#5");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#6");
	end;
OnTimer110500:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#7");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#8");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#9");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#10");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#7");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#8");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#9");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#10");
	end;
OnTimer111000:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#11");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#12");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#13");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#14");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#11");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#12");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#13");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#14");
	end;
OnTimer111500:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#15");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#16");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#17");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#18");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#15");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#16");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#17");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#18");
	end;
OnTimer112000:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#19");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#20");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#21");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#22");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#19");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#20");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#21");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#22");
	disablenpc 'npc_heinrich2$;
	enablenpc 'npc_heinrich3$;
	killmonster 'map_name$[0], instance_npcname("#talkinstance1") + "::OnMyMobDead";
	end;
OnTimer112500:
	npctalk "Heinrich: I killed my own men...", 'npc_heinrich3$;
	end;
OnTimer115500:
	npctalk "Varmundt: Sir Heinrich! We don't have much time!", 'npc_varmundt1$;
	end;
OnTimer118500:
	npctalk "Varmundt: If you hurry now, there's a chance!", 'npc_varmundt1$;
	end;
OnTimer121500:
	npctalk "Heinrich: Varmundt is right. Now is not the time for mourning.", 'npc_heinrich3$;
	end;
OnTimer124500:
	npctalk "Heinrich: I have a request to you followers.", 'npc_heinrich3$;
	end;
OnTimer127500:
	npctalk "Heinrich: Himelmez can turn living beings into monsters.", 'npc_heinrich3$;
	end;
OnTimer130500:
	npctalk "Heinrich: But, there might still be survivors here.", 'npc_heinrich3$;
	end;
OnTimer134500:
	npctalk "Heinrich: Destroy the monsters and find any survivors.", 'npc_heinrich3$;
	end;
OnTimer138500:
	npctalk "Heinrich: Varmundt and I will chase Himelmez.", 'npc_heinrich3$;
	end;
OnTimer143500:
	npctalk "Heinrich: Very well, Varmundt. Let's find Himelmez.", 'npc_heinrich3$;
	end;
OnTimer147500:
	disablenpc 'npc_heinrich3$;
	end;
OnTimer148500:
	stopnpctimer;
	donpcevent instance_npcname("#ghmemorialmob01") + "::OnStart";

	disablenpc 'npc_varmundt1$;
	disablenpc instance_npcname("#talkinstance1");
	'npc_himelmez1$ = 'npc_varmundt1$ = 'npc_heinrich2$ = 'npc_heinrich3$ = "";
	end;
OnMyMobDead:
	end;
}

// Sector 1 Mobs
//============================================================
1@gl_k,1,1,0	script	#ghmemorialmob01	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob01");
	enablenpc instance_npcname("#2Control");
	enablenpc instance_npcname("#2Control2");
	mapannounce 'map_name$[0], "A portal has opened to the west.", bc_map,0xFFFF00;

	// note: x17 MG_GHOUL / x17 MG_ZOMBIE / x17 MG_WRAITH
	.@label$ = instance_npcname("#ghmemorialmob01") + "::OnMyMobDead";
	areamonster 'map_name$[0],76,99,87,10,"Grand Chamberlain in pain",2466,14,.@label$;
	areamonster 'map_name$[0],67,39,12, 6,"Corrupted Monk",2465,17,.@label$;
	areamonster 'map_name$[0],67,39,12, 6,"Grand Chamberlain in pain",2466,3,.@label$;
	areamonster 'map_name$[0],32,75,51,58,"Corrupted Steward",2464,5,.@label$;
	areamonster 'map_name$[0],45,84,6,137,"Corrupted Steward",2464,12,.@label$;
	end;
OnMyMobDead:
	.@label$ = instance_npcname("#ghmemorialmob01") + "::OnMyMobDead";
	.@mob_dead_num = 51 - mobcount('map_name$[0],.@label$);
	if (.@mob_dead_num > 35) {
		mapannounce 'map_name$[0], "Himelmez's curse is getting weaker. Find any survivors!", bc_map,0xFFFFFF;
		killmonster 'map_name$[0], .@label$;
		enablenpc instance_npcname("Altar boy Domun#1");
		disablenpc instance_npcname("#ghmemorialmob01");
	}
	end;
}

1@gl_k,17,51,3	script	Altar boy Domun#1	4_M_KID1,{
	if (is_party_leader() == false) {
		mes "[Altar boy Domun]";
		mes "Save me, save me, please...";
		close;
	}
	.@account_id = getcharid(3);
	.@player_name$ = strcharinfo(0);
	mes "[Altar boy Domun]";
	mes "Save me! Save me!!!";
	npctalk "Save me! Save me!!!";
	next;
	select("Hold on! Are you the only survivor?");
	mes "[" + .@player_name$ + "]";
	mes "Hold on! Are you the only survivor?";
	unittalk .@account_id, .@player_name$ + " : Hold on! Are you the only survivor?";
	next;
	mes "[Altar boy Domun]";
	mes "Chamberlains... monks... They all turned into monsters. I couldn't do anything.";
	npctalk "Altar boy Domun: Chamberlains... monks... They all turned into monsters. I couldn't do anything.";
	next;
	mes "[Altar boy Domun]";
	mes "All I could do was... Just hide in here... Nothing, nothing I could do...";
	npctalk "Altar boy Domun: All I could do was... Just hide in here... Nothing, nothing I could do...";
	next;
	select("Pull it together!");
	mes "[" + .@player_name$ + "]";
	mes "Wake up kid! Go east and find the middle passage to the outside! It is safe there!";
	unittalk .@account_id, .@player_name$ + " : Wake up kid! Go east and find the middle passage to the outside! It is safe there!";
	next;
	mes "[Altar boy Domun]";
	mes "To the east passage? Alone? How?";
	npctalk "Altar boy Domun: To the east passage? Alone? How?";
	next;
	select("I will give you a weapon.");
	mes "[" + .@player_name$ + "]";
	mes "Here's a weapon. Just close your eye and swing for those monsters.";
	unittalk .@account_id, .@player_name$ + " : Here's a weapon. Just close your eye and swing for those monsters.";
	next;
	mes "[Altar boy Domun]";
	mes "Ok, I... I'll try.";
	npctalk "Altar boy Domun: Ok, I... I'll try.";
	disablenpc instance_npcname("Altar boy Domun#1");
	donpcevent instance_npcname("#ghmemorialmob02") + "::OnStart";
	close;
}

// Sector 2 Mobs
//============================================================
1@gl_k,1,1,0	script	#ghmemorialmob02	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob02");
	enablenpc instance_npcname("#3Control");
	enablenpc instance_npcname("#3Control2");
	for ( .@i = 1; .@i <= 26; .@i++ )
		enablenpc instance_npcname("A dead man#" + .@i);
	mapannounce 'map_name$[0], "A portal has opened to the east.", bc_map,0xFFFF00;

	// note: x34 MG_ZOMBIE / x35 MG_GHOUL
	.@label$ = instance_npcname("#ghmemorialmob02") + "::OnMyMobDead";
	areamonster 'map_name$[0],236,12,288,52,"Outraged Refiner",2466,18,.@label$;// MG_GHOUL
	areamonster 'map_name$[0],236,12,288,52,"Decomposed Blacksmith",2464,17,.@label$;// MG_ZOMBIE
	areamonster 'map_name$[0],242,71,286,145,"Outraged Refiner",2466,17,.@label$;
	areamonster 'map_name$[0],242,71,286,145,"Decomposed Blacksmith",2464,17,.@label$;
	end;
OnMyMobDead:
	.@label$ = instance_npcname("#ghmemorialmob02") + "::OnMyMobDead";
	.@mob_dead_num = 69 - mobcount('map_name$[0],.@label$);
	if (.@mob_dead_num > 56) {
		mapannounce 'map_name$[0], "Himelmez's curse is getting weaker. Find any survivors!", bc_map,0xFFFFFF;
		killmonster 'map_name$[0],.@label$;
		enablenpc instance_npcname("Holgren the Destroyer#1");
		disablenpc instance_npcname("#ghmemorialmob02");
	}
	end;
}

1@gl_k,291,145,3	script	Holgren the Destroyer#1	4_F_JOB_BLACKSMITH,{
	if (is_party_leader() == false) {
		mes "[Holgren the Destroyer]";
		mes "You human?";
		close;
	}
	.@account_id = getcharid(3);
	.@player_name$ = strcharinfo(0);
	mes "[Holgren the Destroyer]";
	mes "Die!! You shall die!!!";
	npctalk "Holgren the Destroyer: Die!! You shall die!!!";
	specialeffect EF_CRASHEARTH;
	next;
	select("Relax! I'm not a monster!");
	mes "[" + .@player_name$ + "]";
	mes "Relax! I am Human. Are you alone? Is anyone else here?";
	unittalk .@account_id, .@player_name$ + " : Relax! I am Human. Are you alone? Is anyone else here?";
	next;
	mes "[Holgren the Destroyer]";
	mes "It's only me.";
	npctalk "Holgren the Destroyer: It's only me.";
	next;
	select("It's dangerous here...");
	mes "[" + .@player_name$ + "]";
	mes "It's dangerous here. You know the way to the middle passage? Can you move?";
	unittalk .@account_id, .@player_name$ + " : It's dangerous here. You know the way to the middle passage? Can you move?";
	next;
	mes "[Holgren the Destroyer]";
	mes "Yes, I can move. I need to get out of here.";
	npctalk "Holgren the Destroyer: Yes, I can move. I need to get out of here.";
	next;
	select("Be safe...");
	mes "[" + .@player_name$ + "]";
	mes "Sorry, I can't go with you.";
	unittalk .@account_id, .@player_name$ + " : Sorry, I can't go with you.";
	next;
	mes "[Holgren the Destroyer]";
	mes "It's ok. You've already done enough. I can help myself. Good luck to you too.";
	npctalk "Holgren the Destroyer: It's ok. You've already done enough. I can help myself. Good luck to you too.";
	disablenpc instance_npcname("Holgren the Destroyer#1");
	donpcevent instance_npcname("#ghmemorialmob03") + "::OnEnable";
	close;
}

// Tramp Mobs
//============================================================
1@gl_k,221,82,3	script	A dead man#1	4_M_DIEMAN,5,5,{
	end;
OnTouch_:
	.@i = rand(1,10);
	if (.@i == 1) .@mobs = 3;
	else if (.@i == 2) .@mobs = 4;
	else if (.@i == 3) .@mobs = 5;
	else if (.@i < 7) .@mobs = 6;
	else .@mobs = 7;
	getmapxy .@map$,.@x,.@y, BL_NPC;
	specialeffect EF_VENOMDUST;
	monster .@map$,.@x,.@y,"Maggot",2467,.@mobs;
	disablenpc instance_npcname( strnpcinfo(0) );
	end;
}
1@gl_k,233,123,4	duplicate(A dead man#1)	A dead man#2	4_M_DIEMAN,5,5
1@gl_k,258,150,2	duplicate(A dead man#1)	A dead man#3	4_M_DIEMAN,5,5
1@gl_k,255,157,5	duplicate(A dead man#1)	A dead man#4	4_M_DIEMAN,5,5
1@gl_k,280,167,4	duplicate(A dead man#1)	A dead man#5	4_M_DIEMAN,5,5
1@gl_k,293,161,2	duplicate(A dead man#1)	A dead man#6	4_M_DIEMAN,5,5
1@gl_k,249,101,3	duplicate(A dead man#1)	A dead man#7	4_M_DIEMAN,5,5
1@gl_k,241,86,6	duplicate(A dead man#1)	A dead man#8	4_M_DIEMAN,5,5
1@gl_k,246,62,0	duplicate(A dead man#1)	A dead man#9	4_M_DIEMAN,5,5
1@gl_k,240,43,7	duplicate(A dead man#1)	A dead man#10	4_M_DIEMAN,5,5
1@gl_k,271,19,1	duplicate(A dead man#1)	A dead man#11	4_M_DIEMAN,5,5
1@gl_k,282,48,5	duplicate(A dead man#1)	A dead man#12	4_M_DIEMAN,5,5
1@gl_k,285,81,7	duplicate(A dead man#1)	A dead man#13	4_M_DIEMAN,5,5
1@gl_k,276,106,0	duplicate(A dead man#1)	A dead man#14	4_M_DIEMAN,5,5
1@gl_k,261,164,0	duplicate(A dead man#1)	A dead man#15	4_M_DIEMAN,5,5
1@gl_k,269,173,0	duplicate(A dead man#1)	A dead man#16	4_M_DIEMAN,5,5
1@gl_k,252,120,0	duplicate(A dead man#1)	A dead man#17	4_M_DIEMAN,5,5
1@gl_k,213,63,0	duplicate(A dead man#1)	A dead man#18	4_M_DIEMAN,5,5
1@gl_k,222,39,0	duplicate(A dead man#1)	A dead man#19	4_M_DIEMAN,5,5
1@gl_k,214,27,0	duplicate(A dead man#1)	A dead man#20	4_M_DIEMAN,5,5
1@gl_k,223,17,1	duplicate(A dead man#1)	A dead man#21	4_M_DIEMAN,5,5
1@gl_k,230,50,2	duplicate(A dead man#1)	A dead man#22	4_M_DIEMAN,5,5
1@gl_k,235,16,3	duplicate(A dead man#1)	A dead man#23	4_M_DIEMAN,5,5
1@gl_k,226,96,4	duplicate(A dead man#1)	A dead man#24	4_M_DIEMAN,5,5
1@gl_k,222,119,5	duplicate(A dead man#1)	A dead man#25	4_M_DIEMAN,5,5
1@gl_k,251,20,6	duplicate(A dead man#1)	A dead man#26	4_M_DIEMAN,5,5

// Sector 3 Mobs
//============================================================
1@gl_k,1,1,0	script	#ghmemorialmob03	HIDDEN_WARP_NPC,{
	end;
OnEnable:
	enablenpc instance_npcname("#ghmemorialmob03");
	enablenpc instance_npcname("#4Control");
	enablenpc instance_npcname("#4Control2");
	mapannounce 'map_name$[0], "A portal has appeared to the northwest.", bc_map,0xFFFF00;

	// note: x50 MG_RAYDRIC / x50 MG_RAYDRIC_ARCHER
	.@label$ = instance_npcname("#ghmemorialmob03") + "::OnMyMobDead";
	areamonster 'map_name$[0],16,186,43,280,"Outraged Archer",2469,25,.@label$;
	areamonster 'map_name$[0],44,191,89,225,"Hungry Palace Guard",2468,25,.@label$;
	areamonster 'map_name$[0],115,215,188,273,"Corrupted Palace Guard",2468,20,.@label$;
	areamonster 'map_name$[0],108,232,193,281,"Corrupted Palace Guard",2468,5,.@label$;
	areamonster 'map_name$[0],158,236,230,250,"Wandering Archer",2469,12,.@label$;
	areamonster 'map_name$[0],65,231,155,256,"Wandering Archer",2469,13,.@label$;
	end;
OnMyMobDead:
	.@label$ = instance_npcname("#ghmemorialmob03") + "::OnMyMobDead";
	.@mob_dead_num = 100 - mobcount('map_name$[0],.@label$);
	if (.@mob_dead_num > 85) {
		killmonster 'map_name$[0],.@label$;
		enablenpc instance_npcname("#Mimelon");
		enablenpc instance_npcname("Himelmez#2");
		enablenpc instance_npcname("Varmundt#2");
		enablenpc instance_npcname("Heinrich#4");
		disablenpc instance_npcname("#ghmemorialmob03");
		mapannounce 'map_name$[0], "Himelmez: Not bad. Thought you would be dead by now by my creatures~", bc_map,0xFFFFFF;
		initnpctimer;
	}
	end;
OnTimer5000:
	mapannounce 'map_name$[0], "Himelmez: I'll wait for you at the north of the castle. I want to see how lucky you are.", bc_map,0xFFFFFF;
	stopnpctimer;
	end;
}

// 1st MVP
//============================================================
1@gl_k,144,258,6	script	Heinrich#4	4_M_HEINRICH,{
	mes "[Heinrich]";
	mes "Himelmez... I will never forget what you've done to my men.";
	cutin "gl_heinrich1",2;
	close3;
}

// note: never hidden
1@gl_k,156,258,3	script	Varmundt#2	4_M_BARMUND,{
	cutin "gl_barmund1",2;
	mes "[Varmundt]";
	if (checkquest(12318,HUNTING) != 2) {
		mes "I guess this is it. Is it impossible to stop the time traveler's will?!";
		mes "A portal seems to have appeared to the north.";
		close3;
	}
	erasequest 12318;
	if (isbegin_quest(12319) == 0)
		setquest 12319;// Amdarais Hunt
	if (isbegin_quest(12320) == 0) {
		setquest 12320;// Time Traveler
		completequest 12320;
		getexp 250000,250000;
	}
	mes "This item has an extraordinary aura with it. Can be very useful for someone special.";
	getitem 6607,1;// Temporal_Crystal
	getitem 6608,1;// Coagulated_Spell
	close3;
}

1@gl_k,150,257,3	script	Himelmez#2	4_F_HIMEL,{
	cutin "gl_himel2",2;
	mes "[Himelmez]";
	mes "Don't look at me nervous like that. It will be over soon...";
	close3;
}

1@gl_k,150,257,0	script	#Mimelon	HIDDEN_WARP_NPC,7,7,{
	end;
OnTouch_:
	disablenpc instance_npcname("#Mimelon");
	initnpctimer;
	'npc_himelmez2$ = instance_npcname("Himelmez#2");
	'npc_heinrich4$ = instance_npcname("Heinrich#4");
	end;
OnTimer3000:
	npctalk "Himelmez: Guess you are either lucky or powerful to make it this far.", 'npc_himelmez2$;
	end;
OnTimer6000:
	npctalk "Himelmez: But it doesn't matter.", 'npc_himelmez2$;
	end;
OnTimer9000:
	npctalk "Himelmez: You will all die here.", 'npc_himelmez2$;
	end;
OnTimer12000:
	npctalk "Heinrich: Himelmez! We will not let you get away from us!", 'npc_heinrich4$;
	end;
OnTimer15000:
	npctalk "Himelmez: Ha ha ha, worry about yourself. You think I am alone here?", 'npc_himelmez2$;
	end;
OnTimer18000:
	npctalk "Varmundt: Sir Heinrich! I sense something strange and strong coming!", instance_npcname("Varmundt#2");
	end;
OnTimer21000:
	npctalk "Heinrich: What... These are!", 'npc_heinrich4$;
	end;
OnTimer24000:
	npctalk "Himelmez: I will go on my way while my new toy entertains you.", 'npc_himelmez2$;
	end;
OnTimer27000:
	npctalk "Himelmez: Fare well~, hope to see you again sometime, Heinrich.", 'npc_himelmez2$;
	end;
OnTimer28000:
	disablenpc 'npc_himelmez2$;
	end;
OnTimer31000:
	npctalk "Heinrich: Sir Varmundt! Help those adventurers. I will go after Himelmez!", 'npc_heinrich4$;
	end;
OnTimer32000:
	disablenpc 'npc_heinrich4$;
	end;
OnTimer35000:
	mapannounce 'map_name$[0], "An echoing comes from deep inside of the knight's shrine.", bc_map,0xFFFFFF;
	end;
OnTimer38000:
	donpcevent instance_npcname("#ghmemorialmob04") + "::OnStart";
	stopnpctimer;
	'npc_himelmez2$ = 'npc_heinrich4$ = "";
	end;
}

1@gl_k,1,1,0	script	#ghmemorialmob04	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob04");
	monster 'map_name$[0],150,259,"Corrupted Soul",2475,1, instance_npcname("#ghmemorialmob04") + "::OnMyMobDead";// MG_CORRUPTION_ROOT
	unittalk $@mobid[0],"Grrrrrrhh~~~";
	end;
OnMyMobDead:
	if (mobcount('map_name$[0], instance_npcname("#ghmemorialmob04") + "::OnMyMobDead") < 1) {
		mapannounce 'map_name$[0], "Opening 2nd floor entrance towards 12 O'clock direction.", bc_map,0xFFFF00;
		npctalk "Varmundt: I collected some items dropped from its body. You can take it from me.", instance_npcname("Varmundt#2");
		enablenpc instance_npcname("#2F Entrance");
		enablenpc instance_npcname("#1 Control");
		enablenpc instance_npcname("#Servanton");
		enablenpc instance_npcname("Heinrich#21");
		enablenpc instance_npcname("Varmundt#21");
		donpcevent instance_npcname("#ghmemorialmob05") + "::OnStart";
		disablenpc instance_npcname("#ghmemorialmob04");
	}
	end;
}

// Floor 2
//============================================================
2@gl_k,148,67,1	script	Heinrich#21	4_M_HEINRICH,{
	mes "[Heinrich]";
	mes "Himelmez's closed space covers everywhere...";
	cutin "gl_heinrich1",2;
	close3;
}

2@gl_k,151,71,7	script	Varmundt#21	4_M_BARMUND,{
	mes "[Varmundt]";
	mes "How many times have I done this job? In my dream, I did it over and over again...";
	cutin "gl_barmund2",2;
	close3;
}

2@gl_k,150,66,0	script	#Servanton_effect	HIDDEN_WARP_NPC,{
	end;
OnEffect:
	specialeffect EF_LORD;
	end;
}

// note: this part can be skipped
2@gl_k,150,66,0	script	#Servanton	HIDDEN_WARP_NPC,7,7,{
	end;
OnTouch_:
	disablenpc instance_npcname("#Servanton");
	initnpctimer;
	'npc_heinrich$ = instance_npcname("Heinrich#21");
	'npc_varmundt$ = instance_npcname("Varmundt#21");
	end;
OnTimer3000:
	npctalk "Heinrich: This structure was not in the castle before!", 'npc_heinrich$;
	end;
OnTimer6000:
	npctalk "Varmundt: This is Himelmez's closed space. We blocked each area and aisle.", 'npc_varmundt$;
	end;
OnTimer9000:
	npctalk "Heinrich: We tried to break it down but it's really strong.", 'npc_heinrich$;
	end;
OnTimer12000:
	npctalk "Varmundt: Step back. Let me try to dispel the magic.", 'npc_varmundt$;
	end;
OnTimer15000:
	specialeffect EF_LORD,AREA, instance_npcname("#Servanton_effect");
	disablenpc instance_npcname("#Servanton_effect");
	end;
OnTimer18000:
	npctalk "Varmundt: I think that part of closed space is broken down.", 'npc_varmundt$;
	end;
OnTimer21000:
	npctalk "Varmundt: I have never seen this closed space.", 'npc_varmundt$;
	end;
OnTimer24000:
	npctalk "Varmundt: Himelmez hides stone chains in undead people's body.", 'npc_varmundt$;
	end;
OnTimer27000:
	npctalk "Varmundt: Maybe this closed space is maintained with these stone chains.", 'npc_varmundt$;
	end;
OnTimer30000:
	npctalk "Varmundt: If you want to break it, you have to kill one of those who have a stone chain.", 'npc_varmundt$;
	end;
OnTimer33000:
	npctalk "Varmundt: But we can't recognize who has a stone chain so we have to purify everything.", 'npc_varmundt$;
	end;
OnTimer36000:
	npctalk "Heinrich: It is inexcusable behavior.", 'npc_heinrich$;
	end;
OnTimer39000:
	npctalk "Heinrich: I already exterminated all my soldiers and maybe more...", 'npc_heinrich$;
	end;
OnTimer42000:
	npctalk "Varmundt: Commander...", 'npc_varmundt$;
	end;
OnTimer45000:
	npctalk "Varmundt: Commander! You need to be strong.", 'npc_varmundt$;
	end;
OnTimer48000:
	npctalk "Varmundt: Our enemy is not human.", 'npc_varmundt$;
	end;
OnTimer51000:
	npctalk "Varmundt: Even though you deny it, they'll never turn back to human.", 'npc_varmundt$;
	end;
OnTimer54000:
	npctalk "Heinrich: ...", 'npc_heinrich$;
	end;
OnTimer57000:
	npctalk "Varmundt: Well, let's go then.", 'npc_varmundt$;
	end;
OnTimer60000:
	npctalk "Varmundt: And you guys, just take a break and follow us.", 'npc_varmundt$;
	end;
OnTimer63000:
	npctalk "Varmundt: It could be hard fighting so stay strong.", 'npc_varmundt$;
	end;
OnTimer66000:
	npctalk "Varmundt: Ok, it's time to begin Heinrich.", 'npc_varmundt$;
	end;
OnTimer69000:
	mapannounce 'map_name$[1], "A portal to the west has opened in the central hallway.", bc_map,0xFFFF00;
	enablenpc instance_npcname("#22 Control");
	enablenpc instance_npcname("#22 Control2");
	disablenpc 'npc_varmundt$;
	disablenpc 'npc_heinrich$;
	stopnpctimer;
	'npc_varmundt$ = 'npc_heinrich$ = "";
	end;
}

// Spots
// Note: timer is the only condition for them to respawn

2@gl_k,118,141,0	script	#ogh_2-1	HIDDEN_WARP_NPC,20,20,{
	end;
OnTouch_:
OnSpawn:
	disablenpc instance_npcname( strnpcinfo(0) );
	.@hidden_name$ = strnpcinfo(2);
	.@event_type = atoi( charat(.@hidden_name$,4) );
	if (.@event_type == 2)
		.@label$ = instance_npcname("#ghmemorialmob05") + "::OnMyMobDead";
	else
		.@label$ = instance_npcname("#ghmemorialmob06") + "::OnMyMobDead";
	getmapxy .@map$,.@x,.@y, BL_NPC;
	monster .@map$,.@x,.@y, "Corrupted Palace Guard", 2468,1, .@label$;
	monster .@map$,.@x,.@y, "Archer of Death", 2469,1, .@label$;
	monster .@map$,.@x,.@y, "Corrupted Abysmal Knight", 2470,1, .@label$;
	monster .@map$,.@x,.@y, "Suffered Khalitzburg", 2471,1, .@label$;
	monster .@map$,.@x,.@y, "Bloody Knight", 2472,1, .@label$;
	initnpctimer;
	end;
OnTimer30000:
	enablenpc instance_npcname( strnpcinfo(0) );
	stopnpctimer;
	end;
OnStop:
	disablenpc instance_npcname( strnpcinfo(0) );
	stopnpctimer;
	end;
}
2@gl_k,128,81,0	duplicate(#ogh_2-1)	#ogh_2-2	HIDDEN_WARP_NPC,20,20
2@gl_k,131,54,0	duplicate(#ogh_2-1)	#ogh_2-3	HIDDEN_WARP_NPC,20,20
2@gl_k,89,48,0	duplicate(#ogh_2-1)	#ogh_2-4	HIDDEN_WARP_NPC,20,20
2@gl_k,64,117,0	duplicate(#ogh_2-1)	#ogh_2-5	HIDDEN_WARP_NPC,20,20
2@gl_k,62,82,0	duplicate(#ogh_2-1)	#ogh_2-6	HIDDEN_WARP_NPC,20,20
2@gl_k,38,138,0	duplicate(#ogh_2-1)	#ogh_2-7	HIDDEN_WARP_NPC,20,20

2@gl_k,171,120,0	duplicate(#ogh_2-1)	#ogh_3-1	HIDDEN_WARP_NPC,20,20
2@gl_k,232,133,0	duplicate(#ogh_2-1)	#ogh_3-2	HIDDEN_WARP_NPC,20,20
2@gl_k,256,149,0	duplicate(#ogh_2-1)	#ogh_3-3	HIDDEN_WARP_NPC,20,20
2@gl_k,212,106,0	duplicate(#ogh_2-1)	#ogh_3-4	HIDDEN_WARP_NPC,20,20
2@gl_k,243,73,0	duplicate(#ogh_2-1)	#ogh_3-5	HIDDEN_WARP_NPC,20,20
2@gl_k,229,26,0	duplicate(#ogh_2-1)	#ogh_3-6	HIDDEN_WARP_NPC,20,20
2@gl_k,181,34,0	duplicate(#ogh_2-1)	#ogh_3-7	HIDDEN_WARP_NPC,20,20

// Commander 1
2@gl_k,1,1,0	script	#ghmemorialmob05	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob05");
	for ( .@i = 1; .@i <= 7; .@i++ )
		enablenpc instance_npcname("#ogh_2-" + .@i);
	end;

OnMyMobDead:
	if (rand(50) == 0) {// can re-spawn
		mapannounce 'map_name$[1], "Evil Forces are appearing in this area.", bc_map,0xFFFF44,FW_NORMAL,15;
		killmonster 'map_name$[1], instance_npcname("#ghmemorialmob05") + "::OnBossDead";

		.@r = rand(4) * 2;
		setarray .@coord[0], 41,146, 58,44, 122,148, 131,64;
		monster 'map_name$[1],.@coord[.@r],.@coord[.@r+1], "1st Commander of Destruction",2473,1, instance_npcname("#ghmemorialmob05") + "::OnBossDead";
		'ogh_com_h1 = 1;
	}
	end;

OnBossDead:
	mapannounce 'map_name$[1], "A portal has opened to the east in the central hallway.", bc_map,0xFFFF00;
	enablenpc instance_npcname("#23 Control");
	enablenpc instance_npcname("#23 Control2");
	donpcevent instance_npcname("#ghmemorialmob06") + "::OnStart";

	disablenpc instance_npcname("#ghmemorialmob05");
	for ( .@i = 1; .@i <= 7; .@i++ )
		donpcevent instance_npcname("#ogh_2-" + .@i) + "::OnStop";
	end;
}

// Commander 2
2@gl_k,1,1,0	script	#ghmemorialmob06	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob06");
	for ( .@i = 1; .@i <= 7; .@i++ )
		enablenpc instance_npcname("#ogh_3-" + .@i);

	// Fix spawn
	.@label$ = instance_npcname("#ghmemorialmob06") + "::OnMyMobDead";
	monster 'map_name$[1],252, 75, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],253, 76, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],247, 77, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],248, 80, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],236,100, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],240,100, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],242,100, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],244,100, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],199,111, "Corrupted Palace Guard",2468,1, .@label$;
	monster 'map_name$[1],181,107, "Wandering Archer",2469,1, .@label$;
	monster 'map_name$[1],177,110, "Wandering Archer",2469,1, .@label$;
	monster 'map_name$[1],236, 27, "Wandering Archer",2469,1, .@label$;
	monster 'map_name$[1],242, 27, "Wandering Archer",2469,1, .@label$;
	monster 'map_name$[1],252, 26, "Wandering Archer",2469,1, .@label$;
	monster 'map_name$[1],172,130, "Wandering Archer",2469,1, .@label$;
	monster 'map_name$[1],171,127, "Wandering Archer",2469,1, .@label$;
	monster 'map_name$[1],173,127, "Wandering Archer",2469,1, .@label$;
	monster 'map_name$[1],177, 69, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],186, 66, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],189, 67, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],190, 68, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],257,157, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],246,159, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],237,158, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],206,159, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],172,120, "Corrupted Abysmal Knight",2470,1, .@label$;
	monster 'map_name$[1],226, 30, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],226, 38, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],228, 29, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],226, 63, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],268,137, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],263,138, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],259,138, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],259,138, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],187,121, "Suffered Khalitzburg",2471,1, .@label$;
	monster 'map_name$[1],265, 52, "Bloody Knight",2472,1, .@label$;
	monster 'map_name$[1],265, 55, "Bloody Knight",2472,1, .@label$; 
	monster 'map_name$[1],264, 79, "Bloody Knight",2472,1, .@label$; 
	monster 'map_name$[1],225, 92, "Bloody Knight",2472,1, .@label$; 
	monster 'map_name$[1],237, 92, "Bloody Knight",2472,1, .@label$; 
	monster 'map_name$[1],249, 92, "Bloody Knight",2472,1, .@label$; 
	monster 'map_name$[1],256, 93, "Bloody Knight",2472,1, .@label$; 
	monster 'map_name$[1],264,100, "Bloody Knight",2472,1, .@label$;
	monster 'map_name$[1],181,120, "Bloody Knight",2472,1, .@label$;
	end;

OnMyMobDead:
	if (rand(50) == 0) {// can re-spawn
		mapannounce 'map_name$[1], "An evil presence has teleported into this area.", bc_map,0xFFFF44,FW_NORMAL,15;
		killmonster 'map_name$[1], instance_npcname("#ghmemorialmob06") + "::OnBossDead";

		.@r = rand(4) * 2;
		setarray .@coord[0], 166,119, 211,45, 227,139, 245,74;
		monster 'map_name$[1],.@coord[.@r],.@coord[.@r+1], "2nd Commander of Destruction",2474,1, instance_npcname("#ghmemorialmob06") + "::OnBossDead";
		'ogh_com_h2 = 1;
	}
	end;

OnBossDead:
	mapannounce 'map_name$[1], "A new portal has appeared at the end of the central corridor.", bc_map,0xFFFF00;
	enablenpc instance_npcname("#24 Control");
	enablenpc instance_npcname("#24 Control2");
	enablenpc instance_npcname("#Geron");
	for ( .@i = 1; .@i <= 35; .@i++ )
		enablenpc instance_npcname("Decomposed body#" + .@i);

	disablenpc instance_npcname("#ghmemorialmob06");
	for ( .@i = 1; .@i <= 7; .@i++ )
		donpcevent instance_npcname("#ogh_3-" + .@i) + "::OnStop";

	// Hidden mobs
	setarray .@coord[0],
		 37,265, 57,265, 77,265, 97,265, 117,265, 188,264, 208,264,
		 50,172, 70,172, 90,172, 110,172, 170,172, 210,172, 230,172,
		 88,214, 108,214, 128,214, 180,219, 200,219, 220,219, 240,219;
	.@size = getarraysize(.@coord);
	for ( .@i = 0; .@i < .@size; .@i += 2 )
		monster 'map_name$[1], .@coord[.@i], .@coord[.@i+1], "Flame of destruction",2337,1;// HIDDEN_MOB
	end;
}

// Amdarais Room Entrance
2@gl_k,150,180,0	script	#Geron	HIDDEN_WARP_NPC,7,7,{
	end;
OnTouch_:
	disablenpc instance_npcname("#Geron");
	mapannounce 'map_name$[1], "???: Do not come here! It's a trap... Kkkkah!!!", bc_map,0xFF7777,FW_NORMAL,15;
	enablenpc instance_npcname("Himelmez#22");
	enablenpc instance_npcname("Varmundt#23");
	enablenpc instance_npcname("Heinrich#23");
	enablenpc instance_npcname("Gerhalt#23");
	end;
}

2@gl_k,143,260,4	script	Decomposed body#1	4_M_DIEMAN,5,5,{
	end;
OnTouch_:
	disablenpc instance_npcname( strnpcinfo(0) );
	.@i = rand(1,10);
	if (.@i == 1) .@mobs = 3;
	else if (.@i == 2) .@mobs = 4;
	else if (.@i == 3) .@mobs = 5;
	else if (.@i < 7) .@mobs = 6;
	else .@mobs = 7;
	getmapxy .@map$,.@x,.@y, BL_NPC;
	specialeffect EF_VENOMDUST;
	monster .@map$,.@x,.@y,"Maggot",2467,.@mobs;
	initnpctimer;
	end;
OnTimer45000:
	enablenpc instance_npcname( strnpcinfo(0) );
	stopnpctimer;
	end;
}
2@gl_k,145,236,4	duplicate(Decomposed body#1)	Decomposed body#2	4_M_DIEMAN,5,5
2@gl_k,141,222,2	duplicate(Decomposed body#1)	Decomposed body#3	4_M_DIEMAN,5,5
2@gl_k,147,203,5	duplicate(Decomposed body#1)	Decomposed body#4	4_M_DIEMAN,5,5
2@gl_k,167,225,4	duplicate(Decomposed body#1)	Decomposed body#5	4_M_DIEMAN,5,5
2@gl_k,172,233,2	duplicate(Decomposed body#1)	Decomposed body#6	4_M_DIEMAN,5,5
2@gl_k,176,244,3	duplicate(Decomposed body#1)	Decomposed body#7	4_M_DIEMAN,5,5
2@gl_k,184,248,6	duplicate(Decomposed body#1)	Decomposed body#8	4_M_DIEMAN,5,5
2@gl_k,193,228,0	duplicate(Decomposed body#1)	Decomposed body#9	4_M_DIEMAN,5,5
2@gl_k,206,250,7	duplicate(Decomposed body#1)	Decomposed body#10	4_M_DIEMAN,5,5
2@gl_k,130,249,1	duplicate(Decomposed body#1)	Decomposed body#11	4_M_DIEMAN,5,5
2@gl_k,122,236,5	duplicate(Decomposed body#1)	Decomposed body#12	4_M_DIEMAN,5,5
2@gl_k,130,228,7	duplicate(Decomposed body#1)	Decomposed body#13	4_M_DIEMAN,5,5
2@gl_k,106,226,0	duplicate(Decomposed body#1)	Decomposed body#14	4_M_DIEMAN,5,5
2@gl_k,104,245,0	duplicate(Decomposed body#1)	Decomposed body#15	4_M_DIEMAN,5,5
2@gl_k,131,187,0	duplicate(Decomposed body#1)	Decomposed body#16	4_M_DIEMAN,5,5
2@gl_k,121,197,0	duplicate(Decomposed body#1)	Decomposed body#17	4_M_DIEMAN,5,5
2@gl_k,107,194,0	duplicate(Decomposed body#1)	Decomposed body#18	4_M_DIEMAN,5,5
2@gl_k,92,187,0	duplicate(Decomposed body#1)	Decomposed body#19	4_M_DIEMAN,5,5
2@gl_k,153,214,3	duplicate(Decomposed body#1)	Decomposed body#20	4_M_DIEMAN,5,5
2@gl_k,155,195,4	duplicate(Decomposed body#1)	Decomposed body#21	4_M_DIEMAN,5,5
2@gl_k,154,188,2	duplicate(Decomposed body#1)	Decomposed body#22	4_M_DIEMAN,5,5
2@gl_k,143,195,5	duplicate(Decomposed body#1)	Decomposed body#23	4_M_DIEMAN,5,5
2@gl_k,132,214,4	duplicate(Decomposed body#1)	Decomposed body#24	4_M_DIEMAN,5,5
2@gl_k,125,208,2	duplicate(Decomposed body#1)	Decomposed body#25	4_M_DIEMAN,5,5
2@gl_k,114,210,3	duplicate(Decomposed body#1)	Decomposed body#26	4_M_DIEMAN,5,5
2@gl_k,137,182,6	duplicate(Decomposed body#1)	Decomposed body#27	4_M_DIEMAN,5,5
2@gl_k,138,246,0	duplicate(Decomposed body#1)	Decomposed body#28	4_M_DIEMAN,5,5
2@gl_k,132,260,7	duplicate(Decomposed body#1)	Decomposed body#29	4_M_DIEMAN,5,5
2@gl_k,128,251,1	duplicate(Decomposed body#1)	Decomposed body#30	4_M_DIEMAN,5,5
2@gl_k,179,260,3	duplicate(Decomposed body#1)	Decomposed body#31	4_M_DIEMAN,5,5
2@gl_k,170,261,4	duplicate(Decomposed body#1)	Decomposed body#32	4_M_DIEMAN,5,5
2@gl_k,177,219,2	duplicate(Decomposed body#1)	Decomposed body#33	4_M_DIEMAN,5,5
2@gl_k,190,214,5	duplicate(Decomposed body#1)	Decomposed body#34	4_M_DIEMAN,5,5
2@gl_k,201,214,4	duplicate(Decomposed body#1)	Decomposed body#35	4_M_DIEMAN,5,5

// Amdarais Spawn
2@gl_k,153,250,8	script	Heinrich#23	4_M_HEINRICH,{
	cutin "gl_heinrich1",2;
	mes "[Heinrich]";
	mes "What are you putting on Himelmez!";
	close3;
}

2@gl_k,162,250,1	script	Varmundt#23	4_M_BARMUND,{
	mes "[Varmundt]";
	mes "Can't take off this bridle...";
	cutin "gl_barmund2",2;
	close3;
}

2@gl_k,158,255,1	script	Gerhalt#23	4_LEVITATEMAN,{
	mes "[Gerhalt]";
	mes "Uuuuu... Khhhah! Just run away with the commander.";
	close;
}

2@gl_k,158,252,1	script	Himelmez#22	4_F_HIMEL,3,3,{
	cutin "gl_himel2",2;
	mes "[Himelmez]";
	mes "That is amazing ~ you made it all the way here. May I say thank you?";
	close3;

OnTouch:
	end;
OnTouch_:
	disablenpc instance_npcname("Himelmez#22");
	enablenpc instance_npcname("Himelmez#23");
	initnpctimer;
	'party_id = getcharid(1);
	'npc_himelmez$ = instance_npcname("Himelmez#23");
	'npc_gerhalt$ = instance_npcname("Gerhalt#23");
	'npc_heinrich$ = instance_npcname("Heinrich#23");
	'npc_varmundt$ = instance_npcname("Varmundt#23");
	end;
OnTimer3000:
	npctalk "Himelmez: Amazing~ I thought that you were not even close to getting here...", 'npc_himelmez$;
	end;
OnTimer6000:
	npctalk "Gerhalt: Kkkkah! Run away! I can't endure anymore!", 'npc_gerhalt$;
	end;
OnTimer9000:
	npctalk "Heinrich: Gerhalt!", 'npc_heinrich$;
	end;
OnTimer15000:
	npctalk "Heinrich: What are you doing to my soldier Himelmez!", 'npc_heinrich$;
	end;
OnTimer18000:
	npctalk "Himelmez: Hoo hoo, I already found a piece of Ymir's heart, Heinrich.", 'npc_himelmez$;
	end;
OnTimer21000:
	npctalk "Himelmez: If he did not bother me it would have been faster.", 'npc_himelmez$;
	end;
OnTimer24000:
	npctalk "Gerhalt: Commandant... Come on, you need to run away from here... Ugh.", 'npc_gerhalt$;
	end;
OnTimer27000:
	npctalk "Himelmez: Really? What makes you think so?", 'npc_himelmez$;
	end;
OnTimer30000:
	npctalk "Heinrich: Himelmez! You already made what you wanted so there is no more need for a sacrifice!", 'npc_heinrich$;
	end;
OnTimer33000:
	npctalk "Heinrich: Let him go! I don't need to see anyone else suffer!", 'npc_heinrich$;
	end;
OnTimer36000:
	npctalk "Himelmez: Let him go? I think... No...", 'npc_himelmez$;
	end;
OnTimer39000:
	npctalk "Himelmez: Besides, this is your last surviving soldier, Heinrich.", 'npc_himelmez$;
	end;
OnTimer42000:
	npctalk "Himelmez: He made life difficult for me.", 'npc_himelmez$;
	end;
OnTimer45000:
	npctalk "Himelmez: He is perfectly fit for my new creation Amdarais.", 'npc_himelmez$;
	end;
OnTimer48000:
	npctalk "Heinrich: I'll never forgive you.", 'npc_heinrich$;
	end;
OnTimer51000:
	npctalk "Himelmez: Uh uh~ I'm so scared.", 'npc_himelmez$;
	end;
OnTimer54000:
	npctalk "Himelmez: Anyway, we will have a chance to see because we need to talk more.", 'npc_himelmez$;
	end;
OnTimer57000:
	npctalk "Himelmez: So long boys.", 'npc_himelmez$;
	end;
OnTimer60000:
	specialeffect EF_BARRIER, AREA, 'npc_gerhalt$;
	end;
OnTimer63000:
	disablenpc 'npc_himelmez$;
	end;
OnTimer65000:
	npctalk "Gerhalt: You can make my body but you can't take my soul, Himelmez!", 'npc_gerhalt$;
	end;
OnTimer66000:
	specialeffect EF_CHAINCOMBO, AREA, 'npc_gerhalt$;
	end;
OnTimer67000:
	npctalk "Heinrich: I'll never let you get away Himelmez!!", 'npc_heinrich$;
	specialeffect EF_MAPPILLAR, AREA, 'npc_gerhalt$;
	end;
OnTimer70000:
	specialeffect EF_MAPPILLAR2, AREA, 'npc_gerhalt$;
	specialeffect EF_MAPPILLAR, AREA, 'npc_gerhalt$;
	disablenpc 'npc_heinrich$;
	npctalk "Varmundt: We have no choice. We have to fight against Amdarais!", 'npc_varmundt$;
	end;
OnTimer73000:
	mapannounce 'map_name$[1], "Gerhalt's body is changing.", bc_map,0xFFFFFF;
	end;
OnTimer76000:
	specialeffect EF_LORD, AREA, 'npc_gerhalt$;
	disablenpc 'npc_varmundt$;
	mapannounce 'map_name$[1], "Varmundt: Let me help this battle with my illusion. Just follow the illusion's orders.", bc_map,0xFFFF00;
	end;
OnTimer80000:
	disablenpc 'npc_gerhalt$;
	donpcevent instance_npcname("#ghmemorialmob07") + "::OnStart";
	stopnpctimer;
	'npc_himelmez$ = 'npc_gerhalt$ = 'npc_heinrich$ = 'npc_varmundt$ = "";
	end;
}

2@gl_k,158,252,4	script	Himelmez#23	4_F_HIMEL,{
	cutin "gl_himel2",2;
	mes "[Himelmez]";
	mes "That is amazing ~ you made it all the way here. May I say thank you?";
	close3;
}

2@gl_k,1,1,0	script	#ghmemorialmob07	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob07");
	monster 'map_name$[1],158,255,"Amdarais",2476,1,instance_npcname("#ghmemorialmob07") + "::OnMyMobDead";// MG_AMDARAIS
	'boss_id = $@mobid[0];
	unittalk 'boss_id, "Run away... run away from me...";
	initnpctimer;
	end;
OnTimer5000:
	unittalk 'boss_id, "I don't want... I don't want to kill anyone. Uhuuuuuh";
	end;
OnTimer10000:
	unittalk 'boss_id, "Please kill me! Please!";
	end;
OnTimer16000:
	unittalk 'boss_id, "Eeeeee...eee...die... die...";
	end;
OnTimer22000:
	unittalk 'boss_id, "Demolition... Death!...";
	end;
OnTimer55000:
	donpcevent instance_npcname("#ghmemorialmob08") + "::OnStart";// Varmundt buffs and additionnal monsters
	stopnpctimer;
	end;

OnMyMobDead:
	if (mobcount('map_name$[1], instance_npcname("#ghmemorialmob07") + "::OnMyMobDead") < 1) {
		stopnpctimer;
		enablenpc instance_npcname("Hugin#21");
		enablenpc instance_npcname("#Secret Room Exit");

		stopnpctimer;
		disablenpc instance_npcname("#ghmemorialmob07");
		// note: monsters from #ghmemorialmob08 still alive on Amdarais's dead
	}
	end;
}

// Varmundt Buffs
2@gl_k,1,1,0	script	#ghmemorialmob08	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob08");
	initnpctimer;
	end;
OnTimer5000:
	if (unitexists('boss_id) == 0) {
		disablenpc instance_npcname("#ghmemorialmob08");
		stopnpctimer;
		end;
	}
	getunitdata 'boss_id, .@data;
	.@percent_hp = (.@data[UMOB_HP] * 100) / .@data[UMOB_MAXHP];
	mapannounce 'map_name$[1], "Amdarais HP " + .@percent_hp + "% reach!", bc_map,0x70DBDB;

	// event type every 10%
	switch( .@percent_hp / 10 ) {
	case 10:
		break;
	case 9:
		donpcevent instance_npcname("Varmundt's Ghost#Buff2") + "::OnEvent";
		break;
	case 8:
		donpcevent instance_npcname("Varmundt's Ghost#Buff3") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Suffered Khalitzburg",2471,6, instance_npcname("#ghmemorialmob08") + "::OnMobDead";
		break;
	case 7:
		donpcevent instance_npcname("Varmundt's Ghost#Buff3") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Abysmal Knight",2470,6, instance_npcname("#ghmemorialmob08") + "::OnMobDead";
		break;
	case 6:
		donpcevent instance_npcname("Varmundt's Ghost#Buff3") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Bloody Knight",2472,6, instance_npcname("#ghmemorialmob08") + "::OnMobDead";
		break;
	case 5:
		donpcevent instance_npcname("Varmundt's Ghost#Buff2") + "::OnEvent";
		break;
	case 4:
		donpcevent instance_npcname("Varmundt's Ghost#Buff3") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Wandering Archer",2469,6, instance_npcname("#ghmemorialmob08") + "::OnMobDead";
		break;
	case 3:
		donpcevent instance_npcname("Varmundt's Ghost#Buff1") + "::OnEvent";
		donpcevent instance_npcname("Varmundt's Ghost#Buff3") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Bloody Knight",2472,6, instance_npcname("#ghmemorialmob08") + "::OnMobDead";
		break;
	case 2:
		donpcevent instance_npcname("Varmundt's Ghost#Buff1") + "::OnEvent";
		donpcevent instance_npcname("Varmundt's Ghost#Buff3") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Abysmal Knight",2470,6, instance_npcname("#ghmemorialmob08") + "::OnMobDead";
		break;
	case 1:
	case 0:
		donpcevent instance_npcname("Varmundt's Ghost#Buff1") + "::OnEvent";
		donpcevent instance_npcname("Varmundt's Ghost#Buff4") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Wandering Archer",2469,6, instance_npcname("#ghmemorialmob08") + "::OnMobDead";
		break;
	}
	end;
OnTimer30000:
	killmonster 'map_name$[1], instance_npcname("#ghmemorialmob08") + "::OnMobDead";
	initnpctimer;
	end;
OnMobDead:
	end;
}

2@gl_k,150,247,5	script	Varmundt's Ghost#Buff1	4_M_BARMUND,2,2,{
	end;
OnTouch:
	specialeffect2 EF_ENHANCE;
	.@num = atoi( replacestr(strnpcinfo(2), "Buff", "") );
	if (.@num == 1)
		sc_start SC_GLASTHEIM_HIDDEN,30000,1,10000,SCSTART_NOTICKDEF;
	else if (.@num == 2)
		sc_start SC_GLASTHEIM_STATE,30000,1,10000,SCSTART_NOTICKDEF;
	else if (.@num == 3) {
		sc_start SC_GLASTHEIM_HEAL,30000,1,10000,SCSTART_NOTICKDEF;
		sc_start SC_GLASTHEIM_HPSP,30000,1,10000,SCSTART_NOTICKDEF;
	}
	else {
		sc_start SC_GLASTHEIM_DEF,30000,1,10000,SCSTART_NOTICKDEF;
		sc_start SC_GLASTHEIM_ITEMDEF,30000,1,10000,SCSTART_NOTICKDEF;
	}
	end;
OnEvent:
	initnpctimer;
	enablenpc instance_npcname( strnpcinfo(0) );
	.@num = atoi( replacestr(strnpcinfo(2), "Buff", "") );
	if (.@num == 1)
		npctalk "Varmundt's Ghost: Amdarais may use a strong magic shield! Stay close to me and I'll protect you!";
	else if (.@num == 2)
		npctalk "Varmundt's Ghost: Now's a chance to attack! Come closer to me and strike!";
	else if (.@num == 3)
		npctalk "Varmundt's Ghost: If you don't want to be attacked by Amdarais' zombie, come to me and get more power!";
	else
		npctalk "Varmundt's Ghost: If you don't want to be attacked by Amdarais's power, come to me and get more power!";
	end;
OnTimer10000:
	stopnpctimer;
	disablenpc instance_npcname( strnpcinfo(0) );
	end;
}
2@gl_k,165,247,3	duplicate(Varmundt's Ghost#Buff1)	Varmundt's Ghost#Buff2	4_M_BARMUND,2,2
2@gl_k,150,232,8	duplicate(Varmundt's Ghost#Buff1)	Varmundt's Ghost#Buff3	4_M_BARMUND,2,2
2@gl_k,165,232,2	duplicate(Varmundt's Ghost#Buff1)	Varmundt's Ghost#Buff4	4_M_BARMUND,2,2


2@gl_k,158,241,1	script	Hugin#21	4_M_SAGE_C,{
	if (checkquest(12319,HUNTING) == 2) {// note: complete hunting 'Corrupted Soul Hunt' prerequis
		mes "[Hugin]";
		mes "Hm, you are very well. First of all, let me give you some loot from Amdarais.";
		erasequest 12319;
		setquest 12322;// Space Distortion
		if (isbegin_quest(12321) == 0) {
			setquest 12321;// Time Conqueror
			completequest 12321;
			getitem 6607,5;// Temporal_Crystal
			getitem 6608,5;// Coagulated_Spell
			getexp 350000,350000;
		}
		else {
			getitem 6607,1;// Temporal_Crystal
			getitem 6608,1;// Coagulated_Spell
		}
		next;
		mes "[Hugin]";
		mes "Varmundt's time is stopped by me.";
		mes "And your time will be distorted soon.";
		specialeffect2 EF_BLIND;
		soundeffect "_blind.wav",0;
		next;
		mes "[Hugin]";
		mes "Maybe this poor time traveler will try to stop Glast Heim's tragedy from happening.";
		next;
		mes "[Hugin]";
		mes "However, we will never overlook his behavior now and forever...";
		next;
		mes "[Hugin]";
		mes "Now let me remove your memory. If you see me again it will be someone new.";
		specialeffect2 EF_FREEZE;
		close2;
		warp 'map_name$[1],158,244;
		end;
	}
	mes "[Hugin]";
	mes "Oops. I almost distorted the time gap. Come over here. We need to go out!";
	next;
	select("You were just with me...");
	mes "[Hugin]";
	mes "What did you say just before?";
	mes "Anyway, that is not important. The gap of time will be closed so we need to get out of here.";
	next;
	if (select("Let me look around more:Please let me out") == 1) {
		mes "[Hugin]";
		mes "Really? This place will be break down soon. Please look around quickly.";
		close;
	}
	close2;
	warp "glast_01",204,270;
	end;
}

// Treasure Room
//============================================================
1@gl_k,165,136,3	script	Strange crack#2	CLEAR_NPC,{
	if (isbegin_quest(12322) == 0) {// Space Distortion
		mes "The crack looks suspicious but nothing more to check.";
		close;
	}
	specialeffect EF_SPELLBREAKER;

	.@random = rand(1,4);
	switch( atoi(strnpcinfo(2)) ) {
	case 2:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 719,1,"this",165,138;
		makeitem 6608,1,"this",165,138;
		break;
	case 3:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 720,1,"this",159,138;
		if (rand(1,4) == 4)
			makeitem2 15066,1,"this",159,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",159,138;
		makeitem 7229,1,"this",159,138;
		break;
	case 4:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 721,1,"this",153,138;
		if (rand(1,4) == 4)
			makeitem2 13086,1,"this",153,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",153,138;
		makeitem 7230,1,"this",153,138;
		break;
	case 5:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 722,1,"this",147,138;
		if (rand(1,4) == 4)
			makeitem2 2949,1,"this",147,138,0,0,0,0,0,0,0;
		makeitem 6612,1,"this",147,138;
		makeitem 6613,1,"this",147,138;
		makeitem 6608,1,"this",147,138;
		break;
	case 6:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 725,1,"this",141,138;
		makeitem 7228,1,"this",141,138;
		if (rand(1,4) == 4)
			makeitem2 13440,1,"this",141,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",141,138;
		break;
	case 7:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 726,1,"this",135,138;
		if (rand(1,4) == 4)
			makeitem2 2022,1,"this",135,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",135,138;
		break;
	case 8:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 727,1,"this",129,138;
		if (rand(1,4) == 4)
			makeitem2 21007,1,"this",129,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",129,138;
		break;
	}
	disablenpc instance_npcname( strnpcinfo(0) );
	end;
}
1@gl_k,159,136,3	duplicate(Strange crack#2)	Strange crack#3	CLEAR_NPC
1@gl_k,153,136,3	duplicate(Strange crack#2)	Strange crack#4	CLEAR_NPC
1@gl_k,147,136,3	duplicate(Strange crack#2)	Strange crack#5	CLEAR_NPC
1@gl_k,141,136,3	duplicate(Strange crack#2)	Strange crack#6	CLEAR_NPC
1@gl_k,135,136,3	duplicate(Strange crack#2)	Strange crack#7	CLEAR_NPC
1@gl_k,129,136,3	duplicate(Strange crack#2)	Strange crack#8	CLEAR_NPC

1@gl_k,269,267,3	script	Strange crack#1	CLEAR_NPC,{
	if (isbegin_quest(12322) == 0) {// Space Distortion
		mes "The crack looks suspicious but nothing more to check.";
		close;
	}
	warp 'map_name$[0],149,198;
	end;

OnInstanceInit:
	'map_name$[0] = instance_mapname("1@gl_k");
	'map_name$[1] = instance_mapname("2@gl_k");

	// Entrance
	disablenpc instance_npcname("Himelmez#1");
	disablenpc instance_npcname("Varmundt#1");
	disablenpc instance_npcname("Heinrich#1");
	disablenpc instance_npcname("Heinrich#2");
	disablenpc instance_npcname("Heinrich#3");

	// Rescue 1
	disablenpc instance_npcname("#ghmemorialmob01");
	disablenpc instance_npcname("Altar boy Domun#1");

	// Rescue 2
	disablenpc instance_npcname("#ghmemorialmob02");
	disablenpc instance_npcname("Holgren the Destroyer#1");
	for ( .@i = 1; .@i <= 26; .@i++ )
		disablenpc instance_npcname("A dead man#" + .@i);

	// Sector 3
	disablenpc instance_npcname("#ghmemorialmob03");

	// Root of Corruption
	disablenpc instance_npcname("Himelmez#2");
	disablenpc instance_npcname("Varmundt#2");
	disablenpc instance_npcname("Heinrich#4");
	disablenpc instance_npcname("#Mimelon");
	disablenpc instance_npcname("#ghmemorialmob04");

	// Entrance 2nd map
	disablenpc instance_npcname("Varmundt#21");
	disablenpc instance_npcname("Heinrich#21");
	disablenpc instance_npcname("#Servanton");
	hideonnpc instance_npcname("#Servanton_effect");

	// Commanders
	disablenpc instance_npcname("#ghmemorialmob05");
	disablenpc instance_npcname("#ghmemorialmob06");
	for ( .@i = 1; .@i <= 7; .@i++ ) {
		disablenpc instance_npcname("#ogh_2-" + .@i);
		disablenpc instance_npcname("#ogh_3-" + .@i);
	}

	// Amdarais Room Entrance
	disablenpc instance_npcname("#Geron");
	for ( .@i = 1; .@i <= 35; .@i++ )
		disablenpc instance_npcname("Decomposed body#" + .@i);

	// Amdarais Spawn
	disablenpc instance_npcname("Gerhalt#23");
	disablenpc instance_npcname("Himelmez#22");
	disablenpc instance_npcname("Himelmez#23");
	disablenpc instance_npcname("Varmundt#23");
	disablenpc instance_npcname("Heinrich#23");
	disablenpc instance_npcname("#ghmemorialmob07");

	// Varmundt Buffs
	disablenpc instance_npcname("#ghmemorialmob08");
	disablenpc instance_npcname("Varmundt's Ghost#Buff1");
	disablenpc instance_npcname("Varmundt's Ghost#Buff2");
	disablenpc instance_npcname("Varmundt's Ghost#Buff3");
	disablenpc instance_npcname("Varmundt's Ghost#Buff4");
	disablenpc instance_npcname("Hugin#21");

	// Warps
	disablenpc instance_npcname("#2Control");
	disablenpc instance_npcname("#2Control2");
	disablenpc instance_npcname("#3Control");
	disablenpc instance_npcname("#3Control2");
	disablenpc instance_npcname("#4Control");
	disablenpc instance_npcname("#4Control2");
	disablenpc instance_npcname("#2F Entrance");
	disablenpc instance_npcname("#1 Control");
	disablenpc instance_npcname("#22 Control");
	disablenpc instance_npcname("#22 Control2");
	disablenpc instance_npcname("#23 Control");
	disablenpc instance_npcname("#23 Control2");
	disablenpc instance_npcname("#24 Control");
	disablenpc instance_npcname("#24 Control2");
	disablenpc instance_npcname("#Secret Room Exit");
	end;
}

// Warps
1@gl_k2,96,80,0	warp	#2Control_h	2,2,1@gl_k2,80,80
1@gl_k2,90,80,0	warp	#2Control2_h	2,2,1@gl_k2,105,80
1@gl_k2,202,79,0	warp	#3Control_h	2,2,1@gl_k2,215,79
1@gl_k2,206,79,0	warp	#3Control2_h	2,2,1@gl_k2,195,79
1@gl_k2,227,216,0	warp	#4Control_h	2,2,1@gl_k2,215,216
1@gl_k2,222,216,0	warp	#4Control2_h	2,2,1@gl_k2,233,216
1@gl_k2,150,284,0	warp	#2F Entrance_h	2,2,2@gl_k2,150,46
2@gl_k2,149,32,0	warp	#1 Control_h	2,2,1@gl_k2,150,270
2@gl_k2,145,123,0	warp	#22 Control_h	2,2,2@gl_k2,126,123
2@gl_k2,136,122,0	warp	#22 Control2_h	2,2,2@gl_k2,150,116
2@gl_k2,154,101,0	warp	#23 Control_h	2,2,2@gl_k2,174,101
2@gl_k2,165,101,0	warp	#23 Control2_h	2,2,2@gl_k2,150,111
2@gl_k2,150,163,0	warp	#24 Control_h	2,2,2@gl_k2,150,179
2@gl_k2,150,167,0	warp	#24 Control2_h	2,2,2@gl_k2,150,149
1@gl_k2,69,168,0	warp	#Secret Room Exit_h	2,2,1@gl_k2,48,168

// Floor 1
//============================================================
1@gl_k2,149,41,5	script	Varmundt#0_h	4_M_BARMUND,{
	if (is_party_leader() == false) {
		mes "[Varmundt]";
		mes "Where's your leader? I need his help.";
		cutin "gl_barmund2",2;
		close3;
	}
	'party_id = getcharid(1);
	.@account_id = getcharid(3);
	.@player_name$ = strcharinfo(0);
	mes "[Varmundt]";
	mes "Are you the one ^0000ffHerico^000000 sent to help me?";
	npctalk "Varmundt: Are you the one Herico sent to help me?";
	cutin "gl_barmund1",2;
	next;
	select("Oh. Well I...");
	mes "[" + .@player_name$ + "]";
	mes "Ah yes, I am. Herico told me to meet you.";
	unittalk .@account_id, .@player_name$ + " : Ah yes, I am. Herico told me to meet you.";
	next;
	mes "[Varmundt]";
	mes "We don't have much time. We must report to Sir Heinrich about Himelmez's invasion.";
	npctalk "Varmundt: We don't have much time. We must report to Sir Heinrich about Himelmez's invasion.";
	cutin "gl_barmund2",2;
	next;
	select("Himelmez...");
	mes "[" + .@player_name$ + "]";
	mes "Who is Himelmez?";
	unittalk .@account_id, .@player_name$ + " : Who is Himelmez?";
	next;
	mes "[Varmundt]";
	mes "Herico didn't tell you?";
	npctalk "Varmundt: Herico didn't tell you?";
	cutin "gl_barmund3",2;
	next;
	mes "[Varmundt]";
	mes "She is the Ruler of Death, Dead man's Valkyrie. Himelmez is looking to take the heart of Ymir from us.";
	npctalk "Varmundt: She is the Ruler of Death, Dead man's Valkyrie. Himelmez is looking to take the heart of Ymir from us.";
	cutin "gl_barmund2",2;
	next;
	mes "[Varmundt]";
	mes "She might even destroy this whole castle if she wanted to.";
	npctalk "Varmundt: She might even destroy this whole castle if she wanted to.";
	next;
	mes "[Varmundt]";
	mes "Hurry! Report to Sir. Heinrich about Himelmez. I must check the defense barrier here!";
	npctalk "Varmundt: Hurry! Report to Sir. Heinrich about Himelmez. I must check the defense barrier here!";
	close2;
	cutin "",255;
	disablenpc instance_npcname("Varmundt#0_h");
	enablenpc instance_npcname("Heinrich#1_h");
	enablenpc instance_npcname("Varmundt#1_h");
	end;
}

1@gl_k2,145,104,6	script	Khalitzburg Knightage#1_h	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "My work shift will be over soon, but the next crew is not coming.";
	close;
}

1@gl_k2,154,104,3	script	Khalitzburg Knightage#2_h	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "Something you want to tell me?";
	close;
}

1@gl_k2,145,99,6	script	White Knight#3_h	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "Are you with Varmundt? Commander is waiting for you.";
	close;
}

1@gl_k2,154,99,3	duplicate(Khalitzburg Knightage#1_h)	White Knight#4_h	4_WHITEKNIGHT

1@gl_k2,145,94,6	script	Khalitzburg Knightage#5_h	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "I had a weird dream last night. My mom was in it... Wonder if she is ok...";
	close;
}

1@gl_k2,154,94,3	duplicate(White Knight#3_h)	Khalitzburg Knightage#6_h	4_F_KHALITZBURG

1@gl_k2,145,89,6	script	White Knight#7_h	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "Please do not make a mess here.";
	close;
}
1@gl_k2,154,89,3	duplicate(White Knight#7_h)	White Knight#8_h	4_WHITEKNIGHT

1@gl_k2,145,84,6	script	Khalitzburg Knightage#9_h	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "Orders please.";
	close;
}
1@gl_k2,154,84,3	duplicate(Khalitzburg Knightage#9_h)	Khalitzburg Knightage#10_h	4_F_KHALITZBURG

1@gl_k2,145,79,6	script	White Knight#11_h	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "How do you know Varmundt? I heard that he's not really a friendly man...";
	close;
}
1@gl_k2,154,79,3	duplicate(White Knight#11_h)	White Knight#12_h	4_WHITEKNIGHT

1@gl_k2,145,74,6	script	Khalitzburg Knightage#13_h	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "Doesn't this castle seem weird all of a sudden? Something's not quite right.";
	close;
}
1@gl_k2,154,74,3	duplicate(Khalitzburg Knightage#13_h)	Khalitzburg Knightage#14_h	4_F_KHALITZBURG

1@gl_k2,145,69,6	script	White Knight#15_h	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "I do not like to chat during work.";
	close;
}
1@gl_k2,154,69,3	duplicate(White Knight#15_h)	White Knight#16_h	4_WHITEKNIGHT

1@gl_k2,145,64,6	script	Khalitzburg Knightage#17_h	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "...";
	close;
}
1@gl_k2,154,64,3	duplicate(Khalitzburg Knightage#17_h)	Khalitzburg Knightage#18_h	4_F_KHALITZBURG

1@gl_k2,145,59,6	script	White Knight#19_h	4_WHITEKNIGHT,{
	mes "[White Knight]";
	mes "What can I do for you?";
	close;
}
1@gl_k2,154,59,3	duplicate(White Knight#19_h)	White Knight#20_h	4_WHITEKNIGHT

1@gl_k2,145,54,6	script	Khalitzburg Knightage#21_h	4_F_KHALITZBURG,{
	mes "[Khalitzburg Knightage]";
	mes "Is there something you need?";
	close;
}
1@gl_k2,154,54,3	duplicate(Khalitzburg Knightage#21_h)	Khalitzburg Knightage#22_h	4_F_KHALITZBURG

1@gl_k2,149,100,6	script	Heinrich#1_h	4_M_HEINRICH,{
	if (is_party_leader() == false) {
		mes "[Heinrich]";
		mes "Where is your leader? I must talk to him.";
		cutin "gl_heinrich2",2;
		close3;
	}
	.@account_id = getcharid(3);
	.@player_name$ = strcharinfo(0);
	cutin "gl_heinrich2",2;
	select("Sir Heinrich. Varmundt...");
	mes "[" + .@player_name$ + "]";
	mes "Sir Heinrich. Do you know what is happening in the castle now?";
	unittalk .@account_id, .@player_name$ + " : Sir Heinrich. Do you know what is happening in the castle now?";
	next;
	mes "[Heinrich]";
	mes "Aren't you the adventurer that came along with Varmundt?";
	npctalk "Heinrich: Aren't you the adventurer that came along with Varmundt?";
	next;
	mes "[Heinrich]";
	mes "What is it? Something wrong with the castle?";
	npctalk "Heinrich: What is it? Something wrong with the castle?";
	next;
	select("Himelmez's invasion...");
	mes "[" + .@player_name$ + "]";
	mes "Dead man's Valkyrie, Himelmez is coming to take the Ymir's Heart piece hidden inside this castle!";
	unittalk .@account_id, .@player_name$ + " : Dead man's Valkyrie, Himelmez is coming to take the Ymir's Heart piece hidden inside this castle!";
	next;
	mes "[Heinrich]";
	mes "Haha. Funny. Do you really think that is possible?";
	npctalk "Heinrich: Haha. Funny. Do you really think that is possible?";
	cutin "gl_heinrich1",2;
	next;
	mes "[Varmundt]";
	mes "I'm not kidding, Sir Heinrich. If I'm correct, then she will be here very soon.";
	npctalk "Varmundt: I'm not kidding, Sir Heinrich. If I'm correct, then she will be here very soon.", instance_npcname("Varmundt#1_h");
	cutin "gl_barmund2",2;
	next;
	mes "[Varmundt]";
	mes "We must hide the heart piece in a safe place before Himelmez's attack starts!";
	npctalk "Varmundt: We must hide the heart piece in a safe place before Himelmez's attack starts!", instance_npcname("Varmundt#1_h");
	next;
	select("Even if you don't believe me...");
	mes "[" + .@player_name$ + "]";
	mes "I can't make you believe me, but there's no time to argue!";
	unittalk .@account_id, .@player_name$ + " : I can't make you believe me, but there's no time to argue!";
	cutin "",255;
	next;
	mes "[Heinrich]";
	mes "Thank you for the help. But we don't even have our king with us right now.";
	npctalk "Heinrich: Thank you for the help. But we don't even have our king with us right now.";
	cutin "gl_heinrich1",2;
	next;
	mes "[Heinrich]";
	mes "We cannot risk moving the heart just because some stranger says so.";
	npctalk "Heinrich: We cannot risk moving the heart just because some stranger says so.";
	close2;
	disablenpc instance_npcname("Heinrich#1_h");
	enablenpc instance_npcname("Heinrich#2_h");
	enablenpc instance_npcname("Himelmez#1_h");
	donpcevent instance_npcname("#talkinstance1_h") + "::OnEnable";
	cutin "",255;
	end;
}

1@gl_k2,152,97,3	script	Varmundt#1_h	4_M_BARMUND,{ end; }
1@gl_k2,149,97,5	duplicate(Varmundt#1_h)	Heinrich#2_h	4_M_HEINRICH
1@gl_k2,149,100,5	duplicate(Varmundt#1_h)	Heinrich#3_h	4_M_HEINRICH
1@gl_k2,149,89,1	duplicate(Varmundt#1_h)	Himelmez#1_h	4_F_HIMEL

// Control Timer
//============================================================
1@gl_k2,1,1,0	script	#talkinstance1_h	HIDDEN_WARP_NPC,{
	end;
OnEnable:
	mapannounce 'map_name$[0], "????'s: Muahahahaha~!", bc_map,0xFFFF00,FW_NORMAL,18;
	initnpctimer;
	'npc_himelmez1$ = instance_npcname("Himelmez#1_h");
	'npc_varmundt1$ = instance_npcname("Varmundt#1_h");
	'npc_heinrich2$ = instance_npcname("Heinrich#2_h");
	'npc_heinrich3$ = instance_npcname("Heinrich#3_h");
	end;
OnTimer1500:
	npctalk "Heinrich: Who are you?", 'npc_heinrich2$;
	end;
OnTimer4500:
	npctalk "Himelmez: Well well~ Am I interrupting you? Weren't you expecting me?", 'npc_himelmez1$;
	end;
OnTimer10000:
	npctalk "Varmundt: Himelmez!! Already!", 'npc_varmundt1$;
	end;
OnTimer17500:
	npctalk "Himelmez: My name is Lisa Kahn Himelmez. Master of Dullahan, Dead man's Valkyrie, that's what they call me.", 'npc_himelmez1$;
	end;
OnTimer22000:
	npctalk "Heinrich: Aren't you a little too feminine to be the Ruler of death? We are not afraid of you...", 'npc_heinrich2$;
	end;
OnTimer28500:
	npctalk "Himelmez: Let's see if you can relax like that after you find out where your king is.", 'npc_himelmez1$;
	end;
OnTimer36000:
	npctalk "Heinrich: What?", 'npc_heinrich2$;
	end;
OnTimer41000:
	npctalk "Himelmez: Hmm, now I have your attention do I not?", 'npc_himelmez1$;
	end;
OnTimer47000:
	npctalk "Himelmez: You don't want the king's position, just wait for him to come back. I like your purity.", 'npc_himelmez1$;
	end;
OnTimer54000:
	npctalk "Himelmez: It's a pity to meet you in a situation like this.", 'npc_himelmez1$;
	end;
OnTimer59000:
	npctalk "Heinrich: My king is visiting the Rune-Midgarts royal family. He's not back yet.", 'npc_heinrich2$;
	end;
OnTimer66500:
	npctalk "Heinrich: And now you are trying to trick me, what has happened to him?!", 'npc_heinrich2$;
	end;
OnTimer71500:
	npctalk "Himelmez: Well~ I would love to sit down and explain for you, but I'm kind of busy today~", 'npc_himelmez1$;
	end;
OnTimer78000:
	npctalk "Himelmez: I have business to take care of. My minions will treat you well enough for me~", 'npc_himelmez1$;
	end;
OnTimer84500:
	npctalk "Heinrich: She probably already knows where the Ymir's heart piece is.", 'npc_heinrich2$;
	disablenpc 'npc_himelmez1$;
	end;
OnTimer90500:
	npctalk "Heinrich: All Khalitzburg and White Knights should follow me now...", 'npc_heinrich2$;
	end;
OnTimer92000:
	for (.@i = 1; .@i <= 20; .@i += 4) {
		hideonnpc instance_npcname("Khalitzburg Knightage#" + .@i + "_h");
		hideonnpc instance_npcname("Khalitzburg Knightage#" + (.@i+1) + "_h");
		hideonnpc instance_npcname("White Knight#" + (.@i+2) + "_h");
		hideonnpc instance_npcname("White Knight#" + (.@i+3) + "_h");
	}
	hideonnpc instance_npcname("Khalitzburg Knightage#21_h");
	hideonnpc instance_npcname("Khalitzburg Knightage#22_h");

	.@label$ = instance_npcname("#talkinstance1_h") + "::OnMyMobDead";
	monster 'map_name$[0],145,59,"Abysmal Knight",3145,1,.@label$;// MG_KNIGHT_OF_ABYSS
	monster 'map_name$[0],154,59,"Abysmal Knight",3145,1,.@label$;
	monster 'map_name$[0],145,69,"Abysmal Knight",3145,1,.@label$;
	monster 'map_name$[0],154,69,"Abysmal Knight",3145,1,.@label$;
	monster 'map_name$[0],145,79,"Abysmal Knight",3145,1,.@label$;
	monster 'map_name$[0],154,79,"Abysmal Knight",3145,1,.@label$;
	monster 'map_name$[0],145,89,"Abysmal Knight",3145,1,.@label$;
	monster 'map_name$[0],154,89,"Abysmal Knight",3145,1,.@label$;
	monster 'map_name$[0],145,99,"Abysmal Knight",3145,1,.@label$;
	monster 'map_name$[0],154,99,"Abysmal Knight",3145,1,.@label$;

	monster 'map_name$[0],145,54,"Khalitzburg",3146,1,.@label$;// G_MG_KHALITZBURG
	unittalk $@mobid[0],"Water... Someone give me water...";
	monster 'map_name$[0],154,54,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"Kkkrrrruughgh...";
	monster 'map_name$[0],145,64,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"Sir Heinrich. Save me...";
	monster 'map_name$[0],154,64,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"I miss my sister...";
	monster 'map_name$[0],145,74,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"Don't leave me alone, help me.";
	monster 'map_name$[0],154,74,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"Aaarrrrrhhhh";
	monster 'map_name$[0],145,84,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"I am so thirsty.";
	monster 'map_name$[0],154,84,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"Oh...No...I can't die yet...";
	monster 'map_name$[0],145,94,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"I feel sick to my stomach urrgg";
	monster 'map_name$[0],154,94,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"Can someone...";
	monster 'map_name$[0],145,104,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"Arrgg... My body";
	monster 'map_name$[0],154,104,"Khalitzburg",3146,1,.@label$;
	unittalk $@mobid[0],"My throat is burning!";
	end;
OnTimer94000:
	npctalk "Heinrich: My men... This can't be happening!", 'npc_heinrich2$;
	end;
OnTimer96500:
	npctalk "Varmundt: Sir Heinrich, they're all monsters. You need to give them rest!", 'npc_varmundt1$;
	end;
OnTimer100000:
	npctalk "Heinrich: I'm so sorry...", 'npc_heinrich2$;
	end;
OnTimer103000:
	npctalk "Heinrich: I am sorry, my knights! Forgive me!", 'npc_heinrich2$;
	end;
OnTimer106000:
	mapannounce 'map_name$[0], "Sir Heinrich: Death to all!", bc_map,0xFFFF33,FW_NORMAL,15;
	end;
OnTimer109000:
	mapannounce 'map_name$[0], "Sir Heinrich: Go back to the darkness!", bc_map,0xFFFF33,FW_NORMAL,15;
	end;
OnTimer109500:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#1_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#2_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#1_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#2_h");
	end;
OnTimer110000:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#3_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#4_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#5_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#6_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#3_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#4_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#5_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#6_h");
	end;
OnTimer110500:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#7_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#8_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#9_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#10_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#7_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#8_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#9_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#10_h");
	end;
OnTimer111000:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#11_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#12_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#13_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#14_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#11_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#12_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#13_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#14_h");
	end;
OnTimer111500:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#15_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#16_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#17_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#18_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#15_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#16_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#17_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#18_h");
	end;
OnTimer112000:
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#19_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("White Knight#20_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#21_h");
	specialeffect EF_GRANDCROSS,AREA, instance_npcname("Khalitzburg Knightage#22_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#19_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("White Knight#20_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#21_h");
	specialeffect EF_LEXAETERNA,AREA, instance_npcname("Khalitzburg Knightage#22_h");
	disablenpc 'npc_heinrich2$;
	enablenpc 'npc_heinrich3$;
	killmonster 'map_name$[0], instance_npcname("#talkinstance1_h") + "::OnMyMobDead";
	end;
OnTimer112500:
	npctalk "Heinrich: I killed my own men...", 'npc_heinrich3$;
	end;
OnTimer115500:
	npctalk "Varmundt: Sir Heinrich! We don't have much time!", 'npc_varmundt1$;
	end;
OnTimer118500:
	npctalk "Varmundt: If you hurry now, there's a chance!", 'npc_varmundt1$;
	end;
OnTimer121500:
	npctalk "Heinrich: Varmundt is right. Now is not the time for mourning.", 'npc_heinrich3$;
	end;
OnTimer124500:
	npctalk "Heinrich: I have a request to you followers.", 'npc_heinrich3$;
	end;
OnTimer127500:
	npctalk "Heinrich: Himelmez can turn living beings into monsters.", 'npc_heinrich3$;
	end;
OnTimer130500:
	npctalk "Heinrich: But, there might still be survivors here.", 'npc_heinrich3$;
	end;
OnTimer134500:
	npctalk "Heinrich: Destroy the monsters and find any survivors.", 'npc_heinrich3$;
	end;
OnTimer138500:
	npctalk "Heinrich: Varmundt and I will chase Himelmez.", 'npc_heinrich3$;
	end;
OnTimer143500:
	npctalk "Heinrich: Very well, Varmundt. Let's find Himelmez.", 'npc_heinrich3$;
	end;
OnTimer147500:
	disablenpc 'npc_heinrich3$;
	end;
OnTimer148500:
	stopnpctimer;
	donpcevent instance_npcname("#ghmemorialmob01_h") + "::OnStart";
	disablenpc 'npc_varmundt1$;
	disablenpc instance_npcname("#talkinstance1_h");
	'npc_himelmez1$ = 'npc_varmundt1$ = 'npc_heinrich2$ = 'npc_heinrich3$ = "";
	end;
OnMyMobDead:
	end;
}

// Sector 1 Mobs
//============================================================
1@gl_k2,1,1,0	script	#ghmemorialmob01_h	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob01_h");
	enablenpc instance_npcname("#2Control_h");
	enablenpc instance_npcname("#2Control2_h");
	mapannounce 'map_name$[0], "A portal has opened to the west.", bc_map,0xFFFF00;

	// note: x17 MG_GHOUL / x17 MG_ZOMBIE / x17 MG_WRAITH
	.@label$ = instance_npcname("#ghmemorialmob01_h") + "::OnMyMobDead";
	areamonster 'map_name$[0],76,99,87,10,"Grand Chamberlain in pain",3141,14,.@label$;
	areamonster 'map_name$[0],67,39,12, 6,"Corrupted Monk",3140,17,.@label$;
	areamonster 'map_name$[0],67,39,12, 6,"Grand Chamberlain in pain",3141,3,.@label$;
	areamonster 'map_name$[0],32,75,51,58,"Corrupted Steward",3139,5,.@label$;
	areamonster 'map_name$[0],45,84,6,137,"Corrupted Steward",3139,12,.@label$;
	end;
OnMyMobDead:
	.@label$ = instance_npcname("#ghmemorialmob01_h") + "::OnMyMobDead";
	.@mob_dead_num = 51 - mobcount('map_name$[0],.@label$);
	if (.@mob_dead_num > 35) {
		mapannounce 'map_name$[0], "Himelmez's curse is getting weaker. Find any survivors!", bc_map,0xFFFFFF;
		killmonster 'map_name$[0], .@label$;
		enablenpc instance_npcname("Altar boy Domun#1_h");
		disablenpc instance_npcname("#ghmemorialmob01_h");
	}
	end;
}

1@gl_k2,17,51,3	script	Altar boy Domun#1_h	4_M_KID1,{
	if (is_party_leader() == false) {
		mes "[Altar boy Domun]";
		mes "Save me, save me, please...";
		close;
	}
	.@account_id = getcharid(3);
	.@player_name$ = strcharinfo(0);
	mes "[Altar boy Domun]";
	mes "Save me! Save me!!!";
	npctalk "Save me! Save me!!!";
	next;
	select("Hold on! Are you the only survivor?");
	mes "[" + .@player_name$ + "]";
	mes "Hold on! Are you the only survivor?";
	unittalk .@account_id, .@player_name$ + " : Hold on! Are you the only survivor?";
	next;
	mes "[Altar boy Domun]";
	mes "Chamberlains... monks... They all turned into monsters. I couldn't do anything.";
	npctalk "Altar boy Domun: Chamberlains... monks... They all turned into monsters. I couldn't do anything.";
	next;
	mes "[Altar boy Domun]";
	mes "All I could do was... Just hide in here... Nothing, nothing I could do...";
	npctalk "Altar boy Domun: All I could do was... Just hide in here... Nothing, nothing I could do...";
	next;
	select("Pull it together!");
	mes "[" + .@player_name$ + "]";
	mes "Wake up kid! Go east and find the middle passage to the outside! It is safe there!";
	unittalk .@account_id, .@player_name$ + " : Wake up kid! Go east and find the middle passage to the outside! It is safe there!";
	next;
	mes "[Altar boy Domun]";
	mes "To the east passage? Alone? How?";
	npctalk "Altar boy Domun: To the east passage? Alone? How?";
	next;
	select("I will give you a weapon.");
	mes "[" + .@player_name$ + "]";
	mes "Here's a weapon. Just close your eye and swing for those monsters.";
	unittalk .@account_id, .@player_name$ + " : Here's a weapon. Just close your eye and swing for those monsters.";
	next;
	mes "[Altar boy Domun]";
	mes "Ok, I... I'll try.";
	npctalk "Altar boy Domun: Ok, I... I'll try.";
	disablenpc instance_npcname("Altar boy Domun#1_h");
	donpcevent instance_npcname("#ghmemorialmob02_h") + "::OnStart";
	close;
}

// Sector 2 Mobs
//============================================================
1@gl_k2,1,1,0	script	#ghmemorialmob02_h	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob02_h");
	enablenpc instance_npcname("#3Control_h");
	enablenpc instance_npcname("#3Control2_h");
	for ( .@i = 1; .@i <= 26; .@i++ )
		enablenpc instance_npcname("A dead man#" + .@i + "_h");
	mapannounce 'map_name$[0], "A portal has opened to the east.", bc_map,0xFFFF00;

	// note: x34 MG_ZOMBIE / x35 MG_GHOUL
	.@label$ = instance_npcname("#ghmemorialmob02_h") + "::OnMyMobDead";
	areamonster 'map_name$[0],236,12,288,52,"Outraged Refiner",3141,18,.@label$;// MG_GHOUL
	areamonster 'map_name$[0],236,12,288,52,"Decomposed Blacksmith",3139,17,.@label$;// MG_ZOMBIE
	areamonster 'map_name$[0],242,71,286,145,"Outraged Refiner",3141,17,.@label$;
	areamonster 'map_name$[0],242,71,286,145,"Decomposed Blacksmith",3139,17,.@label$;
	end;
OnMyMobDead:
	.@label$ = instance_npcname("#ghmemorialmob02_h") + "::OnMyMobDead";
	.@mob_dead_num = 69 - mobcount('map_name$[0],.@label$);
	if (.@mob_dead_num > 56) {
		mapannounce 'map_name$[0], "Himelmez's curse is getting weaker. Find any survivors!", bc_map,0xFFFFFF;
		killmonster 'map_name$[0],.@label$;
		enablenpc instance_npcname("Holgren the Destroyer#1_h");
		disablenpc instance_npcname("#ghmemorialmob02_h");
	}
	end;
}

1@gl_k2,291,145,3	script	Holgren the Destroyer#1_h	4_F_JOB_BLACKSMITH,{
	if (is_party_leader() == false) {
		mes "[Holgren the Destroyer]";
		mes "You human?";
		close;
	}
	.@account_id = getcharid(3);
	.@player_name$ = strcharinfo(0);
	mes "[Holgren the Destroyer]";
	mes "Die!! You shall die!!!";
	npctalk "Holgren the Destroyer: Die!! You shall die!!!";
	specialeffect EF_CRASHEARTH;
	next;
	select("Relax! I'm not a monster!");
	mes "[" + .@player_name$ + "]";
	mes "Relax! I am Human. Are you alone? Is anyone else here?";
	unittalk .@account_id, .@player_name$ + " : Relax! I am Human. Are you alone? Is anyone else here?";
	next;
	mes "[Holgren the Destroyer]";
	mes "It's only me.";
	npctalk "Holgren the Destroyer: It's only me.";
	next;
	select("It's dangerous here...");
	mes "[" + .@player_name$ + "]";
	mes "It's dangerous here. You know the way to the middle passage? Can you move?";
	unittalk .@account_id, .@player_name$ + " : It's dangerous here. You know the way to the middle passage? Can you move?";
	next;
	mes "[Holgren the Destroyer]";
	mes "Yes, I can move. I need to get out of here.";
	npctalk "Holgren the Destroyer: Yes, I can move. I need to get out of here.";
	next;
	select("Be safe...");
	mes "[" + .@player_name$ + "]";
	mes "Sorry, I can't go with you.";
	unittalk .@account_id, .@player_name$ + " : Sorry, I can't go with you.";
	next;
	mes "[Holgren the Destroyer]";
	mes "It's ok. You've already done enough. I can help myself. Good luck to you too.";
	npctalk "Holgren the Destroyer: It's ok. You've already done enough. I can help myself. Good luck to you too.";
	disablenpc instance_npcname("Holgren the Destroyer#1_h");
	donpcevent instance_npcname("#ghmemorialmob03_h") + "::OnEnable";
	close;
}

// Tramp Mobs
//============================================================
1@gl_k2,221,82,3	script	A dead man#1_h	4_M_DIEMAN,5,5,{
	end;
OnTouch_:
	.@i = rand(1,10);
	if (.@i == 1) .@mobs = 3;
	else if (.@i == 2) .@mobs = 4;
	else if (.@i == 3) .@mobs = 5;
	else if (.@i < 7) .@mobs = 6;
	else .@mobs = 7;
	getmapxy .@map$,.@x,.@y, BL_NPC;
	specialeffect EF_VENOMDUST;
	monster .@map$,.@x,.@y,"Maggot",3142,.@mobs;
	disablenpc instance_npcname( strnpcinfo(0) );
	end;
}
1@gl_k2,233,123,4	duplicate(A dead man#1_h)	A dead man#2_h	4_M_DIEMAN,5,5
1@gl_k2,258,150,2	duplicate(A dead man#1_h)	A dead man#3_h	4_M_DIEMAN,5,5
1@gl_k2,255,157,5	duplicate(A dead man#1_h)	A dead man#4_h	4_M_DIEMAN,5,5
1@gl_k2,280,167,4	duplicate(A dead man#1_h)	A dead man#5_h	4_M_DIEMAN,5,5
1@gl_k2,293,161,2	duplicate(A dead man#1_h)	A dead man#6_h	4_M_DIEMAN,5,5
1@gl_k2,249,101,3	duplicate(A dead man#1_h)	A dead man#7_h	4_M_DIEMAN,5,5
1@gl_k2,241,86,6	duplicate(A dead man#1_h)	A dead man#8_h	4_M_DIEMAN,5,5
1@gl_k2,246,62,0	duplicate(A dead man#1_h)	A dead man#9_h	4_M_DIEMAN,5,5
1@gl_k2,240,43,7	duplicate(A dead man#1_h)	A dead man#10_h	4_M_DIEMAN,5,5
1@gl_k2,271,19,1	duplicate(A dead man#1_h)	A dead man#11_h	4_M_DIEMAN,5,5
1@gl_k2,282,48,5	duplicate(A dead man#1_h)	A dead man#12_h	4_M_DIEMAN,5,5
1@gl_k2,285,81,7	duplicate(A dead man#1_h)	A dead man#13_h	4_M_DIEMAN,5,5
1@gl_k2,276,106,0	duplicate(A dead man#1_h)	A dead man#14_h	4_M_DIEMAN,5,5
1@gl_k2,261,164,0	duplicate(A dead man#1_h)	A dead man#15_h	4_M_DIEMAN,5,5
1@gl_k2,269,173,0	duplicate(A dead man#1_h)	A dead man#16_h	4_M_DIEMAN,5,5
1@gl_k2,252,120,0	duplicate(A dead man#1_h)	A dead man#17_h	4_M_DIEMAN,5,5
1@gl_k2,213,63,0	duplicate(A dead man#1_h)	A dead man#18_h	4_M_DIEMAN,5,5
1@gl_k2,222,39,0	duplicate(A dead man#1_h)	A dead man#19_h	4_M_DIEMAN,5,5
1@gl_k2,214,27,0	duplicate(A dead man#1_h)	A dead man#20_h	4_M_DIEMAN,5,5
1@gl_k2,223,17,1	duplicate(A dead man#1_h)	A dead man#21_h	4_M_DIEMAN,5,5
1@gl_k2,230,50,2	duplicate(A dead man#1_h)	A dead man#22_h	4_M_DIEMAN,5,5
1@gl_k2,235,16,3	duplicate(A dead man#1_h)	A dead man#23_h	4_M_DIEMAN,5,5
1@gl_k2,226,96,4	duplicate(A dead man#1_h)	A dead man#24_h	4_M_DIEMAN,5,5
1@gl_k2,222,119,5	duplicate(A dead man#1_h)	A dead man#25_h	4_M_DIEMAN,5,5
1@gl_k2,251,20,6	duplicate(A dead man#1_h)	A dead man#26_h	4_M_DIEMAN,5,5

// Sector 3 Mobs
//============================================================
1@gl_k2,1,1,0	script	#ghmemorialmob03_h	HIDDEN_WARP_NPC,{
	end;
OnEnable:
	enablenpc instance_npcname("#ghmemorialmob03_h");
	enablenpc instance_npcname("#4Control_h");
	enablenpc instance_npcname("#4Control2_h");
	mapannounce 'map_name$[0], "A portal has appeared to the northwest.", bc_map,0xFFFF00;

	// note: x50 MG_RAYDRIC / x50 MG_RAYDRIC_ARCHER
	.@label$ = instance_npcname("#ghmemorialmob03_h") + "::OnMyMobDead";
	areamonster 'map_name$[0],16,186,43,280,"Outraged Archer",3144,25,.@label$;
	areamonster 'map_name$[0],44,191,89,225,"Hungry Palace Guard",3143,25,.@label$;
	areamonster 'map_name$[0],115,215,188,273,"Corrupted Palace Guard",3143,20,.@label$;
	areamonster 'map_name$[0],108,232,193,281,"Corrupted Palace Guard",3143,5,.@label$;
	areamonster 'map_name$[0],158,236,230,250,"Wandering Archer",3144,12,.@label$;
	areamonster 'map_name$[0],65,231,155,256,"Wandering Archer",3144,13,.@label$;
	end;
OnMyMobDead:
	.@label$ = instance_npcname("#ghmemorialmob03_h") + "::OnMyMobDead";
	.@mob_dead_num = 100 - mobcount('map_name$[0],.@label$);
	if (.@mob_dead_num > 85) {
		killmonster 'map_name$[0],.@label$;
		enablenpc instance_npcname("#Mimelon_h");
		enablenpc instance_npcname("Himelmez#2_h");
		enablenpc instance_npcname("Varmundt#2_h");
		enablenpc instance_npcname("Heinrich#4_h");
		disablenpc instance_npcname("#ghmemorialmob03_h");
		mapannounce 'map_name$[0], "Himelmez: Not bad. Thought you would be dead by now by my creatures~", bc_map,0xFFFFFF;
		initnpctimer;
	}
	end;
OnTimer5000:
	mapannounce 'map_name$[0], "Himelmez: I'll wait for you at the north of the castle. I want to see how lucky you are.", bc_map,0xFFFFFF;
	stopnpctimer;
	end;
}

// 1st MVP
//============================================================
1@gl_k2,144,258,6	script	Heinrich#4_h	4_M_HEINRICH,{
	mes "[Heinrich]";
	mes "Himelmez... I will never forget what you've done to my men.";
	cutin "gl_heinrich1",2;
	close3;
}

// note: never hidden
1@gl_k2,156,258,3	script	Varmundt#2_h	4_M_BARMUND,{
	cutin "gl_barmund1",2;
	mes "[Varmundt]";
	if (checkquest(12336,HUNTING) != 2) {
		mes "I guess this is it. Is it impossible to stop the time traveler's will?!";
		mes "A portal seems to have appeared to the north.";
		close3;
	}
	erasequest 12336;
	if (isbegin_quest(12337) == 0)
		setquest 12337;// Amdarais Hunt
	if (isbegin_quest(12338) == 0) {
		setquest 12338;// Time Traveler
		completequest 12338;
		getexp 750000,750000;
	}
	mes "This item has an extraordinary aura with it. Can be very useful for someone special.";
	getitem 6607,1;// Temporal_Crystal
	getitem 6755,1;//= Contaminated Magic
	close3;
}

1@gl_k2,150,257,3	script	Himelmez#2_h	4_F_HIMEL,{
	cutin "gl_himel2",2;
	mes "[Himelmez]";
	mes "Don't look at me nervous like that. It will be over soon...";
	close3;
}

1@gl_k2,150,257,0	script	#Mimelon_h	HIDDEN_WARP_NPC,7,7,{
	end;
OnTouch_:
	disablenpc instance_npcname("#Mimelon_h");
	initnpctimer;
	'npc_himelmez2$ = instance_npcname("Himelmez#2_h");
	'npc_heinrich4$ = instance_npcname("Heinrich#4_h");
	end;
OnTimer3000:
	npctalk "Himelmez: Guess you are either lucky or powerful to make it this far.", 'npc_himelmez2$;
	end;
OnTimer6000:
	npctalk "Himelmez: But it doesn't matter.", 'npc_himelmez2$;
	end;
OnTimer9000:
	npctalk "Himelmez: You will all die here.", 'npc_himelmez2$;
	end;
OnTimer12000:
	npctalk "Heinrich: Himelmez! We will not let you get away from us!", 'npc_heinrich4$;
	end;
OnTimer15000:
	npctalk "Himelmez: Ha ha ha, worry about yourself. You think I am alone here?", 'npc_himelmez2$;
	end;
OnTimer18000:
	npctalk "Varmundt: Sir Heinrich! I sense something strange and strong coming!", instance_npcname("Varmundt#2_h");
	end;
OnTimer21000:
	npctalk "Heinrich: What... These are!", 'npc_heinrich4$;
	end;
OnTimer24000:
	npctalk "Himelmez: I will go on my way while my new toy entertains you.", 'npc_himelmez2$;
	end;
OnTimer27000:
	npctalk "Himelmez: Fare well~, hope to see you again sometime, Heinrich.", 'npc_himelmez2$;
	end;
OnTimer28000:
	disablenpc 'npc_himelmez2$;
	end;
OnTimer31000:
	npctalk "Heinrich: Sir Varmundt! Help those adventurers. I will go after Himelmez!", 'npc_heinrich4$;
	end;
OnTimer32000:
	disablenpc 'npc_heinrich4$;
	end;
OnTimer35000:
	mapannounce 'map_name$[0], "An echoing comes from deep inside of the knight's shrine.", bc_map,0xFFFFFF;
	end;
OnTimer38000:
	donpcevent instance_npcname("#ghmemorialmob04_h") + "::OnStart";
	stopnpctimer;
	'npc_himelmez2$ = 'npc_heinrich4$ = "";
	end;
}

1@gl_k2,1,1,0	script	#ghmemorialmob04_h	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob04_h");
	monster 'map_name$[0],150,259,"Corrupted Soul",3151,1, instance_npcname("#ghmemorialmob04_h") + "::OnMyMobDead";// MG_CORRUPTION_ROOT
	'boss_gid = $@mobid[0];
	unittalk $@mobid[0],"Grrrrrrhh~~~";
	initnpctimer;
	donpcevent instance_npcname(strnpcinfo(0)) + "::OnSummonUnit";
	end;
	
OnMyMobDead:
	if (mobcount('map_name$[0], instance_npcname("#ghmemorialmob04_h") + "::OnMyMobDead") < 1) {
		killmonster 'map_name$[0],instance_npcname(strnpcinfo(0)) + "::OnUnitDead";
		killmonster 'map_name$[0],instance_npcname(strnpcinfo(0)) + "::OnUnitDead2";
		mapannounce 'map_name$[0], "Opening 2nd floor entrance towards 12 O'clock direction.", bc_map,0xFFFF00;
		npctalk "Varmundt: I collected some items dropped from its body. You can take it from me.", instance_npcname("Varmundt#2_h");
		enablenpc instance_npcname("#2F Entrance_h");
		enablenpc instance_npcname("#1 Control_h");
		enablenpc instance_npcname("#Servanton_h");
		enablenpc instance_npcname("Heinrich#21_h");
		enablenpc instance_npcname("Varmundt#21_h");
		donpcevent instance_npcname("#ghmemorialmob05_h") + "::OnStart";
		disablenpc instance_npcname("#ghmemorialmob04_h");

	}
end;

OnSummonUnit:
	sleep 500;
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnUnitDead";
	setarray .@one,
	154,263,
	154,255,
	146,263,
	146,255;
	if(unitexists('boss_gid)){
		for(.@i = 0; .@i < getarraysize(.@one); .@i += 2){
			sleep 500;
			if(unitexists('boss_gid))
				monster 'map_name$[0],.@one[.@i],.@one[.@i+1],"",2536,1,.@event$;
		}
	}
	while(unitexists('boss_gid)){
		if(unitexists('boss_gid)){
			getunitdata 'boss_gid,.@boss_data;
			.@HP = .@boss_data[UMOB_HP];
			.@MAX_HP = .@boss_data[UMOB_MAXHP];
			.@trigger = (.@MAX_HP/10)*7;
		}
		if(.@HP <= .@trigger)
			break;
		sleep 1000;
	}
	killmonster 'map_name$[0],.@event$;
	.@event$ = instance_npcname(strnpcinfo(0)) + "::OnUnitDead2";
	setarray .@two,
	147,259,
	146,267,
	159,251,
	141,251,
	152,258,
	160,267,
	147,265,
	150,253,
	152,255,
	154,254,
	145,256,
	158,257;
	if(unitexists('boss_gid)){
		for(.@i = 0; .@i < getarraysize(.@two); .@i += 2){
			sleep 500;
			if(unitexists('boss_gid))
				monster 'map_name$[0],.@two[.@i],.@two[.@i+1],"",2536,1,.@event$;
		}
	}
OnUnitDead:
OnUnitDead2:
end;
}

// Floor 2
//============================================================
2@gl_k2,148,67,1	script	Heinrich#21_h	4_M_HEINRICH,{
	mes "[Heinrich]";
	mes "Himelmez's closed space covers everywhere...";
	cutin "gl_heinrich1",2;
	close3;
}

2@gl_k2,151,71,7	script	Varmundt#21_h	4_M_BARMUND,{
	mes "[Varmundt]";
	mes "How many times have I done this job? In my dream, I did it over and over again...";
	cutin "gl_barmund2",2;
	close3;
}

2@gl_k2,150,66,0	script	#Servanton_effect_h	HIDDEN_WARP_NPC,{
	end;
OnEffect:
	specialeffect EF_LORD;
	end;
}

// note: this part can be skipped
2@gl_k2,150,66,0	script	#Servanton_h	HIDDEN_WARP_NPC,7,7,{
	end;
OnTouch_:
	disablenpc instance_npcname("#Servanton_h");
	initnpctimer;
	'npc_heinrich$ = instance_npcname("Heinrich#21_h");
	'npc_varmundt$ = instance_npcname("Varmundt#21_h");
	end;
OnTimer3000:
	npctalk "Heinrich: This structure was not in the castle before!", 'npc_heinrich$;
	end;
OnTimer6000:
	npctalk "Varmundt: This is Himelmez's closed space. We blocked each area and aisle.", 'npc_varmundt$;
	end;
OnTimer9000:
	npctalk "Heinrich: We tried to break it down but it's really strong.", 'npc_heinrich$;
	end;
OnTimer12000:
	npctalk "Varmundt: Step back. Let me try to dispel the magic.", 'npc_varmundt$;
	end;
OnTimer15000:
	specialeffect EF_LORD,AREA, instance_npcname("#Servanton_effect_h");
	disablenpc instance_npcname("#Servanton_effect_h");
	end;
OnTimer18000:
	npctalk "Varmundt: I think that part of closed space is broken down.", 'npc_varmundt$;
	end;
OnTimer21000:
	npctalk "Varmundt: I have never seen this closed space.", 'npc_varmundt$;
	end;
OnTimer24000:
	npctalk "Varmundt: Himelmez hides stone chains in undead people's body.", 'npc_varmundt$;
	end;
OnTimer27000:
	npctalk "Varmundt: Maybe this closed space is maintained with these stone chains.", 'npc_varmundt$;
	end;
OnTimer30000:
	npctalk "Varmundt: If you want to break it, you have to kill one of those who have a stone chain.", 'npc_varmundt$;
	end;
OnTimer33000:
	npctalk "Varmundt: But we can't recognize who has a stone chain so we have to purify everything.", 'npc_varmundt$;
	end;
OnTimer36000:
	npctalk "Heinrich: It is inexcusable behavior.", 'npc_heinrich$;
	end;
OnTimer39000:
	npctalk "Heinrich: I already exterminated all my soldiers and maybe more...", 'npc_heinrich$;
	end;
OnTimer42000:
	npctalk "Varmundt: Commander...", 'npc_varmundt$;
	end;
OnTimer45000:
	npctalk "Varmundt: Commander! You need to be strong.", 'npc_varmundt$;
	end;
OnTimer48000:
	npctalk "Varmundt: Our enemy is not human.", 'npc_varmundt$;
	end;
OnTimer51000:
	npctalk "Varmundt: Even though you deny it, they'll never turn back to human.", 'npc_varmundt$;
	end;
OnTimer54000:
	npctalk "Heinrich: ...", 'npc_heinrich$;
	end;
OnTimer57000:
	npctalk "Varmundt: Well, let's go then.", 'npc_varmundt$;
	end;
OnTimer60000:
	npctalk "Varmundt: And you guys, just take a break and follow us.", 'npc_varmundt$;
	end;
OnTimer63000:
	npctalk "Varmundt: It could be hard fighting so stay strong.", 'npc_varmundt$;
	end;
OnTimer66000:
	npctalk "Varmundt: Ok, it's time to begin Heinrich.", 'npc_varmundt$;
	end;
OnTimer69000:
	mapannounce 'map_name$[1], "A portal to the west has opened in the central hallway.", bc_map,0xFFFF00;
	enablenpc instance_npcname("#22 Control_h");
	enablenpc instance_npcname("#22 Control2_h");
	disablenpc 'npc_varmundt$;
	disablenpc 'npc_heinrich$;
	stopnpctimer;
	'npc_varmundt$ = 'npc_heinrich$ = "";
	end;
}

// Spots
// Note: timer is the only condition for them to respawn

2@gl_k2,118,141,0	script	#ogh_2-1_h	HIDDEN_WARP_NPC,20,20,{
	end;
OnTouch_:
OnSpawn:
	disablenpc instance_npcname( strnpcinfo(0) );
	.@hidden_name$ = strnpcinfo(2);
	.@event_type = atoi( charat(.@hidden_name$,4) );
	if (.@event_type == 2)
		.@label$ = instance_npcname("#ghmemorialmob05_h") + "::OnMyMobDead";
	else
		.@label$ = instance_npcname("#ghmemorialmob06_h") + "::OnMyMobDead";
	getmapxy .@map$,.@x,.@y, BL_NPC;
	monster .@map$,.@x,.@y, "Corrupted Palace Guard", 3143,1, .@label$;
	monster .@map$,.@x,.@y, "Archer of Death", 3144,1, .@label$;
	monster .@map$,.@x,.@y, "Corrupted Abysmal Knight", 3145,1, .@label$;
	monster .@map$,.@x,.@y, "Suffered Khalitzburg", 3146,1, .@label$;
	monster .@map$,.@x,.@y, "Bloody Knight", 3147,1, .@label$;
	initnpctimer;
	end;
	
OnTimer30000:
	enablenpc instance_npcname( strnpcinfo(0) );
	stopnpctimer;
	end;
OnStop:
	disablenpc instance_npcname( strnpcinfo(0) );
	stopnpctimer;
	end;
}

2@gl_k2,128,81,0	duplicate(#ogh_2-1_h)	#ogh_2-2_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,131,54,0	duplicate(#ogh_2-1_h)	#ogh_2-3_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,89,48,0	duplicate(#ogh_2-1_h)	#ogh_2-4_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,64,117,0	duplicate(#ogh_2-1_h)	#ogh_2-5_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,62,82,0	duplicate(#ogh_2-1_h)	#ogh_2-6_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,38,138,0	duplicate(#ogh_2-1_h)	#ogh_2-7_h	HIDDEN_WARP_NPC,20,20

2@gl_k2,171,120,0	duplicate(#ogh_2-1_h)	#ogh_3-1_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,232,133,0	duplicate(#ogh_2-1_h)	#ogh_3-2_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,256,149,0	duplicate(#ogh_2-1_h)	#ogh_3-3_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,212,106,0	duplicate(#ogh_2-1_h)	#ogh_3-4_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,243,73,0	duplicate(#ogh_2-1_h)	#ogh_3-5_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,229,26,0	duplicate(#ogh_2-1_h)	#ogh_3-6_h	HIDDEN_WARP_NPC,20,20
2@gl_k2,181,34,0	duplicate(#ogh_2-1_h)	#ogh_3-7_h	HIDDEN_WARP_NPC,20,20

// Commander 1
2@gl_k2,1,1,0	script	#ghmemorialmob05_h	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob05_h");
	for ( .@i = 1; .@i <= 7; .@i++ )
		enablenpc instance_npcname("#ogh_2-" + .@i + "_h");
	end;

OnMyMobDead:
	if (rand(50) == 0) {// can re-spawn
		mapannounce 'map_name$[1], "Evil Forces are appearing in this area.", bc_map,0xFFFF44,FW_NORMAL,15;
		killmonster 'map_name$[1], instance_npcname("#ghmemorialmob05_h") + "::OnBossDead";
		.@r = rand(4) * 2;
		setarray .@coord[0], 41,146, 58,44, 122,148, 131,64;
		monster 'map_name$[1],.@coord[.@r],.@coord[.@r+1], "1st Commander of Destruction",3148,1, instance_npcname("#ghmemorialmob05_h") + "::OnBossDead";
		'ogh_com_h1 = 1;
	}
	end;

OnBossDead:
	mapannounce 'map_name$[1], "A portal has opened to the east in the central hallway.", bc_map,0xFFFF00;
	enablenpc instance_npcname("#23 Control_h");
	enablenpc instance_npcname("#23 Control2_h");
	donpcevent instance_npcname("#ghmemorialmob06_h") + "::OnStart";

	disablenpc instance_npcname("#ghmemorialmob05_h");
	for ( .@i = 1; .@i <= 7; .@i++ )
		donpcevent instance_npcname("#ogh_2-" + .@i + "_h") + "::OnStop";
	end;
}

// Commander 2
2@gl_k2,1,1,0	script	#ghmemorialmob06_h	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob06_h");
	for ( .@i = 1; .@i <= 7; .@i++ )
		enablenpc instance_npcname("#ogh_3-" + .@i + "_h");

	// Fix spawn
	.@label$ = instance_npcname("#ghmemorialmob06_h") + "::OnMyMobDead";
	monster 'map_name$[1],252, 75, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],253, 76, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],247, 77, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],248, 80, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],236,100, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],240,100, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],242,100, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],244,100, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],199,111, "Corrupted Palace Guard",3143,1, .@label$;
	monster 'map_name$[1],181,107, "Wandering Archer",3144,1, .@label$;
	monster 'map_name$[1],177,110, "Wandering Archer",3144,1, .@label$;
	monster 'map_name$[1],236, 27, "Wandering Archer",3144,1, .@label$;
	monster 'map_name$[1],242, 27, "Wandering Archer",3144,1, .@label$;
	monster 'map_name$[1],252, 26, "Wandering Archer",3144,1, .@label$;
	monster 'map_name$[1],172,130, "Wandering Archer",3144,1, .@label$;
	monster 'map_name$[1],171,127, "Wandering Archer",3144,1, .@label$;
	monster 'map_name$[1],173,127, "Wandering Archer",3144,1, .@label$;
	monster 'map_name$[1],177, 69, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],186, 66, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],189, 67, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],190, 68, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],257,157, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],246,159, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],237,158, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],206,159, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],172,120, "Corrupted Abysmal Knight",3145,1, .@label$;
	monster 'map_name$[1],226, 30, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],226, 38, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],228, 29, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],226, 63, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],268,137, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],263,138, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],259,138, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],259,138, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],187,121, "Suffered Khalitzburg",3146,1, .@label$;
	monster 'map_name$[1],265, 52, "Bloody Knight",3147,1, .@label$;
	monster 'map_name$[1],265, 55, "Bloody Knight",3147,1, .@label$; 
	monster 'map_name$[1],264, 79, "Bloody Knight",3147,1, .@label$; 
	monster 'map_name$[1],225, 92, "Bloody Knight",3147,1, .@label$; 
	monster 'map_name$[1],237, 92, "Bloody Knight",3147,1, .@label$; 
	monster 'map_name$[1],249, 92, "Bloody Knight",3147,1, .@label$; 
	monster 'map_name$[1],256, 93, "Bloody Knight",3147,1, .@label$; 
	monster 'map_name$[1],264,100, "Bloody Knight",3147,1, .@label$;
	monster 'map_name$[1],181,120, "Bloody Knight",3147,1, .@label$;
	end;

OnMyMobDead:
	if (rand(50) == 0) {// can re-spawn
		mapannounce 'map_name$[1], "An evil presence has teleported into this area.", bc_map,0xFFFF44,FW_NORMAL,15;
		killmonster 'map_name$[1], instance_npcname("#ghmemorialmob06_h") + "::OnBossDead";

		.@r = rand(4) * 2;
		setarray .@coord[0], 166,119, 211,45, 227,139, 245,74;
		monster 'map_name$[1],.@coord[.@r],.@coord[.@r+1], "2nd Commander of Destruction",3149,1, instance_npcname("#ghmemorialmob06_h") + "::OnBossDead";
		'ogh_com_h2 = 1;
	}
	end;

OnBossDead:
	mapannounce 'map_name$[1], "A new portal has appeared at the end of the central corridor.", bc_map,0xFFFF00;
	enablenpc instance_npcname("#24 Control_h");
	enablenpc instance_npcname("#24 Control2_h");
	enablenpc instance_npcname("#Geron_h");
	for ( .@i = 1; .@i <= 35; .@i++ )
		enablenpc instance_npcname("Decomposed body#" + .@i + "_h");

	disablenpc instance_npcname("#ghmemorialmob06_h");
	for ( .@i = 1; .@i <= 7; .@i++ )
		donpcevent instance_npcname("#ogh_3-" + .@i + "_h") + "::OnStop";

	// Hidden mobs
	setarray .@coord[0],
		 37,265, 57,265, 77,265, 97,265, 117,265, 188,264, 208,264,
		 50,172, 70,172, 90,172, 110,172, 170,172, 210,172, 230,172,
		 88,214, 108,214, 128,214, 180,219, 200,219, 220,219, 240,219;
	.@size = getarraysize(.@coord);
	for ( .@i = 0; .@i < .@size; .@i += 2 )
		monster 'map_name$[1], .@coord[.@i], .@coord[.@i+1], "Flame of destruction",2337,1;// HIDDEN_MOB
	end;
}

// Amdarais Room Entrance
2@gl_k2,150,180,0	script	#Geron_h	HIDDEN_WARP_NPC,7,7,{
	end;
OnTouch_:
	disablenpc instance_npcname("#Geron_h");
	mapannounce 'map_name$[1], "???: Do not come here! It's a trap... Kkkkah!!!", bc_map,0xFF7777,FW_NORMAL,15;
	enablenpc instance_npcname("Himelmez#22_h");
	enablenpc instance_npcname("Varmundt#23_h");
	enablenpc instance_npcname("Heinrich#23_h");
	enablenpc instance_npcname("Gerhalt#23_h");
	end;
}

2@gl_k2,143,260,4	script	Decomposed body#1_h	4_M_DIEMAN,5,5,{
	end;
OnTouch_:
	disablenpc instance_npcname( strnpcinfo(0) );
	.@i = rand(1,10);
	if (.@i == 1) .@mobs = 3;
	else if (.@i == 2) .@mobs = 4;
	else if (.@i == 3) .@mobs = 5;
	else if (.@i < 7) .@mobs = 6;
	else .@mobs = 7;
	getmapxy .@map$,.@x,.@y, BL_NPC;
	specialeffect EF_VENOMDUST;
	monster .@map$,.@x,.@y,"Maggot",3142,.@mobs;
	initnpctimer;
	end;
OnTimer45000:
	enablenpc instance_npcname( strnpcinfo(0) );
	stopnpctimer;
	end;
}
2@gl_k2,145,236,4	duplicate(Decomposed body#1_h)	Decomposed body#2_h	4_M_DIEMAN,5,5
2@gl_k2,141,222,2	duplicate(Decomposed body#1_h)	Decomposed body#3_h	4_M_DIEMAN,5,5
2@gl_k2,147,203,5	duplicate(Decomposed body#1_h)	Decomposed body#4_h	4_M_DIEMAN,5,5
2@gl_k2,167,225,4	duplicate(Decomposed body#1_h)	Decomposed body#5_h	4_M_DIEMAN,5,5
2@gl_k2,172,233,2	duplicate(Decomposed body#1_h)	Decomposed body#6_h	4_M_DIEMAN,5,5
2@gl_k2,176,244,3	duplicate(Decomposed body#1_h)	Decomposed body#7_h	4_M_DIEMAN,5,5
2@gl_k2,184,248,6	duplicate(Decomposed body#1_h)	Decomposed body#8_h	4_M_DIEMAN,5,5
2@gl_k2,193,228,0	duplicate(Decomposed body#1_h)	Decomposed body#9_h	4_M_DIEMAN,5,5
2@gl_k2,206,250,7	duplicate(Decomposed body#1_h)	Decomposed body#10_h	4_M_DIEMAN,5,5
2@gl_k2,130,249,1	duplicate(Decomposed body#1_h)	Decomposed body#11_h	4_M_DIEMAN,5,5
2@gl_k2,122,236,5	duplicate(Decomposed body#1_h)	Decomposed body#12_h	4_M_DIEMAN,5,5
2@gl_k2,130,228,7	duplicate(Decomposed body#1_h)	Decomposed body#13_h	4_M_DIEMAN,5,5
2@gl_k2,106,226,0	duplicate(Decomposed body#1_h)	Decomposed body#14_h	4_M_DIEMAN,5,5
2@gl_k2,104,245,0	duplicate(Decomposed body#1_h)	Decomposed body#15_h	4_M_DIEMAN,5,5
2@gl_k2,131,187,0	duplicate(Decomposed body#1_h)	Decomposed body#16_h	4_M_DIEMAN,5,5
2@gl_k2,121,197,0	duplicate(Decomposed body#1_h)	Decomposed body#17_h	4_M_DIEMAN,5,5
2@gl_k2,107,194,0	duplicate(Decomposed body#1_h)	Decomposed body#18_h	4_M_DIEMAN,5,5
2@gl_k2,92,187,0	duplicate(Decomposed body#1_h)	Decomposed body#19_h	4_M_DIEMAN,5,5
2@gl_k2,153,214,3	duplicate(Decomposed body#1_h)	Decomposed body#20_h	4_M_DIEMAN,5,5
2@gl_k2,155,195,4	duplicate(Decomposed body#1_h)	Decomposed body#21_h	4_M_DIEMAN,5,5
2@gl_k2,154,188,2	duplicate(Decomposed body#1_h)	Decomposed body#22_h	4_M_DIEMAN,5,5
2@gl_k2,143,195,5	duplicate(Decomposed body#1_h)	Decomposed body#23_h	4_M_DIEMAN,5,5
2@gl_k2,132,214,4	duplicate(Decomposed body#1_h)	Decomposed body#24_h	4_M_DIEMAN,5,5
2@gl_k2,125,208,2	duplicate(Decomposed body#1_h)	Decomposed body#25_h	4_M_DIEMAN,5,5
2@gl_k2,114,210,3	duplicate(Decomposed body#1_h)	Decomposed body#26_h	4_M_DIEMAN,5,5
2@gl_k2,137,182,6	duplicate(Decomposed body#1_h)	Decomposed body#27_h	4_M_DIEMAN,5,5
2@gl_k2,138,246,0	duplicate(Decomposed body#1_h)	Decomposed body#28_h	4_M_DIEMAN,5,5
2@gl_k2,132,260,7	duplicate(Decomposed body#1_h)	Decomposed body#29_h	4_M_DIEMAN,5,5
2@gl_k2,128,251,1	duplicate(Decomposed body#1_h)	Decomposed body#30_h	4_M_DIEMAN,5,5
2@gl_k2,179,260,3	duplicate(Decomposed body#1_h)	Decomposed body#31_h	4_M_DIEMAN,5,5
2@gl_k2,170,261,4	duplicate(Decomposed body#1_h)	Decomposed body#32_h	4_M_DIEMAN,5,5
2@gl_k2,177,219,2	duplicate(Decomposed body#1_h)	Decomposed body#33_h	4_M_DIEMAN,5,5
2@gl_k2,190,214,5	duplicate(Decomposed body#1_h)	Decomposed body#34_h	4_M_DIEMAN,5,5
2@gl_k2,201,214,4	duplicate(Decomposed body#1_h)	Decomposed body#35_h	4_M_DIEMAN,5,5

// Amdarais Spawn
2@gl_k2,153,250,8	script	Heinrich#23_h	4_M_HEINRICH,{
	cutin "gl_heinrich1",2;
	mes "[Heinrich]";
	mes "What are you putting on Himelmez!";
	close3;
}

2@gl_k2,162,250,1	script	Varmundt#23_h	4_M_BARMUND,{
	mes "[Varmundt]";
	mes "Can't take off this bridle...";
	cutin "gl_barmund2",2;
	close3;
}

2@gl_k2,158,255,1	script	Gerhalt#23_h	4_LEVITATEMAN,{
	mes "[Gerhalt]";
	mes "Uuuuu... Khhhah! Just run away with the commander.";
	close;
}

2@gl_k2,158,252,1	script	Himelmez#22_h	4_F_HIMEL,3,3,{
	cutin "gl_himel2",2;
	mes "[Himelmez]";
	mes "That is amazing ~ you made it all the way here. May I say thank you?";
	close3;

OnTouch:
	end;
OnTouch_:
	disablenpc instance_npcname("Himelmez#22_h");
	enablenpc instance_npcname("Himelmez#23_h");
	initnpctimer;
	'npc_himelmez$ = instance_npcname("Himelmez#23_h");
	'npc_gerhalt$ = instance_npcname("Gerhalt#23_h");
	'npc_heinrich$ = instance_npcname("Heinrich#23_h");
	'npc_varmundt$ = instance_npcname("Varmundt#23_h");
	end;
OnTimer3000:
	npctalk "Himelmez: Amazing~ I thought that you were not even close to getting here...", 'npc_himelmez$;
	end;
OnTimer6000:
	npctalk "Gerhalt: Kkkkah! Run away! I can't endure anymore!", 'npc_gerhalt$;
	end;
OnTimer9000:
	npctalk "Heinrich: Gerhalt!", 'npc_heinrich$;
	end;
OnTimer15000:
	npctalk "Heinrich: What are you doing to my soldier Himelmez!", 'npc_heinrich$;
	end;
OnTimer18000:
	npctalk "Himelmez: Hoo hoo, I already found a piece of Ymir's heart, Heinrich.", 'npc_himelmez$;
	end;
OnTimer21000:
	npctalk "Himelmez: If he did not bother me it would have been faster.", 'npc_himelmez$;
	end;
OnTimer24000:
	npctalk "Gerhalt: Commandant... Come on, you need to run away from here... Ugh.", 'npc_gerhalt$;
	end;
OnTimer27000:
	npctalk "Himelmez: Really? What makes you think so?", 'npc_himelmez$;
	end;
OnTimer30000:
	npctalk "Heinrich: Himelmez! You already made what you wanted so there is no more need for a sacrifice!", 'npc_heinrich$;
	end;
OnTimer33000:
	npctalk "Heinrich: Let him go! I don't need to see anyone else suffer!", 'npc_heinrich$;
	end;
OnTimer36000:
	npctalk "Himelmez: Let him go? I think... No...", 'npc_himelmez$;
	end;
OnTimer39000:
	npctalk "Himelmez: Besides, this is your last surviving soldier, Heinrich.", 'npc_himelmez$;
	end;
OnTimer42000:
	npctalk "Himelmez: He made life difficult for me.", 'npc_himelmez$;
	end;
OnTimer45000:
	npctalk "Himelmez: He is perfectly fit for my new creation Amdarais.", 'npc_himelmez$;
	end;
OnTimer48000:
	npctalk "Heinrich: I'll never forgive you.", 'npc_heinrich$;
	end;
OnTimer51000:
	npctalk "Himelmez: Uh uh~ I'm so scared.", 'npc_himelmez$;
	end;
OnTimer54000:
	npctalk "Himelmez: Anyway, we will have a chance to see because we need to talk more.", 'npc_himelmez$;
	end;
OnTimer57000:
	npctalk "Himelmez: So long boys.", 'npc_himelmez$;
	end;
OnTimer60000:
	specialeffect EF_BARRIER, AREA, 'npc_gerhalt$;
	end;
OnTimer63000:
	disablenpc 'npc_himelmez$;
	end;
OnTimer65000:
	npctalk "Gerhalt: You can make my body but you can't take my soul, Himelmez!", 'npc_gerhalt$;
	end;
OnTimer66000:
	specialeffect EF_CHAINCOMBO, AREA, 'npc_gerhalt$;
	end;
OnTimer67000:
	npctalk "Heinrich: I'll never let you get away Himelmez!!", 'npc_heinrich$;
	specialeffect EF_MAPPILLAR, AREA, 'npc_gerhalt$;
	end;
OnTimer70000:
	specialeffect EF_MAPPILLAR2, AREA, 'npc_gerhalt$;
	specialeffect EF_MAPPILLAR, AREA, 'npc_gerhalt$;
	disablenpc 'npc_heinrich$;
	npctalk "Varmundt: We have no choice. We have to fight against Amdarais!", 'npc_varmundt$;
	end;
OnTimer73000:
	mapannounce 'map_name$[1], "Gerhalt's body is changing.", bc_map,0xFFFFFF;
	end;
OnTimer76000:
	specialeffect EF_LORD, AREA, 'npc_gerhalt$;
	disablenpc 'npc_varmundt$;
	mapannounce 'map_name$[1], "Varmundt: Let me help this battle with my illusion. Just follow the illusion's orders.", bc_map,0xFFFF00;
	end;
OnTimer80000:
	disablenpc 'npc_gerhalt$;
	donpcevent instance_npcname("#ghmemorialmob07_h") + "::OnStart";
	stopnpctimer;
	'npc_himelmez$ = 'npc_gerhalt$ = 'npc_heinrich$ = 'npc_varmundt$ = "";
	end;
}

2@gl_k2,158,252,4	script	Himelmez#23_h	4_F_HIMEL,{
	cutin "gl_himel2",2;
	mes "[Himelmez]";
	mes "That is amazing ~ you made it all the way here. May I say thank you?";
	close3;
}

2@gl_k2,1,1,0	script	#ghmemorialmob07_h	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob07_h");
	monster 'map_name$[1],158,255,"Amdarais",3150,1,instance_npcname("#ghmemorialmob07_h") + "::OnMyMobDead";// MG_AMDARAIS
	'boss_id = $@mobid[0];
	unittalk 'boss_id, "Run away... run away from me...";
	donpcevent instance_npcname(strnpcinfo(0)) + "::OnSummonUnit";
	initnpctimer;
	end;

OnTimer5000:
	unittalk 'boss_id, "I don't want... I don't want to kill anyone. Uhuuuuuh";
	end;
OnTimer10000:
	unittalk 'boss_id, "Please kill me! Please!";
	end;
OnTimer16000:
	unittalk 'boss_id, "Eeeeee...eee...die... die...";
	end;
OnTimer22000:
	unittalk 'boss_id, "Demolition... Death!...";
	end;
OnTimer55000:
	donpcevent instance_npcname("#ghmemorialmob08_h") + "::OnStart";// Varmundt buffs and additionnal monsters
	stopnpctimer;
	end;
	
OnSummonUnit:
	sleep 5000;
	while(unitexists('boss_id)){
		if(unitexists('boss_id)){
			getunitdata 'boss_id,.@boss_data;
			.@HP = .@boss_data[UMOB_HP];
			.@MAX_HP = .@boss_data[UMOB_MAXHP];
			.@trigger = (.@MAX_HP/10)*7;
		}
		if(.@HP <= .@trigger)
			break;
		sleep 1000;
	}
	while(unitexists('boss_id)){
		getunitdata 'boss_id,.@boss_data;
		.@x = .@boss_data[UMOB_X];
		.@y = .@boss_data[UMOB_Y];
		.@event$ = instance_npcname(strnpcinfo(0)) + "::OnUnitDead";
		if(unitexists('boss_id)){
			monster 'map_name$[1],.@x + 5,.@y + 5,"",2495,1,.@event$;
			monster 'map_name$[1],.@x + 5,.@y - 5,"",2495,1,.@event$;
			monster 'map_name$[1],.@x - 5,.@y + 5,"",2495,1,.@event$;
			monster 'map_name$[1],.@x - 5,.@y - 5,"",2495,1,.@event$;
		}
		sleep 15000;
		killmonster 'map_name$[1],.@event$;
	}
OnUnitDead:
end;

OnMyMobDead:
	if (mobcount('map_name$[1], instance_npcname("#ghmemorialmob07_h") + "::OnMyMobDead") < 1) {
		stopnpctimer;
		.@event$ = instance_npcname(strnpcinfo(0)) + "::OnUnitDead";
		killmonster 'map_name$[1],.@event$;
		enablenpc instance_npcname("Hugin#21_h");
		enablenpc instance_npcname("#Secret Room Exit_h");

		stopnpctimer;
		disablenpc instance_npcname("#ghmemorialmob07_h");
		// note: monsters from #ghmemorialmob08_h still alive on Amdarais's dead
	}
	end;
}

// Varmundt Buffs
2@gl_k2,1,1,0	script	#ghmemorialmob08_h	HIDDEN_WARP_NPC,{
	end;
OnStart:
	enablenpc instance_npcname("#ghmemorialmob08_h");
	initnpctimer;
	end;
OnTimer5000:
	if (unitexists('boss_id) == 0) {
		disablenpc instance_npcname("#ghmemorialmob08_h");
		stopnpctimer;
		end;
	}
	getunitdata 'boss_id, .@data;
	.@percent_hp = (.@data[UMOB_HP] * 100) / .@data[UMOB_MAXHP];
	mapannounce 'map_name$[1], "Amdarais HP " + .@percent_hp + "% reach!", bc_map,0x70DBDB;

	// event type every 10%
	switch( .@percent_hp / 10 ) {
	case 10:
		break;
	case 9:
		donpcevent instance_npcname("Varmundt's Ghost#Buff2_h") + "::OnEvent";
		break;
	case 8:
		donpcevent instance_npcname("Varmundt's Ghost#Buff3_h") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Suffered Khalitzburg",3146,6, instance_npcname("#ghmemorialmob08_h") + "::OnMobDead";
		break;
	case 7:
		donpcevent instance_npcname("Varmundt's Ghost#Buff3_h") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Abysmal Knight",3145,6, instance_npcname("#ghmemorialmob08_h") + "::OnMobDead";
		break;
	case 6:
		donpcevent instance_npcname("Varmundt's Ghost#Buff3_h") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Bloody Knight",3147,6, instance_npcname("#ghmemorialmob08_h") + "::OnMobDead";
		break;
	case 5:
		donpcevent instance_npcname("Varmundt's Ghost#Buff2_h") + "::OnEvent";
		break;
	case 4:
		donpcevent instance_npcname("Varmundt's Ghost#Buff3_h") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Wandering Archer",3144,6, instance_npcname("#ghmemorialmob08_h") + "::OnMobDead";
		break;
	case 3:
		donpcevent instance_npcname("Varmundt's Ghost#Buff1_h") + "::OnEvent";
		donpcevent instance_npcname("Varmundt's Ghost#Buff3_h") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Bloody Knight",3147,6, instance_npcname("#ghmemorialmob08_h") + "::OnMobDead";
		break;
	case 2:
		donpcevent instance_npcname("Varmundt's Ghost#Buff1_h") + "::OnEvent";
		donpcevent instance_npcname("Varmundt's Ghost#Buff3_h") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Abysmal Knight",3145,6, instance_npcname("#ghmemorialmob08_h") + "::OnMobDead";
		break;
	case 1:
	case 0:
		donpcevent instance_npcname("Varmundt's Ghost#Buff1_h") + "::OnEvent";
		donpcevent instance_npcname("Varmundt's Ghost#Buff4_h") + "::OnEvent";
		areamonster 'map_name$[1],140,220,175,255,"Wandering Archer",3144,6, instance_npcname("#ghmemorialmob08_h") + "::OnMobDead";
		break;
	}
	end;
OnTimer30000:
	killmonster 'map_name$[1], instance_npcname("#ghmemorialmob08_h") + "::OnMobDead";
	initnpctimer;
	end;
OnMobDead:
	end;
}

2@gl_k2,150,247,5	script	Varmundt's Ghost#Buff1_h	4_M_BARMUND,2,2,{
	end;
OnTouch:
	specialeffect2 EF_ENHANCE;
	.@num$ = replacestr(strnpcinfo(2), "Buff", "");
	.@num = atoi(replacestr(.@num$, "_h", ""));
	if (.@num == 1)
		sc_start SC_GLASTHEIM_HIDDEN,30000,1,10000,SCSTART_NOTICKDEF;
	else if (.@num == 2)
		sc_start SC_GLASTHEIM_STATE,30000,1,10000,SCSTART_NOTICKDEF;
	else if (.@num == 3) {
		sc_start SC_GLASTHEIM_HEAL,30000,1,10000,SCSTART_NOTICKDEF;
		sc_start SC_GLASTHEIM_HPSP,30000,1,10000,SCSTART_NOTICKDEF;
	}
	else {
		sc_start SC_GLASTHEIM_DEF,30000,1,10000,SCSTART_NOTICKDEF;
		sc_start SC_GLASTHEIM_ITEMDEF,30000,1,10000,SCSTART_NOTICKDEF;
	}
	end;
OnEvent:
	initnpctimer;
	enablenpc instance_npcname( strnpcinfo(0) );
	.@num$ = replacestr(strnpcinfo(2), "Buff", "");
	.@num = atoi(replacestr(.@num$, "_h", ""));
	if (.@num == 1)
		npctalk "Varmundt's Ghost: Amdarais may use a strong magic shield! Stay close to me and I'll protect you!";
	else if (.@num == 2)
		npctalk "Varmundt's Ghost: Now's a chance to attack! Come closer to me and strike!";
	else if (.@num == 3)
		npctalk "Varmundt's Ghost: If you don't want to be attacked by Amdarais' zombie, come to me and get more power!";
	else
		npctalk "Varmundt's Ghost: If you don't want to be attacked by Amdarais's power, come to me and get more power!";
	end;
OnTimer10000:
	stopnpctimer;
	disablenpc instance_npcname( strnpcinfo(0) );
	end;
}
2@gl_k2,165,247,3	duplicate(Varmundt's Ghost#Buff1_h)	Varmundt's Ghost#Buff2_h	4_M_BARMUND,2,2
2@gl_k2,150,232,8	duplicate(Varmundt's Ghost#Buff1_h)	Varmundt's Ghost#Buff3_h	4_M_BARMUND,2,2
2@gl_k2,165,232,2	duplicate(Varmundt's Ghost#Buff1_h)	Varmundt's Ghost#Buff4_h	4_M_BARMUND,2,2


2@gl_k2,158,241,1	script	Hugin#21_h	4_M_SAGE_C,{
	if (checkquest(12337,HUNTING) == 2) {// note: complete hunting 'Corrupted Soul Hunt' prerequis
		mes "[Hugin]";
		mes "Hm, you are very well. First of all, let me give you some loot from Amdarais.";
		erasequest 12337;
		setquest 12335;// Space Distortion
		if (isbegin_quest(12339) == 0) {
			setquest 12339;// Time Conqueror
			completequest 12339;
			getitem 6607,5;// Temporal_Crystal
			getitem 6755,1;// Contaminated_Magic
			getexp 700000,700000;
		}
		else {
			getitem 6607,1;// Temporal_Crystal
			getitem 6755,1;// Contaminated_Magic
		}
		next;
		mes "[Hugin]";
		mes "Varmundt's time is stopped by me.";
		mes "And your time will be distorted soon.";
		specialeffect2 EF_BLIND;
		soundeffect "_blind.wav",0;
		next;
		mes "[Hugin]";
		mes "Maybe this poor time traveler will try to stop Glast Heim's tragedy from happening.";
		next;
		mes "[Hugin]";
		mes "However, we will never overlook his behavior now and forever...";
		next;
		mes "[Hugin]";
		mes "Now let me remove your memory. If you see me again it will be someone new.";
		specialeffect2 EF_FREEZE;
		close2;
		warp 'map_name$[1],158,244;
		end;
	}
	mes "[Hugin]";
	mes "Oops. I almost distorted the time gap. Come over here. We need to go out!";
	next;
	select("You were just with me...");
	mes "[Hugin]";
	mes "What did you say just before?";
	mes "Anyway, that is not important. The gap of time will be closed so we need to get out of here.";
	next;
	if (select("Let me look around more:Please let me out") == 1) {
		mes "[Hugin]";
		mes "Really? This place will be break down soon. Please look around quickly.";
		close;
	}
	close2;
	warp "glast_01",204,270;
	end;
}

// Treasure Room
//============================================================
1@gl_k2,165,136,3	script	Strange crack#2_h	CLEAR_NPC,{
	if (isbegin_quest(12322) == 0) {// Space Distortion
		mes "The crack looks suspicious but nothing more to check.";
		close;
	}
	specialeffect EF_SPELLBREAKER;
	.@random = rand(1,4);
	switch( atoi(strnpcinfo(2)) ) {
	case 2:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 719,1,"this",165,138;
		makeitem 6608,1,"this",165,138;
		break;
	case 3:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 720,1,"this",159,138;
		if (rand(1,4) == 4)
			makeitem2 15066,1,"this",159,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",159,138;
		makeitem 7229,1,"this",159,138;
		break;
	case 4:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 721,1,"this",153,138;
		if (rand(1,4) == 4)
			makeitem2 13086,1,"this",153,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",153,138;
		makeitem 7230,1,"this",153,138;
		break;
	case 5:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 722,1,"this",147,138;
		if (rand(1,4) == 4)
			makeitem2 2949,1,"this",147,138,0,0,0,0,0,0,0;
		makeitem 6612,1,"this",147,138;
		makeitem 6613,1,"this",147,138;
		makeitem 6608,1,"this",147,138;
		break;
	case 6:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 725,1,"this",141,138;
		makeitem 7228,1,"this",141,138;
		if (rand(1,4) == 4)
			makeitem2 13440,1,"this",141,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",141,138;
		break;
	case 7:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 726,1,"this",135,138;
		if (rand(1,4) == 4)
			makeitem2 2022,1,"this",135,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",135,138;
		break;
	case 8:
		for ( .@i = 1; .@i <= .@random; ++.@i )
			makeitem 727,1,"this",129,138;
		if (rand(1,4) == 4)
			makeitem2 21007,1,"this",129,138,0,0,0,0,0,0,0;
		makeitem 6608,1,"this",129,138;
		break;
	}
	disablenpc instance_npcname( strnpcinfo(0) );
	end;
}

1@gl_k2,159,136,3	duplicate(Strange crack#2_h)	Strange crack#3_h	CLEAR_NPC
1@gl_k2,153,136,3	duplicate(Strange crack#2_h)	Strange crack#4_h	CLEAR_NPC
1@gl_k2,147,136,3	duplicate(Strange crack#2_h)	Strange crack#5_h	CLEAR_NPC
1@gl_k2,141,136,3	duplicate(Strange crack#2_h)	Strange crack#6_h	CLEAR_NPC
1@gl_k2,135,136,3	duplicate(Strange crack#2_h)	Strange crack#7_h	CLEAR_NPC
1@gl_k2,129,136,3	duplicate(Strange crack#2_h)	Strange crack#8_h	CLEAR_NPC

1@gl_k2,269,267,3	script	Strange crack#1_h	CLEAR_NPC,{
	if (isbegin_quest(12322) == 0) {// Space Distortion
		mes "The crack looks suspicious but nothing more to check.";
		close;
	}
	warp 'map_name$[0],149,198;
	end;

OnInstanceInit:
	'map_name$[0] = instance_mapname("1@gl_k2");
	'map_name$[1] = instance_mapname("2@gl_k2");

	// Entrance
	disablenpc instance_npcname("Himelmez#1_h");
	disablenpc instance_npcname("Varmundt#1_h");
	disablenpc instance_npcname("Heinrich#1_h");
	disablenpc instance_npcname("Heinrich#2_h");
	disablenpc instance_npcname("Heinrich#3_h");

	// Rescue 1
	disablenpc instance_npcname("#ghmemorialmob01_h");
	disablenpc instance_npcname("Altar boy Domun#1_h");

	// Rescue 2
	disablenpc instance_npcname("#ghmemorialmob02_h");
	disablenpc instance_npcname("Holgren the Destroyer#1_h");
	for ( .@i = 1; .@i <= 26; .@i++ )
		disablenpc instance_npcname("A dead man#" + .@i + "_h");

	// Sector 3
	disablenpc instance_npcname("#ghmemorialmob03_h");

	// Root of Corruption
	disablenpc instance_npcname("Himelmez#2_h");
	disablenpc instance_npcname("Varmundt#2_h");
	disablenpc instance_npcname("Heinrich#4_h");
	disablenpc instance_npcname("#Mimelon_h");
	disablenpc instance_npcname("#ghmemorialmob04_h");

	// Entrance 2nd map
	disablenpc instance_npcname("Varmundt#21_h");
	disablenpc instance_npcname("Heinrich#21_h");
	disablenpc instance_npcname("#Servanton_h");
	hideonnpc instance_npcname("#Servanton_effect_h");

	// Commanders
	disablenpc instance_npcname("#ghmemorialmob05_h");
	disablenpc instance_npcname("#ghmemorialmob06_h");
	for ( .@i = 1; .@i <= 7; .@i++ ) {
		disablenpc instance_npcname("#ogh_2-" + .@i + "_h");
		disablenpc instance_npcname("#ogh_3-" + .@i + "_h");
	}

	// Amdarais Room Entrance
	disablenpc instance_npcname("#Geron_h");
	for ( .@i = 1; .@i <= 35; .@i++ )
		disablenpc instance_npcname("Decomposed body#" + .@i + "_h");

	// Amdarais Spawn
	disablenpc instance_npcname("Gerhalt#23_h");
	disablenpc instance_npcname("Himelmez#22_h");
	disablenpc instance_npcname("Himelmez#23_h");
	disablenpc instance_npcname("Varmundt#23_h");
	disablenpc instance_npcname("Heinrich#23_h");
	disablenpc instance_npcname("#ghmemorialmob07_h");

	// Varmundt Buffs
	disablenpc instance_npcname("#ghmemorialmob08_h");
	disablenpc instance_npcname("Varmundt's Ghost#Buff1_h");
	disablenpc instance_npcname("Varmundt's Ghost#Buff2_h");
	disablenpc instance_npcname("Varmundt's Ghost#Buff3_h");
	disablenpc instance_npcname("Varmundt's Ghost#Buff4_h");
	disablenpc instance_npcname("Hugin#21_h");

	// Warps
	disablenpc instance_npcname("#2Control_h");
	disablenpc instance_npcname("#2Control2_h");
	disablenpc instance_npcname("#3Control_h");
	disablenpc instance_npcname("#3Control2_h");
	disablenpc instance_npcname("#4Control_h");
	disablenpc instance_npcname("#4Control2_h");
	disablenpc instance_npcname("#2F Entrance_h");
	disablenpc instance_npcname("#1 Control_h");
	disablenpc instance_npcname("#22 Control_h");
	disablenpc instance_npcname("#22 Control2_h");
	disablenpc instance_npcname("#23 Control_h");
	disablenpc instance_npcname("#23 Control2_h");
	disablenpc instance_npcname("#24 Control_h");
	disablenpc instance_npcname("#24 Control2_h");
	disablenpc instance_npcname("#Secret Room Exit_h");
	end;
}
