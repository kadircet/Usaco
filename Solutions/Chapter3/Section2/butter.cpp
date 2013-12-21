/*
ID:kadirce1
LANG:C++
PROG:butter
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct edge
{
	int start,to;
	int cost;
	
	bool operator<(const edge& e) const
	{
		return e.cost > cost;
	}
};

bool calc[801];
int dist[801][801];
int cows[501];
vector<edge> edges[801];
int N,P,E;

void sp(int start)
{
	if(calc[start])
		return;
	calc[start] = true;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > toVisit;
	for(int i=0;i<edges[start].size();i++)
		toVisit.push(pair<int, int>(edges[start][i].cost, edges[start][i].to));
	
	bool visited[801];
	for(int i=1;i<=P;i++)
		visited[i] = false;
	visited[start] = true;
	
	while(!toVisit.empty())
	{
		pair<int, int> p = toVisit.top(); toVisit.pop();
		edge e;e.to = p.second; e.cost = p.first;
		if(visited[e.to])
			continue;
		visited[e.to] = true;
		
		for(int i=0;i<edges[e.to].size();i++)
		{
			edge ed = edges[e.to][i];
			if(dist[start][ed.to] > dist[start][ed.start] + ed.cost)
				dist[start][ed.to] = dist[start][ed.start] + ed.cost;
			ed.cost = dist[start][ed.to];
			
			toVisit.push(pair<int, int>(ed.cost, ed.to));
		}
	}
}

int main()
{
	ifstream inp("butter.in");
	ofstream oup("butter.out");
	
	inp >> N >> P >> E;
	for(int i=0;i<N;i++)
		inp>>cows[i];
	
	for(int i=1;i<=P;i++)
	{
		for(int j=1;j<=P;j++)
			dist[i][j] = 1<<20;
		dist[i][i] = 0;
	}
	
	edge ed;
	int s,e,c;
	for(int i=0;i<E;i++)
	{
		inp >> s >> e >> c;
		dist[s][e] = dist[e][s] = c;
		ed.start = s;ed.to = e;ed.cost=c;
		edges[s].push_back(ed);
		ed.to = s;ed.start = e;
		edges[e].push_back(ed);
	}
	
	for(int i=0;i<N;i++)
		sp(cows[i]);
	
	int best=1<<20;
	int cost=0;
	for(int i=1;i<=P;i++)
	{
		cost=0;
		for(int j=0;j<N;j++)
		{
			if(cost>best)
				break;
			cost += dist[cows[j]][i];
		}
		if(best>cost)
			best = cost;
	}
	oup << best << endl;
	
	return 0;
}

