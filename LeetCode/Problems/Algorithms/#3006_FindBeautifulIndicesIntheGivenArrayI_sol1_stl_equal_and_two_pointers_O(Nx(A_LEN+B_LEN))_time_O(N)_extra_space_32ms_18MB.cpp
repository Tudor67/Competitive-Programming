class Solution {
private:
    vector<int> computeMatches(string& p, string& s){
        int pLen = p.length();
        int sLen = s.length();

        vector<int> matches;
        for(int i = 0; i + pLen - 1 < sLen; ++i){
            if(equal(p.begin(), p.end(), s.begin() + i)){
                matches.push_back(i);
            }
        }

        return matches;
    }
    
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> aMatches = computeMatches(a, s);
        vector<int> bMatches = computeMatches(b, s);

        vector<int> res;
        int ptr = 0;
        for(int i: aMatches){
            while(ptr < (int)bMatches.size() && bMatches[ptr] < i - k){
                ptr += 1;
            }
            if(ptr < (int)bMatches.size() && bMatches[ptr] <= i + k){
                res.push_back(i);
            }
        }
        
        return res;
    }
};