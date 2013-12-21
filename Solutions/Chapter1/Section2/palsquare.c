/*
ID: kadirce1
LANG: C
PROG: palsquare
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base[]={48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74};

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

int square(int n)
{
    return n*n;
}

int ispal(char* a)
{
    if(strlen(a)==1)return 1;
    char *c=(char*)malloc(sizeof(char)*strlen(a));
    int d;
    for(d=0;d<strlen(a);d++)
        c[d]=a[strlen(a)-d-1];
    if(!strcmp(a,c))return 1;
    return 0;
}

void main()
{
    char *a=(char*)malloc(sizeof(char)*128);
    int b,i;
    FILE *in = fopen("palsquare.in","r");
    fscanf(in,"%d",&b);
    fclose(in);
    FILE *out=fopen("palsquare.out","w");
    for(i=1;i<=300;i++)
        if(ispal(convert(square(i),b)))
            fprintf(out,"%s %s\n",convert(i,b),convert(square(i),b));
    fclose(out);
    exit(0);
}
