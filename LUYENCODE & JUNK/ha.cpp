#include <bits/stdc++.h>
using namespace std;

int arr[101][101],n,m;

void input()
{
    cin>>n>>m;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++) 
                cin>>arr[x][y];  
    for(int x=1;x<=m;x++) 
        arr[0][x]=arr[n+1][x]=-101;
}


void spread()
{
    for(int y=2;y<=m;y++)
        for(int x=1;x<=n;x++) 
            arr[x][y]+=+max(arr[x-1][y-1],max(arr[x][y-1],arr[x+1][y-1]));
    // for(int y=1;y<=m;y++)
    // {
    //     for(int x=1;x<=n;x++)
    //         cout<<arr[x][y]<<" ";
    // cout<<endl;
    // }
}

int res()
{
    int maxx=arr[1][m];
    for(int x=1;x<=n;x++)
        if(arr[x][m]>maxx)
            maxx=arr[x][m];
    return maxx;
}

int main()
{
    input();
    spread();
    cout<<res();
}