/*
ID:kadirce1
LANG:C++
PROG:fence6
*/

#include <iostream>
#include <fstream>
#include <set>
#include <cstring>
using namespace std;

int N, nodes;
int edges[202][8];
int nadj[202];
int length[100];
int adj[202][8];
int dist[202];

void shortest(int start)
{
	bool visited[202];
	for(int i=0;i<202;i++)visited[i] = false;
	for(int i=0;i<202;i++)dist[i] = 1 << 25;
	dist[start] = 0;
	set<pair<int, int> > toVisit;
	toVisit.insert(pair<int, int>(0, start));
	while(!toVisit.empty())
	{
		pair<int, int> cur = *toVisit.begin();
		toVisit.erase(toVisit.begin());
		
		int cost = cur.first, node = cur.second;
		if(visited[node])
			continue;
		visited[node] = true;
		
		for(int i=0;i<nadj[node];i++)
		{
			int s = adj[node][i];
			if(dist[s]>cost)
			{
				dist[s] = cost;
				toVisit.insert(pair<int, int>(cost, s));
			}
		}
		cost += length[node/2];
		node ^= 1;
		if(dist[node] > cost)
		{
			dist[node] = cost;
			toVisit.insert(pair<int, int>(cost, node));
		}
	}
}

int main()
{
	ifstream inp("fence6.in");
	ofstream oup("fence6.out");
	
	int s, l, n1, n2, as;
	inp >> N;
	nodes = 2*N;
	for(int i=0;i<N;i++)
	{
		inp >> s >> l >> n1 >> n2;
		s--;
		length[s] = l;
		nadj[2*s] = n1;
		nadj[2*s+1] = n2;
		for(int j=0;j<n1;j++)
		{
			inp >> as;
			edges[2*s][j] = as-1;
		}
		for(int j=0;j<n2;j++)
		{
			inp >> as;
			edges[2*s+1][j] = as-1;
		}
	}
	
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nadj[i];j++)
		{
			s = i/2;
			as = edges[i][j]*2;
			bool found=false;
			for(int k=0;k<nadj[as];k++)
				if(edges[as][k] == s)
				{
					found = true;
					break;
				}
			if(!found)
				as++;
			adj[i][j] = as;
		}
	}
	
	int best=1<<25;
	for(int i=0;i<N;i++)
	{
		int l = length[i];
		length[i] = 1<<25;
		shortest(2*i);
		if(dist[2*i+1] + l < best)
			best = dist[2*i+1] + l;
	}
	oup << best << endl;
	
	return 0;
}

