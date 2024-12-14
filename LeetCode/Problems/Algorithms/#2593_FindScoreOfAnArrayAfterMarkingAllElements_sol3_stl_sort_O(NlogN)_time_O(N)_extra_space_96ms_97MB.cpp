class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int N = nums.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return pair<int, int>{nums[lhs], lhs} <
                       pair<int, int>{nums[rhs], rhs};
             });

        long long score = 0;
        vector<bool> isMarked(N, false);
        for(int i: p){
            if(!isMarked[i]){
                score += nums[i];
                for(int j = max(0, i - 1); j <= min(i + 1, N - 1); ++j){
                    isMarked[j] = true;
                }
            }
        }

        return score;
    }
};