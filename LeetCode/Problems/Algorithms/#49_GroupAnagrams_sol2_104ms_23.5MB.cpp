class Solution {
private:
    vector<int> get_cnt(const string& s){
        vector<int> cnt(26, 0);
        for(char c: s){
            ++cnt[c - 'a'];
        }
        return cnt;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<int>> cnt_ids_map;
        vector<vector<string>> ans;
        
        for(int i = 0; i < strs.size(); ++i){
            cnt_ids_map[get_cnt(strs[i])].push_back(i);
        }
        
        for(const pair<vector<int>, vector<int>>& p: cnt_ids_map){
            ans.push_back({});
            for(const int& i: p.second){
                ans.back().push_back(strs[i]);
            }
        }
        
        return ans;
    }
};