#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    cin>>a;
    for(int i=a.size()-1;i>=0;i--)
        b+=a[i];
    a=" "+a;
    b=" "+b;
    int dp[1000][1000]={0};
    for(int i=1;i<a.size();i++)
        for(int j=1;j<b.size();j++)
        {
            
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }

    cout<<dp[a.size()-1][b.size()-1];
}