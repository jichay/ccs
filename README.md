# ccs
L3 App project

gcc -Wall -g  -c etudiant.c -o etudiant.o  
gcc -Wall -g  -c execute.c -o execute.o  
gcc -Wall -g  -c main.c -o main.o  
gcc -Wall -g  -c parser.c -o parser.o  
gcc  -o ccs_exe etudiant.o execute.o main.o parser.o  
