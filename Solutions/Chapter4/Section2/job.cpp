/*
ID:kadirce1
LANG:C++
PROG:job
*/

#include <iostream>
#include <fstream>
using namespace std;

int N,M[2];
int c[2][31];

int finish(int op, int t)
{
	int res=0;
	for(int i=0;i<M[op];i++)
		if(t%c[op][i]==0)
			res++;
	
	int proc=0;
	for(int i=0;i<M[op];i++)
		proc += (t-1)/c[op][i];
		
	if(proc>=N)
		res=0;
	else if(proc+res>N)
		res = N-proc;
	return res;
}

int main()
{
	ifstream inp("job.in");
	ofstream oup("job.out");
	
	inp >> N >> M[0] >> M[1];
	for(int j=0;j<2;j++)
		for(int i=0;i<M[j];i++)
			inp >> c[j][i];
	
	int ta, tb;
	int proc=0;
	for(tb=1;proc<N;tb++)
	{
		proc=0;
		for(int i=0;i<M[1];i++)
			proc += tb/c[1][i];
	}
	tb--;
	
	proc=0;
	for(ta=1;proc<N;ta++)
	{
		proc=0;
		for(int i=0;i<M[0];i++)
			proc += ta/c[0][i];
	}
	ta--;
	
	bool adjust=false;
	int inter=0,t=0,d=1;
	while(d+t<ta && t<tb)
	{
		int jb = finish(1, tb-t);
		inter += finish(0, d+t);
		while(inter<jb)
		{
			d++;
			inter += finish(0, d+t);
		}
		inter -= jb;
		t++;
	}
	
	oup << ta << " ";
	oup << tb+d << endl;
	
	return 0;
}

