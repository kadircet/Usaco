/*
ID:kadirce1
LANG:C++
PROG:zerosum
*/

#include <iostream>
#include <fstream>
#include <vector>
#define foreach(x, it) for(typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)
#define debug(x) cout << #x << "="; foreach((x), it) cout << *it << " "; cout << endl;
using namespace std;

string ops = " +-";
string cops = "--------";
int N;

void checkSeq(ostream &os)
{
	int sum=0;
	int n=2;
	vector<int> numbers;
	numbers.push_back(1);
	for(int i=0;i<N-1;i++)
	{
		int l = numbers.back();
		if(cops[i] == ' ')
		{
			l*=10;
			l+=i+2;
			numbers.pop_back();
			numbers.push_back(l);
		}
		else
			numbers.push_back(i+2);
	}
	int op=1;
	sum = numbers[0];
	for(int i=0;i<N-1;i++)
	{
		if(cops[i]==' ')
			continue;
		if(cops[i]=='+')
			sum += numbers[op++];
		else if(cops[i] == '-')
			sum -= numbers[op++];
	}
	if(sum == 0)
	{
		for(int i=0;i<N-1;i++)
			os << i+1 << cops[i];
		os << N << endl;
	}
}

void solve(int pos, ostream& os)
{
	if(pos==N-1)
	{
		checkSeq(os);
		return;
	}
	for(int i=0;i<3;i++)
	{
		cops[pos] = ops[i];
		solve(pos+1, os);
	}
}

int main()
{
	ifstream inp("zerosum.in");
	ofstream oup("zerosum.out");
	
	inp >> N;
	solve(0, oup);
	
	return 0;
}

