#include <iostream>
#include <cmath>
using namespace std;
#define M 1000000007
#define maxN 10000007
bool eratos[10000007];
unsigned long long  value[maxN];
void gen_eratos(int n)
{
    for(int x=2;x<=n;x++)
        if(eratos[x]==0)
            for(int y=x;y<=n;y+=x)
            {
                eratos[y] = 1;
                int temp=y;
                while(temp%x==0&&x>0)
                {
                    temp/=x;
                    value[x]++;
                }
            }
}

unsigned long long poww(unsigned long long  x, unsigned long long  n) {
    if(n==0) return 1;
    unsigned long long  t = poww(x,n/2);
    t=t*t%M;
    if(n%2)t=t*x%M;
    return t;
}

int main()
{
    unsigned long long  n;
    cin>>n;
    gen_eratos(n);
    long long res=1;
  // for(int i=0;i<=n;i++) cout<<value[i]<<" ";
    for(int x=2; x <= n; x++)
        if(value[x]%2!=0)
        {
            value[x]--;
            res=res*poww(x,value[x]);
            res%=M;
        }
        else
            res*=poww(x,value[x]),res%=M;;
      //  cout<<poww(100000,100000000);
    cout<<res%M;
}//testtime
