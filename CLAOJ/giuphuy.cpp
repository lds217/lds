// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "SUADUONG"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e4+2;
const ll mod=26051968;
const ll inf=1e18;

const int moveX[]={0,0,1,-1};
const int moveY[]={-1,1,0,0};

bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

//main
#define int ll
int n,m;
map <ll,ll> prexor,root;
set<int> vals;

void input()
{
	
}

ll get(int u)
{
	return root[u]==0?u:root[u]=get(root[u]);
}

void lds_go_goooo()
{
	
	while(cin>>n)
	{
		vals.clear();
		prexor.clear();
		root.clear();
		if(n==-1)	break;
		cin>>m;
		FOR(i,1,m)
		{

			ll u,v;
			string type;
			cin>>u>>v>>type;
			u--;
			vals.insert(u);
			vals.insert(v);
			ll ru=get(u);
			ll rv=get(v);
		//	cout<<root[u]<<' '<<root[v]<<endl;
			bool flag;
			if(type=="odd")
				flag=1;
			else
				flag=0;
			if(ru!=rv)
			{
				if((prexor[v]^prexor[u])!=flag)
					for(int j:vals)
						if(get(root[j])==rv||(root[j]==0&&j==rv))
							prexor[j]^=1; //= 1 - prexor[j];
					root[ru]=rv;
			}
			else
				if((prexor[v]^prexor[u])!=flag)
				{
					cout<<i-1<<endl;
				//	cout<<"hi"<<endl;
					break;
				}

		}
			
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}