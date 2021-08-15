class Solution {
private:
    string getCanonicalForm(const string& S){
        vector<int> count(26);
        for(char c: S){
            count[c - 'a'] += 1;
        }
        string canonicalForm;
        for(int i = 0; i < (int)count.size(); ++i){
            if(count[i] > 0){
                canonicalForm += char('a' + i);
                canonicalForm += to_string(count[i]);
            }
        }
        return canonicalForm;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string, int> groupIdxOf;
        for(const string& S: strs){
            string canonicalForm = getCanonicalForm(S);
            if(!groupIdxOf.count(canonicalForm)){
                groupIdxOf[canonicalForm] = groups.size();
                groups.push_back({});
            }
            groups[groupIdxOf[canonicalForm]].push_back(S);
        }
        return groups;
    }
};