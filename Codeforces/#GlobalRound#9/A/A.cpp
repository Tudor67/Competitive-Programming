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
    cin >> t;

    for(; t > 0; --t){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        for(int i = 0; i < n; ++i){
            if(i % 2){
                cout << max(-a[i], a[i]) << " ";
            }else{
                cout << min(-a[i], a[i]) << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}