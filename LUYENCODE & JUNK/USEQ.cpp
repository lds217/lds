#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
   int array[15]; int n;int i;float x;;int g;int le;
   cout<<"nhap so mang :";
   cin>>n;
   int c=0;
    cout<<"nhap mang"<<endl;
    for(i=0;i<n;i++)
    { 
        cout << " number "<< i+1 <<": ";
        cin>>array[i];
        
    }   
    for(int j=0;j<n;j++)  
    {   array[j]; g=0;
        for(int k=0;k<n;k++){
            if(array[k]==array[j])
                {g++;}
        }
            if(g%2==1)
             cout<<array[j]<<" ";
    }
system("pause");
return(0);
}