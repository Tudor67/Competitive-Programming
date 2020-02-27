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

int solve(int s){
    int sol = s;
    int r;

    while(s > 9){
        r = s / 10;
        sol += r;
        s = (s % 10) + r;
    }
    
    return sol;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int t, s;

    cin >> t;

    for(; t > 0; --t){
        cin >> s;
        cout << solve(s) << "\n";
    }

    return 0;
}