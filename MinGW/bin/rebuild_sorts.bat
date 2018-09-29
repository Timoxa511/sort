
@echo off

:set .do=ECHO

for %%i in (sorts/*.cpp) do (
	%.do% g++ -c sorts/%%i 
	%.do% g++ -o %%~ni.sort %%~ni.o -mdll -lint_t -L. 								 
	%.do% del %%~ni.o
	)