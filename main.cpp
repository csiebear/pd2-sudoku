#include "Sudoku.h"
#include <iostream>

using namespace std;

int main(){
	cout<<"Test solve!"<<endl;
	Sudoku sudoku;
	sudoku.readIn();
	cout<<"Origin:"<<endl;
	sudoku.printBoard();
	cout<<"Solve it"<<endl;
	sudoku.solve();
	cout<<"Answer："<<endl;
	sudoku.printBoard();
	cout<<"Test transform!"<<endl;
	sudoku.readIn();
	sudoku.transform();
//	sudoku.readIn();
//	sudoku.printBoard();
//	sudoku.changeRow(1,2);
//	sudoku.printBoard();
//	cout<<"Test ChangeColumn 1 and 2"<<endl;
//	sudoku.readIn();
//	sudoku.changeCol(1,2);
//	sudoku.printBoard();

//	cout<<"Test ChangeColumn 2 and 0"<<endl;
//	sudoku.readIn();
//	sudoku.printBoard();
//	sudoku.changeCol(2,0);
//	sudoku.printBoard();
	
	sudoku.readIn();
	sudoku.printBoard();
/*旋轉*/
	sudoku.rotate(2);	
	sudoku.printBoard();

//	sudoku.solve();
//	sudoku.printBoard();
}
