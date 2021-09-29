class Solution {
public:
    int maxLength(vector<string>& arr) {
        const int N = arr.size();
        const int FULL_MASK = (1 << N) - 1;
        
        int maxLen = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            bool isValid = true;
            int len = 0;
            int visMask = 0;
            for(int bit = 0; isValid && bit < N; ++bit){
                if((mask >> bit) & 1){
                    for(char c: arr[bit]){
                        if((visMask >> (c - 'a')) & 1){
                            isValid = false;
                        }
                        len += 1;
                        visMask |= (1 << (c - 'a'));
                    }
                }
            }
            if(isValid){
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
    }
};