#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
int n, l1, l2;
int a[MAX];
long long f[MAX];
long long fopt = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l1 >> l2;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=l1; i++) {
        f[i] = a[i];
    }
    for (int i=l1+1; i<=n; i++) {
        for (int j = l1; j<= l2; j++)
            if (i-j >= 0)
                f[i] = max(f[i-j] + a[i], f[i]);
    }
    for (int i=1; i<=n; i++) {
        fopt = max(fopt, f[i]);
    }
    cout << fopt;
    return 0;
}