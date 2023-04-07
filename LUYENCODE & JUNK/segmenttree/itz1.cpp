#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100000],node[400000];

void build(int id,int l,int r)
{
    if(l==r)
    {
        node[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    node[id]+=node[id*2]+node[id*2+1];
}

void update(int id, int l, int r, int pos, int val)
{
    if(pos<l||pos>r)return;
    if(l==r)
    {
        node[id]=val;
        a[l]=val;
        return ;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    node[id]=node[id*2]+node[id*2+1];
}

int get(int id, int l, int r, int u, int v)
{
     if (v < l || u > r)
        return 0;
    if (u <= l && v >= r)
        return node[id];
    int mid=(l+r)/2;
    int sumL=get(id*2,l,mid,u,v);
    int sumR=get(id*2+1,mid+1,r,u,v);
    return sumL+sumR;
}

int main(int argc, char **argv)
{
    int N,q;
    cin>>N>>q;
    for(int x=1;x<=N;x++)   a[x]=0;
    build(1,1,N);
    while(q--)
    {
        int type,x,y;
        cin>>type>>x>>y;
        if(type==1)
            update(1,1,N,x,y);
        else
            cout<<get(1,1,N,x,y)<<endl;
    }

}