#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,k,q,arr[100001],m,res[10001],cnt=0;
    cin>>n>>k>>q;
    for(int x=0;x<n;x++)
        cin>>arr[x];
    int rot=k%n; // ta thay nen so lan quay k chia het cho day n thi day quay ve ban dau nen thay vi lam cho k lan thi ta chi can lam cho so lan du
    for(int x=0;x<q;x++)
    {
        cin>>m;
        for(int i=0;i<n;i++)
            if(i==m)
                if(i-rot>=0)
                    res[cnt++]=arr[i-rot]; // thay vi chay for se 6/7 t thay qui luat k=3 thi so cho m se di chuyen lui ve 3
                else
                    res[cnt++]=arr[(n-1)-(rot-(i+1))];
    }
    for(int x=0;x<cnt;x++)
        cout<<res[x]<<endl;
        //mong cac ban code ac :3
}