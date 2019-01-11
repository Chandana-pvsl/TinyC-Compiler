testing: a.out
	./a.out < ass5_16cs30026_test5.c > ass5_16cs30026_quads5.out
	./a.out < ass5_16cs30026_test1.c > ass5_16cs30026_quads1.out
	./a.out < ass5_16cs30026_test2.c > ass5_16cs30026_quads2.out
	./a.out < ass5_16cs30026_test3.c > ass5_16cs30026_quads3.out
	./a.out < ass5_16cs30026_test4.c > ass5_16cs30026_quads4.out

a.out: lex.yy.o y.tab.o ass5_16cs30026_translator.o
	g++ lex.yy.o y.tab.o ass5_16cs30026_translator.o -lfl

ass5_16cs30026_translator.o: ass5_16cs30026_translator.cxx ass5_16cs30026_translator.h
	g++ -c -std=c++0x ass5_16cs30026_translator.h
	g++ -c -std=c++0x ass5_16cs30026_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c  y.tab.c

lex.yy.c: ass5_16cs30026.l y.tab.h ass5_16cs30026_translator.h
	flex ass5_16cs30026.l

y.tab.c: ass5_16cs30026.y
	yacc -dtv  ass5_16cs30026.y 

y.tab.h: ass5_16cs30026.y
	yacc -dtv  ass5_16cs30026.y 
	
clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass5_16cs30026_translator.o a.out y.output 
