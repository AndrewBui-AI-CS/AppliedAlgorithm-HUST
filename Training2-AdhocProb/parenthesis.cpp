#include <iostream>
#include <stack>
#include <map>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    cin.ignore(1);
    string exp;
    stack<char> a;
    map<char, char> b;
    b.insert(make_pair('[', ']'));
    b.insert(make_pair('(', ')'));
    b.insert(make_pair('{', '}'));
    for (int i=0; i<n; i++) {
        int mark = 0;
        getline(cin, exp);
        int length_exp = exp.length();
        for (int i=0; i<length_exp; i++) {
            if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') a.push(exp[i]);
            else {
                if (a.empty()) {
                    cout << 0 << endl;
                    mark = 1;
                    break;
                }
                else {
                    char temp = a.top();
                    if (b[temp] != exp[i]) {
                        mark = 1;
                        cout << 0 << endl;
                        break;
                    }
                    else a.pop();
                }
            }
        }
        if (!mark) cout << 1 << endl;
    }
    return 0;
}