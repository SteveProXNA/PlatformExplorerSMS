REM bank2	Generic sprite tiles
@echo off

cd ..
cd banks
cd bank2

REM player
bmp2tile.exe raw\player\Idle.png -savetiles "player_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "sprites (palette).bin" -fullpalette  -spritepalette -exit
bmp2tile.exe raw\player\Run_Left_01.png -savetiles "player_run_left_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_02.png -savetiles "player_run_left_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_03.png -savetiles "player_run_left_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_04.png -savetiles "player_run_left_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Left_05.png -savetiles "player_run_left_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_01.png -savetiles "player_run_rght_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_02.png -savetiles "player_run_rght_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_03.png -savetiles "player_run_rght_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_04.png -savetiles "player_run_rght_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\player\Run_Rght_05.png -savetiles "player_run_rght_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

REM enemyX
bmp2tile.exe raw\enemyA\Idle.png -savetiles "enemyA_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\enemyB\Idle.png -savetiles "enemyB_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\enemyC\Idle.png -savetiles "enemyC_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\enemyD\Idle.png -savetiles "enemyD_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

cd ..
folder2c bank2 bank2 2

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
cd scripts