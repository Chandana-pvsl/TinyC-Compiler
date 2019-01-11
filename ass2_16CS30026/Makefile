a.out: main.o libprint.a
		cc main.o -L. -lprint
main.o: main.c myl.h
		cc -Wall -c main.c
libprint.a: ass2_16CS30026.o
		ar -rcs libprint.a ass2_16CS30026.o
myl.o: ass2_16CS30026.c myl.h
		cc -Wall -c ass2_16CS30026.c
clean:
		rm a.out main.o libprint.a ass2_16CS30026.o