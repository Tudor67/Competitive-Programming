class Solution {
private:
    void computeCanonicalForm(const string& STR, string& canonicalForm){
        const int A = 26;
        const int FIRST_CHAR = 'a';
        
        vector<int> count(A);
        for(char c: STR){
            count[c - FIRST_CHAR] += 1;
        }
        
        canonicalForm.clear();
        for(char c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
            if(count[c - FIRST_CHAR] >= 1){
                canonicalForm += c;
            }
            if(count[c - FIRST_CHAR] >= 2){
                canonicalForm += to_string(count[c - FIRST_CHAR]);
            }
        }
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int N = strs.size();
        
        vector<vector<string>> groups;
        unordered_map<string, int> groupIndexOf;
        for(const string& STR: strs){
            string canonicalForm;
            computeCanonicalForm(STR, canonicalForm);
            
            if(!groupIndexOf.count(canonicalForm)){
                groupIndexOf[canonicalForm] = groups.size();
                groups.push_back({});
            }
            groups[groupIndexOf[canonicalForm]].push_back(STR);
        }
        
        return groups;
    }
};