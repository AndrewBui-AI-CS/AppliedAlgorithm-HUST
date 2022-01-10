#include <bits/stdc++.h>
#define MAX 1000007
using namespace std;
int a[MAX];
int n;
int f[MAX];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    cin >> a[i];
    f[1] = a[1];
    for (int i=2; i<=n; i++) {
        f[i] = max(f[i-1] + a[i], a[i]);
    }
    int res = INT_MIN;
    for (int i=1; i<=n; i++)
        res = max(res, f[i]);
    cout << res;
    return 0;
}