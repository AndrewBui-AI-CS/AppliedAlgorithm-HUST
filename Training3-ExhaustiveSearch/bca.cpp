#include<bits/stdc++.h>
#define MAX 37
using namespace std;
int m, n;
int t;
int pre[MAX][MAX];
int conflict[MAX][MAX];
vector<int> teach[MAX];
int fopt = INT_MAX;
bool checkEmpty() {
    for (int i=1; i<=m; i++) if (teach[i].size() == 0) return 1;
    return 0;
}
bool checkNotConflict(int m, int k) {
    int teach_size = teach[m].size();
    for (int i=0; i<teach_size; i++) {
        if (conflict[teach[m][i]][k]) return 0;
    }
    return 1;
}
void Try(int k) {
    if (k > n) {
//        if (!checkEmpty()) {
            int max_load = 0;
        for (int i=1; i<=m; i++) {
            int teach_size = teach[i].size();
            max_load = max(max_load, teach_size);
        }
        fopt = min(fopt, max_load);
        }
//    }
 
 
    for (int i=1; i<=m; i++) {
        if (checkNotConflict(i, k) && pre[i][k]) {
            teach[i].push_back(k);
            if (teach[i].size() < fopt)Try(k+1);
            teach[i].pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i=1; i<=m; i++) {
        cin >> t;
        int temp;
        for (int j=0; j<t; j++) {
            cin >> temp;
            pre[i][temp] = 1;
        }
    }
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        conflict[x][y] = 1;
        conflict[y][x] = 1;
    }
    Try(1);
    cout << fopt;
    return 0;
}