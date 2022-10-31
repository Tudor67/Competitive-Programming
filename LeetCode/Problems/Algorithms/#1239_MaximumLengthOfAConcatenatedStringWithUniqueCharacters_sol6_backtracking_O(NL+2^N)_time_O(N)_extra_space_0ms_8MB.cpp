class Solution {
private:
    void back(int index, int currentCharMask, vector<int>& charMaskOf, int& maxLen){
        if(index >= (int)charMaskOf.size()){
            int len = __builtin_popcount((unsigned int)currentCharMask);
            maxLen = max(maxLen, len);
        }else{
            if((currentCharMask & charMaskOf[index]) == 0){
                back(index + 1, currentCharMask | charMaskOf[index], charMaskOf, maxLen);
            }
            back(index + 1, currentCharMask, charMaskOf, maxLen);
        }
    }
    
public:
    int maxLength(vector<string>& arr) {
        const int N = arr.size();
        
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
        back(0, 0, charMaskOf, maxLen);
        
        return maxLen;
    }
};