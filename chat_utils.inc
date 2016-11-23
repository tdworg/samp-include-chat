/** ======================================================================== **\
| Name:
	Chat Utils

| Verison:
1.0.0

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


#if defined _inc_chat_utils
	#undef _inc_chat_utils
#endif

#if defined _TDW_CHLIB__CHAT_UTILS
	#endinput
#endif

#define _TDW_CHLIB__CHAT_UTILS


#if !defined TDW_DEFAULT_LINES_COUNT
	#define TDW_DEFAULT_LINES_COUNT (100)
#endif


stock
	ClearChat(playerid = cellmin, line = TDW_DEFAULT_LINES_COUNT)
{
	static const
		__space[] = !"";

	if (_:(0 < line <= 100) == 0)
		return 0;

	#if __Pawn < 0x030A
		if (line == 0)
		{
			SendClientMessageToAll(0, __space);
			SendClientMessage(INVALID_PLAYER_ID, 0, __space);
		}
		{}
	#endif

	if (playerid == cellmin)
	{
		#emit push.c __space
		#emit push.c 0xffffffff
		#emit push.c 8

		do
		{
			#emit sysreq.c SendClientMessageToAll
		}
		while (--line != 0);

		#emit stack 12
		#emit retn
	}
	else
	{
		#emit push.c __space
		#emit push.c 0xffffffff
		#emit push.s playerid
		#emit push.c 12

		do
		{
			#emit sysreq.c SendClientMessage
		}
		while (--line != 0);

		#emit stack 16
		#emit retn
	}
	return 0; // Make compile happy.
}
