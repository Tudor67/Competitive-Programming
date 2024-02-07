class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int N = strs.size();

        unordered_map<string, vector<int>> canonicalFormToIndices;
        for(int i = 0; i < N; ++i){
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            canonicalFormToIndices[sortedStr].push_back(i);
        }

        vector<vector<string>> res;
        res.reserve(canonicalFormToIndices.size());
        for(const pair<const string, vector<int>>& P: canonicalFormToIndices){
            const vector<int>& INDICES = P.second;
            res.push_back({});
            for(int i: INDICES){
                res.back().push_back(strs[i]);
            }
        }

        return res;
    }
};