class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        const int N = nums.size();
        const int MIN_VALID_SUM = 2;
        const int MAX_VALID_SUM = 2 * limit;

        unordered_map<int, int> count;
        vector<int> a(N / 2);
        vector<int> b(N / 2);
        for(int i = 0; i < N / 2; ++i){
            a[i] = min(nums[i], nums[N - 1 - i]);
            b[i] = max(nums[i], nums[N - 1 - i]);
            count[a[i] + b[i]] += 1;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int minCost = N;
        for(int sum = MIN_VALID_SUM; sum <= MAX_VALID_SUM; ++sum){
            int leftBadPairs2 = a.end() - lower_bound(a.begin(), a.end(), sum);
            int rightBadPairs2 = lower_bound(b.begin(), b.end(), sum - limit) - b.begin();
            int badPairs12 = N / 2 - (count.contains(sum) ? count[sum] : 0);
            int badPairs2 = leftBadPairs2 + rightBadPairs2;
            int currCost = badPairs12 + badPairs2;
            minCost = min(minCost, currCost);
        }

        return minCost;
    }
};