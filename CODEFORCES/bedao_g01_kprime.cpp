#include <bits/stdc++.h>
using namespace std;

bool eratos[10000001];
int n, k;
void gen_eratos()
{
    eratos[1] = eratos[0] = 1;
    for (int x = 2; x * x <= n; x++)
        if (eratos[x] == 0)
            for (int y = x * x; y <= n; y += x)
                eratos[y] = 1;
}

int main()
{

    cin >> n >> k;
    gen_eratos();
    long long l = 1, r = 1, cnt = 0, res = 0;
    // for (int x = 0; x <= n; x++)
    //     cout << eratos[x] << " ";
    while (r <= n)
    {
        if (eratos[r] == 0)
            cnt++;
        while (cnt == k)
        {
            res += n - r + 1;
            if (eratos[l] == 0)
                cnt--;
            l++;
        }
        r++;
    }
    cout << res;
}
