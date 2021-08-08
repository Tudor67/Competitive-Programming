class Solution {
private:
    bool isPalindrome(const string& S, const int& START_POS, const int& END_POS){
        for(int i = START_POS, j = END_POS; i < j; ++i, --j){
            if(S[i] != S[j]){
                return false;
            }
        }
        return true;
    }
    
public:
    int minCut(string s) {
        const int N = s.length();
        
        // minCuts[i]: minimum cuts needed for a palindrome partitioning of s[0 .. i]
        vector<int> minCuts(N);
        for(int i = 0; i < N; ++i){
            minCuts[i] = i;
            for(int j = 0; j <= i; ++j){
                if(isPalindrome(s, j, i)){
                    if(j == 0){
                        minCuts[i] = 0;
                    }else{
                        minCuts[i] = min(minCuts[i], 1 + minCuts[j - 1]);
                    }
                }
            }
        }
        
        return minCuts[N - 1];
    }
};