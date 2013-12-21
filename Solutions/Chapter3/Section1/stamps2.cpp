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
int best[201];

int main()
{
	ifstream inp("stamps.in");
	ofstream oup("stamps.out");
	
	inp >> K >> N;
	int s;
	for(int i=0;i<N;i++)
	{
		inp >> s;
		stamps.push_back(s);
	}
	
	sort(stamps.begin(), stamps.end());
	
	int last=-1;
	int maxA=0;
	best[0] = 0;
	while(last!=maxA)
	{
		last=maxA;
		for(int i=1;i<=K;i++)
		{
			int curMax = best[i-1];
			for(int j=N-1;j>=0;j--)
			{
				int q = curMax + stamps[j];
				if(q<=maxA+1)
				{
					curMax = q;
					break;
				}
			}
			best[i] = curMax;
			cout << curMax << " ";
			if(curMax>maxA)
				maxA=curMax;
		}
		cout << endl;
	}
	oup << maxA << endl;
	
	return 0;
}

