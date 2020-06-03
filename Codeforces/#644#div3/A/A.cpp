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
    int a, b;
    int answer;

    cin >> t;

    for(; t > 0; --t){
        cin >> a >> b;
        answer = max({2 * min(a, b), a, b});
        cout << answer * answer << "\n";
    }

    return 0;
}