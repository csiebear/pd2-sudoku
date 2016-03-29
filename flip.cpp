#include "Sudoku.h"
#include <iostream>

int main(){
	Sudoku ss;
	ss.readIn();
	ss.flip(1);
	ss.print();
	ss.flip(0);
	ss.print();
}
