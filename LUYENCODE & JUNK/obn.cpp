#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
vector <ii> K[100000];

int N,M,S,T,valS[10000],valT[10000];

void dijkstra(int st,int value[])
{
    priority_queue<ii,vector<ii>, greater <ii>> q;
    q.push({0,st});
    //format
    for(int x=0;x<=N;x++)
        value[x]=1e9;
    value[st]=0;
    while(!q.empty())
    {
        int u=q.top().Y;
        int vU=q.top().X;
        q.pop();
        for(auto i:K[u])
        {
            int v=i.Y;
            int vV=i.X;
            if(value[v]>vV+vU)
            {
                value[v]=vU+vV;
                q.push({value[v],v});
            }
        }
    }
}

int main()
{
    cin>>N>>M>>S>>T;
    while(M--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        K[u].push_back({w,v});
        K[v].push_back({w,u});
    }
    dijkstra(S,valS);
    dijkstra(T,valT);
    long long res=1e9,ans=N;
    for(int x=1;x<=N;x++)
        if(valS[x]==valT[x]&&valS[x]<res)res=valS[x],ans=x;
    if(ans!=N)
        cout<<ans;
    else
        cout<<"CRY";
    return 0;

}