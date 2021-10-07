class Solution {
private:
    bool checkPalindrome(const string& S, const int& MASK){
        const int N = S.length();
        int i = 0;
        int j = N - 1;
        while(i < j){
            if(((MASK >> i) & 1) && ((MASK >> j) & 1)){
                if(S[i] == S[j]){
                    i += 1;
                    j -= 1;
                }else{
                    return false;
                }
            }else if((MASK >> i) & 1){
                j -= 1;
            }else{
                i += 1;
            }
        }
        return true;
    }
    
public:
    int maxProduct(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;
        
        vector<bool> isPalindrome(FULL_MASK + 1, false);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            isPalindrome[mask] = checkPalindrome(s, mask);
        }
        
        int maxProduct = 0;
        for(int mask1 = 0; mask1 <= FULL_MASK; ++mask1){
            if(isPalindrome[mask1]){
                int mask1Complement = mask1 ^ FULL_MASK;
                for(int mask2 = mask1Complement; mask2 > 0; mask2 = (mask2 - 1) & mask1Complement){
                    if(isPalindrome[mask2]){
                        int product = __builtin_popcount((unsigned int)mask1) * __builtin_popcount((unsigned int)mask2);
                        maxProduct = max(maxProduct, product);
                    }
                }
            }
        }
        
        return maxProduct;
    }
};