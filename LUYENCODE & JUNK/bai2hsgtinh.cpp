#include <iostream>
using namespace std;

int main()
{
    int n;float arr[15];int count=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        if(arr[i]-10==0)
            count++;}
    cout<<count;        
system("pause");
return 0;
}