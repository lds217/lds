#include <bits/stdc++.h>
using namespace std;

int main()
{
    int wait[10000],cnt=0;
    int cord[10000][2];
    bool traverse[1000]={0};
    int N,F0,D;
    cin>>N>>F0>>D;
    for(int x = 1; x <= N; x++)
        cin>>cord[x][0]>>cord[x][1];
    int f1=0,f2=0;
    for(int x = 1; x <= N; x++)
        if(sqrt(pow(cord[F0][0]-cord[x][0],2)+pow(cord[F0][1]-cord[x][1],2))<D&&x!=F0)
        {
            f1++;
            wait[cnt++]=x;
            traverse[x]=1;
        }
    traverse[F0]=1;
    for(int i=0;i<cnt;i++)
    {
        F0=wait[i];
        for(int x = 1; x <= N; x++)
        if(sqrt(pow(cord[F0][0]-cord[x][0],2)+pow(cord[F0][1]-cord[x][1],2))<D&&x!=F0&&traverse[x]!=1)
        {
            f2++;
            traverse[x]=1;
        }
    }  
    

    cout<<f1<<" "<<f2;
}