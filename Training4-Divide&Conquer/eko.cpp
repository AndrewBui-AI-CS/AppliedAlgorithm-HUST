#include<bits/stdc++.h>
#define MAX 1000007
using namespace std;
int a[MAX];
int n, m;
bool check(int height) {
    long long sum = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] - height > 0) sum += a[i] - height;
    }
    return sum >= m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        if (a[i] > r) r = a[i];
    }
//    cout << r << endl;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        }
        else r = mid;
    }
    cout << l;
    return 0;
}
