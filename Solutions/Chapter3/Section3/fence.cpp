/*
ID:kadirce1
LANG:C++
PROG:fence
*/

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int adj[501][501];
int deg[501];
stack<int> visit;

void eulerian(int start)
{
	for(int i=0;i<501;i++)
		if(adj[start][i]!=0)
		{
			adj[start][i]--;
			adj[i][start]--;
			eulerian(i);
		}
	visit.push(start);
}

int main()
{
	ifstream inp("fence.in");
	ofstream oup("fence.out");
	
	int N,start=1;
	inp >> N;
	int s,e;
	for(int i=0;i<N;i++)
	{
		inp >> s >> e;
		adj[s][e]++;
		adj[e][s]++;
		deg[s]++;
		deg[e]++;
	}
	
	for(int i=0;i<501;i++)
		if(deg[i]%2==1)
		{
			start = i;
			break;
		}
		
	eulerian(start);
	while(!visit.empty())
	{
		oup << visit.top() << endl;
		visit.pop();
	}
	
	return 0;
}
