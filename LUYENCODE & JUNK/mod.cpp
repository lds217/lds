#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    double a,b,c;
    cin>>a>>b>>c;
    if(sqrt(a)!=round(sqrt(a)))
            a=a*a;
    if(sqrt(b)!=round(sqrt(b)))
            b=b*b;
    if(sqrt(c)!=round(sqrt(c)))
            c=c*c;
    n=a*b*c;
    cout<<sqrt(n);
}