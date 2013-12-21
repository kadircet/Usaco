/*
ID: kadirce1
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

vector<int> seq;
int seqs[3];
int nchanges;
int N;

void printSeq()
{
	for(int i=0;i<seq.size();i++)
		cout << seq[i] << endl;
	cout << "---------" << endl;
}

int main()
{
	ifstream inp("sort3.in");
	ofstream oup("sort3.out");
	int k;
	
	inp >> N;
	for(int i=0;i<N;i++)
	{
		inp >> k;
		seqs[k-1]++;
		seq.push_back(k-1);
	}
	seqs[1] += seqs[0];
	seqs[2] = N;
	for(int p=0;p<3;p++)
	{
		int s = p==0?p:seqs[p-1];
		for(int i=s;i<seqs[p];i++)
		{
			int q = seq[i];
			if(q!=p)
			{
				for(int j=seqs[q-1];j<seqs[q];j++)
				{
					if(seq[j]==p)
					{
						swap(seq[i], seq[j]);
						nchanges++;
						break;
					}
				}
			}
		}
	}
	
	int miss=0;
	for(int p=0;p<3;p++)
	{
		int s = p==0?p:seqs[p-1];
		for(int i=s;i<seqs[p];i++)
		{
			int q = seq[i];
			if(q!=p)
				miss++;
		}
	}
	
	oup << nchanges + 2*(miss/3) << endl;
	
	return 0;
}

