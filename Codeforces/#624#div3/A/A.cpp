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

short int solve(const int& a, const int& b){
    short int sol = 0;
    int d;
    if(a == b){
        sol = 0;
    }else if(a < b){
        d = b - a;
        sol = 1 + (d % 2 == 0);
    }else{
        d = a - b;
        sol = 1 + (d % 2 == 1);
    }
    return sol;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int t, n, a, b;
    cin >> t;

    for(; t > 0; --t){
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }

    return 0;
}