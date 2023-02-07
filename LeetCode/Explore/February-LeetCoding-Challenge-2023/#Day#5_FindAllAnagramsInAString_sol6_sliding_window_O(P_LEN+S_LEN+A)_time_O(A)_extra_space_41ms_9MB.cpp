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
        int matches = A - (int)pCount.size();
        for(int i = 0; i < S_LEN; ++i){
            matches -= (int)(wCount[s[i]] == pCount[s[i]]);
            wCount[s[i]] += 1;
            matches += (int)(wCount[s[i]] == pCount[s[i]]);
            if(i >= P_LEN){
                matches -= (int)(wCount[s[i - P_LEN]] == pCount[s[i - P_LEN]]);
                wCount[s[i - P_LEN]] -= 1;
                matches += (int)(wCount[s[i - P_LEN]] == pCount[s[i - P_LEN]]);
            }

            if(matches == A){
                res.push_back(i - P_LEN + 1);
            }
        }

        return res;
    }
};