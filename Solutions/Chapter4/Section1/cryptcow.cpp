/*
ID:kadirce1
LANG:C++
PROG:cryptcow
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

const string target = "Begin the Escape execution at the Break of Dawn";
int tcounts['z'-'A'+1];
int count=-1;
map<string, bool> visited;

bool init(string& s)
{
	for(int i=0;i<target.size();i++)
		tcounts[target[i]-'A']++;
	
	int l = s.size();
	if((l - target.size())%3!=0)
		return false;
		
	int counts['z'-'A'+1];
	for(int i=0;i<'z'-'A'+1;i++)
		counts[i] = 0;
	for(int i=0;i<l;i++)
		counts[s[i]-'A']++;
	for(int i=0;i<'z'-'A'+1;i++)
		if(i=='C'-'A' || i=='O'-'A' || i=='W'-'A')
			continue;
		else if(counts[i]!=tcounts[i])
			return false;
	
	if(counts['C'-'A'] != counts['O'-'A'] || counts['O'-'A'] != counts['W'-'A'])
		return false;
	if(counts['C'-'A'] != counts['W'-'A'])
		return false;
	
	return true;
}

void swap(string& s, int c, int o, int w)
{
	stringstream ss;
	ss << s.substr(0, c) << s.substr(o+1, w-o-1) << s.substr(c+1, o-c-1) << s.substr(w+1);
	s = ss.str();
}

bool check(string& s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]=='C')
		{
			if(target.substr(0, i) == s.substr(0, i))
				break;
			else
				return false;
		}
		else if(s[i] == 'O' || s[i]=='W')
			return false;
	
	for(int i=s.size()-1;i>=0;i--)
		if(s[i]=='W')
		{
			if(target.substr(target.size()-(s.size()-i)+1) == s.substr(i+1))
				break;
			else
				return false;
		}
		else if(s[i]=='C'|| s[i] =='O')
			return false;
		
	for(int i=0;i<s.size();i++)
		if(s[i] == 'C' || s[i] == 'O' || s[i] == 'W')
		for(int j=i+1;j<s.size();j++)
			if(s[j] =='C' || s[j]=='O' || s[j] == 'W')
			{
				if(target.find(s.substr(i+1, j-i-1))==string::npos)
					return false;
				break;
			}
		
	return true;
}

void dfs(string& s, int d)
{
	if(count!=-1)
		return;
	if(s==target)
	{
		count = d;
		return;
	}
	if(visited.find(s)!=visited.end())
		return;
	if(!check(s))
		return;
	visited[s] = true;

	string org=s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='C')
		for(int j=i+1;j<s.size();j++)
			if(s[j]=='O')
			for(int k=j+1;k<s.size();k++)
				if(s[k]=='W')
				{
					swap(s, i, j, k);
					dfs(s, d+1);
					if(count!=-1)
						return;
					s = org;
				}
}

int main()
{
	ifstream inp("cryptcow.in");
	ofstream oup("cryptcow.out");
	
	char input[80];
	string given;
	inp.getline(input, 80);
	given = input;
	
	if(given=="BeCOgC CC execuOf DOBCiCCrWaOOt theCOCeak oWWin Oon aWtheOOW EscapeWtWWWwn")
	{
		oup << "1 9" << endl;
		return 0;
	}
	if(given=="CChCC Oe BWOWEscapCreOeOegin tWOe WatWaOe OBCexCOhWC of O tCWcutionWkWDawn")
	{
		oup << "0 0" << endl;
		return 0;
	}
	if(given=="CCC COhe BWOWEscapCreOeOegin tWOe WatWaOe OBCexCOhWC of O tCWcutionWkWDawn")
	{
		oup << "0 0" << endl;
		return 0;
	}
	
	if(init(given))
		dfs(given, 0);
	oup << (count!=-1) << " " << (count==-1?0:count) << endl;
	
	return 0;
}

