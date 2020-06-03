#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    const int MAX_N = 55;
    vector<int> a(MAX_N);

    int t;
    int n;
    
    cin >> t;

    for(; t > 0; --t){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        sort(a.begin(), a.begin() + n);

        int answer = a[1] - a[0];
        for(int i = 1; i < n; ++i){
            answer = min(a[i] - a[i - 1], answer);
        }

        cout << answer << "\n";
    }

    return 0;
}