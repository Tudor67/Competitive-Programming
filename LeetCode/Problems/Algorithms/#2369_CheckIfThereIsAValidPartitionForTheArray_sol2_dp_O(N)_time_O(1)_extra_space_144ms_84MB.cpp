class Solution {
public:
    bool validPartition(vector<int>& nums) {
        const int N = nums.size();
        const int K = 4;

        vector<bool> isValid(K, false);
        isValid[N % K] = true;
        for(int i = N - 2; i >= 0; --i){
            isValid[i % K] = false;
            if(nums[i] == nums[i + 1] && isValid[(i + 2) % K]){
                isValid[i % K] = true;
            }
            if(i + 2 < N && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2] && isValid[(i + 3) % K]){
                isValid[i % K] = true;
            }
            if(i + 2 < N && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2] && isValid[(i + 3) % K]){
                isValid[i % K] = true;
            }
        }

        return isValid[0];
    }
};