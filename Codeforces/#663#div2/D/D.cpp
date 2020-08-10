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
    
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    int answer = n * m + 1;
    if(n >= 4){
        answer = -1;
    }else if(n == 1){
        answer = 0;
    }else if(n == 2){
        for(int expected_parity: {0, 1}){
            int cnt = 0;
            for(int j = 0; j < m; ++j){
                int parity = (s[0][j] + s[1][j]) % 2;
                cnt += (parity != expected_parity);
                expected_parity ^= 1;
            }
            answer = min(cnt, answer);
        }
    }else if(n == 3){
        for(pair<int, int> expected_parity: vector<pair<int, int>>{{0, 0}, {0, 1}, {1, 0}, {1, 1}}){
            int cnt = 0;
            for(int j = 0; j < m; ++j){
                pair<int, int> parity = {(s[0][j] + s[1][j]) % 2, (s[1][j] + s[2][j]) % 2};
                cnt += (parity != expected_parity);
                expected_parity.first ^= 1;
                expected_parity.second ^= 1;
            }
            answer = min(cnt, answer);
        }
    }

    cout << answer;

    return 0;
}