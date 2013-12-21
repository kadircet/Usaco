/*
ID: kadirce1
LANG: C
PROG: ride
*/

#include <stdio.h>
#include <stdlib.h>

int carp(char *x)
{
    int p=1;
    int i;
    for(;;)
    {
            if (*x)
            {
                   *x=*x%64;
                   p*=*x++;
            }
            else
                break;
    }
    return p;
}

void main()
{
    char a[100],b[100];
    FILE *in=fopen("ride.in","r"), *out=fopen("ride.out","w");
    fscanf(in,"%s\n%s\n",a,b);
    fclose(in);
    if(carp(a)%47==carp(b)%47)
        fprintf(out,"GO\n");
    else
        fprintf(out,"STAY\n");
    fclose(out);
    exit(0);
}
