class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> res(N - k + 1);

        set<pair<int, int>> wSet;
        for(int i = 0; i < N; ++i){
            wSet.insert({nums[i], i});
            if(i >= k){
                wSet.erase({nums[i - k], i - k});
            }
            if(i >= k - 1){
                res[i - (k - 1)] = wSet.rbegin()->first;
            }
        }

        return res;
    }
};