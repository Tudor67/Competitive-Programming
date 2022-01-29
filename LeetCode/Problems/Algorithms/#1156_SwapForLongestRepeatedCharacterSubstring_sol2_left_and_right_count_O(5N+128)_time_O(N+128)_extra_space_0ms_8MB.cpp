class Solution {
public:
    int maxRepOpt1(string text) {
        const int N = text.length();
        
        vector<int> totalCount(128);
        for(char c: text){
            totalCount[c] += 1;
        }
        
        vector<int> leftCount(N, 1);
        for(int i = 1; i < N; ++i){
            if(text[i - 1] == text[i]){
                leftCount[i] += leftCount[i - 1];
            }
        }
        
        vector<int> rightCount(N, 1);
        for(int i = N - 2; i >= 0; --i){
            if(text[i] == text[i + 1]){
                rightCount[i] += rightCount[i + 1];
            }
        }
        
        int maxLen = *max_element(leftCount.begin(), leftCount.end());
        for(int i = 0; i < N; ++i){
            int len = min(totalCount[text[i]], leftCount[i] + 1);
            maxLen = max(maxLen, len);
        }
        
        for(int i = 1; i + 1 < N; ++i){
            if(text[i - 1] == text[i + 1]){
                int len = min(totalCount[text[i - 1]], leftCount[i - 1] + rightCount[i + 1] + 1);
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};