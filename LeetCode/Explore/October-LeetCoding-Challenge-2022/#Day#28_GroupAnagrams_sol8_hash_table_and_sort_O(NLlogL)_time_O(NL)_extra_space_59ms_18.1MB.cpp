class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int N = strs.size();
        
        vector<vector<string>> groups;
        unordered_map<string, int> groupIndexOf;
        for(const string& STR: strs){
            string canonicalForm = STR;
            sort(canonicalForm.begin(), canonicalForm.end());
            
            if(!groupIndexOf.count(canonicalForm)){
                groupIndexOf[canonicalForm] = groups.size();
                groups.push_back({});
            }
            groups[groupIndexOf[canonicalForm]].push_back(STR);
        }
        
        return groups;
    }
};