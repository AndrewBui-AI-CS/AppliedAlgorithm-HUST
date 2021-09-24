#include <bits/stdc++.h>
#define MAX 1007
using namespace std;
int n, k;
int x[MAX];
int m[MAX];
bool cmp(const pair<int, int> a, const pair<int, int> b) {
    return abs(b.first) < abs(a.first);
}
unsigned long long count_path(vector<pair<int, int>> temp) {
   int t_size = temp.size();
   long long res = 0;
   long long left = 0;
   for (int i = 0; i< t_size; i++) {
        long long x = abs(temp[i].first);
        long long m = temp[i].second - left;
        if (m > 0)
        {
            long long n = (m-1)/k + 1;
            left = n*k -m;
            res += 2*x*n;
        }
        else {
            left -= temp[i].second;
        }
 
   }
   return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<pair<int,int>> neg;
    vector<pair<int,int>> pos;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> m[i];
        if (x[i] < 0) neg.push_back(make_pair(x[i], m[i]));
        else pos.push_back(make_pair(x[i], m[i])) ;
    }
    sort(neg.begin(), neg.end(), cmp);
    sort(pos.begin(), pos.end(), cmp);
    unsigned long long neg_path = count_path(neg);
    unsigned long long pos_path = count_path(pos);
    cout << neg_path + pos_path;
    return 0;
}

// v2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//inline unsigned long long count_path(vector<pair<int, int> > pos_coord, int k) {
//    int size_pos = pos_coord.size();
//    int i = size_pos - 1;
//    int weight_redunt = 0;
//    unsigned long long count_path_i = 0;
//    while (i != -1) {
//        if (pos_coord[i].second > k) {
//            pos_coord[i].second -= k;
//            count_path_i += abs(pos_coord[i].first) << 1;
//        }
//        else {
//            count_path_i += abs(pos_coord[i].first) << 1;
//            weight_redunt = k - pos_coord[i].second;
//            pos_coord.pop_back();
//            --i;
//            while (i != -1 && !(weight_redunt < pos_coord[i].second)){
//                weight_redunt -= pos_coord[i].second;
//                --i;
//                pos_coord.pop_back();
//            }
//            if(i != -1) pos_coord[i].second -= weight_redunt;
//        }
//    }
//    return count_path_i;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    int n, k;
//    cin >> n >> k;
//    map<int, int> a;
//    for (int i=0; i<n; i++) {
//        int x, y;
//        cin >> x >> y;
//        a.insert(make_pair(x, y));
//    }
//    vector<pair<int, int>> pos_coord;
//    vector<pair<int, int>> neg_coord;
//    for (auto i : a) {
//        if (i.first > 0) pos_coord.push_back(i);
//        else neg_coord.insert(neg_coord.begin(), i);
//    }
//    int size_pos = pos_coord.size();
//    int size_neg = neg_coord.size();
//    unsigned long long path = count_path(pos_coord, k);
//    path += count_path(neg_coord, k);
//    cout << path;
//    return 0;
//}
//
 
// version 2: fast version:
const int N = 1002;
typedef pair<int, int> pii;
int n, nn, np, k, x, m;
long long ans = 0;
pii negCus[N], posCus[N];
 
long long calSegment(pii p[], int np, int k) {
    long long res = 0;
    int cur = 0;
    for (int i=1; i<=np; i++) {
        if (p[i].second > 0) {
            if (cur >= p[i].second) {
                cur -= p[i].second;
            }
            else {
                p[i].second -= cur;
                int times = (p[i].second - 1) / k +1;
                res += 2ll*abs(p[i].first) * times;
                cur = times*k -p[i].second;
            }
        }
    }
    return res;
}
 
int main() {
    cin >> n >> k;
    nn = np = 0;
    for (int i=1; i<=n; i++) {
        cin >> x >> m;
        // Chia thanh 2 phan
        if (x < 0) negCus[++nn] = make_pair(x, m);
        else posCus[++np] = make_pair(x, m);
    }
    // Sap xep
    sort(negCus + 1, negCus + nn + 1);
    sort(posCus + 1, posCus + np + 1, greater<pii>());
 
    // tinh thoi gian
    long long negSeg = calSegment(negCus, nn, k);
    long long posSeg = calSegment(posCus, np, k);
    ans = negSeg + posSeg;
    cout << ans;
}