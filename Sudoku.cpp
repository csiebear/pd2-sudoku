#include "Sudoku.h"
#include <vector>
#include <iostream>
#define Size 81
#define length 9

using namespace std;

void Sudoku::readIn(){
	int digit;
	for(int i=0;i<Size;i++){
		cin>>board[i];
	}
}
void Sudoku::printBoard(){
	for(int i=0;i<Size;i++){
		if((i+1)%9==0){
			cout<<board[i]<<" "<<endl;
		}else
			cout<<board[i]<<" ";
		
	}
}
void Sudoku::solve(){
	
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
		for(int col=0;col<3;col++){
			for(int row=0;row<length;row++){
				temp=board[(a*3+row)*9+col];
				board[(a*3+row)*9+col]=board[(b*3+row)*9+col];
				board[(b*3+row)*9+col]=temp;
			}
		}
	}
	else
		cerr<<"The parameter is illegal(0<=a,b<=2)";
}
