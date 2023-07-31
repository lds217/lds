#include <bits/stdc++.h>
using namespace std;
using db=double;
struct node {
    int f,s;
    int w;
};
int n,tong,so;
db ans;
node a[100001];
vector <int> vec;
bool cmp(node x,node y) {
    double so=double(x.f)/double(x.s);
    double so1=double(y.f)/double(y.s);
	return (so>so1) || (so==so1 && x.w<y.w);
}
int main() {
    //freopen("survey.inp","r",stdin);
    //freopen("survey.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;++i) cin >> a[i].s;
	for (int i=1;i<=n;++i) cin >> a[i].f;
	for (int i=1;i<=n;++i) a[i].w=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i) 	cout<<a[i].s<<' ';
	cout<<endl;
	for (int i=1;i<=n;++i) 	cout<<a[i].f<<' ';
	ans=double(a[1].f)/double(a[1].s);
	tong=a[1].f;
	so=a[1].s;
	vec.push_back(a[1].w);
	for (int i=2;i<=n;++i) {
		tong+=a[i].f;
		so+=a[i].s;
		if (double(tong/so)>=ans) {
			ans=double(tong/so);
			vec.push_back(a[i].w);
		}
	}
	cout << vec.size() << '\n';
	for (int i=0;i<vec.size();++i) cout << vec[i] << " ";
}