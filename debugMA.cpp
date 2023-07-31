#include <bits/stdc++.h>
using namespace std;

pair <int,int> t1,t0;
int n,m,i,j,d[1002][1002],x,ans,l,r,mid,d1[]={1,-1,0,0},d2[]={0,0,1,-1};

string a[1002];

bool check(int k)
{
	int i,f[1002][1002];
	memset(f,0, sizeof (f));
    pair<int,int> u,v1;
    queue <pair<int,int> > q;

   // f[t0.first][t0.second]=1;
   // q.push(t0);
    
   /* while (!q.empty())
    {
        u=q.front();
        q.pop();
        for (i=0;i<4;i++)
        {
            v.first=u.first+d1[i];
            v.second=u.second+d2[i];
            if (v.first>=1&&v.first<=m&&v.second>=1&&v.second<=n&&d[v.first][v.second]<=k&&a[v.first][v.second]!='#')
            {
                f[v.first][v.second]=1;
                q.push(v);
            }
        }
    }*/
    cout<<"hi";
    if (f[t1.first][t1.second]==1) return true;
	else return false;
}
int main()
{
    //freopen("INP.txt","r",stdin);
   // freopen("OUT.txt","w",stdout);
   vector <pair<int,int>> v;
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]='0'+a[i];
        for (j=1;j<=m;j++)
        {
            if (a[i][j]=='S') 
            {
                t0.first=i;
                t0.second=j;
            }
            if (a[i][j]=='E')
            {
                t1.first=i;
                t1.second=j;
            }
            if (a[i][j]=='#') v.push_back({i,j});
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (a[i][j]=='.') 
            {
                for (x=0;x<(int)v.size();x++)
                {
                    d[i][j]=min(d[i][j],abs(v[x].first-i)+abs(v[x].second-j));
                }
            }
        }
    }
	check(1);
    l=0;
    r=n*m;
   /* while (l<=r) 
    {
    	 
        mid=(l+r)/2;
        if (check(mid)) 
        {
            r=mid-1;
            ans=mid;
        }
        else 
        {
            l=mid+1;
        }
    }
    cout<<ans;*/
    return 0;
}