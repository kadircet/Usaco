/*
ID:kadirce1
LANG:C++
PROG:fact4
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inp("fact4.in");
	ofstream oup("fact4.out");
	
	int N;
	inp >> N;
	
	int f=1;
	for(int i=2;i<=N;i++)
	{
		f*=i;
		while(f%10==0)
			f/=10;
		f%=10000;
	}
	oup << f%10 << endl;
	
	return 0;
}

