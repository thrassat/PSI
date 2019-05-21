compilateurc: y.tab.c lex.yy.c ts.c ti.c
	gcc lex.yy.c y.tab.c ts.c ti.c -o compilateurc -ly -ll 

lex.yy.c: compilateurc.l
	flex compilateurc.l 

y.tab.c: compilateurc.y 
	yacc -d -v -t compilateurc.y 

inputstring:compilateurc
	./compilateurc < inputstring

clean:
	rm y.tab.c y.tab.h lex.yy.c compilateurc
