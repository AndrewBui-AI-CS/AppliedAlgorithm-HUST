
#include <iostream>
#include<string>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    cin.ignore(1);
    string temp;
    for (int i=0; i<n; i++) {
        string result = "";
        getline(cin, temp);
        int length_temp = temp.length();
        if (length_temp > 10) {
            result = temp[0] + to_string(length_temp-2) + temp[length_temp-1];
        }
        else result = temp;
        cout << result << endl;
    }
    return 0;
 
}
//18446744073709551614