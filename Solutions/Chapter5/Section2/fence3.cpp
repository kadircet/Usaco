/*
ID:kadirce1
LANG:C++
PROG:fence3
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

struct fence
{
	int lx, rx;
	int by, ty;
	
	double dist(double x, double y)
	{
		double dx, dy;
		if(x>rx)
			dx=x-rx;
		else if(lx>x)
			dx=lx-x;
		else
			dx=0;
			
		if(y>ty)
			dy=y-ty;
		else if(by>y)
			dy=by-y;
		else
			dy=0;
		
		return sqrt(dx*dx+dy*dy);
	}
};

int N;
vector<fence> fences;

double dist(double x, double y)
{
	double res=0;
	for(int i=0;i<fences.size();i++)
		res+=fences[i].dist(x, y);
	return res;
}

int main()
{
	freopen("fence3.in", "r", stdin);
	cin >> N;
	for(int i=0;i<N;i++)
	{
		int lx,rx,ty,by;
		cin >> lx >> by >> rx >> ty;
		if(lx>rx)
			swap(lx, rx);
		if(by>ty)
			swap(by, ty);
		fence f;
		f.lx=lx, f.rx=rx, f.ty=ty, f.by=by;
		fences.push_back(f);
	}
	fclose(stdin);
	
	double bx=0, by=0, best=1e10, d=5;
	double cx=bx, cy=by;
	while(d>1e-5)
	{
		for(int i=0;i<21;i++)
			for(int j=0;j<21;j++)
			{
				double t = dist(cx+i*d, cy+j*d);
				if(best>t)
				{
					best=t;
					bx=cx+i*d;
					by=cy+j*d;
				}
			}
		
		cx=bx-d;
		cy=by-d;
		d/=10;
	}
	
	freopen("fence3.out", "w", stdout);
	cout << fixed << setprecision(1) << bx << ' ' << by << ' ' << best << endl;
	fclose(stdout);
	return 0;
}

