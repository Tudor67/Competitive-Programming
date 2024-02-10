class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        const int N = nums.size();
        const int INF = INT_MAX;
        
        int res = INF;
        
        set<int> s;
        for(int i = x; i < N; ++i){
            s.insert(nums[i - x]);
            set<int>::iterator it = s.lower_bound(nums[i]);
            int diff1 = (it == s.end() ? INF : *it - nums[i]);
            int diff2 = (it == s.begin() ? INF : nums[i] - *prev(it));
            res = min(res, min(diff1, diff2));
        }
        
        return res;
    }
};