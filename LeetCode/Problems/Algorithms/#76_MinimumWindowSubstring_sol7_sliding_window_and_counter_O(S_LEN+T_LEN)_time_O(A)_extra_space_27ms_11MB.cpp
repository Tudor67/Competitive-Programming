class Solution {
public:
    string minWindow(string s, string t) {
        const int S_LEN = s.length();
        const int T_LEN = t.length();

        unordered_map<char, int> targetFreq;
        for(char c: t){
            targetFreq[c] += 1;
        }

        int resStartPos = 0;
        int resLen = 0;
        int matches = 0;
        unordered_map<char, int> freq;

        int l = 0;
        for(int r = 0; r < S_LEN; ++r){
            freq[s[r]] += 1;
            if(targetFreq.count(s[r]) && freq[s[r]] <= targetFreq[s[r]]){
                matches += 1;
            }
            while(matches == T_LEN && freq[s[l]] > targetFreq[s[l]]){
                freq[s[l]] -= 1;
                l += 1;
            }
            if(matches == T_LEN){
                if(resLen == 0 || r - l + 1 < resLen){
                    resLen = r - l + 1;
                    resStartPos = l;
                }
            }
        }

        return s.substr(resStartPos, resLen);
    }
};