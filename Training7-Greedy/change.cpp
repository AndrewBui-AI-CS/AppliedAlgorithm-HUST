#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int currency[] = {1, 5, 10, 50, 100, 500};
    int pos = 5;
    int money = 1000 - n;
    int cnt = 0;
    while (money > 0) {
        if (money >= currency[pos]) {
            cnt++;
            money -= currency[pos];
        }
        else {
            pos--;
        }
    }
    cout << cnt;
    return 0;
}