class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int N = words.size();

        // dp[i]: max length of an alternating subsequence ending with words[i]
        vector<int> dp(N, 1);
        vector<int> prev(N, -1);
        vector<int> prevIndexOfGroup(2, -1);

        for(int i = 0; i < N; ++i){
            int j = prevIndexOfGroup[1 - groups[i]];
            if(j >= 0){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
            prevIndexOfGroup[groups[i]] = i;
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