/*
ID:kadirce1
LANG:C++
PROG:snail
*/
#include <iostream>
#include <cstdio>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool map[125][125];
bool vis[125][125];
int best;
int N,B;

bool isOk(int r, int c)
{
	return r>=0 && c>=0 && r<N && c<N && !map[r][c] && !vis[r][c];
}

void search(int r, int c, int num)
{
	best=max(best, num);
	
	if(r<0 || c<0 || r>=N || c>=N)
		return;
	
	for(int i=0;i<4;i++)
	{
		if(isOk(r+dy[i], c+dx[i]))
		{
			vis[r][c]=true;
			int tr=r+dy[i], tc=c+dx[i];
			while(isOk(tr, tc))
				tr+=dy[i], tc+=dx[i];
			int ttr=tr-dy[i], ttc=tc-dx[i];
			while(ttr!=r || ttc!=c)
			{
				vis[ttr][ttc]=true;
				num++;
				ttr-=dy[i], ttc-=dx[i];
			}
			best=max(best, num);
			if(tr<0 || tc<0 || tr>=N || tc>=N || !vis[tr][tc])
				search(tr-dy[i], tc-dx[i], num);
			tr-=dy[i], tc-=dx[i];
			while(tr!=r || tc!=c)
			{
				vis[tr][tc]=false;
				num--;
				tr-=dy[i], tc-=dx[i];
			}
			vis[r][c]=false;
		}
	}
}

int main()
{
	freopen("snail.in", "r", stdin);
	cin >> N >> B;
	char c;
	int r;
	for(int i=0;i<B;i++)
	{
		cin >> c >> r;
		map[r-1][c-'A']=true;
	}
	fclose(stdin);
	
	search(0,0,1);
	
	freopen("snail.out", "w", stdout);
	cout << best << endl;
	fclose(stdout);
	
	return 0;
}

