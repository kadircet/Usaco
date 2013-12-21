/*
ID:kadirce1
LANG:C++
PROG:heritage
*/

#include <iostream>
#include <fstream>
using namespace std;

string inorder, preorder;

string postorder(string s)
{
	if(s.size()==0)
		return s;
	char root = preorder[0];
	preorder = preorder.substr(1);
	
	int rootid = s.find(root);
	string leftsub = s.substr(0, rootid);
	leftsub = postorder(leftsub);
	string rightsub = s.substr(rootid+1);
	rightsub = postorder(rightsub);
	return leftsub + rightsub + root;
}

int main()
{
	ifstream inp("heritage.in");
	ofstream oup("heritage.out");
	
	inp >> inorder >> preorder;
	oup << postorder(inorder) << endl;
	
	return 0;
}

