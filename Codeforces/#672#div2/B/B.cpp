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

int getMSB(const int& NUM, const int& MAX_BIT){
    int msb = -1;
    for(int bit = MAX_BIT; bit >= 0; --bit){
        if((NUM >> bit) & 1){
            msb = bit;
            break;
        }
    }
    return msb;
}

void solve(istream& cin, ostream& cout){
    const int MAX_BIT = 30;

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> cnt(MAX_BIT + 1);
    for(int i = 0; i < n; ++i){
        cnt[getMSB(a[i], MAX_BIT)] += 1;
    }

    long long answer = 0;
    for(int i = 0; i < n; ++i){
        int msb = getMSB(a[i], MAX_BIT);
        cnt[msb] -= 1;
        answer += cnt[msb];
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