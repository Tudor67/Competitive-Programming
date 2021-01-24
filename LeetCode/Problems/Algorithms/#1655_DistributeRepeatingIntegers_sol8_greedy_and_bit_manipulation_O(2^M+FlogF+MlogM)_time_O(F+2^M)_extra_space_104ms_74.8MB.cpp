class Solution {
private:
    void back(int level, const int& M, int currentMask, vector<int>& maskQuantity, vector<int>& quantity){
        if(level < M){
            back(level + 1, M, currentMask, maskQuantity, quantity);
            maskQuantity[currentMask | (1 << level)] = maskQuantity[currentMask] + quantity[level];
            back(level + 1, M, currentMask | (1 << level), maskQuantity, quantity);
        }
    }
    
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {        
        unordered_map<int, int> freqOf;
        for(int num: nums){
            freqOf[num] += 1;
        }
        
        vector<int> freq;
        for(const pair<int, int>& P: freqOf){
            freq.push_back(P.second);
        }
        
        sort(freq.rbegin(), freq.rend());
        sort(quantity.rbegin(), quantity.rend());
            
        const int F = freq.size();
        const int M = quantity.size();
        const int FULL_MASK = (1 << M) - 1;
        
        vector<int> maskQuantity(FULL_MASK + 1, 0);
        back(0, M, 0, maskQuantity, quantity);
        
        int completedMask = 0;
        for(int fIdx = 0; completedMask != FULL_MASK && fIdx < F; ++fIdx){
            int maxValidMaskQuantity = 0;
            int maxValidMask = 0;
            int freeMask = ~completedMask & FULL_MASK;
            for(int mask = freeMask; mask >= 1; mask = (mask - 1) & freeMask){
                if(maskQuantity[mask] <= freq[fIdx] && maskQuantity[mask] >= maxValidMaskQuantity){
                    maxValidMaskQuantity = maskQuantity[mask];
                    maxValidMask = mask;
                }
            }
            completedMask |= maxValidMask;
            if(maxValidMask == 0){
                break;
            }
        }
        
        return (completedMask == FULL_MASK);
    }
};