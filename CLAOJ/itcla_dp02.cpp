#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("TREASURE.INP","r",stdin);
	//freopen("TREASURE.OUT","w",stdout);
	int n, k;
	cin>>n>>k;
	long long a[100001];
	a[0]=0;
	a[1]=1;
	a[2]=1;
	a[3]=0;
	while(k--)
	{
		int u; cin>>u;
		if (u==2) a[u]=0;
		else a[u]=-1;
	}
	for (int i=3; i<=n; i++)
	{
		if (a[i]==-1)
		{
			a[i]=0;
		}
		else
		{
			a[i]=(a[i-1]+a[i-2])%14062008;
		}
	}
	cout<<a[n];
}
