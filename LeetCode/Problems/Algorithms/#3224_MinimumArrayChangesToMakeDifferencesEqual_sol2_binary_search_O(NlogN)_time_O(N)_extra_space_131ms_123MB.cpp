class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int N = nums.size();

        map<int, int> freqOf;
        vector<int> sortedLimits(N / 2);
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            int a = min(nums[i], nums[j]);
            int b = max(nums[i], nums[j]);

            freqOf[b - a] += 1;

            int limit = max(b, k - a);
            sortedLimits[i] = limit;
        }

        sort(sortedLimits.begin(), sortedLimits.end());

        int minCost = N;
        for(auto [diff, diffFreq]: freqOf){
            int pairs0 = diffFreq;
            int pairs1 = sortedLimits.end() - lower_bound(sortedLimits.begin(), sortedLimits.end(), diff) - pairs0;
            int pairs2 = N / 2 - pairs1 - pairs0;
            minCost = min(minCost, pairs1 + 2 * pairs2);
        }

        return minCost;
    }
};