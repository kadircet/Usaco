/*
NAME:kadirce1
PROG:numtri
LANG:C
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	return a>b?a:b;
}

int triangle[1000][1000];
int best[1000][1000];
int r;

/*int detrow(int pos)
{
	int n=0;
	for(;n<=r;n++)
		if(pos*2<n*(n+1))
			return n;
}

void calc(int pos, int point)
{
	point+=triangle[pos];
	if(pos*2>=r*(r-1))
	{
		if(point>max)max=point;
		return;
	}
	int row=detrow(pos);
	pos+=row;
	if(triangle[pos]!=0)
		calc(pos,point);
	if(triangle[pos+1]!=0)
		calc(pos+1,point);
}*/

int calc()
{
	int i,j;
	best[0][0]=triangle[0][0];
	for(i=1;i<r;i++)
	{
		best[i][0]=best[i-1][0]+triangle[i][0];
		for(j=1;j<i;j++)
			best[i][j]=max(best[i-1][j-1],best[i-1][j])+triangle[i][j];
		best[i][i]=best[i-1][i-1]+triangle[i][i];
	}
	int max=best[r-1][0];
	for(i=1;i<r;i++)
		if(best[r-1][i]>max)
			max=best[r-1][i];
	return max;
}

/*int calc()
{
	int i,j;
	best[0]=triangle[0][0];
	for(i=1;i<r;i++)
	{
		best[0]=best[0]+triangle[i][0];
		for(j=1;j<i;j++)
			best[j]=max(best[j-1],best[j])+triangle[i][j];
		best[i]=best[i-1]+triangle[i][i];
	}
	int max=best[0];
	for(i=1;i<r;i++)
		if(best[i]>max)
			max=best[i];
	return max;
}*/

int main()
{
	freopen("numtri.in","r",stdin);
	int i,j;
	scanf("%d",&r);
	for(i=0;i<r;i++)
		for(j=0;j<=i;j++)
			scanf("%d",&triangle[i][j]);
	fclose(stdin);
	
	freopen("numtri.out","w",stdout);
	printf("%d\n",calc());
	fclose(stdout);
	return 0;
}
