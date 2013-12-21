/*
ID:kadirce1
LANG:C++
PROG:spin
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct wedge
{
	int start,end;
};

struct wheel
{
	int w, nw;
	wedge wedges[5];
};

wheel wheels[5];

int main()
{
	ifstream inp("spin.in");
	ofstream oup("spin.out");
	
	for(int i=0;i<5;i++)
	{
		inp >> wheels[i].w >> wheels[i].nw;
		for(int j=0;j<wheels[i].nw;j++)
		{
			inp >> wheels[i].wedges[j].start >> wheels[i].wedges[j].end;
			wheels[i].wedges[j].end += wheels[i].wedges[j].start;
		}
	}
	
	int t;
	int interval[360];
	for(t=0;t<360;t++)
	{
		memset(interval, 0, sizeof(interval));
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<wheels[i].nw;j++)
			{
				wedge w= wheels[i].wedges[j];
				int cs = w.start+t*wheels[i].w;
				cs%=360;
				int ce = w.end+t*wheels[i].w;
				ce%=360;
				if(cs>ce)
					ce+=360;
				for(int k=cs;k<=ce;k++)
				{
					if(++interval[k%360]>4)
					{
						oup << t << endl;
						return 0;
					}
				}
			}
		}
	}
	
	oup << "none" << endl;
	
	return 0;
}

