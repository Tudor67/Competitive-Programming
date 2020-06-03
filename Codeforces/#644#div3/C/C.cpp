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
    
    const int MAX_N = 55;
    vector<int> a(MAX_N);

    int t;
    cin >> t;

    for(; t > 0; --t){
        int n;
        cin >> n;

        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        int odd = 0;
        int even = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] % 2 == 0){
                ++even;
            }else{
                ++odd;
            }
        }

        string answer;
        if(even % 2 == 0 && odd % 2 == 0){
            answer = "YES";
        }else{
            multiset<int> values;
            for(int i = 0; i < n; ++i){
                values.insert(a[i]);
            }

            int consec_pairs = 0;
            for(int i = 0; i < n; ++i){
                consec_pairs += min(values.count(a[i]), values.count(a[i] + 1));
                values.erase(a[i] + 1);
            }

            even -= (consec_pairs > 0);
            odd -= (consec_pairs > 0);

            if(even % 2 == 0 && odd % 2 == 0){
                answer = "YES";
            }else{
                answer = "NO";
            }
        }
        
        cout << answer << "\n";
    }

    return 0;
}