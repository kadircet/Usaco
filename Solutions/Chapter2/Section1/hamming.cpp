/*
ID: kadirce1
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int N,B,D;
set<int> result;

int hamming(int a, int b)
{
	int ndiff=0;
	a = a^b;
	for(int i=0;i<B;i++)
		if((a>>i)&1)
			ndiff++;
	return ndiff;
}

int main()
{
	ifstream inp("hamming.in");
	ofstream oup("hamming.out");
	bool valid = false;
	set<int>::iterator it;
	
	inp >> N >> B >> D;
	result.insert(0);
	N--;
	for(int i=1;i<(1<<B);i++)
	{
		if(N<=0)
			break;
		valid = true;
		for(it=result.begin();it!=result.end();it++)
			if(hamming(*it, i) < D)
			{
				valid = false;
				break;
			}
		if(valid)
		{
			result.insert(i);
			N--;
		}
	}
	N=0;
	for(it=result.begin();it!=result.end();it++)
	{
		if(N>0)
		{
			if(N%10==0)
				oup << endl;
			else
				oup << " ";
		}
		N++;
		oup << *it;
	}
	oup << endl;
	return 0;
}

