/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "always.h"

#include "unattended.h"

#include "globals.h"
#include "queue.h"

#include <cstdio>

static bool IsHeadless = false;
static std::FILE * CRCLog = nullptr;
static int ExitFrame = 0;


/// <summary>
/// Makes the game play its ticks back to back with nothing shown: the main window stays
/// hidden, and no frame is drawn, presented or waited for.
/// </summary>
void Unattended_Set_Headless(void)
{
	IsHeadless = true;
}


bool Unattended_Is_Headless(void)
{
	return(IsHeadless);
}


/// <summary>
/// Creates the file the game's checksum is written to after every tick, one line of frame
/// number and checksum each. Two runs of the same game can be compared line by line.
/// </summary>
/// <param name="path">The file to create, replacing any already there.</param>
/// <returns>bool; Was the file created?</returns>
bool Unattended_Set_CRC_Log(char const * path)
{
	if (CRCLog != nullptr) {
		std::fclose(CRCLog);
	}
	CRCLog = std::fopen(path, "w");
	return(CRCLog != nullptr);
}


/// <summary>
/// Makes the game end once the given number of ticks has been played. Zero plays on.
/// </summary>
void Unattended_Set_Exit_Frame(int frame)
{
	ExitFrame = frame;
}


/// <summary>
/// Logs the checksum and ends the game at the exit frame. Call after each tick that carried
/// on, once Main_Loop_End_Tick has run.
/// </summary>
void Unattended_Tick_Done(void)
{
	if (CRCLog != nullptr) {
		std::fprintf(CRCLog, "%d %08X\n", Frame, Calculate_Game_CRC());
	}

	if (ExitFrame > 0 && Frame >= ExitFrame) {
		if (CRCLog != nullptr) {
			std::fclose(CRCLog);
			CRCLog = nullptr;
		}
		GameActive = false;
	}
}
