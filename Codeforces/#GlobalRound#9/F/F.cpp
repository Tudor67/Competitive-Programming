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

long long a, b, c, pile;
vector<long long> v;

void ask(const long long& Y){
    cout << Y << endl;
    cin >> pile;
    if(pile <= 0){
        exit(0);
    }
    if(pile == 1){
        a += Y;
    }
    if(pile == 2){
        b += Y;
    }
    if(pile == 3){
        c += Y;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    // Step 0
    cin >> a >> b >> c;
    cout << "First" << endl;
    
    // Step 1
    ask(a + b + c);

    // Step 2
    v = {a, b, c};
    sort(v.begin(), v.end());
    ask(v[1] - v[0] + 2 * (v[2] - v[1]));

    // Step 3
    v = {a, b, c};
    sort(v.begin(), v.end());
    ask(v[1] - v[0]);

    return 0;
}