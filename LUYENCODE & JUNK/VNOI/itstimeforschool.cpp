// wake up CJ it's time for school
#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long
#define ull unsigned long long
#define INF 1e9 + 7
using namespace std;
int N,M;
vector<pair<ll, ll>> K[100000];
ll value[100000];
ll cnt;
ll c[100000];

void dijkstra(int st)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    for(int x=0;x<=N;x++)
        value[x] =INF;
        c[st]=1;
    value[st] = 0;
    q.push({0, st});
    while (q.size())
    {
        int u = q.top().second;
        int value_u = q.top().first;
        q.pop();
        if (value_u!=value[u]  )
            continue;
        for (auto i : K[u])
        {
            int v = i.second;
            int value_v = i.first;
             if (value[v] == value_v+value_u) {
            	c[v] += c[u];
            	continue;
             }
            if(value[v]>value_v+value_u)
            {
                c[v]=c[u];

                value[v]=value_v+value_u;
                q.push({value[v],v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while (M--)
    {
        int k, u, v, w;
       cin>>k>>u>>v>>w;
        K[u].push_back({w, v});
        if (k == 2)
            K[v].push_back({w, u});
    }
    dijkstra(1);
    cout << value[N] << " " << c[N];
    return 0;
}