all : four.elf


one.o : one.c
	gcc --static -c -o one.o one.c
two.o : two.c
	gcc --static -c -o two.o two.c

libjaewon.a : two.o
	ar rc libjaewon.a two.o

four.elf : libjaewon.a one.o
	gcc -o four.elf one.o -l jaewon -L .
