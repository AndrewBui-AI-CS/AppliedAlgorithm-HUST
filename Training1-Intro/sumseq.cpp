#include <iostream>
#define MAX 1000000007;
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    unsigned long long result = 0;
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        result += x;
    }
    result = result % MAX;
    cout << result;
    return 0;
}