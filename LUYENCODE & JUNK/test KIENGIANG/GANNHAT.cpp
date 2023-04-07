#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long X[n],Y[n];
    for(int i=1;i<=n;i++)
        cin>>X[i]>>Y[i];
    double res=1000000;
    for(int x=1;x<=n-1;x++)
    {
        for(int y=x+1;y<=n;y++)
        {
            int u=abs(X[y]-X[x]);
            int v=abs(Y[y]-Y[x]);
            double a=sqrt(u*u+v*v);
            res=min(  res   ,a) ;
        }
    }
    cout<<fixed<<setprecision(3)<<res;
}
