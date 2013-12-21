/*
ID:kadirce1
LANG:C++
PROG:ditch
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N,M;
int cap[205][205];
int flow[205];
int prev[205];
bool visited[205];

int maxFlow(int source, int sink)
{
	int maxf=0, maxl=0;
	int totf=0;
	while(true)
	{
		for(int i=0;i<M;i++)
		{
			visited[i] = false;
			flow[i] = 0;
			prev[i] = -1;
		}
		flow[source] = ~(1<<31);

		while(true)
		{
			maxf=0; maxl=-1;
			for(int i=0;i<M;i++)
			{
				if(flow[i] > maxf && !visited[i])
				{
					maxf=flow[i];
					maxl=i;
				}
			}
			if(maxl==-1 || maxl==sink)
				break;
			
			visited[maxl] = true;
			
			for(int i=0;i<M;i++)
			{
				if(min(maxf, cap[maxl][i])>flow[i])
				{
					flow[i] = min(maxf, cap[maxl][i]);
					prev[i] = maxl;
				}
			}
		}
		
		if(maxl==-1)
			break;
		
		int pathCap = flow[sink];
		totf += pathCap;
		
		int cur = sink;
		while(cur!=source)
		{
			cout << cur << " ";
			int next = prev[cur];
			cap[next][cur] -= pathCap;
			cap[cur][next] += pathCap;
			cur=next;
		}
		cout << cur << endl;
	}
	return totf;
}

int main()
{
	ifstream inp("ditch.in");
	ofstream oup("ditch.out");
	
	inp >> N >> M;
	
	int f,t,c;
	for(int i=0;i<N;i++)
	{
		inp >> f >> t >> c;
		cap[f-1][t-1] += c;
	}
		
	oup << maxFlow(0, M-1) << endl;
	
	return 0;
}

