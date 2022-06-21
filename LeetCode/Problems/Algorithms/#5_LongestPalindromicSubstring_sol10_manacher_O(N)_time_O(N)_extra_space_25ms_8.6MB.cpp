class Solution {
public:
    string longestPalindrome(string initialS) {
        const int N = 2 * initialS.length() + 1;
        
        string s(N, '.');
        for(int i = 1; i < N; i += 2){
            s[i] = initialS[i / 2];
        }
        
        vector<int> radius(N);
        int a = 0;
        int b = 0;
        for(int i = 0; i < N; ++i){
            if(i <= b){
                radius[i] = min(radius[a + (b - i)], b - i);
            }
            while(0 <= i - radius[i] - 1 && i + radius[i] + 1 < N && s[i - radius[i] - 1] == s[i + radius[i] + 1]){
                ++radius[i];
            }
            if(i + radius[i] >= b){
                a = i - radius[i];
                b = i + radius[i];
            }
        }
        
        int startIdx = 0;
        int maxLen = 0;
        for(int i = 0; i < N; ++i){
            if(radius[i] > maxLen){
                startIdx = (i - radius[i]) / 2;
                maxLen = radius[i];
            }
        }
        
        return initialS.substr(startIdx, maxLen);
    }
};