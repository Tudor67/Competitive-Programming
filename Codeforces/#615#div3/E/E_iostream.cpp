#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <string>
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

    vector <vector <int>> a(n + 1);
    for(int i = 1; i <= n; ++i){
        a[i].resize(m + 1, 0);
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    int sol = 0;
    for(int j = 1; j <= m; ++j){
        vector <int> dist_freq(n + 1, 0);

        for(int i = 1; i <= n; ++i){
            int exp_line = 1 + (a[i][j] - 1) / m;

            if(a[i][j] % m == j % m && exp_line <= n){
                // valid candidate: possible shift operation
                int dist = (i - exp_line + n) % n;
                ++dist_freq[dist];
            }
        }

        int cur_sol = n;
        int cnt_op1 = 0; // these candidates need the 1st operation (change value)
        int cnt_op2 = 0; // these candidates need the 2nd operation (shift column)
        for(int dist = 0; dist <= n; ++dist){
            cnt_op1 = n - dist_freq[dist];
            cnt_op2 = dist;
            cur_sol = min(cnt_op1 + cnt_op2, cur_sol);
        }

        sol += cur_sol;
    }

    cout << sol;

    return 0;
}