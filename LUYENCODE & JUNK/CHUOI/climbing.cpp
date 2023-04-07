#include <iostream>
using namespace std;

int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    int arr[1000000];
    int count=0;
    for(int x=1;x<=n;x++)
        cin>>arr[x];
    for(int x=1;x<=n-m+1;x++)
    {
        int max=arr[x];
        int min=arr[x];
        for(int i=x;i<x+m;i++)
        {
            if(arr[i]>max)
                max=arr[i];
            if(arr[i]<min)
                min=arr[i];   
        }
        if(max-min<=c)
        {
            cout<<x<<endl;
            count++;
        }

    }
    if(count==0)
        cout<<"NONE";
    return 0;
}