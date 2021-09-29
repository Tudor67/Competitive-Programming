class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> arrMasks;
        for(const string& S: arr){
            bool isValid = true;
            int mask = 0;
            for(char c: S){
                if((mask >> (c - 'a')) & 1){
                    isValid = false;
                    break;
                }
                mask |= (1 << (c - 'a'));
            }
            if(isValid){
                arrMasks.push_back(mask);
            }
        }
        
        const int M = arrMasks.size();
        const int FULL_MASK = (1 << M) - 1;
        
        int maxLen = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            bool isValid = true;
            int visMask = 0;
            for(int bit = 0; isValid && bit < M; ++bit){
                if((mask >> bit) & 1){
                    if(visMask & arrMasks[bit]){
                        isValid = false;
                        break;
                    }
                    visMask |= arrMasks[bit];
                }
            }
            if(isValid){
                int len = __builtin_popcount((unsigned int)visMask);
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};