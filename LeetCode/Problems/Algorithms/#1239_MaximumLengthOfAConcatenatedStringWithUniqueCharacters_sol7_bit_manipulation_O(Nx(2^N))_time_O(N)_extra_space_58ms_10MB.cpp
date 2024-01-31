class Solution {
public:
    int maxLength(vector<string>& arr) {
        const int N = arr.size();
        const int FULL_MASK = (1 << N) - 1;
        const int A = 26;
        const char FIRST_CHAR = 'a';

        vector<int> charMasks(N);
        for(int i = 0; i < N; ++i){
            bool isValid = true;
            for(char c: arr[i]){
                if((charMasks[i] >> (c - FIRST_CHAR)) & 1){
                    isValid = false;
                }
                charMasks[i] |= (1 << (c - FIRST_CHAR));
            }
            if(!isValid){
                charMasks[i] = 0;
            }
        }

        int maxLen = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            bool isValid = true;
            int subsetMask = 0;
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    if(subsetMask & charMasks[bit]){
                        isValid = false;
                    }
                    subsetMask |= charMasks[bit];
                }
            }
            if(isValid){
                maxLen = max(maxLen, __builtin_popcount(subsetMask));
            }
        }

        return maxLen;
    }
};