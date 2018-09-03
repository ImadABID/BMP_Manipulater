make_a_grille: bib c_make_a_grille
	gcc -o compilation/exe/make_a_grille compilation/src/*.o compilation/exemples/make_a_grille.o

c_make_a_grille:
	gcc -c exemples/make_a_grille.c
	copy make_a_grille.o compilation\exemples
	del make_a_grille.o

bib:
	gcc -c src/*.c
	copy *.o compilation\src
	del *.o