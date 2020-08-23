@echo off
title FOR

:main
    set /a i=1
    :loop_start
        echo %i%
        set/a i="i+1"
        if %i% leq 20 goto loop_start
    :loop_end

:main_end