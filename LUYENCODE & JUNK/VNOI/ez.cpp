#include <bits/stdc++.h>
using namespace std;

bool eratos[10000007];
int a[1000001],prefix[1000001];


void gen_eratos()
{
    eratos[0] =eratos[1]=1;
    for(int x=2;x*x<=1000000; x++)
        if(eratos[x]==0)
            for(int y=x*x;y<=1000000;y+=x)
                eratos[y]=1;
}


int main()
{
    gen_eratos();
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
        cin>>a[x];
    for(int x=1;x<=n;x++)
        prefix[x]=prefix[x-1]+a[x]; 
    
  int minn=1e9,maxx=-1e9;
    for(int r=1; r <= n; r++)
    {
        if(!eratos[r])
        {
            minn=min(minn,prefix[r-1]);
            maxx=max(maxx,prefix[r]-minn);
        }
    }
   // cout<<maxx,minn;
    cout<<maxx;
}