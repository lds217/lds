#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,maxx=-1;
    int arr[100000]={0};
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        arr[a]++;arr[b]--;
    }
    for(int x=1;x<=10000;x++)
    {
        arr[x]=arr[x]+arr[x-1];
       // cout<<arr[x]<<" ";
        maxx=max(maxx,arr[x]);
    }
    int res=0;
    for(int x=0;x<=10000;x++)
    {
        if(arr[x]==maxx)
            res++;
    }
    cout<<res;
}