out.txt:	a.out
	./a.out < ass3_16cs30026_tst.c > out.txt
a.out: lex.yy.c
	gcc ass3_16cs30026.c -lfl
lex.yy.c: 
	flex ass3_16cs30026.l
clean: 
	rm a.out lex.yy.c out.txt
