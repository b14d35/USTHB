cls
flex projet.l
bison -d projet.y
gcc -o projet.exe lex.yy.c projet.tab.c src/assem.c src/Errors.c src/indentation.c src/optim.c src/pile.c src/pile2.c src/quad.c src/TS.c
projet.exe