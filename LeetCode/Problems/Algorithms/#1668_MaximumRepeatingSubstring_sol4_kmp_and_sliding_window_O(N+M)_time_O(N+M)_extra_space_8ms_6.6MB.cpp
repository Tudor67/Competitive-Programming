class Solution {
public:
    int maxRepeating(string sequence, string word) {
        const int N = sequence.length();
        const int M = word.length();
        
        const string PS = word + "$" + sequence;
        const int L = PS.length();
        
        vector<int> p(L, 0);
        for(int i = 1; i < L; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                p[i] = k + 1;
            }
        }
        
        // dp[i]: max k-repeating value of word ending in PS[i]
        vector<int> dp(L, 0);
        for(int i = M + 1; i < L; ++i){
            if(p[i] == M){
                dp[i] = dp[i - M] + 1;
            }else{
                dp[i] = 0;
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};