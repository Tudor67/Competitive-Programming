class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), (long long)0);

        if(TOTAL_SUM < target){
            return -1;
        }

        sort(nums.begin(), nums.end());

        int res = 0;
        int N = nums.size();
        vector<bool> used(N, false);

        while(target > 0){
            int currentTarget = target - (target & (target - 1));
            long long currentSum = 0;
            for(int i = 0; i < N; ++i){
                if(!used[i] && nums[i] <= currentTarget){
                    currentSum += nums[i];
                }
            }

            if(currentSum >= currentTarget){
                for(int i = N - 1; i >= 0; --i){
                    if(!used[i] && nums[i] <= currentTarget){
                        currentTarget -= nums[i];
                        used[i] = true;
                    }
                }
                target &= (target - 1);
            }else{
                vector<int>::iterator it = upper_bound(nums.begin(), nums.end(), currentTarget);

                int newVal = (*it) / 2;
                *it = newVal;
                nums.insert(it, newVal);
                used.push_back(false);
                N += 1;

                res += 1;
            }
        }

        return res;
    }
};