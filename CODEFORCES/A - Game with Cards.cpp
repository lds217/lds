#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    {
        int maxa=-1,maxb=-1;
        cin>>n;
        for(int x=0;x<n;x++){cin>>a; maxa=max(maxa,a);}
        cin>>m;
        for(int x=0;x<m;x++){cin>>b; maxb=max(maxb,b);}
        if(maxa==maxb)
        {
            cout<<"Alice"<<endl;
            cout<<"Bob"<<endl;
        }
        else
            if(maxa>maxb)
            {
                cout<<"Alice"<<endl;
                cout<<"Alice"<<endl;
            }
            else
            {
                cout<<"Bob"<<endl;
                cout<<"Bob"<<endl;
            }
 
    }
}