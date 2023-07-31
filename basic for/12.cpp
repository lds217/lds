#include <bits/stdc++.h>
using namespace std;

int main()
{
	//cach 1
	/*int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<j;
		}
		cout<<endl;
	}*/
	
	//cach2
	int n,cnt=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cnt=1;
		for(int j=1;j<=n;j++)
		{
			cout<<cnt;
			cnt++;
		}
		cout<<endl;
	}
}