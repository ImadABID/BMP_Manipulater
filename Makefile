make_a_grill: bib c_make_a_grille make_dir_exe
	gcc -o exe\make_a_grill objects\src\*.o objects\exemples\make_a_grille.o

c_make_a_grille: make_dir_objects_exemples
	gcc -c exemples\make_a_grille.c
	copy exemples\make_a_grill.o objects\exemples\
	del exemples\make_a_grill.o

bib: make_dir_objects_src
	gcc -c src\*.c
	copy src\*.o objects\src\
	del src\*.o

#make-dir
make_dir_exe:
	mkdir exe

make_dir_objects:
	mkdir objects

make_dir_objects_exemples: make_dir_objects
	cd objects && mkdir exemples

make_dir_objects_src: make_dir_objects
	cd objects && mkdir src