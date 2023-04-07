#include <bits/stdc++.h>
using namespace std;
int x[31], y[31], n;
int u, v ;   int a,b;;
map<pair<int, int>, int> m1;
map<pair<int, int>, int> m2;
long long res=0;

void Try(map<pair<int, int>,int>  &m, int begin, int end)
{
    int N=end-begin;
        for(int mask=0;mask<=(1<<N)-1;mask++)
        {
            for(int i=N-1;i>=0;i--)
            {
              //  cout<<((mask>>i)&1);
                if(((mask>>i)&1)==1)
                    a+=x[begin+i],b+=y[begin+i];
            }
           //   cout<<endl;
            m[pair<int,int>(a,b)]++;
            a=b=0;
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cin >> u >> v;
    
    Try(m1, 0, n/2);
    Try (m2 , n/2,n);
    long long res=0;
    for(auto it=m1.begin();it!=m1.end();it++)
    {
        //cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
        pair<int, int> f = pair<int, int>(u - it->first.first, v - it->first.second);
        if(m2[f]!=0)
            res+=(long long) it->second*m2[f];
    }
    cout<<res;
    // for(auto it=m2.begin();it!=m2.end();it++)
    // {
    //     cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;

    // }
    //cout<<res;
}