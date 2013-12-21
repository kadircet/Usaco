/*
ID:kadirce1
LANG:C++
PROG:runround
*/

#include <iostream>
#include <fstream>
using namespace std;

int input[10];
int inn;
int l;
bool used[10];
int res[10];
bool found;

void solve(int pos)
{
	if(found)
		return;
	if(pos==l)
	{
		found = true;
		int r=0;
		for(int i=0;i<l;i++)
		{
			r*=10;
			r+=res[i];
		}
		if(r<=inn)
		{
			found=false;
			return;
		}

		bool visited[10];
		for(int i=0;i<10;i++)
			visited[i]=false;
		for(int i=0;;)
		{
			if(visited[(i+res[i])%l])
				break;
			if((i+res[i])%l==0)
			{
				visited[0]=true;
				break;
			}
			visited[(i+res[i])%l] = true;
			i = (i+res[i])%l;
		}

		for(int i=0;i<l;i++)
		{
			if(!visited[i])
			{
				found = false;
				return;
			}
		}
		return;
	}
	for(int i=1;i<=9&&!found;i++)
	{
		if(!used[i])
		{
			res[pos] = i;
			used[i] = true;
			solve(pos+1);
			used[i] = false;
		}
	}
}

int main()
{
	ifstream inp("runround.in");
	ofstream oup("runround.out");
	
	char c;
	int i=0;
	inp >> c;
	inn = 0;
	while(inp.good())
	{
		inn *= 10;
		inn += c-'0';
		input[i++] = c-'0';
		inp >> c;
	}
	l=i;
	used[0]=true;
	
	while(!found && l<10)
	{
		solve(0);
		l++;
	}
	for(int i=0;i<l-1;i++)
		oup << res[i];
	oup << endl;
	
	return 0;
}

