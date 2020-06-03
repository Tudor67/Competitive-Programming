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

        string answer = "-1";
        for(int pos = 0; answer == "-1" && pos < m; ++pos){
            string candidate = s[0];
            for(char c = 'a'; c <= 'z'; ++c){
                candidate[pos] = c;

                bool ok = true;
                for(int i = 0; i < n; ++i){
                    int dist = 0;
                    for(int j = 0; j < m; ++j){
                        dist += (candidate[j] != s[i][j]);
                    }
                    ok &= (dist <= 1);
                }

                if(ok){
                    answer = candidate;
                    break;
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
