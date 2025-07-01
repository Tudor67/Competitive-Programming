class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }

        nth_element(v.begin(), v.end() - k, v.end());

        vector<bool> used(N, false);
        for(int i = N - k; i < N; ++i){
            used[v[i].second] = true;
        }

        vector<int> res;
        res.reserve(k);
        for(int i = 0; i < N; ++i){
            if(used[i]){
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};