#include<bits/stdc++.h>
#define MAX 1000007
using namespace std;
int f, s, g, u, d;
struct pos
{
    int floor;
    int step;
};
int mark[MAX];
typedef struct pos P;
queue<P> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    P start;
    start.floor = s;
    start.step = 0;
    q.push(start);
    while (!q.empty())
    {
        P temp = q.front();
        q.pop();
        if (temp.floor == g)
        {
            cout << temp.step;
            return 0;
        }
        if (!mark[temp.floor])
        {
            mark[temp.floor] = 1;
            if (u + temp.floor <= f)
            {
                P up;
                up.floor = temp.floor + u;
                up.step = temp.step + 1;
                q.push(up);
            }
            if (temp.floor - d >= 1)
            {
                P down;
                down.floor = temp.floor - d;
                down.step = temp.step + 1;
                q.push(down);
            }
        }
    }
    cout << "use the stairs";
    return 0;
}