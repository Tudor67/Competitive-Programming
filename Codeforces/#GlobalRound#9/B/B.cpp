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

int max_k(const int& I, const int& J, const int& N, const int& M){
    if(I > 0 && I < N - 1 && J > 0 && J < M - 1){
        return 4;
    }
    if((I == 0 || I == N - 1) && (J > 0 && J < M - 1)){
        return 3;
    }
    if((J == 0 || J == M - 1) && (I > 0 && I < N - 1)){
        return 3;
    }
    return 2;
}

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

        bool ok = true;
        int k;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> k;
                if(max_k(i, j, n, m) < k){
                    ok = false;
                }
            }
        }

        if(ok){
            cout << "YES\n";
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    cout << max_k(i, j, n, m) << " ";
                }
                cout << "\n";
            }
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}