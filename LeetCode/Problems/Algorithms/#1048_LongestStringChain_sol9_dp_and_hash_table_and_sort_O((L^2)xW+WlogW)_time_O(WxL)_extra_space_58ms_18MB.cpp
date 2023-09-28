class Solution {
public:
    int longestStrChain(vector<string>& words) {
        const int W = words.size();

        vector<int> p(W);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return (words[lhs].length() < words[rhs].length());
             });

        int res = 0;
        unordered_map<string, int> maxLen;
        for(int i: p){
            maxLen[words[i]] = 1;
            const int L = words[i].length();
            for(int j = 0; j < L; ++j){
                string predecessor = words[i].substr(0, j) + words[i].substr(j + 1);
                if(maxLen.count(predecessor)){
                    maxLen[words[i]] = max(maxLen[words[i]], maxLen[predecessor] + 1);
                }
            }
            res = max(res, maxLen[words[i]]);
        }

        return res;
    }
};