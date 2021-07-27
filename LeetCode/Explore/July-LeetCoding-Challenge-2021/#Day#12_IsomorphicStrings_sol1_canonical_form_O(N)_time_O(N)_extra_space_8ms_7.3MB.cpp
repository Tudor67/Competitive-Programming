class Solution {
private:
    string computeCanonicalForm(const string& S){
        string canonicalForm;
        unordered_map<char, int> idxOf;
        int idx = -1;
        for(char c: S){
            if(!idxOf.count(c)){
                idx += 1;
                idxOf[c] = idx;
            }
            canonicalForm += char(idxOf[c]);
        }
        return canonicalForm;
    }
    
public:
    bool isIsomorphic(string s, string t) {
        string sCanonicalForm = computeCanonicalForm(s);
        string tCanonicalForm = computeCanonicalForm(t);
        return (sCanonicalForm == tCanonicalForm);
    }
};