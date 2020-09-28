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

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    bool isPossible = false;
    for(int i = 0; i < n - 1; ++i){
        if(a[i] <= a[i + 1]){
            isPossible = true;
            break;
        }
    }

    if(isPossible){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int t;
    cin >> t;

    for(; t > 0; --t){
        solve(cin, cout);
    }
    
    return 0;
}