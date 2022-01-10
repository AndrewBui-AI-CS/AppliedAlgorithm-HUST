#include<bits/stdc++.h>
#define MAX 27
using namespace std;
int f = 0, fopt = 1e9;
int c[MAX][MAX];
int mark[MAX];
int v[MAX];
int n;
int cmin = 1e9;
void Try(int k) {
    for (int i=1; i<=n; i++) {
        if (!mark[i]) {
            mark[i] = 1;
            v[k] = i;
            if (k == 1) {
                f = f + c[0][i] + c[i][i+n];
            }
            else {
                f = f + c[v[k-1] + n][i] + c[i][i+n];
            }
            if (k == n) {
                if (fopt > f + c[v[k] + n][0]) fopt = f + c[v[k] + n][0];
            }
            else {
                int g = f + (2*n+1 - 2*k)*cmin;
                if (g < fopt)
                Try(k+1);
            }
            mark[i] = 0;
            if (k==1) {
                f = f - c[0][i] - c[i][i+n];
            }
            else {
                f = f - c[v[k-1] + n][i] - c[i][i+n];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<=2*n; i++) {
        for (int j=0; j<=2*n; j++) {
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    }
    Try(1);
    cout << fopt;
    return 0;
}