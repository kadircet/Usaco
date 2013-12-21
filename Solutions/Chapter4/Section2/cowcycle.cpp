/*
ID:kadirce1
LANG:C++
PROG:cowcycle
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int F,R;
int fL,fH,rL,rH;
int bestF[10], bestR[10];
int curF[10], curR[10];
double minVar = 1e10;

void pickR(int low, int pos)
{
	if(pos == R)
	{
		if(curF[F-1]*curR[R-1]<3*curF[0]*curR[0])
			return;
		
		int rs=0;
		double ratios[5*10];
		for(int i=0;i<F;i++)
			for(int j=0;j<R;j++)
				ratios[rs++] = (double)curF[i]/curR[j];
		
		sort(ratios, ratios+rs);
		
		for(int i=0;i<rs-1;i++)
			ratios[i] = ratios[i+1] - ratios[i];
			
		double mean, var;
		
		mean = 0;
		for(int i=0;i<rs-1;i++)
			mean += ratios[i];
		mean /= rs-1;
		
		var = 0;
		for(int i=0;i<rs-1;i++)
			var += (ratios[i] - mean)*(ratios[i] - mean);
		var /= rs-1;
		if(minVar>var)
		{
			minVar = var;
			for(int i=0;i<F;i++)
				bestF[i] = curF[i];
			for(int i=0;i<R;i++)
				bestR[i] = curR[i];
		}

		return;
	}
	for(int i=low;i<=rH-(R-pos)+1;i++)
	{
		curR[pos] = i;
		pickR(i+1, pos+1);
	}
}

void pickF(int low, int pos)
{
	if(pos == F)
	{
		pickR(rL, 0);
		return;
	}
	
	for(int i=low;i<=fH-(F-pos)+1;i++)
	{
		curF[pos] = i;
		pickF(i+1, pos+1);
	}
}


int main()
{
	ifstream inp("cowcycle.in");
	ofstream oup("cowcycle.out");
	
	inp >> F >> R >> fL >> fH;
	inp >> rL >> rH;
	
	pickF(fL, 0);

	oup << bestF[0];
	for(int i=1;i<F;i++)
		oup << " " << bestF[i];
	oup << endl;
	
	oup << bestR[0];
	for(int i=1;i<R;i++)
		oup << " " << bestR[i];
	oup << endl;
	
	return 0;
}

