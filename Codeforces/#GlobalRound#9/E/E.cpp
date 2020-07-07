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
    
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<tuple<int, int, int>> inversions;
    for(int i = 1; i <= n - 1; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(a[i] > a[j]){
                inversions.push_back({-j, a[i], i});
            }
        }
    }

    sort(inversions.begin(), inversions.end());

    cout << inversions.size() << "\n";
    for(const tuple<int, int, int>& t: inversions){
        int i = get<2>(t);
        int j = -get<0>(t);
        cout << i << " " << j << "\n";
    }

    return 0;
}