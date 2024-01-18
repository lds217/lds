#include <iostream>
#include <vector>
using namespace std;

int n,m,e,p,b;
int vb[100001],value[100001];
vector<int> K[100001];

void bfs(int st)
{
    queue<int> q;
    for(int x=0;x<=n;x++)
        value[x]=1e9;
    value[st]=vb[st];
    q.push(st);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : K[u])
        {
            if(value[u]+vb[v]<value[v]&&value[u]+vb[v]<=b)
            {
                value[v]=value[u]+vb[v];
                q.push(v);
            }
        }
    }
}

int main()
{
    cin>>n>>m>>e>>p>>b;
    for(int i=0;i<n;i++)
        cin>>vb[i];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        K[u].push_back(v);
        K[v].push_back(u);
    }
    bfs(e);
}