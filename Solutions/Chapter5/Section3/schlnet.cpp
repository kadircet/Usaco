/*
ID:kadirce1
LANG:C++
PROG:schlnet
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N;
bool connected[101][101];
int out[101], ind[101];
bool map[101][101];
int comp[101];
int indcomp[101], outcomp[101];

int main()
{
	memset(comp, -1, sizeof(comp));
	freopen("schlnet.in", "r", stdin);
	cin >> N;
	for(int i=0;i<N;i++)
	{
		//connected[i][i]=true;
		int w;
		cin >> w;
		while(w!=0)
		{
			connected[i][w-1]=true;
			map[i][w-1]=true;
			out[i]++;
			ind[w-1]--;
			cin >> w;
		}
	}
	fclose(stdin);
	
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(connected[i][k] && connected[k][j])
					connected[i][j] = true;
	
	for(int i=0;i<N;i++)
	{
		if(comp[i]==-1)
			comp[i]=i;
		
		for(int j=0;j<N;j++)
			if(connected[i][j] && connected[j][i])
				comp[j]=comp[i];
	}
	
	int A=0,B=0;
	int ncomp=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(comp[i]!=comp[j])
				if(connected[i][j])
					indcomp[comp[j]]++, outcomp[comp[i]]++;
	for(int i=0;i<N;i++)
		if(comp[i]==i)
		{
			ncomp++;
			if(indcomp[i]==0)
				A++;
			if(outcomp[i]==0)
				B++;
		}
		
	B=max(A,B);
	if(ncomp==1)A=1,B=0;
	
	freopen("schlnet.out", "w", stdout);
	cout << A << endl;
	cout << B << endl;
	fclose(stdout);
	return 0;
}

