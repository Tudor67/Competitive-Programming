class Solution {
public:
    bool canSortArray(vector<int>& inputNums) {
        const int N = inputNums.size();

        vector<int> nums = inputNums;

        int l = 0;
        while(l < N){
            int r = l + 1;
            while(r < N && popcount((unsigned int)nums[l]) == popcount((unsigned int)nums[r])){
                r += 1;
            }
            sort(nums.begin() + l, nums.begin() + r);
            l = r;
        }

        return is_sorted(nums.begin(), nums.end());
    }
};