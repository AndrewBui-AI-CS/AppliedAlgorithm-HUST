#60%
#include <bits/stdc++.h>
#define MAX 50005
 
using namespace std;
int n, x, y;
int index1, index2;
vector<pair<int, int> > a;
double euclid_dist(pair<int, int> x, pair<int, int> y) {
    double res = pow(x.first-y.first, 2) + pow(x.second-y.second, 2);
    res = sqrt(res);
    return res;
}
double round_up(double value, int decimal_places) {
    const double multiplier = pow(10.0, decimal_places);
    return ceil(value * multiplier) / multiplier;
}
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        a.push_back(make_pair(x,y));
    }
    double res = 100000000.0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            double temp = euclid_dist(a[i], a[j]);
//            cout << temp << endl;
            if (temp < res) {
                res = temp;
                index1 = i;
                index2 = j;
            }
        }
    }
//    for (int i=0; i<n; i++) {
//        cout << a[i].first << "=>" << a[i].second;
//    }
    cout << index1 << " " << index2 << " ";
    printf("%.6lf", res);
    return 0;
}