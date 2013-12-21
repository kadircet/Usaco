/*
USER: kadirce1
PROG: milk2
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Milking
{
	int begin;
	int end;
}Milking;

int nmilking;

Milking milking[5000];

int milkcmp(const void *va, const void *vb)
{
    Milking *a, *b;

    a = (Milking*)va;
    b = (Milking*)vb;

    if(a->begin > b->begin)
		return 1;
    if(a->begin < b->begin)
		return -1;
    return 0;
}

void main(void)
{
    FILE *fin, *fout;
    int i, j, t, tmilk, tnomilk;
    Milking cur;

    fin = fopen("milk2.in", "r");
    fout = fopen("milk2.out", "w");

    fscanf(fin, "%d", &nmilking);
    for(i=0; i<nmilking; i++)
		fscanf(fin, "%d %d", &milking[i].begin, &milking[i].end);

    qsort(milking, nmilking, sizeof(Milking), milkcmp);

    tmilk = 0;
    tnomilk = 0;
    cur = milking[0];
    for(i=1; i<nmilking; i++) 
	{
		if(milking[i].begin > cur.end) 
		{
			t = milking[i].begin - cur.end;
			if(t > tnomilk)
				tnomilk = t;

			t = cur.end - cur.begin;
			if(t > tmilk)
				tmilk = t;

			cur = milking[i];
		} 
		else if(milking[i].end > cur.end)
			cur.end = milking[i].end;
    }

    t = cur.end - cur.begin;
    if(t > tmilk)
		tmilk = t;

    fprintf(fout, "%d %d\n", tmilk, tnomilk);
    exit(0);
}
