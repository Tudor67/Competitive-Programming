#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif

pair <int, int> char_to_dxy(const char& c){
    int dx = 0;
    int dy = 0;
    
    if(c == 'L') --dx;
    else if(c == 'R') ++dx;
    else if(c == 'U') ++dy;
    else if(c == 'D') --dy;

    return {dx, dy};
}

void solve(string& s, const int& n, ostream& cout){
    pair <int, int> sol(1, n + 1);

    map <pair <int, int>, int> last_visit;
    last_visit[{0, 0}] = 0;

    pair <int, int> dxy;
    pair <int, int> cur_pos(0, 0);

    for(int i = 1; i <= n; ++i){
        dxy = char_to_dxy(s[i - 1]);
        cur_pos.first += dxy.first;
        cur_pos.second += dxy.second;

        if(last_visit.find(cur_pos) != last_visit.end()){
            if(i - last_visit[cur_pos] < sol.second - sol.first + 1){
                sol = {last_visit[cur_pos] + 1, i};
            }
        }

        last_visit[cur_pos] = i;
    }

    if(sol.second == n + 1){
        cout << "-1\n";
    }else{
        cout << sol.first << " " << sol.second << "\n";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int t, n;
    string s;

    cin >> t;

    for(; t > 0; --t){
        cin >> n >> s;
        solve(s, n, cout);
    }

    return 0;
}