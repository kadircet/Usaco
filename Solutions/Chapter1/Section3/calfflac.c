/*
NAME: kadirce1
PROG: calfflac
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[20000],*clear;
int map[20000],max,maxs,maxe;

int inrange(int l, int r)
{
	return (l>=0&&r<=strlen(clear));
}

void findpal(int l, int r)
{
	while(inrange(l,r))
	{
		if(*(clear+l)==*(clear+r))
		{
			l--,r++;
		}
		else break;
	}
	int le = r-l-1;
	if(le>max)
	{
		max=le;
		maxs=l+1;
		maxe=r-1;
	}
}

int main()
{
	clear = malloc(20000);
	FILE *in = fopen("calfflac.in","r"),
		*out = fopen("calfflac.out","w");
	char c;
	int i=0,z=0;

	while(fscanf(in,"%c",&c)!=EOF)
		input[i++]=c;
	fclose(in);

	for(i=0;i<strlen(input);i++)
	{
		if(isalpha(input[i]))
		{
			clear[z]=toupper(input[i]);
			map[z++]=i;
		}
	}

	for(i=0;i<strlen(clear);i++)
	{
		findpal(i,i+1);
		findpal(i-1,i+1);
	}

	fprintf(out,"%d\n",max);
	for(i=map[maxs];i<=map[maxe];i++)
		fprintf(out,"%c",input[i]);
	fprintf(out,"\n");
	return 0;
}
