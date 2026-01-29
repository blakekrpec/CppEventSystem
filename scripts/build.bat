
@echo off
setlocal

REM Check if --clean is passed
if "%1"=="--clean" (
    if exist build (
        echo Cleaning build directory...
        rmdir /s /q build
    )
)

REM Create build directory if it doesn't exist
if not exist build (
    echo Creating build directory...
    mkdir build
)

cd build

REM Run CMake
cmake -G "Ninja" ..

REM Wait until compile_commands.json exists and is not empty
:wait_loop
if not exist compile_commands.json (
    echo Waiting for compile_commands.json to be created...
    timeout /t 1 >nul
    goto wait_loop
)

for %%A in (compile_commands.json) do (
    if %%~zA==0 (
        echo Waiting for compile_commands.json to be populated...
        timeout /t 1 >nul
        goto wait_loop
    )
)

REM Delete old compile_commands.json in root if exists
if exist ..\compile_commands.json (
    del ..\compile_commands.json
)

REM Copy instead of symlink (Windows symlink requires admin or special privileges)
copy compile_commands.json ..\compile_commands.json >nul

REM Build
cmake --build .

endlocal
