#include <bits/stdc++.h>
#include <string>
#define ull unsigned long long
using namespace std;

int main()
{
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);
  //  cout.tie(0);
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
    //cout<<temp<<" ";
    
    ull num=pow(10,a-2);
   // cout<<num;
    ull sizee=to_string(num).length();
    num=num+(p-temp)/sizee;
    cout<<to_string(num)[(p-temp)%sizee];
}
    