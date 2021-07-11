@echo|set /p = Compiling......
@echo off

gcc main.c ^
src\file_handler.c src\inventory_manager.c ^
-o main

@echo on
@echo|set /p = complete!
@echo.
@echo Program can be run by executing "main.exe".
