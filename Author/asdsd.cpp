#include <bits/stdc++.h>
using namespace std;

int n,k,a[101];
long long dp[101][100001];
const int mod=1e9+7;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
        {
            for(int x=max(0,j-a[i]);x<=j;x++)
                dp[i][j]+=dp[i-1][x]%mod;
    	}
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        	cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    cout << dp[n][k]%mod;
}
