class Solution {
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
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < M; ++bit){
                if((mask >> bit) & 1){
                    maskQuantity[mask] += quantity[bit];
                }
            }
        }
        
        int completedMask = 0;
        for(int fIdx = 0; completedMask != FULL_MASK && fIdx < F; ++fIdx){
            int maxValidMaskQuantity = 0;
            int maxValidMask = 0;
            for(int mask = 1; mask <= FULL_MASK; ++mask){
                if(mask & completedMask){
                    continue;
                }
                if(maskQuantity[mask] <= freq[fIdx] && maskQuantity[mask] > maxValidMaskQuantity){
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