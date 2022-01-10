#include <bits/stdc++.h>
#define MAX 10007
#define PI 3.141592654
using namespace std;
int n, f;
int r[MAX];
int check(double volume) {
    long long sum = 0;
    for (int i=1; i<=n; i++) {
        sum += (long long)(PI*r[i]*r[i]/volume);
    }
    return sum >= f+1;
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> f;
        for (int i=1; i<=n; i++) cin >> r[i];
        double l = 0, r = 1e8*PI;
        while(r-l > 1e-6) {
        double mid = (r+l)/2;
            if (check(mid)) {
                l = mid;
            }
            else r = mid;
        }
        printf("%.6f\n", l);
    }
    return 0;
}
 #include<bits/stdc++.h>
#define MAX 10007
#define PI 3.14159265
using namespace std;
int r[MAX];
int n, f;
 
double area(int radi) {
    return PI*radi*radi;
}
bool check(double volume) {
    int man = 0;
    for (int i=1; i<=n; i++) {
        double _area = area(r[i]);
        int temp = _area / volume;
        man += temp;
    }
    return man >= f+1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> f;
        for (int i=1; i<=n; i++) {
            cin >> r[i];
        }
        double l = 0, r = 1e9;
        while (r - l > .000001) {
            double mid = (r + l)/2;
            if (check(mid)) {
                l = mid;
            }
            else r = mid;
        }
        printf("%.6lf\n", l);
    }
 
    return 0;
}