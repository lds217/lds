#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[1000];
      int dp[1000]={1};
    for(int x=0;x<n;x++)
    {
        cin>>a[x];
        dp[x]=1;
    }
  
    for(int x=0;x<n-1;x++)
        for(int y=x+1;y<n;y++)
            if(a[y]<a[x]&&dp[x]==dp[y])
                dp[y]++;
    for(int x=0;x<n;x++)
        cout<<dp[x]<<" ";
    }