#include <bits/stdc++.h>
#define MAX 17
using namespace std;
int n, m;
vector<int> adj[MAX];
int deg[MAX];
int mark[MAX];
int main()
{
    cin >> n >> m;
    priority_queue< pair<int, int> > q;
    set<int> s;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x] += 1;
        deg[y] += 1;
        s.insert(x);
        s.insert(y);
    }
    for (int i=1; i<=n; i++) {
        q.push(make_pair(deg[i], i));
        mark[i] = 1;
    }
    while (!q.empty()) {
        auto temp = q.top();
        q.pop();
        int v = temp.second;
        if (!mark[v]) continue;
        set<int> temp_set;
        auto origin_set = s;
        origin_set.erase(v);
        for (int i=0; i<adj[v].size(); i++) {
          origin_set.erase(adj[v][i]);
        }
        for (auto i:origin_set) {
            s.erase(i);
            mark[i] = 0;
        }
    }
    cout << s.size();
    return 0;
}