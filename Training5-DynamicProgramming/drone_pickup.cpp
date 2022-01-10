#include<bits/stdc++.h>
#define MAX 3007
using namespace std;
int n, k;
int c[MAX];
int a[MAX];
int f[107][MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    f[1][1] = c[1];
    for (int i=1; i<=k; i++) {
        for (int j=i; j<=n; j++) {
            for (int t=1; t<=a[j]; t++) {
                if (f[i][j] != 0)
                f[i+1][j+t] = max(f[i+1][j+t], f[i][j] + c[j+t]);
            }
        }
    }
    int res = 0;
    for (int i=1; i<=k+1; i++) {
        res = max(res, f[i][n]);
    }
    cout << res;
    return 0;
}