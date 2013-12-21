/*
ID:kadirce1
LANG:C++
PROG:prefix
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> pri;
string cont;
int C[200005];

bool comp(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

int main()
{
	ifstream inp("prefix.in");
	ofstream oup("prefix.out");
	
	string t;
	inp >> t;
	while(t!=".")
	{
		pri.push_back(t);
		inp >> t;
	}
	inp >> t;
	while(inp.good())
	{
		cont += t;
		inp >> t;
	}
	
	sort(pri.begin(), pri.end(), comp);
	
	for(int i=cont.size();i>=0;i--)
	{
		for(int j=0;j<pri.size();j++)
		{
			if(i+pri[j].size() > cont.size())
				break;
			if(cont.substr(i, pri[j].size()) == pri[j])
			{
				int t = C[i+pri[j].size()] + pri[j].size();
				C[i] = max(C[i], t);
			}
		}
	}
	oup << C[0] << endl;
	return 0;
}

