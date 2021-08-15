class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string, int> groupIdxOf;
        for(const string& STR: strs){
            string sortedStr(STR.begin(), STR.end());
            sort(sortedStr.begin(), sortedStr.end());
            if(!groupIdxOf.count(sortedStr)){
                groupIdxOf[sortedStr] = groups.size();
                groups.push_back({});
            }
            groups[groupIdxOf[sortedStr]].push_back(STR);
        }
        return groups;
    }
};