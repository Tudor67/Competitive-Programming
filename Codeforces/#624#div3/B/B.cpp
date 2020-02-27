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

void read_vector(vector<int>& v, const int& n, istream& cin){
    v.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }
}

string solve(vector<int>& a, const int& n, vector<int>& p, const int& m){
    sort(p.begin() + 1, p.end());

    int i = 1;
    int j = 1;
    while(j < p.size()){
        while(j + 1 < p.size() && p[j] + 1 == p[j + 1]){
            ++j;
        }
        sort(a.begin() + p[i], a.begin() + p[j] + 2);
 
        ++j;
        i = j;
    }

    bool is_sorted = 1;
    for(int i = 1; is_sorted && i <= n - 1; ++i){
        if(a[i] > a[i + 1]){
            is_sorted = 0;
        }
    }

    return is_sorted ? "YES" : "NO";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int t, n, m;
    vector<int> a;
    vector<int> p;

    cin >> t;
    for(; t > 0; --t){
        cin >> n >> m;
        read_vector(a, n, cin);
        read_vector(p, m, cin);
        cout << solve(a, n, p, m) << "\n";
    }

    return 0;
}