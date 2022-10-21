class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int N = s.length();
        
        // Case 1: empty string
        if(N == 0){
            return 0;
        }
        
        // Case 2: k == 0
        if(k == 0){
            string compressedS;
            int count = 0;
            for(int i = 0; i < N; ++i){
                if(i == 0 || s[i - 1] == s[i]){
                    count += 1;
                }
                if(i == N - 1 || s[i] != s[i + 1]){
                    compressedS += s[i];
                    compressedS += (count >= 2 ? to_string(count) : "");
                    count = 1;
                }
            }
            return compressedS.length();
        }
        
        // Case 3: non-empty string and k >= 1
        int minLen = N;
        for(int i = 0; i < N; ++i){
            if(i == 0 || s[i - 1] != s[i]){
                string newS = s.substr(0, i) + s.substr(i + 1);
                minLen = min(minLen, getLengthOfOptimalCompression(newS, k - 1));
            }
        }
        return minLen;
    }
};