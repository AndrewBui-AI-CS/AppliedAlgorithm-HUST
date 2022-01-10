#include <bits/stdc++.h>
#define MAX 10
using namespace std;
int n, q;
int visited[MAX];
int character_arr[MAX];
int cal_op(int character_arr[]) {
    int ICT = character_arr[1]*100 + character_arr[2]*10 + character_arr[3];
    int K62 = character_arr[7]*100 + 62;
    int HUST = character_arr[4]*1000+character_arr[5]*100+character_arr[6]*10+character_arr[3];
    return ICT - K62 + HUST;
}
void Try(int k) {
    for (int i=1; i<=9; i++) {
        if (!visited[i]) {
            character_arr[k] = i;
            visited[i] = 1;
            if(k==7) {
//            for (int i=1; i<=7; i++) cout << character_arr[i] << " ";
//            cout << endl;
//            cout << cal_op(character_arr) << endl;
                if(cal_op(character_arr) == n) q++;
//                return;
            }
            else Try(k+1);
            visited[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    memset(visited, 0, sizeof visited);
    Try(1);
    cout << q;
    return 0;
}