call "C:\apps\MVS12\VC\VCVARSALL.BAT " amd64

cd .
nmake -f soh.mk optimized_floating_point=1 MODELLIB=sohlib.lib RELATIVE_PATH_TO_ANCHOR=.. MODELREF_TARGET_TYPE=NONE ISPROTECTINGMODEL=NOTPROTECTING
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
