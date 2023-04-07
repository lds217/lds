#include <iostream>
using namespace std;
int main()
{
    int n;
    unsigned long long int a[100],l[100];
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) cin>>a[i];
// check array //for (int i=0;i<n;i++) cout<<arr[i];
        l[0] = 1;
    unsigned long long int lmax;
    for (int i=1;i<n;i++)
    {
        lmax = 0;
        for (int j=0;j<i;j++)
        {
            if (a[j]<a[i])
                if (l[j]>lmax ) 
                    lmax = l[j];
        }
    l[i] = lmax + 1;

    }
    unsigned long long int lengmax = 0;
    for (int i=0;i<n;i++)
    {
        if (lengmax < l[i]) lengmax = l[i];
    }
cout<<lengmax;
return 0;
}


 
