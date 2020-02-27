#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif

int t, n, x, y;
vector <pair<int, int>> p;

void solve(vector <pair<int, int>>& p, const int& n, ostream& cout){
    sort(p.begin(), p.end());

    string sol = "";
    int prev_x, prev_y;
    int x, y;

    prev_x = 0;
    prev_y = 0;
    for(auto p_xy: p){
        x = p_xy.first;
        y = p_xy.second;

        //cout << x << " " << y << "\n";

        if(prev_y > y){
            cout << "NO\n";
            return;
        }

        for(int i = 1; i <= x - prev_x; ++i) sol += "R";
        for(int i = 1; i <= y - prev_y; ++i) sol += "U";

        prev_x = x;
        prev_y = y;
    }


    cout << "YES\n" << sol << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    cin >> t;

    for(; t > 0; --t){
        cin >> n;

        p.clear();
        for(int i = 1; i <= n; ++i){
            cin >> x >> y;
            p.push_back(make_pair(x, y));
        }

        solve(p, n, cout);
    }

    return 0;
}