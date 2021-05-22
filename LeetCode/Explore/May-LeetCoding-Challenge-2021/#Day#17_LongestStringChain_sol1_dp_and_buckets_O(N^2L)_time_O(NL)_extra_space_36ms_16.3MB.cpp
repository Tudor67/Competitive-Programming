class Solution {
private:
    static bool isSubsequence(const string& A, const string& B){
        const int A_LEN = A.length();
        const int B_LEN = B.length();
        int i = 0;
        for(int j = 0; i < A_LEN && j < B_LEN; ++j){
            if(A[i] == B[j]){
                ++i;
            }
        }
        return (i == A_LEN);
    }
    
public:
    int longestStrChain(vector<string>& words) {
        const int N = words.size();
        vector<vector<string>> buckets;
        
        for(const string& WORD: words){
            int len = WORD.size();
            if(len >= (int)buckets.size()){
                buckets.resize(len + 1);
            }
            buckets[len].push_back(WORD);
        }
        
        int answer = 0;
        vector<vector<int>> dp(2);
        for(int len = 1; len < (int)buckets.size(); ++len){
            dp[len % 2].resize((int)buckets[len].size());
            fill(dp[len % 2].begin(), dp[len % 2].end(), 0);
            for(int i = 0; i < (int)buckets[len].size(); ++i){
                dp[len % 2][i] = 1;
                for(int j = 0; j < (int)buckets[len - 1].size(); ++j){
                    if(isSubsequence(buckets[len - 1][j], buckets[len][i])){
                        dp[len % 2][i] = max(1 + dp[(len - 1) % 2][j], dp[len % 2][i]);
                    }
                }
                answer = max(dp[len % 2][i], answer);
            }
        }
        
        return answer;
    }
};