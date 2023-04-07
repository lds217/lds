#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    int a; int b;int c;int sum;
    cin>>a;
    cin>>b;
    cin>>c;
    if(-1000<=a && a<=1000 && -1000<=b && b<=1000 && -1000<=c && c<=1000 )
    {
        sum=a+b+c;
        cout<<sum;
    
    }
    else 
        cout<<"khong thoa";
 system("pause");
 return(0);
}