/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

void Unattended_Set_Headless(void);
bool Unattended_Is_Headless(void);
bool Unattended_Set_CRC_Log(char const * path);
void Unattended_Set_Exit_Frame(int frame);
void Unattended_Tick_Done(void);
