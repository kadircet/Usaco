/*
ID:kadirce1
LANG:C++
PROG:fc
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef complex<double> point;
vector<point> points;

bool comp(const point& lhs, const point& rhs)
{
	if(lhs.real()!=rhs.real())
		return lhs.real()<rhs.real();
	return lhs.imag()>rhs.imag();
}
double dot(const point &a, const point &b)
{
	return real(conj(a) * b);
}
double cross(const point &a, const point &b)
{
	return imag(conj(a) * b);
}
bool ccw(point p1, point p2)
{
	return cross(p1, p2)>0;
}
bool ccw(point p1, point p2, point p3)
{
	return ccw(p2-p1, p3-p1);
}
double dist(point p1, point p2)
{
	double x = (p2-p1).real(),
		y = (p2-p1).imag();
	
	return sqrt(x*x+y*y);
}

vector<point> convexHull(vector<point> p)
{
	vector<point> res;
	vector<point> up,low;
	int N=p.size();
	for(int i=0;i<N;i++)
	{
		while(low.size()>=2 && !ccw(low[low.size()-1], low[low.size()-2], p[i]))
			low.pop_back();
		low.push_back(p[i]);
	}
	low.pop_back();
	
	for(int i=N-1;i>=0;i--)
	{
		while(up.size()>=2 && !ccw(up[up.size()-1], up[up.size()-2], p[i]))
			up.pop_back();
		up.push_back(p[i]);
	}
	up.pop_back();
	for(int i=0;i<low.size();i++)
		res.push_back(low[i]);
	for(int i=0;i<up.size();i++)
		res.push_back(up[i]);
	return res;
}

int main()
{
	int N;
	
	freopen("fc.in", "r", stdin);
	cin >> N;
	points.resize(N);
	for(int i=0;i<N;i++)
		cin >> points[i].real() >> points[i].imag();
	fclose(stdin);
	
	sort(points.begin(), points.end(), comp);
	vector<point> convex=convexHull(points);
	N=convex.size();
	double res=0;
	for(int i=0;i<N;i++)
		res+=dist(convex[i], convex[(i+1)%N]);
	
	freopen("fc.out", "w", stdout);
	cout << fixed << setprecision(2) << res << endl;
	fclose(stdout);
	return 0;
}

