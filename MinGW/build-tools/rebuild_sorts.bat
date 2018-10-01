
@echo off

:set .do=ECHO

%.do% pushd Y:\src

for %%i in (sorts/*.cpp) do (
	%.do% g++ -c sorts/%%i 
	%.do% g++ -o ../MinGw/output/%%~ni.sort %%~ni.o -mdll -lint_t -LY:/MinGW/output 								 
	%.do% del %%~ni.o
	)

%.do% popd 