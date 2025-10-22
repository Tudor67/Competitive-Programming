class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> countOf(MAX_NUM + 1);
        for(int num: nums){
            countOf[num] += 1;
        }

        vector<int> prefCount(MAX_NUM + 1);
        for(int num = MIN_NUM; num <= MAX_NUM; ++num){
            prefCount[num] = prefCount[num - 1] + countOf[num];
        }

        int res = 0;
        for(int num = MIN_NUM; num <= MAX_NUM; ++num){
            int lCount = prefCount[num - 1] - prefCount[max(0, num - k - 1)];
            int rCount = prefCount[min(MAX_NUM, num + k)] - prefCount[num];
            int equalNums = countOf[num] + min(lCount + rCount, numOperations);
            res = max(res, equalNums);
        }

        return res;
    }
};