class Solution {
private:
    void back(int idx, int visMask, vector<int>& arrMasks, int& maxLen){
        if(idx == (int)arrMasks.size()){
            int len = __builtin_popcount((unsigned int)visMask);
            maxLen = max(maxLen, len);
        }else{
            if((visMask & arrMasks[idx]) == 0){
                back(idx + 1, visMask | arrMasks[idx], arrMasks, maxLen);
            }
            back(idx + 1, visMask, arrMasks, maxLen);
        }
    }
    
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
        back(0, 0, arrMasks, maxLen);
        
        return maxLen;
    }
};