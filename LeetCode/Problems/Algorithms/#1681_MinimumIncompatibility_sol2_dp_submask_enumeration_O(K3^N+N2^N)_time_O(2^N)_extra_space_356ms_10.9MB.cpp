class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const int N = nums.size();
        const int SUBSET_SIZE = N / k;
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e5;
        
        sort(nums.begin(), nums.end());
        
        vector<int> incompatibility(FULL_MASK + 1, INF);
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            if(__builtin_popcount(mask) == SUBSET_SIZE){
                bool isValid = true;
                int prevNum = -1;
                int minNum =  INF;
                int maxNum = -INF;
                for(int bit = 0; bit < N; ++bit){
                    if((mask >> bit) & 1){
                        isValid = isValid && (prevNum != nums[bit]);
                        prevNum = nums[bit];
                        minNum = min(nums[bit], minNum);
                        maxNum = max(nums[bit], maxNum);
                    }
                }
                if(isValid){
                    incompatibility[mask] = maxNum - minNum;
                }
            }
        }
        
        for(int step = 2; step <= k; ++step){
            for(int mask = 1; mask <= FULL_MASK; ++mask){
                if(__builtin_popcount(mask) == step * SUBSET_SIZE){
                    for(int submask = mask; submask >= 1; submask = (submask - 1) & mask){
                        if(__builtin_popcount(submask) == SUBSET_SIZE){
                            int submask1 = submask;
                            int submask2 = submask ^ mask;
                            incompatibility[mask] = min(incompatibility[submask1] + incompatibility[submask2], incompatibility[mask]);
                        }
                    }
                }
            }
        }
        
        int answer = incompatibility[FULL_MASK];
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};