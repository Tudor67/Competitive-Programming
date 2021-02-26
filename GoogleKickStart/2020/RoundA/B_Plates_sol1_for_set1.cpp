#include <bits/stdc++.h>
using namespace std;

void solve(const int& TEST_CASE, istream& cin, ostream& cout){
    int N, K, P;
    cin >> N >> K >> P;

    vector<vector<int>> a(N, vector<int>(K));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < K; ++j){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> prefSum(N, vector<int>(K));
    for(int i = 0; i < N; ++i){
        prefSum[i][0] = a[i][0];
        for(int j = 1; j < K; ++j){
            prefSum[i][j] = prefSum[i][j - 1] + a[i][j];
        }
    }

    int answer = 0;
    if(N == 1){
        answer = prefSum[0][P - 1];
    }else if(N == 2){
        for(int c0 = 0; c0 <= min(K, P); ++c0){
            int c1 = max(0, min(K, P - c0));
            int sum0 = (c0 - 1 < 0 ? 0 : prefSum[0][c0 - 1]);
            int sum1 = (c1 - 1 < 0 ? 0 : prefSum[1][c1 - 1]);
            answer = max(sum0 + sum1, answer);
        }
    }else if(N == 3){
        for(int c0 = 0; c0 <= min(K, P); ++c0){
            for(int c1 = 0; c1 <= min(K, P - c0); ++c1){
                int c2 = max(0, min(K, P - c0 - c1));
                int sum0 = (c0 - 1 < 0 ? 0 : prefSum[0][c0 - 1]);
                int sum1 = (c1 - 1 < 0 ? 0 : prefSum[1][c1 - 1]);
                int sum2 = (c2 - 1 < 0 ? 0 : prefSum[2][c2 - 1]);
                answer = max(sum0 + sum1 + sum2, answer);
            }
        }
    }

    cout << "Case #" << TEST_CASE << ": " << answer << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        solve(testCase, cin, cout);
    }

    return 0;
}