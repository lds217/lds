#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
   	set<int>::iterator it;
    cin.tie(0);
	set <int> s1;
	s1.insert(0);
	int N,size=s1.size();
	cin>>N;
	int a[N+1],dis[N+1];
    a[0]=0;
	int res=0;
	long long sum=0;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
		sum+=a[i];
		a[i]=sum;
		s1.insert(a[i]);
        int pos=*s1.find(a[i]);
		if(size!=s1.size())
        {
			size=s1.size();
        	dis[pos]=i;
        }
		else
            res=max(res,i-dis[pos]);
		
	}
    for(int x=0;x<N;x++)
        cout<<a[x]<<" ";
		cout<<res;
	
}