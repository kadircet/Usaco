/*
ID: kadirce1
LANG: C
PROG: dualpal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base[]={48,49,50,51,52,53,54,55,56,57};

char* convert(int n, int b)
{
    char a[100];
    int d=0;
    while(n)
    {
        a[d]=base[n%b];
        n/=b;
        d++;
    }
    a[d]='\0';
    char *c=(char*)malloc(sizeof(char)*strlen(a));
    for(d=0;d<strlen(a);d++)
        c[d]=a[strlen(a)-d-1];
    c[strlen(a)]=0;
    return c;
}


int ispal(char *s)
{
    char *t;

    t = s+strlen(s)-1;
    for(t=s+strlen(s)-1; s<t; s++, t--)
    	if(*s != *t)
	    return 0;

    return 1;
}

void main()
{
	int n,s,b,i,q=0,z=0;
    FILE *in = fopen("dualpal.in","r");
    fscanf(in,"%d %d",&n,&s);
    fclose(in);
    FILE *out=fopen("dualpal.out","w");
	for(i=s+1;;i++)
	{
		for(b=2;b<=10;b++)
		{
			if(ispal(convert(i,b)))
			{
				q++;
				if(q==2)
				{
					z++;
					fprintf(out,"%d\n",i);
					break;
				}
			}
		}
		q=0;
		if(z==n)break;
	}
    fclose(out);
    exit(0);
}
