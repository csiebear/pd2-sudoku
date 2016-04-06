#include <iostream>

using namespace std;

class Sudoku{
		public:
			Sudoku();
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
		//	void ShowAns(int b[][9]);
		//	bool tryExact();
			bool compare();
			int tryAns(int b[81],int n);
			int tryAns2(int b[],int n);
			int tryNumFrom1(int b[81],int n);
			int tryNumFrom9(int b[81],int n);
			bool validate();

		private:
			//the data for readIn()and solve()
			int Sol[81];
			int board[81];
			int Solveboard[81];
			int Ansboard[81],Ansboard2[81];
//			bool block[10][10];
//			bool row[10][10];
//			bool col[10][10];
			bool multiAns;
			int Cnt,Ans,Ans2;
			int times;
			void rotate90degree(int b[81]);
};
