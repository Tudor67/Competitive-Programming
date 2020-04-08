class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> pairs;
        for(const string& s: strs){
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            pairs.push_back({sorted_s, s});
        }
        
        sort(pairs.begin(), pairs.end());
        
        vector<vector<string>> ans;
        ans.push_back({pairs[0].second});
        for(int i = 1; i < pairs.size(); ++i){
            if(pairs[i].first == pairs[i - 1].first){
                ans.back().push_back(pairs[i].second);
            }else{
                ans.push_back({pairs[i].second});
            }
        }
        
        return ans;
    }
};