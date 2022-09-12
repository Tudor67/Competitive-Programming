class Solution {
private:
    static bool comp(const string& LHS, const string& RHS){
        int lhsFirstSpacePos = find(LHS.begin(), LHS.end(), ' ') - LHS.begin();
        int rhsFirstSpacePos = find(RHS.begin(), RHS.end(), ' ') - RHS.begin();
        int identifierCompRes = LHS.compare(0, lhsFirstSpacePos, RHS, 0, rhsFirstSpacePos);
        int contentCompRes = LHS.compare(lhsFirstSpacePos + 1, string::npos, RHS, rhsFirstSpacePos + 1, string::npos);
        return (contentCompRes < 0 || (contentCompRes == 0 && identifierCompRes < 0));
    }
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        const int N = logs.size();
        
        vector<string> res;
        res.reserve(N);
        
        // 1. The letter-logs come before all digit-logs.
        for(const string& LOG: logs){
            if(!isdigit(LOG.back())){
                res.push_back(LOG);
            }
        }
        
        // 2. The letter-logs are sorted lexicographically by their contents.
        //    If their contents are the same, then sort them lexicographically by their identifiers.
        sort(res.begin(), res.end(), comp);
        
        // 3. The digit-logs maintain their relative ordering.
        for(const string& LOG: logs){
            if(isdigit(LOG.back())){
                res.push_back(LOG);
            }
        }
        
        return res;
    }
};