/** ======================================================================== **\
| Name:
	Chat Groups

| Verison:
1.0.1

| License:
Copyright (c) 2016 Double V

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1.	The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgement in the product documentation would be
	appreciated but is not required.
2.	Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.
3.	This notice may not be removed or altered from any source distribution.
\** ======================================================================== **/


#if defined _inc_chat_groups
	#undef _inc_chat_groups
#endif

#if defined _TDW_CHLIB__CHAT_GROUPS
	#endinput
#endif

#define _TDW_CHLIB__CHAT_GROUPS


#include "tdw_chat/detect/foreach"


#if !defined _TDW_CHAT_FOREACH_DEFINED
	#error You can't use this library because the foreach library not found.
#endif

#if !defined MAX_CHATGROUPS
	#define MAX_CHATGROUPS (10)
#endif

#if !defined MAX_CHATGROUP_PLAYERS
	#define MAX_CHATGROUP_PLAYERS (256)
#endif

#if !defined TDW_INVALID_CHATGROUP_ID
	#define TDW_INVALID_CHATGROUP_ID (-1)
#endif


static stock
	IteratorArray:TDW_g_sCGroup@PList[MAX_CHATGROUPS]<MAX_CHATGROUP_PLAYERS>,
	TDW_g_sCGroup@Id;


stock
	CGroup:CreateChatGroup()
{
	if (TDW_g_sCGroup@Id > MAX_CHATGROUPS)
		return CGroup:-1;
	return CGroup:TDW_g_sCGroup@Id++;
}


stock
	RemoveChatGroup(CGroup:groupid)
{
	if (IsValidChatGroup(groupid) == 0)
		return 0;
	Iter_Clear(TDW_g_sCGroup@PList[groupid]);
	TDW_g_sCGroup@Id = groupid;
	return 1;
}


stock
	IsValidChatGroup(CGroup:groupid)
{
	if (_:(0 <= _:groupid < MAX_CHATGROUPS) == 0)
		return 0;
	return 1;
}


stock
	AddPlayerToChatGroup(CGroup:groupid, playerid)
{
	if (IsValidChatGroup(groupid) == 0)
		return 0;
	Iter_Add(TDW_g_sCGroup@PList[_:groupid], playerid);
	return 1;
}


stock
	RemovePlayerFromChatGroup(CGroup:groupid, &playerid)
{
	if (IsValidChatGroup(groupid) == 0)
		return 0;
	if (Iter_Contains(TDW_g_sCGroup@PList[groupid], playerid) == 0)
		return 0;
	Iter_SafeRemove(TDW_g_sCGroup@PList[groupid], playerid, playerid);
	return 1;
}


stock
	SendClientMessageToChatGroup(CGroup:groupid, color, const message[])
{
	if (IsValidChatGroup(groupid) == 0)
		return 0;
	foreach (new i : TDW_g_sCGroup@PList[_:groupid])
	{
		SendClientMessage(i, color, message);
	}
	return 1;
}


#if !defined FILTERSCRIPT
	public
		OnGameModeInit()
	{
		Iter_Init(TDW_g_sCGroup@PList);
		return 1;
	}

	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif

	#define OnGameModeInit TDWCH_CG@OnGameModeInit

	#if defined TDWCH_CG@OnGameModeInit
	forward TDWCH_CG@OnGameModeInit();
	#endif
#else
	public
		OnFilterScriptInit()
	{
		Iter_Init(TDW_g_sCGroup@PList);
		return 1;
	}

	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif

	#define OnFilterScriptInit TDWCH_CG@OnFilterScriptInit

	#if defined TDWCH_CG@OnFilterScriptInit
	forward TDWCH_CG@OnFilterScriptInit();
	#endif
#endif
