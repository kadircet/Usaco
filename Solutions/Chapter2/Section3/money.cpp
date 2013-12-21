/*
ID:kadirce1
LANG:C++
PROG:money
*/

#include <iostream>
#include <fstream>
#include <vector>
#define foreach(x, it) for(typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)
#define debug(x) cout << #x << "="; foreach((x), it) cout << *it << " "; cout << endl;
using namespace std;

int V,N;
vector<int> coins;
unsigned long long int DP[10001];

int main()
{
	ifstream inp("money.in");
	ofstream oup("money.out");
	DP[0] = 1;
	
	inp >> V >> N;
	int t;
	for(int i=0;i<V;i++)
	{
		inp >> t;
		coins.push_back(t);
	}
	for(int i=0;i<coins.size();i++)
		for(int j=coins[i];j<=N;j++)
			DP[j] += DP[j-coins[i]];
	
	oup << DP[N] << endl;
	
	return 0;
}

