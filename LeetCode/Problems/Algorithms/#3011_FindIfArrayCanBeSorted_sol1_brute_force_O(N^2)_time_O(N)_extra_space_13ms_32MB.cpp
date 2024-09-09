class Solution {
public:
    bool canSortArray(vector<int>& inputNums) {
        const int N = inputNums.size();

        vector<int> nums = inputNums;

        bool updated = true;
        while(updated){
            updated = false;
            for(int i = 0; i + 1 < N; ++i){
                if(nums[i] > nums[i + 1] &&
                   popcount((unsigned int)nums[i]) == popcount((unsigned int)nums[i + 1])){
                    swap(nums[i], nums[i + 1]);
                    updated = true;
                }
            }
        }

        return is_sorted(nums.begin(), nums.end());
    }
};