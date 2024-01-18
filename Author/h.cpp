#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int check[1000001];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		check[a[i]]++;
	for(int i=1;i<=1000000;i++)
	{
	    if(check[i]!=0&&check[i]%2==0)
	    	cout<<i<<' ';
	}
//	cout<<check[n];
}