#include "Sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define Size 81
#define length 9

using namespace std;

Sudoku::Sudoku(){
	int Cnt=0;
	for(int x=0;x<Size;x++){
		Sol[x]=0;
		Ansboard[x]=0;
		Ansboard2[x]=0;
		multiAns=false;
	}
	for(int x=1;x<=length;x++)
		for(int y=1;y<=length;y++){
			row[x][y]=true;
			col[x][y]=true;
			block[x][y]=true;
		}
}


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
	int temp;
	for(int i=0;i<Size;i++){
		cin>>board[i];
		temp=board[i];
		row[(i/9)+1][temp]=false;	
		col[(i%9)+1][temp]=false;
		block[ ((i/9)/3*3) + (i%9/3)][temp]=false;
	}
}

void Sudoku::solve(){
	int x,now_row,now_col,num,count=0;
	bool haveToChange=true;
	for(x=0;x<Size;x++){
		now_row=x/9;
		now_col=x%9;
		if(board[x]==0)
			Sol[count++]=(now_row<<8)+(now_col<<4);
		Cnt=count;	
	}
	if(Cnt==0)
		cout<<"0";
	else if(validate()){
		cout<<"0";//means the input board is wrong
	}
	else {
		tryAns(board,0);
		tryAns2(board,0);
		if(Ans==0)
			cout<<"0"<<endl;
		if(compare())
	   		cout<<"2"<<endl;
		else{
	  		cout<<"1"<<endl;
			printBoard(board);
		}
	}
}
bool Sudoku::compare(){
	bool SameOrNot;
	for(int x;x<Size;x++){
		board[x]=Ansboard[x];
	}	
	for(int x;x<Size;x++){
		if(Ansboard[x]!=Ansboard2[x]){
			SameOrNot=true;
		}
	}
	return SameOrNot;
}
bool Sudoku::tryExact(){
	int x,y,now_row,now_col,now_block,num=0;
	int canWrite;
	bool change=false;
	for(x=0;x<Size;x++){
		now_row=x/9;
		now_col=x%9;
		now_block=x/9/3*3+x%9/3;
		canWrite=0;
		if(board[x]==0){
			for(y=1;y<=length;y++){
				if(row[now_row+1][y]&&col[now_col+1][y]&&block[now_block][y]){
					canWrite++;		
					num=y;
				}
			}
			if(canWrite==1){
				board[x]=num;
				row[now_row+1][num]=false;
				col[now_col+1][num]=false;
				block[now_block][num]=false;
				change=true;
			}
		}
	}
	return change;
}
int Sudoku::tryAns(int b[81],int n){
	if(n==0){
		Ans=0;
	}
	if(Ans<1){
		if(n<Cnt){
			times++;
			return tryNumFrom1(b,n);
		}
		if(++Ans<2){
			for(int j=0;j<Size;j++)
				Ansboard[j]=b[j];
		}
	else
		return 1;
	}
}

int Sudoku::tryAns2(int b[81],int n){
	if(n==0){
		Ans2=0;
	}
	if(Ans2<1){
		if(n<Cnt){
			times++;
			return tryNumFrom9(b,n);
		}
		if(++Ans2<2){
			for(int j=0;j<Size;j++)
				Ansboard2[j]=b[j];
		}
	else
		return 1;
	}
}
int Sudoku::tryNumFrom1(int b[81], int n){
	int xx, yy, m, num, r;
	int x= (Sol[n]>>8);
	int y = ((Sol[n]>>4)&0x0F);
	for(num=1, r=0; num<=9; num++){
		b[x*9+y] = num;
		Sol[n] = (Sol[n]&0xFF0) + num;
		for(m=0; m<9; m++){
			xx = x/3*3+m%3;
			yy = y/3*3+m/3;
			if ((m!=y && b[x*9+m]==b[x*9+y]) || (m!=x && b[m*9+y]==b[x*9+y])|| (x!=xx && y!=yy && b[xx*9+yy]==b[x*9+y]))
				break;
		}
		if (m==9 && tryAns(b, n+1)) r=1;
	}
	b[x*9+y]=0;
	Sol[n]&=0xFF0;
	return r;
}

int Sudoku::tryNumFrom9(int b[81], int n){
	int xx, yy, m, num, r;
	int x= (Sol[n]>>8);
	int y = ((Sol[n]>>4)&0x0F);
	for(num=9, r=0; num>=1; num--){
		b[x*9+y] = num;
		Sol[n] = (Sol[n]&0xFF0) + num;
		for(m=0; m<9; m++){
			xx = x/3*3+m%3;
			yy = y/3*3+m/3;
			if ((m!=y && b[x*9+m]==b[x*9+y]) || (m!=x && b[m*9+y]==b[x*9+y])|| (x!=xx && y!=yy && b[xx*9+yy]==b[x*9+y]))
				break;
		}
		if (m==9 && tryAns2(b, n+1)) r=1;
	}
	b[x*9+y]=0;
	Sol[n]&=0xFF0;
	return r;
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
	if((0<=a and a<=2) and (0<=b and b<=2)){
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
	if((0<=a and a<=2) and (0<=b and b<=2)){
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
		}else{
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
		}
	}else
		cerr<<"The parameter is illegal"<<endl;
}

void Sudoku::transform(){
	changeNum(1,2);
	printBoard(board);
}

bool Sudoku::validate(){
	bool inputFalse=false;
	int now_row,now_col,xx,yy;
	for(int x=0;x<Size;x++){
		now_row=x/9;
		now_col=x%9;
		if(board[x]<0||board[x]>10)
			inputFalse=true;
		for(int i=0;i<length;i++){
			xx=now_row/3*3+i%3;
			yy=now_col/3*3+i/3;
			if(	(i!=now_col && board[x]==board[now_row*9+i]) ||
				(i!=now_row && board[x]==board[i*9+now_col]) ||
				(i!=xx && i!=yy && board[x]==board[xx*9+yy]))	
				inputFalse=true;
		}
	}
	return inputFalse;
}
