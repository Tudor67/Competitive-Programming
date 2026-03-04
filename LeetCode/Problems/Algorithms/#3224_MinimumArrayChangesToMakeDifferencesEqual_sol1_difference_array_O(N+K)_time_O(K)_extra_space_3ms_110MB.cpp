class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> delta(k + 2);
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            int a = min(nums[i], nums[j]);
            int b = max(nums[i], nums[j]);

            // cost 2
            delta[max(b, k - a) + 1] += 2;
            delta[k + 1] -= 2;
            
            // cost 1
            delta[0] += 1;
            delta[max(b, k - a) + 1] -= 1;

            // cost 0
            delta[b - a] -= 1;
            delta[b - a + 1] += 1;
        }

        int minCost = N;
        int prefSum = 0;
        for(int x = 0; x <= k; ++x){
            prefSum += delta[x];
            minCost = min(minCost, prefSum);
        }

        return minCost;
    }
};