#include <iostream>
using namespace std;
#define MOD 1e9+7
long long dp[1000000];
 
int main()
{
    int N;
    cin>>N;
    dp[0]=1;
    for(int x=1;x<=N;x++)
    {
        for(int y=1;y<=6;y++)
            if(y<=x)
                dp[x]=(dp[x]+dp[x-y])%(1000000007);
            
    }
    cout<<dp[N];
}