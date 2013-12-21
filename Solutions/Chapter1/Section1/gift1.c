/*
ID: kadirce1
LANG: C
PROG: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person
{
	char name[100];
	int money;
}person;

void main()
{
	int np;
	int a,b,q,l,s;
    FILE *in = fopen("gift1.in" ,"r");
	FILE *out= fopen("gift1.out","w");

	fscanf(in,"%d",&np);

	person p[np];
	char z[100];
	int i;

	for(i=0;i<np;i++)
		p[i].money = 0;

	for(i=0;i<np;i++)
		fscanf(in,"%s",p[i].name);
	
	while(fscanf(in,"%s",z)!=EOF)
	{
		for(i=0;i<np;i++)
		{
			if(!strcmp(p[i].name,z))
			{
				fscanf(in,"%d %d",&a,&b);
				if (b==0)
					break;
				p[i].money-=(a-a%b);
				for (q=0;q<b;q++)
				{
					fscanf(in,"%s",z);
					for(l=0;l<np;l++)
					{
						if(!strcmp(p[l].name,z))
							p[l].money+=a/b;
					}
				}
				break;
			}
		}
	}

	for (i=0; i<np; i++)
		fprintf(out,"%s %d\n",p[i].name,p[i].money);

	fclose(in);
	fclose(out);
	exit(0);
}
