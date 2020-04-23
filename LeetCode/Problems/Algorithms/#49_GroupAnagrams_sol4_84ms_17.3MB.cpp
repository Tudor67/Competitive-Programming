class Solution {  
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> string_ids_map;
        vector<vector<string>> ans;
        
        for(int i = 0; i < strs.size(); ++i){
            string sorted_s = strs[i];
            sort(sorted_s.begin(), sorted_s.end());
            string_ids_map[sorted_s].push_back(i);
        }
        
        for(const pair<string, vector<int>>& p: string_ids_map){
            ans.push_back({});
            for(const int& i: p.second){
                ans.back().push_back(strs[i]);
            }
        }
        
        return ans;
    }
};