#include <iostream>
#include<math.h>
#define MAX 1000000007
using namespace std;
 
int main()
{
    unsigned long long a, b, a1, b1;
    cin >> a >> b;
    a1 = a % MAX;
    b1 = b % MAX;
    unsigned long long result = (a1 + b1) % MAX;
    cout << result;
    return 0;
}
//18446744073709551614

// v2
#include <iostream>
#include<string>
using namespace std;
#include<math.h>
#define MAX 1000000007
int mod(string num, int a)
{
    // Initialize result
    unsigned long long res = 0;
 
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
    {
        res = (res*10 + num[i] - '0');
//            cout << res << endl;
        res = res % a;
//         cout << res << endl;
    }
    return res;
}
int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    string a_str = to_string(a);
    string b_str = to_string(b);
    string result = "";
    int len_a = a_str.length();
    int len_b = b_str.length();
    if (len_a > len_b)
    {
        string temp = a_str;
        a_str = b_str;
        b_str = temp;
    }
    int min_len = len_a;
    int carry = 0;
    for (int i= 0; i < min_len; ++i)
    {
        int sum = (a_str[len_a - i -1] - '0') + (b_str[len_b - i -1] - '0') + carry;
        carry = sum / 10;
        sum = sum%10;
        result = to_string(sum) + result;
    }
    if (len_a < len_b)
    {
        int max_len = len_b -1 - len_a;
        for (int i = max_len; i>=0; i--)
        {
            int sum = b_str[i] - '0' + carry;
            carry = sum/10;
            sum %= 10;
            result = to_string(sum) + result;
        }
    }
    if (carry > 0)
    {
        result = to_string(carry) + result;
    }
    int final_res = mod(result, MAX);
    cout << final_res;
    return 0;
}
//18446744073709551614
//36893488147419103228