#include <iostream>
using namespace std;

int main()
{
    int N;int arr[10000];
    cout<<"nhap so mang ";
    cin>>N;
    int temp=N;
    for(int i=0;i<N;i++)
        {cin>>arr[i];}
    
    for(int x=0;x<N;x++)
    {
        for(int j=0;j<temp-1;j++)
            if(arr[j]<arr[j+1])
                swap(arr[j],arr[j+1]);
        temp--;
    }
    for(int k=0;k<N;k++)
        cout<<arr[k]<<" ";
    system("pause");
	return(0);
}