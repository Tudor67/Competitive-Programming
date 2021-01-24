class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        vector<int> numFreq(MAX_NUM + 1, 0);
        for(int num: nums){
            numFreq[num] += 1;
        }
        
        vector<int> freq;
        for(int num = 0; num <= MAX_NUM; ++num){
            if(numFreq[num] > 0){
                freq.push_back(numFreq[num]);
            }
        }
        
        const int F = freq.size();
        const int M = quantity.size();
        const int FULL_MASK = (1 << M) - 1;
        
        vector<unordered_set<int>> masksFor(F);
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            int maskQuantity = 0;
            for(int bit = 0; bit < M; ++bit){
                if((mask >> bit) & 1){
                    maskQuantity += quantity[bit];
                }
            }
            for(int fIdx = 0; fIdx < F; ++fIdx){
                if(maskQuantity <= freq[fIdx]){
                    masksFor[fIdx].insert(mask);
                }
            }
        }
        
        vector<bool> isPossible(FULL_MASK + 1, false);
        isPossible[0] = true;
        for(int fIdx = 0; !isPossible[FULL_MASK] && fIdx < F; ++fIdx){
            for(int mask = FULL_MASK; mask >= 1; --mask){
                for(int submask = mask; !isPossible[mask] && submask >= 1; submask = (submask - 1)& mask){
                    int submask1 = submask;
                    int submask2 = submask ^ mask;
                    if((isPossible[submask1] && masksFor[fIdx].count(submask2)) ||
                       (isPossible[submask2] && masksFor[fIdx].count(submask1))){
                        isPossible[mask] = true;
                    }
                }
            }
        }
        
        return isPossible[FULL_MASK];
    }
};