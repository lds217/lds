#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float n;
    cin>>n;
    float temp=n;
        if(sqrt(n)==round(sqrt(n)))
            cout<<n<<" la sao chinh phuong";
        else    
            while(sqrt(temp)!=round(sqrt(temp)))
                temp++;
            cout<<temp;
system("pause");
return(0);
}