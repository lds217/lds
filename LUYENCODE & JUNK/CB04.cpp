#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

int main()
{
	int a; int b; int Sum; float Qut; int Sub;int Mul;
	cin >> a;
	cin >> b;
	if (abs(a) <= 100 && abs(b) <= 100)
	{
		Sum = a + b;
		cout<<"sum= " << Sum<<endl;
        Sub = a-b;
        cout <<"Sub= "<< Sub<<endl;
        Mul=a*b;
        cout <<"Mul= "<<  Mul<<endl;
        if(b!=0)
        {
            Qut=a/b;
            cout <<"Qut= "<<  fixed << setprecision(2) << Qut<<endl;
        }  
                
        else
             cout<<"inf"<<endl; 
          
	}	
	system("pause");
	return(0);
}