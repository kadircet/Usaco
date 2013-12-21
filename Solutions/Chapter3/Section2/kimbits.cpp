/*
ID:kadirce1
LANG:C++
PROG:kimbits
*/

#include <iostream>
#include <fstream>
using namespace std;

unsigned int N,L,K;
int comb[33][33];
int C[33][33];

string print(unsigned int n)
{
	if(n<=1)
		return "";
	return print(n/2) + (char)(n%2 + '0');
}

int main()
{
	ifstream inp("kimbits.in");
	ofstream oup("kimbits.out");
	
	inp >> N >> L >> K;
	K--;
	
	for(int i=1;i<=N;i++)
		for(int j=0;j<=i;j++)
		{
			if(j==0 || j==i)
				comb[i][j] = 1;
			else if(j==1)
				comb[i][j] = i;
			else
				comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
		}
		
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=j;k++)
				C[i][j] += comb[i][k];
			//cout << i << " " << j << " " << C[i][j] << endl;
		}
		for(int j=i+1;j<=L;j++)
		{
			C[i][j] = C[i][j-1];
			//cout << i << " " << j << " " << C[i][j] << endl;
		}
	}
				
	
	int used=0;
	unsigned int mask = 1<<N, numb=1<<N;
	for(int i=0;i<N;i++)
	{
		mask>>=1;
		if(K==0)
			break;
		if(K>=C[N-i-1][L-used])
		{
			numb |= mask;
			K-=C[N-i-1][L-used++];
		}
	}
	oup << print(numb) << endl;
	
	return 0;
}

