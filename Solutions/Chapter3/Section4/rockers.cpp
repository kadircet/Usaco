/*
ID:kadirce1
LANG:C++
PROG:rockers
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

int cost[21][21][21];
vector<int> songs;
int N,T,M;

int pick(int m, int t, int i)
{
	if(m<=0||t<0||i>=N)return 0;
	if(cost[m][t][i]>=0)
		return cost[m][t][i];
	int c=0;
	if(t>=songs[i])
		c=max(pick(m, t-songs[i], i+1)+1, pick(m-1, T, i));
	else
		c=pick(m-1, T, i);
	c=max(pick(m, t, i+1), c);
	return cost[m][t][i]=c;
}

int main()
{
	ifstream inp("rockers.in");
	ofstream oup("rockers.out");
	memset(cost, -1, sizeof(int)*21*21*21);

	inp >> N >> T >> M;
	int tmp;
	for(int i=0;i<N;i++)
	{
		inp >> tmp;
		songs.push_back(tmp);
	}
	oup << pick(M, T, 0) << endl;
	
	return 0;
}

