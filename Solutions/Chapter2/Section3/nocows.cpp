/*
ID:kadirce1
LANG:C++
PROG:nocows
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int N,K;
int C[201][101];

int main()
{
	ifstream inp("nocows.in");
	ofstream oup("nocows.out");
	
	inp >> N >> K;
	C[1][1] = 1;
	for(int i=3;i<=N;i+=2)
		for(int j=2;j<=K;j++)
		{
			for(int k=1;k<=i-2;k+=2)
			{
				for(int d=1;d<j-1;d++)
				{
					C[i][j] += C[k][d] * C[i-k-1][j-1]+
								C[k][j-1] * C[i-k-1][d];
					C[i][j]%=9901;
				}
				C[i][j] += C[k][j-1] * C[i-k-1][j-1];
				C[i][j]%=9901;
			}
		}
	oup << C[N][K] << endl;
	
	return 0;
}

