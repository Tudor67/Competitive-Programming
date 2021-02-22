#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<long long> h(N + 2);
    for(int i = 0; i < N; ++i){
        cin >> h[i];
    }

    for(int i = 0; i < N; ++i){
        if(h[i] > i){
            h[i + 1] += (h[i] - i);
            h[i] = i;
        }
    }

    bool isValid = true;
    for(int i = 1; i < N; ++i){
        if(h[i - 1] >= h[i]){
            isValid = false;
            break;
        }
    }

    if(isValid){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}