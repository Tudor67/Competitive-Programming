class Solution {
public:
    int maxLength(vector<string>& arr) {
        const int N = arr.size();
        const int FULL_MASK = (1 << N) - 1;
        
        vector<int> charMaskOf(N);
        for(int i = 0; i < N; ++i){
            bool isValid = true;
            int currentCharMask = 0;
            for(char c: arr[i]){
                int bit = c - 'a';
                if((currentCharMask >> bit) & 1){
                    isValid = false;
                }else{
                    currentCharMask |= (1 << bit);
                }
            }
            if(isValid){
                charMaskOf[i] = currentCharMask;
            }
        }
        
        int maxLen = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            bool isValid = true;
            int currentCharMask = 0;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    if(currentCharMask & charMaskOf[bit]){
                        isValid = false;
                    }else{
                        currentCharMask |= charMaskOf[bit];
                    }
                }
            }
            if(isValid){
                int len = __builtin_popcount((unsigned int)currentCharMask);
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};