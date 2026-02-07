@echo off
setlocal EnableExtensions

REM ==========================================
REM clean.bat : delete *.exe under current dir
REM usage:
REM   clean.bat
REM   clean.bat -h N   (N = 0,1,2,... ; depth limit)
REM ==========================================

set "MAXDEPTH=-1"

REM ---- ARG PARSE ----
if "%~1"=="" goto :RUN
if /I "%~1"=="-h" (
  if "%~2"=="" goto :USAGE
  set "MAXDEPTH=%~2"
  goto :RUN
)
if /I "%~1"=="--help" goto :USAGE
if /I "%~1"=="-?" goto :USAGE
goto :USAGE

:USAGE
echo Usage:
echo   %~nx0
echo   %~nx0 -h N
echo Examples:
echo   %~nx0 -h 3
echo   %~nx0 -h 0
exit /b 1

:RUN
REM ---- VALIDATE MAXDEPTH ----
for /f "delims=0123456789" %%A in ("%MAXDEPTH%") do (
  if not "%MAXDEPTH%"=="-1" (
    echo [ERROR] -h expects a non-negative integer. Got: "%MAXDEPTH%"
    exit /b 2
  )
)

echo [INFO] Root: "%CD%"
if "%MAXDEPTH%"=="-1" (echo [INFO] Depth: unlimited) else (echo [INFO] Depth: %MAXDEPTH%)
echo.

REM ---- Call PowerShell safely (handles spaces/parentheses) ----
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "& { " ^
  "  $root = (Get-Location).Path; " ^
  "  $max  = [int]%MAXDEPTH%; " ^
  "  $rootLen = $root.Length; " ^
  "  $del=0; $fail=0; $skip=0; " ^
  "  Get-ChildItem -LiteralPath $root -Filter '*.exe' -File -Recurse -ErrorAction SilentlyContinue | ForEach-Object { " ^
  "    $dir = $_.DirectoryName; " ^
  "    $rel = $dir.Substring($rootLen).TrimStart('\'); " ^
  "    if ([string]::IsNullOrEmpty($rel)) { $depth = 0 } else { $depth = ($rel -split '\\').Count } " ^
  "    if ($max -ge 0 -and $depth -gt $max) { $skip++; return } " ^
  "    try { Remove-Item -LiteralPath $_.FullName -Force -ErrorAction Stop; Write-Host ('[DEL ] \"{0}\"' -f $_.FullName); $del++ } " ^
  "    catch { Write-Host ('[FAIL] \"{0}\"  ({1})' -f $_.FullName, $_.Exception.Message); $fail++ } " ^
  "  }; " ^
  "  Write-Host ''; Write-Host ('[DONE] deleted={0} failed={1} skipped={2}' -f $del,$fail,$skip); " ^
  "  if ($fail -gt 0) { exit 3 } else { exit 0 } " ^
  "}"

exit /b %ERRORLEVEL%
