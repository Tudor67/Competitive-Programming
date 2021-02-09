#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }

    // Step 1: remove consecutive elements with the same value
    //         [x, x, x, y, x, z, z, y] -> [x, y, x, z, y]
    int M = 1;
    for(int j = 2; j <= N; ++j){
        if(a[M] != a[j]){
            M += 1;
            a[M] = a[j];
        }
    }

    a.resize(M + 1);

    // Step 2: apply dp
    //         dp[i]: minimum possible total number of segments at step i
    vector<int> dp(M + 1, 0);
    vector<int> lastPosOf(N + 1, -1);
    for(int i = 1; i <= M; ++i){
        dp[i] = dp[i - 1] + 1;
        if(lastPosOf[a[i]] != -1){
            int j = lastPosOf[a[i]] + 1;
            dp[i] = min(dp[j] + i - j - 1, dp[i]);
        }
        lastPosOf[a[i]] = i;
    }

    cout << dp[M];
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve(cin, cout);

    return 0;
}