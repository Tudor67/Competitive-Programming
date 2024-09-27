class Solution {
public:
    string lastNonEmptyString(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> freq(A);
        for(char c: s){
            freq[c - 'a'] += 1;
        }

        vector<bool> includedInRes(A, false);
        int maxFreq = *max_element(freq.begin(), freq.end());
        for(char c = 'a'; c <= 'z'; ++c){
            if(freq[c - 'a'] == maxFreq){
                includedInRes[c - 'a'] = true;
            }
        }

        string res;
        for(char c: s){
            freq[c - 'a'] -= 1;
            if(freq[c - 'a'] == 0 && includedInRes[c - 'a']){
                res += c;
            }
        }

        return res;
    }
};