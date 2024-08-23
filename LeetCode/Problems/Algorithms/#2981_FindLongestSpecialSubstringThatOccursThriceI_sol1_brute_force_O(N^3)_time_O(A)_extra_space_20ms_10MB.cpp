class Solution {
public:
    int maximumLength(string s) {
        const int N = s.length();
        
        unordered_map<char, int> freq;
        for(int len = N - 2; len >= 1; --len){
            freq.clear();
            for(int i = 0; i + len - 1 < N; ++i){
                if(count(s.begin() + i, s.begin() + i + len, s[i]) == len){
                    freq[s[i]] += 1;
                    if(freq[s[i]] == 3){
                        return len;
                    }
                }
            }
        }
        
        return -1;
    }
};