/*
ID:kadirce1
LANG:C++
PROG:camelot
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
#define INF (1<<6)
using namespace std;

struct point
{
	int y,x;
	bool king;
	
	bool operator<(const point& p) const
	{
		if(y==p.y && x==p.y)
			return king;
		if(y==p.y)
			return x<p.x;
		return y<p.y;
	}
};

int nrow,ncol;
int dist[31][31][2];
int kcost[31][31];
int cost[31][31];

point ck;
point king;
int kingDist(int r, int c)
{
	return max(abs(r-king.y), abs(c-king.x));
}

void sp()
{
	bool visited[31][31][2];
	memset(visited, false, 31*31*2*sizeof(bool));
	dist[ck.x][ck.y][0] = 0;
	dist[ck.x][ck.y][1] = kingDist(ck.y, ck.x);
	priority_queue<pair<int, point>, vector<pair<int, point> >, greater<pair<int, point> > > toVisit;
	ck.king=false;
	toVisit.push(pair<int, point>(0, ck));
	ck.king=true;
	toVisit.push(pair<int, point>(kingDist(ck.y, ck.x), ck));
	
	while(!toVisit.empty())
	{
		point cp = toVisit.top().second;
		int d = toVisit.top().first;
		toVisit.pop();
		
		int y=cp.y, x=cp.x;
		int kflag = cp.king;
		
		if(visited[cp.x][cp.y][kflag])
			continue;
		visited[cp.x][cp.y][kflag] = true;
		
		if (y > 0)
		{
			if (x > 1)
				if (dist[x-2][y-1][kflag] > d+1)
				{
					dist[x-2][y-1][kflag] = d+1;
					toVisit.push(pair<int, point>(d+1, (point){y-1, x-2, kflag}));
				}
			if (x < ncol-2)
			{
				if (dist[x+2][y-1][kflag] > d+1)
				{
					dist[x+2][y-1][kflag] = d+1;
					toVisit.push(pair<int, point>(d+1, (point){y-1, x+2, kflag}));
				}
			}
			if (y > 1)
			{
				if (x > 0)
					if (dist[x-1][y-2][kflag] > d+1)
					{
						dist[x-1][y-2][kflag] = d+1;
						toVisit.push(pair<int, point>(d+1, (point){y-2, x-1, kflag}));
					}
				if (x < ncol-1)
					if (dist[x+1][y-2][kflag] > d+1)
					{
						dist[x+1][y-2][kflag] = d+1;
						toVisit.push(pair<int, point>(d+1, (point){y-2, x+1, kflag}));
					}
			}
		}
		if (y < nrow-1)
		{
		    if (x > 1)
		        if (dist[x-2][y+1][kflag] > d+1)
		        {
		            dist[x-2][y+1][kflag] = d+1;
		            toVisit.push(pair<int, point>(d+1, (point){y+1, x-2, kflag}));
		        }
		    if (x < ncol-2)
		    {
				if (dist[x+2][y+1][kflag] > d+1)
				{
					dist[x+2][y+1][kflag] = d+1;
					toVisit.push(pair<int, point>(d+1, (point){y+1, x+2, kflag}));
				}
		    }
		    if (y < nrow-2)
		    {
		        if (x > 0)
		            if (dist[x-1][y+2][kflag] > d+1)
		            {
		                dist[x-1][y+2][kflag] = d+1;
		                toVisit.push(pair<int, point>(d+1, (point){y+2, x-1, kflag}));
		            }
		        if (x < ncol-1)
		            if (dist[x+1][y+2][kflag] > d+1)
		            {
		                dist[x+1][y+2][kflag] = d+1;
		                toVisit.push(pair<int, point>(d+1, (point){y+2, x+1, kflag}));
		            }
		    }
		}
		
		if(kflag==0 && dist[x][y][1] > d + kingDist(y, x))
		{
			dist[x][y][1] = d + kingDist(y, x);
			toVisit.push(pair<int, point>(dist[x][y][1], (point){y, x, true}));
		}
	}
}

int main()
{
	ifstream inp("camelot.in");
	ofstream oup("camelot.out");
	
	inp >> nrow >> ncol;
	char col;
	int row;
	inp >> col >> row;
	king.y=row-1; king.x=col-'A';
	
	for(int i=0;i<ncol;i++)
		for(int j=0;j<nrow;j++)
			kcost[i][j] = kingDist(j, i);
	while(true)
	{
		inp >> col >> row;
		if(!inp.good())
			break;
		ck.y=row-1;ck.x=col-'A';
		
		memset(dist, INF, 31*31*2*sizeof(int));
		sp();
		for(int i=0;i<ncol;i++)
			for(int j=0;j<nrow;j++)
			{
				cost[i][j] += dist[i][j][0];
		
				if(dist[i][j][1] - dist[i][j][0] < kcost[i][j])
					kcost[i][j] = dist[i][j][1] - dist[i][j][0];
			}
	}
	
	int best=kcost[0][0] + cost[0][0];
	for(int i=0;i<ncol;i++)
		for(int j=0;j<nrow;j++)
			best = min(best, kcost[i][j] + cost[i][j]);
	oup << best << endl;
	
	return 0;
}
