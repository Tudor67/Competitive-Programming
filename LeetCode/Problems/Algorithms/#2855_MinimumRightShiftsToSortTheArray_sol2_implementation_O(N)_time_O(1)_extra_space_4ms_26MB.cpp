class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        const int N = nums.size();

        int startIndex = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] > nums[i + 1]){
                startIndex = i + 1;
            }
        }

        for(int i = startIndex; i + 1 < startIndex + N; ++i){
            if(nums[i % N] > nums[(i + 1) % N]){
                return -1;
            }
        }

        return (N - startIndex) % N;
    }
};