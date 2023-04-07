#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a[1000000],res[1000000]={0},N,K,maxx=0;
    cin>>N>>K;
    for(int x=1;x<=N;x++)
        cin>>a[x];
    a[0]=0;
    for(int x=1;x<=N;x++)
    {
        if(x<=K)
            res[x]=a[x]+*max_element(res,res+x);
        else
            res[x]=a[x]+*max_element(res+x-K,res+x); 
        maxx=max(res[x],maxx);
    }
    cout<<maxx;
}