#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, t, a[200005], mid, l = 1, r = 1e9;

ll check()
{
    long long sum=0;
    for (int x = 0; x < n; x++)
        sum += mid / a[x];
    return sum;
}

int main()
{

    cin >> n >> t;
    for (int x = 0; x < n; x++)
    {
        cin >> a[x];
        r = min(r, a[x]);
    }
    r *= t;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check() >= t)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
}