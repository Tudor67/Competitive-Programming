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
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        if(a * n == b * m){
            vector<string> s(n, string(m, '0'));
            int col = 0;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < a; ++j){
                    s[i][col] = '1';
                    col = (col + 1) % m;
                }
            }

            cout << "YES\n";
            for(int i = 0; i < n; ++i){
                cout << s[i] << "\n";
            }
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}