#include <iostream>
#include <map>
using namespace std;
 
int main()
{
    map<char, int> button = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 1}, {'e',2}, {'f',3 }, {'g', 1}, {'h', 2}, {'i',3 },
        {'j', 1}, {'k', 2}, {'l', 3}, {'m', 1}, {'n', 2}, {'o', 3}, {'p', 1}, {'q', 2}, {'r', 3}, {'s',4},
        {'t', 1},{'u', 2},{'v', 3},{'w', 1},{'x', 2},{'y', 3},{'z', 4}
    };
    int T;
    cin >> T;
    cin.ignore(1);
    string temp;
    for (int i=0; i<T; i++) {
        getline(cin, temp);
        int t_len = temp.length();
        int count_button = 0;
        for(int j=0; j<t_len; j++) {
            if (temp[j] != ' ') {
//                cout << button[temp[j]] << endl;
                count_button += button[temp[j]];
            }
            else count_button += 1;
        }
        cout << "Case #" << i + 1 << ": " << count_button << endl;
    }
    return 0;
}