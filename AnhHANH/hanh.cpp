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
#define task "seq198"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e6+2;
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
int vs[maxn],y[maxn];
vector <long long> k[maxn];
long long m,n,p;

int t;
unordered_map <int,int> pos;
	int a[100001];
void input()
{
	cin>>n;
	FOR(i,0,n-1)	cin>>a[i],pos[a[i]]=i;
}




bool dfs(int i)
{
	if(vs[i]!=t)
		vs[i]=t;
	else
		return 0;
	for(int v:k[i])
		if(y[v]==0||dfs(y[v]))
		{
			y[v]=i;
			return 1;
		}
	return 0;
}

void lds_go_goooo()
{
	if(n>30)
	{
		mset(vs,0);
	FOR(i,0,n-1)
		FOR(j,0,n-1)
			if(a[i]-a[j]==1||a[i]-a[j]==8||a[i]-a[j]==9)
					k[i].pb(j);
 
	ll cnt=0,tmp=0;
	FOR(i,0,n-1)
	{
		t=i;
		cnt+=dfs(i);
	}
 
	cout<<cnt<<endl;
	return;
	}
	ll ans=1e9;
	FOR(i,1,MASK(n)-1)
	{
		int cnt=0;
		bool mark[n+1];
		FOR(j,0,n-1)
		{
			//cout<<BIT(i,j);
			if(BIT(i,j))
				mark[j]=1;
			else
				mark[j]=0,cnt++;
		}
		FOR(j,0,n-1)
		{
		    if(mark[j])
		    	FOR(k,0,n-1)
					if((mark[k])&&(a[j]-a[k]==1||a[j]-a[k]==8||a[j]-a[k]==9))
					{
						j=n;
						break;
					}
						
			if(j==n-1)
				minimize(ans,cnt);//cout<<"Hi";
		}
	//	cout<<endl;
	}
	cout<<(ans==1e9?-1:ans);

	
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}

//Dont ask me why this code works, go ask Kieu Phat
