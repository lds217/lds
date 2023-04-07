#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin >> N;
        long long a[N + 1], res[N + 1] = {0};
        for (int i = 0; i < N; i++)
            cin >> a[i];
        long long amountVNI = 1, sum_boughtVNI = 0, temp = a[N - 1], pos = N - 1;
        for (int i = N - 2; i >= 0; i--)
        {
            sum_boughtVNI += a[i];
            if (a[i] <= temp)
            {
                res[i] = max(res[i + 1], temp * amountVNI - sum_boughtVNI + res[pos]);
                amountVNI++;
            }
            else
            {
                res[i] = max(res[i + 1], max(0LL, temp * amountVNI - sum_boughtVNI));
                sum_boughtVNI = 0;
                amountVNI = 1;
                temp = a[i];
                pos = i;
            }
        }
    cout<<res[0]<<endl;
    }
}