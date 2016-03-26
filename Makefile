solve:Sudoku.o solve.o
	g++ -o solve solve.o Sudoku.o
giveQuestion:Sudoku.o giveQuestion.o
	g++ -o GiveQuestion giveQuestion.o Sudoku.o
Sudoku.o:Sudoku.h Sudoku.cpp
	g++ -c Sudoku.cpp
solve.o:solve.cpp Sudoku.h
	g++ -c solve.cpp
giveQuestion.o:giveQuestion.o Sudoku.h
	g++ -c giveQuestion.o
clear:
	rm *.o
