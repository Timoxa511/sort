
@echo off

:set .do=ECHO

%.do% pushd Y:\src  

%.do% g++ -c sortir.cpp 
%.do% g++ -o Y:/MinGW/output/sortir.exe sortir.o -lint_t -LY:/MinGW/output -lsfml-window -lsfml-system -lsfml-graphics
%.do% del sortir.o

%.do% popd 
