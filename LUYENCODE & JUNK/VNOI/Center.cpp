// wake up CJ it's time for school
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define INF 9223372036854775807
using namespace std;
ll N,M;
vector<pair<ll, ll>> K[1000000];
ll value[1000000],c[1000000];
ll value1[1000000],c1[1000000];


void dijkstra(ll st)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    for(ll x=0;x<=N;x++)
        value[x] =INF;
    value[st] = 0;
    q.push({0, st});
    while (q.size())
    {
        ll u = q.top().second;
        ll value_u = q.top().first;
        q.pop();
        c[st]=1;
        if (value_u!=value[u]  )
            continue;
        for (auto i : K[u])
        {
            ll v = i.second;
            ll value_v = i.first;
            if(value[v] == value_v+value_u) {
            	c[v] += c[u];
            	continue;}
            if(value[v]>value_v+value_u)
            {
                c[v]=c[u];
                value[v]=value_v+value_u;
                q.push({value[v],v});
            }
        }
    }
}

void dijkstra1(ll st)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    for(ll x=0;x<=N;x++)
        value1[x] =INF;
    value1[st] = 0;
    q.push({0, st});
    while (q.size())
    {
        ll u = q.top().second;
        ll value_u = q.top().first;
        q.pop();
        c1[st]=1;
        if (value_u!=value1[u]  )
            continue;
        for (auto i : K[u])
        {
            ll v = i.second;
            ll value_v = i.first;
            if(value1[v] == value_v+value_u) {
            	c1[v] += c1[u];
            	continue;}
            if(value1[v]>value_v+value_u)
            {
                c1[v]=c1[u];
                value1[v]=value_v+value_u;
                q.push({value1[v],v});
            }
        }
    }
}

int main()
{
    set<ll> s1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while (M--)
    {
        ll  u, v, w;
       cin>>u>>v>>w;
        K[u].push_back({w, v});
        K[v].push_back({w, u});
        s1.insert(u);
        s1.insert(v);
    }
    dijkstra(1);
    dijkstra1(N);
    ll res=0;
    for(auto i : s1)
        if((value1[i]+value[i]>value[N]||c[i]*c1[i]<c[N])&&(i!=1&&i!=N))
            res++;
    cout<<res<<endl;
    for(auto i : s1)
        if((value1[i]+value[i]>value[N]||c[i]*c1[i]<c[N])&&(i!=1&&i!=N))
            cout<<i<<endl;
    return 0;
}