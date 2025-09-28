class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for(int i = N - 3; i >= 0; --i){
            if(sortedNums[i] + sortedNums[i + 1] > sortedNums[i + 2]){
                return (sortedNums[i] + sortedNums[i + 1] + sortedNums[i + 2]);
            }
        }

        return 0;
    }
};