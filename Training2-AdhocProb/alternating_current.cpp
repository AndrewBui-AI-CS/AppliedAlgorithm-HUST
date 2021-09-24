#include <iostream>
 
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    if (s[0] != s[len-1] || len % 2==1) {
        cout << "No";
        return 0;
    }
    else
    {
        int same = 1;
        for (int i=1; i<len-1; i++) {
            if (s[i] == s[i+1]) same++;
            else {
                if (same % 2) {
                    cout << "No";
                    return 0;
                }
                else same = 1;
            }
        }
    }
    cout << "Yes";
    return 0;
}

// Not completely solve