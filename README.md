<div align="center">
  
#  Left 4 Dead Toolz

### *Elevating Your SourceMod Experience*

[![License](https://img.shields.io/badge/License-LGPLv3-blue.svg)](LICENSE)
[![SourceMod](https://img.shields.io/badge/SourceMod-1.11+-orange.svg)](https://www.sourcemod.net/)
[![Game](https://img.shields.io/badge/Game-L4D2-brightgreen.svg)]()
[![Version](https://img.shields.io/badge/Version-1.0.0.0-red.svg)]()

---

## Overview

**Left 4 Dead Toolz** is a high-performance sourcemod extension designed to replace ["Left4DHooks"](https://forums.alliedmods.net/showthread.php?t=321696) due to its excessive bloat and cumbersome structure. It provides nearly all native and forward functions of Left4DHooks.As my first major project, I spent nearly a month completing it. Since I was still in high school at the time, there might be some places I didn't handle well or made mistakes, send issue please.

<div align="left">

## Installation

1. **Download** the all the files in this project;
2. Place file **left4deadtoolz.autoload** and **left4deadtoolz.ext.2.l4d2.so** into your `/addons/sourcemod/extensions/` directory;
3. Place file **left4deadtoolz.txt** into your `/addons/sourcemod/gamedata/` directory;
4. Place file **left4deadtoolz.inc** into your `/addons/sourcemod/scripting/include`, use natives or forwards from it and write your plugins.

---

## Commands & ConVars

### ConVars

| ConVars | Default | Description |
|---------|---------|-------------|
| `l4d2_addons_eclipse` | `-1` | Addons Manager (-1: use addonconfig; 0: disable addons; 1: enable addons.) |
| `convar_vscript_output` | ` ` | Buffer used to return VScript values. `Warning: Do not use.` |

---

## Natives & Forwards

|   APIs   |  Count  |
|----------|---------|
| Natives  |   383   |
| Forwards |   222   |


---

## Issues & Warning

1. *Some natives must `validate before using`(such as valid client/entity index), or it may cause crash;*
2. *You can request feature you need in issues, such as adding natives or forwards;*
3. *Some rare use natives in `Left 4 DHooks` are removed;*
4. *You can contact me through [My Steam](https://steamcommunity.com/profiles/76561198827998137/)*

---