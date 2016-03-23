EXE:Sudoku.o main.o
	g++ -o EXE main.o Sudoku.o
Sudoku.o: Sudoku.h Sudoku.cpp
	g++ -c Sudoku.cpp
main.o:main.cpp Sudoku.h
	g++ -c main.cpp
clear:
	rm *.o
