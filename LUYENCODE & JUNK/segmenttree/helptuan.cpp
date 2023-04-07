#include <iostream>
 #include <cstdio>
using namespace std;

int a[100001],N;
bool displace[100001];

void build()
{
    for(int x=2;x<=N;x++)
        if(a[x]==0)
        {
            displace[x]=1;
            for(int y=x+x;y<=N;y+=x)
            {
                int temp=y;
                while(temp%x==0)
                {
                    a[x]++;
                    a[y]=1;
                    temp/=x;
                }
            }
        }
}

int main()
{
    //   freopen("ANALYSE.INP","r",stdin);
    // freopen("ANALYSE.OUT","w",stdout);  
    cin>>N;
    build();
    for(int x=1;x<=N;x++)
        if(displace[x]==1)
            cout<<a[x]+1<<" ";
}