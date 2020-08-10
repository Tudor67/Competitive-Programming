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
    
    int t;
    cin >> t;

    for(; t > 0; --t){
        int n, m;
        cin >> n >> m;

        vector<string> s(n);
        for(int i = 0; i < n; ++i){
            cin >> s[i];
        }

        int answer = 0;
        for(int i = 0; i < n - 1; ++i){
            answer += (s[i][m - 1] == 'R');
        }

        for(int j = 0; j < m - 1; ++j){
            answer += (s[n - 1][j] == 'D');
        }

        cout << answer << "\n";
    }

    return 0;
}