/*
ID:kadirce1
LANG:C++
PROG:concom
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int C[101][101];
bool O[101][101];
int N;

int main()
{
	ifstream inp("concom.in");
	ofstream oup("concom.out");
	
	inp >> N;
	int a,b,p;
	for(int i=0;i<N;i++)
	{
		inp >> a >> b >> p;
		C[a][b] = p;
		O[a][a] = O[b][b] = true;
		if(p>50)
			O[a][b] = true;
	}
	
	bool changed = true;
	while(changed)
	{
		changed = false;
		for(int i=1;i<=100;i++)
		{
			for(int j=1;j<=100;j++)
			{
				if(i==j)
					continue;
				int op=0;
				for(int k=1;k<=100;k++)
				{
					if(O[i][k])
						op += C[k][j];
				}
				if(op>50 && !O[i][j])
				{
					O[i][j] = true;
					changed = true;
				}
			}
		}
	}
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			if(O[i][j] && i!=j)
				oup << i << " " << j << endl;
	
	return 0;
}

