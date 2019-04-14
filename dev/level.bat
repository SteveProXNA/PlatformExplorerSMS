@echo off
REM echo Generate levels

REM cd ..
cd banks

folder2c bank4 bank4 4
folder2c bank5 bank5 5
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK4 bank4.c
sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK5 bank5.c
del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
REM cd scripts