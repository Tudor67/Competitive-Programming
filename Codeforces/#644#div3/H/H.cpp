#include <algorithm>
#include <bitset>
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

bool valid(const long long& median, const long long& size, const vector<long long>& v){
    bool contains_median = false;
    long long less_cnt = 0;
    long long greater_cnt = 0;
    for(const long long& x: v){
        if(x < median){
            ++less_cnt;
        }else{
            ++greater_cnt;
        }

        if(x == median){
            contains_median = true;
            break;
        }
    }

    long long left_cnt = median + 1 - less_cnt;
    long long right_cnt = size - 1 - median - greater_cnt;
    return (!contains_median && (left_cnt == right_cnt || left_cnt - 1 == right_cnt));
}

string solve(const vector<string>& a, const int& m){
    vector<long long> v(a.size());
    for(int i = 0; i < v.size(); ++i){
        v[i] = stoll(a[i], NULL, 2);
    }

    long long size = (1LL << m);
    long long median = size / 2 - 2 * int(v.size());
    for(; median <= size / 2 + 2 * v.size(); ++median){
        if(valid(median, size, v)){
            break;
        }
    }

    string answer = bitset<60>(median).to_string().substr(60 - m);
    return answer;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int t;
    cin >> t;

    for(; t > 0; --t){
        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        cout << solve(a, m) << "\n";
    }

    return 0;
}