class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int i = 0;
        int prevLen = 0;
        while(i < N){
            int j = i;
            while(j + 1 < N && nums[j] < nums[j + 1]){
                j += 1;
            }

            int len = j - i + 1;
            if((prevLen >= k && len >= k) || len >= 2 * k){
                return true;
            }

            i = j + 1;
            prevLen = len;
        }

        return false;
    }
};