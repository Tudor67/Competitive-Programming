#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int N = 20;
    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1));
    
    for(int i = 0; i <= N; ++i){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    // 137846528820
    cout << dp[N][N];
    
    return 0;
}