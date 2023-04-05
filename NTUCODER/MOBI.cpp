#include <bits/stdc++.h>
#include <vector>
using namespace std;
int N,K,X;
long long res=0;
vector<pair<int,int>> vect;
int a[1000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    int size=0;
    fill(a,a+1000000,0);
    for(int x=0;x<N;x++)
    {
        cin>>X;
        cin>>a[X];
        size=max(size,X);
    }
    
    if(K>=size)
    {
        for(int x=0;x<=size;x++)
            res=res+a[x];
        cout<<res;
        return 0;
    }
   // cout<<size;
    long long sum=0;
    for(int x=0;x<=K*2;x++)
        sum=sum+a[x];
    res=sum;
   // cout<<sum;
    for(int x=1;x<=size-K*2;x++)
    {
        sum=sum-a[x-1]+a[x+K*2];
        res=max(sum,res);
    }
   cout<<res;
}