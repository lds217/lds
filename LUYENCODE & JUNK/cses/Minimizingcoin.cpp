#include <bits/stdc++.h>
using namespace std;

int dp[101][1000001];

int main()
{
    int N,V;
    cin>>N>>V;
    int A[101];
    for(int i=1; i<=N; i++)
        cin>>A[i];
    for(int x=0; x<=V; x++)
        dp[0][x]=1e9;
    for(int x=1;x<=N; x++)
        for(int y=1; y<=V; y++)
        if(A[x]>y)
            dp[x][y]=dp[x-1][y];
        else
            dp[x][y]=min(dp[x-1][y],dp[x][y-A[x]]+1);
    if(dp[N][V]!=1e9)
        cout<<dp[N][V];
    else
        cout<<-1;
}