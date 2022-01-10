#include <bits/stdc++.h>
#define MAX 1007
using namespace std;
int n, l;
int a[MAX];
double d[MAX];
int main()
{
    cin >> n >> l;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
//    for (int i=1; i<=n; i++) cout << a[i] << " ";
    for (int i=2; i<=n; i++) {
        double dd = (double)(a[i] - a[i-1]) / 2;
        d[i] = dd;
    }
    d[n+1] = l-a[n];
    d[1] = a[1];
    double m = 0;
    for (int i=1; i<=n+1; i++) m = max(m, d[i]);
    printf("%.10lf", m);
    return 0;
}