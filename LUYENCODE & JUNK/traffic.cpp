#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;


vector<pair<int, int>> a[100000];
long long d[100000],value[100000];
int n,m;

void dijkstra(int st)
{
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater <pair<int, int>>> q;
    for(int i=1;i<=n;i++)
        d[i]=1e9+7,value[i]=1;
    d[st]=0;
    value[st]=1;
    q.push({0,st});
    while(!q.empty())
    {
        int u=q.top().Y;
        int du=q.top().X;
        q.pop();

        if(du!=d[u]) continue;
        for(auto i:a[u])
        {
            int v=i.Y;
            int dv=i.X;
            if(d[v]==du+dv)
                value[u]+=value[v];
            if(d[v]>du+dv)
            {
                value[u]+=value[v];
                d[v]=du+dv;
                q.push({d[v],v});
                
            }
        }
    }
}

int main(int argc, char** argv)
{
    // freopen("GIAOTHONG.inp","r",stdin);
    // freopen("GIAOTHONG.out","w",stdout);
    cin>>n>>m;
    int pos[100000];
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pos[i]=v;
        a[u].push_back({w,v});
    }
    dijkstra(1);
    for(int i=0; i<n; i++)
    cout<<value[pos[i]]<<endl;
    return 0;
}