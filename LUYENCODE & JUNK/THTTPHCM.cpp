#include <iostream>
#include <cmath>
using namespace std;

int CalNA(int A)
{
    int n = 1, a = 2;
    while (a <= sqrt(A))
    {
        if (A % a == 0)
        {
            while (A % a == 0)
                A /= a;
            n *= a;
        }
        ++a;
    }
    return n * A;
}
long long mod(long long u, long long v, int m)
{
    if (v == 1)
        return u % m;
    long long t = mod(u, v / 2, m);
    if (v % 2 == 0)
        return (t * t) % m;
    return ((u % m) * (t * t % m) % m);
}

int CalN(int n,int A)
{
    int q = 1;
    while (mod(q * n, q * n, A) != 0)
        q++;
    return q * n;
}

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (sqrt(a * b * c) == round(sqrt(a * b * c)))
        cout << sqrt(a * b * c);
    else
        cout << CalN(a * b * c,CalNA(a*b*c));
}