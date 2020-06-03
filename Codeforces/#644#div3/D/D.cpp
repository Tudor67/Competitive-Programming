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
        long long n, k;
        cin >> n >> k;
        
        long long answer = n;
        if(k >= n){
            answer = 1;
        }else{
            for(long long i = 2; i * i <= n; ++i){
                if(n % i == 0){
                    for(long long package_size: {i, n / i}){
                        if(package_size <= k){
                            answer = min(n / package_size, answer);
                        }
                    }
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}