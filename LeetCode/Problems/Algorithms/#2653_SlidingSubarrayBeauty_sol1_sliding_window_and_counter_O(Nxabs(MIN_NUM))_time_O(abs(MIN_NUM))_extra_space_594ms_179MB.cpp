class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());

        // Step 1: special case when all nums >= 0
        vector<int> res(N - k + 1);
        if(MIN_NUM >= 0){
            return res;
        }

        // Step 2: sliding window + counter for negative nums
        vector<int> count(-MIN_NUM + 1);
        for(int i = 0; i < N; ++i){
            if(nums[i] < 0){
                count[-nums[i]] += 1;
            }
            if(i >= k && nums[i - k] < 0){
                count[-nums[i - k]] -= 1;
            }
            if(i >= k - 1){
                int remX = x;
                for(int num = MIN_NUM; num < 0; ++num){
                    if(count[-num] >= 1){
                        remX -= count[-num];
                        if(remX <= 0){
                            res[i - k + 1] = num;
                            break;
                        }
                    }
                }
            }
        }

        return res;
    }
};