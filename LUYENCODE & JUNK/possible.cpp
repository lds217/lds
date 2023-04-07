#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int K;
    cin >> K;
    long long a, b;
    while (K--)
    {
        cin >> a >> b;
        long long c;
        a=abs(a);
            c=(1+a)*a/2;

        if (((abs(c % 2) == 0 && abs(b % 2) == 0) || (abs(c % 2 )!= 0 && abs(b % 2 )!= 0))&&c<=b&&b>=-c)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}