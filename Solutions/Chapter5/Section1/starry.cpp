/*
ID:kadirce1
LANG:C++
PROG:starry
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int nc;
int pat[500];
int inp[100][100];
int W,H;
struct cluster
{
	char** c;
	int w,h;
	
	void reflect()
	{
		for(int i=0;i<h/2;i++)
			swap(c[i], c[h-i-1]);
	}
	
	void rotate()
	{
		char **nc=new char*[w];
		for(int i=0;i<w;i++)
			nc[i]=new char[h];
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				nc[j][i]=c[h-i-1][j];
		swap(w,h);
		c=nc;
	}
	
	void print()
	{
		for(int i=0;i<h;i++, cout<<endl)
			for(int j=0;j<w;j++)
				if(c[i][j]!='0')
					cout << char(c[i][j]);
				else
					cout << 0;
		cout << endl;
	}
	
	char*& operator[](int idx) const
	{
		return c[idx];
	}
	
	bool operator==(const cluster& cl) const
	{
		if(cl.h!=h || cl.w!=w)
			return false;
		
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(cl[i][j]!=c[i][j])
					return false;
		
		return true;
	}
};

vector<cluster> patterns;
int dx[] = {1,1,1,-1,-1,-1,0,0,0};
int dy[] = {1,-1,0,1,-1,0,1,-1,0};

int lef[500],rig[500];
int top[500],bot[500];
void search(int r, int c)
{
	if(r<0||c<0||r>=H||c>=W||inp[r][c]!='1')
		return;
	
	int cl=nc;
	inp[r][c]=-cl-1;
	lef[cl]=min(lef[cl], c);
	rig[cl]=max(rig[cl], c);
	top[cl]=min(top[cl], r);
	bot[cl]=max(bot[cl], r);
	for(int i=0;i<9;i++)
		search(r+dy[i],c+dx[i]);
}

int match(cluster& c)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<patterns.size();j++)
			if(c==patterns[j])
				return j;
		c.rotate();
	}
	c.reflect();
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<patterns.size();j++)
			if(c==patterns[j])
				return j;
		c.rotate();
	}
	return -1;
}

int main()
{
	memset(lef, 101, sizeof(lef));
	memset(top, 101, sizeof(top));
	
	freopen("starry.in", "r", stdin);
	cin >> W >> H;
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			cin >> (char&)inp[i][j];
	fclose(stdin);
	
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			if(inp[i][j]=='1')
			{
				search(i, j);
				int cl=nc;
				cluster c;
				c.w=rig[cl]-lef[cl]+1;
				c.h=bot[cl]-top[cl]+1;
				c.c = new char*[c.h];
				for(int i=0;i<c.h;i++)
					c[i]=new char[c.w];
				
				for(int i=0;i<c.h;i++)
					for(int j=0;j<c.w;j++)
						c[i][j] = inp[top[cl]+i][lef[cl]+j]==-cl-1?'1':'0';
				if(cl==15)
					c.print();
				nc++;
				int m=match(c);
				if(m==-1)
				{
					pat[cl]=patterns.size();
					patterns.push_back(c);
				}
				else
					pat[cl]=m;
			}
	
	freopen("starry.out", "w", stdout);
	for(int i=0;i<H;i++,cout<<endl)
		for(int j=0;j<W;j++)
		{
			if(inp[i][j]!='0')
			{
				int cl=-inp[i][j]-1;
				cout << char(pat[cl]+'a');
			}
			else
				cout << 0;
		}
	fclose(stdout);
	
	return 0;
}

