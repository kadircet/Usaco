/*
ID:kadirce1
LANG:C++
PROG:maze1
*/

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct pos
{
	int row,col;
};

char maze[100*2+10][38*2+10];
int W,H;
pos exits[2];
int dist[100*2+10][38*2+10];
int deltaRow[] = {2,-2,0,0};
int deltaCol[] = {0,0,2,-2};

void bfs(pos start)
{
	bool visited[100*2+10][38*2+10];
	for(int i=0;i<=2*H+1;i++)
		for(int j=0;j<=2*W+1;j++)
			visited[i+2][j+2] = false;
	
	queue<pos> toVisit;
	toVisit.push(start);
	dist[start.row+2][start.col+2] = 0;
	while(!toVisit.empty())
	{
		pos cur = toVisit.front();toVisit.pop();
		if(visited[cur.row+2][cur.col+2])
			continue;
		visited[cur.row+2][cur.col+2] = true;
		
		pos ap;
		for(int i=0;i<4;i++)
		{
			int ar = cur.row+deltaRow[i], ac=cur.col+deltaCol[i];
			if(ar>0 && ac>0 && ar<2*H+3 && ac<2*W+3)
			{
				if(maze[(ar+cur.row)/2][(ac+cur.col)/2] == ' ')
				{
					ap.row = ar;ap.col = ac;
					toVisit.push(ap);
					if(dist[ap.row+2][ap.col+2] > dist[cur.row+2][cur.col+2]+1 || dist[ap.row+2][ap.col+2]==0)
						dist[ap.row+2][ap.col+2] = dist[cur.row+2][cur.col+2]+1;
				}
			}
		}
	}
}

int main()
{
	ifstream inp("maze1.in");
	ofstream oup("maze1.out");
	int e=0;
	
	inp >> W >> H;
	for(int i=0;i<2*H+1;i++)
		for(int j=0;j<2*W+1;j++)
		{
			inp.get(maze[i][j]);
			if(maze[i][j] == '\n')
				inp.get(maze[i][j]);
			if(i==2*H || i==0)
				if(maze[i][j] == ' ')
				{
					exits[e].row = i==0?i-1:i+1;
					exits[e++].col = j;
				}
			if(j==2*W || j==0)
				if(maze[i][j] == ' ')
				{
					exits[e].row = i;
					exits[e++].col = j==0?j-1:j+1;
				}
		}
	
	for(int i=0;i<2;i++)
		bfs(exits[i]);
	int m=0;
	for(int i=0;i<2*H+1;i++)
		for(int j=0;j<2*W+1;j++)
			if(dist[i+2][j+2] > m)
				m=dist[i+2][j+2];
	oup << m << endl;
	
	return 0;
}
