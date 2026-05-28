class Solution {
public:
    bool check(vector<int>& nums) {
        const int N = nums.size();

        int adjBadPairs = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] > nums[i + 1]){
                ++adjBadPairs;
            }
        }

        return (adjBadPairs == 0 || (adjBadPairs == 1 && nums[N - 1] <= nums[0]));
    }
};