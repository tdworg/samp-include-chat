/** ======================================================================== **\
| Name:
	Message shorter

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


#if defined _inc_msg_shorter
	#undef _inc_msg_shorter
#endif
#if defined _TDW_CHLIB__SHORTER
	#endinput
#endif
#define _TDW_CHLIB__SHORTER


// Checks if a string is packed.
// https://github.com/TDW-org/samp-include-string
// Other information: //www.compuphase.com/pawn/String_Manipulation.pdf
// Author: Untonyst.
#if !defined IsPackedString
	#define IsPackedString(%0) ((%0){0} != 0)
#endif

#if !defined TDW_MAX_LENGTH_PER_LINE
	#define TDW_MAX_LENGTH_PER_LINE (MAX_CHATBUBBLE_LENGTH / 2)
#endif


stock
	TDWMSRH@SendClientMessage(playerid, color, message[])
{
	new length = strlen(message),
		shift_counts = length / TDW_MAX_LENGTH_PER_LINE,
		i, spos, epos, tmp;
	if (IsPackedString(message))
	{
		while (i != shift_counts)
		{
			epos = GetLastSpace(message, spos, TDW_MAX_LENGTH_PER_LINE);
			tmp = message{epos};
			message{epos} = '\0';
			SendClientMessage(playerid, color, message);
			message{epos} = tmp;
			strmid(message, message, epos + 1, length, length);
			i++;
		}
	}
	else
	{
		while (i != shift_counts)
		{
			epos = GetLastSpace(message, spos, TDW_MAX_LENGTH_PER_LINE);
			tmp = message[epos];
			message[epos] = '\0';
			SendClientMessage(playerid, color, message);
			message[epos] = tmp;
			strmid(message, message, epos + 1, length, length);
			i++;
		}
	}
	if ((length % TDW_MAX_LENGTH_PER_LINE) != 0)
	{
		SendClientMessage(playerid, color, message);
	}
	return 1;
}

#if defined _ALS_SendClientMessage
	#undef SendClientMessage
#else
	#define _ALS_SendClientMessage
#endif

#define SendClientMessage TDWMSRH@SendClientMessage


stock
	TDWMSRH@SendClientMessageToAll(color, message[])
{
	new length = strlen(message),
		shift_counts = length / TDW_MAX_LENGTH_PER_LINE,
		i, spos, epos, tmp;
	if (IsPackedString(message))
	{
		while (i != shift_counts)
		{
			epos = GetLastSpace(message, spos, TDW_MAX_LENGTH_PER_LINE);
			tmp = message{epos};
			message{epos} = '\0';
			SendClientMessageToAll(color, message);
			message{epos} = tmp;
			strmid(message, message, epos + 1, length, length);
			i++;
		}
	}
	else
	{
		while (i != shift_counts)
		{
			epos = GetLastSpace(message, spos, TDW_MAX_LENGTH_PER_LINE);
			tmp = message[epos];
			message[epos] = '\0';
			SendClientMessageToAll(color, message);
			message[epos] = tmp;
			strmid(message, message, epos + 1, length, length);
			i++;
		}
	}
	if ((length % TDW_MAX_LENGTH_PER_LINE) != 0)
	{
		SendClientMessageToAll(color, message);
	}
	return 1;
}

#if defined _ALS_SendClientMessageToAll
	#undef SendClientMessageToAll
#else
	#define _ALS_SendClientMessageToAll
#endif

#define SendClientMessageToAll TDWMSRH@SendClientMessageToAll


stock
	TDWMSRH@SendPlayerMsgToPlayer(playerid, senderid, message[])
{
	new length = strlen(message),
		shift_counts = length / TDW_MAX_LENGTH_PER_LINE,
		i, spos, epos, tmp;
	if (IsPackedString(message))
	{
		while (i != shift_counts)
		{
			epos = GetLastSpace(message, spos, TDW_MAX_LENGTH_PER_LINE);
			tmp = message{epos};
			message{epos} = '\0';
			SendPlayerMessageToPlayer(playerid, senderid, message);
			message{epos} = tmp;
			strmid(message, message, epos + 1, length, length);
			i++;
		}
	}
	else
	{
		while (i != shift_counts)
		{
			epos = GetLastSpace(message, spos, TDW_MAX_LENGTH_PER_LINE);
			tmp = message[epos];
			message[epos] = '\0';
			SendPlayerMessageToPlayer(playerid, senderid, message);
			message[epos] = tmp;
			strmid(message, message, epos + 1, length, length);
			i++;
		}
	}
	if ((length % TDW_MAX_LENGTH_PER_LINE) != 0)
	{
		SendPlayerMessageToPlayer(playerid, senderid, message);
	}
	return 1;
}

#if defined _ALS_SendPlayerMessageToPlayer
	#undef SendPlayerMessageToPlayer
#else
	#define _ALS_SendPlayerMessageToPlayer
#endif

#define SendPlayerMessageToPlayer TDWMSRH@SendPlayerMsgToPlayer


stock
	TDWMSRH@SendPlayerMessageToAll(senderid, message[])
{
	new length = strlen(message),
		shift_counts = length / TDW_MAX_LENGTH_PER_LINE,
		i, spos, epos, tmp;
	if (IsPackedString(message))
	{
		while (i != shift_counts)
		{
			epos = GetLastSpace(message, spos, TDW_MAX_LENGTH_PER_LINE);
			tmp = message{epos};
			message{epos} = '\0';
			SendPlayerMessageToAll(senderid, message);
			message{epos} = tmp;
			strmid(message, message, epos + 1, length, length);
			i++;
		}
	}
	else
	{
		while (i != shift_counts)
		{
			epos = GetLastSpace(message, spos, TDW_MAX_LENGTH_PER_LINE);
			tmp = message[epos];
			message[epos] = '\0';
			SendPlayerMessageToAll(senderid, message);
			message[epos] = tmp;
			strmid(message, message, epos + 1, length, length);
			i++;
		}
	}
	if ((length % TDW_MAX_LENGTH_PER_LINE) != 0)
	{
		SendPlayerMessageToAll(senderid, message);
	}
	return 1;
}

#if defined _ALS_SendPlayerMessageToAll
	#undef SendPlayerMessageToAll
#else
	#define _ALS_SendPlayerMessageToAll
#endif

#define SendPlayerMessageToAll TDWMSRH@SendPlayerMessageToAll


static stock
	GetLastSpace(const message[], start_pos, limit)
{
	new size = strlen(message);
	assert (0 <= start_pos < size);
	new last_pos;
	if (IsPackedString(message))
	{
		do
		{
			if (message{start_pos} == ' ')
				last_pos = start_pos;
		}
		while (++start_pos < limit);
	}
	else
	{
		do
		{
			if (message[start_pos] == ' ')
				last_pos = start_pos;
		}
		while (++start_pos < limit);
	}
	return last_pos;
}


stock
	SendClientMessageEx(playerid, color, message[])
{
	new pos, tmp, length = strlen(message);
	if (IsPackedString(message))
	{
		while ((pos = strfind(message, !"\n", false, pos++)) != -1)
		{
			tmp = message{pos};
			message{pos} = '\0';
			SendClientMessage(playerid, color, message);
			message{pos} = tmp;
			strmid(message, message, pos + 1, length, length);
		}
	}
	else
	{
		while ((pos = strfind(message, !"\n", false, pos++)) != -1)
		{
			tmp = message[pos];
			message[pos] = '\0';
			SendClientMessage(playerid, color, message);
			message[pos] = tmp;
			strmid(message, message, pos + 1, length, length);
		}
	}
	SendClientMessage(playerid, color, message);
	return 1;
}
