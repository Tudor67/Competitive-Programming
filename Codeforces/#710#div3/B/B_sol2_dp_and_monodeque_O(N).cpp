#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    const int INF = 1e8;
    vector<int> dp(N, INF);

    int startPos = s.find('*');
    dp[startPos] = 1;

    int lastPos = startPos;
    deque<int> dq;
    dq.push_back(startPos);
    for(int i = startPos + 1; i < N; ++i){
        if(i - dq.front() > K){
            dq.pop_front();
        }
        if(s[i] == '*'){
            dp[i] = 1 + dp[dq.front()];
            lastPos = i;
            while(!dq.empty() && dp[dq.back()] >= dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }

    cout << dp[lastPos] << "\n";
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