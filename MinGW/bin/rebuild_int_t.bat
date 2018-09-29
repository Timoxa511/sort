
@echo off

:set .do=ECHO

%.do%  g++ -c int_t.cpp 
%.do%  g++ -shared -o int_t.dll -Wl,--out-implib,libint_t.a int_t.o
%.do%  del int_t.o