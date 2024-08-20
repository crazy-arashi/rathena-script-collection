//===== Crazyarashi Services =====================================|
//= Edda Somatology                                              =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version (Combat Mode/Japanese)                   =|
//= 1.1 Added Exploration Mode (Swordsman,Thief,Merchant)        =|
//= 1.2 Added Exploration Mode (Archer,Mage,Acolyte)             =|
//= 1.3 English Translation                                      =|
//= 1.4 Combat Mode treasure [kRO]                               =|
//================================================================|

yuno,214,347,5	script	Nina#somatology_instance	4_DR_F_01,{
	mes "[ Nina ]";
	mes "Have you met Sierra yet?";
	mes "My name is Nina and I'm a reporter from the Rekenber Corporation.";
	next;
	npctalk "Sierra : Is that why you're always serious?","Nina#somatology_instance",bc_self;
	npctalk "Nina : Hold up there, don't bully me! There are only a few serious employees at Rekenber!","",bc_self;
	mes "[ Nina ]";
	mes "When a user is interpreting the Visual Record, they use their time synchronizing and refining. But simultaneously, we can also give the adventurers a chance to empower their equipment.";
	next;
	npctalk "Sierra : Well, wasn't it because of the Rekenber Laboratories that we've all suffered?","Nina#somatology_instance",bc_self;
	npctalk "Nina : They're not Rekenber's laboratories! And it was for the better too...","",bc_self;
	mes "[ Nina ]";
	mes "I'm a little busy preparing the Visual Record at the moment.";
	mes "Why don't you talk to Sierra first?";
	close;
}

yuno,216,345,3	script	Sierra#somatology_instance	4_F_SCIENCE,{
	if(BaseLevel < 170){
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "This place is too dangerous for you!";
		next;
		mes "^FF0000- You need to be at least level 170 to proceed on this quest. - ^000000";
		close3;
	}
	if(isbegin_quest(16388) == 0){
		if(isbegin_quest(16389) == 1){
			cutin "3rd_gn_demi01",2;
			mes "[ Sierra ]";
			mes "Have you changed your mind?";
			mes "Would you like to sign with us to participate in the Virtual Record interpretation?";
			next;
			cutin "",255;
			if(select("I'll sign the contract.:I can't. I'm sorry.") == 2){
				cutin "3rd_gn_demi02",2;
				mes "[ Sierra ]";
				mes "It's not a witches contract, so there's no danger.";
				next;
				cutin "",255;
				if(select("No, I can't.:What's a witch contract?") == 1){
					cutin "3rd_gn_demi01",2;
					mes "[ Sierra ]";
					mes "I think you can do it!";
				} else {
					cutin "3rd_gn_demi01",2;
					mes "[ Sierra ]";
					mes "It means it's a very dangerous contract.";
				}
				mes "If you change your mind and want to apply for the Virtual Record Interpretation, You know where to find me. Please let me know.";
				close3;
			}
			goto OnContract;
		}
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "Greetings, my name is Sierra, Sierra Morris.";
		mes "You must be the famous " + strcharinfo(0) + ", I've heard so much about you.";
		next;
		mes "[ Sierra ]";
		mes "The one over here is Nina.";
		mes "She's a reporter from Rekenber.";
		npctalk "Nina : Hello, nice to meet you!","Nina#somatology_instance",bc_self;
		next;
		cutin "",255;
		select("Do you know me?");
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "Of course. I'm a researcher for the ^0000CDSecret Wing^000000.";
		mes "You've worked with Lazy and Philifontes before, didn't you?";
		npctalk "Sierra : I'm pretty sure, " + ((Sex)?"He":"She") + " had a hard time working with these agents.","",bc_self;
		next;
		mes "[ Sierra ]";
		mes "Both of them are professional agents.";
		mes "But, when I told them I was looking for a collaborator, they both recommended you!";
		next;
		mes "[ Sierra ]";
		mes "I'm glad to have such person come here.";
		mes "Let met explain my request.";
		next;
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "We are currently cooperating with several companies to find common enemies.";
		mes "Such as those who have done ^0000CDillegal experiments on human at Regenschirm^000000.";
		next;
		mes "[ Sierra ]";
		mes "It would never cross my mind before to have companies, rivals and goverments join forces to fight together.";
		mes "Thankfully, times are slowly changing.";
		next;
		mes "[ Sierra ]";
		mes strcharinfo(0) + ",you've had a big impact on this changes.";
		mes "I have a big respect for as a member of the Secret Wing.";
		next;
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "We've been investigating illegal research facilities thanks to the cooperation of the companies.";
		mes "Along the way, we discovered something new at the ^0000CDSomatology Laboratory^000000 in Lighthalzen.";
		next;
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "In the Somatology Laboratory, there is a hidden basement that is completely buried and made inaccessible.";
		next;
		mes "[ Sierra ]";
		mes "At the same time, an adventurer who was exploring the somatology discovered ^FF0000this^000000.";
		next;
		cutin "",255;
		select("What is it?");
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "It hasn't been officially named yet.";
		mes "The investigation team temporary named it as ^0000CDVirtual Record^000000.";
		next;
		cutin "",255;
		select("Virtual Record?:The name is not familiar.");
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes strcharinfo(0) + ". No one can get information about Virtual Records. I have to think how to get it.";
		next;
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "But of course, I'll give you as much information as I can.";
		npctalk "Sierra : That's information that can't be given out easily.","",bc_self;
		npctalk "Nina : The legal team is not very happy. Are we going to get screwed if we do it wrong?","Nina#somatology_instance",bc_self;
		next;
		mes "[ Sierra ]";
		mes "Since the Virtual Records were discovered in the Somatology Laboratory, I've been thinking that other ^FF0000forbidden technologies^000000 must also be in there too.";
		next;
		cutin "",255;
		select("What kind of technology is it?");
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "Those who weren't hesitant to experiment and use ^0000CDhuman memories, bodies and souls^000000 as a medium.";
		next;
		mes "[ Sierra ]";
		mes "But even the results of such experiments can be used to reveal the ^FF0000truth^000000.";
		next;
		cutin "",255;
		select("Truth?");
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "The truth about the creatures that exist in the Somatology Laboratory.";
		next;
		mes "[ Sierra ]";
		mes "This record contains data of the ^0000CDMidgard Unofficial Expedition^000000, including ^0000CDSeyren Windsor's data^000000.";
		next;
		mes "[ Sierra ]";
		mes "You can put it in an analysis device and play it in virtual reality to solve the unknowns.";
		next;
		cutin "",255;
		select("If you say so.");
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "We can finally find out the truth about about why the Midgard Unofficial Expedition was abandoned in the Somatology Laboratory.";
		next;
		mes "[ Sierra ]";
		mes "The royal families of Midgard also asked for the investigation for it.";
		next;
		cutin "",255;
		select("What do I have to do?");
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "If you interpret memories through virtual reality, you will be in the same situation as they did.";
		next;
		mes "[ Sierra ]";
		mes "The consequences of the dangers they suffered were those ^FF0000countless creatures^000000 of the Somatology.";
		mes "Some agents have tried it, but they all gave up.";
		next;
		cutin "",255;
		mes "[ Nina ]";
		mes "I did a little tweak on the finished part of the records. But If I tweak too much, it might also change the truth.";
		next;
		select("I see, you need someone to take the risk.");
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "Exactly.";
		mes "Virtual Records with high synchronization rates are very dangerous for an average person.";
		next;
		mes "[ Sierra ]";
		mes "I believe that you, " + strcharinfo(0) +",";
		mes "Who is very experienced with battles, would be able to interpret it until the end.";
		next;
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "Of course, I'm not entirely relying on " + strcharinfo(0) + "'s good will.";
		mes "The experience gained from the Virtual Records will help you in your future adventures!";
		next;
		cutin "",255;
		mes "[ Nina ]";
		mes "Indeed, since I've adjusted the synchronization rate, I can't get as much as I want by interpreting just once.";
		next;
		mes "[ Nina ]";
		mes "By doing it multiple times, you can get the interpretation data to our side.";
		mes "When the research is over, I'll give you something as a reward.";
		next;
		mes "[ Nina ]";
		mes "You'll be compensated with the latest equipment made exclusively by the Rekenber technologies! I'll also customize it for you!";
		next;
		if(select("Join.:Do not join.") == 2){
			mes "[ Sierra ]";
			mes "You seemed to lack information gathering interest.";
			mes "We'll need to find others who are as good as you are. It won't be easy though.";
			setquest 16389;
		} else {
		OnContract:
			cutin "3rd_gn_demi01",2;
			mes "[ Sierra ]";
			mes "All right. Then please sign this agreement.";
			next;
			cutin "",255;
			select("Aren't the letters too small?!");
			cutin "3rd_gn_demi02",2;
			mes "[ Sierra ]";
			mes "Just sign here and here.";
			mes "^FF0000Do you drink or smoke? Your body is healthy, right?^000000";
			next;
			cutin "",255;
			select("I'm scared, I'm not signing!");
			npctalk "Nina : I'm starting to doubt Sierra, maybe she is an illegal scientist at Regenschirm.","Nina#somatology_instance",bc_self;
			npctalk "Sierra : What?!","",bc_self;
			cutin "3rd_gn_demi01",2;
			mes "[ Sierra ]";
			mes "I'm just kidding.";
			mes "Please come again and I'll explain about the interpretation of the Virtual Record.";
			if(isbegin_quest(16389) == 1)
				completequest 16389;
			setquest 16388;
			close2;
			cutin "",255;
		}
		end;
	}
	switch(checkquest(16390,PLAYTIME)){
		case -1:
			break;
			
		case 0:
		case 1:
			cutin "3rd_gn_demi01",2;
			mes "[ Sierra ]";
			mes "You're back. Do you want to a virtual record interpretation again?";
			next;
			cutin "",255;
			mes "[ Nina ]";
			mes "Oh! Wait a minute! It's been less than a day since you used the virtual record interpretation.";
			mes "If you try to interpret while you still have the after effects, you'll experience some bad side effects.";
			npctalk "Nina : Dizziness, nausea, headache, body weakening, death, super thoughtfulness, toothache, depression, and so on...","Nina#somatology_instance",bc_self;
			npctalk "Sierra : Isn't there something wrong in the middle?","",bc_self;
			next;
			mes "[ Nina ]";
			mes "Please come back after you recover for ^0000CDone day^000000!";
			end;
			
		case 2:
			cutin "3rd_gn_demi01",2;
			mes "[ Sierra ]";
			mes "It seems you're good to go!";
			mes "Talk to me again to start the virtualization.";
			erasequest 16390;
			close3;
	}
	npctalk "Nina : Ugh, I'll take care of you!","Nina#somatology_instance",bc_self;
	cutin "3rd_gn_demi01",2;
	mes "[ Sierra ]";
	mes "Proceed with the Virtual Record synchronization. After the synchronization is complete, please speak to me again to begin the interpretation.";
	next;
	cutin "",255;
	if(select("Synchronize Virtual Record:Listen to explanation") == 2){
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "Exploration Mode lets you interpret the events of the expedition.";
		mes "On the other hand, Combat Mode will let you interpret the battle that the expedition has experienced.";
		next;
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "Combat mode is more dangerous and the rewards are better.";
		mes "Exploration mode is long and the battle is short. ^0000CDExploration Mode has less rewards.^000000";
		close3;
	}
	.@party_id = getcharid(1);
	.@party_name$ = getpartyname(.@party_id);
	.@md_name$ = "Journey of Expedition";
	.@instance_name$ = instance_live_info(ILI_NAME,instance_id());
	if(!.@party_id){
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "Please come with a party, adventurer.";
		mes "Even if you're exploring on our own, it's necessary to contact me and Nina.";
		close3;
	}
	if(instance_live_info(ILI_NAME, instance_id(IM_PARTY)) == .@md_name$){
		mes "[ Sierra ]";
		mes "Proceed with the Virtual Record synchronization. Please speak to me to begin the interpretation.";
		next;
		if(select("Start Analysis.:Explanation") == 2){
			mes "[ Nina ]";
			mes "There were other adventurers who tried before you and gave up.";
			mes "Some people were actually traumatized and some got injured from the injuries they suffered in the Virtual Record.";
			next;
			mes "[ Nina ]";
			mes "In order to prevent that from happening, I divided the Virtual Record into two modes.";
			npctalk "Nina : That way, you can decide the way you want to interpret it!","Nina#somatology_instance",bc_self;
			npctalk "Sierra : That's extra hassle for me though!","",bc_self;
			next;
			mes "[ Nina ]";
			mes "In ^0000CDExploration Mode^000000, the combat difficulty is greatly reduced.";
			mes "We were more focused on what the expedition was talking about and what was going on.";
			npctalk "Nina : It takes time, so please prepare beforehand.","Nina#somatology_instance",bc_self;
			next;
			mes "[ Nina ]";
			mes "You can only participate once a day for both modes to not stress out your body.";
			mes "^FF0000The rewards for the Exploration Mode are very small^000000.";
			mes "In Combat Mode, It's much dangerous but also better rewards.";
			npctalk "Nina : As you go through various battles, you can into an unprecedented danger.","Nina#somatology_instance",bc_self;
			npctalk "Sierra : Well that's a well known risk. Are you not familiar with adventurers?","",bc_self;
			next;
			mes "[ Nina ]";
			mes "Since the two modes have different characteristics, please talk with your party members to decide which mode to synchronize with.";
			mes "^FF0000The mode cannot be changed once synchronized.^000000";
			end;
		}
		.@type = getvariableofinstance('type, instance_id(IM_PARTY));
		if(.@type){
			.@mode$ = "Battle";
			if(isbegin_quest(16400) == 0)
				setquest 16400;
			if(isbegin_quest(16399) > 0)
				erasequest 16399;
		} else {
			.@mode$ = "Exploration";
			if(isbegin_quest(16399) == 0)
				setquest 16399;
			if(isbegin_quest(16400) > 0)
				erasequest 16400;
		}
		mes "[ Sierra ]";
		mes "Synchronization of " + .@mode$ + " Mode has been completed.";
		next;
		mes "[ Sierra ]";
		mes "All right! Now I need to check the stability...";
		mes "Okay, that's about it! Let's start the virtualization!";
		close2;
		switch(instance_enter(.@md_name$)){
			case 3:
				mes "An unknown error has occurred.";
				end;
				
			case 2:
			case 1:
				mes "^ff0000Character doesn't have an instance reserved.^000000";
				end;
				
			case 0:
				mapannounce "yuno", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00FF99";
				if(isbegin_quest(16391) > 0)
					erasequest 16391;
				if(isbegin_quest(16392) > 0)
					erasequest 16392;
				setquest 16390;
				end;
		}
	}
	cutin "3rd_gn_demi01",2;
	mes "[ Sierra ]";
	mes "Please select the mode.";
	mes "In which mode should I synchronize the Virtual Record with?";
	next;
	cutin "",255;
	switch(select((!instance_id(IM_PARTY) && is_party_leader()?"Create Exploration Mode.":""),(!instance_id(IM_PARTY) && is_party_leader()?"Create Combat Mode.":""),"Explanation")){
		case 1:
			mes "[ Nina ]";
			mes "Alright! The synchronization for the Exploration Mode is in progress!";
			mes "When the synchronization is complete, ^0000CDyou can talk to Sierra and start interpreting it!^000000";
			if(isbegin_quest(16399) == 0)
				setquest 16399;
			if(isbegin_quest(16400) > 0)
				erasequest 16400;
			instance_create(.@md_name$);
			end;
			
		case 2:
			mes "[ Nina ]";
			mes "Alright! The synchronization for the Combat Mode is in progress!";
			mes "When the synchronization is complete, ^0000CDyou can talk to Sierra and start interpreting it!^000000";
			if(isbegin_quest(16400) == 0)
				setquest 16400;
			if(isbegin_quest(16399) > 0)
				erasequest 16399;
			instance_create(.@md_name$);
			set getvariableofinstance('type, instance_id(IM_PARTY)),1;
			end;
			
		case 3:
			mes "[ Nina ]";
			mes "There were other adventurers who tried before you and gave up.";
			mes "Some people were actually traumatized and some got injured from the injuries they suffered in the Virtual Record.";
			next;
			mes "[ Nina ]";
			mes "In order to prevent that from happening, I divided the Virtual Record into two modes.";
			npctalk "Nina : That way, you can decide the way you want to interpret it!","Nina#somatology_instance",bc_self;
			npctalk "Sierra : That's extra hassle for me though!","",bc_self;
			next;
			mes "[ Nina ]";
			mes "In ^0000CDExploration Mode^000000, the combat difficulty is greatly reduced.";
			mes "We were more focused on what the expedition was talking about and what was going on.";
			npctalk "Nina : It takes time, so please prepare beforehand.","Nina#somatology_instance",bc_self;
			next;
			mes "[ Nina ]";
			mes "You can only participate once a day for both modes to not stress out your body.";
			mes "^FF0000The rewards for the Exploration Mode are very small^000000.";
			mes "In Combat Mode, It's much dangerous but also better rewards.";
			npctalk "Nina : As you go through various battles, you can into an unprecedented danger.","Nina#somatology_instance",bc_self;
			npctalk "Sierra : Well that's a well known risk. Are you not familiar with adventurers?","",bc_self;
			next;
			mes "[ Nina ]";
			mes "Since the two modes have different characteristics, please talk with your party members to decide which mode to synchronize with.";
			mes "^FF0000The mode cannot be changed once synchronized.^000000";
			end;
	}
}

yuno,220,353,3	script	Ravian#rgsr_lab_enchant	4_DR_F_02,{
	function weapon_check;
	.@equip_id = getequipid(EQI_HAND_R);
	.@bool = weapon_check(.@equip_id);
	if(!.@bool){
		mes "[ Ravian ]";
		mes "Hello~ Is there something that interests you?";
		next;
		select("Can you empower my weapon?");
		mes "[ Ravian ]";
		mes "It's not that I don't want to, but. I can't do anything with your weapon right now.";
		next;
		mes "[ Ravian ]";
		mes "If you found a weapon in the Somatology, visit me again~";
		next;
		if(select("What weapon are you referring to?:What's the cost?") == 1){
			for(.@i = 0; .@i < getarraysize(.weapon_list); .@i++){
				mes "<ITEM>" + getitemname(.weapon_list[.@i]) + "<INFO>" + .weapon_list[.@i] + "</INFO></ITEM>";
				.@n++;
				if(.@n == 6){
					.@n = 0;
					next;
				}
			}
		} else {
			mes "[ Ravian ]";
			mes "I will tell you a story.";
			mes "I will speak slowly because this is my favorite.";
			next;
			mes "[ Ravian ]";
			mes "All weapons that can be empower will benefit from its 3rd and 4th slot. The slots price is the same.";
			next;
			mes "[ Ravian ]";
			mes "I actually don't need your Zeny. I need the items that you can find while inside the Somatology.";
			next;
			mes "[ Ravian ]";
			mes "I'll need these two items from the Somatology to reinforce weapons.";
			mes "<ITEM>Somatology Research Document<INFO>25786</INFO></ITEM>";
			mes "<ITEM>Somatology Experimental Fragment<INFO>25787</INFO></ITEM>";
			next;
			mes "[ Ravian ]";
			mes "The cost varies depending of the type of enchant.";
			mes "What type of enchant do you want to take a look at?";
			next;
			switch(select("General Enchant:Advanced Enchant:Specific Enchant")){
				case 1:
					setarray .@cost,25786,50,25787,50;
					break;
					
				case 2:
					setarray .@cost,25786,500,25787,500;
					break;
					
				case 3:
					setarray .@cost,25786,5000;
					break;
			}
			mes "[ Ravian ]";
			mes "Before anything, let me tell you the cost of the enchant~";
			for(.@i = 0; .@i < getarraysize(.@cost); .@i += 2)
				mes "<ITEM>"+getitemname(.@cost[.@i])+"<INFO>"+.@cost[.@i]+"</INFO></ITEM> x " + .@cost[.@i+1];
			mes "This costs quite a lot. Here's the quality of the enchant service you can get.";
			next;
			switch(.@s){
				case 1:
					mes "[ Ravian ]";
					mes "The general enchant has a ^0000CD35% chance of failure for the 4th slot.^000000 And ^FF0000There is a 5% chance of the weapon being destroyed^000000 in the process.";
					next;
					mes "[ Ravian ]";
					mes "For the 3rd slot, it has a ^0000CD70% chance of failure^000000 and ^FF0000a 5% chance of the weapon being destroyed^000000 in the process.";
					next;
					mes "[ Ravian ]";
					mes "The enchants are the same regardless of the enchant method you use.";
					mes "The 3rd slot has a very high destruction rate. It's not recommended to enchant it using this type~";
					next;
					break;
					
				case 2:
					mes "[ Ravian ]";
					mes "The advanced enchant has a ^0000CD10% chance of failure for the 4th slot.^000000 And no chance of the weapon being destroyed in the process.";
					next;
					mes "[ Ravian ]";
					mes "For the 3rd slot, it has a ^0000CD30% chance of failure^000000. Of course, because of the high cost, there is not chance that the weapon is going to be destroyed.";
					next;
					mes "[ Ravian ]";
					mes "If you want to enchant the 3rd slot securely and at a low cost, this option may be your choice.";
					next;
					break;
					
				case 3:
					mes "[ Ravian ]";
					mes "The determined enchant has a ^0000CD100% chance of success.^000000 You can also choose the effect you want there!";
					next;
					mes "[ Ravian ]";
					mes "This option is only available for the 3rd slot though.";
					next;
					break;
			}
			mes "[ Ravian ]";
			mes "If you have any questions, feel free to ask~";
			close;		
		}
	}
	disable_items;
	.@refine = getequiprefinerycnt(EQI_HAND_R);
	for(.@i = 0; .@i < 4; .@i++){
		.@card[.@i] = getequipcardid(EQI_HAND_R,.@i);
		.@check[.@i] = .@card[.@i];
	}
	if(.@card[2] > 0){
		mes "[ Ravian ]";
		mes "Wow~ You've got the weapon. But...";
		next;
		mes "[ Ravian ]";
		mes "I can't empower this weapon anymore, it's already on its maximum capacity.";
		end;
	}
	.@slot = ((.@card[3] > 0) ? 2 : 3);
	mes "[ Ravian ]";
	mes "Wow~ You've got the weapon.";
	mes "Alright, what enchant method will you use to empower it?";
	next;
	switch(select("Cancel","General Enchant","Advanced Enchant",((.@slot == 2) ? "Determined Enchant":""))){
		case 1:
			end;
			
		case 2:
			setarray .@cost,25786,50,25787,50;
			if(.@slot == 3)
				setarray .@chance,35,5;
			else
				setarray .@chance,70,20,30;
			break;
			
		case 3:
			setarray .@cost,25786,500,25787,500;
			if(.@slot == 3)
				setarray .@chance,10,0;
			else
				setarray .@chance,30,0,70;
			break;

		case 4:
			setarray .@cost,25786,5000;
			setarray .@chance,0,0;
			.@select = true;
			break;
	}
	if(.@select){
		mes "[ Ravian ]";
		mes "Which enchant do you want on your final slot?";
		next;
		.@menu$ = "Cancel:";
		for(.@i = 0; .@i < getarraysize(.special_enchant); .@i++)
			.@menu$ += getitemname(.special_enchant[.@i]) + ":";
		.@s = select(.@menu$);
		if(.@s == 1)
			end;
		.@s = .@s - 2;
	}
	mes "[ Ravian ]";
	mes "Enchant Cost :";
	for(.@i = 0; .@i < getarraysize(.@cost); .@i += 2)
		mes "<ITEM>"+getitemname(.@cost[.@i])+"<INFO>"+.@cost[.@i]+"</INFO></ITEM> x " + .@cost[.@i+1];
	mes "^0000CDSuccess chance is " + (100-.@chance[0]) + "%^000000";
	mes "^FF0000Destroyed chance is " + .@chance[1] + "%^000000";
	if(.@select)
		mes "^0000CDYou selected the " + getitemname(.special_enchant[.@s]) + " as your special enchant.^000000";
	mes "Do you want to proceed?";
	next;
	if(select("Wait.:Yes, please.") == 1){
		mes "[ Ravian ]";
		mes "Good decision~ Make sure you think about it carefully.";
		close;
	}
	for(.@i = 0; .@i < getarraysize(.@cost); .@i += 2){
		if(countitem(.@cost[.@i]) < .@cost[.@i+1])
			.@miss++;
	}
	if(.@miss){
		mes "[ Ravian ]";
		mes "You do not have all the the materials. Make sure you have everything before enchanting.";
		close;
	}
	for(.@i = 0; .@i < getarraysize(.@cost); .@i += 2)
		delitem .@cost[.@i],.@cost[.@i+1];
	if(rand(1,100) >= .@chance[0]){
		if(!.@select){
			if(.@slot == 3)
				.@enchant = .enchant[rand(getarraysize(.enchant))];
			else {
				if(rand(1,100) <= .@chance[2])
					.@enchant = .special_enchant[rand(getarraysize(.special_enchant))];
				else
					goto OnFail;
			}
		} else 
			.@enchant = .special_enchant[.@s];
		.@card[.@slot] = .@enchant;
		if(callfunc("F_IsEquipIDHack", EQI_HAND_R, .@equip_id) || callfunc("F_IsEquipRefineHack", EQI_HAND_R, .@refine) || callfunc("F_IsEquipCardHack", EQI_HAND_R, .@check[0], .@check[1], .@check[2], .@check[3]))
			end;
		specialeffect2 EF_REPAIRWEAPON;
		delequip EQI_HAND_R;
		getitem2 .@equip_id,1,1,.@refine,0,.@card[0],.@card[1],.@card[2],.@card[3];
		mes "[ Ravian ]";
		mes "The enchantment process is completed successfully. I hope you like it~";
		end;
	} else {
		OnFail:
		specialeffect2 EF_REFINEFAIL;
		delequip EQI_HAND_R;
		if(rand(1,100) >= .@chance[1]){
			getitem2 .@equip_id,1,1,.@refine,0,.@card[0],.@card[1],.@card[2],.@card[3];
			mes "[ Ravian ]";
			mes "Ugh, sorry. The enchant failed, but the weapon wasn't destroyed.";
		} else {
			mes "[ Ravian ]";
			mes "Ugh, sorry. The enchant failed and the weapon was destroyed. I'll do better next time.";
		}
	}
	end;
	
OnInit:
	setarray .weapon_list,21051,21052,32023,1333,16092,28138,28765,28766,28044,28042,26158,2055,2056,26161,2057,16095,18185,18187,
	18186,32350,32024,32025,32351,16093,16094,28767,28768,18184,28633,26159,26160,1865,1866,16096,18188,26212,26213,32107,32108;
	setarray .enchant,4832,4833,4834,4808,4820,4821,4818,4817,4816,4863,4864,4865,4815,4814,4813;
	setarray .special_enchant,29594,29595,29596,29598,29599,29600,29601,29602,29603,29604,29605,29606,29607;
end;

function	weapon_check	{
	for(.@i = 0; .@i < getarraysize(.weapon_list); .@i++){
		if(getarg(0) == .weapon_list[.@i])
			return true;
	}
	return false;
}

}

1@gol1,1,1,0	script	#edda_journey_control	-1,{
	end;
	
OnInstanceInit:
	set_instance_var("first_floor$",instance_mapname("1@gol1"));
	set_instance_var("second_floor$",instance_mapname("1@gol2"));
	.@map$ = get_instance_var("first_floor$");
	instance_enable("Sierra#edda_lab_start-1",false);
	instance_enable("Sierra#edda_lab_0-1",false);
	instance_enable("Synchronization Device#edda_lab_start-0",false);
	instance_enable("Eremes Guile#edda_lab_0",false);
	instance_enable("Katrinn Keyron#edda_lab_0",false);
	instance_enable("Magaleta Sorin#edda_lab_0",false);
	instance_enable("Seyren Windsor#edda_lab_0",false);
	instance_enable("Harword Alt-Eisen#edda_lab_0",false);
	instance_enable("Shecil Damon#edda_lab_0",false);
	instance_enable("Security Officer#edda_lab_0",false);
	instance_enable("Schwarzwald Soldier#edda_lab_0-1",false);
	instance_enable("Schwarzwald Soldier#edda_lab_0-2",false);
	instance_enable("Seyren Windsor#edda_lab_1",false);
	instance_enable("Seyren Windsor#edda_lab_2",false);
	instance_enable("Eremes Guile#edda_lab_1",false);
	instance_enable("#edda_explore_warp_0",false);
	instance_enable("Seyren Windsor#edda_lab_3",false);
	instance_enable("Eremes Guile#edda_lab_2",false);
	instance_enable("Seyren Windsor#edda_lab_4",false);
	instance_enable("Eremes Guile#edda_lab_3",false);
	instance_enable("Katrinn Keyron#edda_lab_1",false);
	instance_enable("#edda_explore_warp_1",false);
	instance_enable("Seyren Windsor#edda_lab_5",false);
	instance_enable("Harword Alt-Eisen#edda_lab_1",false);
	instance_enable("Seyren Windsor#edda_lab_6",false);
	instance_enable("Wolfchev#edda_lab_0",false);
	instance_enable("Nameless Swordsman#edda_lab_0",false);
	instance_enable("Shecil Damon#edda_lab_1",false);
	instance_enable("Magaleta Sorin#edda_lab_1",false);
	instance_enable("Magaleta Sorin#edda_lab_2",false);
	instance_enable("Harword Alt-Eisen#edda_lab_3",false);
	instance_enable("Seyren Windsor#edda_lab_7",false);
	instance_enable("Shecil Damon#edda_lab_2",false);
	instance_enable("#edda_explore_warp_2",false);
	instance_enable("Harword Alt-Eisen#edda_lab_4",false);
	instance_enable("Seyren Windsor#edda_lab_8",false);
	instance_enable("Shecil Damon#edda_lab_3",false);
	instance_enable("Magaleta Sorin#edda_lab_3",false);
	instance_enable("#edda_exploration_mob",false);
	instance_enable("Harword Alt-Eisen#edda_lab_5",false);
	instance_enable("Seyren Windsor#edda_lab_9",false);
	instance_enable("Shecil Damon#edda_lab_4",false);
	instance_enable("Harword Alt-Eisen#edda_lab_2",false);
	instance_enable("Wolfchev#edda_lab_1",false);
	instance_enable("Nameless Swordsman#edda_lab_1",false);
	instance_enable("Katrinn Keyron#edda_lab_2",false);
	instance_enable("Eremes Guile#edda_lab_4",false);
	instance_enable("Magaleta Sorin#edda_lab_4",false);
	instance_enable("Harword Alt-Eisen#edda_lab_6",false);
	instance_enable("Seyren Windsor#edda_lab_10",false);
	instance_enable("Shecil Damon#edda_lab_5",false);
	instance_enable("Sierra#edda_explore_end",false);
	for(.@i = 0; .@i < 15; .@i++)
		instance_enable("edda_explore_dummy_" + .@i,false);
	
	//= Archer Laboratory
	for(.@i = 0; .@i < 3; .@i++){
		instance_enable("Rekenber Guard#edda_shecil_0-" + .@i,false);
		instance_enable("Rekenber Guard#edda_shecil_1-" + .@i,false);
	}
	instance_enable("Shecil Damon#edda_shecil_0-0",false);
	instance_enable("Shecil Damon#edda_shecil_1-0",false);
	instance_enable("Shecil Damon#edda_shecil_1-1",false);
	instance_enable("Experiment Report#edda_shecil_0",false);
	for(.@i = 0; .@i < 5; .@i++)
		instance_enable("Rekenber Guard#edda_shecil_2-" + .@i,false);
	instance_enable("Sierra#edda_shecil_0",false);
	instance_enable("#edda_shecil_mob",false);
	
	//= Swordsman Lab
	for(.@i = 0; .@i < 2; .@i++)
		instance_enable("Rekenber Guard#edda_seyren_0-" + .@i,false);
	instance_enable("Seyren Windsor#edda_seyren_0-0",false);
	instance_enable("Seyren Windsor#edda_seyren_1-0",false);
	instance_enable("Seyren's PecoPeco#edda_seyren_1-0",false);
	for(.@i = 0; .@i < 6; .@i++)
		instance_enable("Rekenber Guard#edda_seyren_1-" + .@i,false);
	instance_enable("Sierra#edda_seyren_0",false);
	instance_enable("#edda_seyren_mob",false);
	
	//= Thief Lab
	instance_enable("Eremes Guile#edda_eremes_0-0",false);
	instance_enable("Katrinn Keyron#edda_eremes_0-0",false);
	instance_enable("Eremes Guile#edda_eremes_1-0",false);
	for(.@i = 0; .@i < 2; .@i++)
		instance_enable("Rekenber Guard#edda_eremes_0-" + .@i,false);
	for(.@i = 0; .@i < 6; .@i++)
		instance_enable("Rekenber Guard#edda_eremes_1-" + .@i,false);
	instance_enable("Sierra#edda_eremes_0",false);
	instance_enable("#edda_eremes_mob",false);
	
	//= Mage Lab
	instance_enable("Katrinn Keyron#edda_keyron_0-0",false);
	instance_enable("Katrinn Keyron#edda_keyron_1-0",false);
	instance_enable("Eremes Guile#edda_keyron_1-0",false);
	for(.@i = 0; .@i < 6; .@i++)
		instance_enable("Rekenber Guard#edda_keyron_1-" + .@i,false);
	instance_enable("Sierra#edda_keyron_0",false);
	instance_enable("#edda_keyron_mob",false);
	
	//= Acolyte Lab
	instance_enable("Seyren Windsor#edda_sorin_0-0",false);
	instance_enable("Rekenber Guard#edda_sorin_0-0",false);
	instance_enable("Rekenber Guard#edda_sorin_0-1",false);
	instance_enable("Magaleta Sorin#edda_sorin_1-0",false);
	instance_enable("Seyren Windsor#edda_sorin_1-0",false);
	instance_enable("Sierra#edda_sorin_0",false);
	instance_enable("Experiment Report#edda_sorin_1-0",false);
	for(.@i = 0; .@i < 2; .@i++)
		instance_enable("Rekenber Guard#edda_sorin_0-" + .@i,false);
	for(.@i = 0; .@i < 4; .@i++)
		instance_enable("Rekenber Guard#edda_sorin_1-" + .@i,false);
	instance_enable("#edda_sorin_mob",false);
	
	//= Merchant Lab
	instance_enable("Harword Alt-Eisen#edda_harword_0-0",false);
	instance_enable("Harword Alt-Eisen#edda_harword_0-1",false);
	instance_enable("Harword Alt-Eisen#edda_harword_0-2",false);
	instance_enable("Switch#edda_harword_0-0",false);
	instance_enable("Sierra#edda_harword_0",false);
	for(.@i = 0; .@i < 8; .@i++)
		instance_enable("Rekenber Guard#edda_harword_0-" + .@i,false);		
	instance_enable("#edda_harword_mob",false);
	
	//= Combat Mode
	instance_enable("#edda_combat_mob",false);
	instance_enable("???#edda_combat_reward",false);
	for(.@i = 0; .@i < 10; .@i++)
		instance_enable("Sierra#edda_combat_" + .@i,false);
	instance_enable("#edda_eremes_effect",false);
	for(.@i = 0; .@i < 2; .@i++)
		instance_enable("Vision Device#edda_combat_" + .@i,false);
	for(.@i = 0; .@i < 3; .@i++)
		instance_enable("#edda_combat_wall_0-" + .@i,false);
	for(.@i = 0; .@i < 5; .@i++){
		instance_enable("#edda_combat_wall_2-" + .@i,false);
		instance_enable("#edda_combat_wall_4-" + .@i,false);
	}
	for(.@i = 0; .@i < 8; .@i++){
		instance_enable("#edda_combat_wall_1-" + .@i,false);
		instance_enable("#edda_combat_wall_3-" + .@i,false);
	}
	instance_enable("#edda_combat_silence_0",false);
	for(.@i = 0; .@i < 4; .@i++){
		instance_enable("#edda_combat_trap_" + .@i,false);
		instance_enable("#edda_trap_silence_" + .@i,false);
	}
	for(.@i = 0; .@i < 7; .@i++)
		instance_enable("#edda_combat_mimic_" + .@i,false);
	for(.@i = 0; .@i < 14; .@i++){
		instance_enable("#edda_c_wall_0-" + .@i,false);
		instance_enable("#edda_c_wall_1-" + .@i,false);
		instance_enable("#edda_c_wall_2-" + .@i,false);
		instance_enable("#edda_c_wall_3-" + .@i,false);
	}
	for(.@i = 0; .@i < 2; .@i++)
		instance_enable("#edda_c_wall_4-" + .@i,false);
end;

OnCombatMode:
	.@map$ = get_instance_var("first_floor$");
	set_instance_var("type",1);
	instance_enable("Sierra#edda_combat_0",true);
	instance_enable("#edda_combat_mob",true);
	instance_event("#edda_combat_mob","OnSpawn00",false);
	.@party_id = 'party_id;
	warpparty .@map$,164,187,.@party_id,.@map$;
end;

OnExplorationMode:
	set_instance_var("type",0);
	.@map$ = get_instance_var("first_floor$");
	.@party_id = 'party_id;
	instance_enable("Sierra#edda_lab_0-1",true);
	instance_hide("Sierra#edda_lab_0-1",true);
	instance_enable("Eremes Guile#edda_lab_0",true);
	instance_enable("Katrinn Keyron#edda_lab_0",true);
	instance_enable("Magaleta Sorin#edda_lab_0",true);
	instance_enable("Seyren Windsor#edda_lab_0",true);
	instance_enable("Harword Alt-Eisen#edda_lab_0",true);
	instance_enable("Shecil Damon#edda_lab_0",true);
	instance_enable("Security Officer#edda_lab_0",true);
	instance_enable("Schwarzwald Soldier#edda_lab_0-1",true);
	instance_enable("Schwarzwald Soldier#edda_lab_0-2",true);
	for(.@i = 0; .@i < 5; .@i++){
		instance_enable("Rekenber Guard#edda_lab_0-" + .@i,true);
		instance_hide("Rekenber Guard#edda_lab_0-" + .@i,true);
	}
	warpparty .@map$,171,188,.@party_id,.@map$;
	instance_enable("Synchronization Device#edda_lab_start-0",true);
	instance_hide("Synchronization Device#edda_lab_start-0",true);
end;

OnExploration00:
	.@map$ = get_instance_var("first_floor$");
	set_instance_var("edda_lab",2);
	.@eremes$ = instance_npcname("Eremes Guile#edda_lab_0");
	.@keyron$ = instance_npcname("Katrinn Keyron#edda_lab_0");
	.@sorin$ = instance_npcname("Magaleta Sorin#edda_lab_0");
	.@seyren$ = instance_npcname("Seyren Windsor#edda_lab_0");
	.@harword$ = instance_npcname("Harword Alt-Eisen#edda_lab_0");
	.@shecil$ = instance_npcname("Shecil Damon#edda_lab_0");
	sleep 100;
	specialeffect EF_WHITEBODY,AREA,instance_npcname("Security Officer#edda_lab_0");
	specialeffect EF_GRAYBODY,AREA,instance_npcname("Security Officer#edda_lab_0");
	specialeffect EF_WHITEBODY,AREA,instance_npcname("Schwarzwald Soldier#edda_lab_0-1");
	specialeffect EF_GRAYBODY,AREA,instance_npcname("Schwarzwald Soldier#edda_lab_0-1");
	specialeffect EF_WHITEBODY,AREA,instance_npcname("Schwarzwald Soldier#edda_lab_0-2");
	specialeffect EF_GRAYBODY,AREA,instance_npcname("Schwarzwald Soldier#edda_lab_0-2");
	sleep 1000;
	specialeffect EF_CLOUD4,AREA,.@seyren$;
	sleep 3000;
	mapannounce .@map$,"Eremes : Wait, what is this strange smell?",bc_map,0xB4B4FF;
	npctalk "Eremes : Wait, what is this strange smell?",.@eremes$;
	sleep 3000;
	mapannounce .@map$,"Seyren : Where did the security officials go?",bc_map,0xD3D3D3;
	npctalk "Seyren : Where did the security officials go?",.@seyren$;
	sleep 3000;
	mapannounce .@map$,"Keyron : Weird. Why am I so sleep... sleepy...",bc_map,0xFFFFB4;
	npctalk "Keyron : Weird. Why am I so sleep... sleepy...",.@keyron;
	classchange 4_F_MD_KATRINN_D,.@keyron$;
	classchange 4_F_MD_MAGALETA_D,.@sorin$;
	classchange 4_M_MD_HARWORD_D,.@harword$;
	specialeffect EF_SLEEPATTACK,AREA,.@keyron$;
	sleep 100;
	specialeffect EF_SLEEPATTACK,AREA,.@harword$;
	sleep 3000;
	for(.@i = 0; .@i < 4; .@i++)
		instance_hide("Rekenber Guard#edda_lab_0-" + .@i,false);
	mapannounce .@map$,"Rekenber Guard : They're all asleep, right? Seize them!",bc_map,0xD2FFD2;
	npctalk "Rekenber Guard : Hold it! Don't miss a single person!",instance_npcname("Rekenber Guard#edda_lab_0-0");
	npctalk "Rekenber Guard : Wait, why are they still awake?",instance_npcname("Rekenber Guard#edda_lab_0-2");
	sleep 2000;
	instance_hide("Rekenber Guard#edda_lab_0-4",false);
	sleep 250;
	mapannounce .@map$,"Eremes : Damn. We've been deceived!",bc_map,0xB4B4FF;
	npctalk "Eremes : Damn. We've been deceived!",.@eremes$;	
	specialeffect EF_SOULBREAKER,AREA,.@eremes$;
	specialeffect EF_NPC_BURNT,AREA,instance_npcname("Rekenber Guard#edda_lab_0-4");
	npctalk "Rekenber Guard : Ahhh!",instance_npcname("Rekenber Guard#edda_lab_0-4");
	sleep 3000;
	mapannounce .@map$,"Eremes : I'll leave Katrinn in a safe place. Hang in there Seyren!",bc_map,0xB4B4FF;
	npctalk "Eremes : I'll leave Katrinn in a safe place. Hang in there Seyren!",.@eremes$;	
	npctalk "Rekenber Guard : Hold it! Tie up the ones who are sleeping!",instance_npcname("Rekenber Guard#edda_lab_0-2");
	npctalk "Shecil : Damn... I can't...",.@shecil$;
	instance_hide("Eremes Guile#edda_lab_0",true);
	instance_hide("Katrinn Keyron#edda_lab_0",true);
	instance_enable("Eremes Guile#edda_lab_0",false);
	instance_enable("Katrinn Keyron#edda_lab_0",false);
	sleep 3000;
	npctalk "Shecil : Damn...",.@shecil$;
	mapannounce .@map$,"Seyren : Oh, no. I musn't... fall... asle...",bc_map,0xD3D3D3;
	npctalk "Seyren : Oh, no. I musn't... fall... asle...",.@seyren$;
	classchange 4_F_MD_SHECIL_D,.@shecil$;
	sleep 100;
	classchange 4_M_MD_SEYREN_D,.@seyren$;
	sleep 3000;
	instance_hide("Seyren Windsor#edda_lab_0",true);
	instance_enable("Seyren Windsor#edda_lab_0",false);
	instance_hide("Magaleta Sorin#edda_lab_0",true);
	instance_enable("Magaleta Sorin#edda_lab_0",false);
	instance_hide("Harword Alt-Eisen#edda_lab_0",true);
	instance_enable("Harword Alt-Eisen#edda_lab_0",false);
	instance_hide("Shecil Damon#edda_lab_0",true);
	instance_enable("Shecil Damon#edda_lab_0",false);
	for(.@i = 0; .@i < 5; .@i++){
		instance_hide("Rekenber Guard#edda_lab_0-" + .@i,true);
		instance_enable("Rekenber Guard#edda_lab_0-" + .@i,false);
	}
	instance_hide("Security Officer#edda_lab_0",true);
	instance_enable("Security Officer#edda_lab_0",false);
	instance_hide("Schwarzwald Soldier#edda_lab_0-1",true);
	instance_enable("Schwarzwald Soldier#edda_lab_0-1",false);
	instance_hide("Schwarzwald Soldier#edda_lab_0-2",true);
	instance_enable("Schwarzwald Soldier#edda_lab_0-2",false);
	sleep 2000;
	instance_enable("Sierra#edda_lab_start-0",false);
	instance_enable("Sierra#edda_lab_start-1",true);
	instance_hide("Sierra#edda_lab_0-1",false);
	sleep 100;
	specialeffect EF_CRYSTAL_BLUE,instance_npcname("Sierra#edda_lab_0-1");
	sleep 2500;
	npctalk "Sierra : Don't be alarmed. I stepped in for a moment.",instance_npcname("Sierra#edda_lab_0-1");
	sleep 3000;
	npctalk "Sierra : If you talk to me, I'll connect you to the situation room.";
	set_instance_var("edda_lab",3);
end;

OnExploration01:
	.@map$ = get_instance_var("first_floor$");
	.@party_id = 'party_id;
	set_instance_var("edda_lab",6);
	instance_enable("Seyren Windsor#edda_lab_1",true);
	sleep 10;
	warpparty .@map$,42,156,.@party_id,.@map$;
end;

OnExploration02:
	.@map$ = get_instance_var("first_floor$");
	set_instance_var("edda_lab",7);
	instance_hide("Seyren Windsor#edda_lab_1",true);
	instance_enable("Seyren Windsor#edda_lab_1",false);
	instance_enable("Seyren Windsor#edda_lab_2",true);
	instance_enable("Eremes Guile#edda_lab_1",true);
	instance_enable("#edda_exploration_mob",true);
end;

OnExploration03:
	set_instance_var("edda_lab",10);
	instance_enable("#edda_explore_warp_0",true);
	instance_enable("Seyren Windsor#edda_lab_3",true);
	instance_enable("Eremes Guile#edda_lab_2",true);
	instance_enable("Katrinn Keyron#edda_lab_1",true);
end;

OnExploration04:
	set_instance_var("edda_lab",11);
	.@map$ = get_instance_var("first_floor$");
	mapannounce .@map$,"Regenschirm Scientist : Get your hands off me! What do you think you're doing!",bc_map,0xFFDCDC;
	sleep 1750;
	mapannounce .@map$,"Rekenber Guard : But what if she wakes up and go berserk with magic again? I don't want to die!",0xDCFFDC;
	sleep 1750;
	mapannounce .@map$,"Regenschirm Scientist : I've already tranquilized her to the limits. There's no black blood reaction yet. Are you going to kill this important sample?",bc_map,0xFFDCDC;
	sleep 1750;
	mapannounce .@map$,"Rekenber Guard : It's your job to keep them alive. If she is tranquilized, then why does she keep using magic!",0xDCFFDC;
	sleep 1750;
	mapannounce .@map$,"Rekenber Officer : Hey, you! We are not allowed to disturb the researchers. You have to stay still or else.",0xE6E6FF;
	sleep 1750;
	mapannounce .@map$,"Rekenber Guard : But, they don't care about our lives! If she wakes up again, we'll die for sure!",0xDCFFDC;
	sleep 1750;
	mapannounce .@map$,"Regenschirm Scientist : Well, if she doesn't wake up, Dr. Wolchev will kill us all instead!",bc_map,0xFFDCDC;
	sleep 1750;
	mapannounce .@map$,"Regenschirm Scientist : Her vitals are weird all of a sudden. The numbers are!!",bc_map,0xFFDCDC;
	sleep 1750;
	mapannounce .@map$,"Seyren : I'm at the front of the lab, I'm going right in! We'll save Keyron!",bc_map,0xD3D3D3;
	instance_hide("Seyren Windsor#edda_lab_3",true);
	instance_enable("Seyren Windsor#edda_lab_3",false);
	instance_hide("Eremes Guile#edda_lab_2",true);
	instance_enable("Eremes Guile#edda_lab_2",false);
	instance_event("#edda_exploration_mob","OnSummon01",false);
	instance_enable("Seyren Windsor#edda_lab_4",true);
	instance_enable("Eremes Guile#edda_lab_3",true);
end;

OnExploration05:
	set_instance_var("edda_lab",14);
	instance_enable("Seyren Windsor#edda_lab_5",true);
	instance_enable("Harword Alt-Eisen#edda_lab_1",true);
	instance_enable("Shecil Damon#edda_lab_1",true);
	instance_hide("Shecil Damon#edda_lab_1",true);
	instance_enable("Magaleta Sorin#edda_lab_1",true);
	instance_hide("Magaleta Sorin#edda_lab_1",true);
	instance_enable("#edda_explore_warp_1",true);
end;


OnExploration06:
	set_instance_var("edda_lab",15);
	instance_hide("Seyren Windsor#edda_lab_5",true);
	instance_enable("Seyren Windsor#edda_lab_5",false);
	instance_hide("Harword Alt-Eisen#edda_lab_1",true);
	instance_enable("Harword Alt-Eisen#edda_lab_1",false);
	instance_enable("Harword Alt-Eisen#edda_lab_2",true);
	instance_enable("Seyren Windsor#edda_lab_6",true);
	instance_enable("Wolfchev#edda_lab_0",true);
	instance_enable("Nameless Swordsman#edda_lab_0",true);
end;

OnExploration07:
	set_instance_var("edda_lab",18);
	instance_hide("Harword Alt-Eisen#edda_lab_2",true);
	instance_enable("Harword Alt-Eisen#edda_lab_2",false);
	instance_hide("Shecil Damon#edda_lab_1",true);
	instance_enable("Shecil Damon#edda_lab_1",false);
	instance_hide("Seyren Windsor#edda_lab_6",true);
	instance_enable("Seyren Windsor#edda_lab_6",false);
	instance_enable("Harword Alt-Eisen#edda_lab_3",true);
	instance_enable("Seyren Windsor#edda_lab_7",true);
	instance_enable("Shecil Damon#edda_lab_2",true);
end;

OnExploration08:
	set_instance_var("edda_lab",19);
	instance_enable("#edda_explore_warp_2",true);
	specialeffect EF_READYPORTAL2,AREA,instance_npcname("#edda_explore_warp_2");
	instance_hide("Harword Alt-Eisen#edda_lab_3",true);
	instance_hide("Seyren Windsor#edda_lab_7",true);
	instance_hide("Shecil Damon#edda_lab_2",true);
	instance_hide("Magaleta Sorin#edda_lab_2",true);
	instance_enable("Harword Alt-Eisen#edda_lab_3",false);
	instance_enable("Seyren Windsor#edda_lab_7",false);
	instance_enable("Shecil Damon#edda_lab_2",false);
	instance_enable("Magaleta Sorin#edda_lab_2",false);
	instance_enable("Harword Alt-Eisen#edda_lab_4",true);
	instance_enable("Seyren Windsor#edda_lab_8",true);
	instance_enable("Shecil Damon#edda_lab_3",true);
	instance_enable("Magaleta Sorin#edda_lab_3",true);
	instance_enable("Wolfchev#edda_lab_1",true);
	instance_hide("Wolfchev#edda_lab_1",true);
	instance_enable("Nameless Swordsman#edda_lab_1",true);
	instance_hide("Nameless Swordsman#edda_lab_1",true);
	instance_enable("Katrinn Keyron#edda_lab_2",true);
	instance_enable("Eremes Guile#edda_lab_4",true);
	instance_enable("Magaleta Sorin#edda_lab_4",true);
	instance_enable("Harword Alt-Eisen#edda_lab_6",true);
	instance_enable("Seyren Windsor#edda_lab_10",true);
	instance_enable("Shecil Damon#edda_lab_5",true);
	instance_hide("Katrinn Keyron#edda_lab_2",true);
	instance_hide("Eremes Guile#edda_lab_4",true);
	instance_hide("Magaleta Sorin#edda_lab_4",true);
	instance_hide("Harword Alt-Eisen#edda_lab_6",true);
	instance_hide("Seyren Windsor#edda_lab_10",true);
	instance_hide("Shecil Damon#edda_lab_5",true);
	
end;

OnExploration09:
	set_instance_var("edda_lab",20);
	instance_hide("Harword Alt-Eisen#edda_lab_4",true);
	instance_hide("Seyren Windsor#edda_lab_8",true);
	instance_enable("Harword Alt-Eisen#edda_lab_4",false);
	instance_enable("Seyren Windsor#edda_lab_8",false);
	instance_enable("Harword Alt-Eisen#edda_lab_5",true);
	instance_enable("Seyren Windsor#edda_lab_9",true);
	instance_enable("Shecil Damon#edda_lab_4",true);
	for(.@i = 0; .@i < 15; .@i++)
		instance_enable("edda_explore_dummy_" + .@i,true);
end;

OnExploration10:
	set_instance_var("edda_lab",23);
	classchange 4_M_MD_HARWORD_D,instance_npcname("Harword Alt-Eisen#edda_lab_5");
	classchange 4_F_MD_SHECIL_D,instance_npcname("Shecil Damon#edda_lab_4");
	instance_hide("Harword Alt-Eisen#edda_lab_6",false);
	instance_hide("Seyren Windsor#edda_lab_10",false);
	instance_hide("Shecil Damon#edda_lab_5",false);
	instance_enable("Sierra#edda_explore_end",true);
end;

OnMerchantLab:
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("merchant_lab");
	if(!.@var){
		set_instance_var("merchant_lab",1);
		instance_enable("Harword Alt-Eisen#edda_harword_0-0",true);
		instance_enable("Harword Alt-Eisen#edda_harword_0-1",true);
		instance_hide("Harword Alt-Eisen#edda_harword_0-1",true);
		instance_enable("Harword Alt-Eisen#edda_harword_0-2",true);
		instance_hide("Harword Alt-Eisen#edda_harword_0-2",true);
		instance_enable("Switch#edda_harword_0-0",true);
		instance_hide("Switch#edda_harword_0-0",true);
		for(.@i = 0; .@i < 3; .@i++)
			instance_enable("Rekenber Guard#edda_harword_0-" + .@i,true);
		for(.@i = 3; .@i < 8; .@i++){
			instance_enable("Rekenber Guard#edda_harword_0-" + .@i,true);
			instance_hide("Rekenber Guard#edda_harword_0-" + .@i,true);
		}
		instance_enable("Sierra#edda_harword_0",true);
		instance_hide("Sierra#edda_harword_0",true);
		instance_enable("#edda_harword_mob",true);
	}
	if(!isbegin_quest(16397))
		setquest 16397;
	warp .@map$,165,108;
end;

OnAcolyteLab:
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("acolyte_lab");
	if(!.@var){
		set_instance_var("acolyte_lab",1);
		instance_enable("Seyren Windsor#edda_sorin_0-0",true);
		instance_enable("Magaleta Sorin#edda_sorin_1-0",true);
		instance_enable("Experiment Report#edda_sorin_1-0",true);
		instance_enable("Sierra#edda_sorin_0",true);
		instance_hide("Sierra#edda_sorin_0",true);
		instance_enable("#edda_sorin_mob",true);
		for(.@i = 0; .@i < 2; .@i++)
			instance_enable("Rekenber Guard#edda_sorin_0-" + .@i,true);
		for(.@i = 0; .@i < 4; .@i++){
			instance_enable("Rekenber Guard#edda_sorin_1-" + .@i,true);
			instance_hide("Rekenber Guard#edda_sorin_1-" + .@i,true);
		}
	}
	if(!isbegin_quest(16394))
		setquest 16394;
	warp .@map$,116,220;
end;

OnMageLab:
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("mage_lab");
	if(!.@var){
		set_instance_var("mage_lab",1);
		instance_enable("Katrinn Keyron#edda_keyron_0-0",true);
		instance_enable("Eremes Guile#edda_keyron_1-0",true);
		instance_hide("Eremes Guile#edda_keyron_1-0",true);
		instance_enable("Sierra#edda_keyron_0",true);
		instance_hide("Sierra#edda_keyron_0",true);
		instance_enable("#edda_keyron_mob",true);
		for(.@i = 3; .@i < 6; .@i++){
			instance_enable("Rekenber Guard#edda_keyron_1-" + .@i,true);
			instance_hide("Rekenber Guard#edda_keyron_1-" + .@i,true);
		}
	}
	if(!isbegin_quest(16396))
		setquest 16396;
	warp .@map$,108,59;
end;

OnArcherLab:
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("archer_lab");
	if(!.@var){
		set_instance_var("archer_lab",1);
		for(.@i = 0; .@i < 3; .@i++)
			instance_enable("Rekenber Guard#edda_shecil_0-" + .@i,true);
		instance_enable("Shecil Damon#edda_shecil_0-0",true);
		instance_enable("Shecil Damon#edda_shecil_0-1",true);
		instance_hide("Shecil Damon#edda_shecil_0-1",true);
		instance_enable("Experiment Report#edda_shecil_0",true);
		instance_hide("Experiment Report#edda_shecil_0",true);
		for(.@i = 0; .@i < 5; .@i++){
			instance_enable("Rekenber Guard#edda_shecil_2-" + .@i,true);
			instance_hide("Rekenber Guard#edda_shecil_2-" + .@i,true);
		}
		instance_enable("Sierra#edda_shecil_0",true);
		instance_hide("Sierra#edda_shecil_0",true);
		instance_enable("#edda_shecil_mob",true);
	}
	if(!isbegin_quest(16398))
		setquest 16398;
	warp .@map$,171,300;
end;

OnSwordsmanLab:
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("swordsman_lab");
	if(!.@var){
		set_instance_var("swordsman_lab",1);
		for(.@i = 0; .@i < 2; .@i++){
			instance_enable("Rekenber Guard#edda_seyren_0-" + .@i,true);
			instance_hide("Rekenber Guard#edda_seyren_0-" + .@i,true);
		}
		for(.@i = 0; .@i < 6; .@i++){
			instance_enable("Rekenber Guard#edda_seyren_1-" + .@i,true);
			instance_hide("Rekenber Guard#edda_seyren_1-" + .@i,true);
		}
		instance_enable("Seyren Windsor#edda_seyren_0-0",true);		
		instance_enable("Sierra#edda_seyren_0",true);
		instance_hide("Sierra#edda_seyren_0",true);
		instance_enable("#edda_seyren_mob",true);
	}
	if(!isbegin_quest(16393))
		setquest 16393;
	warp .@map$,67,276;
end;

OnThiefLab:
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("thief_lab");
	if(!.@var){
		set_instance_var("thief_lab",1);
		instance_enable("Eremes Guile#edda_eremes_0-0",true);
		instance_enable("Katrinn Keyron#edda_eremes_0-0",true);
		for(.@i = 0; .@i < 2; .@i++){
			instance_enable("Rekenber Guard#edda_eremes_0-" + .@i,true);
			instance_hide("Rekenber Guard#edda_eremes_0-" + .@i,true);
		}
		for(.@i = 4; .@i < 6; .@i++){
			instance_enable("Rekenber Guard#edda_eremes_1-" + .@i,true);
			instance_hide("Rekenber Guard#edda_eremes_1-" + .@i,true);
		}
		instance_enable("Sierra#edda_eremes_0",true);
		instance_hide("Sierra#edda_eremes_0",true);
		instance_enable("#edda_eremes_mob",true);
	}
	if(!isbegin_quest(16395))
		setquest 16395;
	warp .@map$,41,153;
end;

}

1@gol1,196,38,5	script	Sierra#edda_lab_start-0	4_F_SCIENCE,{
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("edda_lab");
	set_instance_var("party_id",getcharid(1));
	if(.@var){
		get_instance_var("type");
		if(!.@type)
			warp .@map$,171,188;
		else
			warp .@map$,164,187;
		end;
	}
	if(isbegin_quest(16399) == 1){
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "You arrived here safely.";
		mes "Just a moment, please. Nina is making the final adjustments.";
		npctalk "Sierra : Virtual Record connection confirmed. Just a moment, please. Nina is making the final adjustments.";
		next;
		mes "[ Sierra ]";
		mes "From now on, you'll be able to interpret the memories of the expeditions in the Virtual Records.";
		mes "Before I start the interpretation, let me give you a some instruction.";
		npctalk "Sierra : Before I start the interpretation, let me give you a some instruction.";
		mapannounce .@map$,"Nina : Adjustments completed. You can now proceed with the interpretation with Sierra!",bc_map,0xFFFF90;
		next;
		mes "[ Sierra ]";
		mes "First of all, as Nina mentioned, the expedition members will recognize you as part of the same exploration team.";
		mes "Please try to gather as much information as possible.";
		npctalk "Sierra : First of all, as Nina mentioned, the expedition members will recognize you as part of the same exploration team. Please try to gather as much information as possible.";
		next;
		mes "[ Sierra ]";
		mes "Nina has modified the record, but it's limited.";
		mes "If you failed to blend-in, the syncronization will decrease and the analysis reliability will decrease.";
		npctalk "Sierra : If you failed to blend-in, the syncronization will decrease and the analysis reliability will decrease.";
		next;
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "However, If you think it's necessary, unexpected behavior is accepted.";
		mes "Every action is inside the Virtual Record. If you fail, you can take a break and start again.";
		npctalk "Sierra : However, If you think it's necessary, unexpected behavior is accepted. Every action is inside the Virtual Record. If you fail, you can take a break and start again.";
		next;
		mes "[ Sierra ]";
		mes "If any event occur during the interpretation that has a significant influence on the souls of the participants, I'm going to adjust the synchronization rate to bring you back here.";
		npctalk "Sierra : If any event occur during the interpretation that has a significant influence on the souls of the participants, I'm going to adjust the synchronization rate to bring you back here.";
		next;
		mes "[ Sierra ]";
		mes "Please remember this is just a virtual memory.";
		mes "Even if we save them here, nothing's going to change. They're already dead. They're turning into spirits in the basement of the Somatology.";
		npctalk "Sierra : Even if we save them here, nothing's going to change. They're already dead.";
		next;
		mes "[ Sierra ]";
		mes "Your mission is to find about the truth.";
		mes "If we stay here with you, we'll be compromising the outcome.";
		npctalk "Sierra : Your mission is to find about the truth. If we stay here with you, we'll be compromising the outcome.";
		next;
		mes "[ Sierra ]";
		mes "Alright then, I'll connect you to the waiting room for an informal expedition with Seyren Windsor.";
		mes "Make sure you ^FF0000speak to everyone^000000.";
		npctalk "Sierra : Alright then, I'll connect you to the waiting room for an informal expedition with Seyren Windsor. Make sure you speak to everyone";
		next;
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "I hope you find about the truth of the Somatology.";
		npctalk "Sierra : I hope you find about the truth of the Somatology.";
		instance_event("#edda_journey_control","OnExplorationMode",false);
		close2;
	} else {
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "You're participating in the Combat Mode interpretation.";
		mes "In this mode, you will experience the combat data of the expedition.";
		npctalk "Sierra : In this mode, you will experience the combat data of the expedition.";
		next;
		mes "[ Sierra ]";
		mes "I can give you information during combats, but I can't intervene.";
		mes "Please be careful not to put yourself in danger.";
		npctalk "Sierra : I can give you information during combats, but I can't intervene. Please be careful not to put yourself in danger.";
		next;
		mes "[ Sierra ]";
		mes "When the battle is over, only those who with conscious virtual state are moved to the next area.";
		mes "In the case that you're knock unconscious, I'll be waiting for you, so come and see me afterwards.";
		npctalk "Sierra : When the battle is over, only those who with conscious virtual state are moved to the next area.";
		sleep2 1500;
		npctalk "In the case that you're knock unconscious, I'll be waiting for you, so come and see me afterwards.";
		next;
		mes "[ Sierra ]";
		mes "Alright then, I'll move you to the expedition team. They're in the waiting room for the president.";
		npctalk "Sierra : Alright then, I'll move you to the expedition team. They're in the waiting room for the president.";
		instance_event("#edda_journey_control","OnCombatMode",false);
		close2;
	}
	cutin "",255;
	set_instance_var("edda_lab",1);
	end;
}

1@gol1,202,44,3	script	Sierra#edda_lab_start-1	4_F_SCIENCE,{
	.@var = get_instance_var("edda_lab");
	.@var2 = get_instance_var("edda_sync");
	.@map$ = get_instance_var("first_floor$");
	if(.@var == 3){
		mes "[ Sierra ]";
		mes "Because of the events that occurred, all the explorers memories have been lost, I've stepped in and brought you into the Situation Room.";
		npctalk "Because of the events that occurred, all the explorers memories have been lost, I've stepped in and brought you into the Situation Room.";
		next;
		mes "[ Sierra ]";
		mes "It's a memory-replicating device. So when everyone is asleep, it doesn't work.";
		npctalk "It's a memory-replicating device. So when everyone is asleep, it doesn't work.";
		next;
		mes "[ Sierra ]";
		mes "According to the Virtual Record, each of the five people who fell asleep was moved to each respective places. To explore all the memories of each person, we'll now split up.";
		npctalk "According to the Virtual Record, each of the five people who fell asleep was moved to each respective places. To explore all the memories of each person, we'll now split up.";
		next;
		mes "[ Sierra ]";
		mes "You may follow the memory of one place, or you may follow the memory of another. The more memories you navigate to the faster we can interpret them. You don't have to over do it.";
		npctalk "You may follow the memory of one place, or you may follow the memory of another. The more memories you navigate to the faster we can interpret them. You don't have to over do it.";
		next;
		mes "[ Sierra ]";
		mes "To manage different exploration points, we will now seek help of the Sync-Device, right next to me.";
		npctalk "Sierra : To manage different exploration points, we will now seek help of the Sync-Device, right next to me.";
		instance_hide("Synchronization Device#edda_lab_start-0",false);
		set_instance_var("edda_lab",4);
		end;
	}
	if(.@var == 4 || .@var2 == 0){
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "Please use the synchronization device to follow the memories of each location. Please talk to me again after you're done adjusting.";
		npctalk "Sierra : Please use the synchronization device to follow the memories of each location. Please talk to me again after you're done adjusting.";
		close2;
		cutin "",255;
		end;
	}
	if(.@var == 5){
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "Synchronization adjustments is complete. Now all the explorers are asleep again. You look a little depressed.";
		npctalk "Sierra : Synchronization adjustments is complete. Now all the explorers are asleep again. You look a little depressed.";
		next;
		cutin "",255;
		if(select("Yes, my feelings is in disarray.:You really can't help them.") == 1){
			cutin "3rd_gn_demi02",2;
			mes "[ Sierra ]";
			mes "I was also depressed on the first time. Now, I don't think so.";
			npctalk "Sierra : I was also depressed on the first time. Now, I don't think so.";
		} else {
			cutin "3rd_gn_demi02",2;
			mes "[ Sierra ]";
			mes "Yes. If the difference of the actual record and the interpreted one are too different, the synchronization will fail. We won't get any results with that.";
			npctalk "Sierra : Yes. If the difference of the actual record and the interpreted one are too different, the synchronization will fail. We won't get any results with that.";
		}
		next;
		mes "[ Sierra ]";
		mes "There's nothing we can do for them. Remember, these records are just memories of the dead.";
		npctalk "Sierra : There's nothing we can do for them. Remember, these records are just memories of the dead.";
		next;
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "What we can do for them now is to interpret every piece of data you've collected to reveal the truth.";
		npctalk "Sierra : What we can do for them now is to interpret every piece of data you've collected to reveal the truth.";
		next;
		mes "[ Sierra ]";
		mes "Alright, I'll connect you to the next memory.";
		mes "This one is from Seyren Windosr.";
		npctalk "Sierra : Alright, I'll connect you to the next memory. This one is from Seyren Windosr.";
		next;
		mes "[ Sierra ]";
		mes "There's something tangled up within the record that Nina can't adjust, and it's been connected since from the start.";
		mes "Please make sure you're careful.";
		npctalk "Sierra : There's something tangled up within the record that Nina can't adjust, and it's been connected since from the start. Please make sure you're careful.";
		close2;
		instance_event("#edda_journey_control","OnExploration01",false);
		end;
	}
	if(.@var >= 6)
		warp .@map$,42,156;
	end;
}

1@gol1,199,44,5	script	Synchronization Device#edda_lab_start-0	4_GC109,{
	.@var = get_instance_var("edda_lab");
	.@var2 = get_instance_var("edda_sync");
	if(.@var == 4){
		mes "[ Synchronization Device ]";
		mes "I'm cute and smart!";
		mes "Hello! I'm the Synchronization Device!";
		mes "I'll prepare the selection of path for you to choose!";
		npctalk "Sierra : Why is Nina's machine like this.",instance_npcname("Sierra#edda_lab_start-1");
		next;
		if(select("Synchronization guide.:Select path.") == 1){
			mes "[ Synchronization Device ]";
			mes "Let me tell you about the synchronization!";
			mes "Starting at this point, you are able to go to a specific memory and proceed with the Virtual Record interpretation.";
			next;
			mes "[ Synchronization Device ]";
			mes "You'll be back here when you are finish with the interpretation.";
			mes "You can wait here until the participants come back, or you can go help them with the interpretation!";
			next;
			mes "[ Synchronization Device ]";
			mes "I will assist you until the first interpretation of each locations is completed!";
			mes "I the cute and smart device will help you finish the path of your choosing!";
			next;
			mes "[ Synchronization Device ]";
			mes "When you're finish, the fun time with the synchronization device is over, though!";
			mes "You can continue to interpret with Sierra, who is stubborn, blunt, and scary!";
			npctalk "Sierra : Let's go outside and have a talk later, Nina.",instance_npcname("Sierra#edda_lab_start-1");
			next;
		}
		setarray .@lab$,"Swordsman","Acolyte","Thief","Mage","Merchant","Archer";
		for(.@i = 0; .@i < getarraysize(.@lab$); .@i++)
			.@menu$ += .@lab$[.@i] + " Laboratory" + ":";
		.@s = select(.@menu$) - 1;
		instance_event("#edda_journey_control","On" + .@lab$[.@s] + "Lab",true);
		end;
	}
	if(.@var >= 5){
		mes "[ Synchronization Device ]";
		mes "All the interpretations are now complete. I'm happy that you returned safely. But It's over!";
		mes "Sierra, who is stubborn, blunt, and scary, can continue to interpret it!";
		npctalk "Sierra : The Synchronization Device is not needed anymore. Please talk to me instead.",instance_npcname("Sierra#edda_lab_start-1");
		if(.@var2 == 0)
			set_instance_var("edda_sync",1);
	}
	end;
}

//= Exploration Mode

//= Meeting Room
function	script	edda_talk_finish	{
	setarray .@name$,"eremes","keyron","sorin","seyren","harword","shecil";
	.@size = getarraysize(.@name$);
	for(.@i = 0; .@i < .@size; .@i++)
		if(get_instance_var("edda_talk_" + .@name$[.@i]))
			.@talk++;
	if(.@talk == .@size)
		instance_event("#edda_journey_control","OnExploration00",true);
	return;
}

1@gol1,172,207,3	script	Eremes Guile#edda_lab_0	4_M_MD_EREMES,{
	.@var = get_instance_var("edda_lab");
	.@talk = get_instance_var("edda_talk_eremes");
	if(.@var == 2){
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "Damn, even as an assassin, dealing with poison gas is difficult.";
		close3;
	}
	if(!.@talk){
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "I'm not your colleague. I have nothing to do with the President.";
		mes "My mission here is to be Keyron's escort. How am I supposed to do that without my weapon?";
		next;
		cutin "bio_katrinn02",0;
		mes "[ Katrinn Keyron ]";
		mes "You're the same as usual.";
		mes "How long will you treat me like a child?";
		mes "I'm Katrinn Keyron. One of the strongest wizards recognized by the Geffen Magic Academy. Am I not?";
		next;
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "I doesn't matter. Whether you're the Katrinn Keyron or whatever, my job is to keep you safe.";
		npctalk "Keyron : Eremes, you're no fun.",instance_npcname("Katrinn Keyron#edda_lab_0");
		close2;
		cutin "",255;
		set_instance_var("edda_talk_eremes",1);
		edda_talk_finish();		
	} else {
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "My mission here is to be Keyron's escort. How am I supposed to do that without my weapon?";
		close2;
		cutin "",255;
	}
	end;
}

1@gol1,175,204,3	script	Katrinn Keyron#edda_lab_0	4_F_MD_KATRINN,{
	.@var = get_instance_var("edda_lab");
	.@talk = get_instance_var("edda_talk_keyron");
	if(.@var == 2){
		cutin "bio_katrinn02",0;
		mes "[ Katrinn Keyron ]";
		mes "Huh, this is weird. Why am I so sleepy? I am just fine a while ago!!!";
		close3;
	}
	if(!.@talk){
		cutin "bio_katrinn01",0;
		mes "[ Katrinn Keyron ]";
		mes "Why did they take our weapons?";
		mes "We are a state representative and we're being treated like assassins.";
		mes "What do they expect doing such thing.";
		next;
		mes "[ Katrinn Keyron ]";
		mes "My brother didn't give me an extra weapon, so I had to give up my only one. Stupid brother.";
		next;
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "Don't be alarmed. As you know, we're on a mission. We can't even have even the smallest disagreement.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Eremes is short tempered, but I believe he would listen to my sister.";
		npctalk "Keyron : Who taught such flattery to my brother?";
		close2;
		cutin "",255;
		set_instance_var("edda_talk_keyron",1);
		edda_talk_finish();
	} else {
		cutin "bio_katrinn01",0;
		mes "[ Katrinn Keyron ]";
		mes "Why did they take our weapons?";
		mes "We are a state representative and we're being treated like assassins.";
		close2;
		cutin "",255;
	}
	end;
}

1@gol1,170,200,5	script	Magaleta Sorin#edda_lab_0	4_F_MD_MAGALETA,{
	.@var = get_instance_var("edda_lab");
	.@talk = get_instance_var("edda_talk_sorin");
	if(.@var == 2){
		cutin "bio_sorin02",1;
		mes "[ Magaleta Sorin ]";
		mes "Why am I so sleepy all of a sudden...";
		mes "Huh... I feel so dizzy.";
		close3;
	}
	if(!.@talk){
		cutin "bio_sorin01",1;
		mes "[ Magaleta Sorin ]";
		mes "Are you nervous? It's my first time doing this. I'm excited.";
		next;
		mes "[ Magaleta Sorin ]";
		mes "I've been through lots of adversity during my training days... Oh, nevermind that.";
		next;
		mes "[ Magaleta Sorin ]";
		mes "Even if I'm nervous, it's important for Seyren, and I want to be around. I can't be at ease if he went alone.";
		npctalk "Seyren : Do you think I'm that bad?",instance_npcname("Seyren Windsor#edda_lab_0");
		npctalk "Sorin : That's different.";
		next;
		mes "[ Magaleta Sorin ]";
		mes "How can I leave such a naive child alone?";
		mes "I'll stand by his side.";
		npctalk "Seyren : What's different? Why are you only telling the adventurer?",instance_npcname("Seyren Windsor#edda_lab_0");
		close2;
		cutin "",255;
		set_instance_var("edda_talk_sorin",1);
		edda_talk_finish();
	} else {
		cutin "bio_sorin01",1;
		mes "[ Magaleta Sorin ]";
		mes "Are you nervous? It's my first time doing this. I'm excited.";
		close2;
		cutin "",255;
	}
	end;
}

1@gol1,172,198,1	script	Seyren Windsor#edda_lab_0	4_M_MD_SEYREN,{
	.@var = get_instance_var("edda_lab");
	.@talk = get_instance_var("edda_talk_seyren");
	if(.@var == 2){
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "Eremes! Did you bring any antidote?";
		mes "Eremes didn't take any... Ugh. You...";
		close3;
	}
	if(!.@talk){
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes strcharinfo(0) + ", I'm glad you came on time, even though the appointment was changed suddenly.";
		next;
		cutin "bio_sorin01",1;
		mes "[ Magaleta Sorin ]";
		mes "Seyren's Peco Peco ran away on the way here and it delayed our arrival here.";
		npctalk "Sorin : You've tied it up correctly this time, right?",instance_npcname("Magaleta Sorin#edda_lab_0");
		npctalk "Seyren : I tied it correctly the first time. Next time it's not going to get away.";
		next;
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "The Schwarzwald President's cooperation is essential if we want to ambush the Arunafeltz Cathedral to search for the king.";
		next;
		mes "[ Seyren Windsor ]";
		mes "I'm quite nervous. I have never done a job with such responsibilities before.";
		npctalk "Sorin : You'll do fine.",instance_npcname("Magaleta Sorin#edda_lab_0");
		close2;
		cutin "",255;
		set_instance_var("edda_talk_seyren",1);
		edda_talk_finish();
	} else {
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "I'm quite nervous. I have never done a job with such responsibilities before.";
		close2;
		cutin "",255;
	}
	end;
}

1@gol1,177,197,3	script	Harword Alt-Eisen#edda_lab_0	4_M_MD_HARWORD,{
	.@var = get_instance_var("edda_lab");
	.@talk = get_instance_var("edda_talk_harword");
	if(.@var == 2){
	}
	if(!.@talk){
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Sister, can I pour you a cup of tea? Or maybe some snacks?";
		mes "Woah, this is the first time I've seen this kind of thing. This looks amazing~";
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "I'm not going to eat any of that. Don't touch anything, you idiot. What's your first thought when we came here?";
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Don't tell me you're thinking that they'll poison us?";
		mes "You should relax and enjoy, it's always a nice experience to try something good.";
		npctalk "Howard : I'm always at the workshop, I don't usually get a chance to eat tasty food.";
		next;
		cutin "bio_shecil02",2;
		mes "[ Shecil Damon ]";
		mes "Idiot.";
		close2;
		cutin "",255;
		set_instance_var("edda_talk_harword",1);
		edda_talk_finish();
	} else {
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "I'm always at the workshop, I don't usually get a chance to eat tasty food.";
		mes "I'll be back there when the mission is over. I have to help out my sister first~";
		close2;
		cutin "",255;
	}
	end;
}

1@gol1,176,194,7	script	Shecil Damon#edda_lab_0	4_F_MD_SHECIL,{
	.@var = get_instance_var("edda_lab");
	.@talk = get_instance_var("edda_talk_shecil");
	if(.@var == 2){
		cutin "bio_shecil01",2;
		mes "[ Shecil Damon ]";
		mes "Come on, everyone, wake up!";
		mes "Prepare for the ambush... quick...!";
		close3;
	}
	if(!.@talk){
		cutin "bio_shecil01",2;
		mes "[ Shecil Damon ]";
		mes "Didn't they make you surrender your weapon? How did you manage to keep your weapon when you came?";
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "Did they search you?";
		mes "Tch, what's wrong with this expedition, it's full of idiots.";
		next;
		cutin "bio_sorin01",1;
		mes "[ Magaleta Sorin ]";
		mes "It's a reception for the president of another country. I know you're worried.";
		next;
		cutin "bio_shecil01",2;
		mes "[ Shecil Damon ]";
		mes "Yes. As you said, I should just ignore it. But I can't. I won't force you to understand.";
		close2;
		cutin "",255;
		set_instance_var("edda_talk_shecil",1);
		edda_talk_finish();
	} else {
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "You didn't give up your weapon when you came in didn't you?";
		mes "Tch, what's wrong with this expedition, it's full of idiots.";
		close2;
		cutin "",255;
	}
	end;
}

1@gol1,162,206,5	script	Security Officer#edda_lab_0	4_M_HUMAN_02,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 1){
		mes "[ Security Officer ]";
		mes "Please rest until the President arrives.";
		mes "We've prepared some food and refreshments, relax and enjoy yourselves.";
		close2;
		npctalk "Security Officer : What happened? Wasn't it supposed to be 6 people only?";
	}
	end;
}

1@gol1,168,207,3	script	Schwarzwald Soldier#edda_lab_0-1	4_M_EIN_SOLDIER,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 1){
		mes "[ Schwarzwald Soldier ]";
		mes "When will the signal come, I'm tired of waiting...";
		npctalk "Eremes : What signal.",instance_npcname("Eremes Guile#edda_lab_0");
		next;
		mes "[ Schwarzwald Soldier ]";
		mes "Huh?! It's nothing!";
		npctalk "Eremes : That's very suspicious.",instance_npcname("Eremes Guile#edda_lab_0");
		next;
		mes "[ Security Officer ]";
		mes "The signal is for the President's arrival.";
		mes "Rest until he comes, Ahah!";
		npctalk "Security Officer : Be careful of what you say and your action to avoid any misunderstandings.",instance_npcname("Security Officer#edda_lab_0");
		npctalk "Soldier : Roger!";
		close;
	}
	end;
}

1@gol1,169,205,3	script	Schwarzwald Soldier#edda_lab_0-2	4_M_EIN_SOLDIER,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 1){
		mes "[ Schwarzwald Soldier ]";
		mes "Do you need something? If you do, don't hesitate to ask.";
		next;
		cutin "bio_katrinn01",0;
		mes "[ Katrinn Keyron ]";
		mes "Oh, really, anything? In that case please return my weapon.";
		next;
		cutin "",255;
		mes "[ Schwarzwald Soldier ]";
		mes "Eh... Under the circumstances, it would be difficult.";
		next;
		cutin "bio_seyren03",1;
		mes "[ Seyren Windsor ]";
		mes "Keyron, I understand that you're anxious, but don't bother the officers.";
		npctalk "Keyron : It has nothing to do with being anxious, isn't it?",instance_npcname("Katrinn Keyron#edda_lab_0");
		close2;
		cutin "",255;
	}
	end;
}

1@gol1,163,205,5	duplicate(instancedummynpc)	Rekenber Guard#edda_lab_0-0	4_M_LGTGUARD
1@gol1,160,206,5	duplicate(instancedummynpc)	Rekenber Guard#edda_lab_0-1	4_M_LGTGUARD
1@gol1,160,204,5	duplicate(instancedummynpc)	Rekenber Guard#edda_lab_0-2	4_M_LGTGUARD
1@gol1,160,202,5	duplicate(instancedummynpc)	Rekenber Guard#edda_lab_0-3	4_M_LGTGUARD
1@gol1,163,203,5	duplicate(instancedummynpc)	Rekenber Guard#edda_lab_0-4	20541

1@gol1,166,203,3	script	Sierra#edda_lab_0-1	4_F_SCIENCE,{
	.@var = get_instance_var("edda_lab");
	.@map$ = get_instance_var("first_floor$");
	if(.@var == 3){
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "With these, Nina's adjustments allows me to intervine in the Virtual Record that you're interpreting.";
		mes "I'll tell you more in the situation Room.";
		close2;
		cutin "",255;
		warp .@map$,201,42;
	}
	end;
}


1@gol1,45,156,4	script	Seyren Windsor#edda_lab_1	4_M_MD_SEYREN,4,3,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 6){
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes strcharinfo(0) + "!";
		mes "I'm so glad you're safe.";
		npctalk "Seyren : I'm so glad you're safe.";
		next;
		mes "[ Seyren Windsor ]";
		mes "I woke up and found myself in some kind of lab.";
		mes "Strangely, no one was there when i woke up. I took that chance to escape immediately.";
		npctalk "Seyren : I woke up and found myself in some kind of lab. Strangely, no one was there when i woke up. I took that chance to escape immediately.";
		next;
		mes "[ Seyren Windsor ]";
		mes "I was struggling when we were attacked.";
		mes "Thank you so much for your help.";
		npctalk "Seyren : I was struggling when we were attacked. Thank you so much for your help.";
		next;
		mes "[ Seyren Windsor ]";
		mes "While searching the laboratory, I found some clues regarding the experiments.";
		mes "I learned more about the Battle Core and Ymir's heart fragments.";
		npctalk "Seyren While searching the laboratory, I found some clues regarding the experiments. I learned more about the Battle Core and Ymir's heart fragments";
		next;
		mes "[ Seyren Windsor ]";
		mes "I'm sure the Schwarzwald President isn't involved with these experiments right?";
		mes "We need to look for our colleagues so they don't get experimented on.";
		npctalk "Seyren : I'm sure the Schwarzwald President isn't involved with these experiments right? We need to look for our colleagues so they don't get experimented on.";
		next;
		cutin "",255;
		mes "[ Seyren Windsor ]";
		mes "We don't have time, so let's split up and gather information.";
		mes "I need you to stay on your guard.";
		npctalk "Seyren : We don't have time, so let's split up and gather information. I need you to stay on your guard.";
		instance_event("#edda_journey_control","OnExploration02",false);
	} 
	end;
	
OnTouch:
	.@var = get_instance_var("edda_lab");
	if(.@var == 6)
		emotion ET_SURPRISE;
end;
}

1@gol1,81,116,3	script	Seyren Windsor#edda_lab_2	4_M_MD_SEYREN,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 7){
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Eremes is acting weird. He doesn't seem like himself.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Oh, of course, he always looks like that. But, something's different, I can feel it.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Instead of me, could you try talking to him?";
		close3;
	}
	if(.@var == 8){
		npctalk "Seyren : We have to stop him somehow!";
		end;
	}
	if(.@var == 9)
		npctalk "Seyren : I was worried, Eremes.";
	end;
}

1@gol1,78,120,5	script	Eremes Guile#edda_lab_1	4_M_MD_EREMES,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 7){
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "...";
		npctalk "Eremes : ...";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Eremes, what's the matter?";
		mes "Why are you alone in this place?";
		npctalk "Seyren : Eremes, what's the matter? Why are you alone in this place?",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		mes "[ Seyren Windsor ]";
		mes "It's me, Seyren!";
		mes "Don't you recognize me?";
		npctalk "Seyren : It's me, Seyren! Don't you recognize me?",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "...";
		npctalk "Eremes : ...";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Eremes is acting weird. He doesn't seem like himself.";
		mes "And what happened to this lab, it's in a mess.";
		npctalk "Seyren : Eremes is acting weird. He doesn't seem like himself. And what happened to this lab, it's in a mess.",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		cutin "bio_eremes02",2;
		mes "[ Eremes Guile ]";
		mes "!";
		npctalk "Eremes : !";
		specialeffect EF_STIN6,AREA,instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "Ah!";
		npctalk "Seyren : Ah!",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		cutin "",255;
		select("We have to stop him.");
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "If you're a bit conscious, I'm begging you snap out of it.";
		mes "We have to stop him somehow!";
		mes "Please fight with me!";
		npctalk "Seyren : If you're a bit conscious, I'm begging you snap out of it. We have to stop him somehow! Please fight with me!",instance_npcname("Seyren Windsor#edda_lab_2");
		close2;
		cutin "",255;
		instance_event("#edda_exploration_mob","OnSummon00",false);
		end;
	}
	if(.@var == 9){
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "Stop hitting me. I'm conscious already. I don't know what's this all about.";
		npctalk "Eremes : Stop hitting me. I'm conscious already. I don't know what's this all about.";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Eremes!";
		npctalk "Seyren : Eremes!",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";		
		mes "There are many of them, and they got me from behind. But I think " + strcharinfo(0) + "'s done fighting.";
		npctalk "Eremes : There are many of them, and they got me from behind. But I think " + strcharinfo(0) + "'s done fighting.";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Take your time to regain your thoughts.";
		mes "I was worried that you won't snap out of it, Eremes!";
		npctalk "Seyren : Take your time to regain your thoughts. I was worried that you won't snap out of it, Eremes!",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "Alright. By the way... Ugh.";
		mes "My head hurts. I'm not in my peak form. What about you?";
		npctalk "Eremes : Alright. By the way... Ugh. My head hurts. I'm not in my peak form. What about you?";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Is that how badly you've been fighting. This doesn't look good. What can you remember Eremes?";
		npctalk "Seyren : Is that how badly you've been fighting. This doesn't look good. What can you remember Eremes?",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "Let me think. I'm sure that...-";
		npctalk "Eremes : Let me think. I'm sure that...-";
		next;
		mes "[ Eremes Guile ]";
		mes "...!!!";
		npctalk "Eremes : ...!!!";
		next;
		cutin "bio_eremes02",2;
		mes "[ Eremes Guile ]";
		mes "Seyren, there's no time to think.";
		mes "Keyron. Your sister is in danger!";
		npctalk "Eremes : Seyren, there's no time to think. Keyron. Your sister is in danger!";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "What about Keyron?";
		mes "Don't tell me she's being experimented on!";
		npctalk "Seyren : What about Keyron? Don't tell me she's being experimented on!",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		mes "[ Seyren Windsor ]";
		mes "There was a record of the prototype Battle Core in my laboratory.";
		mes "It was meant to increase the combat potential to the limit. I have to save her.";
		npctalk "Seyren : There was a record of the prototype Battle Core in my laboratory. It was meant to increase the combat potential to the limit. I have to save her.",instance_npcname("Seyren Windsor#edda_lab_2");
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "You must have done your own research too. Rekenber does things like this behind the scenes. It's not only Keyron. My body was also modified. I'm sure that it's the same for you, Seyren.";
		npctalk "Eremes : You must have done your own research too. Rekenber does things like this behind the scenes. It's not only Keyron. My body was also modified. I'm sure that it's the same for you, Seyren.";
		next;
		cutin "bio_eremes02",2;
		mes "[ Eremes Guile ]";
		mes "I tried to protect Keyron, but... I failed. I'm sorry Seyren.";
		mes "Let's find her quickly!";
		npctalk "Eremes : I tried to protect Keyron, but... I failed. I'm sorry Seyren. Let's find her quickly!";
		next;
		cutin "bio_eremes02",2;
		mes "[ Eremes Guile ]";
		mes "Let's get out of here and head south through the door.";
		mes "Let's regroup at the nearby laboratory there!";
		npctalk "Eremes : Let's get out of here and head south through the door. Let's regroup at the nearby laboratory there!";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Hey, " + strcharinfo(0) + ", did you got what Eremes said? Let's go meet down there!";
		npctalk "Seyren : Did you got what Eremes said? Let's go meet down there!",instance_npcname("Seyren Windsor#edda_lab_2");
		instance_hide("Seyren Windsor#edda_lab_2",true);
		instance_enable("Seyren Windsor#edda_lab_2",false);
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes strcharinfo(0) + ", We need to hurry!";
		npctalk "Eremes : We need to hurry!";
		next;
		cutin "",255;
		select("Black Blood?");
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "Please keep the black blood a secret from Seyren for now. Let's get going.";
		npctalk "Eremes : Please keep the black blood a secret from Seyren for now. Let's get going.";
		close2;
		cutin "",255;
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_event("#edda_journey_control","OnExploration03",false);
	}
	end;
}

1@gol1,122,40,5	script	Seyren Windsor#edda_lab_3	4_M_MD_SEYREN,{
	npctalk "Seyren : I'm going right in! I'll save Keyron!";
	end;
}

1@gol1,124,40,3	script	Eremes Guile#edda_lab_2	4_M_MD_EREMES,{
	npctalk "Eremes : Be quiet. Don't disturb me, I'm thinking.";
	end;
}

1@gol1,111,12,5	script	Seyren Windsor#edda_lab_4	4_M_MD_SEYREN,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 11){
		npctalk "Seyren : Keyron, Keyron!!!";
		end;
	}
	if(.@var == 12){
		.@keyron$ = instance_npcname("Katrinn Keyron#edda_lab_1");
		.@eremes$ = instance_npcname("Eremes Guile#edda_lab_3");
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Keyron, can you hear me? It's me! Seyren!!";
		npctalk "Seyren : Keyron, can you hear me? It's me! Seyren!!";
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "What's this machine, how do we release her?";
		mes "If we are only with the Whitesmith, we'd have no problem with this.";
		npctalk "Eremes : What's this machine, how do we release her? If we are only with the Whitesmith, we'd have no problem with this.",.@eremes$;
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "I'll use force to break it! " + strcharinfo(0) + ", Eremes, please stand back!";
		npctalk "Seyren : I'll use force to break it! Everyone, please stand back!";
		next;
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "Huh, where am I?";
		mes "No. This can't be, there's no way...";
		npctalk "Keyron : Huh, where am I? No. This can't be, there's no way...",.@keyron$;
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Keyron, are you awake?";
		npctalk "Seyren : Keyron, are you awake?";
		next;
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "I saw it again. That day... when I was three, was it a dream?";
		mes "Because of me, mother and my brother... covering me...";
		npctalk "Keyron : I saw it again. That day... when I was three, was it a dream? Because of me, mother and my brother... covering me...",.@keyron$;
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Keyron, that wasn't your fault.";
		mes "Let's go back. Wait a bit. I'll get you out!!";
		npctalk "Seyren : Keyron, that wasn't your fault. Let's go back. Wait a bit. I'll get you out!!";
		next;
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "I wanted to make it work, but... failed...";
		mes "I wanted to prove that I wasn't a coward hiding behind my brother.";
		npctalk "Keyron : I wanted to make it work, but... failed... I wanted to prove that I wasn't a coward hiding behind my brother.",.@keyron$;
		next;
		mes "[ Katrinn Keyron ]";
		mes "Ugh... You idiot, brother... of mine.";
		npctalk "Keyron : Ugh... You idiot, brother... of mine.",.@keyron$;
		next;
		mes "[ Katrinn Keyron ]";
		mes "No, I'm the idiot. It was my fault, I'm sorry.";
		npctalk "Keyron : No, I'm the idiot. It was my fault, I'm sorry.",.@keyron$;
		specialeffect EF_ICECRASH,AREA,.@keyron$;
		classchange 4_F_MD_KATRINN_D,.@keyron$;
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Keyron... Keyron!!!";
		mes "No!!!-- Keyron!-- Tch, Damn it all!";
		npctalk "Seyren : Keyron... Keyron!!! No!!!-- Keyron!-- Tch, Damn it all!";
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes ".....";
		npctalk "Eremes : .....",.@eremes$;
		set_instance_var("edda_lab",13);
		close2;
		cutin "",255;
		npctalk "Eremes : Go ahead, Seyren. I'll stay here a bit longer.",.@eremes$;
		end;
	}
	if(.@var == 13)
		npctalk "Seyren : Keyron, Keyron!!-";
	end;
}

1@gol1,113,15,3	script	Eremes Guile#edda_lab_3	4_M_MD_EREMES,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 11){
		npctalk "Eremes : Focus on the battle.";
	}
	if(.@var == 12){
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "Wait for Seyren to speak.";
		close3;
	}
	if(.@var == 13){
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "Go ahead, " + strcharinfo(0) + ".";
		mes "Take Seyren with you.";
		npctalk "Eremes : Go ahead, everyone. Take Seyren with you.";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Eremes? What are you planning?";
		npctalk "Seyren : Eremes? What are you planning?",instance_npcname("Seyren Windsor#edda_lab_4");
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "I'll take Keyron's body to a safe place.";
		mes "That way they won't be able to experiment on her anymore.";
		npctalk "Eremes : I'll take Keyron's body to a safe place. That way they won't be able to experiment on her anymore.";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Alright, Eremes.";
		mes "This is no time for this. I'll go find the others first.";
		npctalk "Seyren : Alright, Eremes. This is no time for this. I'll go find the others first.",instance_npcname("Seyren Windsor#edda_lab_4");
		next;
		mes "[ Seyren Windsor ]";
		mes "Please join us as soon as you're done.";
		npctalk "Seyren : Please join us as soon as you're done.",instance_npcname("Seyren Windsor#edda_lab_4");
		instance_hide("Seyren Windsor#edda_lab_4",true);
		instance_enable("Seyren Windsor#edda_lab_4",false);
		next;
		cutin "bio_eremes03",2;
		mes "[ Eremes Guile ]";
		mes "Are you not going?";
		npctalk "Eremes : Are you not going?";
		next;
		mes "[ Eremes Guile ]";
		mes "You must have noticed, " + strcharinfo(0) + ".";
		mes "That's right. The meaning of the Black Blood that I threw up.";
		npctalk "Eremes : You must have noticed it too. That's right. The meaning of the Black Blood that I threw up.";
		next;
		mes "[ Eremes Guile ]";
		mes "It's the side effect of the black blood. It's a sign that the implanted core is eroding the subject's body.";
		npctalk "Eremes : It's the side effect of the black blood. It's a sign that the implanted core is eroding the subject's body.";
		next;
		cutin "bio_eremes04",2;
		mes "[ Eremes Guile ]";
		mes "Ugh. Sooner than I expected.";
		npctalk "Eremes : Ugh. Sooner than I expected.";
		next;
		mes "[ Eremes Guile ]";
		mes "I won't last long.";
		mes "Keyron died in front of us, Seyren might not be able to think clearly.";
		npctalk "Eremes : I won't last long. Keyron died in front of us, Seyren might not be able to think clearly.";
		next;
		mes "[ Eremes Guile ]";
		mes "I have a favor to ask you. Please follow Seyren.";
		mes "The next lab is out the door and go north. Hope is the only thing we can do.";
		npctalk "Eremes : I have a favor to ask you. Please follow Seyren. The next lab is out the door and go north. Hope is the only thing we can do.";
		close2;
		cutin "",255;
		classchange 4_M_MD_EREMES_D,instance_npcname(strnpcinfo(0));
		instance_event("#edda_journey_control","OnExploration05",false);
		end;
	}
	if(.@var >= 14)
		npctalk "Eremes : ....";
	end;
}

1@gol1,111,7,0	script	Katrinn Keyron#edda_lab_1	4_F_MD_KATRINN,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 11){
		npctalk "Keyron : ...";
		end;
	}
	if(.@var == 12){
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "I missed you guys so much...";
		close3;
	}
	if(.@var >= 13)
		npctalk "Keyron : ...";
	end;
}

1@gol1,146,240,7	script	Seyren Windsor#edda_lab_5	4_M_MD_SEYREN,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 14){
		npctalk "Seyren : Harword, is that you?";
	}
	end;
}

1@gol1,148,243,3	script	Harword Alt-Eisen#edda_lab_1	4_M_MD_HARWORD,3,3,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 14){
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Shecil, Sister~";
		npctalk "Harword : Shecil, Sister~";
		next;
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "...?!";
		npctalk "Seyren : ...?!",instance_npcname("Seyren Windsor#edda_lab_5");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Shecil, is my sister~!!";
		npctalk "Harword : Shecil, is my sister~!!";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Uh, Harword?";
		npctalk "Seyren : Uh, Harword?",instance_npcname("Seyren Windsor#edda_lab_5");
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "!?";
		npctalk "Harword : !?";
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Oh, Seyren, it's you!";
		npctalk "Oh, Seyren, it's you!";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Harword!! Are you okay?!";
		npctalk "Seyren : Harword!! Are you okay?!",instance_npcname("Seyren Windsor#edda_lab_5");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Yeah. I'm in good condition, don't you think?";
		mes "When I woke up in the glass, It was a mess. I broke and escaped.";
		npctalk "Harword : Yeah. I'm in good condition, don't you think? When I woke up in the glass, It was a mess. I broke and escaped.";
		next;
		cutin "",255;
		select("You broke it?:By yourself?");
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Well, there wasn't anyone around that could help. Oddly I was alone when I came out.";
		mes "I had a hard time because I'm in worse condition than usual, but Harword the whitesmith isn't going to collapse easily!";
		npctalk "Harword : Well, there wasn't anyone around that could help. Oddly I was alone when I came out. I had a hard time because I'm in worse condition than usual, but Harword the whitesmith isn't going to collapse easily!";
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "By the way Seyren, have you met the others?";
		mes "Like Shecil, or Shecil, or possibly my sister Shecil.";
		npctalk "Harword : By the way Seyren, have you met the others? Like Shecil, or Shecil, or possibly my sister Shecil.";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Oh... we met the others. It wasn't Shecil. I met her, I...";
		npctalk "Seyren : Oh... we met the others. It wasn't Shecil. I met her, I...",instance_npcname("Seyren Windsor#edda_lab_5");
		next;
		cutin "",255;
		select("Tell what happened.");
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "I see, that's how it is.";
		npctalk "Harword : I see, that's how it is.";
		next;
		mes "[ Harword Alt-Eisen ]";
		mes "...";
		npctalk "Harword : ...";
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "All right! Now that the great Harword is with you, you can rest easy!";
		mes "I'm truly sorry to hear what happened. Keyron, I can't go back.";
		npctalk "Harword : All right! Now that the great Harword is with you, you can rest easy! I'm truly sorry to hear what happened. Keyron, I can't go back.";
		next;
		mes "[ Harword Alt-Eisen ]";
		mes "Let's go and beat up every single one of those guys that did those to Keyron!";
		mes "Also, let's find my sister Shecil and your fiancé as well.";
		npctalk "Harword : Let's go and beat up every single one of those guys that did those to Keyron! Also, let's find my sister Shecil and your fiancé as well.";
		next;
		mes "[ Harword Alt-Eisen ]";
		mes "And then we go out and figure out if it's the battle core or something!";
		mes "Whatever they did to our body, There is nothing that I, Harword can't fix!";
		npctalk "Harword : And then we go out and figure out if it's the battle core or something! Whatever they did to our body, There is nothing that I, Harword can't fix!";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Yes, that's sounds good.";
		npctalk "Seyren : Yes, that's sounds good.",instance_npcname("Seyren Windsor#edda_lab_5");
		next;
		select("Harword, you're really great.");
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Ahaha. Now, don't praise me. Seyren will hear you.";
		mes "I don't want him to be hurt more than this. I have to cheer him up.";
		npctalk "Harword : Ahaha. Now, don't praise me. Seyren will hear you. I don't want him to be hurt more than this. I have to cheer him up.";
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Alright, it's time to go! Let's find Shecil!";
		npctalk "Harword : Alright, it's time to go! Let's find Shecil!";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Oh, uh. Is that what we're doing?";
		npctalk "Seyren : Oh, uh. Is that what we're doing?",instance_npcname("Seyren Windsor#edda_lab_5");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Yes! Let's spread out and send a signal when you find anyone, okay?";
		mes "Let's go!";
		npctalk "Harword : Yes! Let's spread out and send a signal when you find anyone, okay? Let's go!";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Harword is always positive. I think we can do anything if he's with us.";
		npctalk "Seyren : Harword is always positive. I think we can do anything if he's with us.",instance_npcname("Seyren Windsor#edda_lab_5");
		next;
		mes "[ Seyren Windsor ]";
		mes "He's right. I can't just sit around. Now, let's look for them!";
		npctalk "Seyren : He's right. I can't just sit around. Now, let's look for them!",instance_npcname("Seyren Windsor#edda_lab_5");
		close2;
		cutin "",255;
		instance_event("#edda_journey_control","OnExploration06",false);
	}
	end;
	
OnTouch:
	emotion ET_SURPRISE;
end;
}

1@gol1,160,301,3	script	Harword Alt-Eisen#edda_lab_2	4_M_MD_HARWORD,{ 
	.@var = get_instance_var("edda_lab");
	.@map$ = get_instance_var("first_floor$");
	if(.@var < 17)
		end;
	if(.@var == 17){
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Shecil! She's so strong. I'm going to fall in love if this continues.";
		mes "I've been looking for you Shecil~!!";
		next;
		cutin "",255;
		mes "[ Harword Alt-Eisen ]";
		mes "Shecil! She's so strong. I'm going to fall in love if this continues.";
		mes "I've been looking for you Shecil~!!";
		mapannounce .@map$,"Shecil Damon : The best thing the enemy should say is silence. Don't listen to it.",bc_map,0xD2FFD2;
		npctalk "Shecil : The best thing the enemy should say is silence. Don't listen to it.",instance_npcname("Shecil Damon#edda_lab_1");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Ouch!";
		specialeffect EF_CLAYMORE;
		next;
		cutin "bio_shecil02",2;
		mes "[ Shecil Damon ]";
		mes "I'm a little relieved that you're as foolish as ever.";
		mapannounce .@map$,"Harword : Shecil~!",bc_map,0xD2FFD2;
		npctalk "Harword : Shecil~!";
		npctalk "Shecil : I'm a little relieved that you're as foolish as ever.",instance_npcname("Shecil Damon#edda_lab_1");
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Ugh, why did you do that.";
		mes "Of course, I always prepare for a situation like this, sister!";
		npctalk "Harword : Ugh, why did you do that. Of course, I always prepare for a situation like this, sister!";
		next;
		cutin "bio_shecil01",2;
		mes "[ Shecil Damon ]";
		mes "This idiot is still quite. Huh.";
		mes "Seyren, you look ridiculous.";
		npctalk "Shecil : This idiot is still quite. Huh. Seyren, you look ridiculous.",instance_npcname("Shecil Damon#edda_lab_1");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Huh? Uh, no.";
		mes "It's just that a lot happened. Let's find the others.";
		npctalk "Seyren : Huh? Uh, no. It's just that a lot happened. Let's find the others.",instance_npcname("Seyren Windsor#edda_lab_6");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "That's right! Now that we've found Shecil, I feel much safer.";
		mes "Now let's find your fiancé as well and wait for Eremes to regroup with us, then we can leave this place.";
		npctalk "Harword : That's right! Now that we've found Shecil, I feel much safer. Now let's find your fiancé as well and wait for Eremes to regroup with us, then we can leave this place.";
		next;
		cutin "bio_shecil04",2;
		mes "[ Shecil Damon ]";
		mes "...";
		npctalk "Shecil : ...",instance_npcname("Shecil Damon#edda_lab_1");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Huh, sister...";
		npctalk "Harword : Huh, sister...";
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "This is nothing. It won't kill me. I thought you had a joke on me, so I took advantage of it. In fact, I'm in a tight situation.";
		npctalk "Shecil : This is nothing. It won't kill me. I thought you had a joke on me, so I took advantage of it. In fact, I'm in a tight situation.",instance_npcname("Shecil Damon#edda_lab_1");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Don't force it.";
		npctalk "Harword : Don't force it.";
		next;
		cutin "bio_shecil04",2;
		mes "[ Shecil Damon ]";
		mes "Do you think we should hold back? I mean, It's, ugh...";
		npctalk "Shecil : Do you think we should hold back? I mean, It's, ugh...",instance_npcname("Shecil Damon#edda_lab_1");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Shecil!";
		npctalk "Seyren : Shecil!",instance_npcname("Seyren Windsor#edda_lab_6");
		instance_hide("Magaleta Sorin#edda_lab_1",false);
		next;
		cutin "bio_sorin01",1;
		mes "[ Magaleta Sorin ]";
		mes "...";
		npctalk "Sorin : ...",instance_npcname("Magaleta Sorin#edda_lab_1");
		specialeffect EF_BLESSING;
		specialeffect EF_BLESSING,AREA,instance_npcname("Seyren Windsor#edda_lab_6");
		specialeffect EF_BLESSING,AREA,instance_npcname("Shecil Damon#edda_lab_1");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Sorin?";
		mes "You're safe! Sorin!!!";
		npctalk "Seyren : Sorin? You're Safe! Sorin!!!",instance_npcname("Seyren Windsor#edda_lab_6");
		next;
		cutin "bio_sorin01",1;
		mes "[ Magaleta Sorin ]";
		mes "Sey...ren...";
		npctalk "Sorin : Sey...ren...",instance_npcname("Magaleta Sorin#edda_lab_1");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Sorin...?";
		npctalk "Seyren : Sorin...?",instance_npcname("Seyren Windsor#edda_lab_6");
		instance_hide("Magaleta Sorin#edda_lab_1",true);
		instance_enable("Magaleta Sorin#edda_lab_1",false);
		instance_enable("Magaleta Sorin#edda_lab_2",true);
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "She's gone.";
		npctalk "Shecil : She's gone.",instance_npcname("Shecil Damon#edda_lab_1");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "There's a strange voice. I can hear it inside my head. It must be Sorin!!!";
		npctalk "Seyren : There's a strange voice. I can hear it inside my head. It must be Sorin!!!",instance_npcname("Seyren Windsor#edda_lab_6");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Come on, let's catch up. Let's go through the hallway at the north.";
		npctalk "Harword : Come on, let's catch up. Let's go through the hallway at the north.";
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Yeah, let's go! Sorin, if you're safe, we'll find you!!";
		npctalk "Seyren : Yeah, let's go! Sorin, if you're safe, we'll find you!!",instance_npcname("Seyren Windsor#edda_lab_6");
		close2;
		cutin "",255;
		instance_event("#edda_journey_control","OnExploration07",false);
	}
	end;
}

1@gol1,160,296,3	script	Shecil Damon#edda_lab_1	4_F_MD_SHECIL,{
	npctalk "Shecil : I'm glad this idiot is still alive.";
	end;
}

1@gol1,156,299,5	script	Nameless Swordsman#edda_lab_0	20537,{
	npctalk "Nameless Swordsman : ...";
	end;
}

1@gol1,156,302,5	script	Wolfchev#edda_lab_0	4_LGTSCIENCE,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 15){
		npctalk "Wolfchev : Don't disturb me. I'm reviewing this battle.";
		end;
	}
	end;
}

1@gol1,166,299,3	script	Magaleta Sorin#edda_lab_1	4_F_MD_MAGALETA,{ end; }

1@gol1,163,298,3	script	Seyren Windsor#edda_lab_6	4_M_MD_SEYREN,3,3,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 15){
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "Who is this people...?";
		npctalk "Seyren : Who is this people?";
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "You're a suspicious looking bunch.";
		npctalk "Harword : You're a suspicious looking bunch.",instance_npcname("Harword Alt-Eisen#edda_lab_2");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Who are you, what are you doing here? Are you one of the one who were dragged into this lab? Or are you the one who did the experiments?";
		npctalk "Seyren : Who are you, what are you doing here? Are you one of the one who were dragged into this lab? Or are you the one who did the experiments?";
		next;
		cutin "bio_worsev03",2;
		mes "[ Wolfchev ]";
		mes "Hahahah!";
		mes "That's brilliant. Both are correct.";
		npctalk "Wolfchev : Hahahah! That's brilliant. Both are correct.",instance_npcname("Wolfchev#edda_lab_0");
		next;
		cutin "bio_worsev01",2;
		mes "[ Wolfchev ]";
		mes "Let's start with a greeting. You're my failure. And the one over here is my cute kid. My greatest work so far.";
		npctalk "Wolfchev : Let's start with a greeting. You're my failure. And the one over here is my cute kid. My greatest work so far.",instance_npcname("Wolfchev#edda_lab_0");
		next;
		cutin "bio_ygnizem02",0;
		mes "[ Nameless Swordsman ]";
		mes "...";
		npctalk "Nameless Swordsman : ...",instance_npcname("Nameless Swordsman#edda_lab_0");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "You're very unpleasant when you talk about us.";
		mes "Seyren, I think we know which one we're going to catch.";
		npctalk "Harword : You're very unpleasant when you talk about us. Seyren, I think we know which one we're going to catch.",instance_npcname("Harword Alt-Eisen#edda_lab_2");
		next;
		cutin "bio_worsev01",2;
		mes "[ Wolfchev ]";
		mes "Oh, no, no, you don't get it at all. First of all, you're the failure, you we're pretty good as a starting subject though.";
		mes "Isn't that right? Seyren Windsor. My masterpiece.";
		npctalk "Wolfchev : Oh, no, no, you don't get it at all. First of all, you're the failure, you we're pretty good as a starting subject though. Isn't that right? Seyren Windsor. My masterpiece.",instance_npcname("Wolfchev#edda_lab_0");
		next;
		mes "[ Wolfchev ]";
		mes "You need to work harder to reach me. But before that, I came here to test my masterpiece.";
		npctalk "Wolfchev : You need to work harder to reach me. But before that, I came here to test my masterpiece.",instance_npcname("Wolfchev#edda_lab_0");
		next;
		cutin "bio_worsev03",2;
		mes "[ Wolfchev ]";
		mes "Hahaha. Through experience, you will become the perfect subject.";
		mes "Well, I'm looking forward to it. Then do your best to become perfect.";
		npctalk "Wolfchev : Hahaha. Through experience, you will become the perfect subject. Well, I'm looking forward to it. Then do your best to become perfect.",instance_npcname("Wolfchev#edda_lab_0");
		next;
		cutin "bio_ygnizem01",0;
		mes "[ Nameless Swordsman ]";
		mes "...!";
		npctalk "Nameless Swordsman : ...!",instance_npcname("Nameless Swordsman#edda_lab_0");		
		close2;
		cutin "",255;
		instance_event("#edda_exploration_mob","OnSummon02",false);
		end;
	}
	if(.@var == 16)
		npctalk "Seyren : Please focus on the battle.";
	end;
	
OnTouch:
	.@var = get_instance_var("edda_lab");
	if(.@var == 15){
		emotion ET_SURPRISE;
		npctalk "Seyren : Who are you people?";
	}
end;
}

1@gol1,190,325,3	script	Magaleta Sorin#edda_lab_2	4_F_MD_MAGALETA,{
	cutin "bio_sorin02",1;
	mes "[ Magaleta Sorin ]";
	mes "...";
	npctalk "Sorin : ...";
	close3;
}

1@gol1,186,321,7	script	Seyren Windsor#edda_lab_7	4_M_MD_SEYREN,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 18){
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Sorin, wait!";
		npctalk "Seyren : Sorin, wait!";
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "She didn't even look back at all.";
		npctalk "Harword : She didn't even look back at all.",instance_npcname("Harword Alt-Eisen#edda_lab_3");
		next;
		cutin "bio_shecil04",2;
		mes "[ Shecil Damon ]";
		mes "That may not be Sorin...";
		npctalk "Shecil : That may not be Sorin...",instance_npcname("Shecil Damon#edda_lab_2");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "What do you mean? We all love Sorin, don't we? Did you see an illusion?";
		npctalk "Seyren : What do you mean? We all love Sorin, don't we? Did you see an illusion?";
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "We'll learn the truth by following her. Let's go upstairs.";
		npctalk "Shecil : We'll learn the truth by following her. Let's go upstairs.",instance_npcname("Shecil Damon#edda_lab_2");
		close2;
		cutin "",255;
		instance_event("#edda_journey_control","OnExploration08",false);
	}
	end;
}

1@gol1,188,318,7	script	Harword Alt-Eisen#edda_lab_3	4_M_MD_HARWORD,{
	npctalk "Harword : It's been full of strange events. I have a feeling it's about to get worse.";
	end;
}

1@gol1,192,320,1	script	Shecil Damon#edda_lab_2	4_F_MD_SHECIL,{
	npctalk "Shecil : I have an idea. But I don't want to make a hasty guess.";
	end;
}

1@gol2,50,22,7	script	Seyren Windsor#edda_lab_8	4_M_MD_SEYREN,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 19){
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Sorin, please look at me. Where are you going?";
		npctalk "Seyren : Sorin, please look at me. Where are you going?";
		next;
		cutin "bio_sorin02",1;
		mes "[ Magaleta Sorin ]";
		mes "...";
		npctalk "Sorin : ...",instance_npcname("Magaleta Sorin#edda_lab_3");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Why are you looking at me like that?";
		mes "Please, answer me!";
		npctalk "Seyren : Why are you looking at me like that? Please, answer me!";
		instance_hide("Magaleta Sorin#edda_lab_3",true);
		instance_enable("Magaleta Sorin#edda_lab_3",false);
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "Seyren. This doesn't feel right. Maybe that's not Sorin.";
		npctalk "Shecil : Seyren. This doesn't feel right. Maybe that's not Sorin.",instance_npcname("Shecil Damon#edda_lab_3");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "How is that possible? She's just standing right in front of me. I don't believe it.";
		npctalk "Seyren : How is that possible? She's just standing right in front of me. I don't believe it.";
		next;
		cutin "bio_shecil01",2;
		mes "[ Shecil Damon ]";
		mes "Maybe the truth lies there, I'm afraid it isn't impossible.";
		mes "Let's catch up. We will know once we get there.";
		npctalk "Shecil : Maybe the truth lies there, I'm afraid it isn't impossible. Let's catch up. We will know once we get there.";
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "I don't know why, but I'm really creeped out, can you feel it too?";
		mes "I want to be embraced by my sister's warm arms.";
		npctalk "Harword : I don't know why, but I'm really creeped out, can you feel it too? I want to be embraced by my sister's warm arms.",instance_npcname("Harword Alt-Eisen#edda_lab_4");
		sleep2 500;
		mes "Ouch!!!";
		npctalk "Harword : Ouch!!!",instance_npcname("Harword Alt-Eisen#edda_lab_4");
		specialeffect EF_CLAYMORE,AREA,instance_npcname("Harword Alt-Eisen#edda_lab_4");
		next;
		cutin "bio_shecil02",2;
		mes "[ Shecil Damon ]";
		mes "How about this, is it warm now? Let's go.";
		npctalk "Shecil : How about this, is it warm now? Let's go.",instance_npcname("Shecil Damon#edda_lab_3");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Yes, right away sister~!!";
		npctalk "Harword : Yes, right away sister~!!",instance_npcname("Harword Alt-Eisen#edda_lab_4");
		instance_hide("Shecil Damon#edda_lab_3",true);
		instance_enable("Shecil Damon#edda_lab_3",false);
		close2;
		cutin "",255;
		instance_event("#edda_journey_control","OnExploration09",false);
	}
	end;
}

1@gol2,48,24,7	script	Harword Alt-Eisen#edda_lab_4	4_M_MD_HARWORD,{
	npctalk "Harword : Seyren is confused. Please talk to him.";
	end;
}

1@gol2,52,25,1	script	Shecil Damon#edda_lab_3	4_F_MD_SHECIL,{
	npctalk "Shecil : Even if it's hard to believe, you shouldn't turn a blind eye to what you've seen.";
	end;
}

1@gol2,49,29,1	script	Magaleta Sorin#edda_lab_3	4_F_MD_MAGALETA,{
	npctalk "Sorin : ...";
	end;
}

1@gol2,50,63,7	script	Seyren Windsor#edda_lab_9	4_M_MD_SEYREN,3,3,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 20){
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Sorin!!! What the hell is this place. What's going on?";
		mes "Eremes, and Keyron too? I saw Keyron died with my own eyes!!";
		npctalk "Seyren : Sorin!!! What the hell is this place. What's going on? Eremes, and Keyron too? I saw Keyron died with my own eyes!!";
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "Don't deny the reality Seyren. I'm sure you've seen the reports.";
		mes "This is what becomes of the people who have been implanted Battle Cores.";
		npctalk "Shecil : Don't deny the reality Seyren. I'm sure you've seen the reports. This is what becomes of the people who have been implanted Battle Cores.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		mes "[ Shecil Damon ]";
		mes "Once the core starts to overpower the body, It will trigger the black blood reaction and the mind changes after death.";
		npctalk "Shecil : Once the core starts to overpower the body, It will trigger the black blood reaction and the mind changes after death.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		mes "[ Shecil Damon ]";
		mes "Look ahead, Seyren. That's Sorin and two dead comrades, They're spirits now. Soon we will be also like that.";
		npctalk "Shecil : Look ahead, Seyren. That's Sorin and two dead comrades, They're spirits now. Soon we will be also like that.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Wait, look over there. There's something where the spirits are being created.";
		npctalk "Harword : Wait, look over there. There's something where the spirits are being created.",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "You're right... Sorin, Eremes, and ...?!";
		npctalk "Shecil : You're right... Sorin, Eremes, and ...?!",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Seyren...?";
		npctalk "Seyren...?",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "What? That's absurd.";
		npctalk "Seyren : What? That's absurd.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Wait, so that means, don't tell me.";
		npctalk "Seyren : Wait, so that means, don't tell me.";
		next;
		mes "[ Seyren Windsor ]";
		mes "I'm already dead?";
		mes "According to the report, now I'm...";
		npctalk "Seyren : I'm already dead? According to the report, now I'm...";
		next;
		instance_hide("Wolfchev#edda_lab_1",false);
		instance_hide("Nameless Swordsman#edda_lab_1",false);
		cutin "bio_worsev03",2;
		mes "[ Wolfchev ]";
		mes "Yes, you're the first one to have such a perfect consciousness.";
		npctalk "Wolfchev : Yes, you're the first one to have such a perfect consciousness.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		mes "[ Wolfchev ]";
		mes "Even those spirits, they respond to your will. I've never had such a perfect subject like you, Seyren Windsor.";
		npctalk "Wolfchev : Even those spirits, they respond to your will. I've never had such a perfect subject like you, Seyren Windsor.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "You damn bastard!!";
		npctalk "Shecil : You damn bastard!!",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		cutin "bio_worsev01",2;
		mes "[ Wolfchev ]";
		mes "Should a lady speak like that?";
		mes "You were a pretty interesting subject yourself, Shecil Damon.";
		mes "Even though you've read about the black blood reaction, you've been testing the core's power aggressively.";
		npctalk "Wolfchev : Should a lady speak like that? You were a pretty interesting subject yourself, Shecil Damon.  Even though you've read about the black blood reaction, you've been testing the core's power aggressively.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_worsev03",2;
		mes "[ Wolfchev ]";
		mes "But your body doesn't seem it can handle anymore, I'm afraid. I can't say you're the best subject. Hahahaha!!";
		npctalk "Wolfchev : But your body doesn't seem it can handle anymore, I'm afraid. I can't say you're the best subject. Hahahaha!!",instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Shecil...";
		npctalk "Harword : Shecil...",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_shecil04",2;
		mes "[ Shecil Damon ]";
		mes "It's the truth. Maybe there's no chance of surviving here.";
		npctalk "Shecil : It's the truth. Maybe there's no chance of surviving here.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		cutin "bio_worsev03",2;
		mes "[ Wolfchev ]";
		mes "Heh, Hahahaha!!";
		mes "Exactly. But your death will be worthwhile. I rarely see such great experimental subjects.";
		npctalk "Wolfchev : Heh, Hahahaha!! Exactly. But your death will be worthwhile. I rarely see such great experimental subjects.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		mes "[ Wolfchev ]";
		mes "Seyren Windsor, your excellent adaptability and reaction is a step forward for the experiment.";
		mes "At this rate, the completion of the Battle core will soon be finished. Hahahah!!";
		npctalk "Wolfchev : Seyren Windsor, your excellent adaptability and reaction is a step forward for the experiment. At this rate, the completion of the Battle core will soon be finished. Hahahah!!",instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "You, you!!! You're behind all of this!!! I will never forgive you!";
		npctalk "Seyren : You, you!!! You're behind all of this!!! I will never forgive you!";
		next;
		cutin "bio_worsev01",2;
		mes "[ Wolfchev ]";
		mes "I couldn't care less about that. The final experiment still remains.";
		mes "You've already met, but this is quite different from the one you've fought before.";
		npctalk "Wolfchev : I couldn't care less about that. The final experiment still remains. You've already met, but this is quite different from the one you've fought before.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		mes "[ Wolfchev ]";
		mes "Right now, it's the best thing to do.";
		mes "Seyren, I've adapted your battle core to get the best result out of this experiment.";
		npctalk "Wolfchev : Right now, it's the best thing to do. Seyren, I've adapted your battle core to get the best result out of this experiment.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_ygnizem02",0;
		mes "[ Nameless Swordsman ]";
		mes "Ugh...";
		npctalk "Nameless Swordsman : Ugh...",instance_npcname("Nameless Swordsman#edda_lab_1");
		next;
		cutin "bio_worsev02",2;
		mes "[ Wolfchev ]";
		mes "After the battle, they'll be torn apart to the point where they won't be even conscious. But, that's fine. I'll get Seyren afterwards.";
		npctalk "Wolfchev : After the battle, they'll be torn apart to the point where they won't be even conscious. But, that's fine. I'll get Seyren afterwards.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_shecil04",2;
		mes "[ Shecil Damon ]";
		mes "You can't just do nothing after listening to that, can you? Let's fight. I'll beat them to death.";
		npctalk "Shecil : You can't just do nothing after listening to that, can you? Let's fight. I'll beat them to death.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes "Doing nothing was never an option. I came here to save everyone, even if I have to die. I will fight until the end.";
		npctalk "Seyren : Doing nothing was never an option. I came here to save everyone, even if I have to die. I will fight until the end.";
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Then I'll have to play my part too! It's okay if people don't understand me! Here goes the great Harword Alt-Eisen!!";
		npctalk "Harword : Then I'll have to play my part too! It's okay if people don't understand me! Here goes the great Harword Alt-Eisen!!",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "I'm sure Shecil will remember me, so anything is fine.";
		npctalk "Harword : I'm sure Shecil will remember me, so anything is fine.",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_seyren04",1;
		mes "[ Seyren Windsor ]";
		mes strcharinfo(0) + ", we've all made up our minds.";
		mes "We're going to fight until the end.";
		npctalk "Seyren : We've all made up our minds. We're going to fight until the end.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Will you join us?";
		next;
		select("No need to ask.: I will fight with you.");
		cutin "bio_worsev03",2;
		mes "[ Wolfchev ]";
		mes "The more data, the better. Then please, do your part will all your power! Let's exploit the future, my pitiful and lovely subjects.";
		npctalk "Wolfchev : The more data, the better. Then please, do your part will all your power! Let's exploit the future, my pitiful and lovely subjects.",instance_npcname("Wolfchev#edda_lab_1");
		close2;
		cutin "",255;
		instance_event("#edda_exploration_mob","OnSummon03",false);
		end;
	}
	if(.@var == 22){
		cutin "bio_worsev02",2;
		mes "[ Wolfchev ]";
		mes "Damn it! I can't believe I'm going to get out of here empty handed. What a failure!";
		mes "That's it. The results came out anyway. It can be discarded.";
		npctalk "Wolfchev : Damn it! I can't believe I'm going to get out of here empty handed. What a failure! That's it. The results came out anyway. It can be discarded.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_harword05",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Don't think you can just run away like that!";
		npctalk "Harword : Don't think you can just run away like that!",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_shecil05",2;
		mes "[ Shecil Damon ]";
		mes "Don't let him escape! We can't let him continue with these kinds of experiments.";
		npctalk "Shecil : Don't let him escape! We can't let him continue with these kinds of experiments.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		instance_hide("Katrinn Keyron#edda_lab_2",false);
		instance_hide("Eremes Guile#edda_lab_4",false);
		instance_hide("Magaleta Sorin#edda_lab_4",false);
		cutin "bio_katrinn04",0;
		mes "[ Katrinn Keyron ]";
		mes "...";
		npctalk "Keyron : ...",instance_npcname("Katrinn Keyron#edda_lab_2");
		specialeffect EF_LIGHTBOLT,AREA,instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_eremes05",2;
		mes "[ Eremes Guile ]";
		mes "...!";
		npctalk "Eremes : ...!",instance_npcname("Eremes Guile#edda_lab_4");
		specialeffect EF_STIN6,AREA,instance_npcname("Wolfchev#edda_lab_1");
		specialeffect EF_NPC_BURNT,AREA,instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_worsev02",2;
		mes "[ Wolfchev ]";
		mes "I'm... ugh, how did you? They've completely lost their minds.";
		npctalk "Wolfchev : I'm... ugh, how did you? They've completely lost their minds.",instance_npcname("Wolfchev#edda_lab_1");
		next;
		cutin "bio_harword05",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Stop him! He's using a butterfly wing to escape!";
		npctalk "Harword : Stop him! He's using a butterfly wing to escape!",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		specialeffect EF_PORTAL,AREA,instance_npcname("Wolfchev#edda_lab_1");
		instance_hide("Wolfchev#edda_lab_1",true);
		instance_enable("Wolfchev#edda_lab_1",false);
		next;
		mes "[ Harword Alt-Eisen ]";
		mes "Damn it!";
		npctalk "Harword : Damn it!",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_seyren05",1;
		mes "[ Seyren Windsor ]";
		mes "Sorin, Keyron, Eremes...";
		npctalk "Seyren : Sorin, Keyron, Eremes...";
		next;
		mes "[ Seyren Windsor ]";
		mes "Do you still recognize me? Did you... fight?";
		npctalk "Seyren : Do you still recognize me? Did you... fight?";
		next;
		cutin "bio_katrinn04",0;
		mes "[ Katrinn Keyron ]";
		mes "...";
		npctalk "Keyron : ...",instance_npcname("Katrinn Keyron#edda_lab_2");
		next;
		cutin "bio_eremes05",2;
		mes "[ Eremes Guile ]";
		mes "...";
		npctalk "Eremes : ...",instance_npcname("Eremes Guile#edda_lab_4");
		next;
		cutin "bio_harword05",2;
		mes "[ Harword Alt-Eisen ]";
		mes "I thought so, there's no way out of here. All exits have been sealed off. And it seems we're also reaching our limits.";
		npctalk "Harword : I thought so, there's no way out of here. All exits have been sealed off. And it seems we're also reaching our limits.",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		specialeffect EF_TETRA,AREA,instance_npcname("#edda_explore_ef");
		next;
		cutin "bio_seyren05",1;
		mes "[ Seyren Windsor ]";
		mes "Yes, I'm really sorry everyone... that it's going to end like this.";
		mes "I can't save everyone, without telling the truth out there.";
		npctalk "Seyren : Yes, I'm really sorry everyone... that it's going to end like this. I can't save everyone, without telling the truth out there.";
		next;
		cutin "",255;
		select("I don't think so.:Point it to me.");
		.@map$ = get_instance_var("second_floor$");
		mapannounce .@map$,"Sierra : You'd better not say anything more!",bc_map,0xD2D2FF;
		cutin "bio_harword05",2;
		mes "[ Harword Alt-Eisen ]";
		mes strcharinfo(0) + "? What do you mean?";
		npctalk "Harword : What do you mean?",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "",255;
		select("Reveal why you're here.");
		mapannounce .@map$,"Sierra : All the data we've accumulated so far will be corrupted if you continue.",bc_map,0xD2D2FF;
		cutin "bio_seyren05",1;
		mes "[ Seyren Windsor ]";
		mes "That's a hard story to believe. But I started to think there was something off with you.";
		npctalk "Seyren : That's a hard story to believe. But I started to think there was something off with you.";
		next;
		cutin "bio_harword05",2;
		mes "[ Harword Alt-Eisen ]";
		mes "I saw you fighting and you didn't get a battle core implanted on you. I didn't say anything out of fear that it would confuse everyone, I thought you were a spy.";
		npctalk "Harword : I saw you fighting and you didn't get a battle core implanted on you. I didn't say anything out of fear that it would confuse everyone, I thought you were a spy.",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_shecil05",2;
		mes "[ Shecil Damon ]";
		mes "Even though you were safe, you fought with more anger than we did even while we had our core implanted? Is this the record you're talking about.";
		npctalk "Shecil : Even though you were safe, you fought with more anger than we did even while we had our core implanted? Is this the record you're talking about.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		cutin "bio_seyren05",1;
		mes "[ Seyren Windsor ]";
		mes "Sometimes you show up places that we couldn't see or in places where we looked away for a second. It's funny but I have to believe you, but I don't want to.";
		npctalk "Seyren : Sometimes you show up places that we couldn't see or in places where we looked away for a second. It's funny but I have to believe you, but I don't want to.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Please understand. It's hard to accept that you're just a record of the past.";
		npctalk "Seyren : Please understand. It's hard to accept that you're just a record of the past.";
		next;
		cutin "",255;
		select("It's the truth.:It's a lie.");
		mapannounce .@map$,"Sierra : If they don't accept it, we have to destroy this interpretation.",bc_map,0xD2D2FF;
		cutin "bio_seyren05",1;
		mes "[ Seyren Windsor ]";
		mes "I can't believe it, but. I'd like to believe it.";
		mes "What we've been through, this terrible truth. The fact that you will know it.";
		npctalk "Seyren : What we've been through, this terrible truth. The fact that you will know it.";
		next;
		select("I promise to deliver the truth.");
		cutin "bio_shecil05",2;
		mes "[ Shecil Damon ]";
		mes "Yeah, at least our deaths are not just meaningless.";
		mes "You've seen how it began and how it ended.";
		npctalk "Shecil : Yeah, at least our deaths are not just meaningless. You've seen how it began and how it ended.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		cutin "bio_harword05",2;
		mes "[ Harword Alt-Eisen ]";
		mes "That's much better. I feel a bit more at ease now. Atleast that's how I feel.";
		npctalk "Harword : That's much better. I feel a bit more at ease now. Atleast that's how I feel.",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		next;
		cutin "bio_seyren05",1;
		mes "[ Seyren Windsor ]";
		mes "If we ever met in the future. Please tell me all of this.";
		mes "We haven't finished our mission, but your presence is a glimpse of hope for us.";
		npctalk "Seyren : If we ever met in the future. Please tell me all of this. We haven't finished our mission, but your presence is a glimpse of hope for us.";
		next;
		mes "[ Seyren Windsor ]";
		mes "I would really appreciate it.";
		npctalk "Seyren : I would really appreciate it.";
		next;
		cutin "bio_harword05",2;
		mes "[ Harword Alt-Eisen ]";
		mes "What's that noise? Ugh, it hurts, stop it!!";
		npctalk "Harword : What's that noise? Ugh, it hurts, stop it!!",instance_npcname("Harword Alt-Eisen#edda_lab_5");
		specialeffect EF_TETRA,AREA,instance_npcname("#edda_explore_ef");
		next;
		cutin "",255;
		select("This place will be buried.:Wolfchev will destroy this place.");
		cutin "bio_shecil05",2;
		mes "[ Shecil Damon ]";
		mes "Damn it, he's going to bury us? Our bodies and the other experiments that are in this place.";
		npctalk "Shecil : Damn it, he's going to bury us? Our bodies and the other experiments that are in this place.",instance_npcname("Shecil Damon#edda_lab_4");
		next;
		cutin "bio_seyren05",1;
		mes "[ Seyren Windsor ]";
		mes "He was planning to cover up everything from the beginning. As soon he escaped the laboratory started collapsing.";
		npctalk "Seyren : He was planning to cover up everything from the beginning. As soon he escaped the laboratory started collapsing.";
		next;
		cutin "bio_seyren06",1;
		mes "[ Seyren Windsor ]";
		mes "I think it's really over.";
		npctalk "Seyren : I think it's really over.";
		next;
		cutin "bio_seyren05",1;
		mes "[ Seyren Windsor ]";
		mes "Huh, what's...";
		close2;
		cutin "",255;
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_event("#edda_journey_control","OnExploration10",false);
	}
	end;
	
OnTouch:
	emotion ET_SURPRISE;
end;
}

1@gol2,48,63,7	script	Harword Alt-Eisen#edda_lab_5	4_M_MD_HARWORD,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 20){
		npctalk "Harword : It's freezing here. You're gonna have to wear some clothes.";
		end;
	}
	npctalk "Harword : ...";
	end;
}

1@gol2,52,63,1	script	Shecil Damon#edda_lab_4	4_F_MD_SHECIL,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 20){
		npctalk "Shecil : The idiot is shaking. You're not scared, are you?";
		end;
	}
	npctalk "Shecil : ...";
	end;
}

1@gol2,51,67,3	script	Wolfchev#edda_lab_1	4_LGTSCIENCE,{
	npctalk "Wolfchev : Your sacrifices will be the foundation of the future. You can take pride in yourselves.";
	end;
}

1@gol2,49,67,5	script	Nameless Swordsman#edda_lab_1	20537,{
	npctalk "Nameless Swordsman : ...";
	end;
}

1@gol2,51,70,3	script	Katrinn Keyron#edda_lab_2	4_F_MD_KATRINN_H,{
	cutin "bio_katrinn04",0;
	mes "[ Katrinn Keyron ]";
	mes "...";
	close3;
}

1@gol2,53,70,3	script	Eremes Guile#edda_lab_4	4_M_MD_EREMES_H,{
	cutin "bio_eremes05",2;
	mes "[ Eremes Guile ]";
	mes "...";
	close3;
}

1@gol2,54,67,3	script	Magaleta Sorin#edda_lab_4	4_F_MD_MAGALETA_H,{
	cutin "bio_sorin03",1;
	mes "[ Magaleta Sorin ]";
	mes "...";
	close3;
}

1@gol2,45,67,5	script	Harword Alt-Eisen#edda_lab_6	4_M_MD_HARWORD_H,{
	cutin "bio_harword06",2;
	mes "[ Harword Alt-Eisen ]";
	mes "It's not what I expected. But I want you to smile until our memories are gone completely.";
	close3;
}

1@gol2,46,70,5	script	Shecil Damon#edda_lab_5	4_F_MD_SHECIL_H,{
	cutin "bio_shecil06",2;
	mes "[ Shecil Damon ]";
	mes "I thought I was going to die alone. I'm fine with this.";
	close3;
}

1@gol2,48,70,5	script	Seyren Windsor#edda_lab_10	4_M_MD_SEYREN_H,{
	cutin "bio_seyren06",1;
	mes "[ Seyren Windsor ]";
	mes "Soon we'll be like that. I'm sorry that I couldn't save you.";
	close3;
}

1@gol2,51,66,3	script	Sierra#edda_explore_end	4_F_SCIENCE,{
	.@var = get_instance_var("edda_lab");
	if(.@var == 23){	
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "It have ended now, but you couldn't have known. Didn't I tell you that the data is contaminated?";
		next;
		mes "[ Sierra ]";
		mes "But I also feel a bit calm. Thank you for that. I think I had some sense of debt to them.";
		next;
		mes "[ Sierra ]";
		mes "We will pay you the items you acquired during the exploration.";
		mes "Let's regroup back to Yuno. I'll you back when you're ready.";
		if(isbegin_quest(16388) == 1)
			completequest 16388;
		if(isbegin_quest(16399) == 1)
			erasequest 16399;
		if(isbegin_quest(16392) == 0){
			setquest 16392;
			completequest 16392;
			getitem 25787,5;
			getitem 25787,5;
		}
		next;
		cutin "",255;
		if(select("Let's return.:Stay for a while.") == 2){
			cutin "3rd_gn_demi02",2;
			mes "[ Sierra ]";
			mes "Please talk to me again when you7re ready to return.";
			close3;
		}
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "I'll see you again in Yuno.";
		close2;
		warp "yuno",213,344;
	}
	end;
}

1@gol2,49,47,0	script	#edda_explore_ef	HIDDEN_WARP_NPC,{ end; }

1@gol2,45,72,7	duplicate(dummynpc2)	Seyren Windsor::edda_explore_dummy_0	4_M_MD_SEYREN_H
1@gol2,47,72,7	duplicate(dummynpc2)	Katrinn Keyron::edda_explore_dummy_1	4_F_MD_KATRINN_H
1@gol2,49,72,1	duplicate(dummynpc2)	Katrinn Keyron::edda_explore_dummy_2	4_F_MD_KATRINN
1@gol2,51,72,1	duplicate(dummynpc2)	Magaleta Sorin::edda_explore_dummy_3	4_F_MD_MAGALETA_H
1@gol2,52,72,1	duplicate(dummynpc2)	Seyren Windsor::edda_explore_dummy_4	4_M_MD_SEYREN_H
1@gol2,53,73,1	duplicate(dummynpc2)	Katrinn Keyron::edda_explore_dummy_5	4_F_MD_KATRINN_H
1@gol2,52,75,3	duplicate(dummynpc2)	Eremes Guile::edda_explore_dummy_6	4_M_MD_EREMES_H
1@gol2,51,76,3	duplicate(dummynpc2)	Eremes Guile::edda_explore_dummy_7	4_M_MD_EREMES
1@gol2,49,76,3	duplicate(dummynpc2)	Magaleta Sorin::edda_explore_dummy_8	4_F_MD_MAGALETA_H
1@gol2,47,75,5	duplicate(dummynpc2)	Eremes Guile::edda_explore_dummy_9	4_M_MD_EREMES_H
1@gol2,46,74,5	duplicate(dummynpc2)	Magaleta Sorin::edda_explore_dummy_10	4_F_MD_MAGALETA

1@gol2,50,74,3	script	Katrinn Keyron::edda_explore_dummy_11	4_F_MD_KATRINN_D,{
	npctalk "Body of Katrinn Keyron.";
	end;
}

1@gol2,48,74,7	script	Magaleta Sorin::edda_explore_dummy_12	4_F_MD_MAGALETA_D,{
	npctalk "Body of Magaleta Sorin.";
	end;
}

1@gol2,49,75,1	script	Eremes Guile::edda_explore_dummy_13	4_M_MD_EREMES_D,{
	npctalk "Body of Eremes Guile.";
	end;
}

1@gol2,51,75,5	script	Seyren Windsor::edda_explore_dummy_14	4_M_MD_SEYREN_D,{
	npctalk "Body of Seyren Windsor.";
	end;
}

1@gol1,1,1,0	script	#edda_exploration_mob	-1,{
	end;
	
OnSummon00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	instance_hide("Eremes Guile#edda_lab_1",true);
	monster .@map$,78,120,"Eremes Guile",20540,1,.@event$;
	set_instance_var("edda_lab",8);
end;

OnMobKill00:
	set_instance_var("edda_lab",9);
	instance_hide("Eremes Guile#edda_lab_1",false);
	npctalk "Eremes : Stop hitting me. I'm awake now.",instance_npcname("Eremes Guile#edda_lab_1");
end;

OnSummon01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	setarray .@xy,126,27,20542,120,23,20542,117,23,20543,112,28,20538,114,28,20539,114,21,20543,113,22,20541,110,28,20543,125,15,20543;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_lab",12);
		npctalk "Seyren : Keyron!! It's me, Seyren!!",instance_npcname("Seyren Windsor#edda_lab_4");
		mapannounce .@map$,"Seyren : Keyron!! It's me, Seyren!!",bc_map,0xD3D3D3;
	}
end;

OnSummon02:
	set_instance_var("edda_lab",16);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill02";
	instance_hide("Wolfchev#edda_lab_0",true);
	instance_enable("Wolfchev#edda_lab_0",false);
	instance_hide("Nameless Swordsman#edda_lab_0",true);
	monster .@map$,156,299,"Nameless Swordsman",20537,1,.@event$;
end;

OnMobKill02:
	.@map$ = get_instance_var("first_floor$");
	instance_hide("Nameless Swordsman#edda_lab_0",false);
	mapannounce .@map$,"Nameless Swordsman : You guys... Please... R-run... away from.. here...",bc_map,0xFFE1FF;
	npctalk "Nameless Swordsman : You guys... Please... R-run... away from.. here...",instance_npcname("Nameless Swordsman#edda_lab_0");
	sleep 1500;
	mapannounce .@map$,"Harword : What does that mean?",bc_map,0xD2FFD2;
	npctalk "Harword : What does that mean?",instance_npcname("Harword Alt-Eisen#edda_lab_2");
	sleep 1500;
	specialeffect EF_BLASTMINEBOMB,AREA,instance_npcname("Nameless Swordsman#edda_lab_0");
	sleep 500;
	specialeffect EF_CLAYMORE,AREA,instance_npcname("Nameless Swordsman#edda_lab_0");
	instance_enable("Nameless Swordsman#edda_lab_0",false);
	instance_hide("Shecil Damon#edda_lab_1",false);
	set_instance_var("edda_lab",17);
end;

OnSummon03:
	set_instance_var("edda_lab",21);
	for(.@i = 0; .@i < 11; .@i++){
		instance_hide("edda_explore_dummy_" + .@i,true);
		instance_enable("edda_explore_dummy_" + .@i,false);
	}
	instance_hide("Seyren Windsor#edda_lab_9",true);
	instance_hide("Harword Alt-Eisen#edda_lab_5",true);
	instance_hide("Shecil Damon#edda_lab_4",true);
	instance_hide("Wolfchev#edda_lab_1",true);
	instance_hide("Nameless Swordsman#edda_lab_1",true);
	instance_enable("Nameless Swordsman#edda_lab_1",false);
	.@map$ = get_instance_var("second_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill03";
	monster .@map$,49,67,"Nameless Swordsman",20537,1,.@event$;
end;

OnMobKill03:
	set_instance_var("edda_lab",22);
	instance_hide("Seyren Windsor#edda_lab_9",false);
	instance_hide("Harword Alt-Eisen#edda_lab_5",false);
	instance_hide("Shecil Damon#edda_lab_4",false);
	instance_hide("Wolfchev#edda_lab_1",false);
	npctalk "Seyren : I can't believe it. We won...",instance_npcname("Seyren Windsor#edda_lab_9");
end;
}

1@gol1,94,84,0	script	#edda_explore_warp_0	WARPNPC,1,1,{
	end;
	
OnTouch:
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("edda_lab");
	.@w = atoi(replacestr(strnpcinfo(2),"edda_explore_warp_",""));
	switch(.@w){
		case 0:
			if(.@var == 10)
				instance_event("#edda_journey_control","OnExploration04",false);
			warp .@map$,94,76; 
			break;
			
		case 1:
			warp .@map$,146,234;
			break;
			
		case 2:
			.@map$ = get_instance_var("second_floor$");
			warp .@map$,49,20;
			break;
	}
end;
}

1@gol1,142,81,0	duplicate(#edda_explore_warp_0)	#edda_explore_warp_1	WARPNPC,1,1
1@gol1,189,329,0	duplicate(#edda_explore_warp_0)	#edda_explore_warp_2	WARPNPC,1,1

//= Archer Laboratory
1@gol1,175,297,7	script	Shecil Damon#edda_shecil_0-0	4_F_MD_SHECIL,{
	.@var = get_instance_var("archer_lab");
	if(!.@var)
		end;
	if(.@var == 3)
		npctalk "Shecil : I can't run away from this place unless I kill those bastards. Let's check there's anything useful here.";
	if(.@var == 1){
		cutin "bio_shecil04",2;
		mes "[ Shecil Damon ]";
		mes "Hey, How...?";
		mes "Oh, it's you... hey.";
		npctalk "Shecil : Hey, How...? Oh, it's you... hey.";
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "I thought you were a mere fool, but no -";
		npctalk "Shecil : I thought you were a mere fool, but no -";
		next;
		select("A fool?");
		cutin "bio_shecil02",2;
		mes "[ Shecil Damon ]";
		mes "Well, there are two idiots on the group.";
		next;
		cutin "bio_shecil01",2;
		mes "[ Shecil Damon ]";
		mes "Oh, don't worry. I'm sure you'll be much better of a help anyway.";
		mes "Let's get out of here!";
		npctalk "Shecil : Oh, don't worry. I'm sure you'll be much better of a help anyway. Let's get out of here!";
		select("Let's go!");
		cutin "",255;
		.@var = get_instance_var("archer_lab");
		if(.@var == 1){
			set_instance_var("archer_lab",2);
			for(.@i = 0; .@i < 3; .@i++){
				instance_hide("Rekenber Guard#edda_shecil_0-" + .@i,true);
				instance_enable("Rekenber Guard#edda_shecil_0-" + .@i,false);
			}
			instance_event("#edda_shecil_mob","OnSpawn00",false);
		}	
	}
	end;
}

1@gol1,172,310,7	duplicate(instancedummynpc)	Shecil Damon#edda_shecil_0-1	4_F_MD_SHECIL


1@gol1,171,302,5	script	Rekenber Guard#edda_shecil_0-0	4_M_LGTGUARD,3,2,{
	end;
	
OnTouch:
	npctalk "Rekenber Guard : We're under siege!";
end;
}

1@gol1,176,304,3	script	Rekenber Guard#edda_shecil_0-1	4_M_LGTGUARD,3,2,{
	end;
	
OnTouch:
	npctalk "Rekenber Guard : Isn't she the famous Devil's Archer?!";
end;
}

1@gol1,178,301,5	script	Rekenber Guard#edda_shecil_0-2	4_M_LGTGUARD,3,2,{
	end;
OnTouch:
	npctalk "Rekenber Guard : Hey! Don't come near me!";
end;
}


1@gol1,176,256,7	script	Rekenber Guard#edda_shecil_1-0	4_M_LGTGUARD,3,3,{
	end;
	
OnTouch:
	npctalk "Rekenber Guard : Who's there!";
end;
}

1@gol1,171,254,7	script	Rekenber Guard#edda_shecil_1-1	4_M_LGTGUARD,{ end; }
1@gol1,178,250,7	script	Rekenber Guard#edda_shecil_1-2	4_M_LGTGUARD,{ end; }


1@gol1,178,312,0	script	Experiment Report#edda_shecil_0	4_ENERGY_WHITE,{
	.@var = get_instance_var("archer_lab");
	if(.@var == 3){
		mes "[ " + strcharinfo(0) + " ]";
		mes "I have found something. I'll read it to Shecil.";
		unittalk getcharid(3),strcharinfo(0) + " : I have found something. I'll read it to Shecil.";
		next;
		instance_hide("Shecil Damon#edda_shecil_0-0",true);
		instance_enable("Shecil Damon#edda_shecil_0-0",false);
		instance_hide("Shecil Damon#edda_shecil_0-1",false);
		cutin "bio_shecil02",2;
		mes "[ Shecil Damon ]";
		mes "Oh. They did these experiments on us.";
		mes "Raising our combat potential to the limit, I wonder why.";
		npctalk "Shecil : Oh. They did these experiments on us. Raising our combat potential to the limit, I wonder why.";
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "We have no choice but to use that potential to our advantage.";
		npctalk "Shecil : We have no choice but to use that potential to our advantage.";
		next;
		cutin "",255;
		select("It's dangerous.");
		cutin "bio_shecil02",2;
		mes "[ Shecil Damon ]";
		mes "It's already dangerous.";
		mes "Running away from danger is the difference between dying and fighting.";
		npctalk "Shecil : It's already dangerous. Running away from danger is the difference between dying and fighting.";
		next;
		cutin "",255;
		if(select("I'll run away from here.:I will fight until the end.") == 1){
			cutin "bio_shecil01",2;
			mes "[ Shecil Damon ]";
			mes "Maybe it's a gamble if you can run away and save your life.";
			mes "This document, you've seen it, right? I don't know how long I would survive without my real heart.";
			npctalk "Shecil : Maybe it's a gamble if you can run away and save your life. This document, you've seen it, right? I don't know how long I would survive without my real heart.";
			next;
		}
		cutin "bio_shecil02",2;
		mes "[ Shecil Damon ]";
		mes "Now that we have an information, we'll use it to make a surprise attack here.";
		npctalk "Shecil : Now that we have an information, we'll use it to make a surprise attack here.";
		next;
		mes "[ Shecil Damon ]";
		mes "Look at the corner, there will be patrol guards coming soon.";
		mes "I'll wait for the right time. Then I'll kill them all.";
		close2;
		cutin "",255;
		set_instance_var("archer_lab",4);
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_hide("Shecil Damon#edda_shecil_0-1",true);
		instance_enable("Shecil Damon#edda_shecil_0-1",false);
		instance_enable("Shecil Damon#edda_shecil_1-0",true);
		instance_enable("Shecil Damon#edda_shecil_1-1",true);
		instance_hide("Shecil Damon#edda_shecil_1-1",true);
		for(.@i = 0; .@i < 3; .@i++)
			instance_enable("Rekenber Guard#edda_shecil_1-" + .@i,true);
	}
	end;
}

1@gol1,186,262,7	script	Shecil Damon#edda_shecil_1-0	4_F_MD_SHECIL,5,3,{
	.@var = get_instance_var("archer_lab");
	if(.@var == 4){
		cutin "bio_shecil01",2;
		mes "[ Shecil Damon ]";
		mes "The position is as expected. Well, are you ready?";
		npctalk "Shecil : The position is as expected. Well, are you ready?";
		next;
		cutin "",255;
		select("Are you sure it's okay?");
		cutin "bio_shecil01",2;
		mes "[ Shecil Damon ]";
		mes "It's probably okay now. But it won't be soon.";
		npctalk "Shecil : It's probably okay now. But it won't be soon.";
		next;
		cutin "bio_shecil02",2;
		mes "[ Shecil Damon ]";
		mes "Who knows? If we run around here too much, they'll all be coming here.";
		npctalk "Shecil : Who knows? If we run around here too much, they'll all be coming here.";
		next;
		cutin "bio_shecil03",2;
		mes "[ Shecil Damon ]";
		mes "Let's stop wasting time. I'll count and we'll catch them.";
		npctalk "Shecil : Let's stop wasting time. I'll count and we'll catch them.";
		next;
		mes "[ Shecil Damon ]";
		mes "Three, two-";
		npctalk "Shecil : Three, two-";
		next;
		mes "[ Shecil Damon ]";
		mes "One!";
		npctalk "Shecil : One!";
		close2;
		cutin "",255;
		set_instance_var("archer_lab",5);
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_hide("Shecil Damon#edda_shecil_1-1",false);
		for(.@i = 0; .@i < 3; .@i++){
			instance_hide("Rekenber Guard#edda_shecil_1-" + .@i,true);
			instance_enable("Rekenber Guard#edda_shecil_1-" + .@i,false);
		}
		instance_event("#edda_shecil_mob","OnSpawn01",false);
	}
	end;

OnTouch:
	npctalk "Shecil : Stop. They'll find us if we go any further.";
end;
}

1@gol1,174,254,3	script	Shecil Damon#edda_shecil_1-1	4_F_MD_SHECIL,{
	.@var = get_instance_var("archer_lab");
	if(.@var == 5){
		npctalk "Shecil : Burst Damage!";
		specialeffect EF_CLAYMORE;
	}
	end;
}

1@gol1,180,250,1	duplicate(instancedummynpc)	Rekenber Guard#edda_shecil_2-0	4_M_LGTGUARD
1@gol1,178,250,7	duplicate(instancedummynpc)	Rekenber Guard#edda_shecil_2-1	4_M_LGTGUARD
1@gol1,172,251,5	duplicate(instancedummynpc)	Rekenber Guard#edda_shecil_2-2	4_M_LGTGUARD
1@gol1,176,256,7	duplicate(instancedummynpc)	Rekenber Guard#edda_shecil_2-3	4_M_LGTGUARD
1@gol1,171,254,7	duplicate(instancedummynpc)	Rekenber Guard#edda_shecil_2-4	4_M_LGTGUARD

1@gol1,1,1,0	script	#edda_shecil_mob	-1,{
	end;
	
OnSpawn00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	setarray .@xy,175,303,20542,177,303,20542,178,301,20542,178,301,20543,175,300,20543,176,300,20543;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("archer_lab",3);
		npctalk "Shecil : Sigh. We can't just run away. I can't see well what's over there. Try to find a clue.",instance_npcname("Shecil Damon#edda_shecil_0-0");
		instance_hide("Experiment Report#edda_shecil_0",false);
	}
end;

OnSpawn01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	setarray .@xy,179,256,20542,179,254,20543,179,253,20543,178,255,20541,176,255,20542,176,254,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("archer_lab",6);
		npctalk "Shecil : Ahahaha! They're all dead! I'll make a mountain out of your corpse and a river out of your blood!",instance_npcname("Shecil Damon#edda_shecil_1-1");
		sleep 1800;
		for(.@i = 0; .@i < 5; .@i++)
			instance_hide("Rekenber Guard#edda_shecil_2-" + .@i,false);
		npctalk "Rekenber Guard : I'll kill them all!",instance_npcname("Rekenber Guard#edda_shecil_2-0");
		sleep 1800;
		npctalk "Shecil : Ahaha. Are you expecting me to run? Never! I'll use every one of my arrows!",instance_npcname("Shecil Damon#edda_shecil_1-1");
		sleep 1800;
		npctalk "Shecil : Then, I don't know. Damn, I can't believe this is the end. Damn it all!",instance_npcname("Shecil Damon#edda_shecil_1-1");
		sleep 1000;
		specialeffect EF_CRYSTAL_BLUE,AREA,instance_npcname("Shecil Damon#edda_shecil_1-1");
		sleep 1500;
		specialeffect EF_WHITEBODY,AREA,instance_npcname("Shecil Damon#edda_shecil_1-1");
		specialeffect EF_GRAYBODY,AREA,instance_npcname("Shecil Damon#edda_shecil_1-1");
		for(.@i = 0; .@i < 5; .@i++){
			specialeffect EF_WHITEBODY,AREA,instance_npcname("Rekenber Guard#edda_shecil_2-" + .@i);
			specialeffect EF_GRAYBODY,AREA,instance_npcname("Rekenber Guard#edda_shecil_2-" + .@i);
		}
		sleep 1000;
		for(.@i = 0; .@i < 5; .@i++){
			instance_hide("Rekenber Guard#edda_shecil_2-" + .@i,true);
			instance_enable("Rekenber Guard#edda_shecil_2-" + .@i,false);
		}
		instance_hide("Shecil Damon#edda_shecil_1-1",true);
		instance_enable("Shecil Damon#edda_shecil_1-1",false);
		instance_hide("Sierra#edda_shecil_0",false);
		sleep 1500;
		npctalk "Sierra : You probably know why I'm here.",instance_npcname("Sierra#edda_shecil_0");
		sleep 3000;
		npctalk "Sierra : Shecil Damon can't leave this place.",instance_npcname("Sierra#edda_shecil_0");
		sleep 3000;
		npctalk "Sierra : It's no use helping. Please talk to me. I'll get you to the situation room.",instance_npcname("Sierra#edda_shecil_0");
		set_instance_var("archer_lab",7);
		.@var = get_instance_var("edda_lab");
		if(.@var == 4)
			set_instance_var("edda_lab",5);
	}
end;
}

1@gol1,174,251,5	script	Sierra#edda_shecil_0	4_F_SCIENCE,{
	.@var = get_instance_var("archer_lab");
	if(.@var == 7){
		.@map$ = get_instance_var("first_floor$");
		if(isbegin_quest(16398))
			erasequest 16398;
		warp .@map$,201,42;
	}
	end;
}

1@gol1,66,273,5	script	Seyren Windsor#edda_seyren_0-0	4_M_MD_SEYREN_D,{
	.@var = get_instance_var("swordsman_lab");
	if(.@var == 1){
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "Ugh...";
		npctalk "Seyren : Ugh...";
		next;
		mes "[ Seyren Windsor ]";
		mes "I feel dizzy...";
		npctalk "Seyren : I feel dizzy...";
		next;
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes strcharinfo(0) + ", do you know where we are?";
		mes "I want to find the others, we need to move fast, but this headache.";
		npctalk "Seyren : Do you know where we are? I want to find the others, we need to move fast, but this headache.";
		next;
		for(.@i = 0; .@i < 2; .@i++){
			instance_hide("Rekenber Guard#edda_seyren_0-" + .@i,true);
			instance_event("Rekenber Guard#edda_seyren_0-" + .@i,"OnTalk0",false);
		}
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "They're a company called Rekenber.";
		mes "They said they were soldiers. Why are they here? Are they here to meet the president?";
		npctalk "Seyren : They're a company called Rekenber. They said they were soldiers. Why are they here? Are they here to meet the president?";
		next;
		for(.@i = 0; .@i < 2; .@i++)
			instance_event("Rekenber Guard#edda_seyren_0-" + .@i,"OnTalk1",false);
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "I don't know the details, but they were here, too!";
		mes "If I could only hold my sword. Huh...";
		mes strcharinfo(0) + ", can I ask for you assistance?";
		npctalk "Seyren : I don't know the details, but they were here, too! If I could only hold my sword. Huh...  Can I ask for you assistance?";
		next;
		cutin "",255;
		select("Help Seyren.");
		for(.@i = 0; .@i < 2; .@i++)
			instance_event("Rekenber Guard#edda_seyren_0-" + .@i,"OnTalk2",false);
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "It seems like the effect of the sleeping gas is still present.";
		mes "I'm sorry I can't be any of help! I'll let you handle it.";
		npctalk "Seyren : It seems like the effect of the sleeping gas is still present. I'm sorry I can't be any of help! I'll let you handle it.";
		close2;
		cutin "",255;
		instance_event("#edda_seyren_mob","OnSpawn00",false);
		end;
	}
	if(.@var == 2){
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "Thank you. Ugh.";
		mes "Now I can move a little bit.";
		npctalk "Seyren : Thank you. Ugh. Now I can move a little bit.";
		next;
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "Come on, let's find a way to save Sorin and the others.";
		mes "We need to gather as much information as we can.";
		npctalk "Seyren : Come on, let's find a way to save Sorin and the others. We need to gather as much information as we can.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Why are we here, where are we, and the way out of here.";
		mes "Most importantly, who's behind all of this.";
		npctalk "Seyren : Why are we here, where are we, and the way out of here. Most importantly, who's behind all of this.";
		next;
		mes "[ Seyren Windsor ]";
		mes "It's like this place was built solely for research.";
		mes "They were trying to study me, I believe there's still some data left around here.";
		npctalk "Seyren : It's like this place was built solely for research. They were trying to study me, I believe there's still some data left around here.";
		next;
		mes "[ Seyren Windsor ]";
		mes "I don't think the men we just attacked knew anything of this neither.";
		mes "Let's split up and gather as much information as we can.";
		npctalk "Seyren : I don't think the men we just attacked knew anything of this neither. Let's split up and gather as much information as we can.";
		next;
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "Let's gather data and look around. If you found an important clue, please come and tell me.";
		npctalk "Seyren : Let's gather data and look around. If you found an important clue, please come and tell me.";
		set_instance_var("swordsman_lab",3);
		close2;
		cutin "",255;
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_enable("Seyren Windsor#edda_seyren_1-0",true);
		instance_enable("Seyren's PecoPeco#edda_seyren_1-0",true);
	}
	end;
}

1@gol1,12,324,5	script	Seyren Windsor#edda_seyren_1-0	4_M_MD_SEYREN,{
	.@var = get_instance_var("swordsman_lab");
	if(.@var == 3){
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "Adventurer, adventurer! This way! My PecoPeco. Finally, I found my PecoPeco.";
		npctalk "Seyren : Adventurer, adventurer! This way! My PecoPeco. Finally, I found my PecoPeco.";
		next;
		mes "[ Seyren Windsor ]";
		mes "He's usually a good boy and he like to cut his reins.";
		mes "I can't believe I found him in a place like this.";
		npctalk "Seyren : He's usually a good boy and he like to cut his reins. I can't believe I found him in a place like this.";
		next;
		mes "[ Seyren Windsor ]";
		mes "We need to gather information we've learned so far and have Peco send outside.";
		npctalk "Seyren : We need to gather information we've learned so far and have Peco send outside.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Even if we don't get out of here, at least the world will know about this place.";
		npctalk "Seyren : Even if we don't get out of here, at least the world will know about this place.";
		next;
		mes "[ Seyren Windsor ]";
		mes "When we're done here, let's go straight for the rescue. So, what have you learned about this place so far?";
		npctalk "Seyren : When we're done here, let's go straight for the rescue. So, what have you learned about this place so far?";
		next;
		cutin "",255;
		if(select("So far so good.:Not much. Let's ride your PecoPeco~!!") == 3){
			cutin "bio_seyren02",1;
			mes "[ Seyren Windsor ]";
			mes strnpcinfo(0) + ",";
			mes "We need to save everyone and go back together. We can't just run away with our lives.";
			npctalk "Seyren : We need to save everyone and go back together. We can't just run away with our lives.";
			next;
		}
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "I can't hear the wind outside the wall.";
		mes "We must be trapped underground.";
		mes "If we go up, we might be able to get out of here.";
		npctalk "Seyren : I can't hear the wind outside the wall. We must be trapped underground. If we go up, we might be able to get out of here.";
		next;
		mes "[ Seyren Windsor ]";
		mes "I don't know if this is the way out, but I need to try something to save everyone.";
		npctalk "Seyren : I don't know if this is the way out, but I need to try something to save everyone.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Peco. You must escape here and go back to your old man.";
		mes "Do you remember, the bearded man.";
		npctalk "Seyren : Peco. You must escape here and go back to your old man. Do you remember, the bearded man.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Your special skill is getting out of your reins, but this time I'm freeing you. So make sure you go home!";
		npctalk "Seyren : Your special skill is getting out of your reins, but this time I'm freeing you. So make sure you go home!";
		next;
		cutin "",255;
		mes "[ Seyren's PecoPeco ]";
		mes "Peco~!";
		npctalk "Seyren's Pecopeco :  Peco~!",instance_npcname("Seyren's PecoPeco#edda_seyren_1-0");
		next;
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "Shhh, it's alright. Now please go.";
		npctalk "Seyren : Shhh, it's alright. Now please go.";
		next;
		mes "[ Seyren Windsor ]";
		mes "That boy is smart. I'm sure he'll get away from here somehow.";
		mes "So now we're gonna have to...";
		npctalk "Seyren : That boy is smart. I'm sure he'll get away from here somehow. So now we're gonna have to...";
		instance_hide("Seyren's PecoPeco#edda_seyren_1-0",true);
		instance_enable("Seyren's PecoPeco#edda_seyren_1-0",false);
		next;
		cutin "",255;
		for(.@i = 0; .@i < 3; .@i++)
			instance_hide("Rekenber Guard#edda_seyren_1-" + .@i,false);
		mes "[ Rekenber Guard ]";
		mes "Stop right there, who are you!";
		mes "Put your hands up and turn around!";
		npctalk "Rekenber Guard : Stop right there, who are you! Put your hands up and turn around!",instance_npcname("Rekenber Guard#edda_seyren_1-0");
		next;
		mes "[ Rekenber Guard ]";
		mes "This one is dressed like the fugitive subject. We've got him here!";
		npctalk "Rekenber Guard : This one is dressed like the fugitive subject. We've got him here!",instance_npcname("Rekenber Guard#edda_seyren_1-1");
		next;
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "So much for trying to be subtle. Wait, did they show up while we were sending Peco out?";
		npctalk "Seyren : So much for trying to be subtle. Wait, did they show up while we were sending Peco out?";
		next;
		cutin "",255;
		mes "[ Rekenber Guard ]";
		mes "What are you talking about? Sieze him!";
		npctalk "Rekenber Guard : What are you talking about? Sieze him!",instance_npcname("Rekenber Guard#edda_seyren_1-0");
		next;
		mes "[ Rekenber Guard ]";
		mes "We need to return him alive!";
		npctalk "Rekenber Guard : We need to return him alive!",instance_npcname("Rekenber Guard#edda_seyren_1-0");
		close2;
		instance_hide(strnpcinfo(0),true);
		instance_event("#edda_seyren_mob","OnSpawn01",false);
	}
	end;
}

1@gol1,14,326,3	script	Seyren's PecoPeco#edda_seyren_1-0	4_PECOPECO,{
	npctalk "Peco~!!";
	end;
}


1@gol1,64,277,5	script	Rekenber Guard#edda_seyren_0-0	4_M_LGTGUARD,{
	end;
	
OnTalk0:
	npctalk "Rekenber Guard : I told you he'd be asleep, all we have to do is prepare for the experiment, right?";
	
end;

OnTalk1:
	npctalk "Rekenber Guard : What, why is he awake? Why does he have all his equipments?";
end;

OnTalk2:
	npctalk "Rekenber Guard : These damn researchers, they're out of their minds. Can't they do their jobs right?";
end;
}


1@gol1,61,274,5	script	Rekenber Guard#edda_seyren_0-1	4_M_LGTGUARD,{
	end;
	
OnTalk0:
	npctalk "Rekenber Guard : Yes. I'm sure he's asleep with all the gas they inhaled.";
end;

OnTalk1:
	npctalk "Rekenber Guard : These damn researchers, they're out of their minds. Can't they do their job correctly?";
end;

OnTalk2:
	npctalk "Rekenber Guard : I guess we have no choice but to fight. Damn it!";
end;
}

1@gol1,15,319,1	duplicate(dummynpc2)	Rekenber Guard#edda_seyren_1-0	20541
1@gol1,12,317,1	duplicate(dummynpc2)	Rekenber Guard#edda_seyren_1-1	4_M_LGTGUARD
1@gol1,8,319,7	duplicate(dummynpc2)	Rekenber Guard#edda_seyren_1-2	4_M_LGTGUARD
1@gol1,15,317,1	duplicate(dummynpc2)	Rekenber Guard#edda_seyren_1-3	4_M_LGTGUARD
1@gol1,12,315,1	duplicate(dummynpc2)	Rekenber Guard#edda_seyren_1-4	4_M_LGTGUARD
1@gol1,8,317,1	duplicate(dummynpc2)	Rekenber Guard#edda_seyren_1-5	4_M_LGTGUARD

1@gol1,1,1,0	script	#edda_seyren_mob	-1,{
	end;
	
OnSpawn00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	setarray .@xy,66,276,20542,64,274,20542,62,276,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("swordsman_lab",2);
		specialeffect EF_BASH,AREA,instance_npcname("Seyren Windsor#edda_seyren_0-0");
		classchange 4_M_MD_SEYREN,instance_npcname("Seyren Windsor#edda_seyren_0-0");
		npctalk "Seyren : Oh, damn. I'm feeling a little better now.",instance_npcname("Seyren Windsor#edda_seyren_0-0");
	}
end;

OnSpawn01:
	set_instance_var("swordsman_lab",4);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	for(.@i = 0; .@i < 3; .@i++)
		instance_hide("Rekenber Guard#edda_seyren_1-" + .@i,true);
	setarray .@xy,14,316,20542,9,316,20542,11,315,20541;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill01:
	set_instance_var("swordsman_lab",5);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		for(.@i = 0; .@i < 3; .@i++)
			instance_hide("Rekenber Guard#edda_seyren_1-" + .@i,false);
		instance_hide("Seyren Windsor#edda_seyren_1-0",false);
		npctalk "Rekenber Guard : We need back up here! Quick!",instance_npcname("Rekenber Guard#edda_seyren_1-2");
		npctalk "Rekenber Guard : These lab rats. Let's try harder! Everyone, Attack!!",instance_npcname("Rekenber Guard#edda_seyren_1-0");
		sleep 1500;
		for(.@i = 3; .@i < 6; .@i++)
			instance_hide("Rekenber Guard#edda_seyren_1-" + .@i,false);
		npctalk "Rekenber Guard : Yes!",instance_npcname("Rekenber Guard#edda_seyren_1-1");
		npctalk "Rekenber Guard : Aye!",instance_npcname("Rekenber Guard#edda_seyren_1-2");
		npctalk "Rekenber Guard : Roger!",instance_npcname("Rekenber Guard#edda_seyren_1-3");
		npctalk "Rekenber Guard : Let's Attack!",instance_npcname("Rekenber Guard#edda_seyren_1-4");
		npctalk "Rekenber Guard : Backup is here!",instance_npcname("Rekenber Guard#edda_seyren_1-5");
		sleep 1500;
		npctalk "Seyren : We can't fall like this! We have to save everyone!",instance_npcname("Seyren Windsor#edda_seyren_1-0");
		sleep 1000;
		specialeffect EF_ENDURE,AREA,instance_npcname("Seyren Windsor#edda_seyren_1-0");
		sleep 200;
		specialeffect EF_MAGNUMBREAK,AREA,instance_npcname("Seyren Windsor#edda_seyren_1-0");
		sleep 1200;
		specialeffect EF_DESPERADO,AREA,instance_npcname("Seyren Windsor#edda_seyren_1-0");
		sleep 200;
		specialeffect EF_DESPERADO,AREA,instance_npcname("Seyren Windsor#edda_seyren_1-0");
		sleep 300;
		specialeffect EF_CRYSTAL_BLUE,AREA,instance_npcname("Seyren Windsor#edda_seyren_1-0");
		sleep 3000;
		for(.@i = 0; .@i < 6; .@i++){
			specialeffect EF_WHITEBODY,AREA,instance_npcname("Rekenber Guard#edda_seyren_1-" + .@i);
			specialeffect EF_GRAYBODY,AREA,instance_npcname("Rekenber Guard#edda_seyren_1-" + .@i);
		}
		specialeffect EF_WHITEBODY,AREA,instance_npcname("Seyren Windsor#edda_seyren_1-0");
		specialeffect EF_GRAYBODY,AREA,instance_npcname("Seyren Windsor#edda_seyren_1-0");
		sleep 3000;
		for(.@i = 0; .@i < 6; .@i++){
			instance_hide("Rekenber Guard#edda_seyren_1-" + .@i,true);
			instance_enable("Rekenber Guard#edda_seyren_1-" + .@i,false);
		}
		instance_hide("Seyren Windsor#edda_seyren_1-0",true);
		instance_enable("Seyren Windsor#edda_seyren_1-0",false);
		instance_hide("Sierra#edda_seyren_0",false);
		.@var = get_instance_var("edda_lab");
		if(.@var == 4)
			set_instance_var("edda_lab",5);
		sleep 1500;
		npctalk "Sierra : You probably know why I'm here.",instance_npcname("Sierra#edda_seyren_0");
		sleep 3000;
		npctalk "Sierra : Seyren Windsor cannot leave here.",instance_npcname("Sierra#edda_seyren_0");
		sleep 3000;
		npctalk "Sierra : It's no use helping. Please talk to me. I'll get you to the situation room.",instance_npcname("Sierra#edda_seyren_0");
	}
end;
}

1@gol1,13,322,3	script	Sierra#edda_seyren_0	4_F_SCIENCE,{
	.@var = get_instance_var("swordsman_lab");
	if(.@var == 5){
		.@map$ = get_instance_var("first_floor$");
		if(isbegin_quest(16393))
			erasequest 16393;
		warp .@map$,201,42;
	}
	end;
}

1@gol1,37,148,7	script	Eremes Guile#edda_eremes_0-0	4_M_MD_EREMES,{
	.@var = get_instance_var("thief_lab");
	if(.@var == 1){
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "Is that you? I'm surprised you managed to get here.";
		npctalk "Eremes : Is that you? I'm surprised you managed to get here.";
		next;
		cutin "",255;
		select("Eremes! What of Keyron?");
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "...";
		npctalk "Keyron : ...",instance_npcname("Katrinn Keyron#edda_eremes_0-0");
		next;
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "Keyron was silenced. They silenced and poison the magic user first, these people are not amateurs.";
		npctalk "Eremes : Keyron was silenced. They silenced and poison the magic user first, these people are not amateurs.";
		next;
		cutin "bio_eremes02",2;
		mes "[ Eremes Guile ]";
		mes "Don't look at me like that, Keyron. It's my mistake. I'm sorry.";
		npctalk "Eremes : Don't look at me like that, Keyron. It's my mistake. I'm sorry.";
		next;
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "...";
		npctalk "Keyron : ...",instance_npcname("Katrinn Keyron#edda_eremes_0-0");
		next;
		cutin "bio_eremes02",2;
		mes "[ Eremes Guile ]";
		mes "Shhh, quiet. Someone's coming.";
		npctalk "Eremes : Shhh, quiet. Someone's coming.";
		next;
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "It's a Rekenber's Guard outfit. It's all props to make us think we'd meet the President.";
		npctalk "Eremes : It's a Rekenber's Guard outfit. It's all props to make us think we'd meet the President.";
		for(.@i = 0; .@i < 2; .@i++)
			instance_hide("Rekenber Guard#edda_eremes_0-" + .@i,false);
		npctalk "Rekenber Guard : I can hear something here. Is it the lab rats?",instance_npcname("Rekenber Guard#edda_eremes_0-0");
		next;
		mes "[ Eremes Guile ]";
		mes "You need to be more quiet. Let's finish this together quickly.";
		close2;
		cutin "",255;
		instance_event("#edda_eremes_mob","OnSpawn00",false);
		end;
	}
	if(.@var == 2){
		npctalk "Eremes : Now's not the time. Focus on the battle.";
		end;
	}
	end;
}

1@gol1,35,147,7	script	Katrinn Keyron#edda_eremes_0-0	4_F_MD_KATRINN,{
	.@var = get_instance_var("thief_lab");
	if(.@var == 1){
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "...";
		emotion ET_THINK;
		next;
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "Keyron is silenced. I gave her an antidote for it, but there's not much time left.";
		close3;
	}
	npctalk "Katrinn Keyron : ...";
	end;
}

1@gol1,54,90,5	script	Eremes Guile#edda_eremes_1-0	4_M_MD_EREMES,12,12,{
	.@var = get_instance_var("thief_lab");
	if(.@var == 3){
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "This is a disgrace.";
		mes "I can't believe we've been driven to a dead end.";
		npctalk "Eremes : This is a disgrace. I can't believe we've been driven to a dead end.";
		next;
		cutin "",255;
		select("No. I'll fight with you.");
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "I appreciate your cooperation.";
		npctalk "Eremes : I appreciate your cooperation.";
		next;
		cutin "",255;
		select("(Is Keyron safe?)");
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "(Keyron is well hidden. Don't worry.)";
		npctalk "Eremes : (Keyron is well hidden. Don't worry.)";
		next;
		cutin "bio_eremes02",2;
		mes "[ Eremes Guile ]";
		mes "Then let's go! Let's get rid of them all together and get out of here!";
		close2;
		cutin "",255;
		instance_event("#edda_eremes_mob","OnSpawn01",false);
		end;
	}
	if(.@var == 4){
		npctalk "Eremes : Focus on the battle.";
		end;
	}
	end;
	
OnTouch_:
	.@var = get_instance_var("thief_lab");
	if(.@var == 3){
		npctalk "Rekenber Guard : We outnumber him, get him!",instance_npcname("Rekenber Guard#edda_eremes_1-0");
		npctalk "Rekenber Guard : Why is he this strong?!",instance_npcname("Rekenber Guard#edda_eremes_1-1");
		npctalk "Rekenber Guard : Poison them, huh?",instance_npcname("Rekenber Guard#edda_eremes_1-2");
		npctalk "Rekenber Guard : This way! All of you, move!",instance_npcname("Rekenber Guard#edda_eremes_1-3");
	}
end;
}

1@gol1,46,152,3	duplicate(dummynpc2)	Rekenber Guard#edda_eremes_0-0	4_M_LGTGUARD
1@gol1,48,155,3	duplicate(dummynpc2)	Rekenber Guard#edda_eremes_0-1	4_M_LGTGUARD

1@gol1,59,92,3	duplicate(dummynpc2)	Rekenber Guard#edda_eremes_1-0	4_M_LGTGUARD
1@gol1,62,91,3	duplicate(dummynpc2)	Rekenber Guard#edda_eremes_1-1	4_M_LGTGUARD
1@gol1,62,88,1	duplicate(dummynpc2)	Rekenber Guard#edda_eremes_1-2	4_M_LGTGUARD
1@gol1,59,87,1	duplicate(dummynpc2)	Rekenber Guard#edda_eremes_1-3	4_M_LGTGUARD
1@gol1,56,90,3	duplicate(dummynpc2)	Rekenber Guard#edda_eremes_1-4	4_M_LGTGUARD
1@gol1,61,86,1	duplicate(dummynpc2)	Rekenber Guard#edda_eremes_1-5	4_M_LGTGUARD

1@gol1,1,1,0	script	#edda_eremes_mob	-1,{
	end;
	
OnSpawn00:
	set_instance_var("thief_lab",2);
	for(.@i = 0; .@i < 2; .@i++){
		instance_hide("Rekenber Guard#edda_eremes_0-" + .@i,true);
		instance_enable("Rekenber Guard#edda_eremes_0-" + .@i,true);
	}
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	setarray .@xy,43,154,20542,44,157,20542,41,157,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("thief_lab",3);
		npctalk "Eremes : I can't hide for long. I'll leave Keyron in a safe place. Let's meet in the hall below this laboratory.",instance_npcname("Eremes Guile#edda_eremes_0-0");
		instance_hide("Eremes Guile#edda_eremes_0-0",true);
		instance_hide("Katrinn Keyron#edda_eremes_0-0",true);
		instance_enable("Eremes Guile#edda_eremes_0-0",false);
		instance_enable("Katrinn Keyron#edda_eremes_0-0",false);
		instance_enable("Eremes Guile#edda_eremes_1-0",true);
	}
end;

OnSpawn01:
	set_instance_var("thief_lab",4);
	for(.@i = 0; .@i < 4; .@i++)
		instance_hide("Rekenber Guard#edda_eremes_1-" + .@i,true);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	setarray .@xy,56,91,20542,56,91,20542,56,89,20542,56,89,20541;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("thief_lab",5);
		instance_hide("Rekenber Guard#edda_eremes_1-0",false);
		instance_hide("Rekenber Guard#edda_eremes_1-3",false);
		npctalk "Rekenber Guard : Get them!",instance_npcname("Rekenber Guard#edda_eremes_1-3");
		sleep 1000;
		instance_hide("Rekenber Guard#edda_eremes_1-1",false);
		instance_hide("Rekenber Guard#edda_eremes_1-2",false);
		instance_hide("Rekenber Guard#edda_eremes_1-4",false);
		instance_hide("Rekenber Guard#edda_eremes_1-5",false);
		npctalk "Rekenber Guard : This way! Attack together",instance_npcname("Rekenber Guard#edda_eremes_1-3");
		sleep 500;
		npctalk "Eremes : Ahaha, damn it. There's no end to them.",instance_npcname("Eremes Guile#edda_eremes_1-0");
		npctalk "Rekenber Guard : Everyone, Attack!",instance_npcname("Rekenber Guard#edda_eremes_1-4");
		sleep 1200;
		npctalk "Eremes : Damn them. They prepared for this.",instance_npcname("Eremes Guile#edda_eremes_1-0");
		sleep 1200;
		npctalk "Eremes : I should have been stronger. I've even got you involved.",instance_npcname("Eremes Guile#edda_eremes_1-0");
		sleep 1000;
		specialeffect EF_DESPERADO,AREA,instance_npcname("Eremes Guile#edda_eremes_1-0");
		sleep 200;
		specialeffect EF_DESPERADO,AREA,instance_npcname("Eremes Guile#edda_eremes_1-0");
		sleep 300;
		specialeffect EF_CRYSTAL_BLUE,AREA,instance_npcname("Eremes Guile#edda_eremes_1-0");
		sleep 150;
		for(.@i = 0; .@i < 6; .@i++){
			specialeffect EF_WHITEBODY,AREA,instance_npcname("Rekenber Guard#edda_eremes_1-" + .@i);
			specialeffect EF_GRAYBODY,AREA,instance_npcname("Rekenber Guard#edda_eremes_1-" + .@i);
		}
		specialeffect EF_WHITEBODY,AREA,instance_npcname("Eremes Guile#edda_eremes_1-0");
		specialeffect EF_GRAYBODY,AREA,instance_npcname("Eremes Guile#edda_eremes_1-0");
		sleep 1200;
		for(.@i = 0; .@i < 6; .@i++){
			instance_hide("Rekenber Guard#edda_eremes_1-" + .@i,true);
			instance_enable("Rekenber Guard#edda_eremes_1-" + .@i,false);
		}
		instance_hide("Eremes Guile#edda_eremes_1-0",true);
		instance_enable("Eremes Guile#edda_eremes_1-0",false);
		instance_hide("Sierra#edda_eremes_0",false);
		sleep 1500;
		npctalk "Sierra : You probably know why I'm here.",instance_npcname("Sierra#edda_seyren_0");
		sleep 3000;
		npctalk "Sierra : Eremes Guile cannot leave here.",instance_npcname("Sierra#edda_seyren_0");
		sleep 3000;
		npctalk "Sierra : It's no use helping. Please talk to me. I'll get you to the situation room.",instance_npcname("Sierra#edda_seyren_0");
		.@var = get_instance_var("edda_lab");
		if(.@var == 4)
			set_instance_var("edda_lab",5);
	}
end;
}

1@gol1,56,93,5	script	Sierra#edda_eremes_0	4_F_SCIENCE,{
	.@var = get_instance_var("thief_lab");
	if(.@var == 5){
		.@map$ = get_instance_var("first_floor$");
		if(isbegin_quest(16395))
			erasequest 16395;
		warp .@map$,201,42;
	}
	end;
}

1@gol1,113,55,1	script	Katrinn Keyron#edda_keyron_0-0	4_F_MD_KATRINN,{
	.@var = get_instance_var("mage_lab");
	if(.@var == 1){
		select("Katrinn Keyron?");
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "- She nods her head and pointed her finger at her lips. -";
		next;
		cutin "",255;
		select("You were silenced?");
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "...";
		npctalk "Keyron : ...";
		emotion ET_SWEAT;
		next;
		cutin "",255;
		select("This place is safe, but...:It's dangerous here. We should go.");
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "- She nods her head. -";
		unittalk getcharid(3),strcharinfo(0) + " : Keyron nodded.";
		next;
		cutin "",255;
		select("Let's find the others before any guards show up.");
		cutin "bio_katrinn03",0;
		mes "[ Katrinn Keyron ]";
		mes "- She's pointing towards the southwest direction. -";
		unittalk getcharid(3),strcharinfo(0) + " : Keyron pointed towards the southwest direction.";
		emotion ET_CRY;
		close2;
		cutin "",255;
		set_instance_var("mage_lab",2);
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
		instance_enable("Katrinn Keyron#edda_keyron_1-0",true);
		for(.@i = 0; .@i < 3; .@i++)
			instance_enable("Rekenber Guard#edda_keyron_1-" + .@i,true);
	}
	end;
}

1@gol1,90,10,7	script	Katrinn Keyron#edda_keyron_1-0	4_F_MD_KATRINN,{
	.@var = get_instance_var("mage_lab");
	if(.@var == 2){
		cutin "bio_katrinn02",0;
		mes "[ Katrinn Keyron ]";
		mes "- Has an angry looking face. -";
		unittalk getcharid(3),strcharinfo(0) + " : Keyron looks angry.";
		next;
		cutin "",255;
		select("I'll fight for you.");
		cutin "bio_katrinn02",0;
		mes "[ Katrinn Keyron ]";
		mes "...";
		npctalk "Keyron : ...";
		next;
		cutin "",255;
		select("I owe you, so it's not a problem.");
		cutin "bio_katrinn01",0;
		mes "[ Katrinn Keyron ]";
		mes "- Keyron nods. -";
		unittalk getcharid(3),strcharinfo(0) + " : Keyron nodded.";
		next;
		cutin "",255;
		select("Then let's go.");
		close2;
		instance_event("#edda_keyron_mob","OnSpawn00",false);
		end;
	}
	if(.@var == 3){
		npctalk "Keyron : ...";
		end;
	}
	if(.@var >= 4){
		npctalk "Keyron : ...!!!";
		end;
	}
	end;
}

1@gol1,90,13,7	script	Eremes Guile#edda_keyron_1-0	4_M_MD_EREMES,{
	.@var = get_instance_var("mage_lab");
	if(.@var == 4){
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "I'm sorry, I'm late, Keyron.";
		npctalk "Eremes : I'm sorry, I'm late, Keyron.";
		next;
		cutin "bio_katrinn02",0;
		mes "[ Katrinn Keyron ]";
		mes "...!!!";
		npctalk "Keyron : ...!!!",instance_npcname("Katrinn Keyron#edda_keyron_1-0");
		next;
		cutin "",255;
		select("It's hard to fight alone.");
		cutin "bio_eremes01",2;
		mes "[ Eremes Guile ]";
		mes "Thank you. You did what should have been my job.";
		npctalk "Eremes : Thank you. You did what should have been my job.";
		next;
		mes "[ Eremes Guile ]";
		mes "Let's clean up the rest now.";
		mes "I won't let a single one of them escape.";
		npctalk "Eremes : Let's clean up the rest now. I won't let a single one of them escape.";
		close2;
		instance_event("#edda_keyron_mob","OnSpawn01",false);
		end;
	}
	if(.@var == 5){
		npctalk "Eremes : Focus on the battle.";
		end;
	}
	end;
}

1@gol1,90,19,5	script	Rekenber Guard#edda_keyron_1-0	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : You don't think I can handle a kid?";
	end;
}

1@gol1,93,16,3	script	Rekenber Guard#edda_keyron_1-1	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Grab everyone!";
	end;
}

1@gol1,87,16,5	script	Rekenber Guard#edda_keyron_1-2	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Surround her!";
	end;
}

1@gol1,87,19,5	script	Rekenber Guard#edda_keyron_1-3	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Surround her!";
	end;
}

1@gol1,93,19,3	script	Rekenber Guard#edda_keyron_1-4	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Grab everyone!";
	end;
}

1@gol1,90,22,5	script	Rekenber Guard#edda_keyron_1-5	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : You don't think I can handle a kid?";
	end;
}



1@gol1,1,1,0	script	#edda_keyron_mob	-1,{
	end;
	
OnSpawn00:
	for(.@i = 0; .@i < 3; .@i++)
		instance_hide("Rekenber Guard#edda_keyron_1-" + .@i,true);
	set_instance_var("mage_lab",3);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	setarray .@xy,92,16,20543,92,16,20543,92,17,20543,91,18,20543;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("mage_lab",4);
		instance_hide("Eremes Guile#edda_keyron_1-0",false);
		npctalk "Eremes : I'm sorry, I'm late.",instance_npcname("Eremes Guile#edda_keyron_1-0");
		npctalk "Keyron : ...!",instance_npcname("Katrinn Keyron#edda_keyron_1-0");
		for(.@i = 0; .@i < 3; .@i++)
			instance_hide("Rekenber Guard#edda_keyron_1-" + .@i,false);
	}
end;

OnSpawn01:
	for(.@i = 0; .@i < 3; .@i++)
		instance_hide("Rekenber Guard#edda_keyron_1-" + .@i,true);
	set_instance_var("mage_lab",5);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	setarray .@xy,91,16,20541,91,17,20542,91,18,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("mage_lab",6);
		npctalk "Eremes : Is that it?",instance_npcname("Eremes Guile#edda_keyron_1-0");
		sleep 1000;
		instance_hide("Rekenber Guard#edda_keyron_1-0",false);
		instance_hide("Rekenber Guard#edda_keyron_1-2",false);
		npctalk "Rekenber Guard : Backup troops have arrived.",instance_npcname("Rekenber Guard#edda_keyron_1-2");
		instance_hide("Rekenber Guard#edda_keyron_1-1",false);
		npctalk "Rekenber Guard : Reinforcements are here.",instance_npcname("Rekenber Guard#edda_keyron_1-1");
		sleep 200;
		instance_hide("Rekenber Guard#edda_keyron_1-3",false);
		instance_hide("Rekenber Guard#edda_keyron_1-4",false);
		instance_hide("Rekenber Guard#edda_keyron_1-5",false);
		sleep 1000;
		npctalk "Eremes : I'm sorry, Keyron. I think this is it for us.",instance_npcname("Eremes Guile#edda_keyron_1-0");
		npctalk "Keyron : ...",instance_npcname("Katrinn Keyron#edda_keyron_1-0");		
		sleep 1000;
		emotion ET_CRY,getnpcid(0,instance_npcname("Katrinn Keyron#edda_keyron_1-0"));
		sleep 250;
		specialeffect EF_BOWLINGBASH,AREA,instance_npcname("Eremes Guile#edda_keyron_1-0");
		npctalk "Eremes : Even if I die here. I will fulfill my duty to protect you!",instance_npcname("Eremes Guile#edda_keyron_1-0");
		sleep 50;
		specialeffect EF_SCREEN_QUAKE,AREA,instance_npcname("Eremes Guile#edda_keyron_1-0");
		sleep 1000;
		specialeffect EF_DESPERADO,AREA,instance_npcname("Eremes Guile#edda_keyron_1-0");
		sleep 200;
		specialeffect EF_DESPERADO,AREA,instance_npcname("Eremes Guile#edda_keyron_1-0");
		sleep 300;
		specialeffect EF_CRYSTAL_BLUE,AREA,instance_npcname("Eremes Guile#edda_keyron_1-0");
		sleep 150;
		for(.@i = 0; .@i < 6; .@i++){
			specialeffect EF_WHITEBODY,AREA,instance_npcname("Rekenber Guard#edda_keyron_1-" + .@i);
			specialeffect EF_GRAYBODY,AREA,instance_npcname("Rekenber Guard#edda_keyron_1-" + .@i);
		}
		specialeffect EF_WHITEBODY,AREA,instance_npcname("Eremes Guile#edda_keyron_1-0");
		specialeffect EF_GRAYBODY,AREA,instance_npcname("Eremes Guile#edda_keyron_1-0");
		specialeffect EF_WHITEBODY,AREA,instance_npcname("Katrinn Keyron#edda_keyron_1-0");
		specialeffect EF_GRAYBODY,AREA,instance_npcname("Katrinn Keyron#edda_keyron_1-0");
		sleep 1200;
		for(.@i = 0; .@i < 6; .@i++){
			instance_hide("Rekenber Guard#edda_keyron_1-" + .@i,true);
			instance_enable("Rekenber Guard#edda_keyron_1-" + .@i,false);
		}
		instance_hide("Eremes Guile#edda_keyron_1-0",true);
		instance_enable("Eremes Guile#edda_keyron_1-0",false);
		instance_hide("Katrinn Keyron#edda_keyron_1-0",true);
		instance_enable("Katrinn Keyron#edda_keyron_1-0",false);
		instance_hide("Sierra#edda_keyron_0",false);
		sleep 1500;
		npctalk "Sierra : You probably know why I'm here.",instance_npcname("Sierra#edda_keyron_0");
		sleep 3000;
		npctalk "Sierra : Katrinn Keyron and Eremes Guile cannot leave here.",instance_npcname("Sierra#edda_keyron_0");
		sleep 3000;
		npctalk "Sierra : It's no use helping. Please talk to me. I'll get you to the situation room.",instance_npcname("Sierra#edda_keyron_0");
		.@var = get_instance_var("edda_lab");
		if(.@var == 4)
			set_instance_var("edda_lab",5);
	}
end;
}

1@gol1,93,13,3	script	Sierra#edda_keyron_0	4_F_SCIENCE,{
	.@var = get_instance_var("mage_lab");
	if(.@var == 6){
		.@map$ = get_instance_var("first_floor$");
		if(isbegin_quest(16396))
			erasequest 16396;
		warp .@map$,201,42;
	}
	end;
}

1@gol1,120,220,7	script	Seyren Windsor#edda_sorin_0-0	4_M_MD_SEYREN,3,3,{
	.@var = get_instance_var("acolyte_lab");
	if(.@var == 1){
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "Oh, you are here! " + strcharinfo(0) + "!";
		mes "You arrived at a perfect time.";
		npctalk "Seyren : Oh, you are here! You arrived at a perfect time.";
		next;
		mes "[ Seyren Windsor ]";
		mes "Beyond these guards is the laboratory where Sorin is.";
		mes "We need to get rid of the guards and save her.";
		npctalk "Seyren : Beyond these guards is the laboratory where Sorin is. We need to get rid of the guards and save her.";
		npctalk "Rekenber Guard : We're going to kill someone?",instance_npcname("Rekenber Guard#edda_sorin_0-0");
		next;
		mes "[ Seyren Windsor ]";
		mes strcharinfo(0) + ", please help me break through here.";
		npctalk "Seyren : Please help me break through here.";
		next;
		cutin "",255;
		select("Fight with Seyren.");
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "Thank you! Come on, let's break through! Let's free Sorin from the room below.";
		npctalk "Seyren : Thank you! Come on, let's break through! Let's free Sorin from the room below.";
		npctalk "Rekenber Guard : I'll give you a good beating?",instance_npcname("Rekenber Guard#edda_sorin_0-1");
		close2;
		cutin "",255;
		for(.@i = 0; .@i < 2; .@i++){
			instance_hide("Rekenber Guard#edda_sorin_0-" + .@i,true);
			instance_enable("Rekenber Guard#edda_sorin_0-" + .@i,false);
		}
		instance_event("#edda_sorin_mob","OnSpawn00",false);
	}
	end;
	
OnTouch:
	npctalk "Seyren : Adventurer, this way!";
end;
}

1@gol1,126,221,3	script	Rekenber Guard#edda_sorin_0-0	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : What's wrong with you people?";
	end;
}

1@gol1,126,217,1	script	Rekenber Guard#edda_sorin_0-1	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Damn, another one arrived.";
	end;
}

1@gol1,112,197,5	script	Rekenber Guard#edda_sorin_1-0	4_M_LGTGUARD,{ end; }
1@gol1,116,197,3	script	Rekenber Guard#edda_sorin_1-1	4_M_LGTGUARD,{ end; }
1@gol1,112,199,5	script	Rekenber Guard#edda_sorin_1-2	4_M_LGTGUARD,{ end; }
1@gol1,116,199,3	script	Rekenber Guard#edda_sorin_1-3	4_M_LGTGUARD,{ end; }

1@gol1,114,191,5	script	Seyren Windsor#edda_sorin_1-0	4_M_MD_SEYREN,3,3,{
	.@var = get_instance_var("acolyte_lab");
	if(.@var == 3){
		instance_event("Magaleta Sorin#edda_sorin_1-0","OnEvent",true);
		end;
	}
	
}

1@gol1,119,183,1	script	Magaleta Sorin#edda_sorin_1-0	4_F_MD_MAGALETA,{
	.@var = get_instance_var("acolyte_lab");
	if(.@var < 3)
		end;
	if(.@var == 3){
		instance_event(strnpcinfo(0),"OnEvent",true);
		end;
	}
	end;
	
OnEvent:
	cutin "bio_seyren01",1;
	mes "[ Seyren Windsor ]";
	mes "Sorin! Can you hear me, Sorin?!";
	mes "Come on... We need to find a way to save Sorin.";
	npctalk "Seyren : Come on... We need to find a way to save Sorin.",instance_npcname("Seyren Windsor#edda_sorin_1-0");
	next;
	mes "[ Seyren Windsor ]";
	mes "Let's look around in this room!";
	npctalk "Seyren : Let's look around in this room!",instance_npcname("Seyren Windsor#edda_sorin_1-0");
	close2;
	cutin "",255;
end;
}

1@gol1,128,192,0	script	Experiment Report#edda_sorin_1-0	4_ENERGY_WHITE,{
	.@var = get_instance_var("acolyte_lab");
	if(.@var < 3)
		end;
	if(.@var == 3){
		mes "[ " + strcharinfo(0) + " ]";
		mes "I have found something. I'll read it to Seyren.";
		unittalk getcharid(3),strcharinfo(0) + " : I have found something. I'll read it to Seyren.";
		next;
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "Wait, what.";
		mes "Replaced the heart with the battle core prototype to maximize combat capability.";
		npctalk "Seyren : Wait, what. Replaced the heart with the battle core prototype to maximize combat capability.",instance_npcname("Seyren Windsor#edda_sorin_1-0");
		next;
		mes "[ Seyren Windsor ]";
		mes "What have they done to Sorin!";
		mes "What's happening, Sorin!";
		npctalk "Seyren : What have they done to Sorin! What's happening, Sorin!",instance_npcname("Seyren Windsor#edda_sorin_1-0");
		next;
		cutin "bio_seyren01",1;
		mes "[ Seyren Windsor ]";
		mes "We've got to fight.";
		mes "Are you the one who experimented on Sorin?";
		npctalk "Seyren : Are you the one who experimented on Sorin?",instance_npcname("Seyren Windsor#edda_sorin_1-0");
		for(.@i = 0; .@i < 2; .@i++)
			instance_hide("Rekenber Guard#edda_sorin_1-" + .@i,false);
		next;
		cutin "",255;
		mes "[ Rekenber Guard ]";
		mes "The experiments are up to the Regenschirm scientists.";
		npctalk "Rekenber Guard : The experiments are up to the Regenschirm scientists.",instance_npcname("Rekenber Guard#edda_sorin_1-1");
		next;
		mes "[ Rekenber Guard ]";
		mes "It's our job to bring back the experiments that are running around this place.";
		npctalk "Rekenber Guard : It's our job to bring back the experiments that are running around this place.",instance_npcname("Rekenber Guard#edda_sorin_1-0");
		next;
		cutin "bio_seyren02",1;
		mes "[ Seyren Windsor ]";
		mes "Is that so. Then I'll kill them all.";
		mes "I'll start with you, then find those researchers at Regenschirm, I'll destroy everything.";
		npctalk "Seyren : Is that so. Then I'll kill them all. 'll start with you, then find those researchers at Regenschirm, I'll destroy everything.",instance_npcname("Seyren Windsor#edda_sorin_1-0");
		next;
		specialeffect EF_BOWLINGBASH,AREA,instance_npcname("Seyren Windsor#edda_sorin_1-0");
		sleep2 50;
		specialeffect EF_SCREEN_QUAKE,AREA,instance_npcname("Seyren Windsor#edda_sorin_1-0");
		mes "[ Seyren Windsor ]";
		mes "No one will forgive you for what you've done to Sorin.";
		npctalk "Seyren : No one will forgive you for what you've done to Sorin.",instance_npcname("Seyren Windsor#edda_sorin_1-0");
		close2;
		cutin "",255;
		for(.@i = 0; .@i < 2; .@i++)
			instance_hide("Rekenber Guard#edda_sorin_1-" + .@i,true);
		instance_event("#edda_sorin_mob","OnSpawn01",false);
		end;
	}
	end;
}

1@gol1,1,1,0	script	#edda_sorin_mob	-1,{
	end;
	
OnSpawn00:
	set_instance_var("acolyte_lab",2);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	setarray .@xy,121,220,20542,122,218,20542,123,221,20543,123,221,20543,122,218,20543;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill00:
	set_instance_var("acolyte_lab",3);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("acolyte_lab",3);
		instance_hide("Seyren Windsor#edda_sorin_0-0",true);
		instance_enable("Seyren Windsor#edda_sorin_0-0",false);
		instance_enable("Seyren Windsor#edda_sorin_1-0",true);
	}	
end;

OnSpawn01:
	set_instance_var("acolyte_lab",4);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	setarray .@xy,113,196,20543,113,197,20543,112,197,20542,112,198,20542,113,200,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill01:
	set_instance_var("acolyte_lab",5);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		npctalk "Seyren : Damn it. I'm going to kill every single one of them!",instance_npcname("Seyren Windsor#edda_sorin_1-0");
		sleep 1500;
		for(.@i = 0; .@i < 4; .@i++)
			instance_hide("Rekenber Guard#edda_sorin_1-" + .@i,false);
		npctalk "Rekenber Guard : Quick, get the gas! It doesn't matter. Use all of it!",instance_npcname("Rekenber Guard#edda_sorin_1-0");
		npctalk "Rekenber Guard : But, Dr. Wolfchev said don't use it!!!",instance_npcname("Rekenber Guard#edda_sorin_1-3");
		sleep 1200;
		specialeffect EF_BLESSING,AREA,instance_npcname("Seyren Windsor#edda_sorin_1-0");
		specialeffect EF_BLESSING,AREA,instance_npcname("Magaleta Sorin#edda_sorin_1-0");
		npctalk "Sorin : I'm crying like a fool. The clothes and the faces aren't vivid at all. Without my soul, I can't, I can't.",instance_npcname("Magaleta Sorin#edda_sorin_1-0");
		npctalk "Seyren : Sorin? Is that you? Can you hear me? Are you alright?!",instance_npcname("Seyren Windsor#edda_sorin_1-0");
		sleep 1200;
		specialeffect EF_ICECRASH,AREA,instance_npcname("Magaleta Sorin#edda_sorin_1-0");
		classchange 4_F_MD_MAGALETA_D,instance_npcname("Magaleta Sorin#edda_sorin_1-0");
		specialeffect EF_DESPERADO,AREA,instance_npcname("Seyren Windsor#edda_sorin_1-0");
		npctalk "Sorin : Oh hear me great father, Odin. Please, help us...",instance_npcname("Magaleta Sorin#edda_sorin_1-0");
		npctalk "Seyren : Sorin? No please, Sorin!!!",instance_npcname("Seyren Windsor#edda_sorin_1-0");
		npctalk "Rekenber Guard : Now! Hold him down!!!",instance_npcname("Rekenber Guard#edda_sorin_1-0");
		sleep 1200;
		specialeffect EF_CRYSTAL_BLUE,AREA,instance_npcname("Seyren Windsor#edda_sorin_1-0");
		sleep 100;
		specialeffect EF_WHITEBODY,AREA,instance_npcname("Magaleta Sorin#edda_sorin_1-0");
		specialeffect EF_GRAYBODY,AREA,instance_npcname("Magaleta Sorin#edda_sorin_1-0");
		specialeffect EF_WHITEBODY,AREA,instance_npcname("Seyren Windsor#edda_sorin_1-0");
		specialeffect EF_GRAYBODY,AREA,instance_npcname("Seyren Windsor#edda_sorin_1-0");
		for(.@i = 0; .@i < 4; .@i++){
			specialeffect EF_WHITEBODY,AREA,instance_npcname("Rekenber Guard#edda_sorin_1-" + .@i);
			specialeffect EF_GRAYBODY,AREA,instance_npcname("Rekenber Guard#edda_sorin_1-" + .@i);
		}
		sleep 1000;
		for(.@i = 0; .@i < 4; .@i++){
			instance_hide("Rekenber Guard#edda_sorin_1-" + .@i,true);
			instance_enable("Rekenber Guard#edda_sorin_1-" + .@i,false);
		}
		instance_hide("Seyren Windsor#edda_sorin_1-0",true);
		instance_hide("Magaleta Sorin#edda_sorin_1-0",true);
		instance_enable("Seyren Windsor#edda_sorin_1-0",false);
		instance_enable("Magaleta Sorin#edda_sorin_1-0",false);	
		instance_hide("Sierra#edda_sorin_0",false);
		sleep 1500;
		npctalk "Sierra : You probably know why I'm here.",instance_npcname("Sierra#edda_sorin_0");
		sleep 3000;
		npctalk "Sierra : Magaleta Sorin died here and Seyron Windsor can't leave this place.",instance_npcname("Sierra#edda_sorin_0");
		sleep 3000;
		npctalk "Sierra : It's no use helping. Please talk to me. I'll get you to the situation room.",instance_npcname("Sierra#edda_sorin_0");
		set_instance_var("acolyte_lab",6);
		.@var = get_instance_var("edda_lab");
		if(.@var == 4)
			set_instance_var("edda_lab",5);
	}
end;
}

1@gol1,114,186,3	script	Sierra#edda_sorin_0	4_F_SCIENCE,{
	.@var = get_instance_var("acolyte_lab");
	if(.@var == 6){
		.@map$ = get_instance_var("first_floor$");
		if(isbegin_quest(16394))
			erasequest 16394;
		warp .@map$,201,42;
	}
	end;
}

1@gol1,158,108,3	script	Harword Alt-Eisen#edda_harword_0-0	4_M_MD_HARWORD,{
	.@var = get_instance_var("merchant_lab");
	if(.@var == 1){
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Woah!!!";
		npctalk "Harword : Woah!!!";
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Hey, " + strcharinfo(0);
		mes "Help me out here~";
		npctalk "Harword : Hey, help me out here~";
		next;
		mes "[ Harword Alt-Eisen ]";
		mes "I woke up in a oddly made glass tube, and I escaped somehow, but they saw me running away. It's too hard by myself.";
		npctalk "Harword : I woke up in a oddly made glass tube, and I escaped somehow, but they saw me running away. It's too hard by myself.";
		next;
		cutin "",255;
		mes "[ Rekenber Guard ]";
		mes "The subject is here.";
		npctalk "Rekenber Guard : The subject is here.",instance_npcname("Rekenber Guard#edda_harword_0-0");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Finally, an ally with such superhuman tenacity! Isn't it great?";
		npctalk "Harword : Finally, an ally with such superhuman tenacity! Isn't it great?";
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "If only Shecil is here, it would have been perfect, but I already know that life is imperfect, hahaha!";
		npctalk "Harword : If only Shecil is here, it would have been perfect, but I already know that life is imperfect, hahaha!";
		next;
		cutin "",255;
		mes "[ Rekenber Guard ]";
		mes "...";
		npctalk "Rekenber Guard : ...",instance_npcname("Rekenber Guard#edda_harword_0-1");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "But I wish my sister would be here.";
		npctalk "Harword : But I wish my sister would be here.";
		next;
		cutin "",255;
		mes "[ Rekenber Guard ]";
		mes "Damn this guy can't just shut up! Are you kidding me!";
		npctalk "Rekenber Guard : Damn this guy can't just shut up! Are you kidding me!",instance_npcname("Rekenber Guard#edda_harword_0-2");
		next;
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "I'm sorry, you're dealing with them for me, right?";
		mes strcharinfo(0) + ". I'm so tired, I need your help!";
		npctalk "Harword : I'm sorry, you're dealing with them, right? I'm so tired, I need your help!";
		close2;
		cutin "",255;
		for(.@i = 0; .@i < 3; .@i++){
			instance_hide("Rekenber Guard#edda_harword_0-" + .@i,true);
			instance_enable("Rekenber Guard#edda_harword_0-" + .@i,false);
		}
		instance_event("#edda_harword_mob","OnSpawn00",false);
		end;
	}
	if(.@var == 3){
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "The door to this laboratory is blocked. Obviously, you can see the way out, but for some reason you can't pass through the wall. It's as if there's a barrier on it. What kind of technology is this?";
		next;
		mes "[ Harword Alt-Eisen ]";
		mes "Let's find a way out. The switch must be in here somewhere!";
		close3;
	}
	end;
}

1@gol1,162,121,7	script	Harword Alt-Eisen#edda_harword_0-1	4_M_MD_HARWORD,{ end; }

1@gol1,169,103,7	script	Harword Alt-Eisen#edda_harword_0-2	4_M_MD_HARWORD,{
	specialeffect EF_COIN;
	npctalk "Harword : My hands are full! I'm getting weaker slowly. No, not possible.";
	end;
}

1@gol1,164,126,0	script	Switch#edda_harword_0-0	4_ENERGY_WHITE,{
	.@var = get_instance_var("merchant_lab");
	if(.@var == 3){
		instance_hide("Harword Alt-Eisen#edda_harword_0-0",true);
		instance_enable("Harword Alt-Eisen#edda_harword_0-0",false);
		instance_hide("Harword Alt-Eisen#edda_harword_0-1",false);
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Hey, isn't this suspicious? This device has been touched more than everywhere else.";
		npctalk "Harword : Hey, isn't this suspicious? This device has been touched more than everywhere else.",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		cutin "",255;
		select("I don't know.");
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Help me figure this out, haha! The door to this laboratory is blocked. Obviously, you can see the way out, but for some reason you can't pass through the wall. It's as if there's a barrier on it. What kind of technology is this?";
		npctalk "Harword : The door to this laboratory is blocked. Obviously, you can see the way out, but for some reason you can't pass through the wall. It's as if there's a barrier on it. What kind of technology is this?",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "I wonder what's this all about.";
		npctalk "Harword : I wonder what's this all about.",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		select("Can't I touch it like that?!");
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "You can't touch it? Of course you can't.";
		mes "But I can, by being delicate!";
		mes "Is your body the same as I, a great blacksmith?";
		npctalk "Harword : You can't touch it? Of course you can't. But I can, by being delicate! Is your body the same as I, a great blacksmith?",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		mes "[ Harword Alt-Eisen ]";
		mes "I see~ I see~";
		npctalk "Harword : I see~ I see~",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Hmm~ My sister Shecil~ Hmm~";
		npctalk "Harword : Hmm~ My sister Shecil~ Hmm~",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		cutin "bio_harword01",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Okay! Good, then we'll see what's going on out there.";
		npctalk "Harword : Okay! Good, then we'll see what's going on out there.",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		for(.@i = 3; .@i < 6; .@i++)
			instance_hide("Rekenber Guard#edda_harword_0-" + .@i,false);
		cutin "bio_harword04",2;
		mes "[ Harword Alt-Eisen ]";
		mes "Oh, there are things I wish there weren't near us.";
		npctalk "Harword : Oh, there are things I wish there weren't near us.",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		mes "[ Harword Alt-Eisen ]";
		mes "I'm already drained. I don't have the strength to fight those guards. Can you assist me?";
		npctalk "Harword : I'm already drained. I don't have the strength to fight those guards. Can you assist me?",instance_npcname("Harword Alt-Eisen#edda_harword_0-1");
		next;
		cutin "",255;
		select("Hey, is something wrong?");
		cutin "bio_harword02",2;
		mes "[ Harword Alt-Eisen ]";
		mes "It's a joke! We can't die in a place like this!";
		mes "We have to find my sister and get out of here!";
		npctalk "Harword : It's a joke! We can't die in a place like this! We have to find my sister and get out of here!";
		close2;
		cutin "",255;
		for(.@i = 3; .@i < 6; .@i++)
			instance_hide("Rekenber Guard#edda_harword_0-" + .@i,true);
		instance_hide("Harword Alt-Eisen#edda_harword_0-1",true);
		instance_enable("Harword Alt-Eisen#edda_harword_0-1",false);
		instance_hide("Harword Alt-Eisen#edda_harword_0-2",false);
		instance_event("#edda_harword_mob","OnSpawn01",false);
	}
	end;
}

1@gol1,153,109,5	script	Rekenber Guard#edda_harword_0-0	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Who are you trying to fool?";
	end;
}

1@gol1,151,106,5	script	Rekenber Guard#edda_harword_0-1	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Don't fall for his provocations!";
	end;
}

1@gol1,156,104,7	script	Rekenber Guard#edda_harword_0-2	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Ugh. Is this guy really human?";
	end;
}

1@gol1,174,109,1	script	Rekenber Guard#edda_harword_0-3	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : Hey, you!";
	end;
}

1@gol1,172,108,3	script	Rekenber Guard#edda_harword_0-4	4_M_LGTGUARD,{
	npctalk "Rekenber Guard : What are you trying to pull here?";
	end;
}

1@gol1,174,105,1	script	Rekenber Guard#edda_harword_0-5	4_M_LGTGUARD,{ end; }
1@gol1,173,104,7	script	Rekenber Guard#edda_harword_0-6	4_M_LGTGUARD,{ end; }
1@gol1,169,99,1	script	Rekenber Guard#edda_harword_0-7	4_M_LGTGUARD,{ end; }





1@gol1,1,1,0	script	#edda_harword_mob	-1,{
	end;
	
OnSpawn00:
	set_instance_var("merchant_lab",2);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	setarray .@xy,154,104,20542,154,104,20543,156,104,20542,156,104,20543;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("merchant_lab",3);
		instance_hide("Switch#edda_harword_0-0",false);
		npctalk "Harword : Woah! I almost died there. Thank you so much. Now we should find a way out of here.",instance_npcname("Harword Alt-Eisen#edda_harword_0-0");
	}
end;

OnSpawn01:
	set_instance_var("merchant_lab",4);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	setarray .@xy,167,108,20542,167,108,20542,167,107,20542,168,107,20542,168,107,20541;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("merchant_lab",5);
		instance_hide("Switch#edda_harword_0-0",false);
		npctalk "Harword : Nice!!! We can escape from here!!! Yeah!!!",instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		sleep 1500;
		for(.@i = 3; .@i < 6; .@i++)
			instance_hide("Rekenber Guard#edda_harword_0-" + .@i,false);
		npctalk "Rekenber Guard : Hey!",instance_npcname("Rekenber Guard#edda_harword_0-4");
		npctalk "Rekenber Guard : We need reinforcements here!",instance_npcname("Rekenber Guard#edda_harword_0-5");
		npctalk "Harword : You're shouting to cheer yourself up? Well that doesn't cheer me up at all.",instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		sleep 1200;
		specialeffect EF_DESPERADO,AREA,instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		specialeffect EF_COIN,AREA,instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		sleep 100;
		for(.@i = 6; .@i < 8; .@i++)
			instance_hide("Rekenber Guard#edda_harword_0-" + .@i,false);
		sleep 1200;
		npctalk "Harword : Damn. This doesn't look good.",instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		sleep 1200;
		specialeffect EF_DESPERADO,AREA,instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		sleep 1000;
		specialeffect EF_CRYSTAL_BLUE,AREA,instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		sleep 100;
		specialeffect EF_WHITEBODY,AREA,instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		specialeffect EF_GRAYBODY,AREA,instance_npcname("Harword Alt-Eisen#edda_harword_0-2");
		for(.@i = 0; .@i < 8; .@i++){
			specialeffect EF_WHITEBODY,AREA,instance_npcname("Rekenber Guard#edda_harword_0-" + .@i);
			specialeffect EF_GRAYBODY,AREA,instance_npcname("Rekenber Guard#edda_harword_0-" + .@i);
		}
		sleep 1000;
		for(.@i = 0; .@i < 8; .@i++){
			instance_hide("Rekenber Guard#edda_harword_0-" + .@i,true);
			instance_enable("Rekenber Guard#edda_harword_0-" + .@i,false);
		}
		instance_hide("Harword Alt-Eisen#edda_harword_0-2",true);
		instance_enable("Harword Alt-Eisen#edda_harword_0-2",false);
		instance_hide("Sierra#edda_harword_0",false);
		sleep 1500;
		npctalk "Sierra : You probably know why I'm here.",instance_npcname("Sierra#edda_harword_0");
		sleep 3000;
		npctalk "Sierra : Harword Alt-Eisen can't leave this place.",instance_npcname("Sierra#edda_harword_0");
		sleep 3000;
		npctalk "Sierra : It's no use helping. Please talk to me. I'll get you to the situation room.",instance_npcname("Sierra#edda_harword_0");
		set_instance_var("merchant_lab",6);
		.@var = get_instance_var("edda_lab");
		if(.@var == 4)
			set_instance_var("edda_lab",5);
	}
end;
}

1@gol1,166,109,3	script	Sierra#edda_harword_0	4_F_SCIENCE,{
	.@var = get_instance_var("merchant_lab");
	if(.@var == 6){
		.@map$ = get_instance_var("first_floor$");
		if(isbegin_quest(16397))
			erasequest 16397;
		warp .@map$,201,42;
	}
	end;
}

1@gol1,1,1,0	script	#edda_combat_mob	-1,{
	end;

OnSpawn00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	setarray .@xy,161,190,20542,160,189,20542,159,188,20542,156,188,20542,171,200,20542,175,202,20542,176,201,20542,177,202,20542,
	158,203,20541,159,204,20541,160,203,20541,161,203,20541,173,189,20543,175,189,20543,176,188,20543,176,187,20543;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_lab_c",1);
		instance_enable("Sierra#edda_combat_1",true);
		instance_event(strnpcinfo(0),"OnSpawn01",false);
		sleep 3000;
		.@party_id = 'party_id;
		warpparty .@map$,67,274,.@party_id,.@map$;
	}
end;

OnSpawn01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	setarray .@xy,70,294,20542,72,294,20541,72,292,20542,72,291,20542,72,289,20542,73,289,20543,74,292,20542,75,290,20542,76,290,20541,
	62,310,20538,64,310,20538,65,308,20541,65,306,20542,67,306,20542,69,308,20542,71,308,20541,73,307,20542,63,307,20542,
	8,317,20542,10,317,20542,13,317,20542,15,317,20542,14,319,20543,12,319,20543,10,319,20541,8,319,20541,10,321,20542,13,321,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_lab_c",2);
		instance_enable("Sierra#edda_combat_2",true);
		instance_event(strnpcinfo(0),"OnSpawn02",false);
		sleep 3000;
		.@party_id = 'party_id;
		warpparty .@map$,113,191,.@party_id,.@map$;
	}
end;

OnSpawn02:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill02";
	setarray .@xy,104,187,20542,104,189,20542,106,190,20542,127,195,20542,128,195,20542,129,194,20542,110,202,20543,111,202,20543,111,203,20543,127,207,20541,129,207,20541,131,207,20541,
	121,221,20543,118,221,20543,114,221,20541,114,218,20541,118,218,20541,121,218,20541,89,224,20542,89,221,20542,89,218,20542,92,218,20542,92,221,20542,92,224,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill02:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill02";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_lab_c",3);
		instance_enable("Sierra#edda_combat_3",true);
		instance_enable("#edda_eremes_effect",true);
		for(.@i = 0; .@i < 2; .@i++)
			instance_enable("Vision Device#edda_combat_" + .@i,true);
		instance_event(strnpcinfo(0),"OnSpawn03",false);
		sleep 3000;
		.@party_id = 'party_id;
		instance_event("#edda_eremes_effect","OnEffect",false);
		warpparty .@map$,80,110,.@party_id,.@map$;
	}
end;

OnSpawn03:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill03";
	setarray .@xy,59,110,20542,58,111,20542,57,111,20543,58,110,20543,57,108,20543,58,114,20541,58,113,20542,57,109,20543,
	91,141,20543,94,141,20543,97,141,20543,97,138,20541,91,138,20541,91,135,20542,94,135,20542,97,137,20542,
	53,139,20542,53,136,20542,53,133,20542,48,138,20541,48,135,20538,48,132,20538,87,93,20538,87,88,20538,83,93,20542,83,101,20542,83,86,20541;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill03:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill03";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_lab_c",4);
		instance_enable("Sierra#edda_combat_4",true);
		instance_enable("#edda_eremes_effect",false);
		for(.@i = 0; .@i < 3; .@i++)
			instance_enable("#edda_combat_wall_0-" + .@i,true);
		setcell .@map$,127,36,133,37,CELL_WALKABLE,false;
		setcell .@map$,127,36,133,37,CELL_SHOOTABLE,false;
		for(.@i = 0; .@i < 8; .@i++){
			instance_enable("#edda_combat_wall_1-" + .@i,true);
			instance_hide("#edda_combat_wall_1-" + .@i,true);
			instance_enable("#edda_combat_wall_3-" + .@i,true);
			instance_hide("#edda_combat_wall_3-" + .@i,true);			
		}
		for(.@i = 0; .@i < 5; .@i++){
			instance_enable("#edda_combat_wall_2-" + .@i,true);
			instance_hide("#edda_combat_wall_2-" + .@i,true);
			instance_enable("#edda_combat_wall_4-" + .@i,true);
			instance_hide("#edda_combat_wall_4-" + .@i,true);
		}
		instance_event(strnpcinfo(0),"OnSpawn04",false);
		sleep 3000;
		.@party_id = 'party_id;
		warpparty .@map$,117,28,.@party_id,.@map$;
		instance_enable("#edda_combat_silence_0",true);
		instance_event("#edda_combat_silence_0","OnActive",false);
	}
end;

OnSpawn04:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill04";
	setarray .@xy,100,29,20542,100,16,20542,103,17,20541,117,31,20542,127,32,20542,125,28,20542,131,28,20541;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill04:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill04";
	if(!mobcount(.@map$,.@event$)){
		for(.@i = 0; .@i < 3; .@i++){
			instance_hide("#edda_combat_wall_0-" + .@i,true);
			instance_enable("#edda_combat_wall_0-" + .@i,false);
		}
		setcell .@map$,127,36,133,37,CELL_WALKABLE,true;
		setcell .@map$,127,36,133,37,CELL_SHOOTABLE,true;
		for(.@i = 0; .@i < 4; .@i++)
			instance_enable("#edda_combat_trap_" + .@i,true);
		
	}
end;

OnWarp04:
	sleep 3000;
	.@map$ = get_instance_var("first_floor$");
	.@party_id = 'party_id;
	set_instance_var("edda_lab_c",5);
	instance_enable("Sierra#edda_combat_5",true);
	instance_event(strnpcinfo(0),"OnSpawn05",false);
	for(.@i = 0; .@i < 7; .@i++)
		instance_enable("#edda_combat_mimic_" + .@i,true);
	warpparty .@map$,168,105,.@party_id,.@map$;
end;

OnSpawn05:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill05";
	setarray .@xy,161,118,20542,163,120,20542,166,120,20542,159,110,20537,158,108,20537,158,107,20537,156,111,20537,158,108,20537,158,107,20537,158,107,20537,148,111,20539,147,110,20539,146,109,20539,
	142,109,20539,143,109,20539,145,109,20539,142,112,20543,142,110,20542,147,119,20541,149,121,20538,149,119,20538,
	155,139,20537,155,137,20537,155,135,20537,155,133,20537,153,133,20539,153,135,20539,153,137,20539,153,139,20539,159,139,20542,159,137,20543,159,135,20542,159,133,20543,156,140,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill05:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill05";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_lab_c",6);
		instance_enable("Sierra#edda_combat_6",true);
		instance_event(strnpcinfo(0),"OnSpawn06",false);
		instance_event(strnpcinfo(0),"OnWarp05",false);
	}
end;

OnWarp05:
	sleep 3000;
	.@map$ = get_instance_var("first_floor$");
	.@party_id = 'party_id;
	warpparty .@map$,160,298,.@party_id,.@map$;
end;

OnSpawn06:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill06";
	setarray .@xy,173,303,20537,172,302,20537,172,301,20537,173,301,20537,174,301,20537,174,302,20537,154,299,20541,154,301,20541,153,301,20541,153,300,20541,151,298,20543,151,296,20543,151,295,20543,150,295,20543,
	150,304,20542,149,306,20542,147,304,20542,146,305,20542;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill06:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill06";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_lab_c",7);
		instance_enable("Sierra#edda_combat_7",true);
		npctalk "Sierra : Let's go to the last room. The morgue.",instance_npcname("Sierra#edda_combat_6");
		for(.@i = 0; .@i < 14; .@i++){
			instance_enable("#edda_c_wall_0-" + .@i,true);
			instance_enable("#edda_c_wall_1-" + .@i,true);
			instance_enable("#edda_c_wall_2-" + .@i,true);
			instance_enable("#edda_c_wall_3-" + .@i,true);
			instance_hide("#edda_c_wall_0-" + .@i,true);
			instance_hide("#edda_c_wall_1-" + .@i,true);
			instance_hide("#edda_c_wall_2-" + .@i,true);
			instance_hide("#edda_c_wall_3-" + .@i,true);
		}
	}
end;
}

1@gol1,171,204,3	script	Sierra#edda_combat_0	4_F_SCIENCE,{
	.@map$ = get_instance_var("first_floor$");
	.@var = get_instance_var("edda_lab_c");
	.@id = atoi(replacestr(strnpcinfo(2),"edda_combat_",""));
	if(.@var <= .@id){
		instance_event(strnpcinfo(0),"OnTalk" + .@id,false);
		end;
	}
	switch(.@id){
		case 0:
			warp .@map$,67,274;
			break;
			
		case 1:
			warp .@map$,113,191;
			break;
			
		case 2:
			warp .@map$,80,110;
			break;
			
		case 3:
			warp .@map$,117,28;
			break;
			
		case 4:
			warp .@map$,168,105;
			break;
			
		case 5:
			warp .@map$,160,298;
			break;
			
		case 6:
			.@map$ = get_instance_var("second_floor$");
			npctalk strnpcinfo(1) + " : " + "The next room is where the bodies of the expedition members were stored.";
			sleep2 200;
			warp .@map$,49,20;
			break;
	}
	end;
	
OnTalk0:
	npctalk strnpcinfo(1) + " : " + "This reception room is where they're supposed to meet the president. This is where Seyren and the rest of the expedition members were poisoned with sleeping gas.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Except Eremes Guile who managed to escape from this room with Katrinn Keyron.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "The other members who failed to escape have been taken to each laboratory made for them.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "This room still has the sleeping gas due to the virtualization of the events that took here.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Don't let your guard down, there are a circular waves just before it starts to spread.";
end;

OnTalk1:
	npctalk strnpcinfo(1) + " : " + "Seyren Windsor's heart was removed and implanted with a Battle Core, but he died shortly after the core was implanted.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Even Seyren Windsor died, his spirit started looking for the others with the strong will that he will save everyone.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "In order to stop Lord Knight Seyren's disturbance, they prepared a lot of guards in the examination lab.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Once you're done in this lab, you can proceed to the next one.";
end;

OnTalk2:
	npctalk strnpcinfo(1) + " : " + "Magaleta Sorin also failed to escape and her heart was replaced with a Battle Core earlier than most members.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Magaleta Sorin was experimented for the divine power she possess, but she died shortly after.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Sorin's will made her spirit devoted to save the rest of her party.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Please stop all the guards deployed to stop Sorin.";
end;

OnTalk3:
	npctalk strnpcinfo(1) + " : " + "Eremes Guile took Katrinn Keyron and tried to escape, but Eremes fell into a trap and hands over Katrinn Keyron into the enemy.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Eremes then caught and his heart was changed into a Battle Core.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Eremes because furious and lost control of himself after the Battle Core transplant. Seyren Windsor found Eremes and help him regain consciousness.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "You must pay attention in this room, you'll find it hard to move around as time goes on.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Let's quickly stop the guards and move to the next lab.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "I've set up the Vision Devices to return your vision. Make sure you use it to your benefit.";
end;

OnTalk4:
	npctalk strnpcinfo(1) + " : " + "Katrinn Keyron escaped with Eremes Guile after the ambush on the conference room. However she had already been poisoned and silenced.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Katrinn Keyron was captured again and unable to do anything her heart was replaced with a Battle Core. She's then stored inside a glass tube.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "There are chemical walls and silencing devices meant to stop Katrinn Keyron around this room.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Be careful, you'll get hurt as well if you walk around carelessly.";	
end;

OnTalk5:
	npctalk strnpcinfo(1) + " : " + "Harword Alt-Eisen broke free from his glass tube and escapes after the Battle Core was implanted on him.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "While hiding from the guards, he met Seyren who is looking to save the others and they went together.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "This lab has several traps in the image of a mimic, they're devices that has beneficial effect.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Perhaps it's a device to test the merchant's luck?";
end;

OnTalk6:
	npctalk strnpcinfo(1) + " : " + "After Shecil Damon's heart was replaced with a battle core, she soon escaped on her own.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "While she's escaping, she learns about the Heart of Ymir and learns about how to use the battle core. She then uses the battle core to fight the guards.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "Most of the guards that fled or lost their lives was forced to fight against people who were no longer humans.";
	sleep 3000;
	npctalk strnpcinfo(1) + " : " + "In Shecil Damon's virtualization, you'll encounter very powerful enemies.";
end;
}

1@gol2,1,1,0	script	#edda_combat_boss	-1,{
	end;
	
OnSpawn:
	set_instance_var("edda_lab_c",9);
	instance_enable("Sierra#edda_combat_7",false);
	instance_enable("Sierra#edda_combat_8",false);

	instance_event(strnpcinfo(0),"OnWarp",false);
	.@map$ = get_instance_var("second_floor$");
	monster .@map$,49,63,"Nameless Swordsman",20536,1,instance_npcname(strnpcinfo(0)) + "::OnBossKill";
	set_instance_var("edda_boss",1);
	for(.@i = 0; .@i < 2; .@i++)
		instance_enable("#edda_c_wall_4-" + .@i,true);
	setcell .@map$,50,44,52,44,CELL_WALKABLE,false;
	setcell .@map$,50,44,52,44,CELL_SHOOTABLE,false;	
	instance_event(strnpcinfo(0),"OnSlave",false);
end;

OnBossKill:
	.@party_id = 'party_id;
	set_instance_var("edda_boss",0);
	.@map$ = get_instance_var("second_floor$");
	setarray .@xy,52,60,52,53,52,53,59,53,59,53,59,60,59,60,52,60,52,64,52,71,52,71,59,71,59,71,59,64,59,64,52,71,48,60,48,53,48,53,41,53,41,53,41,60,41,60,48,60,48,64,48,71,48,71,41,71,41,71,41,64,41,64,48,64;
	killmonster .@map$,instance_npcname(strnpcinfo(0)) + "::OnSlaveDie";
	for(.@i = 0; .@i < 14; .@i++){
		instance_hide("#edda_c_wall_0-" + .@i,true);
		instance_hide("#edda_c_wall_1-" + .@i,true);
		instance_hide("#edda_c_wall_2-" + .@i,true);
		instance_hide("#edda_c_wall_3-" + .@i,true);
		instance_enable("#edda_c_wall_0-" + .@i,false);
		instance_enable("#edda_c_wall_1-" + .@i,false);
		instance_enable("#edda_c_wall_2-" + .@i,false);
		instance_enable("#edda_c_wall_3-" + .@i,false);
	}
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 4){
		setcell .@map$,.@xy[.@i],.@xy[.@i+1],.@xy[.@i+2],.@xy[.@i+3],CELL_WALKABLE,true;
		setcell .@map$,.@xy[.@i],.@xy[.@i+1],.@xy[.@i+2],.@xy[.@i+3],CELL_SHOOTABLE,true;
	}
	set_instance_var("edda_lab_c",10);
	instance_enable("Sierra#edda_combat_9",true);
	for(.@i = 0; .@i < 2; .@i++){
		instance_hide("#edda_c_wall_4-" + .@i,true);
		instance_enable("#edda_c_wall_4-" + .@i,false);
	}
	setcell .@map$,50,44,52,44,CELL_WALKABLE,true;
	setcell .@map$,50,44,52,44,CELL_SHOOTABLE,true;
	if(rand(1,100) >= 75) //= 25% Chance
		instance_enable("???#edda_combat_reward",true);
	npctalk "Sierra : The battle data has been interpreted safely.",instance_npcname("Sierra#edda_combat_9");
	killmonster .@map$,instance_npcname(strnpcinfo(0)) + "::OnSlaveDie";
	callfunc("instance_points", 10);
end;

OnSlave:
	.@map$ = get_instance_var("second_floor$");
	setarray .@xy,52,60,52,53,52,53,59,53,59,53,59,60,59,60,52,60,52,64,52,71,52,71,59,71,59,71,59,64,59,64,52,71,48,60,48,53,48,53,41,53,41,53,41,60,41,60,48,60,48,64,48,71,48,71,41,71,41,71,41,64,41,64,48,64;
	while(get_instance_var("edda_boss") > 0){
		for(.@i = 0; .@i < 14; .@i++){
			instance_hide("#edda_c_wall_0-" + .@i,false);
			instance_hide("#edda_c_wall_1-" + .@i,false);
			instance_hide("#edda_c_wall_2-" + .@i,false);
			instance_hide("#edda_c_wall_3-" + .@i,false);
			sleep 480;
		}
		for(.@i = 0; .@i < getarraysize(.@xy); .@i += 4){
			setcell .@map$,.@xy[.@i],.@xy[.@i+1],.@xy[.@i+2],.@xy[.@i+3],CELL_WALKABLE,false;
			setcell .@map$,.@xy[.@i],.@xy[.@i+1],.@xy[.@i+2],.@xy[.@i+3],CELL_SHOOTABLE,false;
		}
		setarray .@mob,56,70,20538,56,56,20539,44,56,20542,44,68,20543;
		for(.@i = 0; .@i < getarraysize(.@mob); .@i += 3){
			if(get_instance_var("edda_boss") == 1)
				monster .@map$,.@mob[.@i],.@mob[.@i+1],"--ja--",.@mob[.@i+2],1,instance_npcname(strnpcinfo(0)) + "::OnSlaveDie";
			if(get_instance_var("edda_boss") == 0){
				killmonster .@map$,instance_npcname(strnpcinfo(0)) + "::OnSlaveDie";
				break;
			}
		}
		sleep 8500;
		instance_event(strnpcinfo(0),"OnWarp",false);
		killmonster .@map$,instance_npcname(strnpcinfo(0)) + "::OnSlaveDie";
		for(.@i = 0; .@i < 14; .@i++){
			instance_hide("#edda_c_wall_0-" + .@i,true);
			instance_hide("#edda_c_wall_1-" + .@i,true);
			instance_hide("#edda_c_wall_2-" + .@i,true);
			instance_hide("#edda_c_wall_3-" + .@i,true);
		}
		for(.@i = 0; .@i < getarraysize(.@xy); .@i += 4){
			setcell .@map$,.@xy[.@i],.@xy[.@i+1],.@xy[.@i+2],.@xy[.@i+3],CELL_WALKABLE,true;
			setcell .@map$,.@xy[.@i],.@xy[.@i+1],.@xy[.@i+2],.@xy[.@i+3],CELL_SHOOTABLE,true;
		}
		sleep 15000;
		if(get_instance_var("edda_boss") == 0)
			break;
	}
	killmonster .@map$,instance_npcname(strnpcinfo(0)) + "::OnSlaveDie";
end;

OnWarp:
	.@party_id = 'party_id;
	.@map$ = get_instance_var("second_floor$");
	getpartymember .@party_id,1;
	getpartymember .@party_id,2;
	for(.@i = 0; .@i < $@partymembercount; .@i++){
		if(attachrid($@partymemberaid[.@i])){
			if(strcharinfo(3) == .@map$ && isloggedin($@partymemberaid[.@i], $@partymembercid[.@i]) && HP > 0)
				warp .@map$,52,62;
		}
	}
end;

OnSlaveDie:
end;
}

1@gol1,64,276,3	duplicate(Sierra#edda_combat_0)	Sierra#edda_combat_1	4_F_SCIENCE
1@gol1,119,196,3	duplicate(Sierra#edda_combat_0)	Sierra#edda_combat_2	4_F_SCIENCE
1@gol1,74,118,3	duplicate(Sierra#edda_combat_0)	Sierra#edda_combat_3	4_F_SCIENCE
1@gol1,113,26,3	duplicate(Sierra#edda_combat_0)	Sierra#edda_combat_4	4_F_SCIENCE
1@gol1,159,112,3	duplicate(Sierra#edda_combat_0)	Sierra#edda_combat_5	4_F_SCIENCE
1@gol1,170,305,3	duplicate(Sierra#edda_combat_0)	Sierra#edda_combat_6	4_F_SCIENCE

1@gol2,50,25,3	script	Sierra#edda_combat_7	4_F_SCIENCE,{
	.@var = get_instance_var("edda_lab_c");
	cutin "3rd_gn_demi02",2;
	mes "[ Sierra ]";
	mes "The morgue. Here is where the final battle occured against one of Wolfchev's experiment.";
	next;
	mes "[ Sierra ]";
	mes "Wolfchev considered all of this to be an experiment, but his thoughts would change depending on the battle's outcome.";
	next;
	mes "[ Sierra ]";
	mes "Go to the northern part of the morgue. I'll be waiting for you there.";
	if(.@var == 7){
		set_instance_var("edda_lab_c",8);
		instance_enable("Sierra#edda_combat_8",true);
	}
	close3;
}

1@gol2,51,63,3	script	Sierra#edda_combat_8	4_F_SCIENCE,{
	.@var = get_instance_var("edda_lab_c");
	if(.@var == 8){
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "Are all the members of this interpretation is present ^0000CDpresent inside the morgue^000000?";
		mes "To maintain accuracy of the battle results, ^0000CDall access to the morgue is going to be closed once the battle starts.^000000";
		next;
		cutin "",255;
		if(select("All members is present.:Please wait.") == 2){
			cutin "3rd_gn_demi02",2;
			mes "[ Sierra ]";
			mes "Please talk to me when all party members are present in this room. Then I'll load the combat data.";
			close3;
		}
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "Initiating the loading of the dead body data. Please wait a moment.";
		mes "Complete. All party members on this floor will be moved to the center for the battle to begin.";
		close2;
		cutin "",255;
		instance_event("#edda_combat_boss","OnSpawn",false);
	}
	end;
}

1@gol2,51,66,3	script	Sierra#edda_combat_9	4_F_SCIENCE,{
	.@var = get_instance_var("edda_lab_c");
	if(.@var == 10){	
		cutin "3rd_gn_demi02",2;
		mes "[ Sierra ]";
		mes "It have ended now, but you couldn't have known. Didn't I tell you that the data is contaminated?";
		next;
		mes "[ Sierra ]";
		mes "But I also feel a bit calm. Thank you for that. I think I had some sense of debt to them.";
		next;
		mes "[ Sierra ]";
		mes "We will pay you the items you acquired during the exploration.";
		mes "Let's regroup back to Yuno. I'll you back when you're ready.";
		if(isbegin_quest(16388) == 1)
			completequest 16388;
		if(isbegin_quest(16400) == 1)
			erasequest 16400;
		if(isbegin_quest(16392) == 0){
			setquest 16392;
			completequest 16392;
			getitem 25787,10;
			getitem 25786,10;
		}
		next;
		cutin "",255;
		if(select("Let's return.:Stay for a while.") == 2){
			cutin "3rd_gn_demi02",2;
			mes "[ Sierra ]";
			mes "Please talk to me again when you7re ready to return.";
			close3;
		}
		cutin "3rd_gn_demi01",2;
		mes "[ Sierra ]";
		mes "I'll see you again in Yuno.";
		close2;
		warp "yuno",213,344;
	}
	end;
}

1@gol2,50,62,3	script	???#edda_combat_reward	4_TREASURE_BOX,{
	mes "- Would you like to open the box? -";
	next;
	if(select("Open the box.:Don't open the box.") == 2)
		end;
	if(isbegin_quest(16391) > 0){
		mes "- This box is empty. -";
		end;
	}
	setarray .@weapon,21051,21052,32023,1333,16092,28138,28765,28766,28044,28042,26158,2055,2056,26161,2057,16095,18185,18187,18186,
	32350,32024,32025,32351,16093,16094,28767,28768,18184,28633,26159,26160,1865,1866,16096,18188,26212,26213,32107,32108;
	setquest 16391;
	completequest 16391;
	getitem .@weapon[rand(getarraysize(.@weapon))],1;
	mes "- There is something in the box. It looks strange. -";
	end;
}

1@gol1,170,114,3	script	#edda_combat_mimic_0	4_MIMIC,3,3,{
	end;
	
OnTouch:
	.@gid = getnpcid(0);
	setarray .@data,UNPC_ATKMIN,100,UNPC_ATKMAX,300,UNPC_MATKMIN,100,UNPC_MATKMAX,300,UNPC_STR,100,UNPC_AGI,100,UNPC_VIT,100,UNPC_INT,100,UNPC_DEX,100,UNPC_LUK,100;
	for(.@i = 0; .@i < 20; .@i += 2)
		setunitdata .@gid,.@data[.@i],.@data[.@i+1];
	.@map$ = get_instance_var("first_floor$");
	.@effect = rand(1,3);
	switch(.@effect){
		case 1:
			unitskilluseid .@gid,"AL_BLESSING",10,getcharid(3),-10000;
			break;
			
		case 2:
			unitskilluseid .@gid,"AL_INCAGI",10,getcharid(3),-10000;
			break;
			
		case 3:
			unitskillusepos .@gid,"NPC_EARTHQUAKE",1,.@x,.@y,-20000;
			break;
	}
	sleep 500;
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
end;
}

1@gol1,153,114,3	duplicate(#edda_combat_mimic_0)	#edda_combat_mimic_1	4_MIMIC,3,3
1@gol1,183,89,3	duplicate(#edda_combat_mimic_0)	#edda_combat_mimic_2	4_MIMIC,3,3
1@gol1,183,136,3	duplicate(#edda_combat_mimic_0)	#edda_combat_mimic_3	4_MIMIC,3,3
1@gol1,199,146,3	duplicate(#edda_combat_mimic_0)	#edda_combat_mimic_4	4_MIMIC,3,3
1@gol1,182,154,3	duplicate(#edda_combat_mimic_0)	#edda_combat_mimic_5	4_MIMIC,3,3
1@gol1,163,154,3	duplicate(#edda_combat_mimic_0)	#edda_combat_mimic_6	4_MIMIC,3,3


1@gol1,77,156,3	script	Vision Device#edda_combat_0	4_GC109,{
	.@map$ = get_instance_var("first_floor$");
	mes "[ Vision Device ]";
	mes "Nice to meet you! I'll make you see more clearly!";
	close2;
	warp .@map$,79,156;
	end;
}

1@gol1,100,108,3	script	Vision Device#edda_combat_1	4_GC109,{
	.@map$ = get_instance_var("first_floor$");
	mes "[ Vision Device ]";
	mes "Do you need help?";
	mes "I'm glad you came to me!";
	close2;
	warp .@map$,98,108;
	end;
}

1@gol1,1,1,0	script	#edda_eremes_effect	-1,{
    end;
    
OnEffect:
	sleep 2500;
    while(get_instance_var("edda_lab_c") < 4){
        .@count = getareaunits(BL_PC,instance_mapname("1@gol1"),32,84,102,165,.@player$[0]);
		for(.@i = 0; .@i < .@count; .@i++)
			specialeffect2 EF_DEVIL7,SELF,.@player$[.@i];
		deletearray .@player$[0],getarraysize(.@player$);
        sleep 10000;
    }
end;
}

1@gol1,118,22,0	script	#edda_combat_silence_0	4_SYSTEM_BOX,{
	end;

OnActive:
	.@gid = getnpcid(0);
	setarray .@data,UNPC_ATKMIN,1,UNPC_ATKMAX,1,UNPC_MATKMIN,100,UNPC_MATKMAX,100,UNPC_STR,100,UNPC_AGI,100,UNPC_VIT,100,UNPC_INT,500,UNPC_DEX,500,UNPC_LUK,100;
	for(.@i = 0; .@i < 20; .@i += 2)
		setunitdata .@gid,.@data[.@i],.@data[.@i+1];
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname("#edda_combat_mob")+"::OnMobKill04";
	while(mobcount(.@map$,.@event$)){
		npctalk "Bshhhhh... releasing silence in 10 seconds...";
		sleep 5000;
		if(!mobcount(.@map$,.@event$))
			break;
		npctalk "Bshhhhh... releasing silence in 5 seconds...";
		for(.@i = 4; .@i > 0; .@i--){
			sleep 1100;
			if(!mobcount(.@map$,.@event$))
				break;
			npctalk "Bshhhhh... releasing silence in " + .@i + " seconds...";
		}
		if(unitexists(.@gid)){
			if(!mobcount(.@map$,.@event$))
				break;
			unitskilluseid .@gid,"NPC_WIDESILENCE",1;
		}
		sleep 5000;
		if(!mobcount(.@map$,.@event$))
			break;
	}
	sleep 3000;
	npctalk "Please contact me to remove the restriction.";
end;
}

1@gol1,94,63,0	script	#edda_combat_trap_0	HIDDEN_WARP_NPC,7,0,{
	end;
	
OnTouch:
	instance_enable(strnpcinfo(0),false);
	.@id = atoi(replacestr(strnpcinfo(2),"edda_combat_trap_",""));
	instance_enable("#edda_trap_silence_" + .@id,true);
	instance_event("#edda_trap_silence_" + .@id,"OnActive",false);
	instance_event("#edda_trap_silence_" + .@id,"OnSpawn0" + .@id,false);
end;
}

1@gol1,89,21,0	duplicate(#edda_combat_trap_0)	#edda_combat_trap_1	HIDDEN_WARP_NPC,7,0
1@gol1,142,61,0	duplicate(#edda_combat_trap_0)	#edda_combat_trap_2	HIDDEN_WARP_NPC,7,0
1@gol1,146,23,0	duplicate(#edda_combat_trap_0)	#edda_combat_trap_3	HIDDEN_WARP_NPC,7,0

1@gol1,94,68,0	script	#edda_trap_silence_0	4_SYSTEM_BOX,{
	end;
	
OnActive:
	.@id$ = replacestr(strnpcinfo(2),"edda_trap_silence_","");
	.@gid = getnpcid(0);
	setarray .@data,UNPC_ATKMIN,1,UNPC_ATKMAX,1,UNPC_MATKMIN,100,UNPC_MATKMAX,100,UNPC_STR,100,UNPC_AGI,100,UNPC_VIT,100,UNPC_INT,500,UNPC_DEX,500,UNPC_LUK,100;
	for(.@i = 0; .@i < 20; .@i += 2)
		setunitdata .@gid,.@data[.@i],.@data[.@i+1];
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname("#edda_trap_silence_" + .@id$)+"::OnMobKill0" + .@id$;
	while(mobcount(.@map$,.@event$)){
		sleep 10000;
		if(unitexists(.@gid)){
			if(!mobcount(.@map$,.@event$))
				break;
			unitskilluseid .@gid,"NPC_WIDESILENCE",5;
		}
		sleep 3000;
		if(!mobcount(.@map$,.@event$))
			break;
	}
end;

OnSpawn00:
	for(.@i = 0; .@i < 8; .@i++)
		instance_hide("#edda_combat_wall_1-" + .@i,false);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	setcell .@map$,88,54,99,54,CELL_WALKABLE,false;
	setcell .@map$,88,54,99,54,CELL_SHOOTABLE,false;
	setcell .@map$,100,72,100,76,CELL_WALKABLE,false;
	setcell .@map$,100,72,100,76,CELL_SHOOTABLE,false;
	setarray .@xy,93,68,20541,92,69,20542,92,71,20542,95,71,20542,94,70,20542,95,70,20537,94,69,20537,93,70,20537,94,72,20537;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill00:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill00";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_c_trap",get_instance_var("edda_c_trap") + 1);
		npctalk "Please contact me to remove the restriction.";
		setcell .@map$,88,54,99,54,CELL_WALKABLE,true;
		setcell .@map$,88,54,99,54,CELL_SHOOTABLE,true;
		setcell .@map$,100,72,100,76,CELL_WALKABLE,true;
		setcell .@map$,100,72,100,76,CELL_SHOOTABLE,true;
		for(.@i = 0; .@i < 8; .@i++){
			instance_hide("#edda_combat_wall_1-" + .@i,true);
			instance_enable("#edda_combat_wall_1-" + .@i,false);
		}
		if(get_instance_var("edda_c_trap") >= 4)
			instance_event("#edda_combat_mob","OnWarp04",false);
	}
end;

OnSpawn01:
	for(.@i = 0; .@i < 5; .@i++)
		instance_hide("#edda_combat_wall_2-" + .@i,false);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	setcell .@map$,84,31,95,31,CELL_WALKABLE,false;
	setcell .@map$,84,31,95,31,CELL_SHOOTABLE,false;
	setarray .@xy,89,18,20542,88,17,20542,88,16,20542,91,14,20542,91,13,20542,92,14,20541,89,14,20537,88,16,20537,88,15,20537,88,12,20537;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill01:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill01";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_c_trap",get_instance_var("edda_c_trap") + 1);
		npctalk "Please contact me to remove the restriction.";
		setcell .@map$,84,31,95,31,CELL_WALKABLE,true;
		setcell .@map$,84,31,95,31,CELL_SHOOTABLE,true;
		for(.@i = 0; .@i < 5; .@i++){
			instance_hide("#edda_combat_wall_2-" + .@i,true);
			instance_enable("#edda_combat_wall_2-" + .@i,false);
		}
		if(get_instance_var("edda_c_trap") >= 4)
			instance_event("#edda_combat_mob","OnWarp04",false);
	}
end;

OnSpawn02:
	for(.@i = 0; .@i < 8; .@i++)
		instance_hide("#edda_combat_wall_3-" + .@i,false);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill02";
	setcell .@map$,136,54,147,54,CELL_WALKABLE,false;
	setcell .@map$,136,54,147,54,CELL_SHOOTABLE,false;
	setcell .@map$,135,71,135,75,CELL_WALKABLE,false;
	setcell .@map$,135,71,135,75,CELL_SHOOTABLE,false;
	setarray .@xy,144,70,20542,143,71,20542,143,72,20542,141,69,20542,142,69,20537,141,70,20537,141,71,20537,144,71,20537,142,73,20541;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;
end;

OnMobKill02:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill02";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_c_trap",get_instance_var("edda_c_trap") + 1);
		npctalk "Please contact me to remove the restriction.";
		setcell .@map$,136,54,147,54,CELL_WALKABLE,true;
		setcell .@map$,136,54,147,54,CELL_SHOOTABLE,true;
		setcell .@map$,135,71,135,75,CELL_WALKABLE,true;
		setcell .@map$,135,71,135,75,CELL_SHOOTABLE,true;
		for(.@i = 0; .@i < 8; .@i++){
			instance_hide("#edda_combat_wall_3-" + .@i,true);
			instance_enable("#edda_combat_wall_3-" + .@i,false);
		}
		if(get_instance_var("edda_c_trap") >= 4)
			instance_event("#edda_combat_mob","OnWarp04",false);
	}
end;

OnSpawn03:
	for(.@i = 0; .@i < 5; .@i++)
		instance_hide("#edda_combat_wall_4-" + .@i,false);
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill03";
	setcell .@map$,140,31,151,31,CELL_WALKABLE,false;
	setcell .@map$,140,31,151,31,CELL_SHOOTABLE,false;
	setarray .@xy,145,18,20542,145,17,20542,146,17,20542,148,18,20542,144,17,20541,146,16,20537,148,16,20537,145,15,20537,144,14,20537;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 3)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"--ja--",.@xy[.@i+2],1,.@event$;	
end;

OnMobKill03:
	.@map$ = get_instance_var("first_floor$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill03";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("edda_c_trap",get_instance_var("edda_c_trap") + 1);
		npctalk "Please contact me to remove the restriction.";
		setcell .@map$,140,31,151,31,CELL_WALKABLE,true;
		setcell .@map$,140,31,151,31,CELL_SHOOTABLE,true;
		for(.@i = 0; .@i < 5; .@i++){
			instance_hide("#edda_combat_wall_4-" + .@i,true);
			instance_enable("#edda_combat_wall_4-" + .@i,false);
		}
		if(get_instance_var("edda_c_trap") >= 4)
			instance_event("#edda_combat_mob","OnWarp04",false);
	}
end;
}

1@gol1,90,18,0	duplicate(#edda_trap_silence_0)	#edda_trap_silence_1	4_SYSTEM_BOX
1@gol1,142,68,0	duplicate(#edda_trap_silence_0)	#edda_trap_silence_2	4_SYSTEM_BOX
1@gol1,146,18,0	duplicate(#edda_trap_silence_0)	#edda_trap_silence_3	4_SYSTEM_BOX
1@gol1,128,36,0	duplicate(dummynpc2)	#edda_combat_wall_0-0	4_NFWISP
1@gol1,130,36,0	duplicate(dummynpc2)	#edda_combat_wall_0-1	4_NFWISP
1@gol1,132,36,0	duplicate(dummynpc2)	#edda_combat_wall_0-2	4_NFWISP
1@gol1,89,54,0	duplicate(dummynpc2)	#edda_combat_wall_1-0	4_NFWISP
1@gol1,91,54,0	duplicate(dummynpc2)	#edda_combat_wall_1-1	4_NFWISP
1@gol1,93,54,0	duplicate(dummynpc2)	#edda_combat_wall_1-2	4_NFWISP
1@gol1,95,54,0	duplicate(dummynpc2)	#edda_combat_wall_1-3	4_NFWISP
1@gol1,97,54,0	duplicate(dummynpc2)	#edda_combat_wall_1-4	4_NFWISP
1@gol1,99,54,0	duplicate(dummynpc2)	#edda_combat_wall_1-5	4_NFWISP
1@gol1,100,75,0	duplicate(dummynpc2)	#edda_combat_wall_1-6	4_NFWISP
1@gol1,100,73,0	duplicate(dummynpc2)	#edda_combat_wall_1-7	4_NFWISP
1@gol1,85,31,0	duplicate(dummynpc2)	#edda_combat_wall_2-0	4_NFWISP
1@gol1,87,31,0	duplicate(dummynpc2)	#edda_combat_wall_2-1	4_NFWISP
1@gol1,89,31,0	duplicate(dummynpc2)	#edda_combat_wall_2-2	4_NFWISP
1@gol1,91,31,0	duplicate(dummynpc2)	#edda_combat_wall_2-3	4_NFWISP
1@gol1,93,31,0	duplicate(dummynpc2)	#edda_combat_wall_2-4	4_NFWISP
1@gol1,137,54,0	duplicate(dummynpc2)	#edda_combat_wall_3-0	4_NFWISP
1@gol1,139,54,0	duplicate(dummynpc2)	#edda_combat_wall_3-1	4_NFWISP
1@gol1,141,54,0	duplicate(dummynpc2)	#edda_combat_wall_3-2	4_NFWISP
1@gol1,143,54,0	duplicate(dummynpc2)	#edda_combat_wall_3-3	4_NFWISP
1@gol1,145,54,0	duplicate(dummynpc2)	#edda_combat_wall_3-4	4_NFWISP
1@gol1,147,54,0	duplicate(dummynpc2)	#edda_combat_wall_3-5	4_NFWISP
1@gol1,135,74,0	duplicate(dummynpc2)	#edda_combat_wall_3-6	4_NFWISP
1@gol1,135,72,0	duplicate(dummynpc2)	#edda_combat_wall_3-7	4_NFWISP
1@gol1,141,31,0	duplicate(dummynpc2)	#edda_combat_wall_4-0	4_NFWISP
1@gol1,143,31,0	duplicate(dummynpc2)	#edda_combat_wall_4-1	4_NFWISP
1@gol1,145,31,0	duplicate(dummynpc2)	#edda_combat_wall_4-2	4_NFWISP
1@gol1,147,31,0	duplicate(dummynpc2)	#edda_combat_wall_4-3	4_NFWISP
1@gol1,149,31,0	duplicate(dummynpc2)	#edda_combat_wall_4-4	4_NFWISP

1@gol2,52,60,0	duplicate(dummynpc2)	#edda_c_wall_0-0	4_NFWISP
1@gol2,52,58,0	duplicate(dummynpc2)	#edda_c_wall_0-1	4_NFWISP
1@gol2,52,56,0	duplicate(dummynpc2)	#edda_c_wall_0-2	4_NFWISP
1@gol2,52,54,0	duplicate(dummynpc2)	#edda_c_wall_0-3	4_NFWISP
1@gol2,53,53,0	duplicate(dummynpc2)	#edda_c_wall_0-4	4_NFWISP
1@gol2,55,53,0	duplicate(dummynpc2)	#edda_c_wall_0-5	4_NFWISP
1@gol2,57,53,0	duplicate(dummynpc2)	#edda_c_wall_0-6	4_NFWISP
1@gol2,59,53,0	duplicate(dummynpc2)	#edda_c_wall_0-7	4_NFWISP
1@gol2,59,55,0	duplicate(dummynpc2)	#edda_c_wall_0-8	4_NFWISP
1@gol2,59,57,0	duplicate(dummynpc2)	#edda_c_wall_0-9	4_NFWISP
1@gol2,59,59,0	duplicate(dummynpc2)	#edda_c_wall_0-10	4_NFWISP
1@gol2,58,60,0	duplicate(dummynpc2)	#edda_c_wall_0-11	4_NFWISP
1@gol2,56,60,0	duplicate(dummynpc2)	#edda_c_wall_0-12	4_NFWISP
1@gol2,54,60,0	duplicate(dummynpc2)	#edda_c_wall_0-13	4_NFWISP
1@gol2,52,64,0	duplicate(dummynpc2)	#edda_c_wall_1-0	4_NFWISP
1@gol2,52,66,0	duplicate(dummynpc2)	#edda_c_wall_1-1	4_NFWISP
1@gol2,52,68,0	duplicate(dummynpc2)	#edda_c_wall_1-2	4_NFWISP
1@gol2,52,70,0	duplicate(dummynpc2)	#edda_c_wall_1-3	4_NFWISP
1@gol2,53,71,0	duplicate(dummynpc2)	#edda_c_wall_1-4	4_NFWISP
1@gol2,55,71,0	duplicate(dummynpc2)	#edda_c_wall_1-5	4_NFWISP
1@gol2,57,71,0	duplicate(dummynpc2)	#edda_c_wall_1-6	4_NFWISP
1@gol2,59,71,0	duplicate(dummynpc2)	#edda_c_wall_1-7	4_NFWISP
1@gol2,59,69,0	duplicate(dummynpc2)	#edda_c_wall_1-8	4_NFWISP
1@gol2,59,67,0	duplicate(dummynpc2)	#edda_c_wall_1-9	4_NFWISP
1@gol2,59,65,0	duplicate(dummynpc2)	#edda_c_wall_1-10	4_NFWISP
1@gol2,58,64,0	duplicate(dummynpc2)	#edda_c_wall_1-11	4_NFWISP
1@gol2,56,64,0	duplicate(dummynpc2)	#edda_c_wall_1-12	4_NFWISP
1@gol2,54,64,0	duplicate(dummynpc2)	#edda_c_wall_1-13	4_NFWISP
1@gol2,48,60,0	duplicate(dummynpc2)	#edda_c_wall_2-0	4_NFWISP
1@gol2,48,58,0	duplicate(dummynpc2)	#edda_c_wall_2-1	4_NFWISP
1@gol2,48,56,0	duplicate(dummynpc2)	#edda_c_wall_2-2	4_NFWISP
1@gol2,48,54,0	duplicate(dummynpc2)	#edda_c_wall_2-3	4_NFWISP
1@gol2,47,53,0	duplicate(dummynpc2)	#edda_c_wall_2-4	4_NFWISP
1@gol2,45,53,0	duplicate(dummynpc2)	#edda_c_wall_2-5	4_NFWISP
1@gol2,43,53,0	duplicate(dummynpc2)	#edda_c_wall_2-6	4_NFWISP
1@gol2,41,53,0	duplicate(dummynpc2)	#edda_c_wall_2-7	4_NFWISP
1@gol2,41,55,0	duplicate(dummynpc2)	#edda_c_wall_2-8	4_NFWISP
1@gol2,41,57,0	duplicate(dummynpc2)	#edda_c_wall_2-9	4_NFWISP
1@gol2,41,59,0	duplicate(dummynpc2)	#edda_c_wall_2-10	4_NFWISP
1@gol2,42,60,0	duplicate(dummynpc2)	#edda_c_wall_2-11	4_NFWISP
1@gol2,44,60,0	duplicate(dummynpc2)	#edda_c_wall_2-12	4_NFWISP
1@gol2,46,60,0	duplicate(dummynpc2)	#edda_c_wall_2-13	4_NFWISP
1@gol2,48,64,0	duplicate(dummynpc2)	#edda_c_wall_3-0	4_NFWISP
1@gol2,48,66,0	duplicate(dummynpc2)	#edda_c_wall_3-1	4_NFWISP
1@gol2,48,68,0	duplicate(dummynpc2)	#edda_c_wall_3-2	4_NFWISP
1@gol2,48,70,0	duplicate(dummynpc2)	#edda_c_wall_3-3	4_NFWISP
1@gol2,47,71,0	duplicate(dummynpc2)	#edda_c_wall_3-4	4_NFWISP
1@gol2,45,71,0	duplicate(dummynpc2)	#edda_c_wall_3-5	4_NFWISP
1@gol2,43,71,0	duplicate(dummynpc2)	#edda_c_wall_3-6	4_NFWISP
1@gol2,41,71,0	duplicate(dummynpc2)	#edda_c_wall_3-7	4_NFWISP
1@gol2,41,69,0	duplicate(dummynpc2)	#edda_c_wall_3-8	4_NFWISP
1@gol2,41,67,0	duplicate(dummynpc2)	#edda_c_wall_3-9	4_NFWISP
1@gol2,41,65,0	duplicate(dummynpc2)	#edda_c_wall_3-10	4_NFWISP
1@gol2,42,64,0	duplicate(dummynpc2)	#edda_c_wall_3-11	4_NFWISP
1@gol2,44,64,0	duplicate(dummynpc2)	#edda_c_wall_3-12	4_NFWISP
1@gol2,46,64,0	duplicate(dummynpc2)	#edda_c_wall_3-13	4_NFWISP
1@gol2,50,44,0	duplicate(dummynpc2)	#edda_c_wall_4-0	4_NFWISP
1@gol2,52,44,0	duplicate(dummynpc2)	#edda_c_wall_4-1	4_NFWISP

1@gol1	mapflag	nowarp
1@gol1	mapflag	nomemo
1@gol1	mapflag	noteleport
1@gol1	mapflag	monster_noteleport
1@gol1	mapflag	nosave
1@gol1	mapflag	nobranch
1@gol1	mapflag	nowarpto
1@gol1	mapflag	noicewall
1@gol1	mapflag	restricted	9

1@gol2	mapflag	nowarp
1@gol2	mapflag	nomemo
1@gol2	mapflag	noteleport
1@gol2	mapflag	monster_noteleport
1@gol2	mapflag	nosave
1@gol2	mapflag	nobranch
1@gol2	mapflag	nowarpto
1@gol2	mapflag	noicewall
1@gol2	mapflag	restricted	9