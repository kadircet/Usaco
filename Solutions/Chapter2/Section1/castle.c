/*
PROG:castle
ID:kadirce1
LANG:C
*/
#include <stdio.h>
#include <stdlib.h>

int M,N;
int castle[50][50];
int visit[50][50];
int rooms[2500];
int roommax;
int avaibmax;
int breakrow, breakcol, breakdir;
int ncomp;

void visitf(int row, int col, int comp)
{
	if (visit[row][col]!=0)
		return;
	visit[row][col] = comp;
	rooms[comp]++;
	if (rooms[comp]>roommax)
		roommax = rooms[comp];
	int wall = castle[row][col];
	if (!(wall & 0x01))
		visitf(row, col-1, comp);
	if (!(wall & 0x02))
		visitf(row-1, col, comp);
	if (!(wall & 0x04))
		visitf(row, col+1, comp);
	if (!(wall & 0x08))
		visitf(row+1, col, comp);
}

void breakwall(int row, int col)
{
	int cur = visit[row][col];
	int N = row>0?visit[row-1][col]:0;
	int E = col<M-1?visit[row][col+1]:0;
	if (N!=cur && N!=0 && avaibmax < rooms[cur] + rooms[N])
	{
		avaibmax = rooms[cur] + rooms[N];
		breakrow = row;
		breakcol = col;
		breakdir = 0;
	}
	if (E!=cur && E!=0 && avaibmax < rooms[cur] + rooms[E])
	{
		avaibmax = rooms[cur] + rooms[E];
		breakrow = row;
		breakcol = col;
		breakdir = 1;
	}
}

int main()
{
	freopen("castle.in", "r", stdin);
	scanf("%d%d", &M, &N);
	int i,j;
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
		{
			scanf("%d", &castle[i][j]);
			visit[i][j] = 0;
		}
	fclose(stdin);
	
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
			if (visit[i][j]==0)
				visitf(i, j, 1+ncomp++);

	for (i=0; i<M; i++)
		for (j=N-1; j>=0; j--)
			breakwall(j, i);

	freopen("castle.out", "w", stdout);
	printf("%d\n%d\n%d\n", ncomp, roommax, avaibmax);
	printf("%d %d %c\n", breakrow+1, breakcol+1, breakdir==0?'N':'E');
	fclose(stdout);
	return 0;
}
