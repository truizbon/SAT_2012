all: sat

sat:	Students.o BinarySearchTree.o Main.o
	gcc -o sat BinarySearchTree.o Students.o Main.o
Main.o:	Main.c
	gcc -c Main.c
BinarySearchTree.o:	BinarySearchTree.c BinarySearchTree.h
			gcc -c BinarySearchTree.c BinarySearchTree.h
Students.o:	Students.c Students.h
		gcc -c Students.c Students.h
clean:
	rm -f *.o *.h.gch sat
