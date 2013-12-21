/*
ID: kadirce1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

class rational
{
	public:
		int num;
		int denum;

		bool operator<(const rational r2) const
		{
			rational r1 = *this;
			return r1.num*r2.denum<r1.denum*r2.num;
		}
};

int gcd(int a, int b)
{
	return a==0?b:gcd(b%a, a);
}

int main()
{
	ifstream inp("frac1.in");
	ofstream oup("frac1.out");
	
	int N;
	cin >> N;
	set<rational> fracts;
	rational r;
	r.num = 0; r.denum = 1;
	fracts.insert(r);
	r.num = 1;
	fracts.insert(r);
	for(int i=1;i<N;i++)
		for(int j=i;j<=N;j++)
		{
			if(gcd(i,j)==1)
			{
				r.num = i;
				r.denum = j;
				fracts.insert(r);
			}
		}
	
	set<rational, rational>::iterator it;
	for(it=fracts.begin();it!=fracts.end();it++)
		oup << it->num << "/" << it->denum << endl;
	
	return 0;
}

