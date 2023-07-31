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
#define task "div"

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
#define int long long
string str;
bool dupp[10];

void input()
{
	cin>>str;
}

bool div2()
{
	if((str[n-1]-'0')%2==0)
		return 1;
}

bool div3()
{
		return (sum%3==0);
}

bool div4()
{
	if(n==1&&(str[n-1]-'0')%4==0)
		return 1;
	else
		if(n==1)
			return 0;
		else
		{
			string tmp="";
			tmp=tmp+str[n-2]+str[n-1];
			return (stoi(tmp)%4==0);
		}
}

bool div5()
{
	if(str[n-1]=='0'||str[n-1]=='5')
		return 1;
}

bool div6()
{
		return (div2()&&div3());
}

bool div7(string num)
{
    int n = num.length(), gSum=0;
    if (n == 0)
        return 1;
    if (n % 3 == 1) {
        num="00" + num;
        n += 2;
    }
    else if (n % 3 == 2) {
        num= "0" + num;
        n++;
    }
    int i, GSum = 0, p = 1;
    for (i = n - 1; i >= 0; i--) {

        int group = 0;
        group += num[i--] - '0';
        group += (num[i--] - '0') * 10;
        group += (num[i] - '0') * 100;
 
        gSum = gSum + group * p;

        p *= (-1);
    }
 	
    return (gSum % 7 == 0);
}

bool div8()
{
	if(n==1&&(str[n-1]-'0')%8==0)
		return 1;
	else
		if(n==1)
			return 0;
		else
			if(n==2)
			{
				string tmp="";
				tmp=tmp+str[n-2]+str[n-1];
				return (stoi(tmp)%8==0);
			}
			else
			{
				string tmp="";
				tmp=tmp+str[n-3]+str[n-2]+str[n-1];
				return (stoi(tmp)%8==0);
			}
}

bool div9()
{
	return (sum%9==0);
}

bool ongtrummodule(string str,int dg)
{
	unsigned long long ans=0;
	FOR(i,0,str.size()-1)
	{
		ans=(ans*10+(str[i]-'0'));
		ans%=dg;
	}
	return (ans==0);
}

void lds_go_goooo()
{	
/*n=str.size();
	
	FOR(i,0,n-1)
		dupp[str[i]-'0']++,sum+=(str[i]-'0');
	int ans=dupp[1];
	if(div2())
		ans+=dupp[2];
	if(div3())
		ans+=dupp[3];
	if(div4())
		ans+=dupp[4];
	if(div5())
		ans+=dupp[5];
	if(div6())
		ans+=dupp[6];
	//if(div7(str))
	//	ans+=dupp[7];//cout<<"hi";
	if(div8())
		ans+=dupp[8];
	if(div9())
		ans+=dupp[9];*/
	//cout<<ans;
	int n=str.size();
	mset(dupp,0);
	dupp[0]=0;
	dupp[1]=1;
	FOR(i,2,9)
		if(ongtrummodule(str,i))
			dupp[i]=1;
	
	int ans=0;
	FOR(i,0,n-1)
		if(dupp[str[i]-'0'])
			ans++;
	cout<<ans;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
