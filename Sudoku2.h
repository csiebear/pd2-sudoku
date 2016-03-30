#include <iostream>
#include <vector>

using namespace std;

class Sudoku{
		public:
			void giveQuestion();//output 81 digits
			void readIn();//input 81 digit,and Read in Sudoku board
			void solve();//use the ReadIn data and output slovable
			//unsolable(if solvable print 1 and the answer
			void changeNum(int a,int b);//exchange the number a and b in Sudoku board
			void changeRow(int a,int b);//exchagne the row set a and b
			//the row set 0 mean row 0~2 
			void changeCol(int a,int b);//the same concept as changeRow,but now we change the column
			void rotate(int n);//Rotate the board clockwise 90 degree,and the input n between 0 and 100
			void flip(int n);//when input n==0,flip the board vertically.Otherwise,flip it horizontally.
			//input 0<=n<=1
			void transform();
			void print();
			void printBoard(int b[81]);
			void ShowAns(int b[][9]);
			int tryAns(int b[][9],int n);
			int tryNum(int b[][9],int n);
			int validate();

		private:
			//the data for readIn()and solve()
			int board[81];
			int board2[9][9];
			int Solve[9][9];
			int Sol[81],Sol_x[81],Sol_y[81];
			bool rule1,rule2;
			int Cnt,Ans,Ans2;
			void init();
			void rotate90degree(int b[81]);
};
