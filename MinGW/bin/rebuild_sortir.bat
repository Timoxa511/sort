
@echo off

:set .do=ECHO

%.do% g++ -c sortir.cpp 
%.do% g++ -o sortir.exe sortir.o -lint_t -L. -lsfml-window -lsfml-system -lsfml-graphics
%.do% del sortir.o
