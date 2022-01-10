#include<bits/stdc++.h>
#define MAX 17
using namespace std;
int n, K, q;
int d[MAX];
int res = 0;
int truck[MAX];
int man[MAX];
int cal(int a)
{
    if (a == 0) return 0;
    if (a == 1) return 1;
    else return a*cal(a-1);
}
void Try(int k)
{
    if (k > n)
    {
        int temp = 1;
        for (int j=1; j<=K; j++)
        {
            temp *= cal(man[j]);
        }
        res += temp;
    }
    else
    for (int i=1; i<=K; i++)
    {
        if (truck[i] + d[k] <= q)
        {
            truck[i] += d[k];
            man[i]++;
            Try(k+1);
            truck[i] -= d[k];
            man[i]--;
        }
    }
}
int main()
{
    cin >> n >> K >> q;
    for (int i=1; i<=n; i++) cin >> d[i];
    Try(1);
    cout << (res/cal(K)) % 1000000007;
    return 0;
}
