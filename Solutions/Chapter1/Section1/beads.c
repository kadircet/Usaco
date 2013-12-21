/*
ID: kadirce1
LANG: C
PROG: beads
*/

#include <stdio.h>
#include <stdlib.h>

#define LONG 400

char necklace[LONG];
int len;

int mod(int n, int m)
{
    while(n<0)
        n+=m;
    return n%m;
}

int nbreak(int p, int dir)
{
    char color = 'w';
    int i,n;
    
    if (dir>0)
        i=p;
    else
        i = mod(p-1, len);
        
    for(n=0;n<len;n++,i=mod(i+dir,len))
    {
        if(color=='w'&&necklace[i]!='w')
            color=necklace[i];
        
        if(color!='w'&&necklace[i]!='w'&&necklace[i]!=color)
            break;
    }
    return n;
}

void main()
{
    FILE *in,*out;
    in = fopen("beads.in","r");
    out = fopen("beads.out","w");
    
    fscanf(in,"%d %s",&len,necklace);
    
    int i,n,m=0;
    
    for(i=0;i<len;i++)
    {
        n = nbreak(i,1) + nbreak(i,-1);
        if(n>m)
            m=n;
    }
    
    if(m>len)
        m=len;
        
    fprintf(out,"%d\n",m);
    exit(0);
}
