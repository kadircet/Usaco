/*
NAME:kadirce1
PROG:sprime
LANG:C
*/
#include <stdio.h>
#include <stdlib.h>

int length;

int pow10(int n)
{
	switch(n)
	{
		case 0:
			return 1;
		case 1:
			return 10;
		case 2:
			return 100;
		case 3:
			return 1000;
		case 4:
			return 10000;
		case 5:
			return 100000;
		case 6:
			return 1000000;
		case 7:
			return 10000000;
		case 8:
			return 100000000;
	}
	return 1;
}

int get(int number, int n)
{
	return number/pow10(length-n);
}

int isPrime(int n)
{
	if(n==2||n==3||n==5||n==7||n==11)return 1;
	if(n%2==0)return 0;
	int i;
	for(i=3;i*i<=n;i+=2)
		if(n%i==0)
			return 0;
	return 1;
}

int main()
{
	int i,j,isp=1;

	freopen("sprime.in","r",stdin);
	scanf("%d",&length);
	fclose(stdin);

	freopen("sprime.out","w",stdout);
	for(i=2*pow10(length-1)+1;i<4*pow10(length-1);)
	{
		j=i;
		while(j>9)
		{
			if(j%10==5)
			{
				isp=0;
				break;
			}
			if((j%10)%2==0)
			{
				isp=0;
				break;
			}
			j/=10;
		}
		if(isp==1)
			for(j=0;j<length;j++)
			{
				if(!isPrime(get(i,j+1)))
				{
					isp=0;
					break;
				}
			}
		if(isp==1)
			printf("%d\n",i);
		isp=1;
		if(i%10==3)i+=4;
		else i+=2;
	}
	for(i=5*pow10(length-1)+1;i<6*pow10(length-1);)
	{
		j=i;
		while(j>9)
		{
			if(j%10==5)
			{
				isp=0;
				break;
			}
			if((j%10)%2==0)
			{
				isp=0;
				break;
			}
			j/=10;
		}
		if(isp==1)
			for(j=0;j<length;j++)
			{
				if(!isPrime(get(i,j+1)))
				{
					isp=0;
					break;
				}
			}
		if(isp==1)
			printf("%d\n",i);
		isp=1;
		if(i%10==3)i+=4;
		else i+=2;
	}
	for(i=7*pow10(length-1)+1;i<8*pow10(length-1);)
	{
		j=i;
		while(j>9)
		{
			if(j%10==5)
			{
				isp=0;
				break;
			}
			if((j%10)%2==0)
			{
				isp=0;
				break;
			}
			j/=10;
		}
		if(isp==1)
			for(j=0;j<length;j++)
			{
				if(!isPrime(get(i,j+1)))
				{
					isp=0;
					break;
				}
			}
		if(isp==1)
			printf("%d\n",i);
		isp=1;
		if(i%10==3)i+=4;
		else i+=2;
	}
	fclose(stdout);

	return 0;
}
