//===== rAthena Script ===========================================|
//= Verus Merchants [ Charleston Extension ]                     =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//= 1.1 Script Clean-up                                          =|
//================================================================|
//= Verus Merchants / Verus Enchants                             =|
//================================================================|
verus04,63,112,3	script	Mass Charleston#exchanger	4_F_CHARLESTON01,{
	if (checkweight(1201,1) == 0) {
		mes "Inventory full, speak to me again when you have enough space.";
		close;
	}
	if (MaxWeight - Weight < 5000) {
		mes "You are overweight please ensure that you have enough space.";
		close;
	}	
	disable_items;
	cutin "dalle03.bmp",2;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "Eh, do I have a customer?";
	mes "Activating Salesman mode....";
	next;
	cutin "dalle01.bmp",2;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "Charleston Factory's best-selling items : <ITEM>"+getitemname(15111)+"<INFO>"+15111+"</INFO></ITEM> and <ITEM>"+getitemname(15110)+"<INFO>"+15110+"</INFO></ITEM> now on sale!";
	next;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "For only 3,999,999 Zeny! Get yourself some ultra-preformance action gears!";
	next;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "Also available is the ^FF0000Pile Bunker Upgrade^000000 service!";
	next;
	switch(select("Talk.:Buy Reinforced Parts - Plate.:Buy STR Supplement Equipment.:Upgrade Pilebunker.")){
		case 1:
			mes "[ ^0000FFMass Charleston^000000 ]";
			mes "The Charleston Factory shut down, but its technology and product remains with us.";
			next;
			mes "[ ^0000FFMass Charleston^000000 ]";
			mes "Oh, haven't you heard the news? Oops, my bad. Please forget I said that.";
			close3;
			
		case 2:
			.@item = 15111;
			break;
			
		case 3:
			.@item = 15110;
			break;
			
		case 4:
			mes "[ ^0000FFMass Charleston^000000 ]";
			mes "The last masterpiece of the Charleston Factory! You'll never find such equipment anywhere else!";
			next;
			mes "[ ^0000FFMass Charleston^000000 ]";
			mes "To upgrade a Pile Bunker:";
			mes "^FF00001 Pile Bunker^0000FF,^FF0000300 Dented Iron Plates^000000, and ^FF000015 Broken Engines^000000 are required.";
			next;
			for(.@i = 0; .@i < getarraysize(.bunker_data$); .@i += 2){
				.@menu$ += .bunker_data$[.@i] + ":";
			}
			.@s = ( select(.@menu$) - 1 * 2);
			mes "[ ^0000FFMass Charleston^000000 ]";
			mes "Do you really want to buy?";
			mes "<ITEM>" +.bunker_data$[.@s]+ "<INFO>"+atoi(.bunker_data$[.@s+1])+"</INFO></ITEM>";
			next;
			if(select("I suggest you reconsider.:Buy it.") == 1){
				mes "[ ^0000FFMass Charleston^000000 ]";
				mes "It's a good buy, but you still need to make your decision carefully.";
				close3;
			}
			mes "[ ^0000FFMass Charleston^000000 ]";
			for(.@i = 0; .@i < getarraysize(.bunker_requirement); .@i += 2){
				if(countitem(.bunker_requirement[.@i]) >= .bunker_requirement[.@i+1]){
					mes "^0000FF" + getitemname(.bunker_requirement[.@i]) + "^000000" + " - " + "[" + "^00FF00"+countitem(.bunker_requirement[.@i])+"^000000" + "/" + "^00FF00"+.bunker_requirement[.@i+1]+"^000000" + "]";
				} else {
					mes "^0000FF" + getitemname(.bunker_requirement[.@i]) + "^000000" + " - " + "[" + "^FF0000"+countitem(.bunker_requirement[.@i])+"^000000" + "/" + "^FF0000"+.bunker_requirement[.@i+1]+"^000000" + "]";
					.@miss++
				}
			}
			next;
			if(.@miss > 0){
				mes "[ ^0000FFMass Charleston^000000 ]";
				mes "Not enough materials for the Upgrade.";
				close3;
			}
			for ( .@i = 0; .@i < getarraysize(.bunker_requirement); .@i++ ){
				delitem .bunker_requirement[.@i],.bunker_requirement[.@i+1];
			}
			progressbar "ffff00",5;
			specialeffect2 EF_REPAIRWEAPON;
			mes "[ ^0000FFMass Charleston^000000 ]";
			mes "Thank you for you transaction.";
			getitem atoi(.bunker_data$[.@s]),1;
			close3;		
	}
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "<ITEM>" +getitemname(.@item)+ "<INFO>"+.@item+"</INFO></ITEM>";
	mes "Price : ^0000FF3,999,999 Zeny.^000000";
	next;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "Do you really want to buy ";
	mes "<ITEM>" +getitemname(.@item)+ "<INFO>"+.@item+"</INFO></ITEM>";
	next;
	if(select("I suggest you reconsider.:Buy it.") == 1){
		mes "[ ^0000FFMass Charleston^000000 ]";
		mes "It's a good buy, but you still need to make your decision carefully.";
		close3;
	}
	if (Zeny < .item_price){
		mes "[ ^0000FFMass Charleston^000000 ]";
		mes "You do not have enough zenies to buy this factory item";
		close3;
	}
	Zeny -= .item_price;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "Thank you for you transaction.";
	getitem .@item,1;
	close3;
			
OnInit:
	.item_price = 3999999;
	setarray .bunker_data$,
	"Pile Bunker S",16030,
	"Pile Bunker P",16031,
	"Pile Bunker T",16032;
	setarray .bunker_requirement,1549,1,6751,300,6750,15;
	end;
}

verus04,69,108,5	script	Mass Charleston#exchanger_2	4_F_CHARLESTON01,{
	if (checkweight(1201,1) == 0) {
		mes "Inventory full, speak to me again when you have enough space.";
		close;
	}
	if (MaxWeight - Weight < 5000) {
		mes "You are overweight please ensure that you have enough space.";
		close;
	}
	disable_items;
	cutin "dalle03.bmp",2;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "I can exchange ^0000FF"+.price+"^000000 of your <ITEM>"+getitemname(.component_id)+"<INFO>"+.component_id+"</INFO></ITEM> for factory products.";
	if(countitem(.component_id) < 10){
		close3;
	}
	next;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "Which product do you wish to exchange for?";
	next;
	for(.@i = 0; .@i < getarraysize(.item_list); .@i++){
		.@menu$ += getitemname(.item_list[.@i]) + ":";
	}
	.@s = select(.@menu$) - 1;
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "Are you certain you want to exchange ^0000FF10 Charleston Components^000000 for one";
	mes "<ITEM>"+getitemname(.item_list[.@s])+"<INFO>"+.item_list[.@s]+"</INFO></ITEM>?";
	next;
	if(select("No:Yes") == 1){
		close3;
	}
	if(countitem(.component_id) < 10){
		mes "[ ^0000FFMass Charleston^000000 ]";
		mes "You don't have enough Charleston Components.";
		end;
	}
	mes "[ ^0000FFMass Charleston^000000 ]";
	mes "Thank you and enjoy your purchase.";
	delitem .component_id,.price;
	getitem .item_list[.@s],1;
	close3;
	
OnInit:
	.component_id = 6752;
	.price = 10;
	setarray .item_list,20733,22044,2996,20732,22043,2995;
	end;
}
