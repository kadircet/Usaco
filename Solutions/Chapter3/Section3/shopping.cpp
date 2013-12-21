/*
ID:kadirce1
LANG:C++
PROG:shopping
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct item
{
	int cost;
	int amount;
};

struct offer
{
	int amounts[5];
	int cost, n;
	
	offer()
	{
		for(int i=0;i<5;i++)
			amounts[i]=0;	
	}
};

vector<offer> offers;
int cost[6][6][6][6][6];
map<int, int> index;
item items[5];

int main()
{
	ifstream inp("shopping.in");
	ofstream oup("shopping.out");
	
	int no, ni=0, code;
	inp >> no;
	for(int i=0;i<no;i++)
	{
		offer tmp;
		inp >> tmp.n;
		for(int j=0;j<tmp.n;j++)
		{
			inp >> code;
			if(index.find(code)==index.end())
				index[code] = ni++;
			inp >> tmp.amounts[index[code]];
		}
		inp >> tmp.cost;
		offers.push_back(tmp);
	}
	
	inp >> no;
	for(int i=0;i<no;i++)
	{
		inp >> code;
		if(index.find(code)==index.end())
			index[code] = ni++;
		inp >> items[index[code]].amount >> items[index[code]].cost;
	}
	
	for(int i=ni;i<6;i++)
		items[i].amount=0;
	
	cost[0][0][0][0][0] = 0;
	int a[5];
	
	for(int i=0;i<offers.size();i++)
	for(a[0]=0;a[0]<=items[0].amount;a[0]++)for(a[1]=0;a[1]<=items[1].amount;a[1]++)
	for(a[2]=0;a[2]<=items[2].amount;a[2]++)for(a[3]=0;a[3]<=items[3].amount;a[3]++)
	for(a[4]=0;a[4]<=items[4].amount;a[4]++)
	{
		if(cost[a[0]][a[1]][a[2]][a[3]][a[4]]==0)
		{
			int c=0;
			for(int i=0;i<5;i++)
				c += a[i]*items[i].cost;
			cost[a[0]][a[1]][a[2]][a[3]][a[4]] = c;
		}
		
		int b[5];
		for(int j=0;j<5;j++)
		{
			b[j] = a[j] - offers[i].amounts[j];
			if(b[j] < 0)
			{
				b[0] = -1;
				break;
			}
		}
		if(b[0]==-1)
			continue;

		cost[a[0]][a[1]][a[2]][a[3]][a[4]] = min(cost[a[0]][a[1]][a[2]][a[3]][a[4]], cost[b[0]][b[1]][b[2]][b[3]][b[4]] + offers[i].cost);
	}
	if(offers.size()==0)
	{
		int c=0;
		for(int i=0;i<5;i++)
			c += items[i].amount*items[i].cost;
		oup << c << endl;
	}
	else
		oup << cost[items[0].amount][items[1].amount][items[2].amount][items[3].amount][items[4].amount] << endl;
	return 0;
}

