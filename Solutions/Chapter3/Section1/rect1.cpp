/*
ID:kadirce1
LANG:C++
PROG:rect1
*/

#include <iostream>
#include <fstream>
using namespace std;

struct rect
{
	int lx, ly;
	int ux, uy;
	int color;
};

rect rects[100000];
bool under[100000];
int N;
int color[2501];

int main()
{
	ifstream inp("rect1.in");
	ofstream oup("rect1.out");
	
	int nr=0;
	inp >> rects[nr].ux >> rects[nr].uy;
	rects[nr].lx = rects[nr].ly = 0;
	rects[nr].color = 1;
	nr++;
	inp >> N;
	for(int i=0;i<N;i++)
	{
		inp >> rects[nr].lx >> rects[nr].ly;
		inp >> rects[nr].ux >> rects[nr].uy;
		inp >> rects[nr++].color;
		
		int cr=nr-1;
		for(int j=0;j<cr;j++)
		{
			if(under[j])
				continue;
			int uy = min(rects[cr].uy, rects[j].uy);
			int ly = max(rects[cr].ly, rects[j].ly);
			int lx = max(rects[cr].lx, rects[j].lx);
			int ux = min(rects[cr].ux, rects[j].ux);
			
			if(lx>=ux || ly>=uy)
				continue;
			under[j] = true;
			
			rects[nr].lx = rects[j].lx; rects[nr].ly = rects[j].ly;
			rects[nr].ux = ux; rects[nr].uy = ly;
			rects[nr++].color = rects[j].color;
			
			rects[nr].lx = ux; rects[nr].ly = rects[j].ly;
			rects[nr].ux = rects[j].ux; rects[nr].uy = uy;
			rects[nr++].color = rects[j].color;
			
			rects[nr].lx = rects[j].lx; rects[nr].ly = ly;
			rects[nr].ux = lx; rects[nr].uy = rects[j].uy;
			rects[nr++].color = rects[j].color;
			
			rects[nr].lx = lx; rects[nr].ly = uy;
			rects[nr].ux = rects[j].ux; rects[nr].uy = rects[j].uy;
			rects[nr++].color = rects[j].color;
		}
	}
	
	for(int i=0;i<nr;i++)
		if(!under[i])
		{
			int area = (rects[i].ux - rects[i].lx) * (rects[i].uy - rects[i].ly);
			color[rects[i].color] += area;
		}
	
	for(int i=0;i<=2500;i++)
		if(color[i]!=0)
			oup << i << " " << color[i] << endl;
	
	return 0;
}

