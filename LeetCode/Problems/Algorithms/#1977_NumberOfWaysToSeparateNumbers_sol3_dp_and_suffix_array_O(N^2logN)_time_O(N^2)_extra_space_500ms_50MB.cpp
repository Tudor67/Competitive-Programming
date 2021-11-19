class Solution {
private:
    int computeLCPLength(int i, int j, vector<vector<int>>& c){
        const int N = c[0].size();
        int lcpLength = 0;
        for(int k = (int)c.size() - 1; k >= 0 && i < N && j < N; --k){
            if(c[k][i] == c[k][j]){
                lcpLength += (1 << k);
                i += (1 << k);
                j += (1 << k);
            }
        }
        return lcpLength;
    }
    
public:
    int numberOfCombinations(string num) {        
        if(num[0] == '0'){
            return 0;
        }
        
        const int N = num.length();
        const int LOG_N = ceil(log2(N));
        const int MODULO = 1e9 + 7;
        
        // suffix array
        // c[k][i]: equivalence class of substring num[i .. i + (2^k) - 1]
        //          in the sorted array of suffixes of length 2^k
        vector<vector<int>> c(LOG_N + 1, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = num[i] - '0';
        }
        
        vector<pair<pair<int, int>, int>> v(N);
        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i < N; ++i){
                int l = c[k - 1][i];
                int r = (i + len / 2 < N ? c[k - 1][i + len / 2] : -1);
                v[i] = {{l, r}, i};
            }
            
            sort(v.begin(), v.end());
            
            int classID = 0;
            c[k][v[0].second] = classID;
            for(int i = 1; i < N; ++i){
                if(v[i - 1].first == v[i].first){
                    c[k][v[i].second] = classID;
                }else{
                    c[k][v[i].second] = ++classID;
                }
            }
        }
        
        // dp[i][j]: number of possible lists of integers from num[0 .. j] with the last integer num[i .. j]
        int dp[N][N];
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                dp[i][j] = 0;
            }
        }
        
        fill(dp[0], dp[0] + N, 1);
        
        for(int i = 1; i < N; ++i){
            if(num[i] == '0'){
                continue;
            }
            // sum = dp[k + 1][i - 1] + dp[k + 2][i - 1] + ... + dp[i - 1][i - 1]
            int sum = 0;
            int k = i - 1;
            for(int j = i; j < N; ++j){
                if(0 <= k + 1 && k + 1 <= i - 1){
                    sum += dp[k + 1][i - 1];
                    sum %= MODULO;
                }
                dp[i][j] += sum;
                dp[i][j] %= MODULO;
                int len = j - i + 1;
                if(k >= 0 && i - k == len){
                    int lcpLen = computeLCPLength(k, i, c);
                    if(lcpLen >= len || num[k + lcpLen] < num[i + lcpLen]){
                        dp[i][j] += dp[k][i - 1];
                        dp[i][j] %= MODULO;
                    }
                }
                k -= 1;
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            answer += dp[i][N - 1];
            answer %= MODULO;
        }
        
        return answer;
    }
};