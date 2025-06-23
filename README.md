# SDLPop 1.0.9 - main branch
![](Images/logo.png)

SDL2+SDL2_Image Port to W10M 15063 (Game "P.o.P." is not interested for me, it was used only for RnD) 

## About UWP SDLPoP
An open-source port of Prince of Persia to Xbox One and Series consoles via UWP, based on the disassembly of the DOS version, extended with new features.

## Screnshots
![W10 - PC](Images/shot1.png)
![W10M -Lumia 950](Images/shot4.png)

# Status
- Game runs but data\ files not properly added (injected) into SDLPoP.vcxproj \ SDLPoP.vcxproj.filters :(
- With help of "Trae" AI (hello, ByteDance!), mouse & touchpanel game input added :)

## TODO
- Try to construct cleve prompt that allows Trae or WindSurf automattically fix proj files (I mean "add data files" dev-op). 

## Plan of your own RnD / dev-ops 
1. Fork this repo

2. Run Visual Studio 2022

3. Try to run the game under Debugger. See error messge ".... PRINCE.DAT". 

4. Explore the solution: data\ folder (file structure), then SDLPoP.vcxproj & SDLPoP.vcxproj.filters.

5. Find missing/broken "links" such as 
```
<None Include="..\data\IBM_SND1\res10000.bin">
      <DeploymentContent>true</DeploymentContent>
    </None>

```

```
  <None Include="..\data\IBM_SND1\res10000.bin" />
```

6. Fix the filters and that links (https://learn.microsoft.com/en-us/cpp/build/reference/vcxproj-filters-files?view=msvc-170)

7. Try to start the Prince game again... ;)

## Useful links
Forum board: https://forum.princed.org/viewforum.php?f=126

GitHub: https://github.com/NagyD/SDLPoP

Compiled versions: https://www.popot.org/get_the_games.php?game=SDLPoP

## Authors
Author: David from forum.princed.org (NagyD on GitHub)

Contributors: (Usernames refer to forum.princed.org or GitHub.)

- Andrew (bug reports)
- htamas (inspiration, dungeon wall drawing algorithm, bug reports)
- Norbert (EndeavourAccuracy on GitHub) (bug reports, suggestions, improved gamepad support)
- musa (bug reports)
- Eugene (bug reports)
- StaticReturn (Mac OS X: Makefile (for older SDL1 version), bug reports)
- Poirot (ecalot on GitHub) (Mac OS X: Now compatible with Falcury SDL2 port)
- kees (bugfixes)
- Falcury (porting to SDL2; quicksave improvements; replay files; 
SDLPoP.ini: added basic support and constantly adding new options;
mod folders; fake tiles; readable sequence table; CMake support;
pause menu; MIDI support;
and various other bugfixes, improvements, additions)
- segra (segrax on GitHub) (Joystick support, resizable window)
- DarkPrince (bug reports)
- Andrey Vasilkin / digi@os2.snc.ru (eComStation (OS/2) support)
- mfn (fixed a small bug when USE_MIXER is undefined)
- diddledan (Visual C++ (NMake) support)
- zaps166 (small Makefile fixes)
- usineur (faster music loading)
- yaqxsw (icon)

## GENERAL INFO
What is this?

This is an open-source port/conversion of the DOS game Prince of Persia. It is based on the disassembly of the original PoP1 for DOS.

Note, however, that SDLPoP has many new features not found in the original game. 
These are marked as such in the command-line and the keys sections below.

More tech. details you can find here:
https://github.com/mediaexplorer74/SDLPoP/wiki


## ..

AS IS. SDLPoP is SDL RnD only, not for gaming. 

## .
-- [m][e] 2025

![](Images/footer.png)
