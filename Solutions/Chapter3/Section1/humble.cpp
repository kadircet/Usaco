/*
ID:kadirce1
LANG:C++
PROG:humble
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int N,K;
vector<int> hummble;
vector<int> primes;
int lastH[101];

int main()
{
	ifstream inp("humble.in");
	ofstream oup("humble.out");
	
	inp >> K >> N;
	int p;
	for(int i=0;i<K;i++)
	{
		inp >> p;
		primes.push_back(p);
	}
	
	hummble.push_back(1);
	for(int i=0;i<N;i++)
	{
		int min=0,minp=0;
		for(int j=0;j<K;j++)
		{
			int k=lastH[j];
			int last = hummble[k];
			while(last*primes[j] <= hummble[i])
				last = hummble[++lastH[j]];
			if(min>last*primes[j] || min==0)
			{
				min=primes[j]*last;
				minp=j;
			}
		}
		hummble.push_back(min);
		lastH[minp]++;
		//cout << min << " " << primes[minp] << endl;
	}
	oup << hummble[N] << endl;
	
	return 0;
}

