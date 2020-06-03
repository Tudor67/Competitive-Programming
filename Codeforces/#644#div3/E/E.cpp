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
    vector<string> s(MAX_N);

    int t, n;
    cin >> t;

    for(; t > 0; --t){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> s[i];
        }

        string answer = "YES";
        for(int i = 0; i < n - 1; ++i){
            for(int j = 0; j < n - 1; ++j){
                if(s[i][j] == '1'){
                    if(s[i + 1][j] == '0' && s[i][j + 1] == '0'){
                        answer = "NO";
                    }
                }
            }
        }

        cout << answer << "\n";
    }   

    return 0;
}