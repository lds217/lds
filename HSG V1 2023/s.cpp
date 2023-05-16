#include <cstdio>
 
using namespace std;
char a[100000], b[100000];
int n, res;
 
int main()
{
    scanf("%d\n", &n);
    scanf("%s\n", a); scanf("%s\n", b);
    int i, cnt = 0;
    if (a[0] == '1' && b[0] == '1' && a[1] == '0' && b[1]=='0')
	{res++; a[0]='0'; b[0]='0';}
    if (a[n-1] == '1' && b[n-1] == '1' && a[n-2] == '0' && b[n-2]=='0') {res++; a[n-1]='0'; b[n-1]='0';}
    for(i=1; i<n-1; i++)
    if (((a[i]!=a[i+1]) && (a[i]!=a[i-1])) &&
    ((b[i]!=b[i+1]) && (b[i]!=b[i-1]))) {
        if (a[i] == '1') a[i] = '0'; else a[i] = '1';
        if (b[i] == '1') b[i] = '0'; else b[i] = '1';
        res++;
    }
    a[n] = '0'; b[n] = '0';
    for(i=0; i<=n; i++) {
        if (a[i] == '1') cnt++;
        if (a[i] == '0') {
            if (cnt > 0) res++;
            cnt = 0;
        }
    }
    for(i=0; i<=n; i++) {
        if (b[i] == '1') cnt++;
        if (b[i] == '0') {
            if (cnt > 0) res++;
            cnt = 0;
        }
    }
    printf("%d", res);
    return 0;
}
 