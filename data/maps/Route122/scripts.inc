Route122_MapScripts::
	.byte 0

@ Nurse 
Route122_EventScript_Nurse::
	lock 
	faceplayer
	msgbox Route122_Text_Rest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route122_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route122_EventScript_DeclineRest
	end 

Route122_EventScript_Rest::
	msgbox Route122_Nurse_Text_Rest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	setvar VAR_POKEVIAL_CHARGES, 4
	msgbox Route122_Nurse_Text_Healed, MSGBOX_DEFAULT
	release 
	end 

Route122_EventScript_DeclineRest::
    msgbox Route122_Nurse_Text_DeclineRest, MSGBOX_DEFAULT
	release
	end

Route122_Text_Rest:
    .string "There's a lot of trainers in\n"
	.string "Mt. Pyre.\p"
	.string "Do you want me to heal your Pokémon?$"

Route122_Nurse_Text_Rest:
    .string "I'll take your Pokémon for a minute.$"

Route122_Nurse_Text_Healed:
    .string "There! Your Pokémon look happy and\n"
	.string "healthy!\p"
	.string "I've also restored your PokéVial\n"
	.string "charges for you!$"	

Route122_Nurse_Text_DeclineRest:
    .string "Come back to me if you want to heal\n"
	.string "your Pokémon.$"