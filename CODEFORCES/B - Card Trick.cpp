#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long m,n;
        cin>>m;
        long long a[m+1]={0};
        for(int i=0;i<m;i++)
            cin>>a[i];
        cin>>n;
        long long changes=0,temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp; 
            changes+=temp;
        }
        cout<<a[changes%m]<<endl;
    }
}