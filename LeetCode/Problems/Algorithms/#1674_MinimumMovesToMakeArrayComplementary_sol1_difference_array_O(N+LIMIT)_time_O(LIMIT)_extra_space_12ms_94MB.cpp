class Solution {
private:
    void add(vector<int>& delta, int l, int r, int val){
        delta[l] += val;
        delta[r + 1] -= val;
    }

public:
    int minMoves(vector<int>& nums, int limit) {
        const int N = nums.size();
        const int MIN_VALID_SUM = 2;
        const int MAX_VALID_SUM = 2 * limit;

        vector<int> delta(MAX_VALID_SUM + 2);
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            int a = min(nums[i], nums[j]);
            int b = max(nums[i], nums[j]);
            add(delta, MIN_VALID_SUM, MAX_VALID_SUM, 2);
            add(delta, a + 1, b + limit, -1);
            add(delta, a + b, a + b, -1);
        }

        int minCost = N;
        int currCost = 0;
        for(int i = MIN_VALID_SUM; i <= MAX_VALID_SUM; ++i){
            currCost += delta[i];
            minCost = min(minCost, currCost);
        }

        return minCost;
    }
};