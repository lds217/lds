#include <bits/stdc++.h>
using namespace std;

double l;

double dis(double x, double y)
{
    return (double)sqrt(l*l+abs(x-y)*abs(x-y));
}

int main()
{
    double a[301],b[301],dp[30][30][30],T;
   int m,n,k;
    cin>>m>>n>>l>>k;
    for(int x=1;x<=m;x++)    cin>>a[x];
    for(int x=1;x<=n;x++)    cin>>b[x];
    sort(a+1,a+1+m);
    sort(b+1,b+1+n);
    for(int x=0;x<=m;x++)
        for(int y=0;y<=n;y++)
            for(int z=1;z<=k;z++)
                dp[x][y][z] =1e9;
    
        for(int x=1;x<=m;x++)
            for(int y=1;y<=n;y++)
                for(int z=1;z<=k;z++)
                    dp[x][y][z] =min(dp[x-1][y-1][z-1]+dis(a[x],b[y]),min(dp[x][y-1][z],dp[x-1][y][z]));
    for(int z=1;z<=k;z++)
    {
         for(int x=1;x<=m;x++)
         {
            for(int y=1;y<=n;y++)
                    cout<<dp[x][y][z]<<" ";
                cout<<endl;
         }
         cout<<endl;
    }
}
/*code inspired by ti21_phnam*/