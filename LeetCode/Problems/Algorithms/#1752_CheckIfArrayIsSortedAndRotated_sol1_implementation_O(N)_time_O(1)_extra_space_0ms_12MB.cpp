class Solution {
public:
    bool check(vector<int>& nums) {
        const int N = nums.size();

        int startIndex = 0;
        while(startIndex + 1 < N && nums[startIndex] <= nums[startIndex + 1]){
            startIndex += 1;
        }
        startIndex += 1;

        for(int i = startIndex; i + 1 < startIndex + N; ++i){
            if(nums[i % N] > nums[(i + 1) % N]){
                return false;
            }
        }

        return true;
    }
};