/*
NAME:kadirce1
PROG:ariprog
LANG:C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ub,length;
struct _seq
{
	int start;
	int diff;
};

struct _seq seq[10000];

char bisq[125001];

int comp(const void* a, const void *b)
{
	struct _seq *s1 = (struct _seq *)a;
	struct _seq *s2 = (struct _seq *)b;
	
	if(s1->diff==s2->diff)
		return s1->start-s2->start;
	return s1->diff-s2->diff;
}

void calcbisq()
{
	int i,j;
	for(i=0;i<=ub;i++)
		for(j=0;j<=ub;j++)
			bisq[i*i+j*j]=1;
}

int isBQ(int n)
{
	/*int i,j;
	for(i=0;i<=ub;i++)
		for(j=0;j<=ub;j++)
			if(i*i+j*j==n)
				return 1;
			else if(i*i>n)
				return 0;
			else if(j*j>n)
				break;
	return 0;*/
	return bisq[n];
}

int no=0;

void progress()
{
	int a,b,n;
	int isq=1;
	int max=ub*ub*2;
	for(a=0;a<max-length+1;a++)
	{
		for(b=1;b*(length-1)<max+1-a;b++)
		{
			for(n=0;n<length;n++)
			{
				if(!isBQ(a+b*n))
				{
					isq=0;
					break;
				}
			}
			if(isq==1)
			{
				seq[no].start=a;
				seq[no++].diff=b;
			}
			isq=1;
		}
	}
}

int main()
{
	int i;
	freopen("ariprog.in","r",stdin);
	scanf("%d%d",&length,&ub);
	fclose(stdin);

	calcbisq();

	progress();
	qsort(seq,no,sizeof(struct _seq),&comp);

	freopen("ariprog.out","w",stdout);
	for(i=0;i<no;i++)
		printf("%d %d\n",seq[i].start,seq[i].diff);
	if(no==0)
		printf("NONE\n");
	fclose(stdout);
}
