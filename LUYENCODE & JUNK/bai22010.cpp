#include <bits/stdc++.h>
using namespace std;

int n,m;
bool vis[200005];
vector <int> K[200005],temp;

void dfs(int node,int par)
{
    vis[node]=true;
    temp.push_back(node);

    for(int v:K[node])
        if(vis[v]==false)
            dfs(v,node);
        else
            if(par!=v)
                temp.push_back(v);
            else
                temp.pop_back();
}


int main()
{
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        K[u].push_back(v);
    }
    dfs(1,0);
    for(int i:temp)
        cout<<i<<' ';
}
