#include<bits/stdc++.h>
#define MAX 35
using namespace std;
 
int n, b;
int a[MAX], c[MAX];
int fopt = 0;
void Try(int k, int weight, int value)
{
    if (k > n)
    {
        fopt = max(fopt, value);
        return;
    }
    if (weight + a[k] <= b)
    {
        Try(k+1, weight+a[k], value + c[k]);
    }
    Try(k+1, weight, value);
}
int main()
{
    cin >> n >> b;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i] >> c[i];
    }
    Try(1, 0, 0);
    cout << fopt;
    return 0;
}