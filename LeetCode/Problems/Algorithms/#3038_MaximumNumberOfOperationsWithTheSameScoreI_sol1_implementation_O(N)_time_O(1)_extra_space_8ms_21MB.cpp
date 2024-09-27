class Solution {
public:
    int maxOperations(vector<int>& nums) {
        const int N = nums.size();

        int maxOps = 0;
        int i = 0;
        while(i + 1 < N && nums[0] + nums[1] == nums[i] + nums[i + 1]){
            i += 2;
            maxOps += 1;
        }

        return maxOps;
    }
};