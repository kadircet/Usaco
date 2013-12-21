/*
ID:kadirce1
LANG:C++
PROG:game1
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N;
vector<int> w;
long long int P[101][101];

long long int point(int i, int j)
{
	if(i>100 || j>100 || i<0 || j<0 || i>j)
		return 0;
	if(P[i][j]!=0)
		return P[i][j];
	
	return P[i][j]=max(w[i] + min(point(i+1,j-1), point(i+2, j)),
				w[j] + min(point(i+1,j-1), point(i, j-2)));
}

int main()
{
	ifstream inp("game1.in");
	ofstream oup("game1.out");
	
	long long int t, sum=0;
	inp >> N;
	for(int i=0;i<N;i++)
	{
		inp >> t;
		w.push_back(t);
		sum += t;
	}
	
	oup << point(0, N-1) << " " << sum-point(0, N-1) << endl;
	
	return 0;
}
