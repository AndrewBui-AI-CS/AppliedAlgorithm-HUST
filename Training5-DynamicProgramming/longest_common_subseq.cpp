#include<bits/stdc++.h>
#define MAX 10007
using namespace std;
int n, m;
int X[MAX];
int Y[MAX];
int f[MAX][MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> X[i];
    for (int j=1; j<=m; j++) cin >> Y[j];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (X[i] == Y[j]) {
                f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
            }
            else {
                f[i][j] = max(f[i][j], f[i-1][j]);
                f[i][j] = max(f[i][j], f[i][j-1]);
            }
        }
    }
    cout << f[n][m];
    return 0;
}