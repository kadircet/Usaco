/*
ID:kadirce1
LANG:C++
PROG:stall4
*/

#include <iostream>
#include <fstream>
using namespace std;

int N,M;
bool visited[405];
bool cap[405][405];
int prev[405];
int flow[405];

int max_match(int source, int sink)
{
	int maxf, maxl;
	int totm=0;
	while(true)
	{
		for(int i=0;i<N+M+2;i++)
		{
			visited[i] = false;
			flow[i] = 0;
			prev[i] = -1;
		}
		flow[source] = 2;
		
		while(true)
		{
			maxl=-1;maxf=0;
			for(int i=0;i<N+M+2;i++)
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
				
			for(int i=start;i<N+M+2;i++)
			{
				if(cap[maxl][i])
					if(maxf > flow[i])
					{
						flow[i] = 1;
						prev[i] = maxl;
					}
			}
		}
		
		if(maxl==-1)
			break;
		
		int pathCap = flow[sink];
		totm += pathCap;
		int cur=sink;
		while(cur!=source)
		{
			int next=prev[cur];
			cap[next][cur] = false;
			cap[cur][next] = true;
			cur=next;
		}
	}
	return totm;
}

int main()
{
	ifstream inp("stall4.in");
	ofstream oup("stall4.out");
	
	inp >> N >> M;
	int n,t;
	for(int i=0;i<N;i++)
	{
		inp >> n;
		cap[0][i+1] = true;
		for(int j=0;j<n;j++)
		{
			inp >> t;
			cap[i+1][N+t] = true;
		}
	}
	for(int i=N+1;i<N+M+1;i++)
		cap[i][N+M+1]=true;
	
	oup << max_match(0, N+M+1) << endl;
	
	return 0;
}

