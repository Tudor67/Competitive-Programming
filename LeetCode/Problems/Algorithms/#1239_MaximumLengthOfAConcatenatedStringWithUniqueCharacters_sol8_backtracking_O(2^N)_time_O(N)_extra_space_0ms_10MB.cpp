class Solution {
private:
    void back(int i, int currentMask, vector<int>& charMasks, int& maxLen){
        if(i == (int)charMasks.size()){
            maxLen = max(maxLen, __builtin_popcount(currentMask));
        }else{
            back(i + 1, currentMask, charMasks, maxLen);
            if(!(currentMask & charMasks[i])){
                back(i + 1, currentMask | charMasks[i], charMasks, maxLen);
            }
        }
    }

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
        back(0, 0, charMasks, maxLen);

        return maxLen;
    }
};