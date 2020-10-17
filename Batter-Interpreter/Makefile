CFLAGS:= -g -Wall -Wno-unused 
DEPS:= main.c main.h

windows: $(DEPS)
	gcc $(CFLAGS) -D_WINDOWS=1 *.c -o batter

linux: $(DEPS)
	gcc $(CFLAGS) *.c -o batter
