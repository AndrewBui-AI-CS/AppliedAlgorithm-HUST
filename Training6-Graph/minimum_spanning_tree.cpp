#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
typedef struct edge edges;
int parent[MAX];
struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
void Union_Find (int n)
{
    for (int i =1; i<=n; i++)
    {
        parent[i] = i;
    }
}
int Find(int x)
{
    if (parent[x] == x) return x;
    else
    {
        parent[x] = Find(parent[x]);
        return parent[x];
    }
}
void Unite(int x, int y)
{
    parent[Find(x)] = Find(y);
}
//struct Union_Find {
//    vector<int> parent;
//    Union_Find (int n) {
//        parent = vector<int> (n);
//        for (int i =1; i<=n; i++) {
//            parent[i] = i;
//        }
//    }
//    int Find(int x) {
//        if (parent[x] == x) return x;
//        else {
//             parent[x] = Find(parent[x]);
//             return parent[x];
//        }
//    }
////    hop x vao tap chua y
//    void Unite(int x, int y) {
//        parent[Find(x)] = Find(y);
//    }
//};
 
bool cmp (const edges &a, const edges &b)
{
    return a.w < b.w;
}
vector<edges> MST(int n, vector<edges> e)
{
    Union_Find(n);
    sort(e.begin(), e.end(), cmp);
    vector<edges> res;
    for (int i=0; i<e.size(); i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        if (Find(u)!= Find(v))
        {
            Unite(u, v);
            res.push_back(e[i]);
        }
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<edges> e;
    while(m--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e.push_back(edge(x, y, w));
    }
    vector<edges> result = MST(n, e);
    long long sum = 0;
    for (int i=0; i<result.size(); i++)
    {
        sum+= result[i].w;
    }
    cout << sum;
}