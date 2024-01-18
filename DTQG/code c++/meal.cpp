#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

#define int long long
int node[400040],a[100010];


void upd(long long id,long long l,long long r,long long pos,long long val)
{
    if(pos<l||pos>r)return;
    if(l==r)
    {
        node[id]+=val;
        return;
    }
    long long mid = (l+r)/2;
    upd(id*2,l,mid,pos,val);
    upd(id*2+1,mid+1,r,pos,val);
    node[id]=max(node[id*2],node[id*2+1]);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        memset(node,0,sizeof node);
        int n,k;
        long long ans=0,l=1;
        cin>>n>>k;
            for(int x=1;x<=n;x++)
                cin>>a[x];
            for(int r=1;r<=n;r++)
            {
                upd(1,1,n,a[r],1);
                while(r-l+1>node[1]+k) 
                    upd(1,1,n,a[l++],-1);
                ans=max(ans,r-l+1);
            }
        cout<<ans<<endl;
    }
    return 0;
}