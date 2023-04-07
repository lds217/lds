#include <iostream>
using namespace std;

int main()
{
    unsigned long long arr[10000];
    bool check[10000];
    int N;
    cin>>N;
    int res=0;
    int temp=0;
    for(int x=0;x<N;x++)
    {
        cin>>arr[x];
        check[x]=1;
    }
    for(int x=0;x<N;x++)
    {
        if(check[x]==1)
        {
            temp=0;
            check[x]=0;
            for(int i=x;i<N;i++)
            {

                if((arr[i]>arr[i-1]&&arr[i]<arr[i+1]&&i!=0)||(i==0&&arr[i+1]>arr[i]))
                {
                    check[i]=0;
                    temp++;
                }
            }
        }
        if(temp>res)
            res=temp;
    }
    cout<<res;
}