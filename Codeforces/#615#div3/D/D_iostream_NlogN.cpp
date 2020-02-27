#include <algorithm>
#include <set>
using namespace std;
 
#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif
 
const int MAX_N = 4e5 + 1;

int modulo_freq[MAX_N];
set <pair<int, int>> vals;
int q, x, y;
 
int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    // First solution: O(QlogQ)
    cin >> q >> x;

    for(int i = 0; i < x; ++i){
        vals.insert(make_pair(0, i));
    }

    for(; q > 0; --q){
        cin >> y; 
        y %= x;

        vals.erase(make_pair(modulo_freq[y], y));
        vals.insert(make_pair(++modulo_freq[y], y));
 
        cout << vals.begin()->first * x + vals.begin()->second << "\n";
    }
 
    return 0;
}