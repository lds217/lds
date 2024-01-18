#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
using namespace std;

vector<pair<pair<int, int>,int> > V;
int N,tree[4*300000],ans[300001];

void upd(int i,int val){
    while(i < 100000){
        tree[i] += val;
        i += (i & (-i));
    }
}
 
int get(int i){
    int ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= (i & (-i));
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int u, v;
        cin >> u >> v;
        V.push_back(pair<pair<int, int>,int>(make_pair(u, v),i));
    }
    sort(V.begin(),V.end()+1);
    // for(int i=1;i<=N;i++)
    //     cout<<V[i].first.first<<" "<<V[i].first.second<<" "<<V[i].second<<endl;
    upd(V[1].first.second,1);
    for(int x=2;x<=N;x++)
    {
        if(V[x].first.first!=V[x-1].first.first||V[x].first.second!=V[x-1].first.second)
            ans[V[x].second]=get(V[x].first.second);
        else
            ans[V[x].second]=ans[V[x-1].second];
        upd(V[x].first.second,1);
    }
    
    for(int x=1;x<=N;x++)
        cout<<ans[x]<<endl;
    return 0;
}
