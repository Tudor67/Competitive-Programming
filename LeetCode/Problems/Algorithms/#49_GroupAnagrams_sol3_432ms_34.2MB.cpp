class Solution {
private:
    map<char, int> get_cnt(const string& s){
        map<char, int> cnt;
        for(char c: s){
            ++cnt[c];
        }
        return cnt;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<int>> cnt_ids_map;
        vector<vector<string>> ans;
        
        for(int i = 0; i < strs.size(); ++i){
            cnt_ids_map[get_cnt(strs[i])].push_back(i);
        }
        
        for(const pair<map<char, int>, vector<int>>& p: cnt_ids_map){
            ans.push_back({});
            for(const int& i: p.second){
                ans.back().push_back(strs[i]);
            }
        }
        
        return ans;
    }
};