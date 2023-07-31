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
ll a[maxn];

int main(int argc, char** argv) {
    ifstream inp(argv[1]);
    ifstream out(argv[2]);
    ifstream ans(argv[3]);

    ll  t;
    inp>>t;
    while(t--)
    {
    	string s;
    	inp>>s;
    	ll ansfirst,userfirst,anssecond,ansthird,ansforth,usersecond,userthird,userforth;
    	ans>>ansfirst;
    	out>>userfirst;
    	if(ansfirst==-1)
    	{
    		if(userfirst!=-1)
    			return 1;
    		continue;
    	}
		else
		{
			ans>>anssecond>>ansthird>>ansforth;
			out>>usersecond>>userthird>>userforth;
			if(anssecond-ansfirst!=usersecond-userfirst||ansforth-ansthird!=userforth-userthird)
				return 1;
			mset(a,0);
		//	ll resans=0;
			FOR(i,0,s.size()-1)
				a[i+1]=a[i]+s[i]-'0';
			if(a[anssecond]-a[ansfirst-1]!=a[usersecond]-a[userfirst-1]||a[ansforth]-a[ansthird-1]!=a[userforth]-a[userthird-1])
				return 1;
		}
		
	}

    return 0;

}
