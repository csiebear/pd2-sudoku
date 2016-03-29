#include "Sudoku.h"
int main(){
	Sudoku ss;
	ss.readIn();
	cout<<"Input board"<<endl;
	ss.print();
	cout<<"changeNumber(1,9)"<<endl;
	ss.changeNum(1,9);
	ss.print();
	ss.changeNum(9,1);
//	ss.print();
	cout<<"changeRow(1,2)"<<endl;	
	ss.changeRow(1,2);
	ss.print();
	ss.changeRow(2,1);
	cout<<"chagneCol(1,2)"<<endl;
	ss.changeCol(1,2);
	ss.print();
	ss.changeCol(2,1);
	cout<<"Test transform(clockwise rotate 90 degree),it will print the board"<<endl;
	ss.transform();
	return 0;
}
