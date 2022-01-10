#include <bits/stdc++.h>
#define MAX 2000007
using namespace std;
int n, max_stop;
int s[MAX];
int t[MAX];
int start[MAX];
int stop[MAX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s[i] >> t[i];
        max_stop = max(max_stop, t[i]);
        start[s[i]] = t[i] - s[i];
        stop[t[i]] = t[i] - s[i];
    }
    for (int i=1; i<=max_stop; i++) {
        start[max_stop - i] = max(start[max_stop - i ], start[max_stop - i + 1]);
        stop[i] = max(stop[i-1], stop[i]);
    }
    int res = 0;
    for (int i=1; i<=max_stop; i++) {
        res = max(res, stop[i]+start[i+1]);
    }
    cout << res;
    return 0;
}