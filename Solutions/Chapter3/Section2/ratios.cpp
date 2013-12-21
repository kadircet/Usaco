/*
ID:kadirce1
LANG:C++
PROG:ratios
*/

#include <iostream>
#include <fstream>
using namespace std;

struct ratio
{
	int mix[3];
};

ratio r[4];

int main()
{
	ifstream inp("ratios.in");
	ofstream oup("ratios.out");
	
	for(int i=0;i<4;i++)
		for(int j=0;j<3;j++)
			inp >> r[i].mix[j];
		
	int best=1000,bi,bj,bk,br;
		
	for(int i=0;i<=100;i++)
	for(int j=0;j<=100;j++)
	for(int k=0;k<=100;k++)
	{
		bool found=true;
		int rat=-1;
		for(int m=0;m<3;m++)
		{
			int t = r[1].mix[m]*i + r[2].mix[m]*j + r[3].mix[m]*k;
			if(r[0].mix[m]==0)
			{
				if(t!=0)
				{
					found=false;
					break;
				}
			}
			else if(t%r[0].mix[m]==0 && t!=0)
			{
				int rc = t/r[0].mix[m];
				if(rc==rat || rat==-1)
				{
					rat = rc;
					continue;
				}
				found=false;
				break;
			}
			else
			{
				found=false;
				break;
			}
		}
		if(found)
		{
			if(i+j+k<best)
			{
				best=i+j+k;
				bi=i;bj=j;bk=k;
				br=rat;
			}
		}
	}
	
	if(best==1000)
		oup << "NONE" << endl;
	else
		oup << bi << " " << bj << " " << bk << " " << br << endl;
	
	return 0;
}

