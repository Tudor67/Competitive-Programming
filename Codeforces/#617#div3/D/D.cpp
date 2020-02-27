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

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int n, a, b, k, h;

    cin >> n >> a >> b >> k;

    vector <int> cost(n);
    for(int i = 0; i < n; ++i){
        cin >> h;

        h %= a + b;
        if(h == 0){
            h = a + b;
        }

        if(h <= a){
            cost[i] = 0;
        }else{
            cost[i] = (h - a) / a + (h % a != 0);
        }
    }

    sort(cost.begin(), cost.end());

    int win_cnt = 0;
    for(int& c: cost){
        if(k >= c){
            k -= c;
            ++win_cnt;
        }else{
            break;
        }
    }

    cout << win_cnt;

    return 0;
}