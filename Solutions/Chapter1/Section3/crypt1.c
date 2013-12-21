/*
NAME:kadirce1
LANG:C
PROG:crypt1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *digits,x;

int in(int n)
{
	int i=0;
	for(;i<x;i++)
		if(n==*(digits+i))
			return 1;
	return 0;
}

int partials(int p1, int p2)
{
	if(control(p1*p2,4)&&control(p1*(p2%10),3)&&control(p1*((p2/10)%10),3))
		return 1;
	return 0;
}

int control(int n, int d)
{
	if(n==0)
		return in(0);
	int a=n;
	while(n>0)
	{
		if(in(n%10))
			n/=10;
		else return 0;
	}
	n=a;
	switch(d)
	{
		case 2:
			return (n>9&&n<100);
		case 3:
			return (n>99&&n<1000);
		case 4:
			return (n>999&&n<10000);
	}
	return 0;
}

int main()
{
	FILE *in = fopen("crypt1.in" ,"r"),
		*out = fopen("crypt1.out","w");

	int n,i,ans=0;
	fscanf(in,"%d",&n);
	digits = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		fscanf(in,"%d",digits+i);
	fclose(in);
	x=n;

	for(i=100;i<1000;i++)
		if(control(i,3))
			for(n=10;n<100;n++)
				if(control(n,2))
					if(partials(i,n))
						ans++;
	fprintf(out,"%d\n",ans);
	fclose(out);

	return 0;
}
