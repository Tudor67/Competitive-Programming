class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int S_LEN = s.length();
        const int P_LEN = p.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';

        unordered_map<char, int> pCount;
        for(char c: p){
            pCount[c] += 1;
        }

        vector<int> res;
        unordered_map<char, int> wCount;
        for(int i = 0; i < S_LEN; ++i){
            wCount[s[i]] += 1;
            if(i >= P_LEN){
                wCount[s[i - P_LEN]] -= 1;
            }

            bool isEqual = true;
            for(char c = FIRST_CHAR; c < FIRST_CHAR + A && isEqual; ++c){
                if(wCount[c] != pCount[c]){
                    isEqual = false;
                }
            }

            if(isEqual){
                res.push_back(i - P_LEN + 1);
            }
        }

        return res;
    }
};