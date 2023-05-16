// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()

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
const ll maxn=5000005;
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



long long m,n;
long long r[maxn];
	int q;
set <long long> s;
struct pnlp{
	int u,v,w,type,id;
}b[maxn];


long long get(long long u)
{
	return r[u]?r[u]=get(r[u]):u;
}
bool ans[maxn];
void input()
{
	mset(r,0);
	cin>>n>>m>>q;
	
	FOR(i,1,m)
	{
		int u,v,c;
		cin>>u>>v>>c;

		b[i]={u,v,c,0,0};
	}
	//0 la nhap 1 la hoi
	FOR(i,1,q)
	{
		int u,v,w;
		cin>>u>>v>>w;
		b[m+i]={u,v,w,1,i};
	}
	sort(b+1,b+1+m+q,[](pnlp a, pnlp b)
	{
		if(a.w==b.w)
			return a.type<b.type;
		return a.w>b.w;
	});
	//int ans=0;
	mset(ans,0);
//	FOR(i,1,m+q)
//		cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<" "<<b[i].type<<" "<<b[i].id<<endl;
	FOR(i,1,m+q)
	{
		int u=get(b[i].u);
		int v=get(b[i].v);
		if(b[i].type==0)
			if(u!=v)
				r[u]=v;
				
		
		if(b[i].type==1)
			if(u==v)
				ans[b[i].id]=1;
	}
	FOR(i,1,q)
		if(ans[i]==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
}




int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(); //lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
