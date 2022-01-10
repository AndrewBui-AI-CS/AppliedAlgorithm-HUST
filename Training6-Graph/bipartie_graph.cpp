#include <bits/stdc++.h>
#define MAX 100007
using namespace std;
int n, m;
vector<int> adj[MAX];
int mark[MAX];
bool check = true;
void dfs(int u) {
    for (int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if (!mark[v]) {
            mark[v] = 3 - mark[u];
            dfs(v);
        }
        if (mark[u] == mark[v]) {
            check = 0;
//            exit(0);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        if (!mark[i]) {
            mark[i] = 1;
            dfs(i);
        }
    }
    if(check) cout << 1;
    else cout << 0;
    return 0;
}
