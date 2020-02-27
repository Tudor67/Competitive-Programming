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

string solve(istream& cin){
    int n, x;
    cin >> n;

    int odd_cnt = 0;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        odd_cnt += (x % 2);
    }

    if((odd_cnt % 2 == 1) || ((odd_cnt > 0) && (n - odd_cnt > 0))){
        return "YES";
    }

    return "NO";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int t;

    cin >> t;

    for(; t > 0; --t){
        cout << solve(cin) << "\n";
    }

    return 0;
}