class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        const int N = nums.size();

        int l = 0;
        int prevMax = INT_MIN;
        while(l < N){
            int r = l;
            int currMin = nums[l];
            int currMax = nums[l];
            while(r < N && popcount((unsigned int)nums[l]) == popcount((unsigned int)nums[r])){
                currMin = min(currMin, nums[r]);
                currMax = max(currMax, nums[r]);
                r += 1;
            }

            if(prevMax > currMin){
                return false;
            }

            l = r;
            prevMax = currMax;
        }

        return true;
    }
};