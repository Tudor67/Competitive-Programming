class Solution {
private:
    vector<int> computeMatches(string& p, string& s){
        string ps = p + "#" + s;
        int psLen = ps.length();
        int pLen = p.length();

        vector<int> matches;
        vector<int> z(psLen);
        int l = 0;
        int r = 0;
        for(int i = 1; i < psLen; ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < psLen && ps[z[i]] == ps[i + z[i]]){
                z[i] += 1;
            }
            if(r <= i + z[i] - 1){
                l = i;
                r = i + z[i] - 1;
            }
            if(z[i] == pLen){
                matches.push_back(i - (pLen + 1));
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