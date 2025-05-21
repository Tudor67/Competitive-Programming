class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int N = words.size();

        vector<string> res;
        int lastTakenGroup = 1 - groups[0];

        for(int i = 0; i < N; ++i){
            if(lastTakenGroup != groups[i]){
                res.push_back(words[i]);
                lastTakenGroup = groups[i];
            }
        }

        return res;
    }
};