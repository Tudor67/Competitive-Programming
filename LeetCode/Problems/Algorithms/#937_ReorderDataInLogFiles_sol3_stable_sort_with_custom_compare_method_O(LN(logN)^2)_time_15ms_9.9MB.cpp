class Solution {
private:
    static bool comp(const string& LHS, const string& RHS){
        int lhsType = isdigit(LHS.back());
        int rhsType = isdigit(RHS.back());
        if(lhsType != rhsType){
            // letter log type < digit log type
            return (lhsType < rhsType);
        }
        if(lhsType == 1 && rhsType == 1){
            // digit logs maintain their relative order
            return false;
        }
        // letter logs are sorted lexicographically by their (content, identifier) values
        int lhsFirstSpacePos = find(LHS.begin(), LHS.end(), ' ') - LHS.begin();
        int rhsFirstSpacePos = find(RHS.begin(), RHS.end(), ' ') - RHS.begin();
        int identifierCompRes = LHS.compare(0, lhsFirstSpacePos, RHS, 0, rhsFirstSpacePos);
        int contentCompRes = LHS.compare(lhsFirstSpacePos + 1, string::npos, RHS, rhsFirstSpacePos + 1, string::npos);
        return (contentCompRes < 0 || (contentCompRes == 0 && identifierCompRes < 0));
    }
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        const int N = logs.size();
        vector<string> res = logs;
        stable_sort(res.begin(), res.end(), comp);
        return res;
    }
};