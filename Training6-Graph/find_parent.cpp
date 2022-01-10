#include <bits/stdc++.h>
#define MAX 100007
using namespace std;
int n;
vector<int> adj[MAX];
int parent[MAX];
int mark[MAX];
void dfs(int start) {
    stack<int> st;
    st.push(start);
    mark[start] = 1;
    while(!st.empty()) {
        int v = st.top();
        st.pop();
        for (int i=0; i<adj[v].size(); i++) {
            int u = adj[v][i];
            if (!mark[u]) {
                mark[u] = 1;
                parent[u] = v;
                dfs(u);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i=2; i<=n; i++) cout << parent[i] << " ";
    return 0;
}