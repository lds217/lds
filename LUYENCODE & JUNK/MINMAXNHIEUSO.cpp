#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int arr[200];
    int N;
    cout<<" nhap so phan tu ";
    cin>>N;
    for(int x=0;x<N;x++)
        cin>>arr[x];

    int MAX= arr[0];
    int MIN= arr[0];
    for(int i=1; i<N;i++)
    {
        if(MAX<arr[i])
            MAX=arr[i];
        
        if(MIN>arr[i])
            MIN=arr[i];
    }
    cout<<"max la "<<MAX<<endl;
    cout<<"min la "<<MIN<<endl;
    system("pause");
    return(0);
}