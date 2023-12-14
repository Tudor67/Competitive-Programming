class Solution {
private:
    int findIndexOfMax(vector<int>& nums, int excludedIndex){
        const int N = nums.size();

        int maxNum = INT_MIN;
        int maxNumIndex = -1;

        for(int i = 0; i < N; ++i){
            if(i != excludedIndex){
                if(maxNum < nums[i]){
                    maxNum = nums[i];
                    maxNumIndex = i;
                }
            }
        }

        return maxNumIndex;
    }

public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();

        int i = findIndexOfMax(nums, -1);
        int j = findIndexOfMax(nums, i);

        return (nums[i] - 1) * (nums[j] - 1);
    }
};