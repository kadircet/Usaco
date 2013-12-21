/*
ID:kadirce1
LANG:C++
PROG:cowtour
*/

#include <iostream>
#include <fstream>
#include <cmath>
#define INF 1<<30
using namespace std;

struct point
{
	int x, y;
};

double dist[151][151];
bool adj[151][151];
point nodes[151];
int component[151];
double diameter[151];
double further[151];
int N;

void dfs(int start, int comp)
{
	if(component[start]!=-1)
		return;
	component[start] = comp;
	for(int i=0;i<N;i++)
		if(adj[start][i])
			dfs(i, comp);
}

double d(point& p1, point& p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int main()
{
	ifstream inp("cowtour.in");
	ofstream oup("cowtour.out");
	
	inp >> N;
	int x,y;
	for(int i=0;i<N;i++)
	{
		component[i] = -1;
		inp >> nodes[i].x >> nodes[i].y;
		for(int j=0;j<N;j++)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}
	
	char a;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			inp >> a;
			adj[i][j] = a=='1';
			if(adj[i][j])
				dist[i][j] = d(nodes[i], nodes[j]);
		}
	
	int nc=0;
	for(int i=0;i<N;i++)
	{
		if(component[i] == -1)
			dfs(i,nc++);
	}
	
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j]=dist[i][k] + dist[k][j];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(component[i] == component[j])
				further[i] = max(further[i], dist[i][j]);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(component[i]==component[j] && diameter[component[i]] < dist[i][j])
				diameter[component[i]] = dist[i][j];
	
	double minField = 0;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(component[i]!=component[j])
			{
				double curDia=max(diameter[component[i]], diameter[component[j]]);
				curDia = max(curDia, further[i] + further[j] + d(nodes[i], nodes[j]));
				if(minField == 0)
					minField = curDia;
				minField = min(minField, curDia);
			}
		}
	
	oup.setf(ios::fixed);
	oup.precision(6);
	oup << minField << endl;
	
	return 0;
}

