#include <bits/stdc++.h>
#define MAX 1000007
using namespace std;
int n,m;
//pair<int, int> edges;
vector<pair<int, int> > Adj[MAX];
vector<int> weight(MAX, 1e8);
int s, t;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
void djk(int start) {
    weight[start] = 0;
    pq.push(make_pair(start, weight[start]));
    while (!pq.empty()) {
        int w = pq.top().second;
        int v = pq.top().first;
        pq.pop();
        for (int i=0; i<Adj[v].size(); i++) {
            int x = Adj[v][i].first;
            int y = Adj[v][i].second;
            if (y + weight[v] < weight[x]) {
                weight[x] = y + weight[v];
                pq.push(make_pair(x, weight[x]));
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Adj[u].push_back(make_pair(v, w));
    }
    cin >> s >> t;
    djk(s);
//    for (int i=1; i<=n; i++) cout << weight[i] << " ";
    cout << weight[t];
    return 0;
}