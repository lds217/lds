#include <iostream>
using namespace std;

int main()
{
    int n;
    long long a[100000],ss[100000],ss1[100000];
    cin>>n;
    for(int i=0; i<n; i++) 
    {
        cin>>a[i];
        ss[i]=1;
        ss1[i]=1;
    }
    for(int x=0; x<n-1; x++)
        for(int i=x+1; i<n; i++)
            if(a[i]>a[x]&&ss[i]==ss[x])
                ss[i]++;
    for(int x=n-1;x>=1;x--)
        for(int i=x-1;i>=0;i--)
            if(a[i]>a[x]&&ss1[i]==ss1[x])
                ss1[i]++;
    long long res=0;
    for(int x=0;x<n;x++)
        cout<<ss[x]<<ss1[x]<<endl;
  

    
}