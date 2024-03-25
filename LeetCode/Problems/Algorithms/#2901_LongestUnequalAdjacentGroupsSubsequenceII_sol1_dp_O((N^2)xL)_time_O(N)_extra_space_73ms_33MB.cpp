class Solution {
private:
    int computeHammingDistance(const string& A, const string& B){
        if(A.length() != B.length()){
            return INT_MAX;
        }
        const int L = A.length();
        int distance = 0;
        for(int i = 0; i < L; ++i){
            distance += (A[i] != B[i]);
        }
        return distance;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int N = words.size();

        // dp[i]: max length of an alternating subsequence ending with words[i]
        vector<int> dp(N, 1);
        vector<int> prev(N, -1);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(groups[j] != groups[i] && dp[j] + 1 > dp[i]){
                    if(computeHammingDistance(words[i], words[j]) == 1){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }

        vector<string> res;
        int index = max_element(dp.begin(), dp.end()) - dp.begin();
        while(index != -1){
            res.push_back(words[index]);
            index = prev[index];
        }

        reverse(res.begin(), res.end());

        return res;
    }
};