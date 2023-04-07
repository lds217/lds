#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,K;
    cin>>N>>K;
    int arr[100000];
    for(int x=0;x<N;x++)
        cin>>arr[x];
    sort(arr,arr+N);
    int minn,maxx;
    for(int x=0;x<K;x++)
        minn+=arr[x];
    for(int x=N-K-1;x<N-1;x++)
        maxx+=arr[x];
    cout<<minn<<" "<<maxx;
    return 0;
}