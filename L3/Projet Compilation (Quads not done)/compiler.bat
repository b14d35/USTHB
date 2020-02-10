@@echo off
cls
flex lex.l
bison -d synt.y
gcc lex.yy.c synt.tab.c -ly -o comp
comp.exe < test.txt