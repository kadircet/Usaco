/*
NAME: kadirce1
PROG: milk
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _milker
{
	int n;
	int c;
}Milker;

int cmp(const void* a,const void* b)
{
	Milker *m,*n;
	m = (Milker*)a;
	n = (Milker*)b;
	if(m->c>n->c)
		return 1;
	else if(m->c<n->c)
		return -1;
	return 0;
}

void main()
{
	FILE *in = fopen("milk.in","rb");

	int n,m=0,i,c=0,j;
	fscanf(in,"%d %d",&n,&m);

	Milker milker[m];
	for(i=0;i<m;i++)
		fscanf(in,"%d %d",&milker[i].c,&milker[i].n);
	fclose(in);

	qsort(milker,m,sizeof(Milker),cmp);

	for(i=0,j=0;;j++)
	{
		if((i+milker[j].n)<=n)
		{
			i+=milker[j].n;
			c+=milker[j].c*milker[j].n;
			//printf("%d %d\n",i,c);
		}
		else
		{
			int t=n-i;
			i+=t;
			c+=milker[j].c*t;
			//printf("dikkat: %d %d\n",i,c);
		}
		if(i==n)break;
	}

	FILE *out=fopen("milk.out","w");
	fprintf(out,"%d\n",c);
	fclose(out);
	exit(0);
}
