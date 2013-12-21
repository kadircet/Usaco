/*
ID:kadirce1
LANG:C++
PROG:ttwo
*/

#include <iostream>
#include <fstream>
using namespace std;

enum DIR
{
	U=0,N,E,W,S
};

struct object
{
	int row, col;
	DIR dir;
};

char map[11][11];
object john, cows;
int minute=0;

void move(object& obj)
{
	int cr=obj.row, cc=obj.col;
	if(obj.dir==N)
	{
		if(cr==0)
			obj.dir=E;
		else if(map[cr-1][cc]=='*')
			obj.dir=E;
		else
			obj.row = cr-1;
	}
	else if(obj.dir==E)
	{
		if(cc==9)
			obj.dir=S;
		else if(map[cr][cc+1]=='*')
			obj.dir=S;
		else
			obj.col = cc+1;
	}
	else if(obj.dir==W)
	{
		if(cc==0)
			obj.dir=N;
		else if(map[cr][cc-1]=='*')
			obj.dir=N;
		else
			obj.col = cc-1;
	}
	else if(obj.dir==S)
	{
		if(cr==9)
			obj.dir=W;
		else if(map[cr+1][cc]=='*')
			obj.dir=W;
		else
			obj.row = cr+1;
	}
}

int main()
{
	ifstream inp("ttwo.in");
	ofstream oup("ttwo.out");
	
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			inp >> map[i][j];
			if(map[i][j] == 'F')
			{
				john.row = i;john.col = j;
				john.dir = N;
			}
			else if(map[i][j] == 'C')
			{
				cows.row = i;cows.col = j;
				cows.dir = N;
			}
		}
	
	while((cows.row != john.row || cows.col != john.col) && minute <= 160000)
	{
		minute++;
		move(cows);move(john);
	}
	if(cows.row!=john.row || cows.col != john.col)
		minute=0;
	oup << minute << endl;
	
	return 0;
}

