class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        const int N = nums.size();

        vector<int> leftBound(N, -1);
        vector<int> posOf(N + 2, -1);
        for(int i = 0; i < N; ++i){
            leftBound[i] = max(posOf[nums[i] + 1], posOf[nums[i]]);
            posOf[nums[i]] = i;
        }

        vector<int> rightBound(N, N);
        fill(posOf.begin(), posOf.end(), N);
        for(int i = N - 1; i >= 0; --i){
            rightBound[i] = posOf[nums[i] + 1];
            posOf[nums[i]] = i;
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            res += (i - leftBound[i]) * (rightBound[i] - i);
        }

        res -= N * (N + 1) / 2;

        return res;
    }
};