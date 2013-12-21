/*
ID: kadirce1
LANG: C
PROG: friday
*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *in = fopen("friday.in", "r");
	FILE *out= fopen("friday.out","w");

	int y;
	fscanf(in,"%d\n",&y);
	fclose(in);
	
	int i,a,g,c=2;
	int x[7];

	for (i=0;i<7;i++)
		x[i] = 0;

	for (i=0;i<y;i++)
	{
		for (a=1;a<13;a++)
		{
			if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
			{
				for (g=1;g<32;g++)
				{
					c++;
					if (c>7)
						c=1;
					if (g==13)
						x[c-1]++;
				}
			}
			else if (a==2)
			{
				if((1900+i)%400==0)
				{
					for (g=1;g<30;g++)
					{
						c++;
						if(c>7)
							c=1;
						if(g==13)
							x[c-1]++;
					}
				}
				else if (((1900+i)%4==0)&&((1900+i)%100)!=0)
				{
					for (g=1; g<30; g++)
					{
						c++;
						if (c>7)
							c=1;
						if(g==13)
							x[c-1]++;
					}
				}
				else
				{
					for (g=1; g<29; g++)
					{
						c++;
						if(c>7)
							c=1;
						if (g==13)
							x[c-1]++;
					}
				}
			}
			else
			{
				for (g=1;g<31;g++)
				{
					c++;
					if (c>7)
						c=1;
					if (g==13)
						x[c-1]++;
				}
			}
		}
	}

	for (i=0;i<7;i++)
	{
		if(i<6)
			fprintf(out,"%d ",x[i]);
		else
			fprintf(out,"%d\n",x[i]);
	}
	fclose(out);
	exit(0);
}
