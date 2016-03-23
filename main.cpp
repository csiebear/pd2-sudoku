#include "Sudoku.h"
#include <iostream>

using namespace std;

int main(){
	Sudoku sudoku;
	sudoku.readIn();
	sudoku.printBoard();
	sudoku.changeNum(1,4);
	sudoku.printBoard();
}
