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
		void printBoard(int *);
		int searchZero();
		int validate();//check the board is True or false
		void topSolve(int *);//the result put into the board
		int multiSolve();
	private:
		//the data for readIn()and solve()
		int solveboard[81];
		int checkboard[81];
		int board[81];
		int tempNum[81];
		int tempSp;
		int startR[81];//starting index for each row
		int startC[81];//starting index for each column
		int startB[81];//starting index for each block(3*3)
		int addR[9];//the number added for moving to next row
		int addC[9];//the number added for moving to next column
		int addB[9];//the number added for moving to next block
		int copyForSolve();
		int copyForCheck();
		int getNextBlank(int *,int sp);
		void init();
		int check(int *,int sp);
		int check1(int *,int sp,int start,int *);
		int pop();
		int push(int);
		void rotate90degree(int *);
};
