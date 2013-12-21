/*
ID:kadirce1
LANG:C++
PROG:fence9
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
	return a==0?b:gcd(b%a, a);
}

int main()
{
	ifstream inp("fence9.in");
	ofstream oup("fence9.out");
	
	int n,m,p;
	int w,b;
	inp >> n >> m >> p;
	
	b = p + gcd(m,n) + gcd(m, (int)abs((double)p-n));
	w = p*m/2 - b/2 +1;
	oup << w << endl;
	return 0;
}

