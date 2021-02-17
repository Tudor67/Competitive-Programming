#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    int answer = 0;
    for(int i = 0; i < N - 1; ++i){
        int maximum = max(a[i], a[i + 1]);
        int minimum = min(a[i], a[i + 1]);
        while(2 * minimum < maximum){
            minimum *= 2;
            answer += 1;
        }
    }

    cout << answer << "\n";
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