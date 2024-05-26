# Nom de l'exécutable
all: exec

mainFinal.o: mainFinal.c ProjetFishFinal.h
	gcc -c mainFinal.c -o mainFinal.o
	
fonctionFinal.o: fonctionFinal.c ProjetFishFinal.h
	gcc -c fonctionFinal.c -o fonctionFinal.o 
	
structuresFinal.o: structuresFinal.c ProjetFishFinal.h
	gcc -c structuresFinal.c -o structuresFinal.o	

deplacementFinal.o: deplacementFinal.c ProjetFishFinal.h
	gcc -c deplacementFinal.c -o deplacementFinal.o	
	
exec: mainFinal.o fonctionFinal.o structuresFinal.o deplacementFinal.o
	gcc mainFinal.o fonctionFinal.o structuresFinal.o deplacementFinal.o -o exec
	
clean: 
	rm -f *.o
	rm exec
