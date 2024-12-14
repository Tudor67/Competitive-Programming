class Solution {
public:
    int maximumLength(string s) {
        const int N = s.length();

        map<pair<char, int>, int> freq;

        int l = 0;
        while(l < N){
            int r = l;
            while(r < N && s[l] == s[r]){
                r += 1;
            }
            freq[{s[l], r - l}] += 1;
            l = r;
        }

        int maxLen = 0;
        for(const pair<const pair<char, int>, int>& P: freq){
            char c = P.first.first;
            int len = P.first.second;
            int lenFreq = P.second;

            if(lenFreq >= 3){
                maxLen = max(maxLen, len);
            }else if(lenFreq == 2 || freq.count({c, len - 1})){
                maxLen = max(maxLen, len - 1);
            }else{
                maxLen = max(maxLen, len - 2);
            }
        }

        if(maxLen >= 1){
            return maxLen;
        }

        return -1;
    }
};