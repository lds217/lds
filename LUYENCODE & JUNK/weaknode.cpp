#include <bits/stdc++.h>
using namespace std;

int n, m, s, t,cnt=0;
bool visited[100000] = {0};
vector<int> k[100000];
int value[100000];
int possway[100000];
void dfs(int u)
{
    if(u!=t)
    {
        visited[u]=1;
        for(auto v : k[u])
        {
            if(visited[v]==0&&value[v]!=-1)
            {
              //  cout<<u<<" "<<v<<endl;
                value[v]++;
                possway[u]++;
                dfs(v);
                visited[v]=0;
                if(value[v]==-1)
                    possway[u]--;
            }
        }   
    }
    if(possway[u]==0&&u!=t)
        value[u]=-1;

}

int main()
{
    cin >> n >> m >> s >> t;
    for (int x = 0; x < m; x++)
    {
        int u, v;
        cin >> u >> v;
        k[u].push_back(v);
    }
  //  cout<<endl;
    dfs(s);
    int final=0;
   for(int x=0;x<=n;x++)
    //if(value[x]==value[t]&&x!=t&&x!=s)
        cout<<value[x]<<" ";
    cout<<final;
}