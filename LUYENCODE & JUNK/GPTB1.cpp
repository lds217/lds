#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double a, b, c, a1, b1, c1;
double x, y;

bool VONGHIEM()
{
    if (a / a1 == b / b1 && b / b1 != c / c1)
        return 1;
    return 0;
}

bool VOSONGHIEM()
{
    if (a / a1 == b / b1 && b / b1 == c / c1)
        return 1;
    return 0;
}

void process_a()
{
    if (a < 0)
    {
        a = a * -1;
        b = b * -1;
        c = c * -1;
    }
    if (a1 < 0)
    {
        a1 = a1 * -1;
        b1 = b1 * -1;
        c1 = c1 * -1;
    }
}

double func_GCD(double m, double n)
{
    while (m != n)
    {
        if (m > n)
            m = m - n;
        if (n > m)
            n = n - m;
    }
    return m;
}

void mul(double LCM)
{
    // cout << a << " " << b << " " << c << endl;
    //  cout << a1 << " " << b1 << " " << c1 << endl;
    b = b * (LCM / a);
    c = c * (LCM / a);
    a = a * (LCM / a);
    b1 = b1 * (LCM / a1);
    c1 = c1 * (LCM / a1);
    a1 = a1 * (LCM / a1);
    //  cout << a << " " << b << " " << c << endl;
    //   cout << a1 << " " << b1 << " " << c1 << endl;
}

void xuly()
{
    y = (c - c1) / (b - b1);
    x = (c - b * y) / a;
}

void xuat()
{
    cout << fixed;
    cout.precision(2);
    cout << x << " " << y;
}

int main()
{
    cin >> a >> b >> c >> a1 >> b1 >> c1;
    if (VONGHIEM())
        cout << "VONGHIEM";
    else if (VOSONGHIEM())
        cout << "VOSONGHIEM";
    else
    {
        process_a();
        double LCM = abs(a * a1) / func_GCD(a, a1);
        //   cout << LCM << endl;
        mul(LCM);
        xuly();
        xuat();
    }
}