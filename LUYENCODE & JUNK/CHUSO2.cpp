#include <bits/stdc++.h>
#define ull unsigned long long;
uisng namespace std;

int main()
{
    ull p,a=1;
    cin>>p;
    ull start=0;
    while(start<=p)
    {
        start=start+(9*pow(10,a-1))*a;
        a++;
    }
    cout<<start;
}