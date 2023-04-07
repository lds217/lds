#include <iostream>
#include <iomanip>
using namespace std;
long long dp[45][1000000]={0};
int main()
{
    long long N,S;
    cin>>N>>S;
    long long w[N+1],v[N+1];
    for(int x=1;x<=N;x++)
        cin>>w[x]>>v[x];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=S;j++)
        {
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    
    cout<<dp[N][S]<<endl;
   
}