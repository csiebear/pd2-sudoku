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

void Sudoku::init(){
	//Parameter initialization	參數初始化
	tempSp=0;
	int i;
	for(i=0;i<Size;i++){
		startR[i]= i/9 *9 ;
		startC[i]= i%9 ;
		startB[i]=((i/9)/3)*27+((i%9)/3)*3;
	}
	for(i=0;i<length;i++){
		addR[i]=i;
		addC[i]=i*9;
		addB[i]=(i/3)*9+(i%3);
	}
}

int Sudoku::getNextBlank(int sp){
	do{
		sp++;
	}while(sp<Size && board[sp]>0);
	return sp;
}

int Sudoku::check1(int sp, int start, int *addnum) {
// 檢查指定的行、列、九宮格有沒有相同的數字，若有傳回 1
	int fg= 0, i, sp1  ;
	for(i=0; i<9; i++) {
	sp1= start+ addnum[i] ;
	if(sp!=sp1 && board[sp]==board[sp1]) fg++ ;
	}
	return(fg);
}

int Sudoku::check(int sp){
	int fg=0;
	if(!fg) fg= check1(sp, startR[sp], addR) ;   // 檢查同列有沒有相同的數字
	if(!fg) fg= check1(sp, startC[sp], addC) ;   // 檢查同行有沒有相同的數字
	if(!fg) fg= check1(sp, startB[sp], addB) ;   // 檢查同九宮格有沒有相同的數字
	return(fg);
}

void Sudoku::solve() {
	init();
	int sp=getNextBlank(-1) ;                    // 取得第一個空白的位置開始填入數字
	do{
		board[sp]++;                            // 將本位置數字加 1
		if(board[sp]>9) {                        // 如果本位置的數字已大於 9 時則回到上一個位置繼續測試
			board[sp]= 0 ;
			sp=pop() ;
		}else{
			if(check(sp)==0){                     // 如果同行、列、九宮格都沒有相同的數字，則到下一個空白處繼續
				push(sp);
				sp=getNextBlank(sp);
			}//end if
		}//end else
	}while(sp>=0 && sp<Size);
}

int Sudoku::push(int sp){
	tempNum[tempSp++]=sp;
}

int Sudoku::pop(){
	if(tempSp<=0) return -1;
	else return (tempNum[--tempSp]);
}
