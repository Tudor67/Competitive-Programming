class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        const int N = nums.size();

        int maxK = 0;
        int prevLen = 0;

        int i = 0;
        while(i < N){
            int j = i;
            while(j + 1 < N && nums[j] < nums[j + 1]){
                j += 1;
            }

            int len = j - i + 1;
            maxK = max(maxK, min(prevLen, len));
            maxK = max(maxK, len / 2);

            i = j + 1;
            prevLen = len;
        }

        return maxK;
    }
};