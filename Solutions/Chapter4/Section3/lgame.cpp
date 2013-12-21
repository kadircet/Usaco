/*
ID:kadirce1
LANG:C++
PROG:lgame
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N ('z'-'a'+1)
using namespace std;

int points[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
string inp;
int used[N];
int best;
vector<string> sol;

class TRIE
{
	public:
		TRIE *next[N];
		char val;
		bool end;
		
		TRIE(char val, bool end)
		{
			this->val=val;
			this->end=end;
			
			for(int i=0;i<N;i++)
				this->next[i]=NULL;
		}
};

TRIE* dict = new TRIE(0, false);

void insertTrie(TRIE* root, string word)
{
	for(int i=0;i<word.length();i++)
	{
		if(root->next[word[i]-'a']==NULL)
			root->next[word[i]-'a']=new TRIE(word[i], false);
		
		root = root->next[word[i]-'a'];
	}
	root->end = true;
}

bool searchTrie(TRIE* root, string word)
{
	if(word.find(' ')!=string::npos)
		word=word.substr(word.find(' ')+1);
	
	for(int i=0;i<word.length();i++)
	{
		if(root->next[word[i]-'a']==NULL)
			return false;
		
		root = root->next[word[i]-'a'];
	}
	
	return root->end;
}

void printTrie(TRIE* root, string cur="")
{
	if(root->val!=0)
		cur += root->val;
	if(root->end)
		cout << cur << endl;
		
	for(int i=0;i<N;i++)
		if(root->next[i]!=NULL)
			printTrie(root->next[i], cur);
}

void search(string str="")
{
	if(searchTrie(dict, str))
	{
		int p=0;
		for(int i=0;i<str.length();i++)
			if(str[i]!=' ')
				p+=points[str[i]-'a'];
		
		if(p>best)
		{
			best=p;
			sol.clear();
		}
		
		if(p==best)
		{
			if(str.find(' ')!=string::npos)
			{
				string w1=str.substr(0, str.find(' '));
				string w2=str.substr(str.find(' ')+1);
				
				if(w1>w2)
					str= w2 + ' ' + w1;
			}
			sol.push_back(str);
		}

		search(str + " ");
	}
	
	for(int i=0;i<inp.length();i++)
	{
		if(used[inp[i]-'a']>0)
		{
			used[inp[i]-'a']--;
			search(str+inp[i]);
			used[inp[i]-'a']++;
		}
	}
}

int main()
{	
	freopen("lgame.in", "r", stdin);
	cin >> inp;
	for(int i=0;i<inp.length();i++)
		used[inp[i]-'a']++;
	fclose(stdin);
	
	string word;
	freopen("lgame.dict", "r", stdin);
	cin >> word;
	while(word!=".")
	{
		insertTrie(dict, word);
		cin >> word;
	}
	fclose(stdin);
	
	search();
	
	freopen("lgame.out", "w", stdout);
	cout << best << endl;
	sort(sol.begin(), sol.end());
	sol.resize(unique(sol.begin(), sol.end()) - sol.begin());
	for(int i=0;i<sol.size();i++)
		cout << sol[i] << endl;
	fclose(stdout);
	
	return 0;
}

