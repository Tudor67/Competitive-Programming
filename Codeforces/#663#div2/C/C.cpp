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
    
    const long long MODULO = (1e9) + 7;

    int n;
    cin >> n;

    long long factorial = 1;
    for(int i = 1; i <= n; ++i){
        factorial = (factorial * i) % MODULO;
    }

    long long pow2 = 1;
    for(int i = 1; i <= n - 1; ++i){
        pow2 = (pow2 * 2) % MODULO;
    }

    long long answer = (factorial - pow2 + MODULO) % MODULO;
    cout << answer;

    return 0;
}