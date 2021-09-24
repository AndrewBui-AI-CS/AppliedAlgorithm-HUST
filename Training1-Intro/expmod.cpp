#include <iostream>
#define MAX 1000000007
using namespace std;
int mod(unsigned long long a, unsigned long long b, int module) {
    unsigned long long res = 1;
    a %= module;
    b %= module - 1;
    while (b > 0) {
        if ( b%2 > 0) {
            res = res * a % module;
        }
        a = a*a%module;
        b /= 2;
    }
    return (int) res;
}
int main()
{
    unsigned long long a, b, i;
    cin >> a >> b;
    int result = mod(a, b, MAX);
    cout << result;
    return 0;
}
//18446744073709551614