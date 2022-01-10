#include <iostream>
#define MAX 10007
using namespace std;
int n;
int a[MAX];
int f[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        f[i] = 1;
    }
    for (int i=2; i<=n; i++) {
        for (int j=1; j<i; j++) {
        if (a[i] > a[i-j])
            f[i] = max(f[i-j] + 1, f[i]);
        }
    }
    int res = 1;
    for (int i=2; i<=n; i++) res = max(res, f[i]);
    cout << res;
    return 0;
}