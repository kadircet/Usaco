/*
NAME:kadirce1
PROG:milk3
LANG:C
*/
#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

int A,B,C;
int v[21][21];

void cal(int b,int c)
{
	int a, temp;

	if (v[b][c]) return;
	v[b][c] = 1;
	a = C-b-c;
	temp = MIN(a,B-b);
	if (temp) cal(b+temp,c);
	temp = MIN(b,A-a);
	if (temp) cal(b-temp,c);
	temp = MIN(b,C-c);
	if (temp) cal(b-temp,c+temp);
	temp = MIN(c,B-b);
	if (temp) cal(b+temp,c-temp);
	temp = MIN(a,C-c);
	if (temp) cal(b,c+temp);
	temp = MIN(c,A-a);
	if (temp) cal(b,c-temp);
}

int main()
{
	int f = 1;
	register int i,j;
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);

	scanf("%d%d%d", &A, &B, &C);
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)
			v[i][j]=0;
	cal(0,C);
	for (i = 0 ; i <= C ; i++)
	{
		if (v[C-i][i])
		{
			if (f)
				printf("%d",i);
			else
				printf(" %d",i);
			f = 0;
		}
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);

	return 0;
}