#include<bits/stdc++.h>
#define MAX 25
using namespace std;
int n, k;
int c[MAX][MAX];
int cmin = 1e9;
int f = 0, fopt = 1e9;
int mark[MAX];
int v[MAX];
int cur = 0;
bool check(int i) {
    if (i<=n) {
        if (mark[i] == 0 && cur < k) return true;
        else return false;
    }
    else {
        if (mark[i-n] != 0 && mark[i] == 0) return true;
        else return false;
    }
}
void Try(int t) {
    for (int i=1; i<=2*n; i++) {
        if (check(i)) {
            f += c[v[t-1]][i];
            mark[i] = 1;
            v[t] = i;
            if (i <=n) cur++;
            else cur--;
            if (t == 2*n) {
                if (fopt > f + c[v[t]][0]) fopt = f + c[v[t]][0];
            }
            else {
                int bound = (2*n+1-t)*cmin + f;
                if (bound < fopt) Try(t+1);
            }
            f -= c[v[t-1]][i];
            mark[i] = 0;
            if (i<=n) cur--;
            else cur++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<=2*n; i++) {
        for (int j=0; j<=2*n; j++) {
            cin >> c[i][j];
            if (c[i][j])cmin = min(c[i][j], cmin);
        }
    }
    f = 0;
    Try(1);
    cout << fopt;
    return 0;
}