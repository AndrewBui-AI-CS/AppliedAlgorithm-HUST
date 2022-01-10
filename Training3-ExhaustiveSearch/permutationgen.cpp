#include <bits/stdc++.h>
#define MAX 10002
using namespace std;
int main()
{
    int n;
    vector<int> a(MAX, 0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    int i = n;
    while (i > 1)
    {
        if (a[i] < a[i-1]) i--;
        else break;
    }
    if (i==1) cout << -1;
//    cout << i << endl;
    else
    {
        if (i==n)
        {
            swap(a[i-1], a[i]);
        }
        else
        {
            i--;
//            cout << i << endl;
            for (int j = n; j > i; j--)
            {
 
                if (a[j] > a[i])
                {
                    swap(a[j], a[i]);
                    break;
                }
            }
//            cout << "ok" << endl;
            sort(a.begin() + i + 1, a.begin() + 1 + n);
        }
         for (int i=1; i<=n; i++)
            {
                cout << a[i] << " ";
            }
    }
    return 0;
}