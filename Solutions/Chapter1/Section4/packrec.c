/*
PROG: packrec
NAME: kadirce1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _rect
{
	int w,h;
}rect;

rect Rotate(rect in)
{
	rect t;
	t.w=in.h;
	t.h=in.w;
	return t;
}

int max(int i, int j)
{
	return (i>j)?i:j;
}

int max3(int i, int j, int k)
{
	return max(max(i,j),k);
}

int max4(int i, int j, int k, int l)
{
	return max(max3(i,j,k),l);
}

rect rects[4],answ[100];
int pers[24][4],x,min=1000000,count;

void check(int w, int h)
{
	rect t;
	t.w=w;
	t.h=h;

	if(w==5&&h==8)return;
	if(w>h)
	{
		int tw=w;
		w=h;
		h=tw;
		t=Rotate(t);
	}
	if(w*h<min)
	{
		int i;
		for(i=0;i<count;i++)
			answ[i].w=answ[i].h=0;
		answ[0]=t;
		count=1;
		min=w*h;
	}
	else if(w*h==min)
	{
		int i;
		for(i=0;i<count;i++)
			if(answ[i].w==t.w)
				return;
		/*i=0;
		while(answ[i].w!=0&&t.w>answ[i].w)i++;
		int index=i;
		for(i=count;i>index;i--)
			answ[i]=answ[i-1];*/
		answ[count]=t;
		count++;
	}
}

void swap(int *v, int i, int j)
{
    int t=v[i];
    v[i]=v[j];
    v[j]=t;
}

void RotateLeft(int *v, int start, int n)
{
    int t=v[start];
    int i;
    for(i=start;i<n-1;i++)
        v[i]=v[i+1];
    v[n-1]=t;
}

void assignper(int *v)
{
    int i;
    for(i=0;i<4;i++)
        pers[x][i]=v[i];
    x++;
}

void permute(int *v, int start, int n)
{
    assignper(v);
    if(start<n)
    {
        int i,j;
        for(i=n-2;i>=start;i--)
        {
            for(j=i+1;j<n;j++)
            {
                swap(v,i,j);
                permute(v,i+1,n);
            }
            RotateLeft(v, i, n);
        }
    }
}

void getmin()
{
	int p;
	for(p=0;p<24;p++)
	{
		rect one=rects[pers[p][0]],two=rects[pers[p][1]],three=rects[pers[p][2]],four=rects[pers[p][3]];
		int a,b,c,d;
		for(a=0;a<2;a++,one=Rotate(one))
		{
			for(b=0;b<2;b++,two=Rotate(two))
			{
				for(c=0;c<2;c++,three=Rotate(three))
				{
					for(d=0;d<2;d++,four=Rotate(four))
					{
						int ow=one.w + two.w + three.w + four.w;
						int oh=max(max3(one.h,two.h,three.h),four.h);
						check(ow,oh);

						int tw=max(one.h,two.w+three.w+four.w);
						int th=one.w+max3(two.h,three.h,four.h);
						check(tw,th);

						int thw = four.w+max(one.h,two.w+three.w);
						int thh = max(four.h , one.w+max(two.h,three.h));
						check(thw,thh);

						int fw = one.w+max(two.w,three.w)+four.w;
						int fh = max3(one.h,two.h+three.h,four.h);
						check(fw,fh);

						int fiw = max(one.w,two.w) + three.w+four.w;
						int fih = max3(one.h+two.h,three.h,four.h);
						check(fiw,fih);

						int sw=one.w+four.w;

						if (one.h<four.h)
							sw=max(one.w+four.w,two.w+four.w);
						if (one.h+two.h>four.h)
							sw=max(sw,two.w+three.w);
						if (one.h>four.h)
							sw=max(sw,one.w+three.w);
						sw=max(max(sw,two.w),three.w);

						int sh = max(one.h+two.h,three.h+four.h);
						check(sw,sh);
					}
				}
			}
		}
	}
}

int cmpr(const void *a, const void *b)
{
	rect *c, *d;
	c=(rect*)a;
	d=(rect*)b;
	return c->w - d->w;
}

int main()
{
	int i=0;
	FILE *in = fopen("packrec.in", "r"),
		*out = fopen("packrec.out","w");

	for(;i<4;i++)
		fscanf(in,"%d %d", &rects[i].w, &rects[i].h);
	fclose(in);

	int v[]={0,1,2,3};
	permute(v,0,4);

	getmin();
	qsort(answ, count, sizeof(rect), cmpr);

	fprintf(out,"%d\n",answ[0].w*answ[0].h);
	for(i=0;i<count;i++)
		fprintf(out,"%d %d\n",answ[i].w,answ[i].h);
	fclose(out);

	return 0;
}
