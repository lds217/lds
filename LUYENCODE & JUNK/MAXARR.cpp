#include <iostream>
using namespace std;
int a[100001];
void Value(){
    a[0] = 0; // khoi tao gia tri trong mang
    a[1] = 1; // khoi tao gia tri trong mang
    for (int i = 2; i <= 100000; i++){
        if (i % 2 == 0)
            a[i] = a[i / 2];
        else
            a[i] = a[i / 2] + a[(i + 1) / 2];
    }
}
// ham tim gia tri lon nhat trong mang
int get_max(int n){
    int max = 0;
    for (int i = 1; i <= n; i++){
        if (max < a[i])
            max = a[i];
    }
    return max;
}
// ham chinh
int main(){
    int t;
    cin >> t;
    Value();
    while (t--){
        int n;
        cin >> n;
        cout << get_max(n) << endl;
    }
    return 0;
}