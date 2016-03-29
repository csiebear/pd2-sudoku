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
//	cout<<"The random number:"<<random<<endl;
	int q1[81]={5,3,0,0,7,0,0,0,0,
				6,0,0,1,9,5,0,0,0,
				0,9,8,0,0,0,0,6,0,
				8,0,0,0,6,0,0,0,3,
				4,0,0,8,0,3,0,0,1,
				7,0,0,0,2,0,0,0,6,
				0,6,0,0,0,0,2,8,0,
				0,0,8,5,0,0,0,1,0,
				0,0,0,0,8,0,0,7,9	
				};
	for(int i=0;i<Size;i++)
		board[i]=q1[i];
	printBoard(board);
}
//Read in the Sudoku board(81 digits) and store them into the array board
void Sudoku::readIn(){
	for(int i=0;i<Size;i++){
		cin>>board[i];
	}
}

//Print the board,if the column(i+1) equals to 9 print the number and endline,
//else only print the number
void Sudoku::printBoard(int b[81]){
	for(int i=0;i<Size;i++){
		if((i+1)%9==0){
			cout<<b[i]<<" "<<endl;
		}else
			cout<<b[i]<<" ";
	}
}


void Sudoku::print(){
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
				if(board[row*9+col]==a){
					a_pos=row*9+col;
					board[a_pos]=b;
				}else if(board[row*9+col]==b){
					b_pos=row*9+col;
					board[b_pos]=a;
				}
			}
		}
	}else
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
			rotate90degree(board);	
		}
	}
	else
		cerr<<"The parameter is illegal(0<=n<=100)"<<endl;
}


void Sudoku::rotate90degree(int b[81]){
	int cnd=length/2;
	int tmp=0;
	for(int i=0;i<cnd;++i){
		int side=length-1-2*i;
		for(int j=i;j<side+i;++j){ 
			tmp = b[j*length+i];						/* m[j][i]*/
			b[j*length+i]=b[length*(i+side)+j];			/* m[i+ss][j]*/
		    b[length*(i+side)+j] = b[length*(length-j-1)+i+side]; /* m[dim-j-1][i+ss] */
		    b[length*(length-j-1)+i+side] = b[i*length+length-j-1]; /* m[i][dim-j-1] */
		   	b[i*length+length-j-1] = tmp;             /* m[dim-j-1][i+ss] */
		}//end inner for-loop
	}//end outer for-loop
}

void Sudoku::flip(int n){
	if(n==1 || n==0){	
		if(n==1){
			for(int i=0;i<Size;i++){
				int temp;
				switch (i%9){
					case 0:
						temp=board[i+8];
						board[i+8]=board[i];
						board[i]=temp;
						break;
					case 1:
						temp=board[i+6];
						board[i+6]=board[i];
						board[i]=temp;
						break;
					case 2:
						temp=board[i+4];
						board[i+4]=board[i];
						board[i]=temp;
						break;
					case 3:
						temp=board[i+2];
						board[i+2]=board[i];
						board[i]=temp;
						break;
				}	
			}
			printBoard(board);		
		}
		if(n==0){
			int temp,row,col;
			for(int i=0;i<=35;i++){
				row=i/9;
				col=i%9;
				switch (row){
					case 0:
						temp=board[i];
						board[i]=board[(row+8)*9+col];
						board[(row+8)*9+col]=temp;
						break;
					case 1:
						temp=board[i];
						board[i]=board[(row+6)*9+col];
						board[(row+6)*9+col]=temp;
						break;
					case 2:
						temp=board[i];
						board[i]=board[(row+4)*9+col];
						board[(row+4)*9+col]=temp;
						break;
					case 3:	
						temp=board[i];
						board[i]=board[(row+2)*9+col];
						board[(row+2)*9+col]=temp;
				}
			}	
			printBoard(board);
		}
	}else
		cerr<<"The parameter is illegal"<<endl;
}

void Sudoku::transform(){
	rotate90degree(board);
	printBoard(board);
}
int Sudoku::searchZero(){
	//search the 0 in the board,if the board have 0,return the position.Otherwise,return -1(mean no 0)
	int count=0;
	for(int i=0;i<Size;i++){
		if(board[i]==0)
			count++;
	}
	return count;
}

int Sudoku::copyForCheck(){
	for(int i=0;i<Size;i++){
		if(board[i]==0)
			checkboard[i]=10;
		else
			checkboard[i]=board[i];
	}
}
int Sudoku::copyForSolve(){
	for(int i=0;i<Size;i++){
		solveboard[i]=board[i];
	}
}

void Sudoku::solve(){
	if(searchZero()==0){//No digit is zero,and then check the board correctness
		if(validate()==1){//do not solve just print result and board
			cout<<"1"<<endl;
			printBoard(board);
		}else{
			cout<<"0";
		}
	}else{
		switch(multiSolve()){
			case 0:
				cout<<"0";
				break;
			case 1:
				cout<<"1"<<endl;
				printBoard(solveboard);
				break;
			case 2:
				cout<<"2";
				break;
			default:
				cout<<"0";
				break;
		}
		}	
}
int Sudoku::multiSolve(){
	int noAns=0;
	int solution=0;
//solve from the origin board[0]
	copyForSolve();
	topSolve(solveboard);
	copyForCheck();
	downSolve(checkboard);
	for(int i=0;i<Size;i++){	
		if(board[i]==solveboard[i])
			noAns++;
	}
	for(int i=0;i<Size;i++){	
		if(solveboard[i]==checkboard[i]){
			solution++;
		}
	}
	if(noAns==81)
		return 0;
	else if(solution==81)
		return 1;//mean have exactly one solution 
	else
		return 2;//the solution=1,mean at least two result
}

void Sudoku::init(){
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
void Sudoku::topSolve(int b[81]){
	init();
	int sp=getNextBlank(b,-1);// 取得第一個空白的位置開始填入數字
	do{
		b[sp]++;            // 將本位置數字加 1
		if(b[sp]>9) {		// 如果本位置的數字已大於 9 時則回到上一個位置繼續測試
			b[sp]= 0 ;
			sp=pop() ;
		}else{
			if(check(b,sp)==0){	//如果同行、列、九宮格都沒有相同的數字，則到下一個空白處繼續
			push(sp);
			sp=getNextBlank(b,sp);
			}//end else
		}//end else
	}while(sp>=0 && sp<Size);
}
void Sudoku::downSolve(int b[81]){
	init();
	int sp=getNextBlank2(b,-1);// 取得第一個空白的位置開始填入數字
	do{
		b[sp]--;
		if(b[sp]<1) {
		b[sp]= 10 ;
		sp=pop() ;
	}else{
		if(check(b,sp)==0){	//如果同行、列、九宮格都沒有相同的數字，則到下一個空白處繼續
		push(sp);
		sp=getNextBlank2(b,sp);
			}//end else
		}//end else
	}while(sp>=0 && sp<Size);
}

int Sudoku::validate(){
	int result;//0:mean no flase digit in the board
	init();
	for(int i=0;i<Size;i++)
		result=check(board,i)+1;
	return result;	
}

int Sudoku::getNextBlank(int b[81],int sp){
	do{
	sp++;
	}while(sp<Size && b[sp]>0);
	return sp;
}
int Sudoku::getNextBlank2(int b[81],int sp){
	do{
	sp++;
	}while(sp<Size && b[sp]<10);
	return sp;
}


int Sudoku::check1(int b[81],int sp, int start, int *addnum) {
// 檢查指定的行、列、九宮格有沒有相同的數字，若有傳回 1
	int fg= 0, i, sp1  ;
	for(i=0; i<9; i++) {
		sp1= start+ addnum[i] ;
		if(sp!=sp1 && b[sp]==b[sp1]) fg++ ;
	}
	return(fg);
}


int Sudoku::check(int b[81],int sp){
	int fg=0;
	if(!fg) fg= check1(b,sp, startR[sp], addR) ;   // 檢查同列有沒有相同的數字
	if(!fg) fg= check1(b,sp, startC[sp], addC) ;   // 檢查同行有沒有相同的數字
	if(!fg) fg= check1(b,sp, startB[sp], addB) ;   // 檢查同九宮格有沒有相同的數字
	return(fg);
}
int Sudoku::push(int sp){
	tempNum[tempSp++]=sp;
}

int Sudoku::pop(){
	if(tempSp<=0) return -1;
	else return (tempNum[--tempSp]);
}
