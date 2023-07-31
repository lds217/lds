#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    long long tong=0;
    if(a%2==1)
    {
        tong=tong+a/2;
    }
    else
    {
        tong-tong+(a+1)/2;
    }
    
    if(b%2==1)
    {
        tong=tong+b/2;
    }
    else
    {
        tong-tong+(b+1)/2;
    }
    
    if(c%2==1)
    {
        tong=tong+c/2;
    }
    else
    {
        tong-tong+(c+1)/2;
    }
    
    if(d%2==1)
    {
        tong=tong+d/2;
    }
    else
    {
        tong-tong+(d+1)/2;
    }
    
    if(e%2==1)
    {
        tong=tong+e/2;
    }
    else
    {
        tong-tong+(e+1)/2;
    }
    
    if(f%2==1)
    {
        tong=tong+f/2;
    }
    else
    {
        tong-tong+(f+1)/2;
    }
}