#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
   int array[15]; float n;int sum;int i;
   cout<<"nhap so mang :";
   cin>>n;
    cout<<"nhap mang"<<endl;
    for(i=0;i<n;i++)
    {
        cout << " number "<< i+1 <<": ";
        cin>> array[i];
        sum = sum + array[i];
    }
    cout<<sum<<endl;
    float avg=sum/n;
    cout<< avg;
system("pause");
return(0);

}