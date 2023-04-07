#include <iostream>
using namespace std;
#define MOD 1e9+7
long long dp[1000001];
int tok[1000001];
int main()
{
    int N,value;
    cin>>N>>value;
    for(int i=0;i<N;i++)
        cin>>tok[i];
    dp[0]=1;
    for(int x=1;x<=value;x++)
    {
        for(int y=0;y<N;y++)
            if(tok[y]<=x)
                dp[x]=(dp[x]+dp[x-tok[y]])%(1000000007);       
    }
    cout<<dp[value];
}