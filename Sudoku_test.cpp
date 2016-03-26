#include "Sudoku.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#define Size 81
#define length 9

using namespace std;

void Sudoku::giveQuestion(){
	srand(time(NULL));	
	int random=(rand()%10)+1;
	cout<<"The random number:"<<random<<endl;
	int q1[81]={8,0,0,0,0,0,0,0,0,
				0,0,3,6,0,0,0,0,0,
				0,7,0,0,9,9,2,0,0,
				0,5,0,0,0,7,0,0,0,
				0,0,0,0,4,5,7,0,0,
				0,0,0,1,0,0,0,3,0,
				0,0,1,0,0,0,0,6,8,
				0,0,8,5,0,0,0,1,0,
				0,9,0,0,0,0,4,0,0	
				};
	for(int i=0;i<Size;i++)
		board[i]=q1[i];
	printBoard();
}

//Read in the Sudoku board(81 digits) and store them into the array board
void Sudoku::readIn(){
	int digit;
	for(int i=0;i<Size;i++){
		cin>>board[i];
	}
}

//Print the board,if the column(i+1) equals to 9 print the number and endline,
//else only print the number
void Sudoku::printBoard(){
	for(int i=0;i<Size;i++){
		if((i+1)%9==0){
			cout<<board[i]<<" "<<endl;
		}else
			cout<<board[i]<<" ";
	}
}

void Sudoku::changeNum(int a,int b){
	if( (1<=a and a<=9) and (1<=b and b <=9)){
	int a_pos,b_pos;
	for(int row=0;row<length;row++){
		for(int col=0;col<length;col++){
			if(board[row*9+col]==a)
				a_pos=row*9+col;
			if(board[row*9+col]==b)
				b_pos=row*9+col;
		}
		board[a_pos]=b;
		board[b_pos]=a;
	}
	}
	else
		cerr<<"The parameter is illegal"<<endl;
}

void Sudoku::changeRow(int a,int b){
	int temp;
	if((0<=a and a<=2) and (0<=b and 0<=b)){
		for(int row=0;row<3;row++){
			for(int col=0;col<length;col++){
				temp=board[(a*3+row)*9+col];
				board[(a*3+row)*9+col]=board[(b*3+row)*9+col];
				board[(b*3+row)*9+col]=temp;
			}
		}
	}
	else
		cerr<<"The parameter is illegal(0<=a,b<=2)";
}

void Sudoku::changeCol(int a,int b){
	int temp;
	if((0<=a and a<=2) and (0<=b and 0<=b)){
		for(int row=0;row<length;row++){
			for(int col=b*3;col<b*3+3;col++){
				int temp_col=col%3;
				temp=board[row*9+a*3+temp_col];
				board[row*9+a*3+temp_col]=board[row*9+b*3+temp_col];
				board[row*9+b*3+temp_col]=temp;
			}
		}
	}
	else
		cerr<<"The parameter is illegal(0<=a,b<=2)"<<endl;
}

void Sudoku::rotate(int n){
	if(n>=0 and n<=100){
		for(int i=0;i<(n%4);i++){
			rotate90degree();	
		}
	}
	else
		cerr<<"The parameter is illegal(0<=n<=100)"<<endl;
}

void Sudoku::rotate90degree(){
	int cnd=length/2;
	int tmp=0;
	for(int i=0;i<cnd;++i){
		int side=length-1-2*i;
		for(int j=i;j<side+i;++j){ 
			tmp = board[j*length+i];						/* m[j][i]*/
			board[j*length+i]=board[length*(i+side)+j];			/* m[i+ss][j]*/
		    board[length*(i+side)+j] = board[length*(length-j-1)+i+side]; /* m[dim-j-1][i+ss] */
		    board[length*(length-j-1)+i+side] = board[i*length+length-j-1]; /* m[i][dim-j-1] */
		   	board[i*length+length-j-1] = tmp;             /* m[dim-j-1][i+ss] */
		}//end inner for-loop
	}//end outer for-loop
}

void Sudoku::flip(int n){

}

void Sudoku::transform(){
	srand(time(NULL));	
	int random=(rand()%10)+1;
	cout<<"The random number:"<<random<<endl;
	changeCol(time(NULL)%3,random%3);
	printBoard();
}
int Sudoku::searchZero(){
	//search the 0 in the board,if the board have 0,return the position.Otherwise,return -1(mean no 0)
	for(int i=0;i<Size;i++){
		if(board[i]==0)
			return i;
	}
	return -1;
}


void Sudoku::solve(){

}
