
SET C_SOURCE_FILE=main.c
SET ARM_SOURCE_FILE=main.asm
SET LINKER_SCRIPT=../defines/dos_linker.ld

SET DEVKITARM=C:/devkitPro/devkitARM
SET ARMIPS=../armips/armips.exe
SET BUILD_DIR=../build

SET CC=%DEVKITARM%/bin/arm-none-eabi-gcc.exe
SET LD=%DEVKITARM%/bin/arm-none-eabi-ld.exe
SET CFLAGS=-marm -mno-thumb-interwork -march=armv5te -mtune=arm946e-s -fno-inline -Wall -O3
SET LDFLAGS=-T %LINKER_SCRIPT% --relocatable

mkdir "%BUILD_DIR%"

%CC% %CFLAGS% -c %C_SOURCE_FILE% -o %BUILD_DIR%/main.o
if %errorlevel% neq 0 exit /b %errorlevel%
%LD% %LDFLAGS% -o %BUILD_DIR%/linked.o %BUILD_DIR%/main.o
if %errorlevel% neq 0 exit /b %errorlevel%
"%ARMIPS%" %ARM_SOURCE_FILE%
