#include "Sudoku.h"
#include <iostream>

using namespace std;

int main(){
	Sudoku sudoku;
	sudoku.readIn();
	sudoku.printBoard();
	sudoku.changeRow(1,2);
	sudoku.printBoard();
}
