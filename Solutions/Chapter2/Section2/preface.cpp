/*
ID:kadirce1
LANG:C++
PROG:preface
*/

#include <iostream>
#include <fstream>
using namespace std;

int N;
int I[3501], V[3501], X[3501];	//1 5 10
int L[3501], C[3501], D[3501];	//50 100 500
int M[3501];				 	//1000

int main()
{
	ifstream inp("preface.in");
	ofstream oup("preface.out");
	
	inp >> N;
	I[1] = 1;I[2] = 2;I[3] = 3;I[4] = 1;
	V[4] = V[5] = V[6] = V[7] = V[8] = 1;
	X[9] = 1;X[10]=1;X[20]=2;X[30]=3;X[40]=1;
	L[40]=L[50]=L[60]=L[70]=L[80]=1;
	C[90]=1;C[100]=1;C[200]=2;C[300]=3;C[400]=1;
	D[400]=D[500]=D[600]=D[700]=D[800]=1;
	M[900]=M[1000]=1;M[2000]=2;M[3000]=3;
	for(int i=1;i<=N;i++)
	{
		int o=i;
		I[i] = I[i%5];
		V[i] = V[i%10];
		
		o = i%100;
		X[i] = X[((o/10)%5)*10] + X[o%10];
		L[i] = L[(o/10)*10];
		
		o=i%1000;
		C[i] = C[((o/100)%5)*100] + C[((o/10)*10)%100];
		D[i] = D[(o/100)*100];
		
		M[i] = M[((i/1000)%5)*1000] + M[((i/100)*100)%1000];
	}
	for(int i=1;i<N;i++)
	{
		I[N] += I[i];
		V[N] += V[i];
		X[N] += X[i];
		L[N] += L[i];
		C[N] += C[i];
		D[N] += D[i];
		M[N] += M[i];
	}
	
	if(I[N]!=0)
		oup << "I " << I[N] << endl;
	if(V[N]!=0)
		oup << "V " << V[N] << endl;
	if(X[N]!=0)
		oup << "X " << X[N] << endl;
	if(L[N]!=0)
		oup << "L " << L[N] << endl;
	if(C[N]!=0)
		oup << "C " << C[N] << endl;
	if(D[N]!=0)
		oup << "D " << D[N] << endl;
	if(M[N]!=0)
		oup << "M " << M[N] << endl;
		
	return 0;
}

