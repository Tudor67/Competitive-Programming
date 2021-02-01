#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N; 
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    const int MAX_VAL = *max_element(a.begin(), a.end());
    vector<int> count(MAX_VAL + 1, 0);
    for(int i = 0; i < N; ++i){
        count[a[i]] += 1;
    }

    vector<int> dp(MAX_VAL + 1, 0);
    for(int i = 1; i <= MAX_VAL; ++i){
        if(count[i] >= 1){
            dp[i] = max(count[i], dp[i]);
            for(int j = i + i; j <= MAX_VAL; j += i){
                dp[j] = max(count[j] + dp[i], dp[j]);
            }
        }
    }

    int answer = N - *max_element(dp.begin(), dp.end());

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