/*
ID:kadirce1
LANG:C++
PROG:nuggets
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

vector<int> packs;
set<int> avaibs;

int gcd(int a, int b)
{
	return a==0?b:gcd(b%a, a);
}

int main()
{
	ifstream inp("nuggets.in");
	ofstream oup("nuggets.out");
	
	int N,tmp,g=0;
	int minpack=0;
	int consect=0;
	inp >> N;
	for(int i=0;i<N;i++)
	{
		inp >> tmp;
		g=gcd(g, tmp);
		if(tmp==1)
		{
			oup << 0 << endl;
			return 0;
		}
		if(minpack>tmp || minpack==0)
			minpack=tmp;
		packs.push_back(tmp);
	}
	
	int last=0;
	if(g==1)
	{
		avaibs.insert(0);
		while(consect!=minpack)
		{
			int cur=*avaibs.begin();
			avaibs.erase(avaibs.begin());
			
			if(cur==last+1)
				consect++;
			else
				consect=0;
			last=cur;
			for(int i=0;i<N;i++)
				avaibs.insert(cur+packs[i]);
		}
		oup << last - minpack - 1 << endl;
	}
	else
		oup << 0 << endl;
	
	return 0;
}

