REM bank3
@echo off

cd ..
cd banks
cd bank3

bmp2tile.exe raw\guardA\Idle.png -savetiles "guardA_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 128 -savetilemap "guardA_idle (tilemap).bin" -exit
bmp2tile.exe raw\guardB\Idle.png -savetiles "guardB_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 136 -savetilemap "guardB_idle (tilemap).bin" -exit
bmp2tile.exe raw\guardC\Idle.png -savetiles "guardC_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 144 -savetilemap "guardC_idle (tilemap).bin" -exit
bmp2tile.exe raw\guardD\Idle.png -savetiles "guardD_idle (tiles).psgcompr" -noremovedupes -planar -tileoffset 152 -savetilemap "guardD_idle (tilemap).bin" -exit

bmp2tile.exe raw\splash.bmp -savetiles "splash (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "splash (tilemap).stmcompr" -exit
bmp2tile.exe raw\title6.png -savetiles "title6 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "title6 (tilemap).stmcompr" -exit
bmp2tile.exe raw\title6.png -savetiles "title8 (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 128 -savetilemap "title8 (tilemap).stmcompr" -exit

cd ..
folder2c bank3 bank3 3

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
cd scripts