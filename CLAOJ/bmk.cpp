#include<bits/stdc++.h>
#define reu(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define red(i,a,b) for(int i=a,_b=b;i>=_b;--i)
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define iii pair<int,ii>
using namespace std;
const int N = 11;
const ll M=9876543210;

ll l,r;
int n;
ll f[N][1<<11][3];
string s;

void input()
{
    cin >> l >> r;
}

ll dp(int pos,int mask,bool ok)
{
    if(pos==n) return 1;
    ll &res=f[pos][mask][ok];
    if(~res) return res;
    res=0;
    int c=int(s[pos])-48;
    int lim=(ok)?9:c;
    cout<<lim;
    reu(i,0,lim)
    {
        if(mask==0 && i==0)
        {
        	cout<<1;
            res+=dp(pos+1,mask,ok|(i<lim));
        }
        else
        if((mask&(1<<i))==0)
        {
            res+=dp(pos+1,mask|(1<<i),ok|(i<lim));
        }
    }
    return res;
}

int main()
{
   // freopen("cspb.inp","r",stdin);
   // freopen("cspb.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    if(l>M)
    {
        cout<<0;
        return 0;
    }
    if(r>M)
    {
        r=M;
    }
    l--;
    s=to_string(r);
    n=sz(s);
    memset(f,-1,sizeof(f));
    ll t1=dp(0,0,0);
    s=to_string(l);
    n=sz(s);
    memset(f,-1,sizeof(f));
    cout<<t1-dp(0,0,0);
    return 0;
}
