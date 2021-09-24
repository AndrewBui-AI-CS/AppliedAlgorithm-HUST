#include <bits/stdc++.h>
#define MAX 1000007
using namespace std;
int n;
int a[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n-1; i++) {
        a[i+1] = max(a[i] + a[i+1], a[i+1]);
    }
    auto res = a[0];
    for (int i=1; i<n; i++) res = max(res, a[i]);
    cout << res;
 
    return 0;
}
// V2
#include <iostream>
#define MAX 1000006
using namespace std;
long long A[MAX];
int n;
long long MAXLM(int left, int mid) {
    long long max_lm = A[mid];
    long long sum = 0;
    for (int i = mid; i>=left; i--) {
        sum+=A[i];
        max_lm = max(max_lm, sum);
    }
    return max_lm;
}
long long MAXRM(int mid, int right) {
    long long max_rm = A[mid];
    long long sum = 0;
    for (int i=mid; i<=right; i++) {
        sum+=A[i];
        max_rm = max(max_rm, sum);
    }
    return max_rm;
}
long long subSeqMax(int left, int right) {
    if (left == right) return A[left];
    long long mid = (left+right)/2;
    long long maxleft = subSeqMax(left, mid);
    long long maxright = subSeqMax(mid+1, right);
    long long maxleftmid = MAXLM(left, mid);
    long long maxrightmid = MAXRM(mid+1, right);
    long long maxmid = maxleftmid+maxrightmid;
    return max(max(maxleft, maxright), maxmid);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> A[i];
    long long result = subSeqMax(1, n);
    cout << result;
    return 0;
}

// V3
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;
//6
//-2 11 -4 13 -5 2
int mem[MAX];
bool mark[MAX];
int arr[MAX];
int Try(int k) {
     if (k==0) return arr[k];
     if (mark[k]) {
        return mem[k];
     }
     int result = max(arr[k], arr[k] + Try(k-1));
     mem[k] = result;
     mark[k] = true;
     return result;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    Try(n);
    int max_value = mem[0];
    for (int i=1; i<n; i++) {
        max_value = max(mem[i], max_value);
//        cout << mem[i] << endl;
    }
    cout << max_value;
    return 0;
}