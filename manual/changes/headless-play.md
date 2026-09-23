---
title: Play unattended with a checksum log
category: feature
release: 0.2.0
targets:
- type: command
  id: launch:headless
  effect: added
- type: command
  id: launch:checksum-log
  effect: added
- type: command
  id: launch:exit-frame
  effect: added
credit:
- hammerstromlabs
---

Three launch options let a game run without a player and be compared with another run of the same game. `-HEADLESS` keeps the window hidden and plays each tick straight after the last, with nothing drawn, presented or waited for. `-CRCLOG=<file>` writes the game checksum after every tick, and `-EXITFRAME=<frame>` ends the game after that many ticks.

A computer-only match launched from `SPAWN.INI` with a fixed `Seed` and the local seat spectating needs no input. Run once windowed and once headless with the same checksum log settings, it produces two logs that match line for line when drawing and pacing have no effect on the simulation.
