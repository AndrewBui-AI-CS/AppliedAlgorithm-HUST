#include<bits/stdc++.h>
#define MAX 27
using namespace std;
int n, m;
int c[MAX];
int a[MAX][MAX];
int fopt = INT_MAX;
int per[MAX];
int load_per[MAX];
 
int check_pre(int per[], int k) {
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=k, j!=i; j++) {
            if (a[i][j] == 1 && per[j] <= per[i]) return 0;
        }
    }
    return 1;
}
int max_load(int load_per[]) {
    int res = 0;
    for (int i=1; i<=m; i++) {
        res = max(res, load_per[i]);
    }
    return res;
}
void Try(int k) {
    if (k == n+1) {
        if (check_pre(per, n))
            fopt = min(fopt, max_load(load_per));
    }
    for (int i=1; i<=m; i++) {
        load_per[i] += c[k];
        per[k] = i;
        if (check_pre(per, k) &&  max_load(load_per) < fopt) {
            Try(k+1);
        }
        load_per[i] -= c[k];
    }
}
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << fopt;
    return 0;
}