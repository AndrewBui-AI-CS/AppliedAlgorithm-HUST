#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
int main() {
    int n, k;
    int a[MAX], mark[MAX];
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mark[a[i]]++;
    }
    int res = 0;
    sort(a, a+n);
    for (int i=0; i<n-2; i++) {
        mark[a[i]]--;
        for (int j=i+1; j<n-1; j++) {
            mark[a[j]]--;
            int key = k - a[i] - a[j];
            if (key > 0) {
                res += mark[key];
            }
        }
        for (int j=i+1; j<n-1; j++) {
            mark[a[j]]++;
        }
    }
    cout << res;
    return 0;
}