/*
ID:kadirce1
LANG:C++
PROG:buylow
*/

#include <iostream>
#include <fstream>
using namespace std;

struct bignum
{
	int val;
	bignum* next;
	
	bignum()
	{
		val=0;
		next=NULL;
	}
	
	void add(bignum* b)
	{
		bignum* cur=this;
		int c=0;
		while(b||c)
		{
			cur->val += c;
			if(b) cur->val += b->val;
			
			if(b) b=b->next;
			c = cur->val/1000000;
			cur->val %= 1000000;
			if(!cur->next && (b||c))
				cur->next = new bignum;
			cur = cur->next;
		}
	}
	
	void print(ostream& os)
	{
		if(next==NULL)
			os << val;
		else
		{
			next->print(os);
			os.width(6);
			os.fill('0');
			os << val;
		}
	}
};

int N;
int prices[5000];
int dp[5000];

bignum count[5000];

int main()
{
	ifstream inp("buylow.in");
	ofstream oup("buylow.out");
	
	inp >> N;
	for(int i=0;i<N;i++)
		inp >> prices[i];
	
	for(int i=0;i<N;i++)
	{
		dp[i] = 1;
		for(int j=0;j<i;j++)
			if(prices[j]>prices[i])
				dp[i] = max(dp[i], dp[j]+1);
	}
	
	int sol=0;
	for(int i=0;i<N;i++)
		sol = max(sol, dp[i]);
	
	int l=-1;
	for(int i=0;i<N;i++)
	{
		l=-1;
		if(dp[i]==1)
			count[i].val = 1;
		else
		{
			for(int j=i-1;j>=0;j--)
			{
				if(prices[j]>prices[i] && dp[j]+1==dp[i] && l!=prices[j])
				{
					count[i].add(&count[j]);
					l=prices[j];
				}
			}
		}
	}
	
	
	bignum nsol;
	l=-1;
	for(int i=N-1;i>=0;i--)
	{
		if(dp[i]==sol && l != prices[i])
		{
			nsol.add(&count[i]);
			l=prices[i];
		}
	}
	
	oup << sol << " ";
	nsol.print(oup);
	oup << endl;
	
	return 0;
}

