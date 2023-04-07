#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
const int MAXN=1001;
int number[MAXN]={0},low[MAXN]={0};
vector<int> k[MAXN];
stack<int> st;
int res=0;

void tarjan(int u)
{
    low[u]=number[u]=cnt++;
    st.push(u);
    for(auto v : k[u])
    {
        if(number[v]!=0)
        {
            low[u]=min(low[u],number[v]);
        }
        else
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(number[u]==low[u])
    {
        res++;
        int temp;
        do
        {
            temp=st.top();
            st.pop();
            number[temp]=low[u]=INT_MAX;
        } while (temp!=u);
        
    }
}

using namespace std;
int main() {
    cin>>n>>m;
    int u,v;
    for(int i=0;i<n;i++)
    {
        cin>>u>>v;
        k[u].push_back(v);
    }
    for(int x=0;x<n;x++)
        if(number[x]==0)
            tarjan(x);
    cout<<res;
}