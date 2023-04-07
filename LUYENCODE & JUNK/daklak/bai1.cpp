#include <iostream>
using namespace std;



int ucln(int b,int d)
{
    while(b!=d)
    {
        if(b>d)
            b=b-d;
        else
            d=d-b;
    }
    return d;
}


int main()
{
    int a,b,c,d;int mau;int tu;
    cin>>a>>b;
    cin>>c>>d;
    if(ucln(b,d)==1)
        mau=b*d;
    else
        mau=ucln(b,d);
    tu=a*(d/ucln(b,d))+c*(b/ucln(b,d));
    cout<<tu<<" "<<mau;
    return 0;
}