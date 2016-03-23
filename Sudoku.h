#include <iostream>
#include <vector>

using namespace std;

class Sudoku{

	public:
		void giveQuestion();//output 81 digits
		void readIn();//input 81 digit,and Read in Sudoku board
		void solve();
		//use the ReadIn data and output slovable/unsolable(if solvable print 1 and the answer
		void changeNum(int a,int b);//exchange the number a and b in Sudoku board
		void changeRow(int a,int b);//exchagne the row set a and b
		//the row set 0 mean row 0~2 
		void changeCol(int a,int b);
		//the same concept as changeRow,but now we change the column
		void rotate(int n);
		//Rotate the board clockwise 90 degree,and the input n between 0 and 100
		void flip(int n);
		//when input n==0,flip the board vertically.Otherwise,flip it horizontally.
		//input 0<=n<=1
		void transform();
		void printBoard();
	private:
		//the data for readIn()and solve()
		int board[81];
		int tempNum[81];
		int tempSp;
		int startR[81];
		int startC[81];
		int startB[81];
		int addR[9];
		int addC[9];
		int addB[9];
		void init();
		int getNextBlank(int sp);
		int check(int sp);
		int check1(int sp,int start,int *);
		int pop();
		int push(int);
};
