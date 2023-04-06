#include <bits/stdc++.h>
using namespace std;

long long N,D,F0,x,y,cnt1,cnt2;
double kc;
long long check[1001];
pair<int,int> t[1001];
vector <long long> f1[1001];
int main()
{
	cin >> N >> F0 >> D;
	check[F0]=1;
	for(int i=1;i<=N;i++)
		cin >> t[i].first >> t[i].second;
	for(int i=1;i<=N;i++)
	{
		if(i==F0)	continue;
		kc=sqrt((double)(pow(t[i].first-t[F0].first,2)+pow(t[i].second-t[F0].second,2)));
		if(kc<D)
		{
			cnt1++;
			f1[1].push_back(i);
			check[i]=1;
		}
	}
	for(long long j:f1[1])
		for(int i=1;i<=N;i++)
		{
			if(i==j)	continue;
			kc=sqrt((double)(pow(t[i].first-t[j].first,2)+pow(t[i].second-t[j].second,2)));
			if(kc<D&&check[i]==0)
			{
				cnt2++;
				check[i]=1;
			}
		}
	cout << cnt1 <<" "<< cnt2;
}
