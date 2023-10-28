class Solution {
public:
    string longestPalindrome(string inputStr) {
        const int N = 2 * inputStr.length() + 1;

        string s(N, '.');
        for(int i = 1; i < N; i += 2){
            s[i] = inputStr[i / 2];
        }

        vector<int> radius(N);
        int a = 0;
        int b = 0;
        for(int i = 1; i < N; ++i){
            if(i <= b){
                radius[i] = min(radius[a + (b - i)], b - i);
            }
            while(0 <= i - radius[i] - 1 && i + radius[i] + 1 < N &&
                 s[i - radius[i] - 1] == s[i + radius[i] + 1]){
                radius[i] += 1;
            }
            if(i + radius[i] > b){
                a = i - radius[i];
                b = i + radius[i];
            }
        }

        int maxLen = 0;
        int maxLenStartIndex = 0;
        for(int i = 0; i < N; ++i){
            int len = radius[i];
            int startIndex = (i - radius[i]) / 2;
            if(maxLen < len){
                maxLen = len;
                maxLenStartIndex = startIndex;
            }
        }

        return inputStr.substr(maxLenStartIndex, maxLen);
    }
};