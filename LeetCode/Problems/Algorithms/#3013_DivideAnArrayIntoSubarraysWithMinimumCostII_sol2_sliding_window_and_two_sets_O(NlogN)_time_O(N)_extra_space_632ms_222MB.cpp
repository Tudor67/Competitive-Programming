class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int N = nums.size();

        long long minCost = accumulate(nums.begin(), nums.end(), (long long)0);
        long long lSum = 0;
        set<pair<int, int>> lSet;
        set<pair<int, int>> rSet;

        for(int i = 1; i < N; ++i){
            lSet.insert({nums[i], i});
            lSum += nums[i];

            rSet.insert(*prev(lSet.end()));
            lSum -= prev(lSet.end())->first;
            lSet.erase(prev(lSet.end()));

            if(i - dist - 1 >= 1){
                pair<int, int> p = {nums[i - dist - 1], i - dist - 1};
                set<pair<int, int>>::iterator it = lSet.lower_bound(p);
                if(it != lSet.end() && *it == p){
                    lSum -= p.first;
                    lSet.erase(p);
                }else{
                    rSet.erase(p);
                }
            }

            if((int)lSet.size() < k - 1){
                lSum += rSet.begin()->first;
                lSet.insert(*rSet.begin());
                rSet.erase(rSet.begin());
            }

            if((int)lSet.size() == k - 1){
                long long cost = nums[0] + lSum;
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};