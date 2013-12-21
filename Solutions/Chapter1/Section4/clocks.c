/*
NAME:kadirce1
PROG:clocks
LANG:C
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int c[9];
char moves[9][6]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int movedist[9][9];
int sol[9];
int move[9];
int nbest;

void moved()
{
	char *p;
	int i;
	for(i=0;i<9;i++)
		for(p=moves[i];*p;p++)
			movedist[i][*p-'A']=3;
}

void solve(int k)
{
	int i,j;

	if(k==9)
	{
		for(i=0;i<9;i++)
			if(c[i]%12!=0)
				return;
		j=0;
		for(i=0;i<9;i++)
			j+=move[i];

		if(nbest==0 || j < nbest)
		{
			for(i=0;i<9;i++)
				sol[i] = move[i];
			nbest=j;
		}
		return;
	}

	int kont;
	for(kont=3;kont>=0;kont--)
	{
		for(i=0;i<9;i++)
			c[i] += movedist[k][i]*kont;

		move[k]=kont;

		solve(k+1);

		for(i=0;i<9;i++)
			c[i] -= movedist[k][i]*kont;
	}
}

int main()
{
	moved();
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	int i,j;

	for(i=0;i<9;i++)
		scanf("%d",&c[i]);

	fclose(stdin);

	solve(0);

	char *sep="";
	for(i=0;i<9;i++)
		for(j=0;j<sol[i];j++)
		{
			printf("%s%d",sep,i+1);
			sep=" ";
		}
	printf("\n");

	fclose(stdout);
	return 0;
}
