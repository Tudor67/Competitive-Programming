class Solution {
public:
    int largestVariance(string s) {
        const int N = s.length();
        
        int maxVariance = 0;
        vector<int> count(130);
        vector<int> f(N + 1);
        
        for(int i = 0; i < N; ++i){
            int maxCount = 1;
            int minCount = 1;
            
            for(int j = i; j < N; ++j){
                count[s[j]] += 1;
                f[count[s[j]] - 1] -= 1;
                f[count[s[j]]] += 1;
                
                maxCount = max(maxCount, count[s[j]]);
                if(count[s[j]] == 1){
                    minCount = 1;
                }else if(minCount == count[s[j]] - 1 && f[minCount] == 0){
                    minCount += 1;
                }
                
                int variance = maxCount - minCount;
                maxVariance = max(maxVariance, variance);
            }
            
            for(int c = 'a'; c <= 'z'; ++c){
                f[count[c]] = 0;
                count[c] = 0;
            }
            f[0] = 0;
        }
        
        return maxVariance;
    }
};