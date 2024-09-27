class Solution {
public:
    string lastNonEmptyString(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> freq(A);
        for(char c: s){
            freq[c - 'a'] += 1;
        }

        string res;
        int maxFreq = *max_element(freq.begin(), freq.end());
        for(int i = N - 1; i >= 0; --i){
            char c = s[i];
            if(freq[c - 'a'] == maxFreq){
                res += c;
                freq[c - 'a'] = 0;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};