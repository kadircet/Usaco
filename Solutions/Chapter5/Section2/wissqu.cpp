/*
ID:kadirce1
LANG:C++
PROG:wissqu
*/
#include <iostream>
#include <cstdio>
using namespace std;

struct pos
{
	int k;
	int r,c;
};

int visited[6][6][5];
bool marked[4][4];
int inp[4][4];
int remain[5];
int nsol;
pos sol[16];

bool poss(int r, int c)
{
	return r>=0 && c>=0 && r<4 && c<4;
}

int dx[] = {1,1,1,0,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,0,-1,1,0,-1};
void visit(int r, int c, int k)
{
	for(int i=0;i<9;i++)
		//if(poss(r+dy[i], c+dx[i]))
			visited[r+dy[i]][c+dx[i]][k]++;
}
void unvisit(int r, int c, int k)
{
	for(int i=0;i<9;i++)
		//if(poss(r+dy[i], c+dx[i]))
			visited[r+dy[i]][c+dx[i]][k]--;
}

void search(int r, int c, int k, int d)
{
	sol[d].r=r, sol[d].c=c, sol[d].k=k;
	if(d==15)
	{
		if(nsol==0)
			for(int i=0;i<16;i++)
				cout << char(sol[i].k+'A') << ' ' << sol[i].r+1 << ' ' << sol[i].c+1 << endl;
		nsol++;
		return;
	}
	
	//cout << d << endl;
	unvisit(r+1, c+1, inp[r][c]);
	visit(r+1, c+1, k);
	marked[r][c]=true;
	
	for(int q=0;q<5;q++)
		if(remain[q]>0)
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					if(!visited[i+1][j+1][q] && !marked[i][j])
					{
						remain[q]--;
						search(i, j, q, d+1);
						remain[q]++;
					}
	
	marked[r][c]=false;
	visit(r+1, c+1, inp[r][c]);
	unvisit(r+1, c+1, k);
}

int main()
{
	freopen("wissqu.in", "r", stdin);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			cin >> (char&)inp[i][j];
			inp[i][j]-='A';
			visit(i+1, j+1, inp[i][j]);
		}
	fclose(stdin);
	
	for(int i=0;i<5;i++)
		remain[i]=3;
		
	freopen("wissqu.out", "w", stdout);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(!visited[i+1][j+1][3])
				search(i, j, 3, 0);
	cout << nsol << endl;
	fclose(stdout);
	return 0;
}

