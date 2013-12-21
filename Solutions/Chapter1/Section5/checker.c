/*
NAME:kadirce1
PROG:checker
LANG:C
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXN 20

int row[MAXN];
int col[MAXN], diag1[2*MAXN], diag2[2*MAXN];
int n,n2,p,nsol;

void printsol()
{
	if(p++<3)
	{
		int j;
		for(j=0;j<n-1;j++)
			printf("%d ", row[j]+1);
		printf("%d\n", row[j]+1);
	}
}

void solve(int k, int l)
{
	int i;
	if(k==n)
	{
		nsol++;
		if(n>6 && row[0]<n/2)nsol++;
		printsol();
		return;
	}

	for(i=0;i<l;i++)
	{
		if(!col[i] && !diag1[i+k] && !diag2[k-i+MAXN])
		{
			row[k]=i;
			col[i]++;
			diag1[i+k]++;
			diag2[k-i+MAXN]++;

			solve(k+1,n);
			
			col[i]--;
			diag1[i+k]--;
			diag2[k-i+MAXN]--;
		}
	}
}

int main()
{
	freopen("checker.in","r",stdin);
	scanf("%d",&n);
	fclose(stdin);

	freopen("checker.out","w",stdout);
	solve(0,n>6?(n+1)/2:n);
	printf("%d\n",nsol);
	fclose(stdout);

	return 0;
}
