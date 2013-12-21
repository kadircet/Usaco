/*
ID:kadirce1
LANG:C++
PROG:inflate
*/

#include <iostream>
#include <fstream>
using namespace std;

struct prob
{
	int m, p;
};

int poss[10000+10];
int N,M;
prob probs[10001];

int main()
{
	ifstream inp("inflate.in");
	ofstream oup("inflate.out");

	inp >> M >> N;
	for(int i=0;i<N;i++)
		inp >> probs[i].p >> probs[i].m;

	for(int i=0;i<N;i++)
		for(int j=probs[i].m;j<=M;j++)
		{
			int cMax = poss[j-probs[i].m] + probs[i].p;
			if(cMax > poss[j])
				poss[j] = cMax;
		}

	oup << poss[M] << endl;	
	return 0;
}

