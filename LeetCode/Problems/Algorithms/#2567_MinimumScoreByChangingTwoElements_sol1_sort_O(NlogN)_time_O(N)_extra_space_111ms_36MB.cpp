class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int score1 = sortedNums[N - 1] - sortedNums[2];
        int score2 = sortedNums[N - 2] - sortedNums[1];
        int score3 = sortedNums[N - 3] - sortedNums[0];

        return min({score1, score2, score3});
    }
};