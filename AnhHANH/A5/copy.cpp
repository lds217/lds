#include <bits/stdc++.h>
#define INF int64_t(1e12)
#define pll pair <long long, long long>
#define file "election"
using namespace std;
const int nmax = 6e5 ;
long long n, a;
long long b;
vector <long long> adj[nmax + 5], c[nmax + 5];
int alpha;
priority_queue < long long > q;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> alpha >> n;
long long cost=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a >> b;
        if (a>0) cost+=b;
        adj[a].push_back(b);
    }
    long long res=cost;
    for (int i=1;i<=nmax + 1;i++)
    {
        if (adj[i].size())
        {
            sort(adj[i].begin() , adj[i].end(), greater <int>());
            for (int j=0;j<adj[i].size();j++) c[j].push_back(adj[i][j]);
        }
    }
    for (int i=0;i<=nmax && c[i].size()!=0 ;i++) sort(c[i].begin(), c[i].end());
    long long co = n;
    for (int i=1;i<=n;i++)
    {
        if (c[i-1].size())
            for (auto x:c[i-1])
            {
                co--;
                q.push(-x);
                cost-=x;
            }
        while (!q.empty() && co<=i)
        {
            cost-=q.top();
            co++;
            q.pop();
        }
        if (co > i) res=min(res,cost);
    }
    cout << res;
return 0;
}

