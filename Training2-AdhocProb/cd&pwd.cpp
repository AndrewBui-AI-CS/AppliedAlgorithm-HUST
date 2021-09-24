#include <bits/stdc++.h>
 
using namespace std;
vector<string> tokenize(string s, string del = " ")
{
    int start = 0;
    int end_ = s.find(del);
    vector<string> res;
    while (end_ != -1) {
        res.push_back(s.substr(start, end_ - start));
        start = end_ + del.size();
        end_ = s.find(del, start);
    }
    res.push_back(s.substr(start, end_ - start));
    return res;
}
 
int main()
{
    int n;
    cin >> n;
    cin.ignore(1);
    bool is_absolute = false;
    deque <string> q;
    for (int i=0; i<n; i++) {
        string a;
        getline(cin, a);
        auto res = tokenize(a, " ");
        auto command = res[0];
        if (res.size() > 1) {
            auto path = res[1];
//            cout << path << endl;
            auto seperated_path = tokenize(path, "/");
            for (int i = 0; i<seperated_path.size(); i++) {
                if (seperated_path[i]=="") {
                    if (i == 0) q.clear();
                    else continue;
                }
                else if (seperated_path[i]=="..") {
                    q.pop_back();
                }
                else q.push_back(seperated_path[i]);
            }
        }
        else {
            deque<string> temp_q = q;
            while(!temp_q.empty()) {
                cout << "/" + temp_q.front();
                temp_q.pop_front();
            }
            cout << "/" << endl;
        }
    }
    return 0;
}