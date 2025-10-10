#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
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

void sol() {
    int n;
    cin>>n;
    vector<int> arr[n+10];
    int maxx = 0;
    FOR(i, 1, n) {
        int x;
        cin>>x;
        maximize(maxx, x);
        FOR(j, 1, x) {
            int y;
            cin>>y;
            arr[i].push_back(y);
        }
    }
    sort(arr + 1, arr+ n + 1, [] (vector <int> &a, vector<int> &b) {
        return a.size() < b.size();
    });
    int left = 0;
    int right = arr[1].size() - 1;
    vector<int> ans;
    while (right < maxx){
        vector<int> edit(maxx + 1, INT_MAX);
        int selected = -1;
        FOR (i , 1, n) {
            bool tie = 1;
            FOR(j, left, min(arr[i].size() - 1ULL,right- 1ULL)) {
                if (arr[i][j] < edit[j])
                {
                    selected = i;
                    tie = 0;
                    FOR(z, j, min(arr[i].size() - 1ULL, right- 1ULL))
                        edit[z] = arr[i][z];
                    break;
                }
                else {
                    if (arr[i][j] > edit[j]){
                        tie = 0;
                    } break;
                }
                if (tie && arr[selected].size() > arr[i].size()) {
                    FOR(z, left, min(arr[i].size() - 1, edit.size()- 1))
                        edit[z] = arr[i][z];
                    selected = i;
                }
            }
        }
        
        if (selected == -1) {
            break;
        }
        for (auto i : edit) {
            if(i!=INT_MAX)
                ans.push_back(i);
        }
        
        left = arr[selected].size();
    }
    
    for(int i : ans) {
        cout<< i<<' ';
    }
    cout<<endl;
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