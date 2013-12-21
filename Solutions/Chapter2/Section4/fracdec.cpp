/*
ID:kadirce1
LANG:C++
PROG:fracdec
*/

#include <iostream>
#include <fstream>
using namespace std;

int N,D;
int rem[100001];
int diva[100001];

int main()
{
	ifstream inp("fracdec.in");
	ofstream oup("fracdec.out");
	for(int i=0;i<100001;i++)
		rem[i] = -1;
	
	inp >> N >> D;
	int comma=-1,rs=-1;
	int r=0,d=0,t=0;
	r = N%D;
	d = N/D;
	while(true)
	{
		diva[t] = d;
		if(rem[r]!=-1)
			break;
		rem[r] = t;
		if(r==0)
			break;
		t++;
		N%=D;
		if(N<D&&comma==-1)
			comma=t;
		N*=10;
		r = N%D;
		d = N/D;
	}
	if(r!=0)
		rs=rem[r]+1;
	
	int printed=0;
	for(int i=0;i<=t;i++)
	{
		if(i==comma)
		{
			oup << '.';
			printed++;
			if(printed%76==0)
				oup << endl;
		}
		if(i==rs)
		{
			oup << '(';
			printed++;
			if(printed%76==0)
				oup << endl;
		}
		oup << diva[i];
		int d=1;
		diva[i]/=10;
		while(diva[i]>0)
		{
			d++;
			diva[i]/=10;
		}
		printed+=d;
		if(printed%76==0)
			oup << endl;
	}
	if(rs!=-1)
		oup << ')';
	if(comma==-1)
		oup << ".0";
	oup << endl;
	
	return 0;
}

