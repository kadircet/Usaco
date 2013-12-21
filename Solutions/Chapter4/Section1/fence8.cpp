/*
ID:kadirce1
LANG:C++
PROG:fence8
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> boards;
vector<int> rails;

int sum[1024], tot;
int N,R;
int maxwaste;

bool tryRails(int K, int last)
{
	if(K==0)
		return true;
		
	if(maxwaste<0)
		return false;
	
	bool retVal = false;
	bool wasted=false;
	for(int i=0;i<boards.size();i++)
	{
		if(boards[i]==rails[K-1])
		{
			boards[i] -= rails[K-1];
			retVal = tryRails(K-1, i);
			boards[i] += rails[K-1];
			return retVal;
		}
	}
	if(last==-1)
		last=0;
	else if(rails[K]!=rails[K-1])
		last=0;
	for(int i=last;i<boards.size();i++)
	{
		wasted=false;
		if(boards[i]>rails[K-1])
		{
			boards[i] -= rails[K-1];
			if(boards[i]<rails[0])
			{
				maxwaste-=boards[i];
				wasted=true;
			}
			retVal = retVal || tryRails(K-1, i);
			if(wasted)
				maxwaste+=boards[i];
			boards[i] += rails[K-1];
		}
		if(retVal)
			break;
	}
	return retVal;
}

int main()
{
	ifstream inp("fence8.in");
	ofstream oup("fence8.out");
	
	int b;
	inp >> N;
	for(int i=0;i<N;i++)
	{
		inp >> b;
		boards.push_back(b);
		tot+=b;
	}
	inp >> R;
	for(int i=0;i<R;i++)
	{
		inp >> b;
		rails.push_back(b);
	}
	sort(rails.begin(), rails.end());
	sum[0]=rails[0];
	for(int i=1;i<rails.size();i++)
		sum[i] = rails[i] + sum[i-1];
	
	int u=R, l=0;
	while(u>=l)
	{
		int k=(u+l)/2;
		maxwaste = tot - sum[k-1];
		if(tryRails(k, -1))
			l=k+1;
		else
			u=k-1;
	}
	oup << l-1 << endl;
	
	return 0;
}

