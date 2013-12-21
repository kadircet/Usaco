/*
NAME: kadirce1
PROG: barn1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

int stalls[200];
int comp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	FILE *in = fopen("barn1.in","r");
	FILE *out=fopen("barn1.out","w");

	int m,s,c,i,j,ans=0,lo=0,hi=200;
	int test[200],ntest=0;

	fscanf(in,"%d %d %d",&m,&s,&c);
	for(i=0;i<c;i++)
	{
		fscanf(in,"%d",&j);
		stalls[j-1]=1;
	}
	fclose(in);

	for(i=0;i<s&&stalls[i]!=1;i++)
		ans++;
	lo=i;

	for(i=s-1;i>=0&&stalls[i]!=1;i--)
		ans++;
	hi=i+1;

	i=lo;
	while(i<hi)
	{
		while(stalls[i]==1&&i<hi)i++;
		j=i;
		while(stalls[i]==0&&i<hi)i++;
		test[ntest++]=i-j;
	}
	qsort(test, ntest, sizeof(test[0]), comp);

	for(i=0;i<m-1&&i<ntest;i++)ans+=test[i];

	fprintf(out,"%d\n",s-ans);
	fclose(out);

	return 0;
}
