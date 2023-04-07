#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        int a[n+1],b[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        int res[1000][2],cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                for(int j=0;j<n;j++)
                    if(b[j]<=a[i+1]&&i!=j)
                    {
                        res[cnt++][0]=i;
                        res[cnt++][1]=j;
                    }
            }
        }
    }
}