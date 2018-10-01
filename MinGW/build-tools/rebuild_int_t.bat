
:@echo off

:set .do=ECHO

%.do%  pushd Y:\src

%.do%  g++ -c int_t.cpp 
%.do%  g++ -shared -o Y:/MinGW/output/int_t.dll -Wl,--out-implib,Y:/MinGW/output/libint_t.a int_t.o
%.do%  del int_t.o

%.do%  popd