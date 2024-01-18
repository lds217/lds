#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FOD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define MASK(i) (1LL << (i))


using namespace std;
mt19937 rd(time(0));
int Rand(int l, int r) {
    return l + rd() % (r - l + 1);
}
#define task "PER"
void make_test() {
    ofstream inp(task".inp");

    inp << Rand(1,100)<<' '<<Rand(1,100)<<endl;
}

int main() {
    FOR(itest, 1, 50) {
        make_test();
        system(task".exe");
        system("PERtrau.exe");
        if (system("fc " task".ans " task".out")) {
            cout << itest << ": NO\n";
            return 0;
        }
        cout << itest << ": YES\n";
    }

    return 0;
}