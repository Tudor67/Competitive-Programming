class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int N = nums.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return pair<int, int>{nums[lhs], lhs} <
                       pair<int, int>{nums[rhs], rhs};
             });

        int maxWidth = 0;
        int prefMinIndex = N;
        for(int i: p){
            maxWidth = max(maxWidth, i - prefMinIndex);
            prefMinIndex = min(prefMinIndex, i);
        }

        return maxWidth;
    }
};