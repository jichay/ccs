# CCS
L3 App project

## Instructions de compilation:
```
gcc -Wall -g  -c etudiant.c -o etudiant.o  
gcc -Wall -g  -c execute.c -o execute.o  
gcc -Wall -g  -c main.c -o main.o  
gcc -Wall -g  -c parser.c -o parser.o  
gcc  -o ccs_exe etudiant.o execute.o main.o parser.o  
```
## Test

Les test unitaire sont basés sur la bibliotheque standard [assert.h](https://fr.wikipedia.org/wiki/Assert.h).  
Ils sont présents dans le main et executés a chaque lancement du programme.
