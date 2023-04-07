#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#define ll long long
#define ull unsigned long long
#define maxN 3000006
#define vv_inter vector<vector<ll> >::iterator
using namespace std;

int N;
pair<ll, ll> ord[maxN];
map<pair<ll, ll>, int> K;
map<pair<ll, ll>, int> r;
map <ll,ll> res;
pair<ll, ll> t[maxN];
vector<ll> nums;
int sec[maxN];

void merge_count(vv_inter l, vv_inter r, vector<ll> &cnt)
{
    if (r - l <= 1)
        return;
    vv_inter m = l + (r - l) / 2;
    merge_count(l, m, cnt);
    merge_count(m, r, cnt);
    vv_inter j = m;
    for (vv_inter i = l; i < m; i++)
    {
        while (j < r and (*i)[0] >= (*j)[0])
            j++;
        cnt[(*i)[1]] += j - m;
    }
    inplace_merge(l, m, r);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int x = 0; x < N; x++)
    {
        int u, v;
        cin >> u >> v;
        ord[x] = pair<ll, ll>(u, v);
        t[x] = pair<ll, ll>(u, v);
        r[t[x]]=x;
    }
    sort(t, t + N);

    //  for (int x =0;x < N; x++)
    //      cout<<t[x].first<<" "<<t[x].second<<endl;

    for (int x = N - 1; x >= 0; x--)
        nums.push_back(t[x].second);
    vector<vector<ll> > temp;
    for (int x = 0; x < nums.size(); x++)
        temp.push_back(vector<ll>({nums[x], x}));

    vector<ll> cnt(nums.size(), 0);
    
    merge_count(temp.begin(), temp.end(), cnt);
    reverse(cnt.begin(), cnt.end());
    int o = 0;
    for (auto x : cnt)
        sec[o++] = x;
    for (int x = 0; x < N; x++)
    {
        if(t[x].first==t[x-1].first&&t[x].second==t[x-1].second&&x!=0)
            res[r[t[x]]]= res[r[t[x]]-1];
        else
            res[r[t[x]]]=sec[x];
    }
    for (int x = 0; x < N; x++)
        cout <<res[x] << endl;
    return 0;
}