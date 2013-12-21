/*
ID:kadirce1
LANG:C++
PROG:theme
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> notes;
vector<int> diffs;

int main()
{
	freopen("theme.in", "r", stdin);
	cin >> N;
	int note;
	for(int i=0;i<N;i++)
	{
		cin >> note;
		notes.push_back(note);
		if(i>0)
			diffs.push_back(note-notes[i-1]);
	}
	fclose(stdin);
	
	int answ=0;
	for(int dist=5;dist<N;dist++)
	{
		int l=1;
		for(int cur=0;cur<N-1-dist;cur++)
		{
			if(diffs[cur]==diffs[cur+dist])
				l++,answ=max(l, answ);
			else
				l=1;
			if(l==dist)
				break;
		}
	}
	
	freopen("theme.out", "w", stdout);
	cout << (answ>=5?answ:0) << endl;
	fclose(stdout);
	
	return 0;
}

