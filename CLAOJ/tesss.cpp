#include <bits/stdc++.h>
using namespace std;

int check[1000001];
int main()
{
	int n;
	cin>>n;
	int a[100001];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		check[a[i]]++;
	for(int i=0;i<1000000;i++)
		if(check[i]!=0)
			cout<<i<<' '<<check[i]<<endl;
}