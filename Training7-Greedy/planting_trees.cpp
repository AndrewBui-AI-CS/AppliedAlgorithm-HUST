#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
int n;
int d[MAX];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int res = 0;
    int max_day = 0;
    for (int i=1; i<=n; i++) {
        cin >> d[i];
    }
    sort(d+1, d+1+n,cmp);
    for (int i=1; i<=n; i++) {
        max_day = max(max_day, d[i] + i);
    }
    cout << max_day + 1;
    return 0;
}