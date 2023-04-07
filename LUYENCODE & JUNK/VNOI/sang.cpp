#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,K;
    //int r=2;
    while(cin>>N>>K)
    {
        
        bool era[10000]={0};
        int cnt=0;
        for(int i=2;i<=N;i++)
            if(era[i]==0)
                for(int j=i;j<=N;j+=i)
                    if(era[j]==0)
                    {
                        era[j]=1;
                        cnt++;
                        if(cnt==K)
                        {
                            cout<<j<<endl;
                            i=N+1;
                            break;
                        }
                    }
    }
}