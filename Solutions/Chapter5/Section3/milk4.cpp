/*
ID:kadirce1
LANG:C++
PROG:milk4
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int Q;
vector<int> P;
int dp[20001];
int lused[20001];
int nused[20001];

bool prior(int x, int y)
{
	while(x>0 && y>0)
	{
		if(P[lused[x]]!=P[lused[y]])
			return P[lused[x]]<P[lused[y]];
		
		x-=P[lused[x]]*nused[x];
		y-=P[lused[y]]*nused[y];
	}
	return x!=0;
}

int main()
{
	int n;
	freopen("milk4.in", "r", stdin);
	cin >> Q >> n;
	P.resize(n);
	for(int i=0;i<n;i++)
		cin >> P[i];
	fclose(stdin);
	
	sort(P.begin(), P.end());
	for(int i=1;i<=Q;i++)
		dp[i]=1<<30;
	
	for(int i=n-1;i>=0;i--)
	{
		int tlused[20001], tdp[20001], tnused[20001];
		for(int j=0;j<=Q;j++)
		{
			tdp[j]=dp[j];
			tlused[j]=lused[j];
			tnused[j]=nused[j];
		}
		for(int j=0;j+P[i]<=Q;j++)
		{
			if(tdp[j]<1<<30)
			{
				if(tlused[j]==i)
				{
					tlused[j+P[i]]=i;
					tdp[j+P[i]]=tdp[j];
					tnused[j+P[i]]=tnused[j]+1;
				}
				else
				{
					tlused[j+P[i]]=i;
					tdp[j+P[i]]=tdp[j]+1;
					tnused[j+P[i]]=1;
				}
			
				if(dp[j]+1<tdp[j+P[i]] || (dp[j]+1==tdp[j+P[i]] && prior(j, j+P[i]-tnused[j+P[i]]*P[i])))
				{
					tdp[j+P[i]] = dp[j]+1;
					tnused[j+P[i]]=1;
				}
			}
		}
		for(int j=0;j<=Q;j++)
		{
			if(tdp[j]<=dp[j])
			{
				dp[j]=tdp[j];
				lused[j]=tlused[j];
				nused[j]=tnused[j];
			}
		}
		
	}
	
	vector<int> res;
	while(Q>0)
	{
		res.push_back(lused[Q]);
		Q-=P[lused[Q]]*nused[Q];
	}
	
	freopen("milk4.out", "w", stdout);
	cout << res.size();
	for(int i=0;i<res.size();i++)
		cout << ' ' << P[res[i]];
	cout << endl;
	fclose(stdout);
	
	return 0;
}

