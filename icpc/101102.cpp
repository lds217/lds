#include <bits/stdc++.h>
using namespace std;

#define             ed        << "\n";
#define             el        cout<<'\n';
#define            ALL(s)     s.begin(),s.end()
#define             fi        first
#define             se        second
#define            SQ(a)      (a)*(a)
#define            A(a)        abs(a)
#define            SZ(a)      ((int)(a.size()))
#define          REP(i,a,b)    for (int i = (a), _b = (b); i < _b; i++)
#define          FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)
#define          FOD(i,r,l)    for(int i=r; i>=l; i--)
#define           MASK(x)      (1LL << (x))



template <class T> inline bool minimize(T &a, const T &b) {
    return (a > b ? (a = b),1 : 0);
}

template <class T> inline bool maximize(T &a, const T &b) {
    return (a < b ? (a = b),1 : 0);
}

long long cntrec(vector<long long> &arr) {
    int n = arr.size();
    vector<long long> pre(n + 2, 0), dp(n + 2, 0);
    stack<int> minn;
    
    FOR(i, 1, n-1) {
      while(!minn.empty() && arr[minn.top()] > arr[i] ) minn.pop();
        if (!minn.empty())
            pre[i] = minn.top();
        minn.push(i);
        dp[i] += arr[i] * (i-pre[i]) + dp[pre[i]];      
    }
    long long ans = 0;
    FOR(i,1,n-1) {
        ans+=dp[i];
    }
    return ans;
}

void sol() {
    long long n, m;
    cin>>n>>m;
    long long ans = 0;
    long long arr[m + 1], h[m+1];
    memset(h, 0, sizeof(h));
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin>>x;
            if (x == arr[j]) {
                h[j]++;
            }
            else {
                h[j] =1;
            }
            arr[j] = x;
        }
       vector<long long> v;
       v.push_back(-100000000);
       for(int j = 0; j < m; j++) {
            if (j+1 == m || arr[j+1] != arr[j]) {
                v.push_back(h[j]);
                long long x = cntrec(v);
                ans += x;
                v.clear();
                v.push_back(-100000000);
            }
            else {
                v.push_back(h[j]);
            }
       }
      
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}