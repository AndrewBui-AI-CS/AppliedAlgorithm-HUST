#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<pair<int, int>, int> level;
queue< pair<int, int> > q;
void Pour (int a, int b, pair<int, int> status) {
    if (level[{a, b}] == 0) {
        q.push({a, b});
        level[{a, b}] = level[{status.first, status.second}] + 1;
    }
}
void BFS(int a, int b, int target) {
    bool isSolvable = false;
    level.clear();
    q = queue< pair<int, int> >();
    q.push({0, 0});
    level[{0, 0}] = 1;
 
    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
 
        if (u.first == target || u.second == target) {
            isSolvable = true;
            cout << level[{u.first, u.second}] - 1;
            break;
        }
 
        Pour(a, u.second, u);
        Pour(u.first, b, u);
        Pour(0, u.second, u);
        Pour(u.first, 0, u);
 
        for (int amt = 0; amt <= max(a, b); amt ++) {
            //
            int c = u.first + amt;
            int d = u.second - amt;
            if ( (c==a && d >=0) || (d==0 && c<=a) ) Pour(c, d, u);
            //
             c = u.first - amt;
             d = u.second + amt;
            if ( (c==0 && d <=b) || (c>=0 && d==b) ) Pour(c, d, u);
        }
 
    }
    if (!isSolvable) {
        cout << -1 << endl;
    }
}
int main()
{
    int jug1, jug2, target;
    cin >> jug1 >> jug2 >> target;
    BFS(jug1, jug2, target);
    return 0;
}

// v2

#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> level;
queue<pair<int, int> > q;
void Pour(int left, int right, int status) {
    auto a = make_pair(left, right);
    if (level[a] == 0) {
        q.push(a);
        level[a] = status;
    }
}
int a, b, c;
int main() {
    cin >> a >> b >> c;
    bool isSolved = false;
    q.push({0, 0});
    level[{0, 0}] = 1;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (t.first == c || t.second == c) {
            cout << level[t] - 1;
            isSolved = true;
            break;
        }
 
        Pour(a, t.second, level[t]+ 1);
        Pour(t.first, b, level[t] + 1);
        Pour(0, t.second,level[t] + 1);
        Pour(t.first, 0, level[t] + 1);
 
        for (int amt = 1; amt <= max(a, b); amt++) {
            int c = t.first + amt;
            int d = t.second - amt;
            if (c == a && d >=0 || d==0 && c<=a) Pour(c, d, level[t] + 1);
            c = t.first - amt;
            d = t.second + amt;
            if (c >= 0 && d == b || c == 0 && d <=b) Pour(c, d, level[t] + 1);
        }
    }
    if (isSolved == 0)cout << -1;
    return 0;
}