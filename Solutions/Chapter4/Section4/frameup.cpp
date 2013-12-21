/*
ID:kadirce1
LANG:C++
PROG:frameup
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SIZE ('Z'-'A'+1)
using namespace std;

int lef[SIZE], rig[SIZE];
int top[SIZE], bot[SIZE];
int N, M;
char frame[31][31];
bool found[SIZE][SIZE];
bool put[SIZE];
vector<char> chars;
vector<string> sol;
bool visited[SIZE];

void printSol(string order)
{
	if(order.length()==chars.size())
	{
		sol.push_back(order);
		return;
	}
	for(int i=0;i<SIZE;i++)
	{
		if(put[i])
		{
			bool f=false;
			for(int j=0;j<SIZE;j++)
				if(found[i][j] && put[j])
				{
					f=true;
					break;
				}
			
			if(!f)
			{
				put[i]=false;
				printSol(char(i+'A')+order);
				put[i]=true;
			}
		}
	}
}

int main()
{
	memset(lef, 31, sizeof(lef));
	memset(top, 31, sizeof(top));
	
	freopen("frameup.in", "r", stdin);
	cin >> N >> M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			cin >> frame[i][j];
			if(frame[i][j]>='A')
			{
				char c = frame[i][j]-'A';
				if(!put[c])
				{
					chars.push_back(c);
					put[c]=true;
				}
				lef[c] = min(lef[c], j);
				top[c] = min(top[c], i);
				bot[c] = max(bot[c], i);
				rig[c] = max(rig[c], j);
			}	
		}
	fclose(stdin);
	
	for(int c=0;c<SIZE;c++)
	{
		for(int i=lef[c];i<=rig[c];i++)
		{
			if(frame[top[c]][i]>='A')
				found[c][frame[top[c]][i]-'A']=true;
			if(frame[bot[c]][i]>='A')
				found[c][frame[bot[c]][i]-'A']=true;
		}
		for(int i=top[c]+1;i<=bot[c]-1;i++)
		{
			if(frame[i][lef[c]]>='A')
				found[c][frame[i][lef[c]]-'A']=true;
			if(frame[i][rig[c]]>='A')
				found[c][frame[i][rig[c]]-'A']=true;
		}
	}
	for(int i=0;i<SIZE;i++)
		found[i][i]=false;
	
	for(int k=0;k<SIZE;k++)
		for(int i=0;i<SIZE;i++)
			for(int j=0;j<SIZE;j++)
				if(found[i][k] && found[k][i])
					found[i][j]=true;

	printSol("");
	sort(sol.begin(), sol.end());
	
	freopen("frameup.out", "w", stdout);	
	for(int i=0;i<sol.size();i++)
		cout << sol[i] << endl;
	fclose(stdout);
	
	return 0;
}

