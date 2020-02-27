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
        int a, b, c;
        cin >> a >> b >> c;

        int sol_num_moves = (int)4e4;
        int sol_a = -1;
        int sol_b = -1;
        int sol_c = -1;

        // O(NlogN), N = 20_000
        int lim = (int)2e4;
        for(int i = 1; i <= lim; ++i){
            for(int j = i; j <= lim; j += i){
                for(int k: {(c / j) * j, (1 + c / j) * j}){
                    int num_moves = abs(i - a) + abs(j - b) + abs(k - c);
                    if(num_moves < sol_num_moves){
                        sol_num_moves = num_moves;
                        sol_a = i;
                        sol_b = j;
                        sol_c = k;
                    }
                }
            }
        }

        cout << sol_num_moves << "\n";
        cout << sol_a << " " << sol_b << " " << sol_c << "\n";
    }

    return 0;
}