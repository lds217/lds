#include <iostream>
#include <math.h>
using namespace std; 

int main()
{int count;int number;int n;int sum=0;
    cin>>n;
    int cache=n;
    while(cache!=0){
        cache = cache/10;
        count++; //count digits of number
    }
    int temp=n;
    for(int j=count;j>0;j=j-1)
    {  
        int pow10=pow(10,j-1);
        int x=temp/pow10;
        sum=sum + x;
        temp=temp%pow10; 
    }
    //cout<<sum<<endl;//total of digits
int somethingthatidontknowhowtoname = sum%10;
if(somethingthatidontknowhowtoname==9)
    cout<<"YES";
else
    cout<<"NO";

system("pause");
return(0);
}