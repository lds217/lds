#include <bits/stdc++.h>

using namespace std;
#define M 998244353

int eratos[10000007];

void gen_eratos()
{
    for(long long i=1; i*i<=10000007; i++)
            for(long long j=i*i+i;j<=10000007;j+=i)
                eratos[j] ++;
}

long long poww(int x, int n) {
    if(n==0) return 1;
    long long t = poww(x,n/2);
    t=t*t%M;
    if(n%2)t=t*x%M;
    return t;
}


int main()
{
    unsigned long long T,N;
    cin>>T;
    gen_eratos();
    //  for(int x=0;x<=10;x++)
    //      cout<<eratos[x]<<" ";
    while(T--)
    {   
        cin>>N;
        int k=sqrt(N);
         long long res=poww(N,eratos[N]);
        if(k*k==N)
            res=res*k %M;
        cout<<res<<endl;
    }
}