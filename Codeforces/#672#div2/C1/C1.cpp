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
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    a[0] = INT_MIN;
    a[n + 1] = INT_MIN;

    long long answer = 0;
    bool searchMax = true;
    int prevMin = 0;
    for(int i = 1; i <= n; ++i){
        if(searchMax){
            if(a[i - 1] < a[i] && a[i] > a[i + 1]){
                answer += a[i] - prevMin;
                searchMax = false;
            }
        }else{
            if(a[i - 1] > a[i] && a[i] < a[i + 1]){
                prevMin = a[i];
                searchMax = true;
            }
        }
    }

    cout << answer << "\n";
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