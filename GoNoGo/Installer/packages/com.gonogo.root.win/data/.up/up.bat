@echo off

SET ROOT=%~dp0

CALL :RESOLVE "%ROOT%\.." PARENT_ROOT

start "" "%PARENT_ROOT%\updater.exe" "--updater"

GOTO :EOF

:RESOLVE
SET %2=%~f1 
GOTO :EOF
