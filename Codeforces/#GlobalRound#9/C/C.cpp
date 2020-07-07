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
    
    const int MAX_N = 3e5 + 3;
    vector<int> a(MAX_N);

    int t;
    cin >> t;

    for(; t > 0; --t){
        int n;
        cin >> n;

        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        if(a[0] < a[n - 1]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}