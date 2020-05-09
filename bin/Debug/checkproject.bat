@rem Program: checkproject
@rem Author: Markus Schordan, 2011
@rem Edit by Thomas Eizinger and Simon Dimitriadis, 2012
@rem Edit by Leonhardt Schwarz, 2014
@rem Edit by Karl Gmeiner, 2014

@echo off

set project=%1
set pfad=%~dpn1
set name=%~nx1
set arbeitsverzeichnis=%~dp1

if not exist "%pfad%.exe" (
  if "%~dpnx1"=="" (
    echo --------------------------------------------------------------------------------
    echo Usage: %0 PROJECTNAME
    echo        Perform tests with program PROJECTNAME using the test files 
    echo        'PROJECTNAME_test*.in' and 'PROJECTNAME_test*.out'.
    echo --------------------------------------------------------------------------------
    pause
    goto :eof
  )
  echo Error: executable %pfad%.exe does not exist.
  echo Please try again and check for spelling mistakes!
  pause
  goto :eof
)

echo -------------------------------------------------------
echo Checking tests for project %name%: 		    
echo -------------------------------------------------------

set passed=0
set failed=0
set total=0

for %%x in ("%pfad%_test*.in") do (call :checkone "%pfad%" %%~nx)
goto :end

:checkone
  if not exist "%2.out" (
    echo Error: output file %2.out does not exist in folder %arbeitsverzeichnis%."
    exit /b
  )

  "%pfad%" < "%2.in" > "%2.myout"
  fc "%2.out" "%2.myout" > nul
  if errorlevel 1 ( 
    set /a failed+=1
    echo Test: %2: FAIL
    goto aftertest
  )
  set /a passed+=1
  echo Test: %2: PASS
  del "%2.myout"
:aftertest
  set /a total+=1
  goto :eof

:end
  echo -------------------------------------------------------
  echo Tests total : %total%
  echo Tests passed: %passed%
  echo Tests failed: %failed%
  echo -------------------------------------------------------
  pause
