class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int N = strs.size();
        
        vector<pair<string, int>> v(N);
        for(int i = 0; i < N; ++i){
            string sortedStr(strs[i].begin(), strs[i].end());
            sort(sortedStr.begin(), sortedStr.end());
            v[i] = {sortedStr, i};
        }
        
        sort(v.begin(), v.end());
        
        vector<vector<string>> groups;
        for(int i = 0; i < N; ++i){
            if(i == 0 || v[i - 1].first != v[i].first){
                groups.push_back({});
            }
            groups.back().push_back(strs[v[i].second]);
        }
        
        return groups;
    }
};