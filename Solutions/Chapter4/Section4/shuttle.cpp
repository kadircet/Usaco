/*
ID:kadirce1
PROG:shuttle
LANG:C++
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> sol;
void solve(int d, int N)
{
	if(d==1)
	{
		sol.push_back(N);
		sol.push_back(N+2);
		return;
	}
	solve(d-1, N);
	if(d%2==0)
	{
		//cout << N+d+1 << ' ';
		for(int i=0;i<=d;i++)
			sol.push_back(N+d+1-2*i);
	}
	else
	{
		for(int i=0;i<=d;i++)
			sol.push_back(N-d+1+2*i);
	}
}

void finish(int d, int N)
{
	if(d<1)
		return;
	if(d%2==1)
	{
		for(int i=0;i<d;i++)
			sol.push_back(N+d-2*i);
	}
	else
	{
		for(int i=1;i<=d;i++)
			sol.push_back(N-d+2*i);
	}
	finish(d-1, N);
}

int main()
{
	int N;
	
	freopen("shuttle.in", "r", stdin);
	cin >> N;
	fclose(stdin);
	
	solve(N, N);
	finish(N, N);
	
	freopen("shuttle.out", "w", stdout);
	cout << sol[0];
	for(int i=1;i<sol.size();i++)
		if(i%20==0)
			cout << endl << sol[i];
		else
			cout << ' ' << sol[i];
	cout << endl;
	fclose(stdout);
	
	return 0;
}

