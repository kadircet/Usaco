/*
ID: kadirce1
LANG: C
PROG: transform
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int z;

/*void bas(char* a)
{
	int i,j;
    for(i=0;i<z;i++,puts(""))
        for(j=0;j<z;j++,a++)
            printf("%c",*a);
	puts("1");
}*/

char* ninety(char* a)
{
	char* t;
	int p=strlen(a);
	t=(char*)malloc(sizeof(char)*p);
	int i,j;
	for(j=0;j<z;j++)
		for(i=1;i<=z;i++)
			*(t+i-1+(z*j))=*(a+p-(z*i)+j);
	*(t+p)=0;
	//bas(t);
	return t;
}

char* reflect(char* a)
{
	char* t;
	int p=strlen(a),i,j;
	t=(char*)malloc(sizeof(char)*p);
	a=a+strlen(a)-z;
    for(i=z;i>0;i--,a-=z)
        for(j=0;j<z;j++)
            *(t+j+z*(z-i))=*(a+j);
	*(t+p)=0;
	return t;
}

char* reflect1(char* a)
{
	char* t;
	int p=strlen(a),i,j;
	t=(char*)malloc(sizeof(char)*p);
	a=a+z-1;
    for(i=z;i>0;i--,a+=z)
        for(j=0;j<z;j++)
            *(t+j+z*(z-i))=*(a-j);
	*(t+p)=0;
	return t;
}

int isreflect(char* a,char *b)
{
	return (!strcmp(reflect(a),b)||!strcmp(ninety(reflect(a)),b)||!strcmp(ninety(ninety(reflect(a))),b)||!strcmp(ninety(ninety(ninety(reflect(a)))),b));
}

int control(char* a,char* b)
{
	//if(z==6)return 1;
	if(!strcmp(ninety(a),b))
		return 1;
	else if(!strcmp(ninety(ninety(a)),b))
		return 2;
	else if(!strcmp(ninety(ninety(ninety(a))),b))
		return 3;
	else if(!strcmp(reflect1(a),b))
		return 4;
	else if(isreflect(a,b))
		return 5;
	else if(!strcmp(a,b))
		return 6;
	return 7;
}

void main()
{
	FILE *in=fopen("transform.in","r");
	int i;
	fscanf(in,"%d",&z);
	char a[z][z];
	char b[z][z];
	for(i=0;i<z;i++)
		fscanf(in,"%s\n",&a[i]);
	for(i=0;i<z;i++)
		fscanf(in,"%s\n",&b[i]);
	fclose(in);
	//bas((char*)a);
	//bas((char*)b);
	FILE *out=fopen("transform.out","w");
	fprintf(out,"%d\n",control((char*)a,(char*)b));
	fclose(out);
	exit(0);
}
