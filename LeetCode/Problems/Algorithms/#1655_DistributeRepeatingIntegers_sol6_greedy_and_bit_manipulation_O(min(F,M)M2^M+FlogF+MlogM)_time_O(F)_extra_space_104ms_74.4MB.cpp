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
        
        int completedMask = 0;
        for(int fIdx = 0; completedMask != FULL_MASK && fIdx < F; ++fIdx){
            int maxValidMaskQuantity = 0;
            int maxValidMask = 0;
            for(int mask = 1; mask <= FULL_MASK; ++mask){
                if(mask & completedMask){
                    continue;
                }
                int maskQuantity = 0;
                for(int bit = 0; bit < M; ++bit){
                    if((mask >> bit) & 1){
                        maskQuantity += quantity[bit];
                    }
                }
                if(maskQuantity <= freq[fIdx] && maskQuantity > maxValidMaskQuantity){
                    maxValidMaskQuantity = maskQuantity;
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