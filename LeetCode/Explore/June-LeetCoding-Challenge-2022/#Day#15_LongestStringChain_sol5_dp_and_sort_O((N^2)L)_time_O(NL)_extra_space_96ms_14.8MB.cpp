class Solution {
private:
    bool isPredecessor(const string& A, const string& B){
        const int A_LEN = A.length();
        const int B_LEN = B.length();
        
        if(A_LEN + 1 != B_LEN){
            return false;
        }
        
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
        vector<string> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end(),
             [](const string& LHS, const string& RHS){
                 return (LHS.length() < RHS.length());
             });
        
        // dp[i]: length of the longest chain ending with sortedWords[i]
        const int N = sortedWords.size();
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = 1;
            for(int j = 0; j < i && sortedWords[j].length() + 1 <= sortedWords[i].length(); ++j){
                if(dp[j] + 1 > dp[i] && isPredecessor(sortedWords[j], sortedWords[i])){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};