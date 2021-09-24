#include<bits/stdc++.h>
using namespace std;
 
int main()
{
//    int n, b;
//    cin >> n >> b;
//    int a[n];
//    for (int i=0; i<n; i++) {
//        cin >> a[i];
//    }
//    vector<pair<int, int>> max_left_right;
//    vector<int> max_divide;
//    for (int i=0; i<n; i++) {
//        auto max_left = *max_element(a, a+i);
//        auto max_right = *max_element(a+i+1, a+n);
//        if (max_left - a[i] < b || max_right - a[i] < b) continue;
//        else
//        {
//            max_left_right.push_back(make_pair(max_left, max_right));
//            int divide = max_left + max_right - a[i] - a[i];
//            max_divide.push_back(divide);
//        }
//    }
//    int max_res = 0;
//    int divide_size = max_divide.size();
//    for (int i=0; i<divide_size; i++) {
//        if (max_divide[i] > max_res) max_res = max_divide[i];
//    }
//    cout << max_res;
 
 
    int n, b;
    cin >> n >> b;
    vector<int> a(n+7);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    // Preprocessing
    int maxPrefix[n+7];
    int maxPostfix[n+7];
    maxPrefix[1] = a[1];
    for (int i=2; i<=n; i++) {
        maxPrefix[i] = max(maxPrefix[i-1] , a[i]);
    }
    maxPostfix[n] = a[n];
    for (int j=n-1; j>0; --j) {
        maxPostfix[j] = max(maxPostfix[j+1], a[j]);
    }
    int res = maxPrefix[1] - a[2] + maxPostfix[3] - a[2];
//    cout << res << endl;
    int mark = false;
    for (int i = 2; i < n; i++) {
        if (maxPrefix[i-1] - a[i] < b || maxPostfix[i+1] - a[i] < b) {
            continue;
        }
        else {
            mark = true;
            int temp = maxPrefix[i-1] - a[i] + maxPostfix[i+1] - a[i];
            res = max(res, temp);
        }
    }
    if (mark)
    cout << res;
    else cout << -1;
    return 0;
}
//10 5
//3 5 4 7 2 5 4 6 9 8

// v2

