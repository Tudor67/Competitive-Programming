class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int N = nums.size();

        int indexOfMin = 0;
        int indexOfMax = 0;
        for(int i = 1; i < N; ++i){
            if(nums[i] < nums[indexOfMin]){
                indexOfMin = i;
            }
            if(nums[i] > nums[indexOfMax]){
                indexOfMax = i;
            }
        }

        int leftIndex = min(indexOfMin, indexOfMax);
        int rightIndex = max(indexOfMin, indexOfMax);

        return min({rightIndex + 1, N - leftIndex, (leftIndex + 1) + (N - rightIndex)});
    }
};