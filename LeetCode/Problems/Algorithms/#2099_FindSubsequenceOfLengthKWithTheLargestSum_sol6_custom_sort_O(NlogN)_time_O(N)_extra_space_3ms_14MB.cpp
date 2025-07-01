class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
            [&](int lhs, int rhs){
                return (nums[lhs] > nums[rhs]);
            });

        sort(p.begin(), p.begin() + k);

        vector<int> res(k);
        for(int i = 0; i < k; ++i){
            res[i] = nums[p[i]];
        }

        return res;
    }
};