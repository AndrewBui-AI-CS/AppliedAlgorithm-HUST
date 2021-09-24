#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
int n, m;
vector<int> adj[MAX];
int mark[MAX];
void find_components(int cur_comp, int u) {
    if (mark[u] != -1) return;
    mark[u] = cur_comp;
    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        find_components(cur_comp, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(mark, -1, sizeof mark);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cur = 0;
    for (int i=1; i<=n; i++) {
        if (mark[i] == -1) {
            find_components(++cur, i);
        }
    }
    cout << cur;
    return 0;
}