class Solution {
private:
    vector<int> lps;

    bool isSubstring(const string& P, const string& S){
        const string PS = P + "$" + S;
        const int PS_LEN = PS.length();

        lps.resize(PS_LEN);
        for(int i = 1; i < PS_LEN; ++i){
            int k = lps[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = lps[k - 1];
            }
            if(PS[k] == PS[i]){
                k += 1;
            }
            lps[i] = k;
            if(lps[i] == (int)P.length()){
                return true;
            }
        }

        return false;
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        const int N = words.size();

        vector<string> res;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && isSubstring(words[i], words[j])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};