
#include<bits/stdc++.h>

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define BIT(S, i) (((S) >> (i) & 1))
#define MASK(i) ((1ll) << (i))

#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, a, b) for(int i = a; i <= b; i++)
#define countloop(i, a, b) for(i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define rcountloop(i, a, b) for(i = a; i >= b; i--)
#define line '\n'
#define bruhhhhhhhhhhhhhhhhhh for(;;)
using namespace std;

const int MAX_N = 3005;
const int MAX_C = 27;
int n, cnt;
bool vst[MAX_C], check[MAX_C][MAX_C];
vi adlist[MAX_C];
string arr[MAX_N];
char c, res[MAX_C];

void trace(int x){
    if(vst[x]) return;

    for(int j : adlist[x]){
        if(check[x][j] && check[j][x]){
            cout << "Impossible";
            exit(0);
        }
        if(check[j][x]) trace(j);
    }

    res[++cnt] = (char)(x + 'a');
    vst[x] = true;
}

void checku(string x, string y){
    loop(id, 0, min(x.size(), y.size()) - 1){
        if(x[id] != y[id]){
            if(!check[x[id] - 'a'][y[id] - 'a']){
                check[x[id] - 'a'][y[id] - 'a'] = 1;
                adlist[y[id] - 'a'].pb(x[id] - 'a');
            }
            return;
        }
    }
}

void Shuba(){
    cin >> c >> n;
    loop(i, 1, n) cin >> arr[i];

    loop(i, 1, n - 1){
            checku(arr[i], arr[i + 1]);
    }

    loop(i, 0, c - 'a') trace(i);
    loop(i, 1, cnt) cout << res[i];
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    Shuba();
    return 0;
}
