#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    int N;
    cout<<"nhap nam sinh ";
    cin>>N;
    if(1900<=N && N<=2018)
    {
        int age=2021-N;
        cout << age;
    }
    else 
        cout<<"ko thoa";

system("pause");
return(0);

}