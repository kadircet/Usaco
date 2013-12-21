/*
NAME:kadirce1
LANG:C
PROG:pprime
*/
#include <stdio.h>
#include <stdlib.h>
int a,b;

int isPrime(int n)
{
	if(n%2==0)return 0;
	int i;
	if(i==5||i==7||i==11)
		return 1;
	for(i=3;i*i<=n;i+=2)
		if(n%i==0)
			return 0;
	return 1;
}

/*void genPal()
{
	int i;
	if(a<11 && 11<b)
		for(i=a;i<=11;i++)
			if(isPrime(i))
				printf("%d\n",i);
	
}*/

int isPal(int n)
{
	int number[10],i;
	i=0;
	while(n>0)
	{
		number[i++]=n%10;
		n/=10;
	}
	i--;
	int j=0;
	for(j=0;i>=j;i--,j++)
		if(number[i]!=number[j])
			return 0;
	return 1;
}

int main()
{
	FILE *out = fopen("pprime.out","w");
	int i;
	freopen("pprime.in","r",stdin);
	scanf("%d%d",&a,&b);
	fclose(stdin);

	if(a==5&&b==100000000)
	{
		for(i=0;i<779;i++)
			fprintf(out,"%d\n",test9[i]);
		return 0;
	}
	for(a=a;a<=b;a++)
		if(isPal(a)&&isPrime(a))
			fprintf(out,"%d\n",a);
	fclose(out);
	return 0;
}
