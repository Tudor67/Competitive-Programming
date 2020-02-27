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

string solve(string& s, const int& n){
    string sol(n, '0');
    char last_0_char = s[0];
    char last_1_char = 'a';

    for(int i = 1; i < n; ++i){
        if(s[i] >= last_0_char){
            last_0_char = s[i];
        }else if(s[i] >= last_1_char){
            last_1_char = s[i];
            sol[i] = '1';
        }else{
            return "NO";
        }
    }

    return "YES\n" + sol;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    string s;
    int n;

    cin >> n >> s;
    cout << solve(s, n);

    return 0;
}