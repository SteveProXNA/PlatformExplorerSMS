@echo off

REM https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
:: Calculate the start timestamp
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs


REM build.bat assumes the following scripts been re-run and REL files cached:
REM bank*.bat
REM gfx.bat
REM psg.bat

cd engine
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 asm_manager.c
cd ..

cd source
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _sms_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _snd_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 global_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 debug_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 hack_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 level_object.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 anim_object.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 audio_object.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 intro_object.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 tutorial_object.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 content_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 font_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 text_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 delay_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 reset_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 sprite_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 tile_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 memo_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 level_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 anim_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 input_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 player_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemy_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 score_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 stats_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 audio_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 game_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 state_manager.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 none_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 splash_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 intro_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 begin_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 title_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 entry_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 diff_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 pace_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 level_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 view_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 init_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 load_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 ready_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 play_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 reset_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 pass_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 gems_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 dead_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 cont_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 over_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 beat_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 test_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 func_screen.c
REM sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 screen_manager.c
cd ..

REM echo Build main
sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


:: Calculate the difference in cSeconds
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started

:: Populate variables for rendering (100+ needed for padding)
set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100

echo.
echo Time taken: %_sec:~-2%.%_cs:~-2% secs
echo.


::prints something like:
::Done at: 12:37:53,70 took: 0:02:03.55



REM echo Linking
sdcc -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 ^
-Wl-b_BANK2=0x8000 ^
-Wl-b_BANK3=0x8000 ^
-Wl-b_BANK4=0x8000 ^
-Wl-b_BANK5=0x8000 ^
-Wl-b_BANK6=0x8000 ^
-Wl-b_BANK7=0x8000 ^
-Wl-b_BANK8=0x8000 ^
-Wl-b_BANK9=0x8000 ^
-Wl-b_BANK10=0x8000 ^
-Wl-b_BANK11=0x8000 ^
-Wl-b_BANK12=0x8000 ^
-Wl-b_BANK13=0x8000 ^
-Wl-b_BANK14=0x8000 ^
-Wl-b_BANK15=0x8000 ^
..\crt0\crt0_sms.rel main.rel ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
banks\bank2.rel ^
banks\bank3.rel ^
banks\bank4.rel ^
banks\bank5.rel ^
banks\bank6.rel ^
banks\bank7.rel ^
banks\bank8.rel ^
banks\bank9.rel ^
banks\bank10.rel ^
banks\bank11.rel ^
banks\bank12.rel ^
banks\bank13.rel ^
banks\bank14.rel ^
banks\bank15.rel ^
engine\asm_manager.rel ^
source\_sms_manager.rel ^
source\_snd_manager.rel ^
source\global_manager.rel ^
source\debug_manager.rel ^
source\hack_manager.rel ^
source\level_object.rel ^
source\anim_object.rel ^
source\audio_object.rel ^
source\intro_object.rel ^
source\tutorial_object.rel ^
source\content_manager.rel ^
source\font_manager.rel ^
source\text_manager.rel ^
source\delay_manager.rel ^
source\reset_manager.rel ^
source\sprite_manager.rel ^
source\tile_manager.rel ^
source\memo_manager.rel ^
source\level_manager.rel ^
source\anim_manager.rel ^
source\input_manager.rel ^
source\player_manager.rel ^
source\enemy_manager.rel ^
source\score_manager.rel ^
source\state_manager.rel ^
source\stats_manager.rel ^
source\audio_manager.rel ^
source\game_manager.rel ^
source\none_screen.rel ^
source\splash_screen.rel ^
source\intro_screen.rel ^
source\begin_screen.rel ^
source\title_screen.rel ^
source\entry_screen.rel ^
source\diff_screen.rel ^
source\pace_screen.rel ^
source\level_screen.rel ^
source\init_screen.rel ^
source\ready_screen.rel ^
source\load_screen.rel ^
source\play_screen.rel ^
source\reset_screen.rel ^
source\pass_screen.rel ^
source\gems_screen.rel ^
source\dead_screen.rel ^
source\cont_screen.rel ^
source\over_screen.rel ^
source\beat_screen.rel ^
source\test_screen.rel ^
source\func_screen.rel ^
source\view_screen.rel ^
source\screen_manager.rel ^
gfx.rel ^
psg.rel

REM echo Binary output
ihx2sms output.ihx output.sms

REM copy output.sms
copy output.sms ..
copy output.sms ..\PlatformExplorer-3.0.sms
REM copy output.sms ..\asm
REM cd ..\asm
REM smsexamine.exe output.sms
REM cd ..\dev

REM https://www.askingbox.com/question/batch-script-delete-file-if-it-exists
cd engine
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..
cd source
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

if exist "*.asm" del "*.asm" > nul
if exist "*.ihx" del "*.ihx" > nul
if exist "*.lk"  del "*.lk"  > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.map" del "*.map" > nul
if exist "*.noi" del "*.noi" > nul
REM if exist "*.rel" del "*.rel" > nul
if exist "*.sym" del "*.sym" > nul


C:\SEGA\Fusion\fusion.exe output.sms
REM C:\SEGA\Meka\mekaw.exe output.sms
REM java -jar C:\SEGA\Emulicious\emulicious.jar output.sms