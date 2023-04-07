#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a; int b; int Sum;
	cin >> a;
	cin >> b;
	if (abs(a) <= 100 && abs(b) <= 100)
	{
		Sum = a + b;
		cout << Sum;
	}
	else
    {
		cout << "khong thoa" << endl;
    }
	system("pause");
	return(0);
}