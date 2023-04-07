#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    unsigned long long bcnn = a * b / __gcd(a, b);
    bcnn = bcnn * c / __gcd(bcnn, c);
    unsigned long long res = 1, x = 0, cnt = 0;
    for (unsigned long long i = 2; i * i <= bcnn; ++i)
    {
        cnt = 0;
        while (bcnn % i == 0)
        {
            bcnn /= i; //chia ra giảm vòng lặp
            cnt++;
        }
        if (cnt % 2 != 0)
            cnt++;
            // cái nào mũ lẻ thì cộng lên chẵn
        res *= pow(i, cnt / 2);
        //lấy căn trước để tránh tràn dữ liệu
    }
    cout << res * bcnn; // vì mỗi lần phân tích bcnn bị chua rồi lại lấy đến sqrt của bcnn thôi nên luôn bị thiếu số cuối đó là giá trị của bcnn sau khi chia bccn/=i...
    return 0;
}