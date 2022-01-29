class Solution {
public:
    int maxRepOpt1(string text) {
        const int N = text.length();
        
        int maxLen = 0;
        for(int targetChar = 'a'; targetChar <= 'z'; ++targetChar){
            int targetCount = count(text.begin(), text.end(), targetChar);
            if(targetCount > 0){
                int currentCount = 0;
                int i = 0;
                for(int j = 0; j < N; ++j){
                    currentCount += (int)(text[j] == targetChar);
                    while(currentCount + 1 < j - i + 1){
                        currentCount -= (int)(text[i] == targetChar);
                        i += 1;
                    }
                    int len = min(targetCount, j - i + 1);
                    maxLen = max(maxLen, len);
                }
            }
        }
        
        return maxLen;
    }
};