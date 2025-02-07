class Solution {
public:
    bool check(vector<int>& nums) {
        const int N = nums.size();

        int decAdjPairs = 0;
        for(int i = 0; i < N; ++i){
            if(nums[i] > nums[(i + 1) % N]){
                decAdjPairs += 1;
            }
        }

        return (decAdjPairs <= 1);
    }
};