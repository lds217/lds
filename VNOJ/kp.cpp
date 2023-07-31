#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long ll;
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)

long long dp[101][100005];
long long a[100005];
long long pre[100005];
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    FOR(i,1,n)  cin>>a[i];
    dp[0][0]=1;
    
    FOR(i,1,n)
    { 
        pre[0]=1;
        FOR(j,1,k)
            pre[j]=pre[j-1]+dp[i-1][j];
       //cout<<i<<endl;
       // FOR(d,0,k)  
       //     cout<<pre[d]<<" ";
       // cout<<endl;
        FOR(j,1,k)
            if(j-a[i]<=0)
                dp[i][j]=(pre[j]-pre[0]+1)%1000000007;
            else
                dp[i][j]=(pre[j]-pre[j-a[i]-1])%1000000007;
    }
   /* FOR(i,0,n)
    {
        FOR(j,0,k)
            cout<<dp[i][j];
        cout<<endl;
    }*/
    cout<<dp[n][k];
}
