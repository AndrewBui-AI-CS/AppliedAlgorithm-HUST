#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n, m;
    vector<int> a, b;
    cin >> n;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> x;
        b.push_back(x);
    }
 
    if (m > n) cout << 0;
    else {
    bool mark = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (b[i] == a[j]) mark = 1;
            }
            if (mark == 0) {
                cout << 0;
                return 0;
            }
            else {
                mark = 0;
            }
        }
        cout << 1;
    }
    return 0;
}