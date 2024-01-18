#include<iostream>
#include<cstdio>
#define gmx(a,b) (a=(a)>(b)?(a):(b))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(u) for(int i=hd[u],v;v=e[i].v,i;i=e[i].n)
using namespace std;
typedef long long ll;
const int N=200200;
const ll INF=1e14;
struct edge{int n,v;}e[N<<1];
int n,u,v,fl,hd[N],fa[N];
ll ans,a[N],f[N][5];
void add(int u,int v){e[++fl]=(edge){hd[u],v};hd[u]=fl;}
void dfs(int u){
	f[u][0]=f[u][1]=a[u];
	f[u][2]=f[u][3]=f[u][4]=-INF;
	REP(u)if(v!=fa[u]){
		fa[v]=u;dfs(v);
		gmx(ans,f[u][0]+f[v][2]);
		gmx(ans,f[u][1]+f[v][1]);
		gmx(ans,f[u][2]+f[v][0]);
		gmx(f[u][2],f[v][2]+a[u]);
		gmx(f[u][2],f[u][0]+f[v][1]);
		gmx(f[u][2],f[u][4]+f[v][0]+a[u]);
		gmx(f[u][4],f[v][1]);
		gmx(f[u][1],f[v][1]);
		gmx(f[u][1],f[u][0]+f[v][0]);
		gmx(f[u][0],f[v][0]+a[u]);
	}
}
int main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld",&a[i]);
	FOR(i,2,n) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1);
	cout<<ans<<'\n';
}