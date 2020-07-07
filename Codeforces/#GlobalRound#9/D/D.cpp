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

int extract_mex(const vector<int>& CNT){
    for(int i = 0; i < CNT.size(); ++i){
        if(CNT[i] == 0){
            return i;
        }
    }
    return -1;
}

int extract_unfixed_position(const vector<int>& A, const int& N){
    for(int i = 0; i < N; ++i){
        if(A[i] != i){
            return i;
        }
    }
    return -1;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
 
    const int MAX_N = 1003;
    vector<int> a(MAX_N);
    vector<int> cnt(MAX_N);

    int t;
    cin >> t;

    for(; t > 0; --t){
        int n;
        cin >> n;

        fill(cnt.begin(), cnt.begin() + n + 1, 0);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            ++cnt[a[i]];
        }

        vector<int> x;
        int unfixed_position = extract_unfixed_position(a, n);
        while(unfixed_position != -1){
            int mex = extract_mex(cnt);
            int pos = mex;
            if(pos == n){
                pos = unfixed_position;
            }
            --cnt[a[pos]];
            ++cnt[mex];
            a[pos] = mex;
            x.push_back(pos + 1);
            unfixed_position = extract_unfixed_position(a, n);
        }

        cout << x.size() << "\n";
        for(int position: x){
            cout << position << " ";
        }
        cout << "\n";
    } 

    return 0;
}