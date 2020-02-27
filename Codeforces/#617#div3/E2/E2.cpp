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

string solve(string& s, const int& n, ostream& cout){
    vector <set <char>> color_set(26, set<char>());
    vector <char> sol(n, 1);

    for(int i = 0; i < n; ++i){
        set <char> colors_to_visit;
        for(char c = s[i] - 'a' + 1; c < color_set.size(); ++c){
            if(!color_set[c].empty()){
                colors_to_visit.insert(color_set[c].begin(), color_set[c].end());
            }
        }

        for(char c = 1; c <= 26; ++c){
            if(colors_to_visit.find(c) == colors_to_visit.end()){
                sol[i] = c;
                break;
            }
        }

        color_set[s[i] - 'a'].insert(sol[i]);
    }

    cout << (short int)*max_element(sol.begin(), sol.end()) << "\n";
    for(short int c: sol){
        cout << c << " ";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    string s;
    int n;

    cin >> n >> s;

    solve(s, n, cout);

    return 0;
}