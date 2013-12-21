/*
ID:kadirce1
LANG:C++
PROG:lamps
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int N, C;
vector<bool> on(104), off(104);
vector<string> poss;

void check(int lamps)
{
	bool c1 = lamps & 1, c2 = lamps & 2,
		c3 = lamps & 4, c4 = lamps & 8;
		
	int npress = c1 + c2 + c3 + c4;
	if(npress>C)
		return;
	if(npress%2!=C%2)
		return;
	
	for(int i=1;i<=N;i++)
	{
		bool state = true;
		if(c1)
			state = !state;
		if(c2 && i%2==0)
			state = !state;
		if(c3 && i%2==1)
			state = !state;
		if(c4 && i%3==1)
			state = !state;
		
		if(state && off[i])
			return;
		if(!state && on[i])
			return;
	}
	stringstream s;
	for(int i=1;i<=N;i++)
	{
		bool state = true;
		if(c1)
			state = !state;
		if(c2 && i%2==0)
			state = !state;
		if(c3 && i%2==1)
			state = !state;
		if(c4 && i%3==1)
			state = !state;
		s << state;
	}
	poss.push_back(s.str());
}

int main()
{
	ifstream inp("lamps.in");
	ofstream oup("lamps.out");
	
	inp >> N >> C;
	int t;
	inp >> t;
	while(t!=-1)
	{
		on[t] = true;
		inp >> t;
	}
	inp >> t;
	while(t!=-1)
	{
		off[t] = true;
		inp >> t;
	}
	
	for(int i=0;i<16;i++)
		check(i);
	
	sort(poss.begin(), poss.end());
	if(poss.empty())
		oup << "IMPOSSIBLE" << endl;
	else
		for(int i=0;i<poss.size();i++)
			oup << poss[i] << endl;
	
	return 0;
}

