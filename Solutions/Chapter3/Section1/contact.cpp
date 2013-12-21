/*
ID:kadirce1
LANG:C++
PROG:contact
*/

#include <iostream>
#include <fstream>
#include <set>
#include <utility>
using namespace std;

int A,B,N;
int pattern=1;
int count[1<<13];

string print(int n)
{
	if(n<=1)
		return "";
	return print(n/2) + (char)(n%2 + '0');
}

struct patt
{
	int first;
	string second;
	
	bool operator<(const patt& p) const
	{
		if(p.first==first)
		{
			if(p.second.size()==second.size())
				return second < p.second;
			return second.size() < p.second.size();
		}
		return p.first < first;
	}
};

set<patt> patts;

int main()
{
	ifstream inp("contact.in");
	ofstream oup("contact.out");
	
	int q=0;
	inp >> A >> B >> N;
	char d;
	inp >> d;
	while(inp.good())
	{
		pattern &= (1<<B)-1;
		pattern <<=1;
		if(d=='0')
			pattern &= ~1;
		else
			pattern |= 1;
		if(q<B)q++;
		
		int mask=1;
		for(int i=0;i<A;i++)
			mask = mask<<1 | 1;
		for(int i=0;q>=A && A+i<=q;i++)
		{
			int test=pattern & mask;
			test |= 1<<(A+i);
			//cout << print(mask) << " ";
			//cout << print(test) << endl;
			count[test]++;
			mask = mask << 1 |1;
		}
		inp >> d;
	}
	
	patt p;
	for(int i=0;i<1<<13;i++)
		if(count[i]>0)
		{
			//cout << print(i) << " " << count[i] << endl;
			p.first = count[i];p.second=print(i);
			patts.insert(p);
		}
	
	int printed=0;
	int last=0;
	set<patt>::iterator it;
	for(it = patts.begin();it!=patts.end() && N>0;it++)
	{
		if(last==0 || it->first!=last)
		{
			if(last!=0)
				oup << endl;
			N--;
			printed=0;
			oup << it->first << endl;
		}
		if(printed==6)
			oup << endl;
		printed%=6;
		if(printed!=0)
			oup << " ";
		oup << it->second;
		printed++;
		last = it->first;
	}
	while(it!=patts.end() && it->first==last)
	{
		if(printed==6)
			oup << endl;
		printed%=6;
		if(printed!=0)
			oup << " ";
		oup << it++->second;
		printed++;
	}
	oup << endl;
		
	return 0;
}

