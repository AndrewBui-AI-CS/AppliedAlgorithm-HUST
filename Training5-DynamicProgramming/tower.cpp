#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int n;
int height[MAX];
int u, v, t;
typedef struct block B;
struct block {
    int x, y, z;
};
B a[MAX];
void input() {
    cin >> n;
    if (n==0) exit(0);
    for (int i=1; i<=n; i++) {
        cin >> u >> v >> t;
        a[3*i-2].x = u;
        a[3*i-2].y = v;
        a[3*i-2].z = t;
        a[3*i-1].x = u;
        a[3*i-1].y = t;
        a[3*i-1].z = v;
        a[3*i].x = v;
        a[3*i].y = t;
        a[3*i].z = u;
    }
}
int dp(int i) {
    if (height[i] > 0) return height[i];
    height[i]  = a[i].z;
    for (int j=1; j<=3*n; j++) {
        if (a[i].x < a[j].x && a[i].y < a[j].y || a[i].x < a[j].y && a[i].y < a[j].x) {
            height[i] = max(height[i], dp(j) + a[i].z);
        }
    }
    return height[i];
}
int main()
{
    int dem = 0;
    while(1) {
       int res = 0;
        memset(height, 0, sizeof height);
        input();
        for (int i=1; i<=3*n; i++) {
            res = max(res, dp(i));
        }
        cout << "Case " << ++dem << ": maximum height = " << res << endl;
    }
    return 0;
}