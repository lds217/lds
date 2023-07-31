#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<'0';
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				cout<<'1';
			}
		}
		cout<<endl;
	}
}