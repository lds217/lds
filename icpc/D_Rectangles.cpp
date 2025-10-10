#include <iostream>
#include <stack>
#include <vector>
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
      while(!minn.empty() && arr[minn.top()-1] > arr[i] ) minn.pop();
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
                // for(int z = 1; z < v.size(); z++) {
                //     cout<<v[z]<<' ';
                // }
               // cout<<endl;
                long long x = cntrec(v);
                //cout<< x <<endl;
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
    // vector<int> x;
    // x.push_back(-10000000);
    // x.push_back(1);
    // x.push_back(2);
    // cout<<cntrec(x);
    return 0;
}