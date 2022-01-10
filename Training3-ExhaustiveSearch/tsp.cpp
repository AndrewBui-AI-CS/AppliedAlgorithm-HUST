#include<bits/stdc++.h>
#define MAX 27
using namespace std;
int c[MAX][MAX];
int v[MAX];
int cmin = 1e9;
int fopt = 1e9, f = 0;
int mark[MAX];
int m, n;
void Try(int k) {
    for (int i=2; i<=n; i++) {
        if (!mark[i]) {
            mark[i] = 1;
            v[k] = i;
            f += c[v[k-1]][i];
            if (k==n) {
                if (fopt > f + c[i][1]) fopt = f + c[i][1];
            }
            else {
                int g = f + cmin*(n-k+1);
                if (g < fopt) Try(k+1);
            }
            mark[i] = 0;
            f -= c[v[k-1]][i];
        }
    }
}
int main() {
    cin >> n >> m;
    memset(mark, 0, sizeof mark);
    memset(v, 0, sizeof v);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            c[i][j] = 1e8;
        }
    }
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        c[x][y] = z;
        cmin = min(cmin, z);
    }
    v[1] = 1;
    mark[1] = 1;
    Try(2);
    cout << fopt;
    return 0;
}