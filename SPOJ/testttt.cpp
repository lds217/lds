#include <bits/stdc++.h>
using namespace std;
int main() 
{
    // nhập 2 số n,m in ra hcn n x m
	// VD : 4 5
	// *****
	// *****
	// *****
	// ***** 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
}
