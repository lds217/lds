#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int N,res=0,temp=0;
    cin>>N;
    char a[100000];
    for(int x=1;x<=N;x++)
    {
        cin>>a[x];
        if(a[x]==a[x-1])
            temp++;
        else
        {
            if(temp!=1)
            {
                 res=res+temp/2;
                 if(temp%2!=0)
                  res++;
            }
                else
                    res=res+temp;
            temp=0;
        }
        if(x==N)
        {
            if(temp!=1)
            {
                 res=res+temp/2;
                 if(temp%2!=0)
                  res++;
            }
                else
                    res=res+temp;
        }
        
    }
    cout<<res;
}