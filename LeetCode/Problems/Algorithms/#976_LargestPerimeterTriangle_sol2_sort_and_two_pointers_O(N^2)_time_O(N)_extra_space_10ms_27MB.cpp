class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int maxPerimeter = 0;
        for(int i = N - 1; i >= 0; --i){
            int k = 0;
            for(int j = i + 1; j < N; ++j){
                k = max(k, j + 1);
                while(k < N && sortedNums[i] + sortedNums[j] > sortedNums[k]){
                    maxPerimeter = max(maxPerimeter, sortedNums[i] + sortedNums[j] + sortedNums[k]);
                    k += 1;
                }
            }
            if(maxPerimeter > 0){
                return maxPerimeter;
            }
        }

        return 0;
    }
};