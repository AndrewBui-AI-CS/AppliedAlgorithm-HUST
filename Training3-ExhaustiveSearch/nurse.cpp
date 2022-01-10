#include<bits/stdc++.h>
#define MAX 1007
using namespace std;
int n, k1, k2;
int mark[MAX];
int res = 0;
int count_day = 0;
bool check(int k, int i) {
    if (k==1) return true;
    else {
        if (i==0) {
            if (mark[k-1]==0) return false;
            else {
                if (count_day < k1) return false;
            }
        }
        else {
            if (mark[k-1] == 0) {
                if (n-k+1 < k1) return false;
            }
            else {
                if (count_day >= k2) return false;
            }
        }
        return true;
    }
}
void Try(int k) {
    for (int i=0; i<=1; i++) {
        if (check(k,i)) {
            mark[k] = i;
            int temp = count_day;
            if (i == 1) {
                if (mark[k-1] == 1) count_day++;
                else count_day = 1;
            }
            else {
                count_day = 0;
            }
            if (k==n) {
                res++;
            }
            else Try(k+1);
            mark[k] = 0;
            count_day = temp;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k1 >> k2;
    Try(1);
    cout << res;
    return 0;
}