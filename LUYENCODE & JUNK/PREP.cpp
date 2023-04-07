#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;int b; int c;int d;
    cout<<"so sach";
	cin >> a;
    cout<<"so but";
	cin >> b;
    cout<<"gia sach";
    cin >> c;
      cout<<"gia but";
	cin >> d;
    if(a>=0 && b>=0 && c>=0 & d>=0)
    {
     int sum=a*c+b*d;
     cout<<"tong tien: "<< sum ;
    }
    else
     cout<<"ko thoa";
	system("pause");
	return(0);
}