#include <bits/stdc++.h>
#include <string>
#define ull unsigned long long
using namespace std;

int main()
{
    ull p,a=1;
    cin>>p;
    ull start=1;
    ull temp;
    while(start<=p)
    {   
        temp=start;
        start=start+(9*pow(10,a-1))*a;
        a++;
    }
    ull num=pow(10,a-2);
    ull sizee=to_string(num).length();
    num=num+(p-temp)/sizee;
    cout<<to_string(num)[(p-temp)%sizee];
}