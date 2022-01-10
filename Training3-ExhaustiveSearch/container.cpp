#include <bits/stdc++.h>
#define MAX 37
using namespace std;
int height, width;
int n;
 
struct target_rec {
    int x1, x2, y1, y2;
    target_rec(int a1, int a2, int a3, int a4) {
        x1 = a1;
        x2 = a2;
        y1 = a3;
        y2 = a4;
    }
};
struct given_rec
{
    int h, w;
} a[MAX];
 
vector<target_rec> b;
int not_conflict(target_rec new_rec) {
    int bsize = b.size();
    for (int i=0; i<bsize; i++) {
        target_rec temp = b[i];
        if (new_rec.x1 >= temp.x2 || new_rec.x2 <= temp.x1) continue;
        if (new_rec.y1 >= temp.y2 || new_rec.y2 <= temp.y1) continue;
        return 0;
    }
    return 1;
}
 
void Try(int k) {
    if (k > n) {
        cout << 1;
        exit(0);
    }
    for (int i=0; i<= height-a[k].h; i++) {
        for (int j=0; j<=width - a[k].w; j++) {
            target_rec temp = target_rec(i, i+a[k].h, j, j+a[k].w);
            if (not_conflict(temp)) {
                b.push_back(temp);
                Try(k+1);
                b.pop_back();
            }
        }
    }
}
int main()
{
    cin >> height >> width;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i].h >> a[i].w;
    }
    Try(1);
    cout << 0;
    return 0;
}
