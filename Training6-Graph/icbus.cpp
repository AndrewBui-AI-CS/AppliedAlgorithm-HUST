#include<bits/stdc++.h>
#define MAX 10007
using namespace std;
int n, k;
int c[MAX], d[MAX];
vector<int> adj[MAX];
int dist[MAX];
vector< pair<int, int> > new_adj[MAX];
void bfs(int u) {
    for (int i=1; i<=n; i++) dist[i] = -1;
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        for (int i=0; i<adj[temp].size(); i++) {
            int v = adj[temp][i];
            if (dist[v] == -1) {
                q.push(v);
                dist[v] = dist[temp] + 1;
            }
        }
    }
}
void djk(int start) {
       for (int i=1; i<=n; i++) dist[i] = 1e8;
    dist[start] = 0;
 
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(dist[start], start));
    while(!pq.empty()) {
        auto u = pq.top().second;
        pq.pop();
        for (int i=0; i<new_adj[u].size(); i++) {
            int v = new_adj[u][i].first;
            int w = new_adj[u][i].second;
            if (w + dist[u] < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> c[i] >> d[i];
    }
    for (int i=0; i<k; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        bfs(i);
        for (int j=1; j<=n; j++) {
            if (dist[j] <= d[i] && i != j) {
                new_adj[i].push_back(make_pair(j, c[i]));
            }
        }
    }
    djk(1);
    cout << dist[n];
    return 0;
}
