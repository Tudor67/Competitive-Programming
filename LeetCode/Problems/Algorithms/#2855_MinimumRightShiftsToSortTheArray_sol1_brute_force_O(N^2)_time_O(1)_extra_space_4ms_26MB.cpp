class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        const int N = nums.size();

        for(int startIndex = 0; startIndex < N; ++startIndex){
            bool isSorted = true;
            for(int i = startIndex; i + 1 < startIndex + N; ++i){
                if(nums[i % N] > nums[(i + 1) % N]){
                    isSorted = false;
                }
            }
            
            if(isSorted){
                return (N - startIndex) % N;
            }
        }

        return -1;
    }
};