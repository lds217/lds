#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,cnt=1; // cnt: count: dem
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<cnt<<' ';
			cnt++;
		}
		cout<<endl;
	}
}