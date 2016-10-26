/** ======================================================================== **\
| Name:
	Message shorter

| Verison:
2.0.0

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
	#define IsPackedString%0(%1) ((%1){0} != 0)
#endif

#if !defined TDW_MAX_LENGTH_PER_LINE
	#define TDW_MAX_LENGTH_PER_LINE (MAX_CHATBUBBLE_LENGTH/2)
#endif

#if !defined TDW_MSG_SHORTER_SEPARATOR
	#define TDW_MSG_SHORTER_SEPARATOR (' ')
#endif


stock
	TDWMSRH@SendClientMessage(playerid, color, message[])
{
	new length = strlen(message);
	if (length <= TDW_MAX_LENGTH_PER_LINE)
		return SendClientMessage(playerid, color, message);
	new start_pos, end_pos, tmp, bool:is_packed = IsPackedString(message), ret;
	goto _no_init;
	new buffer[MAX_CHATBUBBLE_LENGTH char];
	_no_init:
	while (end_pos <= length)
	{
		start_pos = GetStartPos(message, end_pos, is_packed, length),
		end_pos = start_pos + MAX_CHATBUBBLE_LENGTH;
		if (is_packed)
		{
			if (end_pos >= length)
			{
				strmid(buffer, message, start_pos, length, sizeof buffer);
				return SendClientMessage(playerid, color, message);
			}
			end_pos = GetEndPos(message, end_pos, is_packed);
			// SendClientMessage gives a error when we use this:
			//    SendClientMessage(playerid, color, buffer{start_pos});
			// So i use strmid to get part of the message and send it.
			strmid(buffer, message, start_pos, end_pos, sizeof buffer);
			buffer{end_pos - start_pos} = '\0';
			ret = SendClientMessage(playerid, color, buffer);
		}
		else
		{
			if (end_pos >= length)
				return SendClientMessage(playerid, color, message[start_pos]);
			end_pos = GetEndPos(message, end_pos, is_packed);
			tmp = message[end_pos];
			message[end_pos] = '\0';
			ret = SendClientMessage(playerid, color, message[start_pos]);
			message[end_pos] = tmp;
		}
	}
	return ret;
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
	new length = strlen(message);
	if (length <= TDW_MAX_LENGTH_PER_LINE)
		return SendClientMessageToAll(color, message);
	new start_pos, end_pos, tmp, bool:is_packed = IsPackedString(message), ret;
	goto _no_init;
	new buffer[MAX_CHATBUBBLE_LENGTH char];
	_no_init:
	while (end_pos <= length)
	{
		start_pos = GetStartPos(message, end_pos, is_packed, length),
		end_pos = start_pos + MAX_CHATBUBBLE_LENGTH;
		if (is_packed)
		{
			if (end_pos >= length)
			{
				strmid(buffer, message, start_pos, length, sizeof buffer);
				return SendClientMessageToAll(color, message);
			}
			end_pos = GetEndPos(message, end_pos, is_packed);
			// SendClientMessageToAll gives a error when we use this:
			//    SendClientMessageToAll(color, buffer{start_pos});
			// So i use strmid to get part of the message and send it.
			strmid(buffer, message, start_pos, end_pos, sizeof buffer);
			buffer{end_pos - start_pos} = '\0';
			ret = SendClientMessageToAll(color, buffer);
		}
		else
		{
			if (end_pos >= length)
				return SendClientMessageToAll(color, message[start_pos]);
			end_pos = GetEndPos(message, end_pos, is_packed);
			tmp = message[end_pos];
			message[end_pos] = '\0';
			ret = SendClientMessageToAll(color, message[start_pos]);
			message[end_pos] = tmp;
		}
	}
	return ret;
}

#if defined _ALS_SendClientMessageToAll
	#undef SendClientMessageToAll
#else
	#define _ALS_SendClientMessageToAll
#endif

#define SendClientMessageToAll TDWMSRH@SendClientMessageToAll


stock
	TDWMSRH@SendPlayerMsg2Player(playerid, senderid, message[])
{
	new length = strlen(message);
	if (length <= TDW_MAX_LENGTH_PER_LINE)
		return SendPlayerMessageToPlayer(playerid, senderid, message);
	new start_pos, end_pos, tmp, bool:is_packed = IsPackedString(message), ret;
	goto _no_init;
	new buffer[MAX_CHATBUBBLE_LENGTH char];
	_no_init:
	while (end_pos <= length)
	{
		start_pos = GetStartPos(message, end_pos, is_packed, length),
		end_pos = start_pos + MAX_CHATBUBBLE_LENGTH;
		if (is_packed)
		{
			if (end_pos >= length)
			{
				strmid(buffer, message, start_pos, length, sizeof buffer);
				return SendPlayerMessageToPlayer(playerid, senderid, message);
			}
			end_pos = GetEndPos(message, end_pos, is_packed);
			// SendPlayerMessageToPlayer gives a error when we use this:
			//    SendPlayerMessageToPlayer(playerid, senderid, message);
			// So i use strmid to get part of the message and send it.
			strmid(buffer, message, start_pos, end_pos, sizeof buffer);
			buffer{end_pos - start_pos} = '\0';
			ret = SendPlayerMessageToPlayer(playerid, senderid, message);
		}
		else
		{
			if (end_pos >= length)
				return SendPlayerMessageToPlayer(playerid, senderid,
					message[start_pos]
				);
			end_pos = GetEndPos(message, end_pos, is_packed);
			tmp = message[end_pos];
			message[end_pos] = '\0';
			ret = SendPlayerMessageToPlayer(playerid, senderid,
				message[start_pos]
			);
			message[end_pos] = tmp;
		}
	}
	return ret;
}

#if defined _ALS_SendClientMessageToAll
	#undef SendClientMessageToAll
#else
	#define _ALS_SendClientMessageToAll
#endif

#define SendClientMessageToAll TDWMSRH@SendClientMessageToAll


stock
	TDWMSRH@SendPlayerMessageToAll(senderid, message[])
{
	new length = strlen(message);
	if (length <= TDW_MAX_LENGTH_PER_LINE)
		return SendPlayerMessageToAll(senderid, message);
	new start_pos, end_pos, tmp, bool:is_packed = IsPackedString(message), ret;
	goto _no_init;
	new buffer[MAX_CHATBUBBLE_LENGTH char];
	_no_init:
	while (end_pos <= length)
	{
		start_pos = GetStartPos(message, end_pos, is_packed, length),
		end_pos = start_pos + MAX_CHATBUBBLE_LENGTH;
		if (is_packed)
		{
			if (end_pos >= length)
			{
				strmid(buffer, message, start_pos, length, sizeof buffer);
				return SendPlayerMessageToAll(senderid, message);
			}
			end_pos = GetEndPos(message, end_pos, is_packed);
			// SendPlayerMessageToAll gives a error when we use this:
			//    SendPlayerMessageToAll(senderid, message);
			// So i use strmid to get part of the message and send it.
			strmid(buffer, message, start_pos, end_pos, sizeof buffer);
			buffer{end_pos - start_pos} = '\0';
			ret = SendPlayerMessageToAll(senderid, message);
		}
		else
		{
			if (end_pos >= length)
				return SendPlayerMessageToAll(senderid, message[start_pos]);
			end_pos = GetEndPos(message, end_pos, is_packed);
			tmp = message[end_pos];
			message[end_pos] = '\0';
			ret = SendPlayerMessageToAll(senderid, message[start_pos]);
			message[end_pos] = tmp;
		}
	}
	return ret;
}

#if defined _ALS_SendPlayerMessageToAll
	#undef SendPlayerMessageToAll
#else
	#define _ALS_SendPlayerMessageToAll
#endif

#define SendPlayerMessageToAll TDWMSRH@SendPlayerMessageToAll



static stock
	GetStartPos(const message[], current_pos, bool:is_packed = false,
		size = sizeof message)
{
	if (is_packed)
	{
		while (current_pos++ < size)
		{
			// If the current character is not the delimiter, break the loop.
			if (message{current_pos} != TDW_MSG_SHORTER_SEPARATOR)
				break;
			current_pos++;
		}
	}
	else
	{
		while (current_pos < size)
		{
			// If the current character is not the delimiter, break the loop.
			if (message[current_pos] != TDW_MSG_SHORTER_SEPARATOR)
				break;
			current_pos++;
		}
	}
	// returns the position that was found.
	return current_pos;
}


static stock
	GetEndPos(const message[], current_pos, bool:is_packed = false)
{
	if (is_packed)
	{
		while (current_pos != 0)
		{
			// If the current character is the delimiter, break the loop.
			if (message{current_pos} == TDW_MSG_SHORTER_SEPARATOR)
				break;
			--current_pos;
		}
	}
	else
	{
		while (current_pos != 0)
		{
			// If the current character is the delimiter, break the loop.
			if (message[current_pos] == TDW_MSG_SHORTER_SEPARATOR)
				break;
			--current_pos;
		}
	}
	// returns the position that was found.
	return current_pos;
}
