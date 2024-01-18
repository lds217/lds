#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double m, n, a[301], b[301], l, k;

double distance(double x, double y)
{
    return sqrt(pow(abs(x - y), 2) + pow(l, 2));
}

int main()
{
    cin >> m >> n >> l >> k;
    for (int x = 0; x < m; x++)
        cin >> a[x];
    for (int x = 0; x < n; x++)
        cin >> b[x];

    double dp[301][301];
    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++)
            dp[y][x] = distance(a[x], b[y]);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
            cout <<dp[x][y]<<setw(10) ;
        cout << endl;
    }
}