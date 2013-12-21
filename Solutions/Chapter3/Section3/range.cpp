/*
ID:kadirce1
LANG:C++
PROG:range
*/

#include <iostream>
#include <fstream>
using namespace std;

int N;
bool map[251][251];
int places[251];
int poss[251][251];

void check(int r, int c, int n)
{
	if(r>0 && c>0)
		while(n<poss[r-1][c-1])
		{
			poss[r][c]=n;
			places[n++]++;
		}
	
	if(n+r>N || c+n>N)
		return;

	for(int i=0;i<n;i++)
		if(!map[r+n-1][c+i])
			return;
	
	for(int i=0;i<n;i++)
		if(!map[r+i][c+n-1])
			return;
	
	poss[r][c]=n;
	places[n]++;
	check(r,c,n+1);
}

int main()
{
	ifstream inp("range.in");
	ofstream oup("range.out");
	
	inp >> N;
	char c;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			inp >> c;
			map[i][j] = c=='1';
		}
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(map[i][j])
				check(i, j, 2);
	
	for(int i=2;i<=N;i++)
		if(places[i]!=0)
			oup << i << " " << places[i] << endl;
	
	return 0;
}

