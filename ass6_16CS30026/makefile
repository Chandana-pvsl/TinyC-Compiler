asmGenerate: comp
	./comp 1 > ass6_16CS30026_quads1.out
	./comp 2 > ass6_16CS30026_quads2.out
	./comp 3 > ass6_16CS30026_quads3.out
	./comp 4 > ass6_16CS30026_quads4.out
	./comp 5 > ass6_16CS30026_quads5.out
 
comp: lex.yy.o y.tab.o ass6_16CS30026_translator.o ass6_16CS30026_target_translator.o
	g++ lex.yy.o y.tab.o ass6_16CS30026_translator.o \
	ass6_16CS30026_target_translator.o -lfl -o comp

ass6_16CS30026_target_translator.o: ass6_16CS30026_target_translator.cxx
	g++ -c ass6_16CS30026_target_translator.cxx

ass6_16CS30026_translator.o: ass6_16CS30026_translator.cxx ass6_16CS30026_translator.h
	g++ -c -std=c++0x ass6_16CS30026_translator.h
	g++ -c -std=c++0x ass6_16CS30026_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass6_16CS30026.l y.tab.h ass6_16CS30026_translator.h
	flex ass6_16CS30026.l

y.tab.c: ass6_16CS30026.y
	yacc -dtv ass6_16CS30026.y 

y.tab.h: ass6_16CS30026.y
	yacc -dtv ass6_16CS30026.y 
	
clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass6_16CS30026_translator.o test1 test2 test3 test4 test5 y.output comp ass6_16CS30026_target_translator.o libass2_16CS30026.a ass6_16CS30026_1.o ass2_16CS30026.o ass6_16CS30026_2.o ass6_16CS30026_3.o ass6_16CS30026_4.o ass6_16CS30026_5.o

clean1:
	rm test1 ass6_16CS30026_1.o libass2_16CS30026.a ass2_16CS30026.o

#Test files
test1: ass6_16CS30026_1.o libass2_16CS30026.a
	gcc -g ass6_16CS30026_1.o -o test1 -L. -lass2_16CS30026
ass6_16CS30026_1.o: myl.h
	gcc -c ass6_16CS30026_1.s

test2: ass6_16CS30026_2.o libass2_16CS30026.a
	gcc ass6_16CS30026_2.o -o test2 -L. -lass2_16CS30026
ass6_16CS30026_2.o: myl.h
	gcc -Wall -c ass6_16CS30026_2.s

test3: ass6_16CS30026_3.o libass2_16CS30026.a
	gcc ass6_16CS30026_3.o -o test3 -L. -lass2_16CS30026
ass6_16CS30026_3.o: myl.h
	gcc -Wall -c ass6_16CS30026_3.s

test4: ass6_16CS30026_4.o libass2_16CS30026.a
	gcc ass6_16CS30026_4.o -o test4 -L. -lass2_16CS30026
ass6_16CS30026_4.o: myl.h
	gcc -Wall -c ass6_16CS30026_4.s

test5: ass6_16CS30026_5.o libass2_16CS30026.a
	gcc ass6_16CS30026_5.o -o test5 -L. -lass2_16CS30026
ass6_16CS30026_5.o: myl.h
	gcc -Wall -c ass6_16CS30026_5.s


libass2_16CS30026.a: ass2_16CS30026.o
	ar -rcs libass2_16CS30026.a ass2_16CS30026.o

ass2_16CS30026.o: ass2_16CS30026.c myl.h
	gcc -Wall -c ass2_16CS30026.c