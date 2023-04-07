// #include <iostream>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int N;long long res=1000000001;bool zeroa=0,zerob=0;
//     long long a[100000],mina=-1000000001,maxa=1000000001;
//     long long b[100000],minb=-1000000001,maxb=1000000001;
//     cin>>N;
//     for(int x=0;x<N;x++)
//     {
//         cin>>a[x];
//         if(a[x]<0)
//         mina=max(mina,a[x]);
//         if(a[x]>0)
//         maxa=min(maxa,a[x]);
//         if(a[x]==0)
//             zeroa=1;
//     }
//     for(int x=0;x<N;x++)
//     {
//         cin>>b[x];
//         if(b[x]<0)
//         minb=max(minb,b[x]);
//         if(b[x]>0)
//         maxb=min(maxb,b[x]);
//         if(b[x]==0)
//         zerob=1;
//     }
//     for(int x=0;x<N;x++)
//     {
//         res=min(res,abs(b[x]+mina));
//         res=min(res,abs(b[x]+maxa));
//     }
//     for(int x=0;x<N;x++)
//     {
//         res=min(res,abs(a[x]+minb));
//         res=min(res,abs(a[x]+maxb));
//     }
//     if(zeroa==1||zerob==1)
//     {
//         if(zeroa==1)
//             for(int x=0;x<N;x++)
//                 res=min(res,abs(b[x]));
//         else
//             for(int x=0;x<N;x++)
//                 res=min(res,abs(a[x]));
//     }
//     cout<<res;
// }
#include <bits/stdc++.h>
using namespace std;
int n, a[100001],b[100001],minn;

int main()
{
cin>>n;
minn=1000000001;
for (int i=1;i<=n;i++) 
    cin>>a[i];
for (int i=1;i<=n;i++) 
    cin>>b[i];


sort(a+1,a+1+n);
for (int i=1;i<=n;i++)
{
   int k=lower_bound(a+1,a+1+n,-b[i])-a;
   cout<<*a+1<<" ";
    if (k!=1) 
        minn=min(minn,abs(b[i]+a[k-1]));
    if (k!=n+1)
        minn=min(minn,abs(b[i]+a[k]));
}
    cout<<minn;
}