class Solution {
private:
    bool isSubstring(const string& P, const string& S){
        const string PS = P + "$" + S;
        const int P_LEN = P.length();
        const int PS_LEN = PS.length();

        vector<int> lps(PS_LEN);
        for(int i = 1; i < PS_LEN; ++i){
            int k = lps[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = lps[k - 1];
            }
            if(PS[k] == PS[i]){
                ++k;
            }
            lps[i] = k;
            if(lps[i] == P_LEN){
                return true;
            }
        }

        return false;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int matchings = 0;
        for(string& p: patterns){
            if(isSubstring(p, word)){
                ++matchings;
            }
        }
        return matchings;
    }
};