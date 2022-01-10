#include<bits/stdc++.h>
#define MAX 2007
using namespace std;
vector<int> adj[MAX];
int color[MAX];
int check;
void DFS(int u) {
    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if (!color[v]) {
            color[v] = 3 - color[u];
            DFS(v);
        }
        if (color[v] == color[u]) check = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = n;
    while (n--) {
        check = 1;
        memset(color, 0, sizeof color);
        for (int i=0; i<MAX; i++) adj[i].clear();
        int bugs, conn;
        cin >> bugs >> conn;
        for (int i=0; i<conn; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=1; i<=bugs; i++) {
            if (!color[i]) {
                color[i] = 1;
                DFS(i);
            }
        }
        cout << "Scenario #" << cnt-n << ":" << endl;
        if (check) cout << "No suspicious bugs found!\n";
        else cout << "Suspicious bugs found!\n";
    }
    return 0;
}
