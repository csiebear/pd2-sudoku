solve:Sudoku.o solve.o
	g++ -o solve solve.o Sudoku.o
giveQuestion:Sudoku.o giveQuestion.o
	g++ -o giveQuestion giveQuestion.o Sudoku.o
transform:Sudoku.o transform.o
	g++ -o transform transform.o Sudoku.o
Sudoku.o:Sudoku.h Sudoku.cpp
	g++ -c Sudoku.cpp
solve.o:solve.cpp Sudoku.h
	g++ -c solve.cpp
giveQuestion.o:giveQuestion.cpp Sudoku.h
	g++ -c giveQuestion.cpp
transform.o:transform.cpp Sudoku.h
	g++ -c transform.cpp
clear:
	rm *.o
