#include <iostream>
#include <cstring>
#define MOD 100000000
using namespace std;

int n1, n2, k1, k2;
int save[101][101][11][11];

long long C(int f, int h, int kf, int kh)
{
    if (save[f][h][kf][kh] == -1)
    {
        long long ans;
        if (f + h == 0)
            ans = 1;
        else
        {
            ans = 0;
            if (f > 0 && kf > 0)
                ans = (ans + C(f - 1, h, kf - 1, k2)) % MOD;
            if (h > 0 && kh > 0)
                ans = (ans + C(f, h - 1, k1, kh - 1)) % MOD;
            save[f][h][kf][kh] = ans;
        }
    }
    return save[f][h][kf][kh];
}

int main()
{
    memset(save, -1, sizeof(save));
    cin >> n1 >> n2 >> k1 >> k2;
    cout << -C(n1, n2, k1, k2) << endl;
    return 0;
}
