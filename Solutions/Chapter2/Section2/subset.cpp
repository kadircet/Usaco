/*
ID:kadirce1
LANG:C++
PROG:subset
*/

#include <iostream>
#include <fstream>
using namespace std;

int N;
long long int C[39*20+5];

int main()
{
	ifstream inp("subset.in");
	ofstream oup("subset.out");
	
	inp >> N;
	if(N*(N+1)%4!=0)
		oup << 0 << endl;
	else
	{
		C[0] = 1;
		for(int i=1;i<=N;i++)
			for(int j=N*(N+1)/4;j>=0;j--)
				if(C[j]>0)
					C[i+j] += C[j];
	
		oup << C[N*(N+1)/4]/2 << endl;
	}
	
	return 0;
}

