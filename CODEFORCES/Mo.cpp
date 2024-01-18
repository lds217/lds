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
const ll maxn=500005;
const ll block= 710;
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

int n;
string s;
ll cnt[26][block];
void input()
{
	cin>>n>>s;
	s=' '+s;
	FOR(i,1,n)
		cnt[s[i]-'a'][i/block]++;
}
void lds_go_goooo()
{
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int pos;char a;
			cin>>pos>>a;
			cnt[s[pos]-'a'][pos/block]--;
			s[pos]=a;
			cnt[s[pos]-'a'][pos/block]++;
		}
		else
		{
			int l,r;
			cin>>l>>r;
			int blockl=l/block+1;
			int blockr=r/block-1;
			int mask=0;
			FOR(i,blockl,blockr)
				FOR(j,0,25)
					if(cnt[j][i])	mask |= 1<<j;
			
			if(l/block==r/block)
				FOR(i,l,r)	mask |= 1<<s[i]-'a';
			else
			{
				for(int i=l;i<blockl*block;i++)	mask |= 1<< s[i]-'a';
				for(int i=(blockr+1)*block;i<=r;i++)	mask |= 1<<s[i]-'a';
			}
			cout<<__builtin_popcount(mask)<<endl;;		
		}
	}
}

int main()
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
