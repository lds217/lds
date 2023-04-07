#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

int main()
{
	int n; int a; int b;
	cin >> n;
    cin >> a;
    cin >> b;
    
    if (a>0 && b>0)
    {
        if( n%b==0&&n%a==0)
                cout<<"Co, tat ca!"<<endl;
        else
            {
            if( n%a==0 )
                cout<<"chia het cho "<<a<<endl;
            if(n%b==0)
                cout<<"chia het cho "<<b<<endl;
            }
        if (n%b!=0&&n%a!=0)
            cout<<"Khong chia het cho so nao ca"<<endl;
    }
    else
        cout<<"error"<<endl;
    
        //code chạy mà không biết sao nó chạy được =))    
system("pause");
return(0);
}