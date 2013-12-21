/*
ID:kadirce1
LANG:C++
PROG:stamps
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> stamps;
int N,K;
int poss[2000001];

int main()
{
	ifstream inp("stamps.in");
	ofstream oup("stamps.out");
	
	inp >> K >> N;
	int s;
	int smax=0;
	for(int i=0;i<N;i++)
	{
		inp >> s;
		stamps.push_back(s);
		if(s>smax)
			smax=s;
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=smax*(K-1);j++)
		{
			if(j==0 || poss[j]!=0)
				if(poss[j+stamps[i]]>poss[j]+1 || poss[j+stamps[i]]==0)
					poss[j+stamps[i]]=poss[j]+1;
		}
	}
	int i;
	for(i=1;i<=smax*K && poss[i]!=0 && poss[i]<=K;i++);
	oup << (i==1?1:i-1) << endl;
	
	return 0;
}
