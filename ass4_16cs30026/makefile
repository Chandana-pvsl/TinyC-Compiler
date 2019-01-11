test_output.txt: a.out ass4_16CS30026_test.c
	./a.out < ass4_16CS30026_test.c 2>stack.txt >output.txt
a.out: ass4_16cs30026_main.o lex.yy.c assgn4.tab.c
	gcc lex.yy.c assgn4.tab.c ass4_16cs30026_main.o -lfl 
ass4_16cs30026_main.o: ass4_16cs30026_main.c assgn4.tab.h 
	gcc -c ass4_16cs30026_main.c
assgn4.tab.c: ass4_16cs30026.y
	bison -dtv ass4_16cs30026.y
assgn4.tab.h:ass4_16cs30026.y
	bison -dtv ass4_16cs30026.y
lex.yy.c: assgn4.tab.h ass4_16cs30026.l
	flex ass4_16cs30026.l
clean:
	rm lex.yy.c ass4_16cs30026.tab.c ass4_16cs30026.tab.h ass4_16cs30026_main.o a.out stack.txt output.txt ass4_16cs30026.output
