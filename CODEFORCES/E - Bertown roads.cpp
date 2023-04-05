#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int n,m,low[200001],in[200001],visit[200001];
vector <int> K[200001];
int timer=0;
vector <pair<int,int> > ans;
bool maycophailabrigdeko=0;
 
void dfs(int node,int par)
{
    visit[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(int child : K[node])
    {
        if(child==par) continue;
        if(visit[child]==1)
        {
            low[node]=min(low[node],in[child]);
            if(in[node]>in[child])
               ans.push_back({node,child});
        }
        else
        {
            dfs(child,node);
            if(low[child]>in[node])
            {
               // cout<<node<<" "<<child<<endl;
               maycophailabrigdeko=1;
               return;
            }
            ans.push_back({node,child});
            low[node]=min(low[node],low[child]);
        }
    }
}
 
int main(int argc, char **argv)
{
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        K[u].push_back(v);
        K[v].push_back(u);
    }
    dfs(1,-1);
    if(maycophailabrigdeko==1)
        cout<<0;
    else
        for(pair<int,int> x : ans)
            cout<<x.first<<" "<<x.second<<endl;
    return 0;
}