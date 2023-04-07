#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a; int b; int div;
	cin >> a;
	cin >> b;
	if (a < 1000000 && 0<a && b < 1000000  && 0<b)
	{
		div=a%b;
		cout<<div;
	}
	else 
		cout<<"ko thoa";
system("pause");
return(0);
}