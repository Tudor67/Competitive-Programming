class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        vector<int> count(MAX_NUM + 1, 0);
        for(int num: nums){
            count[num] += 1;
        }
        
        vector<int> freqs;
        for(int num = 0; num <= MAX_NUM; ++num){
            if(count[num] > 0){
                freqs.push_back(count[num]);
            }
        }
        
        const int M = quantity.size();
        const int Q_FULL_MASK = (1 << M) - 1;
        const int F = freqs.size();
        vector<vector<int>> masksFor(F);
        for(int mask = 1; mask <= Q_FULL_MASK; ++mask){
            int sum = 0;
            for(int bit = 0; bit < M; ++bit){
                if((mask >> bit) & 1){
                    sum += quantity[bit];
                }
            }
            for(int i = 0; i < F; ++i){
                if(sum <= freqs[i]){
                    masksFor[i].push_back(mask);
                }
            }
        }
        
        vector<bool> isPossible(Q_FULL_MASK + 1, false);
        isPossible[0] = true;
        for(int i = 0; i < F; ++i){
            for(int mask1 = Q_FULL_MASK; mask1 >= 0; --mask1){
                if(isPossible[mask1]){
                    for(int mask2: masksFor[i]){
                        isPossible[mask1 | mask2] = true;
                    }
                }
            }
        }
        
        return isPossible[Q_FULL_MASK];
    }
};