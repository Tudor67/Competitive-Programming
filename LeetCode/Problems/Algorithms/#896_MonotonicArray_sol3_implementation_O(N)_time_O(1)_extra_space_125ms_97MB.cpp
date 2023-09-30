class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        const int N = nums.size();

        int incAdjNums = 0;
        int decAdjNums = 0;
        for(int i = 0; i + 1 < N; ++i){
            incAdjNums += (int)(nums[i] <= nums[i + 1]);
            decAdjNums += (int)(nums[i] >= nums[i + 1]);
        }

        return (incAdjNums == N - 1) || (decAdjNums == N - 1);
    }
};