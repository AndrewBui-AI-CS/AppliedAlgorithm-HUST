#include <bits/stdc++.h>
#define MAX 1000000007
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long x, y, x0, y0, x1, y1, z0, z1;
    cin >> x >> y;
    x0 = x / 10;
    x1 = x % 10;
    y0 = y / 10;
    y1 = y % 10;
    z0 = (x0 + y0) + (x1 + y1) / 10;
    z1 = (x1 + y1) % 10;
    if (z0) cout << z0;
    cout << z1;
    return 0;
}