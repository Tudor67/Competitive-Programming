class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int N = words.size();

        vector<string> res = {words[0]};
        int prevGroup = groups[0];
        for(int i = 1; i < N; ++i){
            if(prevGroup != groups[i]){
                res.push_back(words[i]);
                prevGroup = groups[i];
            }
        }
        
        return res;
    }
};