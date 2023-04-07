#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

long double K[100000];
 map<long double,int> pos;
 int n;

bool dk(long double x, long double y) 
{
        return x<y;
}

int main(int argc, char** argv)
{
    cin>>n;
    for(int x=0;x<n;x++)
    {
        int u,v; cin>>u>>v;
        K[x]=atan2(v,u);
        pos[K[x]]=x+1;
   //     cout<<atan2(v,u)<<endl;
    }
 //   cout<<endl;
    sort(K, K+n,dk);
    int resx,resy;
    // for(int x=0;x<n;x++)
    //     cout<<K[x]<<endl;
    long double minn=1000000000;
   for(int x=1;x<n;x++)
   {
       if(K[x]-K[x-1]<minn)
       {
           minn=K[x]-K[x-1];
           resx=pos[K[x]];
           resy=pos[K[x-1]];
       }
   }

    cout<<resx<<" "<<resy;

}