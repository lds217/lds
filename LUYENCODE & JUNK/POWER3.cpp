#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
   int array[15]; int n;int i;float x;int j;
   cout<<"nhap so mang :";
   cin>>n;
   int c=0;
    cout<<"nhap mang"<<endl;
    for(i=0;i<n;i++)
    { 
        cout << " number "<< i+1 <<": ";
        cin>>array[i];
        for(j=0;j<array[i];j++)
           {if(pow(j,3)==array[i])
                cout<<"YES"<<endl; 
            else
                c=c+1;       
            } if(c==j)
                    cout<<"NO"<<endl;    
            //reset c
            c=0;         
    }     
system("pause");
return(0);

}