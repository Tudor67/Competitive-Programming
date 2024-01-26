class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        if(MAX_NUM != N - 1){
            return false;
        }

        if(count(nums.begin(), nums.end(), MAX_NUM) != 2){
            return false;
        }

        bool isValid = true;
        for(int i = 0; i < N; ++i){
            if(abs(nums[i]) != MAX_NUM){
                int index = abs(nums[i]) - 1;
                if(nums[index] < 0){
                    isValid = false;
                }else{
                    nums[index] = -nums[index];
                }
            }
        }

        for(int i = 0; i < N; ++i){
            nums[i] = abs(nums[i]);
        }

        return isValid;
    }
};