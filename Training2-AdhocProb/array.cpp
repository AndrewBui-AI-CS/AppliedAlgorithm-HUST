#include <bits/stdc++.h>
#define MAX 107
using namespace std;
int n;
vector<int> neg;
vector<int> pos;
vector<int> zero;
int a[MAX];
int main()
{
    cin >> n;
    int count_neg = 0;
    int count_pos = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] == 0) zero.push_back(a[i]);
        else if (a[i] < 0) {
            neg.push_back(a[i]);
            count_neg++;
        }
        else {
            pos.push_back(a[i]);
            count_pos++;
        }
    }
    if (count_pos == 0) {
        if (count_neg % 2 ==1) {
            int temp = neg[0];
            for (int i=1; i<neg.size(); i++) {
                pos.push_back(neg[i]);
            }
            neg.clear();
            neg.push_back(temp);
        }
        else {
            int temp = neg[0];
            int temp2 = neg[1];
            for (int i=2; i<neg.size(); i++) {
                pos.push_back(neg[i]);
            }
            neg.clear();
            neg.push_back(temp);
            zero.push_back(temp2);
        }
    }
    else {
        if (count_neg % 2 == 0) {
            int temp = neg[neg.size()-1];
            neg.pop_back();
            zero.push_back(temp);
        }
    }
    cout << neg.size() << " ";
    for (int i=0; i<neg.size(); i++) cout << neg[i] << " ";
    cout << endl;
    cout << pos.size() << " ";
    for (int i=0; i<pos.size(); i++) cout << pos[i] << " ";
    cout << endl;
    cout << zero.size() << " ";
    for (int i=0; i<zero.size(); i++) cout << zero[i] << " ";
    return 0;
}