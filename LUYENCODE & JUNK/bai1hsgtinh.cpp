#include <iostream>
using namespace std;

int main()
{
    int a,b,c,m,n,k;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>k;
    cin>>m;
    cin>>n;
    int Sum=a*k + b*(m-k) + c*(n-m);
    cout<<Sum;
system("pause");
return 0;
}