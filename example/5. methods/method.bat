@echo off
title Method

:: method square gets a parameter param_1
:square
    set /a square_result=square_param_1*square_param_1
    :: end method
    goto square_call
:square_end


:: main function
:main
    set /a number=4

    :: basic function call in batch

    :: prepare parameter 1 for square()
    set /a square_param_1=%number%

    :: jump into method
    goto square
    :square_call

    set /a number=%square_result%

    echo %number%

:main_end