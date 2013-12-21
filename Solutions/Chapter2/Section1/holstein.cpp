/*
ID: kadirce1
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

vector<int> nV;
vector<vector<int> > foods;
vector<int> cV;
set<int> used;

void printUsed()
{
	set<int>::iterator it;
	for(it=used.begin();it!=used.end();it++)
		cout << *it+1 << " ";
	cout << endl;
}

bool solve(int pos, int cs, int ms)
{
	//printUsed();
	if(pos>=foods.size() && cs<ms)
		return false;
	if(cs == ms)
	{
		for(int i=0;i<nV.size();i++)
			if(nV[i] > cV[i])
				return false;
		return true;
	}
	
	for(int i=0;i<nV.size();i++)
		cV[i] += foods[pos][i];
	used.insert(pos);
	bool res1 = solve(pos+1, cs+1, ms);
	if(res1)
		return true;
	used.erase(pos);
	
	for(int i=0;i<nV.size();i++)
		cV[i] -= foods[pos][i];
	bool res2 = solve(pos+1, cs, ms);	
	
	return res1 || res2;
}

int main()
{
	ifstream inp("holstein.in");
	ofstream oup("holstein.out");
	vector<int> food;
	int V, G, t;
	
	inp >> V;
	for(int i=0;i<V;i++)
	{
		inp>>t;
		nV.push_back(t);
		cV.push_back(0);
	}
	inp >> G;
	for(int i=0;i<G;i++)
	{
		food.clear();
		for(int j=0;j<V;j++)
		{
			inp >> t;
			food.push_back(t);
		}
		foods.push_back(food);
	}
	
	int i;
	for(i=1;i<=G;i++)
	{
		used.clear();
		if(solve(0, 0, i))
			break;
	}
	oup << i;
	set<int>::iterator it;
	for(it=used.begin();it!=used.end();it++)
		oup << " " << *it+1;
	oup << endl;
	return 0;
}

