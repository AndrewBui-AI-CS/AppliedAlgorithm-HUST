Copy
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, q;
    cin >> n;
    vector<int> path(n+7);
    for (int i=1; i<=n; i++) {
        cin >> path[i];
    }
    // precomputing for weight and roughness_histogram
    vector<int> roughness_histogram(n+7);
    int W = 1;
    roughness_histogram[1] = 1;
    for (int i=2; i<=n; i++) {
        roughness_histogram[i] = !(path[i] == path[i-1]);
        W += roughness_histogram[i];
    }
//    for (int i=1; i<=n; i++) {
//        cout << roughness_histogram[i] << " ";
//    }
//    cout << endl << W;
 
    // queries input and processing
    cin >> q;
    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        // First, need to subtract own report value in histogram
        W = W - roughness_histogram[x];
        if (x != n) W -= roughness_histogram[x+1];
        // Update report
        path[x] = y;
        if (x != 1) roughness_histogram[x] = !(path[x] == path[x-1]);
        if (x != n) roughness_histogram[x+1] = !(path[x+1] == path[x]);
        // Adding weighs for new changing report
        W = W + roughness_histogram[x];
        if (x != n) W = W + roughness_histogram[x+1];
        cout << W << endl;
    }
 
    return 0;
}