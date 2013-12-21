/*
ID:kadirce1
LANG:C++
PROG:race3
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

int arrows[101][2];
int nA;
bool reach[51];
vector<int> split, artic;

void fill_reach(int v)
{
	reach[0] = true;
	bool ready = false;
	while(!ready)
	{
		ready = true;
		for(int a=0;a<nA;a++)
			if(reach[arrows[a][0]] && !reach[arrows[a][1]])
				if(arrows[a][1] != v)
				{
					reach[arrows[a][1]] = true;
					ready = false;
				}
	}
}

bool isSplit(int v)
{
	bool split=true;
	for(int a=0;a<nA && split;a++)
		split = reach[arrows[a][0]] || !reach[arrows[a][1]];
	return split;
}

int main()
{
	ifstream inp("race3.in");
	ofstream oup("race3.out");
	
	int s=0, e=0;
	inp >> e;
	while(e!=-1)
	{
		if(e==-2)
		{
			inp >> e;
			s++;
			continue;
		}
		arrows[nA][0] = s;
		arrows[nA++][1] = e;
		inp >> e;
	}
	
	s--;
	for(int i=1;i<s;i++)
	{
		memset(reach, false, 50);
		fill_reach(i);
		if(!reach[s])
			artic.push_back(i);
		if(isSplit(i))
			split.push_back(i);
	}
	
	oup << artic.size();
	for(int i=0;i<artic.size();i++)
		oup << " " << artic[i];
	oup << endl;
	
	oup << split.size();
	for(int i=0;i<split.size();i++)
		oup << " " << split[i];
	oup << endl;
	
	return 0;
}

