/*
ID: kadirce1
LANG: C
PROG: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char num[12],sol[12];
char dict[5000][13];
int maxlen,len,ns=0;
FILE *out;

void calc (int cl, int low, int high) 
{
	if(cl==maxlen)
	{
		sol[cl]=0;
		int x;
		for(x=low;x<high;x++)
		{
			if(!strcmp(sol,dict[x]))
			{
				fprintf(out,"%s\n",sol);
				ns++;
			}
		}
		return;
	}
	if(cl>0)
	{
		int x;
		for(x=low;x<=high;x++)
		{
			if(sol[cl-1]==dict[x][cl-1])
			{
				low=x;
				while(sol[cl-1]==dict[x][cl-1])x++;
				high=x;
				break;
			}
			if(x==high)return;
		}
	}
	if(low>high)return;
	switch(num[cl])
	{
		case '2':
			sol[cl]='A';calc(cl+1,low,high);
			sol[cl]='B';calc(cl+1,low,high);
			sol[cl]='C';calc(cl+1,low,high);
			break;
		case '3':
			sol[cl]='D';calc(cl+1,low,high);
			sol[cl]='E';calc(cl+1,low,high);
			sol[cl]='F';calc(cl+1,low,high);
			break;
		case '4':
			sol[cl]='G';calc(cl+1,low,high);
			sol[cl]='H';calc(cl+1,low,high);
			sol[cl]='I';calc(cl+1,low,high);
			break;
		case '5':
			sol[cl]='J';calc(cl+1,low,high);
			sol[cl]='K';calc(cl+1,low,high);
			sol[cl]='L';calc(cl+1,low,high);
			break;
		case '6':
			sol[cl]='M';calc(cl+1,low,high);
			sol[cl]='N';calc(cl+1,low,high);
			sol[cl]='O';calc(cl+1,low,high);
			break;
		case '7':
			sol[cl]='P';calc(cl+1,low,high);
			sol[cl]='R';calc(cl+1,low,high);
			sol[cl]='S';calc(cl+1,low,high);
			break;
		case '8':
			sol[cl]='T';calc(cl+1,low,high);
			sol[cl]='U';calc(cl+1,low,high);
			sol[cl]='V';calc(cl+1,low,high);
			break;
		case '9':
			sol[cl]='W';calc(cl+1,low,high);
			sol[cl]='X';calc(cl+1,low,high);
			sol[cl]='Y';calc(cl+1,low,high);
			break;
	}
}

void main()
{
	FILE *in=fopen ("namenum.in", "r");
	FILE *in2=fopen ("dict.txt", "r");
	out=fopen ("namenum.out","w");

	while(fscanf(in2,"%s",dict[len++])!=EOF);
	fscanf (in, "%s",&num);

	fclose(in);
	fclose(in2);

	maxlen = strlen(num);

	calc (0, 0, len);

	if (!ns) fprintf(out,"NONE\n");

	fclose(out);

	exit(0);
}
