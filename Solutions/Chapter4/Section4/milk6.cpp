/*
ID:kadirce1
PROG:milk6
LANG:C++
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int N,M;
struct edge
{
	int from,to;
	unsigned long long cap;
	vector<int> idx1;
	bool operator<(const edge& rhs) const
	{
		return cap<rhs.cap;
	}
};

vector<edge> edges;
unsigned long long cap[33][33];

unsigned long long maxFlow(int s, int t)
{
	unsigned long long maxf=0,totf=0;
	int maxl=0;
	
	bool visited[33];
	int prev[33];
	unsigned long long flow[33];
	while(true)
	{
		for(int i=0;i<N;i++)
			visited[i]=false, prev[i]=-1, flow[i]=0;
		flow[s]=1LL<<62;
		
		while(true)
		{
			maxf=0, maxl=-1;
			for(int i=0;i<N;i++)
				if(flow[i]>maxf && !visited[i])
					maxf=flow[i], maxl=i;
			
			if(maxl==-1 || maxl==t)
				break;
			
			visited[maxl]=true;
			for(int i=0;i<N;i++)
				if(min(maxf, cap[maxl][i]) > flow[i])
					flow[i]=min(maxf, cap[maxl][i]), prev[i] = maxl;
		}
		
		if(maxl==-1)
			break;
		
		unsigned long long pCap=flow[t];
		totf+=pCap;
		int cur=t;
		while(cur!=s)
		{
			int next=prev[cur];
			cap[next][cur] -= pCap;
			cap[cur][next] += pCap;
			cur=next;
		}
	}
	
	return totf;
}

int main()
{
	freopen("milk6.in", "r", stdin);
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		int f,t,c;
		cin >> f >> t >> c;
		edge e;
		e.from=f-1, e.to=t-1, e.cap=c*1001LL+1;
		e.idx1.push_back(i+1);
		cap[f-1][t-1]+=e.cap;
		bool found=false;
		for(int j=0;j<edges.size();j++)
			if(edges[j].from==e.from && edges[j].to==e.to)
			{
				found=true;
				edges[j].cap+=e.cap, edges[j].idx1.push_back(i+1);
				break;
			}
		if(!found)
			edges.push_back(e);
	}
	fclose(stdin);
	
	vector<int> sol;
	unsigned long long res=0;
	sort(edges.begin(), edges.end());
	
	unsigned long long mFlow=maxFlow(0, N-1);
	for(int i=0;i<edges.size();i++)
	{
		for(int j=0;j<edges.size();j++)
		{
			edge e = edges[j];
			cap[e.from][e.to]=e.cap;
		}
		edge e = edges[i];
		cap[e.from][e.to]=0;
		
		unsigned long long cFlow=maxFlow(0, N-1);
		if(cFlow+e.cap==mFlow)
		{
			res += e.cap;
			mFlow=cFlow;
			edges[i].cap = 0;
			for(int j=0;j<e.idx1.size();j++)
				sol.push_back(e.idx1[j]);
		}
	}
	sort(sol.begin(), sol.end());
	
	freopen("milk6.out", "w", stdout);
	res -=sol.size();
	res /=1001;
	cout << res << ' ' << sol.size() << endl;
	for(int i=0;i<sol.size();i++)
		cout << sol[i] << endl;
	fclose(stdout);
	
	return 0;
}

