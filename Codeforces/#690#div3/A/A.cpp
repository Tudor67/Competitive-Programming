#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    int l = 0;
    int r = n - 1;
    bool updateLeft = true;
    while(l <= r){
        if(updateLeft){
            cout << b[l] << " ";
            l += 1;
        }else{
            cout << b[r] << " ";
            r -= 1;
        }
        updateLeft ^= 1;
    }
    cout << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}