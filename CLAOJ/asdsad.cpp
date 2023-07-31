#include<bits/stdc++.h>
#define reu(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define red(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define iii pair<int,pair<int,int> >
#define sz(x) int(x.size())
using namespace std;
//const int N = 3e5 + 7;

ll n, x, y, m, mn, mx, res;
vector< ii > v; // chứa các đơn hàng có A[i]>B[i]

bool cmp(const ii &u, const ii &v)
{
    return( (u.se < v.se) || (u.se == v.se && u.fi > v.fi));
}

void input()
{
    cin >> n >> m;
    reu(i, 1, n)
    {
        cin >> x >> y;
        if(x > y) v.pb({x,y});
    }
    sort(v.begin(), v.end(), cmp);
}

void solve()
{
    res = m; // biến lưu kết quả. Vì trước sau cũng phải đến M nên res = M.
    if(sz(v) == 0)
    {
        cout << m;
        return;
    }
    mn = v[0].se; // vị trí nhỏ nhất của tập hợp hiện tại.
    mx = v[0].fi; // vị trí lớn nhất của tập hợp hiện tại.
    cout<<sz(v);
    reu(i, 0, sz(v) - 1)
    {
    	cout<<i<<endl;
        mx = max(mx, v[i].fi);
        mn = min(mn, v[i].se);
        if( (i == sz(v) - 1) || (mn > v[i+1].fi) || (mx < v[i+1].se)) // nếu đơn hàng tiếp theo không trùng với tập hợp hiện tại hoặc đã xét hết đơn hàng.
        {
        	
        	cout<<"hi";
            res += (mx - mn) * 2; // độ dài đoạn phải đi ngược xuống và đi lên lại
            if(i == sz(v) - 1) break;
            // Khởi tạo lại tập hợp mới.
            mn = v[i+1].se;
            mx = v[i+1].fi;
        }
    }
    cout << res;
}

int main()
{
   // freopen("GIAOHANG.INP","r",stdin);
    //freopen("GIAOHANG.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
